
//STD
#include <sstream>
#include <string>
//inet
#include "inet/linklayer/ethernet/EtherMACBase.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/ITransportPacket.h"
#include "inet/common/ModuleAccess.h"
#include "inet/networklayer/common/InterfaceTable.h"
#include "inet/networklayer/ipv4/ICMPMessage.h"
//Auto-generated Messages
#include "inet/networklayer/arp/ipv4/ARPPacket_m.h"
#include "inet/applications/pingapp/PingPayload_m.h"
//openflow
#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/messages/Open_Flow_Message_m.h"
#include "openflow/messages/OFP_Features_Reply_m.h"
#include "openflow/messages/OFP_Hello_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/messages/OFP_Packet_Out_m.h"
#include "openflow/messages/OFP_Flow_Mod_m.h"
//SDN4CoRE
#include <sdn4core/switch/base/engine/OF_RelayUnit.h>
#include <sdn4core/switch/base/engine/OF_SwitchAgent.h>


using namespace std;
using namespace inet;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(OF_SwitchAgent);

#define MSGKIND_CONNECT                     1
#define MSGKIND_SERVICETIME                 3


OF_SwitchAgent::OF_SwitchAgent(){}

OF_SwitchAgent::~OF_SwitchAgent(){
    for(auto&& entry : msgList) {
      delete entry;
    }
    msgList.clear();
}

void OF_SwitchAgent::initialize(int stage){

    switch(stage){
    case INITSTAGE_LOCAL: {
        relayUnit = dynamic_cast<OF_RelayUnit*> (getParentModule()->getSubmodule("relayUnit"));
        ofBusy = false;
        handleParameterChange(nullptr);

        //stats
        bufferSize = registerSignal("bufferSize");
        waitingTime = registerSignal("waitingTime");
        queueSize = registerSignal("queueSize");

        //register relay unit signals
        forwardToConSign = registerSignal("forwardToConSign");
        tableMissSign = registerSignal("tableMissSign");
        relayUnit->subscribe(forwardToConSign, this);
        relayUnit->subscribe(tableMissSign, this);

        controlPlanePacket=0l;

        //init helper classes
        buffer = Buffer((int)par("bufferCapacity"));

        int numFlowTables = getParentModule()->getSubmodule("flowTables",0)->getVectorSize();
        for (int i = 0; i < numFlowTables; i++) {
            if(OF_FlowTable* table = dynamic_cast<OF_FlowTable*> (getParentModule()->getSubmodule("flowTables",i))){
                _flowTables.push_back(table);
            }
        }
        break;
    }
    case INITSTAGE_TRANSPORT_LAYER: {
        //init socket to controller
        const char *localAddress = par("localAddress");
        int localPort = par("localPort");

        socket.bind(*localAddress ? L3Address(localAddress) : L3Address(), localPort);
        socket.setOutputGate(gate("controlPlaneOut"));
        socket.setDataTransferMode(TCP_TRANSFER_OBJECT);
        break;
    }
    case INITSTAGE_LAST: {
        //schedule connection setup
       cMessage *initiateConnection = new cMessage("initiateConnection");
       initiateConnection->setKind(MSGKIND_CONNECT);
       scheduleAt(par("connectAt").doubleValue(), initiateConnection);
       break;
    }
    default:
        break;
    }
}

void OF_SwitchAgent::processControlPlanePacket(cMessage *msg){
    controlPlanePacket++;
    if (Open_Flow_Message *of_msg = dynamic_cast<Open_Flow_Message *>(msg)) { //msg from controller
        switch ((ofp_type)of_msg->getHeader().type){
            case OFPT_HELLO:
                this->hasController = true;
                break;

            case OFPT_FEATURES_REQUEST:
                handleFeaturesRequestMessage(of_msg);
                break;

            case OFPT_FLOW_MOD:
                handleFlowModMessage(of_msg);
                break;

            case OFPT_PACKET_OUT:
                handlePacketOutMessage(of_msg);
                break;

            default:
                //TODO Process openflow Hello...?
                break;
        }
    }
    delete msg;
}


void OF_SwitchAgent::scheduleNextServiceTime(){
    //check for more waiting packets
    if (msgList.empty()) {
        ofBusy = false;
    } else {
        cMessage* msgFromList = msgList.front();
        msgList.pop_front();
        scheduleForServiceTime(msgFromList);
        emit(queueSize, static_cast<unsigned int>(msgList.size()));
        emit(bufferSize, static_cast<int>(buffer.size()));
    }
}

void OF_SwitchAgent::scheduleForServiceTime(cMessage *msg){
    cMessage* event = new cMessage("event");
    event->setKind(MSGKIND_SERVICETIME);
    event->setContextPointer(msg);
    scheduleAt(simTime() + ofServiceTime, event);
}

void OF_SwitchAgent::handleMessage(cMessage *msg){
    if (msg->isSelfMessage()){
        if (msg->getKind() == MSGKIND_CONNECT) {
            EV << "starting of session" << '\n';
            connect(""); // active OPEN
        } else if (msg->getKind() == MSGKIND_SERVICETIME) {
            //This is message which has been scheduled due to service time
            //Get the Original message
            cMessage* data_msg = (cMessage*) (msg->getContextPointer());
            emit(waitingTime,
                    (simTime() - data_msg->getArrivalTime() - ofServiceTime));

            //handle packet
            processControlPlanePacket(data_msg);

            //schedule next service time
            scheduleNextServiceTime();
        }
        delete msg;
    } else if (msg->getKind() == TCP_I_ESTABLISHED) { //fast handle for TCP Established
        socket.processMessage(msg);
    } else if(msg->arrivedOn("controlPlaneIn")){
        simulateServiceTime(msg);
    }
}

void OF_SwitchAgent::simulateServiceTime(cMessage* msg) {
    //imlement service time
    if(parallelProcessing || !ofBusy){
        scheduleForServiceTime(msg);
        ofBusy = true;
    }else if (ofBusy) {
        msgList.push_back(msg);
        emit(queueSize, static_cast<unsigned int>(msgList.size()));
        emit(bufferSize, static_cast<int>(buffer.size()));
    }
}

void OF_SwitchAgent::connect(const char *addressToConnect){
    socket.renewSocket();
    const char *connectAddress;

    int connectPort = par("connectPort").intValue();

    if(strlen(addressToConnect) == 0){
        connectAddress = par("connectAddress");
    } else {
        connectAddress = addressToConnect;
    }


    EV << "Sending Hello to " << connectAddress <<" \n";

    socket.connect(L3AddressResolver().resolve(connectAddress), connectPort);

    OFP_Hello *msg = OFMessageFactory::instance()->createHello();

    socket.send(msg);
}

void OF_SwitchAgent::handleFeaturesRequestMessage(Open_Flow_Message *of_msg){
    //prepare data
    IInterfaceTable* inet_ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
    MACAddress mac = inet_ift->getInterface(0)->getMacAddress();

    //output address
    EV <<"SwitchID:" << mac.str() << " SwitchPath:" << this->getFullPath() << '\n';

    if(relayUnit){
        int dataPlaneGateSize = relayUnit->gateSize("dataPlaneOut");
        //get message from factory
        OFP_Features_Reply *featuresReply = OFMessageFactory::instance()->createFeaturesReply(mac.str(), buffer.getCapacity(), 1, 0, dataPlaneGateSize);

        //send message
        socket.send(featuresReply);
    }
}


void OF_SwitchAgent::handleFlowModMessage(Open_Flow_Message *of_msg){
    EV << "OFA_switch::handleFlowModMessage" << '\n';
    if(OFP_Flow_Mod *flowModMsg = dynamic_cast<OFP_Flow_Mod *> (of_msg)){
        _flowTables[flowModMsg->getTable_id()]->handleFlowMod(flowModMsg);
    }
}

/**
 * This method belongs here because it only operates on switchAgent members so there
 * is no need to move it to the data plane
 */
void OF_SwitchAgent::handleMissMatchedPacket(EthernetIIFrame *frame){
    OFP_Packet_In *packetIn;
    if (sendCompletePacket || buffer.isfull()) {

#if OFP_VERSION_IN_USE == OFP_100
        packetIn = OFMessageFactory::instance()->createPacketIn(OFPR_NO_MATCH,
                frame);
#elif OFP_VERSION_IN_USE == OFP_151
        packetIn = OFMessageFactory::instance()->createPacketIn(
                OFPR_TABLE_MISS, frame);
#endif

    } else {
        auto buffer_id = buffer.storeMessage(frame->dup());
#if OFP_VERSION_IN_USE == OFP_100
        packetIn = OFMessageFactory::instance()->createPacketIn(OFPR_NO_MATCH,
                frame, buffer_id, false);
#elif OFP_VERSION_IN_USE == OFP_151
        packetIn = OFMessageFactory::instance()->createPacketIn(
                OFPR_TABLE_MISS, frame, buffer_id, false);
#endif
    }
    socket.send(packetIn);
}


void OF_SwitchAgent::handlePacketOutMessage(Open_Flow_Message *of_msg)
{
    OFP_Packet_Out *packet_out_msg = (OFP_Packet_Out *) of_msg;
    uint32_t bufferId = packet_out_msg->getBuffer_id();
    uint32_t inPort = packet_out_msg->getIn_port();
    unsigned int actions_size = packet_out_msg->getActionsArraySize();
    EthernetIIFrame *frame;
    if (bufferId != OFP_NO_BUFFER)
    {
        frame = buffer.returnMessage(bufferId);
    }
    else
    {
        frame = dynamic_cast<EthernetIIFrame *>(packet_out_msg->decapsulate());
    }
    for (unsigned int i = 0; i < actions_size; ++i)
    {
        auto action = packet_out_msg->getActions(i);
        relayUnit->executePacketOutAction(&(action), frame, inPort);
    }
    take(frame);
    delete frame;
}

void OF_SwitchAgent::receiveSignal(cComponent *src, simsignal_t id, cObject *value, cObject *details){
    if(isConnectedToController()){
        Enter_Method_Silent();
        EthernetIIFrame* tmp = check_and_cast<EthernetIIFrame*>(value);
        if(forwardToConSign == id){
            forwardFrameToController(tmp);
        }else if(tableMissSign == id){
            handleMissMatchedPacket(tmp);
        }
    }
}

bool OF_SwitchAgent::isConnectedToController(void){
    return (socket.getState() == TCPSocket::CONNECTED) && (this->hasController);
}

void OF_SwitchAgent::finish(){
    recordScalar("packetsControlPlane", controlPlanePacket);
}

void OF_SwitchAgent::handleParameterChange(const char* parname) {
    //read ned file parameters
    if (!parname || !strcmp(parname, "serviceTime")){
        ofServiceTime = par("serviceTime").doubleValue();
    }
    if (!parname || !strcmp(parname, "sendCompletePacket")){
        sendCompletePacket = par("sendCompletePacket").boolValue();
    }
    if (!parname || !strcmp(parname, "parallelProcessing")){
        parallelProcessing = par("parallelProcessing").boolValue();
    }


}

void OF_SwitchAgent::forwardFrameToController(EthernetIIFrame* frame){
    //send it to the controller
#if OFP_VERSION_IN_USE == OFP_100
    OFP_Packet_In *packetIn =
            OFMessageFactory::instance()->createPacketIn(OFPR_ACTION, frame);
#elif OFP_VERSION_IN_USE == OFP_151
    OFP_Packet_In *packetIn = OFMessageFactory::instance()->createPacketIn(OFPR_ACTION_SET, frame->dup());
#endif

    socket.send(packetIn);
}

} /*end namespace SDN4CoRE*/
