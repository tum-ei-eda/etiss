// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_PLUGIN_InstructionAccurateCallback_H_
#define ETISS_PLUGIN_InstructionAccurateCallback_H_

#include "etiss/Plugin.h"

#include <fstream>

namespace etiss
{

namespace plugin
{

/**
        writes the value of a field before each instruction

*/
class InstructionAccurateCallback : public etiss::TranslationPlugin
{
  public:
    InstructionAccurateCallback();
    virtual ~InstructionAccurateCallback();
    virtual void initCodeBlock(etiss::CodeBlock &block) const;
    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;

  protected:
    virtual std::string _getPluginName() const;

  public:
    etiss_int32 call_on_entry();
};

} // namespace plugin

} // namespace etiss

#endif
