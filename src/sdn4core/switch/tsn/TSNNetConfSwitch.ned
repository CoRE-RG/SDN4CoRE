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

import sdn4core.netconf.nodes.NetConfManagedUnit;

//INET
import inet.linklayer.contract.IWiredNic;
import inet.networklayer.contract.INetworkLayer;
import inet.networklayer.contract.IRoutingTable;
import inet.transportlayer.contract.ITCP;

//CoRE4INET
import core4inet.nodes.ethernet.tsn.TSNEtherSwitch;


//
// This module adds programmable parameters via NetConf to the a NON-OPENFLOW TSN switch.
// This allows to change the configuration of TSN modules via NetConf, e.g., the 802.1Qbv gcl schedule.
//
// @author Timo Haeckel, for HAW Hamburg
//
module TSNNetConfSwitch extends TSNEtherSwitch
{
    parameters:

        // Interface Submodule types to be exchangeable in inheriting modules
        string routingTableType = default("IPv4RoutingTable");
        string ethControlPlaneType = default("TSNEtherNic");
        string networkLayerType = default("RTNetworkLayer");
        string tcpType = default("TCP");
        
        bool routingforwarding = default(false);
        bool multicastForwarding = default(false);
        routingTable.forwarding = this.routingforwarding;
        routingTable.multicastForwarding = this.multicastForwarding;   // for IPv4, IPv6, Generic
        *.routingTableModule = default(absPath(".routingTable"));
        networkLayer.proxyARP = false;
        
        string srpTableModule = default(absPath(".srpTable"));

        // NETCONF settings
        double nc_service_time @unit(s) = default(0s);
        string netConfServerType = default("NetConfServerTCP");
        int numConfigurators = default(2);
        string qbv_configuratorType = default("NetConfDataConfiguratorIEEE8021Qbv");
        string srp_configuratorType = default("NetConfDataConfiguratorSRP");

    gates:
        inout gateControlPlane @labels(ControlPlane);

    submodules:

        // Interface Table module for all Ethernet interfaces
//        interfaceTable: InterfaceTable {
//            @display("p=35,38");
//        }

        // Routing module for the controlplane network, every inet host contains one
        routingTable: <routingTableType> like IRoutingTable if routingTableType != "" {
            parameters:
                @display("p=500,135");
        }

        // Ethernet Interface module for the control plane port
        eth[sizeof(gateControlPlane)]: <ethControlPlaneType> like IWiredNic {
            @display("p=600,50");
        }

        // NetworkLayer module for the control plane port
        networkLayer: <networkLayerType> like INetworkLayer {
            @display("p=500,50");
            gates:
                ifIn[1];
                ifOut[1];
        }

        // TCP module for the control plane port
        tcp: <tcpType> like ITCP {
            @display("p=420,50");
        }

        // Netconf Server module
        netconf: NetConfManagedUnit {
            processingTime = parent.nc_service_time;
            netConfServerType = parent.netConfServerType;
            numConfigurators = parent.numConfigurators;
            configurators[0].typename = parent.qbv_configuratorType;
            configurators[0].etherMacModule = default("phy");
            configurators[1].typename = parent.srp_configuratorType;
            configurators[1].ofSrpTableModule = parent.srpTableModule;
            @display("p=420,135");
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
        
        netconf.transportIn <-- tcp.appOut++;
        netconf.transportOut --> tcp.appIn++;

}
