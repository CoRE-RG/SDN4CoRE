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

//INET
import inet.common.misc.ThruputMeteringChannel;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.EtherSwitch;

//
// This is a test network for the basic netconf functionality. It contains a Management 
// Unit (@see ~NetConfManagementUnit) and a Managed Unit (@see ~NetConfManagedUnit). 
//
network netconf_test_standardhost
{
    parameters:
        int numOfManagers = default(1);
        int numOfManaged = default(1);

    types:
        channel connection extends ThruputMeteringChannel
        {
            delay = 1us;
            datarate = 1Gbps;
            thruputDisplayFormat = "u";
        }

    submodules:

        configurator: IPv4NetworkConfigurator;
        
        managedUnit[numOfManaged]: ManagedUnit {
            @display("p=95,234,r,50");
        }

        managementUnit[numOfManagers]: ManagementUnit {
            @display("p=95,68,r,50");
        }

        switch: EtherSwitch {
            @display("p=95,151");
        }

    connections:
        for i=0..numOfManagers-1 {
            managementUnit[i].ethg++ <--> connection <--> switch.ethg++;
        }
        for i=0..numOfManaged-1 {
            managedUnit[i].ethg++ <--> connection <--> switch.ethg++;
        }
}
