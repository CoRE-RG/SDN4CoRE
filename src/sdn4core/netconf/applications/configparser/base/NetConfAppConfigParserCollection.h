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

#ifndef __SDN4CORE_NETCONFAPPCONFIGPARSERBASECOLLECTION_H_
#define __SDN4CORE_NETCONFAPPCONFIGPARSERBASECOLLECTION_H_

//Omnet
#include <omnetpp.h>
//STD
#include <map>
#include <string>
//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/base/Configuration_t.h>
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserBase.h>
#include <sdn4core/netconf/applications/base/NetConfApplicationBase.h>


using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Implements an XML parser for NetConf App configurations.
 * Uses all known implementations for Configurations to parse XML input
 * in the parsers vector @see(NetConfAppConfigParserIEEE8021Qbv)
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfAppConfigParserCollection {
public:
    /**
     * Create a list of NetConf app configurations from XML elements using the specific parsers.
     * @param configuresXML      The XML list to parse
     * @return  a list of configuration objects according to the XML for empty Configs and Filters a dummy object is used.
     */
    static std::vector<Configuration_t*> parseXMLConfigList(
            const cXMLElementList& configuresXML, bool executionTimeRequired = true);

    /**
     * Create a NetConf app configuration from an XML element using the specific parsers.
     * @param configureXML      The XML to parse
     * @return  a configuration object according to the XML for empty Config and Filter a dummy object is used.
     */
    static Configuration_t* parseXMLConfig(cXMLElement* configureXML,
            bool executionTimeRequired = true);

    /**
     * Create config data from XML.
     */
    static NetConfConfig* getConfigDataFor(cXMLElement* element);

    /**
     * Create config filter from XML.
     */
    static NetConfFilter* getConfigFilterFor(cXMLElement* element);

    /**
     * Create a list of NetConf app connections from XML elements.
     * @param connectionsXML      The XML to parse
     * @return  a list of connections objects according to the XML.
     */
    static std::vector<NetConfApplicationBase::Connection_t> parseXMLConnectionList(
            const cXMLElementList& connectionsXML, bool executionTimeRequired = true);

    /**
     * Create a NetConf app connection from an XML element.
     * @param element      The XML to parse
     * @return  a connections object according to the XML.
     */
    static NetConfApplicationBase::Connection_t parseXMLConnection(
            cXMLElement* element, bool executionTimeRequired = true);

private:
    /**
     * Available ConfigParsers
     */
    static std::map<std::string, NetConfAppConfigParserBase*> parsers;
};

};// namespace SDN4CoRE

#endif //__SDN4CORE_NETCONFAPPCONFIGPARSERBASECOLLECTION_H_
