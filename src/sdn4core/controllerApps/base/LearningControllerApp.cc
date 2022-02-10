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
//openflow
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"

using namespace inet;
using namespace std;
using namespace openflow;

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
    CommonHeaderFields headerFields = extractCommonHeaderFields(packetIn);

    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_ETH_DST, &headerFields.dst_mac);
    builder->setField(OFPXMT_OFB_ETH_TYPE, &headerFields.eth_type);
    builder->setField(OFPXMT_OFB_ETH_SRC, &headerFields.src_mac);
    builder->setField(OFPXMT_OFB_IN_PORT, &headerFields.inport);
    oxm_basic_match match = builder->build();

    return match;
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
