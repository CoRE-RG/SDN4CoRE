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

#ifndef __SDN4CORE_NETCONFSERVER_H_
#define __SDN4CORE_NETCONFSERVER_H_

#include <omnetpp.h>
#include <unordered_map>
#include <vector>

#include "sdn4core/utility/processing/ProcessingTimeSimulation.h"

#include "sdn4core/netconf/server/base/NetConfSessionInfo.h"
// AUTO-GENERATED MESSAGES
#include "sdn4core/netconf/messages/NetConfMessage_m.h"
#include "sdn4core/netconf/messages/NetConfCtrlInfo_m.h"

using namespace omnetpp;

namespace SDN4CoRE {
/**
 * forward declaration of NetConfDataStoreManagerBase
 */
class NetConfDataStoreManagerBase;

/**
 * Base implementation for a NetConfServer, communicating with a NetConf client @see~NetConfClient.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfServerBase : public ProcessingTimeSimulation
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
    virtual NetConfSessionInfo* openNewSession(cMessage* msg) = 0;

    /**
     * Closes the protocol specific session and removes the session from openSessions list.
     * @param msg   the last message of the session to close
     */
    virtual void closeSession(cMessage* msg) = 0;

    /**
     * Finds the session info for an incoming message.
     * @param msg   the message of a session
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfSessionInfo* findSessionInfoForMsg(cMessage *msg) = 0;

    /**
     * Finds the session info for an existing session id.
     * @param sessionId   the id of the session to find
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfSessionInfo* findSessionInfoForId(int sessionId);

    /**
     * @see ~ProcessingTimeSimulation::processScheduledMessage(cMessage *msg)
     */
    virtual void processScheduledMessage(cMessage *msg);

    /**
     * Network and Controller State
     */
    std::vector<NetConfSessionInfo> _openSessions;

    /**
     * The session ID to add to the next session opened with openNewSession();
     */
    int _nextSessionId = 0;

    /**
     * Cached reference to the NetConf data store manager.
     */
    NetConfDataStoreManagerBase* _configDataStoreManager;

    /**
     * Gate name (@directIn) for request inputs in data stores
     */
    static const char REQUEST_FWD_GATE_NAME []; // = "requestIn";
    /**
     * Gate name (@directIn) for response inputs to NetConf server
     */
    static const char RESPONSE_IN_GATE_NAME []; // = "responseIn";
    /**
     * Gate name for transport inputs
     */
    static const char TRANSPORT_IN_GATE_NAME []; //= "transportIn";
    /**
     * Gate name for transport outputs
     */
    static const char TRANSPORT_OUT_GATE_NAME []; //= "transportOut";

private:
    /**
     * Handles the hello message and replys to it.
     * @param msg   the incoming hello message
     */
    void handleHello(cMessage* msg);

    /**
     * Handles the RPC message and forwards it to the correct store.
     * @param msg   the incoming RPC message
     */
    void handleRPC(NetConfMessage* msg);

    /**
     * Creates a NetConfCtrlInfo for the incoming message and sessionInfo.
     * @param sessionInfo   the session info for the message
     * @param msg           the incoming message
     * @return  a new NetConfCtrlInfo
     */
    virtual NetConfCtrlInfo* createCtrlInfoFor(NetConfSessionInfo* sessionInfo, NetConfMessage* msg);
};

}  // namespace SDN4CoRE

#endif
