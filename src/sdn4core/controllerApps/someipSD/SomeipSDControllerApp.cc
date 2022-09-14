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

using namespace inet;
using namespace std;
using namespace openflow;
using namespace CoRE4INET;
using namespace SOA4CoRE;

namespace SDN4CoRE {

// Löschen, wenn Datenstruktur zum Speichern der Offers vorhanden
#define MAJOR_VERSION 0xFF       // see [PRS_SOMEIPSD_00351],[PRS_SOMEIPSD_00356],[PRS_SOMEIPSD_00386],[PRS_SOMEIPSD_00391]
#define MINOR_VERSION 0xFFFFFFFF // see [PRS_SOMEIPSD_00351],[PRS_SOMEIPSD_00356],[PRS_SOMEIPSD_00386],[PRS_SOMEIPSD_00391]
#define TTL 0xFFFFFF             // see [PRS_SOMEIPSD_00351],[PRS_SOMEIPSD_00356],[PRS_SOMEIPSD_00386],[PRS_SOMEIPSD_00391]


Define_Module(SomeipSDControllerApp);

void SomeipSDControllerApp::initialize() {
    PacketProcessorBase::initialize();
//    serviceTable = check_and_cast<ServiceTable*>(
//    this->getModuleByPath(par("serviceTablePath")));


    // 1. Create ServiceEntry - a static entry to simulate one entry in an coming xml table
    ServiceEntry* entry = new ServiceEntry("ServiceEntry");
    // 2. fill entry
    entry->setType(SOA4CoRE::SomeIpSDEntryType::OFFER);
    entry->setIndex1stOptions(0);
    entry->setIndex2ndOptions(0);
    entry->setNum1stOptions(2);
    entry->setNum2ndOptions(0);
    entry->setServiceID(1);
    entry->setInstanceID(1);
    entry->setMajorVersion(MAJOR_VERSION);
    entry->setTTL(TTL);
    entry->setMinorVersion(MINOR_VERSION);

    //Option UDP
    IPv4EndpointOption *ipv4EndpointOption = new IPv4EndpointOption("IPv4EndpointOption of Publisher");
    ipv4EndpointOption->setIpv4Address(IPv4Address("192.168.178.1"));
    ipv4EndpointOption->setL4Protocol(IPProtocolId::IP_PROT_UDP);
    ipv4EndpointOption->setPort(3171);
    //Option TCP
    IPv4EndpointOption *ipv4EndpointOption2 = new IPv4EndpointOption("IPv4EndpointOption of Publisher");
    ipv4EndpointOption2->setIpv4Address(IPv4Address("192.168.178.1"));
    ipv4EndpointOption2->setL4Protocol(IPProtocolId::IP_PROT_TCP);
    ipv4EndpointOption2->setPort(3171);
    ServiceInstance instance;
    instance.entry = entry;
    instance.optionList.push_back(ipv4EndpointOption);
    instance.optionList.push_back(ipv4EndpointOption2);
    // 3. insert into map
    InstanceMap instances; // calls map constructor
    instances[entry->getInstanceID()] = instance;
    serviceTable[entry->getServiceID()] = instances;
}


void SomeipSDControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {

    // layer 2
    if (EthernetIIFrame* eth =
                dynamic_cast<EthernetIIFrame *>
                        (packet_in_msg->getEncapsulatedPacket())) {
        //layer 3
        if (INetworkDatagram* ip =
                dynamic_cast<INetworkDatagram *>
                            (eth->getEncapsulatedPacket())) {

            // layer 4
            if (UDPPacket* transport = dynamic_cast<UDPPacket*>(eth->getEncapsulatedPacket()->getEncapsulatedPacket())) {
                if (SomeIpSDHeader *someIpSDHeader = dynamic_cast<SomeIpSDHeader*>(transport->getEncapsulatedPacket()))  {
                    // a) fill layeredInformation and attach control info
                    LayeredInformation * layeredInformation = new LayeredInformation();
                    layeredInformation->eth_src = eth->getSrc();
                    layeredInformation->ip_src = ip->getSourceAddress();
                    layeredInformation->transport_src = transport->getSourcePort();
                    someIpSDHeader->setControlInfo(layeredInformation);
                    processSomeIpSDHeader(someIpSDHeader);
//
//
//                    // b) fill layeredInformation... <-schlechteste option
//                    processSomeIpSDHeader(someIpSDHeader, layeredInformation);
//
//                    // c) forward packetin
//                    processSomeIpSDHeader(someIpSDHeader, packet_in_msg);

                }
            }
        }
    }
        // checken, ob ein Offer in unserer Xml-Datei steht, wenn ja Offer erzeugen alsAnwort auf find - Verbindung in
        // Flowtable eintragen
        // wenn nein, find in ToDo-Liste und selber find versenden.
        // Nach Antwort, Eintrag in Xml und s.o. find bearbeiten
}

void SomeipSDControllerApp::processSomeIpSDHeader(SomeIpSDHeader* someIpSDHeader) {
    std::list<SomeIpSDEntry*> entries = someIpSDHeader->getEncapEntries();
    for (std::list<SomeIpSDEntry*>::const_iterator it = entries.begin(); it != entries.end(); ++it) {
        switch ((*it)->getType()) {
            case SOA4CoRE::SomeIpSDEntryType::FIND:
                EV << "FIND ARRIVED" << endl;
                processFindEntry(*it, someIpSDHeader);
                break;
            case SOA4CoRE::SomeIpSDEntryType::OFFER:
                EV << "OFFER ARRIVED" << endl;
                // processOfferEntry(*it, someIpSDHeader);
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

void SomeipSDControllerApp::processFindEntry(SomeIpSDEntry* findEntry, SomeIpSDHeader* someIpSDHeader) {

    std::list<ServiceInstance> entries = lookUpFindInMap(findEntry);
    if( entries.empty())
    {
       //nothing found - broadcast find
    } else {

        SomeIpSDHeader* foundOffer = buildOffer(someIpSDHeader, findEntry, entries);
        sendOffer(foundOffer, someIpSDHeader);
    }


//        for (serviceInformation::const_iterator it = serviceInformation.begin(); it != serviceInformation.end(); ++it){
//            instanceTable.push_back(it);
//        }
//
//        serviceTable[serviceID] = {instanceID, instanceTable};

}

void SomeipSDControllerApp::sendOffer(SomeIpSDHeader* offer, SomeIpSDHeader* findSource){
    // aus findSource die Zieladresse für das Offer
    // den neuen Header mit encapsulated entry
    // in OFP_Packet_Out verpacken und Layer 4-2 beachten

    //Layer 4
    LayeredInformation* info = dynamic_cast<LayeredInformation*>(findSource->getControlInfo());
    UDPPacket *udpPacket = new UDPPacket(offer->getName());
    udpPacket->setByteLength(UDP_HEADER_BYTES);
    udpPacket->encapsulate(offer);
    udpPacket->setSourcePort(myLayeredInformation.transport_src);
    udpPacket->setDestinationPort(info->transport_src);

    //Layer 3
    IPv4Datagram *datagram = new IPv4Datagram(offer->getName());
    datagram->setByteLength(IP_HEADER_BYTES);
    datagram->encapsulate(udpPacket);

    // set source and destination address
    IPv4Address dest = info->ip_src.toIPv4();
    datagram->setDestAddress(dest);
    IPv4Address src = myLayeredInformation.ip_src.toIPv4();
    datagram->setSrcAddress(src);

    // set other fields
    // to do Herausfinden was typeOfService ist, bzw auf einen unsigned char setzen
//    datagram->setTypeOfService(controlInfo->getTypeOfService());
//    datagram->setIdentification(curFragmentId++);
    datagram->setMoreFragments(false);
//    datagram->setDontFragment(controlInfo->getDontFragment());
//    datagram->setFragmentOffset(0);
    short ttl = 1;
    datagram->setTimeToLive(ttl);
    datagram->setTransportProtocol(17);

    // Layer 2
    EthernetIIFrame *eth2Frame = new EthernetIIFrame(offer->getName());
    eth2Frame->setSrc(myLayeredInformation.eth_src);
    // if blank, will be filled in by MAC
    eth2Frame->setDest(info->eth_src);
    eth2Frame->encapsulate(datagram);
    if (eth2Frame->getByteLength() < MIN_ETHERNET_FRAME_BYTES)
        eth2Frame->setByteLength(MIN_ETHERNET_FRAME_BYTES); // "padding"


}

SomeIpSDHeader* SomeipSDControllerApp::buildOffer(SomeIpSDHeader* findSource, SomeIpSDEntry* findEntry, list<ServiceInstance> foundInstances){
    // findSource --> information about requester
    // findEntry --> information what was requested
    // list foundEntries --> found entries to include in the offer as options

    // Header mit Daten aus xml-Datei erstellen
    // SomeIpSDEntry aus xml erstellen
    // SomeIpSDOptions erstellen
    // Envelope mit den drei Datein
    // entweder hier das sendOffer aufrufen
    // oder Rückgabewert auf SomeIpSDHeader ändern und vielleicht in der processFindEntry verarbeiten

    SomeIpSDHeader* header = new SomeIpSDHeader();
    header->setRequestID(findSource->getRequestID());

    // create offer entry per found entry.
    int optionsIndex = 0;
    for (auto instance: foundInstances) {
        int numOptions = instance.optionList.size();
        instance.entry->setNum1stOptions(numOptions);
        instance.entry->setIndex1stOptions(optionsIndex);
        header->encapEntry(instance.entry);
        for (auto option: instance.optionList){
            header->encapOption(option);
        }
        optionsIndex += numOptions;
    }

    return header;
}

list<SomeipSDControllerApp::ServiceInstance> SomeipSDControllerApp::lookUpFindInMap(SomeIpSDEntry* findEntry){
    list<ServiceInstance> returnList;
    uint16_t requestedServiceId = findEntry->getServiceID();
    auto found = serviceTable.find(requestedServiceId);
    if (found != serviceTable.end()) {
        auto instanceMap = found->second;
        auto requestedInstanceId = findEntry->getInstanceID();
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

} /*end namespace SDN4CoRE*/

