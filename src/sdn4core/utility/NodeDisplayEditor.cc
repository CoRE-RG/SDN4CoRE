/*
 * NodeColorChanger.cc
 *
 *  Created on: Nov 30, 2018
 *      Author: timo
 */

#include <omnetpp.h>
#include <openflow/utility/NodeDisplayEditor.h>
using namespace omnetpp;

namespace ofp {

NodeDisplayEditor::NodeDisplayEditor(cModule* targetModule) :
        _target(targetModule) {

}

NodeDisplayEditor::~NodeDisplayEditor() {

}

void NodeDisplayEditor::setNodeColor(const char* color, const char* opacity) {
    setNodeColor(_target, color, opacity);
}

void NodeDisplayEditor::setNodeColor(omnetpp::cModule* target,
        const char* color, const char* opacity) {
    if (target && getEnvir()->isGUI()) {
        if (color && opacity) {
            if (target->hasDisplayString()) {
                target->getDisplayString().setTagArg("i", 1, color);
                target->getDisplayString().setTagArg("i", 2, opacity);
            }
        }
    }
}

NodeDisplayEditor::NodeDisplayEditor() :
        _target(nullptr) {
}

} /* namespace ofp */

