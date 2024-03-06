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

package sdn4core.examples.soa.qosSmall;

import inet.node.ethernet.EtherLink;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

network SomeIp_Qos_Small
{
    parameters:
        double linkspeed @unit(bps) = default(100Mbps);
    submodules:
        configurator: IPv4NetworkConfigurator {
         	parameters:
     	       config = xmldoc("ipv4config.xml");
        }
        
        N[4]: Node;
        
        CT[2]: Node;
        
        S[3]: Switch {
            switchAgent.connectAddress = "controller";
			switchAgent.connectAt = 0s;
        }
        
        controller: Controller;
        
    connections:
        // connect controplane
        S[0].gateControlPlane <--> EtherLink{datarate=parent.linkspeed;} <--> controller.ethg++;
        S[1].gateControlPlane <--> EtherLink{datarate=parent.linkspeed;} <--> controller.ethg++;
        S[2].gateControlPlane <--> EtherLink{datarate=parent.linkspeed;} <--> controller.ethg++;
        
        // connect switches
        S[0].gateDataPlane++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[1].gateDataPlane++;
        S[1].gateDataPlane++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[2].gateDataPlane++;
        
        // connect nodes
        N[0].ethg++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[0].gateDataPlane++;
        N[1].ethg++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[1].gateDataPlane++;
        N[2].ethg++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[2].gateDataPlane++;
        N[3].ethg++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[1].gateDataPlane++;
        
        // connect ct nodes        
        CT[0].ethg++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[0].gateDataPlane++;
        CT[1].ethg++ <--> EtherLink{datarate=parent.linkspeed;} <--> S[2].gateDataPlane++;
}
