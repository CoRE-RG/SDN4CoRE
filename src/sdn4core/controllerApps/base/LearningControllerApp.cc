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

#include "sdn4core/controllerApps/base/LearningControllerApp.h"

#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
//STD
#include <sstream>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/transportlayer/contract/ITransportPacket.h"
//openflow
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"
//CoRE4INET
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"

using namespace inet;
using namespace std;
using namespace openflow;
using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(LearningControllerApp);

void LearningControllerApp::initialize() {
    PacketProcessorBase::initialize();
    hostTable = check_and_cast<HostTable*>(
            this->getModuleByPath(par("hostTablePath")));
    deviceTable = check_and_cast<DeviceTable*>(
            this->getModuleByPath(par("deviceTablePath")));
    topology = check_and_cast<TopologyManagement*>(
            this->getModuleByPath(par("topologyManagementPath")));
}

void LearningControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    Switch_Info* swInfo = controller->findSwitchInfoFor(packet_in_msg);
    hostTable->update(packet_in_msg, swInfo);
    //find outport or flood
    int outport = topology->findOutportAtSwitch(swInfo, packet_in_msg);
    if (outport == -1) {
        floodPacket(packet_in_msg);
    } else {
        oxm_basic_match match = createMatchFromPacketIn(packet_in_msg);
        TCPSocket * socket = controller->findSocketFor(packet_in_msg);
        sendFlowModMessage(OFPFC_ADD, match, outport, socket, getIdleTimeout(),
                getHardTimeout());
        sendPacket(packet_in_msg, outport);
    }
}

oxm_basic_match LearningControllerApp::createMatchFromPacketIn(
        OFP_Packet_In* packetIn) {
    if (packetIn->getBuffer_id() != OFP_NO_BUFFER){
        // todo forward buffered packets.
        throw cRuntimeError("Learning Controller does not yet support buffered packets.");
    }

    auto builder = OFMatchFactory::getBuilder();
    if(par("matchAll").boolValue() || par("matchInport").boolValue()) {
        int inport = packetIn->getEncapsulatedPacket()->getArrivalGate()->getIndex();
        builder->setField(OFPXMT_OFB_IN_PORT, &inport);
    }
    //layer 2
    if (EthernetIIFrame* eth =
            dynamic_cast<EthernetIIFrame *>(packetIn->getEncapsulatedPacket())) {
        if(par("matchAll").boolValue() || par("matchL2Src").boolValue()) {
            MACAddress src = eth->getSrc();
            builder->setField(OFPXMT_OFB_ETH_SRC, &src);
        }
        if(par("matchAll").boolValue() || par("matchL2Dest").boolValue()) {
            MACAddress dest = eth->getDest();
            builder->setField(OFPXMT_OFB_ETH_DST, &dest);
        }
        if(par("matchAll").boolValue() || par("matchL2Type").boolValue()) {
            int type = eth->getEtherType();
            builder->setField(OFPXMT_OFB_ETH_TYPE, &type);
        }
        //qframe
        if (EthernetIIFrameWithQTag* vlan =
                dynamic_cast<EthernetIIFrameWithQTag *>(packetIn->getEncapsulatedPacket())) {
            if(par("matchAll").boolValue() || par("matchL2VID").boolValue()) {
                uint16_t vid = vlan->getVID();
                builder->setField(OFPXMT_OFB_VLAN_VID, &vid);
            }
            if(par("matchAll").boolValue() || par("matchL2PCP").boolValue()) {
                uint8_t pcp = vlan->getPcp();
                builder->setField(OFPXMT_OFB_VLAN_PCP, &pcp);
            }
        }
        //layer 3
        if (INetworkDatagram* ip =
                dynamic_cast<INetworkDatagram *>(eth->getEncapsulatedPacket())) {
            if(par("matchAll").boolValue() || par("matchL3Src").boolValue()) {
                IPv4Address src = ip->getSourceAddress().toIPv4();
                builder->setField(OFPXMT_OFB_IPV4_SRC, &src);
            }
            if(par("matchAll").boolValue() || par("matchL3Dest").boolValue()) {
                IPv4Address dest = ip->getDestinationAddress().toIPv4();
                builder->setField(OFPXMT_OFB_IPV4_DST, &dest);
            }
            if(par("matchAll").boolValue() || par("matchL3Proto").boolValue()) {
                int ipProto = ip->getTransportProtocol();
                builder->setField(OFPXMT_OFB_IP_PROTO, &ipProto);
            }
            //layer 4
            if (ITransportPacket* transport = dynamic_cast<ITransportPacket*>(eth->getEncapsulatedPacket()->getEncapsulatedPacket())) {
                // ports are handled the same for tcp and udp depending on the ip proto type.
                if(par("matchAll").boolValue() || par("matchL4Src").boolValue()) {
                    int src = transport->getSourcePort();
                    builder->setField(OFPXMT_OFB_UDP_SRC, &src);
                }
                if(par("matchAll").boolValue() || par("matchL4Dest").boolValue()) {
                    int dest = transport->getDestinationPort();
                    builder->setField(OFPXMT_OFB_UDP_DST, &dest);
                }
            }
        }
    }
    return builder->build();
}

bool LearningControllerApp::loadOfflineConfigFromXML(Switch_Info* info) {
    Enter_Method
    ("loadOfflineConfigFromXML()");
    //load XML config if specified.
    bool changed = false;
    cXMLElement* xmlDoc = par("configXML").xmlValue();
    if (xmlDoc) { //we got an XML document for config set.
        changed |= hostTable->loadConfigForSwitch(info->getMacAddress(),
                xmlDoc);
        changed |= deviceTable->loadConfigForSwitch(info->getMacAddress(),
                xmlDoc);
        changed |= topology->loadConfigForSwitch(info->getMacAddress(),
                xmlDoc);
    }
    return changed;
}

void LearningControllerApp::processSwitchConnection(
        openflow::Switch_Info* info) {
    deviceTable->addNetworkDevice(info);
    PacketProcessorBase::processSwitchConnection(info);
}

string LearningControllerApp::stateToXML() {
    ostringstream oss;
    string tab = "\t";
    oss << "<controller>" << endl;
    hostTable->dumpConfigToStream(oss, 2);
    deviceTable->dumpConfigToStream(oss, 2);
    topology->dumpConfigToStream(oss, 2);
    oss << "</controller>" << endl;
    return oss.str();
}

} /*end namespace SDN4CoRE*/
