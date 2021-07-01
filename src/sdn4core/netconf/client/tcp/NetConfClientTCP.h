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

#ifndef __SDN4CORE_NETCONFCLIENTTCP_H_
#define __SDN4CORE_NETCONFCLIENTTCP_H_

#include <omnetpp.h>

#include "sdn4core/netconf/client/base/NetConfClientBase.h"

//INET
#include "inet/transportlayer/contract/tcp/TCPSocket.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * Contains the TCP specific implementation of a NetConf client.
 * This module has to be connected to the tcp module.
 *
 * All responses will be forwarded to the applicaitonOut gate with the
 * same index as the arriving applicationIn gate
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfClientTCP : public NetConfClientBase
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;

    /**
     * Forwards the message to the protocol specific transport layer.
     * The NetConfCtrlInfo_Transport should be attached to the message.
     * @param msg   the message to forward
     */
    virtual void sendToTransport(cMessage* msg) override;

    /**
     * Protocol specific implementation to open a new session for a NetConfHello message.
     * Must insert the new session into the _openSessions list.
     * @param hello   the NetConfHello to create a session for NetConfHello
     */
    virtual NetConfClientSessionInfo* openNewSession(NetConfHello* hello) override;

    /**
     * Closes the protocol specific session and removes the session from openSessions list.
     * @param sessionId   the  session to close
     * @return      true if the session was closed
     */
    virtual bool closeSession(int sessionId) override;

    /**
     * Finds the session info for an incoming message.
     * @param msg   the message of a session
     * @return      pointer to the session info stored in _openSessions, null if none found.
     */
    virtual NetConfClientSessionInfo* findSessionInfoForMsg(cMessage *msg) override;

};

}  // namespace SDN4CoRE

#endif
