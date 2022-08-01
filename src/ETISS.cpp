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
        @file ETISS.cpp
        @brief Implementation of etiss/ETISS.h except for
   etiss::preloadLibraries
        @detail
*/

#include "etiss/ETISS.h"
#include "etiss/fault/Stressor.h"

#include <csignal>
#include <cstring>
#include <fstream>
#include <functional>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/algorithm/string.hpp>

#if ETISS_USE_DLSYM
#include <dlfcn.h>
#endif

using namespace etiss;

std::string etiss_defaultjit_;

std::list<std::shared_ptr<etiss::LibraryInterface>> etiss_libraries_;
std::recursive_mutex etiss_libraries_mu_;

boost::program_options::variables_map vm;
std::vector<std::string> pluginOptions = {"plugin.logger.logaddr", "plugin.logger.logmask", "plugin.gdbserver.port"};

std::set<std::string> etiss::listCPUArchs()
{
    std::set<std::string> ret;
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        if ((*iter).get() != 0)
        {
            if (!(*iter)->isEmpty())
            {
                for (unsigned i = 0; i < (*iter)->countCPUArchs(); i++)
                {
                    std::string jit = (*iter)->nameCPUArch(i);
                    if (ret.find(jit) != ret.end())
                    {
                        etiss::log(etiss::ERROR, "CPUArch provided by multiple libraries: \"" + jit + "\"");
                    }
                    else
                    {
                        ret.insert(jit);
                    }
                }
            }
        }
    }
    return ret;
}

std::set<std::string> etiss::listJITs()
{
    std::set<std::string> ret;
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        if ((*iter).get() != 0)
        {
            if (!(*iter)->isEmpty())
            {
                for (unsigned i = 0; i < (*iter)->countJITs(); i++)
                {
                    std::string jit = (*iter)->nameJIT(i);
                    if (ret.find(jit) != ret.end())
                    {
                        etiss::log(etiss::ERROR, "JIT provided by multiple libraries: \"" + jit + "\"");
                    }
                    else
                    {
                        ret.insert(jit);
                    }
                }
            }
        }
    }
    return ret;
}

std::set<std::string> etiss::listPlugins()
{
    std::set<std::string> ret;
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        if ((*iter).get() != 0)
        {
            if (!(*iter)->isEmpty())
            {
                for (unsigned i = 0; i < (*iter)->countPlugins(); i++)
                {
                    std::string jit = (*iter)->namePlugin(i);
                    if (ret.find(jit) != ret.end())
                    {
                        etiss::log(etiss::ERROR, "JIT provided by multiple libraries: \"" + jit + "\"");
                    }
                    else
                    {
                        ret.insert(jit);
                    }
                }
            }
        }
    }
    return ret;
}

std::shared_ptr<JIT> etiss::getJIT(std::string name, std::map<std::string, std::string> options)
{
    std::shared_ptr<JIT> jit;
    std::string ujit;
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        std::shared_ptr<LibraryInterface> lib = *iter;
        if (lib.get() != 0)
        {
            if (!lib->isEmpty())
            {
                for (unsigned i = 0; i < lib->countJITs(); i++)
                {
                    if (lib->nameJIT(i) == name)
                    {
                        if (jit.get() != 0)
                        {
                            etiss::log(etiss::ERROR, "JIT provided by multiple libraries: using \"" + name +
                                                         "\" from library \"" + ujit +
                                                         "\" [also provided by library \"" + lib->getName() + "\"]");
                        }
                        else
                        {
                            etiss::JIT *ca = lib->createJIT(i, options);
                            if (ca == 0)
                            {
                                etiss::log(etiss::ERROR,
                                           "Failed to create JIT via library interface \"" + lib->getName() + "\"");
                            }
                            else
                            {
                                jit = std::shared_ptr<JIT>(ca, [lib](JIT *j) { lib->deleteJIT(j); });
                                ujit = lib->getName();
                            }
                        }
                    }
                }
            }
        }
    }
    return jit;
}

std::shared_ptr<CPUArch> etiss::getCPUArch(std::string name, std::map<std::string, std::string> options)
{
    std::shared_ptr<CPUArch> arch;
    std::string uarch;
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        std::shared_ptr<LibraryInterface> lib = *iter;
        if (lib.get() != 0)
        {
            if (!lib->isEmpty())
            {
                for (unsigned i = 0; i < lib->countCPUArchs(); i++)
                {
                    if (lib->nameCPUArch(i) == name)
                    {
                        if (arch.get() != 0)
                        {
                            etiss::log(etiss::ERROR, "CPU Architecture provided by multiple libraries: using \"" +
                                                         name + "\" from library \"" + uarch +
                                                         "\" [also provided by library \"" + lib->getName() + "\"]");
                        }
                        else
                        {
                            etiss::CPUArch *ca = lib->createCPUArch(i, options);
                            if (ca == 0)
                            {
                                etiss::log(etiss::ERROR,
                                           "Failed to create CPUArch via library interface \"" + lib->getName() + "\"");
                            }
                            else
                            {
                                arch = std::shared_ptr<CPUArch>(ca, [lib](CPUArch *a) { lib->deleteCPUArch(a); });
                                uarch = lib->getName();
                            }
                        }
                    }
                }
            }
        }
    }
    return arch;
}

std::shared_ptr<Plugin> etiss::getPlugin(std::string name, std::map<std::string, std::string> options)
{
    std::shared_ptr<Plugin> ptrPlugin;
    std::string strPluginName;
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        std::shared_ptr<LibraryInterface> lib = *iter;
        if (lib.get() != 0)
        {
            if (!lib->isEmpty())
            {
                for (unsigned i = 0; i < lib->countPlugins(); i++)
                {
                    if (lib->namePlugin(i) == name)
                    {
                        if (ptrPlugin.get() != 0)
                        {
                            etiss::log(etiss::ERROR, "Plugin provided by multiple libraries: using \"" + name +
                                                         "\" from library \"" + strPluginName +
                                                         "\" [also provided by library \"" + lib->getName() + "\"]");
                        }
                        else
                        {
                            etiss::Plugin *ca = lib->createPlugin(i, options);
                            if (ca == 0)
                            {
                                etiss::log(etiss::ERROR,
                                           "Failed to create Plugin via library interface \"" + lib->getName() + "\"");
                            }
                            else
                            {
                                ptrPlugin = std::shared_ptr<Plugin>(ca, [lib](Plugin *p) { lib->deletePlugin(p); });
                                strPluginName = lib->getName();
                                etiss::log(etiss::INFO, "Plugin \"" + name + "\" loaded via library interface \"" +
                                                            strPluginName + "\"\n");
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return ptrPlugin;
}

bool etiss::loadLibrary(std::string path, std::string name)
{
    auto lib = etiss::LibraryInterface::openSharedLibrary(path, name);

    if (lib.get())
    {
        addLibrary(lib);
        return true;
    }

    return false;
}

void etiss::addLibrary(std::shared_ptr<etiss::LibraryInterface> libInterface)
{
    etiss::LibraryInterface *lif = libInterface.get();

    if (lif == 0)
    {
        return;
    }

    etiss::forceInitialization();

    {
        std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
        etiss_libraries_.push_back(libInterface);
    }
    // if no default jit is present, try to use one from this library
    for (unsigned i = 0; (etiss_defaultjit_.size() <= 0) && (i < libInterface->countJITs()); i++)
    {
        etiss_defaultjit_ = libInterface->nameJIT(i);
    }
}
std::set<std::string> etiss::listLibraries()
{
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    std::set<std::string> ret;
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        ret.insert((*iter)->getName() + "[" + (*iter)->versionInfo() + "]");
    }
    return ret;
}

std::set<std::string> etiss::listLibraryPrefixes()
{
    std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    std::set<std::string> ret;
    for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
    {
        ret.insert((*iter)->getName());
    }
    return ret;
}

std::shared_ptr<etiss::JIT> etiss::getDefaultJIT()
{
    return getJIT(etiss_defaultjit_);
}

// transfer controll to etiss console on SIGINT
void (*etiss_prev_SIGINT_handler)(int) = 0;
bool etiss_SIGINT_handler_enabled = false;

void etiss_SIGINT_handler(int sig)
{
    if (sig == SIGINT)
    {
        std::cout << std::endl << "\033[0;31m" << std::endl;
        /// TODO etiss::transferCMDControll();
        std::cout << std::endl << "\033[0m" << std::endl;
    }
    else
    { // false handler assignment
        signal(sig, SIG_DFL);
        raise(sig);
        return;
    }
}

//__attribute__((destructor))
static void etiss_remove_SIGINT()
{
    if (etiss_SIGINT_handler_enabled)
    {
        etiss_prev_SIGINT_handler = signal(SIGINT, etiss_prev_SIGINT_handler);
        etiss_SIGINT_handler_enabled = false;
    }
}
/// replaces __attribute__((destructor)) in a portable way
static class helper_class_etiss_2
{
  public:
    ~helper_class_etiss_2() { etiss_remove_SIGINT(); }
} helper_class_etiss_2;

// initialize
CSimpleIniA *po_simpleIni;
void etiss_loadIni(std::string fileName)
{
    if (po_simpleIni == NULL)
        po_simpleIni = new CSimpleIniA(true, true, true);

    SI_Error rc = po_simpleIni->LoadFile(fileName.c_str());
    if (rc < 0)
        std::cout << "Initializer::loadIni(): Failed to load Ini: " << fileName << std::endl;
    else
        std::cout << "Initializer::loadIni(): Ini sucessfully loaded " << fileName << std::endl;
}

void etiss::Initializer::loadIni(std::list<std::string> *files)
{
    std::cout << "  Load ini file." << std::endl;
    // create ini parser
    if (po_simpleIni == NULL)
        po_simpleIni = new CSimpleIniA(true, true, true);
    else
        std::cout << "Info: simpleIni already exists!" << std::endl;

    // load file
    for (auto it_files : *files)
    {
        // the check above is sufficient no need for this / checked for previous cases false and last true gives true not the case based on files structure
        etiss_loadIni(it_files);
    }
}

void etiss_loadIniConfigs()
{
    if (!po_simpleIni) // no .ini files were given.
    {
        return;
    }
    std::cout << "  Load Configs from .ini files:" << std::endl;

    // preload loglevel
    if (!etiss::cfg().isSet("etiss.loglevel"))
    {
        etiss::cfg().set<int>("etiss.loglevel", po_simpleIni->GetLongValue("IntConfigurations", "etiss.loglevel", etiss::WARNING));
    }
    {
        int ll = cfg().get<int>("etiss.loglevel", etiss::WARNING);
        if (ll >= 0 && ll <= etiss::VERBOSE)
        { // valid log level
          // dnm
            // etiss::verbosity() = etiss::VERBOSE;
            etiss::verbosity() = (Verbosity)ll;
            etiss::log(etiss::VERBOSE, "Log level set to VERBOSE");
        }
        else
        {
            etiss::verbosity() = etiss::WARNING;
            etiss::log(etiss::ERROR, "Specified log level is not valid. must range between 0 (= "
                                     "silent) and 5 (= verbose)");
        }
    }

    // get all sections
    CSimpleIniA::TNamesDepend sections;
    po_simpleIni->GetAllSections(sections);
    for (auto iter_section : sections)
    {
        // only load config sections
        if (std::string(iter_section.pItem) != "StringConfigurations" &&
            std::string(iter_section.pItem) != "BoolConfigurations" &&
            std::string(iter_section.pItem) != "IntConfigurations")
        {
            continue;
        }
        etiss::log(etiss::INFO, std::string("  [") + iter_section.pItem + ']');

        // get all keys in a section
        CSimpleIniA::TNamesDepend keys;
        po_simpleIni->GetAllKeys(iter_section.pItem, keys);
        for (auto iter_key : keys)
        {
            std::stringstream message;
            bool warning = false;

            // skip loglevel
            if (std::string(iter_key.pItem) == "etiss.loglevel")
                continue;

            // check if cfg is already set
            if (etiss::cfg().isSet(iter_key.pItem))
            {
                message << "    cfg already set on command line. ";
                message << "    " << iter_key.pItem << "=";
                const ::std::type_info& type = vm[std::string(iter_key.pItem)].value().type() ;
                if (type == typeid(::std::string))
                    message << vm[std::string(iter_key.pItem)].as<std::string>() << ",";
                else if (type == typeid(int))
                    message << vm[std::string(iter_key.pItem)].as<int>() << ",";
                else if (type == typeid(bool))
                    message << std::boolalpha << vm[std::string(iter_key.pItem)].as<bool>() << ",";
                warning = true;
            }
            else
            {
                // write key (=option) to message.
                message << "    " << iter_key.pItem << "=";

                // get all values of a key with multiple values
                CSimpleIniA::TNamesDepend values;
                po_simpleIni->GetAllValues(iter_section.pItem, iter_key.pItem, values);
                for (auto iter_value : values)
                {
                    // Handle configurations
                    if (std::string(iter_section.pItem) == "StringConfigurations")
                    {
                        etiss::cfg().set<std::string>(iter_key.pItem, iter_value.pItem);
                    }
                    else if (std::string(iter_section.pItem) == "BoolConfigurations")
                    {
                        std::string itemval = iter_value.pItem;
                        boost::algorithm::to_lower(itemval); // converts itemval to lower case string
                        bool val;

                        if ((itemval == "true") | (itemval == "yes") | (itemval == "1") | (itemval == "t")) val = true;
                        else if ((itemval == "false") | (itemval == "no") | (itemval == "0") | (itemval == "f")) val = false;
                        else etiss::log(etiss::FATALERROR, std::string("Configuration value ") + iter_key.pItem + " could not be parsed as boolean");

                        etiss::cfg().set<bool>(iter_key.pItem, val);
                    }
                    else if (std::string(iter_section.pItem) == "IntConfigurations") // already load!
                    {
                        std::string itemval = iter_value.pItem;
                        std::size_t sz = 0;
                        long long val;
                        try {
                            val = std::stoll(itemval, &sz, 0);
                        }
                        // catch invalid_argument exception.
                        catch (std::invalid_argument const&){
                            etiss::log(etiss::FATALERROR, std::string("Configuration value ") + iter_key.pItem + " could not be parsed as integer");
                        }
                        etiss::cfg().set<long long>(iter_key.pItem, val);
                        // we use double, as long could have only 32 Bit (e.g. on Windows)
                        // and long long is not offered by the ini library
                    }
                    else
                    // we don't add a DoubleConfigurations section, as converting them
                    // to and from strings could provoke accuracy issues.
                    // To support double, a Configuration::get<double>() has to be
                    // added to Misc.cpp
                    {
                        message << "   Section not found  for Value:";
                        warning = true;
                    }

                    // write item (=option value) to message.
                    message << iter_value.pItem << ",";
                }

                // check if more than one value is set in the ini file
                if (values.size() > 1)
                {
                    warning = true;
                        message << "   Multi values. Take only LAST one!";
                }
            }
            // add message to etiss log.
            etiss::log(warning ? etiss::WARNING : etiss::INFO, message.str());
        }
    }
}

void etiss::Initializer::loadIniPlugins(std::shared_ptr<etiss::CPUCore> cpu)
{
    std::map<std::string, std::string> options;
    for (auto iter = pluginOptions.begin(); iter != pluginOptions.end(); iter++)
    {
        if (etiss::cfg().isSet(*iter))
        {
            options[*iter] = std::string(vm[std::string(*iter)].as<std::string>());
            etiss::log(etiss::INFO, *iter + " written from command line\n" + "               options[" +
                                        std::string(*iter) +
                                        "] = " + std::string(vm[std::string(*iter)].as<std::string>()) + "\n");
        }
    }
    if (vm.count("pluginToLoad"))
    {
        const std::vector<std::string> pluginList = vm["pluginToLoad"].as<std::vector<std::string>>();
        for (auto pluginName = pluginList.begin(); pluginName != pluginList.end(); pluginName++)
        {
            std::string::size_type pos = std::string(*pluginName).length();
            bool pluginAlreadyPresent = false;
            for (auto iter : *cpu->getPlugins())
            {
                std::string pluginNamecpu = iter->getPluginName();
                if (pos != std::string::npos)
                {
                    pluginNamecpu = pluginNamecpu.substr(0, pos);
                }
                if (pluginNamecpu == *pluginName)
                {
                    pluginAlreadyPresent = true;
                    break;
                }
            }
            if (pluginAlreadyPresent)
            {
                etiss::log(etiss::WARNING, "    Warning: Plugin already present. Skipping it: " + *pluginName + "\n");
                continue;
            }
            etiss::log(etiss::INFO, "  Adding Plugin " + *pluginName + "\n");
            cpu->addPlugin(etiss::getPlugin(*pluginName, options));
        }
    }
    if (!po_simpleIni)
    {
        etiss::log(etiss::WARNING, "Ini file not loaded. Can't load plugins from simpleIni!");
        return;
    }
    // get all sections
    CSimpleIniA::TNamesDepend sections;
    po_simpleIni->GetAllSections(sections);
    for (auto iter_section : sections)
    {
        // only load Plugin sections
        if (std::string(iter_section.pItem).substr(0, 6) != std::string("Plugin"))
            continue;
        std::string pluginName = std::string(iter_section.pItem).substr(7);
        std::string::size_type pos = pluginName.length();
        // check if Plugin is already present
        bool pluginAlreadyPresent = false;
        for (auto iter : *cpu->getPlugins())
        {
            std::string pluginNamecpu = iter->getPluginName();
            if (pos != std::string::npos)
            {
                pluginNamecpu = pluginNamecpu.substr(0, pos);
            }
            if (pluginNamecpu == pluginName)
            {
                pluginAlreadyPresent = true;
                break;
            }
        }
        if (pluginAlreadyPresent)
        {
            etiss::log(etiss::WARNING, "    Warning: Plugin already present. Skipping it: " + pluginName + "\n");
            continue;
        }

        etiss::log(etiss::INFO, "  Adding Plugin " + pluginName + "\n");

        // get all keys in a section = plugin option
        CSimpleIniA::TNamesDepend keys;
        po_simpleIni->GetAllKeys(iter_section.pItem, keys);
        for (auto iter_key : keys)
        {
            // get all values of a key with multiple values = value of option
            CSimpleIniA::TNamesDepend values;
            po_simpleIni->GetAllValues(iter_section.pItem, iter_key.pItem, values);
            if (!etiss::cfg().isSet(iter_key.pItem))
            {
                std::stringstream ss;
                ss << iter_key.pItem << " not set on the command line. Checking in .ini file.";
                etiss::log(etiss::INFO, ss.str());

                for (auto iter_value : values)
                {
                    options[iter_key.pItem] = iter_value.pItem;
                    etiss::log(etiss::INFO,
                            "    options[" + std::string(iter_key.pItem) + "] = " + std::string(iter_value.pItem) + "\n\n");
                }
                // check if more than one value is set in the ini file
                if (values.size() > 1)
                    etiss::log(etiss::WARNING, "Multiple values for option. Took only last one!");
            }
        }
        cpu->addPlugin(etiss::getPlugin(pluginName, options));
    }
}

void etiss::Initializer::loadIniJIT(std::shared_ptr<etiss::CPUCore> cpu)
{
    // check if JIT is set
    if (!etiss::cfg().isSet("jit.type"))
    {
        etiss::log(etiss::INFO, "No JIT configured. Will use default JIT. \n");
        cpu->set(etiss::getDefaultJIT());
        return;
    }
    if (cpu->getJITName() != "")
    {
        etiss::log(etiss::WARNING,
                    "etiss::Initializer::loadIniJIT:" + std::string(" JIT already present. Overwriting it."));
    }
    etiss::log(etiss::INFO, " Adding JIT \"" + cfg().get<std::string>("jit.type", "") + '\"');
    cpu->set(getJIT(cfg().get<std::string>("jit.type", "")));
}

std::pair<std::string, std::string> inifileload(const std::string& s)
{
    if (s.find("-i") == 0)
    {
        std::string inifile;
        inifile = s.substr(2);
        etiss_loadIni(inifile);
    }
    return make_pair(std::string(), std::string());
}

void etiss_initialize(const std::vector<std::string>& args, bool forced = false)
{
    static std::mutex mu_;
    static bool initialized_(false);
    {
        std::lock_guard<std::mutex> lock(mu_);
        if (initialized_)
        {
            if (!forced)
            {
                etiss::log(etiss::WARNING, "Multiple calls to etiss::initialize");
            }
            else
            {
                return;
            }
        }
        else
        {
            if (forced)
            {
                etiss::log(etiss::WARNING, "etiss::initialize has not been called before using ETISS library "
                                           "functions. Please add the line \'etiss::initialize(argc,argv);\' "
                                           "at the beginning of \'int main(int argc, char**argv);\'");
            }
        }
        initialized_ = true;
    }

    {
        namespace po = boost::program_options;
        try
        {
            po::options_description desc("Allowed options");
            desc.add_options()
            ("help", "Produce a help message that lists all supported options.")
            ("arch.cpu", po::value<std::string>(), "The CPU Architecture to simulate.")
            ("arch.or1k.ignore_sr_iee", po::value<bool>(), "Ignore exception on OpenRISC.")
            ("arch.or1k.if_stall_cycles", po::value<int>(), "Add instruction stall cycles on OpenRISC.")
            ("arch.cpu_cycle_time_ps", po::value<int>(), "Sets CPU cycles time on OpenRISC and ARM.")
            ("arch.enable_semihosting", po::value<bool>(), "Enables semihosting operations")
            ("etiss.enable_dmi", po::value<bool>(), "Enables the Direct Memory Interface feature of SystemC to speed up memory accesses. This needs to be disabled for memory tracing.")
            ("etiss.log_pc", po::value<bool>(), "Enables logging of the program counter.")
            ("etiss.max_block_size", po::value<int>(), "Sets maximum amount of instructions in a block.")
            ("etiss.output_path_prefix", po::value<std::string>(), "Path prefix to use when writing output files.")
            ("etiss.loglevel", po::value<int>(), "Verbosity of logging output.")
            ("jit.gcc.cleanup", po::value<bool>(), "Cleans up temporary files in GCCJIT. ")
            ("jit.verify", po::value<bool>(), "Run some basic checks to verify the functionality of the JIT engine.")
            ("jit.debug", po::value<bool>(), "Causes the JIT Engines to compile in debug mode.")
            ("jit.type", po::value<std::string>(), "The JIT compiler to use.")
            ("jit.external_headers", po::value<std::string>(), "List of semicolon-separated paths to headers for the JIT to include.")
            ("jit.external_libs", po::value<std::string>(), "List of semicolon-separated library names for the JIT to link.")
            ("jit.external_header_paths", po::value<std::string>(), "List of semicolon-separated headers paths for the JIT.")
            ("jit.external_lib_paths", po::value<std::string>(), "List of semicolon-separated library paths for the JIT.")
            ("vp.sw_binary_ram", po::value<std::string>(), "Path to binary file to be loaded into RAM.")
            ("vp.sw_binary_rom", po::value<std::string>(), "Path to binary file to be loaded into ROM.")
            ("vp.elf_file", po::value<std::string>(), "Load ELF file.")
            ("vp.stats_file_path", po::value<std::string>(), "Path where the output json file gets stored after bare processor is run.")
            ("simple_mem_system.print_dbus_access", po::value<bool>(), "Traces accesses to the data bus.")
            ("simple_mem_system.print_ibus_access", po::value<bool>(), "Traces accesses to the instruction bus.")
            ("simple_mem_system.print_dbgbus_access", po::value<bool>(), "Traces accesses to the debug bus.")
            ("simple_mem_system.print_to_file", po::value<bool>(), "Write all tracing to a file instead of the terminal. The file will be located at etiss.output_path_prefix.")
            ("plugin.logger.logaddr", po::value<std::string>(), "Provides the compare address that is used to check for memory accesses that are redirected to the logger.")
            ("plugin.logger.logmask", po::value<std::string>(), "Provides the mask that is used to check for memory accesses that are redirected to the logger.")
            ("plugin.gdbserver.port", po::value<std::string>(), "Option for gdbserver")
            ("pluginToLoad,p", po::value<std::vector<std::string>>()->multitoken(), "List of plugins to be loaded.")
            ;

            po::command_line_parser parser{args};
            po::command_line_parser iniparser{args};
            iniparser.options(desc).allow_unregistered().extra_parser(inifileload).run();
            parser.options(desc).allow_unregistered().extra_parser(etiss::Configuration::set_cmd_line_boost);
            po::parsed_options parsed_options = parser.run();
            po::store(parsed_options, vm);

            if (vm.count("help"))
            {
                std::cout << "\nPlease begin all options with --\n\n";
                std::cout << desc << "\n";
                etiss::log(etiss::FATALERROR, std::string("Please choose the right configurations from the list and re-run.\n"));
            }

            auto unregistered = po::collect_unrecognized(parsed_options.options, po::include_positional);
            for (auto iter_unreg : unregistered)
            {
                if (iter_unreg.find("-i") != 0 && iter_unreg.find("-p"))
                {
                    etiss::log(etiss::FATALERROR, std::string("Unrecognised option ") + iter_unreg +
                                               "\n\t Please use --help to list all recognised options. \n");
                }
            }

            for (po::variables_map::iterator i = vm.begin() ; i != vm.end() ; ++ i)
            {
                const po::variable_value& v = i->second;
                if (!v.empty())
                {
                    const ::std::type_info& type = v.value().type();
                    if (type == typeid(::std::string))
                    {
                        const ::std::string& val = v.as<::std::string>() ;
                        etiss::cfg().set<std::string>(std::string(i->first), val);
                    }
                    else if (type == typeid(int))
                    {
                        int val = v.as<int>();
                        etiss::cfg().set<int>(std::string(i->first), val);
                    }
                    else if (type == typeid(bool))
                    {
                        bool val = v.as<bool>();
                        etiss::cfg().set<bool>(std::string(i->first), val);
                    }
                }
            }
        }
        catch(std::exception& e)
        {
            etiss::log(etiss::FATALERROR, std::string(e.what()) +
                                               "\n\t Please use --help to list all recognised options. \n");
        }
    }
    etiss_loadIniConfigs();

    // log level
    {
        int ll = cfg().get<int>("etiss.loglevel", etiss::WARNING);
        if (ll >= 0 && ll <= etiss::VERBOSE)
        { // valid log level
          // dnm
            // etiss::verbosity() = etiss::VERBOSE;
            etiss::verbosity() = (Verbosity)ll;
            etiss::log(etiss::VERBOSE, "Log level set to VERBOSE");
        }
        else
        {
            etiss::verbosity() = etiss::WARNING;
            etiss::log(etiss::ERROR, "Specified log level is not valid. must range between 0 (= "
                                     "silent) and 5 (= verbose)");
        }
    }

    etiss::py::init(); // init python

    etiss_remove_SIGINT();
    preloadLibraries();

    // load integrated library
    if (cfg().get<bool>("etiss.load_integrated_libraries", true))
    {
        etiss::addLibrary(LibraryInterface::openIntegratedLibrary());
    }

    // check if some required files can be found
    {
        std::string path = etiss::installDir();
        std::vector<std::string> requiredFiles;

        // required files
        requiredFiles.push_back(path + "/include/jit/etiss/jit/CPU.h");

        // check
        for (auto iter = requiredFiles.begin(); iter != requiredFiles.end(); iter++)
        {
            std::ifstream f(iter->c_str());
            if (!f)
            {
                etiss::log(etiss::WARNING, std::string("Could not find file: ") + *iter + "\n" +
                                               "\t The installation seems broken");
            }
        }
    }

    // load fault files
    {
        std::string faults = cfg().get<std::string>("faults.xml", "");
        if (!faults.empty())
        {
            std::list<std::string> ffs = etiss::split(faults, ';');
            for (auto ff : ffs)
            {
                etiss::fault::Stressor::loadXML(ff);
            }
        }
    }
}

void etiss::initialize(std::vector<std::string>& args)
{
    etiss_initialize(args, false);
}

void etiss::forceInitialization()
{
    std::vector<std::string> args{};
    etiss_initialize(args, true);
}

//__attribute__((destructor))
static void etiss_shutdown()
{
    etiss::shutdown(); // TODO: verify with spec. assuming shared library close
                       // after __attribute__((destructor)) functions have been
                       // called

    // force close open libraries
    //{
    //	std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
    //	etiss_libraries_.clear();
    //}
}
/// replaces __attribute__((destructor)) in a portable way
static class helper_class_etiss_1
{
  public:
    ~helper_class_etiss_1() { etiss_shutdown(); }
} helper_class_etiss_1;

bool etiss_shutdownOk = false;

void etiss::shutdown()
{
    if (etiss_shutdownOk) // only on shutdown
        return;

    etiss_shutdownOk = true;

    etiss::fault::Stressor::clear();

    // unload libraries
    {
        std::list<std::weak_ptr<LibraryInterface>> libraries_weak;
        {
            std::lock_guard<std::recursive_mutex> lock(etiss_libraries_mu_);
            for (auto iter = etiss_libraries_.begin(); iter != etiss_libraries_.end(); iter++)
            {
                libraries_weak.push_back(std::weak_ptr<LibraryInterface>(*iter));
            }
            etiss_libraries_.clear();
        }
        for (auto iter = libraries_weak.begin(); iter != libraries_weak.end(); iter++)
        {
            std::shared_ptr<LibraryInterface> li = iter->lock();
            if (li.get() != 0)
            {
                std::stringstream ss;
                ss << "Failed to unload library \"" << li.get()->getName() << "\": ";
                ss << li.use_count() - 1 << " references " << std::endl;
                etiss::log(etiss::ERROR, ss.str());
            }
        }
    }

    // check for existing cpu core instances
    {
        std::list<std::string> cores = CPUCore::list();
        if (cores.size() > 0)
        {
            for (auto iter = cores.begin(); iter != cores.end(); iter++)
            {
                etiss::log(etiss::ERROR, std::string("CPU core has not been deleted before "
                                                     "etiss::shutdown() call: ") +
                                             *iter);
            }
        }
    }

    etiss::py::shutdown();
}

/**
        @brief check if etiss::shutdown() was called before exiting main.
*/
//__attribute__((destructor))
static void etiss_check_shutdown()
{
    if (!etiss_shutdownOk)
    {
        etiss::log(etiss::ERROR, "To prevent segmentation faults it is neccessary to call "
                                 "\"etiss::shutdown();\" at the end of main and free any "
                                 "resource acquired through ETISS.");
    }
}
/// replaces __attribute__((destructor)) in a portable way
static class helper_class_etiss_3
{
  public:
    ~helper_class_etiss_3() { etiss_check_shutdown(); }
} helper_class_etiss_3;

etiss::Initializer::~Initializer()
{
    if (po_simpleIni)
        delete po_simpleIni;
    etiss::shutdown();
}

std::string etiss::errorMessage(etiss::int32 code, CPUArch *arch)
{
    if (code <= 0)
    { // global code
        const char *msg = etiss::RETURNCODE::getErrorMessages()[code];
        if (msg == 0)
            return std::string();
        return std::string(msg);
    }
    else
    { // cpu arch dependent code
        if (arch != 0)
        {
            std::string ret = arch->getName() + ": ";
            /// TODO: cpu arch error message function
            return ret;
        }
        else
        {
            return "Unknown CPU architecture dependent error code.";
        }
    }
}