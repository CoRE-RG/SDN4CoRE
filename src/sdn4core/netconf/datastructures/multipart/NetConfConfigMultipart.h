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

#ifndef SDN4CORE_NETCONF_DATASTRUCTURES_MULTIPART_NETCONFCONFIGMULTIPART_H_
#define SDN4CORE_NETCONF_DATASTRUCTURES_MULTIPART_NETCONFCONFIGMULTIPART_H_

//STD
#include <vector>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>


namespace SDN4CoRE {


/**
 * Multipart configuration data to be transferred in NetConf sessions
 *
 * @author Tobias Haugg, for HAW Hamburg
 */
class NetConfConfigMultipart: public NetConfConfig{

public:
    NetConfConfigMultipart(){};

    virtual ~NetConfConfigMultipart();

    /**
     * copy constructor to support copy of config data.
     * @param old_obj   the config to copy
     */
    NetConfConfigMultipart (const NetConfConfigMultipart &old_obj);

    /**
     * Calculates the byte size of this config.
     * @return  the calculated byte size.
     */
    virtual unsigned int getByteSize() override;

    /**
     * overrides message duplication to use class specific copy.
     */
    virtual NetConfConfig_Base *dup() const override;

    /**
     * @returns a vector containing all stored NetConfConfigs
     */
    std::vector<NetConfConfig*> getConfigurations();

    /**
     * set the a list of configuration for a NetConfConfigMultipart
     * @param new_configs new list of configurations
     */
    void setConfigurations(std::vector<NetConfConfig*> new_configs);

    /**
     * adds a single configurations to the list of stored configurations
     * @param new_config
     */
    void addConfiguration(NetConfConfig* new_config);

protected:
    /**
     * list of nested configurations
     */
    std::vector<NetConfConfig*> _configs;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTRUCTURES_MULTIPART_NETCONFCONFIGMULTIPART_H_ */
