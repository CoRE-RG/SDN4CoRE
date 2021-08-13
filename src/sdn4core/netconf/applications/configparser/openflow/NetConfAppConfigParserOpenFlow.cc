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
#include <sdn4core/netconf/applications/configparser/openflow/NetConfAppConfigParserOpenFlow.h>


namespace SDN4CoRE {

NetConfConfig* NetConfAppConfigParserOpenFlow::getConfigDataFor(cXMLElement* element){

    OF_NetConfConfigFlowMod* configData = new OF_NetConfConfigFlowMod();
    cXMLElementList configsXML = element->getChildrenByTagName("config");

    for(cXMLElement* config: configsXML){

        OF_NetConfConfigFlowMod::OF_FlowTableConfig_t* tableConfig = new OF_NetConfConfigFlowMod::OF_FlowTableConfig_t();
        tableConfig->command = parseCommand(config->getAttribute("operation"));
        tableConfig->table_id = atoi(config->getAttribute("tableIndex"));

        for(cXMLElement* entry: config->getChildrenByTagName("flowEntry")){
            OF100_FlowTableEntry* tmp = new OF100_FlowTableEntry(entry);
            tableConfig->flowTableEntries.push_back(tmp);
        }
        if(tableConfig->flowTableEntries.empty()){
            throw cRuntimeError("No flow entries to change in flowtable config");
        }
        configData->addFlowTableConfig(tableConfig);
    }
    if(configData->getFlowTableConfigs().empty()){
        throw cRuntimeError("No configuration in flow table config data");
    }

    return dynamic_cast<NetConfConfig*> (configData);
}

OF_NetConfConfigFlowMod::commands NetConfAppConfigParserOpenFlow::parseCommand(const char* command){
    if(!strcmp(command, "ADD_FLOW")){
            return OF_NetConfConfigFlowMod::ADD_FLOW;
    }else if(!strcmp(command, "MODIFY_FLOW")){
            return OF_NetConfConfigFlowMod::MODIFY_FLOW;
    }else if(!strcmp(command, "MODIFY_STRICT_FLOW")){
            return OF_NetConfConfigFlowMod::MODIFY_STRICT_FLOW;
    }else if(!strcmp(command, "DELETE_FLOW")){
            return OF_NetConfConfigFlowMod::DELETE_FLOW;
    }else if(!strcmp(command, "DELETE_STRICT_FLOW")){
            return OF_NetConfConfigFlowMod::DELETE_STRICT_FLOW;
    }else if(!strcmp(command, "NO_ACTION")){
        return OF_NetConfConfigFlowMod::NO_ACTION;
    }else{
        throw cRuntimeError("OF_NetConfApplicationFlowMod: could not parse command attribute from XML");
    }
}
}
