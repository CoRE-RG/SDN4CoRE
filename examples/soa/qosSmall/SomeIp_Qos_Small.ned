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

import inet.node.ethernet.Eth100M;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;

network SomeIp_Qos_Small
{
    parameters:
    submodules:
        configurator: IPv4NetworkConfigurator;
        
        N[4]: Node;
        
        CT[2]: Node;
        
        S[3]: Switch;
        
    connections:
        // connect switches
        S[0].ethg++ <--> Eth100M <--> S[1].ethg++;
        S[1].ethg++ <--> Eth100M <--> S[2].ethg++;
        
        // connect nodes
        N[0].ethg++ <--> Eth100M <--> S[0].ethg++;
        N[1].ethg++ <--> Eth100M <--> S[1].ethg++;
        N[2].ethg++ <--> Eth100M <--> S[2].ethg++;
        N[3].ethg++ <--> Eth100M <--> S[1].ethg++;
        
        // connect ct nodes
        
        CT[0].ethg++ <--> Eth100M <--> S[0].ethg++;
        CT[1].ethg++ <--> Eth100M <--> S[2].ethg++;
        
}
