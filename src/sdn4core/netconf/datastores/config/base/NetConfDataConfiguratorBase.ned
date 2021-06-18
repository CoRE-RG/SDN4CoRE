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

package sdn4core.netconf.datastores.config.base;

import sdn4core.netconf.datastores.config.base.INetConfDataConfigurator;

//
// Contains the base module implementation and provides interface methods of a netconf config data store.
// NetConfConfigDataStore implementations execute netconf commands on the 
// device such as get, copy and edit config commands.
// They are managed and dynamically created during runtime by 
 // @see~INetConfDataStoreManager modules.
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfDataConfiguratorBase like INetConfDataConfigurator
{
    //these modules are used via direct method calls.
    @signal[editConfigOk]();
    @statistic[editConfigOk](title="execution of edit config Ok";record=vector?;interpolationmode=none);
    @signal[editConfigError]();
    @statistic[editConfigError](title="execution of edit config Error";record=vector?;interpolationmode=none);
}
