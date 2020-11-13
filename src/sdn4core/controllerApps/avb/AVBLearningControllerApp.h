//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// c Timo Haeckel, for HAW Hamburg
// 

#ifndef __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_
#define __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_

#include "sdn4core/controllerApps/utility/SRPTableManagement.h"
#include "sdn4core/controllerApps/utility/MACTableManagement.h"
//STD
#include <vector>
#include <string>
//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/controllerApps/AbstractControllerApp.h"

namespace SDN4CoRE{

/**
 * AVBLearningControllerApp is an SDN controller application that handles
 * avb real time traffic as well as best effort MAC switching.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class AVBLearningControllerApp : public openflow::AbstractControllerApp
{
public:
    int getHardTimeout() const {
        return _hardTimeout;
    }

    int getIdleTimeout() const {
        return _idleTimeout;
    }

    AVBLearningControllerApp();
    ~AVBLearningControllerApp();

    virtual void finish() override;


  protected:
    void receiveSignal(omnetpp::cComponent *src, omnetpp::simsignal_t id, omnetpp::cObject *obj, omnetpp::cObject *details) override;
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
    virtual void doSwitching(openflow::OFP_Packet_In *packet_in_msg);

    /**
     * Implements how to process SRP packets.
     * @param packet_in_msg Packet with the SRP message
     */
    void doSRP(openflow::OFP_Packet_In *packet_in_msg);

    /**
     * Creates and sends an SRPFlowModification Message implementing a flow rule in the switch to forward AVB streams.
     * @param mod_com       The modification command of the FlowModMessage (e.g. create, delete, modify,...).
     * @param match         The match to be implemented in the switch.
     * @param outports      The output ports.
     * @param socket        The socket belonging to the switch connection.
     * @param idleTimeOut   The Idle TimeOut, default will be no timeout.
     * @param hardTimeOut   The Hard TimeOut, default will be no timeout.
     */
    virtual void sendSRPFlowModMessage(openflow::ofp_flow_mod_command mod_com, const openflow::oxm_basic_match &match, std::vector<int> outports, inet::TCPSocket * socket, int idleTimeOut , int hardTimeOut);

    /**
     * Forwards an SRP Packet to the switch to be processed.
     * @param packet_in_msg the packet in from the switch
     */
    virtual void forwardSRPPacket(openflow::OFP_Packet_In *packet_in_msg);

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
    bool loadOfflineConfigFromXML(openflow::Switch_Info* info);

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
    virtual openflow::oxm_basic_match createMatchFromPacketIn(openflow::OFP_Packet_In* packetIn);

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

    /**
     * The MAC table associated with each SDN switch in the network.
     */
    std::map<openflow::Switch_Info *,std::map<std::string, int>> unknownMacs;

    /**
     * Path to the ned module of the SRPTableManagement.
     */
    static const char SRPTABLEMANAGERMODULEPATH [];

    /**
     * Path to the ned module of the MACTableManagement.
     */
    static const char MACTABLEMANAGERMODULEPATH [];
};

} /*end namespace SDN4CoRE*/

#endif /* __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_ */
