//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "TSNLearningControllerApp.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"
#include "core4inet/linklayer/ethernet/base/EtherFrameWithQTag_m.h"

using namespace openflow;

namespace SDN4CoRE{

Define_Module(TSNLearningControllerApp);

void TSNLearningControllerApp::initialize()
{
    AVBLearningControllerApp::initialize();
}

void TSNLearningControllerApp::handleParameterChange(const char* parname)
{
    AVBLearningControllerApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "staticPriorities"))
    {
        _staticPriorities = cStringTokenizer(par("staticPriorities"), ",").asIntVector();
    }
}

oxm_basic_match TSNLearningControllerApp::createMatchFromPacketIn(
        OFP_Packet_In* packetIn)
{
    if(CoRE4INET::EthernetIIFrameWithQTag* qframe = dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag *>(packetIn->getEncapsulatedPacket()))
    {
        CommonHeaderFields headerFields = extractCommonHeaderFields(packetIn);
        uint8_t vlanpcp = qframe->getPcp();
        auto builder = OFMatchFactory::getBuilder();
        builder->setField(OFPXMT_OFB_ETH_DST, &headerFields.dst_mac);
        builder->setField(OFPXMT_OFB_ETH_TYPE, &headerFields.eth_type);
        builder->setField(OFPXMT_OFB_ETH_SRC, &headerFields.src_mac);
        builder->setField(OFPXMT_OFB_IN_PORT, &headerFields.inport);
        builder->setField(OFPXMT_OFB_VLAN_PCP,&vlanpcp);
        oxm_basic_match match = builder->build();
        return match;
    }
    else
    {
        return AVBLearningControllerApp::createMatchFromPacketIn(packetIn);
    }
}

void TSNLearningControllerApp::doSwitching(OFP_Packet_In* packet_in_msg)
{
    if(CoRE4INET::EthernetIIFrameWithQTag* qframe = dynamic_cast<CoRE4INET::EthernetIIFrameWithQTag *>(packet_in_msg->getEncapsulatedPacket()))
    {
        for(int staticPriority: _staticPriorities){
            if(qframe->getPcp() == staticPriority){
                dropPacket(packet_in_msg);
                return;
            }
        }
    }
    AVBLearningControllerApp::doSwitching(packet_in_msg);
}

} /*end namespace SDN4CoRE*/
