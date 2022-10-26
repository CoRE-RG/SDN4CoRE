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
    inet::MACAddress eth_dst;
    inet::L3Address ip_src;
    inet::L3Address ip_dst;
    int transport_src;
    int transport_dst;
    int in_port;
    openflow::Switch_Info* sw_info;

    LayeredInformation();
    virtual ~LayeredInformation();

    LayeredInformation(const LayeredInformation& other) : omnetpp::cObject(other) {
        copy(other);
    }

    /**
     * @brief Assignment operator
     */
    LayeredInformation& operator=(const LayeredInformation& other)
    {
        if (this==&other) return *this;
        cObject::operator=(other);
        copy(other);
        return *this;
    }

    virtual LayeredInformation *dup() const {return new LayeredInformation(*this);}

private:
    void copy(const LayeredInformation& other);
};



} /* namespace SDN4CoRE */

#endif /* SDN4CORE_UTILITY_LAYEREDINFORMATION_LAYEREDINFORMATION_H_ */
