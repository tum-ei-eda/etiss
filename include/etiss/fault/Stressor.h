/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

        The initial version of this software has been created with the funding support by the German Federal
        Ministry of Education and Research (BMBF) in the project EffektiV under grant 01IS13022.

        Redistribution and use in source and binary forms, with or without modification, are permitted
        provided that the following conditions are met:

        1. Redistributions of source code must retain the above copyright notice, this list of conditions and
        the following disclaimer.

        2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions
        and the following disclaimer in the documentation and/or other materials provided with the distribution.

        3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse
        or promote products derived from this software without specific prior written permission.

        THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
        WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
        PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
        DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
        PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
        HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
        NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
        POSSIBILITY OF SUCH DAMAGE.

        </pre>

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date December 15, 2014

        @version 0.4

*/
/**
        @file

        @brief contains the stressor class that loads and activates faults.

        @detail

*/

#ifndef ETISS_STRESSOR_H_
#define ETISS_STRESSOR_H_

#ifndef NO_ETISS
#include "etiss/fault/Fault.h"
#else
#include "fault/Fault.h"
#endif

namespace etiss
{

namespace fault
{

class Stressor
{
  public:
    /** @brief extracts faults out of the given xml file.
     * @param file the xmlfile with fault triggers.
     * @return true if XML file could be loaded.
     */
    static bool loadXML(const std::string &file, const int coreID = 0);

    /** @brief adds a fault to a static map that can be accessed
     *        by static std::map<int32_t,Fault> & faults().
     * @param f the fault for adding to the map.
     * @return false if fault already exists in map.
     */
    static bool addFault(const Fault &f);

    /** @brief Checks if the given trigger is valid and calls applyAction.
     *
     *         Is called by a VirtualStruct e.g. OR1KVCPU::vcoreState.
     *         The VirtualStruct inherits the Injector so it can call
     *         Injector::cycleAccurateCallback, which calls this function
     * @param firedTrigger the Trigger which was called.
     * @param fault_id the id of the fault to which the trigger corresponds.
     * @param injector injector which called this function.
     * @param time_ps cpu time.
     * @return true if the fired trigger expired.
     */
    static bool firedTrigger(const Trigger &firedTrigger, int32_t fault_id, Injector *injector, uint64_t time_ps);

    /** @brief clears the fault map.
     */
    static void clear();
};

} // namespace fault

} // namespace etiss

#endif
