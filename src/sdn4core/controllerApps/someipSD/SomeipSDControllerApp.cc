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

#include "sdn4core/utility/dynamicmodules/DynamicModuleHandling.h"
//STD
#include <sstream>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/transportlayer/udp/UDPPacket.h"
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

Define_Module(SomeipSDControllerApp);

void SomeipSDControllerApp::initialize() {
    PacketProcessorBase::initialize();
//    serviceTable = check_and_cast<ServiceTable*>(
//            this->getModuleByPath(par("serviceTablePath")));


    // initialize map:
    // 1. Create ServiceEntry - a static entry to simulate an entry in an coming xml table
    ServiceEntry* entry = new ServiceEntry();
    // 2. fill entry
    entry->instanceID = 0;
    entry->majorVersion = 1;
    entry->minorVersion = 0;
    entry->options = std::list<SomeIpSDOption*>;
    //...
    // 3. insert into map
    InstanceMap instances(); // calls map constructor
    instances[entry->instanceID] = entry;
    serviceTable[serviceId] = instances;
}


void SomeipSDControllerApp::processPacketIn(OFP_Packet_In* packet_in_msg) {
    // Message aus OpenFlowPacket auspacken:
    // Layer 2-4, je Layer prüfen, ob es richtiges Paket ist und auspacken
    // ServiceEntry anschauen -> processSomeIpSDHeader

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
                    someIpSDHeader->setControlInfo(layeredInformation);
                    processSomeIpSDHeader(someIpSDHeader);


                    // b) fill layeredInformation... <-schlechteste option
                    processSomeIpSDHeader(someIpSDHeader, layeredInformation);

                    // c) forward packetin
                    processSomeIpSDHeader(someIpSDHeader, packet_in_msg);

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
        // 1 element aus der Liste
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

    list<ServiceEntry*> entries = lookUpFindInMap(findEntry);
    if( entries.empty())
    {
       //nothing found - broadcast find
    }
        uint16_t serviceId = findEntry->getServiceID();
        uint16_t instanceID = findEntry->getInstanceID();
        uint8_t majorVersion = findEntry->getMajorVersion();
        struct ServiceInformation {
               serviceID;
               uint16_t instanceID;
               uint8_t majorVersion;
        };
        for (serviceInformation::const_iterator it = serviceInformation.begin(); it != serviceInformation.end(); ++it){
            instanceTable.push_back(it);
        }

        serviceTable[serviceID] = {instanceId, instanceTable};

}

void SomeipSDControllerApp::sendOffer(SomeIpSDHeader* someIpSDHeader, SomeIPSDHeader* findSource){
    // aus findSource die Zieladresse für das Offer
    // den neuen Header mit encapsulated entry
    // in OFP_Packet_Out verpacken und Layer 4-2 beachten

}

void SomeipSDControllerApp::buildOffer(SomeIpSDHeader* findSource){
    // Header mit Daten aus xml-Datei erstellen
    // SomeIpSDEntry aus xml erstellen
    // SomeIpSDOptions erstellen
    // Envelope mit den drei Datein
    // entweder hier das sendOffer aufrufen
    // oder Rückgabewert auf SomeIpSDHeader ändern und vielleicht in der processFindEntry verarbeiten

}

list<ServiceEntry*> SomeipSDControllerApp::lookUpFindInMap(SomeIpSDEntry* findEntry){
    list<ServiceEntry*> returnList;
    uint16_t requestedServiceId = findEntry->getServiceID();
    auto found=serviceTable.find(requestedServiceId);
    if (found != serviceTable.end()) {
        auto instanceMap = found->second;
        auto requestedInstanceId = findEntry->getInstanceID();
        if (requestedInstanceId == 0xFFFF){
            //all InstanceIDs shall be returned [PRS_SOMEIPSD_00351]
            for (auto instance: instanceMap) {
                returnList.push_back(instance);
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

