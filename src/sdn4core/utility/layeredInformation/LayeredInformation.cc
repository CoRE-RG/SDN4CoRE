/*
 * LayeredInformation.cc
 *
 *  Created on: 13.09.2022
 *      Author: jsolb
 */

#include <sdn4core/utility/layeredInformation/LayeredInformation.h>

namespace SDN4CoRE {

LayeredInformation::LayeredInformation() {
    // TODO Auto-generated constructor stub

}

void LayeredInformation::copy(const LayeredInformation& other) {
    this->eth_src = other.eth_src;
    this->eth_dst = other.eth_dst;
    this->ip_src = other.ip_src;
    this->ip_dst = other.ip_dst;
    this->transport_src = other.transport_src;
    this->transport_dst = other.transport_dst;
    this->in_port = other.in_port;
    this->sw_info = other.sw_info;
}

LayeredInformation::~LayeredInformation() {

}

} /* namespace SDN4CoRE */
