#include <sdn4core/switch/base/engine/OF_RelayUnit.h>

#include <openflow/openflow/protocol/OpenFlow.h>
#include "openflow/openflow/util/ofmessagefactory/OFMessageFactory.h"
#include "openflow/messages/openflowprotocol/OFP_Message.h"
#include "openflow/messages/openflowprotocol/OFP_Features_Reply.h"
#include "openflow/messages/openflowprotocol/OFP_Hello.h"
#include "openflow/messages/openflowprotocol/OFP_Packet_In.h"
#include "openflow/messages/openflowprotocol/OFP_Packet_Out.h"
#include "openflow/messages/openflowprotocol/OFP_Flow_Mod.h"
//STD
#include <sstream>
#include <string>
//INET
#include "inet/linklayer/ethernet/EtherMAC.h"
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/ITransportPacket.h"
#include "inet/common/ModuleAccess.h"
#include "inet/networklayer/common/InterfaceTable.h"
#include "inet/networklayer/ipv4/ICMPMessage.h"
//Auto-generated Messages
//INET
#include "inet/networklayer/arp/ipv4/ARPPacket_m.h"
#include "inet/applications/pingapp/PingPayload_m.h"


using namespace std;
using namespace inet;
using namespace ofp;


namespace SDN4CoRE{

Define_Module(OF_RelayUnit);

#define MSGKIND_CONNECT                     1
#define MSGKIND_SERVICETIME                 3


OF_RelayUnit::OF_RelayUnit(){
}

OF_RelayUnit::~OF_RelayUnit(){
    for(auto&& entry : msgList) {
      delete entry;
    }
    msgList.clear();
}

void OF_RelayUnit::initialize(int stage){

    switch(stage){
    case INITSTAGE_LOCAL: {
        busy = false;

        handleParameterChange(nullptr);

        //stats
        dpPingPacketHash = registerSignal("dpPingPacketHash");
        cpPingPacketHash = registerSignal("cpPingPacketHash");
        queueSize = registerSignal("queueSize");
        bufferSize = registerSignal("bufferSize");
        waitingTime = registerSignal("waitingTime");
        dataPlanePacket=0l;
        controlPlanePacket=0l;
        flowTableHit=0l;
        flowTableMiss=0l;

        //init helper classes
        buffer = Buffer((int)par("bufferCapacity"));

        //load table modules.
        int numFlowTables = getParentModule()->getSubmodule("flowTables",0)->getVectorSize();
        for (int i = 0; i < numFlowTables; i++) {
            if(OF_FlowTable* table = dynamic_cast<OF_FlowTable*> (getParentModule()->getSubmodule("flowTables",i))){
                _flowTables.push_back(table);
            }
        }
        break;
    }
//    case INITSTAGE_PHYSICAL_ENVIRONMENT:
//    case INITSTAGE_PHYSICAL_ENVIRONMENT_2:
//    case INITSTAGE_PHYSICAL_LAYER:
//    case INITSTAGE_LINK_LAYER:
//    case INITSTAGE_LINK_LAYER_2:
    case INITSTAGE_NETWORK_LAYER: {
        // Init all ports
        portVector.resize(gateSize("dataPlaneIn"));
        for(unsigned int i=0;i<portVector.size();i++){
            portVector[i].port_no = i+1;
            cModule *ethernetModule = gate("dataPlaneOut",i)->getNextGate()->getOwnerModule()->getSubmodule("mac");
            if(dynamic_cast<EtherMAC *>(ethernetModule) != NULL) {
                EtherMAC *nic = (EtherMAC *)ethernetModule;
                uint64_t tmpHw = nic->getMACAddress().getInt();
                memcpy(portVector[i].hw_addr,&tmpHw, sizeof tmpHw);
            }

            sprintf(portVector[i].name,"Port: %d",i);
            portVector[i].config =0;
            portVector[i].state =0;
            //TODO fix wildcards for OFP151!
    #if OFP_VERSION_IN_USE == OFP_100
            portVector[i].curr =0;
            portVector[i].advertised =0;
            portVector[i].supported =0;
            portVector[i].peer =0;
            portVector[i].curr_speed =0;
            portVector[i].max_speed =0;
    #endif
        }
        break;
    }
//    case INITSTAGE_NETWORK_LAYER_2:
//    case INITSTAGE_NETWORK_LAYER_3:
    case INITSTAGE_TRANSPORT_LAYER: {
        //init socket to controller
        const char *localAddress = par("localAddress");
        int localPort = par("localPort");

        socket.bind(*localAddress ? L3Address(localAddress) : L3Address(), localPort);
        socket.setOutputGate(gate("controlPlaneOut"));
        socket.setDataTransferMode(TCP_TRANSFER_OBJECT);
        break;
    }
//    case INITSTAGE_TRANSPORT_LAYER_2:
//    case INITSTAGE_ROUTING_PROTOCOLS:
    case INITSTAGE_APPLICATION_LAYER: {
        //load XML config if specified.
        cXMLElement* xmlDoc = par("configXML").xmlValue();
        if(xmlDoc){
            if(strcmp(xmlDoc->getName(), "config") == 0){
                string switchName = getParentModule()->getSubmodule("eth", 0)->getSubmodule("mac")->par("address").stringValue();
                if(cXMLElement* switchConfigXML = xmlDoc->getFirstChildWithAttribute("switch", "id", switchName.c_str()))
                {//there is a config for this switch.
                    cXMLElementList flowTableXML = switchConfigXML->getChildrenByTagName("flowTable");
                    for (size_t i=0; i<flowTableXML.size(); i++)
                    {//the config contains a flow tables so set them.
                        int index = i;
                        if(const char* value = flowTableXML[i]->getAttribute("index")){
                            index = atoi(value);
                        } else if(flowTableXML.size() == 1){
                            // do nothing
                        } else {
                            throw cRuntimeError ("OF_RelayUnit::initialize(): could not read flow table the index is not specified.");
                        }
                        _flowTables[index]->importFromXML(flowTableXML[i]);
                    }
                }
            }
        }
        break;
    }
    case INITSTAGE_LAST: {
        //schedule connection setup
       cMessage *initiateConnection = new cMessage("initiateConnection");
       initiateConnection->setKind(MSGKIND_CONNECT);
       scheduleAt(par("connectAt"), initiateConnection);

       //remove unused nics from ift
       IInterfaceTable* interfaceTable = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
       for(int i=0; i< interfaceTable->getNumInterfaces() ;i++){
           if(interfaceTable->getInterface(i) != interfaceTable->getInterfaceByName("eth0")){
               interfaceTable->deleteInterface(interfaceTable->getInterface(i));
               i--;
           }
       }
       break;
    }
    default:
        break;
    }
}

void OF_RelayUnit::handleMessage(cMessage *msg){

    if (msg->isSelfMessage()){
        handleSelfMessage(msg);
    } else if (msg->getKind() == TCP_I_ESTABLISHED) { //fast handle for TCP Established
            socket.processMessage(msg);
    } else {
        simulateServiceTime(msg);
    }
}

void OF_RelayUnit::simulateServiceTime(cMessage* msg) {
    //imlement service time
    if (busy) {
        msgList.push_back(msg);
    } else {
        busy = true;
        cMessage* event = new cMessage("event");
        event->setKind(MSGKIND_SERVICETIME);
        event->setContextPointer(msg);
        scheduleAt(simTime() + serviceTime, event);
    }
    emit(queueSize, msgList.size());
    emit(bufferSize, buffer.size());
}

void OF_RelayUnit::handleSelfMessage(cMessage* msg) {
    if (msg->getKind() == MSGKIND_CONNECT) {
        EV << "starting session" << '\n';
        connect(""); // active OPEN
    } else if (msg->getKind() == MSGKIND_SERVICETIME) {
        //This is message which has been scheduled due to service time
        //Get the Original message
        cMessage* data_msg = (cMessage*) (msg->getContextPointer());
        emit(waitingTime,
                (simTime() - data_msg->getArrivalTime() - serviceTime));
        processQueuedMsg(data_msg);
        //delete the processed msg
        delete data_msg;
        //Trigger next service time
        if (msgList.empty()) {
            busy = false;
        } else {
            cMessage* msgFromList = msgList.front();
            msgList.pop_front();
            cMessage* event = new cMessage("event");
            event->setKind(MSGKIND_SERVICETIME);
            event->setContextPointer(msgFromList);
            scheduleAt(simTime() + serviceTime, event);
        }
    }

    //delete the msg for efficiency
    delete msg;
}

void OF_RelayUnit::connect(const char *addressToConnect){
    socket.renewSocket();
    const char *connectAddress;

    int connectPort = par("connectPort");

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

void OF_RelayUnit::processQueuedMsg(cMessage *data_msg){

     if(data_msg->arrivedOn("dataPlaneIn")){
        dataPlanePacket++;
        if(socket.getState() != TCPSocket::CONNECTED){
            //not yet connected to controller
            //drop packet by returning
            return;
        } else if (EthernetIIFrame *frame = dynamic_cast<EthernetIIFrame *>(data_msg)) {
            //msg from dataplane
            //copy the frame as the original will be deleted
            EthernetIIFrame *copy = frame->dup();
            processFrame(copy);
        }
    } else {
        controlPlanePacket++;
       if (dynamic_cast<OFP_Message *>(data_msg) != NULL) { //msg from controller
            OFP_Message *of_msg = (OFP_Message *)data_msg;
            ofp_type type = (ofp_type)of_msg->getHeader().type;
            switch (type){
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
                    break;
                }
        }

    }

}

oxm_basic_match OF_RelayUnit::extractMatch(EthernetIIFrame* frame) {
    oxm_basic_match match = oxm_basic_match();

    //extract match fields
    match.in_port = frame->getArrivalGate()->getIndex();
    match.dl_src = frame->getSrc();
    match.dl_dst = frame->getDest();
    match.dl_type = frame->getEtherType();

    //extract ARP specific match fields if present
    if (frame->getEtherType() == ETHERTYPE_ARP) {
        ARPPacket* arpPacket = check_and_cast<ARPPacket*>(
                frame->getEncapsulatedPacket());
        match.nw_proto = arpPacket->getOpcode();
        match.nw_src = arpPacket->getSrcIPAddress();
        match.nw_dst = arpPacket->getDestIPAddress();
    }

    //extract IPv4 fields if present
    //if(frame->getEtherType()==IPv4Datagram) {
    if (IPv4Datagram* ipv4Datagram =
            dynamic_cast<IPv4Datagram*>(frame->getEncapsulatedPacket())) {
        match.nw_proto = ipv4Datagram->getTransportProtocol();
        match.nw_src = ipv4Datagram->getSourceAddress().toIPv4();
        match.nw_dst = ipv4Datagram->getDestinationAddress().toIPv4();

        //extract transport if present
        if (ITransportPacket* transport =
                dynamic_cast<ITransportPacket*>(ipv4Datagram->getEncapsulatedPacket())) {
            // Transport packet.
            match.tp_src = transport->getSourcePort();
            match.tp_dst = transport->getDestinationPort();
        }
    }

    return match;
}

void OF_RelayUnit::processFrame(EthernetIIFrame *frame) {
    //get all relevant match fiels
    oxm_basic_match match = extractMatch(frame);

    unsigned long hash = 0;

    //emit id of ping packet to indicate where it was processed
    if (dynamic_cast<ICMPMessage *>(frame->getEncapsulatedPacket()->getEncapsulatedPacket())
            != NULL) {
        ICMPMessage *icmpMessage =
                (ICMPMessage *) frame->getEncapsulatedPacket()->getEncapsulatedPacket();

        PingPayload * pingMsg =
                (PingPayload *) icmpMessage->getEncapsulatedPacket();
        //generate and emit hash
        std::stringstream hashString;
        hashString << "SeqNo-" << pingMsg->getSeqNo() << "-Pid-"
                << pingMsg->getOriginatorId();
        hash = std::hash<std::string>()(hashString.str().c_str());
    }

    if (hash != 0) {
        emit(cpPingPacketHash, hash);
    }

    OF_FlowTableEntry *lookup = _flowTables[0]->lookup(match);
    if (lookup != nullptr) {
        //lookup successful
        flowTableHit++;
        EV << "Found entry in flow table." << '\n';
        for (size_t i = 0; i < lookup->getInstructions().size(); i++) {
            ofp_action_output action_output = lookup->getInstructions()[i];
            uint32_t outport = action_output.port;
            if (outport == OFPP_CONTROLLER) {
                //send it to the controller
#if OFP_VERSION_IN_USE == OFP_100
                OFP_Packet_In *packetIn =
                        OFMessageFactory::instance()->createPacketIn(
                                OFPR_ACTION, frame);
#elif OFP_VERSION_IN_USE == OFP_151
                OFP_Packet_In *packetIn = OFMessageFactory::instance()->createPacketIn(OFPR_ACTION_SET, frame->dup());
#endif

                socket.send(packetIn);
            } else {
                //send it out the dataplane on the specific port
                send(frame->dup(), "dataPlaneOut", outport);
            }
        }
    } else {
        // lookup failed
        flowTableMiss++;
        EV << "No Entry Found contacting controller" << '\n';
        handleMissMatchedPacket(frame);
    }
    delete frame;
}

void OF_RelayUnit::handleFeaturesRequestMessage(OFP_Message *of_msg){
    //prepare data
    IInterfaceTable *inet_ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);

    MACAddress mac = inet_ift->getInterface(0)->getMacAddress();

    //output address
    EV <<"SwitchID:" << mac.str() << " SwitchPath:" << this->getFullPath() << '\n';

    //get message from factory
    OFP_Features_Reply *featuresReply = OFMessageFactory::instance()->createFeaturesReply(mac.str(), buffer.getCapacity(), 1, 0, gateSize("dataPlaneOut"));

    //send message
    socket.send(featuresReply);
}

void OF_RelayUnit::handleFlowModMessage(OFP_Message *of_msg){
    EV << "OFA_switch::handleFlowModMessage" << '\n';
    if(OFP_Flow_Mod *flowModMsg = dynamic_cast<OFP_Flow_Mod *> (of_msg)){
        _flowTables[flowModMsg->getTable_id()]->handleFlowMod(flowModMsg);
    }
}

void OF_RelayUnit::handleMissMatchedPacket(EthernetIIFrame *frame){
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

#if OFP_VERSION_IN_USE == OFP_100
        packetIn = OFMessageFactory::instance()->createPacketIn(OFPR_NO_MATCH,
                frame, buffer.storeMessage(frame), false);
#elif OFP_VERSION_IN_USE == OFP_151
        packetIn = OFMessageFactory::instance()->createPacketIn(
                OFPR_TABLE_MISS, frame, buffer.storeMessage(frame), false);
#endif

    }


    socket.send(packetIn);
}

void OF_RelayUnit::handlePacketOutMessage(OFP_Message *of_msg){
    //cast message
    OFP_Packet_Out *packet_out_msg = (OFP_Packet_Out *) of_msg;

    //return variables
    uint32_t bufferId = packet_out_msg->getBuffer_id();
    uint32_t inPort = packet_out_msg->getIn_port();
    unsigned int actions_size = packet_out_msg->getActionsArraySize();

    //get the frame
    EthernetIIFrame *frame;
    if(bufferId != OFP_NO_BUFFER){
        frame = buffer.returnMessage(bufferId);
    } else {
        frame = dynamic_cast<EthernetIIFrame *>(packet_out_msg->getEncapsulatedPacket());
        frame = frame->dup();
    }

    //execute
    for (unsigned int i = 0; i < actions_size; ++i){
        executePacketOutAction(&(packet_out_msg->getActions(i)), frame, inPort);
    }
    delete frame;
}


// packet encapsulated and not stored in buffer
void OF_RelayUnit::executePacketOutAction(ofp_action_output *action_output, EthernetIIFrame *frame, uint32_t inport){
    uint32_t outport = action_output->port;
    take(frame);


    if(outport == OFPP_ANY){
           EV << "Dropping packet" << '\n';
    } else if (outport == OFPP_FLOOD){
        EV << "Flood Packet\n" << '\n';

        unsigned int n = gateSize("dataPlaneOut");
        for (unsigned int i=0; i<n; ++i) {
            if(i != inport && !(portVector[i].state & OFPPS_BLOCKED)){
                send(frame->dup(), "dataPlaneOut", i);
            }
        }
    }else {
        EV << "Send Packet\n" << '\n';
        send(frame->dup(), "dataPlaneOut", outport);
    }
}

// invoked by Spanning Tree module disable ports for broadcast packets
void OF_RelayUnit::disablePorts(vector<int> ports) {
    EV << "disablePorts method at " << this->getParentModule()->getFullPath() << '\n';

    for (unsigned int i = 0; i<ports.size(); ++i){
        portVector[ports[i]].state |= OFPPS_BLOCKED;
    }

    for(unsigned int i=0;i<portVector.size();++i){
        EV << "Port: " << i << " Value: " << portVector[i].state << '\n';
    }

    if(par("highlightActivePorts")){
        // Highlight links that belong to spanning tree
        for (unsigned int i = 0; i < portVector.size(); ++i){
            if (!(portVector[i].state & OFPPS_BLOCKED)){
                cGate *gateOut = getParentModule()->gate("gateDataPlane$o", i);
                do {
                    cDisplayString& connDispStrOut = gateOut->getDisplayString();
                    connDispStrOut.parse("ls=green,3,dashed");
                    gateOut=gateOut->getNextGate();
                } while (!gateOut->getOwnerModule()->getModuleType()->isSimple());

                cGate *gateIn = getParentModule()->gate("gateDataPlane$i", i);
                do {
                    cDisplayString& connDispStrIn = gateIn->getDisplayString();
                    connDispStrIn.parse("ls=green,3,dashed");
                    gateIn=gateIn->getPreviousGate();
                } while (!gateIn->getOwnerModule()->getModuleType()->isSimple());
            }
        }
    }

}

void OF_RelayUnit::finish(){
    // record statistics
    recordScalar("packetsDataPlane", dataPlanePacket);
    recordScalar("packetsControlPlane", controlPlanePacket);
    recordScalar("flowTableHit", flowTableHit);
    recordScalar("flowTableMiss", flowTableMiss);

    //print flow table


    //xml head
    std::ostringstream oss;
    oss << "<config>" << endl;
    oss << "<switch id=\"" << getParentModule()->getSubmodule("eth", 0)->getSubmodule("mac")->par("address").stringValue() << "\">" << endl;
    for (size_t i = 0; i < _flowTables.size() ; i++){
        oss << _flowTables[i]->exportToXML();
    }
    oss << "</switch>" << endl;
    oss << "</config>" << endl;
    cout << oss.str();
}

void OF_RelayUnit::handleParameterChange(const char* parname) {
    //read ned file parameters
    if (!parname || !strcmp(parname, "serviceTime")){
        serviceTime = par("serviceTime");
    }
    if (!parname || !strcmp(parname, "sendCompletePacket")){
        sendCompletePacket = par("sendCompletePacket");
    }


}

} /*end namespace SDN4CoRE*/
