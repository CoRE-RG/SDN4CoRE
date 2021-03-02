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
import sdn4core.switch.IOF_RelayUnit;

//
// The OF_RelayUnit implements the switching engine of an OpenFlow Switch.
// It is directly connected to the TCP module to communicate with the OF Controller.
// It handles the forwarding of incoming packets by matching them with the OpenFlowTable 
// (@see~IOpenFlowFlowTable) entries.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple OF_RelayUnit like IOF_RelayUnit
{
    parameters:
        @class(SDN4CoRE::OF_RelayUnit);
        
     	@signal[forwardToCon](type=inet::EthernetIIFrame);
     	@signal[tableMissSign](type=inet::EthernetIIFrame);
     	
     	
        @signal[cpPingPacketHash](type="unsigned long");
        @statistic[cpPingPacketHash](title="CpPingPacketHash"; record=vector?,stats; interpolationmode=none);
        @signal[dpPingPacketHash](type="unsigned long");
        @statistic[dpPingPacketHash](title="DpPingPacketHash"; record=vector?,stats; interpolationmode=none);
        @display("i=block/app");
        
        // paths to other modules
        string interfaceTableModule;   // The path to the InterfaceTable module
		bool highlightActivePorts = default(false);
		//Path of the switch configuration xml file
    	xml configXML = default(xml("<root/>"));
    	
    	
    gates:        
        input  dataPlaneIn[];
        output dataPlaneOut[];
}
