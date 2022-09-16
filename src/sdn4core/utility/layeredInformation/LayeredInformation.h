/*
 * LayeredInformation.h
 *
 *  Created on: 13.09.2022
 *      Author: jsolb
 */

#ifndef SDN4CORE_UTILITY_LAYEREDINFORMATION_LAYEREDINFORMATION_H_
#define SDN4CORE_UTILITY_LAYEREDINFORMATION_LAYEREDINFORMATION_H_

#include <omnetpp/cobject.h>
#include "inet/linklayer/common/MACAddress.h"
#include "inet/networklayer/common/L3Address.h"
#include "openflow/openflow/controller/Switch_Info.h"

namespace SDN4CoRE {

class LayeredInformation: public omnetpp::cObject {
public:
    inet::MACAddress eth_src;
    inet::L3Address ip_src;
    int transport_src;
    int inPort;
    openflow::Switch_Info* swInfo;
    LayeredInformation();
    virtual ~LayeredInformation();
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_UTILITY_LAYEREDINFORMATION_LAYEREDINFORMATION_H_ */
