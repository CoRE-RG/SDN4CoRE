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
        receiveMulticast = par("receiveMulticast");
        receiveBroadcast = par("receiveBroadcast");
        sendBroadcast = par("sendBroadcast");
        sendMulticast = par("sendMulticast");
        mtu = par("mtu");

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
        handlePacketFromHL(packet);
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
        if (destAddr.isMulticast() && !receiveMulticast) {
            EV_WARN << "Skip forwarding of multicast datagram (forwarding disabled)\n";
            emit(LayeredProtocolBase::packetFromLowerDroppedSignal, datagram);
            delete datagram;
        }
        if(destAddr.isLimitedBroadcastAddress() && !receiveBroadcast) {
            EV_WARN << "Skip forwarding of broadcast datagram (forwarding disabled)\n";
            emit(LayeredProtocolBase::packetFromLowerDroppedSignal, datagram);
            delete datagram;
        }
        else {
            reassembleAndDeliver(datagram);
        }
    }
}

void IPTunnelingControllerApp::handlePacketFromHL(cPacket *packet)
{
    EV_INFO << "Received " << packet << " from upper layer.\n";
    emit(LayeredProtocolBase::packetReceivedFromUpperSignal, packet);

    // TODO if no interface exists, do not send datagram
//    if (ift->getNumInterfaces() == 0) {
//        EV_ERROR << "No interfaces exist, dropping packet\n";
//        numDropped++;
//        emit(LayeredProtocolBase::packetFromUpperDroppedSignal, packet);
//        delete packet;
//        return;
//    }

    // encapsulate
    IPv4ControlInfo *controlInfo = check_and_cast<IPv4ControlInfo *>(packet->removeControlInfo());
    IPv4Datagram *datagram = encapsulate(packet, controlInfo);
    // TODO extract requested interface and next hop
//    const InterfaceEntry *destIE = controlInfo ? const_cast<const InterfaceEntry *>(ift->getInterfaceById(controlInfo->getInterfaceId())) : nullptr;
    datagramLocalOut(datagram);
}

void IPTunnelingControllerApp::datagramLocalOut(IPv4Datagram* datagram) {
    // send
    IPv4Address& destAddr = datagram->getDestAddress();

    EV_DETAIL << "Sending datagram " << datagram << " with destination = " << destAddr << "\n";

    if (destAddr.isMulticast()) {
        if(sendMulticast) {
            routeMulticastPacket(datagram);
        }
        else {
            EV_ERROR << "Multicast from upper layer is turned off for OpenFlow IP tunnel, packet dropped\n";
            numDropped++;
            emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
            delete datagram;
        }
    }
    else if (destAddr.isLimitedBroadcastAddress()) {// || rt->isLocalBroadcastAddress(destAddr))
        if (sendBroadcast) {
            routeLocalBroadcastPacket(datagram);
        }
        else {
            EV_ERROR << "Broadcast from upper layer is turned off for OpenFlow IP tunnel, packet dropped\n";
            numDropped++;
            emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
            delete datagram;
        }
    } else {
        routeUnicastPacket(datagram);
    }
}

void IPTunnelingControllerApp::routeUnicastPacket(IPv4Datagram* datagram) {
//    IPv4Address destAddr = datagram->getDestAddress();
//    EV_INFO << "Routing " << datagram << " with destination = " << destAddr << ", ";
//
//    IPv4Address nextHopAddr;
//    // if output port was explicitly requested, use that, otherwise use IPv4 routing
//    if (destIE) {
//        EV_DETAIL << "using manually specified output interface " << destIE->getName() << "\n";
//        // and nextHopAddr remains unspecified
//        if (!requestedNextHopAddress.isUnspecified())
//            nextHopAddr = requestedNextHopAddress;
//        // special case ICMP reply
//        else if (destIE->isBroadcast()) {
//            // if the interface is broadcast we must search the next hop
//            const IPv4Route *re = rt->findBestMatchingRoute(destAddr);
//            if (re && re->getInterface() == destIE)
//                nextHopAddr = re->getGateway();
//        }
//    }
//    else {
//        // use IPv4 routing (lookup in routing table)
//        const IPv4Route *re = rt->findBestMatchingRoute(destAddr);
//        if (re) {
//            destIE = re->getInterface();
//            nextHopAddr = re->getGateway();
//        }
//    }
//
//    if (!destIE) {    // no route found
//        EV_WARN << "unroutable, sending ICMP_DESTINATION_UNREACHABLE, dropping packet\n";
//        numUnroutable++;
//        emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
//        icmp->sendErrorMessage(datagram, fromIE ? fromIE->getInterfaceId() : -1, ICMP_DESTINATION_UNREACHABLE, 0);
//    }
//    else {    // fragment and send
//        L3Address nextHop(nextHopAddr);
//        if (fromIE != nullptr) {
//            if (datagramForwardHook(datagram, fromIE, destIE, nextHop) != INetfilter::IHook::ACCEPT)
//                return;
//            nextHopAddr = nextHop.toIPv4();
//        }
//
//        EV_INFO << "output interface = " << destIE->getName() << ", next hop address = " << nextHopAddr << "\n";
//        numForwarded++;
//        fragmentAndSend(datagram, destIE, nextHopAddr);
//    }
}

void IPTunnelingControllerApp::routeMulticastPacket(IPv4Datagram* datagram) {
//    const InterfaceEntry *ie = nullptr;
//    if (multicastIFOption) {
//        ie = multicastIFOption;
//        EV_DETAIL << "multicast packet routed by socket option via output interface " << ie->getName() << "\n";
//    }
//    if (!ie) {
//        IPv4Route *route = rt->findBestMatchingRoute(datagram->getDestAddress());
//        if (route)
//            ie = route->getInterface();
//        if (ie)
//            EV_DETAIL << "multicast packet routed by routing table via output interface " << ie->getName() << "\n";
//    }
//    if (!ie) {
//        ie = rt->getInterfaceByAddress(datagram->getSrcAddress());
//        if (ie)
//            EV_DETAIL << "multicast packet routed by source address via output interface " << ie->getName() << "\n";
//    }
//    if (!ie) {
//        ie = ift->getFirstMulticastInterface();
//        if (ie)
//            EV_DETAIL << "multicast packet routed via the first multicast interface " << ie->getName() << "\n";
//    }
//    return ie;
}

void IPTunnelingControllerApp::routeLocalBroadcastPacket(
        IPv4Datagram* datagram) {
    // The destination address is 255.255.255.255 or local subnet broadcast address.
    // We always use 255.255.255.255 as nextHopAddress, because it is recognized by ARP,
    // and mapped to the broadcast MAC address.
//    if (destIE != nullptr) {
//        fragmentAndSend(datagram, destIE, IPv4Address::ALLONES_ADDRESS);
//    }
//    else
//    if (forceBroadcast) {
//        // forward to each interface including loopback
//        for (int i = 0; i < ift->getNumInterfaces(); i++) {
//            const InterfaceEntry *ie = ift->getInterface(i);
//            fragmentAndSend(datagram->dup(), ie, IPv4Address::ALLONES_ADDRESS);
//        }
//        delete datagram;
//    }
//    else {
//        numDropped++;
//        emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
//        delete datagram;
//    }
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

void IPTunnelingControllerApp::fragmentAndSend(IPv4Datagram *datagram)
{
//    // fill in source address
//    if (datagram->getSrcAddress().isUnspecified())
//        datagram->setSrcAddress(ie->ipv4Data()->getIPAddress());
//
//    // hop counter check
//    if (datagram->getTimeToLive() <= 0) {
//        emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
//        EV_WARN << "datagram TTL reached zero, packet dropped\n";
//        numDropped++;
//        delete datagram;
//        return;
//    }
//
//    // send datagram straight out if it doesn't require fragmentation (note: mtu==0 means infinite mtu)
//    if (mtu == 0 || datagram->getByteLength() <= mtu) {
//        sendDatagramToOutput(datagram, ie, nextHopAddr);
//        return;
//    }
//
//    // if "don't fragment" bit is set, throw datagram away and send ICMP error message
//    if (datagram->getDontFragment()) {
//        emit(LayeredProtocolBase::packetFromUpperDroppedSignal, datagram);
//        EV_WARN << "datagram larger than MTU and don't fragment bit set, packet dropped\n";
//        numDropped++;
//        delete datagram;
//        return;
//    }
//
//    // FIXME some IP options should not be copied into each fragment, check their COPY bit
//    int headerLength = datagram->getHeaderLength();
//    int payloadLength = datagram->getByteLength() - headerLength;
//    int fragmentLength = ((mtu - headerLength) / 8) * 8;    // payload only (without header)
//    int offsetBase = datagram->getFragmentOffset();
//    if (fragmentLength <= 0)
//        throw cRuntimeError("Cannot fragment datagram: MTU=%d too small for header size (%d bytes)", mtu, headerLength); // exception and not ICMP because this is likely a simulation configuration error, not something one wants to simulate
//
//    int noOfFragments = (payloadLength + fragmentLength - 1) / fragmentLength;
//    EV_DETAIL << "Breaking datagram into " << noOfFragments << " fragments\n";
//
//    // create and send fragments
//    std::string fragMsgName = datagram->getName();
//    fragMsgName += "-frag";
//
//    for (int offset = 0; offset < payloadLength; offset += fragmentLength) {
//        bool lastFragment = (offset + fragmentLength >= payloadLength);
//        // length equal to fragmentLength, except for last fragment;
//        int thisFragmentLength = lastFragment ? payloadLength - offset : fragmentLength;
//
//        // FIXME is it ok that full encapsulated packet travels in every datagram fragment?
//        // should better travel in the last fragment only. Cf. with reassembly code!
//        IPv4Datagram *fragment = datagram->dup();
//        fragment->setName(fragMsgName.c_str());
//
//        // "more fragments" bit is unchanged in the last fragment, otherwise true
//        if (!lastFragment)
//            fragment->setMoreFragments(true);
//
//        fragment->setByteLength(headerLength + thisFragmentLength);
//        fragment->setFragmentOffset(offsetBase + offset);
//
//        sendDatagramToOutput(fragment, ie, nextHopAddr);
//    }
//
//    delete datagram;
}

void IPTunnelingControllerApp::sendDatagramToOutput(IPv4Datagram *datagram)
{
//    if (nextHopAddr.isUnspecified()) {
//        nextHopAddr = destAddress;
//    }
//
//    MACAddress nextHopMacAddr;    // unspecified
//    nextHopMacAddr = resolveNextHopMacAddress(datagram, nextHopAddr, ie);
//
//    sendPacketToIeee802NIC(datagram, ie, nextHopMacAddr, ETHERTYPE_IPv4);
}

IPv4Datagram *IPTunnelingControllerApp::encapsulate(cPacket *transportPacket, IPv4ControlInfo *controlInfo)
{
    IPv4Datagram *datagram = createIPv4Datagram(transportPacket->getName());
    datagram->setByteLength(IP_HEADER_BYTES);
    datagram->encapsulate(transportPacket);

    // set source and destination address
    IPv4Address dest = controlInfo->getDestAddr();
    datagram->setDestAddress(dest);

    IPv4Address src = controlInfo->getSrcAddr();
    // when source address was given, use it; otherwise it'll get the address
    // of the outgoing interface after routing
    if (!src.isUnspecified()) {
        datagram->setSrcAddress(src);
    }

    // set other fields
    datagram->setTypeOfService(controlInfo->getTypeOfService());

    datagram->setIdentification(curFragmentId++);
    datagram->setMoreFragments(false);
    datagram->setDontFragment(controlInfo->getDontFragment());
    datagram->setFragmentOffset(0);

    short ttl;
    if (controlInfo->getTimeToLive() > 0)
        ttl = controlInfo->getTimeToLive();
    else if (datagram->getDestAddress().isLinkLocalMulticast())
        ttl = 1;
    else if (datagram->getDestAddress().isMulticast())
        ttl = defaultMCTimeToLive;
    else
        ttl = defaultTimeToLive;
    datagram->setTimeToLive(ttl);
    datagram->setTransportProtocol(controlInfo->getProtocol());

    // setting IPv4 options is currently not supported

    return datagram;
}

IPv4Datagram *IPTunnelingControllerApp::createIPv4Datagram(const char *name)
{
    return new IPv4Datagram(name);
}

} /*end namespace SDN4CoRE*/
