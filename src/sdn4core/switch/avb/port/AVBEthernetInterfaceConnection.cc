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

#include <sdn4core/switch/avb/port/AVBEthernetInterfaceConnection.h>

//STD
#include <iostream>
#include <list>
//CoRE4INET
#include "core4inet/buffer/AS6802/CTBuffer.h"
#include "core4inet/incoming/base/Incoming.h"
#include "core4inet/linklayer/ethernet/AS6802/CTFrame.h"
//Auto-generated Messages
#include "inet/linklayer/ethernet/EtherFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"

using namespace CoRE4INET;
using namespace omnetpp;


namespace SDN4CoRE{

Define_Module(AVBEthernetInterfaceConnection);

void AVBEthernetInterfaceConnection::initialize()
{
    CTApplicationBase::initialize();

    _avbOutCTC = getParentModule()->getSubmodule("avbCTC");
    _beBuffer = getParentModule()->getSubmodule("bgOut");

    //set port info
    _portNo = getParentModule()->getIndex();
    _portCount = getParentModule()->getVectorSize();

}

bool AVBEthernetInterfaceConnection::isSRPMessage(cMessage* msg) {
    return msg->arrivedOn("encapSrpIn") || dynamic_cast<CoRE4INET::SRPFrame *>(msg);
}

void AVBEthernetInterfaceConnection::handleMessage(cMessage *msg)
{
    CTApplicationBase::handleMessage(msg);

    EV_INFO << "RTEtherPort received a message: " << msg << endl;

    if (isSRPMessage(msg)) {
        // srp message --> forward to correct modules
        handleSRPMessage(msg);
    } else if(msg->arrivedOn("upperLayerIn")){
        //from switch --> forward to correct buffer
        handleOutMessage(msg);
    } else {
        //this message should be forwarded to the upper layer!
        handleSwitchMessage(msg);
    }

    delete msg;
}

void AVBEthernetInterfaceConnection::handleSRPMessage(cMessage* msg) {
    // srp message --> forward to correct modules

    if (msg->arrivedOn("encapSrpIn")) {//from encap to controller
        //check the control info and change it for the of-switch module.
        inet::Ieee802Ctrl *etherctrl = dynamic_cast<inet::Ieee802Ctrl *>(msg->removeControlInfo());
        if (!etherctrl)
        {
            error("packet `%s' from encap received without Ieee802Ctrl", msg->getName());
        }
        else
        {
            //set correct port number
            etherctrl->setSwitchPort(_portNo);

            //pack message
            cMessage* fromEncap = msg->dup();
            fromEncap->setControlInfo(etherctrl);
            send(fromEncap, "upperLayerOut");
        }

    } else if (msg->arrivedOn("upperLayerIn")) {//from controller to encap
        // srp message --> forward to correct modules
        if (CoRE4INET::ExtendedIeee802Ctrl *etherctrl = dynamic_cast<CoRE4INET::ExtendedIeee802Ctrl *>(msg->removeControlInfo())) { //ExtendedIeee802Ctrl --> encap
            //manipulate port to 0 because the port thinks he is a host.
            if(etherctrl->getSwitchPort() == SWITCH_PORT_BROADCAST) {
                if(etherctrl->getNotSwitchPort() == this->_portNo) {
                    //do not broadcast it.
                    etherctrl->setNotSwitchPort(0);
                } else {
                    //set to other port than 0 to not ignore it.
                    etherctrl->setNotSwitchPort(1);
                }
            } else if (etherctrl->getSwitchPort() == this->_portNo) {
                etherctrl->setSwitchPort(0);
            } else {
                etherctrl->setSwitchPort(1);
            }

            //pack message
            cMessage* deliver = msg->dup();
            deliver->setControlInfo(etherctrl);
            send(deliver, "encapSrpOut");

        } else {
            error("packet `%s' from upperLayer received without Ieee802Ctrl",
                    msg->getName());
        }
    } else {

        error("SRP packet `%s' received on wrong gate", msg->getName());

    }
}

void AVBEthernetInterfaceConnection::handleSwitchMessage(cMessage* msg) {
    //this message should be forwarded to the upper layer!
    EV_INFO << "Forwarding to upperLayer.\n";
    send(msg->dup(), "upperLayerOut");
}

void AVBEthernetInterfaceConnection::handleOutMessage(cMessage* msg) {
    //from switch --> forward to correct buffer
    if(AVBFrame* avbFrame = dynamic_cast<AVBFrame*>(msg)){
        EV_INFO << "Treated as AVB --> forward to avbCTC." << endl;

        //get sender module to forward input.
        //const char * name = msg->getSenderModule()->getName();

        //AVB transfer
        sendDirect(avbFrame->dup(), _avbOutCTC->gate("in"));

    }else if(CTFrame* ctFrame = dynamic_cast<CTFrame*>(msg)){
        EV_INFO << "Treated as ct";
        //ct frame so find correct buffer virtual link
        std::list<CoRE4INET::CTBuffer*> buffer = ctbuffers[ctFrame->getCtID()];
        for(std::list<CoRE4INET::CTBuffer*>::iterator buf = buffer.begin(); buf!=buffer.end(); ++buf){
            EV_INFO << " --> forward to virtual link buffer." << endl;
            Incoming *in = dynamic_cast<Incoming *>((*buf)->gate("in")->getPathStartGate()->getOwner());
            sendDirect(ctFrame->dup(), in->gate("in"));
        }
    }else if(inet::EthernetIIFrame* ethernetFrame = dynamic_cast<inet::EthernetIIFrame*>(msg)){
        EV_INFO << "Treated as BE --> forward to best effort buffer." << endl;
        //BE transfer
        sendDirect(ethernetFrame->dup(), _beBuffer->gate("in"));

        //for (std::list<BGBuffer*>::iterator buf = bgbuffers.begin(); buf != bgbuffers.end(); ++buf) {
        //    sendDirect(ethernetFrame->dup(), (*buf)->gate("in"));
        //}
    }
}

} /*end namespace SDN4CoRE*/
