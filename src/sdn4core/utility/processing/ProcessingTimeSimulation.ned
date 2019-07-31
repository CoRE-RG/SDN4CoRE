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

package sdn4core.utility.processing;

//
// Base module to simulate processing time.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple ProcessingTimeSimulation
{
    parameters:
        @signal[queueSize](type="unsigned long");
        @statistic[queueSize](title="QueueSize"; record=vector?,stats; interpolationmode=none);
        @signal[waitingTime](type="simtime_t");
        @statistic[waitingTime](title="WaitingTime"; record=vector?,stats?; interpolationmode=none);
        
        // modelling realistic environment:
        // request processing time
       	double processingTime @unit(s) = default(0s);
       	
       	// allow parallel processing so new incoming 
       	// messages will be scheduled in processing time.
       	bool allowParallelProcessing = default(false);
       	
}
