//
// c Timo Haeckel, for HAW Hamburg
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

#include "NetConfAppConfigParserCollection.h"
//STD
#include <algorithm>
//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/openflow/NetConfAppConfigParserOpenFlow.h>
#include <sdn4core/netconf/applications/configparser/ieee8021qbv/NetConfAppConfigParserIEEE8021Qbv.h>
#include <sdn4core/netconf/applications/configparser/multipart/NetConfAppConfigParserMultipart.h>
#include <sdn4core/netconf/applications/configparser/srptable/NetConfAppConfigParserSRPTable.h>
#include <sdn4core/utility/xml/XMLUtility.h>


using namespace std;

namespace SDN4CoRE {

// All key strings have to be in lower case!!!
map<string, NetConfAppConfigParserBase*> NetConfAppConfigParserCollection::parsers =
        { {"ieee8021qbv", new NetConfAppConfigParserIEEE8021Qbv()},
                {"openflow", new NetConfAppConfigParserOpenFlow()},
                {"multipart", new NetConfAppConfigParserMultipart()},
                {"srptable", new NetConfAppConfigParserSRPTable()}};

vector<Configuration_t*> NetConfAppConfigParserCollection::parseXMLConfigList(
        const cXMLElementList& configuresXML, bool executionTimeRequired) {
    vector<Configuration_t*> configurations;

    for (auto configureXML : configuresXML) {
        Configuration_t* config = parseXMLConfig(configureXML, executionTimeRequired);
        if (config) {
            configurations.push_back(config);
        } else {
            throw cRuntimeError(
                    "Could not parse XML input for Controller Application");
        }
    }
    return configurations;
}

Configuration_t* NetConfAppConfigParserCollection::parseXMLConfig(
        cXMLElement* configureXML, bool executionTimeRequired) {
    Configuration_t* config = nullptr;
    double executeAt = getDoubleAttributeFromXML(configureXML,"at",executionTimeRequired, SimTime::ZERO.dbl());
    Configuration_t::NetConfMessageType_t configType =
            static_cast<Configuration_t::NetConfMessageType_t> (Configuration_t::getConfigTypeFor(
            getStringAttributeFromXML(configureXML, "type").c_str()));
    if (configType >= 0) {
        config = new Configuration_t();
        config->executeAt = executeAt;
        config->type = configType;
        config->state =
                Configuration_t::ConfigurationState_t::ConfigurationStateWaiting;
        switch (config->type) {
        case Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig:
            config->data = getConfigDataFor(configureXML);
            config->filter = getConfigFilterFor(configureXML);
            config->target = getStringAttributeFromXML(configureXML, "target", false, "running");
            break;
        case Configuration_t::NetConfMessageType_t::NetConfMessageType_GetConfig:
            config->filter = getConfigFilterFor(configureXML);
            config->target = getStringAttributeFromXML(configureXML, "target", false, "running");
            break;
        case Configuration_t::NetConfMessageType_t::NetConfMessageType_CopyConfig:
            config->target = getStringAttributeFromXML(configureXML, "target", false, "candidate");
            config->source = getStringAttributeFromXML(configureXML, "source", false, "running");
            break;
        case Configuration_t::NetConfMessageType_t::NetConfMessageType_DeleteConfig:
            config->target = getStringAttributeFromXML(configureXML, "target");
            break;
        case Configuration_t::NetConfMessageType_t::NetConfMessageType_Lock:
            config->target = getStringAttributeFromXML(configureXML, "target");
            break;
        case Configuration_t::NetConfMessageType_t::NetConfMessageType_Unlock:
            config->target = getStringAttributeFromXML(configureXML, "target");
            break;
        default:
            break;
        }
    }
    return config;
}

NetConfConfig* NetConfAppConfigParserCollection::getConfigDataFor(
        cXMLElement* element) {
    NetConfConfig* config = nullptr;
    const char* module = element->getAttribute("module");
    if (module) {
        string configType = module;
        transform(configType.begin(), configType.end(), configType.begin(), ::tolower);
        auto parser = parsers.find(configType);
        if (parser != parsers.end()) {
            config = parser->second->getConfigDataFor(element);
            if (!config) {
                throw cRuntimeError("Config parser %s returned null element", configType.c_str());
            }
        } else {
            throw cRuntimeError("Unknown XML Parser type %s", configType.c_str());
        }
    } else {
        config = new NetConfConfig();
    }
    return config;
}

NetConfFilter* NetConfAppConfigParserCollection::getConfigFilterFor(
        cXMLElement* element) {
//    NetConfFilter* filter = nullptr;
//    const char* filterType = element->getAttribute("module");
//    if (filterType) {
//        auto parser = parsers.find(filterType);
//        if (parser != parsers.end()) {
//            filter = parser->second->getConfigFilterFor(element);
//            if (!filter) {
//                throw cRuntimeError("Filter parser %s returned null element", filterType);
//            }
//        } else {
//            throw cRuntimeError("Unknown XML Parser type %s", filterType);
//        }
//    } else {
//        filter = new NetConfFilter();
//    }
    return new NetConfFilter();
}

vector<NetConfApplicationBase::Connection_t> NetConfAppConfigParserCollection::parseXMLConnectionList(
        const cXMLElementList& connectionsXML, bool executionTimeRequired) {
    vector<NetConfApplicationBase::Connection_t> connections;
    for (size_t i = 0; i < connectionsXML.size(); i++) {
        connections.push_back(parseXMLConnection(connectionsXML[i], executionTimeRequired));
    }
    return connections;
}

NetConfApplicationBase::Connection_t NetConfAppConfigParserCollection::parseXMLConnection(
        cXMLElement* element, bool executionTimeRequired) {
    NetConfApplicationBase::Connection_t connection;
    connection.localPort = getIntAttributeFromXML(element,"local_port");
    connection.remoteAddress = getStringAttributeFromXML(element,"remote_address");
    connection.remotePort = getIntAttributeFromXML(element,"remote_port");
    connection.connectAt = getDoubleAttributeFromXML(element,"connect_at", executionTimeRequired, SimTime::ZERO.dbl());
    connection.state = NetConfApplicationBase::ConnectionState_t::ConnectionStateWaiting;
    // check if there are any configurations.
    connection.configurations = parseXMLConfigList(element->getChildrenByTagName("configure"), executionTimeRequired);
    return connection;
}

}  // namespace SDN4CoRE

