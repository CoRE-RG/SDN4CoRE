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
#include "sdn4core/controllerState/devices/DeviceTable.h"
#include "sdn4core/controllerState/hosts/HostTable.h"
#include "sdn4core/controllerState/topology/TopologyManagement.h"

//STD
#include <vector>
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

    virtual void initialize() override;
    virtual void handleParameterChange(const char* parname) override;
    virtual void refreshDisplay() const override;
    void receiveSignal(cComponent *src, simsignal_t id, cObject *obj,
            cObject *details) override;
    virtual void handleMessage(cMessage *msg) override;

    /**
     * Interface function for the main processing engine of packet_in messages.
     *
     * This default implementation does nothing
     *
     * @param packet_in_msg The packet in message
     */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) override;


protected:

    /**
     * Check if a given address is in localIps.
     * @param addr The address to compare
     * @return True if it is on of localIps, else false
     */
    virtual bool isLocalIp(const IPv4Address& addr);

    virtual IPv4Address findBestFittingSrcIp(const IPv4Address& dest);

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

    void handleIncomingARPPacket(openflow::OFP_Packet_In* packet_in_msg);

    /**
     * Handle messages (typically packets to be send in IPv4) from transport or ICMP.
     * Invokes encapsulate(), then routePacket().
     */
    virtual void handlePacketFromHL(cPacket *packet);

    /**
     * Routes and sends datagram received from higher layers.
     * Invokes datagramLocalOutHook(), then routePacket().
     */
    virtual void datagramLocalOut(IPv4Datagram *datagram);

    /**
     * Performs unicast routing. Based on the routing decision, it sends the
     * datagram through the outgoing interface.
     */
    virtual void routeUnicastPacket(IPv4Datagram *datagram);

    /**
     * Performs multicast routing. Based on the routing decision, it sends the
     * datagram through the outgoing interface(s).
     */
    virtual void routeMulticastPacket(IPv4Datagram *datagram);

    /**
     * Broadcasts the datagram on the specified interface.
     * When destIE is nullptr, the datagram is broadcasted on each interface.
     */
    virtual void routeLocalBroadcastPacket(IPv4Datagram *datagram);

    /**
     * Perform reassembly of fragmented datagrams, then send them up to the
     * higher layers using sendToHL().
     */
    virtual void reassembleAndDeliver(IPv4Datagram *datagram);

    /**
     * Decapsulate and return encapsulated packet after attaching IPv4ControlInfo.
     */
    virtual cPacket *decapsulate(IPv4Datagram *datagram);

    /**
     * Fragment packet if needed, then send it to the selected interface using
     * sendDatagramToOutput().
     */
    virtual void fragmentAndSend(IPv4Datagram *datagram, HostTable::HostEntry* host);

    /**
     * Send datagram on the given interface.
     */
    virtual void sendDatagramToHost(IPv4Datagram *datagram, HostTable::HostEntry* host);

    /**
     * Encapsulate packet coming from higher layers into IPv4Datagram, using
     * the given control info. Override if you subclassed controlInfo and/or
     * want to add options etc to the datagram.
     */
    virtual IPv4Datagram *encapsulate(cPacket *transportPacket, IPv4ControlInfo *controlInfo);

    /**
     * Creates a blank IPv4 datagram. Override when subclassing IPv4Datagram is needed
     */
    virtual IPv4Datagram *createIPv4Datagram(const char *name);

private:
    void dropPacketFromUpper(cMessage* packet, std::string reason = "");
    void dropPacketFromLower(cMessage* packet, std::string reason = "");
    inet::EthernetIIFrame* etherEncap(cPacket* packet, HostTable::HostEntry* host,
            int etherType = ETHERTYPE_IPv4);

protected:
    /**
     * A management module handling all MAC operations.
     */
    HostTable* hostTable;
    /**
     * A management module handling all MAC operations.
     */
    DeviceTable* deviceTable;
    /**
     * A management module handling all MAC operations.
     */
    TopologyManagement* topology;

    // working vars
    bool isUp = false; // TODO set is up if received controller booted signal!
    long curFragmentId = -1;    // counter, used to assign unique fragmentIds to datagrams
    IPv4FragBuf fragbuf;    // fragmentation reassembly buffer
    simtime_t lastCheckTime;    // when fragbuf was last checked for state fragments
    ProtocolMapping mapping;    // where to send packets after decapsulation

    std::vector<std::string> localIps;
    inet::MACAddress controllerSrcMac;

    // config
    int defaultTimeToLive = -1;
    int defaultMCTimeToLive = -1;
    simtime_t fragmentTimeoutTime;
    bool forceBroadcast = false;
    bool receiveMulticast = false;
    bool receiveBroadcast = false;
    bool sendBroadcast = false;
    bool sendMulticast = false;
    int mtu = 0; // mtu == 0 means infinite default Ethernet 1500

    // statistics
    int numMulticast = 0;
    int numLocalDeliver = 0;
    int numDropped = 0;    // forwarding off, no outgoing interface, too large but "don't fragment" is set, TTL exceeded, etc
    int numUnroutable = 0;
    int numForwarded = 0;
};

} /*end namespace SDN4CoRE*/

#endif
