//
// c Mohammad Fazel Soltani, Timo Haeckel for HAW Hamburg
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
///////////////////////////////////////////////////////////////////////////////
package sdn4core.controller.iptunnel;
///////////////////////////////////////////////////////////////////////////////
//SDN4CoRE
import sdn4core.controller.tsn.TSN_NC_OF_Controller;
import sdn4core.controllerApps.tunnel.IPTunnelingControllerApp;
//INET
import inet.applications.contract.ITCPApp;
import inet.applications.contract.IUDPApp;
import inet.transportlayer.contract.ITCP;
import inet.transportlayer.contract.IUDP;
///////////////////////////////////////////////////////////////////////////////
module TSN_NC_OF_IPTunnel_Controller extends TSN_NC_OF_Controller
{
    parameters:

        int numOfTunnelTcpApps = default(0);
        int numOfTunnelUdpApps = default(0);
        bool hasOfTunnelTcp = default(numOfTunnelTcpApps > 0);
        bool hasOfTunnelUdp = default(numOfTunnelUdpApps > 0);
        bool hasOfIpTunnel = default(hasOfTunnelTcp || hasOfTunnelUdp);
        string ofTunneltcpType = default(firstAvailableOrEmpty("TCP", "TCP_lwIP", "TCP_NSC"));
        string ofTunneludpType = default(firstAvailableOrEmpty("UDP"));

    submodules:
        openFlowIPTunnel: IPTunnelingControllerApp if hasOfIpTunnel {

            @display("p=423,141");
        }
        ofTunnelTcpApp[numOfTunnelTcpApps]: <> like ITCPApp {
            @display("p=397,40");
        }
        ofTunnelTcp: <ofTunneltcpType> like ITCP if hasOfTunnelTcp {
            @display("p=397,93");
        }
        ofTunnelUdpApp[numOfTunnelUdpApps]: <> like IUDPApp {
            @display("p=449,40");
        }
        ofTunnelUdp: <ofTunneludpType> like IUDP if hasOfTunnelUdp {

            @display("p=449,93");
        }
    connections allowunconnected:
        for i=0..numOfTunnelTcpApps-1 {
            ofTunnelTcpApp[i].tcpOut --> ofTunnelTcp.appIn++;
            ofTunnelTcpApp[i].tcpIn <-- ofTunnelTcp.appOut++;
        }

        ofTunnelTcp.ipOut --> openFlowIPTunnel.transportIn++ if hasOfTunnelTcp;
        ofTunnelTcp.ipIn <-- openFlowIPTunnel.transportOut++ if hasOfTunnelTcp;

        for i=0..numOfTunnelUdpApps-1 {
            ofTunnelUdpApp[i].udpOut --> ofTunnelUdp.appIn++;
            ofTunnelUdpApp[i].udpIn <-- ofTunnelUdp.appOut++;
        }

        ofTunnelUdp.ipOut --> openFlowIPTunnel.transportIn++ if hasOfTunnelUdp;
        ofTunnelUdp.ipIn <-- openFlowIPTunnel.transportOut++ if hasOfTunnelUdp;
}
