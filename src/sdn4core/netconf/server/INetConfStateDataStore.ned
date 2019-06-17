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

package sdn4core.netconf.server;

//
// Contains the common interface of a netconf config store.
// This module handles state netconf requests. A device which is configurable with Netconf
// needs to contain an inherited version of this interface to respond to state requests.
//
// Modules of types cListener can subscribe to this module to be notified on updates.
//
// @author Timo Haeckel, for HAW Hamburg
//
moduleinterface INetConfStateDataStore extends INetConfDataStore
{
    parameters:
        @display("i=block/buffer2");
        
}
