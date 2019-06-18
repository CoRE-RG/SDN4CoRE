//
// c Timo Haeckel, for HAW Hamburg
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

#include "ProcessingTimeSimulation.h"


namespace SDN4CoRE{

#define MSGKIND_SERVICETIME     3

ProcessingTimeSimulation::~ProcessingTimeSimulation() {
    for(auto&& entry : _msgList) {
      delete entry;
    }
    _msgList.clear();
}

void ProcessingTimeSimulation::initialize()
{
    _queueSize = registerSignal("queueSize");
    _waitingTime = registerSignal("waitingTime");
}

void ProcessingTimeSimulation::handleParameterChange(const char* parname) {
    if (!parname || !strcmp(parname, "processingTime")) {
        _processingTime = par("processingTime");
    }
}

void ProcessingTimeSimulation::triggerNextProcessingTime() {
    //Trigger next service time
    if (_msgList.empty()) {
        _busy = false;
    } else {
        cMessage* msgFromList = _msgList.front();
        _msgList.pop_front();
        cMessage* event = new cMessage("event");
        event->setKind(MSGKIND_SERVICETIME);
        event->setContextPointer(msgFromList);
        scheduleAt(simTime() + _processingTime, event);
    }
}

void ProcessingTimeSimulation::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage() && msg->getKind() == MSGKIND_SERVICETIME) {
        // processing delay introduced now handle the message
        cMessage* data_msg = (cMessage*) (msg->getContextPointer());
        emit(_waitingTime, (simTime() - data_msg->getArrivalTime() - _processingTime));
        processScheduledMessage(data_msg);
        //Trigger next service time
        triggerNextProcessingTime();
    } else {
        simulateProcessingTime(msg);
    }
}

void ProcessingTimeSimulation::simulateProcessingTime(cMessage* msg) {
    if (_busy) {
        _msgList.push_back(msg);
    } else {
        _busy = true;
        cMessage* event = new cMessage("event");
        event->setKind(MSGKIND_SERVICETIME);
        scheduleAt(simTime() + _processingTime, event);
    }
    emit(_queueSize, _msgList.size());
}

} /*end namespace SDN4CoRE*/
