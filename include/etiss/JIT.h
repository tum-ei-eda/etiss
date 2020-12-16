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

        @date July 28, 2014

        @version 0.1

*/
/**
        @file

        @brief JIT compiler interface definition

        @detail




*/
#ifndef ETISS_INCLUDE_JIT_H_
#define ETISS_INCLUDE_JIT_H_

#include "etiss/Misc.h"

namespace etiss
{

/**
        @brief compiler interface for just in time compilation of generated C code
*/
class JIT
{
  public:
    JIT(std::string name);
    virtual ~JIT();
    /**
            @brief translate C code to executable code and return a handle/pointer that identifies the compilation
       result
            @param code generated code
            @param headerpaths paths where required header files are located
            @param librarypaths paths where required libraries are located (usually not needed since libraries don't
       require full linking)
            @param libraries file names of required libraries (usually not needed since libraries don't require full
       linking)
            @param error string to return additional error information
            @param debug if true then compilation should try to enable gdb to jump into compiled functions
    */
    virtual void *translate(std::string code, std::set<std::string> headerpaths, std::set<std::string> librarypaths,
                            std::set<std::string> libraries, std::string &error,
                            bool debug = true) = 0; // CHANGE!!origianl debug = false:
    /**
            @brief returns a function pointer to a compiled function from the handle returned by etiss::JIT::translate
    */
    virtual void *getFunction(void *handle, std::string name, std::string &error) = 0;
    /**
            @brief clean up handled returned by etiss::JIT::translate
    */
    virtual void free(void *handle) = 0;
    /**
            @brief returns the JIT instance name previously passed to the constructor
    */
    std::string getName();

  private:
    std::string name_;
};

} // namespace etiss

#endif
