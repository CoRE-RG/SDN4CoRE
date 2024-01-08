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
// c Tobias Haugg, for HAW Hamburg

#include <sdn4core/switch/tsn/engine/TSN_OF_SwitchAgent.h>
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/messages/OFP_Packet_Out_m.h"

using namespace std;
using namespace inet;
using namespace openflow;
using namespace omnetpp;

namespace SDN4CoRE{

Define_Module(TSN_OF_SwitchAgent);

void TSN_OF_SwitchAgent::handleMessage(cMessage *msg){
    if (msg->arrivedOn("srpIn")) {
        if(CoRE4INET::ListenerReady* srp = dynamic_cast<CoRE4INET::ListenerReady *>(msg)){
            sendSRPResponse(srp);
        } else {
            delete msg;
        }
    } else {
       // nothing to do here - just forward
       OF_SwitchAgent::handleMessage(msg);
    }
}

void TSN_OF_SwitchAgent::sendSRPResponse(CoRE4INET::ListenerReady *msg){
    OFP_Packet_In *packetIn = new OFP_Packet_In("packetIn");
    ofp_header header = packetIn->getHeader();
    header.version = OFP_VERSION;
    header.type = OFPT_VENDOR;
    packetIn->setHeader(header);
    packetIn->setByteLength(32);
    packetIn->encapsulate(msg);
    packetIn->setBuffer_id(OFP_NO_BUFFER);
    socket.send(packetIn);
}

void TSN_OF_SwitchAgent::processControlPlanePacket(cMessage *msg){
    if (Open_Flow_Message *of_msg = dynamic_cast<Open_Flow_Message *>(msg)) { //msg from controller
        ofp_type type = (ofp_type)of_msg->getHeader().type;
        switch (type){
        case OFPT_VENDOR:
            controlPlanePacket++;
            handleSRPFromController(of_msg);
            break;
        default:
            //not a special OF message, forward to base class.
            OF_SwitchAgent::processControlPlanePacket(msg);
            break;
        }
    }
}

void TSN_OF_SwitchAgent::handleSRPFromController(cMessage* msg) {
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

}
