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

        @author Chair of Electronic Design Automation, TUM

        @date November 18, 2021

        @version 0.1

*/
/**
        @file

        @brief general helpers for fault

        @detail




*/

#ifndef ETISS_INCLUDE_FAULT_MISC_H_
#define ETISS_INCLUDE_FAULT_MISC_H_

#include <map>
#include <string>
#include <vector>


namespace etiss
{
namespace fault
{
  
////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Action type class
template<typename enum_t>
class SmartType : public etiss::ToString
{
  public:
    typedef std::map<enum_t, const char*> map_t;
  private:
    enum_t type_;
    static map_t TABLE;
  public:
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief decode a string \p type_str to \ref enum_t, return true if successful
    static bool fromString(const std::string& type_str, enum_t& out) {
      for(auto const& e: TABLE)
      {
        if (type_str == e.second) 
        {
          out = e.first;
          return true;
        }
      }
      return false;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief convert a \ref enum_t \p in to a std::string with the static \ref TABLE
    static std::string toString(enum_t in) {
        return TABLE.at(in);
    }
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief return self as string
    std::string toString() const { return toString(type_); }
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Constructor takes \p type specifying action type
    SmartType() : type_() {}
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Constructor takes \p type specifying action type
    SmartType(enum_t type) : type_(type) {}
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Constructor takes \p type_str specifying action type string encoded
    /// \note If string does not match, default \ref enum_t() is used. Make sure to adapt
    SmartType(const std::string& type_str) {
        auto ret = fromString(type_str, type_);
        if(!ret)
            etiss::log(etiss::ERROR, std::string("SmartType<enum_t>: Unrecognized type string: \"") 
                + type_str + std::string("\" using default enum_t()"));
    }
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Typecast operator to \ref code_t
    operator enum_t() const { return type_; }
    ////////////////////////////////////////////////////////////////////////////////////////////
    /// \brief Typecast operator to \ref code_t
    operator std::string() const { 
        return toString();
    }
} /* class SmartType */ ;

} // end of namespace fault

} // end of namespace etiss

#endif /* ETISS_INCLUDE_FAULT_MISC_H_ */
