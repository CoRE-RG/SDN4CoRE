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

#include <sdn4core/controllerApps/MACTableManagement.h>

using namespace inet;

namespace ofp{

void MACTableManagement::updateMacTable(CommonHeaderFields& headerFields) {
    //search map for source mac address and enter
    if (lookupTable.count(headerFields.swInfo) <= 0) {
        lookupTable[headerFields.swInfo] = std::map<MACAddress, uint32_t>();
        lookupTable[headerFields.swInfo][headerFields.src_mac] =
                headerFields.inport;
    } else {
        if (lookupTable[headerFields.swInfo].count(headerFields.src_mac) <= 0) {
            lookupTable[headerFields.swInfo][headerFields.src_mac] =
                    headerFields.inport;
        }
    }
}

int MACTableManagement::getOutPort(CommonHeaderFields& headerFields) {
    int outport = MAC_MANAGER_OUTPORT_FLOOD;
    if(lookupTable.count(headerFields.swInfo)>0) {
        if (lookupTable[headerFields.swInfo].count(headerFields.dst_mac)>0){
            //MACAdress is known so return
            outport = lookupTable[headerFields.swInfo][headerFields.dst_mac];
        }
    }
    return outport;
}

} /*end namespace ofp*/
