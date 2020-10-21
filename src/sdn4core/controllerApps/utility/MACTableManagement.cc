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


#include <sdn4core/controllerApps/utility/MACTableManagement.h>

using namespace inet;
using namespace openflow;

namespace SDN4CoRE{

Define_Module(MACTableManagement);

void MACTableManagement::update(openflow::Switch_Info* sw_info, inet::MACAddress source, uint32_t in_port) {
    //search map for source mac address and enter
    if (lookupTable.count(sw_info) <= 0) {
        lookupTable[sw_info] = std::map<MACAddress, uint32_t>();
        lookupTable[sw_info][source] =
                in_port;
    } else {
        if (lookupTable[sw_info].count(source) <= 0) {
            lookupTable[sw_info][source] =
                    in_port;
        }
    }
}

int MACTableManagement::lookup(openflow::Switch_Info* sw_info, inet::MACAddress destination) {
    long outport = MAC_MANAGER_OUTPORT_FLOOD;
    if(lookupTable.count(sw_info)>0) {
        if (lookupTable[sw_info].count(destination)>0){
            //MACAdress is known so return
            outport = lookupTable[sw_info][destination];
        }
    }
    return outport;
}

} /*end namespace SDN4CoRE*/
