//
// c Mohammad Fazel Soltani, Timo Haeckel, for HAW Hamburg
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

#ifndef SDN4CORE_NETCONF_DATASTRUCTURES_TRANSACTIONMODEL_NETCONFCONFIGCOMMITTIMESTAMP_H_
#define SDN4CORE_NETCONF_DATASTRUCTURES_TRANSACTIONMODEL_NETCONFCONFIGCOMMITTIMESTAMP_H_

//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>


namespace SDN4CoRE {

/**
 * Commit time stamp data to be transferred in NetConf sessionsn.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfConfigCommitTimestamp: public NetConfConfig{
public:
    typedef struct CommitTimestamp_t{
        /**
         * cycle as commit timestamp
         */
        uint32_t cycle;
        size_t period;
        double time;
        bool executeAtStartOfPeriod;

        friend std::ostream& operator<<(std::ostream& os, const CommitTimestamp_t& obj){
             os<<"{cycle="<<obj.cycle<<", period="<<obj.period<<", time="<<obj.time<<", executeAtStartOfPeriod="<<std::boolalpha<<obj.executeAtStartOfPeriod<<"}";
             return os;
        }

    }CommitTimestamp_t;
public:
    NetConfConfigCommitTimestamp();
    virtual ~NetConfConfigCommitTimestamp();
    /**
     * copy constructor to support copy of config data.
     * @param old_obj   the config to copy
     */
    NetConfConfigCommitTimestamp (const NetConfConfigCommitTimestamp &old_obj):NetConfConfig(old_obj) {
        this->_timestamp = old_obj._timestamp;
    };

    /**
     * Calculates the byte size of this config.
     * @return  the calculated byte size.
     */
    virtual unsigned int getByteSize() override;

    CommitTimestamp_t& getCommitTimestamp();
    void setCommitTimestamp(CommitTimestamp_t& timestamp);

    /**
     * overrides message duplication to use class specific copy.
     */
    virtual NetConfConfig_Base *dup() const override {return new NetConfConfigCommitTimestamp(*this);};
protected:
    CommitTimestamp_t _timestamp;
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_DATASTRUCTURES_TRANSACTIONMODEL_NETCONFCONFIGCOMMITTIMESTAMP_H_ */
