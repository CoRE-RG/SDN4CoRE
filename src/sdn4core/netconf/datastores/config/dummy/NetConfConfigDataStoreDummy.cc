//
// c Timo Haeckel, for HAW Hamburg
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

#include "NetConfConfigDataStoreDummy.h"

namespace SDN4CoRE {

Define_Module(NetConfConfigDataStoreDummy);

NetConfConfig* NetConfConfigDataStoreDummy::getConfig(
        NetConfFilter& filter) {
    Enter_Method("getConfig()");
    return new NetConfConfig();
}

bool NetConfConfigDataStoreDummy::editConfig(int defaultOperation,
        int errorOption, NetConfConfig* config) {
    Enter_Method("editConfig()");
    return true;
}

} /* namespace SDN4CoRE */
