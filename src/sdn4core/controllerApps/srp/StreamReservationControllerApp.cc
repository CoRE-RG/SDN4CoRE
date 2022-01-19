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
// c Timo Haeckel, Tobias Haugg, for HAW Hamburg
// 

#include "sdn4core/controllerApps/srp/StreamReservationControllerApp.h"

#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
//STD
#include <sstream>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//AUTO_GENERATED MESSAGES
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
//openflow
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/controller/OF_Controller.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"

using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(StreamReservationControllerApp);

const char StreamReservationControllerApp::SRPTABLEMANAGERMODULEPATH[] = "sdn4core.controllerState.srp.SRPTableManagement";

void StreamReservationControllerApp::initialize() {
    PacketProcessorBase::initialize();
    // try to locate the macTableManager
    _srpManager = tryLocateStateManager<SRPTableManagement*>("srpTableManagement");
    if(!_srpManager) {
            // create the mac manager
        _srpManager = dynamic_cast<SRPTableManagement*>(
                createFinalizeAndScheduleDynamicModule(SRPTABLEMANAGERMODULEPATH,
                        "srpTableManagement", this->getParentModule()->getSubmodule("controllerState"), false));
        if(!_srpManager){
            throw cRuntimeError("Could not create SRPTableManagement.");
        }
    }
}

void StreamReservationControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    if (dynamic_cast<CoRE4INET::SRPFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        doSRP(packet_in_msg);
    }
}

void StreamReservationControllerApp::doSRP(OFP_Packet_In* packet_in_msg) {
    bool updated = true;

    Switch_Info * swInfo = controller->findSwitchInfoFor(packet_in_msg);
    int arrivalPort = packet_in_msg->getMatch().OFB_IN_PORT;
    //get SRP Frame
    if (CoRE4INET::SRPFrame * srpFrame =
            dynamic_cast<CoRE4INET::SRPFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        if (CoRE4INET::TalkerAdvertise* talkerAdvertise =
                dynamic_cast<CoRE4INET::TalkerAdvertise*>(srpFrame)) {
            updated = _srpManager->registerTalker(swInfo, arrivalPort, talkerAdvertise);
            //save talker and do nothing else.
        } else if (CoRE4INET::ListenerReady* listenerReady =
                dynamic_cast<CoRE4INET::ListenerReady*>(srpFrame)) {
            //save listener
            updated = _srpManager->registerListener(swInfo, arrivalPort, listenerReady);
            if (updated) {
                SRPTableManagement::SRPForwardingInfo_t* fwd = _srpManager->getForwardingInfoForStreamID (swInfo, listenerReady->getStreamID(), listenerReady->getVlan_identifier());
                auto builder = OFMatchFactory::getBuilder();
                builder->setField(OFPXMT_OFB_IN_PORT, &fwd->inPort);
                builder->setField(OFPXMT_OFB_ETH_DST, &fwd->dest);
                uint16_t avb_type = 0x8100;
                builder->setField(OFPXMT_OFB_ETH_TYPE, &avb_type);
                builder->setField(OFPXMT_OFB_VLAN_VID, &fwd->vlanID);
                builder->setField(OFPXMT_OFB_VLAN_PCP, &fwd->pcp);
                oxm_basic_match match = builder->build();
                TCPSocket * socket = controller->findSocketFor(packet_in_msg);
                sendSRPFlowModMessage(OFPFC_ADD, match, fwd->outports, socket, this->getIdleTimeout(), this->getHardTimeout());
                delete fwd;
            }
        }
        //forward original to the switch it came from.
        forwardSRPPacket(packet_in_msg);
    }
}

void StreamReservationControllerApp::sendSRPFlowModMessage(ofp_flow_mod_command mod_com, const oxm_basic_match &match, std::vector<int> outports, TCPSocket * socket, int idleTimeOut =0 , int hardTimeOut=0){
    EV << "sendFlowModMessage" << '\n';
    numFlowMod++;
    int numOutPorts = outports.size();
    uint32_t out[numOutPorts];
    for(int i=0; i<numOutPorts; i++) {
        out[i] = outports[i];
    }
    OFP_Flow_Mod* flow_mod_msg = OFMessageFactory::instance()->createFlowModMessage(mod_com, match, 5000, out, numOutPorts, idleTimeOut, hardTimeOut);
    socket->send(flow_mod_msg);
}

void StreamReservationControllerApp::forwardSRPPacket(OFP_Packet_In* packet_in_msg) {
    TCPSocket *socket = controller->findSocketFor(packet_in_msg);
    //TODO use experimenter message instead of packet out!
    OFP_Packet_Out *packetOut = new OFP_Packet_Out("forwardSRP");
    packetOut->getHeader().version = OFP_VERSION;
#if OFP_VERSION_IN_USE == OFP_100
    packetOut->getHeader().type = OFPT_VENDOR;
    // TODO Add Experimenter Message Structure!
#elif OFP_VERSION_IN_USE == OFP_151
    packetOut->getHeader().type = OFPT_EXPERIMENTER;
        // TODO Add Experimenter Message Structure!
#endif
    packetOut->setBuffer_id(packet_in_msg->getBuffer_id());
    packetOut->setByteLength(24);
    omnetpp::cPacket* packet = packet_in_msg->getEncapsulatedPacket();
    //check if srp packet and copy it.
    //forward to controller
    CoRE4INET::SRPFrame* toSwtich = dynamic_cast<CoRE4INET::SRPFrame *>(packet->dup());
    packetOut->encapsulate(toSwtich);
    packetOut->setIn_port(packet_in_msg->getMatch().OFB_IN_PORT);
    socket->send(packetOut);
}

bool StreamReservationControllerApp::loadOfflineConfigFromXML(Switch_Info* info) {
    Enter_Method("loadOfflineConfigFromXML()");
    //load XML config if specified.
    bool changed = false;
    cXMLElement* xmlDoc = par("configXML").xmlValue();
    if(xmlDoc)
    {//we got an XML document for config set.
        changed |= _srpManager->loadConfigForSwitch(info->getMacAddress(), xmlDoc);
    }
    return changed;
}

void StreamReservationControllerApp::processSwitchConnection(openflow::Switch_Info* info) {
    Enter_Method("processSwitchConnection()");
    loadOfflineConfigFromXML(info);
    installSRPRule(info);
}

void StreamReservationControllerApp::installSRPRule(openflow::Switch_Info* info){
    auto builder = OFMatchFactory::getBuilder();
    uint16_t avb_type = 0x22EA;
    builder->setField(OFPXMT_OFB_ETH_TYPE, &avb_type);
    oxm_basic_match match = builder->build();
    sendSRPFlowModMessage(OFPFC_ADD, match,OFPP_CONTROLLER,info->getSocket());
}

std::string StreamReservationControllerApp::stateToXML() {
    ostringstream oss;
    string tab = "\t";
    oss << "<controller>" << endl;
    _srpManager->dumpConfigToStream(oss, 2);
    oss << "</controller>" << endl;
    return oss.str();
}

} /*end namespace SDN4CoRE*/
