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

package nidsdatasetcreation.simulations.car;

import inet.node.contract.IEthernetNetworkNode;
import nidsdatasetcreation.networks.scenarios.TsnNetworkScenario;

network Car extends TsnNetworkScenario
{
    @display("bgb=1180,1700;bgi=backgrounds/CarBG1,s");
    types:
        channel Eth1G_2m extends inet.node.ethernet.Eth1G
        {
            length = 2m;
        }
        channel Eth1G_05m extends inet.node.ethernet.Eth1G
        {
            length = 0.5m;
        }
    submodules:
        switchFrontLeft: <> like IEthernetNetworkNode {
            @display("p=495.04,495.04;i=device/switch");
        }
        switchFrontRight: <> like IEthernetNetworkNode {
            @display("p=776.83203,495.04;i=device/switch");
        }
        switchRearLeft: <> like IEthernetNetworkNode {
            @display("p=495.04,1172.864;i=device/switch");
        }
        switchRearRight: <> like IEthernetNetworkNode {
            @display("p=776.83203,1172.864;i=device/switch");
        }
        zonalControllerFrontLeft: <> like IEthernetNetworkNode {
            @display("p=357.84,310.98;i=device/card");
        }
        zonalControllerFrontRight: <> like IEthernetNetworkNode {
            @display("p=924.42004,310.98;i=device/card");
        }
        zonalControllerRearLeft: <> like IEthernetNetworkNode {
            @display("p=322.21542,1203.238;i=device/card");
        }
        zonalControllerRearRight: <> like IEthernetNetworkNode {
            @display("p=957.63324,1203.238;i=device/card");
        }
        lidarFrontLeft: <> like IEthernetNetworkNode {
            @display("p=496.29,198.09001;i=device/mainframe");
        }
        lidarFrontRight: <> like IEthernetNetworkNode {
            @display("p=777.45,198.09001;i=device/mainframe");
        }
        lidarRearLeft: <> like IEthernetNetworkNode {
            @display("p=464.576,1344.224;i=device/mainframe");
        }
        lidarRearRight: <> like IEthernetNetworkNode {
            @display("p=811.104,1344.224;i=device/mainframe");
        }
        cameraFront: <> like IEthernetNetworkNode {
            @display("p=641.13,149.1;i=device/smallrouter");
        }
        cameraRear: <> like IEthernetNetworkNode {
            @display("p=639.744,1367.072;i=device/smallrouter");
        }
        infotainment: <> like IEthernetNetworkNode {
            @display("p=639.744,567.392;i=device/pocketpc");
        }
        adas: <> like IEthernetNetworkNode {
            @display("p=639.744,1035.776;i=device/server2");
        }
        connectivityGateway: <> like IEthernetNetworkNode {
            @display("p=639.744,734.94403;i=device/accesspoint");
        }
        masterClock: <> like IEthernetNetworkNode {
            @display("p=639.744,894.88;i=device/clock");
        }
    connections:
        switchFrontLeft.ethg++ <--> Eth1G_2m <--> switchFrontRight.ethg++; 				// 0 - 0
        switchFrontRight.ethg++ <--> Eth1G_2m <--> switchRearRight.ethg++; 				// 1 - 0
        switchRearRight.ethg++ <--> Eth1G_2m <--> switchRearLeft.ethg++;   				// 1 - 0
        switchRearLeft.ethg++ <--> Eth1G_2m <--> switchFrontLeft.ethg++;   				// 1 - 1
        switchFrontLeft.ethg++ <--> Eth1G_05m <--> lidarFrontLeft.ethg++;  				// 2 - 0
        switchFrontLeft.ethg++ <--> Eth1G_05m <--> connectivityGateway.ethg++;			// 3 - 0
        switchFrontLeft.ethg++ <--> Eth1G_05m <--> zonalControllerFrontLeft.ethg++;		// 4 - 0
        switchFrontLeft.ethg++ <--> Eth1G_05m <--> infotainment.ethg++;					// 5 - 0
        cameraFront.ethg++ <--> Eth1G_05m <--> switchFrontRight.ethg++;					// 0 - 2
        lidarFrontRight.ethg++ <--> Eth1G_05m <--> switchFrontRight.ethg++;				// 0 - 3
        zonalControllerFrontRight.ethg++ <--> Eth1G_05m <--> switchFrontRight.ethg++;	// 0 - 4
        switchRearRight.ethg++ <--> Eth1G_05m <--> adas.ethg++;							// 2 - 0
        switchRearRight.ethg++ <--> Eth1G_05m <--> zonalControllerRearRight.ethg++;		// 3 - 0
        switchRearRight.ethg++ <--> Eth1G_05m <--> lidarRearRight.ethg++;				// 4 - 0
        switchRearRight.ethg++ <--> Eth1G_05m <--> masterClock.ethg++;                  // 5 - 0
        cameraRear.ethg++ <--> Eth1G_05m <--> switchRearLeft.ethg++;					// 0 - 2
        lidarRearLeft.ethg++ <--> Eth1G_05m <--> switchRearLeft.ethg++;					// 0 - 3
        zonalControllerRearLeft.ethg++ <--> Eth1G_05m <--> switchRearLeft.ethg++;       // 0 - 4
}
