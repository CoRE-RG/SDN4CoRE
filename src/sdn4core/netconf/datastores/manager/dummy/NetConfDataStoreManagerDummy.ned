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

package sdn4core.netconf.datastores.manager.dummy;

import sdn4core.netconf.datastores.manager.base.NetConfDataStoreManagerBase;

//
// This is a dummy netconf data store manager that uses the dummy config 
// and state manager (@see ~NetConfConfigDataStoreDummy, ~NetConfStateDataStoreDummy)
// All request are answered empty and success.
// NetConfDataStoreManger implementations handle NetConf configuration and 
// state operations for a specific device. 
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfDataStoreManagerDummy extends NetConfDataStoreManagerBase
{
    parameters:
    	@class(SDN4CoRE::NetConfDataStoreManagerDummy);
}
