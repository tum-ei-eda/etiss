// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief contains a simple plugin to print instructions

        @detail

*/

#include "etiss/Misc.h"
#include "etiss/Plugin.h"

namespace etiss
{

namespace plugin
{

/**
        @brief a simple plugin that prints the instruction and address when an instruction is executed
*/
class PrintInstruction : public etiss::TranslationPlugin
{
  public:
    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;
    virtual void initCodeBlock(etiss::CodeBlock &block) const;
    virtual std::string _getPluginName() const;
    virtual void *getPluginHandle();
};

} // namespace plugin

} // namespace etiss
