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

package sdn4core.examples.time_synchronous_transaction_model.transactionModelTest;

import core4inet.scheduler.ITTEScheduler;
import core4inet.synchronisation.base.ISync;

import sdn4core.netconf.applications.transactionModel.TimeSynchronousTransactionApp;

module NetConf {
    gates:
        input in;
        output out;
    submodules:
        timeSynchronousTransactionApp: TimeSynchronousTransactionApp {
        }
    connections:
        timeSynchronousTransactionApp.applicationIn <-- in;
        timeSynchronousTransactionApp.applicationOut --> out;
}

module Controller {
    @networkNode;
    gates:
        input in;
        output out;
    submodules:
        // Sync module for synchronisation of the scheduler
        sync: <default("DummySync")> like ISync {
            parameters:
        }
        // Scheduler for the device
        scheduler: <default("Scheduler")> like ITTEScheduler {
            parameters:
        }
 		netconf : NetConf {
 		}    
    connections:
        netconf.in <-- in;
        netconf.out --> out;
    
}