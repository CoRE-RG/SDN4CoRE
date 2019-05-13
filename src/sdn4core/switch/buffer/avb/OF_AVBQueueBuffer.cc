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

#include <openflow/tsn/switch/core4inet/buffer/avb/OF_AVBQueueBuffer.h>

using namespace ::CoRE4INET;

namespace ofp{

Define_Module(OF_AVBQueueBuffer);

OF_AVBQueueBuffer::~OF_AVBQueueBuffer()
{
}

void OF_AVBQueueBuffer::handleMessage(cMessage *msg)
{
    newTime = getCurrentTime();

    if (credit < 0)
    {
        idleSlope(newTime - oldTime);
    }

    if (msg->arrivedOn("in"))
    {
        Buffer::handleMessage(msg);
        if (inTransmission)
        {
            interferenceSlope(newTime - oldTime);
            if (credit > maxCredit)
                maxCredit = credit;
        }
        else
        {
            if (credit >= 0)
            {
                if (size() > 0)
                {
                    cMessage *outFrame = getFrame();
                    send(outFrame, "out");
                    inTransmission = true;
                }
                else
                {
                    resetCredit();
                }

            }
            else if (credit < 0)
            {
                unsigned long reservedBandwith = srptable->getBandwidthForModuleAndSRClass(
                        getParentModule(), srClass);
                if (reservedBandwith == 0)
                {
                    resetCredit();
                    clear();
                }
                else
                {
                    wDuration = static_cast<double>(-credit) / static_cast<double>(reservedBandwith);
                    SchedulerTimerEvent *event = new SchedulerTimerEvent("API Scheduler Task Event", TIMER_EVENT);
                    event->setTimer(static_cast<uint64_t>(ceil(wDuration / tick)));
                    event->setDestinationGate(gate("schedulerIn"));
                    getTimer()->registerEvent(event);
                }
            }
        }
    }
    else if (msg->arrivedOn("schedulerIn"))
    {
        if (inTransmission)
        {
            interferenceSlope(newTime - oldTime);
            if (credit > maxCredit)
                maxCredit = credit;
        }
        else
        {
            if (credit >= 0)
            {
                if (size() > 0)
                {
                    cMessage *outFrame = getFrame();
                    send(outFrame, "out");
                    inTransmission = true;
                }
                else
                {
                    resetCredit();
                }
            }
            else if (credit < 0)
            {
                unsigned long reservedBandwith = srptable->getBandwidthForModuleAndSRClass(
                        getParentModule(), srClass);
                //When there is no bandwidth reserved reset credit and delete all messages
                if (reservedBandwith == 0)
                {
                    resetCredit();
                    clear();
                }
                else
                {
                    wDuration = static_cast<double>(-credit) / static_cast<double>(reservedBandwith);
                    SchedulerTimerEvent *event = new SchedulerTimerEvent("API Scheduler Task Event", TIMER_EVENT);
                    event->setTimer(static_cast<uint64_t>(ceil(wDuration / tick)));
                    event->setDestinationGate(gate("schedulerIn"));
                    getTimer()->registerEvent(event);
                }
            }
        }
        delete msg;
    }

    if (newTime >= oldTime)
    {
        oldTime = getCurrentTime();
        emitCredit();
    }
}

} /*end namespace ofp*/
