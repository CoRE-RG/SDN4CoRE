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


#ifndef __OPENFLOW_COLORCHANGINGNODE_H_
#define __OPENFLOW_COLORCHANGINGNODE_H_

#include <omnetpp.h>
#include <string>

namespace SDN4CoRE {

/**
 * The Color changing Node provides functions to set the Color and Opacity during runtime.
 * It either can be used as a simple Node to Display Colors in the Network or extended to
 * inherit color changing functionality.
 *
 * @author Timo Haeckel, for HAW Hamburg
 */
class ColorChangingNode: public omnetpp::cSimpleModule {
public:
    const std::string& getColor() const {
        return _color;
    }

    /**
     * sets the color to the string value.
     * The caller must ensure it is accepted by omnetpp display strings.
     */
    virtual void setColor(const std::string& color);

    const std::string& getOpacity() const {
        return _opacity;
    }

    /**
     * Sets the opacity to the string value.
     * The caller must ensure it is accepted by omnetpp display strings.
     */
    void setOpacity(const std::string& opacity);

protected:
    /**
     * initialize the module colors.
     */
    virtual void initialize() override;
    /**
     * refresh the display string if it was updated.
     */
    virtual void refreshDisplay() const override;

private:
    /**
     * The current color.
     */
    std::string _color;
    /**
     * The current opacity.
     */
    std::string _opacity;
    /**
     * True if the color was changed and needs to be updated by refresh display.
     * Refresh display resets this status so it needs to be mutable.
     */
    mutable bool _colorUpdated = false;
};


}  // namespace SDN4CoRE

#endif
