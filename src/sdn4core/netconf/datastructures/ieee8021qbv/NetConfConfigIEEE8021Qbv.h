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

#ifndef SDN4CORE_NETCONF_DATASTRUCTURES_IEEE8021QBV_NETCONFCONFIGIEEE8021QBV_H_
#define SDN4CORE_NETCONF_DATASTRUCTURES_IEEE8021QBV_NETCONFCONFIGIEEE8021QBV_H_

//STD
#include <string>
#include <vector>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>


namespace SDN4CoRE {


/**
 * IEEE8021Qbv configuration data to be transferred in NetConf sessions
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfConfigIEEE8021Qbv: public NetConfConfig {
public:
    typedef struct IEEE8021QbvGateConfig {
        /**
         * The number of the port in the IEEE8021Q device
         */
        int port;
        /**
         * Contains the GateControllist used in @see~IEEE8021QbvGateControlList
         * GateStatus:
         *      C == close
         *      o == open
         * EntryDuration: in seconds
         * Format GateStatus,GateStatus,...,GateStatus:EntryDuration
         * Example: "C,o,o,o,o,o,o,o:0.0001;o,C,o,o,o,o,o,o:0.0001"
         */
        std::string gateControlList;

    }IEEE8021QbvGateConfig_t;

public:
    NetConfConfigIEEE8021Qbv();
    virtual ~NetConfConfigIEEE8021Qbv();
    /**
     * copy constructor to support copy of config data.
     * @param old_obj   the config to copy
     */
    NetConfConfigIEEE8021Qbv (const NetConfConfigIEEE8021Qbv &old_obj):NetConfConfig(old_obj) {
        for(auto gateConfig: old_obj._gateConfigurations){
            this->_gateConfigurations.push_back(new IEEE8021QbvGateConfig_t(*gateConfig));
        }
    };

    /**
     * Calculates the byte size of this config.
     * @return  the calculated byte size.
     */
    virtual unsigned int getByteSize() override;

    /**
     * Finds the gate configuration for a specific port.
     * @param port  this port to look for
     * @return      the IEEE8021QbvGateConfig_t of the port if found, else null
     */
    IEEE8021QbvGateConfig_t* getGateConfigurationForPort(int port);

    /**
     * Replaces the current config or inserts a new config for the port used in config
     * @param config    the config to insert
     */
    void setGateConfiguration(IEEE8021QbvGateConfig_t* config);

    const std::vector<IEEE8021QbvGateConfig_t*>& getGateConfigurations() const {
        return _gateConfigurations;
    }

    void setGateConfigurations(
            const std::vector<IEEE8021QbvGateConfig_t*>& gateConfigurations) {
        _gateConfigurations = gateConfigurations;
    }

    /**
     * overrides message duplication to use class specific copy.
     */
    virtual NetConfConfig_Base *dup() const override {return new NetConfConfigIEEE8021Qbv(*this);};

protected:
    std::vector<IEEE8021QbvGateConfig_t*> _gateConfigurations;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTRUCTURES_IEEE8021QBV_NETCONFCONFIGIEEE8021QBV_H_ */
