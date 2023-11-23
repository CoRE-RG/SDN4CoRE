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
#include <sdn4core/utility/layeredInformation/LayeredInformation.h>

#include <algorithm>

using namespace std;
using namespace inet;
using namespace openflow;
using namespace CoRE4INET;

namespace SDN4CoRE {

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
    auto instances = serviceTable.find(serviceId);
    if (instances != serviceTable.end())
    {
        auto instance = instances.find(instanceId);
        if (instance != instances.end())
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

list<SomeipServiceTable::ServiceInstance> SomeipServiceTable::getAllServiceInstances(ServiceID serviceId)
{
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

list<SomeipServiceTable::ServiceInstance> SomeipServiceTable::findLookup(uint16_t serviceId, uint16_t instanceId)
{
    if (instanceId == 0xFFFF)
    {
        //all InstanceIDs shall be returned [PRS_SOMEIPSD_00351]
        return getAllServiceInstances(serviceId);
    }
    list<ServiceInstance> returnList;
    auto serviceInstance = getServiceInstance(static_cast<ServiceID>(serviceId),
            static_cast<InstanceId>(instanceId),false);
    if(serviceInstance != nullptr)
    {
        returnList.push_back(*serviceInstance);
    }
    return returnList;
}

void SomeipServiceTable::updateServiceTable(SomeIpSDEntry* offerEntry, SomeIpSDHeader* someIpSDHeader)
{
    ServiceInstance newInstance(offerEntry, someIpSDHeader);
    uint16_t serviceId = newInfo.entry->getServiceID();
    uint16_t instanceId = newInfo.entry->getInstanceID();
    if((ServiceInstance* oldInstance = getServiceInstance(serviceId, instanceId)))
    {
        // cleanup old instance, will be replaced later
        oldInstance->clear();
    }
    else if(serviceTable.find(serviceId) == serviceTable.end())
    {
        // neither service nor instance known
        serviceTable[serviceId] = InstanceMap();
    }
    serviceTable[serviceId][instanceId] = newInfo;
}

SomeipServiceTable::ServiceRequestList SomeipServiceTable::getPendingRequests(uint16_t serviceId,
        uint16_t instanceId, bool includeWildcards, bool removeFromCache)
{
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
                requests.push_back(it->second);
                if (removeFromCache)
                {
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
    return ((subscriptionTable.count(serviceId) > 0)
            && (subscriptionTable[serviceId].count(instanceId) > 0));
}

SomeipServiceTable::ServiceInstanceSubscriptionList SomeipServiceTable::getSubscriptions(
        ServiceID serviceId, InstanceID instanceId, bool required=false)
{
    if(!hasSubscriptionsFor(serviceId, instanceId))
    {
        if(required)
        {
            throw cRuntimeError("No subscription for service instance available but required.");
        }
        return SomeipServiceTable::ServiceInstanceSubscriptionList();
    }
    return subscriptionTable[serviceId][instanceId];
}

SomeipServiceTable::Subscription&  SomeipServiceTable::updateSubscriptionTable(
        SomeIpSDEntry* entry, SomeIpSDHeader* someIpSDHeader)
{
    Subscription& sub;
    LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    ServiceInstance* instance = getServiceInstance(entry->getServiceID(), entry->getInstanceID(), true);
    auto serviceId = entry->getServiceID();
    auto instanceId = entry->getInstanceID();
    // identify subscribed endpoint
    SomeipOptionsList entryOptions = SomeipOptionsList(entry, someIpSDHeader);
    auto endpoints = entryOptions->getAllConfigsOfType<IPv4EndpointOption*>();
    if (endpoints.empty())
    {
        throw cRuntimeError("One endpoint information must be present in subscription.");
    }
    else if (endpoints.size() > 1)
    {
        throw cRuntimeError("Exactly one endpoint information must be present in subscription.");
    }
    IPv4EndpointOption* endpoint = endpoints[0];
    // update local subscription table
    bool subKnown = false;
    if (subscriptionTable.find(serviceId) != subscriptionTable.end())
    {
        if (subscriptionTable[serviceId].find(instanceId) != subscriptionTable[serviceId].end())
        {
            for (auto it = subscriptionTable[serviceId][instanceId].begin();
                    it != subscriptionTable[serviceId][instanceId].end();
                    it++)
            {
                if (it->isConsumer(*(layeredInformation), *(endpoint)))
                {
                    // already known!
                    subKnown = true;
                    sub = it->second;
                    break;
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
    if (!subKnown)
    {
        Subscription subscription;
        subscription.service = ServiceIdentifier(serviceId, instanceId);
        subscription.providerInformation = *(instance->layeredInformation);
        subscription.consumerInformation = *(layeredInformation);
        subscription.consumerEndpoint = *(endpoint);
        subscription.waitingForAck = true;
        // add config options of consumer
        subscription.addConfigOptions(entryOptions);
        subscriptionTable[entry->getServiceID()][entry->getInstanceID()].push_back(subscription);
    }
    delete endpoint;
}



void SomeipServiceTable::clearTable() {
    
}

void SomeipServiceTable::initialize() {
    agingTime = par("agingTime");
    lastPurge = SIMTIME_ZERO;
    WATCH_PTRMAP(hostsByMac);
}

void SomeipServiceTable::handleMessage(cMessage* msg) {
    throw cRuntimeError("This module doesn't process messages");
}

void SomeipServiceTable::refreshDisplay() const {
    char buf[50];
    sprintf(buf, "Hosts: %d", getHostCount());
    getDisplayString().setTagArg("t", 0, buf);
}

} /*end namespace SDN4CoRE*/
