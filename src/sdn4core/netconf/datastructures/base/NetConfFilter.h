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

#ifndef SDN4CORE_NETCONF_MESSAGES_NETCONFFILTER_H_
#define SDN4CORE_NETCONF_MESSAGES_NETCONFFILTER_H_

namespace SDN4CoRE {

class NetConfFilter {
public:
    NetConfFilter();

    NetConfFilter(const NetConfFilter& old){}
    virtual ~NetConfFilter();

    /**
     * Calculates the byte size of this config.
     * @return  the calculated byte size.
     */
    virtual unsigned int getByteSize();
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_NETCONF_MESSAGES_NETCONFFILTER_H_ */
