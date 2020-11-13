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


#ifndef OPENFLOW_CONTROLLERAPPS_AVB_AVBSECURITYCONTROLLERAPP_H_
#define OPENFLOW_CONTROLLERAPPS_AVB_AVBSECURITYCONTROLLERAPP_H_

#include <sdn4core/controllerApps/avb/AVBLearningControllerApp.h>

#include <sdn4core/utility/visual/ColorChangingNode.h>
//openflow
#include <openflow/openflow/protocol/OpenFlow.h>

namespace SDN4CoRE {

#define NADS_PORT_NONE -1 //needs to be -1 as it is compared >= for valid ports

/**
 * Security state of the Network
 */
typedef enum SecurityState {
    NONE,
    OK,
    WARNING,
    DANGER,
}SecurityState_t;

/**
 *The AVBSecurityControllerApp extends the RTEthernetControllerApp and adds security functionality.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class AVBSecurityControllerApp: public AVBLearningControllerApp {
public:
    AVBSecurityControllerApp();
    virtual ~AVBSecurityControllerApp();

    SecurityState_t getState() const {
        return _state;
    }

    void setState(SecurityState_t state = NONE) {
        _state = state;
        _stateUpdated = true;
    }

    virtual void finish() override;

protected:
    //omnetpp interface methods.
    virtual void handleMessage(cMessage* msg) override;
    void receiveSignal(cComponent *src, simsignal_t id, cObject *obj, cObject *details) override;
    virtual void initialize() override;
    virtual void refreshDisplay() const override;

    /**
     * Creates a OpenFlow match using the data of the given OpenFlow packet in message.
     * @param packetIn  the OpenFlow packet in message to extract the data from
     * @return  the OpenFlow match
     */
    virtual openflow::oxm_basic_match createMatchFromPacketIn(openflow::OFP_Packet_In* packetIn) override;

    /**
     *
     * Sends a Flow Modification message with a single outport to the switch connected to the TCP socket using the parameter information.
     * @param mod_com       the OpenFlow flow modification command one of @see ofp_flow_mod_command
     * @param match         the OpenFlow match
     * @param outport       the output port
     * @param socket        the socket of the switch to send the message to
     * @param idleTimeOut   the idle timeout of the flow rule
     * @param hardTimeOut   the hard timeout of the flow rule
     */
    virtual void sendFlowModMessage(openflow::ofp_flow_mod_command mod_com, const openflow::oxm_basic_match &match, uint32_t outport, inet::TCPSocket * socket, int idleTimeOut, int hardTimeOut) override;

    /**
     * Sends a Flow Modification message with multiple outports to the switch connected to the TCP socket using the parameter information.
     * @param mod_com       the OpenFlow flow modification command one of @see ofp_flow_mod_command
     * @param match         the OpenFlow match
     * @param outports      the output ports
     * @param socket        the socket of the switch to send the message to
     * @param idleTimeOut   the idle timeout of the flow rule
     * @param hardTimeOut   the hard timeout of the flow rule
     */
    virtual void sendSRPFlowModMessage(openflow::ofp_flow_mod_command mod_com, const openflow::oxm_basic_match &match, std::vector<int> outports, inet::TCPSocket * socket, int idleTimeOut , int hardTimeOut) override;

    /**
     * Creates a OpenFlow packet out message using the data of the given OpenFlow packet in message.
     * It will be send out of the given outport of the switch.
     * @param packet_in_msg     the OpenFlow packet in message to extract the data from
     * @param outport           the outport at the switch
     * @return  the OpenFlow Packet out message.
     */
    virtual openflow::OFP_Packet_Out * createPacketOutFromPacketIn(openflow::OFP_Packet_In *packet_in_msg, uint32_t outport) override;

    /**
     * implements the mirroring rule in a new switch and allows to insert flows on connection.
     * @param msg Incoming switch features reply
     */
    virtual void handleNewSwitch(openflow::Open_Flow_Message* msg);
    /**
     * Handle the message from a Connected NADS. And apply security counter measures.
     * @param msg
     */
    virtual void handleNADSMessage(openflow::OFP_Packet_In* msg);

    /**
     * @brief Indicates a parameter has changed.
     *
     * @param parname Name of the changed parameter or nullptr if multiple parameter changed.
     */
    virtual void handleParameterChange(const char* parname) override;

private:
    /**
     * Checks if the Vector contains the NADS port. If not the NADS port is added.
     * @return true if the vector was altered.
     */
    bool checkOrAddNADSPort(std::vector<int>* portlist);

    /**
     * Checks if the Frame encapsulated in the packetIn is white listed with a flow.
     */
    bool isWhitelisted(openflow::OFP_Packet_In* packetIn);
    void scheduleSelfMessage();

    /**
     * Security status of the Network
     */
    SecurityState_t _state = NONE;
    /**
     * True if the state was updated, will result in display refresh.
     */
    mutable bool _stateUpdated = false;

    /**
     * Caches controller MAC Address parameter
     */
    inet::MACAddress _controllerMAC;

    /**
     * Caches the NADS port.
     */
    int _NADSPort = NADS_PORT_NONE;
    /**
     * Holds a reference to the security traffic light, displaying the nework state.
     */
    ColorChangingNode* _trafficLight;

    /**
     * Caches the allowNewFlows parameter
     */
    bool _allowNewFlows = true;
    /**
     * Caches the allowNewFlows parameter
     */
    bool _allowARP = true;
    /**
     * Caches the allowNewFlows parameter
     */
    bool _allowSRP = true;

    int _anomalyCount = 0;
    simtime_t _lastAnomaly = 0;
    double _anomalyTimeout = 0.1;
    bool _anomalyScheduled = false;
};

} /* namespace SDN4CoRE */

#endif /* OPENFLOW_CONTROLLERAPPS_AVB_AVBSECURITYCONTROLLERAPP_H_ */
