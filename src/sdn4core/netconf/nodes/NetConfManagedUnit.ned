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

package sdn4core.netconf.nodes;

import sdn4core.netconf.server.INetConfServer;
import sdn4core.netconf.datastores.manager.INetConfDataStoreManager;
import sdn4core.netconf.datastores.config.base.INetConfConfigDataStore;

//
// NetConf managed unit compound module to be included in a NetConf server host (e.g. a switch).
//
// @author Timo Haeckel, for HAW Hamburg
//
module NetConfManagedUnit
{
    parameters:
        string netConfServerType = default("");
        string dataStoreManagerType = default("");
       	double processingTime @unit(s) = default(0s);
        *.processingTime = processingTime;

    gates:
        input transportIn;
        output transportOut;

    types:
        channel ProcessingDelay extends ned.DelayChannel
        {
        }

    submodules:
        // Netconf Client module
        netConfServer: <netConfServerType> like INetConfServer {
            @display("p=136,70");
        }

        // Netconf state store modules
        dataStoreManager: <dataStoreManagerType> like INetConfDataStoreManager {
            @display("p=234,70");
        }

        configStores[0]: <> like INetConfConfigDataStore {
            @display("p=330,70,c,50");
        }

    connections:
        netConfServer.transportIn <-- transportIn;
        netConfServer.transportOut --> transportOut;

}
