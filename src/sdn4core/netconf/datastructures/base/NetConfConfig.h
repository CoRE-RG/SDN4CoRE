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

#ifndef SDN4CORE_NETCONF_MESSAGES_NETCONFCONFIG_H_
#define SDN4CORE_NETCONF_MESSAGES_NETCONFCONFIG_H_

//SDN4CoRE
#include <sdn4core/netconf/messages/NetConfOperation_m.h>


namespace SDN4CoRE {

/**
 * Base class for all configuration data transferred in NetConf sessions.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfConfig : public NetConfConfig_Base{
public:
    NetConfConfig();
    virtual ~NetConfConfig();
    /**
     * copy constructor should be overritten to support copy of config data.
     * @param old_obj   the config to copy
     */
    NetConfConfig (const NetConfConfig &old_obj) : NetConfConfig_Base(old_obj) {
    };

    /**
     * Calculates the byte size of this config.
     * @return  the calculated byte size.
     */
    virtual unsigned int getByteSize();

    /**
     * overrides message duplication to use class specific copy.
     */
    virtual NetConfConfig_Base *dup() const override {return new NetConfConfig(*this);};
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_MESSAGES_NETCONFCONFIG_H_ */
