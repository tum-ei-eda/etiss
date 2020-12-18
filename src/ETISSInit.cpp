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

        @brief implementation of etiss::preloadLibraries

        @detail

*/

#include "etiss/ETISS.h"
#include "etiss/config.h"

#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <boost/filesystem.hpp>

namespace etiss
{

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

} // namespace etiss

/** Load libraries specified in a list.txt file.
 *
 * This function loads the libraries specified in a list.txt file. The list.txt
 * is a special configuration file, that contains references to libraries.
 * list.txt Syntax in Bachus-Naur Form:
 * <list-file> ::=
 *  <lib-ref>*
 *
 * <lib-ref> ::=
 *  <remote-lib-ref> | <local-lib-ref>
 *
 * <remote-lib-ref> ::=
 *  <lib-name> COMMA <lib-path> COMMA <lib-name> NEWLINE
 *
 * <local-lib-ref> ::=
 *  <lib-name> NEWLINE
 *
 * <lib-name> ::= The name of the library without the prefix und suffix
 *
 * <lib-path> ::= The file path of the folder where the library resides
 *
 * Example list.txt:
 *
 * QEMU
 * TCCJIT
 * OR1KArch
 * LLVMJIT,/etiss/lib/Jits,LLVMJIT
 * ARMv6M,/etiss/lib/Archs,ARMv6M
 *
 *  \param path std::string A Reference to a string of the path were the
 *  list.txt file can be found.
 *
 *  \return bool Returns true or false.
 */
static bool loadLibraryList(const std::string &path)
{
    std::string list_file = (path + "/list.txt");
    std::ifstream lcfg(list_file.c_str());
    if (!lcfg)
    {
        etiss::log(etiss::ERROR, std::string("Failed to open library list file: ") + list_file);
        return false;
    }

    bool ret = false;
    std::string line;
    while (std::getline(lcfg, line))
    {
        if (line.find(',') == std::string::npos)
        { // relative path
            if (etiss::loadLibrary(path, line))
                ret = true;
        }
        else
        { // absolute path
            std::vector<std::string> def;
            etiss::split(line, ',', def);
            if (def.size() == 3)
            {
                if (def[0] == def[2] && def[1].length() > 0 && def[2].length() > 0)
                {
                    if (etiss::loadLibrary(def[1], def[2]))
                        ret = true;
                }
                else
                {
                    etiss::log(etiss::ERROR, "Invalid line in plugin list file", line);
                }
            }
            else
            {
                etiss::log(etiss::ERROR, "Invalid line in plugin list file", line);
            }
        }
    }
    return ret;
}

/** Find all dynamically linked libraries in a folder and its subfolders.
 *
 * This function searchs a folder and its subfolders for dynamically linked
 * libraries. The folder is provided by a string of the folder path. The strings
 * of the library paths are inserted into the provided vector.
 *
 * \param path boost::filesystem::path& Reference to a path of a folder.
 *
 * \param libs std::vector<std::string>& Reference to the vector where the
 * library paths shall be stored.
 */
static void findLibs(const boost::filesystem::path &path, std::vector<std::string> &libs)
{
    if (boost::filesystem::exists(path) && boost::filesystem::is_directory(path))
    {
        boost::filesystem::recursive_directory_iterator end_itr;
        for (boost::filesystem::recursive_directory_iterator itr(path); itr != end_itr; ++itr)
        {
            if (boost::filesystem::is_regular_file(itr->status()))
            {
                std::string name(itr->path().filename().string());
                if (name.compare(0, 3, "lib") == 0 && name.compare(name.length() - 3, 3, ".so") == 0)
                {
                    libs.push_back(itr->path().string());
                }
            }
        }
    }
}

/// This flag indicate whether the preloading of the libraries has been executed
/// or not.
bool etiss_preload_libraries = false;

void etiss::preloadLibraries()
{

    // only allow to execute preloadLibraries() ones
    if (etiss_preload_libraries)
    {
        return;
    }
    else
    {
        etiss_preload_libraries = true;
    }

    // load libraries
    loadLibraryList(installDir() + "/lib/plugins");

    // load libraries from user folder
    std::string etiss_path = etiss::cfg().get<std::string>("etiss_wd", "");
    std::vector<std::string> lib_dirs{ std::string("ArchImpl"), std::string("JITImpl"), std::string("PluginImpl") };
    if (!etiss_path.empty())
    {
        std::vector<std::string> libs;
        for (auto itr = lib_dirs.begin(); itr != lib_dirs.end(); ++itr)
        {
            findLibs(boost::filesystem::path(etiss_path + *itr), libs);
        }
        for (auto itr = libs.begin(); itr != libs.end(); ++itr)
        {
            size_t path_end = itr->rfind('/');
            etiss::loadLibrary(itr->substr(0, path_end), itr->substr(path_end + 4, itr->length() - path_end - 7));
        }
    }
}
