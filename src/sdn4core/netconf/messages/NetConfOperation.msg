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

//
// TODO implement other operations: kill-session 
//


cplusplus {{
#include "sdn4core/netconf/datastructures/base/NetConfFilter.h"
}}

namespace SDN4CoRE;

struct NetConfFilter;

//
// Base class for all NetConf operations.
//
// Protocol Operations
//   The NETCONF protocol provides a small set of low-level operations to
//   manage device configurations and retrieve device state information.
//   The base protocol provides operations to retrieve, configure, copy,
//   and delete configuration datastores.  Additional operations are
//   provided, based on the capabilities advertised by the device.
//
//   The base protocol includes the following protocol operations:
//   o  get
//   o  get-config
//   o  edit-config
//   o  copy-config
//   o  delete-config
//   o  lock
//   o  unlock
//   o  close-session
//   o  kill-session
//
//   A protocol operation can fail for various reasons, including
//   "operation not supported".  An initiator SHOULD NOT assume that any
//   operation will always succeed.  The return values in any RPC reply
//   SHOULD be checked for error responses.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation {
    
}

// <get-config>
//
// Retrieve all or part of a specified configuration datastore.
//   Parameters:
//      source:  Name of the configuration datastore being queried, such
//         as <running/>.
//      filter:  This parameter identifies the portions of the device
//         configuration datastore to retrieve.  If this parameter is not
//         present, the entire configuration is returned.
//   Positive Response:  If the device can satisfy the request, the server
//      sends an <rpc-reply> element containing a <data> element with the
//      results of the query.
//   Negative Response:  An <rpc-error> element is included in the
//      <rpc-reply> if the request cannot be completed for any reason.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation_GetConfig extends NetConfOperation{
    string source;//dont forget to add string size to length
    NetConfFilter filter;//dont forget to add filter size to length
    byteLength = 133;//<get-config><source></></source><filter type="subtree"><top xmlns="http://example.com/schema/1.2/config"></top></filter></get-config>  
}

//
// Attributes:
//    
//     operation:  Elements in the <config> subtree MAY contain an
//       "operation" attribute.  The attribute identifies the point in
//       the configuration to perform the operation and MAY appear on
//       multiple elements throughout the <config> subtree.
//
//       If the "operation" attribute is not specified, the
//       configuration is merged into the configuration datastore.
//       The "operation" attribute has one of the following values:
//
//       merge:  The configuration data identified by the element
//          containing this attribute is merged with the configuration
//          at the corresponding level in the configuration datastore
//          identified by the <target> parameter.  This is the default
//          behavior.
//
//       replace:  The configuration data identified by the element
//          containing this attribute replaces any related configuration
//          in the configuration datastore identified by the <target>
//          parameter.  If no such configuration data exists in the
//          configuration datastore, it is created.  Unlike a
//          <copy-config> operation, which replaces the entire target
//          configuration, only the configuration actually present in
//          the <config> parameter is affected.
//
//       create:  The configuration data identified by the element
//          containing this attribute is added to the configuration if
//          and only if the configuration data does not already exist in
//          the configuration datastore.  If the configuration data
//          exists, an <rpc-error> element is returned with an
//          <error-tag> value of "data-exists".
//
//       delete:  The configuration data identified by the element
//          containing this attribute is deleted from the configuration
//          if and only if the configuration data currently exists in
//          the configuration datastore.  If the configuration data does
//          not exist, an <rpc-error> element is returned with an
//          <error-tag> value of "data-missing".
//
//       remove:  The configuration data identified by the element
//          containing this attribute is deleted from the configuration
//          if the configuration data currently exists in the
//          configuration datastore.  If the configuration data does not
//          exist, the "remove" operation is silently ignored by the
//          server.
//
//       none:  The target datastore is unaffected by the configuration
//          in the <config> parameter, unless and until the incoming
//          configuration data uses the "operation" attribute to request
//          a different operation.  If the configuration in the <config>
//          parameter contains data for which there is not a
//          corresponding level in the target datastore, an <rpc-error>
//          is returned with an <error-tag> value of data-missing.
//          Using "none" allows operations like "delete" to avoid
//          unintentionally creating the parent hierarchy of the element
//          to be deleted.
//
// @author Timo Haeckel, for HAW Hamburg
//
enum NetConfOperation_Operation {
	NETCONFOPERATION_OPERATION_NONE = 0;
    NETCONFOPERATION_OPERATION_MERGE = 1;
    NETCONFOPERATION_OPERATION_REPLACE = 2;
    NETCONFOPERATION_OPERATION_CREATE = 3;
    NETCONFOPERATION_OPERATION_DELETE = 4;
    NETCONFOPERATION_OPERATION_REMOVE = 5;
}

//
//  error-option:  The <error-option> element has one of the following
//         values:
//
//         stop-on-error:  Abort the <edit-config> operation on first
//            error.  This is the default error-option.
//
//         continue-on-error:  Continue to process configuration data on
//            error; error is recorded, and negative response is generated
//            if any errors occur.
//
//         rollback-on-error:  If an error condition occurs such that an
//            error severity <rpc-error> element is generated, the server
//            will stop processing the <edit-config> operation and restore
//            the specified configuration to its complete state at the
//            start of this <edit-config> operation.  This option requires
//            the server to support the :rollback-on-error capability.
//
// @author Timo Haeckel, for HAW Hamburg
//
enum NetConfOperation_ErrorOption {
	NETCONFOPERATION_ERROROPTION_STOPONERROR = 0;
	NETCONFOPERATION_ERROROPTION_CONTINUEONERROR = 1;
	NETCONFOPERATION_ERROROPTION_ROLLBACKONERROR = 2;
}

//
// <edit-config>
//
// The <edit-config> operation loads all or part of a specified
// configuration to the specified target configuration datastore.
// This operation allows the new configuration to be expressed in
// several ways, such as using a local file, a remote file, or
// inline.  If the target configuration datastore does not exist, it
// will be created.
//
// The device analyzes the source and target configurations and
// performs the requested changes.  The target configuration is not
// necessarily replaced, as with the <copy-config> message.  Instead,
// the target configuration is changed in accordance with the
// source's data and requested operations.
//
// If the <edit-config> operation contains multiple sub-operations
// that apply to the same conceptual node in the underlying data
// model, then the result of the operation is undefined (i.e.,
// outside the scope of the NETCONF protocol).
//
// Attributes:
//    
//     operation (@see ~NetConfOperation_Operation):  Elements in the <config> 
//       subtree MAY contain an "operation" attribute.  The attribute identifies
//       the point in the configuration to perform the operation and MAY 
//       appear on multiple elements throughout the <config> subtree.
//
//       If the "operation" attribute is not specified, the
//       configuration is merged into the configuration datastore.
//
// Parameters:
//    target:  Name of the configuration datastore being edited, such as
//       <running/> or <candidate/>.
//
//    default-operation:  Selects the default operation (@see ~NetConfOperation_Operation)
//       for this <edit-config> request.  The
//       default value for the <default-operation> parameter is "merge".
//       The <default-operation> parameter is optional, but if provided,
//       it has one of the following values: merge, replace, none
//
//    error-option:  The <error-option> element has one of the following
//       values (@see~NetConfOperation_ErrorOption).
//
//    config:  encapsulated packet @see ~NetConfConfig 
//		 A hierarchy of configuration data as defined by one of
//       the device's data models.  The contents MUST be placed in an
//       appropriate namespace, to allow the device to detect the
//       appropriate data model, and the contents MUST follow the
//       constraints of that data model, as defined by its capability
//       definition.  Capabilities are discussed in Section 8.
//
//   Positive Response:  If the device was able to satisfy the request, an
//      <rpc-reply> is sent containing an <ok> element.
//
//   Negative Response:  An <rpc-error> response is sent if the request
//      cannot be completed for any reason.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation_EditConfig extends NetConfOperation{
    string target;//dont forget to add string size to length
    int defaultOperation @enum(NetConfOperation_Operation);
    int errorOption @enum(NetConfOperation_ErrorOption);
    byteLength = 119;//<edit-config><target></></target><defaultOperation>1</defaultOperation><errorOperation>1</errorOperation></edit-config>
}

//
// Configuration element used in both edit_config and get_config 
// has to be extended by specific configurators.
//
//    operation:  Selects the operation (@see ~NetConfOperation_Operation)
//       for this configuration in an edit_config request.  
//	     If this is not set the default value from the <default-operation> 
//		 parameter in @see ~NetConfOperation_EditConfig.
//       The <operation> parameter is optional, but if provided,
//       it has one of the values in @see ~NetConfOperation_Operation.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfConfig {
    @customize(true);
    int operation @enum(NetConfOperation_Operation);
}

//
// <copy-config>
//
// Create or replace an entire configuration datastore
// with the contents of another complete configuration datastore.  If
// the target datastore exists, it is overwritten.  Otherwise, a new
// one is created, if allowed.
//
// Parameters:
//
//    target:  Name of the configuration datastore to use as the
//       destination of the <copy-config> operation.
//
//    source:  Name of the configuration datastore to use as the source
//         of the <copy-config> operation, or the <config> element
//         containing the complete configuration to copy.
//
// Positive Response:  If the device was able to satisfy the request, an
//    <rpc-reply> is sent that includes an <ok> element.
//
// Negative Response:  An <rpc-error> element is included within the
//    <rpc-reply> if the request cannot be completed for any reason.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation_CopyConfig extends NetConfOperation{
    string source;//dont forget to add string size to length
    string target;//dont forget to add string size to length
    byteLength = 67;//<copy-config><target></></target><source></></source></copy-config>
}

//
// <delete-config>
//
// Delete a configuration datastore.  The <running>
// configuration datastore cannot be deleted.
//
//   Parameters:
//
//      target:  Name of the configuration datastore to delete.
//
//   Positive Response:  If the device was able to satisfy the request, an
//      <rpc-reply> is sent that includes an <ok> element.
//
//   Negative Response:  An <rpc-error> element is included within the
//      <rpc-reply> if the request cannot be completed for any reason.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation_DeleteConfig extends NetConfOperation{
    string target;//dont forget to add string size to length
    byteLength = 51;//<delete-config><target></></target></delete-config>
}

//
// <get>
//
// Retrieve running configuration and device state information.
//
//   Parameters:
//
//      filter:  This parameter specifies the portion of the system
//         configuration and state data to retrieve.  If this parameter is
//         not present, all the device configuration and state information
//         is returned.
//
//   Positive Response:  If the device was able to satisfy the request, an
//      <rpc-reply> is sent.  The <data> section contains the appropriate
//      subset.
//
//   Negative Response:  An <rpc-error> element is included in the
//      <rpc-reply> if the request cannot be completed for any reason.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation_Get extends NetConfOperation{
    NetConfFilter filter;//dont forget to add filter size to length
    byteLength = 99;//<get><filter type="subtree"><top xmlns="http://example.com/schema/1.2/config"></top></filter></get>    
}

//
// <close-session>
//
// Request graceful termination of a NETCONF session.
//
// When a NETCONF server receives a <close-session> request, it will
// gracefully close the session.  The server will release any locks
// and resources associated with the session and gracefully close any
// associated connections.  Any NETCONF requests received after a
// <close-session> request will be ignored.
//
//   Positive Response:  If the device was able to satisfy the request, an
//      <rpc-reply> is sent that includes an <ok> element.
//
//   Negative Response:  An <rpc-error> element is included in the
//      <rpc-reply> if the request cannot be completed for any reason.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfOperation_CloseSession extends NetConfOperation{
    byteLength = 16;//<close-session/>
}

//
// <lock>
//
//	The <lock> operation allows the client to lock the
//	entire configuration datastore system of a device.  Such locks are
//	intended to be short-lived and allow a client to make a change
//	without fear of interaction with other NETCONF clients, non-
//	NETCONF clients (e.g., SNMP and command line interface (CLI)
//	scripts), and human users.
//
//	An attempt to lock the configuration datastore MUST fail if an
//	existing session or other entity holds a lock on any portion of
//	the lock target.
//
//	When the lock is acquired, the server MUST prevent any changes to
//	the locked resource other than those requested by this session.
//	SNMP and CLI requests to modify the resource MUST fail with an
//	appropriate error.
//
//	The duration of the lock is defined as beginning when the lock is
//	acquired and lasting until either the lock is released or the
//	NETCONF session closes.  The session closure can be explicitly
//	performed by the client, or implicitly performed by the server
//	based on criteria such as failure of the underlying transport,
//	simple inactivity timeout, or detection of abusive behavior on the
//	part of the client.  These criteria are dependent on the
//	implementation and the underlying transport.
//
//	The <lock> operation takes a mandatory parameter, <target>.  The
//	<target> parameter names the configuration datastore that will be
//	locked.  When a lock is active, using the <edit-config> operation
//	on the locked configuration datastore and using the locked
//	configuration as a target of the <copy-config> operation will be
//	disallowed by any other NETCONF session.  Additionally, the system
//	will ensure that these locked configuration resources will not be
//	modified by other non-NETCONF management operations such as SNMP
//	and CLI.  The <kill-session> operation can be used to force the
//	release of a lock owned by another NETCONF session.  It is beyond
//	the scope of this document to define how to break locks held by
//	other entities.
//
//	A lock MUST NOT be granted if any of the following conditions is
//	true:
//
//	*	A lock is already held by any NETCONF session or another
//		entity.
//	*	The target configuration is <candidate>, it has already been
//		modified, and these changes have not been committed or rolled
//		back.
//	*	The target configuration is <running>, and another NETCONF
//		session has an ongoing confirmed commit (Section 8.4).
//	
//		The server MUST respond with either an <ok> element or an
//		<rpc-error>.
//
//		A lock will be released by the system if the session holding the
//		lock is terminated for any reason.
//
//	Parameters:
//	target:  Name of the configuration datastore to lock.
//
//	Positive Response:  If the device was able to satisfy the request, an
//	<rpc-reply> is sent that contains an <ok> element.
//
//	Negative Response:  An <rpc-error> element is included in the
//	<rpc-reply> if the request cannot be completed for any reason.
//
//	If the lock is already held, the <error-tag> element will be
//	"lock-denied" and the <error-info> element will include the
//	<session-id> of the lock owner.  If the lock is held by a non-
//	NETCONF entity, a <session-id> of 0 (zero) is included.  Note that
//	any other entity performing a lock on even a partial piece of a
//	target will prevent a NETCONF lock (which is global) from being
//	obtained on that target.
//
//
packet NetConfOperation_Lock extends NetConfOperation{
    string target;//dont forget to add string size to length
    byteLength = 33;//<lock><target></></target></lock>
}

//
// <unlock>
//
//	The <unlock> operation is used to release a
//	configuration lock, previously obtained with the <lock> operation.
//
//	An <unlock> operation will not succeed if either of the following
//	conditions is true:
//    
//    * The specified lock is not currently active.
//    * The session issuing the <unlock> operation is not the same
//    session that obtained the lock.
//    
//    The server MUST respond with either an <ok> element or an
//    <rpc-error>.
//    
//    Parameters:
//    
//    target:  Name of the configuration datastore to unlock.
//    
//    A NETCONF client is not permitted to unlock a configuration
//    datastore that it did not lock.
//    	
//    Positive Response:  If the device was able to satisfy the request, an
//    <rpc-reply> is sent that contains an <ok> element.
//    
//    Negative Response:  An <rpc-error> element is included in the
//    <rpc-reply> if the request cannot be completed for any reason.
//
//
packet NetConfOperation_Unlock extends NetConfOperation{
    string target;//dont forget to add string size to length
    byteLength = 37;//<unlock><target></></target></unlock>
}

//	<commit>
//    When the candidate configuration's content is complete, the
//    configuration data can be committed, publishing the data set to
//    the rest of the device and requesting the device to conform to
//    the behavior described in the new configuration.
//    
//    To commit the candidate configuration as the device's new
//    current configuration, use the <commit> operation.
//    
//    The <commit> operation instructs the device to implement the
//    configuration data contained in the candidate configuration.
//    If the device is unable to commit all of the changes in the
//    candidate configuration datastore, then the running
//    configuration MUST remain unchanged.  If the device does
//    succeed in committing, the running configuration MUST be
//    updated with the contents of the candidate configuration.
//    
//    If the running or candidate configuration is currently locked
//    by a different session, the <commit> operation MUST fail with
//    an <error-tag> value of "in-use".
//    
//    If the system does not have the :candidate capability, the
//    <commit> operation is not available.
//    
//    Positive Response:
//    If the device was able to satisfy the request, an <rpc-reply>
//    is sent that contains an <ok> element.
//    
//    Negative Response:
//    An <rpc-error> element is included in the <rpc-reply> if the
//    request cannot be completed for any reason.
//
//
packet NetConfOperation_Commit extends NetConfOperation{
    byteLength=9;//<commit/>
}

//
//	<discard-changes>
// If the client decides that the candidate configuration is not to be
// committed, the <discard-changes> operation can be used to revert the
// candidate configuration to the current running configuration.
//
// This operation discards any uncommitted changes by resetting the
// candidate configuration with the content of the running configuration.
//
//
packet NetConfOperation_Discard_Changes extends NetConfOperation{
    byteLength=18;//<discard-changes/>
}
