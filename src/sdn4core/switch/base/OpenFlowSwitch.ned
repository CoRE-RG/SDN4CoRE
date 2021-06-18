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

package sdn4core.switch.base;
//INET
import inet.networklayer.common.InterfaceTable;
import inet.linklayer.contract.IWiredNic;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.contract.IRoutingTable;
import inet.transportlayer.contract.ITCP;
import inet.common.lifecycle.NodeStatus;
//OPENFLOW
import openflow.openflow.switch.flowtable.IOpenFlowFlowTable;
import sdn4core.switch.IOF_RelayUnit;
import sdn4core.switch.IOF_SwitchAgent;
//OF_SWITCHAGENT
import sdn4core.switch.base.engine.OF_SwitchAgent;
import sdn4core.switch.base.engine.OF_RelayUnit;

//
// Model of an OpenFlow Ethernet switch.
//
// The duplexChannel attributes of the MACs must be set according to the
// medium connected to the port; if collisions are possible (it's a bus or hub)
// it must be set to false, otherwise it can be set to true.
//
// @author Timo Haeckel, for HAW Hamburg
//
module OpenFlowSwitch
{
    parameters:
        @networkNode();
        @OF_Switch();
        @labels(node,ethernet-node);
        @display("i=device/switch;i2=OpenFlow-Logo-small");

        // Should Packet ins contain the full packet.
        bool sendCompletePacket = default(true);
        // service time of the relay unit for openflow interactions
        double of_service_time @unit(s) = default(0s);
        //hardware delay for the forwarding of packets
        double hardware_delay @unit(s) = default(8us);
        double egress_delay @unit(s) = default(hardware_delay/2);
        double ingress_delay @unit(s) = default(hardware_delay/2);
        // number of flow tables in this switch
        int numFlowTables = default(1);

		// Interface Submodule types to be exchangeable in inheriting modules
        string routingTableType = default("IPv4RoutingTable");
        string ethControlPlaneType = default("EthernetInterface");
        string networkLayerType = default("IPv4NetworkLayer");
        string tcpType = default("TCP");
        string relayUnitType = default("OF_RelayUnit");
        string switchAgentType = default("OF_SwitchAgent");
        string ethDataPlaneType = default("EthernetInterface");
        string ofFlowTableType = default("OF_FlowTable");

        // submodule settings
        bool csmacdSupport = default(true);  // by default use CSMA/CD
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex
        bool routingforwarding = default(false);
        bool multicastForwarding = default(false);
        routingTable.forwarding = routingforwarding;
        routingTable.multicastForwarding = multicastForwarding;   // for IPv4, IPv6, Generic
        etherMAC[*].encapType = "EtherEncapDummy";
        etherMAC[*].csmacdSupport = csmacdSupport;
        etherMAC[*].macType = macType;
        networkLayer.proxyARP = false;

        // Setting paths in all submodules in need of those modules
        *.routingTableModule = default(absPath(".routingTable"));
        *.interfaceTableModule = default(absPath(".interfaceTable"));

    gates:
        inout gateControlPlane @labels(ControlPlane);
        inout gateDataPlane[] @labels(DataPlane);

    types:
        channel ProcessingDelay extends ned.DelayChannel
        {
        }

    submodules:

        // Keeps track of the status of network node (up, down, etc.)
        status: NodeStatus {
            @display("p=597,38;is=n");
        }

        // Interface Table module for all Ethernet interfaces
        interfaceTable: InterfaceTable {
            @display("p=35,38");
        }

        // Routing module for the controlplane network, every inet host contains one
        routingTable: <routingTableType> like IRoutingTable if routingTableType != "" {
            parameters:
                @display("p=137,38");
        }

        // Ethernet Interface module for the control plane port
        eth[sizeof(gateControlPlane)]: <ethControlPlaneType> like IWiredNic {
            @display("p=35,143");
        }

        // NetworkLayer module for the control plane port
        networkLayer: <networkLayerType> like INetworkLayer {
            @display("p=137,143");
            gates:
                ifIn[1];
                ifOut[1];
        }

        // TCP module for the control plane port
        tcp: <tcpType> like ITCP {
            @display("p=226,143");
        }

        // OpenFlow RelayUnit
        relayUnit: <relayUnitType> like IOF_RelayUnit{
            parameters:
                @display("p=431,143");
            gates:
                dataPlaneOut[sizeof(gateDataPlane)];
                dataPlaneIn[sizeof(gateDataPlane)];
        }

        // OpenFlow SwitchAgent
        switchAgent: <switchAgentType> like IOF_SwitchAgent {
            parameters:
                serviceTime = of_service_time;
                @display("p=325,143");
        }

        // Ethernet Interface modules for the data plane ports
        etherMAC[sizeof(gateDataPlane)]: <ethDataPlaneType> like IWiredNic {
            parameters:
                mac.promiscuous = true;
                @display("p=597,143,c,50");
        }

		// Flow Table module contains match entries and resulting actions
        flowTables[numFlowTables]: <ofFlowTableType> like IOpenFlowFlowTable {
            @display("p=431,38");
        }

    connections allowunconnected:

        // control plane connections
        for i=0..sizeof(gateControlPlane)-1 {
            eth[i].phys <--> gateControlPlane;
            eth[i].upperLayerIn <-- networkLayer.ifOut++;
            eth[i].upperLayerOut --> networkLayer.ifIn++;
        }
        tcp.ipOut --> networkLayer.transportIn++;
        tcp.ipIn <-- networkLayer.transportOut++;
        tcp.appOut++ --> switchAgent.controlPlaneIn;
        tcp.appIn++ <-- switchAgent.controlPlaneOut;

        // data plane connections
        for i=0..sizeof(gateDataPlane)-1 {
            etherMAC[i].phys <--> gateDataPlane[i];
            etherMAC[i].upperLayerOut --> ProcessingDelay {  delay = (ingress_delay); } --> relayUnit.dataPlaneIn[i];
            etherMAC[i].upperLayerIn <-- ProcessingDelay {  delay = (egress_delay); } <-- relayUnit.dataPlaneOut[i];
        }

}
