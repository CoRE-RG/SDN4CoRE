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

#ifndef __SDN4CORE_NETCONFAPPLICATIONBASE_H_
#define __SDN4CORE_NETCONFAPPLICATIONBASE_H_

//OMNENT
#include <omnetpp.h>
//STD
#include <vector>
#include <string>
//SDN4CoRE
#include <sdn4core/netconf/applications/configparser/base/Configuration_t.h>
#include <sdn4core/netconf/datastructures/tcp/NetConfClientSessionInfoTCP.h>
#include "sdn4core/netconf/messages/NetConfCapability_m.h"
#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"

using namespace omnetpp;

namespace SDN4CoRE {

#define SELFMESSAGE_SEND_HELLO "Send Hello"

/**
 * Contains the common interface of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfApplicationBase: public cSimpleModule {
public:

    /**
     * Information on how and when to connect to server.
     */
    typedef enum ConnectionState {
        ConnectionStateWaiting = 0,
        ConnectionStateScheduled = 1,
        ConnectionStateRequested = 2,
        ConnectionStateEstablished = 3
    } ConnectionState_t;

    static std::string connectionStateToString(ConnectionState_t state) {
        switch(state) {
        case ConnectionStateWaiting:
            return "Waiting";
        case ConnectionStateScheduled:
            return "Scheduled";
        case ConnectionStateRequested:
            return "Requested";
        case ConnectionStateEstablished:
            return "Established";
        default: break;
        }
        return "Unknown";
    }

    /**
     * Information on how and when to connect to server.
     */
    class Connection_t {
    public:
        /**
         * the local port
         */
        int localPort;
        /**
         * the server address to connect to
         */
        std::string remoteAddress;
        /**
         * the netconf port at the server (usually 830)
         */
        int remotePort;
        /**
         * the time at which the app connects to the server
         */
        SimTime connectAt;
        /**
         * the state of this connection @see ~ConnectionState_t.
         */
        ConnectionState_t state;
        /**
         * Configurations to make at a certain time.
         */
        std::vector<Configuration_t*> configurations;
        /**
         * session_id
         */
        int session_id = -1;

        friend std::ostream& operator<<(std::ostream& os, const Connection_t& obj){
             os << "{localPort=" << obj.localPort;
             os << ", remoteAddress=" << obj.remoteAddress;
             os << ", remotePort=" << obj.remotePort;
             os << ", connectAt=" << obj.connectAt;
             os << ", state=" << connectionStateToString(obj.state);
             os << ", configurations=[";
             int count = 0;
             for (auto config : obj.configurations) {
                 if(count>0) {
                     os << ", ";
                 }
                 os << (*config);
                 count++;
             }
             os << "]";
             os << ", session_id=" << obj.session_id;
             os << "}";
             return os;
        }
    };

    virtual ~NetConfApplicationBase();

    void setConnnections(std::vector<Connection_t>& connections);
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    /**
     * Schedules a self messsage for the next connection creation;
     */
    virtual bool scheduleNextConnection();

    /**
     * Schedules a self messsage for the next connection creation;
     */
    virtual bool scheduleNextConfigurationFor(Connection_t* connection);

    /**
     * Creates a NetConfHello message for the connection.
     * @param connection    the connection data.
     * @return the NetConfHello message
     */
    virtual NetConfHello* createHelloFor(Connection_t* connection);

    /**
     * Create an editconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_EditConfig message
     */
    virtual NetConfOperation_EditConfig* createEditConfigOperation(
            Configuration_t* config);

    /**
     * Create a getconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_GetConfig message
     */
    virtual NetConfOperation_GetConfig* createGetConfigOperation(
            Configuration_t* config);

    /**
     * Create a copyconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_CopyConfig message
     */
    virtual NetConfOperation_CopyConfig* createCopyConfigOperation(
            Configuration_t* config);

    /**
     * Create a copyconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_DeleteConfig message
     */
    virtual NetConfOperation_DeleteConfig* createDeleteConfigOperation(
            Configuration_t* config);

    /**
     * Create a lock configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_Lock message
     */
    virtual NetConfOperation_Lock* createLockOperation(
            Configuration_t* config);

    /**
     * Create a unlock configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_Unlock message
     */
    virtual NetConfOperation_Unlock* createUnlockOperation(
            Configuration_t* config);

    /**
     * Create a commit configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_Commit message
     */
    virtual NetConfOperation_Commit* createCommitOperation(
            Configuration_t* config);

    /**
     * Creates a NetConfMessage_RPC message for a connection and the configuration at the given index
     * @param connection    the connection to use
     * @param config        configuration to be created
     * @param message_id    the identifier of the configuration message
     * @return              the NetConfMessage_RPC message
     */
    virtual NetConfMessage_RPC* createNetConfRPCForConfiguration(
            Connection_t* connection, Configuration_t* config,
            std::string message_id);

    /**
     * map the sessioninfo to a connection.
     * todo not use TCP specific info if not required.
     */
    virtual Connection_t* mapSessionInfoToConnection(
            NetConfClientSessionInfoTCP* sessionInfo);

    /**
     * Fills in the control info parameters
     */
    virtual NetConfCtrlInfo* createControlInfo(int messageType, int sessionId,
            const char* messageId);

    /**
     * The connections for this application
     */
    std::vector<Connection_t> _connections;
};

}  // namespace SDN4CoRE

#endif
