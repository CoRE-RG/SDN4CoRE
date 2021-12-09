//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "IPTunnelingControllerApp.h"

//inet
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/networklayer/contract/ipv4/IPv4ControlInfo.h"
#include "inet/common/LayeredProtocolBase.h"
//CoRE4INET
#include "core4inet/utilities/customWatch.h"

using namespace inet;
using namespace std;
using namespace openflow;

namespace SDN4CoRE {

Define_Module(IPTunnelingControllerApp);

void IPTunnelingControllerApp::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        PacketProcessorBase::initialize();
        vector<string> tunnelIPs = cStringTokenizer(par("tunnelIPAddresses"),",").asVector();
        if(!tunnelIPs.empty()) {
            _whitelist.addPacketFilters("ipDst", tunnelIPs);
        }

        ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);

        transportInGateBaseId = gateBaseId("transportIn");

        defaultTimeToLive = par("timeToLive");
        defaultMCTimeToLive = par("multicastTimeToLive");
        fragmentTimeoutTime = par("fragmentTimeout");
        forceBroadcast = par("forceBroadcast");

        numMulticast = numLocalDeliver = numDropped = numUnroutable = numForwarded = 0;

        WATCH(numMulticast);
        WATCH(numLocalDeliver);
        WATCH(numDropped);
        WATCH(numUnroutable);
        WATCH(numForwarded);
    }
    else if (stage == INITSTAGE_NETWORK_LAYER) {
        isUp = true;
    }
}

void IPTunnelingControllerApp::refreshDisplay() const
{
    char buf[80] = "";
    if (numForwarded > 0)
        sprintf(buf + strlen(buf), "fwd:%d ", numForwarded);
    if (numLocalDeliver > 0)
        sprintf(buf + strlen(buf), "up:%d ", numLocalDeliver);
    if (numMulticast > 0)
        sprintf(buf + strlen(buf), "mcast:%d ", numMulticast);
    if (numDropped > 0)
        sprintf(buf + strlen(buf), "DROP:%d ", numDropped);
    if (numUnroutable > 0)
        sprintf(buf + strlen(buf), "UNROUTABLE:%d ", numUnroutable);
    getDisplayString().setTagArg("t", 0, buf);
}

void IPTunnelingControllerApp::processPacketIn(
        openflow::OFP_Packet_In* packet_in_msg) {
    if (EthernetIIFrame* eth =
                dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        if (IPv4Datagram* ip =
                        dynamic_cast<IPv4Datagram *>(eth->getEncapsulatedPacket())) {
            endService(ip->dup());
        }
    }
}

void IPTunnelingControllerApp::handleMessage(cMessage *msg)
{
    if (dynamic_cast<RegisterTransportProtocolCommand *>(msg)) {
        RegisterTransportProtocolCommand *command = check_and_cast<RegisterTransportProtocolCommand *>(msg);
        mapping.addProtocolMapping(command->getProtocol(), msg->getArrivalGate()->getIndex());
        delete msg;
    }
    else {
        //we do not implement queueing and delay in this ip version, so handle it directly
        endService(PK(msg));
    }
}

void IPTunnelingControllerApp::endService(cPacket *packet)
{
    if (!isUp) {
        EV_ERROR << "IPv4 is down -- discarding message\n";
        delete packet;
        return;
    }
    if (packet->getArrivalGate()->isName("transportIn")) {    //TODO packet->getArrivalGate()->getBaseId() == transportInGateBaseId
        return;
        //        handlePacketFromHL(packet);
    }
    else {    // from network
        EV_INFO << "Received " << packet << " from OpenFlow network.\n";
        if (auto dgram = dynamic_cast<IPv4Datagram *>(packet))
            handleIncomingDatagram(dgram);
        else
            throw cRuntimeError(packet, "Unexpected packet type");
    }
}

void IPTunnelingControllerApp::handleIncomingDatagram(IPv4Datagram *datagram)
{
    ASSERT(datagram);
    emit(LayeredProtocolBase::packetReceivedFromLowerSignal, datagram);

    // hop counter decrement
    datagram->setTimeToLive(datagram->getTimeToLive() - 1);

    IPv4Address& destAddr = datagram->getDestAddress();
    EV_DETAIL << "Received datagram `" << datagram->getName() << "' with dest=" << destAddr << "\n";

    // remove control info
    cObject* ctrlInfo = datagram->removeControlInfo();
    if(ctrlInfo) {
        delete ctrlInfo;
    }

    // route packet
    else {
        if (destAddr.isMulticast() && !par("receiveMulticast").boolValue()) {
            EV_WARN << "Skip forwarding of multicast datagram (forwarding disabled)\n";
            emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
            delete datagram;
        }
        if(destAddr.isLimitedBroadcastAddress() && !par("receiveBroadcast").boolValue()) {
            EV_WARN << "Skip forwarding of broadcast datagram (forwarding disabled)\n";
            emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
            delete datagram;
        }
        else {
            reassembleAndDeliver(datagram);
        }
    }
}

void IPTunnelingControllerApp::reassembleAndDeliver(IPv4Datagram *datagram)
{
    EV_INFO << "Delivering " << datagram << " in OpenFlow IP tunnel.\n";

    if (datagram->getSrcAddress().isUnspecified())
        EV_WARN << "Received datagram '" << datagram->getName() << "' without source address filled in\n";

    // reassemble the packet (if fragmented)
    if (datagram->getFragmentOffset() != 0 || datagram->getMoreFragments()) {
        EV_DETAIL << "Datagram fragment: offset=" << datagram->getFragmentOffset()
                  << ", MORE=" << (datagram->getMoreFragments() ? "true" : "false") << ".\n";

        // erase timed out fragments in fragmentation buffer; check every 10 seconds max
        if (simTime() >= lastCheckTime + 10) {
            lastCheckTime = simTime();
            fragbuf.purgeStaleFragments(simTime() - fragmentTimeoutTime);
        }

        datagram = fragbuf.addFragment(datagram, simTime());
        if (!datagram) {
            EV_DETAIL << "No complete datagram yet.\n";
            return;
        }
        EV_DETAIL << "This fragment completes the datagram.\n";
    }

    // decapsulate and send on appropriate output gate
    int protocol = datagram->getTransportProtocol();

    int gateindex = mapping.findOutputGateForProtocol(protocol);
    // check if the transportOut port are connected, otherwise discard the packet
    if (gateindex >= 0) {
        cGate *outGate = gate("transportOut", gateindex);
        if (outGate->isPathOK()) {
            cPacket *packet = decapsulate(datagram);
            send(packet, outGate);
            emit(LayeredProtocolBase::packetSentToUpperSignal, packet);
            numLocalDeliver++;
            return;
        }
    }

    EV_ERROR << "Transport protocol ID=" << protocol << " not connected for OpenFlow IP tunnel, discarding packet\n";
}

cPacket *IPTunnelingControllerApp::decapsulate(IPv4Datagram *datagram)
{
    // decapsulate transport packet
    cPacket *packet = datagram->decapsulate();

    // create and fill in control info
    IPv4ControlInfo *controlInfo = new IPv4ControlInfo();
    controlInfo->setProtocol(datagram->getTransportProtocol());
    controlInfo->setSrcAddr(datagram->getSrcAddress());
    controlInfo->setDestAddr(datagram->getDestAddress());
    controlInfo->setTypeOfService(datagram->getTypeOfService());
    controlInfo->setInterfaceId(-1);
    controlInfo->setTimeToLive(datagram->getTimeToLive());

    // original IPv4 datagram might be needed in upper layers to send back ICMP error message
    controlInfo->setOrigDatagram(datagram);

    // attach control info
    packet->setControlInfo(controlInfo);

    return packet;
}

} /*end namespace SDN4CoRE*/
