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

//STD
#include <string>
//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/srptable/NetConfAppConfigParserSRPTable.h>
#include <sdn4core/netconf/datastructures/srp/NetConfConfigSRP.h>
#include <core4inet/services/avb/SRP/SRPTable.h>


using namespace std;

namespace SDN4CoRE {

NetConfConfig* SDN4CoRE::NetConfAppConfigParserSRPTable::getConfigDataFor( cXMLElement* element) {
    NetConfConfigSRP* configData = new NetConfConfigSRP();
    cXMLElement* configsXML = element->getFirstChildWithTag("config");

    for(cXMLElement* config: configsXML->getChildren()){
        uint64_t streamID   = atoi(config->getAttribute("stream_id"));
        uint64_t vlanID     = atoi(config->getAttribute("vlan_id"));
        cModule* module      = getSimulation()->getModuleByPath(config->getAttribute("module"));
        string tagName = config->getTagName();


        if( tagName == string("talkerEntry")){

           CoRE4INET::SRPTable::TalkerEntry talker;

           talker.streamId = streamID;
           talker.vlan_id = vlanID;
           talker.srClass = stringToEnum[string(config->getAttribute("srClass"))];
           talker.address = inet::MACAddress(config->getAttribute("address"));
           talker.module = module;
           talker.framesize = atoi(config->getAttribute("framesize"));
           talker.intervalFrames = atoi(config->getAttribute("intervalFrames"));
           talker.pcp = atoi(config->getAttribute("pcp"));

           configData->addTalkerEntry(talker);
        }else if( tagName == string("listenerEntry")){

            CoRE4INET::SRPTable::ListenerEntry listener;

            listener.streamId = streamID;
            listener.vlan_id = vlanID;
            listener.module = module;
            configData->addListenerEntry(listener);
        }
    }
    return configData;
}

} /* namespace SDN4CoRE */
