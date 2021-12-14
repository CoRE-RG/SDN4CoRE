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

#ifndef __SDN4CORE_NETCONFDATASTOREMANAGERBASE_H_
#define __SDN4CORE_NETCONFDATASTOREMANAGERBASE_H_

//STD
#include <omnetpp.h>
#include <string>
#include <unordered_map>
//CoRE4INET
#include "core4inet/scheduler/period/Period.h"
//SDN4CoRE
#include <sdn4core/netconf/datastores/store/running/NetConfRunningDataStore.h>
#include <sdn4core/netconf/datastores/store/candidate/NetConfCandidateDataStore.h>
#include <sdn4core/netconf/datastructures/transactionModel/NetConfConfigCommitTimestamp.h>
//AUTO-GENERATED MESSAGES
#include <sdn4core/netconf/messages/NetConfMessage_m.h>
#include <sdn4core/netconf/messages/NetConfOperation_m.h>


using namespace omnetpp;

namespace SDN4CoRE {
/**
 * forward declaration of NetConfDataStoreManagerBase
 */
class NetConfServerBase;

/**
 * Base implementation of a netconf config store manager.
 * NetConfDataStoreManger implementations handle NetConf configuration and
 * state operations for a specific device.
 *
 * It uses a @see ~NetConfStateDataStore to handle state operations and a map
 * @see~ NetConfConfigDataStore to handle config operations.
 * Device specific implementations should also use device specific types for
 * there data stores.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class NetConfDataStoreManagerBase : public cSimpleModule , public cListener
{
  protected:
    virtual void initialize() override;
    virtual void handleParameterChange(const char* parname) override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void receiveSignal(cComponent *source, simsignal_t signalID, long l, cObject *details) override;

    /**
     * Creates an rpc reply element containing the data.
     * @param config    the config data to encapsulate
     * @return  the NetConf_RPCReplyElement_Data
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Data(
            NetConfConfig* config);

    /**
     * Creates an rpc reply element containing the error message.
     * @param error_type        Defines the conceptual layer that the error occurred.
     *                          One of @see ~NetConf_RPCReplyElement_Error_Type
     * @param error_tag         Contains a string identifying the error condition.
     * @param error_severity    Contains an enum identifying the error severity, as
     *                          determined by the device. One of @see ~NetConf_RPCReplyElement_Error_Severity
     * @param error_app_tag     Contains a string identifying the data-model-specific
     *                          or implementation-specific error condition, if one exists.
     * @return                  the NetConf_RPCReplyElement_Error
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Error(
            int error_type, const char * error_tag, int error_severity,
            const char * error_app_tag);

    /**
     * Creates an rpc reply element containing OK.
     * @return the NetConf_RPCReplyElement_Ok
     */
    virtual NetConf_RPCReplyElement* createRPCReplyElement_Ok();

    /**
     * Handles a NetConfOperation_GetConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_GetConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleGetConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_EditConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_EditConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleEditConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_CopyConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_CopyConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleCopyConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_DeleteConfig message, forwards it to the correct
     * config store and creates a reply.
     * @param operation     the NetConfOperation_DeleteConfig message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleDeleteConfig(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_Get message, forwards it to the data
     * store and creates a reply.
     * @param operation     the NetConfOperation_Get message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleGet(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_Lock message, forwards it to the data
     * store and creates a reply.
     * @param operation     the NetConfOperation_Lock message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleLock(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_Unlock message, forwards it to the data
     * store and creates a reply.
     * @param operation     the NetConfOperation_Unlock message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleUnlock(NetConfOperation* operation);

    /**
     * Handles a NetConfOperation_Commit message, forwards it to the data
     * store and creates a reply.
     * @param operation     the NetConfOperation_Commit message
     * @return              a NetConf_RPCReplyElement
     */
    virtual NetConf_RPCReplyElement* handleCommit(NetConfOperation* operation);

    /**
     * verifies the lock by the given sessionId
     * @param datastore the given config data store
     * @param operation the NetConf operation which has the sessionId
     * @return true if the data store is locked by the given sessionId or unlocked, else false
     */
    bool verifyLock(NetConfDataStoreBase* datastore, NetConfOperation* operation);

    /**
     * Schedules the timed commit
     * @param commit the commit operation
     */
    virtual void scheduleTimedCommit(NetConfOperation_Commit* commit);

    /**
     * Executes the commit
     * @return the result of commit execution
     */
    virtual bool executeCommit();

    /**
     * checks if it is a valid commit timestamp
     * @return true, if it is valid, else false
     */
    bool hasCommitTimestamp();

    /**
     * sets the commitOperation and deletes the old commitOperation
     * @param commitOperation   the NetConf operation
     */
    void setCommitOperation(NetConfOperation_Commit* commitOperation);

    /**
     * resets the commit operation and timestamp
     */
    void resetCommitTimestamp();

    /**
     * the commit operation
     */
    NetConfOperation_Commit* _commitOperation = nullptr;
    /**
     * the commit timestamp
     */
    NetConfConfigCommitTimestamp::CommitTimestamp_t _commitTimestamp;

    /**
     * the period of the scheduler
     */
    std::vector<CoRE4INET::Period*> _periods;

    /**
     * the new cycle signal which is to subscribe
     */
    simsignal_t _newCycleSignal;

    /**
     * Cached reference to the NetConf server.
     */
    NetConfServerBase* _netConfServer;

    /**
     * Cached parameter if the status should be displayed
     */
    bool _displayStatus;

    /**
     * Running configuration data store
     */
    NetConfRunningDataStore* _runningStore;

    /**
     * Candidate configuration data store
     */
    NetConfCandidateDataStore* _candidateStore;
    /**
     * Gate name (@directIn) for request inputs in data stores
     */
    static const char REQUEST_IN_GATE_NAME []; // = "requestIn";
    /**
     * Gate name (@directIn) for response inputs to NetConf server
     */
    static const char RESPONSE_OUT_GATE_NAME []; // = "responseIn";

    static simsignal_t commitExecutionSignal;

    static simsignal_t editConfigSignal;
};

}  // namespace SDN4CoRE

#endif
