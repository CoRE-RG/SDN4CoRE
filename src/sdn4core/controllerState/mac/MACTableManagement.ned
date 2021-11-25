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

package sdn4core.controllerState.mac;

import sdn4core.controllerState.base.ControllerStateManagementBase;
import inet.linklayer.ethernet.switch.MACAddressTable;

//
// Module that manages MacTables for a Controller Application.
// It holds one MACTabel per switch.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple MACTableManagement extends ControllerStateManagementBase
{
    parameters:
    	@class(SDN4CoRE::MACTableManagement);
    	switchStateModulePath = default ("sdn4core.controllerState.mac.FriendMACAddressTable"); // ned path to state module 
        switchStateModuleName = default ("macTable"); // name of the module to hold the state per switch
        
        // parameters to be set for all MACTables 
        double agingTime @unit("s") = default(120s); // MAC Address aging default from inet::MACAddressTable         
}

//
// Extended MACAddressTable for controller state which has friend class MACTableManagement
//
simple FriendMACAddressTable extends MACAddressTable
{
    @class(SDN4CoRE::FriendMACAddressTable);
}
