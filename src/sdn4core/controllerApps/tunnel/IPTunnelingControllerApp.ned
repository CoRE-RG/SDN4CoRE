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

package sdn4core.controllerApps.tunnel;

import sdn4core.controllerApps.base.PacketProcessorBase;

//
// Implements tunneling of the IPv4 protocol through OpenFlow, which enables 
// IP communication with network nodes via there neares OpenFlow switch. 
// The protocol header is represented by the ~IPv4Datagram message class.
// TODO: for now this also attaches L2 Ethernet information. This could maybe 
// 		 be separated into two modules for correct layer separation.  
//
// From the INET Framework:
// <b>Interfacing with higher layer protocols</b>
//
// To send a packet over IPv4 from a higher layer protocol, the module should
// fill in an ~IPv4ControlInfo object, attach it to the packet with cMessage's
// setControlInfo() method, the send it to the ~IPv4 module.
//
// When ~IPv4 sends up a packet to a higher layer protocol, it will also attach
// an ~IPv4ControlInfo to the packet, with the source and destination IPv4 address,
// etc. of the IPv4 datagram in which the packet arrived.
//
// ~IPv4 can serve several higher-layer protocols. The higher layer protocols should
// send one or more RegisterProtocol message (a simple cMessage with
// ~IPRegisterProtocolCommand controlinfo and kind=IP_C_REGISTER_PROTOCOL)
// to IPv4 module, for fill up the protocol-to-gateindex map.
// When delivering packets to them, the output gate is determined from the Protocol
// field in the IPv4 header.
//
// <b>Routing and interfacing with lower layers</b>
//
// TODO: Fix this description and describe how tunneling is handled.
//
// The routing table is stored in the module ~IPv4RoutingTable. When a datagram
// needs to be routed, ~IPv4 queries ~IPv4RoutingTable for the output interface
// (or "port") and next hop address of the packet. This is done by directly
// calling C++ methods (such as findBestMatchingRoute(destAddress)) of ~IPv4RoutingTable.
// No message exchange with ~IPv4RoutingTable takes place.
//
// A routed datagram will be sent to the queueOut gate, with an
// ~IPv4ControlInfo  object attached. queueOut is expected to be
// connected to ~INic modules.
//
// @note: Flows that should be tunneled by this application 
// 		  should be blacklisted in all other controller apps.
//		  @see~PacketProcessorBase, e.g., packetfilterBlacklist = "ipDst=, " 
// 
simple IPTunnelingControllerApp extends PacketProcessorBase
{
    parameters:
        @class(SDN4CoRE::IPTunnelingControllerApp);
        @display("i=block/routing");
        string interfaceTableModule;   // The path to the InterfaceTable module
        double procDelay @unit("s") = default(0s);
        int timeToLive = default(32);
        int multicastTimeToLive = default(32);
        double fragmentTimeout @unit("s") = default(60s);
        bool forceBroadcast = default(true); // send broadcasts to all edge ports. 
        string tunnelIPAddresses = default(""); // The dest IP addresses to be accepted as IP tunnels
        bool receiveMulticast = default(false);
        bool receiveBroadcast = default(false);
        bool sendBroadcast = default(false);
        bool sendMulticast = default(false); // TODO how to determine where to send mcast addresses...
        int mtu @unit("B") = default(1500Byte); // Ethernet default MTU, 0 is infinite
        @signal[packetSentToUpper](type=cPacket);
        @signal[packetReceivedFromUpper](type=cPacket);
        @signal[packetFromUpperDropped](type=cPacket);
        @signal[packetSentToLower](type=cPacket);
        @signal[packetReceivedFromLower](type=cPacket);
        @signal[packetFromLowerDropped](type=cPacket);
        @signal[NF_IPv4_NEW_MULTICAST](type=inet::IPv4Datagram);
        @signal[NF_IPv4_DATA_ON_NONRPF](type=inet::IPv4Datagram);
        @signal[NF_IPv4_DATA_ON_RPF](type=inet::IPv4Datagram);
        @signal[NF_IPv4_MDATA_REGISTER](type=inet::IPv4Datagram);
    gates:
        input transportIn[] @labels(IPv4ControlInfo/down,TCPSegment,UDPPacket);
        output transportOut[] @labels(IPv4ControlInfo/up,TCPSegment,UDPPacket);
}
