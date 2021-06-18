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

#include "XMLUtility.h"
using namespace std;

namespace SDN4CoRE {

/**
 * Helper method to get a string attribute from an XML config.
 * @return the value from xml if present, the alternative value if the parameter is not required.
 * @throw a runtime error if required is true and attribute cannot be found.
 */
std::string getStringAttributeFromXML(cXMLElement* configureXML,
        const char* attribute, bool required, std::string alternativeValue) {
    const char* parameter = configureXML->getAttribute(attribute);
    if (required && parameter == nullptr) {
        throw cRuntimeError("Could not parse XML input for controller application because required attribute %s does not exist", attribute);
    }

    return ((parameter != nullptr) ? parameter : alternativeValue);
}

/**
 * Helper method to get a string attribute from an XML config.
 * @return the value from xml if present, the alternative value if the parameter is not required.
 * @throw a runtime error if required is true and attribute cannot be found.
 */
int getIntAttributeFromXML(cXMLElement* configureXML,
        const char* attribute, bool required, int alternativeValue) {
    const char* parameter = configureXML->getAttribute(attribute);
    if (required && parameter == nullptr) {
        throw cRuntimeError("Could not parse XML input for controller application because required attribute %s does not exist", attribute);
    }

    return ((parameter != nullptr) ? atoi(parameter) : alternativeValue);
}

/**
 * Helper method to get a string attribute from an XML config.
 * @return the value from xml if present, the alternative value if the parameter is not required.
 * @throw a runtime error if required is true and attribute cannot be found.
 */
double getDoubleAttributeFromXML(cXMLElement* configureXML,
        const char* attribute, bool required, double alternativeValue) {
    const char* parameter = configureXML->getAttribute(attribute);
    if (required && parameter == nullptr) {
        throw cRuntimeError("Could not parse XML input for controller application because required attribute %s does not exist", attribute);
    }

    return ((parameter != nullptr) ? stod(parameter) : alternativeValue);
}

};  // namespace SDN4CoRE


