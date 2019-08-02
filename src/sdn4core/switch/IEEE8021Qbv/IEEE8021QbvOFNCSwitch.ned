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
// c Timo Haeckel, for HAW Hamburg
// 

package sdn4core.switch.IEEE8021Qbv;
import sdn4core.netconf.server.INetConfServer;
import sdn4core.netconf.datastores.manager.INetConfDataStoreManager;

import sdn4core.switch.IEEE8021Qbv.IEEE8021QbvOpenFlowSwitch;
import sdn4core.netconf.datastores.config.base.INetConfConfigDataStore;

//
// This module adds programmable parameters via NetConf two the original model of an OpenFlow Ethernet 
// switch that supports IEEE 802.1Qbv priority forwarding with Time-Aware Shaping (@see~CoRE4INET::IEEE8021QbvPHYPort).
// It forwards packets according to the flow table entries and is connected to the OpenFlow Controller.
//
// @author Timo Haeckel, for HAW Hamburg
//
module IEEE8021QbvOFNCSwitch extends IEEE8021QbvOpenFlowSwitch
{
    parameters:
        string netConfServerType = default("NetConfServerTCP");
        string dataStoreManagerType = default("NetConfDataStoreManagerIEEE8021Qbv");

    gates:
        // no additional gates needed

    submodules:
        // Netconf Client module
        netConfServer: <netConfServerType> like INetConfServer {
            @display("p=226,216");
        }

        // Netconf state store modules
        dataStoreManager: <dataStoreManagerType> like INetConfDataStoreManager {
            @display("p=226,280");
        }

        configStores[0]: <> like INetConfConfigDataStore {
            @display("p=137,348,m,3,50,50");
        }

    connections:
        netConfServer.transportIn <-- tcp.appOut++;
        netConfServer.transportOut --> tcp.appIn++;

}
