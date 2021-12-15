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
#include "core4inet/scheduler/timer/Timer.h"
//SDN4CoRE
#include <sdn4core/netconf/applications/transactionModel/TimeSynchronousTransactionApp.h>
#include <sdn4core/netconf/applications/configparser/base/NetConfAppConfigParserCollection.h>
#include <sdn4core/utility/xml/XMLUtility.h>


namespace SDN4CoRE{

Define_Module(TimeSynchronousTransactionApp);

void TimeSynchronousTransactionApp::initialize()
{
    TransactionApp::initialize();
    _period = dynamic_cast<CoRE4INET::Period*>(this->getParentModule()->getParentModule()->getSubmodule("scheduler")->getSubmodule("period",_syncPeriod));
    controllerProcessingTime = this->par("controllerProcessingTime").doubleValue();
}

std::vector<NetConfApplicationBase::Connection_t*> TimeSynchronousTransactionApp::getSwitchesInState(int state){
    std::vector<NetConfApplicationBase::Connection_t*> resultVector;
    for(auto it = switchStates.begin(); it != switchStates.end(); it++) {
        if (((TimeSynchronousTransactionApp::SwitchState_s*)(it->second))->isInState(state)) {
            resultVector.push_back(it->first);
        }
    }
    return resultVector;
}

void TimeSynchronousTransactionApp::determineLockOrder(){
    for(auto& connection: _connections){
        switchStates[&connection] = new TimeSynchronousTransactionApp::SwitchState_t();
    }
}

Configuration_t* TimeSynchronousTransactionApp::getCommitTimestampConfig(NetConfConfigCommitTimestamp::CommitTimestamp_t timestamp){
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

std::string TimeSynchronousTransactionApp::transactionAppStateToString(int state)
{
    switch(state)
    {
        case TransactionAppState::WaitOnTimestampConfirmation:
            return "WaitOnTimestampConfirmation";

        default:
            return TransactionApp::transactionAppStateToString(state);
    }
}

void TimeSynchronousTransactionApp::finiteStateMachine(cMessage* msg)
{
    Enter_Method_Silent();//also used in Test environment so we need this to switch context
    bool eventHandled = false;
    switch(transactionState){
    case TransactionAppState::WaitOnTimestampConfirmation:
        eventHandled = handleMessageInWaitOnTimestampConfirmation(msg);
        checkEventHandled(eventHandled, msg);
        break;
    default:
        TransactionApp::finiteStateMachine(msg);
        break;
    }
}

bool TimeSynchronousTransactionApp::handleMessageInWaitOnChangeConfirmation(cMessage* msg)
{
    if(isRPCReplyEvent(msg))
    {
        // received_applied_changes
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
                switchStates[con]->hasConfiguration = true;
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
                switchStates[con]->hasConfiguration = true;
            }
            if((getSwitchesInState(SwitchState::SwitchWithChangedCandidateConfiguration).size() == switchStates.size())
                    && (getSwitchesInState(SwitchState::SwitchError).size() == 0))
            {
                // transition to next state
                NetConfConfigCommitTimestamp::CommitTimestamp_t timestamp = determineTimestamp();
                // send_timestamp
                Connection_t* connection;
                for(auto it = switchStates.begin(); it != switchStates.end(); it++)
                {
                    if(it->second->isInState(SwitchState::SwitchWithChangedCandidateConfiguration))
                    {
                        connection = it->first;
                        if(connection){
                            Configuration_t* config = getCommitTimestampConfig(timestamp);
                            NetConfMessage_RPC* s_Zeitstempel = createNetConfRPCForConfiguration(connection, config, TIMESTAMP_MSG_ID);
                            delete config; // delete the config as it has been duplicated during encapsulation in to NetConfMessage_RPC.
                            sendDelayed(s_Zeitstempel, controllerProcessingTime, gate("applicationOut"));
                            updatePhase(Phase::CONFIRMATION);
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
            // received_applying_changes_failed
            con->configurations[idx]->state = Configuration_t::ConfigurationState_t::ConfigurationStateError;
            switchStates[con]->hasError = true;
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
        // received_timestamp_accepted
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
                ((TimeSynchronousTransactionApp::SwitchState_s*)switchStates[con])->hasCommitTimeStamp = true;
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
            // received_timestamp_missed
            if(strcmp(reply->getMessage_id(), TIMESTAMP_MSG_ID) != 0)
            {
                throw cRuntimeError(" reply is not the response of e_Zeitpunkt_ ueberschritten");
            }
            else
            {
                Connection_t* con = findConnectionForReply(reply);
                switchStates[con]->hasError = true;
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

} // namespace SDN4CoRE
