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

#include "sdn4core/controllerApps/base/LearningControllerApp.h"
#include "sdn4core/controllerState/srp/SRPTableManagement.h"
//STD
#include <vector>

using namespace omnetpp;

namespace SDN4CoRE{

/**
 * AVBLearningControllerApp is an SDN controller application that handles
 * avb real time traffic as well as best effort MAC switching.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class AVBLearningControllerApp : public LearningControllerApp
{
public:


  protected:
    virtual void initialize() override;

    /**
     * Main processing engine of packet_in messages.
     *
     * Checks whether packet in is an srp or avb frame and handles them,
     * else the learning controller can handle it.
     *
     * @param packet_in_msg The packet in message
     */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) override;

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

    /**
     * Loads an offline Configuration for the controller app regarding a connected switch
     * containing MAC and SRP Table.
     * @param info  The switch to load the offline config for.
     * @return      true if a config was loaded.
     */
    virtual bool loadOfflineConfigFromXML(openflow::Switch_Info* info) override;

    /**
     * Exports the current state of the MAC and SRP table and creates an XML formatted string.
     * @return      The current state as an XML formatted string
     */
    virtual std::string stateToXML () override;

    /**
     * A management module handling all SRP operations.
     */
    SRPTableManagement* _srpManager;

private:

    /**
     * Path to the ned module of the SRPTableManagement.
     */
    static const char SRPTABLEMANAGERMODULEPATH [];
};

} /*end namespace SDN4CoRE*/

#endif /* __OPENFLOW_AVB_AVBLEARNINGCONTROLLERAPP_H_ */
