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

package sdn4core.switch.avb_AS6802.buffer.avb;

import core4inet.buffer.avb.AVBBuffer;

//
// Represents a queue buffer for time-triggered traffic. Messages are sent using the Credit Based Shaper Algorithm.
//
// The buffer stores infinit messages in a fifo queue.
// The buffer removes and sends the first message in the queue.
// Updated for usage in Openflow Switches.
//
// @see AVBBuffer, Buffer,
//
// @author Philipp Meyer, Timo Haeckel
simple OF_AVBQueueBuffer extends AVBBuffer
{
    parameters:
        @class(SDN4CoRE::OF_AVBQueueBuffer);
        @display("q=frames");
        //Signal emitted when queuelength changes, contains new length
        @signal[length](type=unsigned long; unit=packets);
        //Signal emitted when queuelength changes, contains new size in bytes
        @signal[size](type=unsigned long; unit=B);
        //Signal emitted when frame is dropped due to buffer overflow, contains dropped EtherFrame
        @signal[dropped](type=inet::EtherFrame);
        
        //Statistic of the queue length of the buffer
        @statistic[length](title="Queue Length"; source=length; record=vector,stats; unit=packets; interpolationmode=sample-hold);
        //Statistic of the queue size of the buffer in bytes
        @statistic[size](title="Queue Size"; source=size; record=vector,stats; unit=B; interpolationmode=sample-hold);
        //Statistic of the amount of packets that were dropped due to buffer overflows
        @statistic[dropped](title="Dropped frames"; source=dropped; unit=packets; record=sum);

        //Size of the buffer negative means infinite
        int size = default(-1);

}
