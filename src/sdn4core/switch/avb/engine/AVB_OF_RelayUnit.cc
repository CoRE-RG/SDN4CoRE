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

#include <sdn4core/switch/avb/engine/AVB_OF_RelayUnit.h>

#include <sdn4core/switch/avb/services/avb/SRP/OF_SRProtocol.h>
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
#include "openflow/messages/OFP_Packet_Out.h"

using namespace std;
using namespace inet;
using namespace openflow;
using namespace omnetpp;


namespace SDN4CoRE{

Define_Module(AVB_OF_RelayUnit);

AVB_OF_RelayUnit::AVB_OF_RelayUnit() {
}

AVB_OF_RelayUnit::~AVB_OF_RelayUnit() {
}

void AVB_OF_RelayUnit::forwardSRPtoController(cPacket* msg) {
    //TODO use experimenter Message for srp forwarding. Maybe add a custom reason.
    OFP_Packet_In *packetIn = new OFP_Packet_In("packetIn");
    packetIn->getHeader().version = OFP_VERSION;
    packetIn->getHeader().type = OFPT_PACKET_IN;
#if OFP_VERSION_IN_USE == OFP_100
    packetIn->setReason(OFPR_NO_MATCH);//TODO maybe add another reason for realtime streams.
#elif OFP_VERSION_IN_USE == OFP_151
    packetIn->setReason(OFPR_ACTION_SET);//TODO maybe add another reason for realtime streams.
#endif
    packetIn->setByteLength(32);
    if (inet::Ieee802Ctrl * controlInfo = dynamic_cast<inet::Ieee802Ctrl *>(msg->getControlInfo())){
        oxm_basic_match match;
        match.in_port = controlInfo->getSwitchPort();
        packetIn->setMatch(match);
    }

    // allways send full packet with packet-in message
    packetIn->encapsulate(msg);
    packetIn->setBuffer_id(OFP_NO_BUFFER);

    socket.send(packetIn);
}

bool AVB_OF_RelayUnit::isSRPMessage(cMessage* msg) {
    return msg->arrivedOn("srpIn") || dynamic_cast<CoRE4INET::SRPFrame *>(msg);
}

void AVB_OF_RelayUnit::initialize(int stage){
    OF_RelayUnit::initialize(stage);

    switch(stage){
        case INITSTAGE_LOCAL: {

            //load srp table module
            _srpTable = dynamic_cast<CoRE4INET::SRPTable*> (getModuleByPath(par("srpTable")));
            if(!_srpTable){
                throw cRuntimeError(("AVB_OF_RelayUnit: Could not init as no SRP Table could be found at " + par("srpTable").str()).c_str());
            }

            break;
        }
        //    case INITSTAGE_PHYSICAL_ENVIRONMENT:
        //    case INITSTAGE_PHYSICAL_ENVIRONMENT_2:
        //    case INITSTAGE_PHYSICAL_LAYER:
        //    case INITSTAGE_LINK_LAYER:
        //    case INITSTAGE_LINK_LAYER_2:
        case INITSTAGE_NETWORK_LAYER: {
            break;
        }
        //    case INITSTAGE_NETWORK_LAYER_2:
        //    case INITSTAGE_NETWORK_LAYER_3:
        case INITSTAGE_TRANSPORT_LAYER: {
            break;
        }
    //    case INITSTAGE_TRANSPORT_LAYER_2:
    //    case INITSTAGE_ROUTING_PROTOCOLS:
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
        case INITSTAGE_LAST: {
            // connect the gates to the SRPProtocol Module.
            // find the srp protocol module
            OF_SRProtocol* srpProtocol = dynamic_cast<OF_SRProtocol*> (getModuleByPath(par("srpProtocolModule")));
            if(!srpProtocol){
                throw cRuntimeError(("AVB_OF_RelayUnit: Could not init as no SRP Protocol Module could be found at " + par("srpProtocolModule").str()).c_str());
            }
            //srpProtocol.out --> relayUnit.srpIn;
            srpProtocol->gate("out")->connectTo(this->gate("srpIn"));
            //srpProtocol.in <-- relayUnit.srpOut;
            this->gate("srpOut")->connectTo(srpProtocol->gate("in"));

            break;
         }
         default:
             break;
         }
}

void AVB_OF_RelayUnit::handleMessage(cMessage *msg)
{
    if (msg->arrivedOn("srpIn")) {
        handleSRPFromProtocol(msg);
    } else {
        // nothing to do here - just forward
            OF_RelayUnit::handleMessage(msg);
    }
}

void AVB_OF_RelayUnit::handleSRPFromController(cMessage* msg) {
    if (OFP_Packet_Out *packetOut = dynamic_cast<OFP_Packet_Out *>(msg)) {

        if (CoRE4INET::SRPFrame * srpFrame =
                dynamic_cast<CoRE4INET::SRPFrame *>(packetOut->decapsulate())) {

            inet::Ieee802Ctrl *etherctrl = new inet::Ieee802Ctrl();
            etherctrl->setSwitchPort(packetOut->getIn_port());
            //pack message
            srpFrame->setControlInfo(etherctrl);

            //forward to port
            send(srpFrame, "srpOut");

        } else {
            throw cRuntimeError("SRP packet from controller received without Ieee802Ctrl");
        }

    }
}

void AVB_OF_RelayUnit::handleSRPFromProtocol(cMessage* msg) {

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
            delete etherctrl;
        } else //check for srp message type
        if (dynamic_cast<CoRE4INET::ListenerReady *>(msg)) {

            //pack message
            cMessage* copy = msg->dup();
            copy->setControlInfo(etherctrl);
            send(copy, "dataPlaneOut", etherctrl->getSwitchPort());
        }

    } else {
        throw cRuntimeError("Packet from SRP received without ExtendedIeee802Ctrl");
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
        forwardSRPtoController(toController);
    } else {
        OF_RelayUnit::processDataPlanePacket(msg);
    }
}

void AVB_OF_RelayUnit::processControlPlanePacket(cMessage *msg){
    if (OFP_Message *of_msg = dynamic_cast<OFP_Message *>(msg)) { //msg from controller
        ofp_type type = (ofp_type)of_msg->getHeader().type;
        switch (type){
        // TODO Add Experimenter Message Structure!
#if OFP_VERSION_IN_USE == OFP_100
        case OFPT_VENDOR:
            controlPlanePacket++;
            handleSRPFromController(of_msg);
            break;

#elif OFP_VERSION_IN_USE == OFP_151
        case OFPT_EXPERIMENTER:
            controlPlanePacket++;
            handleSRPFromController(of_msg);
            break;
#endif

        default:
            //not a special of message forward to base class.
            OF_RelayUnit::processControlPlanePacket(msg);
            break;
        }
    }
}

openflow::oxm_basic_match AVB_OF_RelayUnit::extractMatch(
        inet::EthernetIIFrame* frame) {

    oxm_basic_match match = OF_RelayUnit::extractMatch(frame);
    //extract AVB/VLAN specific information ifpresent
    //if(frame->getEtherType()==AVB_ETHERTYPE) {
    if(match.dl_type == 0x8100){ //we have a q frame!
        CoRE4INET::EthernetIIFrameWithQTag* qFrame =
            dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag*>(frame);
        match.dl_vlan = qFrame->getVID();
        match.dl_vlan_pcp = qFrame->getPcp();
        //}
    }
    return match;
}

void AVB_OF_RelayUnit::finish() {
    // record statistics
        recordScalar("packetsDataPlane", dataPlanePacket);
        recordScalar("packetsControlPlane", controlPlanePacket);
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
