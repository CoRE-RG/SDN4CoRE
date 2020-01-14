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

#ifndef __SDN4CORE_NETCONFSERVERTCP_H_
#define __SDN4CORE_NETCONFSERVERTCP_H_

#include <omnetpp.h>

#include <sdn4core/netconf/server/base/NetConfServerBase.h>

//INET
#include "inet/transportlayer/contract/tcp/TCPSocket.h"

using namespace omnetpp;

namespace SDN4CoRE {

/**
 * TCP implementation for a NetConfServer. Handles all the TCP specific functionality.
 *
 * A NetConf Server must be connected to device specific config and state datastores.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfServerTCP : public NetConfServerBase
{
  protected:
    virtual void initialize() override;

    /**
     * Forwards the message to the protocol specific transport layer.
     * The NetConfCtrlInfo_Transport should be attached to the message.
     * @param msg   the message to forward
     */
    virtual void sendToTransport(cMessage* msg) override;

    /**
     * Protocol specific implementation to open a new session.
     * Checks if the session already exists, else opens a new one and adds the _nextSessionId
     * Must insert the new session into the _openSessions list.
     * @param msg   the message to create a session for
     */
    virtual NetConfServerSessionInfo* openNewSession(cMessage* msg) override;

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
    virtual NetConfServerSessionInfo* findSessionInfoForMsg(cMessage *msg) override;

  private:
    /**
     * The TCP connection to NetConf clients
     */
    inet::TCPSocket _serverSocket;
};

}  // namespace SDN4CoRE

#endif
