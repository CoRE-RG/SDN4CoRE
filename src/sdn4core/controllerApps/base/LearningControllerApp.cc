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

const char LearningControllerApp::MACTABLEMANAGERMODULEPATH[] =
        "sdn4core.controllerState.mac.MACTableManagement";

void LearningControllerApp::initialize() {
    PacketProcessorBase::initialize();
    // try to locate the macTableManager
    _macManager = tryLocateStateManager<MACTableManagement*>("macTableManagement");
    if(!_macManager) {
        // create the mac manager
        _macManager =
                    dynamic_cast<MACTableManagement*>(createFinalizeAndScheduleDynamicModule(
                            MACTABLEMANAGERMODULEPATH, "macTableManagement",
                            this->getParentModule()->getSubmodule("controllerState"),
                            false));
        if (!_macManager) {
            throw cRuntimeError("Could not create MACTableManagement.");
        }
    }
}

void LearningControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    Enter_Method("processPacketIn()");
    CommonHeaderFields headerFields = extractCommonHeaderFields(packet_in_msg);
    //search map for source mac address and enter
    _macManager->update(headerFields.swInfo, headerFields.src_mac,
            headerFields.inport);
    //find outport or flood
    int outport = _macManager->lookup(headerFields.swInfo,
            headerFields.dst_mac);
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
    Enter_Method("loadOfflineConfigFromXML()");
    //load XML config if specified.
    bool changed = false;
    cXMLElement* xmlDoc = par("configXML").xmlValue();
    if (xmlDoc) { //we got an XML document for config set.
        changed |= _macManager->loadConfigForSwitch(info->getMacAddress(), xmlDoc);
    }
    return changed;
}

string LearningControllerApp::stateToXML() {
    ostringstream oss;
    string tab = "\t";
    oss << "<controller>" << endl;
    _macManager->dumpConfigToStream(oss, 2);
    oss << "</controller>" << endl;
    return oss.str();
}

} /*end namespace SDN4CoRE*/
