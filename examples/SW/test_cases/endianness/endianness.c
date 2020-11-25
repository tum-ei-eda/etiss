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

#include "cust_print/cust_print.h"
#include <stdlib.h>


static union {
  uint32_t as_ui;
  struct {
    uint16_t high_hw;
    uint16_t low_hw;
  } as_hwds;
  struct {
    uint8_t MSB;
    uint8_t SMSB;
    uint8_t SLSB;
    uint8_t LSB;
  } as_bytes;
} test_union;

void endianness_test(volatile char* logger_addr)
{
  custom_print_string(logger_addr,"\n\n=========    Endianness test    ============\n");
  custom_print_string(logger_addr,"\nWrite tests:\n");
  custom_print_string(logger_addr,"   Writing 0x11223344 as 32-bit; reading ");
  test_union.as_ui = 0x11223344;
  custom_print_hex_int32(logger_addr, test_union.as_ui);

  custom_print_string(logger_addr,"\n\n  16 Bit:\n");

  test_union.as_hwds.high_hw = 0xAABB;
  custom_print_string(logger_addr,"    Wrote 0xAABB to high halfword (4-byte aligned), reading 0x");
  custom_print_hex_int32(logger_addr, test_union.as_ui);
  custom_print_string(logger_addr," (should be 0xAABB3344)\n");
  if(test_union.as_ui!=0xAABB3344)
    custom_print_string(logger_addr,"\n ERROR in endianess behaviour (write high half word) \n\n");

  test_union.as_hwds.low_hw = 0xCCDD;
  custom_print_string(logger_addr,"    Wrote 0xCCDD to low halfword (2-byte aligned), reading 0x");
  custom_print_hex_int32(logger_addr, test_union.as_ui);
  custom_print_string(logger_addr," (should be 0xAABBCCDD)\n");
  if(test_union.as_ui!=0xAABBCCDD)
    custom_print_string(logger_addr,"\n ERROR in endianess behaviour (write low half word)\n\n");

  custom_print_string(logger_addr,"  8 Bit:\n");

  test_union.as_bytes.MSB = 0x11;
  custom_print_string(logger_addr,"    Wrote 0x11 to MSB (4-byte aligned), reading ");
  custom_print_hex_int32(logger_addr, test_union.as_ui);
  custom_print_string(logger_addr," (should be 0x11BBCCDD)\n");
  if(test_union.as_ui!=0x11BBCCDD)
    custom_print_string(logger_addr,"\n ERROR in endianess behaviour (write MSB)\n\n");

  test_union.as_bytes.SMSB = 0x22;
  custom_print_string(logger_addr,"    Wrote 0x22 to Second-MSB (byte aligned), reading ");
  custom_print_hex_int32(logger_addr, test_union.as_ui);
  custom_print_string(logger_addr," (should be 0x1122CCDD)\n");
  if(test_union.as_ui!=0x1122CCDD)
    custom_print_string(logger_addr,"\n ERROR in endianess behaviour (write 2MSB)\n\n");

  test_union.as_bytes.SLSB = 0x33;
  custom_print_string(logger_addr,"    Wrote 0x33 to Second-LSB (2-byte aligned), reading ");
  custom_print_hex_int32(logger_addr, test_union.as_ui);
  custom_print_string(logger_addr," (should be 0x112233DD)\n");
  if(test_union.as_ui!=0x112233DD)
    custom_print_string(logger_addr,"\n ERROR in endianess behaviour (write 2LSB)\n\n");

  test_union.as_bytes.LSB = 0x44;
  custom_print_string(logger_addr,"    Wrote 0x44 to LSB (byte aligned), reading ");
  custom_print_hex_int32(logger_addr, test_union.as_ui);
  custom_print_string(logger_addr," (should be 0x11223344)\n");
  if(test_union.as_ui!=0x11223344)
    custom_print_string(logger_addr,"\n ERROR in endianess behaviour (write LSB)\n\n");


  custom_print_string(logger_addr,"\nRead tests:\n");
  custom_print_string(logger_addr,"  16 Bit:\n");

  custom_print_string(logger_addr,"    Reading high halfword: ");
  custom_print_hex_int16(logger_addr, test_union.as_hwds.high_hw);

  custom_print_string(logger_addr,"\n    Reading low halfword: ");
  custom_print_hex_int16(logger_addr, test_union.as_hwds.low_hw);

  custom_print_string(logger_addr,"\n\n  8 Bit:");
  custom_print_string(logger_addr,"\n    Reading MSB: ");
  custom_print_hex_int8(logger_addr, test_union.as_bytes.MSB);

  custom_print_string(logger_addr,"\n    Reading Second-MSB: ");
  custom_print_hex_int8(logger_addr, test_union.as_bytes.SMSB);

  custom_print_string(logger_addr,"\n    Reading Second-LSB: ");
  custom_print_hex_int8(logger_addr, test_union.as_bytes.SLSB);

  custom_print_string(logger_addr,"\n    Reading LSB: ");
  custom_print_hex_int8(logger_addr, test_union.as_bytes.LSB);

  custom_print_string(logger_addr,"\n\n");

}
