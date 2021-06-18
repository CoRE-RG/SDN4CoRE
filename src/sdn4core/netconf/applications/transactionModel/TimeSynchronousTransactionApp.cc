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

#include <sdn4core/netconf/applications/transactionModel/TimeSynchronousTransactionApp.h>
#include "sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserCollection.h"
#include "sdn4core/utility/xml/XMLUtility.h"
#include "core4inet/scheduler/oscillator/Oscillator.h"
#include "core4inet/scheduler/timer/Timer.h"

namespace SDN4CoRE{

Define_Module(TimeSynchronousTransactionApp);

void TimeSynchronousTransactionApp::initialize()
{
    LAMBDA_EVENT = new cMessage(SELFMESSAGE_LAMBDA);
    _period = dynamic_cast<CoRE4INET::Period*>(this->getParentModule()->getParentModule()->getSubmodule("scheduler")->getSubmodule("period",_syncPeriod));
    controllerProcessingTime = this->par("controllerProcessingTime").doubleValue();
    numSent = registerSignal("numSentMsgs");
    numReceived = registerSignal("numReceivedMsgs");
    resultOfTransaction = registerSignal("transactionResult");
    transactionDuration = registerSignal("transactionDuration");
    lockPhase = registerSignal("lockPhase");
    changePhase = registerSignal("changePhase");
    confirmationPhase = registerSignal("confirmationPhase");
    unlockPhase = registerSignal("unlockPhase");

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
    scheduleNextConnection();
}

void TimeSynchronousTransactionApp::handleMessage(cMessage* msg)
{
    if(isFSMAlphabet(msg))
    {
        emit(numReceived, 1L);
        finiteStateMachine(msg);
        if(!isLambdaEvent(msg))
        {
            delete msg;
        }
    }
    else
    {
        NetConfApplicationBase::handleMessage(msg);
    }
}

void TimeSynchronousTransactionApp::scheduleNextConnection()
{
    for (auto& connection : _connections)
    {
        if(connection.state == ConnectionState_t::ConnectionStateWaiting)
        {
            connection.state = ConnectionState_t::ConnectionStateScheduled;
            cMessage* msg = new cMessage(SELFMESSAGE_SEND_HELLO);
            msg->setContextPointer(&connection);
            scheduleAt(connection.connectAt, msg);
            break;
        }
    }
}

void TimeSynchronousTransactionApp::scheduleNextConfigurationFor(Connection_t* connection)
{
    bool result = !_connections.empty();
    for(auto& connection: _connections)
    {
        if(connection.state != ConnectionState_t::ConnectionStateEstablished)
        {
            result = false;
            break;
        }
    }
    if(result)
    {
        scheduleTransactionStart(this->par("startTransaction").doubleValue());
    }
}

void TimeSynchronousTransactionApp::scheduleTransactionStart(SimTime startTime)
{
    Enter_Method_Silent();//also used in Test environment so we need this to switch context
    if(startTime == SimTime::ZERO)
    {
        scheduleAt(simTime(), new cMessage(SELFMESSAGE_START_TRANSACTION));
    }
    else if (startTime >= simTime())
    {
        scheduleAt(startTime, new cMessage(SELFMESSAGE_START_TRANSACTION));
    }
    else
    {
        throw cRuntimeError("Start Transaction time (%s) is in the past.",startTime.str().c_str());
    }
}

std::vector<NetConfApplicationBase::Connection_t*> TimeSynchronousTransactionApp::getSwitchesInState(SwitchState state)
{
    std::vector<NetConfApplicationBase::Connection_t*> resultVector;
    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
    {
        if (it->second.isInState(state))
        {
            resultVector.push_back(it->first);
        }
    }
    return resultVector;
}

void TimeSynchronousTransactionApp::determineLockOrder()
{
    for(auto& connection: _connections)
    {
        switchStates[&connection] = SwitchState_t();
    }
}

TimeSynchronousTransactionApp::TransactionAppState TimeSynchronousTransactionApp::getTransactionState()
{
    return transactionState;
}

NetConfConfigCommitTimestamp::CommitTimestamp_t TimeSynchronousTransactionApp::determineTimestamp()
{
    double wireDelay = 1/(this->par("signalDelay").doubleValue());
    double switchDelay = this->par("switchDelay").doubleValue();
    double switchProcessingTime = this->par("switchProcessingTime").doubleValue();
    double bitTransferTime = 1 / (this->par("bitRate").doubleValue());
    int ethernetFrameSizes[] = {SEND_TIMESTAMP_MSG_SIZE, ACK_TIMESTAMP_MSG_SIZE, SEND_COMMIT_MSG_SIZE};
    double sumOfLatencies = 0;
    double queuingDelay = MAX_ETHERNET_FRAME_SIZE * bitTransferTime;
    std::vector<std::string> distanceAndHopPerSwitches = cStringTokenizer(par("distanceAndHopsToSwitches"), ";").asVector();

    if(distanceAndHopPerSwitches.size() == 1)
    {
        std::vector<int> values = cStringTokenizer(distanceAndHopPerSwitches[0].c_str(), ",").asIntVector();
        int wireLength = values[0];
        int hop = values[1];
        for(int i = 0; i < distanceAndHopPerSwitches.size(); i++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(k == 2)
                {
                    _sumOfLastLatencies += wireDelay * wireLength + (hop + 1) * ethernetFrameSizes[k] * bitTransferTime + (hop * switchDelay) + ((hop + 1) * queuingDelay);
                }
                sumOfLatencies += wireDelay * wireLength + (hop + 1) * ethernetFrameSizes[k] * bitTransferTime + (hop * switchDelay) + ((hop + 1) * queuingDelay);
            }
        }
    }
    else if(distanceAndHopPerSwitches.size() == this->_connections.size())
    {
        std::vector<int> values;
        std::vector<int> wireLengths;
        std::vector<int> hops;
        for(int i = 0 ; i < distanceAndHopPerSwitches.size(); i++)
        {
            values = cStringTokenizer(distanceAndHopPerSwitches[i].c_str(), ",").asIntVector();
            wireLengths.push_back(values[0]);
            hops.push_back(values[1]);
        }
        for(int i = 0; i < this->_connections.size(); i++)
        {
            for(int k = 0; k < 3; k++)
            {
                if(k == 2)
                {
                    _sumOfLastLatencies += wireDelay * wireLengths[i] + (hops[i] + 1) * ethernetFrameSizes[k] * bitTransferTime + (hops[i] * switchDelay) + ((hops[i] + 1) * queuingDelay);
                }
                sumOfLatencies += wireDelay * wireLengths[i] + (hops[i] + 1) * ethernetFrameSizes[k] * bitTransferTime + (hops[i] * switchDelay) + ((hops[i] + 1) * queuingDelay);
            }
        }
    }
    else
    {
        throw cRuntimeError("number of switches are not %d", this->_connections.size());
    }

    double buffer = sumOfLatencies + (2*switchProcessingTime) + (2*controllerProcessingTime);
    CoRE4INET::Timer* timer = dynamic_cast<CoRE4INET::Timer*>(this->getParentModule()->getParentModule()->getSubmodule("scheduler")->getSubmodule("timer"));
    // period length
    CoRE4INET::Oscillator* oscillator = timer->getOscillator();
    double periodLength = _period->getCycleTicks() * oscillator->getPreciseTick().dbl();
    // current cycles
    uint32_t currentCycles = _period->getCycles();
    _timestamp.cycle = currentCycles + static_cast<uint32_t>(std::ceil(buffer/periodLength));
    _timestamp.time = buffer + timer->getTotalSimTime().dbl();
    _timestamp.period = _syncPeriod;
    _timestamp.executeAtStartOfPeriod = this->par("executeAtStartOfPeriod");
    return _timestamp;
}

bool TimeSynchronousTransactionApp::checkCommitrelease()
{
    bool commitRelease = false;
    double switchProcessingTime = this->par("switchProcessingTime").doubleValue();
    double buffer = _sumOfLastLatencies + switchProcessingTime;
    uint32_t currentCycles = _period->getCycles();
    // period length
    CoRE4INET::Oscillator* oscillator = dynamic_cast<CoRE4INET::Oscillator*>(this->getParentModule()->getParentModule()->getSubmodule("scheduler")->getSubmodule("oscillator"));
    double periodLength = _period->getCycleTicks() * oscillator->getPreciseTick().dbl();

    uint32_t calculatedExecutionCycle = currentCycles + static_cast<uint32_t>(std::ceil(buffer/periodLength));
    if( _timestamp.cycle > calculatedExecutionCycle)
    {
        commitRelease = true;
    }
    return commitRelease;
}

std::string TimeSynchronousTransactionApp::transactionAppStateToString(TransactionAppState state)
{
    switch(state)
    {
    case TimeSynchronousTransactionApp::BeginOfTransaction:
        return "BeginOfTransaction";
    case TimeSynchronousTransactionApp::WaitOnLockResponse:
        return "WaitOnLockResponse";
    case TimeSynchronousTransactionApp::WaitOnCandidateConfirmation:
        return "WaitOnCandidateConfirmation";
    case TimeSynchronousTransactionApp::WaitOnChangeConfirmation:
        return "WaitOnChangeConfirmation";
    case TimeSynchronousTransactionApp::WaitOnTimestampConfirmation:
        return "WaitOnTimestampConfirmation";
    case TimeSynchronousTransactionApp::WaitOnCommitExecution:
        return "WaitOnCommit_Execution";
    case TimeSynchronousTransactionApp::WaitOnDeleteOldConfiguration:
        return "WaitOnDeleteOldConfiguration";
    case TimeSynchronousTransactionApp::WaitOnDeleteCandidate:
        return "WaitOnDeleteCandidate";
    case TimeSynchronousTransactionApp::WaitOnUnlock:
        return "WaitOnUnlock";
    case TimeSynchronousTransactionApp::ErrorState:
        return "ErrorState";
    case TimeSynchronousTransactionApp::EndOfTransaction:
        return "EndOfTransaction";
    default:
        return "invalid state";
    }
}

NetConfApplicationBase::Connection_t* TimeSynchronousTransactionApp::findConnectionForReply(NetConfMessage_RPCReply* reply)
{
    //check if msg has context pointer
    Connection_t* found = nullptr;
    if(NetConfCtrlInfo* info = dynamic_cast<NetConfCtrlInfo*>(reply->getControlInfo()))
    {
        for (size_t i = 0; i < _connections.size(); i++)
        {
            auto& connection = _connections[i];
            if (connection.state
                    == ConnectionState_t::ConnectionStateEstablished
                    && connection.session_id == info->getSession_id())
            {
                found = &connection;
                break;
            }
        }
        // check if connection is defined
        if(found == nullptr)
        {
            throw cRuntimeError("undefined connection");
        }
    }
    else
    {
        throw cRuntimeError("undefined sessionInfo");
    }
    return found;
}

bool TimeSynchronousTransactionApp::isFSMAlphabet(cMessage* msg)
{
    return isStartTransactionEvent(msg) || isRPCReplyEvent(msg) || isLambdaEvent(msg);
}

bool TimeSynchronousTransactionApp::isStartTransactionEvent(cMessage* msg)
{
    return msg->isSelfMessage() && strcmp(msg->getName(), SELFMESSAGE_START_TRANSACTION) == 0;
}

bool TimeSynchronousTransactionApp::isRPCReplyEvent(cMessage* msg)
{
    if(dynamic_cast<NetConfMessage_RPCReply*>(msg))
    {
        return true;
    }
    return false;
}

bool TimeSynchronousTransactionApp::isLambdaEvent(cMessage* msg)
{
    return msg == TimeSynchronousTransactionApp::LAMBDA_EVENT;
}


Configuration_t* TimeSynchronousTransactionApp::getCommitTimestampConfig(NetConfConfigCommitTimestamp::CommitTimestamp_t timestamp)
{
    NetConfConfigCommitTimestamp* netConfConfigCommitTimestamp = new NetConfConfigCommitTimestamp();
    netConfConfigCommitTimestamp->setCommitTimestamp(timestamp);

    Configuration_t* config = new Configuration_t();
    config->data = netConfConfigCommitTimestamp;
    config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig;
    config->target = "candidate";
    config->filter = new NetConfFilter();
    config->state = Configuration_t::ConfigurationState_t::ConfigurationStateWaiting;

    return config;
}

void TimeSynchronousTransactionApp::transitionToState(TransactionAppState nextState)
{
    //execute exit action of current state
    switch (transactionState)
    {
    default:
        break;
    }
    //switch state
    transactionState = nextState;
    // execute entry action of next state
    Connection_t* connectionToLock = nullptr;
    switch (nextState) {
    case TransactionAppState::WaitOnLockResponse:
        for(auto it = switchStates.begin(); it != switchStates.end(); it++)
        {
            if(it->second.isInState(SwitchState::SwitchAvailable))
            {
                connectionToLock = it->first;
                break;
            }
        }
        if(connectionToLock)
        {
            Configuration_t* config = new Configuration_t();
            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Lock;
            config->target = "running";
            NetConfMessage_RPC* s_Switch_sperren = createNetConfRPCForConfiguration(connectionToLock, config, LOCK_MSG_ID);
            sendDelayed(s_Switch_sperren, controllerProcessingTime, gate("applicationOut"));
            emit(numSent, 1L);
        }
        else
        {
            throw cRuntimeError("connection cannot locked");
        }
        break;
    case TransactionAppState::ErrorState:
        result = false;
        emit(resultOfTransaction,result);
        scheduleAt(simTime(), LAMBDA_EVENT);
        break;
    case TransactionAppState::EndOfTransaction:
        result = true;
        emit(resultOfTransaction,result);
        emit(transactionDuration, true);
        break;
    default:
        //throw cRuntimeError("cannot execute entry action of a state that has no entry action");
        break;
    }
}

void TimeSynchronousTransactionApp::finiteStateMachine(cMessage* msg)
{
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
    case TransactionAppState::WaitOnTimestampConfirmation:
        eventHandled = handleMessageInWaitOnTimestampConfirmation(msg);
        break;
    case TransactionAppState::ErrorState:
        eventHandled = handleMessageInErrorState(msg);
        break;
    case TransactionAppState::WaitOnCommitExecution:
        eventHandled = handleMessageInWaitOnCommit_Execution(msg);
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
        cRuntimeError("Invalid State in FSM-TimeSynchronousTransactionApp");
        break;
    }
    checkEventHandled(eventHandled, msg);
}

void TimeSynchronousTransactionApp::checkEventHandled(bool eventHandled, cMessage* msg)
{
    if(!eventHandled)
    {
        std::string errorMsg = "Cannot handle event ";
        errorMsg += msg->getFullName();
        errorMsg += " in state ";
        errorMsg += transactionAppStateToString(transactionState);
        const char* errorMessage = errorMsg.c_str();
        throw cRuntimeError(errorMessage);
    }
}

bool TimeSynchronousTransactionApp::handleMessageInBeginOfTransaction(cMessage* msg)
{
    if(isStartTransactionEvent(msg))
    {
        emit(transactionDuration, true);
        emit(lockPhase, true);
        determineLockOrder();
        transitionToState(TransactionAppState::WaitOnLockResponse);
        return true;
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnLockResponse(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Switch_gesperrt
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if (((strcmp(reply->getMessage_id(), LOCK_MSG_ID) == 0) && (switchStates[con].isInState(SwitchState::SwitchAvailable))))
            {
                switchStates[con].hasLockedRunning = true;
                std::vector<Connection_t*> lockedSwitches = getSwitchesInState(SwitchState::SwitchLocked);
                if(lockedSwitches.size() < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnLockResponse);
                    return true;
                }
                else if(lockedSwitches.size() == switchStates.size())
                {
                    emit(lockPhase, true);
                    emit(changePhase,true);
                    // s_Konfig_kopieren
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection){
                            config = new Configuration_t();
                            config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_CopyConfig;
                            config->source = "running";
                            config->target = "candidate";
                            NetConfMessage_RPC* s_Konfig_kopieren = createNetConfRPCForConfiguration(connection, config, COPY_CONFIG_MSG_ID);
                            sendDelayed(s_Konfig_kopieren, controllerProcessingTime, gate("applicationOut"));
                            emit(numSent, 1L);
                        }
                    }
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
            }
            else
            {
                throw cRuntimeError("reply is not the response of e_Switch_gesperrt and cannot locked");
            }
        }
        // e_bereits_belegt
        else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket()))
        {
            if(strcmp(reply->getMessage_id(), LOCK_MSG_ID) != 0)
            {
                throw cRuntimeError("error-reply is not the response of e_bereits_belegt ");
            }
            else
            {
                std::vector<Connection_t*> lockedSwitches = getSwitchesInState(SwitchState::SwitchLocked);
                if(lockedSwitches.size() == 0)
                {
                    result = false;
                    emit(resultOfTransaction,result);
                    transitionToState(TransactionAppState::EndOfTransaction);
                    return true;
                }
                else if(lockedSwitches.size() > 0)
                {
                    Connection_t* con = findConnectionForReply(reply);
                    // s_Switch_entsperren
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection){
                            if(connection->remoteAddress == con->remoteAddress)
                            {
                                config = new Configuration_t();
                                config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Unlock;
                                config->target = "running";
                                NetConfMessage_RPC* s_Switch_entsperren = createNetConfRPCForConfiguration(connection, config, UNLOCK_MSG_ID);
                                sendDelayed(s_Switch_entsperren, controllerProcessingTime, gate("applicationOut"));
                                emit(numSent, 1L);
                            }
                        }
                    }
                    switchStates[con].hasLockedRunning = false;
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

bool TimeSynchronousTransactionApp::handleMessageInWaitOnCandidateConfirmation(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Konfig_kopiert
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), COPY_CONFIG_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Konfig_kopiert");
            }
            else
            {
                switchStates[con].hasCandidate = true;
                std::vector<Connection_t*> lockedSwitchesWithCandidate = getSwitchesInState(SwitchState::SwitchWithCandidate);
                std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
                if(failedSwitch.size() > 0)
                {
                    if((lockedSwitchesWithCandidate.size() + failedSwitch.size()) == switchStates.size())
                    {
                        transitionToState(TransactionAppState::ErrorState);
                        return true;

                    }
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
                else if(lockedSwitchesWithCandidate.size() < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
                else if(lockedSwitchesWithCandidate.size() == switchStates.size())
                {
                    // s_Switch_Kandidat_sperren
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
        }
        else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket()))
        {
            // e_Kandidat_fehlgeschlagen
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), COPY_CONFIG_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Kandidat_fehlgeschlagen");
            }
            else
            {
                switchStates[con].hasError = true;
                std::vector<Connection_t*> lockedSwitchesWithCandidate = getSwitchesInState(SwitchState::SwitchWithCandidate);
                std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
                if((lockedSwitchesWithCandidate.size() == 0) && failedSwitch.size() == switchStates.size()){
                    //s_Switch_entsperren
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection)
                        {
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
                }
                else if((lockedSwitchesWithCandidate.size() + failedSwitch.size()) < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnCandidateConfirmation);
                    return true;
                }
                else if((lockedSwitchesWithCandidate.size() + failedSwitch.size()) == switchStates.size())
                {
                    transitionToState(TransactionAppState::ErrorState);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnCandidateLockResponse(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        // e_Switch_Kandidat_gesperrt
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), LOCK_CANDIDATE_MSG_ID) != 0){
                throw cRuntimeError(" reply is not the response of e_Switch_Kandidat_gesperrt");
            }
            else
            {
                switchStates[con].hasLockedCandidate = true;
                std::vector<Connection_t*> switchesWithLockedCandidate = getSwitchesInState(SwitchState::SwitchWithLockedCandidate);
                if(switchesWithLockedCandidate.size() < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnCandidateLockResponse);
                    return true;
                }
                else if(switchesWithLockedCandidate.size() == switchStates.size())
                {
                    // s_Aenderung_durchfuehren
                    Connection_t* connection;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection && connection->configurations[0]->state == Configuration_t::ConfigurationState_t::ConfigurationStateWaiting)
                        {
                            connection->configurations[0]->target = "candidate";
                            NetConfMessage_RPC* s_Aenderung_durchfuehren = createNetConfRPCForConfiguration(connection, connection->configurations[0], std::to_string(CHANGE_MSG_ID+0));
                            sendDelayed(s_Aenderung_durchfuehren, controllerProcessingTime, gate("applicationOut"));
                            emit(numSent, 1L);
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

bool TimeSynchronousTransactionApp::handleMessageInWaitOnChangeConfirmation(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Aenderung_durchgefuehrt
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        Connection_t* con = findConnectionForReply(reply);
        int idx = atoi(reply->getMessage_id()) - CHANGE_MSG_ID;
        if(con->configurations[idx]->state != Configuration_t::ConfigurationState_t::ConfigurationStateRequested)
        {
            throw cRuntimeError(" reply is not the response for last change of e_Aenderung_durchgefuehrt");
        }
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            con->configurations[idx]->state = Configuration_t::ConfigurationState_t::ConfigurationStateSuccess;
            if(getSwitchesInState(SwitchState::SwitchError).size() > 0)
            {
                switchStates[con].hasConfiguration = true;
                if(getSwitchesInState(SwitchState::SwitchError).size()+
                        getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration).size() == switchStates.size())
                {
                    transitionToState(TransactionAppState::ErrorState);
                    return true;
                }
                else
                {
                    transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                    return true;
                }
            }
            std::vector<Configuration_t*> configsInConnection = con->configurations;
            int i;
            for(i = 0; i < configsInConnection.size(); i++)
            {
                if(configsInConnection[i]->state == Configuration_t::ConfigurationState_t::ConfigurationStateWaiting)
                {
                    con->configurations[i]->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_EditConfig;
                    con->configurations[i]->target = "candidate";
                    NetConfMessage_RPC* s_Aenderung_durchfuehren = createNetConfRPCForConfiguration(con, con->configurations[i], std::to_string(CHANGE_MSG_ID+i));
                    sendDelayed(s_Aenderung_durchfuehren, controllerProcessingTime, gate("applicationOut"));
                    emit(numSent, 1L);
                    con->configurations[i]->state = Configuration_t::ConfigurationState_t::ConfigurationStateRequested;
                    break;//only send next one
                }
            }
            if(i >= configsInConnection.size())
            {
                //no more changes sent
                switchStates[con].hasConfiguration = true;
            }
            if((getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration).size() == switchStates.size())
                    && (getSwitchesInState(SwitchState::SwitchError).size() == 0))
            {
                // transition to next state
                NetConfConfigCommitTimestamp::CommitTimestamp_t timestamp = determineTimestamp();
                // s_Zeitstempel
                Connection_t* connection;
                for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                {
                    if(it->second.isInState(SwitchState::SwitchWithChangedCandidateConfiguration))
                    {
                        connection = it->first;
                        if(connection){
                            Configuration_t* config = getCommitTimestampConfig(timestamp);
                            NetConfMessage_RPC* s_Zeitstempel = createNetConfRPCForConfiguration(connection, config, TIMESTAMP_MSG_ID);
                            emit(changePhase,true);
                            sendDelayed(s_Zeitstempel, controllerProcessingTime, gate("applicationOut"));
                            emit(confirmationPhase,true);
                            emit(numSent, 1L);
                        }
                    }
                }
                transitionToState(TransactionAppState::WaitOnTimestampConfirmation);
                return true;
            }
            else
            { // done with changes || no more changes for this switch
                transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                return true;
            }
        }
        else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket())){
            // e_Aenderung_fehlgeschlagen
            con->configurations[idx]->state = Configuration_t::ConfigurationState_t::ConfigurationStateError;
            switchStates[con].hasError = true;
            std::vector<Connection_t*> switchesWithChangedCandidateConfig = getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration);
            std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
            if((switchesWithChangedCandidateConfig.size()+failedSwitch.size()) < switchStates.size())
            {
                transitionToState(TransactionAppState::WaitOnChangeConfirmation);
                return true;
            }
            else if((switchesWithChangedCandidateConfig.size()+failedSwitch.size()) == switchStates.size())
            {
                transitionToState(TransactionAppState::ErrorState);
                return true;
            }
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnTimestampConfirmation(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Zeitstempel_akzeptiert
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), TIMESTAMP_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Zeitstempel_akzeptiert");
            }
            else
            {
                switchStates[con].hasCommitTimeStamp = true;
                std::vector<Connection_t*> switchesWithTimestamp = getSwitchesInState(SwitchState::SwitchWithTimestamp);
                std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
                if(failedSwitch.size() > 0 &&
                        ((switchesWithTimestamp.size()+failedSwitch.size()) == switchStates.size()))
                {
                    transitionToState(TransactionAppState::ErrorState);
                    return true;
                }
                else if(switchesWithTimestamp.size() < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnTimestampConfirmation);
                    return true;
                }
                else if(switchesWithTimestamp.size() == switchStates.size())
                {
                    if(!checkCommitrelease())
                    {
                        transitionToState(TransactionAppState::ErrorState);
                        return true;
                    }
                    else
                    {
                        Connection_t* connection;
                        for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                        {
                            connection = it->first;
                            if(connection){
                                Configuration_t* config = new Configuration_t();
                                config->type = Configuration_t::NetConfMessageType_t::NetConfMessageType_Commit;
                                NetConfMessage_RPC* s_Commit_freigeben = createNetConfRPCForConfiguration(connection, config, COMMIT_APPROVED_MSG_ID);
                                sendDelayed(s_Commit_freigeben, controllerProcessingTime, gate("applicationOut"));
                                emit(numSent, 1L);
                            }
                        }
                        transitionToState(TransactionAppState::WaitOnCommitExecution);
                        return true;
                    }
                }
            }
        }
        else if(dynamic_cast<NetConf_RPCReplyElement_Error*>(reply->getEncapsulatedPacket()))
        {
            // e_Zeitpunkt_ ueberschritten
            if(strcmp(reply->getMessage_id(), TIMESTAMP_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Zeitpunkt_ ueberschritten");
            }
            else
            {
                Connection_t* con = findConnectionForReply(reply);
                switchStates[con].hasError = true;
                std::vector<Connection_t*> switchesWithTimestamp = getSwitchesInState(SwitchState::SwitchWithTimestamp);
                std::vector<Connection_t*> failedSwitch = getSwitchesInState(SwitchState::SwitchError);
                if((switchesWithTimestamp.size() + failedSwitch.size()) < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnTimestampConfirmation);
                    return true;
                }
                else if((switchesWithTimestamp.size() + failedSwitch.size()) == switchStates.size())
                {
                    transitionToState(TransactionAppState::ErrorState);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnCommit_Execution(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Commit_ausgefuehrt
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), COMMIT_APPROVED_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Commit_ausgefuehrt");
            }
            else
            {
                switchStates[con].hasCommited = true;
                std::vector<Connection_t*> commitedSwitches = getSwitchesInState(SwitchState::SwitchCommited);
                if(switchStates.size() > commitedSwitches.size())
                {
                    transitionToState(TransactionAppState::WaitOnCommitExecution);
                    return true;
                }
                else if(switchStates.size() == commitedSwitches.size())
                {
                    emit(confirmationPhase,true);
                    emit(unlockPhase, true);
                    // s_alte_Konfig_loeschen
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection)
                        {
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
        }
        else
        {
            // this is a hardware fault and not handled in transaction
            throw cRuntimeError(" Reply for commit execution is not ok response of e_Commit_ausgefuehrt");
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnDeleteOldConfiguration(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_alte_Konfig_geloescht
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), DELETE_OLD_CONFIG_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_alte_Konfig_geloescht");
            }
            else
            {
                switchStates[con].hasCandidate = false;
                switchStates[con].hasLockedCandidate = false;
                std::vector<Connection_t*> switchesWithoutOldConfig = getSwitchesInState(SwitchState::SwitchWithoutOldConfig);
                if(switchesWithoutOldConfig.size() == switchStates.size())
                {
                    // s_Switch_entsperren
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection)
                        {
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
                }
                else if(switchesWithoutOldConfig.size() < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnDeleteOldConfiguration);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnDeleteCandidate(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Kandidat_geloescht
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), DELETE_CANDIDATE_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Kandidat_geloescht");
            }
            else
            {
                switchStates[con].hasCandidate = false;
                switchStates[con].hasLockedCandidate = false;
                std::vector<Connection_t*> switchesWithoutCandidate = getSwitchesInState(SwitchState::SwitchWithoutCandidate);
                if(switchStates.size() > switchesWithoutCandidate.size())
                {
                    transitionToState(TransactionAppState::WaitOnDeleteCandidate);
                    return true;
                }
                else if(switchStates.size() == switchesWithoutCandidate.size())
                {
                    // s_Switch_entsperren
                    Connection_t* connection;
                    Configuration_t* config;
                    for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                    {
                        connection = it->first;
                        if(connection)
                        {
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
                }
            }
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnUnlock(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // e_Switch_sperren
        NetConfMessage_RPCReply* reply = dynamic_cast<NetConfMessage_RPCReply*>(msg);
        if(dynamic_cast<NetConf_RPCReplyElement_Ok*>(reply->getEncapsulatedPacket()))
        {
            Connection_t* con = findConnectionForReply(reply);
            if(strcmp(reply->getMessage_id(), UNLOCK_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Switch_sperren");
            }
            else
            {
                switchStates[con].hasLockedRunning = false;
                std::vector<Connection_t*> unlockedSwitches = getSwitchesInState(SwitchState::SwitchUnlocked);
                if(unlockedSwitches.size() < switchStates.size())
                {
                    transitionToState(TransactionAppState::WaitOnUnlock);
                    return true;
                }
                else if(unlockedSwitches.size() == switchStates.size())
                {
                    emit(unlockPhase, true);
                    transitionToState(TransactionAppState::EndOfTransaction);
                    return true;
                }
            }
        }
    }
    return false;
}

bool TimeSynchronousTransactionApp::handleMessageInErrorState(cMessage* msg)
{
    if(isLambdaEvent(msg))
    {
        // s_Kandidat_loeschen
        Connection_t* connection;
        Configuration_t* config;
        result = false;
        emit(resultOfTransaction,result);
        for(auto it = switchStates.begin(); it != switchStates.end(); it++)
        {
            connection = it->first;
            if(connection && switchStates[connection].hasCandidate)
            {
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
