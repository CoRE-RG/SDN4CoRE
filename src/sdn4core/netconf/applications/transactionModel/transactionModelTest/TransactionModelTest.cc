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

#include <sdn4core/netconf/applications/transactionModel/transactionModelTest/TransactionModelTest.h>

namespace SDN4CoRE{

Define_Module(TransactionModelTest);

NetConfApplicationBase::Connection_t TransactionModelTest::initConnectionOne(){
    // initialize con1
    NetConfApplicationBase::Connection_t con1;
    con1.connectAt = std::stod("0.01");
    con1.localPort = 1;
    con1.remoteAddress = "switch1";
    con1.remotePort = 830;
    con1.session_id = 1;
    con1.state = NetConfApplicationBase::ConnectionState_t::ConnectionStateEstablished;
    // init config1
    Configuration_t* config1 = new Configuration_t();
    config1->executeAt = std::stod("0.2");
    config1->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig;
    config1->state = Configuration_t::ConfigurationState_t::ConfigurationStateWaiting;
    config1->data = new NetConfConfig();
    config1->filter = new NetConfFilter();
    config1->target = "candidate";
    // init config2
    Configuration_t* config2 = new Configuration_t();
    config2->executeAt = std::stod("0.5");
    config2->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig;
    config2->state = Configuration_t::ConfigurationState_t::ConfigurationStateWaiting;
    config2->data = new NetConfConfig();
    config2->filter = new NetConfFilter();
    config2->target = "candidate";
    // put configs in con1
    con1.configurations.push_back(config1);
    con1.configurations.push_back(config2);
    return con1;
}

NetConfApplicationBase::Connection_t TransactionModelTest::initConnectionTwo(){
    // initialize con2
    NetConfApplicationBase::Connection_t con2;
    con2.connectAt = std::stod("0.02");
    con2.localPort = 2;
    con2.remoteAddress = "switch2";
    con2.remotePort = 830;
    con2.session_id = 2;
    con2.state = NetConfApplicationBase::ConnectionState_t::ConnectionStateEstablished;
    // init config1
    Configuration_t* config1 = new Configuration_t();
    config1->executeAt = std::stod("0.2");
    config1->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig;
    config1->state = Configuration_t::ConfigurationState_t::ConfigurationStateWaiting;
    config1->data = new NetConfConfig();
    config1->filter = new NetConfFilter();
    config1->target = "candidate";
    // put config1 in con2
    con2.configurations.push_back(config1);
    return con2;
}

void TransactionModelTest::initConnections(){
    std::vector<NetConfApplicationBase::Connection_t> connections;
    NetConfApplicationBase::Connection_t con1 = initConnectionOne();
    NetConfApplicationBase::Connection_t con2 = initConnectionTwo();
    connections.push_back(con1);
    connections.push_back(con2);
    _timeSynchronousTransactionApp->setConnnections(connections);
}

void TransactionModelTest::initialize(){
    _timeSynchronousTransactionApp = dynamic_cast<TimeSynchronousTransactionApp*>(this->getParentModule()->getSubmodule("controller")->getSubmodule("netconf")->getSubmodule("timeSynchronousTransactionApp"));
    scheduleAt(simTime(), new cMessage("Reset FSM"));
    _partTwoMessage = new cMessage("PartTwo");
    _testCase = this->par("testCaseNumber");
}

void TransactionModelTest::resetFSM(){
    initConnections();
    _timeSynchronousTransactionApp->scheduleTransactionStart();
}

void TransactionModelTest::handleMessage(omnetpp::cMessage* msg){
    static bool first = true;
    bool success = false;
    bool finish = false;
    if(msg->isSelfMessage() && strcmp(msg->getName(), "Reset FSM") == 0){
        resetFSM();
    }
    else if(!msg->isSelfMessage() && first){
        first = false;
        switch(_testCase) {
        case 1:
            success = stateAndTransitionCoverageSuccesful();
            if(success){
                std::cout << "Success | stateAndTransitionCoverageSuccesful()" << std::endl;
            }
            finish = true;
            break;
        case 2:
            success = stateAndTransitionCoverageFailure();
            if(success){
                std::cout << "Success | stateAndTransitionCoverageFailure()" << std::endl;
            }
            finish = true;
            break;
        case 3:
            success = transitionCoverageAlreadyLocked();
            if(success){
                std::cout << "Success | transitionCoverageAlreadyLocked()" << std::endl;
            }
            finish = true;
            break;
        case 4:
            success = transitionCoverageAlreadyLockedNext();
            if(success){
                std::cout << "Success | transitionCoverageAlreadyLocked2()" << std::endl;
            }
            finish = true;
            break;
        case 5:
            success = transitionCoverageAllCandidatesFailed();
            if(success){
                std::cout << "Success | transitionCoverageAllCandidatesFailed()" << std::endl;
            }
            finish = true;
            break;
        case 6:
            success = transitionCoverageFirstCandidateFailed();
            if(success){
                std::cout << "Success | transitionCoverageFirstCandidateFailed()" << std::endl;
            }
            finish = true;
            break;
        case 7:
            success = transitionCoverageLastCandidateFailed();
            if(success){
                std::cout << "Success | transitionCoverageLastCandidateFailed()" << std::endl;
            }
            finish = true;
            break;
        case 8:
            success = transitionCoverageFirstChangeFails();
            if(success){
                std::cout << "Success | transitionCoverageFirstChangeFails()" << std::endl;
            }
            finish = true;
            break;
        case 9:
            success = transitionCoverageNextChangeFails();
            if(success){
                std::cout << "Success | transitionCoverageNextChangeFails()" << std::endl;
            }
            finish = true;
            break;
        case 10:
            success = transitionCoverageFirstTimestampFail();
            if(success){
                std::cout << "Success | transitionCoverageFirstTimestampFail()" << std::endl;
            }
            finish = true;
            break;
        case 11:
            success = transitionCoverageLastTimestampFail();
            if(success){
                std::cout << "Success | transitionCoverageLastTimestampFail()" << std::endl;
            }
            finish = true;
            break;
        case 12:
            success = transitionCoverageCommitReleasePartOne();
            if(success){
                std::cout << "Success | transitionCoverageCommitReleasePartOne()" << std::endl;
            }
            scheduleAt(simTime() + 1 ,_partTwoMessage);
            break;
        }

    }
    else if(msg->isSelfMessage() && strcmp(msg->getName(), "PartTwo") == 0) {
        switch (_testCase) {
        case 12:
            success = transitionCoverageCommitReleasePartTwo();
            if(success){
                std::cout << "Success | transitionCoverageCommitReleasePartTwo()" << std::endl;
            }
            finish = true;
            break;
        default:
            break;
        }
    }
    if(finish){
        endSimulation();
    }
    delete msg;
}

NetConfCtrlInfo* TransactionModelTest::getControlInfo(std::string controlInfoMessageId, int sessionId){
    NetConfCtrlInfo* controlInfo = new NetConfCtrlInfo();
    controlInfo->setSession_id(sessionId);
    controlInfo->setMessage_id(controlInfoMessageId.c_str());
    return controlInfo;
}

NetConfMessage_RPCReply* TransactionModelTest::getReplyOkMsg(std::string msgId, std::string controlInfoMessageId, int sessionId){
    NetConfMessage_RPCReply* msg = new NetConfMessage_RPCReply();
    msg->setMessage_id(msgId.c_str());
    msg->setControlInfo(getControlInfo(controlInfoMessageId.c_str(),sessionId));
    NetConf_RPCReplyElement_Ok* ok = new NetConf_RPCReplyElement_Ok();
    msg->encapsulate(ok);
    return msg;
}

NetConfMessage_RPCReply* TransactionModelTest::getReplyErrorMsg(std::string msgId, std::string controlInfoMessageId, int sessionId){
    NetConfMessage_RPCReply* msg = new NetConfMessage_RPCReply();
    msg->setMessage_id(msgId.c_str());
    msg->setControlInfo(getControlInfo(controlInfoMessageId.c_str(),sessionId));
    NetConf_RPCReplyElement_Error* error = new NetConf_RPCReplyElement_Error();
    msg->encapsulate(error);
    return msg;
}

bool TransactionModelTest::stateAndTransitionCoverageFailure(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return true;

}

bool TransactionModelTest::stateAndTransitionCoverageSuccesful(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID+1), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnTimestampConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCommitExecution){
        std::cout << "Failure | Transaction State has to be in WaitOnTimestampConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COMMIT_APPROVED_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCommitExecution){
        std::cout << "Failure | Transaction State has to be in WaitOnCommit_Execution" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COMMIT_APPROVED_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteOldConfiguration){
        std::cout << "Failure | Transaction State has to be in WaitOnCommit_Execution" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_OLD_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteOldConfiguration){
        std::cout << "Failure | Transaction State has to be in WaitOnCommit_Execution" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_OLD_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnCommit_Execution" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnCommit_Execution" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in WaitOnCommit_Execution" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageAlreadyLocked(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyErrorMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageAlreadyLockedNext(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageAllCandidatesFailed(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageLastCandidateFailed(){
    return stateAndTransitionCoverageFailure();
}

bool TransactionModelTest::transitionCoverageFirstCandidateFailed(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageFirstChangeFails(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID+1), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageNextChangeFails(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageFirstTimestampFail(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID+1), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(TIMESTAMP_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnTimestampConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageLastTimestampFail(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID+1), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnTimestampConfirmation" << std::endl;
        return false;
    }
    msg = getReplyErrorMsg(TIMESTAMP_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageCommitReleaseFailed(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID+1), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnTimestampConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageCommitReleasePartOne(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(LOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(COPY_CONFIG_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnCandidateLockResponse){
        std::cout << "Failure | Transaction State has to be in WaitOnCandidateLockResponse" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(LOCK_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID), "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnChangeConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(std::to_string(CHANGE_MSG_ID+1), "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnChangeConfirmation" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnTimestampConfirmation){
        std::cout << "Failure | Transaction State has to be in WaitOnTimestampConfirmation" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

bool TransactionModelTest::transitionCoverageCommitReleasePartTwo(){
    NetConfMessage_RPCReply* msg;
    msg = getReplyOkMsg(TIMESTAMP_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::ErrorState){
        std::cout << "Failure | Transaction State has to be in ErrorState" << std::endl;
        return false;
    }
    _timeSynchronousTransactionApp->finiteStateMachine(_timeSynchronousTransactionApp->LAMBDA_EVENT);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnDeleteCandidate){
        std::cout << "Failure | Transaction State has to be in WaitOnDeleteCandidate" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(DELETE_CANDIDATE_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "0", 1);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::WaitOnUnlock){
        std::cout << "Failure | Transaction State has to be in WaitOnUnlock" << std::endl;
        return false;
    }
    msg = getReplyOkMsg(UNLOCK_MSG_ID, "1", 2);
    _timeSynchronousTransactionApp->finiteStateMachine(msg);
    if(_timeSynchronousTransactionApp->transactionState != TimeSynchronousTransactionApp::TransactionAppState::EndOfTransaction){
        std::cout << "Failure | Transaction State has to be in EndOfTransaction" << std::endl;
        return false;
    }
    return _timeSynchronousTransactionApp->result;
}

} // namespace SDN4CoRE
