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


#ifndef OPENFLOW_TSN_CONTROLLERAPPS_RTSECURITYCONTROLLERAPP_H_
#define OPENFLOW_TSN_CONTROLLERAPPS_RTSECURITYCONTROLLERAPP_H_

#include <sdn4core/controllerApps/avb/AVBLearningControllerApp.h>

#include <openflow/openflow/protocol/OpenFlow.h>
#include <sdn4core/utility/NodeDisplayEditor.h>
#include <sdn4core/utility/ColorChangingNode.h>

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

    virtual ofp::oxm_basic_match createMatchFromPacketIn(ofp::OFP_Packet_In* packetIn) override;
    virtual void sendFlowModMessage(ofp::ofp_flow_mod_command mod_com, const ofp::oxm_basic_match &match, int outport, inet::TCPSocket * socket, int idleTimeOut, int hardTimeOut) override;
    virtual void sendSRPFlowModMessage(ofp::ofp_flow_mod_command mod_com, const ofp::oxm_basic_match &match, std::vector<int> outports, inet::TCPSocket * socket, int idleTimeOut , int hardTimeOut) override;
    virtual ofp::OFP_Packet_Out * createPacketOutFromPacketIn(ofp::OFP_Packet_In *packet_in_msg, uint32_t outport) override;

    /**
     * implements the mirroring rule in a new switch and allows to insert flows on connection.
     * @param msg Incoming switch features reply
     */
    virtual void handleNewSwitch(ofp::OFP_Message* msg);
    /**
     * Handle the message from a Connected NADS. And apply security counter measures.
     * @param msg
     */
    virtual void handleNADSMessage(ofp::OFP_Packet_In* msg);

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
    bool isWhitelisted(ofp::OFP_Packet_In* packetIn);
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

#endif /* OPENFLOW_TSN_CONTROLLERAPPS_RTSECURITYCONTROLLERAPP_H_ */
