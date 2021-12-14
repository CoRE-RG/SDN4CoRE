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

package sdn4core.switch.tsn;

import sdn4core.switch.base.OpenFlowSwitch;
import core4inet.services.avb.SRP.SRProtocol;

//CoRE4INET
import core4inet.scheduler.ITTEScheduler;
import core4inet.synchronisation.base.ISync;
import core4inet.services.avb.SRP.SRPTable;
import core4inet.services.avb.SRP.SRProtocol;

//
// Model of an OpenFlow Ethernet switch that supports TSN ingress and egress control (@see~CoRE4INET::TSNPHYPort).
// It forwards packets according to the flow table entries and is connected to the OpenFlow Controller.
//
// @author Timo Haeckel, for HAW Hamburg
//
module TSNOpenFlowSwitch extends OpenFlowSwitch
{
    parameters:
        @display("i=device/switch;i2=OpenFlow-Logo-small");
        relayUnitType = default("TSN_OF_RelayUnit");
        switchAgentType = default("AVB_OF_SwitchAgent");
        ethDataPlaneType = default("TSNEthernetInterface");
        ethControlPlaneType = default("TSNEtherNic");
        networkLayerType = default("RTNetworkLayer");

        string ofSrpProtocolModule = default(absPath(".ofSrpProtocol"));
        string ofSrpTableModule = default(absPath(".ofSrpTable"));
        string srpProtocolModule = default(absPath(".srpProtocol"));
        string srpTableModule = default(absPath(".srpTable"));
     	string pathSwitchAgent = default(absPath(".switchAgent"));
     	string pathEth = default(absPath(".eth[0]"));

        eth[0].**.srpTable = srpTableModule;
        etherMAC[*].**.srpTable = ofSrpTableModule;
        switchAgent.srpProtocolModule = ofSrpProtocolModule;
        switchAgent.srpTable = ofSrpTableModule;
        relayUnit.srpTable = ofSrpTableModule;
		

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
        ofSrpTable: SRPTable {
            @display("p=431,240");
        }

		// Dataplane Stream Reservation Protocol implementation tunneled via openflow
        ofSrpProtocol: SRProtocol {
            srpTable = ofSrpTableModule;
            portModule = "etherMAC";
            srpEncap = pathSwitchAgent;
            @display("p=324.9,240.34999");
        }

		// Control Plane Stream Reservation Protocol implementation
        srpProtocol: SRProtocol {
            srpTable = srpTableModule;
            srpEncap = pathEth;
            @display("p=34.199997,240.34999");
        }

	    // Stream Reservation Protocol table
        srpTable: SRPTable {
            @display("p=137,240");
        }

    connections allowunconnected:
}
