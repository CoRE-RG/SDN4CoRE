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

#ifndef __OPENFLOW_RTETHERNETCONTROLLERAPP_H_
#define __OPENFLOW_RTETHERNETCONTROLLERAPP_H_

#include <bits/stdint-uintn.h>
#include <omnetpp/clistener.h>
#include <openflow/openflow/protocol/OpenFlow.h>
#include <vector>
#include <string>

namespace ofp{
    class MACTableManagement;
    class OFP_Flow_Mod;
    class SRPTableManagement;
}

using namespace omnetpp;

#include "openflow/controllerApps/AbstractControllerApp.h"
#include "openflow/tsn/controllerApps/SRPTableManagement.h"
#include "openflow/tsn/controllerApps/MACTableManagement.h"

namespace ofp{

/**
 * RTEthernetControllerApp is an SDN controller application that handles
 * real time traffic as well as best effort MAC switching.
 */
class RTEthernetControllerApp : public AbstractControllerApp
{
public:
    int getHardTimeout() const {
        return _hardTimeout;
    }

    int getIdleTimeout() const {
        return _idleTimeout;
    }

    RTEthernetControllerApp();
    ~RTEthernetControllerApp();

    virtual void finish() override;


  protected:
    void receiveSignal(cComponent *src, simsignal_t id, cObject *obj, cObject *details) override;
    virtual void initialize();

    /**
     * @brief Indicates a parameter has changed.
     *
     * @param parname Name of the changed parameter or nullptr if multiple parameter changed.
     */
    virtual void handleParameterChange(const char* parname) override;
    /**
     * Implements the main switching engine for best effort packets.
     * @param packet_in_msg Packet in the be switched.
     */
    virtual void doSwitching(OFP_Packet_In *packet_in_msg);

    /**
     * Implements how to process SRP packets.
     * @param packet_in_msg Packet with the SRP message
     */
    void doSRP(OFP_Packet_In *packet_in_msg);

    /**
     * Creates and sends an SRPFlowModification Message implementing a flow rule in the switch to forward AVB streams.
     * @param mod_com       The modification command of the FlowModMessage (e.g. create, delete, modify,...).
     * @param match         The match to be implemented in the switch.
     * @param outports      The output ports.
     * @param socket        The socket belonging to the switch connection.
     * @param idleTimeOut   The Idle TimeOut, default will be no timeout.
     * @param hardTimeOut   The Hard TimeOut, default will be no timeout.
     */
    virtual void sendSRPFlowModMessage(ofp_flow_mod_command mod_com, const oxm_basic_match &match, std::vector<int> outports, inet::TCPSocket * socket, int idleTimeOut , int hardTimeOut);

    /**
     * Forwards an SRP Packet to the switch to be processed.
     * @param packet_in_msg the packet in from the switch
     */
    virtual void forwardSRPPacket(OFP_Packet_In *packet_in_msg);

    void setHardTimeout(int hardTimeout) {
        this->_hardTimeout = hardTimeout;
    }

    void setIdleTimeout(int idleTimeout) {
        this->_idleTimeout = idleTimeout;
    }

    /**
     * Loads an offline Configuration for the controller app regarding a connected switch
     * containing MAC and SRP Table.
     * @param info  The switch to load the offline config for.
     * @return      true if a config was loaded.
     */
    bool loadOfflineConfigFromXML(Switch_Info* info);

    /**
     * Exports the current state of the MAC and SRP table and creates an XML formatted string.
     * @return      The current state as an XML formatted string
     */
    std::string stateToXML ();

    /**
     *  Creates a match from an packet in message, setting as many match fields as possible.
     * @param packetIn  The packet in message to create a match for.
     * @return          The match created.
     */
    virtual oxm_basic_match createMatchFromPacketIn(OFP_Packet_In* packetIn);

    /**
     * A management module handling all SRP operations.
     */
    SRPTableManagement* _srpManager;

    /**
     * A management module handling all MAC operations.
     */
    MACTableManagement* _macManager;

  private:
    /**
     * The cached IdleTimeOut parameter.
     */
    int _idleTimeout;
    /**
     * The cached HardTimeOut parameter.
     */
    int _hardTimeout;
};

} /*end namespace ofp*/

#endif
