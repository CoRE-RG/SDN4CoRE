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
    entry->setNum1stOptions(0);
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

    myLayeredInformation.eth_src.setAddress("0A:AA:00:00:00:0A");
    myLayeredInformation.ip_src = L3Address("10.0.0.2");
    myLayeredInformation.transport_src = 30490; // guck mal nach dem SD Port

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
                    layeredInformation->inPort = eth->getArrivalGate()->getIndex();
                    layeredInformation->swInfo = controller->findSwitchInfoFor(packet_in_msg);
                    someIpSDHeader->setControlInfo(layeredInformation);
                    processSomeIpSDHeader(someIpSDHeader);
//
//          // Haben uns für a) entschieden - Optionen stehen lassen um Entscheidung zu begründen
//                    //b) fill layeredInformation... <-schlechteste option
//                    processSomeIpSDHeader(someIpSDHeader, layeredInformation);
//                    //c) forward packetin
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
        // Hier wird jede entry einzeln verarbeitet, kann man ggf Entries gebündelt verarbeiten?
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
       //toDO nothing found - broadcast find
    } else {
        SomeIpSDHeader* foundOffer = buildOffer(someIpSDHeader, findEntry, entries);
        sendOffer(foundOffer, someIpSDHeader);
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
//      Fields set to default values
//      datagram->setTypeOfService(controlInfo->getTypeOfService());
//      datagram->setIdentification(curFragmentId++);
//      datagram->setDontFragment(controlInfo->getDontFragment());
//      datagram->setFragmentOffset(0);

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
//      packetOut->setIn_port(eth2Frame->getArrivalGate()->getIndex())
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

    // toDo Header mit Daten aus xml-Datei erstellen

    SomeIpSDHeader* header = new SomeIpSDHeader();
        header->setRequestID(findSource->getRequestID());

    // create offer - encap each found entry with corresponding options
    int optionsIndex = 0;
    for (auto instance: foundInstances) {
        int numOptions = instance.optionList.size();
        instance.entry->setNum1stOptions(numOptions);
        instance.entry->setIndex1stOptions(optionsIndex);
        header->encapEntry(instance.entry->dup());
        for (auto option: instance.optionList){
            header->encapOption(option->dup());
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

