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

#include "etiss/Timing.h"

namespace etiss
{

void DataSheetAccurateTiming::addRule(std::function<bool(uint32_t /*mode*/)> matchesMode,
                                      std::function<bool(unsigned /*width*/)> matchesWidth,
                                      std::function<bool(etiss::instr::Instruction & /*instr*/)> matchesInstr,
                                      std::function<void(etiss::instr::Instruction & /*match*/)> handleMatch)
{

    if (!handleMatch) // return if there is no handler
        return;

    if (!matchesMode)
    {
        etiss::log(etiss::WARNING, "etiss::DataSheetAccurateTiming::addRule called without a matcher function for the "
                                   "mode. using default match all rule.");
        matchesMode = [](uint32_t) { return true; };
    }

    if (!matchesWidth)
    {
        etiss::log(etiss::WARNING, "etiss::DataSheetAccurateTiming::addRule called without a matcher function for the "
                                   "width. using default match all rule.");
        matchesWidth = [](unsigned) { return true; };
    }

    if (!matchesInstr)
    {
        etiss::log(etiss::WARNING, "etiss::DataSheetAccurateTiming::addRule called without a matcher function for a "
                                   "instruction. using default match all rule.");
        matchesInstr = [](etiss::instr::Instruction &) { return true; };
    }

    Rule *rule = new Rule();
    rule->mode = matchesMode;
    rule->width = matchesWidth;
    rule->instr = matchesInstr;
    rule->handler = handleMatch;
    rules_.push_back(rule);
}

void DataSheetAccurateTiming::addRule(
    const std::tuple<uint32_t, unsigned, const char *, std::function<void(etiss::instr::Instruction & /*match*/)>>
        &tuple)
{
    uint32_t refmode = std::get<0>(tuple);
    unsigned refwidth = std::get<1>(tuple);
    std::string refname = std::get<2>(tuple);

    addRule([refmode](uint32_t mode) { return refmode == mode; },
            [refwidth](unsigned width) { return refwidth == width; },
            [refname](etiss::instr::Instruction &instr) { return refname == instr.name_; }, std::get<3>(tuple));
}

void DataSheetAccurateTiming::addRule(
    const std::tuple<std::regex, std::regex, std::regex, std::function<void(etiss::instr::Instruction & /*match*/)>>
        &tuple)
{
    std::regex refmode = std::get<0>(tuple);
    std::regex refwidth = std::get<1>(tuple);
    std::regex refname = std::get<2>(tuple);

    addRule([refmode](uint32_t mode) { return std::regex_match(etiss::toString(mode), refmode); },
            [refwidth](unsigned width) { return std::regex_match(etiss::toString(width), refwidth); },
            [refname](etiss::instr::Instruction &instr) { return std::regex_match(instr.name_, refname); },
            std::get<3>(tuple));
}

DataSheetAccurateTiming::~DataSheetAccurateTiming()
{
    for (auto iter = rules_.begin(); iter != rules_.end(); ++iter)
    {
        delete *iter;
    }
    rules_.clear();
}

void DataSheetAccurateTiming::initInstrSet(etiss::instr::ModedInstructionSet &mis) const
{
    bool verifyCompleteness = true;

    std::set<etiss::instr::Instruction *> found;
    std::set<etiss::instr::Instruction *> matched;
    if (verifyCompleteness)
    { // create a list of all instructions
        mis.foreach ([&found](etiss::instr::VariableInstructionSet &vis) {
            vis.foreach ([&found](etiss::instr::InstructionSet &is) {
                is.foreach ([&found](etiss::instr::Instruction &instr) { found.insert(&instr); });
            });
        });
    }

    for (auto iter = rules_.begin(); iter != rules_.end(); ++iter)
    {
        Rule *rule = *iter;
        if (rule)
        {
            mis.foreach ([&matched, rule](etiss::instr::VariableInstructionSet &vis) {
                uint32_t mode = vis.parent_.getMode(vis); /// TODO? pass mode parameter in foreach/ store mode with vis
                if (rule->mode(mode))
                { // match mode
                    vis.foreach ([&matched, rule](etiss::instr::InstructionSet &is) {
                        unsigned width = is.width_;
                        if (rule->width(width))
                        { // match width
                            is.foreach ([&matched, rule](etiss::instr::Instruction &instr) {
                                if (rule->instr(instr))
                                {                           // match instruction
                                    matched.insert(&instr); // store instruction as matched
                                    rule->handler(instr);   // handle instruction
                                }
                            });
                        }
                    });
                }
            });
        }
    }

    if (verifyCompleteness)
    {
        for (auto iter = matched.begin(); iter != matched.end(); ++iter)
        {
            found.erase(*iter);
        }
        for (auto iter = found.begin(); iter != found.end(); ++iter)
        {
            etiss::log(etiss::WARNING, std::string("DataSheetAccurateTiming instance [") +
                                           ((DataSheetAccurateTiming *)this)->_getPluginName() +
                                           "] ignored instruction " + (*iter)->toString());
        }
    }
}

} // namespace etiss
