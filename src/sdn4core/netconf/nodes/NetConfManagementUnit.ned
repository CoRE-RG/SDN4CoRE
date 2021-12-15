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

import sdn4core.netconf.client.INetConfClient;
import sdn4core.netconf.applications.INetConfApplication;

//
// NetConf manager compound module to be included in a NetConf client host (e.g. a controller).
//
// @author Timo Haeckel, for HAW Hamburg
//
module NetConfManagementUnit
{
    parameters:
        int numNetConfApps = default(0);
        string netConfClientType = default("");

    gates:
        input transportIn;
        output transportOut;

    types:

    submodules:

        //NetConfClient applications
        netConfApps[numNetConfApps]: <> like INetConfApplication {

            @display("p=220,70,c,70");
        }
        // Netconf Client module
        netConfClient: <netConfClientType> like INetConfClient {
            @display("p=57,70");
        }

    connections:
        netConfClient.transportIn <-- transportIn;
        netConfClient.transportOut --> transportOut;

        for i=0..(numNetConfApps-1) {
            netConfClient.applicationIn++ <-- netConfApps[i].applicationOut;
            netConfClient.applicationOut++ --> netConfApps[i].applicationIn;
        }
}
