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
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
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
    myLayeredInformation.inPort = -1;
    myLayeredInformation.swInfo = nullptr;

    //[PRS_SOMEIPSD_00158] dThe Session-ID (SOME/IP header) shall start with 1 and
    //be 1 even after wrapping.c(RS_SOMEIPSD_00001)
    // important for the finds the controller sends
    controllerRequestID = 0x0001;
    WATCH_MAPMAP(serviceTable);
    WATCH_LISTMAP(requestTable);
}

void SomeipSDControllerApp::processFindEntry(SomeIpSDEntry* findInquiry, SomeIpSDHeader* someIpSDHeader) {

    std::list<ServiceInstance> entries = lookUpFindInMap(findInquiry);
    if(entries.empty())
    {
        SomeIpSDHeader* myFind = buildFind(someIpSDHeader, findInquiry);
        sendFind(myFind, someIpSDHeader);

        FindRequest saveFind;
        saveFind.requestHeader = someIpSDHeader->dup();
        LayeredInformation* layeredInformation = dynamic_cast<LayeredInformation*>(someIpSDHeader->getControlInfo());
        saveFind.requestHeader->setControlInfo(layeredInformation->dup());
        saveFind.entry = dynamic_cast<ServiceEntry*>(findInquiry->dup());
        saveFind.entry->setIndex1stOptions(0);
        std::list<SomeIpSDOption*> findOptions = getEntryOptions(findInquiry, someIpSDHeader);
        for (auto option: findOptions) {
            saveFind.optionList.push_back(option);
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
        sendOffer(foundOffer, someIpSDHeader);
    }
}

void SomeipSDControllerApp::processOfferEntry(SomeIpSDEntry* offerEntry,SomeIpSDHeader* someIpSDHeader) {
    // update ServiceTable with offer
    // look for requested offers in requestTable
    std::list<ServiceInstance> entries;
    ServiceInstance instance;
    instance.entry = dynamic_cast<ServiceEntry*>(offerEntry->dup());
    instance.entry->setIndex1stOptions(0);
    instance.optionList = getEntryOptions(offerEntry, someIpSDHeader);
    entries.push_back(instance);
    updateServiceTable(instance);


    auto foundX = requestTable.find(offerEntry->getServiceID());
    std::list<FindRequest> findInstances = foundX->second;
    for (auto find: findInstances) {
        if (find.entry->getServiceID() == 0xFFFF) {
            SomeIpSDHeader* foundOffer = buildOffer(find.requestHeader, find.entry, entries);
            sendOffer(foundOffer, find.requestHeader);
        } else if (find.entry->getServiceID() == find.entry->getServiceID()) {
            SomeIpSDHeader* foundOffer = buildOffer(find.requestHeader, find.entry, entries);
            sendOffer(foundOffer, find.requestHeader);
        }
    }
}


void SomeipSDControllerApp::sendOffer(SomeIpSDHeader* offer, SomeIpSDHeader* findSource){

    LayeredInformation* info = dynamic_cast<LayeredInformation*>(findSource->getControlInfo());

    //Layer 4
    UDPPacket *udpPacket = new UDPPacket(offer->getName());
        udpPacket->setByteLength(UDP_HEADER_BYTES);
        udpPacket->encapsulate(offer);
        udpPacket->setSourcePort(myLayeredInformation.transport_src);
        udpPacket->setDestinationPort(info->transport_src);

    //Layer 3
    IPv4Datagram *datagram = new IPv4Datagram(offer->getName());
    IPv4Address dest = info->ip_src.toIPv4();
    IPv4Address src = myLayeredInformation.ip_src.toIPv4();
    short ttl = 1;
        datagram->setByteLength(IP_HEADER_BYTES);
        datagram->encapsulate(udpPacket);
        datagram->setDestAddress(dest);
        datagram->setSrcAddress(src);
        datagram->setMoreFragments(false);
        datagram->setTimeToLive(ttl);
        datagram->setTransportProtocol(17); //the UDP-standard protocol-id

    // Layer 2
    EthernetIIFrame *eth2Frame = new EthernetIIFrame(offer->getName());
        eth2Frame->setSrc(myLayeredInformation.eth_src);
        eth2Frame->setDest(info->eth_src);
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
//        packetOut->setIn_port(eth2Frame->getArrivalGate()->getIndex());
    ofp_action_output *action_output = new ofp_action_output();
    action_output->port = info->inPort;
        packetOut->setActionsArraySize(1);
        packetOut->setActions(0, *action_output);
        packetOut->setKind(TCP_C_SEND);

    controller->sendPacketOut(packetOut, info->swInfo->getSocket());
}

SomeIpSDHeader* SomeipSDControllerApp::buildOffer(SomeIpSDHeader* findSource, SomeIpSDEntry* findEntry, list<ServiceInstance> foundInstances){
    // findSource --> information about requester in the layered information
    // findEntry --> information what is requested
    // list foundEntries --> struct with found entries and list of options

    SomeIpSDHeader* header = new SomeIpSDHeader("SOME/IP SD - OFFER");
        header->setRequestID(findSource->getRequestID());

    // create offer - encap each found entry with corresponding options
    int optionsIndex = 0;
    for (auto instance: foundInstances) {
        int numOptions = instance.optionList.size();
        instance.entry->setNum1stOptions(numOptions);
        instance.entry->setIndex1stOptions(optionsIndex);
        header->encapEntry(instance.entry->dup());
        if (numOptions != 0) {
            for (auto option: instance.optionList){
            header->encapOption(option->dup());
            }
        }
        optionsIndex += numOptions;
    }

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
        packetOut->setIn_port(info->inPort);
        packetOut->setActionsArraySize(1);
        packetOut->setActions(0, *action_output);
        packetOut->setKind(TCP_C_SEND);

    controller->sendPacketOut(packetOut, info->swInfo->getSocket());
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
    for (auto option: oldOptionList) {
        header->encapOption(option);
    }
    return header;
}

list<SomeipSDControllerApp::ServiceInstance> SomeipSDControllerApp::lookUpFindInMap(SomeIpSDEntry* findInquiry){
    list<ServiceInstance> returnList;
    uint16_t requestedServiceId = findInquiry->getServiceID();
    auto found = serviceTable.find(requestedServiceId);
    if (found != serviceTable.end()) {
        auto instanceMap = found->second;
        auto requestedInstanceId = findInquiry->getInstanceID();
        if (requestedInstanceId == 0xFFFF){
            //all InstanceIDs shall be returned [PRS_SOMEIPSD_00351]
            for (auto instance: instanceMap) {
                returnList.push_back(instance.second);
            }
        } else {
            auto foundInstance = instanceMap.find(requestedInstanceId);
            if (foundInstance != instanceMap.end() ) {
                returnList.push_back(foundInstance->second);
            }
        }
    }
    return returnList;
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

//void SomeipSDControllerApp::updateRequestTable(requestInstance& newInfo){
//
//}

void SomeipSDControllerApp::updateServiceTable(ServiceInstance& newInfo) {
    // insert ServiceInstance in an InstanceMap - this into ServiceInstanceMap called serviceTable
    // Case 1: ServiceID and InstanceID exist -> update value of InstanceMap -> entry
    // Case 2: ServiceID exists -> update InstanceMap -> new key value
    // Case 3: neither nor exists -> update serviceTable key key value
    auto offeredServiceId = newInfo.entry->getServiceID();
    auto found = serviceTable.find(offeredServiceId); //ServiceID exists in ServiceTable?
    // Case 1 or 2:
    if (found != serviceTable.end()) {
        auto offeredInstance = newInfo.entry->getInstanceID(); //Which Instance is offered
        auto foundInstance = found->second.find(offeredInstance); //InstanceID exists in Table?
        if (foundInstance != found->second.end()) {
            auto serviceInstance = foundInstance->second;//
            for (auto iter = serviceInstance.optionList.begin(); iter != serviceInstance.optionList.end(); ) {
                auto castIter = dynamic_cast<SOA4CoRE::IPv4EndpointOption*>(*iter);
                bool removed = false;
                for (auto elem: newInfo.optionList) {
                    auto castElem = dynamic_cast<SOA4CoRE::IPv4EndpointOption*>(elem);
                    //if this 3 entries are the same, its the same Option -> delete from old list
                    if (castElem->getIpv4Address() == castIter->getIpv4Address()
                        && castElem->getL4Protocol() == castIter->getL4Protocol()
                        && castElem->getPort() == castIter->getPort()) {
                        iter = serviceInstance.optionList.erase(iter);
                        removed = true;
                        break;
                    }
                }
                if (!removed) {
                    ++iter;
                }
            }
            // insert remaining Options in new list
            for (auto elem: serviceInstance.optionList) {
                newInfo.optionList.push_back(elem);
            }
//            newInfo.optionList.merge(serviceInstance.optionList);
            foundInstance->second.clear();
            found->second[offeredInstance] = newInfo;
        } else {
            found->second[offeredInstance] = newInfo;
            serviceTable[newInfo.entry->getServiceID()] = found->second;
        }
    } else {
        InstanceMap newMap;
        newMap[newInfo.entry->getInstanceID()] = newInfo;
        serviceTable[newInfo.entry->getServiceID()] = newMap;
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
                // processSubscribeEventGroupEntry(*it, someIpSDHeader);
                break;
            case SOA4CoRE::SomeIpSDEntryType::SUBSCRIBEVENTGROUPACK:
                EV << "SUBSCRIBEVENTGROUPACK ARRIVED" << endl;
                // processSubscribeEventGroupAckEntry(*it, someIpSDHeader);
                break;
            default:
                EV << "Unknown type" << std::endl;
        }
    }
}

void SomeipSDControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
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
                    layeredInformation->ip_src = ip->getSourceAddress();
                    layeredInformation->transport_src = transport->getSourcePort();
                    layeredInformation->inPort = eth->getArrivalGate()->getIndex();
                    layeredInformation->swInfo = controller->findSwitchInfoFor(packet_in_msg);
                    someIpSDHeader->setControlInfo(layeredInformation);
                    processSomeIpSDHeader(someIpSDHeader);
                }
            }
        }
    }
}

} /*end namespace SDN4CoRE*/

