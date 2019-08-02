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

#include "ColorChangingNode.h"

using namespace std;
using namespace omnetpp;

namespace SDN4CoRE {

Define_Module(ColorChangingNode);

void ColorChangingNode::initialize()
{
    string initColor = par("initColor");
    if(!initColor.empty()){
        this->setColor(initColor);
    }
    string initOpacity = par("initOpacity");
    if(!initOpacity.empty()){
        this->setOpacity(initOpacity);
    }
}

void ColorChangingNode::refreshDisplay() const {
    if (_colorUpdated){
        if (getEnvir()->isGUI()) {
           getDisplayString().setTagArg("i", 1, _color.c_str());
           getDisplayString().setTagArg("i", 2, _opacity.c_str());
        }
        _colorUpdated = false;
    }
}

void ColorChangingNode::setColor(const std::string& color) {
    this->_color = color;
    _colorUpdated = true;
}

void ColorChangingNode::setOpacity(const std::string& opacity) {
    this->_opacity = opacity;
    _colorUpdated = true;
}


}  // namespace SDN4CoRE
