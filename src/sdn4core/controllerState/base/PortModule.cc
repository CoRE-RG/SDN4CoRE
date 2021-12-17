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

#include "PortModule.h"

namespace SDN4CoRE{

Define_Module(PortModule);

void PortModule::initialize() {
    WATCH(_port);
    WATCH_PTR(_deviceLink);
}

int PortModule::getPort(){
    return _port;
}

void PortModule::setPort(int port) {
    _port = port;
}

bool PortModule::setDeviceLink(PortModule* nextDevicePort) {
    bool updated = false;
    if(_deviceLink) {
        updated = true;
    }
    _deviceLink = nextDevicePort;
    return updated;
}

bool PortModule::isDeviceLink() {
    return _deviceLink != nullptr;
}

PortModule* PortModule::getDeviceLink() {
    return _deviceLink;
}

}
