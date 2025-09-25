// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

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
