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

#ifndef __SDN4CORE_TRANSACTIONAPP_H_
#define __SDN4CORE_TRANSACTIONAPP_H_

//STD
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
//SDN4CoRE
#include <sdn4core/netconf/applications/base/NetConfApplicationBase.h>
#include <sdn4core/netconf/datastructures/transactionModel/NetConfConfigCommitTimestamp.h>
//CoRE4INET
#include "core4inet/scheduler/period/Period.h"


#define SEND_TIMESTAMP_MSG_SIZE 226 * 8 // 226 Byte = 1808 bit
#define ACK_TIMESTAMP_MSG_SIZE 112 * 8 // 112 Byte = 896 bit
#define SEND_COMMIT_MSG_SIZE 108 * 8 // 108 Byte = 864 bit
#define MAX_ETHERNET_FRAME_SIZE 1530 * 8 // 1530 Byte = 12240 bit

namespace SDN4CoRE{

/**
 * Contains the Transaction-App implementation of a netconf application.
 * This module needs to be connected to the NetConf client.
 *
 * @author Mohammad Fazel Soltani, Tobias Haugg for HAW Hamburg
 */
class TransactionApp: public NetConfApplicationBase {
#define LOCK_MSG_ID "Lock"
#define COPY_CONFIG_MSG_ID "Copy Config"
#define LOCK_CANDIDATE_MSG_ID "Lock Candidate"
#define CHANGE_MSG_ID 0
#define TIMESTAMP_MSG_ID "Timestamp"
#define UNLOCK_MSG_ID "Unlock"
#define COMMIT_APPROVED_MSG_ID "Commit approved"
#define DELETE_CANDIDATE_MSG_ID "Delete Candidate Config"
#define DELETE_OLD_CONFIG_MSG_ID "Delete Old Config"
#define SELFMESSAGE_START_TRANSACTION "Start Transaction"
#define SELFMESSAGE_LAMBDA "LAMBDA_EVENT"
public:
    friend class TransactionModelTest;

    struct connections_less {
        bool operator()(Connection_t* lhs, Connection_t* rhs) {
            return lhs->remoteAddress.compare(rhs->remoteAddress.c_str())< 0;
        }
    };

    enum Phase{
        LOCK,
        CHANGE,
        CONFIRMATION,
        UNLOCK,
        DEFAULT
    };

    struct TransactionAppState{
        static const int BeginOfTransaction = 0;
        static const int WaitOnLockResponse = 1;
        static const int WaitOnCandidateConfirmation = 2;
        static const int WaitOnCandidateLockResponse = 3;
        static const int WaitOnChangeConfirmation = 4;
        static const int WaitOnCommitExecution = 5;
        static const int WaitOnDeleteOldConfiguration = 6;
        static const int WaitOnDeleteCandidate = 7;
        static const int WaitOnUnlock = 8;
        static const int ErrorState = 9;
        static const int EndOfTransaction = 10;
    };

    struct SwitchState{
        static const int SwitchAvailable = 0;
        static const int SwitchLocked = 1;
        static const int SwitchWithCandidate = 2;
        static const int SwitchWithLockedCandidate = 3;
        static const int SwitchWithChangedCandidateConfiguration = 4;
        static const int SwitchCommited = 5;
        static const int SwitchWithoutCandidate = 6;
        static const int SwitchWithoutOldConfig = 7;
        static const int SwitchUnlocked = 8;
        static const int SwitchError = 9;
    };

    typedef struct SwitchState_s {
        bool hasLockedRunning = false;
        bool hasCandidate = false;
        bool hasLockedCandidate = false;
        bool hasConfiguration = false;
        bool hasCommited = false;
        bool hasError = false;

        bool isInState(int state) {
            switch (state) {
                case SwitchState::SwitchAvailable:
                    if(!hasLockedRunning && !hasCandidate && !hasLockedCandidate && !hasConfiguration && !hasCommited && !hasError){
                        return true;
                    }
                    break;
                case SwitchState::SwitchLocked:
                    if(hasLockedRunning && !hasError){
                        return true;
                    }
                    break;
                case SwitchState::SwitchWithCandidate:
                    if(hasLockedRunning && hasCandidate && !hasLockedCandidate && !hasConfiguration && !hasCommited && !hasError){
                        return true;
                    }
                    break;
                case SwitchState::SwitchWithLockedCandidate:
                    if(hasLockedRunning && hasCandidate && hasLockedCandidate && !hasConfiguration && !hasCommited && !hasError){
                        return true;
                    }
                    break;
                case SwitchState::SwitchWithChangedCandidateConfiguration:
                    if(hasLockedRunning && hasCandidate && hasLockedCandidate && hasConfiguration && !hasCommited && !hasError){
                        return true;
                    }
                    break;
                case SwitchState::SwitchCommited:
                    if(hasLockedRunning && hasCandidate && hasLockedCandidate && hasConfiguration && hasCommited && !hasError){
                        return true;
                    }
                    break;
                case SwitchState::SwitchWithoutCandidate:
                    if(hasLockedRunning && !hasCandidate && !hasCommited){
                        return true;
                    }
                    break;
                case SwitchState::SwitchWithoutOldConfig:
                    if(hasLockedRunning && !hasCandidate && hasCommited){
                        return true;
                    }
                    break;
                case SwitchState::SwitchUnlocked:
                    if(!hasLockedRunning){
                        return true;
                    }
                    break;
                case SwitchState::SwitchError:
                    if(hasError){
                        return true;
                    }
                    break;
                default:
                    break;
            }
            return false;
        };
    } SwitchState_t;

    TransactionApp() {

    };

    ~TransactionApp(){
        if(LAMBDA_EVENT != nullptr) {
            auto owner = LAMBDA_EVENT->getOwner();
            if (owner != nullptr && owner == this) {
                delete LAMBDA_EVENT;
            }
        }
    }

protected:
    /**
     * update statistics and displaystring of Switch
     * @param Phase    new phase
     */
    void updatePhase(Phase newPhase);

    /**
     * finds the mentioned connection for the reply
     * @param reply    the NetConfMessage_RPCReply
     * @return the Connection
     */
    NetConfApplicationBase::Connection_t* findConnectionForReply(NetConfMessage_RPCReply* reply);

    /**
     * returns a vector of connection which are in the giving state
     * @param state     the giving state
     * @return vector of connection
     */
    virtual std::vector<Connection_t*> getSwitchesInState(int state);

    /**
     * converts a state name to a string
     * @param state     the giving state
     * @return state name as string
     */
    virtual std::string transactionAppStateToString(int state);

    int getTransactionState();

    /**
     * the finite state machine of the transaction model
     *@param msg        the received message
     */
    virtual void finiteStateMachine(cMessage* msg);

    /**
     * determines the lock order of connections
     */
    virtual void determineLockOrder();

    /**
     * executes transition to next state
     * @param state         the giving state
     */
    void transitionToState(int state);

    /**
     * checks if the received message is a msg which the transaction model can process
     * @param msg       the received message
     * @return true if it is a message which can process the model, else false
     */
    bool isFSMAlphabet(cMessage* msg);

    /**
     * checks if the received message is a self message to start the transaction
     * @param msg       the received message
     * @return true if it is a message to start the transaction, else false
     */
    bool isStartTransactionEvent(cMessage* msg);

    /**
     * checks if the received message is a rpc reply event message
     * @param msg       the received message
     * @return true if it is a rpc reply event message , else false
     */
    bool isRPCReplyEvent(cMessage* msg);

    /**
     * checks if it is a Lambda event message
     * @param msg       the received message
     * @return true if it is a Lambda event message , else false
     */
    bool isLambdaEvent(cMessage* msg);

    /**
     * the result of the transaction
     * true = successful
     * false = failed
     */
    bool result;

    /**
     * the cMessage for the Lambda event
     */
    cMessage* LAMBDA_EVENT;

    /**
     * the first state of the transaction model
     */
    int transactionState = TransactionAppState::BeginOfTransaction;

    /**
     * map to order a connection to the switch state
     */
    std::map<Connection_t*, SwitchState_t*,connections_less> switchStates;//connection_less will keep this sorted after the remote_ip

    /**
     * handles the message in the state BeginOfTransaction
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInBeginOfTransaction(cMessage* msg);

    /**
     * handles the message in the state WaitOnLockResponse
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnLockResponse(cMessage* msg);

    /**
     * handles the message in the state WaitOnCandidateConfirmation
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnCandidateConfirmation(cMessage* msg);

    /**
     * handles the message in the state WaitOnCandidateLockResponse
     * @param msg   the received message
     * * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnCandidateLockResponse(cMessage* msg);

    /**
     * handles the message in the state WaitOnChangeConfirmation
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    virtual bool handleMessageInWaitOnChangeConfirmation(cMessage* msg);

    /**
     * handles the message in the state WaitOnCommitExecution
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnCommitExecution(cMessage* msg);

    /**
     * handles the message in the state WaitOnDeleteOldConfiguration
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnDeleteOldConfiguration(cMessage* msg);

    /**
     * handles the message in the state WaitOnDeleteCandidate
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnDeleteCandidate(cMessage* msg);

    /**
     * handles the message in the state WaitOnUnlock
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInWaitOnUnlock(cMessage* msg);

    /**
     * handles the message in the state ErrorState
     * @param msg   the received message
     * @param eventHandled  handled event
     */
    bool handleMessageInErrorState(cMessage* msg);

    /**
     * checks if the event was handled
     * @param eventHandled
     * @return true, if event was handled else false
     */
    void checkEventHandled(bool eventHandled, cMessage* msg);

    virtual void initialize() override;
    virtual void handleMessage(cMessage* msg) override;
    /**
     * intercept when all connections are ready
     */
    virtual bool scheduleNextConfigurationFor(Connection_t* connection) override;

    /**
     * Schedules a self messsage for the next connection creation;
     */
    virtual bool scheduleNextConnection() override;

    /**
     * schedules the start of the transaction
     */
    void scheduleTransactionStart(SimTime startTime = SimTime::ZERO);

    /**
     * the processing time of the controller
     */
    double controllerProcessingTime = 0;

    /**
     * Signal to emit the result of transaction
     */
    simsignal_t resultOfTransaction;

    /**
     * Signal to emit the duration of transaction
     */
    simsignal_t transactionDuration;

    /**
     * Signal that is emitted to count sent messages
     */
    simsignal_t numSent;

    /**
     * Signal that is emitted to count received messages
     */
    simsignal_t numReceived;

    /**
     * Signal that is emitted when anew phase is entered
     */
    simsignal_t enterNewPhase;
};

} // namespace SDN4CoRE

#endif
