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

package sdn4core.examples.netconf_test.ofnc_flowmod_test;

// Network Configuration
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

// 1 Gigabit/sec Ethernet link
import inet.node.ethernet.Eth1G;

// 100 megabit/sec Ethernet link
import inet.node.ethernet.Eth100M;

// for Switch
import inet.node.ethernet.EtherSwitch;



network small_network_ofnc_flowmod
{
    parameters:
        @display("bgb=500,500");
    submodules:
        configurator: IPv4NetworkConfigurator {

            @display("p=100,50");
        }
        controller: Controller {

            @display("p=200,50");
        }
        ethswitch: EtherSwitch {
            @display("p=200,125");
        }
        switch1: Switch1 {
            
            @display("p=100,200");
        }
        switch2: Switch2 {

            @display("p=300,200");
        }
        node1: Node1 {

            @display("p=100,300");
        }
        node2: Node2 {

            @display("p=300,300");
        }
        node3: Node3 {

            @display("p=400,300");
        }
    connections:
        controller.ethg++ <--> Eth1G {  length = 10m; } <--> ethswitch.ethg++;

        ethswitch.ethg++ <--> Eth1G {  length = 10m; } <--> switch1.gateControlPlane;
        ethswitch.ethg++ <--> Eth1G {  length = 10m; } <--> switch2.gateControlPlane;

        switch1.gateDataPlane++ <--> Eth100M {  length = 10m; } <--> switch2.gateDataPlane++;

        node1.ethg <--> Eth100M {  length = 10m; } <--> switch1.gateDataPlane++;
        node2.ethg <--> Eth100M {  length = 10m; } <--> switch2.gateDataPlane++;
        node3.ethg <--> Eth100M {  length = 10m; } <--> switch2.gateDataPlane++;
}