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

#include "sdn4core/controllerState/services/SomeipServiceTable.h"

#include "core4inet/utilities/customWatch.h"

#include <algorithm>

using namespace std;
using namespace inet;
using namespace SOA4CoRE;
// using namespace CoRE4INET;

namespace SDN4CoRE {

ostream& operator<<(ostream& os, const SomeipServiceTable::ServiceInstance& instance)
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

ostream& operator<<(ostream& os, const SomeipServiceTable::FindRequest& request)
{
    os << "find{";
    os << " source=" << request.layeredInformation->ip_src.str();
    os << " service=" << request.entry->getServiceID() << " instance=" << request.entry->getInstanceID();
    os << " }";
    return os;
}

ostream& operator<<(ostream& os, const SomeipServiceTable::Subscription& sub)
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

Define_Module(SomeipServiceTable);


SomeipServiceTable::SomeipServiceTable()
{
}

SomeipServiceTable::~SomeipServiceTable()
{
    clearTable();
}

SomeipServiceTable::ServiceInstance* SomeipServiceTable::getServiceInstance(ServiceID serviceId,
        InstanceID instanceId, bool required)
{
    Enter_Method("getServiceInstance()");
    auto instances = serviceTable.find(serviceId);
    if (instances != serviceTable.end())
    {
        auto instance = instances->second.find(instanceId);
        if (instance != instances->second.end())
        {
            return &(instance->second);
        }
    }
    if (required)
    {
        throw cRuntimeError("Service instance could not be found.");
    }
    return nullptr;
}

SomeipServiceTable::ServiceInstanceList SomeipServiceTable::getAllServiceInstances(ServiceID serviceId)
{
    Enter_Method("getAllServiceInstances()");
    list<ServiceInstance> returnList;
    auto found = serviceTable.find(serviceId);
    if (found != serviceTable.end())
    {
        for (auto iter = found->second.begin(); iter != found->second.end(); iter++)
        {
            returnList.push_back(iter->second);
        }
    }
    return returnList;
}

SomeipServiceTable::ServiceInstanceList SomeipServiceTable::findLookup(uint16_t serviceId, uint16_t instanceId)
{
    Enter_Method("findLookup()");
    if (instanceId == 0xFFFF)
    {
        //all InstanceIDs shall be returned [PRS_SOMEIPSD_00351]
        return getAllServiceInstances(serviceId);
    }
    list<ServiceInstance> returnList;
    auto serviceInstance = getServiceInstance(static_cast<ServiceID>(serviceId),
            static_cast<InstanceID>(instanceId),false);
    if(serviceInstance != nullptr)
    {
        returnList.push_back(*serviceInstance);
    }
    return returnList;
}

void SomeipServiceTable::updateServiceTable(SomeIpSDEntry* offerEntry, SomeIpSDHeader* someIpSDHeader)
{
    Enter_Method("updateServiceTable()");
    ServiceInstance newInstance(offerEntry, someIpSDHeader);
    uint16_t serviceId = offerEntry->getServiceID();
    uint16_t instanceId = offerEntry->getInstanceID();
    ServiceInstance* oldInstance = getServiceInstance(serviceId, instanceId);
    if(oldInstance != nullptr)
    {
        // cleanup old instance, will be replaced later
        oldInstance->clear();
    }
    else if(serviceTable.find(serviceId) == serviceTable.end())
    {
        // neither service nor instance known
        serviceTable[serviceId] = InstanceMap();
    }
    serviceTable[serviceId][instanceId] = newInstance;
}

SomeipServiceTable::ServiceRequestList SomeipServiceTable::getPendingRequests(uint16_t serviceId,
        uint16_t instanceId, bool includeWildcards, bool removeFromCache)
{
    Enter_Method("getPendingRequests()");
    ServiceRequestList requests;
    auto foundX = requestTable.find(static_cast<ServiceID>(serviceId));
    if (foundX != requestTable.end())
    {
        ServiceRequestList& findInstances = foundX->second;
        for (auto it = findInstances.begin(); it != findInstances.end(); it++)
        {
            if ((includeWildcards && (it->entry->getInstanceID() == 0xFFFF))
                    || (it->entry->getInstanceID() == instanceId))
            {
                requests.push_back(*it);
                if (removeFromCache)
                {
                    dropRequest(&(*it));
                    findInstances.erase(it--);
                }
            }
        }
        if (findInstances.empty())
        {
            requestTable.erase(foundX);
        }
    }
    return requests;
}

void SomeipServiceTable::updateRequestTable(SomeIpSDEntry* findInquiry,
        SomeIpSDHeader* someIpSDHeader)
{
    Enter_Method("updateRequestTable()");
    LayeredInformation* findInfo = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    FindRequest saveFind;
    saveFind.requestHeader = someIpSDHeader->dup();
    saveFind.layeredInformation = findInfo->dup();
    saveFind.entry = dynamic_cast<ServiceEntry*>(findInquiry->dup());
    saveFind.entry->setIndex1stOptions(0);
    saveFind.optionList = SomeipOptionsList(findInquiry, someIpSDHeader);
    // insert into map
    uint16_t serviceId = findInquiry->getServiceID();
    uint16_t instanceId  = findInquiry->getInstanceID();
    auto found = requestTable.find(serviceId);
    if (found != requestTable.end()) {
        for (auto findIt = found->second.begin(); findIt !=found->second.end(); findIt++){
            if (findIt->entry->getInstanceID() == instanceId){
                if (findIt->layeredInformation->eth_src == findInfo->eth_src) {
                    findIt->clear();
                    found->second.erase(findIt--);
                }
            }
        }
        requestTable[serviceId].push_back(saveFind);
    } else {
        std::list<FindRequest> newFind = {saveFind};
        requestTable[serviceId] = newFind;
    }
}

bool SomeipServiceTable::hasSubscriptions(ServiceID serviceId, InstanceID instanceId)
{
    Enter_Method("hasSubscriptions()");
    return ((subscriptionTable.count(serviceId) > 0)
            && (subscriptionTable[serviceId].count(instanceId) > 0));
}

SomeipServiceTable::ServiceInstanceSubscriptionList SomeipServiceTable::getSubscriptions(
        ServiceID serviceId, InstanceID instanceId, bool required)
{
//    Enter_Method("getSubscriptions()");
    if(!hasSubscriptions(serviceId, instanceId))
    {
        if(required)
        {
            throw cRuntimeError("No subscription for service instance available but required.");
        }
        return SomeipServiceTable::ServiceInstanceSubscriptionList();
    }
    return subscriptionTable[serviceId][instanceId];
}

SomeipServiceTable::ServiceInstanceSubscriptionList& SomeipServiceTable::getSubscriptionsReference(
        ServiceID serviceId, InstanceID instanceId)
{
    Enter_Method("getSubscriptionsReference()");
    if(!hasSubscriptions(serviceId, instanceId))
    {
        throw cRuntimeError("No subscription for service instance available but required.");
    }
    return subscriptionTable[serviceId][instanceId];
}

SomeipServiceTable::Subscription&  SomeipServiceTable::updateSubscriptionTable(
        SomeIpSDEntry* entry, SomeIpSDHeader* someIpSDHeader)
{
    Enter_Method("updateSubscriptionTable()");
    LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    ServiceInstance* instance = getServiceInstance(entry->getServiceID(), entry->getInstanceID(), true);
    auto serviceId = entry->getServiceID();
    auto instanceId = entry->getInstanceID();
    // identify subscribed endpoint
    SomeipOptionsList entryOptions = SomeipOptionsList(entry, someIpSDHeader);
    auto endpoints = entryOptions.getAllConfigsOfType<IPv4EndpointOption*>();
    if (endpoints.size() != 1)
    {
        throw cRuntimeError("Exactly one endpoint information must be present in subscription.");
    }
    IPv4EndpointOption* endpoint = endpoints.front();
    // update local subscription table
    if (subscriptionTable.find(serviceId) != subscriptionTable.end())
    {
        if (subscriptionTable[serviceId].find(instanceId) != subscriptionTable[serviceId].end())
        {
            for (auto it = subscriptionTable[serviceId][instanceId].begin();
                    it != subscriptionTable[serviceId][instanceId].end(); it++)
            {
                if (it->isConsumer(*(layeredInformation), *(endpoint)))
                {
                    // already known!
                    delete endpoint;
                    return *it;
                }
            }
        }
        else
        {
            subscriptionTable[serviceId][instanceId] = ServiceInstanceSubscriptionList();
        }
    }
    else
    {
        subscriptionTable[serviceId] = IntanceSubscriptionMap();
        subscriptionTable[serviceId][instanceId] = ServiceInstanceSubscriptionList();
    }
    Subscription subscription;
    subscription.service = ServiceIdentifier(serviceId, instanceId);
    subscription.providerInformation = *(instance->layeredInformation);
    subscription.consumerInformation = *(layeredInformation);
    subscription.consumerEndpoint = *(endpoint);
    subscription.waitingForAck = true;
    // add config options of consumer
    subscription.addConfigOptions(entryOptions);
    subscriptionTable[serviceId][instanceId].push_back(subscription);
    delete endpoint;
    return subscriptionTable[serviceId][instanceId].back();
}

void SomeipServiceTable::clearTable() {
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
}

void SomeipServiceTable::initialize() {
    WATCH_MAPMAP(serviceTable);
    WATCH_LISTMAP(requestTable);
    WATCH_LISTMAPMAP(subscriptionTable);
}

void SomeipServiceTable::handleMessage(cMessage* msg) {
    throw cRuntimeError("This module doesn't process messages");
}

void SomeipServiceTable::refreshDisplay() const {
    char buf[60];
    sprintf(buf, "Publishers: %d\nOpen Requests: %d\nSubscribers: %d", 
            getPublisherCount(), getOpenRequestCount(), getSubscriberCount());
    getDisplayString().setTagArg("t", 0, buf);
}

int SomeipServiceTable::getPublisherCount() const {
    int count = 0;
    for (auto service : serviceTable) {
        count += service.second.size();
    }
    return count;
}

int SomeipServiceTable::getSubscriberCount() const {
    int count = 0;
    for (auto service : subscriptionTable) {
        for (auto instance : service.second) {
            count += instance.second.size();
        }
    }
    return count;
}

int SomeipServiceTable::getOpenRequestCount() const {
    int count = 0;
    for (auto request : requestTable) {
        count += request.second.size();
    }
    return count;
}

void SomeipServiceTable::dropRequest(FindRequest* request) {
    if (request->requestHeader) drop(request->requestHeader);
    if (request->entry) drop(request->entry);
    for (auto elem: request->optionList) {
        if (elem) drop(elem);
    }
}

string SomeipServiceTable::dumpAllServicesToJson() {
    stringstream dump;
    dump << "\"services\": [ ";
    bool first = true;
    for (auto& service : serviceTable) {
        for (auto& instance : service.second) {
            if (!first) {
                dump << ", ";
            }
            dump << "{ \"serviceId\": " << service.first;
            dump << ", \"instanceId\": " << instance.first;
            first = false;
            bool firstSubscription = true;
            if (hasSubscriptions(service.first, instance.first))
            {
                for (auto sub: subscriptionTable[service.first][instance.first]) {
                    if(firstSubscription)
                    {
                        dump << ", \"srcHost\": \"" << sub.getSrcHostIp().str() << "\"";
                        dump << ", \"isMcast\": " << sub.isMcast();
                        dump << ", \"dstHosts\": [";
                        firstSubscription = false;
                    }
                    else
                    {
                        dump << ",";
                    }
                    dump << " \"" << sub.getDstHostIp().str() << "\"";
                }
                if (!firstSubscription) {
                    dump << " ]";
                }
            }
            dump << " }";
        }
    }
    dump << " ]";
    return dump.str();
}

} /*end namespace SDN4CoRE*/
