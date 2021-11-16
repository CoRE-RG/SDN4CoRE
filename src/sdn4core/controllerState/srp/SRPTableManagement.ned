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

package sdn4core.controllerState.srp;

import sdn4core.controllerState.base.ControllerStateManagementBase;

//
// Module that manages SRPTables for Controller Applications.
// It holds one SRPTabel per switch.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple SRPTableManagement extends ControllerStateManagementBase
{
    parameters:
    	@class(SDN4CoRE::SRPTableManagement);
    	switchStateModulePath = default ("core4inet.services.avb.SRP.SRPTable"); // ned path to state module 
        switchStateModuleName = default ("srpTable"); // name of the module to hold the state per switch
        
        //Entries not updated are deleted after agingTime (0 means disabled)
        double agingTime @unit("s") = default(7s); // default from CoRE4INET::SRPTable
}
