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
#ifndef SDN4CORE_CONTROLLERSTATE_SERVICES_SOMEIPOPTIONLIST_H_
#define SDN4CORE_CONTROLLERSTATE_SERVICES_SOMEIPOPTIONLIST_H_

#include "soa4core/messages/someip/SomeIpSDHeader.h"
#include "soa4core/messages/someip/SomeIpSDEntry_m.h"
#include "soa4core/messages/someip/SomeIpSDOption_m.h"

namespace SDN4CoRE {

/**
 * Extended list for SomeIpSDOptions implementing comfort functions
 */
class SomeipOptionsList : public std::list<SOA4CoRE::SomeIpSDOption*>
{
public:
    /**
     * Default constructor.
     */
    SomeipOptionsList() {};

    /**
     * Constructor from the some ip sd entries and header options.
     * @param xEntry The sd entry.
     * @param header The corresponding header containing the options.
     */
    SomeipOptionsList(SOA4CoRE::SomeIpSDEntry* xEntry, SOA4CoRE::SomeIpSDHeader* header);

    /**
     * Check if the list containes an option element of a certain pointer type.
     * @return true if the type occurs in the list
     */
    template<typename T>
    bool hasConfigType () {
        for (auto config : *this) {
            if(dynamic_cast<T>(config)) {
                return true;
            }
        }
        return false;
    }

    /**
     * Get the first option in the list that matches the option pointer type.
     * @return The matching option, nullptr if none was found
     */
    template<typename T>
    T getFirstConfigOfType () const {
        for (auto config : *this) {
            if(T castConfig = dynamic_cast<T>(config)) {
                return castConfig;
            }
        }
        return nullptr;
    }

    /**
     * Get the all option in the list that matche the option pointer type.
     * @return The matching options as a list, nullptr if none was found
     */
    template<typename T>
    std::list<T> getAllConfigsOfType () {
        std::list<T> configs;
        for (auto config : *this) {
            if(T castConfig = dynamic_cast<T>(config)) {
                configs.push_back(castConfig);
            }
        }
        return configs;
    }

    /**
     * Deep copy duplicating all config options contained in the list.
     * @return a copy of this list with pointers to new duplicates of the configs.
     */
    SomeipOptionsList dup() {
        SomeipOptionsList duplicate;
        for (auto config : *this) {
            duplicate.push_back(config->dup());
        }
        return duplicate;
    }

    /**
     * Delete all elements stored behin pointers.
     */
    void cleanUp() {
        for (auto elem: *this) {
            if (elem) delete elem;
            elem = nullptr;
        }
        clear();
    }
};

} /* namespace SDN4CoRE */

#endif /* SDN4CORE_CONTROLLERSTATE_SERVICES_SOMEIPOPTIONLIST_H_ */
