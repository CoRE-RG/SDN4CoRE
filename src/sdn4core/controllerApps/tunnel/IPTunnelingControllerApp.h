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

#ifndef __SDN4CORE_IPTUNNELINGCONTROLLERAPP_H_
#define __SDN4CORE_IPTUNNELINGCONTROLLERAPP_H_

#include <omnetpp.h>

#include "sdn4core/controllerApps/base/PacketProcessorBase.h"

//inet
#include "inet/networklayer/ipv4/IPv4.h"


using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Implements tunneling of the IPv4 protocol through an OpenFlow channel based
 * on the inet::IPv4 implementation.
 * Sadly, extension is not possible because of multiple cModule base inheritence.
 */
class IPTunnelingControllerApp: public PacketProcessorBase {
public:

protected:

    /**
     * Interface function for the main processing engine of packet_in messages.
     *
     * This default implementation does nothing
     *
     * @param packet_in_msg The packet in message
     */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) override;

    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void refreshDisplay() const override;


protected:

    /**
     * Processing of IPv4 datagrams. Called when a datagram reaches the front
     * of the queue.
     */
    virtual void endService(cPacket *packet);

    /**
     * Handle IPv4Datagram messages arriving from lower layer.
     * Decrements TTL, then invokes routePacket().
     */
    virtual void handleIncomingDatagram(IPv4Datagram *datagram);

    /**
     * Perform reassembly of fragmented datagrams, then send them up to the
     * higher layers using sendToHL().
     */
    virtual void reassembleAndDeliver(IPv4Datagram *datagram);

    /**
     * Decapsulate and return encapsulated packet after attaching IPv4ControlInfo.
     */
    virtual cPacket *decapsulate(IPv4Datagram *datagram);

protected:

    IInterfaceTable *ift = nullptr;
    int transportInGateBaseId = -1;

    // working vars
    bool isUp = false;
    long curFragmentId = -1;    // counter, used to assign unique fragmentIds to datagrams
    IPv4FragBuf fragbuf;    // fragmentation reassembly buffer
    simtime_t lastCheckTime;    // when fragbuf was last checked for state fragments
    ProtocolMapping mapping;    // where to send packets after decapsulation

    // config
    int defaultTimeToLive = -1;
    int defaultMCTimeToLive = -1;
    simtime_t fragmentTimeoutTime;
    bool forceBroadcast = false;

    // statistics
    int numMulticast = 0;
    int numLocalDeliver = 0;
    int numDropped = 0;    // forwarding off, no outgoing interface, too large but "don't fragment" is set, TTL exceeded, etc
    int numUnroutable = 0;
    int numForwarded = 0;
};

} /*end namespace SDN4CoRE*/

#endif
