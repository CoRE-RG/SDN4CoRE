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


#ifndef OPENFLOW_REALTIME_CONTROLLERAPPS_MACTABLEMANAGEMENT_H_
#define OPENFLOW_REALTIME_CONTROLLERAPPS_MACTABLEMANAGEMENT_H_

#include <omnetpp.h>
#include <sdn4core/controllerState/base/ControllerStateManagementBase.h>
//STD
#include <unordered_map>
//INET
#include "inet/linklayer/common/MACAddress.h"
#include "inet/linklayer/ethernet/switch/MACAddressTable.h"
//openflow
#include "openflow/openflow/controller/Switch_Info.h"


namespace SDN4CoRE{

#define MAC_MANAGER_OUTPORT_FLOOD -1

/**
 * MACTableManagement manages the MAC tables for a controller application.
 * It holds one MACTabel per switch.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class MACTableManagement : public ControllerStateManagementBase<inet::MACAddressTable> {
public:

    /**
     * Updates the MAC table according to the Header Fields provided.
     * @param sw_info       the switch to update
     * @param source        the source to update
     * @param in_port       the in port to update
     * @return True if refreshed. False if it is new.
     */
    bool update(openflow::Switch_Info* sw_info, inet::MACAddress source, uint32_t in_port, int vlan_id=0);

    /**
     * Lookup the output port a destination mac address at a switch.
     * @param sw_info       the switch to lookup
     * @param destination   the destination to lookup
     * @return              return the port to output the packet to.
     *                      return -1 if there is no entry in the table.
     */
    int lookup(openflow::Switch_Info* sw_info, inet::MACAddress destination, int vlan_id=0);

protected:

    /**
     * override method from ControllerStateManagementBase to react to srpTable creation
     */
    virtual void onCreateManagedState(inet::MACAddressTable* managedState,
            openflow::Switch_Info* swinfo) override;
};

} /*end namespace SDN4CoRE*/

#endif /* OPENFLOW_REALTIME_CONTROLLERAPPS_MACTABLEMANAGEMENT_H_ */
