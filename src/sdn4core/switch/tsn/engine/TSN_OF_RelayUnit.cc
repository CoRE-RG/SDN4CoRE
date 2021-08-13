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

//SDN4CoRE
#include <sdn4core/switch/tsn/engine/TSN_OF_RelayUnit.h>
//CoRE4INET
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/contract/ExtendedIeee802Ctrl_m.h"
//INET
#include "inet/linklayer/ethernet/EtherMACBase.h"


namespace SDN4CoRE{

Define_Module(TSN_OF_RelayUnit);

bool TSN_OF_RelayUnit::isSRPMessage(cMessage* msg) {
    bool hasEncapedSRP = false;
    if(inet::EthernetIIFrame * etherframe = dynamic_cast<inet::EthernetIIFrame *>(msg)) {
        hasEncapedSRP = AVB_OF_RelayUnit::isSRPMessage(etherframe->getEncapsulatedPacket());
    }
    return hasEncapedSRP || AVB_OF_RelayUnit::isSRPMessage(msg);
}

void TSN_OF_RelayUnit::processDataPlanePacket(cMessage *msg){
    bool msgHandled = false;

    if(msg->arrivedOn("dataPlaneIn")){
        if (isSRPMessage(msg)) {
            //check for special encapsulation.
            if(inet::EthernetIIFrame * etherframe = dynamic_cast<inet::EthernetIIFrame *>(msg)) {
                if (dynamic_cast<CoRE4INET::SRPFrame *>(etherframe->getEncapsulatedPacket())) {
                    CoRE4INET::SRPFrame* toController = dynamic_cast<CoRE4INET::SRPFrame *>(etherframe->decapsulate());

                    inet::Ieee802Ctrl * controlInfo = new inet::Ieee802Ctrl();
                    controlInfo->setSwitchPort(etherframe->getArrivalGate()->getIndex());
                    toController->setControlInfo(controlInfo);
                    emit(forwardSRPtoConSig,toController);
                    dataPlanePacket++;
                    msgHandled = true;
                    delete msg; //= etherframe
                }
            }
        }
    }

    if(!msgHandled){
        //not handled so forward to base
        AVB_OF_RelayUnit::processDataPlanePacket(msg);
    }
}

void TSN_OF_RelayUnit::handleSRPFromProtocol(cMessage* msg) {
    Enter_Method("handleSRPFromProtocol");
    if(CoRE4INET::SRPFrame * srp = dynamic_cast<CoRE4INET::SRPFrame *>(msg)){

        CoRE4INET::ExtendedIeee802Ctrl * etherctrl = dynamic_cast<CoRE4INET::ExtendedIeee802Ctrl *>(srp->removeControlInfo());
        if (!etherctrl)
        {
            throw cRuntimeError("SRP is missing ControlInfo");
        }

        int portNum = etherctrl->getSwitchPort();
        int notPortNum = etherctrl->getNotSwitchPort();
        inet::MACAddress address = etherctrl->getDest();

        if (portNum >= static_cast<int>(this->portVector.size()))
            throw cRuntimeError("Output port %d doesn't exist!", portNum);

        inet::EthernetIIFrame * frame = new inet::EthernetIIFrame(srp->getName());

        if(inet::EtherMACBase *nic = dynamic_cast<inet::EtherMACBase *>(gate("dataPlaneOut",0)
                ->getNextGate()->getOwnerModule()->getSubmodule("mac"))) {
            frame->setSrc(nic->getMACAddress());
        }
        frame->setDest(address);
        frame->setByteLength(ETHER_MAC_FRAME_BYTES);
        frame->setEtherType(MSRP_ETHERTYPE);
        frame->encapsulate(srp->dup());

        if (frame->getByteLength() < MIN_ETHERNET_FRAME_BYTES){
            frame->setByteLength(MIN_ETHERNET_FRAME_BYTES);
        }

        if(portNum == SWITCH_PORT_BROADCAST){
            for (size_t i = 0; i < portVector.size(); ++i) {
                if(i != notPortNum) {
                    //pack message
                    cMessage* copy = frame->dup();
                    send(copy, gate("dataPlaneOut", i));
                    EV_INFO << "Sending SRP frame " << frame << " with destination = " << frame->getDest() << ", port = "
                            << i << endl;
                }
            }
        } else {//check for srp message type
            //pack message
            send(frame->dup(), gate("dataPlaneOut", portNum));
            EV_INFO << "Sending SRP frame " << frame << " with destination = " << frame->getDest() << ", port = "
                    << portNum << endl;
        }

        delete frame;
        delete msg; // == srp
        delete etherctrl;

    } else {
        cRuntimeError("packet `%s' from SRP received without ExtendedIeee802Ctrl",
                msg->getName());
    }
}



} /*end namespace SDN4CoRE*/
