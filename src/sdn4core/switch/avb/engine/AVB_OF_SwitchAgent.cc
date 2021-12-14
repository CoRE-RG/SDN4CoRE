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

//SND4CoRE
#include <sdn4core/switch/avb/engine/AVB_OF_SwitchAgent.h>
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

Define_Module(AVB_OF_SwitchAgent);

AVB_OF_SwitchAgent::AVB_OF_SwitchAgent() {}
AVB_OF_SwitchAgent::~AVB_OF_SwitchAgent() {}

void AVB_OF_SwitchAgent::forwardSRPtoController(cPacket* msg) {
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
        match.OFB_IN_PORT = controlInfo->getSwitchPort();
        packetIn->setMatch(match);
    }

    // allways send full packet with packet-in message
    packetIn->encapsulate(msg->dup());
    packetIn->setBuffer_id(OFP_NO_BUFFER);

    socket.send(packetIn);
    delete msg;
}


void AVB_OF_SwitchAgent::initialize(int stage){
    OF_SwitchAgent::initialize(stage);

    switch(stage){
        case INITSTAGE_LOCAL: {

            //register siganls
            forwardSRPtoConSig = registerSignal("forwardSRPtoConSig");
            relayUnit->subscribe(forwardSRPtoConSig, this);
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

void AVB_OF_SwitchAgent::handleMessage(cMessage *msg)
{
    if (msg->arrivedOn("srpIn")) {
        ((AVB_OF_RelayUnit*)relayUnit)->handleSRPFromProtocol(msg);
    } else {
        // nothing to do here - just forward
       OF_SwitchAgent::handleMessage(msg);
    }
}

void AVB_OF_SwitchAgent::handleSRPFromController(cMessage* msg) {
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
    delete msg;
}

void AVB_OF_SwitchAgent::processControlPlanePacket(cMessage *msg){
    if (Open_Flow_Message *of_msg = dynamic_cast<Open_Flow_Message *>(msg)) { //msg from controller
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
            OF_SwitchAgent::processControlPlanePacket(msg);
            break;
        }
    }
}

void AVB_OF_SwitchAgent::receiveSignal(cComponent *src, simsignal_t id, cObject *value, cObject *details){
    if(this->isConnectedToController()){
        if(id == forwardSRPtoConSig){
            Enter_Method_Silent();
            CoRE4INET::SRPFrame* toController = dynamic_cast<CoRE4INET::SRPFrame *>(value);
            forwardSRPtoController(toController);
        }else{
            OF_SwitchAgent::receiveSignal(src, id, value, details);
        }
    }
}

} /*end namespace SDN4CoRE*/
