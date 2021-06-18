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

#include "sdn4core/netconf/datastores/store/base/NetConfDataStoreBase.h"

namespace SDN4CoRE {

simsignal_t NetConfDataStoreBase::editConfigOkSignal = registerSignal("editConfigOk");
simsignal_t NetConfDataStoreBase::editConfigErrorSignal = registerSignal("editConfigError");

void NetConfDataStoreBase::initialize()
{
    //Do nothing for now.
    WATCH(this->lockHolderSessionId);
}

void NetConfDataStoreBase::handleMessage(cMessage *msg)
{
    throw cRuntimeError("NetConfDataStoreBase does not handle messages...");
}

} /* namespace SDN4CoRE */
