// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
