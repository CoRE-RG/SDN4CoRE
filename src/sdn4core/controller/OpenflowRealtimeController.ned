

package sdn4core.controller;

import inet.applications.contract.ITCPApp;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.contract.IRoutingTable;
import inet.transportlayer.contract.ITCP;

import openflow.controllerApps.AbstractControllerApp;
import openflow.openflow.controller.OF_Controller;


//
// OpenflowRealtimeController is a controller 
// TODO Why do we need a different controller for Realtime Purposes?
//
module OpenflowRealtimeController
{
    parameters:
        @networkNode();
        @labels(node,ethernet-node);
        @display("i=device/server;bgb=795,445;i2=OpenFlow-Logo-small");
        int numControllerApps = default(0);
        int numTcpControllerApps = default(0);

        string networkLayerType = default("IPv4NetworkLayer");
        string routingTableType = default("IPv4RoutingTable");

		//submodules
        string tcpType = default("TCP");  // tcp implementation (e.g. TCP, TCP_old, TCP_NSC)
        bool forwarding = default(false);
        bool multicastForwarding = default(false);
        string routingFile = default("");
        int numExtInterfaces = default(0);
        double serviceTime @unit("s") = default(0s);

        routingTable.forwarding = forwarding;
        routingTable.multicastForwarding = multicastForwarding;   // for IPv4, IPv6, Generic
        *.routingTableModule = default(absPath(".routingTable"));
        *.interfaceTableModule = default(absPath(".interfaceTable"));

    gates:
        inout ethg[] @labels(EtherFrame-conn);
    submodules:

        controllerApps[numControllerApps]: <> like AbstractControllerApp {
            parameters:
                @display("p=519,141,row,60");
        }

        tcpControllerApps[numTcpControllerApps]: <> like ITCPApp {
            parameters:
                @display("p=200,141,row,60");
        }
        tcp: <tcpType> like ITCP {
            parameters:
                @display("p=200,278");
        }
        routingTable: <routingTableType> like IRoutingTable if routingTableType != "" {
            parameters:
                @display("p=733,333");
        }
        networkLayer: <networkLayerType> like INetworkLayer {
            parameters:
                @display("p=355,278;q=queue");
            gates:
                ifIn[sizeof(ethg)];
                ifOut[sizeof(ethg)];
        }
        eth[sizeof(ethg)]: EthernetInterface {
            parameters:
                @display("p=519,278,row,90;q=txQueue");
        }
        interfaceTable: InterfaceTable {
            parameters:
                @display("p=733,226");
        }
        OF_Controller: OF_Controller {
            @display("p=56,278");
            serviceTime = serviceTime;
        }

    connections allowunconnected:
        tcp.ipOut --> networkLayer.transportIn++;
        tcp.ipIn <-- networkLayer.transportOut++;

        for i=0..sizeof(ethg)-1 {
            ethg[i] <--> eth[i].phys;
            eth[i].upperLayerOut --> networkLayer.ifIn[i];
            eth[i].upperLayerIn <-- networkLayer.ifOut[i];
        }

        for i=0..numTcpControllerApps-1 {
            tcpControllerApps[i].tcpOut --> tcp.appIn++;
            tcpControllerApps[i].tcpIn <-- tcp.appOut++;
        }

        tcp.appOut++ --> OF_Controller.tcpIn;
        OF_Controller.tcpOut --> tcp.appIn++;
}


