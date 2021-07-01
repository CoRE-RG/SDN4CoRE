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

package sdn4core.netconf.datastores.config.ieee8021qbv;

import sdn4core.netconf.datastores.config.base.NetConfDataConfiguratorBase;

//
// Contains a IEEE8021Qbv switch implementation of a NetConf config data store.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfDataConfiguratorIEEE8021Qbv extends NetConfDataConfiguratorBase
{
    parameters:
        @class(SDN4CoRE::NetConfDataConfiguratorIEEE8021Qbv);
    //these modules are used via direct method calls.
}
