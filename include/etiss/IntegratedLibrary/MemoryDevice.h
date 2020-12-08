/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

#ifndef ETISS_PLUGIN_MEMORYDEVICE_H
#define ETISS_PLUGIN_MEMORYDEVICE_H

#include "etiss/Plugin.h"
#include "etiss/System.h"

namespace etiss
{
namespace plugin
{

class MemoryDeviceMapper : public etiss::SystemWrapperPlugin
{
  public:
    const std::string name_;
    MemoryDeviceMapper(std::string name);
    virtual ~MemoryDeviceMapper();
    virtual ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system);
    virtual ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system);

    // similar to etiss::System interface but not overrideable to increase performance
    etiss::int32 iread(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint32 len);
    etiss::int32 iwrite(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dread(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dwrite(ETISS_System *sys, ETISS_CPU *cpu, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dbg_read(ETISS_System *sys, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);
    etiss::int32 dbg_write(ETISS_System *sys, etiss::uint64 addr, etiss::uint8 *buf, etiss::uint32 len);

    inline const std::vector<etiss::System *> &devices() { return devices_; }

    virtual int map(bool ibus, bool read, bool dbg, uint64_t addr, uint8_t *buf, unsigned len, unsigned &newlen);

    virtual bool mount(etiss::System *sys, uint64_t mask, uint64_t addr);

  protected:
    std::vector<etiss::System *> devices_;
    std::vector<std::pair<uint64_t, uint64_t>> mountPoints_;

  private:
};

} // namespace plugin
} // namespace etiss

#endif // ETISS_PLUGIN_MEMORYDEVICE_H
