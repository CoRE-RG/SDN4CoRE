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

#include <sdn4core/netconf/datastructures/transactionModel/NetConfConfigCommitTimestamp.h>

namespace SDN4CoRE {

NetConfConfigCommitTimestamp::NetConfConfigCommitTimestamp(){

}

NetConfConfigCommitTimestamp::~NetConfConfigCommitTimestamp(){

}

unsigned int  NetConfConfigCommitTimestamp::getByteSize() {
    return 108;//<config><top xmlns="http://example.com/schema/1.2/config"><cycle>32</cycle><period>0</period></top></config>
}

NetConfConfigCommitTimestamp::CommitTimestamp_t& NetConfConfigCommitTimestamp::getCommitTimestamp(){
    return _timestamp;
}

void NetConfConfigCommitTimestamp::setCommitTimestamp(CommitTimestamp_t& commitTimestamp){
    _timestamp = commitTimestamp;
}

} /* namespace SDN4CoRE */
