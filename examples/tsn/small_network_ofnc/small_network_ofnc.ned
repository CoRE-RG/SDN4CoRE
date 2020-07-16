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

package sdn4core.examples.tsn.small_network_ofnc;

import inet.node.ethernet.Eth100M;
import inet.node.ethernet.Eth1G;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

//
// Small sample network with three hosts and one switch that shows how to 
// configure the IEEE 802.1Q Model. Configuration in omnetpp.ini
// - 80ns Tick length
//
network small_network_ofnc
{
    parameters:
        @display("bgb=,,white");
    submodules:
        configurator: IPv4NetworkConfigurator {
            @display("p=39,19");
        }

        node1: Node1 {
            @display("p=39,107");
        }

        node2: Node2 {
            @display("p=249,67");
        }

        node3: Node3 {
            @display("p=249,139");
        }

        controller: Controller {
            @display("p=147,36");
        }

        switch1: Switch1 {
            parameters:
                @display("p=147,107");
            gates:
                gateDataPlane[3];
        }
        
    connections:
        //
        // The example uses a simple star topology
        //
        node1.ethg <--> Eth100M {  length = 20m; } <--> switch1.gateDataPlane[0];
        node2.ethg <--> Eth100M {  length = 10m; } <--> switch1.gateDataPlane[1];
        node3.ethg <--> Eth100M {  length = 5m; } <--> switch1.gateDataPlane[2];

        controller.ethg++ <--> Eth1G {  length = 10m; } <--> switch1.gateControlPlane;

}
