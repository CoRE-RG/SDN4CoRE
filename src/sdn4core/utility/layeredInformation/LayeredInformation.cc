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
    this->ip_src = other.ip_src;
    this->transport_src = other.transport_src;
    this->inPort = other.inPort;
    this->swInfo = other.swInfo;
}

LayeredInformation::~LayeredInformation() {
    // TODO Auto-generated destructor stub
}

} /* namespace SDN4CoRE */
