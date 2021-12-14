//
// c Timo Haeckel, for HAW Hamburg
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

//SDN4CoRE
#include <sdn4core/netconf/datastores/manager/base/NetConfDataStoreManagerBase.h>
#include <sdn4core/netconf/server/base/NetConfServerBase.h>
#include <sdn4core/utility/dynamicmodules/DynamicModuleHandling.h>
#include <sdn4core/netconf/messages/NetConfCtrlInfo_m.h>
#include <sdn4core/netconf/NetConfDefines.h>
// CORE4INET
#include "core4inet/scheduler/timer/Timer.h"
//INET
#include "inet/common/ModuleAccess.h"


using namespace std;

namespace SDN4CoRE {

Register_Class(NetConfDataStoreManagerBase);

const char NetConfDataStoreManagerBase::REQUEST_IN_GATE_NAME[] = "requestIn";
const char NetConfDataStoreManagerBase::RESPONSE_OUT_GATE_NAME[] = "responseIn";

simsignal_t NetConfDataStoreManagerBase::commitExecutionSignal = registerSignal("commitExecution");
simsignal_t NetConfDataStoreManagerBase::editConfigSignal = registerSignal("editConfig");

void NetConfDataStoreManagerBase::initialize() {
    handleParameterChange(nullptr);

    //find netconf data stores
    _netConfServer = inet::getModuleFromPar<NetConfServerBase>(
            par("pathToNetConfServer"), this, true);
    if (!_netConfServer) {
        string msg = "No NetConf server found in ";
        msg += par("pathToNetConfServer").stdstringValue();
        throw cRuntimeError(msg.c_str());
    }
    _runningStore = dynamic_cast<NetConfRunningDataStore*>(this->getParentModule()->getSubmodule("running"));
    if (!_runningStore) {
        throw cRuntimeError(
                "No NetConf running config data store found ");
    }
    _candidateStore = dynamic_cast<NetConfCandidateDataStore*>(this->getParentModule()->getSubmodule("candidate"));
    if (!_candidateStore) {
        throw cRuntimeError(
                "No NetConf candidate config data store found ");
    }
    // TODO implement XML startup configuration.

    auto scheduler = this->getParentModule()->getParentModule()->getSubmodule("scheduler");
    if(scheduler){
        _newCycleSignal = registerSignal("newCycle");
        int numOfPeriods = scheduler->getSubmodule("period", 0)->getVectorSize();
        for(int i = 0; i < numOfPeriods; i++){
        _periods.push_back(dynamic_cast<CoRE4INET::Period*>(scheduler->getSubmodule("period", i)));
        }
    }
    resetCommitTimestamp();
    WATCH(_commitTimestamp);
}

void NetConfDataStoreManagerBase::handleParameterChange(const char* parname) {
    if (!parname || !strcmp(parname, "displayStatus")) {
        _displayStatus = par("displayStatus");
    }
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Data(
        NetConfConfig* config) {
    NetConf_RPCReplyElement_Data* dataReply = nullptr;
    if (config) {
        dataReply = new NetConf_RPCReplyElement_Data();
        dataReply->encapsulate(config);
        dataReply->setByteLength(config->getByteSize());
    }

    return dynamic_cast<NetConf_RPCReplyElement*>(dataReply);
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Error(
        int error_type, const char * error_tag, int error_severity,
        const char * error_app_tag = "") {
    // create error
    NetConf_RPCReplyElement_Error* errorReply =
            new NetConf_RPCReplyElement_Error();
    errorReply->setError_type(error_type);
    errorReply->setError_tag(error_tag);
    errorReply->setError_severity(error_severity);
    errorReply->setError_app_tag(error_app_tag);
    errorReply->addByteLength(std::strlen(error_tag) + std::strlen(error_app_tag));
    return dynamic_cast<NetConf_RPCReplyElement*>(errorReply);
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::createRPCReplyElement_Ok() {
    NetConf_RPCReplyElement_Ok* okReply = new NetConf_RPCReplyElement_Ok();
    return dynamic_cast<NetConf_RPCReplyElement*>(okReply);
}

void NetConfDataStoreManagerBase::handleMessage(cMessage *msg) {
    // the reply element to transmit after handling operation.
    NetConf_RPCReplyElement* reply = nullptr;

    if (NetConfOperation* operation = dynamic_cast<NetConfOperation*>(msg)) {

        // check if it is of type get config operation
        if (dynamic_cast<NetConfOperation_GetConfig*>(operation)) {
            reply = handleGetConfig(operation);
        }
        // check if it is of type edit config operation
        else if (dynamic_cast<NetConfOperation_EditConfig*>(operation)) {
            reply = handleEditConfig(operation);
        }
        // check if it is of type copy config operation
        else if (dynamic_cast<NetConfOperation_CopyConfig*>(operation)) {
            reply = handleCopyConfig(operation);
        }
        // check if it is of type delete config operation
        else if (dynamic_cast<NetConfOperation_DeleteConfig*>(operation)) {
            reply = handleDeleteConfig(operation);
        }
        // check if it is of type get operation
        else if (dynamic_cast<NetConfOperation_Get*>(operation)) {
            reply = handleGet(operation);
        }
        // check if it is of type lock operation
        else if (dynamic_cast<NetConfOperation_Lock*>(operation)){
            reply = handleLock(operation);
        }
        // check if it is of type unlock operation
        else if(dynamic_cast<NetConfOperation_Unlock*>(operation)){
            reply = handleUnlock(operation);
        }
        // check if it is of type commit operation
        else if(dynamic_cast<NetConfOperation_Commit*>(operation)){
            reply = handleCommit(operation);
            if(reply == nullptr) {
                // this is a timed commit... so the reply is sent asynchronously
                return;
            }
        }

        // this operation is not known.
        else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_RPC,
                    "This operation is not supported.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }

        if (reply) {
            // attach control info
            reply->setControlInfo(operation->removeControlInfo());
            // send the reply
            sendDirect(reply, _netConfServer->gate(RESPONSE_OUT_GATE_NAME));
        } else {
            throw cRuntimeError(
                    "Received an operation that did not result in a reply, this should never happen!");
        }

    }
    else if(msg->isSelfMessage() || dynamic_cast<CoRE4INET::SchedulerTimerEvent*>(msg)){
        if(msg->isName("EXECUTE_TIMED_COMMIT")){
            bool result = executeCommit();
            if(_commitTimestamp.executeAtStartOfPeriod){
                _periods[_commitTimestamp.period]->unsubscribe(_newCycleSignal, this);
            }
            if(result){
                reply = createRPCReplyElement_Ok();
            }
            else{
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "Commit Execution finished with errors",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
            reply->setControlInfo(_commitOperation->removeControlInfo());
            sendDirect(reply,_netConfServer->gate(RESPONSE_OUT_GATE_NAME));
            resetCommitTimestamp();
        }
    }
    else {
        throw cRuntimeError("Received message the is not a netconf operation.");
    }
    delete msg;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleGetConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type get config operation
    if (NetConfOperation_GetConfig* getConfig =
            dynamic_cast<NetConfOperation_GetConfig*>(operation)) {
        NetConfConfig* config = nullptr;
        if(strcmp(getConfig->getSource(), NETCONF_CONFIG_RUNNING) == 0) {
            config = _runningStore->getConfig(getConfig->getFilter());
        } else if (strcmp(getConfig->getSource(), NETCONF_CONFIG_CANDIDATE) == 0) {
            config = _candidateStore->getConfig(getConfig->getFilter());
        } else {
            // create error
            return createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "The Config store does not exist.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }

        if (config) {
            // create response
            reply = createRPCReplyElement_Data(config);
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Failed to retrieve the data requested.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleEditConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type edit config operation
    if (NetConfOperation_EditConfig* editConfig =
            dynamic_cast<NetConfOperation_EditConfig*>(operation)) {
        bool success = false;
        auto encap = editConfig->decapsulate();
        NetConfDataStoreBase* storeToEdit = nullptr;
        if(NetConfConfig* config = dynamic_cast<NetConfConfig*>(encap)){
            if(strcmp(editConfig->getTarget(), NETCONF_CONFIG_RUNNING) == 0) {
                storeToEdit = _runningStore;
            } else if (strcmp(editConfig->getTarget(), NETCONF_CONFIG_CANDIDATE) == 0) {
                storeToEdit = _candidateStore;
            } else {
                // create error
                return createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "The Config store does not exist.",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
            if (!verifyLock(storeToEdit, operation)) {
                return createRPCReplyElement_Error(
                                NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                                "Store Locked",
                                NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }

            if(NetConfConfigCommitTimestamp* netconfCommitTimestamp = dynamic_cast<NetConfConfigCommitTimestamp*>(encap)){
                NetConfConfigCommitTimestamp::CommitTimestamp_t commitTimestamp = netconfCommitTimestamp->getCommitTimestamp();
                CoRE4INET::Timer* timer = dynamic_cast<CoRE4INET::Timer*>(this->getParentModule()->getParentModule()->getSubmodule("scheduler")->getSubmodule("timer"));
                CoRE4INET::Period* period = _periods[commitTimestamp.period];
                if((commitTimestamp.cycle > period->getCycles() && commitTimestamp.executeAtStartOfPeriod)
                        || (commitTimestamp.time > timer->getTotalSimTime().dbl() && !commitTimestamp.executeAtStartOfPeriod)){
                    _commitTimestamp = netconfCommitTimestamp->getCommitTimestamp();
                    success = true;
                }
                else{
                    return createRPCReplyElement_Error(
                            NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                            "Commit Timestamp is in the past.",
                            NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
                }
            } else {
                success = storeToEdit->editConfig(editConfig->getDefaultOperation(),
                            editConfig->getErrorOption(), config);
                emit(editConfigSignal,1L);
            }
        } else {
            throw cRuntimeError("Edit config does not contain a configuration");
        }

        delete encap;

        if (success) {
            // create response
            reply = createRPCReplyElement_Ok();
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Failed to apply config.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleCopyConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;
    // check if it is of type copy config operation
    if (NetConfOperation_CopyConfig* copyConfig =
            dynamic_cast<NetConfOperation_CopyConfig*>(operation)) {
        bool success = false;
        if (!verifyLock(_runningStore, operation) || !verifyLock(_candidateStore, operation)) {
            return createRPCReplyElement_Error(
                            NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                            "Store Locked",
                            NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
        if( (strcmp(copyConfig->getSource(), NETCONF_CONFIG_CANDIDATE) == 0) &&
                (strcmp(copyConfig->getTarget(), NETCONF_CONFIG_RUNNING) == 0) ) {
            success = _candidateStore->applyTo(_runningStore);
            if (success) {
                // create response
                reply = createRPCReplyElement_Ok();
            } else {
                // create error
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "Failed to copy config.",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
        } else if ( (strcmp(copyConfig->getSource(), NETCONF_CONFIG_RUNNING) == 0) &&
                (strcmp(copyConfig->getTarget(), NETCONF_CONFIG_CANDIDATE) == 0) ) {
            _candidateStore->clear();
            reply = createRPCReplyElement_Ok();
        } else {
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Target or Source is unknown",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }
    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleDeleteConfig(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type delete config operation
    if (NetConfOperation_DeleteConfig* deleteConfig =
            dynamic_cast<NetConfOperation_DeleteConfig*>(operation)) {
        if(strcmp(deleteConfig->getTarget(), NETCONF_CONFIG_RUNNING) == 0){
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "The running config must not be deleted.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
        else if(strcmp(deleteConfig->getTarget(), NETCONF_CONFIG_CANDIDATE) == 0){
            if (!verifyLock(_candidateStore, operation)) {
                return createRPCReplyElement_Error(
                                NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                                "Store Locked",
                                NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
            _candidateStore->clear();
            _candidateStore->unlock();
            reply = createRPCReplyElement_Ok();
        }
        else{
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Target is unknown.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }
    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleGet(
        NetConfOperation* operation) {
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type get operation
    if (NetConfOperation_Get* get =
            dynamic_cast<NetConfOperation_Get*>(operation)) {
        NetConfConfig* config = new NetConfConfig();
        if (config) {
            // create response
            reply = createRPCReplyElement_Data(config);
        } else {
            // create error
            reply = createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "Failed to retrieve the data requested.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }
    }

    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleLock(
        NetConfOperation* operation){
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type lock operation
    if(NetConfOperation_Lock* lock =
            dynamic_cast<NetConfOperation_Lock*>(operation)){
        NetConfDataStoreBase* configStoreToLock = nullptr;
        if(strcmp(lock->getTarget(), NETCONF_CONFIG_RUNNING) == 0) {
            configStoreToLock = _runningStore;
        } else if (strcmp(lock->getTarget(), NETCONF_CONFIG_CANDIDATE) == 0) {
            configStoreToLock = _candidateStore;
        } else {
            // create error
            return createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "The Config store does not exist.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }

        if(NetConfCtrlInfo* controlInfo =
                dynamic_cast<NetConfCtrlInfo*> (lock->getControlInfo())){

            if(configStoreToLock->checkAndLock(controlInfo->getSession_id())){
                reply = createRPCReplyElement_Ok();
            }else{
                const char* errorInfo = to_string(configStoreToLock->getLockOwner()).c_str();
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "lock-denied",// error-tag is "lock-denied"
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR,
                        errorInfo//error-info is the session-id of the lock-owner, if the lock is held by a non-netconf entity it is 0
                );
            }
        }
    }
    return reply;
}

bool NetConfDataStoreManagerBase::verifyLock(NetConfDataStoreBase* datastore, NetConfOperation* operation){
    NetConfCtrlInfo* controlInfo = dynamic_cast<NetConfCtrlInfo*> (operation->getControlInfo());
    int sessionId = controlInfo->getSession_id();
    if(datastore->isLocked()){
        if(!datastore->isLockedBy(sessionId)){
            return false;
        }
    }
    return true;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleUnlock(
        NetConfOperation* operation){
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type unlock operation
    if(NetConfOperation_Unlock* unlock =
            dynamic_cast<NetConfOperation_Unlock*>(operation)){
        NetConfDataStoreBase* configStoreToUnlock = nullptr;
        if(strcmp(unlock->getTarget(), NETCONF_CONFIG_RUNNING) == 0) {
            configStoreToUnlock = _runningStore;
        } else if (strcmp(unlock->getTarget(), NETCONF_CONFIG_CANDIDATE) == 0) {
            configStoreToUnlock = _candidateStore;
        } else {
            // create error
            return createRPCReplyElement_Error(
                    NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                    "The Config store does not exist.",
                    NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
        }

        if(NetConfCtrlInfo* controlInfo =
                dynamic_cast<NetConfCtrlInfo*> (unlock->getControlInfo())){

            if (!configStoreToUnlock->isLocked()) {
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "lock is not active", //error because lock is currently not active
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
            else if(configStoreToUnlock->isLockedBy(controlInfo->getSession_id())){
                configStoreToUnlock->unlock(); //success can be unlocked
                reply = createRPCReplyElement_Ok();
            }else{
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "Cannot unlock config because session Id differs from lock owner", // locked but the current session is not the lock owner
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
        }
    }
    return reply;
}

NetConf_RPCReplyElement* NetConfDataStoreManagerBase::handleCommit(
        NetConfOperation* operation){
    NetConf_RPCReplyElement* reply = nullptr;

    // check if it is of type commit operation
    if(NetConfOperation_Commit* commit =
            dynamic_cast<NetConfOperation_Commit*>(operation)){
        if(_runningStore != nullptr){
            if (verifyLock(_runningStore, operation)) {
                //valid commit
                if(hasCommitTimestamp()){
                    scheduleTimedCommit(commit);
                } else {
                    bool result = executeCommit();
                    if(result){
                        reply = createRPCReplyElement_Ok();
                    }
                    else{
                        reply = createRPCReplyElement_Error(
                                NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                                "Commit Execution finished with errors",
                                NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
                    }
                }
            }
            else{
                reply = createRPCReplyElement_Error(
                        NETCONF_REPLY_ERROR_TYPE_APPLICATION,
                        "Cannot commit because session Id differs from lock owner",
                        NETCONF_REPLY_ERROR_SEVIRITY_ERROR);
            }
        }
    }
    return reply;
}

bool NetConfDataStoreManagerBase::hasCommitTimestamp(){
    bool isCommitTimestamp = true;
    if((_commitTimestamp.cycle == 0 && _commitTimestamp.executeAtStartOfPeriod)
            || (_commitTimestamp.time == 0 && !_commitTimestamp.executeAtStartOfPeriod)){
        isCommitTimestamp = false;
    }
    return isCommitTimestamp;
}

void NetConfDataStoreManagerBase::scheduleTimedCommit(NetConfOperation_Commit* commit){
    setCommitOperation(commit);
    if(_commitTimestamp.executeAtStartOfPeriod){
        //subscribe period cycles signal and wait for correct cycle to execute
        _periods[_commitTimestamp.period]->subscribe(_newCycleSignal, this);
    }else{
        //
        CoRE4INET::Timer* timer = dynamic_cast<CoRE4INET::Timer*>(this->getParentModule()->getParentModule()->getSubmodule("scheduler")->getSubmodule("timer"));
        CoRE4INET::SchedulerTimerEvent* event = new CoRE4INET::SchedulerTimerEvent("EXECUTE_TIMED_COMMIT", CoRE4INET::TIMER_EVENT);
        uint64_t ticksToCommitExecution = static_cast<uint64_t>(ceil((_commitTimestamp.time - timer->getTotalSimTime().dbl() ) / timer->getOscillator()->getPreciseTick()));
        event->setTimer(ticksToCommitExecution);
        event->setDestinationGate(gate("requestIn"));
        timer->registerEvent(event);
    }
}

bool NetConfDataStoreManagerBase::executeCommit(){
    //apply config from candidate to running
    emit(commitExecutionSignal,0L);
    return _candidateStore->applyTo(_runningStore);
}

void NetConfDataStoreManagerBase::setCommitOperation(NetConfOperation_Commit* commitOperation){
    if(_commitOperation != nullptr){
        delete _commitOperation;
    }
    _commitOperation = commitOperation;
}

void NetConfDataStoreManagerBase::receiveSignal(cComponent *source, simsignal_t signalID, long l, cObject *details){
    Enter_Method_Silent();
    // check if signalID is equal to signal event
    if(signalID == _newCycleSignal){
        // check if source is the period on which is planned
        if(dynamic_cast<CoRE4INET::Period*>(source) == _periods[_commitTimestamp.period]){
            // check if the desired cycle has been reached
            if(_periods[_commitTimestamp.period]->getCycles() == _commitTimestamp.cycle){
                scheduleAt(simTime(), new cMessage("EXECUTE_TIMED_COMMIT"));
            }
            else if(_periods[_commitTimestamp.period]->getCycles() > _commitTimestamp.cycle){
                throw cRuntimeError("The commit cycle timestamp was missed!");
            }
            //else wait until desired cycle is reached
        }
    }
}

void NetConfDataStoreManagerBase::resetCommitTimestamp(){
    setCommitOperation(nullptr);
    _commitTimestamp.cycle = 0;
    _commitTimestamp.period = 0;
    _commitTimestamp.time = 0;
    _commitTimestamp.executeAtStartOfPeriod = false;
}

}  // namespace SDN4CoRE
