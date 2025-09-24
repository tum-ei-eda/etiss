// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#include "etiss/interfaces/VCD.h"

namespace etiss
{
namespace interfaces
{

/// TODO efficient implementation
static std::string val2str(uint64_t val, unsigned width, uint64_t udef)
{
    if (width == 1)
    {
        return (udef & 1) ? "x" : ((val & 1) ? "1" : "0");
    }
    else
    {
        char *ret = new char[width + 3];
        ret[0] = 'b';
        ret[width + 1] = ' ';
        ret[width + 2] = 0;
        for (unsigned i = 1; i < width + 1; i++)
        {
            ret[width + 1 - i] = (udef & 1) ? 'x' : ((val & 1) ? '1' : '0');
            val = val >> 1;
            udef = udef >> 1;
        }
        std::string r(ret);
        delete[] ret;
        return r;
    }
}

/**
        generated an identifier for the given index
*/
static std::string index2str(int index)
{
    std::string out;
    while (true)
    {
        out += static_cast<char>(index % 94) + 33;
        if (index < 94)
            break;
        index -= 94;
        index /= 94;
    }
    return out;
}

VCD::VCD(const std::string &file, const std::string &comment) : dumpstarted_(false), lasttime_ps(0), file(file)
{
    out_.open(file);
    valid_ = out_.is_open();

    if (!valid_)
    {
        etiss::log(etiss::WARNING, "Failed to open file for VCD output: " + file);
    }
    else
    {
        out_ << "$date\n"
                "	\n" /// TODO write date to vcd file
                "$end\n"
                "$version\n"
                "	ETISS " ETISS_VERSION_FULL "\n"
                "$end\n"
                "$comment\n"
             << comment
             << "\n"
                "$end\n"
                "$timescale 1ps $end\n"; /// TODO? variable time scale
    }

    dumpvar = "$enddefinitions $end\n$dumpvars\n";
}

VCD::~VCD()
{
    close();
}

void VCD::close()
{
    if (!valid_)
        return;
    valid_ = false;
    flush();
    out_.close();
}

bool VCD::declare(void *variable, const std::string &name, unsigned width, uint64_t initialvalue, uint64_t undefined)
{
    if (!valid_)
        return false;
    if (name.size() == 0)
    {
        etiss::log(etiss::ERROR, "Cannot call etiss::interfaces::VCD::declare without a name.", *this);
        return false;
    }
    if (dumpstarted_)
    {
        etiss::log(etiss::ERROR, "Cannot call etiss::interfaces::VCD::declare after dump started.", *this);
        return false;
    }
    if (sigs_.size() >= (94 + 94 * 94 + 94 * 94 * 94 + 94 * 94 * 94 * 94))
    {
        etiss::log(etiss::ERROR, "etiss::interfaces::VCD::declare called for more than supported variables.", *this);
        return false;
    }
    int checked_sig_size = static_cast<int>(sigs_.size());
    sigs_.emplace_back();
    Signal &sig = sigs_.back();

    sig.valid = false;
    sig.name = name;
    sig.value = initialvalue;
    sig.width = width;
    sig.ident = index2str(checked_sig_size - 1);
    sig.undefined = undefined;

    // declare signal
    {
        // split on dots and double quotes to get the submodules and enter their scopes
        std::list<std::string> vec_bd = etiss::split(name,
                                                     [](const std::string &str, size_t from, size_t &seplen)
                                                     {
                                                         size_t f1 = str.find(".", from);
                                                         size_t f2 = str.find("::", from);
                                                         seplen = f1 < f2 ? 1 : 2;
                                                         return f1 < f2 ? f1 : f2;
                                                     });
        std::vector<std::string> vec;
        vec.insert(vec.end(), vec_bd.begin(), vec_bd.end());
        if (vec.size() == 0)
            vec.push_back(name);
        for (size_t i = 1; i < vec.size(); i++)
        {
            out_ << "$scope module " << vec[i - 1] << " $end\n";
        }
        out_ << "$var wire " << width << " " << sig.ident << " " << vec[vec.size() - 1] << " $end\n";
        for (size_t i = 1; i < vec.size(); i++)
        {
            out_ << "$upscope $end\n";
        }
    }

    dumpvar = dumpvar + val2str(initialvalue, width, undefined) + sig.ident + "\n";

    ptr2index_.insert(std::make_pair(variable, (checked_sig_size - 1)));

    out_.flush();

    return true;
}
void VCD::update(uint64_t time_ps, void *variable, uint64_t value, uint64_t undefined)
{
    if (!valid_)
        return;
    if (time_ps < lasttime_ps)
    {
        etiss::log(etiss::ERROR, "etiss::interfaces::VCD::update called with decreased time value");
    }

    auto findex = ptr2index_.find(variable);
    if (findex != ptr2index_.end())
    {
        if (time_ps > lasttime_ps)
        {
            flush();
            lasttime_ps = time_ps;
        }
        int index = findex->second;
        Signal &sig = sigs_[index];
        sig.valid = true;
        sig.value = value;
        sig.undefined = undefined;
    }
    else
    {
        // not a declared vriable. ignore
    }
}
void VCD::flush()
{
    if (!valid_)
        return;
    dumpstarted_ = true;
    if (lasttime_ps == 0)
    {
        out_ << dumpvar;
        out_ << "$end\n"; // terminate dumpvars
    }
    bool empty = true;
    for (size_t i = 0; i < sigs_.size(); i++)
    {
        if (sigs_[i].valid)
        {
            empty = false;
            break;
        }
    }
    if (empty)
        return;
    out_ << "#" << lasttime_ps << "\n";
    for (size_t i = 0; i < sigs_.size(); i++)
    {
        Signal &s = sigs_[i];
        if (s.valid)
        {
            out_ << val2str(s.value, s.width, s.undefined) << s.ident << "\n";
            s.valid = false;
        }
    }
    // out_.flush();
}

} // namespace interfaces
} // namespace etiss
