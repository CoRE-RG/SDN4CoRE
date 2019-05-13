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
#ifndef OPENFLOW_CORE4INET_OF_CTRL_SRPTable_H_
#define OPENFLOW_CORE4INET_OF_CTRL_SRPTable_H_

//Std

#include <bits/stdint-uintn.h>
#include <omnetpp/simtime_t.h>
#include <stddef.h>
#include <list>
#include <unordered_map>

#include "core4inet/base/avb/AVBDefs.h"
#include "inet/linklayer/common/MACAddress.h"

#include "openflow/openflow/controller/Switch_Info.h"


namespace SDN4CoRE{

/**
 * @brief This module handles the mapping between ports and MAC addresses.
 * The SRPTable is modified for the controller purposes.
 *
 * See the NED definition for details.
 *
 * @author Till Steinbach, Philipp Meyer, Timo Haeckel
 */
class OF_CTRL_SRPTable
{
    public:
        /**
         * @brief Entry for Talker
         */
        class OF_CTRL_TalkerEntry
        {
            public:
                uint64_t streamId;          // Stream ID
                CoRE4INET::SR_CLASS srClass;           // Stream Reservation Class
                inet::MACAddress address;   // The talkers address
                ofp::Switch_Info* swinfo;        // Switch Info from Openflow Controller
                int port;                   // Port at Switch
                size_t framesize;           // Frame size in byte
                uint16_t intervalFrames;    // interval frames
                uint16_t vlan_id;           // VLAN identifier
                simtime_t insertionTime;    // Arrival time of SRP entry

                OF_CTRL_TalkerEntry();
                OF_CTRL_TalkerEntry(uint64_t new_streamId, CoRE4INET::SR_CLASS new_srClass, inet::MACAddress new_address,
                        ofp::Switch_Info *new_swinfo, int new_port, size_t new_framesize, unsigned short new_intervalFrames,
                        unsigned short new_vlan_id, simtime_t new_insertionTime);
                virtual ~OF_CTRL_TalkerEntry();

        };

        /**
         * @brief Entry for Listener
         */
        class OF_CTRL_ListenerEntry
        {
            public:
                uint64_t streamId;          // Stream ID
                ofp::Switch_Info* swinfo;        // Switch Info from Openflow Controller
                int port;                   // Port at Switch
                uint16_t vlan_id;           // VLAN identifier
                simtime_t insertionTime;    // Arrival time of SRP entry

                OF_CTRL_ListenerEntry();
                OF_CTRL_ListenerEntry(uint64_t new_streamId, ofp::Switch_Info *new_swinfo, int new_port, unsigned short new_vlan_id, simtime_t new_insertionTime);
                virtual ~OF_CTRL_ListenerEntry();

        };

        typedef std::list<OF_CTRL_ListenerEntry*> OF_CTRL_ListenerList;
        typedef std::unordered_map<uint64_t, OF_CTRL_TalkerEntry*> OF_CTRL_TalkerTable;
        typedef std::unordered_map<int, OF_CTRL_ListenerEntry*> OF_CTRL_ListenerPortList;
        typedef std::unordered_map<uint64_t, OF_CTRL_ListenerPortList> OF_CTRL_ListenerTable;

    private:
        /**
         * map of talker entries for stream id
         */
        std::unordered_map<unsigned int, OF_CTRL_TalkerTable> talkerTables;

        /**
         * map of listener entries for stream id
         */
        std::unordered_map<unsigned int, OF_CTRL_ListenerTable> listenerTables;

        simtime_t agingTime;

    public:
        /**
         *  @brief Constructor
         */
        OF_CTRL_SRPTable(simtime_t new_agingTime=0):agingTime(new_agingTime){};

        /**
         *  @brief Destructor
         */
        virtual ~OF_CTRL_SRPTable();

    public:
        /**
         * @brief For a known talker address and V-TAG it finds out the streamId
         *
         * @param talkerAddress address
         * @param vid VLAN ID
         * @return streamId related to talkerAddress
         */
        virtual uint64_t getStreamIdForTalkerAddress(const inet::MACAddress &talkerAddress, uint16_t vid =
                CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief For a known talker address and V-TAG it finds out the SR-Class of the Stream
         *
         * @param talkerAddress address
         * @param vid VLAN ID
         * @return SR-Class related to the Stream of the talkerAddress
         */
        virtual CoRE4INET::SR_CLASS getSrClassForTalkerAddress(const inet::MACAddress &talkerAddress, uint16_t vid =
                CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief For a known streamId and V-TAG it finds out the port where relay component should deliver the message
         *
         * @param streamId streamId
         * @param vid VLAN ID
         * @return listeners for the stream
         */
        virtual OF_CTRL_SRPTable::OF_CTRL_ListenerList getListenersForStreamId(uint64_t streamId, uint16_t vid = CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief For a known talker address and V-TAG it finds out the port where relay component should deliver the message
         *
         * @param talkerAddress address
         * @param vid VLAN ID
         * @return listeners for the stream
         */
        virtual OF_CTRL_SRPTable::OF_CTRL_ListenerList getListenersForTalkerAddress(const inet::MACAddress &talkerAddress, uint16_t vid =
                CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief Retrieve the module a message with a given streamId will come from (required for listener ready messages)
         *
         * @param streamId the streams id
         * @param vid VLAN ID
         * @return Output port for address, or -1 if unknown.
         */
        virtual OF_CTRL_SRPTable::OF_CTRL_TalkerEntry* getTalkerForStreamId(uint64_t streamId, uint16_t vid = CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief Retrieve the required bandwidth for a module with registered listeners
         *
         * @param module the module registered as listener
         * @return bandwidth in bps
         */
        virtual unsigned long getBandwidthForPort(const int port);

        /**
         * @brief Retrieve the required bandwidth for a module with registered listeners per SR-Class
         *
         * @param module the module registered as listener
         * @param srClass the SR-Class (A or B)
         * @return bandwidth in bps
         */
        virtual unsigned long getBandwidthForPortAndSRClass(const int port, CoRE4INET::SR_CLASS srClass);

        /**
         * @brief Retrieve the required bandwidth for a stream
         *
         * @param streamId the streams id
         * @param vid VLAN ID
         * @return bandwidth in bps
         */
        virtual unsigned long getBandwidthForStream(uint64_t streamId, uint16_t vid = CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief Register a new streamId at talkerTable.
         * @return True if refreshed. False if it is new.
         */
        virtual bool updateTalkerWithStreamId(uint64_t streamId, ofp::Switch_Info* swinfo, int port, const inet::MACAddress address,
                CoRE4INET::SR_CLASS srClass = CoRE4INET::SR_CLASS::A, size_t framesize = 0, uint16_t intervalFrames = 0, uint16_t vid =
                        CoRE4INET::VLAN_ID_DEFAULT, simtime_t simtime=0);

        /**
         * @brief Unregister a streamId at talkerTable.
         * @return True if removed. False if not registered.
         */
        virtual bool removeTalkerWithStreamId(uint64_t streamId, ofp::Switch_Info* swinfo, int port, const inet::MACAddress address,
                uint16_t vid = CoRE4INET::VLAN_ID_DEFAULT);

        /**
         * @brief Register a new streamId at listenerTable.
         * @return True if refreshed. False if it is new.
         */
        virtual bool updateListenerWithStreamId(uint64_t streamId, ofp::Switch_Info* swinfo, int port, uint16_t vid = CoRE4INET::VLAN_ID_DEFAULT, simtime_t simtime=0);

        /**
         * @brief Unregister a streamId at listenerTable.
         * @return True if removed. False if not registered.
         */
        virtual bool removeListenerWithStreamId(uint64_t streamId, ofp::Switch_Info* swinfo, int port, uint16_t vid = CoRE4INET::VLAN_ID_DEFAULT);

        /**
         *  @brief Prints cached data
         */
        virtual void printState();

        /**
         * @brief For lifecycle: clears all entries from the table.
         */
        virtual void clear();

        /**
         * @brief Remove entries that were not updated during agingTime if necessary
         */
        void removeAgedEntriesIfNeeded(simtime_t now);

        /**
         * @brief creates an XML string with the contents of the SRP Table.
         * This string can be used to fill the SRP Table with importFromXML.
         */
        std::string exportToXML();

        /**
         * @brief Imports entries from an XMLdocument.
         * The root element needs to be <srpTable>
         */
        bool importFromXML(cXMLElement* xml, ofp::Switch_Info* swinfo);


    protected:
        /**
         * @brief Remove entries that were not updated during agingTime
         */
        void removeAgedEntries(simtime_t now);
        /**
         * @brief get the number of registered talkers
         *
         * @return number of talkers
         */
        size_t getNumTalkerEntries();

        /**
         * @brief get the number of registered listeners
         *
         * @return number of listeners
         */
        size_t getNumListenerEntries();
};

} /*end namespace SDN4CoRE*/

#endif
