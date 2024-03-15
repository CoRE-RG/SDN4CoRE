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

package sdn4core.examples.papers.tssdnsoa.car;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.ethernet.Eth1G;

network Car
{
    @display("bgb=1180,1700;bgi=backgrounds/CarBG1,s");
    types:
        channel Eth1G_2m extends Eth1G
        {
            length = 2m;
        }
        channel Eth1G_05m extends Eth1G
        {
            length = 0.5m;
        }
    submodules:
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xmldoc("ipv4config.xml");
                @display("p=50,50");
        }
        controller: Controller {
            @display("p=923.568,780.432");
        }
        switchFrontLeft: Switch {
            @display("p=495.04,495.04");
        }
        switchFrontRight: Switch {
            @display("p=776.83203,495.04");
        }
        switchRearLeft: Switch {
            @display("p=495.04,1172.864");
        }
        switchRearRight: Switch {
            @display("p=776.83203,1172.864");
        }
        switchCenter: Switch {
            @display("p=639.744,834.94403");
        }
        zonalControllerFrontLeft: Node {
            @display("p=357.84,310.98;i=device/card");
        }
        zonalControllerFrontRight: Node {
            @display("p=924.42004,310.98;i=device/card");
        }
        zonalControllerRearLeft: Node {
            @display("p=322.21542,1203.238;i=device/card");
        }
        zonalControllerRearRight: Node {
            @display("p=957.63324,1203.238;i=device/card");
        }
        lidarFrontLeft: Node {
            @display("p=496.29,198.09001;i=device/mainframe");
        }
        lidarFrontRight: Node {
            @display("p=777.45,198.09001;i=device/mainframe");
        }
        lidarRearLeft: Node {
            @display("p=464.576,1344.224;i=device/mainframe");
        }
        lidarRearRight: Node {
            @display("p=811.104,1344.224;i=device/mainframe");
        }
        cameraFront: Node {
            @display("p=641.13,149.1;i=device/smallrouter");
        }
        cameraRear: Node {
            @display("p=639.744,1367.072;i=device/smallrouter");
        }
        infotainment: Node {
            @display("p=639.744,567.392;i=device/pocketpc");
        }
        adas: Node {
            @display("p=923.568,1015.584;i=device/server2");
        }
        connectivityGateway: Node {
            @display("p=282.864,702.048;i=device/accesspoint");
        }
        // masterClock: Node {
        //     @display("p=639.744,894.88;i=device/clock");
        // }
    connections:
        // control plane
        controller.ethg++ <--> Eth1G_2m <--> switchFrontLeft.gateControlPlane; 	// 0 - 0
        controller.ethg++ <--> Eth1G_2m <--> switchFrontRight.gateControlPlane; 	// 1 - 0
        controller.ethg++ <--> Eth1G_2m <--> switchCenter.gateControlPlane; 		// 2 - 0
        controller.ethg++ <--> Eth1G_2m <--> switchRearRight.gateControlPlane; 	// 3 - 0
        controller.ethg++ <--> Eth1G_2m <--> switchRearLeft.gateControlPlane; 	// 4 - 0
        // data plane
        // backbone (no longer as a ring but as a star topology introducing central switch)
        switchFrontLeft.gateDataPlane++ <--> Eth1G_2m <--> switchCenter.gateDataPlane++; 				// 0 - 0
        switchFrontRight.gateDataPlane++ <--> Eth1G_2m <--> switchCenter.gateDataPlane++; 				// 0 - 1
        switchRearRight.gateDataPlane++ <--> Eth1G_2m <--> switchCenter.gateDataPlane++;   				// 0 - 2
        switchRearLeft.gateDataPlane++ <--> Eth1G_2m <--> switchCenter.gateDataPlane++;   				// 0 - 3
        // edge
        switchFrontLeft.gateDataPlane++ <--> Eth1G_05m <--> lidarFrontLeft.ethg++;  				// 1 - 0
        switchFrontLeft.gateDataPlane++ <--> Eth1G_05m <--> connectivityGateway.ethg++;			    // 2 - 0
        switchFrontLeft.gateDataPlane++ <--> Eth1G_05m <--> zonalControllerFrontLeft.ethg++;		// 3 - 0
        switchFrontLeft.gateDataPlane++ <--> Eth1G_05m <--> infotainment.ethg++;					// 4 - 0
        switchFrontRight.gateDataPlane++ <--> Eth1G_05m <--> cameraFront.ethg++;					// 1 - 0
        switchFrontRight.gateDataPlane++ <--> Eth1G_05m <--> lidarFrontRight.ethg++;				// 2 - 0
        switchFrontRight.gateDataPlane++ <--> Eth1G_05m <--> zonalControllerFrontRight.ethg++;	    // 3 - 0
        switchRearRight.gateDataPlane++ <--> Eth1G_05m <--> adas.ethg++;							// 1 - 0
        switchRearRight.gateDataPlane++ <--> Eth1G_05m <--> zonalControllerRearRight.ethg++;		// 2 - 0
        switchRearRight.gateDataPlane++ <--> Eth1G_05m <--> lidarRearRight.ethg++;				    // 3 - 0
        // switchRearRight.gateDataPlane++ <--> Eth1G_05m <--> masterClock.ethg++;                  // 5 - 0
        switchRearLeft.gateDataPlane++ <--> Eth1G_05m <--> cameraRear.ethg++;					    // 1 - 0
        switchRearLeft.gateDataPlane++ <--> Eth1G_05m <--> lidarRearLeft.ethg++;					// 2 - 0
        switchRearLeft.gateDataPlane++ <--> Eth1G_05m <--> zonalControllerRearLeft.ethg++;          // 3 - 0
}
