// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_PLUGIN_VVLOGGER_H_
#define ETISS_PLUGIN_VVLOGGER_H_

#include "etiss/Plugin.h"

#include <fstream>

namespace etiss
{

namespace plugin
{

/**
        writes the value of a field before each instruction

*/
class VariableValueLogger : public etiss::TranslationPlugin
{
  public:
    VariableValueLogger(const std::string &field, const std::string &file,
                        std::function<void(std::ostream &out, const std::string &field, uint64_t value)> writer);
    virtual void initCodeBlock(etiss::CodeBlock &block) const;
    virtual void finalizeInstrSet(etiss::instr::ModedInstructionSet &) const;

  public:
    /** @brief Calls the function specified with writer_ to log the variable
     */
    void writeValue();

  protected:
    /** @brief returns the name of the Plugin.
     */
    virtual std::string _getPluginName() const;

  private:
    std::string field_; ///< Name of the field to log
    /** @brief Function which specifies the outout format.
     *
     * Default output: <field>,<value>\n
     * @param Reference to file stream for writing data.
     * @param Name of the field to log.
     * @param Value of the field to log.
     */
    std::function<void(std::ostream &out, const std::string &field, uint64_t value)> writer_;
    std::ofstream out_; ///< file stream for logger.
};

} // namespace plugin

} // namespace etiss

#endif
