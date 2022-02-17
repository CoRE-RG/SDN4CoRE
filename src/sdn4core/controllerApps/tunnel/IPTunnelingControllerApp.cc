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

//STD
#include <algorithm>
//inet
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/networklayer/arp/ipv4/ARPPacket_m.h"
#include "inet/networklayer/contract/ipv4/IPv4ControlInfo.h"
#include "inet/common/LayeredProtocolBase.h"
//openflow
#include <openflow/openflow/protocol/OFMessageFactory.h>

using namespace inet;
using namespace std;
using namespace openflow;

namespace SDN4CoRE {

Define_Module(IPTunnelingControllerApp);

void IPTunnelingControllerApp::initialize() {
    PacketProcessorBase::initialize();

    hostTable = check_and_cast<HostTable*>(
            this->getModuleByPath(par("hostTablePath")));
    deviceTable = check_and_cast<DeviceTable*>(
            this->getModuleByPath(par("deviceTablePath")));
    topology = check_and_cast<TopologyManagement*>(
            this->getModuleByPath(par("topologyManagementPath")));

    localIps = cStringTokenizer(par("controllerIps"), ",").asVector();
    if (!localIps.empty()) {
        _whitelist.addPacketFilters("ipDst", localIps);
    }

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

void IPTunnelingControllerApp::handleParameterChange(const char* parname) {
    PacketProcessorBase::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "controllerSrcMac")) {
        if (par("controllerSrcMac").stdstringValue() == "auto") {
            // assign automatic address
            this->controllerSrcMac = inet::MACAddress::generateAutoAddress();
            // change module parameter from "auto" to concrete address
            par("controllerSrcMac").setStringValue(this->controllerSrcMac.str());
        } else {
            this->controllerSrcMac.setAddress(par("controllerSrcMac").stringValue());
        }
    }
}

void IPTunnelingControllerApp::refreshDisplay() const {
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

void IPTunnelingControllerApp::receiveSignal(cComponent* src, simsignal_t id,
        cObject* obj, cObject* details) {
    if (id == BootedSignalId) {
        isUp = true;
    }
    PacketProcessorBase::receiveSignal(src, id, obj, details);
}

void IPTunnelingControllerApp::handleMessage(cMessage *msg) {
    if (dynamic_cast<RegisterTransportProtocolCommand *>(msg)) {
        RegisterTransportProtocolCommand *command = check_and_cast<
                RegisterTransportProtocolCommand *>(msg);
        mapping.addProtocolMapping(command->getProtocol(),
                msg->getArrivalGate()->getIndex());
        delete msg;
    } else {
        //we do not implement queueing and delay in this ip version, so handle it directly
        endService(PK(msg));
    }
}

void IPTunnelingControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    if (EthernetIIFrame* eth =
            dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        hostTable->update(packet_in_msg, controller->findSwitchInfoFor(packet_in_msg));
        if (IPv4Datagram* ip =
                dynamic_cast<IPv4Datagram *>(eth->getEncapsulatedPacket())) {
            endService(ip->dup());
        } else if (auto arpPacket = dynamic_cast<ARPPacket *>(eth->getEncapsulatedPacket())) {
            handleIncomingARPPacket(packet_in_msg);
        } else {
            throw cRuntimeError(eth->getEncapsulatedPacket(),
                    "Unexpected packet type");
        }
    }
}

bool IPTunnelingControllerApp::isLocalIp(IPv4Address& addr) {
    return find(localIps.begin(), localIps.end(), addr.str()) != localIps.end();
}

IPv4Address IPTunnelingControllerApp::findBestFittingSrcIp(IPv4Address& dest) {
    if(localIps.empty()) {
        return IPv4Address::UNSPECIFIED_ADDRESS;
    }
    //TODO find best matching src address, e.g. by matching subnets?
    return IPv4Address(localIps[0].c_str());
}

void IPTunnelingControllerApp::endService(cPacket *packet) {
    if (!isUp) {
        EV_ERROR << "IPv4 is down -- discarding message\n";
        delete packet;
        return;
    }
    if (packet->getArrivalGate()->isName("transportIn")) {
        handlePacketFromHL(packet);
    } else {    // from network
        EV_INFO << "Received " << packet << " from OpenFlow network.\n";
        if (auto dgram = dynamic_cast<IPv4Datagram *>(packet)) {
            handleIncomingDatagram(dgram);
        }
    }
}

void IPTunnelingControllerApp::handleIncomingDatagram(IPv4Datagram *datagram) {
    Enter_Method("handleIncomingDatagram");
    ASSERT(datagram);
    emit(LayeredProtocolBase::packetReceivedFromLowerSignal, datagram);
    // hop counter decrement
    datagram->setTimeToLive(datagram->getTimeToLive() - 1);
    // remove control info
    delete datagram->removeControlInfo();
    //route packet
    IPv4Address& destAddr = datagram->getDestAddress();
    EV_DETAIL << "Received datagram `" << datagram->getName() << "' with dest="
                     << destAddr << "\n";
    if (destAddr.isMulticast() && !receiveMulticast) {
        dropPacketFromLower(datagram, "Skip forwarding of multicast datagram (forwarding disabled)");
    } else if (destAddr.isLimitedBroadcastAddress() && !receiveBroadcast) {
        dropPacketFromLower(datagram, "Skip forwarding of broadcast datagram (forwarding disabled)");
    } else if (isLocalIp(destAddr) || destAddr.isMulticast()
            || destAddr.isLimitedBroadcastAddress()) {
        // accept packet and forward!
        reassembleAndDeliver(datagram);
    } else {
        dropPacketFromLower(datagram, "Skip forwarding of datagram with non local ip address");
    }
}

void IPTunnelingControllerApp::handleIncomingARPPacket(OFP_Packet_In* packet_in_msg) {
    ARPPacket* arp = dynamic_cast<ARPPacket *>(packet_in_msg->getEncapsulatedPacket()->getEncapsulatedPacket());
    ASSERT(arp);
    if(arp->getOpcode() == ARP_REQUEST && isLocalIp(arp->getDestIPAddress())) {
        EV << "Received an ARP request for local controller IP, sending reply";
        ARPPacket* reply = new ARPPacket("ControllerArpReply");
        reply->setDestIPAddress(arp->getSrcIPAddress());
        reply->setSrcIPAddress(arp->getDestIPAddress());
        reply->setDestMACAddress(arp->getSrcMACAddress());
        reply->setSrcMACAddress(controllerSrcMac);
        reply->setOpcode(ARP_REPLY);
        HostTable::HostEntry* host = hostTable->getHostForMacAddress(arp->getSrcMACAddress());
        SwitchPort switchPort = topology->findEdgePort(host);
        EthernetIIFrame* frame = etherEncap(reply, host, 0x0806);
        uint32_t outports [] = { (uint32_t) switchPort.port};
        OFP_Packet_Out* packetOut = OFMessageFactory::instance()->createPacketOut(outports, 1, -1, OFP_NO_BUFFER, frame);
        // send to openflow channel
        EV << "Send packet to OpenFlow channel" << '\n';
        numPacketOut++;
        TCPSocket *socket = controller->findSocketForChassisId(switchPort.switchId);
        if(!socket) {
            throw cRuntimeError(("Could not find socket for switch id" + switchPort.switchId).c_str());
        }
        packetOut->setKind(TCP_C_SEND);
        controller->sendPacketOut(packetOut, socket);
    }
}

void IPTunnelingControllerApp::reassembleAndDeliver(IPv4Datagram *datagram) {
    EV_INFO << "Delivering " << datagram << " in OpenFlow IP tunnel.\n";
    if (datagram->getSrcAddress().isUnspecified()) {
        EV_WARN << "Received datagram '" << datagram->getName()
                       << "' without source address filled in\n";
    }
    // reassemble the packet (if fragmented)
    if (datagram->getFragmentOffset() != 0 || datagram->getMoreFragments()) {
        EV_DETAIL << "Datagram fragment: offset="
                         << datagram->getFragmentOffset() << ", MORE="
                         << (datagram->getMoreFragments() ? "true" : "false")
                         << ".\n";
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
    dropPacketFromLower(datagram, "Transport protocol ID=" + to_string(protocol) + " not connected for OpenFlow IP tunnel");
}

void IPTunnelingControllerApp::handlePacketFromHL(cPacket *packet) {
    EV_INFO << "Received " << packet << " from upper layer.\n";
    emit(LayeredProtocolBase::packetReceivedFromUpperSignal, packet);
    if (deviceTable->getDeviceCount() == 0) {
        dropPacketFromUpper(packet, "No devices connected");
        return;
    }
    IPv4ControlInfo *controlInfo = check_and_cast<IPv4ControlInfo *>(
            packet->removeControlInfo());
    IPv4Datagram *datagram = encapsulate(packet, controlInfo);
    // TODO determine the outport from controlInfo interfaceId
    datagramLocalOut(datagram);
}

void IPTunnelingControllerApp::datagramLocalOut(IPv4Datagram* datagram) {
    IPv4Address& destAddr = datagram->getDestAddress();
    EV_DETAIL << "Sending datagram " << datagram << " with destination = "
                     << destAddr << "\n";
    if (destAddr.isMulticast()) {
        if (sendMulticast) {
            routeMulticastPacket(datagram);
        } else {
            dropPacketFromUpper(datagram,
                    "Multicast from upper layer is turned off for OpenFlow IP tunnel");
        }
    } else if (destAddr.isLimitedBroadcastAddress()) { // || rt->isLocalBroadcastAddress(destAddr))
        if (sendBroadcast) {
            routeLocalBroadcastPacket(datagram);
        } else {
            dropPacketFromUpper(datagram,
                    "Broadcast from upper layer is turned off for OpenFlow IP tunnel");
        }
    } else {
        routeUnicastPacket(datagram);
    }
}

void IPTunnelingControllerApp::routeUnicastPacket(IPv4Datagram* datagram) {
    IPv4Address destAddr = datagram->getDestAddress();
    EV_INFO << "Routing " << datagram << " with destination = " << destAddr << ", ";
    // lookup in host table
    HostTable::HostEntry* host = hostTable->getHostForIpAddress(destAddr);
    if(!host) {
        dropPacketFromUpper(datagram, "Unroutable, no host entry could be found");
        //TODO do something like ARP?
    } else {
        //fragment and send
        EV_INFO << "output to host " << host << "\n";
        numForwarded++;
        fragmentAndSend(datagram, host);
    }
}

void IPTunnelingControllerApp::routeMulticastPacket(IPv4Datagram* datagram) {
    throw cRuntimeError("OpenFlow Multicast not yet supported");
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
    throw cRuntimeError("OpenFlow Broadcast not yet supported");
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

cPacket *IPTunnelingControllerApp::decapsulate(IPv4Datagram *datagram) {
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

void IPTunnelingControllerApp::fragmentAndSend(IPv4Datagram *datagram, HostTable::HostEntry* host) {
    // hop counter check
    if (datagram->getTimeToLive() <= 0) {
        dropPacketFromUpper(datagram, "Datagram TTL reached zero");
        return;
    }
    // fill in source address
    if (datagram->getSrcAddress().isUnspecified()) {
        IPv4Address src = findBestFittingSrcIp(datagram->getDestAddress());
        if(src.isUnspecified()) {
            dropPacketFromUpper(datagram, "No controller source IP found for datagram");
            return;
        } else {
            datagram->setSrcAddress(src);
        }
    }
    // send datagram straight out if it doesn't require fragmentation (note: mtu==0 means infinite mtu)
    if (mtu == 0 || datagram->getByteLength() <= mtu) {
        sendDatagramToHost(datagram, host);
        return;
    }
    // if "don't fragment" bit is set, throw datagram away and send ICMP error message
    if (datagram->getDontFragment()) {
        dropPacketFromUpper(datagram, "Datagram larger than MTU and don't fragment bit set");
        return;
    }
    // FIXME some IP options should not be copied into each fragment, check their COPY bit
    int headerLength = datagram->getHeaderLength();
    int payloadLength = datagram->getByteLength() - headerLength;
    int fragmentLength = ((mtu - headerLength) / 8) * 8;    // payload only (without header)
    if (fragmentLength <= 0) {
        throw cRuntimeError("Cannot fragment datagram: MTU=%d too small for header size (%d bytes)", mtu, headerLength); // exception and not ICMP because this is likely a simulation configuration error, not something one wants to simulate
    }
    int offsetBase = datagram->getFragmentOffset();
    int noOfFragments = (payloadLength + fragmentLength - 1) / fragmentLength;
    EV_DETAIL << "Breaking datagram into " << noOfFragments << " fragments\n";
    string fragMsgName = datagram->getName();
    fragMsgName += "-frag";
    // create and send fragments
    for (int offset = 0; offset < payloadLength; offset += fragmentLength) {
        bool lastFragment = (offset + fragmentLength >= payloadLength);
        // length equal to fragmentLength, except for last fragment;
        int thisFragmentLength = lastFragment ? payloadLength - offset : fragmentLength;
        // FIXME is it ok that full encapsulated packet travels in every datagram fragment?
        // should better travel in the last fragment only. Cf. with reassembly code!
        IPv4Datagram *fragment = datagram->dup();
        fragment->setName(fragMsgName.c_str());
        // "more fragments" bit is unchanged in the last fragment, otherwise true
        if (!lastFragment)
            fragment->setMoreFragments(true);
        fragment->setByteLength(headerLength + thisFragmentLength);
        fragment->setFragmentOffset(offsetBase + offset);
        sendDatagramToHost(fragment, host);
    }
    delete datagram;
}

void IPTunnelingControllerApp::sendDatagramToHost(IPv4Datagram *datagram, HostTable::HostEntry* host) {
    ASSERT(host);
    if(datagram->getByteLength() > MAX_ETHERNET_DATA_BYTES) {
        throw cRuntimeError("Datagram to large for Ethernet Frame");
    }
    SwitchPort switchPort = topology->findEdgePort(host);
    if (switchPort.empty()) {
        dropPacketFromUpper(datagram, "Host has no edge port");
        return;
    }
    EthernetIIFrame* frame = etherEncap(datagram, host);
    uint32_t outports [] = { (uint32_t) switchPort.port};
    OFP_Packet_Out* packetOut = OFMessageFactory::instance()->createPacketOut(outports, 1, -1, OFP_NO_BUFFER, frame);
    // send to openflow channel
    EV << "Send packet to OpenFlow channel" << '\n';
    numPacketOut++;
    TCPSocket *socket = controller->findSocketForChassisId(switchPort.switchId);
    if(!socket) {
        throw cRuntimeError(("Could not find socket for switch id" + switchPort.switchId).c_str());
    }
    packetOut->setKind(TCP_C_SEND);
    controller->sendPacketOut(packetOut, socket);
}

IPv4Datagram *IPTunnelingControllerApp::encapsulate(cPacket *transportPacket,
        IPv4ControlInfo *controlInfo) {
    IPv4Datagram *datagram = createIPv4Datagram(transportPacket->getName());
    datagram->setByteLength(IP_HEADER_BYTES);
    datagram->encapsulate(transportPacket);

    // set source and destination address
    IPv4Address dest = controlInfo->getDestAddr();
    datagram->setDestAddress(dest);

    IPv4Address src = controlInfo->getSrcAddr();
    // when source address was given, use it; otherwise it'll get the address
    // of the outgoing interface after routing
    if (!src.isUnspecified() && isLocalIp(src)) {
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

IPv4Datagram *IPTunnelingControllerApp::createIPv4Datagram(const char *name) {
    return new IPv4Datagram(name);
}

void IPTunnelingControllerApp::dropPacketFromUpper(cMessage* packet, string reason) {
    if(!reason.empty()) {
        EV_ERROR << reason << ", dropping packet\n";
    }
    numDropped++;
    emit(LayeredProtocolBase::packetFromUpperDroppedSignal, packet);
    delete packet;
}

void IPTunnelingControllerApp::dropPacketFromLower(cMessage* packet, string reason) {
    if(!reason.empty()) {
        EV_ERROR << reason << ", dropping packet\n";
    }
    numUnroutable++;
    emit(LayeredProtocolBase::packetFromLowerDroppedSignal, packet);
    delete packet;
}

EthernetIIFrame* IPTunnelingControllerApp::etherEncap(
        cPacket* packet, HostTable::HostEntry* host, int etherType) {
    // create ether header
    EthernetIIFrame* frame = new EthernetIIFrame(packet->getName(), 4); // kind 4 = color
    frame->setDest(host->macAddress);
    frame->setSrc(this->controllerSrcMac);
    frame->setEtherType(etherType);
    //TODO maybe support 8021Q options?
    // pack and pad
    ASSERT(frame->getByteLength() > 0); // length comes from msg file
    frame->encapsulate(packet);
    if (frame->getByteLength() < MIN_ETHERNET_FRAME_BYTES) {
        frame->setByteLength(MIN_ETHERNET_FRAME_BYTES); // "padding"
    }
    return frame;
}

} /*end namespace SDN4CoRE*/
