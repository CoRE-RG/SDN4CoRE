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

package sdn4core.netconf.datastores.store.base;

//
// Contains the common interface of a netconf config data store.
// NetConfConfigDataStore implementations execute netconf commands on the 
// device such as get, copy and edit config commands.
// They are managed and dynamically created during runtime by 
 // @see~INetConfDataStoreManager modules.
//
// @author Timo Haeckel, for HAW Hamburg
//
moduleinterface INetConfDataStore
{
    //these modules are used via direct method calls.
}
