/*

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

        @author Chair of Electronic Design Automation, TUM

        @version 0.1

*/

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
