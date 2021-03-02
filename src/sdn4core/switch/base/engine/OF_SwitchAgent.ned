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

package sdn4core.switch.base.engine;

//openflow
import sdn4core.switch.IOF_SwitchAgent;

//
// The OF_RelayUnit implements the switching engine of an OpenFlow Switch.
// It is directly connected to the TCP module to communicate with the OF Controller.
// It handles the forwarding of incoming packets by matching them with the OpenFlowTable 
// (@see~IOpenFlowFlowTable) entries.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple OF_SwitchAgent like IOF_SwitchAgent
{
    parameters:
        @class(SDN4CoRE::OF_SwitchAgent);
		       
        @signal[queueSize](type="unsigned long");
        @statistic[queueSize](title="QueueSize"; record=vector?,stats; interpolationmode=none);
        @signal[bufferSize](type="long");
        @statistic[bufferSize](title="BufferSize"; record=vector?,stats; interpolationmode=none);
        @signal[waitingTime](type="simtime_t");
        @statistic[waitingTime](title="WaitingTime"; record=vector?,stats?; interpolationmode=none);
        @display("i=block/app");
        
        string interfaceTableModule;   // The path to the InterfaceTable module
        string localAddress = default("");
        int localPort = default(-1);
        string connectAddress = default(""); // controller address
        int connectPort = default(6633);// controller port
        
        // Modelling a realistic environment
		double flowTimeoutPollInterval @unit("s") = default(1s);
		double connectAt @unit("s") = default(0s);  // Simtime at which the switch connects to the controller.
		double serviceTime @unit(s) = default(0s);
		int bufferCapacity = default(0); 	// Max. number of frames in Buffer, infinity if <= 0

		bool parallelProcessing = default(false); // only effects openflow messages
		bool sendCompletePacket = default(true);
		
		//Path of the switch configuration xml file
    	xml configXML = default(xml("<root/>"));

    gates:
        input controlPlaneIn @labels(TCPCommand/up);
        output controlPlaneOut @labels(TCPCommand/down);
        
}
