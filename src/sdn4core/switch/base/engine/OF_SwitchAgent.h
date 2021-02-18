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

#ifndef SDN4CORE_SWITCH_BASE_ENGINE_OF_SWITCHAGENT_H_
#define SDN4CORE_SWITCH_BASE_ENGINE_OF_SWITCHAGENT_H_

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

class OF_RelayUnit;

/**
 * The OF_RelayUnit implements the switching engine of an OpenFlow switch.
 * It is directly connected to the TCP module to communicate with the controller (@see~OF_Controller).
 * It handles the forwarding of incoming packets by matching them with the OpenFlowTable
 * (@see~IOpenFlowFlowTable) entries.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class OF_SwitchAgent: public cSimpleModule,  public cListener
{
public:
    OF_SwitchAgent();
    ~OF_SwitchAgent();
    virtual void finish() override;
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, bool b, cObject *details) override;

protected:
    /**
     * Indicates if the relay unit has a packet in the queue
     */
    bool ofBusy;
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
     * Counters for control plane packet arrival events
     */
    long controlPlanePacket;

    //stats

    simsignal_t bufferSize;
    simsignal_t waitingTime;
    simsignal_t queueSize;
    simsignal_t testSignal;

    /**
     * The OpenFlow Flow Table containing match entries
     */
    std::vector<openflow::OF_FlowTable*> _flowTables;
    /**
     * Message List for incoming packets to be handled
     */
    std::list<cMessage *> msgList;
    /**
     * Buffer for packets forwarded to the controller if sendCompletePacket==false
     */
    openflow::Buffer buffer;
    /**
     * The TCP connection to the OpenFlow controller
     */
    inet::TCPSocket socket;
    /**
     * Indicates if the hello handshake has been finished with the SDN Controller.
     */
    bool hasController = false;
    /**
     * Reference to SwitchAgent and forward declaration to resolve circular dependencies
     */
   OF_RelayUnit* relayUnit;

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
     * Handle the OpenFlow feature request message and creates a reply.
     * @param of_msg    the OpenFlow message
     */
    virtual void handleFeaturesRequestMessage(openflow::Open_Flow_Message *of_msg);
    /**
     * Handle the OpenFlow flow mod message and initiate table modifications.
     * @param of_msg    the OpenFlow message
     */
    virtual void handleFlowModMessage(openflow::Open_Flow_Message *of_msg);
    /**
     * Handle the OpenFlow packet out message by outputting the frame to the specified ports.
     * @param of_msg    the OpenFlow message
     */
    virtual void handlePacketOutMessage(openflow::Open_Flow_Message *of_msg);
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

public:
    /**
     * Handles a packet that has not matched any rule in the OpenFlow tables.
     * @param frame     the frame to process
     */
    virtual void handleMissMatchedPacket(inet::EthernetIIFrame *frame);
    /*
     * Forwards a frame to the controller
     * @param frame     the frame that should be forwarded
     */
    void forwardFrameToController(EthernetIIFrame* frame);
};

} /*end namespace SDN4CoRE*/

#endif /* __SDN4CORE_OF_RELAYUNIT_H_ */
