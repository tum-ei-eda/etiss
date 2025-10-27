// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_PLUGIN_LOGGER_H_
#define ETISS_PLUGIN_LOGGER_H_

#include "etiss/Plugin.h"
#include "etiss/IntegratedLibrary/SelectiveSysWrapper.h"

namespace etiss
{

namespace plugin
{

/**
  simple logger implementation.
*/
class Logger : public etiss::plugin::SelectiveSysWrapper
{
  public:
    struct CustomHandle
    {
        uint64_t addr = 0;
        uint64_t mask = 0;
        ETISS_System *origSys = nullptr;
    };

  public:
    Logger(uint64_t addr_value, uint64_t addr_mask);

    ETISS_System getWrapInfo(ETISS_System *origSystem) final;

  protected:
    inline virtual std::string _getPluginName() const { return std::string("Logger"); }

  private:
    CustomHandle customHandle_;
};

} // namespace plugin

} // namespace etiss

#endif
