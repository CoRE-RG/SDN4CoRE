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
// c Tobias Haugg, for HAW Hamburg

#ifndef SDN4CORE_SWITCH_TSN_ENGINE_TSN_OF_SWITCHAGENT_H_
#define SDN4CORE_SWITCH_TSN_ENGINE_TSN_OF_SWITCHAGENT_H_

#include <sdn4core/switch/base/engine/OF_SwitchAgent.h>
#include "core4inet/linklayer/ethernet/avb/SRPFrame_m.h"

namespace SDN4CoRE {

class TSN_OF_SwitchAgent: public OF_SwitchAgent {
protected:
    virtual void handleMessage(cMessage *msg) override;
    virtual void processControlPlanePacket(cMessage *msg) override;
    /**
     * Handles srp messages arriving from the controller and forward them to the local
     * SRProtocol module.
     * @param msg   incoming srp message
     */
    virtual void handleSRPFromController(cMessage* msg);
    /**
     * Handles openflow port mod messages, in particular @see OFP_TSN_Port_Mod_CBS.
     * @param msg   incoming port mod message
     */
    virtual void handlePortMod(cMessage* msg);
private:
    /**
     * Forward the response of the local SRProtocol module to the controller
     * @param msg   response of SRProtocol
     */
    void sendSRPResponse(CoRE4INET::ListenerReady *msg);
};

}

#endif /* SDN4CORE_SWITCH_TSN_ENGINE_TSN_OF_SWITCHAGENT_H_ */
