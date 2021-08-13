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
#ifndef SDN4CORE_NETCONF_DATASTRUCTURES_SRP_NETCONFCONFIGSRP_H_
#define SDN4CORE_NETCONF_DATASTRUCTURES_SRP_NETCONFCONFIGSRP_H_

//STD
#include <vector>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>
//CoRE4INET
#include <core4inet/services/avb/SRP/SRPTable.h>


namespace SDN4CoRE {

/**
 * SRP configuration data to be transferred in NetConf sessions
 *
 * @author Tobias Haugg, for HAW Hamburg
 */
class NetConfConfigSRP: public  NetConfConfig{

public:
    NetConfConfigSRP(){};
    virtual ~NetConfConfigSRP(){};

    /**
     * copy constructor to support copy of config data.
     * @param old_obj   the config to copy
     */
    NetConfConfigSRP (const NetConfConfigSRP &old_obj);

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
     * set's the list of all TalkerEntries that should be configured
     * @param talkers list of talkers
     */
    void setTalkerEntries(std::vector<CoRE4INET::SRPTable::TalkerEntry> talkers);

    /**
     * set's the list of all ListenerEntries that should be configured
     * @param listeners list of listeners
     */
    void setListenerEntries(std::vector<CoRE4INET::SRPTable::ListenerEntry> listeners);

    /**
     * @returns a list containing all TalkerEntries that should be configured
     */
    std::vector<CoRE4INET::SRPTable::TalkerEntry> getTalkerEntries();

    /**
     * @returns a list containing all ListenerEntries that should be configured
     */
    std::vector<CoRE4INET::SRPTable::ListenerEntry> getListenerEntries();

    /**
     * adds a TalkerEntry to the list of TalkerEntries that should be configured
     */
    void addTalkerEntry(CoRE4INET::SRPTable::TalkerEntry talker);

    /**
     * adds a ListenerEntry to the list of ListenerEntry that should be configured
     */
    void addListenerEntry(CoRE4INET::SRPTable::ListenerEntry listener);


private:
    /**
     * TalkerEntries that should be configured
     */
    std::vector<CoRE4INET::SRPTable::TalkerEntry> _talkers;
    /**
     * ListenerEntries that should be configured
     */
    std::vector<CoRE4INET::SRPTable::ListenerEntry> _listeners;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTRUCTURES_SRP_NETCONFCONFIGSRP_H_ */
