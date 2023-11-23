//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
// c Timo Haeckel, for HAW Hamburg
//

#include <sdn4core/controllerState/services/SomeipOptionsList.h>

using namespace std;
using namespace SOA4CoRE;

namespace SDN4CoRE {

SomeipOptionsList::SomeipOptionsList(SomeIpSDEntry* xEntry, SomeIpSDHeader* header) {
    int optionPosition = xEntry->getIndex1stOptions();
    int optionQuantity = xEntry->getNum1stOptions();
    list<SomeIpSDOption *> optList = header->getEncapOptions();
    std::_List_iterator<SomeIpSDOption*> optionListIterator = optList.begin();
    std::advance(optionListIterator, optionPosition);
    for (int firstOptionsIdx = 0; firstOptionsIdx < optionQuantity; firstOptionsIdx++) {
        SomeIpSDOption* option = *optionListIterator;
        this->push_back(option->dup());
        std::advance(optionListIterator, 1);
    }
}

} /* namespace SDN4CoRE */

