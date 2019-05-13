

#ifndef OPENFLOW_REALTIME_RTOFSwitch_H_
#define OPENFLOW_REALTIME_RTOFSwitch_H_

#include <omnetpp.h>
#include "inet/transportlayer/contract/tcp/TCPSocket.h"

#include "openflow/openflow/switch/Buffer.h"
#include "openflow/messages/openflowprotocol/OFP_Message.h"
#include "openflow/openflow/switch/OF_FlowTable.h"
#include <vector>
#include "core4inet/services/avb/SRP/SRPTable.h"
#include "inet/common/InitStages.h"

namespace SDN4CoRE{

/**
 * The RTOFSwitch is the switching engine of a real time capable SDN forwarding device.
 * It controls the forwarding of packets and is connected to the OpenFlow controller via TCP.
 * TODO merge this and the standard switching engine to be inherited as they share most functionality.
 */
class RTOFSwitch: public cSimpleModule
{
public:
    RTOFSwitch();
    ~RTOFSwitch();
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
    CoRE4INET::SRPTable* _srpTable;
    inet::TCPSocket socket;


    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg);
    void connect(const char *connectToAddress);

    void processQueuedMsg(cMessage *data_msg);
    void handleFeaturesRequestMessage(ofp::OFP_Message *of_msg);
    void handleFlowModMessage(ofp::OFP_Message *of_msg);
    void handlePacketOutMessage(ofp::OFP_Message *of_msg);
    void executePacketOutAction(ofp::ofp_action_output *action, inet::EthernetIIFrame *frame, uint32_t inport);
    void processFrame(inet::EthernetIIFrame *frame);
    void handleMissMatchedPacket(inet::EthernetIIFrame *frame);
    void forwardSRPtoController(cPacket* msg);

private:
    void handleSelfMessage(omnetpp::cMessage* msg);
    void simulateServiceTime(omnetpp::cMessage* msg);
    void handleSRP(cMessage* srp);

    bool isSRPMessage(cMessage* msg);
};

} /*end namespace SDN4CoRE*/

#endif /* OPENFLOW_REALTIME_RTOFSwitch_H_ */
