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
#include "soa4core/messages/someip/SomeIpSDHeader.h"
#include "sdn4core/controllerState/devices/DeviceTable.h"
#include "sdn4core/controllerState/hosts/HostTable.h"
#include "sdn4core/controllerState/topology/TopologyManagement.h"
#include "sdn4core/controllerState/srp/SRPTableManagement.h"
#include <sdn4core/messages/openflow/OFP_TSN_Port_Mod_m.h>
//AUTO-GENERATED MESSAGES
#include "soa4core/messages/someip/SomeIpSDEntry_m.h"
#include "soa4core/messages/someip/SomeIpSDOption_m.h"
//CoRE4INET
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
//SOA4CoRE
#include "soa4core/serviceidentifier/ServiceIdentifier.h"

// STD
#include <map>
#include <list>

using namespace omnetpp;


namespace SDN4CoRE {
/**
 * Extended SomeIpSDOption list implementing comfort functions
 */
class SomeipOptionsList : public std::list<SOA4CoRE::SomeIpSDOption*>
{
public:
//    ~SomeipOptionsList() {
//        for (auto elem: *this) {
//            if (elem) delete elem;
//            elem = nullptr;
//        }
//        this->clear();
//    }

    template<typename T>
    bool hasConfigType () {
        for (auto config : *this) {
            if(dynamic_cast<T>(config)) {
                return true;
            }
        }
        return false;
    }

    template<typename T>
    T getFirstConfigOfType () {
        for (auto config : *this) {
            if(T castConfig = dynamic_cast<T>(config)) {
                return castConfig;
            }
        }
        return nullptr;
    }

    template<typename T>
    std::list<T> getAllConfigsOfType () {
        std::list<T> configs;
        for (auto config : *this) {
            if(T castConfig = dynamic_cast<T>(config)) {
                configs.push_back(castConfig);
            }
        }
        return configs;
    }

    /**
     * Deep copy duplicating all config options contained in the list.
     * @return a copy of this list with pointers to new duplicates of the configs.
     */
    SomeipOptionsList dup() {
        SomeipOptionsList duplicate;
        for (auto config : *this) {
            duplicate.push_back(config->dup());
        }
        return duplicate;
    }
};

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

    /**
     * struct to save a single offer-message with the corresponding options
     */
    struct ServiceInstance {
        SOA4CoRE::ServiceEntry* entry = nullptr;
        LayeredInformation* layeredInformation = nullptr;
        SomeipOptionsList optionList;
        void clear() {
            if (entry) delete entry;
            entry = nullptr;
            if (layeredInformation) delete layeredInformation;
            layeredInformation = nullptr;
            for (auto elem: optionList) {
                if (elem) delete elem;
                elem = nullptr;
            }
            optionList.clear();
        }
    };

    /**
     *  InstanceMap includes all available instances sorted by InstanceIDs as key
     *  used to insert the instances into the ServiceInstanceMap
     */
    typedef std::map<int, ServiceInstance> InstanceMap;
    /**
     *  Map includes all available services sorted by ServiceIDs as key
     */
    typedef std::map<int, InstanceMap> ServiceInstanceMap;

    struct FindRequest {
        SOA4CoRE::SomeIpSDHeader* requestHeader;
        LayeredInformation* layeredInformation;
        SOA4CoRE::ServiceEntry* entry;
        SomeipOptionsList optionList;
        void clear() {
            if (requestHeader) delete requestHeader;
            requestHeader = nullptr;
            if (layeredInformation) delete layeredInformation;
            layeredInformation = nullptr;
            if (entry) delete entry;
            entry= nullptr;
            for (auto elem: optionList) {
                if (elem) delete elem;
                elem = nullptr;
            }
            optionList.clear();
        }
    };

    /**
    * RequestMap:Contains all Find-Messages that are not answered
    */
    typedef std::map<int, std::list<FindRequest>> RequestMap;

    struct Subscription {
        SOA4CoRE::ServiceIdentifier service;
        // from provider / publisher
        LayeredInformation providerInformation;
        SOA4CoRE::IPv4EndpointOption providerEndpoint;
        // to consumer / subscriber
        LayeredInformation consumerInformation;
        SOA4CoRE::IPv4EndpointOption consumerEndpoint;
        std::list<SOA4CoRE::ConfigurationOption*> configOptions;
        // control information
        bool active = false;
        bool waitingForAck = false;

        inline bool operator==(const Subscription& other) {
            return isConsumer(other.consumerInformation, other.consumerEndpoint)
                    && isProvider(other.providerInformation, other.providerEndpoint);
        }
        inline bool operator!=(const Subscription& other) { return !(*this == other); }

        bool isConsumer(LayeredInformation otherInformation, SOA4CoRE::IPv4EndpointOption otherEndpoint) {
            return otherInformation.eth_src == consumerInformation.eth_src
                    && otherInformation.ip_src == consumerInformation.ip_src
                    && otherInformation.transport_src == consumerInformation.transport_src
                    && otherEndpoint.getIpv4Address() == consumerEndpoint.getIpv4Address()
                    && otherEndpoint.getPort() == consumerEndpoint.getPort();
        }

        bool isProvider(LayeredInformation otherInformation, SOA4CoRE::IPv4EndpointOption otherEndpoint) {
            return otherInformation.eth_src == providerInformation.eth_src
                    && otherInformation.ip_src == providerInformation.ip_src
                    && otherInformation.transport_src == providerInformation.transport_src
                    && otherEndpoint.getIpv4Address() == providerEndpoint.getIpv4Address()
                    && otherEndpoint.getPort() == providerEndpoint.getPort();
        }

        bool isMcast() {
            return consumerEndpoint.getType() == SOA4CoRE::SomeIpSDOptionType::IPV4MULTICAST;
        }

        IPv4Address getDstHostIp() {
            if(isMcast()) {
                return consumerInformation.ip_src.toIPv4();
            }
            return consumerEndpoint.getIpv4Address();
        }

        IPv4Address getSrcHostIp() {
            if(isMcast()) {
                return providerInformation.ip_src.toIPv4();
            }
            return providerEndpoint.getIpv4Address();
        }

        void addConfigOption(SOA4CoRE::SomeIpSDOption* option) {
            if (SOA4CoRE::ConfigurationOption* config = dynamic_cast<SOA4CoRE::ConfigurationOption*>(option)) {
                configOptions.push_back(config);
            }
        }

        void addConfigOptions(SomeipOptionsList options) {
            for (auto option : options) {
                if (SOA4CoRE::ConfigurationOption* config = dynamic_cast<SOA4CoRE::ConfigurationOption*>(option)) {
                    configOptions.push_back(config);
                }
            }
        }

        void clear() {
            for (auto elem: configOptions) {
                if (elem) delete elem;
                elem = nullptr;
            }
            configOptions.clear();
        }
    };

    typedef std::list<Subscription> ServiceInstanceSubscriptionList;
    typedef std::map<int, ServiceInstanceSubscriptionList> IntanceSubscriptionMap;
    typedef std::map<int, IntanceSubscriptionMap> SubscriptionMap;

    /**
     *  Cleans the serviceTable for finishing the simulation
     */
    ~SomeipSDControllerApp(){
        for (auto idIter : serviceTable){
            for (auto instanceIter : idIter.second) {
                instanceIter.second.clear();
            }
            idIter.second.clear();
        }
        serviceTable.clear();

        for (auto idIter : requestTable){
            for (auto request : idIter.second) {
                request.clear();
            }
            idIter.second.clear();
        }
        requestTable.clear();

        for (auto idIter : subscriptionTable){
            for (auto instanceIter : idIter.second) {
                for (auto sub : instanceIter.second) {
                    sub.clear();
                }
                instanceIter.second.clear();
            }
            idIter.second.clear();
        }
        subscriptionTable.clear();
    };
protected:
    ServiceInstanceMap serviceTable;
    RequestMap requestTable;
    SubscriptionMap subscriptionTable;
    LayeredInformation myLayeredInformation;
    uint16_t controllerRequestID;
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
    SOA4CoRE::SomeIpSDHeader* buildOffer(SOA4CoRE::SomeIpSDHeader* findSource, SOA4CoRE::SomeIpSDEntry* findEntry, std::list<ServiceInstance>& foundInstances);
    SOA4CoRE::SomeIpSDHeader* buildSubscribeEventGroup(SOA4CoRE::SomeIpSDHeader* source, SOA4CoRE::SomeIpSDEntry* entry);
    SOA4CoRE::SomeIpSDHeader* buildSubscribeEventGroupAck(SOA4CoRE::SomeIpSDHeader* source, SOA4CoRE::SomeIpSDEntry* entry);

    void sendFind(SOA4CoRE::SomeIpSDHeader*, SOA4CoRE::SomeIpSDHeader* findSource);
    void sendOffer(SOA4CoRE::SomeIpSDHeader* offer, SOA4CoRE::SomeIpSDHeader* findSource, LayeredInformation* infoFind, LayeredInformation* infoOffer);

    void installFlowForUnicastSubscription(Subscription& sub);
    void installFlowForMulticastSubscription(Subscription& sub);

    /**
     * Checks if all necessary configurations have been set by the producer of the subscription
     * @param sub The subscription to be checked
     * @return true if ressource reservation is required
     */
    bool requiresRessourceReservation(Subscription& sub);
    void reserveRessourcesForUnicastSubscription(Subscription& sub, TopologyManagement::Route route);
    void reserveRessourcesForMulticastSubscription(Subscription& sub, TopologyManagement::McastRoute mcastRoute);
    OFP_TSN_Port_Mod_CBS* buildPortModCBS(uint32_t portno, uint8_t pcp, unsigned long idleSlope);


    SomeipOptionsList getEntryOptions(SOA4CoRE::SomeIpSDEntry* xEntry, SOA4CoRE::SomeIpSDHeader* header);
    void updateServiceTable(ServiceInstance& newInfo);

     /**
       * looks for the service requested in the controllers list of known offers
       * @param requestedServiceId the service id to look for
       * @param requestedInstanceId the instance id to look for (can be 0xFFFF for any)
       * @return List of requested instance entries
       *     containing zero elements if no service was found
       *     containing one element if a specific instance was requested
       *     containing all known instances if no specific instanceId was requested
       */
     std::list<ServiceInstance> lookUpServiceInMap(uint16_t requestedServiceId, uint16_t requestedInstanceId);

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
    bool forwardOfferMulticast;
    IPv4Address someipMcastAddress;
    bool reserverRessources;
    /**
     * A management module handling all SRP operations.
     */
    SRPTableManagement* srpManager;
};

std::ostream& operator<<(std::ostream& os, const SomeipSDControllerApp::ServiceInstance& instance)
{
    os << "offer{";
    if(instance.layeredInformation) {
        os << " source=" << instance.layeredInformation->ip_src.str();
    }
    os << " endpoints { ";
    for (auto iter = instance.optionList.begin(); iter != instance.optionList.end(); ++iter) {
        if(SOA4CoRE::IPv4EndpointOption* endpoint = dynamic_cast<SOA4CoRE::IPv4EndpointOption*>(*iter)) {
            os << (*endpoint);
        }
    }
    os << " } }";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SomeipSDControllerApp::FindRequest& request)
{
    os << "find{";
    os << " source=" << request.layeredInformation->ip_src.str();
    os << " service=" << request.entry->getServiceID() << " instance=" << request.entry->getInstanceID();
    os << " }";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SomeipSDControllerApp::Subscription& sub)
{
    os << "provider " << sub.providerEndpoint;
    os << ", consumer " << sub.consumerEndpoint;
    os << ", active=" << sub.active;
    os << ", waitingForAck=" << sub.waitingForAck;
    os << ", configurationOptions {";
    for (auto config : sub.configOptions)
    {
        if(SOA4CoRE::RealTimeConfigurationOption* rtconfig = dynamic_cast<SOA4CoRE::RealTimeConfigurationOption*>(config)) {
            os << (*rtconfig);
        }
    }
    os << "}";
    return os;
}

} /*end namespace SDN4CoRE*/

#endif
