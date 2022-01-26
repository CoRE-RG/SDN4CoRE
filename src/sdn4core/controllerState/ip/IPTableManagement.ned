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

package sdn4core.controllerState.ip;

import sdn4core.controllerState.base.ControllerStateManagementBase;

//
// Module that manages IP RoutingTables for Controller Applications.
// It holds one RoutingTable per switch.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple IPTableManagement extends ControllerStateManagementBase
{
    parameters:
    	@class(SDN4CoRE::MACTableManagement);
    	switchStateModulePath = default ("sdn4core.controllerState.ip.FriendIPv4RoutingTable"); // ned path to state module 
        switchStateModuleName = default ("routingTable"); // name of the module to hold the state per switch
        string localAddress = default("auto");
        
        // parameters to be set for all RoutingTables 
}
