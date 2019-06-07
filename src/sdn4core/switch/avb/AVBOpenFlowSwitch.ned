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
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.switch.avb;

//CoRE4INET
import core4inet.services.avb.SRP.SRPTable;


import sdn4core.switch.avb.services.avb.SRP.OF_SRProtocol;
import sdn4core.switch.base.OpenFlowSwitch;


//
// Model of an OpenFlow Ethernet switch that supports stream reservations and AVB prioritized traffic.
// It forwards packets according to the flow table entries and is connected to the OpenFlow Controller.
//
// @author Timo Haeckel, for HAW Hamburg
//
module AVBOpenFlowSwitch extends OpenFlowSwitch
{
    parameters:
        relayUnitType = default("AVB_OF_RelayUnit");
        ethDataPlaneType = default("AVBEthernetInterface");

        *.srpTable = default(absPath(".srpTable"));
        *.srpProtocolModule = default(absPath(".srpProtocol"));

        @display("bgb=642,289");
    submodules:
	    // Stream Reservation Protocol table
        srpTable: SRPTable {
            @display("p=442,241");
        }

		// Stream Reservation Protocol implementation
        srpProtocol: OF_SRProtocol {
            portModule = "etherMAC";
            @display("p=371,241");
        }

    connections allowunconnected:
	    //AVB SRP connections will be made in RTOF Switch as it is of different submodule interface.
        //srpProtocol.out --> relayUnit.srpIn;
        //srpProtocol.in <-- relayUnit.srpOut;
}
