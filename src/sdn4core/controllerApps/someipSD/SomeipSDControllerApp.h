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

#ifndef __SDN4CORE_SOMEIPSDCONTROLLERAPP_H_
#define __SDN4CORE_SOMEIPSDCONTROLLERAPP_H_

#define BROADCASTADDRESS "255.255.255.255"

#include <omnetpp.h>
#include "sdn4core/utility/layeredInformation/LayeredInformation.h"
#include "sdn4core/controllerApps/base/PacketProcessorBase.h"
#include "soa4core/messages/someip/SomeIpSDHeader.h"
//AUTO-GENERATED MESSAGES
#include "soa4core/messages/someip/SomeIpSDEntry_m.h"
#include "soa4core/messages/someip/SomeIpSDOption_m.h"

// STD
#include <map>
#include <list>

using namespace omnetpp;


namespace SDN4CoRE {

/**
 * TODO - Generated class
 */
class SomeipSDControllerApp: public PacketProcessorBase
{
public:
    struct ServiceInstance {
        SOA4CoRE::ServiceEntry* entry;
        std::list<SOA4CoRE::SomeIpSDOption*> optionList;
        void clear() {
            if (entry) delete entry;
            entry = nullptr;
            for (auto elem: optionList) {
                if (elem) delete elem;
                elem = nullptr;
            }
            optionList.clear();
        }
    };

    typedef std::map<int, ServiceInstance> InstanceMap;
    typedef std::map<int, InstanceMap> ServiceInstanceMap;

    struct FindRequest {
        SOA4CoRE::SomeIpSDHeader* requestHeader;
        SOA4CoRE::ServiceEntry* entry;
        std::list<SOA4CoRE::SomeIpSDOption*> optionList;
        void clear() {
            if (requestHeader) delete requestHeader;
            requestHeader = nullptr;
            if (entry) delete entry;
            entry= nullptr;
            for (auto elem: optionList) {
                if (elem) delete elem;
                elem = nullptr;
            }
            optionList.clear();
        }
    };

    typedef std::map<int, std::list<FindRequest>> RequestMap;
    ~SomeipSDControllerApp(){
        for (auto elem : serviceTable){
            for (auto element : elem.second) {
                element.second.clear();
            }
            elem.second.clear();
        }
        serviceTable.clear();

        for (auto elem : requestTable){
                for (auto element : elem.second) {
                    element.clear();
                }
                elem.second.clear();
            }
        requestTable.clear();
    };
protected:
    ServiceInstanceMap serviceTable;
    RequestMap requestTable;
    LayeredInformation myLayeredInformation;
    uint16_t controllerRequestID;
    virtual void initialize() override;

    /**
      * Interface function for the main processing engine of packet_in messages.
      *
      * This default implementation does nothing
      *
      * @param packet_in_msg The packet in message
      */
    virtual void processPacketIn(openflow::OFP_Packet_In *packet_in_msg) override;



    void processSomeIpSDHeader(SOA4CoRE::SomeIpSDHeader* someIpSDHeader);
    void processFindEntry(SOA4CoRE::SomeIpSDEntry* findInquiry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);
    void processOfferEntry(SOA4CoRE::SomeIpSDEntry* offerEntry, SOA4CoRE::SomeIpSDHeader* someIpSDHeader);
    SOA4CoRE::SomeIpSDHeader* buildOffer(SOA4CoRE::SomeIpSDHeader* findSource, SOA4CoRE::SomeIpSDEntry* findEntry, std::list<ServiceInstance> foundInstances);
    SOA4CoRE::SomeIpSDHeader* buildFind(SOA4CoRE::SomeIpSDHeader* findSource, SOA4CoRE::SomeIpSDEntry* findEntry);
    void sendOffer(SOA4CoRE::SomeIpSDHeader* someIpSDHeader, SOA4CoRE::SomeIpSDHeader* findSource);
    void sendFind(SOA4CoRE::SomeIpSDHeader*, SOA4CoRE::SomeIpSDHeader* findSource);
    /**
      * looks for the service requested find entry in the controllers list of known offers
      * @param findEntry someIpSD find request
      * @return List of requested instance entries
      *     containing zero elements if no service was found
      *     containing one element if a specific instance was requested
      *     containing all known instances if no specific instanceId was requested
      */
     std::list<ServiceInstance> lookUpFindInMap(SOA4CoRE::SomeIpSDEntry* findEntry);
     std::list<SOA4CoRE::SomeIpSDOption*> getEntryOptions(SOA4CoRE::SomeIpSDEntry* xEntry, SOA4CoRE::SomeIpSDHeader* header);
     void updateServiceTable(ServiceInstance& newInfo);
};

} /*end namespace SDN4CoRE*/

#endif
