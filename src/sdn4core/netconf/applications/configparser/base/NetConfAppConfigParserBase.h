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

#ifndef __SDN4CORE_NETCONFAPPCONFIGPARSERBASE_H_
#define __SDN4CORE_NETCONFAPPCONFIGPARSERBASE_H_

//Omnet
#include <omnetpp.h>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>
#include <sdn4core/netconf/datastructures/base/NetConfFilter.h>


using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Specifies the interface and base implementation of an XML parser
 * for a NetConf Applicaition Configuration
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfAppConfigParserBase {
public:
    /**
     * Create config data from XML.
     */
    virtual NetConfConfig* getConfigDataFor(cXMLElement* element) {
        return nullptr;
    }

    /**
     * Create config filter from XML.
     */
    virtual NetConfFilter* getConfigFilterFor(cXMLElement* element) {
        return nullptr;
    }
};

}  // namespace SDN4CoRE

#endif //__SDN4CORE_NETCONFAPPCONFIGPARSERBASE_H_
