// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_PLUGIN_SELECTIVESYSWRAPPER_H
#define ETISS_PLUGIN_SELECTIVESYSWRAPPER_H

#include "etiss/Plugin.h"

namespace etiss
{

namespace plugin
{

/// @brief SystemWrapperPlugin that only wraps some of the System calls.
class SelectiveSysWrapper : public etiss::SystemWrapperPlugin
{
  public:
    /**
     * @brief Defines which System functions to wrap.
     *
     * @details Initialize an ETISS_System struct to zero and only set the fields of the functions that this plugin
     * should wrap. The handle field may be set to a custom data structure that will be passed to the wrapped functions
     * as first argument.
     *
     * @param origSystem The System that is being wrapped. Must be stored by the plugin to fall back to the parent
     * System.
     */
    virtual ETISS_System getWrapInfo(ETISS_System *origSystem) = 0;

    ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system) final;
    ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system) final;
};

} // namespace plugin

} // namespace etiss

#endif
