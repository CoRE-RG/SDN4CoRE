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

#ifndef __SDN4CORE_NETCONFCLIENTBASE_H_
#define __SDN4CORE_NETCONFCLIENTBASE_H_

#include <omnetpp.h>
#include <sdn4core/netconf/datastructures/base/NetConfClientSessionInfo.h>
#include <vector>

#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"
#include "sdn4core/netconf/messages/NetConfCapability_m.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Contains the basic implementation of a NetConf client.
 * This module can be connected to any Transport protocol that should be of
 * "Connection-Oriented Operation" and should provide "Authentication,
 * Integrity, and Confidentiality" as specified in Network Configuration
 * Protocol (NETCONF) RFC6241.
 *
 * All responses will be forwarded to the applicaitonOut gate with the
 * same index as the arriving applicationIn gate
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfClientBase : public cSimpleModule
{
  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    /**
     * Forwards the message to the protocol specific transport layer.
     * The NetConfCtrlInfo_Transport should be attached to the message.
     * @param msg   the message to forward
     */
    virtual void sendToTransport(cMessage* msg) = 0;

    /**
     * Protocol specific implementation to open a new session.
     * Checks if the session already exists, else opens a new one and adds the _nextSessionId
     * Must insert the new session into the _openSessions list.
     * @param msg   the message to create a session for
     */

    /**
     * Protocol specific implementation to open a new session.
     * Checks if the session already exists, else opens a new one.
     * Must insert the new session into the _openSessions list.
     * @param hello   the NetConfHello to create a session for NetConfHello
     * @return        the session info for the new session.
     */
    virtual NetConfClientSessionInfo* openNewSession(NetConfHello* hello) = 0;

    /**
     * Closes the protocol specific session and removes the session from openSessions list.
     * @param sessionId    the session to close
     * @return              true if the session was closed
     */
    virtual bool closeSession(int sessionId) = 0;

    /**
     * Finds the session info for an incoming message.
     * @param msg   the message of a session
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfClientSessionInfo* findSessionInfoForMsg(cMessage *msg) = 0;

    /**
     * Finds the session info for an existing session id.
     * @param sessionId   the id of the session to find
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfClientSessionInfo* findSessionInfoForId(int sessionId);

    /**
     * Sends the Hello
     * @param hello the incoming hello message
     */
    virtual void sendHello(NetConfHello* hello);

    /**
     * Handles the hello message from the server.
     * @param hello the incoming hello message
     */
    virtual void handleHello(NetConfHello* hello);

    /**
     * Creates a NetConfCtrlInfo for the incoming message and sessionInfo.
     * @param sessionInfo   the session info for the message
     * @param msg           the incoming message
     * @return  a new NetConfCtrlInfo
     */
    virtual NetConfCtrlInfo* createCtrlInfoFor(NetConfClientSessionInfo* sessionInfo, NetConfMessage* msg);

    /**
     * Network and Controller State
     */
    std::vector<NetConfClientSessionInfo*> _openSessions;

    /**
     * Gate name for application outputs
     */
    static const char APPLICATION_OUT_GATE_NAME []; // = "applicaitonOut";
    /**
     * Gate name for application inputs
     */
    static const char APPLICATION_IN_GATE_NAME []; // = "applicationIn";
    /**
     * Gate name for transport inputs
     */
    static const char TRANSPORT_IN_GATE_NAME []; //= "transportIn";
    /**
     * Gate name for transport outputs
     */
    static const char TRANSPORT_OUT_GATE_NAME []; //= "transportOut";
};

}  // namespace SDN4CoRE

#endif
