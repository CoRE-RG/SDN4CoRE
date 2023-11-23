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

#ifndef __SDN4CORE_SOMEIPSERVICETABLE_H_
#define __SDN4CORE_SOMEIPSERVICETABLE_H_

#include <omnetpp.h>
#include <sdn4core/controllerState/base/ControllerStateManagementBase.h>
#include <sdn4core/controllerState/services/SomeipOptionsList.h>
// STD
#include <list>
#include <map>
// INET
#include "inet/linklayer/common/MACAddress.h"
#include "inet/networklayer/common/L3Address.h"
// openflow
//SOA4CoRE
#include "soa4core/messages/someip/SomeIpSDHeader.h"
#include "soa4core/serviceidentifier/ServiceIdentifier.h"
#include "soa4core/messages/someip/SomeIpSDEntry_m.h"
#include "soa4core/messages/someip/SomeIpSDOption_m.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * 
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class SomeipServiceTable: public ControllerStateManagementBase<cModule>
{
public: //type definitions and nested classes
    /**
     * Type of the ServiceID for map lookups
     */
    typedef int ServiceID;
    /**
     * Type of the instanceID for map lookups
     */
    typedef int InstanceID;

    /**
     * Service offering with the corresponding options
     */
    struct ServiceInstance {
        SOA4CoRE::ServiceEntry* entry = nullptr;
        LayeredInformation* layeredInformation = nullptr;
        SomeipOptionsList optionList;
        ServiceInstance(){};
        ServiceInstance(SOA4CoRE::SomeIpSDEntry* offerEntry,
                SOA4CoRE::SomeIpSDHeader* someIpSDHeader){
            entry = dynamic_cast<SOA4CoRE::ServiceEntry*>(offerEntry->dup());
            entry->setIndex1stOptions(0);
            LayeredInformation* info =  dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
            layeredInformation = info->dup();
            optionList = SomeipOptionsList(offerEntry, someIpSDHeader);
        }
        void clear() {
            if (entry) delete entry;
            entry = nullptr;
            if (layeredInformation) delete layeredInformation;
            layeredInformation = nullptr;
            optionList.cleanUp();
        }
    };
    /**
     *  Contains all available services with the same service id mapped to their instance id
     */
    typedef std::map<InstanceID, ServiceInstance> InstanceMap;
    /**
     *  Contains all available services instance maps mapped by a service id
     */
    typedef std::map<ServiceID, InstanceMap> ServiceInstanceMap;

    /**
     * Open find requests for services with correstponding options
     */
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
     * List type for multiple find requests
     */
    typedef std::list<FindRequest> ServiceRequestList;
    /**
    * Contains open find requests mapped to a service id
    */
    typedef std::map<ServiceID, ServiceRequestList> RequestMap;

    /**
     * Subscription handling, status information and connection options
     */
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
    /**
     * List of subscriptions for a service instance
     */
    typedef std::list<Subscription> ServiceInstanceSubscriptionList;
    /**
     * Contains subscrtion lists for one service mapped by its instances
     */
    typedef std::map<InstanceID, ServiceInstanceSubscriptionList> IntanceSubscriptionMap;
    /**
     * Contains subscriptions to service instances mapped by the service id
     */
    typedef std::map<ServiceID, IntanceSubscriptionMap> SubscriptionMap;

public:
    SomeipServiceTable();
    ~SomeipServiceTable();

    /**
     * Get a pointer to the service instance stored in the service table.
     * @param serviceId Requested service id.
     * @param instanceId Requested instance id.
     * @param required If set to true, the function will throw a runtime error when the service is not found.
     * @return A pointer to the service instance. Nullptr if not found.
     */
    ServiceInstance* getServiceInstance(ServiceID serviceId, InstanceID instanceId, bool required=false);

    /**
     * Get all known instances for a service id.
     * @param serviceId Requested service id.
     * @return All known instances, empty list if none are known.
     */
    std::list<SomeipServiceTable::ServiceInstance> getAllServiceInstances(ServiceID requestedServiceId);

    /**
     * Lookup service instances that match the find information. If Instance ID is 0xFFFF all known instances are returned.
     * @param serviceId Requested service id.
     * @param instanceId Requested instance id.
     * @return List of requested instance entries
     *     containing zero elements if no service was found
     *     containing one element if a specific instance was requested
     *     containing all known instances if no specific instanceId was requested
     */
    std::list<SomeipServiceTable::ServiceInstance> SomeipServiceTable::findLookup(uint16_t serviceId, uint16_t instanceId);

    /**
     * Update the table from the SOME/IP offer message.
     * @param offerEntry The offer entry.
     * @param someIpSDHeader The corresponding header containing the options and the control info.
     */
    void updateServiceTable(SomeIpSDEntry* offerEntry, SomeIpSDHeader* someIpSDHeader);

    /**
     * Get all open pending requests for the given service id and instance id.
     * @param serviceId Requested service id.
     * @param instanceId Requested instance id.
     * @param includeWildcards True, if wildcarded instanceIds (0xFFFF) should be included.
     * @param removeFromCache True, entries that are returned will be removed from the cache
     * @return List of open service requests
     *     containing zero elements if no request was found.
     *     containing all open request for this specific service instance if includeWildcards is set to false.
     *     containing all open request for any instance of the service if includeWildcards is set to true.
     */
    ServiceRequestList getPendingRequests(uint16_t serviceId, uint16_t instanceId, bool includeWildcards=true, bool removeFromCache = false);

    /**
     * Update the table from the SOME/IP find message.
     * @param findInquiry The find entry.
     * @param someIpSDHeader The corresponding header containing the options and the control info.
     */
    void updateRequestTable(SomeIpSDEntry* findInquiry, SomeIpSDHeader* someIpSDHeader);

    bool hasSubscriptions(ServiceID serviceId, InstanceID instanceId);

    ServiceInstanceSubscriptionList& getSubscriptions(ServiceID serviceId, InstanceID instanceId, bool required=false);

    Subscription& updateSubscriptionTable(SomeIpSDEntry* entry, SomeIpSDHeader* someIpSDHeader);

    /**
     * For lifecycle: clears all managed tables.
     */
    virtual void clearTable();

protected:

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;

    /**
     * Updates the displaystring for services, subscriptions and open requests.
     */
    virtual void refreshDisplay() const override;

protected:
    /**
     * Collecting known service offers.
     */
    ServiceInstanceMap serviceTable;
    /**
     * Collecting open find requests.
     */
    RequestMap requestTable;
    /**
     * Collecting known subscriptions.
     */
    SubscriptionMap subscriptionTable;

};

} /*end namespace SDN4CoRE*/

std::ostream& operator<<(std::ostream& os, const SomeipOptionsList::ServiceInstance& instance)
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

std::ostream& operator<<(std::ostream& os, const SomeipOptionsList::FindRequest& request)
{
    os << "find{";
    os << " source=" << request.layeredInformation->ip_src.str();
    os << " service=" << request.entry->getServiceID() << " instance=" << request.entry->getInstanceID();
    os << " }";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SomeipOptionsList::Subscription& sub)
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

#endif // __SDN4CORE_SOMEIPSERVICETABLE_H_
