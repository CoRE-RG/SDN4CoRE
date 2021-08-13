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

//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserCollection.h>
#include <sdn4core/netconf/applications/configparser/multipart/NetConfAppConfigParserMultipart.h>
#include <sdn4core/netconf/datastructures/multipart/NetConfConfigMultipart.h>


namespace SDN4CoRE {

NetConfConfig* SDN4CoRE::NetConfAppConfigParserMultipart::getConfigDataFor( cXMLElement* element) {
    cXMLElementList configuresXML = element->getChildrenByTagName("configure");
    NetConfConfigMultipart* multiPartConfig = new NetConfConfigMultipart();
    for (auto configureXML : configuresXML) {
        if(auto newConfig = NetConfAppConfigParserCollection::getConfigDataFor(configureXML)){
            multiPartConfig->addConfiguration(newConfig);
        }else{
            throw new cRuntimeError("NetConfAppConfigParserMultipart: unknown config");
        }
    }
    return multiPartConfig;
}

} /* namespace SDN4CoRE */

