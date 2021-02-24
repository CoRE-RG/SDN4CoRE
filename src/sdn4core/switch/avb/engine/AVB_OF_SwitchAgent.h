#ifndef __SDN4CORE_AVB_OF_SWITCHAGENT_H_
#define __SDN4CORE_AVB_OF_SWITCHAGENT_H_

#include <omnetpp.h>
#include <sdn4core/switch/base/engine/OF_SwitchAgent.h>
#include "core4inet/services/avb/SRP/SRPTable.h"
#include <sdn4core/switch/avb/engine/AVB_OF_RelayUnit.h>

namespace SDN4CoRE{


/**
 * The AVBOpenFlowRelay is the switching engine of the AVB capable OpenFlow switch.
 * It is directly connected to the TCP module to communicate with the controller (@see~OF_Controller).
 * It handles the forwarding of incoming packets by matching them with the OpenFlowTable
 * (@see~IOpenFlowFlowTable) entries.
 * It adds the capability of handling the SRP protocol to the @see~OF_RelayUnit module.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class AVB_OF_SwitchAgent : public OF_SwitchAgent
{
public:
    AVB_OF_SwitchAgent();
    ~AVB_OF_SwitchAgent();
    virtual void receiveSignal(cComponent *src, simsignal_t id, cObject *value, cObject *details) override;

protected:
    //omnetpp module funcitons
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void handleMessage(omnetpp::cMessage *msg) override;


    /**
     * Processes an OpenFlow packet arriving on controlPlane interface.
     */
    virtual void processControlPlanePacket(omnetpp::cMessage* msg) override;

   /**
     * Handles an SRP message coming from the controller and forwards it to the right modules.
     * @param srp the message to handle
     */
    virtual void handleSRPFromController(omnetpp::cMessage* srp);

    /**
     * Forwards an SRP message to the OpenFlow controller.
     * @param msg srp the message to forward
     */
    virtual void forwardSRPtoController(omnetpp::cPacket* msg);


protected:
    /**
     * Reference to the SRP Table module.
     */
    CoRE4INET::SRPTable* _srpTable;
    /**
     * used initiate the forwarding of a srpFrame to the Controller using the AVB_OF_SwitchAgent
     */
    simsignal_t forwardSRPtoConSig;

};

} /*end namespace SDN4CoRE*/

#endif /*  __SDN4CORE_AVB_OF_RELAYUNIT_H_ */