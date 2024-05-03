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

#include "GCCJIT.h"

#include <cstdlib>
#include <cstring>
#include <dlfcn.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h> //mkdtemp
#include <unistd.h>

GCCJIT::GCCJIT(bool cleanup) : etiss::JIT("gcc"), cleanup_(cleanup)
{

    id = 0;

    if (system(std::string("mkdir -p \"./tmp\"").c_str()))
        std::cerr << "ERROR: GCCJIT failed to create ./tmp folder. this may lead to a failure to compile code."
                  << std::endl;

    path_ = "./tmp/XXXXXX";
    // create unique folder (mkdtemp)
    {
        if (mkdtemp(&path_[0]) == 0)
        {
            std::cerr << "ERROR: GCCJIT failed to get unique working folder. Resulting compilations my be unrelyable"
                      << std::endl;
        }

        if (system(std::string("mkdir -p \"" + path_ + "\"").c_str())) // make folder if not present
            std::cerr << "ERROR: GCCJIT failed to create compilation path. this may lead to a failure to compile code."
                      << std::endl;
    }
    path_ = path_ + "/";
}

GCCJIT::~GCCJIT()
{
    if (cleanup_)
        if (path_.substr(0, 6) == "./tmp/") // check path before recursive delete operation
            if (system(std::string("rm -R \"" + path_ + "\"").c_str()))
                std::cerr << "ERROR: GCCJIT failed to clean up compilation files located in " << path_ << std::endl;
}

void *GCCJIT::translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                        std::set<std::string> libraries, std::string &error, bool debug)
{

    if (system(NULL) == 0)
    {
        error = "system command execution not available";
        return 0;
    }

    unsigned lid = id++;

    std::string codefilename;
    {
        std::ofstream codeFile;
        std::stringstream ss;
        ss << "code_" << lid;
        codefilename = ss.str();
        codeFile.open((path_ + codefilename + std::string(".c")).c_str());
        if (!codeFile.is_open())
        {
            error = "failed to create code file";
            return 0;
        }
        codeFile << code;
        codeFile.flush();
        codeFile.close();
    }
    std::stringstream ss;
    ss << "gcc -c -std=c99 -fPIC -march=native -mtune=native -pipe ";
    if (debug)
        ss << "-g -O0 -Wall ";
    else
        ss << "-Ofast ";
    for (std::set<std::string>::const_iterator iter = headerpaths.begin(); iter != headerpaths.end(); iter++)
    {
        ss << "-I\"" << *iter << "\" ";
    }
    ss << path_ << codefilename << ".c"
       << " -o " << path_ << codefilename << ".o";

    // std::cout << "EXECUTING: " << ss.str() << std::endl;

    int eval = system(ss.str().c_str());
    // std::cout << eval << std::endl;

    if (eval != 0)
    {
        std::cout << "compiler failed with code: " << eval << std::endl;
    }

    ss.str("");

    ss << "gcc -shared ";
    /*
    if (debug)
            ss <<"-g -dl ";
    */

    for (std::set<std::string>::const_iterator iter = librarypaths.begin();iter != librarypaths.end();iter++){
            ss << " -L" << *iter << " ";
    }

    ss << " -o " << path_ << "lib" << codefilename << ".so " << path_ << codefilename << ".o ";


    for (std::set<std::string>::const_iterator iter = libraries.begin();iter != libraries.end();iter++){
            ss << " -l\"" << *iter << "\" ";
    }

    if(!librarypaths.empty())
        ss << "-Wl";

    for (std::set<std::string>::const_iterator iter = librarypaths.begin();iter != librarypaths.end();iter++){
            ss << ",-rpath," << *iter;
    }

    //std::cout << "EXECUTING: " << ss.str() << std::endl;
    eval = system(ss.str().c_str());
    //std::cout << eval << std::endl;

    if (eval != 0)
    {
        std::cout << "compiler failed with code: " << eval << std::endl;
    }

    void *lib = dlopen((path_ + "lib" + codefilename + std::string(".so")).c_str(), RTLD_NOW | RTLD_LOCAL);

    if (lib == 0)
    {
        error = dlerror();
        return 0;
    }

    return lib;
}
void *GCCJIT::getFunction(void *handle, std::string name, std::string &error)
{
    void *ret = dlsym(handle, name.c_str());
    if (ret == 0)
    {
        error = dlerror();
        return 0;
    }
    return ret;
}
void GCCJIT::free(void *handle)
{
    dlclose(handle);
}
