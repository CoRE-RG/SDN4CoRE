//
// c Mohammad Fazel Soltani for HAW Hamburg
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

#ifndef __SDN4CORE_TRANSACTIONMODELTEST_H_
#define __SDN4CORE_TRANSACTIONMODELTEST_H_

#include <omnetpp.h>
#include <sdn4core/netconf/applications/configparser/base/Configuration_t.h>
#include <sdn4core/netconf/applications/time_synchronous_transaction_model/TransactionApp.h>
#include "sdn4core/netconf/applications/base/NetConfApplicationBase.h"
#include "sdn4core/netconf/datastructures/base/NetConfConfig.h"
#include "sdn4core/netconf/datastructures/base/NetConfFilter.h"
#include "sdn4core/netconf/messages/NetConfOperation_m.h"


namespace SDN4CoRE{

/*
 * This class provides methods for testing the state coverage and
 * transition coverage of the network-wide transaction model.
 * The states are in (@TransactionApp::TransactionAppState).
 * @author Mohammad Fazel Soltani, for HAW Hamburg
 */
class TransactionModelTest : public omnetpp::cSimpleModule{
private:
    TransactionApp* _transactionApp;
    int _testCase;
    cMessage* _partTwoMessage;


protected:

    /**
     * initializes the first connection with the well-defined configurations
     * @return the connection with configurations
     */
    NetConfApplicationBase::Connection_t initConnectionOne();

    /**
     * initializes the second connection with the well-defined configurations
     * @return the connection with configurations
     */
    NetConfApplicationBase::Connection_t initConnectionTwo();

    /**
     * initializes connections and sets them as connections in the transaction model
     */
    void initConnections();

    /**
     * resets finite state machine
     */
    void resetFSM();

    NetConfCtrlInfo* getControlInfo(std::string controlInfoMessageId, int sessionId);

    NetConfMessage_RPCReply* getReplyOkMsg(std::string msgId, std::string controlInfoMessageId, int sessionId);

    NetConfMessage_RPCReply* getReplyErrorMsg(std::string msgId, std::string controlInfoMessageId, int sessionId);

    /**
     * State-based test method for the following state and transition coverage:
     * transitionCoverageLastCandidateFailed
     * @return
     */
    bool stateAndTransitionCoverageFailure();

    /**
     * State-based test method for the following state and transition coverage:
     * transaction routine and all transitions to do a transaction
     * @return true, if it was successfull else false
     * @return
     */
    bool stateAndTransitionCoverageSuccesful();

    /**
     * State-based test method for the following transition coverage:
     * first switch is already locked
     * @return
     */
    bool transitionCoverageAlreadyLocked();

    /**
     * State-based test method for the following transition coverage:
     * next switch is already locked
     * @return
     */
    bool transitionCoverageAlreadyLocked2();

    /**
     * State-based test method for the following transition coverage:
     * all switches relpy that their copy config failed
     * @return
     */
    bool transitionCoverageAllCandidatesFailed();

    /**
     * State-based test method for the following transition coverage:
     * first switch sends error-reply that copy config failed
     * @return
     */
    bool transitionCoverageFirstCandidateFailed();

    /**
     * State-based test method for the following transition coverage:
     * last switch sends error-reply that copy config failed
     * @return
     */
    bool transitionCoverageLastCandidateFailed();

    /**
     * State-based test method for the following transition coverage:
     * first change of a switch fails
     * @return
     */
    bool transitionCoverageFirstChangeFails();

    /**
     * State-based test method for the following transition coverage:
     * the next change of a switch fails
     * @return
     */
    bool transitionCoverageNextChangeFails();

    /**
     * State-based test method for the following transition coverage:
     * first switch reply is Timestamp-fail
     * @return
     */
    bool transitionCoverageFirstTimestampFail();

    /**
     * State-based test method for the following transition coverage:
     * last switch reply is Timestamp-fail
     */
    bool transitionCoverageLastTimestampFail();

    /**
     * State-based test method for the following transition coverage:
     * commit release failed
     * @return
     */
    bool transitionCoverageCommitReleaseFailed();

    /**
     * @return
     */
    bool transitionCoverageCommitReleasePartOne();

    /**
     * @return
     */
    bool transitionCoverageCommitReleasePartTwo();

protected:
    virtual void initialize() override;
    virtual void handleMessage(omnetpp::cMessage* msg) override;

};

} // namespace SDN4CoRE

#endif
