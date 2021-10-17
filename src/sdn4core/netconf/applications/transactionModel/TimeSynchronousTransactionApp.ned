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

package sdn4core.netconf.applications.transactionModel;

import sdn4core.netconf.applications.transactionModel.TransactionApp;
//
// Contains the Transaction-App implementation of a netconf application.
// This module needs to be connected to the NetConf client.
//
// @author Mohammad Fazel Soltani, for HAW Hamburg
//
simple TimeSynchronousTransactionApp extends TransactionApp
{
    parameters:
        @class(SDN4CoRE::TimeSynchronousTransactionApp);      
        // Distances and hops to switches to be programmed
        // positions in the both lists need to match for the switches.
        string distanceAndHopsToSwitches = default("2,1"); // "l,h;l,h" sets distances for 2 switches / with "l,h" all distances are assumed to be equal
        double bitRate @unit(bps) = default(1Gbps); // bitrate of the controlplane network in bits per second ,
        double switchDelay @unit(s) = default(8us); // the switch delay in seconds, default for 802.1Q ether switch of core4inet
        double signalDelay @unit(mps) = default(200000000mps); // the signal delay in meter per second, default is copper speed 
        double switchProcessingTime @unit(s) = default(0s); // the processing time of a switch
        bool executeAtStartOfPeriod = default(true); // execution time at start of period
}
