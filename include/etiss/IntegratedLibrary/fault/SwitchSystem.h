// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/jit/ReturnCode.h"
#include "etiss/Plugin.h"

namespace etiss
{

namespace plugin
{

namespace fault
{

class SwitchSystem : public etiss::InterruptListenerPlugin
{

  public:
    virtual bool interruptWrite(unsigned bit, bool value) = 0;

    int32_t iread(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len);
    int32_t iwrite(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len);
    int32_t dread(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len);
    int32_t dwrite(uint64_t &time_ps, uint64_t addr, uint8_t *buf, uint32_t len);
};

} // namespace fault

} // namespace plugin

} // namespace etiss
