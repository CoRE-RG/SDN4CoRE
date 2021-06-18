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

package sdn4core.netconf.datastores.manager.base;

import sdn4core.netconf.datastores.manager.INetConfDataStoreManager;

//
// Adds a base implementation to the moduleinterface INetConfDataStoreManager.
// NetConfDataStoreManger implementations handle NetConf configuration and 
// state operations for a specific device. 
//
// @author Timo Haeckel, for HAW Hamburg
//
simple NetConfDataStoreManagerBase like INetConfDataStoreManager
{
    parameters:
        @class(SDN4CoRE::NetConfDataStoreManagerBase);
        
        @signal[commitExecution]();
        @statistic[commitExecution](title="commit execution";record=vector?;interpolationmode=none);
        
        @signal[editConfig]();
        @statistic[editConfig](title="execution of edit config";record=vector?;interpolationmode=none);
        
        @display("i=block/buffer2");
        // if true this module will create a display string for status messages
        bool displayStatus = default(true);
        // the path to the INetConfServer module
        string pathToNetConfServer = default("^.netConfServer");
        // xml file for a startup configuration of the device.
    	xml startupConfigXML = default(xml("<root/>"));
        
    gates:
        
        // input for netconf requests
        input requestIn @directIn;
}
