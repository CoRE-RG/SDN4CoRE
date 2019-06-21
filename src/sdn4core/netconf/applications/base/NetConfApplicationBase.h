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


#include <sdn4core/netconf/datastructures/tcp/NetConfClientSessionInfoTCP.h>
#include "sdn4core/netconf/datastructures/base/NetConfConfig.h"
#include "sdn4core/netconf/messages/NetConfCapability_m.h"

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
     * Configurations to start at certain points in time.
     */
    class Configurations_t {
    public:
        /**
         * The time to execute the config
         */
        SimTime executeAt;

        /**
         * Configuration data to transmit
         */
        NetConfConfig data;

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
     */
    virtual NetConfHello* createHelloFor(Connections_t* connection);

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
     * The connections for this application
     */
    std::vector<Connections_t> _connections;
};

}  // namespace SDN4CoRE

#endif
