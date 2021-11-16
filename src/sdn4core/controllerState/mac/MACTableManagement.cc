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


#include <sdn4core/controllerState/mac/MACTableManagement.h>

using namespace inet;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(MACTableManagement);

bool MACTableManagement::update(openflow::Switch_Info* sw_info, inet::MACAddress source, uint32_t in_port, int vlan_id) {
    Enter_Method("update");
    MACAddressTable* lookupTable = getOrCreateManagedState(sw_info);
    return lookupTable->updateTableWithAddress(in_port,source,vlan_id);
}

int MACTableManagement::lookup(openflow::Switch_Info* sw_info, inet::MACAddress destination, int vlan_id) {
    Enter_Method("lookup");
    if(MACAddressTable* lookupTable = getManagedState(sw_info)){
        return lookupTable->getPortForAddress(destination, vlan_id);
    }
    return MAC_MANAGER_OUTPORT_FLOOD;
}

void MACTableManagement::onCreateManagedState(MACAddressTable* managedState,
        openflow::Switch_Info* swinfo) {
    ControllerStateManagementBase<MACAddressTable>::onCreateManagedState(managedState, swinfo);
    managedState->setAgingTime(this->par("agingTime").doubleValue());
}

} /*end namespace SDN4CoRE*/
