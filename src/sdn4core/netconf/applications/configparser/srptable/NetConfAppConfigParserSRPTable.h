//
// c Tobias Haugg, for HAW Hamburg
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
#ifndef SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_SRPTABLE_NETCONFAPPCONFIGPARSERSRPTABLE_H_
#define SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_SRPTABLE_NETCONFAPPCONFIGPARSERSRPTABLE_H_

//STD
#include <unordered_map>
#include <string>
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserBase.h>


namespace SDN4CoRE {

/**
 * Contains the SRP switch specific implementation of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Tobias Haugg, for HAW Hamburg
 */
class NetConfAppConfigParserSRPTable: public NetConfAppConfigParserBase{
public:
    /**
     * Create config data from XML.
     */
    virtual NetConfConfig* getConfigDataFor(cXMLElement* element) override;
private:
    /**
     * map used to convert from string to enum values of type SR_CLASS
     */
    std::unordered_map<std::string,CoRE4INET::SR_CLASS> stringToEnum{
        {std::string("A"),CoRE4INET::SR_CLASS::A},
        {std::string("B"),CoRE4INET::SR_CLASS::B},
    };
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_SRPTABLE_NETCONFAPPCONFIGPARSERSRPTABLE_H_ */
