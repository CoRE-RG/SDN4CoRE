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

#ifndef __SDN4CORE_TIMESYNCHRONOUSTRANSACTIONAPP_H_
#define __SDN4CORE_TIMESYNCHRONOUSTRANSACTIONAPP_H_

//STD
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
//CoRE4INET
#include "core4inet/scheduler/period/Period.h"
//SDN4CoRE
#include <sdn4core/netconf/applications/base/NetConfApplicationBase.h>
#include <sdn4core/netconf/applications/transactionModel/TransactionApp.h>
#include <sdn4core/netconf/datastructures/transactionModel/NetConfConfigCommitTimestamp.h>


namespace SDN4CoRE{

/**
 * Contains the Transaction-App implementation of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Mohammad Fazel Soltani, Tobias Haugg for HAW Hamburg
 */
class TimeSynchronousTransactionApp: public TransactionApp {

public:
    friend class TransactionModelTest;

    struct TransactionAppState: public TransactionApp::TransactionAppState{
        static const int WaitOnTimestampConfirmation = 11;
    };


    struct SwitchState: public TransactionApp::SwitchState{
        const static int SwitchWithTimestamp = 10;
    };

    typedef struct SwitchState_s: public TransactionApp::SwitchState_s {
        bool hasCommitTimeStamp = false;

        bool isInState(int state) {
            switch (state) {
                case SwitchState::SwitchWithTimestamp:
                    if(hasLockedRunning && hasCandidate && hasLockedCandidate && hasConfiguration && hasCommitTimeStamp && !hasCommited && !hasError){
                        return true;
                    }
                    break;
                default:
                    return TransactionApp::SwitchState_s::isInState(state);
                    break;
            }
            return false;
        };

    }   SwitchState_t;

protected:

    /**
     * returns a vector of connection which are in the giving state
     * @param state     the giving state
     * @return vector of connection
     */
    std::vector<Connection_t*> getSwitchesInState(int state) override;


    /**
     * sets the timestamp as data for the configuration
     * @param timestamp    the timestamp.
     * @return the Configurations
     */
    Configuration_t* getCommitTimestampConfig(NetConfConfigCommitTimestamp::CommitTimestamp_t timestamp);

    /**
     * determines timestamp by calculation for each connection the latencies of all Ethernet frames that still to be sent
     * @return the CommitTimestamp
     */
    NetConfConfigCommitTimestamp::CommitTimestamp_t determineTimestamp();

    /**
     * converts a state name to a string
     * @param state     the giving state
     * @return state name as string
     */
    std::string transactionAppStateToString(int state)override;


    /**
     * the finite state machine of the transaction model
     *@param msg        the received message
     */
    void finiteStateMachine(cMessage* msg)override;

    /**
     * determines the lock order of connections
     */
    void determineLockOrder()override;

    /**
     * checks if the transaction misses the commit timestamp
     * @return true if it misses the commit timestamp, else false
     */
    bool checkCommitrelease();

    /**
     * handles the message in the state WaitOnChangeConfirmation
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnChangeConfirmation(cMessage* msg) override;

    /**
     * handles the message in the state WaitOnTimestampConfirmation
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnTimestampConfirmation(cMessage* msg);

    virtual void initialize() override;
private:

    /**
     * period from scheduler
     */
    CoRE4INET::Period* _period;

    /**
     * the commit time with cycle and period for commit execution
     */
    NetConfConfigCommitTimestamp::CommitTimestamp_t _timestamp;

    /**
     * period to be synchronized
     */
    size_t _syncPeriod = 0;

    /**
     * sum of the last latencies of each connection
     */
    double _sumOfLastLatencies = 0;
};

} // namespace SDN4CoRE

#endif
