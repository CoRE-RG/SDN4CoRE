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
#ifndef SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_MULTIPART_NETCONFAPPCONFIGPARSERMULTIPART_H_
#define SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_MULTIPART_NETCONFAPPCONFIGPARSERMULTIPART_H_

//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserBase.h>


namespace SDN4CoRE {

/**
 * Contains the Multipart switch specific implementation of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Tobias Haugg, for HAW Hamburg
 */
class NetConfAppConfigParserMultipart: public NetConfAppConfigParserBase{
public:
    /**
     * Create config data from XML.
     */
    virtual NetConfConfig* getConfigDataFor(cXMLElement* element) override;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_NETCONFAPPCONFIGPARSERMULTIPART_H_ */
