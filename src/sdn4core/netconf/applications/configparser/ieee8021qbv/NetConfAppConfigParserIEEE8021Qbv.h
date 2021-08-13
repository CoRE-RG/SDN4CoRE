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

#ifndef __SDN4CORE_NETCONFAPPCONFIGPARSERIEEE8021QBV_H_
#define __SDN4CORE_NETCONFAPPCONFIGPARSERIEEE8021QBV_H_

//Omnet
#include <omnetpp.h>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/ieee8021qbv/NetConfConfigIEEE8021Qbv.h>
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserBase.h>


using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Contains the IEEE8021Qbv switch specific implementation of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfAppConfigParserIEEE8021Qbv: public NetConfAppConfigParserBase {
public:
    /**
     * Create config data from XML.
     */
    virtual NetConfConfig* getConfigDataFor(cXMLElement* element) override {
        NetConfConfigIEEE8021Qbv* configData = new NetConfConfigIEEE8021Qbv();
        cXMLElementList configsXML = element->getChildrenByTagName("config");
        for (auto configXML : configsXML) {
            const char* portC = configXML->getAttribute("port");
            const char* gateControlList = configXML->getAttribute(
                    "gatecontrollist");

            if (portC && gateControlList) {
                NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t* gateConfig =
                        new NetConfConfigIEEE8021Qbv::IEEE8021QbvGateConfig_t();
                gateConfig->port = atoi(portC);
                gateConfig->gateControlList = gateControlList;
                configData->setGateConfiguration(gateConfig);
            }
        }
        return dynamic_cast<NetConfConfig*>(configData);
    }
};
}  // namespace SDN4CoRE

#endif //__SDN4CORE_NETCONFAPPCONFIGPARSERIEEE8021QBV_H_
