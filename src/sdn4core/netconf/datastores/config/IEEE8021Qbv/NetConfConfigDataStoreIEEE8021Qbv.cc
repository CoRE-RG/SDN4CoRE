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

#include <sdn4core/netconf/datastores/config/IEEE8021Qbv/NetConfConfigDataStoreIEEE8021Qbv.h>

namespace SDN4CoRE {

NetConfConfigDataStoreIEEE8021Qbv::NetConfConfigDataStoreIEEE8021Qbv() {

}

NetConfConfigDataStoreIEEE8021Qbv::~NetConfConfigDataStoreIEEE8021Qbv() {
}

NetConfConfig* NetConfConfigDataStoreIEEE8021Qbv::getConfig(
        NetConfFilter& filter) {
    return new NetConfConfig();
}

bool NetConfConfigDataStoreIEEE8021Qbv::editConfig(int defaultOperation,
        int errorOption, NetConfConfig& config) {
    return true;
}

NetConfConfigDataStore* NetConfConfigDataStoreIEEE8021Qbv::copyConfig() {
    return new NetConfConfigDataStoreIEEE8021Qbv();
}

} /* namespace SDN4CoRE */
