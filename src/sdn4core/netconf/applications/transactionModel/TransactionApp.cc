//
// c Mohammad Fazel Soltani, Timo Haeckel, for HAW Hamburg
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

//CoRE4INET
#include "core4inet/scheduler/oscillator/Oscillator.h"
//SDN4CoRE
#include <sdn4core/netconf/applications/transactionModel/TransactionApp.h>
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserCollection.h>
#include <sdn4core/utility/xml/XMLUtility.h>


namespace SDN4CoRE{

Define_Module(TransactionApp);

void TransactionApp::initialize(){
    LAMBDA_EVENT = new cMessage(SELFMESSAGE_LAMBDA);
    controllerProcessingTime = this->par("controllerProcessingTime").doubleValue();
    resultOfTransaction = registerSignal("transactionResult");
    transactionDuration = registerSignal("transactionDuration");
    enterNewPhase = registerSignal("enterNewPhase");

    numSent = registerSignal("numSentMsgs");
    numReceived = registerSignal("numReceivedMsgs");

    WATCH(this->result);
    WATCH(this->transactionState);


    cXMLElement* xmlServerConnections = par("serverConnections").xmlValue();
    if (xmlServerConnections) {
        if (strcmp(xmlServerConnections->getName(), "server_connections")
                == 0) {
            cXMLElementList applicationsXML =
                    xmlServerConnections->getChildrenByTagName("application");
            for (size_t i = 0; i < applicationsXML.size(); i++) {
                std::string clientAppHost = getStringAttributeFromXML(applicationsXML[i],"client_host");
                int clientAppIndex = getIntAttributeFromXML(applicationsXML[i],"client_app");
                const char* realHost = getParentModule()->getParentModule()->getFullName();
                if (clientAppIndex == getIndex() && (strcmp(realHost, clientAppHost.c_str()) == 0)) {

                    auto connectionList = NetConfAppConfigParserCollection::parseXMLConnectionList(
                            applicationsXML[i]->getChildrenByTagName("connection"), false);
                    double startHelloHandshake = this->par("startHelloHandshake").doubleValue();
                    for(auto connection : connectionList) {
                        connection.connectAt = startHelloHandshake;
                        _connections.push_back(connection);
                    }
                }
            }
        }
    }
    WATCH_VECTOR(_connections);
    scheduleNextConnection();
}

void TransactionApp::updatePhase(Phase newPhase){
    emit(enterNewPhase,newPhase);
    cDisplayString& parentDispStr = this->getDisplayString();
    switch(newPhase){
        case Phase::LOCK:
            parentDispStr.setTagArg("i", 1, "#0066ff");
            parentDispStr.setTagArg("t", 0, "Lock Phase");
            break;
        case Phase::CHANGE:
            parentDispStr.setTagArg("i", 1, "#ff9933");
            parentDispStr.setTagArg("t", 0, "Change Phase");
            break;
        case Phase::CONFIRMATION:
            parentDispStr.setTagArg("i", 1, "#ffff00");
            parentDispStr.setTagArg("t", 0, "Confirmation Phase");
            break;
        case Phase::UNLOCK:
            parentDispStr.setTagArg("i", 1, "#ff0066");
            parentDispStr.setTagArg("t", 0, "Confirmation Phase");
            break;
        case Phase::DEFAULT:
            if(transactionState == TransactionAppState::EndOfTransaction){
                parentDispStr.setTagArg("i", 1, "green");
                parentDispStr.setTagArg("t", 0, "Success");
            }else{
                parentDispStr.setTagArg("i", 1, "red");
                parentDispStr.setTagArg("t", 0, "Error");
            }
            break;
    }
}

void TransactionApp::handleMessage(cMessage* msg){
    if(isFSMAlphabet(msg)){
        emit(numReceived, 1L);
        finiteStateMachine(msg);
        if(!isLambdaEvent(msg)){
            delete msg;
        }
    } else{
        NetConfApplicationBase::handleMessage(msg);
    }
}

bool TransactionApp::scheduleNextConnection(){
    bool result = false;
    for (auto& connection : _connections) {
        if(connection.state == ConnectionState_t::ConnectionStateWaiting) {
            connection.state = ConnectionState_t::ConnectionStateScheduled;
            cMessage* msg = new cMessage(SELFMESSAGE_SEND_HELLO);
            msg->setContextPointer(&connection);
            scheduleAt(connection.connectAt, msg);
            result = true;
            break;
        }
    }
    return result;
}

bool TransactionApp::scheduleNextConfigurationFor(Connection_t* connection){
    bool result = !_connections.empty();
    for(auto& connection: _connections){
        if(connection.state != ConnectionState_t::ConnectionStateEstablished){
            result = false;
            break;
        }
    }
    if(result){
        scheduleTransactionStart(this->par("startTransaction").doubleValue());
    }
    return result;
}

void TransactionApp::scheduleTransactionStart(SimTime startTime){
    Enter_Method_Silent();//also used in Test environment so we need this to switch context
    if(startTime == SimTime::ZERO){
        scheduleAt(simTime(), new cMessage(SELFMESSAGE_START_TRANSACTION));
    }else if (startTime >= simTime()){
        scheduleAt(startTime, new cMessage(SELFMESSAGE_START_TRANSACTION));
    }else{
        throw cRuntimeError("Start Transaction time (%s) is in the past.",startTime.str().c_str());
    }
}

std::vector<NetConfApplicationBase::Connection_t*> TransactionApp::getSwitchesInState(int state){
    std::vector<NetConfApplicationBase::Connection_t*> resultVector;
    for(auto it = switchStates.begin(); it != switchStates.end(); it++) {
        if (it->second->isInState(state)) {
            resultVector.push_back(it->first);
        }
    }
    return resultVector;
}

void TransactionApp::determineLockOrder(){
    for(auto& connection: _connections){
        switchStates[&connection] = new SwitchState_t();
    }
}

int TransactionApp::getTransactionState(){
    return transactionState;
}

std::string TransactionApp::transactionAppStateToString(int state){
    switch(state){
    case TransactionAppState::BeginOfTransaction:
        return "BeginOfTransaction";
    case TransactionAppState::WaitOnLockResponse:
        return "WaitOnLockResponse";
    case TransactionAppState::WaitOnCandidateConfirmation:
        return "WaitOnCandidateConfirmation";
    case TransactionAppState::WaitOnChangeConfirmation:
        return "WaitOnChangeConfirmation";
    case TransactionAppState::WaitOnCommitExecution:
        return "WaitOnCommitExecution";
    case TransactionAppState::WaitOnDeleteOldConfiguration:
        return "WaitOnDeleteOldConfiguration";
    case TransactionAppState::WaitOnDeleteCandidate:
        return "WaitOnDeleteCandidate";
    case TransactionAppState::WaitOnUnlock:
        return "WaitOnUnlock";
    case TransactionAppState::ErrorState:
        return "ErrorState";
    case TransactionAppState::EndOfTransaction:
        return "EndOfTransaction";
    default:
        return "invalid state";
    }
}

NetConfApplicationBase::Connection_t* TransactionApp::findConnectionForReply(NetConfMessage_RPCReply* reply) {
    //check if msg has context pointer
    Connection_t* found = nullptr;
    if(NetConfCtrlInfo* info = dynamic_cast<NetConfCtrlInfo*>(reply->getControlInfo())){
        for (size_t i = 0; i < _connections.size(); i++) {
            auto& connection = _connections[i];
            if (connection.state
                    == ConnectionState_t::ConnectionStateEstablished
                    && connection.session_id == info->getSession_id()) {
                found = &connection;
                break;
            }
        }
        // check if connection is defined
        if(found == nullptr){
            throw cRuntimeError("undefined connection");
        }
    }
    else {
        throw cRuntimeError("undefined sessionInfo");
    }
    //delete sessionInfo;
    return found;
}

bool TransactionApp::isFSMAlphabet(cMessage* msg){
    return isStartTransactionEvent(msg) || isRPCReplyEvent(msg) || isLambdaEvent(msg);
}

bool TransactionApp::isStartTransactionEvent(cMessage* msg) {
    return msg->isSelfMessage() && strcmp(msg->getName(), SELFMESSAGE_START_TRANSACTION) == 0;
}

bool TransactionApp::isRPCReplyEvent(cMessage* msg) {
    if(dynamic_cast<NetConfMessage_RPCReply*>(msg)){
        return true;
    }
    return false;
}

bool TransactionApp::isLambdaEvent(cMessage* msg) {
    return msg == TransactionApp::LAMBDA_EVENT;
}

void TransactionApp::transitionToState(int nextState){
    //execute exit action of current state
    switch (transactionState) {
    default:
        break;
    }
    //switch state
    transactionState = nextState;
    // execute entry action of next state
    Connection_t* connectionToLock = nullptr;
    switch (nextState) {
    case TransactionAppState::WaitOnLockResponse:
        for(auto it = switchStates.begin(); it != switchStates.end(); it++) {
            if(it->second->isInState(SwitchState::SwitchAvailable)){
                connectionToLock = it->first;
                break;
            }
        }
        if(connectionToLock){
            Configuration_t* config = new Configuration_t();
            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Lock;
            config->target = "running";
            NetConfMessage_RPC* s_Switch_sperren = createNetConfRPCForConfiguration(connectionToLock, config, LOCK_MSG_ID);
            sendDelayed(s_Switch_sperren, controllerProcessingTime, gate("applicationOut"));
            emit(numSent, 1L);
        } else {
            throw cRuntimeError("connection cannot locked");
        }
        break;
    case TransactionAppState::ErrorState:
        updatePhase(Phase::DEFAULT);
        result = false;
        emit(resultOfTransaction,result);
        scheduleAt(simTime(), LAMBDA_EVENT);
        break;
    case TransactionAppState::EndOfTransaction:
        updatePhase(Phase::DEFAULT);
        result = true;
        emit(resultOfTransaction,result);
        emit(transactionDuration, true);
        break;
    default:
        //throw cRuntimeError("cannot execute entry action of a state that has no entry action");
        break;
    }
}

void TransactionApp::finiteStateMachine(cMessage* msg){
    Enter_Method_Silent();//also used in Test environment so we need this to switch context
    bool eventHandled = false;
    switch(transactionState){
    case TransactionAppState::BeginOfTransaction:
        eventHandled = handleMessageInBeginOfTransaction(msg);
        break;
    case TransactionAppState::WaitOnLockResponse:
        eventHandled = handleMessageInWaitOnLockResponse(msg);
        break;
    case TransactionAppState::WaitOnCandidateConfirmation:
        eventHandled = handleMessageInWaitOnCandidateConfirmation(msg);
        break;
    case TransactionAppState::WaitOnCandidateLockResponse:
        eventHandled = handleMessageInWaitOnCandidateLockResponse(msg);
        break;
    case TransactionAppState::WaitOnChangeConfirmation:
        eventHandled = handleMessageInWaitOnChangeConfirmation(msg);
        break;
//    case TransactionAppState::WaitOnTimestampConfirmation:
//        eventHandled = handleMessageInWaitOnTimestampConfirmation(msg);
//        break;
    case TransactionAppState::ErrorState:
        eventHandled = handleMessageInErrorState(msg);
        break;
    case TransactionAppState::WaitOnCommitExecution:
        eventHandled = handleMessageInWaitOnCommitExecution(msg);
        break;
    case TransactionAppState::WaitOnDeleteOldConfiguration:
        eventHandled = handleMessageInWaitOnDeleteOldConfiguration(msg);
        break;
    case TransactionAppState::WaitOnDeleteCandidate:
        eventHandled = handleMessageInWaitOnDeleteCandidate(msg);
        break;
    case TransactionAppState::WaitOnUnlock:
        eventHandled = handleMessageInWaitOnUnlock(msg);
        break;
    case TransactionAppState::EndOfTransaction:
        break;
    default:
        cRuntimeError("Invalid State in FSM-TransactionApp");
        break;
    }
    checkEventHandled(eventHandled, msg);
}

void TransactionApp::checkEventHandled(bool eventHandled, cMessage* msg){
    if(!eventHandled){
        std::string errorMsg = "Cannot handle event ";
        errorMsg += msg->getFullName();
        errorMsg += " in state ";
        errorMsg += transactionAppStateToString(transactionState);
        const char* errorMessage = errorMsg.c_str();
        throw cRuntimeError(errorMessage);
    }
}

bool TransactionApp::handleMessageInBeginOfTransaction(cMessage* msg){
    if(isStartTransactionEvent(msg)){
        emit(transactionDuration, true);
       updatePhase(Phase::LOCK);
        determineLockOrder();
        transitionToState(TransactionAppState::WaitOnLockResponse);
        return true;
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnLockResponse(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // received_Switch_locked
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if (((strcmp(reply->getMessage_id(), LOCK_MSG_ID) == 0) && (switchStates[con]->isInState(SwitchState::SwitchAvailable)))) {
                switchStates[con]->hasLockedRunning = true;
                std::vector<Connection_t*> lockedSwitches = getSwitchesInState(SwitchState::SwitchLocked);
                if(lockedSwitches.size() < switchStates.size()){
                    transitionToState(TransactionAppState::WaitOnLockResponse);
                    return true;
                }
                else if(lockedSwitches.size() == switchStates.size()){
                    updatePhase(Phase::CHANGE);
                    // send_copy_config
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_CopyConfig;
                            config->source = "running";
                            config->target = "candidate";
                            NetConfMessage_RPC* s_Konfig_kopieren = createNetConfRPCForConfiguration(connection, config, COPY_CONFIG_MSG_ID);
                            sendDelayed(s_Konfig_kopieren, controllerProcessingTime, gate("applicationOut"));
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
            }else{
                throw cRuntimeError("reply is not the response of e_Switch_gesperrt and cannot locked");
            }
        }
        // received_not_available
        else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket())){
            if(strcmp(reply->getMessage_id(), LOCK_MSG_ID) != 0){
                throw cRuntimeError("error-reply is not the response of e_bereits_belegt ");
            }else{
                std::vector<Connection_t*> lockedSwitches = getSwitchesInState(SwitchState::SwitchLocked);
                if(lockedSwitches.size() == 0){
                    result = false;
                    emit(resultOfTransaction,result);
                    transitionToState(TransactionAppState::EndOfTransaction);
                    return true;
                }else if(lockedSwitches.size() > 0){
                    Connection_t* con = findConnectionForReply(reply);
                    // send_unlock_switch
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            if(connection->remoteAddress == con->remoteAddress){
                                config = new Configuration_t();
                                config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Unlock;
                                config->target = "running";
                                NetConfMessage_RPC* s_Switch_entsperren = createNetConfRPCForConfiguration(connection, config, UNLOCK_MSG_ID);
                                sendDelayed(s_Switch_entsperren, controllerProcessingTime, gate("applicationOut"));
                            }
                        }
                    }
                    switchStates[con]->hasLockedRunning = false;
                    result = false;
                    emit(resultOfTransaction,result);
                    transitionToState(TransactionAppState::WaitOnUnlock);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnCandidateConfirmation(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // received_config_copied
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), COPY_CONFIG_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Konfig_kopiert");
            }else{
                switchStates[con]->hasCandidate = true;
                std::vector<Connection_t*> lockedSwitchesWithCandidate = getSwitchesInState(SwitchState::SwitchWithCandidate);
                std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
                if(failedSwitch.size() > 0){
                    if((lockedSwitchesWithCandidate.size() + failedSwitch.size()) == switchStates.size()){
                        transitionToState(TransactionAppState::ErrorState);
                        return true;

                    }
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
                else if(lockedSwitchesWithCandidate.size() < switchStates.size()){
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
                else if(lockedSwitchesWithCandidate.size() == switchStates.size()){
                    // send_lock_candidate_of_switch
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->target = "candidate";
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Lock;
                            NetConfMessage_RPC* s_Switch_Kandidat_sperren = createNetConfRPCForConfiguration(connection, config, LOCK_CANDIDATE_MSG_ID);
                            sendDelayed(s_Switch_Kandidat_sperren, controllerProcessingTime, gate("applicationOut"));
                            emit(numSent, 1L);
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnCandidateLockResponse);
                    return true;
                }
            }
        }else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket())){
            // received_creating_candidate_failed
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), COPY_CONFIG_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Kandidat_fehlgeschlagen");
            }else{
                switchStates[con]->hasError = true;
                std::vector<Connection_t*> lockedSwitchesWithCandidate = getSwitchesInState(SwitchState::SwitchWithCandidate);
                std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
                if((lockedSwitchesWithCandidate.size() == 0) && failedSwitch.size() == switchStates.size()){
                    //send_unlock_switch
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Unlock;
                            config->target = "running";
                            NetConfMessage_RPC* s_Switch_entsperren = createNetConfRPCForConfiguration(connection, config, UNLOCK_MSG_ID);
                            sendDelayed(s_Switch_entsperren, controllerProcessingTime, gate("applicationOut"));
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnUnlock);
                    return true;
                }
                else if((lockedSwitchesWithCandidate.size() + failedSwitch.size()) < switchStates.size()){
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
                else if((lockedSwitchesWithCandidate.size() + failedSwitch.size()) == switchStates.size()){
                    transitionToState(TransactionAppState::ErrorState);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnCandidateLockResponse(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        // received_switch_candidate_locked
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), LOCK_CANDIDATE_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Switch_Kandidat_gesperrt");
            }else{
                switchStates[con]->hasLockedCandidate = true;
                std::vector<Connection_t*> switchesWithLockedCandidate = getSwitchesInState(SwitchState::SwitchWithLockedCandidate);
                if(switchesWithLockedCandidate.size() < switchStates.size()){
                    transitionToState(TransactionAppState::WaitOnCandidateLockResponse);
                    return true;
                }else if(switchesWithLockedCandidate.size() == switchStates.size()){
                    // send_apply_changes
                    Connection_t* connection;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection && connection->configurations[0]->state == Configuration_t::ConfigurationState_t::ConfigurationStateWaiting){
                            connection->configurations[0]->target = "candidate";
                            NetConfMessage_RPC* s_Aenderung_durchfuehren = createNetConfRPCForConfiguration(connection, connection->configurations[0], std::to_string(CHANGE_MSG_ID+0));
                            sendDelayed(s_Aenderung_durchfuehren, controllerProcessingTime, gate("applicationOut"));
                            connection->configurations[0]->state = Configuration_t::ConfigurationState_t::ConfigurationStateRequested;
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnChangeConfirmation(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // receive_apply_changes
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        Connection_t* con = findConnectionForReply(reply);
        int idx = atoi(reply->getMessage_id()) - CHANGE_MSG_ID;
        if(con->configurations[idx]->state != Configuration_t::ConfigurationState_t::ConfigurationStateRequested) {
            throw cRuntimeError(" reply is not the response for last change of e_Aenderung_durchgefuehrt");
        }
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            con->configurations[idx]->state = Configuration_t::ConfigurationState_t::ConfigurationStateSuccess;
            if(getSwitchesInState(SwitchState::SwitchError).size() > 0){
                switchStates[con]->hasConfiguration = true;
                if(getSwitchesInState(SwitchState::SwitchError).size()+getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration).size() == switchStates.size()){
                    transitionToState(TransactionAppState::ErrorState);
                    return true;
                }else{
                    transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                    return true;
                }
            }
            std::vector<Configuration_t*> configsInConnection = con->configurations;
            int i;
            for(i = 0; i < configsInConnection.size(); i++){
                if(configsInConnection[i]->state == Configuration_t::ConfigurationState_t::ConfigurationStateWaiting){
                    con->configurations[i]->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig;
                    con->configurations[i]->target = "candidate";
                    NetConfMessage_RPC* s_Aenderung_durchfuehren = createNetConfRPCForConfiguration(con, con->configurations[i], std::to_string(CHANGE_MSG_ID+i));
                    sendDelayed(s_Aenderung_durchfuehren, controllerProcessingTime, gate("applicationOut"));
                    emit(numSent, 1L);
                    con->configurations[i]->state = Configuration_t::ConfigurationState_t::ConfigurationStateRequested;
                    break;//only send next one
                }
            }
            if(i >= configsInConnection.size()){
                //no more changes sent
                switchStates[con]->hasConfiguration = true;
            }
            if((getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration).size() == switchStates.size())
                    && (getSwitchesInState(SwitchState::SwitchError).size() == 0)){ // no more changes for all switches
                // transition to next state
                Connection_t* connection;
                for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                    connection = it->first;
                    if(connection){
                        Configuration_t* config = new Configuration_t();
                        config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Commit;
                        NetConfMessage_RPC* s_Commit_freigeben = createNetConfRPCForConfiguration(connection, config, COMMIT_APPROVED_MSG_ID);
                        sendDelayed(s_Commit_freigeben, controllerProcessingTime, gate("applicationOut"));
                        updatePhase(Phase::CONFIRMATION);
                    }
                }
                transitionToState(TransactionAppState::WaitOnCommitExecution);
                return true;
            }
            else { // done with changes || no more changes for this switch
                transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                return true;
            }
        }
        else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket())){
            // received_applaying_changes_failed
            con->configurations[idx]->state = Configuration_t::ConfigurationState_t::ConfigurationStateError;
            switchStates[con]->hasError = true;
            std::vector<Connection_t*> switchesWithChangedCandidateConfig = getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration);
            std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
            if((switchesWithChangedCandidateConfig.size()+failedSwitch.size()) < switchStates.size()){
                transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                return true;
            }
            else if((switchesWithChangedCandidateConfig.size()+failedSwitch.size()) == switchStates.size()){
                transitionToState(TransactionAppState::ErrorState);
                return true;
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnCommitExecution(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // received_execute_commit
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), COMMIT_APPROVED_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Commit_ausgefuehrt");
            }else{
                switchStates[con]->hasCommited = true;
                std::vector<Connection_t*> commitedSwitches = getSwitchesInState(SwitchState::SwitchCommited);
                if(switchStates.size() > commitedSwitches.size()){
                    transitionToState(TransactionAppState::WaitOnCommitExecution);
                    return true;
                }else if(switchStates.size() == commitedSwitches.size()){

                    updatePhase(Phase::UNLOCK);

                    // send_delete_old_configuration
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_DeleteConfig;
                            config->target = "candidate";
                            NetConfMessage_RPC* s_alte_Konfig_loeschen = createNetConfRPCForConfiguration(connection, config, DELETE_OLD_CONFIG_MSG_ID);
                            sendDelayed(s_alte_Konfig_loeschen, controllerProcessingTime, gate("applicationOut"));
                            emit(numSent, 1L);
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnDeleteOldConfiguration);
                    return true;
                }
            }
        } else {
            // this is a hardware fault and not handled in transaction
            throw cRuntimeError(" Reply for commit execution is not ok response of e_Commit_ausgefuehrt");
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnDeleteOldConfiguration(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // received_delete_old_configuration
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), DELETE_OLD_CONFIG_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_alte_Konfig_geloescht");
            }else{
                switchStates[con]->hasCandidate = false;
                switchStates[con]->hasLockedCandidate = false;
                std::vector<Connection_t*> switchesWithoutOldConfig = getSwitchesInState(SwitchState::SwitchWithoutOldConfig);
                if(switchesWithoutOldConfig.size() == switchStates.size()){
                    // send_unlock_switch
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Unlock;
                            config->target = "running";
                            NetConfMessage_RPC* s_Switch_entsperren = createNetConfRPCForConfiguration(connection, config, UNLOCK_MSG_ID);
                            sendDelayed(s_Switch_entsperren, controllerProcessingTime, gate("applicationOut"));
                            emit(numSent, 1L);
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnUnlock);
                    return true;
                }else if(switchesWithoutOldConfig.size() < switchStates.size()){
                    transitionToState(TransactionAppState::WaitOnDeleteOldConfiguration);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnDeleteCandidate(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // receive_candidate_deleted
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), DELETE_CANDIDATE_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Kandidat_geloescht");
            }else{
                switchStates[con]->hasCandidate = false;
                switchStates[con]->hasLockedCandidate = false;
                std::vector<Connection_t*> switchesWithoutCandidate = getSwitchesInState(SwitchState::SwitchWithoutCandidate);
                if(switchStates.size() > switchesWithoutCandidate.size()){
                    transitionToState(TransactionAppState::WaitOnDeleteCandidate);
                    return true;
                }else if(switchStates.size() == switchesWithoutCandidate.size()){
                    // send_unlock_switch
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++){
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Unlock;
                            config->target = "running";
                            NetConfMessage_RPC* s_Switch_entsperren = createNetConfRPCForConfiguration(connection, config, UNLOCK_MSG_ID);
                            sendDelayed(s_Switch_entsperren, controllerProcessingTime, gate("applicationOut"));
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnUnlock);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInWaitOnUnlock(cMessage* msg){
    if(isRPCReplyEvent(msg)){
        // receive_switch_unlocked
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket())){
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), UNLOCK_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Switch_sperren");
            }else{
                switchStates[con]->hasLockedRunning = false;
                std::vector<Connection_t*> unlockedSwitches = getSwitchesInState(SwitchState::SwitchUnlocked);
                if(unlockedSwitches.size() < switchStates.size()){
                    transitionToState(TransactionAppState::WaitOnUnlock);
                    return true;
                }else if(unlockedSwitches.size() == switchStates.size()){
                    updatePhase(Phase::UNLOCK);
                    transitionToState(TransactionAppState::EndOfTransaction);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TransactionApp::handleMessageInErrorState(cMessage* msg){
    if(isLambdaEvent(msg)){
        // send_delete_candidate
        Connection_t* connection;
        Configuration_t* config;
        result = false;
        emit(resultOfTransaction,result);
        for(auto it = switchStates.begin(); it != switchStates.end(); it++){
            connection = it->first;
            if(connection && switchStates[connection]->hasCandidate){
                config = new Configuration_t();
                config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_DeleteConfig;
                config->target = "candidate";
                NetConfMessage_RPC* s_Kandidat_loeschen = createNetConfRPCForConfiguration(connection, config, DELETE_CANDIDATE_MSG_ID);
                sendDelayed(s_Kandidat_loeschen, controllerProcessingTime, gate("applicationOut"));
                emit(numSent, 1L);
            }
        }
        transitionToState(TransactionAppState::WaitOnDeleteCandidate);
        return true;
    }
    return false;
}

} // namespace SDN4CoRE
