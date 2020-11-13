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


#include <sdn4core/controllerApps/avb/AVBSecurityControllerApp.h>

//inet
#include <inet/common/ModuleAccess.h>
#include "inet/networklayer/ipv4/IPv4Datagram.h"
#include "inet/transportlayer/contract/ITransportPacket.h"
//AUTO_GENERATED MESSAGES
#include "inet/networklayer/arp/ipv4/ARPPacket_m.h"
//CoRE4INET
#include "core4inet/base/avb/AVBDefs.h"
//AUTO_GENERATED MESSAGES
#include "core4inet/linklayer/ethernet/avb/AVBFrame_m.h"
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"
//openflow
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"

namespace SDN4CoRE {

using namespace inet;
using namespace std;
using namespace CoRE4INET;
using namespace openflow;

Define_Module(AVBSecurityControllerApp);

AVBSecurityControllerApp::AVBSecurityControllerApp() : AVBLearningControllerApp(){
}

AVBSecurityControllerApp::~AVBSecurityControllerApp() {
}

void AVBSecurityControllerApp::initialize() {
    AVBLearningControllerApp::initialize();

    setState(OK);
    _trafficLight = getModuleFromPar<ColorChangingNode>(par("pathToTrafficLight"), this, false);

    this->handleParameterChange(nullptr);
}

void AVBSecurityControllerApp::handleParameterChange(const char* parname)
{
    AVBLearningControllerApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "NADSPort"))
    {
        _NADSPort = par("NADSPort");
    }
    if (!parname || !strcmp(parname, "controllerMAC"))
    {
        _controllerMAC.setAddress(par("controllerMAC").stringValue());
    }
    if (!parname || !strcmp(parname, "allowNewFlows"))
    {
        _allowNewFlows = par("allowNewFlows").boolValue();
    }
    if (!parname || !strcmp(parname, "allowNewFlows"))
    {
        _allowARP = par("allowARP").boolValue();
    }
    if (!parname || !strcmp(parname, "allowNewFlows"))
    {
        _allowSRP = par("allowSRP").boolValue();
    }
}

void AVBSecurityControllerApp::handleMessage(cMessage* msg) {

    if(msg->isSelfMessage() && !strcmp(msg->getName(), "AnomalyTimeout")){
        //reset the message scheduled value as we just received one.
        _anomalyScheduled = false;

        //check if this is the last anomaly that happened and no anomalys happend aftwerwards.
        if((_lastAnomaly + _anomalyTimeout <= simTime()) && (_anomalyCount == 0)){
            setState(WARNING);
        } else {
            scheduleSelfMessage();
        }
    }

    if(msg)
        delete msg;
}

void AVBSecurityControllerApp::receiveSignal(cComponent* src, simsignal_t id,
        cObject* obj, cObject* details) {
    bool forwardToBase = true;

    if (id == PacketInSignalId) {
        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            if (dynamic_cast<EthernetIIFrame *>(packet_in->getEncapsulatedPacket())) {
                CommonHeaderFields headerFields = extractCommonHeaderFields(packet_in);
                //check if NADSPort is set
                if(_NADSPort > NADS_PORT_NONE && headerFields.inport == (uint32_t)_NADSPort){
                    //do not forward this as it is for the security module.
                    forwardToBase = false;
                    handleNADSMessage(packet_in);
                }
            }
#if OFP_VERSION_IN_USE == OFP_100
            if(packet_in->getReason() == OFPR_NO_MATCH)
            {// Flow is unknown by switch. Check if it is in our whitelist
                if(!isWhitelisted(packet_in)){
                    // do not forward this flow.
                    if(_state < WARNING)
                        this->setState(WARNING);
                    forwardToBase = false;
                }
            }
#endif
        }
    }

    if(id == PacketFeatureReplySignalId){
        //new switch is connected implement flow for NADS -> Controller, if NADS is active.
        if(_NADSPort > NADS_PORT_NONE){
            if (Open_Flow_Message *msg = dynamic_cast<Open_Flow_Message *>(obj)) {
                handleNewSwitch(msg);
            }
        }
    }

    if(forwardToBase) {
        AVBLearningControllerApp::receiveSignal(src, id, obj, details);
    }
}

void AVBSecurityControllerApp::refreshDisplay() const {
    if (_stateUpdated){
        if(_trafficLight){
            switch (_state){
            case NONE:
                break;

            case OK:
                _trafficLight->setColor("green");
                break;

            case WARNING:
                _trafficLight->setColor("yellow");
                break;

            case DANGER:
                _trafficLight->setColor("red");
                break;

            default:
                break;
            }
        }
        _stateUpdated = false;
    }
}

oxm_basic_match AVBSecurityControllerApp::createMatchFromPacketIn(
        OFP_Packet_In* packetIn) {
    oxm_basic_match match;
    if (packetIn->getBuffer_id() == OFP_NO_BUFFER){
        auto builder = OFMatchFactory::getBuilder();
        // we got the full packet.
        uint16_t in_port = packetIn->getEncapsulatedPacket()->getArrivalGate()->getIndex();
        builder->setField(OFPXMT_OFB_IN_PORT, &in_port);
        if(EthernetIIFrame * frame = dynamic_cast<EthernetIIFrame *>(packetIn->getEncapsulatedPacket())){

            auto mac_src = frame->getSrc();
            builder->setField(OFPXMT_OFB_ETH_SRC, &mac_src);
            auto mac_dest = frame->getDest();
            builder->setField(OFPXMT_OFB_ETH_DST, &mac_dest);

            //check if the frame has Q extensions.
            if(AVBFrame * avbFrame = dynamic_cast<AVBFrame *>(frame)){
                uint16_t avb_type = 0x8100;
                builder->setField(OFPXMT_OFB_ETH_TYPE, &avb_type);
                auto vlan_vid = avbFrame->getVID();
                builder->setField(OFPXMT_OFB_VLAN_VID, &vlan_vid);
                auto vlan_pcp = avbFrame->getPcp();
                builder->setField(OFPXMT_OFB_VLAN_PCP, &vlan_pcp);
            } else {
                uint16_t eth_type = frame->getEtherType();
                builder->setField(OFPXMT_OFB_ETH_TYPE, &eth_type);
            }


            if(ARPPacket *arpPacket = dynamic_cast<ARPPacket *>(frame->getEncapsulatedPacket()))
            {//ARP packet. --> frame->getEtherType() == EtherType::ETHERTYPE_ARP
                //TODO fix --> no rules for arp!
                uint8_t iproto = arpPacket->getOpcode();
                builder->setField(OFPXMT_OFB_IP_PROTO, &iproto);
                auto ip_src = arpPacket->getSrcIPAddress();
                builder->setField(OFPXMT_OFB_IPV4_SRC, &ip_src);
                auto ip_dst = arpPacket->getDestIPAddress();
                builder->setField(OFPXMT_OFB_IPV4_SRC, &ip_dst);
            }
            else if(IPv4Datagram * ipv4Datagram = dynamic_cast<IPv4Datagram *>(frame->getEncapsulatedPacket()))
            {//IPv4 --> frame->getEtherType() == EtherType::ETHERTYPE_IPv4
                uint8_t iproto = ipv4Datagram->getTransportProtocol();
                builder->setField(OFPXMT_OFB_IP_PROTO, &iproto);
                auto ip_src = ipv4Datagram->getSourceAddress().toIPv4();
                builder->setField(OFPXMT_OFB_IPV4_SRC, &ip_src);
                auto ip_dst = ipv4Datagram->getSourceAddress().toIPv4();
                builder->setField(OFPXMT_OFB_IPV4_SRC, &ip_dst);
                if(ITransportPacket * transport = dynamic_cast<ITransportPacket *>(ipv4Datagram->getEncapsulatedPacket()))
                {// Transport packet.
                    auto tp_src = transport->getSourcePort();
                    builder->setField(OFPXMT_OFB_TCP_SRC, &tp_src);
                    auto tp_dst = transport->getDestinationPort();
                    builder->setField(OFPXMT_OFB_TCP_DST, &tp_dst);
                }
            }
        }
        match = builder->build();
    } else{
        // we only have match so copy it.
        match = packetIn->getMatch();
    }

    return match;
}

void AVBSecurityControllerApp::sendFlowModMessage(ofp_flow_mod_command mod_com,
        const oxm_basic_match& match, uint32_t outport, inet::TCPSocket* socket,
        int idleTimeOut, int hardTimeOut) {
    EV << "sendFlowModMessage" << '\n';
    numFlowMod++;

    std::vector<int> outports;
    outports.push_back(outport);

    if(match.OFB_IN_PORT != _NADSPort && ((uint32_t)outport) != OFPP_CONTROLLER) {
        checkOrAddNADSPort(&outports);
    }

    //fill int array
    uint32_t out[outports.size()];
    for(size_t i=0; i<outports.size(); i++) {
        out[i] = outports[i];
    }

    OFP_Flow_Mod* flow_mod_msg = OFMessageFactory::instance()->createFlowModMessage(mod_com, match, 0, out, outports.size(), idleTimeOut, hardTimeOut);

    socket->send(flow_mod_msg);
}

void AVBSecurityControllerApp::sendSRPFlowModMessage(ofp_flow_mod_command mod_com, const oxm_basic_match &match, std::vector<int> outports, TCPSocket * socket, int idleTimeOut =1 , int hardTimeOut=0){
    EV << "sendFlowModMessage" << '\n';
    numFlowMod++;

    if(match.OFB_IN_PORT != _NADSPort) {
        checkOrAddNADSPort(&outports);
    }

    //fill int array
    uint32_t out[outports.size()];
    for(size_t i=0; i<outports.size(); i++) {
        out[i] = outports[i];
    }

    OFP_Flow_Mod* flow_mod_msg = OFMessageFactory::instance()->createFlowModMessage(mod_com, match, 5000, out, outports.size(), idleTimeOut, hardTimeOut);

    socket->send(flow_mod_msg);
}

OFP_Packet_Out * AVBSecurityControllerApp::createPacketOutFromPacketIn(OFP_Packet_In *packet_in_msg, uint32_t outport){

    OFP_Packet_Out *packetOut = nullptr;

    std::vector<int> outports;
    outports.push_back(outport);

    int inport = packet_in_msg->getEncapsulatedPacket()->getArrivalGate()->getIndex();
    if(inport != _NADSPort
            && ((uint32_t)outport) != OFPP_CONTROLLER) {
        checkOrAddNADSPort(&outports);
    }

    //fill int array
    uint32_t out[outports.size()];
    for(size_t i=0; i<outports.size(); i++) {
        out[i] = outports[i];
    }

    if (packet_in_msg->getBuffer_id() == OFP_NO_BUFFER){

        EthernetIIFrame *frame =  dynamic_cast<EthernetIIFrame *>(packet_in_msg->getEncapsulatedPacket());
        if(frame){
            packetOut = OFMessageFactory::instance()->createPacketOut(out, outports.size(), frame->getArrivalGate()->getIndex(), packet_in_msg->getBuffer_id(), frame);
        } else {
            throw cRuntimeError("RTSecurityControllerApp::createPacketOutFromPacketIn: OFP_NO_BUFFER was set but no frame was provided in packet in");
        }
    } else {
        packetOut = OFMessageFactory::instance()->createPacketOut(out, outports.size(), packet_in_msg->getMatch().OFB_IN_PORT, packet_in_msg->getBuffer_id());
    }

    return packetOut;
}

void AVBSecurityControllerApp::handleNewSwitch(Open_Flow_Message* msg) {
    // create ofp match
    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_ETH_DST, &_controllerMAC);
    builder->setField(OFPXMT_OFB_IN_PORT, &_NADSPort);
    oxm_basic_match match = builder->build();

    // find TCP socket.
    TCPSocket * socket = controller->findSocketFor(msg);

    // send new flow mod for NADS -> Controller connection.
    sendFlowModMessage(OFPFC_ADD, match, OFPP_CONTROLLER, socket, 0, 0);

}

void AVBSecurityControllerApp::scheduleSelfMessage() {
    //set timer for status reset
    if (!_anomalyScheduled) {
        if((_lastAnomaly + _anomalyTimeout) > simTime()){
            cMessage* timeout = new cMessage("AnomalyTimeout");
            this->take(timeout);
            this->scheduleAt(_lastAnomaly + _anomalyTimeout, timeout);
            _anomalyCount = 0;
            _anomalyScheduled = true;
        }
    }
}

void AVBSecurityControllerApp::handleNADSMessage(OFP_Packet_In* msg) {
    this->setState(DANGER);
    _lastAnomaly = simTime();
    _anomalyCount++;
#if OFP_VERSION_IN_USE == OFP_100
    if(msg->getReason() == OFPR_NO_MATCH)
    {//miss allthough a flow should be implemented.
        //handle new switch.
        handleNewSwitch(msg);
    }
#endif

    //TODO not always delete same flow :-P
    //delete flow
    //stats
    TCPSocket * socket = controller->findSocketFor(msg);
    numFlowMod++;

    auto eth_type = 2048;
    auto dst_mac = MACAddress("0A-00-00-00-00-03");
    auto src_mac = MACAddress("0A-00-00-00-00-10");
    auto ip_proto = 17;
    auto ip_src = IPv4Address("192.168.0.1");
    auto ip_dst = IPv4Address("192.168.0.13");
    auto tp_src = 6666;
    auto tp_dst = 6666;

    auto builder = OFMatchFactory::getBuilder();
    builder->setField(OFPXMT_OFB_ETH_DST, &dst_mac);
    builder->setField(OFPXMT_OFB_ETH_TYPE, &eth_type);
    builder->setField(OFPXMT_OFB_ETH_SRC, &src_mac);
    builder->setField(OFPXMT_OFB_IP_PROTO, &ip_proto);
    builder->setField(OFPXMT_OFB_IPV4_SRC, &ip_src);
    builder->setField(OFPXMT_OFB_IPV4_SRC, &ip_dst);
    builder->setField(OFPXMT_OFB_TCP_SRC, &tp_src);
    builder->setField(OFPXMT_OFB_TCP_DST, &tp_dst);
    oxm_basic_match match = builder->build();

    //create message and deliver
    OFP_Flow_Mod* flow_mod_msg = OFMessageFactory::instance()->createFlowModMessage(OFPFC_DELETE, match, 0, NULL, 0, 0, 0);
    socket->send(flow_mod_msg);

    //set timer for status reset
    scheduleSelfMessage();

}

void AVBSecurityControllerApp::finish(){
    AVBLearningControllerApp::finish();

}

bool AVBSecurityControllerApp::checkOrAddNADSPort(std::vector<int>* portlist) {
    bool updated = false;
    bool containsNads = false;
    if(_NADSPort > NADS_PORT_NONE){
        for(auto iter = (*portlist).begin(); iter < (*portlist).end(); iter++){
            if(_NADSPort == (*iter)) {
                containsNads = true;
                break;
            }
        }
        if(!containsNads) {
            (*portlist).push_back(_NADSPort);
            updated = true;
        }
    }

    return updated;
}

bool AVBSecurityControllerApp::isWhitelisted(OFP_Packet_In* packetIn) {
    bool whitelisted = _allowNewFlows;
    if(EthernetIIFrame *frame =  dynamic_cast<EthernetIIFrame *>(packetIn->getEncapsulatedPacket())){
        if(frame->getEtherType() == EtherType::ETHERTYPE_ARP){
            //allow arp?
            whitelisted = _allowARP;
        }
    } else if (dynamic_cast<CoRE4INET::SRPFrame *>(packetIn->getEncapsulatedPacket())){
        whitelisted = _allowSRP;
    }

    return whitelisted;
}

} /* namespace SDN4CoRE */
