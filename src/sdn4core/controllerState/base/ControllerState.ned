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

package sdn4core.controllerState.base;

//
// Collection of controller state and state management modules.
//
// @author Timo Haeckel, for HAW Hamburg
//
module ControllerState
{
    parameters:
        @display("i=block/network2");
        bool hasMACState = default(false); // L2 MAC SAT state
        string macManagementType = default("MACTableManagement");
        bool hasSRPState = default(false); // TSN/AVB SR state
        string srpManagementType = default("SRPTableManagement");

    submodules:

        // vector for dynamically create per switch state
        switchState[0]: ControllerSwitchState {
         	@display("p=50,50,r,50");   
        }
        
        macManagement : <macManagementType> like IControllerStateManagement if hasMACState {
        	@display("p=50,150");
        };
        
        srpManagement : <srpManagementType> like IControllerStateManagement if hasSRPState {
        	@display("p=150,150");
        };
}

//
// Empty compound module to dynamically created and access submodules that contain controller state.
//
module ControllerSwitchState
{
    parameters:
        @display("i=block/switch");
        string switchName = default("");
}

moduleinterface IControllerStateManagement
{
	parameters:
        @display("i=block/cogwheel");
}
