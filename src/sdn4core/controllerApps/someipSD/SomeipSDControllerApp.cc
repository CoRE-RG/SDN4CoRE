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

#include "sdn4core/controllerApps/someipSD/SomeipSDControllerApp.h"

//STD
#include <sstream>
#include <stdlib.h>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/transportlayer/udp/UDPPacket.h"
#include <inet/networklayer/contract/ipv4/IPv4Address.h>
#include <inet/networklayer/common/IPProtocolId_m.h>
#include "inet/transportlayer/tcp_common/TCPSegment_m.h"

//openflow
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"
//CoRE4INET
#include "core4inet/utilities/customWatch.h"
#include "core4inet/utilities/HelperFunctions.h"
//SOA4CoRE
#include "soa4core/utility/comfortFunctions.h"

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
    forwardOfferMulticast = this->par("forwardOfferMulticast");
    someipMcastAddress = IPv4Address(par("someipMcastAddress").stringValue());

    if (!(serviceTable = tryLocateStateManager<SomeipServiceTable*>("serviceTable")))
    {
        // create the service manager
        serviceTable = dynamic_cast<SomeipServiceTable*>(
                createFinalizeAndScheduleDynamicModule("sdn4core.controllerState.services.SomeipServiceTable",
                        "serviceTable", this->getParentModule()->getSubmodule("controllerState"), false));
        if (!serviceTable)
        {
            throw cRuntimeError("Could not find or create SomeipServiceTable.");
        }
    }

    if ((reserveResources = this->par("reserveResources")))
    {
        srpManager = tryLocateStateManager<SRPTableManagement*>("srpTableManagement");
        if (!srpManager)
        {
                // create the mac manager
            srpManager = dynamic_cast<SRPTableManagement*>(
                    createFinalizeAndScheduleDynamicModule("sdn4core.controllerState.srp.SRPTableManagement",
                            "srpTableManagement", this->getParentModule()->getSubmodule("controllerState"), false));
            if (!srpManager)
            {
                throw cRuntimeError("Could not create SRPTableManagement.");
            }
        }
    }

    streamIntervalAsCMI = this->par("streamIntervalAsCMI");
    if (!streamIntervalAsCMI)
    {
        cValueMap* pcpCMI = dynamic_cast<cValueMap*>(this->par("pcpCMI").objectValue());
        if(!pcpCMI) {
            throw cRuntimeError("CMIs for PCPs have not been specified.");
        }
        for (auto it : pcpCMI->getFields())
        {
            int pcp = atoi(it.first.c_str());
            double cmi = it.second.doubleValueInUnit("s");
            if (cmi > 0)
            {
                pcpCMIs[pcp] = cmi;
            }
        }
    }
    if ((useXMLReservationList = this->par("useXMLReservationList")))
    {
        if (!loadXMLReservationList())
        {
            throw cRuntimeError("useXMLReservationList is set, but no valid configXML");
        }
        nextReservationIndex = 1;
        WATCH_LISTMAP(resourceReservationTable);
    }

    myLayeredInformation.eth_src.setAddress("C0:C0:C0:C0:C0:C0");
    myLayeredInformation.ip_src = L3Address("10.0.0.2");
    myLayeredInformation.transport_src = SOMEIPSD_PORT;
    myLayeredInformation.eth_dst = MACAddress::makeMulticastAddress(someipMcastAddress);
    myLayeredInformation.ip_dst = someipMcastAddress;
    myLayeredInformation.transport_dst = SOMEIPSD_PORT;
    myLayeredInformation.in_port = -1;
    myLayeredInformation.sw_info = nullptr;

    //[PRS_SOMEIPSD_00158] dThe Session-ID (SOME/IP header) shall start with 1 and
    //be 1 even after wrapping.c(RS_SOMEIPSD_00001)
    // important for the finds the controller sends
    controllerRequestID = 0x0001;
}

void SomeipSDControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    Switch_Info* swInfo = controller->findSwitchInfoFor(packet_in_msg);

    // layer 2
    if (EthernetIIFrame* eth = dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        //layer 3
        if (INetworkDatagram* ip = dynamic_cast<INetworkDatagram *>(eth->getEncapsulatedPacket())) {
            // layer 4
            if (UDPPacket* transport = dynamic_cast<UDPPacket*>
                                        (eth->getEncapsulatedPacket()->getEncapsulatedPacket())) {
                if (SomeIpSDHeader* someIpSDHeader = dynamic_cast<SomeIpSDHeader*>
                                                        (transport->getEncapsulatedPacket()))  {
                    if(ip->getSourceAddress() != myLayeredInformation.ip_src) {
                        hostTable->update(packet_in_msg, swInfo);
                    }
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

    LayeredInformation* findInfo = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    auto entries = serviceTable->findLookup(findInquiry->getServiceID(), findInquiry->getInstanceID());

    if(findInfo->ip_src == myLayeredInformation.ip_src) {
        // this is a find forwarded by the controller
        if(!entries.empty()) {
            // we have already answered this when the offer arrived
            return;
        }
        // still unknown so forward
        multicastSOMEIPMessage(someIpSDHeader->dup(), findInfo);
    }
    else if(entries.empty())
    {
        serviceTable->updateRequestTable(findInquiry, someIpSDHeader);
        SomeIpSDHeader* myFind = buildFind(someIpSDHeader, findInquiry);
        multicastSOMEIPMessage(myFind, findInfo);
    } else {
        SomeIpSDHeader* foundOffer = buildOffer(someIpSDHeader, findInquiry, entries);
        forwardSOMEIPMessage(foundOffer,entries.front().layeredInformation,findInfo);
        // TODO maybe use controller layered info if multiple entries
    }
}

void SomeipSDControllerApp::processOfferEntry(SomeIpSDEntry* offerEntry,SomeIpSDHeader* someIpSDHeader) {
    Enter_Method("SomeipSDControllerApp::processOfferEntry()");
    LayeredInformation* info =  dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    auto serviceId = offerEntry->getServiceID();
    auto instanceId = offerEntry->getInstanceID();
    bool forwarded = false;
    if (info->ip_dst.isMulticast() && forwardOfferMulticast)
    {
        SomeIpSDHeader* dupHeader = someIpSDHeader->dup();
        dupHeader->removeControlInfo();
        multicastSOMEIPMessage(dupHeader, info);
        forwarded = true;
    }
    if(info->ip_src == myLayeredInformation.ip_src)
    {// this is an offer forwarded by the controller
        return;
    }
    // update ServiceTable with offer
    serviceTable->updateServiceTable(offerEntry, someIpSDHeader);
    // look for requested offer in requestTable
    auto pendingRequests = serviceTable->getPendingRequests(serviceId, instanceId, true, true);
    for (auto it = pendingRequests.begin(); it != pendingRequests.end(); it++)
    {
        auto entries = serviceTable->findLookup(serviceId, instanceId);
        if(!forwarded)
        {
            SomeIpSDHeader* response = buildOffer(it->requestHeader, it->entry, entries);
            forwardSOMEIPMessage(response,info,it->layeredInformation);
        }
        takeRequest(*it);
        it->clear();
    }
}

void SomeipSDControllerApp::takeRequest(SomeipServiceTable::FindRequest& request) {
    if (request.requestHeader) take(request.requestHeader);
    if (request.entry) take(request.entry);
    for (auto elem: request.optionList) {
        if (elem) take(elem);
    }
}

void SomeipSDControllerApp::processSubscribeEventGroupEntry(SomeIpSDEntry* entry,SomeIpSDHeader* someIpSDHeader)
{
    LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    auto instance = serviceTable->getServiceInstance(entry->getServiceID(), entry->getInstanceID(), true);
    // get dest ip of the service and compare to the dest id in layered information
    L3Address& destination = instance->layeredInformation->ip_src;
    if (destination != layeredInformation->ip_dst && destination != myLayeredInformation.ip_src) {
        throw cRuntimeError("The subscription was sent to a different destination than known to the controller for the service instance!");
    }

    auto& subscription = serviceTable->updateSubscriptionTable(entry, someIpSDHeader);
    subscription.waitingForAck = true;

    // build subscribe eventgroup
    SomeIpSDHeader* header = buildSubscribeEventGroup(someIpSDHeader, entry);
    forwardSOMEIPMessage(header, layeredInformation, instance->layeredInformation);
}

void SomeipSDControllerApp::processSubscribeEventGroupAckEntry(SomeIpSDEntry* entry, SomeIpSDHeader* someIpSDHeader) {
    LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
    uint16_t serviceId = entry->getServiceID();
    uint16_t instanceId = entry->getInstanceID();
    auto& subscriptions = serviceTable->getSubscriptionsReference(serviceId, instanceId);
    bool requested = false;
    for (auto iter = subscriptions.begin(); iter != subscriptions.end(); iter++) {
        if(iter->waitingForAck && iter->consumerInformation.ip_src == layeredInformation->ip_dst) {
            // subscription requested and response is for this specific consumer
            requested = true;
            iter->waitingForAck = false;
            if(!iter->active) {
                // set provider information from subscribe ack in subscription
                SomeipOptionsList options (entry, someIpSDHeader);
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

                if(iter->isMcast()) {
                    installFlowForMulticastSubscription(*iter);
                } else {
                    installFlowForUnicastSubscription(*iter);
                }

                // forward subscription ack to subscriber
                SomeIpSDHeader* header = buildSubscribeEventGroupAck(someIpSDHeader, entry);
                forwardSOMEIPMessage(header, layeredInformation, &iter->consumerInformation);
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

    SomeipOptionsList oldOptionList (findInquiry, findSource);
    for (auto it = oldOptionList.begin(); it != oldOptionList.end(); it++) {
        header->encapOption(*it);
    }
    return header;
}

SomeIpSDHeader* SomeipSDControllerApp::buildOffer(SomeIpSDHeader* findSource, SomeIpSDEntry* findEntry, 
                                        SomeipServiceTable::ServiceInstanceList& foundInstances){
    SomeIpSDHeader* header = new SomeIpSDHeader("SOME/IP SD - OFFER");
    header->setRequestID(findSource->getRequestID());
    int optionsIndex = 0;
    for (auto it = foundInstances.begin(); it != foundInstances.end(); it++) {
        SomeipServiceTable::ServiceInstance& instance = *it;
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
    SomeipOptionsList entryOptions (entry, source);
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
    SomeipOptionsList entryOptions (entry, source);
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

void SomeipSDControllerApp::forwardSOMEIPMessage(SomeIpSDHeader* msg, LayeredInformation* srcInfo, LayeredInformation* dstInfo)
{
    EthernetIIFrame *eth2Frame = encapSDHeader(msg, srcInfo, dstInfo);
    uint32_t outports [] = {(uint32_t)dstInfo->in_port};
    OFP_Packet_Out *packetOut = OFMessageFactory::instance()->createPacketOut(
            outports, 1, OFPP_CONTROLLER, OFP_NO_BUFFER, eth2Frame);
    packetOut->setKind(TCP_C_SEND);
    controller->sendPacketOut(packetOut, dstInfo->sw_info->getSocket());
    delete eth2Frame; // was duplicated during packet out creation
}

void SomeipSDControllerApp::multicastSOMEIPMessage(SomeIpSDHeader* msg, LayeredInformation* srcInfo)
{
    EthernetIIFrame *eth2Frame = encapSDHeader(msg, &myLayeredInformation);
    uint32 outports [] = { OFPP_FLOOD };
    OFP_Packet_Out *packetOut = OFMessageFactory::instance()->createPacketOut(
            outports, 1, srcInfo->in_port, OFP_NO_BUFFER, eth2Frame);
    controller->sendPacketOut(packetOut, srcInfo->sw_info->getSocket());
    delete eth2Frame; // was duplicated during packet out creation
}

void SomeipSDControllerApp::installFlowForUnicastSubscription(SomeipServiceTable::Subscription& sub) {
    // flow specification
    IPv4Address ip_src = sub.providerEndpoint.getIpv4Address();
    uint16_t tp_src = sub.providerEndpoint.getPort();
    uint8_t ip_proto = sub.consumerEndpoint.getL4Protocol();
    IPv4Address ip_dst = sub.consumerEndpoint.getIpv4Address();
    uint16_t tp_dst = sub.consumerEndpoint.getPort();
    // find route from the switch were the subAck arrived to the consumer IP
    TopologyManagement::Route route = topology->findRoute(
            topology->findEdgePort(ip_src).switchId, ip_dst);
    if(route.empty())
    {
        throw cRuntimeError("Could not find a route for acknowledged subscription");
    }
    // reserve switch ressources if needed
    if(reserveResources && requiresResourceReservation(sub))
    {
        if(useXMLReservationList) {
            reserverResourcesForNextConfig();
        } else {
            reserveResourcesForSubscription(sub, route);
        }
    }
    // create the match
    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_IPV4_SRC, &(ip_src));
    builder->setField(OFPXMT_OFB_UDP_SRC, &(tp_src));
    builder->setField(OFPXMT_OFB_IP_PROTO, &(ip_proto));
    builder->setField(OFPXMT_OFB_IPV4_DST, &(ip_dst));
    builder->setField(OFPXMT_OFB_UDP_DST, &(tp_dst));
    // follow the route and install flows
    for(SwitchPort& switchPort : route)
    {
        int inport = topology->findOutportAtSwitch(switchPort.switchId, ip_src);
        builder->setField(OFPXMT_OFB_IN_PORT, &(inport));
        oxm_basic_match match = builder->build();
        TCPSocket* socket = controller->findSocketForChassisId(switchPort.switchId);
        sendFlowModMessage(ofp_flow_mod_command::OFPFC_ADD, match, switchPort.port, socket, _idleTimeout, _hardTimeout);
    }
}

void SomeipSDControllerApp::installFlowForMulticastSubscription(SomeipServiceTable::Subscription& sub) {
    // flow specification valid for all subscriptions of this provider
    IPv4Address ip_host_src = sub.getSrcHostIp();
    uint8_t ip_proto = sub.consumerEndpoint.getL4Protocol();
    IPv4Address ip_mcast_dst = sub.consumerEndpoint.getIpv4Address();
    uint16_t tp_mcast_dst = sub.consumerEndpoint.getPort();

    // create the match
    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_IPV4_SRC, &(ip_host_src));
//    builder->setField(OFPXMT_OFB_UDP_SRC, &(tp_src)); // transport src is unknown from mcast source endpoints
    builder->setField(OFPXMT_OFB_IP_PROTO, &(ip_proto));
    builder->setField(OFPXMT_OFB_IPV4_DST, &(ip_mcast_dst));
    builder->setField(OFPXMT_OFB_UDP_DST, &(tp_mcast_dst));
    // collect routes to all subscribers
    auto & subscriptions = serviceTable->getSubscriptionsReference(sub.service.getServiceId(), sub.service.getInstanceId());
    TopologyManagement::McastRoute mcastRoute;
    for (auto iter = subscriptions.begin(); iter != subscriptions.end(); iter++) {
        // is active sub or the one that just has been added
        bool isNewSub = (*iter) == sub;
        if(isNewSub || iter->active) {
            IPv4Address ip_host_dst = iter->getDstHostIp();

            // find route from the provider switch to the consumer IP
            TopologyManagement::Route route = topology->findRoute(
                    topology->findEdgePort(ip_host_src).switchId, ip_host_dst);
            if(route.empty()) {
                throw cRuntimeError("Could not find a route for acknowledged subscription");
            }
            mcastRoute.mergeRoute(route);
            // reserve switch ressources if needed
            if(isNewSub && reserveResources && requiresResourceReservation(sub)) {
                if(useXMLReservationList) {
                    reserverResourcesForNextConfig();
                } else {
                    reserveResourcesForSubscription(sub, route);
                }
            }
        }
    }    
    for(auto& hop : mcastRoute.mcastRoute) {
        // hop first is switchid, second is port list
        TCPSocket* socket = controller->findSocketForChassisId(hop.first);
        int inport = topology->findOutportAtSwitch(hop.first, ip_host_src);
        builder->setField(OFPXMT_OFB_IN_PORT, &(inport));
        oxm_basic_match match = builder->build();
        uint32_t outports [hop.second.size()];
        int i = 0;
        for (auto port : hop.second) {
            outports [i++] = port;
        }
        auto flowMod = OFMessageFactory::instance()->createFlowModMessage(
                ofp_flow_mod_command::OFPFC_ADD, match, this->priority, outports, hop.second.size(), _idleTimeout, _hardTimeout);
        EV << "sendFlowModMessage" << '\n';
        numFlowMod++;
        socket->send(flowMod);
    }
}

bool SomeipSDControllerApp::requiresResourceReservation(SomeipServiceTable::Subscription& sub) {
    int serviceId = sub.service.getServiceId();
    int instanceId = sub.service.getInstanceId();
    auto& pubOptions = serviceTable->getServiceInstance(serviceId, instanceId, true)->optionList;
    return pubOptions.hasConfigType<IEEE8021QConfigurationOption*>()
            && pubOptions.hasConfigType<RessourceConfigurationOption*>();
}

void SomeipSDControllerApp::reserveResourcesForSubscription(
        SomeipServiceTable::Subscription& sub, TopologyManagement::Route route) {
    // the serviceId conversion is okay since the service ID is actually uint16_t in the messages
    uint16_t serviceId = sub.service.getServiceId();
    uint16_t instanceId = sub.service.getInstanceId();
    IPv4Address ip_src = sub.getSrcHostIp();
    IPv4Address ip_dst = sub.consumerEndpoint.getIpv4Address();
    MACAddress mac_dest;
    if(ip_dst.isMulticast()) 
    {
        mac_dest = MACAddress::makeMulticastAddress(ip_dst);
    } 
    else 
    {
        mac_dest = hostTable->getHostForIpAddress(ip_dst)->macAddress;
    }
    auto publisher = serviceTable->getServiceInstance(serviceId, instanceId, true);

    auto qOption = publisher->optionList.getFirstConfigOfType<IEEE8021QConfigurationOption*>();
    auto ressourceConfig = publisher->optionList.getFirstConfigOfType<RessourceConfigurationOption*>();
    //calculate framesize used per class measurement interval.
    uint16_t fullL2FrameSize = calculateL2Framesize(sub.consumerEndpoint.getL4Protocol(), ressourceConfig->getMaxPayload());
    int normalizedFramesize = fullL2FrameSize;
    SR_CLASS srclass = SR_CLASS::A;
    double interval;
    if (streamIntervalAsCMI)
    {
        interval = ressourceConfig->getMinInterval();
    }
    else {
        auto cmiIt = pcpCMIs.find(qOption->getPcp());
        if(cmiIt == pcpCMIs.end())
        {
            throw cRuntimeError("CMI for PCP %d unknown", qOption->getPcp());
        }
        interval = cmiIt->second;
    }
    normalizedFramesize = normalizeFramesizeForCMI(fullL2FrameSize, interval, srclass, false);
    if(normalizedFramesize < 0) {
        srclass = SR_CLASS::B;
        normalizedFramesize = normalizeFramesizeForCMI(fullL2FrameSize, interval, srclass, true);
        if(normalizedFramesize < 0) {
            throw cRuntimeError("Normalized framesize negativ for Class A and B CMI");
        }
    }
    // -- not unique if multiple instances of a service exist and are subscribed by the same destination
    // uint64_t streamId = buildStreamIDForService(serviceId, mac_dest)
    uint64_t streamId = buildStreamIDForService(serviceId, instanceId, ip_dst);
    for(SwitchPort& switchPort : route)
    {// for each hop
        // 1. update talker in sr table
        int inport = topology->findOutportAtSwitch(switchPort.switchId, ip_src);
        if(inport < 0) {
            throw cRuntimeError("Could not determine talker port for switch %s and talker IP %s", switchPort.switchId.c_str(), ip_src.str().c_str());
        }
        srpManager->registerTalker(switchPort.switchId, inport,
                streamId, mac_dest, qOption->getVlan_id(), qOption->getPcp(), srclass,
                normalizedFramesize, 1);
        // 2. register new subscriber as listener
        srpManager->registerListener(switchPort.switchId, switchPort.port,
                streamId, qOption->getVlan_id());
        // 3. get new port + pcp bandwidth for the new listener
        unsigned long portIdleSlope = srpManager->getReservedBandwidthForSwitchPortAndPcp(
                switchPort.switchId, switchPort.port, qOption->getPcp());
        // 4. configure the device port accordingly
        sendPortModCBS(switchPort, qOption->getPcp(), portIdleSlope);
    }
}

void SomeipSDControllerApp::reserverResourcesForNextConfig() {
    auto reservationList = resourceReservationTable.find(nextReservationIndex);
    if(reservationList == resourceReservationTable.end()) {
        throw cRuntimeError("nextReservationIndex %d not in resourceReservationTable", nextReservationIndex);
    }
    for (auto reservation : reservationList->second) {
        sendPortModCBS(reservation.switchPort, reservation.pcp, reservation.idleSlope);
    }
    nextReservationIndex++;
}

uint16_t SomeipSDControllerApp::calculateL2Framesize(uint8_t ip_proto,
        uint16_t payload) {
    uint16_t transportBytes;
    switch (ip_proto){
    case IP_PROT_TCP:
        transportBytes = TCP_HEADER_OCTETS;
        break;
    case IP_PROT_UDP:
        transportBytes = UDP_HEADER_BYTES;
        break;
    default:
        throw cRuntimeError("SOME/IP Transport must be either UDP or TCP.");
        break;
    }
    return payload + ETHER_MAC_FRAME_BYTES + ETHER_8021Q_TAG_BYTES
            + IP_HEADER_BYTES + transportBytes + SOMEIP_HEADER_BYTES;
}

void SomeipSDControllerApp::sendPortModCBS(SwitchPort& switchPort, uint8_t pcp, unsigned long idleSlope) {
    TCPSocket* socket = controller->findSocketForChassisId(switchPort.switchId);
    socket->send(buildPortModCBS(switchPort.port, pcp, idleSlope));
}

OFP_TSN_Port_Mod_CBS* SomeipSDControllerApp::buildPortModCBS(uint32_t portno, uint8_t pcp,
        unsigned long idleSlope) {
    OFP_TSN_Port_Mod_CBS* msg = new OFP_TSN_Port_Mod_CBS("portModCBS");
    ofp_header header = msg->getHeader();
    header.version = OFP_VERSION;
    header.type = OFPT_PORT_MOD;
    msg->setHeader(header);
    msg->setPort_no(portno);
    msg->setPcp(pcp);
    msg->setIdleSlope(idleSlope);
    return msg;
}

bool SomeipSDControllerApp::loadXMLReservationList() {
    if (!resourceReservationTable.empty())
        return true; // already loaded a valid config
    bool changed = false;
    if (cXMLElement* xmlDoc = par("configXML").xmlValue()) {
        if (!xmlDoc->isName("resourceReservationTable")) {
            xmlDoc = xmlDoc->getFirstChildWithTag("resourceReservationTable");
        }
        if (!xmlDoc) {
            throw cRuntimeError("Could not find resourceReservationTable in configXML");
        }
        for (auto reservationXML: xmlDoc->getChildrenByTagName("resourceReservation")) {
            if(auto idXML = reservationXML->getAttribute("id")) {
                int id = atoi(idXML);
                resourceReservationTable[id] = ResourceReservationList();
                for (auto switchPortIdleSlopeXML: reservationXML->getChildrenByTagName("switchPortIdleSlope")) {
                    if(auto switchIdXML = switchPortIdleSlopeXML->getAttribute("switch_id")) {
                        if(auto portXML = switchPortIdleSlopeXML->getAttribute("switch_port")) {
                            if(auto pcpXML = switchPortIdleSlopeXML->getAttribute("queue_pcp")) {
                                if(auto idleSlopeXML = switchPortIdleSlopeXML->getAttribute("idle_slope_bps")) {
                                    SwitchPortIdleSlope entry;
                                    entry.idleSlope = strtoul(idleSlopeXML,0,10);
                                    entry.pcp = static_cast<uint8_t>(atoi(pcpXML));
                                    entry.switchPort.port = atoi(portXML);
                                    entry.switchPort.switchId = switchIdXML;
                                    resourceReservationTable[id].push_back(entry);
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return changed;
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

