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

#include <omnetpp.h>
#include <openflow/messages/openflowprotocol/OFP_Flow_Mod.h>
#include <openflow/messages/openflowprotocol/OFP_Packet_In.h>
#include <openflow/openflow/controller/OF_Controller.h>
#include <sdn4core/controllerApps/RTEthernetControllerApp.h>
#include <sdn4core/controller/services/avb/SRP/OF_CTRL_SRPTable.h>
#include "openflow/openflow/util/OFMessageFactory.h"
#include <iostream>

#include "core4inet/base/avb/AVBDefs.h"
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include <sstream>

using namespace inet;
using namespace CoRE4INET;
using namespace std;
using namespace omnetpp;
using namespace ofp;

namespace SDN4CoRE{

Define_Module(RTEthernetControllerApp);

RTEthernetControllerApp::RTEthernetControllerApp() {
    _macManager = nullptr;
    _srpManager = nullptr;
}

RTEthernetControllerApp::~RTEthernetControllerApp() {
    if (_macManager)
        delete _macManager;
    if (_srpManager)
        delete _srpManager;
}

void RTEthernetControllerApp::initialize() {
    AbstractControllerApp::initialize();

    _srpManager = new SRPTableManagement();
    _macManager = new MACTableManagement();

}

void RTEthernetControllerApp::handleParameterChange(const char* parname)
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

void RTEthernetControllerApp::receiveSignal(cComponent* src, simsignal_t id,
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
        if (OFP_Message *msg = dynamic_cast<OFP_Message *>(obj)) {
            //new switch registered check if we allready got a offline config for it.
            loadOfflineConfigFromXML(controller->findSwitchInfoFor(msg));
        }
    }
}

oxm_basic_match RTEthernetControllerApp::createMatchFromPacketIn(
        OFP_Packet_In* packetIn) {
    CommonHeaderFields headerFields = extractCommonHeaderFields(packetIn);
    oxm_basic_match match = oxm_basic_match();
    match.dl_dst = headerFields.dst_mac;
    match.dl_type = headerFields.eth_type;
    match.dl_src = headerFields.src_mac;
    match.in_port = headerFields.inport;
    match.wildcards = 0;
    //TODO fix wildcards for OFP151!
#if OFP_VERSION_IN_USE == OFP_100
    //        match.wildcards |= OFPFW_IN_PORT;
    //        match.wildcards |= OFPFW_DL_TYPE;
    //        match.wildcards |= OFPFW_DL_SRC;
    //        match.wildcards |= OFPFW_DL_DST;
    match.wildcards |= OFPFW_DL_VLAN;
    match.wildcards |= OFPFW_DL_VLAN_PCP;
    match.wildcards |= OFPFW_NW_PROTO;
    match.wildcards |= OFPFW_NW_SRC_ALL;
    match.wildcards |= OFPFW_NW_DST_ALL;
    match.wildcards |= OFPFW_TP_SRC;
    match.wildcards |= OFPFW_TP_DST;
    match.wildcards |= OFPFW_DL_AVBSID;
#endif
    return match;
}

void RTEthernetControllerApp::doSwitching(OFP_Packet_In* packet_in_msg) {
    CommonHeaderFields headerFields = extractCommonHeaderFields(packet_in_msg);

    //search map for source mac address and enter
    _macManager->updateMacTable(headerFields);

    //find outport or flood
    int outport = _macManager->getOutPort(headerFields);
    if (outport == MAC_MANAGER_OUTPORT_FLOOD) {
        floodPacket(packet_in_msg);
    } else {
        oxm_basic_match match = createMatchFromPacketIn(packet_in_msg);

        TCPSocket * socket = controller->findSocketFor(packet_in_msg);
        sendFlowModMessage(OFPFC_ADD, match, outport, socket, _idleTimeout,
                _hardTimeout);
        sendPacket(packet_in_msg, outport);
    }
}

void RTEthernetControllerApp::doSRP(OFP_Packet_In* packet_in_msg) {
    bool updated = true;

    Switch_Info * swInfo = controller->findSwitchInfoFor(packet_in_msg);
    int arrivalPort = packet_in_msg->getEncapsulatedPacket()->getArrivalGate()->getIndex();
    //get SRP Frame
    if (CoRE4INET::SRPFrame * srpFrame =
            dynamic_cast<CoRE4INET::SRPFrame *>(packet_in_msg->getEncapsulatedPacket())) {

        if (CoRE4INET::TalkerAdvertise* talkerAdvertise =
                dynamic_cast<CoRE4INET::TalkerAdvertise*>(srpFrame)) {
            updated = _srpManager->registerTalker(talkerAdvertise, swInfo, arrivalPort);
            //save talker and do nothing else.

        } else if (CoRE4INET::ListenerReady* listenerReady =
                dynamic_cast<CoRE4INET::ListenerReady*>(srpFrame)) {
            //save listener
            updated = _srpManager->registerListener(listenerReady, swInfo, arrivalPort);

            if (updated) {

                SRPForwardingInfo_t* fwd = _srpManager->getForwardingInfoForStreamID (swInfo, listenerReady->getStreamID(), listenerReady->getVlan_identifier());
                oxm_basic_match match = oxm_basic_match();
                // TODO implement AVB eth type.
                match.in_port = fwd->inPort; // get talker in port.
                match.dl_dst = fwd->dest; // set to multicast address
                match.dl_vlan = fwd->vlanID;
                match.dl_vlan_pcp = fwd->srClass;
                match.dl_type = AVB_ETHERTYPE;
                match.AVB_STREAM_ID = fwd->streamID;
                //TODO fix wildcards for OFP151!
                match.wildcards = 0;
#if OFP_VERSION_IN_USE == OFP_100
//                match.wildcards |= OFPFW_IN_PORT;
//                match.wildcards |= OFPFW_DL_TYPE;
                match.wildcards |= OFPFW_DL_SRC;
//                match.wildcards |= OFPFW_DL_DST;
//                match.wildcards |= OFPFW_DL_VLAN;
//                match.wildcards |=  OFPFW_DL_VLAN_PCP;
                match.wildcards |= OFPFW_NW_PROTO;
                match.wildcards |= OFPFW_NW_SRC_ALL;
                match.wildcards |= OFPFW_NW_DST_ALL;
                match.wildcards |= OFPFW_TP_SRC;
                match.wildcards |= OFPFW_TP_DST;
//                match.wildcards |= OFPFW_DL_AVBSID;
#endif

                TCPSocket * socket = controller->findSocketFor(packet_in_msg);
                sendSRPFlowModMessage(OFPFC_ADD, match, fwd->outports, socket, _idleTimeout, _hardTimeout);

                delete fwd;
            }
        }

        //forward original to the switch it came from.
        forwardSRPPacket(packet_in_msg);
    }

}

void RTEthernetControllerApp::sendSRPFlowModMessage(ofp_flow_mod_command mod_com, const oxm_basic_match &match, std::vector<int> outports, TCPSocket * socket, int idleTimeOut =0 , int hardTimeOut=0){
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

void RTEthernetControllerApp::forwardSRPPacket(OFP_Packet_In* packet_in_msg) {
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
    packetOut->setIn_port(packet->getArrivalGate()->getIndex());

    socket->send(packetOut);
}

void RTEthernetControllerApp::finish(){
    AbstractControllerApp::finish();

    cout << stateToXML();

}

bool RTEthernetControllerApp::loadOfflineConfigFromXML(Switch_Info* info) {
    //load XML config if specified.
    bool changed = false;
    cXMLElement* xmlDoc = par("configXML").xmlValue();
    if(xmlDoc)
    {//we got an XML document for config set.
        cXMLElement* controllerXML = xmlDoc->getFirstChildWithAttribute("controllerapp", "type", "RTEthernetControllerApp");
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
                        std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> > lut = _macManager->getLookupTable();


                        std::map<inet::MACAddress,uint32_t> macToPortMap = lut[info];

                        //fill the map.
                        for(size_t i=0; i<macTableXML.size(); i++){
                            MACAddress mac = MACAddress(macTableXML[i]->getAttribute("mac"));
                            if(!mac.isUnspecified()){
                                if(const char * portC = macTableXML[i]->getAttribute("port")){
                                    uint32_t port = atoi(portC);
                                    bool insert = true;
                                    //check if the entry exists.
                                    if(macToPortMap.find(mac) != macToPortMap.end()){
                                        //mac allready exists.
                                        insert = false;
                                    }
                                    if(insert) {
                                        macToPortMap[mac] = port;
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
                cXMLElement* switchXML = srpManagerXML->getFirstChildWithAttribute("srpTable","switch_id",info->getMacAddress().c_str());
                if(switchXML){
                    _srpManager->importFromXML(switchXML, info);
                }
            }
        }
    }
    return changed;
}

std::string RTEthernetControllerApp::stateToXML() {

    ostringstream oss;
    string tab = "    ";
    oss << "<config>" << endl;
    oss << tab << "<controllerapp type=\"RTEthernetControllerApp\">" << endl;

    //mac table
    oss << tab << tab << "<macManager>" << endl;
    std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> > lut = _macManager->getLookupTable();
    for(auto switchMap =lut.begin();switchMap != lut.end();++switchMap){
        oss << tab << tab << tab << "<mactable switch_id=\"" << switchMap->first->getMacAddress() << "\">" << endl;

        for(auto macToPortMap =switchMap->second.begin();macToPortMap != switchMap->second.end();++macToPortMap){
            oss << tab << tab << tab << tab << "<entry mac=\"" << macToPortMap->first.str() << "\" port=\"" << macToPortMap->second << "\" />" << endl;
        }

        oss << tab << tab << tab << "</mactable>" << endl;
    }
    oss << tab << tab << "</macManager>" << endl;

    //srp table
    oss << tab << tab << "<srpManager>" << endl;
    oss << _srpManager->exportToXML();
    oss << tab << tab << "</srpManager>" << endl;

    oss << tab << "</controllerapp>" << endl;
    oss << "</config>" << endl;
    return oss.str();
}

} /*end namespace SDN4CoRE*/
