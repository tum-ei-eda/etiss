/**

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

        @author Marc Greim <marc.greim@mytum.de>, Chair of Electronic Design Automation, TUM

        @date July 29, 2014

        @version 0.1

*/
/**
        @file

        @brief implementation of etiss/IntegratedLibrary/errorInjection/Plugin.h

        @detail

*/
#include "etiss/IntegratedLibrary/errorInjection/Plugin.h"
#include "etiss/CPUArch.h"
#include "etiss/CPUCore.h"
#include <fstream>

using namespace etiss::plugin::errorInjection;

BlockAccurateHandler::Error::Error(std::string reg, unsigned errorid, etiss::uint64 time_ps, etiss::uintMax xor_,
                                   etiss::uintMax and_, etiss::uintMax or_)
    : reg(reg), errorid(errorid), time_ps(time_ps), xor_(xor_), and_(and_), or_(or_)
{
}

BlockAccurateHandler::BlockAccurateHandler()
{
    next_time_ps = (etiss::uint64)(etiss::int64)-1;
    last_time_ps = 0;
}
BlockAccurateHandler::~BlockAccurateHandler() {}

bool etiss_BlockAccurateHandler_cmp(const BlockAccurateHandler::Error &o1, const BlockAccurateHandler::Error &o2)
{
    return o1.time_ps < o2.time_ps;
}

void BlockAccurateHandler::add(etiss::uint64 time_ps, unsigned errorid, std::string register_, etiss::uintMax xor_,
                               etiss::uintMax and_, etiss::uintMax or_)
{
    errors_.push_back(BlockAccurateHandler::Error(register_, errorid, time_ps, xor_, and_, or_));
    errors_.sort(etiss_BlockAccurateHandler_cmp);
    if (!errors_.empty())
    {
        next_time_ps = errors_.front().time_ps;
    }
    else
    {
        next_time_ps = (etiss::uint64)(etiss::int64)-1;
    }
}

etiss::int32 BlockAccurateHandler::execute()
{
    last_time_ps = cpu->cpuTime_ps;
    if (next_time_ps < last_time_ps)
    {
        for (auto iter = errors_.begin(); iter != errors_.end() && iter->time_ps <= cpu->cpuTime_ps;)
        {
            auto f = plugin_core_->getStruct()->findName(iter->reg);
            if (!f)
            {
                return ETISS_RETURNCODE_GENERALERROR;
            }
            switch (f->width_)
            {
            case 8:
            {
                etiss::uint8 val = (etiss::uint8)f->read();
                val = (etiss::uint8)(((val ^ iter->xor_) & iter->and_) | iter->or_);
                f->write(val);
                break;
            }
            case 16:
            {
                etiss::uint16 val = (etiss::uint16)f->read();
                val = (etiss::uint16)(((val ^ iter->xor_) & iter->and_) | iter->or_);
                f->write(val);
                break;
            }
            case 32:
            {
                etiss::uint32 val = (etiss::uint32)f->read();
                std::cout << iter->reg << ": old:" << val;
                val = (etiss::uint32)(((val ^ iter->xor_) & iter->and_) | iter->or_);
                std::cout << "new: " << val << std::endl;
                f->write(val);
                break;
            }
            case 64:
            {
                etiss::uint64 val = (etiss::uint64)f->read();
                val = (etiss::uint64)(((val ^ iter->xor_) & iter->and_) | iter->or_);
                f->write(val);
                break;
            }
            default:
                etiss::log(etiss::ERROR, "BlockAccurateHandler: invalid register width");
            }

            std::stringstream ss;
            ss << "BlockAccurateHandler: injected error (id: " << iter->errorid << ")";
            etiss::log(etiss::INFO, ss.str());
            errors_.erase(iter++);
        }
        if (!errors_.empty())
        {
            next_time_ps = errors_.front().time_ps;
        }
        else
        {
            next_time_ps = (etiss::uint64)(etiss::int64)-1;
        }
    }

    return etiss::RETURNCODE::NOERROR;
}

void BlockAccurateHandler::parseFile(std::string filename, std::string reg)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "failed to load error definition file " << filename << std::endl;
        return;
    }

    while (file.good())
    {
        std::string line;
        std::getline(file, line);
        std::stringstream ls(line);

        while (ls.peek() == ' ' || ls.peek() == '\t')
        {
            char c;
            ls >> c;
        }

        if (ls.peek() == '#')
            continue;

        etiss::uint64 tmp_cf;
        ls >> tmp_cf;           // get time in ns
        tmp_cf = tmp_cf * 1000; // ns to ps
        if (ls.fail())
        {
            printf("Invalid line in error definition file\n");
            continue;
        }
        char semicolon;
        ls >> semicolon;
        if (ls.fail() || semicolon != ';')
        {
            printf("Invalid line in error definition file\n");
            continue;
        }
        unsigned tmp_f;
        ls >> tmp_f; // get flipped bit
        if (ls.fail())
        {
            printf("Invalid line in error definition file\n");
            continue;
        }
        ls >> semicolon;
        bool eidv = false;
        unsigned errorid = 0;
        if (!ls.fail() && semicolon == ';')
        { // parse errorid
            ls >> errorid;
            eidv = !ls.fail();
        }

        static unsigned global_errorid_max = 1024;

        errors_.push_back(BlockAccurateHandler::Error(reg, eidv ? errorid : global_errorid_max++, tmp_cf,
                                                      ((etiss::uintMax)1) << tmp_f));

        std::cout << reg << ": Error ";
        if (eidv)
        {
            std::cout << errorid << " ";
        }
        std::cout << "scheduled for time (ps)" << tmp_cf << "; bit " << tmp_f << std::endl;
    }

    errors_.sort(etiss_BlockAccurateHandler_cmp);

    if (!errors_.empty())
    {
        next_time_ps = errors_.front().time_ps;
    }
    else
    {
        next_time_ps = static_cast<etiss::uint64>(-1);
    }
}

std::string BlockAccurateHandler::_getPluginName() const
{
    return "BlockAccurateHandler";
}

void BlockAccurateHandler::init(ETISS_CPU *cpu_, ETISS_System *system_, etiss::CPUArch *arch_)
{
    cpu = cpu_;
    system = system_;
    arch = arch_;
}
void BlockAccurateHandler::cleanup()
{
    cpu = nullptr;
    system = nullptr;
    arch = nullptr;
}
