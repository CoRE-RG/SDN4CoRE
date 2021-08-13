
#ifndef SDN4CORE_SWITCH_BASE_ENGINE_OF_RELAYUNIT_H_
#define SDN4CORE_SWITCH_BASE_ENGINE_OF_RELAYUNIT_H_

//Omnet
#include <omnetpp.h>
//STD
#include <vector>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/common/InitStages.h"
//openflow
#include "openflow/openflow/switch/Buffer.h"
#include "openflow/messages/Open_Flow_Message_m.h"
#include "openflow/openflow/switch/flowtable/OF_FlowTable.h"


namespace SDN4CoRE{

/**
 * The OF_RelayUnit is part of the switching engine of an OpenFlow switch.
 * It handles the forwarding of incoming packets by matching them with the OpenFlowTable
 * (@see~IOpenFlowFlowTable) entries. Additionally it may send packets to the OF_SwitchAgent
 * for further handling.
 *
 * @author Timo Haeckel, Tobias Haugg, for HAW Hamburg
 */
class OF_RelayUnit: public cSimpleModule
{
public:
    OF_RelayUnit();
    ~OF_RelayUnit();
    virtual void finish() override;
    void disablePorts(std::vector<int> ports);

protected:

    /**
     * Counters for data plane packet arrival events
     */
    long dataPlanePacket;
    /**
     * Counters for flow table match events
     */
    long flowTableHit;
    /**
     * Counters for flow table miss events
     */
    long flowTableMiss;

    /**
     * used initiate the forwarding of a frame to the Controller using the OF_SwitchAgent
     */
    simsignal_t forwardToConSign;
    /**
     * Signals the OF_SwitchAgent that no matching entry was found for an incoming frame
     */
    simsignal_t tableMissSign;

    //stats
    simsignal_t dpPingPacketHash;
    simsignal_t cpPingPacketHash;

    /**
     * The OpenFlow Flow Table containing match entries
     */
    std::vector<openflow::OF_FlowTable*> _flowTables;
    /**
     * List of all connected ports
     */
    std::vector<openflow::ofp_port> portVector;


protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
    /**
     * Processes a data frame arriving on a dataPlane interface.
     */
    virtual void processDataPlanePacket(omnetpp::cMessage* msg);
    /**
     * Processes an EthernetIIFrame by looking up a match in the table and forwarding it.
     * @param frame     the frame to process
     */
    virtual void processFrame(inet::EthernetIIFrame *frame);
    /**
     * Extracts the information from an incoming frame to be matched against the openflow table.
     * @param frame     the frame to create a match for
     * @return          the match for the frame
     */
    virtual openflow::oxm_basic_match extractMatch(inet::EthernetIIFrame* frame);
public:
    /**
     * Executes a PacketOut action(s) by sending the frame to the outports
     * @param action    the openflow output action
     * @param frame     the frame to forward
     * @param inport    the arrival port, to make sure to not flood it back to the in port.
     */
    virtual void executePacketOutAction(openflow::ofp_action_output *action, inet::EthernetIIFrame *frame, uint32_t inport);
};
}
#endif /* SDN4CORE_SWITCH_BASE_ENGINEREWORK_OF_DATAPLANE_H_ */
