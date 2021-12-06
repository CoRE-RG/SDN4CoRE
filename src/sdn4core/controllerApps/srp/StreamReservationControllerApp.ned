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

package sdn4core.controllerApps.srp;

import sdn4core.controllerApps.base.PacketProcessorBase;

//
// StreamReservationControllerApp is an SDN controller application that handles 
// the SRProtocol for TSN and AVB real time traffic. 
// @warning This uses the simplified implementation of the Stream Reservation Protocol 
// from core4inet that does not use the original message format. 
//
// If this app is used together with a learning app (@see~LearningControllerApp)
// it should be configured with a packetfilterBlacklist = default("etherType=0x22EA")
// so SRP is not forwarded automatically.
// 
// @author Timo Haeckel, for HAW Hamburg
//
simple StreamReservationControllerApp extends PacketProcessorBase
{
    parameters:
        @class(SDN4CoRE::StreamReservationControllerApp);
        
        // set priority that is higher than default entries.
        priority = default(1000);
        
        // only processing MSRP packets. 
        packetFilterWhitelist = default("etherType=0x22EA");
}
