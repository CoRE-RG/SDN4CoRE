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

//Openflow
#include "openflow/openflow/switch/flowtable/OF_FlowTableEntry.h"
//SDN4CoRE
#include <sdn4core/netconf/datastores/config/openflow/NetConfDataConfiguratorFlowTable.h>
#include <sdn4core/netconf/datastructures/openflow/OF_NetConfConfigFlowMod.h>


using namespace openflow;
using namespace std;

namespace SDN4CoRE {

Define_Module(NetConfDataConfiguratorFlowTable);

void NetConfDataConfiguratorFlowTable::initialize(){
    NetConfDataConfiguratorBase::initialize();

    //load table modules.
    int numFlowTables = getParentModule()->getParentModule()->getSubmodule("flowTables",0)->getVectorSize();
    for (int i = 0; i < numFlowTables; i++) {
        OF_FlowTable* table = dynamic_cast<OF_FlowTable*> (getParentModule()->getParentModule()->getSubmodule("flowTables",i));
        if(table){
            _flowTables.push_back(table);
        }
    }
}

NetConfConfig *NetConfDataConfiguratorFlowTable::getConfig(NetConfFilter& filter){

    OF_NetConfConfigFlowMod* config = new OF_NetConfConfigFlowMod();
    for(int i = 0; i< _flowTables.size(); i++){

       auto tableConfig = new OF_NetConfConfigFlowMod::OF_FlowTableConfig_t();
        tableConfig->command = OF_NetConfConfigFlowMod::NO_ACTION;
        tableConfig->table_id = i;

        vector<OF_FlowTableEntry*> entries =_flowTables[i]->getEntrys();
        for( auto entry : entries){
            if(auto tmp = dynamic_cast<OF100_FlowTableEntry*>(entry)){
                tableConfig->flowTableEntries.push_back(tmp);
            }else{
                throw cRuntimeError("NetConfConfigFlowMod: wrong flowEntry type, expected OF100_FlowTableEntry*");
            }
        }
        config->addFlowTableConfig( tableConfig);
    }
    return (NetConfConfig*)config;
}

bool NetConfDataConfiguratorFlowTable::editConfig(int defaultOperation, int errorOption, NetConfConfig* config) {
    Enter_Method("editConfig()");
    bool status = false;

    if(OF_NetConfConfigFlowMod* flowMod = dynamic_cast<OF_NetConfConfigFlowMod*>(config)){
        for(auto flowTableConfig : flowMod->getFlowTableConfigs()){

            for(OF100_FlowTableEntry* entry: flowTableConfig->flowTableEntries){
                oxm_basic_match match = entry->getMatch();

                switch(flowTableConfig->command){
                    case OF_NetConfConfigFlowMod::ADD_FLOW:
                        status = _flowTables[flowTableConfig->table_id]->addEntry(entry);
                        break;
                    case OF_NetConfConfigFlowMod::MODIFY_FLOW:
                        _flowTables[flowTableConfig->table_id]->deleteMatchingEntries(match);
                        status = _flowTables[flowTableConfig->table_id]->addEntry(entry);
                        break;
                    case OF_NetConfConfigFlowMod::DELETE_FLOW:
                        _flowTables[flowTableConfig->table_id]->deleteMatchingEntries(match);
                        status = true;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    if(status){
        emit(editConfigOkSignal, 1L);
    }else{
        emit(editConfigErrorSignal, 1L);
    }
    return status;
}

bool NetConfDataConfiguratorFlowTable::validateConfig( NetConfConfig* config, int defaultOperationg) {
   Enter_Method("validateConfig()");
   bool status = false;

   if(OF_NetConfConfigFlowMod* flowMod = dynamic_cast<OF_NetConfConfigFlowMod*>(config)){
       for(auto flowTableConfig : flowMod->getFlowTableConfigs()){

           for(int i=0; i < flowTableConfig->flowTableEntries.size(); i++){

               switch(flowTableConfig->command){
                   case OF_NetConfConfigFlowMod::ADD_FLOW:
                       status = true;
                       break;
                   case OF_NetConfConfigFlowMod::MODIFY_FLOW:
                       status = true;
                       break;
                   case OF_NetConfConfigFlowMod::DELETE_FLOW:
                       status = true;
                       break;
                   default:
                       break;
               }
           }
       }
   }
   return status;
}

}
