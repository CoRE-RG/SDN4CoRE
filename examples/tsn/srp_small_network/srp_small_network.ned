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

package sdn4core.examples.tsn.srp_small_network;
// Network Configuration
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

// 1 Gigabit/sec Ethernet link
import inet.node.ethernet.Eth1G;

// 100 megabit/sec Ethernet link
import inet.node.ethernet.Eth100M;

// for Switch
import core4inet.nodes.ethernet.IEEE8021Q.IEEE8021QEtherSwitch;

import sdn4core.utility.dynamicparameters.DynamicChannelParameterChanger;

network srp_small_network
{
    parameters:
        @display("bgb=631,360");
    submodules:
        configurator: IPv4NetworkConfigurator {
            @display("p=81,50");
        }
        controller: Controller {
            @display("p=299,50");
        }
        switch: Switch {
            @display("p=299,220");
        }
        source1: Source {
            @display("p=81,221");
        }
        sink1: Sink {
            @display("p=514,145");
        }
        sink2: Sink {
            @display("p=514,299");
        }
    connections:
        controller.ethg++ <--> Eth1G {  length = 10m; } <--> switch.gateControlPlane;
        source1.ethg <--> Eth100M {  length = 10m; } <--> switch.gateDataPlane++;
        sink1.ethg <--> Eth100M {  length = 10m; } <--> switch.gateDataPlane++;
        sink2.ethg <--> Eth100M {  length = 10m; } <--> switch.gateDataPlane++;
}
