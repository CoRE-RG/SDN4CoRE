//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// c Timo Haeckel, for HAW Hamburg
// 

#include "sdn4core/controllerApps/lldp/LLDPControllerApp.h"

//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//openflow
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"
#include "openflow/messages/LLDP_m.h"

#define LLDP_ETHER_TYPE 0x88CC

using namespace inet;
using namespace std;
using namespace openflow;

namespace SDN4CoRE {

Define_Module(LLDPControllerApp);

void LLDPControllerApp::initialize() {
    PacketProcessorBase::initialize();
    deviceTable = check_and_cast<DeviceTable*>(
            this->getModuleByPath(par("deviceTablePath")));
    trigger = new cMessage("LLDP Trigger Message");
}

void LLDPControllerApp::handleParameterChange(const char* parname) {
    PacketProcessorBase::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "cycle")) {
        cycle = par("cycle");
    }
    if (!parname || !strcmp(parname, "lldpOnNewConnection")) {
        lldpOnNewConnection = par("lldpOnNewConnection");
    }
}

void LLDPControllerApp::handleMessage(cMessage* msg) {
    if (msg == this->trigger) {
        EV << "Sending Link Layer Discovery through connected switches";
        sendLLDP();
        scheduleNextCycle();
    } else {
        PacketProcessorBase::handleMessage(msg);
    }
}

void LLDPControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    // we should only receive Ethernet LLDP frames because of the packet processor!
    if (EthernetIIFrame *eth =
            dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        if (LLDP *lldp = dynamic_cast<LLDP *>(eth->getEncapsulatedPacket())) {
            string outSwitchId = lldp->getChassisID();
            int outport = lldp->getPortID();
            string inSwitchId =
                    controller->findSwitchInfoFor(packet_in_msg)->getMacAddress();
            int inport =
                    packet_in_msg->getEncapsulatedPacket()->getArrivalGate()->getIndex();
            deviceTable->linkNetworkDevices(outSwitchId, outport, inSwitchId,
                    inport);
        } else {
            throw cRuntimeError(
                    "The received Ethernet Frame does not contain LLDP");
        }
    } else {
        throw cRuntimeError("Received a non Ethernet Frame");
    }
}

void LLDPControllerApp::processSwitchConnection(openflow::Switch_Info* info) {
    deviceTable->addNetworkDevice(info);
    PacketProcessorBase::processSwitchConnection(info);
    EV << "New switch connected, installing LLDP Flow";
    installLLDPFLow(info);
    if (lldpOnNewConnection) {
        sendLLDP();
    }
    if(!this->trigger->isScheduled()) { // this is the first switch we have not yet started with lldp
        scheduleNextCycle();
    }
}

void LLDPControllerApp::scheduleNextCycle() {
    Enter_Method_Silent
    ();
    this->cancelEvent(this->trigger);
    if (deviceTable->getDeviceCount() > 0) {
        this->scheduleAt(simTime() + cycle, this->trigger);
        EV << "Next LLDP cycle scheduled in " << cycle;
    }
}

void LLDPControllerApp::installLLDPFLow(openflow::Switch_Info* swInfo) {
    auto builder = OFMatchFactory::getBuilder();
    uint16_t lldp_type = LLDP_ETHER_TYPE;
    builder->setField(OFPXMT_OFB_ETH_TYPE, &lldp_type);
    oxm_basic_match match = builder->build();
    sendFlowModMessage(OFPFC_ADD, match, OFPP_CONTROLLER, swInfo->getSocket(),
            0, 0);
}

void LLDPControllerApp::sendLLDP() {
    for (auto& device : *(controller->getSwitchesList())) {
        if (strcmp(device.getMacAddress().c_str(), "") == 0) {
            //only use full connections
            continue;
        }
        sendLLDP(&device);
    }
}

void LLDPControllerApp::sendLLDP(openflow::Switch_Info* swInfo) {
    if (swInfo) {
        for (int i = 0; i < swInfo->getNumOfPorts(); i++) {
            EthernetIIFrame* lldp = createLLDPPacket(swInfo->getMacAddress(),
                    i);
            uint32_t ports[] = { (uint32_t) i };
            OFP_Packet_Out* packetOut =
                    OFMessageFactory::instance()->createPacketOut(ports, 1, -1,
                            OFP_NO_BUFFER, lldp);
            controller->sendPacketOut(packetOut, swInfo->getSocket());
        }
    }
}

EthernetIIFrame* LLDPControllerApp::createLLDPPacket(string switchId,
        int port) {
    LLDP *lldpPacket = new LLDP("LLDP");
    lldpPacket->setPortID(port);
    lldpPacket->setChassisID(switchId.c_str());

    EthernetIIFrame *eth = new EthernetIIFrame(lldpPacket->getName());
    eth->setSrc(MACAddress(switchId.c_str()));
    eth->setDest(MACAddress::BROADCAST_ADDRESS);
    eth->setEtherType(LLDP_ETHER_TYPE);
    eth->encapsulate(lldpPacket);
    if (eth->getByteLength() < MIN_ETHERNET_FRAME_BYTES) {
        eth->setByteLength(MIN_ETHERNET_FRAME_BYTES);  // "padding"
    }
    return eth;
}

} /*end namespace SDN4CoRE*/
