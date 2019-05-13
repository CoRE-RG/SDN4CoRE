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

package sdn4core.switch;


import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.contract.IRoutingTable;
import inet.transportlayer.contract.ITCP;

import core4inet.services.avb.SRP.SRPTable;
import sdn4core.switch.services.avb.SRP.OF_SRProtocol;

import sdn4core.switch.RTOFSwitch;
import openflow.openflow.switch.OF_FlowTable;

import sdn4core.switch.RealTimeEthernetPort;

// 
// The OpenflowRealtimeSwitch is a network node. 
// It forwards packets according to the flow table entries and is connected to the OpenFlow Controller.
// 
module OpenflowRealtimeSwitch
{
    parameters:
        @networkNode();
        @OF_Switch();
        @labels(node,ethernet-node);
        @display("i=device/switch;i2=OpenFlow-Logo-small");
        bool sendCompletePacket = default(true);
        double serviceTime @unit("s") = default(0s);
        bool csmacdSupport = default(true);  // by default use CSMA/CD
        string macType = default(csmacdSupport ? "EtherMAC" : "EtherMACFullDuplex"); // ~EtherMAC or ~EtherMACFullDuplex

        string networkLayerType = default("IPv4NetworkLayer");
        string routingTableType = default("IPv4RoutingTable");
		
		int numFlowTables = default(1);

        //submodules
        string tcpType = default("TCP");  // tcp implementation (e.g. TCP, TCP_old, TCP_NSC)
        bool forwarding = default(false);
        bool multicastForwarding = default(false);
        string routingFile = default("");

        routingTable.forwarding = forwarding;
        routingTable.multicastForwarding = multicastForwarding;   // for IPv4, IPv6, Generic
        *.routingTableModule = default(absPath(".routingTable"));
        *.interfaceTableModule = default(absPath(".interfaceTable"));

    gates:
        inout gateControlPlane[] @labels(ControlPlane);
        inout gateDataPlane[] @labels(DataPlane);

    submodules:

        interfaceTable: InterfaceTable {
            parameters:
                @display("p=75,196");
        }

        tcp: <tcpType> like ITCP {
            parameters:
                @display("p=315,121");
        }

        routingTable: <routingTableType> like IRoutingTable if routingTableType != "" {
            parameters:
                @display("p=75,51");
        }

        networkLayer: <networkLayerType> like INetworkLayer {
            parameters:
                @display("p=200,121;q=queue");
            gates:
                ifIn[sizeof(gateControlPlane)];
                ifOut[sizeof(gateControlPlane)];
        }
        eth[sizeof(gateControlPlane)]: EthernetInterface {
            parameters:
                @display("p=75,121,row,90;q=txQueue");
        }

        rtEtherPort[sizeof(gateDataPlane)]: RealTimeEthernetPort {
            @display("p=628,120,c,100");
        }

        OF_Switch: RTOFSwitch {
            @display("p=446,121");
            sendCompletePacket = sendCompletePacket;
            gates:
                dataPlaneOut[sizeof(gateDataPlane)];
                dataPlaneIn[sizeof(gateDataPlane)];
        }

        flowTables[numFlowTables]: OF_FlowTable {
            @display("p=446,196");
        }

		// Stream Reservation Protocol table
        srpTable: SRPTable {
            @display("p=537,35");
        }

		// Stream Reservation Protocol implementation
        srpProtocol: OF_SRProtocol {
            @display("p=446,35");
            srpTable = "^.srpTable";
        }

    connections allowunconnected:

        //AVB SRP
        srpProtocol.out --> OF_Switch.srpIn;
        srpProtocol.in <-- OF_Switch.srpOut;

        for i=0..sizeof(gateDataPlane)-1 {
            rtEtherPort[i].phys <--> gateDataPlane[i];
            OF_Switch.dataPlaneOut[i] --> rtEtherPort[i].upperLayerIn;
            rtEtherPort[i].upperLayerOut --> OF_Switch.dataPlaneIn[i];
        }

        //controlplane connections
        for i=0..sizeof(gateControlPlane)-1 {
            eth[i].phys <--> gateControlPlane[i];
            eth[i].upperLayerOut --> networkLayer.ifIn[i];
            eth[i].upperLayerIn <-- networkLayer.ifOut[i];
        }
        tcp.ipOut --> networkLayer.transportIn++;
        tcp.ipIn <-- networkLayer.transportOut++;

        tcp.appOut++ --> OF_Switch.controlPlaneIn;
        OF_Switch.controlPlaneOut --> tcp.appIn++;

}
