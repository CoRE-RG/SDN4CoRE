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
import core4inet.services.avb.SRP.SRProtocol;

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
        string pathSwitchAgent = default(absPath(".switchAgent"));
        relayUnitType = default("AVB_OF_RelayUnit");
        switchAgentType = default("AVB_OF_SwitchAgent");
        ethDataPlaneType = default("AVBEthernetInterface");

        *.srpTable = default(absPath(".srpTable"));
        *.srpProtocolModule = default(absPath(".srpProtocol"));

        @display("bgb=642,289");
    submodules:
	    // Stream Reservation Protocol table
        srpTable: SRPTable {
            @display("p=431,241");
        }

		// Stream Reservation Protocol implementation
        srpProtocol: SRProtocol {
            portModule = "etherMAC";
			srpEncap = pathSwitchAgent;
            @display("p=325,241");
        }

    connections allowunconnected:
	    //The direct connection works in the current omnet version but throws an error in the IDE
	    //Both srp gates will be connected in the initialization of the switch agent 
	    //srpProtocol.out --> switchAgent.srpIn;
		//srpProtocol.in <-- switchAgent.srpOut;
}
