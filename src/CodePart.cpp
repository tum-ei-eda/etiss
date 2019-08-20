/**

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implementation of etiss/CodePart.h

        @detail

*/

#include "etiss/CodePart.h"

using namespace etiss;

void CodeSet::writeCodeParts(std::string &code, const std::list<CodePart> &parts, bool required, RegisterSet &ignored,
                             bool intersect)
{

    std::list<CodePart>::const_iterator iter = parts.begin();
    while (iter != parts.end())
    {
        if (required)
        { // no optional code; skip

            if (iter->fullRegistersDependency())
            {
                ignored.clear();
            }
            else
            {
                if (intersect)
                {
                    ignored.intersect(iter->getAffectedRegisters());
                }
                else
                {
                    ignored.merge(iter->getAffectedRegisters());
                }
                ignored.applyShadow(iter->getRegisterDependencies());
            }
            code = iter->getCode() + "\n" + code;
            // std::cout << "used code: {"<< std::endl << iter->getCode() << std::endl << "}"<<std::endl;
        }
        else
        {
            if (!iter->getAffectedRegisters().maskedBy(ignored))
            { // check if affected registers will be overwritten anyway

                if (iter->fullRegistersDependency())
                { // requires all registers to be valid
                    ignored.clear();
                }
                else
                {
                    if (intersect)
                    { // in case of return statements only intersection produces an alwasy valid state
                        ignored.intersect(iter->getAffectedRegisters());
                    }
                    else
                    {
                        ignored.merge(iter->getAffectedRegisters());
                    }
                    ignored.applyShadow(iter->getRegisterDependencies());
                }

                code = iter->getCode() + "\n" + code;
                // std::cout << "used code: {"<< std::endl << iter->getCode() << std::endl << "}"<<std::endl;
            }
            else
            {
                // std::cout << "removed code: {"<< std::endl << iter->getCode() << std::endl << "}"<<std::endl;
            }
        }
        iter++;
    }
}

std::string CodeSet::toString(RegisterSet &ignored, bool &ok) const
{
    ok = true;
    std::string code;

    writeCodeParts(code, appretreq_parts_, true, ignored,
                   true); // std::cout << "Ignored 1: " << ignored._dbg_print() << std::endl;

    writeCodeParts(code, appopt_parts_, false, ignored,
                   false); // std::cout << "Ignored 2: " << ignored._dbg_print() << std::endl;

    writeCodeParts(code, appreq_parts_, true, ignored,
                   false); // std::cout << "Ignored 3: " << ignored._dbg_print() << std::endl;

    writeCodeParts(code, midopt_parts_, false, ignored,
                   false); // std::cout << "Ignored 4: " << ignored._dbg_print() << std::endl;

    writeCodeParts(code, inireq_parts_, true, ignored,
                   false); // std::cout << "Ignored 5: " << ignored._dbg_print() << std::endl;

    writeCodeParts(code, pindbgretreq_parts_, true, ignored,
                   true); // std::cout << "Ignored 6: " << ignored._dbg_print() << std::endl;

    return code;
}

void CodeBlock::toCode(std::stringstream &out, const std::string &funcname, std::set<std::string> *fileglobalcode)
{

    if (fileglobalcode)
    {
        for (auto iter = fileglobal_code.begin(); iter != fileglobal_code.end(); iter++)
        {
            if (fileglobalcode->find(*iter) == fileglobalcode->end())
            {
                out << *iter;
                fileglobalcode->insert(*iter);
            }
        }
    }
    else
    {
        for (auto iter = fileglobal_code.begin(); iter != fileglobal_code.end(); iter++)
        {
            out << *iter;
        }
    }

    out << "etiss_uint32 " << funcname
        << "(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers) {\n"
           "	const etiss_uint64 blockglobal_startaddr = 0x"
        << std::hex << startindex_ << std::dec
        << "ULL;\n"
           "	const etiss_uint64 blockglobal_jumpaddr = cpu->instructionPointer - blockglobal_startaddr;\n";

    for (auto iter = functionglobal_code.begin(); iter != functionglobal_code.end(); iter++)
    {
        out << *iter;
    }

    out << "\n\tswitch(blockglobal_jumpaddr){\n";
    std::list<std::string> cases;
    {
        // write cases
        RegisterSet ignored;
#if DEBUG
        etiss::uint64 last = 0;
#endif
        for (auto iter = lines_.rbegin(); iter != lines_.rend(); iter++)
        {
#if DEBUG
            if (last > iter->getAddress())
            {
                etiss::log(etiss::FATALERROR, "error in code block: the line addresses are not in ascending order");
            }
#endif
            bool ok = true; // TODO use result
            std::stringstream lss;
            lss << "	case " << (iter->getAddress() - startindex_) << ":\n";
            lss << "		{\n";
            lss << iter->getCodeSet().toString(ignored, ok);
            lss << "		}\n";
            cases.push_front(lss.str());
        }
    }
    for (auto iter = cases.begin(); iter != cases.end(); iter++)
        out << *iter;
    out << "\n\t break;\n"
           "\tdefault:\n"
           "\t\treturn ETISS_RETURNCODE_ILLEGALJUMP;\n"
           "\t}"
           "\treturn ETISS_RETURNCODE_NOERROR;\n"
           "}\n\n";
}
