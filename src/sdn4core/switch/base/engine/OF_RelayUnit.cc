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
//CoRE4INET
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
//SDN4CoRE
#include <sdn4core/switch/base/engine/OF_SwitchAgent.h>
#include <sdn4core/switch/base/engine/OF_RelayUnit.h>

using namespace std;
using namespace inet;
using namespace openflow;


namespace SDN4CoRE{

Define_Module(OF_RelayUnit);


OF_RelayUnit::OF_RelayUnit() {}
OF_RelayUnit::~OF_RelayUnit() {}

void OF_RelayUnit::initialize(int stage){

    switch(stage){
        case INITSTAGE_LOCAL: {
            //stats
            dpPingPacketHash = registerSignal("dpPingPacketHash");
            cpPingPacketHash = registerSignal("cpPingPacketHash");

            forwardToConSign = registerSignal("forwardToConSign");
            tableMissSign = registerSignal("tableMissSign");

            dataPlanePacket=0l;
            flowTableHit=0l;
            flowTableMiss=0l;

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
//      Init all ports
        portVector.resize(gateSize("dataPlaneIn"));
        for(unsigned int i=0;i<portVector.size();i++){
            portVector[i].port_no = i+1;
            cModule *ethernetModule = gate("dataPlaneOut",i)->getNextGate()->getOwnerModule()->getSubmodule("mac");
            if(dynamic_cast<EtherMACBase *>(ethernetModule) != NULL) {
                EtherMACBase *nic = (EtherMACBase *)ethernetModule;
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
                            throw cRuntimeError ("OF_SwitchAgent::initialize(): could not read flow table the index is not specified.");
                        }
                        _flowTables[index]->importFromXML(flowTableXML[i]);
                    }
                }
            }
        }
        break;
    }
    //    case INITSTAGE_LAST:

    default:
        break;
    }
}

void OF_RelayUnit::processDataPlanePacket(cMessage *msg){
    dataPlanePacket++;
    if (EthernetIIFrame *frame = dynamic_cast<EthernetIIFrame *>(msg)) {
        //msg from dataplane
        processFrame(frame);
    } else {
        delete msg;
    }
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
                emit(forwardToConSign,frame->dup());
            } else {
                //send it out the dataplane on the specific port
                send(frame->dup(), "dataPlaneOut", outport);
            }
        }
    } else {
        // lookup failed
        flowTableMiss++;
        EV << "No Entry Found contacting controller" << '\n';
        emit(tableMissSign,frame->dup());
    }
    delete frame;
}

oxm_basic_match OF_RelayUnit::extractMatch(EthernetIIFrame* frame) {
    oxm_basic_match match = oxm_basic_match();

    //extract match fields
    match.OFB_IN_PORT = frame->getArrivalGate()->getIndex();
    match.OFB_ETH_SRC = frame->getSrc();
    match.OFB_ETH_DST = frame->getDest();
    match.OFB_ETH_TYPE = frame->getEtherType();
    if(CoRE4INET::EthernetIIFrameWithQTag* qFrame =
            dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag*>(frame)){
        //we have a q frame!
        match.OFB_VLAN_VID = qFrame->getVID();
        match.OFB_VLAN_PCP = qFrame->getPcp();
    }

    //extract ARP specific match fields if present
    if (frame->getEtherType() == ETHERTYPE_ARP) {
        ARPPacket* arpPacket = check_and_cast<ARPPacket*>(
                frame->getEncapsulatedPacket());
        match.OFB_IP_PROTO = arpPacket->getOpcode();
        match.OFB_IPV4_SRC = arpPacket->getSrcIPAddress();
        match.OFB_IPV4_DST = arpPacket->getDestIPAddress();
    }

    //extract IPv4 fields if present
    //if(frame->getEtherType()==IPv4Datagram) {
    if (IPv4Datagram* ipv4Datagram =
            dynamic_cast<IPv4Datagram*>(frame->getEncapsulatedPacket())) {
        match.OFB_IP_PROTO = ipv4Datagram->getTransportProtocol();
        match.OFB_IPV4_SRC = ipv4Datagram->getSourceAddress().toIPv4();
        match.OFB_IPV4_DST = ipv4Datagram->getDestinationAddress().toIPv4();

        //extract transport if present
        if (ITransportPacket* transport =
                dynamic_cast<ITransportPacket*>(ipv4Datagram->getEncapsulatedPacket())) {
            // Transport packet.
            match.OFB_TP_SRC = transport->getSourcePort();
            match.OFB_TP_DST = transport->getDestinationPort();
        }
    }

    return match;
}

// packet encapsulated and not stored in buffer
void OF_RelayUnit::executePacketOutAction(ofp_action_output *action_output, EthernetIIFrame *frame, uint32_t inport){
    Enter_Method("executePacketOutAction");
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

void OF_RelayUnit::handleMessage(cMessage *msg){
    if(msg->arrivedOn("dataPlaneIn")){
        processDataPlanePacket(msg);
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

    if(par("highlightActivePorts").boolValue()){
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

}
