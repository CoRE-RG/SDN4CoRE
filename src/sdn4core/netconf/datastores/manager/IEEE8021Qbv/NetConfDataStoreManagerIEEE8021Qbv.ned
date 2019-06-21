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

package sdn4core.netconf.datastores.manager.IEEE8021Qbv;

import sdn4core.netconf.datastores.manager.base.NetConfDataStoreManagerBase;

//
// This is an IEEE8021Qbv netconf data store manager for the @see ~IEEE8021QbvOFNCSwitch.
// It uses the IEEE8021Qbv config and state manager modules 
// (@see ~NetConfConfigDataStoreIEEE8021Qbv, ~NetConfStateDataStoreIEEE8021Qbv).
// NetConfDataStoreManger implementations handle NetConf configuration and 
// state operations for a specific device. 
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfDataStoreManagerIEEE8021Qbv extends NetConfDataStoreManagerBase
{
    parameters:
    	@class(SDN4CoRE::NetConfDataStoreManagerIEEE8021Qbv);
}
