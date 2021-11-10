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

package sdn4core.examples.soa.someip;

import inet.node.ethernet.EtherLink;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

network SomeIpSDSmallTestNetwork
{
    parameters:
    types:
        channel ETH_1GBIT extends EtherLink
        {
            datarate = 1Gbps;
            length = 1.0m;
        }
        channel ETH_100MBIT extends EtherLink
        {
            datarate = 100Mbps;
            length = 5.0m;
        }

    submodules:
        Node1: Node1 {
            @display("p=30,112");
        }
        Node2: Node2 {
            @display("p=172,169");
        }

        Node3: Node3 {
            @display("p=315,112");
        }

        switch: Switch {
            parameters:
                @display("p=172,111");
            gates:
                gateDataPlane[3];
        }

        controller: Controller {
            @display("p=172,36");
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=315,155");
        }

    connections:
        Node1.ethg <--> ETH_100MBIT <--> switch.gateDataPlane[0];
        Node2.ethg <--> ETH_100MBIT <--> switch.gateDataPlane[1];
        Node3.ethg <--> ETH_100MBIT <--> switch.gateDataPlane[2];

        controller.ethg++ <--> ETH_1GBIT <--> switch.gateControlPlane;
}
