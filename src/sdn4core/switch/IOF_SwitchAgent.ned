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

package sdn4core.switch;

//
// Interface module for OpenFlowRealyUnits implementing the flow based forwarding.
//

//
// Prototype for modules providing OpenFlow rule based Ethernet switch functionality.
// These modules forward frames (@see ~EtherFrame) to appropriate ports.
//
// Functions:
// - relays frames based on OpenFlow matching to OpenFlow Table entries (@see ~OF_FlowTable)
// - models finite buffer size (drops) and finite processing power (latency, queueing)
//
//
// This module is not a concrete implementation, it just defines gates and
// parameters a ~IOpenFlowRelayUnit should have. Concrete inplementations add
// capacity and performance aspects to the model (number of frames processed
// per second, amount of memory available in the switch, etc.)
//
// Known implementations are ~OF_Switch
//
// @author Timo Haeckel, for HAW Hamburg
//
moduleinterface IOF_SwitchAgent
{
    parameters:
        @display("i=block/switch");
        
        // paths to other modules
        string interfaceTableModule;   // The path to the InterfaceTable module
        
        // Modelling a realistic environment
        double serviceTime @unit("s");		// The relay units service time, models finite processing power 
        int bufferCapacity; 	// Max. number of frames in Buffer, infinity if <= 0
        
        // Local TCP connection
        string localAddress;
        int localPort;
        
        // OpenFlow controller connection
		double connectAt @unit("s"); // Simtime at which the switch connects to the controller.
        string connectAddress; // controller address
        int connectPort; // controller port
        
    gates:
        // control plane port connection
        input controlPlaneIn @labels(TCPCommand/up);
        output controlPlaneOut @labels(TCPCommand/down);
        
}

