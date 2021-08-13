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

#ifndef SDN4CORE_NETCONF_DATASTRUCTURES_OPENFLOW_OF_NETCONFCONFIGOPENFLOW_H_
#define SDN4CORE_NETCONF_DATASTRUCTURES_OPENFLOW_OF_NETCONFCONFIGOPENFLOW_H_

//STD
#include <vector>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>
//OpenFlow
#include "openflow/openflow/switch/flowtable/OF100_FlowTableEntry.h"


using namespace openflow;

namespace SDN4CoRE {


/**
 * FlowMod configuration data to be transferred in NetConf sessions
 *
 * @author Tobias Haugg, for HAW Hamburg
 */
class OF_NetConfConfigFlowMod : public NetConfConfig {
public:

    //OpenFlow commands
    enum commands{
        ADD_FLOW,
        MODIFY_FLOW,
        MODIFY_STRICT_FLOW,
        DELETE_FLOW,
        DELETE_STRICT_FLOW,
        NO_ACTION
    };
    typedef struct OF_FlowTableConfig{
        //OpenFlow Command
        commands command;

        //ID of the flowtable to be altert
        uint8_t table_id;

        //new flowtable entry
        std::vector<OF100_FlowTableEntry*> flowTableEntries;

    }OF_FlowTableConfig_t;

public:
    OF_NetConfConfigFlowMod();
    ~OF_NetConfConfigFlowMod();
    /**
     * copy constructor to support copy of config data.
     * @param old_obj   the config to copy
     */
    OF_NetConfConfigFlowMod(const OF_NetConfConfigFlowMod &old_obj);
    /**
     * Calculates the byte size of this config.
     * @return  the calculated byte size.
     */
    unsigned int getByteSize()override;
    /**
     * overrides message duplication to use class specific copy.
     */
    virtual NetConfConfig_Base *dup() const override;
    /**
     * adds a OF_FlowTableConfig_t to the flowTableConfigs (the list of flow tables that will be edited)
     * @param  flowTableConfig
     */
    void addFlowTableConfig(OF_FlowTableConfig_t* flowTableConfig);
    /**
     * adds a OF_FlowTableConfig_t to the flowTableConfigs (the list of flow tables that will be edited)
     * @param  flowTableConfig
     */
    void setFlowTableConfigs(std::vector<OF_FlowTableConfig_t*> flowTableConfigs);
   /**
    * return all flow flowTableConfigs
    */
   std::vector<OF_FlowTableConfig_t*> getFlowTableConfigs();

protected:
    /**
     *  open flow flowMod configuration
     */
    std::vector<OF_FlowTableConfig_t*> flowTableConfigs;
};

}

#endif /* SDN4CORE_NETCONF_DATASTRUCTURES_OPENFLOW_OF_NETCONFCONFIGOPENFLOW_H_ */
