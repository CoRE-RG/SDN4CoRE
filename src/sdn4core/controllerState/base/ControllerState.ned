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
        bool hasDeviceTable = default(true); // Network Device state
        string deviceTableType = default("DeviceTable");
        bool hasHostTable = default(true); // L2/L3 Host State
        string hostTableType = default("HostTable");
        bool hasTopologyManagement = default(true); // L2/L3 Host State
        string topologyManagementType = default("TopologyManagement");
        bool hasSRPState = default(false); // TSN/AVB SR state
        string srpManagementType = default("SRPTableManagement");

    submodules:
        
        deviceTable : <deviceTableType> like IControllerStateManagement if hasDeviceTable {
        	@display("p=50,50");
        };
        
        hostTable : <hostTableType> like IControllerStateManagement if hasHostTable {
        	@display("p=150,50");
        };
        
        topology : <topologyManagementType> like IControllerStateManagement if hasTopologyManagement {
        	@display("p=250,50");
        };
        
        srpTableManagement : <srpManagementType> like IControllerStateManagement if hasSRPState {
        	@display("p=350,50");
        };

        // vector for dynamically created switch state
        switchState[0]: ControllerSwitchState {
         	@display("p=50,150,m,5,70,70");   
        }
}

//
// Empty compound module to dynamically created and access submodules that contain controller state.
//
// @author Timo Haeckel, for HAW Hamburg
//
module ControllerSwitchState
{
    parameters:
        @display("i=block/switch");
        string switchName = default("");
}

//
// Module Interface fro controller state management implementations.
// @see also ~ControllerStateManagementBase
//
// @author Timo Haeckel, for HAW Hamburg
//
moduleinterface IControllerStateManagement
{
	parameters:
        @display("i=block/cogwheel");
}
