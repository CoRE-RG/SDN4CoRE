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

#include "sdn4core/controllerApps/avb/AVBLearningControllerApp.h"

#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
//STD
#include <sstream>
#include <algorithm>
//inet
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//AUTO_GENERATED MESSAGES
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
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
using namespace omnetpp;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(AVBLearningControllerApp);

const char AVBLearningControllerApp::SRPTABLEMANAGERMODULEPATH[] = "sdn4core.controllerApps.utility.SRPTableManagement";

const char AVBLearningControllerApp::MACTABLEMANAGERMODULEPATH[] = "sdn4core.controllerApps.utility.MACTableManagement";

AVBLearningControllerApp::AVBLearningControllerApp() {
    _macManager = nullptr;
    _srpManager = nullptr;
}

AVBLearningControllerApp::~AVBLearningControllerApp() {
}

void AVBLearningControllerApp::initialize() {
    AbstractControllerApp::initialize();

    _srpManager = dynamic_cast<SRPTableManagement*>(
            createFinalizeAndScheduleDynamicModule(SRPTABLEMANAGERMODULEPATH,
                    "srpTableManagement", this->getParentModule()->getSubmodule("controllerState"), false));
    if(!_srpManager){
        throw cRuntimeError("Could not create SRPTableManagement.");
    }
    _macManager = dynamic_cast<MACTableManagement*>(
            createFinalizeAndScheduleDynamicModule(MACTABLEMANAGERMODULEPATH,
                    "macTableManagement", this->getParentModule()->getSubmodule("controllerState"), false));
    if(!_macManager){
        throw cRuntimeError("Could not create MACTableManagement.");
    }

}

void AVBLearningControllerApp::handleParameterChange(const char* parname)
{
    AbstractControllerApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "flowModIdleTimeOut"))
    {
        _idleTimeout = par("flowModIdleTimeOut");
    }
    if (!parname || !strcmp(parname, "flowModHardTimeOut"))
    {
        _hardTimeout = par("flowModHardTimeOut");
    }
}

void AVBLearningControllerApp::receiveSignal(cComponent* src, simsignal_t id,
        cObject* obj, cObject* details) {
    AbstractControllerApp::receiveSignal(src, id, obj, details);

    if (id == PacketInSignalId) {
        EV << "LearningSwitch::PacketIn" << endl;
        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            if (dynamic_cast<CoRE4INET::SRPFrame *>(packet_in->getEncapsulatedPacket())) {
                doSRP(packet_in);
            } else if (dynamic_cast<CoRE4INET::AVBFrame *>(packet_in->getEncapsulatedPacket())) {
                // do nothing because the rule should be implemented allready.
                //throw cRuntimeError("Controller Received AVB Frame, this should never happen.");
            } else {
                doSwitching(packet_in);
            }
        }
    } else if(id == PacketFeatureReplySignalId){
        if (Open_Flow_Message *msg = dynamic_cast<Open_Flow_Message *>(obj)) {
            //new switch registered check if we allready got a offline config for it.
            loadOfflineConfigFromXML(controller->findSwitchInfoFor(msg));
        }
    }
}

oxm_basic_match AVBLearningControllerApp::createMatchFromPacketIn(
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

void AVBLearningControllerApp::doSwitching(OFP_Packet_In* packet_in_msg) {
    CommonHeaderFields headerFields = extractCommonHeaderFields(packet_in_msg);

    //search map for source mac address and enter
    _macManager->update(headerFields.swInfo, headerFields.src_mac, headerFields.inport);

    //find outport or flood
    int outport = _macManager->lookup(headerFields.swInfo, headerFields.dst_mac);
    if (outport == MAC_MANAGER_OUTPORT_FLOOD) {
        if(!headerFields.dst_mac.isBroadcast()){
            if (unknownMacs.count(headerFields.swInfo) <= 0) {
                unknownMacs[headerFields.swInfo] = map<string, int>();
                unknownMacs[headerFields.swInfo][headerFields.dst_mac.str()] = headerFields.inport;
            } else {
                if (unknownMacs[headerFields.swInfo].count(headerFields.dst_mac.str()) <= 0) {
                    unknownMacs[headerFields.swInfo][headerFields.dst_mac.str()] = headerFields.inport;
                }
            }
        }
        floodPacket(packet_in_msg);
    } else {
        oxm_basic_match match = createMatchFromPacketIn(packet_in_msg);

        TCPSocket * socket = controller->findSocketFor(packet_in_msg);
        sendFlowModMessage(OFPFC_ADD, match, outport, socket, _idleTimeout,
                _hardTimeout);
        sendPacket(packet_in_msg, outport);
    }
}

void AVBLearningControllerApp::doSRP(OFP_Packet_In* packet_in_msg) {
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
                sendSRPFlowModMessage(OFPFC_ADD, match, fwd->outports, socket, _idleTimeout, _hardTimeout);

                delete fwd;
            }
        }

        //forward original to the switch it came from.
        forwardSRPPacket(packet_in_msg);
    }

}

void AVBLearningControllerApp::sendSRPFlowModMessage(ofp_flow_mod_command mod_com, const oxm_basic_match &match, std::vector<int> outports, TCPSocket * socket, int idleTimeOut =0 , int hardTimeOut=0){
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

void AVBLearningControllerApp::forwardSRPPacket(OFP_Packet_In* packet_in_msg) {
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

void AVBLearningControllerApp::finish(){
    AbstractControllerApp::finish();

    for (std::pair<Switch_Info*,map<string, int>> iter : unknownMacs){
        cout << "Unknown Mac Addresses at Switch " << iter.first->getMacAddress() << endl;
        for (std::pair<string, int> report : iter.second){
            int outport = _macManager->lookup(iter.first, MACAddress(report.first.c_str()));
            if(outport == MAC_MANAGER_OUTPORT_FLOOD) {
                cout << "Still Unknown: ";
            } else {
                cout << "Discovered: Outport " << outport << ", ";
            }
            cout << "Inport " << to_string(report.second) << ", Dst Mac " << report.first << endl;
        }
    }

    cout << stateToXML();
}

bool AVBLearningControllerApp::loadOfflineConfigFromXML(Switch_Info* info) {
    //load XML config if specified.
    bool changed = false;
    cXMLElement* xmlDoc = par("configXML").xmlValue();
    if(xmlDoc)
    {//we got an XML document for config set.
        cXMLElement* controllerXML = xmlDoc->getFirstChildWithAttribute("controllerapp", "type", "AVBLearningControllerApp");
        if(controllerXML)
        {//the XML document contains config for this type of controller app.
            //get the switch ids.
            cXMLElement* macManagerXML = controllerXML->getFirstChildWithTag("macManager");
            if(macManagerXML){

                cXMLElement* switchXML = macManagerXML->getFirstChildWithAttribute("mactable","switch_id",info->getMacAddress().c_str());
                if(switchXML){
                    cXMLElementList macTableXML = switchXML->getChildrenByTagName("entry");
                    if(!macTableXML.empty())
                    {// we git mac entries for this switch.
                        //check if there already is a mac table for the switch
                        std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> >* lut = _macManager->getLookupTable();


                        //fill the map.
                        for(size_t i=0; i<macTableXML.size(); i++){
                            MACAddress mac = MACAddress(macTableXML[i]->getAttribute("mac"));
                            if(!mac.isUnspecified()){
                                if(const char * portC = macTableXML[i]->getAttribute("port")){
                                    uint32_t port = atoi(portC);
                                    bool insert = true;
                                    //check if the entry exists.
                                    if((*lut)[info].find(mac) != (*lut)[info].end()){
                                        //mac allready exists.
                                        insert = false;
                                    }
                                    if(insert) {
                                        (*lut)[info][mac] = port;
                                        changed = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            //get the switch ids.
            cXMLElement* srpManagerXML = controllerXML->getFirstChildWithTag("srpManager");
            if(srpManagerXML){
                _srpManager->importFromXML(info, srpManagerXML);
            }
        }
    }
    return changed;
}

std::string AVBLearningControllerApp::stateToXML() {

    ostringstream oss;
    string tab = "    ";
    oss << "<config>" << endl;
    oss << tab << "<controllerapp type=\"AVBLearningControllerApp\">" << endl;

    //mac table
    oss << tab << tab << "<macManager>" << endl;
    std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> >* lut = _macManager->getLookupTable();
    for(auto switchMap =lut->begin();switchMap != lut->end();++switchMap){
        oss << tab << tab << tab << "<mactable switch_id=\"" << switchMap->first->getMacAddress() << "\">" << endl;

        for(auto macToPortMap =switchMap->second.begin();macToPortMap != switchMap->second.end();++macToPortMap){
            oss << tab << tab << tab << tab << "<entry mac=\"" << macToPortMap->first.str() << "\" port=\"" << macToPortMap->second << "\" />" << endl;
        }

        oss << tab << tab << tab << "</mactable>" << endl;
    }
    oss << tab << tab << "</macManager>" << endl;

    //srp table
    oss << _srpManager->exportToXML();

    oss << tab << "</controllerapp>" << endl;
    oss << "</config>" << endl;
    return oss.str();
}

} /*end namespace SDN4CoRE*/
