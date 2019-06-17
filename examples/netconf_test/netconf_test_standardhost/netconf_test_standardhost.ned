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
import sdn4core.netconf.nodes.NetConfManagementUnit;

//
// This is a test network for the basic netconf functionality. It contains a Management 
// Unit (@see ~NetConfManagementUnit) and a Managed Unit (@see ~NetConfManagedUnit). 
//
network netconf_test_standardhost
{
    submodules:
        managedUnit: NetConfManagedUnit{
        }
        
        managementUnit: NetConfManagementUnit{
        }
        
    connections:
        managementUnit.ethg++ <--> managedUnit.ethg++;
}
