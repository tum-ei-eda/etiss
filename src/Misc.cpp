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
 * @file
 *
 * @brief implements etiss/Misc.h
 *
 * @detail
 */

#define _CRT_SECURE_NO_WARNINGS 1

#include "etiss/Misc.h"
#include "etiss/Memory.h"

#include <cstring>
#include <iterator>
#include <regex>
#include <string>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace etiss;

std::string etiss::toString(const Verbosity &val)
{
    switch (val)
    {
    case SILENT:
        return "General";
    case FATALERROR:
        return "Fatal Error";
    case ERROR:
        return "Error";
    case WARNING:
        return "Warning";
    case INFO:
        return "Info";
    case VERBOSE:
        return "Verbose";
    default:
        return "INVALID_VERBOSITY_LEVEL";
    }
}

std::list<std::string> etiss::split(
    const std::string &str,
    std::function<size_t(const std::string & /**<str*/, size_t /**<from*/, size_t & /**<seperatorsize*/)> findsplit)
{
    std::list<std::string> ret;
    size_t find = 0;
    while (true)
    {
        size_t sepsize = std::string::npos;
        size_t tmpfind = findsplit(str, find, sepsize);
        if (tmpfind >= find && tmpfind != std::string::npos)
        {
            ret.push_back(str.substr(find, tmpfind - find));
            find = tmpfind + sepsize;
        }
        else
        {
            if (str.size() > find)
            {
                ret.push_back(str.substr(find));
            }
            break;
        }
    }
    return ret;
}

Verbosity etiss_verbosity = etiss::INFO; /// verbosity level variable

Verbosity &etiss::verbosity()
{
    return etiss_verbosity;
}

void etiss::log(Verbosity level, std::string msg)
{
    if (level <= etiss_verbosity)
    {
        std::cout << "ETISS: " << etiss::toString(level) << ": " << msg << std::endl;
    }
    if (level == FATALERROR)
    {
        abort();
    }
}
void etiss::logC(Verbosity level, std::function<std::string(void)> msgGen)
{
    if (level <= etiss_verbosity)
    {
        etiss::log(level, msgGen());
    }
}

std::vector<std::string> etiss::parseCommands(const std::string &cmdline)
{

    std::vector<std::string> ret;

    std::string tmp;
    unsigned state = 0;
    for (unsigned pos = 0; pos < cmdline.length(); pos++)
    {
        while (true)
        {
            switch (state)
            {
            case 0:
                switch (cmdline[pos])
                {
                case '\'':
                case '\"':
                    state = 1;
                case ' ':
                case '\t':
                    break;
                default:
                    state = 2;
                    continue;
                }
                break;
            case 1:
                switch (cmdline[pos])
                {
                case '\'':
                case '\"':
                    ret.push_back(tmp);
                    tmp = "";
                    state = 0;
                    break;
                case '\\':
                    if (pos + 1 < cmdline.length())
                    {
                        pos++;
                        tmp = tmp + cmdline[pos];
                    }
                    break;
                default:
                    tmp = tmp + cmdline[pos];
                    break;
                }
                break;
            case 2:
                switch (cmdline[pos])
                {
                case ' ':
                case '\t':
                    ret.push_back(tmp);
                    tmp = "";
                    state = 0;
                    break;
                case '\\':
                    if (pos + 1 < cmdline.length())
                    {
                        pos++;
                        tmp = tmp + cmdline[pos];
                    }
                    break;
                default:
                    tmp = tmp + cmdline[pos];
                    break;
                }
                if (pos + 1 >= cmdline.length())
                {
                    ret.push_back(tmp);
                    tmp = "";
                }
                break;
            default:
                std::cerr << "ERROR: etiss::parseCommand(1) parser failed" << std::endl;
                break;
            }
            break;
        }
    }

    return ret;
}

etiss::Configuration::Configuration() {}
etiss::Configuration::Configuration(std::string args)
{
    std::vector<std::string> vec = etiss::parseCommands(args);
    std::list<std::string> list;
    list.insert(list.end(), vec.begin(), vec.end());
    set(list);
}
static bool etiss_cfg_inConstructor = false;
etiss::Configuration::Configuration(const std::list<std::string> &args)
{
    if (etiss_cfg_inConstructor)
    {
        set(args);
    }
}

std::map<std::string, std::string> &etiss::Configuration::config()
{
    return cfg_;
}

namespace etiss
{

template <>
std::string Configuration::get<std::string>(const std::string &key, std::string default_, bool *default_used)
{
    {
        std::lock_guard<std::mutex> lock(mu_);
        auto find = cfg_.find(key);
        if (find != cfg_.end())
        {
            if (default_used)
                *default_used = false;
            return find->second;
        }
    }

    if (this != &etiss::cfg())
    { // use global config
        etiss::log(etiss::VERBOSE, std::string("using global configuration for key: ") + key);
        return etiss::cfg().get<std::string>(key, default_, default_used);
    }
    else
    {
        if (default_used)
            *default_used = true;
        return default_;
    }
}

template <>
bool Configuration::get<bool>(const std::string &key, bool default_, bool *default_used)
{
    std::string val = get<std::string>(key, default_ ? "true" : "false", default_used);
    /// @todo add compile flag to switch between c++11 and c++0x implementation
    /* c++11 only
    std::regex rtrue("(\\s*[tT][rR][uU][eE]\\s*)|(\\s*[1-9][0-9]*\\s*)|(\\s*[oO][nN]\\s*)");
    std::regex rfalse("(\\s*[fF][aA][lL][sS][eE]\\s*)|(\\s*0+\\s*)|(\\s*[oO][fF][fF]\\s*)");
    if (std::regex_match(val.begin(),val.end(),rtrue)){
      return true;
    }
    if (std::regex_match(val.begin(),val.end(),rfalse)){
      return false;
    }
    */

    // c++0x
    if (val == "true" || val == "1" || val == "on")
    {
        return true;
    }

    if (val == "false" || val == "0" || val == "off")
    {
        return false;
    }

    etiss::log(etiss::VERBOSE, std::string("failed to parse value (") + val + ") of configuration key (" + key + ").");
    return default_;
}

template <>
int Configuration::get<int>(const std::string &key, int default_, bool *default_used)
{
    std::string val = get<std::string>(key, toString(default_), default_used);
    try
    {
        return std::stoi(val, 0, 0); // see doc of std::stoi for last 0 parameter
    }
    catch (...)
    {
        if (default_used)
            *default_used = true;
        etiss::log(etiss::VERBOSE,
                   std::string("failed to parse value (") + val + ") of configuration key (" + key + ").");
        return default_;
    }
}

template <>
unsigned Configuration::get<unsigned>(const std::string &key, unsigned default_, bool *default_used)
{
    std::string val = get<std::string>(key, toString(default_), default_used);
    try
    {
        return static_cast<unsigned>(std::stoull(val, 0, 0)); // see doc of std::stoull for last 0 parameter
    }
    catch (...)
    {
        if (default_used)
            *default_used = true;

        etiss::log(etiss::VERBOSE,
                   std::string("failed to parse value (") + val + ") of configuration key (" + key + ").");
        return default_;
    }
}
template <>
uint64_t Configuration::get<uint64_t>(const std::string &key, uint64_t default_, bool *default_used)
{
    std::string val = get<std::string>(key, toString(default_), default_used);
    try
    {
        return std::stoull(val, 0, 0); // see doc of std::stoull for last 0 parameter
    }
    catch (...)
    {
        if (default_used)
            *default_used = true;

        etiss::log(etiss::VERBOSE,
                   std::string("failed to parse value (") + val + ") of configuration key (" + key + ").");
        return default_;
    }
}

} // end of namespace etiss

bool etiss::Configuration::debug()
{
    return get<bool>("debug", false);
}

void etiss::Configuration::remove(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mu_);
    if (final_.find(key) != final_.end())
        return;
    cfg_.erase(key);
}

bool etiss::Configuration::isSet(std::string key)
{
    std::lock_guard<std::mutex> lock(mu_);
    return cfg_.find(key) != cfg_.end();
}

std::list<std::string> etiss::Configuration::set(const std::list<std::string> &args)
{
    std::list<std::string> ret;
    for (auto iter = args.begin(); iter != args.end(); iter++)
    {
        const std::string &p = *iter;
        bool used = false;
        if (p.length() > 2)
        {
            if (p[0] == '-' && p[1] == 'f')
            {
                used = true;

                size_t epos = p.find_first_of('=');

                if (p.length() > 5 && p[2] == 'n' && p[3] == 'o' && p[4] == '-')
                {
                    if (epos == std::string::npos)
                    {
                        std::string tmp = p.substr(5);
                        if (isSet(tmp))
                            etiss::log(etiss::WARNING, "CONFIG " + tmp + " already set. Overwriting it to false.");
                        set<std::string>(tmp, "false");
                        etiss::log(etiss::VERBOSE, std::string("CONFIG: set ") + tmp + " to false");
                    }
                    else
                    { // unusual case. assuming option shall be erased. value after '=' is ignored
                        std::string tmp = p.substr(5, epos - 5);
                        remove(tmp);
                        etiss::log(etiss::VERBOSE, std::string("CONFIG: removed ") + tmp);
                    }
                }
                else
                {
                    if (epos == std::string::npos)
                    {
                        std::string tmp = p.substr(2);
                        if (isSet(tmp))
                            etiss::log(etiss::WARNING, "CONFIG " + tmp + " already set. Overwriting it to true.");
                        set<std::string>(tmp, "true");
                        etiss::log(etiss::VERBOSE, std::string("CONFIG: set ") + tmp + " to true");
                    }
                    else
                    {
                        std::string tmp = p.substr(2, epos - 2);
                        std::string tval = p.substr(epos + 1);
                        if (isSet(tmp))
                            etiss::log(etiss::WARNING, "CONFIG " + tmp + " already set. Overwriting it to " + tval);
                        set<std::string>(tmp, tval);
                        etiss::log(etiss::VERBOSE, std::string("CONFIG: set ") + tmp + " to " + tval);
                    }
                }
            }
            if (p[0] == '-' && p[1] == 'o')
            {
                used = true;
                std::string tmp = p.substr(2);
                iter++;
                if (iter != args.end())
                {
                    if (isSet(tmp))
                        etiss::log(etiss::WARNING, "CONFIG " + tmp + " already set. Overwriting it to " + *iter);
                    set<std::string>(tmp, *iter);
                }
                else
                {
                    etiss::log(etiss::WARNING, std::string("Expected option value after " + p));
                }
            }
        }
        if (!used)
        {
            ret.push_back(p);
        }
    }
    return ret;
}

std::map<std::string, std::string> etiss::Configuration::listFullConfiguration()
{
    if (this != &etiss::cfg())
    {
        std::map<std::string, std::string> ret = etiss::cfg().cfg_; // copy global config

        // apply local config
        for (auto iter = cfg_.begin(); iter != cfg_.end(); iter++)
        {
            ret[iter->first] = iter->second;
        }

        return ret;
    }
    else
    {
        return cfg_;
    }
}

void etiss::Configuration::makeFinal(const std::string &key)
{
    std::lock_guard<std::mutex> lock(mu_);
    final_.insert(key);
}

void etiss::Configuration::announce(std::string key, std::string type, std::string values, std::string description)
{
    std::lock_guard<std::mutex> lock(mu_);
    announced_[key] = std::tuple<std::string, std::string, std::string>(type, values, description);
}

std::map<std::string, std::tuple<std::string, std::string, std::string>> etiss::Configuration::getAnnounced() const
{
    std::lock_guard<std::mutex> lock(mu_);
    return announced_;
}

etiss::Configuration &etiss::cfg(const std::string &cfgName)
{
    std::string cfgName_ = cfgName;
    if (cfgName.empty())
    {
        etiss::log(etiss::WARNING, "Config name is empty take global!");
        cfgName_ = "global";
    }
    etiss_cfg_inConstructor = true;
    static std::map<std::string, etiss::Configuration> cfg;
    if (cfg.find(cfgName_) == cfg.end())
    {
        etiss::log(etiss::INFO, std::string("Created new config container: ") + cfgName_);
    }
    etiss_cfg_inConstructor = false;
    return cfg[cfgName_];
}
etiss::Configuration &etiss::cfg()
{
    std::string cfgName = "global";
    return etiss::cfg(cfgName);
}

std::string etiss::installDir()
{
    auto etissLib = GetCurrentModulePath();
    auto libPathLoc = etissLib.find_last_of("/\\");
    auto libPath = etissLib.substr(0, libPathLoc);
    auto etissPathLoc = libPath.find_last_of("/\\");
    return libPath.substr(0, etissPathLoc);
}

std::string etiss::jitFiles()
{
    return installDir() + "/include/jit";
}

std::vector<std::string> etiss::jitExtHeaders(){
    std::vector<std::string> x;
    std::string range = cfg().get<std::string>("JIT-External::Headers", "");
    boost::split(x, range, boost::is_any_of(" "));
    return (x);
}

std::vector<std::string> etiss::jitExtLibraries(){
    std::vector<std::string> x;
    std::string range = cfg().get<std::string>("JIT-External::Libs", "");
    boost::split(x, range, boost::is_any_of(" "));
    return (x);
}

std::vector<std::string> etiss::jitExtHeaderPaths(){
    std::vector<std::string> x;
    std::string range = cfg().get<std::string>("JIT-External::HeaderPaths", "");
    boost::split(x, range, boost::is_any_of(" "));
    return (x);
}

std::vector<std::string> etiss::jitExtLibPaths(){
    std::vector<std::string> x;
    std::string range = cfg().get<std::string>("JIT-External::LibPaths", "");
    boost::split(x, range, boost::is_any_of(" "));
    return (x);
}

// IMPORTANT: check if fpu configuration matches endianness
#include "etiss/fpu/386-GCC.h"
#if ETISS_USE_CONSTEXPR
#ifdef LITTLEENDIAN
static_assert(getEndianness() == etiss::_LITTLE_ENDIAN_,
              "ETISS detected an invalid endianness configuartion of the floating point library. please change in the "
              "file etiss/fpu/386-GCC.h the line #define LITTLEENDIAN (or similar) to #define BIGENDIAN");
#endif
#ifdef BIGENDIAN
static_assert(getEndianness() == etiss::_BIG_ENDIAN_,
              "ETISS detected an invalid endianness configuartion of the floating point library. please change in the "
              "file etiss/fpu/386-GCC.h the line #define BIGENDIAN (or similar) to #define LITTLEENDIAN");
#endif
#else
#pragma message("ETISS cannot check if endianess is configured correctly due to missing constexpr support")
#endif
