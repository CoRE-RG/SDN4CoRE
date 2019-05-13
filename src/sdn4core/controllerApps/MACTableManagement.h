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

#ifndef OPENFLOW_REALTIME_CONTROLLERAPPS_MACTABLEMANAGEMENT_H_
#define OPENFLOW_REALTIME_CONTROLLERAPPS_MACTABLEMANAGEMENT_H_


#include "inet/linklayer/common/MACAddress.h"
#include <unordered_map>
#include "openflow/openflow/controller/Switch_Info.h"
#include "openflow/controllerApps/AbstractControllerApp.h"

namespace ofp{

#define MAC_MANAGER_OUTPORT_FLOOD -1

/**
 * MACTableManagement manages the MAC table for a controller application.
 */
class MACTableManagement {
public:
    MACTableManagement(){

    }
    virtual ~MACTableManagement(){

    }

    /**
     * Updates the MAC table according to the Header Fields provided.
     * @param headerFields  The header fields of the incoming packet.
     */
    void updateMacTable(CommonHeaderFields& headerFields);

    /**
     * Get the output port for header fields.
     * @param headerFields  The header fields of the incoming packet.
     * @return              return the port to output the packet to.
     */
    int getOutPort(CommonHeaderFields& headerFields);

    std::unordered_map<Switch_Info*, std::map<inet::MACAddress, uint32_t> >& getLookupTable() {
        return lookupTable;
    }

    void setLookupTable(
            std::unordered_map<Switch_Info*,
                    std::map<inet::MACAddress, uint32_t> >& lookupTable) {
        this->lookupTable = lookupTable;
    }

private:
    /**
     * The MAC table associated with each SDN switch in the network.
     */
    std::unordered_map<Switch_Info *,std::map<inet::MACAddress,uint32_t> > lookupTable;
};

} /*end namespace ofp*/

#endif /* OPENFLOW_REALTIME_CONTROLLERAPPS_MACTABLEMANAGEMENT_H_ */
