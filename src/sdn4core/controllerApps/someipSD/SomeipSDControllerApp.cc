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
                    processSomeIpSDHeader(someIpSDHeader);
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
                // processFindEntry(*it, someIpSDHeader);
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


} /*end namespace SDN4CoRE*/

