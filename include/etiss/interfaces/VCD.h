/**

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://github.com/tum-ei-eda/etiss>.

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

        @date November 21, 2014

        @version 0.4

*/
/**
        @file

        @brief

        @detail

*/
#ifndef ETISS_INTERFACES_VCD_H
#define ETISS_INTERFACES_VCD_H

#include "etiss/Misc.h"

#include <fstream>
#include <iostream>
#include <vector>

/**
        macro to add a TraceableField to a VCD instance.
        @attention only works with TraceableField variables
        e.g.
        etiss::interfaces::VCD cpuLog("cpu.vcd");
        TraceableField<int> var;
        ETISS_INTERFACES_VCD_DECLARE(cpuLog,var)

        in above example the output wire will be named "var"
*/
#define ETISS_INTERFACES_VCD_DECLARE(LOG, VAR, WIDTH)                   \
    {                                                                   \
        (VAR).vcd = &(LOG);                                             \
        (LOG).declare((VAR), ETISS_TOSTRING(VAR), WIDTH, (VAR).errval); \
    }

namespace etiss
{
namespace interfaces
{

/**
        @attention this class streams the output to a file. the update() function may therfore only be called with equal
   or increasing time values
*/
class VCD : public etiss::ToString
{
  public:
    class Signal
    {
      public:
        inline Signal() : valid(false) {}
        std::string name;
        // std::string module;
        bool valid;
        uint64_t value;
        unsigned width;
        std::string ident;
        uint64_t undefined;
    };
    etiss_del_como(VCD)

        VCD(const std::string &file, const std::string &comment = std::string());
    virtual ~VCD();

    template <typename T>
    inline bool declare(T &variable, const std::string &name, unsigned width, uint64_t initialvalue,
                        uint64_t undefined = -1)
    {
        return declare((void *)&variable, name, width, initialvalue, undefined);
    }

    template <typename T>
    inline void update(double time_s, const T &variable, uint64_t value, uint64_t undefined = 0)
    {
        update((uint64_t)(time_s * 1000000000000.0), (void *)&variable, value, undefined);
    }

    inline std::string toString() const { return std::string("VCD { file=\"") + file + "\"}"; }

    void close();

  protected:
    bool declare(void *variable, const std::string &name, unsigned width, uint64_t initialvalue, uint64_t undefined);
    void update(uint64_t time_ps, void *variable, uint64_t value, uint64_t undefined);
    void flush();

  private:
    std::ofstream out_;
    bool valid_;
    bool dumpstarted_;
    std::vector<Signal> sigs_;
    uint64_t lasttime_ps;
    std::map<void *, int> ptr2index_; /// TODO replace with better lookup
    std::string dumpvar;
    std::string file;
};

} // namespace interfaces
} // namespace etiss

#endif // ETISS_INTERFACES_VCD_H
