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
// Contains the common interface of a netconf config data store.
// A config store has a name and contains the full configuration information of the device.
// Its status indicates if it is currently active or not. 
// There can only be one active configuration.
//
// Modules of types cListener can subscribe to this module to be notified on updates.
//
// @author Timo Haeckel, for HAW Hamburg
//
moduleinterface  INetConfConfigDataStore extends INetConfDataStore
{
    parameters:
        @display("i=block/buffer2");
        
        // if true the running config will be marked green, candidate configs yellow and inactive red.
        bool displayStatus;
        
}
