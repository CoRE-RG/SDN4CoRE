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

package sdn4core.controller.base;

import sdn4core.controller.base.NetworkControllerBase;

//INET
import inet.applications.contract.ITCPApp;
import inet.linklayer.ethernet.EthernetInterface;
import inet.networklayer.common.InterfaceTable;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.contract.IRoutingTable;
import inet.transportlayer.contract.ITCP;
//OPENFLOW
import openflow.controllerApps.AbstractControllerApp;
import openflow.openflow.controller.IOpenFlowController;

//
// Base model of an OpenFlow controller that contains a more flexible and extendable 
// implementation then @see ~Open_Flow_Controller.
// An OpenFlow controller controlls the forwarding engines of all networking devices in the network.
//
// @author Timo Haeckel, for HAW Hamburg
//
module OpenFlowControllerBase extends NetworkControllerBase
{
    parameters:
        int numControllerApps = default(0);
        int numTcpControllerApps = default(0);
        string openflowControllerType = default("OF_Controller");

        //submodules
        hasTcp = true;
        tcpType = default("TCP");  // tcp implementation (e.g. TCP, TCP_old, TCP_NSC)
        networkLayerType = default("IPv4NetworkLayer");
        routingTableType = default("IPv4RoutingTable");
        forwarding = default(false);
        multicastForwarding = default(false);
        numExtInterfaces = default(0);
        double serviceTime @unit("s") = default(0s);

        *.routingTableModule = default(absPath(".routingTable"));
        *.interfaceTableModule = default(absPath(".interfaceTable"));

    gates:
        // no additional gates needed.
    submodules:

        controllerApps[numControllerApps]: <> like AbstractControllerApp {
            parameters:
                @display("p=519,141,row,60");
        }

        tcpControllerApps[numTcpControllerApps]: <> like ITCPApp {
            parameters:
                @display("p=200,141,row,60");
        }

        OF_Controller: <openflowControllerType> like IOpenFlowController {
            @display("p=149,281");
            serviceTime = serviceTime;
        }
    connections allowunconnected:

        for i=0..numTcpControllerApps-1 {
            tcpControllerApps[i].tcpOut --> tcp.appIn++;
            tcpControllerApps[i].tcpIn <-- tcp.appOut++;
        }

        tcp.appOut++ --> OF_Controller.tcpIn;
        OF_Controller.tcpOut --> tcp.appIn++;
}


