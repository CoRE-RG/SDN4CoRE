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

import sdn4core.netconf.nodes.NetConfManagedUnit;
//INET
import inet.node.inet.StandardHost;

//
// An example Host for the Managed Unit using a standard inet ipv4 host.
//
// @author Timo Haeckel, for HAW Hamburg
//
module ManagedUnit extends StandardHost
{
    parameters:
        hasTcp = true;

    gates:
        // no additional gates needed

    submodules:
        // Netconf Client module
        netConfServer: NetConfManagedUnit{
            numConfigurators = 1;
            configurators[0].typename = "NetConfDataConfiguratorDummy";
        }

    connections:
        netConfServer.transportIn <-- tcp.appOut++;
        netConfServer.transportOut --> tcp.appIn++;

}
