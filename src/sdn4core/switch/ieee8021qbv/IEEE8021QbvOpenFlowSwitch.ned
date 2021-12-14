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

package sdn4core.switch.ieee8021qbv;

import sdn4core.switch.base.OpenFlowSwitch;
import core4inet.services.avb.SRP.SRProtocol;

//CoRE4INET
import core4inet.scheduler.ITTEScheduler;
import core4inet.synchronisation.base.ISync;
import core4inet.services.avb.SRP.SRPTable;

//
// Model of an OpenFlow Ethernet switch that supports IEEE 802.1Qbv priority forwarding with Time-Aware Shaping (@see~CoRE4INET::IEEE8021QbvPHYPort).
// It forwards packets according to the flow table entries and is connected to the OpenFlow Controller.
//
// @author Timo Haeckel, for HAW Hamburg
//
module IEEE8021QbvOpenFlowSwitch extends OpenFlowSwitch
{
    parameters:
        @display("i=device/switch;i2=OpenFlow-Logo-small");
        ethDataPlaneType = default("IEEE8021QbvEthernetInterface");
        switchAgentType = default("AVB_OF_SwitchAgent");
        string pathSwitchAgent = default(absPath(".switchAgent"));

        *.srpTable = default(absPath(".srpTable"));
        *.srpProtocolModule = default(absPath(".srpProtocol"));

    submodules:

        // Sync module for synchronisation of the scheduler
        sync: <default("DummySync")> like ISync {
            parameters:
                @display("p=576,27");
        }

        // Scheduler for the device
        scheduler: <default("Scheduler")> like ITTEScheduler {
            parameters:
                @display("p=519,27");
        }

	    // Stream Reservation Protocol table
        srpTable: SRPTable {
            @display("p=442,241");
        }

		// Stream Reservation Protocol implementation
        srpProtocol: SRProtocol {
            portModule = "etherMAC";
            srpEncap = pathSwitchAgent;
            @display("p=371,241");
        }

    connections allowunconnected:
	    //AVB SRP connections will be made in RTOF Switch as it is of different submodule interface.
        //srpProtocol.out --> relayUnit.srpIn;
        //srpProtocol.in <-- relayUnit.srpOut;
}
