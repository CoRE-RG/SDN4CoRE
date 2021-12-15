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

#ifndef SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_BASE_CONFIGURATION_T_H_
#define SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_BASE_CONFIGURATION_T_H_

//Omnet
#include <omnetpp.h>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfConfig.h>
#include <sdn4core/netconf/datastructures/base/NetConfFilter.h>


using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Configurations to start at certain points in time.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class Configuration_t {
public:
    ~Configuration_t(){
        if(this->data != nullptr){
            delete this->data;
        }
        if(this->filter != nullptr){
            delete this->filter;
        }
    }

    /**
     * Information on how and when to connect to server.
     */
    typedef enum ConfigurationState {
        ConfigurationStateWaiting = 0,
        ConfigurationStateScheduled = 1,
        ConfigurationStateRequested = 2,
        ConfigurationStateSuccess = 3,
        ConfigurationStateError = 4
    } ConfigurationState_t;

    static std::string connectionStateToString(ConfigurationState_t state) {
        switch(state) {
        case ConfigurationStateWaiting:
            return "Waiting";
        case ConfigurationStateScheduled:
            return "Scheduled";
        case ConfigurationStateRequested:
            return "Requested";
        case ConfigurationStateSuccess:
            return "Success";
        case ConfigurationStateError:
            return "Error";
        default: break;
        }
        return "Unknown";
    }

    /**
     * Configuration message type
     */
    typedef enum NetConfMessageType {
        NetConfMessageType_EditConfig = 0, //edit_config
        NetConfMessageType_GetConfig = 1, //get_config
        NetConfMessageType_CopyConfig = 2, //copy_config
        NetConfMessageType_DeleteConfig = 3, //delete_config
        NetConfMessageType_Lock = 4, //lock
        NetConfMessageType_Unlock = 5, //unlock
        NetConfMessageType_Commit = 6, //commit
    } NetConfMessageType_t;

    static std::string netconfMessageTypeToString(NetConfMessageType_t state) {
        switch(state) {
        case NetConfMessageType_EditConfig:
            return "edit_config";
        case NetConfMessageType_GetConfig:
            return "get_config";
        case NetConfMessageType_CopyConfig:
            return "copy_config";
        case NetConfMessageType_DeleteConfig:
            return "delete_config";
        case NetConfMessageType_Lock:
            return "lock";
        case NetConfMessageType_Unlock:
            return "unlock";
        case NetConfMessageType_Commit:
            return "commit";
        default: break;
        }
        return "Unknown";
    }

    static int getConfigTypeFor(const char* type) {
        if (!strcmp(type, "edit_config")) {
            return NetConfMessageType::NetConfMessageType_EditConfig;
        } else if (!strcmp(type, "get_config")) {
            return NetConfMessageType::NetConfMessageType_GetConfig;
        } else if (!strcmp(type, "copy_config")) {
            return NetConfMessageType::NetConfMessageType_CopyConfig;
        } else if (!strcmp(type, "delete_config")) {
            return NetConfMessageType::NetConfMessageType_DeleteConfig;
        } else if (!strcmp(type, "lock")){
            return NetConfMessageType::NetConfMessageType_Lock;
        } else if (!strcmp(type, "unlock")){
            return NetConfMessageType::NetConfMessageType_Unlock;
        } else if (!strcmp(type, "commit")){
            return NetConfMessageType::NetConfMessageType_Commit;
        }
        return -1;
    };

    /**
     * The time to execute the config
     */
    SimTime executeAt;

    /**
     * The target store.
     */
    std::string target;

    /**
     * The source store.
     */
    std::string source;

    /**
     * Configuration data to transmit
     */
    NetConfConfig* data;

    /**
     * Configuration filters to transmit
     */
    NetConfFilter* filter;

    /**
     * Type
     */
    NetConfMessageType_t type;

    /**
     * the state of this config
     */
    ConfigurationState_t state;

    friend std::ostream& operator<<(std::ostream& os, const Configuration_t& obj){
         os << "{executeAt=" << obj.executeAt;
         os << ", target=" << obj.target;
         os << ", source=" << obj.source;
//         os << ", data=" << obj.data;
//         os << ", filter=" << obj.filter;
         os << ", type=" << netconfMessageTypeToString(obj.type);
         os << ", state=" << connectionStateToString(obj.state);
         os << "}";
         return os;
    }
};


}

#endif /* SDN4CORE_NETCONF_APPLICATIONS_CONFIGPARSER_BASE_CONFIGURATION_T_H_ */
