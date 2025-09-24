// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

/**
 * @file ETISS.h
 *
 * @brief Header file of the ETISS library
 *
 *
 */

#ifndef ETISS_INCLUDE_ETISS_H_
#define ETISS_INCLUDE_ETISS_H_

#include "etiss/config.h"

#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <type_traits>

#include "etiss/CPUCore.h"
#include "etiss/Misc.h"

#include "etiss/LibraryInterface.h"

namespace etiss
{

/** @addtogroup ETISS_Frontend
 *  @{
 */

/**
 * @brief Create a set with all identifier names of the known CPUArch
 * plug-ins.
 *
 * @see CPUArch
 *
 * @return A set with the identifier strings.
 */
std::set<std::string> listCPUArchs();

/**
 * @brief Create a set with all identifier names of the known JIT plug-ins.
 *
 * @see JIT
 *
 * @return A set with the identifier strings.
 */
std::set<std::string> listJITs();

/**
 * @brief Create a set with all identifier names of the known plug-ins.
 *
 * @see Plugin
 *
 * @return A set with the identifier strings.
 */
std::set<std::string> listPlugins();

/**
 * @brief Search and try to load libraries.
 *
 * @detail This function is called automatically by CPUCore::create(1).
 *
 * @see ETISSInit.cpp
 */
void preloadLibraries();

/**
 * @brief Get a present JIT plug-in by name.
 *
 * @param name String of the plug-in name.
 *
 * @param options A key value map with the options required to load the
 * plug-in.
 *
 * @return Pointer to the plug-in.
 */
std::shared_ptr<JIT> getJIT(std::string name,
                            std::map<std::string, std::string> options = std::map<std::string, std::string>());

/**
 * @brief Get a present CPUArch plug-in by name.
 *
 * @param name String of the plug-in name.
 *
 * @param options A key value map with the options required to load the
 * plug-in.
 *
 * @return Pointer to the plug-in.
 */
std::shared_ptr<CPUArch> getCPUArch(std::string name,
                                    std::map<std::string, std::string> options = std::map<std::string, std::string>());

/**
 * @brief Get a present Plugin plug-in by name.
 *
 * @param name String of the plug-in name.
 *
 * @param options A key value map with the options required to load the
 * plug-in.
 *
 * @return Pointer to the plug-in.
 */
std::shared_ptr<Plugin> getPlugin(std::string name,
                                  std::map<std::string, std::string> options = std::map<std::string, std::string>());

/**
 * @brief Load a library.
 *
 * @detail The library needs to be an implementation of etiss::CPUArch,
 * etiss::JIT or etiss::Plugin. A Library interface is created for the library
 * with etiss::LibraryInterface::openSharedLibrary and added to the ETISS
 * environment with etiss::addLibrary.
 *
 * @param path String of the library location. E.g. "/path/to/lib"
 *
 * @param name String of the library name. The library name is the file name
 * of the library without the lib prefix and the file extension. E.g. for
 * libOR1KArch.so the name is OR1KArch.
 *
 * @return True if the operation was successful or false otherwise.
 */
bool loadLibrary(std::string path, std::string name);

/**
 * @brief Add a LibraryInterface to the ETISS environment.
 *
 * @detail Before a library can be use within ETISS the library needs to be
 * added to ETISS.
 *
 * @param interface Pointer to the LibraryInterface of the library to be
 * added.
 *
 * @see LibraryInteface.h
 */
void addLibrary(std::shared_ptr<etiss::LibraryInterface> libInterface);

/**
 * @brief Create a set with strings of the library names and some information
 * appended in square brackets.
 *
 * @note Use etiss::listLibraryPrefixes to get the raw library names.
 *
 * @return A set with the strings.
 */
std::set<std::string> listLibraries();

/**
 * @brief Create a set with strings of the library names.
 *
 * @detail The library names are also required to be used as prefixes to
 * symbols (library name + '_': e.g. ETISSINCLUDED_exportedSymbol).
 *
 * @return A set with the strings.
 */
std::set<std::string> listLibraryPrefixes();

/**
 * @brief Initialize and configure ETISS.
 *
 * @attention It is recommended to use etiss::Initializer instead of calling
 * etiss::initialize / etiss::shutdown manually
 */
void initialize(std::vector<std::string>& args);
/**
 * @brief Get the default JIT implementation.
 *
 * @detail The default JIT implementation, is the first loaded JIT plug-in.
 *
 * @return Pointer to the JIT plug-in.
 */
std::shared_ptr<etiss::JIT> getDefaultJIT();

/**
 * @brief Initialize and configure etiss::VirtualStruct root with etiss::CPUCore
 * \p cpu_core.
 *
 * @detail This function also initializes configured faults which require a
 * mounted \p core etiss::VirtualStruct. Add the virtual structure of the cpu to
 * the VirtualStruct root. This allows to access the field of the cpu from a
 * global context. See etiss::VirtualStruct::getVirtualStruct() and
 * etiss::VirtualStruct::getResolvedField(). In this case e.g. the
 * instructionPointer can be read from a global context by calling
 * etiss::VirtualStruct::root()->getResolvedField("core0.instructionPointer")
 * ->read().
 */
void initialize_virtualstruct(std::shared_ptr<etiss::CPUCore> cpu_core);
/**
 * @brief Extension of etiss::initialize_virtualstruct(
 * std::shared_ptr<etiss::CPUCore>) to allow direct setting of custom action for
 * \p cpu_core etiss::VirtualStruct with \p fcustom_action.
 */
void initialize_virtualstruct(std::shared_ptr<etiss::CPUCore> cpu_core, std::function<bool(const etiss::fault::Fault&, const etiss::fault::Action&, std::string& /*errormsg*/)> const & fcustom_action);

/**
 * @brief Shutdown ETISS
 *
 * @detail This function shutsdown the ETISS environment. All used libraries
 * are unloaded and the used resources are released.
 *
 * @attention It is recommende to use etiss::Initializer instead of calling
 * etiss::initialize / etiss::shutdown manually
 */
void shutdown();

/** @class Initializer
 *
 * @brief Wrapper for the initialize and shutdown of the ETISS environment.
 *
 * @detail At creation of an Initializer object ETISS is initialized. On
 * destruction of an Initializer object ETISS shutdown. There should only be
 * one instance of Initializer at any point of time.
 *
 * Create an instance at the beginning of main to ensure proper initialization
 * and cleanup.
 * @code
 *   int main(int argc,char ** argv){
 *     etiss::Initializer etiss_initializer(argc,argv);
 *
 *     // program/simulation
 *
 *   } // The etiss::Initializer instance will be destroyed here and performs cleanup operations
 * @endcode
 *
 * @note It is recommended to use this class instead of etiss::initialize() /
 * etiss::shutdown().
 */
class Initializer
{
  private:
    /**
     * @brief Add argument list to a string vector.
     *
     * @detail Recursively converts function arguments to a string with
     * etiss::toString() and adds them to a string vector.
     *
     * @param vec The string vector where the arguments should be appended.
     *
     * @param t The argument that is add next.
     *
     * @param args The arguments added in the next recursion.
     */
    template <typename T, typename... lisT>
    void toList(std::vector<std::string> &vec, T t, lisT... args)
    {
        vec.push_back(etiss::toString(t));
        toList(vec, args...);
    }

    /**
     * @brief Break condition for empty argument list.
     */
    inline void toList(std::vector<std::string> &vec) {}

    /** @brief creates a simpleIni object which holds the data of the given .ini file.
     */
    void loadIni(std::list<std::string> *files);

    /** @brief Make sure that the first variadic parameter at compiletime
     * is no number.
     *
     * @detail The original goal was: The Initializer versions that take
     * argc and argv wanted const char as type for argv. In some projects,
     * the Initializer constructor was called with char instead of const char.
     * This led to problems as another construtor with completely variadic
     * parameters was choosen instead, which failed to parse argc and argv.
     * This function was used to make sure these versions of Initializer are
     * not instantiated with argc as the first argument.
     */
    template <typename T, typename... lisT>
    void static_assertFirstParamNotArithmetic(T t, lisT... args)
    {
        static_assert(!std::is_arithmetic<T>::value, "This implementation of the Initializer constructor does not take "
                                                     "integral variables as first variadic parameter");
    }

    /** @brief version of static_assertFirstParamNotArithmetic for the case
     * that no parameter is given.
     */
    void static_assertFirstParamNotArithmetic(){};

  public:
    /** @brief loads the plugins given with the previous loaded .ini files
     * @param Needed to add the plugins to the CPU
     */
    void loadIniPlugins(std::shared_ptr<etiss::CPUCore> cpu);
    /** @brief sets the JIT given with the previous loaded .ini files
     * @param Needed to add the JIT to the CPU
     */
    void loadIniJIT(std::shared_ptr<etiss::CPUCore> cpu);

    /**
     * @brief Constructor that initializes ETISS.
     *
     * @detail This Constructor is useful if the arguments provided to the main
     * function should be forwarded to etiss::initialize(). Additional arguments
     * can simply be added at the end of the argument list. If an argument is
     * not a string it will be converted to a string with the help of
     * etiss::toString().
     *
     * @param argc The number of arguments in the C-string array.
     *
     * @param argv Pointer to a C-string array.
     *
     * @param args_append Additional arguments for etiss::initialize.
     */
    template <typename argvT, typename... lisT>
    Initializer(int argc, argvT **argv, lisT... args_append)
    {
        // const and non const *argv[] are allowed. This assertion is
        // easier than duplicing the constructor.
        static_assert(std::is_same<const char, argvT>::value || std::is_same<char, argvT>::value,
                      "argv must be of type const char or char");
        std::vector<std::string> args;
        for (int i = 1; i < argc; i++)
        {
            args.push_back(std::string(argv[i]));
        }
        toList(args, args_append...);
        initialize(args);
    }

    Initializer(std::list<std::string> *files, int argc, const char* argv[])
    {
        std::vector<std::string> args;
        for (int i = 1; i < argc; i++)
        {
            args.push_back(std::string(argv[i]));
        }
        loadIni(files);
        initialize(args);
    }

    /**
     * @brief Constructor that initializes ETISS.
     *
     * @detail If an argument is not a string it will be converted to a string
     * with the help of etiss::toString(). E.g.
     *
     * @code
     *   etiss::Initializer
     * initializer("-foption1","-fno-option2","-osomevallue",123,"etc.");
     * @endcode
     *
     * @param args List of arguments for etiss::initialize.
     */
    template <typename... listT>
    Initializer(listT... args)
    {
        // At the moment, it doesn't make sense to call this version of the
        // constructor with a number as first arguement (at compile-time!)
        static_assertFirstParamNotArithmetic(args...);
        std::vector<std::string> argv;
        toList(argv, args...);
        initialize(argv);
    }

    /**
     * @brief Constructor that initializes ETISS.
     *
     * @detail This Constructor is useful if the arguments provided to the main
     * function should be forwarded to etiss::initialize(). Additional arguments
     * can simply be added at the end of the argument list. If an argument is
     * not a string it will be converted to a string with the help of
     * etiss::toString().
     *
     * @param argc The number of arguments in the C-string array.
     *
     * @param argv Pointer to a C-string array.
     *
     * @param filename File to open an ini file.
     *
     * @param args_append Additional arguments for etiss::initialize.
     */
    template <typename argvT, typename... lisT>
    Initializer(std::list<std::string> *files, int argc, argvT **argv, lisT... args_append)
    {
        // const and non const *argv[] are allowed. This assertion is
        // easier than duplicing the constructor.
        static_assert(std::is_same<const char, argvT>::value || std::is_same<char, argvT>::value,
                      "argv must be of type const char or char");
        std::vector<std::string> args;
        for (int i = 1; i < argc; i++)
        {
            args.push_back(std::string(argv[i]));
        }
        toList(args, args_append...);
        loadIni(files);
        initialize(args);
    }

    /**
     * @brief Constructor that initializes ETISS.
     *
     * @detail If an argument is not a string it will be converted to a string
     * with the help of etiss::toString(). E.g.
     *
     * @code
     *   etiss::Initializer
     * initializer("-foption1","-fno-option2","-osomevallue",123,"etc.");
     * @endcode
     *
     * @param filename File to open an ini file.
     *
     * @param args List of arguments for etiss::initialize.
     */
    template <typename... listT>
    Initializer(std::list<std::string> *files, listT... args)
    {
        // At the moment, it doesn't make sense to call this version of the
        // constructor with a number as first arguement (at compile-time!)
        static_assertFirstParamNotArithmetic(args...);
        std::vector<std::string> argv;
        toList(argv, args...);
        loadIni(files);
        initialize(argv);
    }

    /**
     * @brief Destructor that shutdowns ETISS.
     *
     * @detail The destructor calls etiss::shutdown().
     */
    ~Initializer();
};

/**
 * @brief Get the error message for an error code for a specific
 * CPUArch plug-in.
 *
 * @todo add error message interface to etiss::CPUArch
 */
std::string errorMessage(etiss::int32 code, CPUArch *arch = 0);

/** @}
 */ // end of @addtogoup ETISS_Frontend

/**
 * @addtogroup ETISS_Internals
 * @{
 */

/**
 * @brief Force the initialization of ETISS.
 *
 * @detail This function is used by some ETISS functions to force
 * initialization. The initialization is only performed if ETISS not
 * initialized already.
 *
 * @see etiss::initialize
 */
void forceInitialization();

/** @}
 */ // end of @addtogoup ETISS_Internals

namespace py
{
void init();
void shutdown();
void console();
bool supported();
void runString(std::string s);
void run(std::function<void(void)> func);
void runEXT(std::function<void(void)> func);
} // namespace py

} // namespace etiss

#endif
