

#ifndef __SDN4CORE_OF_RELAYUNIT_H_
#define __SDN4CORE_OF_RELAYUNIT_H_

#include <omnetpp.h>
#include "inet/transportlayer/contract/tcp/TCPSocket.h"

#include "openflow/openflow/switch/buffer/Buffer.h"
#include "openflow/messages/openflowprotocol/OFP_Message.h"
#include "openflow/openflow/switch/flowtable/OF_FlowTable.h"
#include <vector>
#include "core4inet/services/avb/SRP/SRPTable.h"
#include "inet/common/InitStages.h"

namespace SDN4CoRE{

/**
 * The OF_RelayUnit implements the switching engine of an OpenFlow switch.
 * It is directly connected to the TCP module to communicate with the controller (@see~OF_Controller).
 * It handles the forwarding of incoming packets by matching them with the OpenFlowTable
 * (@see~IOpenFlowFlowTable) entries.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class OF_RelayUnit: public cSimpleModule
{
public:
    OF_RelayUnit();
    ~OF_RelayUnit();
    void disablePorts(std::vector<int> ports);
    virtual void finish();

protected:
    double flowTimeoutPollInterval;
    double serviceTime;
    bool busy;
    bool sendCompletePacket;

    long controlPlanePacket;
    long dataPlanePacket;
    long flowTableHit;
    long flowTableMiss;

    //stats
    simsignal_t dpPingPacketHash;
    simsignal_t cpPingPacketHash;
    simsignal_t queueSize;
    simsignal_t bufferSize;
    simsignal_t waitingTime;

    std::list<cMessage *> msgList;
    std::vector<ofp::ofp_port> portVector;


    ofp::Buffer buffer;
    std::vector<ofp::OF_FlowTable*> _flowTables;
    inet::TCPSocket socket;

protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleParameterChange(const char* parname) override;

    virtual void processQueuedMsg(cMessage *data_msg);
    virtual void connect(const char *connectToAddress);
    virtual void handleFeaturesRequestMessage(ofp::OFP_Message *of_msg);
    virtual void handleFlowModMessage(ofp::OFP_Message *of_msg);
    virtual void handlePacketOutMessage(ofp::OFP_Message *of_msg);
    virtual void executePacketOutAction(ofp::ofp_action_output *action, inet::EthernetIIFrame *frame, uint32_t inport);
    virtual void processFrame(inet::EthernetIIFrame *frame);
    virtual void handleMissMatchedPacket(inet::EthernetIIFrame *frame);

    virtual void handleSelfMessage(omnetpp::cMessage* msg);
    virtual void simulateServiceTime(omnetpp::cMessage* msg);
    virtual ofp::oxm_basic_match extractMatch(inet::EthernetIIFrame* frame);

};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_OF_RELAYUNIT_H_ */
