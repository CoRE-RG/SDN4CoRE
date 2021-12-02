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

//SDN4CoRE
#include <sdn4core/switch/avb/engine/AVB_OF_RelayUnit.h>
//STD
#include <sstream>
#include <string>
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//AUTO_GENERATED MESSAGES
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
//openflow
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/messages/OFP_Packet_Out_m.h"

using namespace std;
using namespace inet;
using namespace openflow;
using namespace omnetpp;


namespace SDN4CoRE{

Define_Module(AVB_OF_RelayUnit);

AVB_OF_RelayUnit::AVB_OF_RelayUnit() {}
AVB_OF_RelayUnit::~AVB_OF_RelayUnit() {}

void AVB_OF_RelayUnit::initialize(int stage){
    OF_RelayUnit::initialize(stage);

    switch(stage){
        case INITSTAGE_LOCAL: {

            //register siganls
            forwardSRPtoConSig = registerSignal("forwardSRPtoConSig");

            //load srp table module
            _srpTable = dynamic_cast<CoRE4INET::SRPTable*> (getModuleByPath(par("srpTable")));
            if(!_srpTable){
                throw cRuntimeError(("AVB_OF_SwitchAgent: Could not init as no SRP Table could be found at " + par("srpTable").str()).c_str());
            }

            break;
        }
        case INITSTAGE_APPLICATION_LAYER: {
            //load XML config if specified.
            cXMLElement* xmlDoc = par("configXML").xmlValue();
            if(xmlDoc){
                if(strcmp(xmlDoc->getName(), "config") == 0){
                    string switchName = getParentModule()->getSubmodule("eth", 0)->getSubmodule("mac")->par("address").stringValue();
                    if(cXMLElement* switchConfigXML = xmlDoc->getFirstChildWithAttribute("switch", "id", switchName.c_str()))
                    {//there is a config for this switch.
                        if(cXMLElement* srpTableXML = switchConfigXML->getFirstChildWithTag("srpTable"))
                        {//the config contains an srp table so set it.
                            if(_srpTable){
                                _srpTable->importFromXML(srpTableXML);
                            }
                        }
                    }
                }
            }
            break;
        }
         default:
             break;
         }
}

void AVB_OF_RelayUnit::processDataPlanePacket(cMessage *msg){
    if (isSRPMessage(msg)) {
        dataPlanePacket++;

        //forward to controller
        CoRE4INET::SRPFrame* toController = dynamic_cast<CoRE4INET::SRPFrame *>(msg->dup());
        inet::Ieee802Ctrl * controlInfo = new inet::Ieee802Ctrl();
        controlInfo->setSwitchPort(msg->getArrivalGate()->getIndex());
        toController->setControlInfo(controlInfo);

        emit(forwardSRPtoConSig,toController);
        delete msg;
    } else {
       OF_RelayUnit::processDataPlanePacket(msg);
    }
}

openflow::oxm_basic_match AVB_OF_RelayUnit::extractMatch(
        inet::EthernetIIFrame* frame) {

    oxm_basic_match match = OF_RelayUnit::extractMatch(frame);
    //extract AVB/VLAN specific information ifpresent
    //if(frame->getEtherType()==AVB_ETHERTYPE) {
    if(match.OFB_ETH_TYPE == 0x8100){ //we have a q frame!
        CoRE4INET::EthernetIIFrameWithQTag* qFrame =
            dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag*>(frame);
        match.OFB_VLAN_VID = qFrame->getVID();
        match.OFB_VLAN_PCP = qFrame->getPcp();
        //}
    }
    return match;
}


void AVB_OF_RelayUnit::handleSRPFromProtocol(cMessage* msg) {
    Enter_Method("handleSRPFromProtocol");
    cObject* ctrlInfo = msg->removeControlInfo();
    //check the control info and change it for the of-switch module.
    if (CoRE4INET::ExtendedIeee802Ctrl *etherctrl =
            dynamic_cast<CoRE4INET::ExtendedIeee802Ctrl *>(ctrlInfo)) {

        //check for srp message type
        if (dynamic_cast<CoRE4INET::TalkerAdvertise *>(msg)) { //TalkerAdvertise
            for (size_t i = 0; i < portVector.size(); ++i) {
                if(i != etherctrl->getNotSwitchPort()) {
                    //pack message
                    cMessage* copy = msg->dup();
                    copy->setControlInfo(etherctrl->dup());
                    send(copy, "dataPlaneOut", i);
                }
            }
        } else //check for srp message type
        if (dynamic_cast<CoRE4INET::ListenerReady *>(msg)) {

            //pack message
            cMessage* copy = msg->dup();
            copy->setControlInfo(etherctrl->dup());
            send(copy, "dataPlaneOut", etherctrl->getSwitchPort());
        }

    } else {
        throw cRuntimeError("Packet from SRP received without ExtendedIeee802Ctrl");
    }

    delete ctrlInfo;
    delete msg;
}

bool AVB_OF_RelayUnit::isSRPMessage(cMessage* msg) {
    return msg->arrivedOn("srpIn") || dynamic_cast<CoRE4INET::SRPFrame *>(msg);
}

void AVB_OF_RelayUnit::finish() {
    // record statistics
        recordScalar("packetsDataPlane", dataPlanePacket);
        recordScalar("flowTableHit", flowTableHit);
        recordScalar("flowTableMiss", flowTableMiss);

        //print flow table


        //xml head
        std::ostringstream oss;
        oss << "<config>" << endl;
        oss << "<switch id=\"" << getParentModule()->getSubmodule("eth", 0)->getSubmodule("mac")->par("address").stringValue() << "\">" << endl;
        for (size_t i = 0; i < _flowTables.size() ; i++){
            oss << _flowTables[i]->exportToXML();
        }
        oss << _srpTable->exportToXML();
        oss << "</switch>" << endl;
        oss << "</config>" << endl;
        cout << oss.str();
}

} /*end namespace SDN4CoRE*/
