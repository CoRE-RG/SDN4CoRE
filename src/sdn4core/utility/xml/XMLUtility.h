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

#ifndef SDN4CORE_UTILITY_XML_XMLUTILITY_H_
#define SDN4CORE_UTILITY_XML_XMLUTILITY_H_

#include <string>
#include <omnetpp.h>
using namespace omnetpp;

namespace SDN4CoRE {

    /**
     * Helper method to get a string attribute from an XML config.
     * @return the value from xml if present, the alternative value if the parameter is not required.
     * @throw a runtime error if required is true and attribute cannot be found.
     */
    std::string getStringAttributeFromXML(cXMLElement* configureXML,
            const char* attribute, bool required = true, std::string alternativeValue = "");

    /**
     * Helper method to get a string attribute from an XML config.
     * @return the value from xml if present, the alternative value if the parameter is not required.
     * @throw a runtime error if required is true and attribute cannot be found.
     */
    int getIntAttributeFromXML(cXMLElement* configureXML,
            const char* attribute, bool required = true, int alternativeValue = 0);

    /**
     * Helper method to get a string attribute from an XML config.
     * @return the value from xml if present, the alternative value if the parameter is not required.
     * @throw a runtime error if required is true and attribute cannot be found.
     */
    double getDoubleAttributeFromXML(cXMLElement* configureXML,
            const char* attribute, bool required = true, double alternativeValue = 0);

};  // namespace SDN4CoRE

#endif /* SDN4CORE_UTILITY_XML_XMLUTILITY_H_ */
