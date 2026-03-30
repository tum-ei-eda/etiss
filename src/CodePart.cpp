// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
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
