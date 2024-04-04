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
// @author Jan Schmitt-Solbrig, Timo Haeckel for HAW Hamburg
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
        // timeout for SOME/IP flows set up by this app, 0 means no timeout
        flowModHardTimeOut = default(0);
        flowModIdleTimeOut = default(0);
        bool reserveResources = default(false);
        bool streamIntervalAsCMI = default(false);  // calculate IdleSlope based on stream interval instead of CMI
        											// the framesize will be "normalized" for the ratio of the interval / CMI of the priority 
        // the class measurement interval for the 802.1Q priorities
        // the key must be the pcp index (usually 0 - 7), see example below.  
        // A CMI <= 0 will not allow stream reservation in this priority.
        // Pcps that are unspecified will also not allow stream reservation.         
        object pcpCMI = default({3: 0s, 4: 0s, 5: 250us, 6: 125us, 7: 0s});
        bool useXMLReservationList = default(false); //set xml config in PacketProcessorBase::confixXML
        bool verifyMaxLatencies = default(false);
        double portTransmitRate @unit(bps) = default(1Gbps);
        double switchProcessingDelay @unit(s) = default(8us); // default of TSN switches from CoRE4INET
        string dumpFlowUpdatesToFile = default(""); // set to a filename to dump flow updates to a file
}
