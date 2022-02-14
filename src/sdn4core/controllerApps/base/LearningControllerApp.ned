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
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.controllerApps.base;

import sdn4core.controllerApps.base.PacketProcessorBase;

//
// LearningControllerApp is an SDN controller application that flow rule creation
// for basic traffic forwarding. 
//
// @author Timo Haeckel, for HAW Hamburg
//
simple LearningControllerApp extends PacketProcessorBase
{
    parameters:
        @class(SDN4CoRE::LearningControllerApp);
        string hostTablePath = default("^.controllerState.hostTable");
        string deviceTablePath = default("^.controllerState.deviceTable");
        string topologyManagementPath = default("^.controllerState.topology");
        
        // match different layers in created flow mod flow entries
        // defaults to iport + l2 (src + dest + vid)        
        bool matchInport = default(true);
        bool matchL2Src = default(true); 
        bool matchL2Dest = default(true);
        bool matchL2Type = default(false); 
        bool matchL2VID = default(true);
        bool matchL2PCP = default(false);
        bool matchL3Src = default(false);
        bool matchL3Dest = default(false);
        bool matchL3Proto = default(false);
        bool matchL4Src = default(false);
        bool matchL4Dest = default(false);         
        
        bool matchAll = default(false); // overwrites the other match settings.
}
