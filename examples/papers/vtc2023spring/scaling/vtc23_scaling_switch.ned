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

package sdn4core.examples.papers.vtc2023spring.scaling;

import inet.node.ethernet.EtherLink;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import core4inet.nodes.ethernet.IEEE8021Q.IEEE8021QEtherSwitch;
import inet.node.inet.Router;

network vtc23_scaling_switch
{
    parameters:
        int numSwitches = default(2);
        int numPublishers = default(1);
        int numSubscribers = default(1);
    types:
        channel ETH_1GBIT extends EtherLink
        {
            datarate = 1Gbps;
            length = 2.0m;
        }
        channel ETH_100MBIT extends EtherLink
        {
            datarate = 100Mbps;
            length = 1.0m;
        }
        
        channel BACKBONE_LINK extends ETH_1GBIT {}
        channel HOST_LINK extends ETH_1GBIT {}

    submodules:
        publishers[numPublishers]: Node {
        }
        
        subscribers[numSubscribers]: Node {
        }          
        
        switches[numSwitches]: IEEE8021QEtherSwitch {
        }

        configurator: IPv4NetworkConfigurator {
            @display("p=22,20");
        }

    connections:
        // backbone links
        for i=0..numSwitches-2 {
            switches[i].ethg++ <--> BACKBONE_LINK <--> switches[i+1].ethg++;
        } 
        
        // publisher connections
        for i=0..numPublishers-1 {
            publishers[i].ethg <--> HOST_LINK <--> switches[0].ethg++;
        }  
        
        // subscriber connections
        for i=0..numSubscribers-1 {
            subscribers[i].ethg <--> HOST_LINK <--> switches[numSwitches-1].ethg++;
        }  
}
