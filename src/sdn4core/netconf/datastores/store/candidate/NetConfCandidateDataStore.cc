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

#include <sdn4core/netconf/datastores/store/candidate/NetConfCandidateDataStore.h>

namespace SDN4CoRE {

Define_Module(NetConfCandidateDataStore);

void NetConfCandidateDataStore::initialize(){
    NetConfDataStoreBase::initialize();
    _runningStore = dynamic_cast<NetConfRunningDataStore*>(this->getParentModule()->getSubmodule("running"));
    if(!_runningStore) {
        throw cRuntimeError("Could not find running store.");
    }
}

NetConfConfig* NetConfCandidateDataStore::getConfig(NetConfFilter& filter){
    Enter_Method("getConfig()");
    throw cRuntimeError("Not yet implemented");
    return new NetConfConfig();
}

bool NetConfCandidateDataStore::editConfig(int defaultOperation, int errorOption, NetConfConfig* config){
    Enter_Method("editConfig()");
    bool newConfigs = false;
    if(config){
        if(validateConfig(config)){
            if(auto dup = dynamic_cast<NetConfConfig*>(config->dup())) {
                _configVector.push_back(dup);
               newConfigs = true;
            } else {
                throw cRuntimeError("Duplication of config failed");
            }
        }
    }
    if(newConfigs){
        emit(editConfigOkSignal, 1L);
    }else{
        emit(editConfigErrorSignal, 1L);
    }
    return newConfigs;
}

bool NetConfCandidateDataStore::validateConfig(NetConfConfig* config){
    return _runningStore->validateConfig(config);
}

bool NetConfCandidateDataStore::checkAndLock(int lockHolderSessionId){
    if(!_configVector.empty()){
        return false;
    }else{
        return NetConfDataStoreBase::checkAndLock(lockHolderSessionId);
    }
}

bool NetConfCandidateDataStore::applyTo(NetConfDataStoreBase* running){
    bool success = true;
    for(auto configChange: _configVector){
        success = success && running->editConfig(NetConfOperation_Operation::NETCONFOPERATION_OPERATION_MERGE,
                NetConfOperation_ErrorOption::NETCONFOPERATION_ERROROPTION_ROLLBACKONERROR,
                configChange);
    }
    this->clear();
    return success;
}

void NetConfCandidateDataStore::clear(){
    for(auto config: _configVector){
        delete config;
    }
    _configVector.clear();
}

} /* namespace SDN4CoRE */
