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

#include "PacketProcessorBase.h"

//STD
#include <fstream>
#include <sstream>
//inet
#include "inet/transportlayer/contract/tcp/TCPSocket.h"
//openflow
#include "openflow/messages/OFP_Flow_Mod_m.h"
#include "openflow/messages/OFP_Packet_In_m.h"
#include "openflow/openflow/protocol/OFMessageFactory.h"
#include "openflow/openflow/protocol/OFMatchFactory.h"

using namespace inet;
using namespace std;
using namespace openflow;

namespace SDN4CoRE {

void PacketProcessorBase::initialize() {
    AbstractControllerApp::initialize();
}

void PacketProcessorBase::handleParameterChange(const char* parname) {
    AbstractControllerApp::handleParameterChange(parname);
    if (!parname || !strcmp(parname, "flowModIdleTimeOut")) {
        _idleTimeout = par("flowModIdleTimeOut");
    }
    if (!parname || !strcmp(parname, "flowModHardTimeOut")) {
        _hardTimeout = par("flowModHardTimeOut");
    }
}

void PacketProcessorBase::receiveSignal(cComponent* src, simsignal_t id,
        cObject* obj, cObject* details) {
    if (id == PacketInSignalId) {
        if (OFP_Packet_In *packet_in = dynamic_cast<OFP_Packet_In *>(obj)) {
            processPacketIn(packet_in);
        }
    } else if (id == PacketFeatureReplySignalId) {
        if (Open_Flow_Message *msg = dynamic_cast<Open_Flow_Message *>(obj)) {
            //new switch registered check if we allready got a offline config for it.
            processSwitchConnection(controller->findSwitchInfoFor(msg));
        }
    } else {
        AbstractControllerApp::receiveSignal(src, id, obj, details);
    }
}

void PacketProcessorBase::finish() {
    AbstractControllerApp::finish();

    string filename = par("dumpConfig").stdstringValue();
    if (!filename.empty()) {
        ofstream file;
        file.open(filename.c_str(), ios::app);
        if (!file.is_open())
            throw cRuntimeError("Cannot open output file");
        file << stateToXML();
        file.close();
    }
}

} /*end namespace SDN4CoRE*/
