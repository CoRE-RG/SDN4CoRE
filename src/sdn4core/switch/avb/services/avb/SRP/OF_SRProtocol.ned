//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// c Timo Haeckel, for HAW Hamburg
// 


package sdn4core.switch.avb.services.avb.SRP;

import core4inet.services.avb.SRP.SRProtocol;

//
// This module handles the Stream Reservation Protocol
//
// SRP messages are sent and received through SRPEtherLLC and SRPRelay
// Updated for usage in Openflow Switches.
//
// @warning This is a simplified implementation of the Stream Reservation Protocol that does not use the original
// message format
//
// @see SRPEtherLLC, SRPRelay
//
// @author Timo Haeckel
//
simple OF_SRProtocol extends SRProtocol
{
    parameters:
        @class(SDN4CoRE::OF_SRProtocol);
        
        //Path to the port array in the switch, used for talker and listener assignment
        string portModule = default("etherMAC");
        string macModulePath = default(".phy.mac");//relative to portModule.
        string shaperModulePath = default(".phy.shaper");//relative to portModule.
        
}
