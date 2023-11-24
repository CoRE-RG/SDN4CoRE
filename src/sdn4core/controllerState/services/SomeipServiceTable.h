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
#include <sdn4core/utility/layeredInformation/LayeredInformation.h>
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
     * List type for multiple service instances of the same service id
     */
    typedef std::list<ServiceInstance> ServiceInstanceList;
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
    ServiceInstanceList getAllServiceInstances(ServiceID requestedServiceId);

    /**
     * Lookup service instances that match the find information. If Instance ID is 0xFFFF all known instances are returned.
     * @param serviceId Requested service id.
     * @param instanceId Requested instance id.
     * @return List of requested instance entries
     *     containing zero elements if no service was found
     *     containing one element if a specific instance was requested
     *     containing all known instances if no specific instanceId was requested
     */
    ServiceInstanceList findLookup(uint16_t serviceId, uint16_t instanceId);

    /**
     * Update the table from the SOME/IP offer message.
     * @param offerEntry The offer entry.
     * @param someIpSDHeader The corresponding header containing the options and the control info.
     */
    void updateServiceTable(SOA4CoRE::SomeIpSDEntry* offerEntry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);

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
    void updateRequestTable(SOA4CoRE::SomeIpSDEntry* findInquiry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);

    bool hasSubscriptions(ServiceID serviceId, InstanceID instanceId);

    /**
     * Get all subscriptions for a service instance.
     * @param serviceId Requested service id.
     * @param instanceId Requested instance id.
     * @param required If set to true, the function will throw a runtime error when the service is not found.
     * @return A list of subscriptions. Empty list if none are found.
     */
    ServiceInstanceSubscriptionList getSubscriptions(ServiceID serviceId, InstanceID instanceId, bool required);

    /**
     * Get a reference to the actual subscription list for a service instance.
     * @param serviceId Requested service id.
     * @param instanceId Requested instance id.
     * @return A reference to the subscription list.
     */
    ServiceInstanceSubscriptionList& getSubscriptionsReference(ServiceID serviceId, InstanceID instanceId);

    /**
     * Update the subscription table from the SOME/IP subscribe event group message.
     * @param entry The subscribe event group entry.
     * @param someIpSDHeader The corresponding header containing the options and the control info.
     * @return The updated subscription as a reference to the actual table entry.
     */
    Subscription& updateSubscriptionTable(SOA4CoRE::SomeIpSDEntry* entry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);

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

    /**
     * Get the number of known publisher services.
     */
    int getPublisherCount() const;

    /**
     * Get the number of known subscriber services.
     */
    int getSubscriberCount() const;

    /**
     * Get the number of known open find requests.
     */
    int getOpenRequestCount() const;

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

std::ostream& operator<<(std::ostream& os, const SomeipServiceTable::ServiceInstance& instance);
std::ostream& operator<<(std::ostream& os, const SomeipServiceTable::FindRequest& request);
std::ostream& operator<<(std::ostream& os, const SomeipServiceTable::Subscription& sub);

} /*end namespace SDN4CoRE*/


#endif // __SDN4CORE_SOMEIPSERVICETABLE_H_
