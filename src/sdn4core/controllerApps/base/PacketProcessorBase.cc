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

#include "PacketProcessorBase.h"

//STD
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/transportlayer/contract/ITransportPacket.h"
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

namespace SDN4CoRE {


simsignal_t PacketProcessorBase::packetFilteredSignal = registerSignal("packetFiltered");
simsignal_t PacketProcessorBase::packetProcessedSignal = registerSignal("packetProcessed");

void PacketProcessorBase::PacketFilter::initializeFromPar(
        const string& parameterValue) {
    this->clear();
    // remove spaces
    string parameter = parameterValue;
    parameter.erase(remove(parameter.begin(), parameter.end(), ' '),
            parameter.end());
    cStringTokenizer listTokens(parameter.c_str(), ";");
    while (listTokens.hasMoreTokens()) {
        cStringTokenizer filterTokens(listTokens.nextToken(), "=");
        string key = filterTokens.nextToken();
        vector<string> values =
                cStringTokenizer(filterTokens.nextToken(), ",").asVector();
        // check inputs are valid syntax.
        if (key.empty()) {
            throw cRuntimeError(
                    "packetFilterList syntax error: Could not parse filter with empty key");
        }
        if (values.empty()) {
            throw cRuntimeError(
                    "packetFilterList syntax error: Could not parse filter with empty value");
        }
        // further checks would require detailed knowledge about key and value...
        // TODO should we implement further checks here to not throw runtime errors?
        // insert it into the map
        (*this)[key] = values;
    }
}

bool PacketProcessorBase::PacketFilter::addPacketFilter(std::string key,
        std::string value) {
    vector<string>values;
    values.push_back(value);
    return addPacketFilters(key, values);
}

bool PacketProcessorBase::PacketFilter::addPacketFilters(std::string key,
        vector<string> values) {
    bool changed = false;
    if (!values.empty() && !key.empty()) {
        auto found = this->find(key);
        if (found != this->end()) {
            for (string existingValue : (*this)[key]) {
                if(std::find(values.begin(), values.end(), existingValue) == values.end()) {
                    values.push_back(existingValue);
                }
            }
            if(values.size() > (*this)[key].size()) {
                changed = true;
            }
        } else {
            changed = true;
        }
        (*this)[key] = values;
    }
    return changed;
}

bool PacketProcessorBase::PacketFilter::matchesIntValue(string key, int value) {
    auto iter = this->find(key);
    if (iter != this->end()) {
        for (const string& strVal : iter->second) {
            if (strtol(strVal.c_str(), NULL, 0) == value) {
                return true;
            }
        }
    }
    return false;
}

bool PacketProcessorBase::PacketFilter::matchesStringValue(string key,
        string value) {
    auto iter = this->find(key);
    if (iter != this->end()) {
        for (const string& strVal : iter->second) {
            if (strVal == value) {
                return true;
            }
        }
    }
    return false;
}

bool PacketProcessorBase::PacketFilter::matchesMACAddressValue(string key,
        MACAddress value) {
    return matchesL3AddressValue(key, value);
}

bool PacketProcessorBase::PacketFilter::matchesL3AddressValue(string key,
        L3Address value) {
    auto iter = this->find(key);
    if (iter != this->end()) {
        for (const string& strVal : iter->second) {
            vector<string> tokenized =
                    cStringTokenizer(strVal.c_str(), "/").asVector();
            if (tokenized.size() > 2 || tokenized.size() < 1) {
                throw cRuntimeError(
                        "Try parsing IP address from value %s but it does not match pattern IP[/mask]",
                        strVal.c_str());
            }
            L3Address addrVal(tokenized[0].c_str());
            if (addrVal.isUnspecified()) {
                throw cRuntimeError("Could not parse L3address from %s",
                        tokenized[0].c_str());
            }
            int prefixLength = 0;
            if (tokenized.size() == 2) {
                prefixLength = atoi(tokenized[1].c_str());
            } else if (addrVal.getType() == L3Address::AddressType::IPv4) {
                prefixLength = 32;
            } else if (addrVal.getType() == L3Address::AddressType::IPv6) {
                prefixLength = 128;
            }
            if (value.matches(addrVal, prefixLength)) {
                return true;
            }
        }
    }
    return false;
}

bool PacketProcessorBase::PacketFilter::matchesPacketIn(
        openflow::OFP_Packet_In* packet_in_msg) {
    //physical info
    //TODO check device id and in port
    //layer 2
    if (EthernetIIFrame* eth =
            dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket())) {
        if (matchesL3AddressValue("ethSrc", eth->getSrc())) {
            return true;
        }
        if (matchesL3AddressValue("ethDst", eth->getDest())) {
            return true;
        }
        if (matchesIntValue("etherType", eth->getEtherType())) {
            return true;
        }
        //qframe
        if (EthernetIIFrameWithQTag* vlan =
                dynamic_cast<EthernetIIFrameWithQTag *>(packet_in_msg->getEncapsulatedPacket())) {
            if (matchesIntValue("vlanId", vlan->getVID())) {
                return true;
            }
            if (matchesIntValue("vlanPcp", vlan->getPcp())) {
                return true;
            }
        }
        //layer 3
        if (INetworkDatagram* ip =
                dynamic_cast<INetworkDatagram *>(eth->getEncapsulatedPacket())) {
            int ipProto = ip->getTransportProtocol();
            if (matchesIntValue("ipProto", ipProto)) {
                return true;
            }
            if (matchesL3AddressValue("ipSrc", ip->getSourceAddress())) {
                return true;
            }
            if (matchesL3AddressValue("ipDst", ip->getDestinationAddress())) {
                return true;
            }
            //layer 4
            if (ITransportPacket* transport =
                    dynamic_cast<ITransportPacket*>(eth->getEncapsulatedPacket()->getEncapsulatedPacket())) {
                if (ipProto == IPProtocolId::IP_PROT_UDP) {
                    if (matchesIntValue("udpSrc", transport->getSourcePort())) {
                        return true;
                    }
                    if (matchesIntValue("udpDst",
                            transport->getDestinationPort())) {
                        return true;
                    }
                } else if (ipProto == IPProtocolId::IP_PROT_TCP) {
                    if (matchesIntValue("tcpSrc", transport->getSourcePort())) {
                        return true;
                    }
                    if (matchesIntValue("tcpDst",
                            transport->getDestinationPort())) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void PacketProcessorBase::initialize() {
    AbstractControllerApp::initialize();
    WATCH_LISTMAP(_whitelist);
    WATCH_LISTMAP(_blacklist);
}

void PacketProcessorBase::handleParameterChange(const char* parname) {
    AbstractControllerApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "flowModIdleTimeOut")) {
        _idleTimeout = par("flowModIdleTimeOut");
    }
    if (!parname || !strcmp(parname, "flowModHardTimeOut")) {
        _hardTimeout = par("flowModHardTimeOut");
    }
    if (!parname || !strcmp(parname, "packetFilterWhitelist")) {
        _whitelist.initializeFromPar(
                this->par("packetFilterWhitelist").stdstringValue());
    }
    if (!parname || !strcmp(parname, "packetfilterBlacklist")) {
        _blacklist.initializeFromPar(
                this->par("packetfilterBlacklist").stdstringValue());
    }
}

void PacketProcessorBase::receiveSignal(cComponent* src, simsignal_t id,
        cObject* obj, cObject* details) {
    if (id == PacketInSignalId) {
        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            if (!isFiltered(packet_in)) {
                processPacketIn(packet_in);
                emit(packetProcessedSignal,packet_in);
            } else {
                emit(packetFilteredSignal,packet_in);
            }
        }
    } else if (id == PacketFeatureReplySignalId) {
        if (Open_Flow_Message *msg = dynamic_cast<Open_Flow_Message *>(obj)) {
            //new switch registered check if we allready got a offline config for it.
            processSwitchConnection(controller->findSwitchInfoFor(msg));
        }
    } else {
        AbstractControllerApp::receiveSignal(src, id, obj, details);
    }
}

void PacketProcessorBase::finish() {
    AbstractControllerApp::finish();

    string filename = par("dumpConfig").stdstringValue();
    if (!filename.empty()) {
        ofstream file;
        file.open(filename.c_str(), ios::app);
        if (!file.is_open())
            throw cRuntimeError("Cannot open output file");
        file << stateToXML();
        file.close();
    }
}

bool PacketProcessorBase::isFiltered(openflow::OFP_Packet_In* packet_in_msg) {
    if (_whitelist.empty() || _whitelist.matchesPacketIn(packet_in_msg)) {
        if (_blacklist.empty() || !_blacklist.matchesPacketIn(packet_in_msg)) {
            return false;
        }
    }
    return true;
}

} /*end namespace SDN4CoRE*/
