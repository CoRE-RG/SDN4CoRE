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

package sdn4core.netconf.applications.time_synchronous_transaction_model;

import sdn4core.netconf.applications.base.NetConfApplicationBase;
//
// Contains the Transaction-App implementation of a netconf application.
// This module needs to be connected to the NetConf client.
//
// @author Mohammad Fazel Soltani, for HAW Hamburg
//
simple TransactionApp extends NetConfApplicationBase
{
    parameters:
        @class(SDN4CoRE::TransactionApp);
        @signal[transactionResult](type="bool");
        @statistic[transactionResult](title="Result of Transaction";record=vector?;interpolationmode=none);
        @signal[numSentMsgs]();
        @statistic[numSentMsgs](title="Number of sent messages";record=vector?;interpolationmode=none);
        @signal[numReceivedMsgs]();
        @statistic[numReceivedMsgs](title="Number of received messages";record=vector?;interpolationmode=none);
        @signal[transactionDuration](type="bool");
        @statistic[transactionDuration](title="Duration of transaction";record=vector?;interpolationmode=none);
        @signal[lockPhase]();
        @statistic[lockPhase](title="Duration of lock phase";record=vector?;interpolationmode=none);
        @signal[changePhase]();
        @statistic[changePhase](title="Duration of change phase";record=vector?;interpolationmode=none);
        @signal[confirmationPhase]();
        @statistic[confirmationPhase](title="Duration of confirmation phase";record=vector?;interpolationmode=none);
        @signal[unlockPhase]();
        @statistic[unlockPhase](title="Duration of unlock phase";record=vector?;interpolationmode=none);
        // Distances and hops to switches to be programmed
        // positions in the both lists need to match for the switches.
        string distanceAndHopsToSwitches; // "l,h;l,h" sets distances for 2 switches / with "l,h" all distances are assumed to be equal
        double bitRate @unit(bps) = default(1Gbps); // bitrate of the controlplane network in bits per second ,
        double switchDelay @unit(s); // the switch delay in seconds
        double signalDelay @unit(mps); // the signal delay in meter per second 
        double controllerProcessingTime @unit(s); // the processing time of a controller
        double switchProcessingTime @unit(s); // the processing time of a switch
        double startHelloHandshake @unit(s) = default(0s); // the begin of NetConf Hello Handshake
        double startTransaction @unit(s) = default(0s); // the begin of the transaction
}
