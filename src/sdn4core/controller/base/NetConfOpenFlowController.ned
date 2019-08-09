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

package sdn4core.controller.base;

import sdn4core.controller.base.OpenFlowControllerBase;

import sdn4core.netconf.client.INetConfClient;
import sdn4core.netconf.applications.INetConfApplication;
import openflow.controllerApps.AbstractControllerApp;

//
// Model of an OpenFlow and NetConf capable controller.
// The NetConf controller can control the controllogic of switches
// An OpenFlow controller controlls the forwarding engines of all networking devices in the network.
//
// @author Timo Haeckel, for HAW Hamburg
//
module NetConfOpenFlowController extends OpenFlowControllerBase
{
    parameters:
        int numNetConfApps = default(0);
        string netConfClientType = default("NetConfClientTCP");

    gates:
        // no additional gates needed

    submodules:

        //NetConfClient applications
        //these may also implement the AbstractControllerApp interface 
        //for OpenFlow apps and subscribe to controller events
        netConfApps[numNetConfApps]: <> like INetConfApplication {

            @display("p=430,141,r,50");
        }
        // Netconf Client module
        netConfClient: <netConfClientType> like INetConfClient {

            @display("p=216,281");
        }

    connections:
        netConfClient.transportIn <-- tcp.appOut++;
        netConfClient.transportOut --> tcp.appIn++;

        for i=0..(numNetConfApps-1) {
            netConfClient.applicationIn++ <-- netConfApps[i].applicationOut;
            netConfClient.applicationOut++ --> netConfApps[i].applicationIn;
        }


}


