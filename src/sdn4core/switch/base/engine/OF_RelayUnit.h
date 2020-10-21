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

#ifndef __SDN4CORE_OF_RELAYUNIT_H_
#define __SDN4CORE_OF_RELAYUNIT_H_

#include <omnetpp.h>
//STD
#include <vector>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
#include "inet/common/InitStages.h"
//openflow
#include "openflow/openflow/switch/buffer/Buffer.h"
#include "openflow/messages/OFP_Message.h"
#include "openflow/openflow/switch/flowtable/OF_FlowTable.h"

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
    virtual void finish() override;

protected:
    /**
     * Cached omnetpp parameter for timeout polling
     */
    double flowTimeoutPollInterval;
    /**
     * Cached omnetpp parameter if the relay unit should forward the complete packet to the controller
     */
    bool sendCompletePacket;
    /**
     * Cached omnetpp parameter if this switch has only a single openflow engine per switch.
     * this will allow the switch to enter a busy status.
     */
    bool parallelProcessing;
    /**
     * Cached omnetpp parameter for the relay units service time in seconds
     */
    double ofServiceTime;
    /**
     * Indicates if the relay unit has a packet in the queue
     */
    bool ofBusy;


    /**
     * Counters for control plane packet arrival events
     */
    long controlPlanePacket;
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

    //stats
    simsignal_t dpPingPacketHash;
    simsignal_t cpPingPacketHash;
    simsignal_t queueSize;
    simsignal_t bufferSize;
    simsignal_t waitingTime;


    /**
     * Message List for incoming packets to be handeled
     */
    std::list<cMessage *> msgList;
    /**
     * List of all connected ports
     */
    std::vector<openflow::ofp_port> portVector;
    /**
     * Buffer for packets forwarded to the controller if sendCompletePacket==false
     */
    openflow::Buffer buffer;
    /**
     * The OpenFlow Flow Table containing match entries
     */
    std::vector<openflow::OF_FlowTable*> _flowTables;
    /**
     * The TCP connection to the OpenFlow controller
     */
    inet::TCPSocket socket;

protected:
    //omnetpp module funcitons
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void handleMessage(cMessage *msg) override;
    virtual void handleParameterChange(const char* parname) override;
    /**
     * Connects to the OpenFlow controller at the given address by sending the ofp hello message.
     * @param connectToAddress  the address of the controller
     */
    virtual void connect(const char *connectToAddress);
    /**
     * Processes an OpenFlow packet arriving on controlPlane interface.
     */
    virtual void processControlPlanePacket(omnetpp::cMessage* msg);
    /**
     * Processes a data frame arriving on a dataPlane interface.
     */
    virtual void processDataPlanePacket(omnetpp::cMessage* msg);
    /**
     * Handle the OpenFlow feature request message and creates a reply.
     * @param of_msg    the OpenFlow message
     */
    virtual void handleFeaturesRequestMessage(openflow::OFP_Message *of_msg);
    /**
     * Handle the OpenFlow flow mod message and initiate table modifications.
     * @param of_msg    the OpenFlow message
     */
    virtual void handleFlowModMessage(openflow::OFP_Message *of_msg);
    /**
     * Handle the OpenFlow packet out message by outputting the frame to the specified ports.
     * @param of_msg    the OpenFlow message
     */
    virtual void handlePacketOutMessage(openflow::OFP_Message *of_msg);
    /**
     * Executes a PacketOut action(s) by sending the frame to the outports
     * @param action    the openflow output action
     * @param frame     the frame to forward
     * @param inport    the arrival port, to make sure to not flood it back to the in port.
     */
    virtual void executePacketOutAction(openflow::ofp_action_output *action, inet::EthernetIIFrame *frame, uint32_t inport);
    /**
     * Processes an EthernetIIFrame by looking up a match in the table and forwarding it.
     * @param frame     the frame to process
     */
    virtual void processFrame(inet::EthernetIIFrame *frame);
    /**
     * Handles a packet that has not matched any rule in the OpenFlow tables.
     * @param frame     the frame to process
     */
    virtual void handleMissMatchedPacket(inet::EthernetIIFrame *frame);
    /**
     * Similate the service time for a given message by scheduling a self message for the next processing.
     * @param msg       the message to schedule
     */
    virtual void simulateServiceTime(omnetpp::cMessage* msg);
    /**
     * Checks if there are messages left in the msgList and schedules the next one.
     */
    virtual void scheduleNextServiceTime();
    /**
     * Schedules a message as a servicetime message with ofServiceTime delay.
     */
    virtual void scheduleForServiceTime(omnetpp::cMessage* msg);
    /**
     * Extracts the information from an incoming frame to be matched against the openflow table.
     * @param frame     the frame to create a match for
     * @return          the match for the frame
     */
    virtual openflow::oxm_basic_match extractMatch(inet::EthernetIIFrame* frame);

};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_OF_RELAYUNIT_H_ */
