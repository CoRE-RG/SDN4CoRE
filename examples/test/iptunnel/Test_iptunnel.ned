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

package sdn4core.examples.test.iptunnel;

import inet.node.ethernet.EtherLink;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

//
// TODO Auto-generated network
//
network Test_iptunnel
{
    parameters:
    types:
        channel ETH_1GBIT extends EtherLink
        {
            datarate = 1Gbps;
            length = 1.0m;
        }
    submodules:
        configurator: IPv4NetworkConfigurator {
            @display("p=22,20");
        }
        node: Node {
            @display("p=45,120");
        }
        switch: Switch {
            parameters:
                @display("p=172,119");
            gates:
                gateDataPlane[1];
        }
        controller: Controller {
            @display("p=172,42");
        }
    connections:
        node.ethg++ <--> ETH_1GBIT <--> switch.gateDataPlane[0];
        controller.ethg++ <--> ETH_1GBIT <--> switch.gateControlPlane;
}
