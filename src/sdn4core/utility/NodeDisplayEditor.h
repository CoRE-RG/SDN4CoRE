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

#ifndef OPENFLOW_UTILITY_NODEDISPLAYEDITOR_H_
#define OPENFLOW_UTILITY_NODEDISPLAYEDITOR_H_

#include <omnetpp.h>

namespace SDN4CoRE {
/**
 * The Node Display Editor can be used to manipulate the a modules display string
 * during runtime with abstracted methods.
 */
class NodeDisplayEditor {
public:
    /**
     * Constructor setting the Target Module.
     * @param targetModule the manipulated module.
     */
    NodeDisplayEditor(omnetpp::cModule* targetModule);
    /**
     * Default Constructor. Don't forget to set the target Module.
     */
    NodeDisplayEditor();
    virtual ~NodeDisplayEditor();

    omnetpp::cModule* getTarget() {
        return _target;
    }

    void setTarget(omnetpp::cModule* target) {
        _target = target;
    }
    /**
     * Set the color of the Node to the given String. The user has to ensure valid strings are used.
     * @param color     The color to set. Valid values are some common color names,
     *                  such as white, black, red, etc. or rgb values in format #rgb or #rrggbb.
     * @param opacity   The opacity of the color. Valid values are 0-100.
     *
     */
    void setNodeColor(const char* color, const char* opacity = "50");

    /**
     * Set the color of the given module to the provided string values. The user has to ensure valid strings are used.
     * @param target    The target module to manipulate.
     * @param color     The color to set. Valid values are some common color names,
     *                  such as white, black, red, etc. or rgb values in format #rgb or #rrggbb.
     * @param opacity   The opacity of the color. Valid values are 0-100.
     *
     */
    static void setNodeColor(omnetpp::cModule* target, const char* color, const char* opacity = "50");

private:
    /**
     * The targeted Module.
     */
    omnetpp::cModule* _target;
};

} /* namespace SDN4CoRE */

#endif /* OPENFLOW_UTILITY_NODEDISPLAYEDITOR_H_ */
