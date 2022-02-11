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

package sdn4core.controllerApps.lldp;

import sdn4core.controllerApps.base.PacketProcessorBase;

//
// LLDPControllerApp is an SDN controller application that handles link layer discovery.
//
// If this app is used together with a learning app (@see~LearningControllerApp)
// it should be configured with a packetFilterBlacklist = default("etherType=0x88CC")
// so LLDP is not forwarded automatically.
// 
// @author Timo Haeckel, for HAW Hamburg
//
simple LLDPControllerApp extends PacketProcessorBase
{
    parameters:
        @class(SDN4CoRE::LLDPControllerApp);        
        // only processing LLDP packets. 
        packetFilterWhitelist = default("etherType=0x88CC");
        
        string deviceTablePath = default("^.controllerState.deviceTable");
        
        // cycle of lldp messages
        double cycle @unit("s") = default(30s);//default value cisco
        bool lldpOnNewConnection = default(true);
}
