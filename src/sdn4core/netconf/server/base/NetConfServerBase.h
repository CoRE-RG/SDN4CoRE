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

//Omnet
#include <omnetpp.h>
//STD
#include <unordered_map>
#include <vector>
//SDN4CoRE
#include <sdn4core/netconf/datastructures/base/NetConfServerSessionInfo.h>
#include "sdn4core/utility/processing/ProcessingTimeSimulation.h"

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
    virtual NetConfServerSessionInfo* openNewSession(cMessage* msg) = 0;

    /**
     * Closes the protocol specific session and removes the session from openSessions list.
     * @param sessionId   the last message of the session to close
     * @return      true if the session was closed
     */
    virtual bool closeSession(int sessionId) = 0;

    /**
     * Finds the session info for an incoming message.
     * @param msg   the message of a session
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfServerSessionInfo* findSessionInfoForMsg(cMessage *msg) = 0;

    /**
     * Finds the session info for an existing session id.
     * @param sessionId   the id of the session to find
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfServerSessionInfo* findSessionInfoForId(int sessionId);

    /**
     * @see ~ProcessingTimeSimulation::processScheduledMessage(cMessage *msg)
     */
    virtual void processScheduledMessage(cMessage *msg);

    /**
     * Handles the hello message and replys to it.
     * @param msg   the incoming hello message
     */
    virtual void handleHello(cMessage* msg);

    /**
     * Handles the close session message and replys to it.
     * @param msg   the incoming close session message
     */
    virtual void handleCloseSession(cMessage* msg);

    /**
     * Handles the RPC message and forwards it to the correct store.
     * @param msg   the incoming RPC message
     */
    virtual void handleRPC(NetConfMessage* msg);

    /**
     * Creates a NetConfCtrlInfo for the incoming message and sessionInfo.
     * @param sessionInfo   the session info for the message
     * @param msg           the incoming message
     * @return  a new NetConfCtrlInfo
     */
    virtual NetConfCtrlInfo* createCtrlInfoFor(NetConfServerSessionInfo* sessionInfo, NetConfMessage* msg);

    /**
     * Creates an rpc reply element containing the error message.
     * @param error_type        Defines the conceptual layer that the error occurred.
     *                          One of @see ~NetConf_RPCReplyElement_Error_Type
     * @param error_tag         Contains a string identifying the error condition.
     * @param error_severity    Contains an enum identifying the error severity, as
     *                          determined by the device. One of @see ~NetConf_RPCReplyElement_Error_Severity
     * @param error_app_tag     Contains a string identifying the data-model-specific
     *                          or implementation-specific error condition, if one exists.
     * @return                  the NetConf_RPCReplyElement_Error
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Error(
            int error_type, const char * error_tag, int error_severity,
            const char * error_app_tag);

    /**
     * Creates an rpc reply element containing OK.
     * @return the NetConf_RPCReplyElement_Ok
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Ok();
    NetConfMessage_RPCReply* createRPCReply(NetConf_RPCReplyElement* element);

    /**
     * Network and Controller State
     */
    std::vector<NetConfServerSessionInfo*> _openSessions;

    /**
     * The session ID to add to the next session opened with openNewSession();
     */
    static int _nextSessionId;

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

};

}  // namespace SDN4CoRE

#endif
