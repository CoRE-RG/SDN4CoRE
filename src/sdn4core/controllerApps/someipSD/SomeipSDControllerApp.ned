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

package sdn4core.controllerApps.someipSD;

import sdn4core.controllerApps.base.PacketProcessorBase;

//
// SomeipSDControllerApp is an SDN controller application that handles 
// the service oriented architectures. The implementation controls the SOME/IP protocol
// which is implemented in the SOA4CoRE framework.
//
// If this app is used together with a learning app (@see~LearningControllerApp)
// it should be configured with a packetFilterBlacklist = default("udpSrc=30490")
// so the SOME/IP SD is not forwarded automatically.
// 
// @note This app is still in an early implementation stage and does not support 
//		 the full SOME/IP feature set!
//       Many features are missing and might not be implemented efficiently. 
//
// @author Jan Schmitt-Solbrig, Timo Haeckel, for HAW Hamburg
//
simple SomeipSDControllerApp extends PacketProcessorBase
{
    parameters:
        @class(SDN4CoRE::SomeipSDControllerApp);
        string hostTablePath = default("^.controllerState.hostTable");
        string deviceTablePath = default("^.controllerState.deviceTable");
        string topologyManagementPath = default("^.controllerState.topology");
        // SOME/IP multicast address
        string someipMcastAddress = default("224.0.2.254");
        bool forwardOfferMulticast = default(true);
        packetFilterWhitelist = default("udpSrc=30490");
        // disable timeout for SOME/IP flows set up by this app
        flowModHardTimeOut = default(0);
        flowModIdleTimeOut = default(0);
        bool reserverRessources = default(false);
}
