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

namespace SDN4CoRE;

//
// Enum for all NetConf message types
//
// @author Timo Haeckel, for HAW Hamburg
//
enum NetConfMessageType {
 	NETCONFMESSAGETYPE_RPC = 0;
 	NETCONFMESSAGETYPE_RPCREPLY = 1;
}

//
// Base class for all NetConf messages.
// The Messages layer provides a simple, transport-independent
// framing mechanism for encoding RPCs and notifications.
//
// RPC Model
//
// The NETCONF protocol uses an RPC-based communication model.  NETCONF
// peers use <rpc> and <rpc-reply> elements to provide transport-
// protocol-independent framing of NETCONF requests and responses.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfMessage {
    int messageType @enum(NetConfMessageType);
}

//
// The <rpc> element is used to enclose a NETCONF request sent from the
// client to the server.
// The <rpc> element has a mandatory attribute "message-id", which is a
// string chosen by the sender of the RPC that will commonly encode a
// monotonically increasing integer. The receiver of the RPC does not
// decode or interpret this string but simply saves it to be used as a
// "message-id" attribute in any resulting <rpc-reply> message.
//
// RPC's usually encapsulate an operation @see ~NetConfOperation.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfMessage_RPC extends NetConfMessage {
    messageType = NetConfMessageType::NETCONFMESSAGETYPE_RPC;
    string message_id;//dont forget to add string size to byteLength
    byteLength = 25;//<rpc message-id=""></rpc>
}

//
// Base class for all RPC-reply elements, such as data, error or ok
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConf_RPCReplyElement {
    
}

//
// The <rpc-reply> message is sent in response to an <rpc> (@see ~NetConfMessage_RPC) message.
//
// The <rpc-reply> element has a mandatory attribute "message-id", which
// is equal to the "message-id" attribute of the <rpc> for which this is
// a response.
//
// The response data is encoded as one or more child elements to the
// <rpc-reply> element.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConfMessage_RPCReply extends NetConfMessage {
    messageType = NetConfMessageType::NETCONFMESSAGETYPE_RPCREPLY;
    string message_id;//dont forget to add filter size to length
    byteLength = 37;//<rpc-reply> message-id=""></rpc-reply>
}

//
// Baseclass for any userdata to be incapsulated in a NetConfMessage_RPCReply.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConf_RPCReplyElement_Data extends NetConf_RPCReplyElement {
}

//
// error-type:  Defines the conceptual layer that the error occurred.
//    Enumeration.  One of:
//    *  transport (layer: Secure Transport)
//    *  rpc (layer: Messages)
//    *  protocol (layer: Operations)
//    *  application (layer: Content)
//
// @author Timo Haeckel, for HAW Hamburg
//
enum NetConf_RPCReplyElement_Error_Type {
 	NETCONF_REPLY_ERROR_TYPE_TRANSPORT = 0;
 	NETCONF_REPLY_ERROR_TYPE_RPC = 1;
 	NETCONF_REPLY_ERROR_TYPE_PROTOCOL = 2;
 	NETCONF_REPLY_ERROR_TYPE_APPLICATION = 3;
}

//
// error-severity:  Contains an enum identifying the error severity, as
//    determined by the device.  One of:
//    *  error
//    *  warning
//
// @author Timo Haeckel, for HAW Hamburg
//
enum NetConf_RPCReplyElement_Error_Severity {
 	NETCONF_REPLY_ERROR_SEVIRITY_ERROR = 0;
 	NETCONF_REPLY_ERROR_SEVIRITY_WARNING = 1;
}

//
// The <rpc-error> element is sent in <rpc-reply> messages if an error
// occurs during the processing of an <rpc> request.
//
// The <rpc-error> element includes the following information:
//
// error-type (@see ~NetConf_RPCReplyElement_Error_Type):  
// 	  Defines the conceptual layer that the error occurred. 
//
// error-tag:  Contains a string identifying the error condition.
//
// error-severity (@see ~NetConf_RPCReplyElement_Error_Severity):  
// 	  Contains an enum identifying the error severity, as
//    determined by the device.
//
// error-app-tag:  Contains a string identifying the data-model-specific
//    or implementation-specific error condition, if one exists.  This
//    element will not be present if no appropriate application error-
//    tag can be associated with a particular error condition.  If a
//	  data-model-specific and an implementation-specific error-app-tag
//    both exist, then the data-model-specific value MUST be used by the
//    server.
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConf_RPCReplyElement_Error extends NetConf_RPCReplyElement {
    int error_type @enum(NetConf_RPCReplyElement_Error_Type);
    string error_tag;//dont forget to add filter size to length
    int error_severity @enum(NetConf_RPCReplyElement_Error_Severity);
    string error_app_tag;//dont forget to add filter size to length
    byteLength = 131;//<rpc-error><error-type>1</error-type><error-tag></error-tag><error-severity>1</error-severity><error-info></error-info></rpc-error>
}

//
// The <ok> element is sent in <rpc-reply> messages if no errors or
// warnings occurred during the processing of an <rpc> request, and no
// data was returned from the operation. 
//
// @author Timo Haeckel, for HAW Hamburg
//
packet NetConf_RPCReplyElement_Ok extends NetConf_RPCReplyElement {
    byteLength = 5;//<ok/>
}











