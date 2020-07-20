//
// c Timo Haeckel, for HAW Hamburg
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

package sdn4core.examples.netconf_test.netconf_test_standardhost;

import sdn4core.netconf.nodes.NetConfManagementUnit;
//INET
import inet.node.inet.StandardHost;

//
// An example Host for the Management Unit using a standard inet ipv4 host.
//
// @author Timo Haeckel, for HAW Hamburg
//
module ManagementUnit extends StandardHost
{
    parameters:
    	hasTcp = true;
    	int numNetConfApps = default(0);
    	string netConfClientType = default("");
    
    gates:
        // no additional gates needed
    
    submodules:        
        
        // Netconf Client module
        netConfClient: NetConfManagementUnit{
            numNetConfApps = numNetConfApps;
            netConfClientType = netConfClientType;
        }
        
    connections: 
        netConfClient.transportIn <-- tcp.appOut++;
        netConfClient.transportOut --> tcp.appIn++;
}
