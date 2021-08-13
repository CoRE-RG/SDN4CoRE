//
// c Tobias Haugg, for HAW Hamburg
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
#include <sdn4core/netconf/datastores/config/srp/NetConfDataConfiguratorSRP.h>
#include <sdn4core/netconf/datastructures/srp/NetConfConfigSRP.h>
#include <sdn4core/netconf/messages/NetConfOperation_m.h>


using namespace std;

namespace SDN4CoRE {

Define_Module(NetConfDataConfiguratorSRP);

void SDN4CoRE::NetConfDataConfiguratorSRP::initialize() {
    //load srp table module
    _srpTable = dynamic_cast<CoRE4INET::SRPTable*> (getModuleByPath(par("ofSrpTableModule")));
    if(!_srpTable){
        throw cRuntimeError(("Could not init as no SRP Table could be found at " + par("srpTable").str()).c_str());
    }
}

NetConfConfig* SDN4CoRE::NetConfDataConfiguratorSRP::getConfig(NetConfFilter& filter) {
    NetConfConfigSRP* config = new NetConfConfigSRP();
    config->setTalkerEntries(_srpTable->getTalkerEntries());
    config->setListenerEntries(_srpTable->getListenerEntries());
    return config;
}

bool SDN4CoRE::NetConfDataConfiguratorSRP::editConfig(int defaultOperation, int errorOption, NetConfConfig* config) {
    //check if config is valide and conforms the given operation
    Enter_Method("editConfig()");
    bool noError = true;
    if(NetConfConfigSRP* configSRP = dynamic_cast<NetConfConfigSRP*>(config)){

        if( (errorOption == NETCONFOPERATION_ERROROPTION_ROLLBACKONERROR) && !validateConfig(config, defaultOperation)){
            return false;
        }

        for(auto talker : configSRP->getTalkerEntries()){

            if(!noError && errorOption == NETCONFOPERATION_ERROROPTION_STOPONERROR){
                return false;
            }

            switch(defaultOperation){
                case NETCONFOPERATION_OPERATION_CREATE:
                    if(_srpTable->getTalkerForStreamId(talker.streamId, talker.vlan_id)){
                        noError = false;
                    }else{
                        _srpTable->updateTalkerWithStreamId(talker.streamId, talker.module, talker.address, talker.srClass, talker.framesize, talker.intervalFrames, talker.vlan_id, talker.pcp,true);
                    }
                    break;
                case NETCONFOPERATION_OPERATION_MERGE:
                    _srpTable->updateTalkerWithStreamId(talker.streamId, talker.module, talker.address, talker.srClass, talker.framesize, talker.intervalFrames, talker.vlan_id, talker.pcp,true);
                    break;
                case NETCONFOPERATION_OPERATION_DELETE:
                    noError &= _srpTable->removeTalkerWithStreamId(talker.streamId, talker.module, talker.address, talker.vlan_id);
                    break;
                case NETCONFOPERATION_OPERATION_REMOVE:
                    _srpTable->removeTalkerWithStreamId(talker.streamId, talker.module, talker.address, talker.vlan_id);
                    break;
                default:
                    break;
            }
        }

        for(auto listener : configSRP->getListenerEntries()){

            if(!noError && errorOption == NETCONFOPERATION_ERROROPTION_STOPONERROR){
                return false;
            }

            switch(defaultOperation){
                case NETCONFOPERATION_OPERATION_CREATE:
                    if((_srpTable->getListenersForStreamId(listener.streamId, listener.vlan_id).size()) <= 0){
                        noError = false;
                    }else{
                        _srpTable->updateListenerWithStreamId(listener.streamId, listener.module, listener.vlan_id);
                    }
                    break;
                case NETCONFOPERATION_OPERATION_MERGE:
                    _srpTable->updateListenerWithStreamId(listener.streamId, listener.module, listener.vlan_id);
                    break;
                case NETCONFOPERATION_OPERATION_DELETE:
                    noError &= _srpTable->removeListenerWithStreamId(listener.streamId, listener.module, listener.vlan_id);
                    break;
                case NETCONFOPERATION_OPERATION_REMOVE:
                    _srpTable->removeListenerWithStreamId(listener.streamId, listener.module, listener.vlan_id);
                    break;
                default:
                    break;
            }
        }
    }else{
        return false;
    }
    return noError;
}

bool NetConfDataConfiguratorSRP::validateConfig( NetConfConfig* config, int defaultOperation) {
    if(NetConfConfigSRP* configSRP = dynamic_cast<NetConfConfigSRP*>(config)){
        if( (defaultOperation == NETCONFOPERATION_OPERATION_CREATE) && (defaultOperation == NETCONFOPERATION_OPERATION_DELETE)){

            for(auto listener : configSRP->getListenerEntries()){
                if(!_srpTable->getListenersForStreamId(listener.streamId, listener.vlan_id).size()){
                    return false;
                }
            }

            for(auto talker : configSRP->getTalkerEntries()){
                if(!_srpTable->getTalkerEntryForStreamId(talker.streamId, talker.vlan_id)){
                    return false;
                }
            }
        }
    }else{
        return false;
    }

    return true;
}

} /* namespace SDN4CoRE */
