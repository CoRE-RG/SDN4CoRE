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

package sdn4core.examples.time_synchronous_transaction_model.transaction_model_test;

import sdn4core.netconf.applications.time_synchronous_transaction_model.TransactionModelTest.TransactionModelTest;

network transaction_model_test
{
    submodules:
        knoten: TransactionModelTest {}
        controller: Controller {}
    connections allowunconnected:
        knoten.in <-- controller.out;
        knoten.out --> controller.in;
}
