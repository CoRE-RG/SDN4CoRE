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
package sdn4core.controller.tsn;
///////////////////////////////////////////////////////////////////////////////
//SDN4CoRE
import sdn4core.controller.base.NetConfOpenFlowController;
//CoRE4INET
import core4inet.scheduler.ITTEScheduler;
import core4inet.synchronisation.base.ISync;
import core4inet.services.avb.SRP.SRPTable;
import core4inet.services.avb.SRP.SRProtocol;
import core4inet.linklayer.ethernet.TSNEtherNic;
///////////////////////////////////////////////////////////////////////////////
module TSN_NC_OF_Controller extends NetConfOpenFlowController
{
    parameters:
        string pathEth = default(absPath(".eth[0]"));
        eth[0].typename = "TSNEtherNic";
        networkLayerType = default("RTNetworkLayer");
    submodules:
        // Sync module for synchronisation of the scheduler
        sync: <default("DummySync")> like ISync {
            parameters:
                @display("p=710,331");
        }

        // Scheduler for the device
        scheduler: <default("Scheduler")> like ITTEScheduler {
            parameters:
                @display("p=710,250");
        }

        // Stream Reservation Protocol table
        srpTable: SRPTable {
            @display("p=519,287");
        }

		// Stream Reservation Protocol implementation
        srpProtocol: SRProtocol {
            @display("p=423,287");
            srpEncap = pathEth;
        }

    connections allowunconnected:
}
