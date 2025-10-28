// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.
/**
        @file

        @brief general configuration and logging

        @detail
*/

#ifndef ETISS_INCLUDE_MISC_H_
#define ETISS_INCLUDE_MISC_H_

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

#include "etiss/config.h"

#include "etiss/jit/types.h"

// some msvc pathces
#ifdef _MSC_VER
typedef std::make_signed<size_t>::type ssize_t;
#endif

#define ETISS_TOSTRING2(X) #X
#define ETISS_TOSTRING(X) ETISS_TOSTRING2(X)

#define etiss_log(LEVEL, MSG) \
    etiss::log(etiss::LEVEL,  \
               std::string("On line " ETISS_TOSTRING(__LINE__) " in file " ETISS_TOSTRING(__FILE__) ": ") + (MSG));

#define etiss_del_copy(CLASS)      \
    CLASS(const CLASS &) = delete; \
    CLASS &operator=(const CLASS &) = delete;
#define etiss_del_move(CLASS)            \
    CLASS &operator=(CLASS &&) = delete; \
    CLASS(CLASS &&) = delete;

#define etiss_del_como(CLASS) etiss_del_copy(CLASS) etiss_del_move(CLASS)

// special define that creates a STRUCT whose STRUCT::value is true if EXPRESSION is valid given template parameter T
// (note expression may not have a ';': e.g. ((T*)0)->toString() NOT ((T*)0)->toString();
#define ETISS_TEMPLATE_EXPRESSION_IS_VALID(STRUCT, EXPRESSION)                           \
    template <typename>                                                                  \
    struct STRUCT##Void                                                                  \
    {                                                                                    \
        typedef void type;                                                               \
    };                                                                                   \
    template <typename T, typename Sfinae = void>                                        \
    struct STRUCT : std::false_type                                                      \
    {                                                                                    \
    };                                                                                   \
    template <typename T>                                                                \
    struct STRUCT<T, typename STRUCT##Void<decltype(EXPRESSION)>::type> : std::true_type \
    {                                                                                    \
    };

namespace etiss
{
class Configuration;

/**
 * @brief Enumeration type for the log levels.
 *
 * @details This is enumeration type for the log levels supported by the ETISS
 * logging framework.
 */
enum Verbosity
{
    SILENT = 0,
    FATALERROR = 1,
    ERROR = 2,
    WARNING = 3,
    INFO = 4,
    VERBOSE = 5
};

/**
 * @brief Marker interface for toString() support.
 */
class ToString
{
  public:
    inline ToString() {}
    virtual inline ~ToString() {}
};

/**
 * @brief Implementation of the write to stream operator for objects, that
 * implement the etiss::ToString interface.
 */
template <typename T>
typename std::enable_if<std::is_base_of<etiss::ToString, T>::value, std::ostream &>::type operator<<(std::ostream &os,
                                                                                                     const T &val)
{
    os << val.toString();
    return os;
}

/**
 * @brief Get log level reference.
 *
 * @details This function allows get the current log level of ETISS and change
 * the log level.
 */
Verbosity &verbosity();
bool &log_to_stderr();

/**
 * @brief conversion of type T to std::string.
 *
 * @details This implementation uses std::stringstream. This function also works
 * if std::string or const char* T::toString() exists.
 *
 * @param val Reference to the value, that shall be converted.
 *
 * @return The string representation.
 */
template <typename T>
std::string toString(const T &val)
{
    std::stringstream ss;
    ss << val;
    return ss.str();
}

std::list<std::string> split(
    const std::string &str,
    std::function<size_t(const std::string & /**<str*/, size_t /**<from*/, size_t & /**<seperatorsize*/)> findsplit);
inline std::list<std::string> split(const std::string &str, char splitchar)
{
    return split(str, [splitchar](const std::string &str, size_t from, size_t &seperatorsize) {
        seperatorsize = 1;
        return str.find(splitchar, from);
    });
}

inline std::list<std::string> split(const std::string &str, const std::string &splitstring)
{
    return split(str, [splitstring](const std::string &str, size_t from, size_t &seperatorsize) {
        seperatorsize = 1;
        return str.find(splitstring, from);
    });
}

/**
 * @brief conversion of type T to std::string. default implementation uses
 * std::stringstream
 */
template <typename T, typename T2, typename... O>
std::string toString(const T &val, const T2 &val2, const O &... others)
{
    return toString(val) + ";" + toString(val2, others...);
}

/**
        @brief prints string representation of verbosity level
*/
std::string toString(const Verbosity &val);

/**
 * @brief simple class that store source location information.
 *
 * @details This class is required to pass location information to etiss::log().
 * Use the macro ETISS_SRCLOC to create a SourceCodeLocation object for the
 * current location in the source code.
 *
 * E.g.:
 * @code
 *   etiss::log(etiss::ERROR,"some error",ETISS_SRCLOC);
 * @endcode
 */
class SourceCodeLocation : public ToString
{
  public:
    inline SourceCodeLocation(const std::string &file, size_t line) : file_(file), line_(line) {}
    inline std::string toString() const
    {
        return std::string("SourceCodeLocation { file=\"") + file_ + "\", line=" + etiss::toString(line_) + "}";
    }
    const std::string file_;
    const size_t line_;
};

#define ETISS_SRCLOC etiss::SourceCodeLocation(__FILE__, __LINE__)
#define ETISS_VARVAL(VAR) (std::string(ETISS_TOSTRING(VAR)) + "={" + toLogString(VAR) + "}")

/**
 * @brief write log message at the given level. if the current verbose level is lower then the message will not be
 * printed
 */
void log(Verbosity level, std::string msg);

/**
 * @brief write log message at the given level. if the current verbose level is lower then the mesGen function will not
 * be called.
 */
void logC(Verbosity level, std::function<std::string(void)> msgGen);

/**
 * @brief Format the string representation of a value for the log output.
 *
 * @details Currently toLogString only puts the result of toString() in curly
 * brackets
 */
template <typename T>
std::string toLogString(const T &t)
{
    return std::string("{") + etiss::toString(t) + "}";
}

/**
 * @brief Format a list of arguments for the log output.
 *
 * @details This function uses etiss::toLogString(cont T & t) convert the
 * arguments to strings. Arguments following the first argument are added to a
 * new line and indented by two tabs.
 */
template <typename T1, typename T2, typename... O>
std::string toLogString(const T1 &t1, const T2 &t2, const O &... os)
{
    return toLogString(t1) + "\n\t\t" + toLogString(t2, os...);
}

/**
 * additional objects will be converted to a string with toString and are added
 * to the message
 */
template <typename T, typename... O>
void log(Verbosity level, std::string msg, const T &t, const O &... args)
{
    if (level <= (int)verbosity())
    {
        etiss::log(level, msg + " \n\t{\n\t\t" + toLogString(t, args...) + "\n\t}");
    }
}

std::vector<std::string> parseCommands(const std::string &cmdline);

/**
 * @brief Get reference of the global ETISS configuration object.
 */
Configuration &cfg(const std::string &cfgName);
Configuration &cfg();

/**
 * @brief Get ETISS installation directory.
 */
std::string installDir();

/**
 * @brief Get ETISS JIT files path.
 */
std::string jitFiles();

/**
 * @brief Get ETISS JIT external headers.
 */
std::vector<std::string> jitExtHeaders();

/**
 * @brief Get ETISS JIT external libraries.
 */
std::vector<std::string> jitExtLibraries();

/**
 * @brief Get ETISS JIT external path.
 */
std::vector<std::string> jitExtHeaderPaths();
/**
 * @brief Get ETISS JIT external path.
 */
std::vector<std::string> jitExtLibPaths();

/**
 * @brief simple class to hold configuration options
 */
class Configuration
{
  public:
    Configuration();
    Configuration(std::string args);
    Configuration(const std::list<std::string> &args);

    /**
     * @brief access to the configuration key value map
     */
    std::map<std::string, std::string> &config();

    /**
     * @brief template function to read the value of a configuration key. use specialization to provide std::string
     * value conversion
     */
    template <typename T>
    T get(const std::string &key, T default_, bool *default_used = 0)
    {
        etiss::log(etiss::ERROR, std::string("etiss::Configuration::get not implemented for requested type")
                   /* + typeid(T).name()*/);
        if (default_used)
            *default_used = true;
        return default_;
    }

    /**
     * @brief Get the value of the key "debug".
     *
     * @return The boolean value that is stored for the key "debug".
     */
    bool debug();

    /**
     * @brief template function to set the value of a configuration key. use specialization to provide to std::string
     * conversion where a stringstream failes to convert the value
     *
     * @return false if key is final
     */
    template <typename T>
    bool set(const std::string &key, T value)
    {
        // GCC 4.9.0 required:
        /*
        std::regex reModule("(^|::)core[[:digit:]]+::");
        std::smatch match;
        if(std::regex_search(key, match, reModule))
        {
          std::ptrdiff_t const match_count(std::distance(
            std::sregex_iterator(key.begin(), key.end(), reModule),
            std::sregex_iterator()));
          if (match_count > 1)
          {
            etiss::log(etiss::ERROR, std::string("Config key invalid") +
                       " (more than one module specialization) key: " + key);
            return false;
          }
          std::string strReplace = match.str(0).substr(0,2).compare("")?"":"::";
          std::string newkey = key;
          newkey.replace(match.position(0),match.length(0),strReplace);
          std::cout << "new key: " << newkey << std::endl;
          return etiss::cfg(newkey).set<T>(newkey, value);
        }*/
        size_t coreStart = key.find("core");
        size_t coreEnd = key.find("::", coreStart + 1);
        if (coreStart != std::string::npos && coreEnd != std::string::npos &&
            key.substr(coreStart + 4, coreEnd - (coreStart + 4)).find_first_not_of("0123456789") == std::string::npos)
        {
            std::string newkey = key;
            newkey.replace(coreStart, coreEnd - coreStart + 2, "");
            etiss::log(etiss::INFO, std::string("use ") + newkey + " in Configuration for module " +
                                        key.substr(coreStart, coreEnd - coreStart));
            return etiss::cfg(key.substr(coreStart, coreEnd - coreStart)).set<T>(newkey, value);
        }

        std::stringstream ss;
        ss << value;
        std::lock_guard<std::mutex> lock(mu_);
        if (final_.find(key) != final_.end())
            return false;

        auto hlp = helpers_.find(key);
        if (hlp != helpers_.end())
        {
            cfg_[key] = (hlp->second)(ss.str());
        }
        else
        {
            cfg_[key] = ss.str();
        }
        return true;
    }

    /**
     * @brief return true if the value of an configuration key has been set
     */
    bool isSet(std::string val);

    /**
     * @brief removes a key value mapping
     */
    void remove(const std::string &key);

    /**
     * @brief parses a list of parameters to apply to this config. currently supported any boolean options in the style
     * of -fOPTION (OPTION = true) and -fno-OPTION (OPTION = false) and string values in the form "-oOPTION value"
     *
     * @return a list of input elements that have not been used in this function due to an unrecognized format
     */
    std::list<std::string> set(const std::list<std::string> &args);

    static std::pair<std::string, std::string> set_cmd_line_boost(const std::string &s);

    /**
     * @brief get a copy of the configuration as a map
     */
    std::map<std::string, std::string> listFullConfiguration();

    /**
     * @brief makes an option final (option can no longer be changed)
     */
    void makeFinal(const std::string &key);

    /**
     * @brief add a possible option to a list. this is just for documentation purposes and has no effect on the
     * configuration itself
     */
    void announce(std::string key, std::string type = std::string(), std::string values = std::string(),
                  std::string description = std::string());

    /**
     * @brief get a map copy with announced options
     */
    std::map<std::string, std::tuple<std::string, std::string, std::string>> getAnnounced() const;

    void operator=(Configuration &&other)
    {
        std::lock_guard<std::mutex> lock(other.mu_);
        std::lock_guard<std::mutex> lock2(mu_);
        cfg_ = other.cfg_;
        final_ = other.final_;
        helpers_ = other.helpers_;
        announced_ = other.announced_;
    }

  private:
    std::map<std::string, std::string> cfg_;
    std::set<std::string> final_;
    std::map<std::string, std::function<std::string(std::string)>> helpers_;
    mutable std::mutex mu_;
    std::map<std::string, std::tuple<std::string, std::string, std::string>> announced_;
};

// template specializations
template <>
std::string Configuration::get<std::string>(const std::string &key, std::string default_, bool *default_used);

template <>
bool Configuration::get<bool>(const std::string &key, bool default_, bool *default_used);

template <>
int Configuration::get<int>(const std::string &key, int default_, bool *default_used);

template <>
unsigned Configuration::get<unsigned>(const std::string &key, unsigned default_, bool *default_used);

template <>
uint64_t Configuration::get<uint64_t>(const std::string &key, uint64_t default_, bool *default_used);

/**
 * @brief simple class to add a configuration option to the list of known
 * options
 */
class ConfigAnnouncer
{
  public:
    inline ConfigAnnouncer(Configuration &config, std::string key, std::string type = std::string(),
                           std::string values = std::string(), std::string description = std::string())
    {
        config.announce(key, type, values, description);
    }

    inline ConfigAnnouncer(std::string key, std::string type = std::string(), std::string values = std::string(),
                           std::string description = std::string())
    {
        cfg().announce(key, type, values, description);
    }
};

/**
 * @brief Enumeration type for the endianness.
 */
enum endian_t : uint32_t
{
    _LITTLE_ENDIAN_ = ETISS_LITTLE_ENDIAN,
    _BIG_ENDIAN_ = ETISS_BIG_ENDIAN,
    _UNKNOWN_ENDIAN_ = ETISS_UNKNOWN_ENDIAN
};

/**
 * @brief evaluates the endianness of the current build as a constexpr.
 *
 * @todo test on big endian machine
 */
#if ETISS_USE_CONSTEXPR
constexpr
#else
inline
#endif
    endian_t
    getEndianness()
{
    return ((0xFFFFFFFF & 1) == _LITTLE_ENDIAN_) ? _LITTLE_ENDIAN_
                                                 : ((0xFFFFFFFF & 1) == _BIG_ENDIAN_) ? _BIG_ENDIAN_ : _UNKNOWN_ENDIAN_;
}

} // end of namespace etiss

#include "etiss/ClassDefs.h"

#endif
