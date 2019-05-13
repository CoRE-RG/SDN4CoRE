/*
 * NodeColorChanger.h
 *
 *  Created on: Nov 30, 2018
 *      Author: timo
 */

#ifndef OPENFLOW_UTILITY_NODEDISPLAYEDITOR_H_
#define OPENFLOW_UTILITY_NODEDISPLAYEDITOR_H_

namespace omnetpp {
class cModule;
}

namespace ofp {
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

} /* namespace ofp */

#endif /* OPENFLOW_UTILITY_NODEDISPLAYEDITOR_H_ */
