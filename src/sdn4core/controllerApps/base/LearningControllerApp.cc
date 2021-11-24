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
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/common/MACAddress.h"
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//AUTO_GENERATED MESSAGES
#include "inet/transportlayer/contract/tcp/TCPCommand_m.h"
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

namespace SDN4CoRE {

Define_Module(LearningControllerApp);

const char LearningControllerApp::MACTABLEMANAGERMODULEPATH[] =
        "sdn4core.controllerState.mac.MACTableManagement";

LearningControllerApp::LearningControllerApp() {
    _macManager = nullptr;
}

LearningControllerApp::~LearningControllerApp() {
}

void LearningControllerApp::initialize() {
    AbstractControllerApp::initialize();
    // try to locate the macTableManager
    _macManager =
            dynamic_cast<MACTableManagement*>(this->getParentModule()->getSubmodule(
                    "controllerState")->getSubmodule("macTableManagement"));
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

void LearningControllerApp::handleParameterChange(const char* parname) {
    AbstractControllerApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "flowModIdleTimeOut")) {
        _idleTimeout = par("flowModIdleTimeOut");
    }
    if (!parname || !strcmp(parname, "flowModHardTimeOut")) {
        _hardTimeout = par("flowModHardTimeOut");
    }
}

void LearningControllerApp::receiveSignal(cComponent* src, simsignal_t id,
        cObject* obj, cObject* details) {
    if (id == PacketInSignalId) {
        EV << "LearningSwitch::PacketIn" << endl;
        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            doSwitching(packet_in);
        }
    } else if (id == PacketFeatureReplySignalId) {
        if (Open_Flow_Message *msg = dynamic_cast<Open_Flow_Message *>(obj)) {
            //new switch registered check if we allready got a offline config for it.
            loadOfflineConfigFromXML(controller->findSwitchInfoFor(msg));
        }
    } else {
        AbstractControllerApp::receiveSignal(src, id, obj, details);
    }
}

void LearningControllerApp::finish() {
    AbstractControllerApp::finish();
    cout << stateToXML();
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

void LearningControllerApp::doSwitching(OFP_Packet_In* packet_in_msg) {
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
        sendFlowModMessage(OFPFC_ADD, match, outport, socket, _idleTimeout,
                _hardTimeout);
        sendPacket(packet_in_msg, outport);
    }
}

bool LearningControllerApp::loadOfflineConfigFromXML(Switch_Info* info) {
    //load XML config if specified.
    bool changed = false;
    cXMLElement* xmlDoc = par("configXML").xmlValue();
    if (xmlDoc) { //we got an XML document for config set.
        cXMLElement* controllerXML = xmlDoc->getFirstChildWithAttribute(
                "controllerapp", "type", "AVBLearningControllerApp");
        if (controllerXML) { //the XML document contains config for this type of controller app.
                             //get the switch ids.
            cXMLElement* macManagerXML = controllerXML->getFirstChildWithTag(
                    "macManager");
            if (macManagerXML) {

                cXMLElement* switchXML =
                        macManagerXML->getFirstChildWithAttribute("mactable",
                                "switch_id", info->getMacAddress().c_str());
                if (switchXML) {
                    cXMLElementList macTableXML =
                            switchXML->getChildrenByTagName("entry");
                    if (!macTableXML.empty()) { // we git mac entries for this switch.
                                                //check if there already is a mac table for the switch
//                        std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> >* lut = _macManager->getLookupTable();
                    //fill the map.
                        for (size_t i = 0; i < macTableXML.size(); i++) {
                            MACAddress mac = MACAddress(
                                    macTableXML[i]->getAttribute("mac"));
                            if (!mac.isUnspecified()) {
                                if (const char * portC =
                                        macTableXML[i]->getAttribute("port")) {
                                    uint32_t port = atoi(portC);

                                    changed |= _macManager->update(info, mac,
                                            port);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return changed;
}

std::string LearningControllerApp::stateToXML() {

    ostringstream oss;
    string tab = "    ";
    oss << "<config>" << endl;
    oss << tab << "<controllerapp type=\"AVBLearningControllerApp\">" << endl;

    //mac table
    oss << tab << tab << "<macManager>" << endl;
//    std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> >* lut = _macManager->getLookupTable();
//    for(auto switchMap =lut->begin();switchMap != lut->end();++switchMap){
//        oss << tab << tab << tab << "<mactable switch_id=\"" << switchMap->first->getMacAddress() << "\">" << endl;
//
//        for(auto macToPortMap =switchMap->second.begin();macToPortMap != switchMap->second.end();++macToPortMap){
//            oss << tab << tab << tab << tab << "<entry mac=\"" << macToPortMap->first.str() << "\" port=\"" << macToPortMap->second << "\" />" << endl;
//        }
//
//        oss << tab << tab << tab << "</mactable>" << endl;
//    }
    oss << tab << tab << tab
            << "<TODO=\"currently not available for inet::MACAddressTable\" />"
            << endl;
    oss << tab << tab << "</macManager>" << endl;

    //srp table
    oss << _srpManager->exportToXML();

    oss << tab << "</controllerapp>" << endl;
    oss << "</config>" << endl;
    return oss.str();
}

} /*end namespace SDN4CoRE*/
