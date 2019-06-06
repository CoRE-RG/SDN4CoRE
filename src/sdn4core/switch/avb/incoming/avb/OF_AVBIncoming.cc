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

#include <sdn4core/switch/avb/incoming/avb/OF_AVBIncoming.h>

//STD
#include <list>
#include <string>
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//CoRE4INET auto-generated
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
//INET
#include "inet/common/ModuleAccess.h"

using namespace std;
using namespace CoRE4INET;

namespace SDN4CoRE {

Define_Module(OF_AVBIncoming);

OF_AVBIncoming::OF_AVBIncoming() {
    this->srptable = nullptr;
}

void OF_AVBIncoming::initialize() {
    this->srptable = inet::getModuleFromPar<SRPTable>(par("srpTable"), this,
            true);
    if (!srptable) {
        throw cRuntimeError(
                "Cannot find module srpTable in node. srpTable is required");
    }
}

void OF_AVBIncoming::handleMessage(cMessage* msg) {

    if (msg && msg->arrivedOn("in")) {
        if (AVBFrame *inFrame = dynamic_cast<AVBFrame*>(msg)) {

            //get sender module to forward input.
            const char * name = msg->getSenderModule()->getName();

            if (strcmp(name, "inControl") == 0) {
                //forward to gateway module
                send(inFrame->dup(),"toGateway");

            } else {

                std::list<cModule*> listeners =
                        srptable->getListenersForTalkerAddress(
                                inFrame->getDest(), inFrame->getVID());
                SR_CLASS srClass = srptable->getSrClassForTalkerAddress(
                        inFrame->getDest(), inFrame->getVID());
                if (listeners.empty()) {
                    emit(droppedSignal, inFrame);
                } else {
                    for (std::list<cModule*>::const_iterator listener =
                            listeners.begin(); listener != listeners.end();
                            ++listener) {

                        if ((*listener) == this->getParentModule()) {
                            if (strcmp(
                                    (*listener)->getSubmodule("phy")->getName(),
                                    "phy") == 0) {
                                string outputStr;
                                if (srClass == SR_CLASS::A)
                                    outputStr = "AVBAout";
                                else if (srClass == SR_CLASS::B)
                                    outputStr = "AVBBout";
                                sendDelayed(inFrame->dup(), getHardwareDelay(),
                                        gate(outputStr.c_str(), 0));
                                emit(rxPkSignal, inFrame);
                            } else {
                                if ((*listener)->hasGate("AVBin")) {
                                    sendDirect(inFrame->dup(),
                                            (*listener)->gate("AVBin"));
                                    emit(rxPkSignal, inFrame);
                                }
                            }
                        }
                    }
                }
            }
            delete inFrame;
        } else {
            throw cRuntimeError("Received non-AVBFrame frame");
        }
    } else {
        delete msg;
    }
}

} /* namespace SDN4CoRE */
