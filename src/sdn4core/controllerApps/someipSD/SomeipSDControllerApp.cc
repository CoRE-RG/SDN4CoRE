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

#include "SomeipSDControllerApp.h"

//STD
#include <sstream>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/transportlayer/udp/UDPPacket.h"
#include <inet/networklayer/contract/ipv4/IPv4Address.h>
#include <inet/networklayer/common/IPProtocolId_m.h>

//openflow
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"
//CoRE4INET
#include "core4inet/utilities/customWatch.h"

using namespace inet;
using namespace std;
using namespace openflow;
using namespace CoRE4INET;
using namespace SOA4CoRE;

namespace SDN4CoRE {

#define MAJOR_VERSION 0xFF       // see [PRS_SOMEIPSD_00351],[PRS_SOMEIPSD_00356],[PRS_SOMEIPSD_00386],[PRS_SOMEIPSD_00391]
#define MINOR_VERSION 0xFFFFFFFF // see [PRS_SOMEIPSD_00351],[PRS_SOMEIPSD_00356],[PRS_SOMEIPSD_00386],[PRS_SOMEIPSD_00391]
#define TTL 0xFFFFFF             // see [PRS_SOMEIPSD_00351],[PRS_SOMEIPSD_00356],[PRS_SOMEIPSD_00386],[PRS_SOMEIPSD_00391]
#define SOMEIPSD_PORT 30490

Define_Module(SomeipSDControllerApp);

void SomeipSDControllerApp::initialize() {
    PacketProcessorBase::initialize();
    hostTable = check_and_cast<HostTable*>(
            this->getModuleByPath(par("hostTablePath")));
    deviceTable = check_and_cast<DeviceTable*>(
            this->getModuleByPath(par("deviceTablePath")));
    topology = check_and_cast<TopologyManagement*>(
            this->getModuleByPath(par("topologyManagementPath")));


    // 1. Create ServiceEntry - a static entry to answer the first incoming find-message
//    ServiceEntry* entry = new ServiceEntry("ServiceEntry");
//    entry->setType(SOA4CoRE::SomeIpSDEntryType::OFFER);
//    entry->setIndex1stOptions(0);
//    entry->setIndex2ndOptions(0);
//    entry->setNum1stOptions(0);
//    entry->setNum2ndOptions(0);
//    entry->setServiceID(1);
//    entry->setInstanceID(1);
//    entry->setMajorVersion(MAJOR_VERSION);
//    entry->setTTL(TTL);
//    entry->setMinorVersion(MINOR_VERSION);
    //Option UDP
//    IPv4EndpointOption *ipv4EndpointOption = new IPv4EndpointOption("IPv4EndpointOption of Publisher");
//    ipv4EndpointOption->setIpv4Address(IPv4Address("192.168.178.1"));
//    ipv4EndpointOption->setL4Protocol(IPProtocolId::IP_PROT_UDP);
//    ipv4EndpointOption->setPort(3171);
    //Option TCP
//    IPv4EndpointOption *ipv4EndpointOption2 = new IPv4EndpointOption("IPv4EndpointOption of Publisher");
//    ipv4EndpointOption2->setIpv4Address(IPv4Address("192.168.178.1"));
//    ipv4EndpointOption2->setL4Protocol(IPProtocolId::IP_PROT_TCP);
//    ipv4EndpointOption2->setPort(3171);
//    ServiceInstance instance;
//    instance.entry = entry;
//    instance.optionList.push_back(ipv4EndpointOption);
//    instance.optionList.push_back(ipv4EndpointOption2);
//    // 3. insert into map
//    InstanceMap instances; // calls map constructor
//    instances[entry->getInstanceID()] = instance;
//    serviceTable[entry->getServiceID()] = instances;

    myLayeredInformation.eth_src.setAddress("0A:AA:00:00:00:0A");
    myLayeredInformation.ip_src = L3Address("10.0.0.2");
    myLayeredInformation.transport_src = SOMEIPSD_PORT;
    myLayeredInformation.in_port = -1;
    myLayeredInformation.sw_info = nullptr;

    //[PRS_SOMEIPSD_00158] dThe Session-ID (SOME/IP header) shall start with 1 and
    //be 1 even after wrapping.c(RS_SOMEIPSD_00001)
    // important for the finds the controller sends
    controllerRequestID = 0x0001;

    WATCH_MAPMAP(serviceTable);
    WATCH_LISTMAP(requestTable);
    WATCH_LISTMAPMAP(subscriptionTable);
}

void SomeipSDControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    Switch_Info* swInfo = controller->findSwitchInfoFor(packet_in_msg);
    hostTable->update(packet_in_msg, swInfo);

    // layer 2
    if (EthernetIIFrame* eth = dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        //layer 3
        if (INetworkDatagram* ip = dynamic_cast<INetworkDatagram *>(eth->getEncapsulatedPacket())) {
            // layer 4
            if (UDPPacket* transport = dynamic_cast<UDPPacket*>
                                        (eth->getEncapsulatedPacket()->getEncapsulatedPacket())) {
                if (SomeIpSDHeader* someIpSDHeader = dynamic_cast<SomeIpSDHeader*>
                                                        (transport->getEncapsulatedPacket()))  {
                    //set layeredInformation and attach control info
                    LayeredInformation* layeredInformation = new LayeredInformation();
                    layeredInformation->eth_src = eth->getSrc();
                    layeredInformation->eth_dst = eth->getDest();
                    layeredInformation->ip_src = ip->getSourceAddress();
                    layeredInformation->ip_dst = ip->getDestinationAddress();
                    layeredInformation->transport_src = transport->getSourcePort();
                    layeredInformation->transport_dst = transport->getDestinationPort();
                    layeredInformation->in_port = eth->getArrivalGate()->getIndex();
                    layeredInformation->sw_info = swInfo;
                    someIpSDHeader->setControlInfo(layeredInformation);
                    processSomeIpSDHeader(someIpSDHeader);
                }
            }
        }
    }
}

void SomeipSDControllerApp::processSomeIpSDHeader(SomeIpSDHeader* someIpSDHeader) {
    std::list<SomeIpSDEntry*> entries = someIpSDHeader->getEncapEntries();
    for (auto it = entries.begin(); it != entries.end(); ++it) {
        switch ((*it)->getType()) {
            case SOA4CoRE::SomeIpSDEntryType::FIND:
                EV << "FIND ARRIVED" << endl;
                processFindEntry(*it, someIpSDHeader);
                break;
            case SOA4CoRE::SomeIpSDEntryType::OFFER:
                EV << "OFFER ARRIVED" << endl;
                processOfferEntry(*it, someIpSDHeader);
                break;
            case SOA4CoRE::SomeIpSDEntryType::SUBSCRIBEVENTGROUP:
                EV << "SUBSCRIBEVENTGROUP ARRIVED" << endl;
                processSubscribeEventGroupEntry(*it, someIpSDHeader);
                break;
            case SOA4CoRE::SomeIpSDEntryType::SUBSCRIBEVENTGROUPACK:
                EV << "SUBSCRIBEVENTGROUPACK ARRIVED" << endl;
                processSubscribeEventGroupAckEntry(*it, someIpSDHeader);
                break;
            default:
                EV << "Unknown type" << std::endl;
        }
    }
}

void SomeipSDControllerApp::processFindEntry(SomeIpSDEntry* findInquiry, SomeIpSDHeader* someIpSDHeader) {

    std::list<ServiceInstance> entries = lookUpServiceInMap(findInquiry->getServiceID(), findInquiry->getInstanceID());
    LayeredInformation* findInfo = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    if(entries.empty())
    {
        SomeIpSDHeader* myFind = buildFind(someIpSDHeader, findInquiry);
        sendFind(myFind, someIpSDHeader);

        FindRequest saveFind;
        saveFind.requestHeader = someIpSDHeader->dup();
        saveFind.requestHeader->setControlInfo(findInfo->dup()); // todo remove!
        saveFind.layeredInformation = findInfo->dup();
        saveFind.entry = dynamic_cast<ServiceEntry*>(findInquiry->dup());
        saveFind.entry->setIndex1stOptions(0);
        std::list<SomeIpSDOption*> findOptions = getEntryOptions(findInquiry, someIpSDHeader);
        for (auto optIt = findOptions.begin(); optIt != findOptions.end(); optIt++) {
            saveFind.optionList.push_back((*optIt));
        }
        // insert into map
        uint16_t requestedServiceId = findInquiry->getServiceID();
        auto found = requestTable.find(requestedServiceId);
        if (found != requestTable.end()) {
            requestTable[requestedServiceId].push_back(saveFind);
        } else {
            std::list<FindRequest> newFind = {saveFind};
            requestTable[requestedServiceId] = newFind;
        }
    } else {
        SomeIpSDHeader* foundOffer = buildOffer(someIpSDHeader, findInquiry, entries);
        sendOffer(foundOffer, someIpSDHeader, findInfo, entries.front().layeredInformation);
        // TODO maybe use controller layered info if multiple entries
    }
}

void SomeipSDControllerApp::processOfferEntry(SomeIpSDEntry* offerEntry,SomeIpSDHeader* someIpSDHeader) {
    // update ServiceTable with offer
    ServiceInstance instance;
    instance.entry = dynamic_cast<ServiceEntry*>(offerEntry->dup());
    instance.entry->setIndex1stOptions(0);
    instance.layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo())->dup();
    instance.optionList = getEntryOptions(offerEntry, someIpSDHeader);
    updateServiceTable(instance);

    // look for requested offers in requestTable
    auto foundX = requestTable.find(offerEntry->getServiceID());
    if(foundX != requestTable.end()) {
        std::list<ServiceInstance> entries;
        entries.push_back(instance);
        std::list<FindRequest> findInstances = foundX->second;
        for (auto it = findInstances.begin(); it != findInstances.end(); it++) {
            LayeredInformation* findInfo = dynamic_cast<LayeredInformation*>(it->requestHeader->getControlInfo());
            if (it->entry->getServiceID() == 0xFFFF) {
                SomeIpSDHeader* foundOffer = buildOffer(it->requestHeader, it->entry, entries);
                sendOffer(foundOffer, it->requestHeader, findInfo, instance.layeredInformation);
            } else if (it->entry->getServiceID() == it->entry->getServiceID()) {
                SomeIpSDHeader* foundOffer = buildOffer(it->requestHeader, it->entry, entries);
                sendOffer(foundOffer, it->requestHeader, findInfo, instance.layeredInformation);
            }
        }
    }
}

void SomeipSDControllerApp::processSubscribeEventGroupEntry(SomeIpSDEntry* entry,SomeIpSDHeader* someIpSDHeader) {
    LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    // find service to subscribe to is in our service table
    std::list<ServiceInstance> instances = lookUpServiceInMap(entry->getServiceID(), entry->getInstanceID());
    // TODO send NACK or throw error
    if(instances.size() <= 0) {
        throw cRuntimeError("The requested service instance to subscribe to could not be found!");
    } else if(instances.size() > 1) {
        throw cRuntimeError("Multiple instances known for subscription, but it should be unambiguous");
    }
    ServiceInstance& instance = instances.front(); // for readability and comfort
    // get dest ip of the service and compare to the dest id in layered information
    L3Address& destination = instance.layeredInformation->ip_src;
    if (destination != layeredInformation->ip_dst) {
        throw cRuntimeError("The subscription was sent to a different destination than known to the controller for the service instance!");
    }

    auto entryOptions = getEntryOptions(entry, someIpSDHeader);
    if(entryOptions.size() != 1) {
        throw cRuntimeError("Exactly one endpoint information must be present in subscribtion.");
    }
    IPv4EndpointOption* endpoint = dynamic_cast<IPv4EndpointOption*>(entryOptions.front());
    // update local subscription table
    bool subKnown = false;
    if(subscriptionTable.find(entry->getServiceID()) != subscriptionTable.end()) {
        if(subscriptionTable[entry->getServiceID()].find(entry->getInstanceID()) != subscriptionTable[entry->getServiceID()].end()) {
            // we know a subscription for this service instance
            for (auto it = subscriptionTable[entry->getServiceID()][entry->getInstanceID()].begin();
                    it != subscriptionTable[entry->getServiceID()][entry->getInstanceID()].end();
                    it++) {
                if(it->isConsumer(*(layeredInformation), *(endpoint))) {
                    // already known!
                    it->waitingForAck = true;
                    subKnown = true;
                    break;
                }
            }
        } else {
            subscriptionTable[entry->getServiceID()][entry->getInstanceID()] = ServiceInstanceSubscriptionList();
        }
    } else {
        subscriptionTable[entry->getServiceID()] = IntanceSubscriptionMap();
        subscriptionTable[entry->getServiceID()][entry->getInstanceID()] = ServiceInstanceSubscriptionList();
    }
    if(!subKnown) {
        Subscription subscription;
        subscription.service = ServiceIdentifier(entry->getServiceID(),entry->getInstanceID());
        subscription.providerInformation = *(instance.layeredInformation);
        subscription.consumerInformation = *(layeredInformation);
        subscription.consumerEndpoint = *(endpoint);
        subscription.waitingForAck = true;
        subscriptionTable[entry->getServiceID()][entry->getInstanceID()].push_back(subscription);
    }
    delete endpoint;

    // build subscribe eventgroup
    SomeIpSDHeader* header = buildSubscribeEventGroup(someIpSDHeader, entry);
    // build packet out
    EthernetIIFrame* eth2Frame = encapSDHeader(header, layeredInformation, instance.layeredInformation);
    uint32_t outports [] = {(uint32_t)instance.layeredInformation->in_port};
    OFP_Packet_Out *packetOut = OFMessageFactory::instance()->createPacketOut(
            outports, 1, OFPP_CONTROLLER, OFP_NO_BUFFER, eth2Frame);
    packetOut->setKind(TCP_C_SEND);
    controller->sendPacketOut(packetOut, instance.layeredInformation->sw_info->getSocket());
    delete eth2Frame;
}

void SomeipSDControllerApp::processSubscribeEventGroupAckEntry(SomeIpSDEntry* entry, SomeIpSDHeader* someIpSDHeader) {
    LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    uint16_t serviceId = entry->getServiceID();
    uint16_t instanceId = entry->getInstanceID();
    // find subscription in subscription table
    if(subscriptionTable.find(serviceId) == subscriptionTable.end()
            || subscriptionTable[serviceId].find(instanceId) == subscriptionTable[serviceId].end()) {
        throw cRuntimeError("No subscription for service instance to be acknowledged.");
    }
    ServiceInstanceSubscriptionList& subscriptions = subscriptionTable[serviceId][instanceId];
    bool requested = false;
    for (auto iter = subscriptions.begin(); iter != subscriptions.end(); iter++) {
        if(iter->waitingForAck && iter->consumerInformation.ip_src == layeredInformation->ip_dst) {
            // subscription requested and response is for this specific consumer
            requested = true;
            iter->waitingForAck = false;
            if(!iter->active) {
                // set provider information from subscribe ack in subscription
                auto options = getEntryOptions(entry, someIpSDHeader);
                if (options.size() != 1) {
                    throw cRuntimeError("Subscription acknowledgement must have exactly one endpoint option");
                }
                if(IPv4EndpointOption* endpoint = dynamic_cast<IPv4EndpointOption*>(options.front())) {
                    iter->providerEndpoint = *endpoint;
                    iter->providerInformation = *layeredInformation;
                    delete endpoint;
                } else {
                    throw cRuntimeError("Provider option is no IPv4 endpoint");
                }
                installFlowForSubscription(*iter);
                // forward subscription ack to subscriber
                SomeIpSDHeader* header = buildSubscribeEventGroupAck(someIpSDHeader, entry);
                EthernetIIFrame* eth2Frame = encapSDHeader(header, layeredInformation, &iter->consumerInformation);
                uint32_t outports [] = {(uint32_t)iter->consumerInformation.in_port};
                OFP_Packet_Out *packetOut = OFMessageFactory::instance()->createPacketOut(
                        outports, 1, OFPP_CONTROLLER, OFP_NO_BUFFER, eth2Frame);
                packetOut->setKind(TCP_C_SEND);
                controller->sendPacketOut(packetOut, iter->consumerInformation.sw_info->getSocket());
                delete eth2Frame;
                iter->active = true;
            }
            // consumer handled the sub ack!
            break;
        }
    }
    if(!requested) {
        throw cRuntimeError("No subscription requested for service instance.");
    }
}

SomeIpSDHeader* SomeipSDControllerApp::buildFind(SomeIpSDHeader* findSource, SomeIpSDEntry* findInquiry){
    // findSource --> information about requester in the layered information
    SomeIpSDHeader* header = new SomeIpSDHeader("SOME/IP SD - FIND");
    header->setRequestID(controllerRequestID++);
    SomeIpSDEntry* newFind = findInquiry->dup();
    int optionQuantity = findInquiry->getNum1stOptions();
    newFind->setIndex1stOptions(0);
    newFind->setNum1stOptions(optionQuantity);
    //[PRS_SOMEIPSD_00157] The Session-ID (SOME/IP header) shall be incremented for every SOME/IP-SD message sent.(RS_SOMEIPSD_00001)
    if (controllerRequestID == 0) {
    //[PRS_SOMEIPSD_00159] The Session-ID (SOME/IP header) shall not be set to 0. (RS_SOMEIPSD_00001
        controllerRequestID = 1;
    }
    header->encapEntry(newFind);

    std::list<SomeIpSDOption*> oldOptionList = getEntryOptions(findInquiry, findSource);
    for (auto it = oldOptionList.begin(); it != oldOptionList.end(); it++) {
        header->encapOption(*it);
    }
    return header;
}

SomeIpSDHeader* SomeipSDControllerApp::buildOffer(SomeIpSDHeader* findSource, SomeIpSDEntry* findEntry, list<ServiceInstance>& foundInstances){
    // findSource --> information about requester in the layered information
    // findEntry --> information what is requested
    // list foundEntries --> struct with found entries and list of options

    SomeIpSDHeader* header = new SomeIpSDHeader("SOME/IP SD - OFFER");
    header->setRequestID(findSource->getRequestID());

    // create offer - encap each found entry with corresponding options
    int optionsIndex = 0;
    for (auto it = foundInstances.begin(); it != foundInstances.end(); it++) {
        SomeipSDControllerApp::ServiceInstance& instance = *it;
        int numOptions = instance.optionList.size();
        ServiceEntry* entry = instance.entry->dup();
        entry->setNum1stOptions(numOptions);
        entry->setIndex1stOptions(optionsIndex);
        header->encapEntry(entry);
        if (numOptions != 0) {
            for (auto optIt = instance.optionList.begin(); optIt != instance.optionList.end(); optIt++) {
                header->encapOption((*optIt)->dup());
            }
        }
        optionsIndex += numOptions;
    }

    return header;
}

SOA4CoRE::SomeIpSDHeader* SomeipSDControllerApp::buildSubscribeEventGroup(
        SOA4CoRE::SomeIpSDHeader* source, SOA4CoRE::SomeIpSDEntry* entry) {
    SomeIpSDHeader* header = new SomeIpSDHeader("SOME/IP SD - SUBSCRIBEEVENTGROUP");
    header->setRequestID(source->getRequestID());
    auto entryOptions = getEntryOptions(entry, source);
    auto entryDup = entry->dup();
    entryDup->setNum1stOptions(entryOptions.size());
    entryDup->setIndex1stOptions(0);
    if (entryOptions.size() > 0) {
        for (auto it = entryOptions.begin(); it != entryOptions.end(); it++) {
            header->encapOption((*it));
        }
    }
    header->encapEntry(entryDup);
    return header;
}

SOA4CoRE::SomeIpSDHeader* SomeipSDControllerApp::buildSubscribeEventGroupAck(
        SOA4CoRE::SomeIpSDHeader* source, SOA4CoRE::SomeIpSDEntry* entry) {
    SomeIpSDHeader* header = new SomeIpSDHeader("SOME/IP SD - SUBSCRIBEEVENTGROUPACK");
    header->setRequestID(source->getRequestID());
    auto entryOptions = getEntryOptions(entry, source);
    auto entryDup = entry->dup();
    entryDup->setNum1stOptions(entryOptions.size());
    entryDup->setIndex1stOptions(0);
    if (entryOptions.size() > 0) {
        for (auto it = entryOptions.begin(); it != entryOptions.end(); it++) {
            header->encapOption((*it));
        }
    }
    header->encapEntry(entryDup);
    return header;
}

void SomeipSDControllerApp::sendFind(SomeIpSDHeader* find, SomeIpSDHeader* findSource){
    LayeredInformation* info = dynamic_cast<LayeredInformation*>(findSource->getControlInfo());
    //Layer 4
    UDPPacket *udpPacket = new UDPPacket(find->getName());
        udpPacket->setByteLength(UDP_HEADER_BYTES);
        udpPacket->encapsulate(find);
        udpPacket->setSourcePort(myLayeredInformation.transport_src);
        udpPacket->setDestinationPort(SOMEIPSD_PORT);

    //Layer 3
    IPv4Datagram *datagram = new IPv4Datagram(find->getName());
    IPv4Address src = myLayeredInformation.ip_src.toIPv4();
    short ttl = 1;
        datagram->setByteLength(IP_HEADER_BYTES);
        datagram->encapsulate(udpPacket);
        datagram->setSrcAddress(src);
        datagram->setDestinationAddress(inet::IPv4Address(BROADCASTADDRESS));
        datagram->setMoreFragments(false);
        datagram->setTimeToLive(ttl);
        datagram->setTransportProtocol(17); //the UDP-standard protocol-id

    // Layer 2
    EthernetIIFrame *eth2Frame = new EthernetIIFrame(find->getName());
        eth2Frame->setSrc(myLayeredInformation.eth_src);
        eth2Frame->encapsulate(datagram);
        if (eth2Frame->getByteLength() < MIN_ETHERNET_FRAME_BYTES)
            eth2Frame->setByteLength(MIN_ETHERNET_FRAME_BYTES); // "padding"

    // Openflow
    OFP_Packet_Out *packetOut = new OFP_Packet_Out("packetOut");
        packetOut->getHeader().version = OFP_VERSION;
        packetOut->getHeader().type = OFPT_PACKET_OUT;
        packetOut->setBuffer_id(OFP_NO_BUFFER);
        packetOut->setByteLength(24);
        packetOut->encapsulate(eth2Frame);
    ofp_action_output *action_output = new ofp_action_output();
    action_output->port = OFPP_FLOOD;
        packetOut->setIn_port(info->in_port);
        packetOut->setActionsArraySize(1);
        packetOut->setActions(0, *action_output);
        packetOut->setKind(TCP_C_SEND);

    controller->sendPacketOut(packetOut, info->sw_info->getSocket());
}

void SomeipSDControllerApp::sendOffer(SomeIpSDHeader* offer, SomeIpSDHeader* findSource, LayeredInformation* infoFind, LayeredInformation* infoOffer){
    EthernetIIFrame *eth2Frame = encapSDHeader(offer, infoOffer, infoFind);

    uint32_t outports [] = {(uint32_t)infoFind->in_port};
    OFP_Packet_Out *packetOut = OFMessageFactory::instance()->createPacketOut(
            outports, 1, OFPP_CONTROLLER, OFP_NO_BUFFER, eth2Frame);
    packetOut->setKind(TCP_C_SEND);

    controller->sendPacketOut(packetOut, infoFind->sw_info->getSocket());

    delete eth2Frame;
}

void SomeipSDControllerApp::installFlowForSubscription(Subscription& sub) {
    // flow specification
    IPv4Address ip_src = sub.providerEndpoint.getIpv4Address();
    uint16_t tp_src = sub.providerEndpoint.getPort();
    uint8_t ip_proto = sub.consumerEndpoint.getL4Protocol();
    IPv4Address ip_dst = sub.consumerEndpoint.getIpv4Address();
    uint16_t tp_dst = sub.consumerEndpoint.getPort();
    IPv4Address ip_host_dst = sub.getDstHostIp();

    // TODO add mcast support!!
    bool isMcast = sub.isMcast();

    // find route from the switch were the subAck arrived to the consumer IP
    TopologyManagement::Route route = topology->findRoute(
            topology->findEdgePort(ip_src).switchId, ip_host_dst);
    if(route.empty()){
        throw cRuntimeError("Could not find a route for acknowledged subscription");
    }
    // create the match
    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_IPV4_SRC, &(ip_src));
    builder->setField(OFPXMT_OFB_UDP_SRC, &(tp_src));
    builder->setField(OFPXMT_OFB_IP_PROTO, &(ip_proto));
    builder->setField(OFPXMT_OFB_IPV4_DST, &(ip_dst));
    builder->setField(OFPXMT_OFB_UDP_DST, &(tp_dst));
    for(SwitchPort& switchPort : route) {
        int inport = topology->findOutportAtSwitch(switchPort.switchId, ip_src);
        builder->setField(OFPXMT_OFB_IN_PORT, &(inport));
        oxm_basic_match match = builder->build();
        TCPSocket* socket = controller->findSocketForChassisId(switchPort.switchId);
        sendFlowModMessage(ofp_flow_mod_command::OFPFC_ADD, match, switchPort.port, socket, _idleTimeout, _hardTimeout);
    }
}

list<SomeIpSDOption*> SomeipSDControllerApp::getEntryOptions(SomeIpSDEntry* xEntry, SomeIpSDHeader* header) {
    int optionPosition = xEntry->getIndex1stOptions();
    int optionQuantity = xEntry->getNum1stOptions();
    std::list<SomeIpSDOption*> optionList;
    std::list<SomeIpSDOption*> optList = header->getEncapOptions();
    std::_List_iterator<SomeIpSDOption*> optionListIterator = optList.begin();
    std::advance(optionListIterator, optionPosition);
    for (int firstOptionsIdx = 0; firstOptionsIdx < optionQuantity; firstOptionsIdx++) {
        SomeIpSDOption* option = *optionListIterator;
        optionList.push_back(option->dup());
        std::advance(optionListIterator, 1);
    }
    return optionList;
}

void SomeipSDControllerApp::updateServiceTable(ServiceInstance& newInfo) {
    uint16_t serviceId = newInfo.entry->getServiceID();
    uint16_t instanceId = newInfo.entry->getInstanceID(); //Which Instance is offered
    //ServiceID exists in ServiceTable?
    auto found = serviceTable.find(serviceId);
    if (found != serviceTable.end()) {
        //InstanceID exists in Table?
        auto foundInstance = found->second.find(instanceId);
        if (foundInstance != found->second.end()) {
            // Case 1: ServiceID and InstanceID exist -> update value of InstanceMap -> entry
            ServiceInstance& serviceInstance = foundInstance->second;//
            for (auto oldOptionIter = serviceInstance.optionList.begin(); oldOptionIter != serviceInstance.optionList.end(); ++oldOptionIter) {
                bool update = false;
                //check if there is already an option of the same type
                for (auto newOptionIter = newInfo.optionList.begin(); newOptionIter != newInfo.optionList.end(); newOptionIter++) {
                    if((*newOptionIter)->getType() == (*oldOptionIter)->getType()) {
                        // option of same type exists
                        // there can be multiple ipv4 options for different protocols
                        if(IPv4EndpointOption* newOption = dynamic_cast<SOA4CoRE::IPv4EndpointOption*>(*newOptionIter)) {
                            if(IPv4EndpointOption* oldOption = dynamic_cast<SOA4CoRE::IPv4EndpointOption*>(*oldOptionIter)) {
                                if (newOption->getL4Protocol() == oldOption->getL4Protocol()) {
                                    // mark for replacement
                                    update = true;
                                }
                            }
                        } else {
                            // both should not be IPv4 so mark for replacement
                            update = true;
                        }
                    }
                    if(update) {
                        //already found
                        break;
                    }
                }
                if(!update) {
                    // insert old option
                    newInfo.optionList.push_back((*oldOptionIter)->dup());
                }
            }
            // now newInfo is complete
            // cleanup old instance
            serviceInstance.clear();
        } else {
            // Case 2: ServiceID exists but instance unknown -> update InstanceMap new key value
        }
    } else {
        // Case 3: neither service nor instance known -> update serviceTable key key value
        serviceTable[serviceId] = InstanceMap();
    }
    serviceTable[serviceId][instanceId] = newInfo;
}

list<SomeipSDControllerApp::ServiceInstance> SomeipSDControllerApp::lookUpServiceInMap(uint16_t requestedServiceId, uint16_t requestedInstanceId){
    list<ServiceInstance> returnList;
    auto found = serviceTable.find(requestedServiceId);
    if (found != serviceTable.end()) {
        if (requestedInstanceId == 0xFFFF){
            //all InstanceIDs shall be returned [PRS_SOMEIPSD_00351]
            for (auto iter = found->second.begin(); iter != found->second.end(); iter++) {
                returnList.push_back(iter->second);
            }
        } else {
            auto foundInstance = found->second.find(requestedInstanceId);
            if (foundInstance != found->second.end()) {
                returnList.push_back(foundInstance->second);
            }
        }
    }
    return returnList;
}

inet::EthernetIIFrame* SomeipSDControllerApp::encapSDHeader(
        SomeIpSDHeader* header, inet::MACAddress eth_src,
        inet::MACAddress eth_dst, inet::L3Address ip_src,
        inet::L3Address ip_dst, int udp_src, int udp_dst) {
    //Layer 4
    UDPPacket *udpPacket = new UDPPacket(header->getName());
    udpPacket->setByteLength(UDP_HEADER_BYTES);
    udpPacket->setSourcePort(udp_src);
    udpPacket->setDestinationPort(udp_dst);
    udpPacket->encapsulate(header);
    //Layer 3
    IPv4Datagram *datagram = new IPv4Datagram(header->getName());
    datagram->setByteLength(IP_HEADER_BYTES);
    datagram->setDestAddress(ip_dst.toIPv4());
    datagram->setSrcAddress(ip_src.toIPv4());
    datagram->setMoreFragments(false);
    datagram->setTimeToLive(1);
    datagram->setTransportProtocol(IP_PROT_UDP); //the UDP-standard protocol-id
    datagram->encapsulate(udpPacket);
    // Layer 2
    EthernetIIFrame *eth2Frame = new EthernetIIFrame(header->getName());
    eth2Frame->setSrc(eth_src);
    eth2Frame->setDest(eth_dst);
    eth2Frame->encapsulate(datagram);
    if (eth2Frame->getByteLength() < MIN_ETHERNET_FRAME_BYTES)
        eth2Frame->setByteLength(MIN_ETHERNET_FRAME_BYTES); // "padding"
    return eth2Frame;
}

inet::EthernetIIFrame* SomeipSDControllerApp::encapSDHeader(
        SomeIpSDHeader* header, LayeredInformation* bedirectionInfo) {
    return encapSDHeader(header,
            bedirectionInfo->eth_src, bedirectionInfo->eth_dst,
            bedirectionInfo->ip_src, bedirectionInfo->ip_dst,
            bedirectionInfo->transport_src, bedirectionInfo->transport_dst);
}

inet::EthernetIIFrame* SomeipSDControllerApp::encapSDHeader(
        SomeIpSDHeader* header, LayeredInformation* src, LayeredInformation* dst) {
    return encapSDHeader(header,
            src->eth_src, dst->eth_src,
            src->ip_src, dst->ip_src,
            src->transport_src, dst->transport_src);

}

} /*end namespace SDN4CoRE*/

