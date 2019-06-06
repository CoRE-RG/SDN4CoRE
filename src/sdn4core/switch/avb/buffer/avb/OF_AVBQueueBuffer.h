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

#ifndef CORE4INET_OF_AVBQueueBuffer_H_
#define CORE4INET_OF_AVBQueueBuffer_H_

//CoRE4INET
#include "core4inet/buffer/avb/AVBBuffer.h"
#include "core4inet/buffer/base/QueueBuffer.h"

namespace SDN4CoRE {

/**
 * Extends the AVBBuffer and the Queue Buffer to enable openflow specific AVB manipulation.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class OF_AVBQueueBuffer : public virtual CoRE4INET::AVBBuffer, public virtual CoRE4INET::QueueBuffer
{
    public:
        virtual ~OF_AVBQueueBuffer();


    protected:
        /**
         * @brief handles the incoming and outgoing messages of the buffer.
         *
         * @param msg incoming inet::EtherFrame for the Buffer or SchedulerActionTimeEvent message.
         */
        virtual void handleMessage(cMessage *msg) override;
};

} /*end namespace SDN4CoRE*/
#endif /* CORE4INET_OF_AVBQueueBuffer_H_ */
