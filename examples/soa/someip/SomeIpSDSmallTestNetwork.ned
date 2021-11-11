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
import core4inet.nodes.ethernet.IEEE8021Q.IEEE8021QEtherSwitch;

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
        Node1: Node {
            @display("p=29,164");
        }
        Node2: Node {
            @display("p=101,218");
        }

        Node3: Node {
            @display("p=314,164");
        }

        Node4: Node {
            @display("p=244,218");
        }

        switch1: Switch {
            parameters:
                @display("p=101,163");
            gates:
                gateDataPlane[3];
        }

        switch2: Switch {
            parameters:
                @display("p=244,163");
            gates:
                gateDataPlane[3];
        }

        ethswitch: IEEE8021QEtherSwitch {
           	parameters:
           	    @display("p=172,105");
           	    hardware_delay = 3us;
        }

        controller: Controller {
            @display("p=172,42");
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=22,20");
        }

    connections:
        Node1.ethg <--> ETH_100MBIT <--> switch1.gateDataPlane[0];
        Node2.ethg <--> ETH_100MBIT <--> switch1.gateDataPlane[1];

        Node3.ethg <--> ETH_100MBIT <--> switch2.gateDataPlane[0];
        Node4.ethg <--> ETH_100MBIT <--> switch2.gateDataPlane[1];

        switch2.gateDataPlane[2] <--> ETH_100MBIT <--> switch1.gateDataPlane[2];

        controller.ethg++ <--> ETH_1GBIT <--> ethswitch.ethg++;
        switch1.gateControlPlane <--> ETH_1GBIT <--> ethswitch.ethg++;
        switch2.gateControlPlane <--> ETH_1GBIT <--> ethswitch.ethg++;
}
