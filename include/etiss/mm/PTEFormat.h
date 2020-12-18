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

        @author Aote Jin <aote.jin@tum.de>, Chair of Electronic Design Automation, TUM

        @date June 24, 2018

        @version 0.1

*/

#ifndef ETISS_INCLUDE_MM_PTEFORMAT_H_
#define ETISS_INCLUDE_MM_PTEFORMAT_H_
#include <iostream>
#include <map>
#include <memory>
#include <string>

namespace etiss
{
namespace mm
{

/**
        @brief Singleton to represent specific PTE format, every PTE uses this singleton
        to parse raw PTE value into PPN and protection flags, read/write PPN or flags.
*/

typedef std::map<std::string, std::pair<uint32_t, uint32_t>> PTEFormatMap;

class PTEFormat
{
  public:
    /**
     *	@brief Get the singleton instance
     */
    static PTEFormat &Instance()
    {
        static std::shared_ptr<PTEFormat> instance = std::shared_ptr<PTEFormat>(new PTEFormat());
        return *instance;
    }

    /**
     *	@brief Called only by PTEFormatBuilder
     *
     * 	@see   etiss::mm::PTEFormatBuilder
     */
    void AddBitField(std::string name, uint32_t begin, uint32_t end);

    /**
     *	@brief Dump the details of the bit field according to given name
     */
    void DumpBitFild(std::string name);

    /**
     *	@brief Dump the details of the whole PTE format
     */
    void Dump();

    uint32_t GetPTELength() const { return pte_len_; }

    PTEFormatMap &GetFormatMap() { return format_map_; }

  private:
    PTEFormat() : pte_len_(0) {}
    PTEFormatMap format_map_;
    uint32_t pte_len_;
};

} // namespace mm
} // namespace etiss

#endif
