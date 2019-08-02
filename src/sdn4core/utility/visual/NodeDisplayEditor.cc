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

#include <sdn4core/utility/visual/NodeDisplayEditor.h>

using namespace omnetpp;

namespace SDN4CoRE {

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

} /* namespace SDN4CoRE */

