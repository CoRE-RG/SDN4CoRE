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

#include <omnetpp.h>
#include <vector>
#include <string>

#include <sdn4core/netconf/datastructures/tcp/NetConfClientSessionInfoTCP.h>
#include "sdn4core/netconf/datastructures/base/NetConfConfig.h"
#include "sdn4core/netconf/datastructures/base/NetConfFilter.h"
#include "sdn4core/netconf/messages/NetConfCapability_m.h"
#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Contains the common interface of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfApplicationBase : public cSimpleModule
{
public:
    /**
     * Information on how and when to connect to server.
     */
    typedef enum ConfigurationState{
        ConfigurationStateWaiting = 0,
        ConfigurationStateScheduled = 1,
        ConfigurationStateRequested = 2,
        ConfigurationStateSuccess = 3,
        ConfigurationStateError = 4
    }ConfigurationState_t;

    /**
     * Configuration message type
     */
    typedef enum NetConfMessageType{
        NetConfMessageType_EditConfig = 0,//edit_config
        NetConfMessageType_GetConfig = 1,//get_config
        NetConfMessageType_CopyConfig = 2,//copy_config
    }NetConfMessageType_t;

    /**
     * Configurations to start at certain points in time.
     */
    class Configurations_t {
    public:
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
    };

    /**
     * Information on how and when to connect to server.
     */
    typedef enum ConnectionState{
        ConnectionStateWaiting = 0,
        ConnectionStateScheduled = 1,
        ConnectionStateRequested = 2,
        ConnectionStateEstablished = 3
    }ConnectionState_t;

    /**
     * Information on how and when to connect to server.
     */
    class Connections_t{
    public:
        /**
         * the local port
         */
        int localPort;
        /**
         * the server address to connect to
         */
        const char* remoteAddress;
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
        std::vector<Configurations_t*> configurations;
        /**
         * session_id
         */
        int session_id = -1;
    };

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    virtual int getConfigTypeFor(const char* type);

    /**
     * Create config data from XML.
     */
    virtual NetConfConfig* getConfigDataFor(cXMLElement* element);

    /**
     * Create config filter from XML.
     */
    virtual NetConfFilter* getConfigFilterFor(cXMLElement* element);

    /**
     * Schedules a self messsage for the next connection creation;
     */
    virtual void scheduleNextConnection();

    /**
     * Schedules a self messsage for the next connection creation;
     */
    virtual void scheduleNextConfigurationFor(Connections_t* connection);

    /**
     * Creates a NetConfHello message for the connection.
     * @param connection    the connection data.
     * @return the NetConfHello message
     */
    virtual NetConfHello* createHelloFor(Connections_t* connection);

    /**
     * Create an editconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_EditConfig message
     */
    virtual NetConfOperation_EditConfig* createEditConfigOperation(Configurations_t* config);

    /**
     * Create a getconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_GetConfig message
     */
    virtual NetConfOperation_GetConfig* createGetConfigOperation(Configurations_t* config);

    /**
     * Create a copyconfig configuration operation.
     * @param config the configuration details
     * @return the NetConfOperation_GetConfig message
     */
    virtual NetConfOperation_CopyConfig* createCopyConfigOperation(Configurations_t* config);

    /**
     * Creates a NetConfMessage_RPC message for a connection and the configuration at the given index
     * @param connection    the connection to use
     * @param index         configuration index to use
     * @return              the NetConfMessage_RPC message
     */
    virtual NetConfMessage_RPC* createNetConfRPCForConfiguration(Connections_t* connection, int index);

    /**
     * map the sessioninfo to a connection.
     */
    virtual Connections_t* mapSessionInfoToConnection(NetConfClientSessionInfoTCP* sessionInfo);

    /**
     * Fills in the control info parameters
     */
    virtual NetConfCtrlInfo* createControlInfo(int messageType, int sessionId,
            const char* messageId);

    /**
     * The connections for this application
     */
    std::vector<Connections_t> _connections;
};

}  // namespace SDN4CoRE

#endif
