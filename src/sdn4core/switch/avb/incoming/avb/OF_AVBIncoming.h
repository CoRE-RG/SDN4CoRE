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

#ifndef CORE4INET_OF_AVBIncoming_H_
#define CORE4INET_OF_AVBIncoming_H_

//CoRE4INET
#include "core4inet/incoming/base/Incoming.h"
#include "core4inet/services/avb/SRP/SRPTable.h"

namespace SDN4CoRE {

//This disables the padding warning for this class! please recheck when adding new members!
#pragma GCC diagnostic ignored "-Wpadded"

/**
 * @brief Class for the critical traffic conformance check of
 * audio-video bridging traffic.
 * Updated for usage in Openflow Switches.
 *
 * @sa Incoming
 *
 * @author Philipp Meyer, Timo Häckel
 */
class OF_AVBIncoming : public CoRE4INET::Incoming
{
    private:
        /**
         * @brief Caches srpTable module
         */
        CoRE4INET::SRPTable *srptable;
    protected:
        /**
         * @brief Initialization of the module
         */
        virtual void initialize() override;

        /**
         * @brief Forwards messages arriving on in-gate to out-gate.
         *
         * @param msg the incoming message.
         */
        virtual void handleMessage(cMessage *msg) override;

    public:
        /**
         * @brief Constructor.
         */
        OF_AVBIncoming();
};

} /* namespace SDN4CoRE */
#endif /* CORE4INET_OF_AVBIncoming_H_ */
