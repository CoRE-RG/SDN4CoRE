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
// c Timo Haeckel, Jan Schmitt-Solbrig, for HAW Hamburg
// 

#ifndef __SDN4CORE_SOMEIPSDCONTROLLERAPP_H_
#define __SDN4CORE_SOMEIPSDCONTROLLERAPP_H_

#define BROADCASTADDRESS "255.255.255.255"

#include <omnetpp.h>
#include "sdn4core/utility/layeredInformation/LayeredInformation.h"
#include "sdn4core/controllerApps/base/PacketProcessorBase.h"
#include "sdn4core/controllerState/services/SomeipServiceTable.h"
#include "sdn4core/controllerState/devices/DeviceTable.h"
#include "sdn4core/controllerState/hosts/HostTable.h"
#include "sdn4core/controllerState/topology/TopologyManagement.h"
#include "sdn4core/controllerState/srp/SRPTableManagement.h"
#include <sdn4core/messages/openflow/OFP_TSN_Port_Mod_m.h>
//CoRE4INET
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
//SOA4CoRE
#include "soa4core/messages/someip/SomeIpSDHeader.h"
#include "soa4core/serviceidentifier/ServiceIdentifier.h"
#include "soa4core/messages/someip/SomeIpSDEntry_m.h"
#include "soa4core/messages/someip/SomeIpSDOption_m.h"

// STD
#include <map>
#include <list>

using namespace omnetpp;


namespace SDN4CoRE {

/**
// SomeipSDControllerApp is an SDN controller application that handles
// the service oriented architectures. The implementation controls the SOME/IP protocol
// which is implemented in the SOA4CoRE framework.
//
// @note This app is still in an early implementation stage and does not support
//       the full SOME/IP feature set!
//       Many features are missing and might not be implemented efficiently.
//
// @author Jan Schmitt-Solbrig, Timo Haeckel, for HAW Hamburg
 */
class SomeipSDControllerApp: public PacketProcessorBase
{
public:

    struct SwitchPortIdleSlope {
        SwitchPort switchPort;
        uint8_t pcp;
        unsigned long idleSlope;
    };

    typedef std::list<SwitchPortIdleSlope> ResourceReservationList;
    typedef std::map<int,ResourceReservationList> ResourceReservationTable;

    /**
     *  Cleans the serviceTable for finishing the simulation
     */
    ~SomeipSDControllerApp(){
    };
protected:
    virtual void initialize() override;

    /**
      * Interface function for the main processing engine of packet_in messages.
      *
      * This default implementation does nothing
      *
      * @param packet_in_msg The packet in message
      */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) override;

    void processSomeIpSDHeader(SOA4CoRE::SomeIpSDHeader* someIpSDHeader);

    void processFindEntry(SOA4CoRE::SomeIpSDEntry* findInquiry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);
    void processOfferEntry(SOA4CoRE::SomeIpSDEntry* offerEntry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);
    void processSubscribeEventGroupEntry(SOA4CoRE::SomeIpSDEntry* entry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);
    void processSubscribeEventGroupAckEntry(SOA4CoRE::SomeIpSDEntry* entry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);

    SOA4CoRE::SomeIpSDHeader* buildFind(SOA4CoRE::SomeIpSDHeader* findSource, SOA4CoRE::SomeIpSDEntry* findEntry);
    SOA4CoRE::SomeIpSDHeader* buildOffer(SOA4CoRE::SomeIpSDHeader* findSource, SOA4CoRE::SomeIpSDEntry* findEntry, SomeipServiceTable::ServiceInstanceList& foundInstances);
    SOA4CoRE::SomeIpSDHeader* buildSubscribeEventGroup(SOA4CoRE::SomeIpSDHeader* source, SOA4CoRE::SomeIpSDEntry* entry);
    SOA4CoRE::SomeIpSDHeader* buildSubscribeEventGroupAck(SOA4CoRE::SomeIpSDHeader* source, SOA4CoRE::SomeIpSDEntry* entry);

    void sendFind(SOA4CoRE::SomeIpSDHeader*, SOA4CoRE::SomeIpSDHeader* findSource);
    void sendOffer(SOA4CoRE::SomeIpSDHeader* offer, SOA4CoRE::SomeIpSDHeader* findSource, LayeredInformation* infoFind, LayeredInformation* infoOffer);

    void installFlowForUnicastSubscription(SomeipServiceTable::Subscription& sub);
    void installFlowForMulticastSubscription(SomeipServiceTable::Subscription& sub);

    void takeRequest(SomeipServiceTable::FindRequest& request);

    /**
     * Checks if all necessary configurations have been set by the producer of the subscription
     * @param sub The subscription to be checked
     * @return true if ressource reservation is required
     */
    bool requiresResourceReservation(SomeipServiceTable::Subscription& sub);
    void reserveResourcesForSubscription(SomeipServiceTable::Subscription& sub, TopologyManagement::Route route);
    void reserverResourcesForNextConfig();
    /**
     * Calculate the layer 1 framesize for the SOME/IP protocol stack with the given payload
     * @param ip_proto
     * @param payload
     * @return the framesize including all headers and the payload
     */
    uint16_t calculateL2Framesize(uint8_t ip_proto, uint16_t payload);
    void sendPortModCBS(SwitchPort& switchPort, uint8_t pcp, unsigned long idleSlope);
    OFP_TSN_Port_Mod_CBS* buildPortModCBS(uint32_t portno, uint8_t pcp, unsigned long idleSlope);

    bool loadXMLReservationList();

    SomeipOptionsList getEntryOptions(SOA4CoRE::SomeIpSDEntry* xEntry, SOA4CoRE::SomeIpSDHeader* header);
    void updateServiceTable(SomeipServiceTable::ServiceInstance& newInfo);

private:
     inet::EthernetIIFrame * encapSDHeader(SOA4CoRE::SomeIpSDHeader* header,
             inet::MACAddress eth_src, inet::MACAddress eth_dst,
             inet::L3Address ip_src, inet::L3Address ip_dst,
             int udp_src, int udp_dst);
     inet::EthernetIIFrame * encapSDHeader(SOA4CoRE::SomeIpSDHeader* header,
             LayeredInformation* bedirectionInfo);
     inet::EthernetIIFrame * encapSDHeader(SOA4CoRE::SomeIpSDHeader* header,
             LayeredInformation* src, LayeredInformation* dst);


protected:
     /**
      * Referenz to the SOME/IP service table.
      */
     SomeipServiceTable* serviceTable;
     /**
      * Reference to the topology management.
      */
     TopologyManagement* topology;
     /**
      * Reference to the host table.
      */
     HostTable* hostTable;
     /**
      * A refernce to the device table.
      */
     DeviceTable* deviceTable;
     /**
      * A management module handling all SRP operations.
      */
     SRPTableManagement* srpManager;

     /**
      * Controller connection information (MAC,IP,usw.).
      */
     LayeredInformation myLayeredInformation;
     /**
      * Request ID counter for controller forwarded find messages.
      */
     uint16_t controllerRequestID;
     /**
      * Cached parameter if multicasts should be forwarded after beeing handled in the controller.
      */
     bool forwardOfferMulticast;
     /**
      * Cached multicast address parameter for SOME/IP SD.
      */
     IPv4Address someipMcastAddress;
     /**
      * Cached parameter if resources should be reserved for services with QoS options.
      */
     bool reserveResources;
     /**
      * Cached parameter if the xml configuration (resourceReservationTable) should be used for resource reservation instead of SRTables.
      */
     bool useXMLReservationList;
     /**
      * Resource reservation steps to be executed one after another.
      */
     ResourceReservationTable resourceReservationTable;
     /**
      * The next entry in the reservation table to be executed.
      */
     int nextReservationIndex = 0;
};

std::ostream& operator<<(std::ostream& os, const SomeipSDControllerApp::SwitchPortIdleSlope& config)
{
    os << "SwitchPortIdleSlope {";
    os << " switch_id=" << config.switchPort.switchId;
    os << " switch_port=" << config.switchPort.port;
    os << " pcp=" << config.pcp;
    os << " idle_slope_bps=" << config.idleSlope;
    os << "}";
    return os;
}

} /*end namespace SDN4CoRE*/

#endif
