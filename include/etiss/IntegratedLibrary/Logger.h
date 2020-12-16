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

#ifndef ETISS_PLUGIN_LOGGER_H_
#define ETISS_PLUGIN_LOGGER_H_

#include "etiss/Plugin.h"

namespace etiss
{

namespace plugin
{

/**
        simple logger implementation.
        by overriding log it would also be possible to use this as a device mounted to a certain memory address. due to
   the function call overhead this is only suggested for testing purposes
*/
class Logger : public etiss::SystemWrapperPlugin
{
  public:
    Logger(uint64_t addr_value, uint64_t addr_mask);

    virtual ETISS_System *wrap(ETISS_CPU *cpu, ETISS_System *system); // wrap read/write redirection

    virtual ETISS_System *unwrap(ETISS_CPU *cpu, ETISS_System *system); // undo wrapping

    /** @brief this function writes the content of buf with length len to std::cout.
     *        It is called by write functions if the write address is the specified
     *        logger address.
     * @attention if called by iread then the buf pointer is NULL
     */
    virtual int32_t log(bool isread, uint64_t local_addr, uint8_t *buf,
                        unsigned len); // called whenever a write(or read) occured to logger address

  protected:
    inline virtual std::string _getPluginName() const { return std::string("Logger @") + etiss::toString(addr); }

  private:
    uint64_t addr;
    uint64_t mask;
};

} // namespace plugin

} // namespace etiss

#endif
