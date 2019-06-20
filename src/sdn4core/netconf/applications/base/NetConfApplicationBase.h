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
    typedef enum ConnectionState{
        ConnectionStateWaiting = 0,
        ConnectionStateScheduled = 1,
        ConnectionStateRequested = 2,
        ConnectionStateEstablished = 3
    }ConnectionState_t;
    /**
     * Information on how and when to connect to server.
     */
    typedef struct Connections{
        int localPort;
        const char* remoteAddress;
        int remotePort;
        SimTime connectAt;
        ConnectionState_t state;
    }Connections_t;

protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    /**
     * Schedules a self messsage for the next connection creation;
     */
    virtual void scheduleNextConnection();

    /**
     * Creates a NetConfHello message for the connection.
     * @param connection    the connection data.
     */
    virtual NetConfHello* createHelloFor(Connections_t* connection);

    /**
     * The connections for this application
     */
    std::vector<Connections_t> _connections;
};

}  // namespace SDN4CoRE

#endif
