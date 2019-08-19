/*

        @copyright

        <pre>

        Copyright 2018 Infineon Technologies AG

        This file is part of ETISS tool, see <https://gitlab.lrz.de/de-tum-ei-eda-open/etiss>.

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

#include "../test_cases/aes/aes.h"
#include "../test_cases/edge/edge.h"
#include "../test_cases/fir/fir.h"
#include "../test_cases/heap/heap.h"
#include "../test_cases/iir/iir.h"
#include "../test_cases/isort/isort.h"
#include "../test_cases/jdct/jdct.h"
//#include "../test_cases/mibench/mibench.h"
//#include "../test_cases/r1y/r2y.h"
//#include "../test_cases/rabbit/rabbit.h"
#include "../test_cases/pi/pi.h"
#include "../test_cases/simple_tests/test.h"
#include <stdlib.h>
#include <stdio.h>

#include "../test_cases/cust_print/cust_print.h"

#define ETISS_LOGGER_ADDR (void*)0x80000000

int main(int arcg,char * argv[])
{
	custom_print_string(ETISS_LOGGER_ADDR,"main called\n");



  /********************************* Software *********************************/
  test(ETISS_LOGGER_ADDR);
  isort(ETISS_LOGGER_ADDR);
  aes(ETISS_LOGGER_ADDR);
  edge(ETISS_LOGGER_ADDR);
  heap(ETISS_LOGGER_ADDR);
  iir(ETISS_LOGGER_ADDR);
  jdct(ETISS_LOGGER_ADDR);
  fir(ETISS_LOGGER_ADDR);
  //pi(ETISS_LOGGER_ADDR);
  /****************************************************************************/

  int *mem = malloc(4*sizeof(int));
  custom_print_string(ETISS_LOGGER_ADDR,"malloc returned!\n");
  custom_print_hex_int32(ETISS_LOGGER_ADDR, (unsigned int)mem);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");
  free(mem);
  int *mem2 = malloc(4*sizeof(int));
  custom_print_string(ETISS_LOGGER_ADDR,"malloc returned!\n");
  custom_print_hex_int32(ETISS_LOGGER_ADDR, (unsigned int)mem2);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");
  if (mem != mem2)
  {
    custom_print_string(ETISS_LOGGER_ADDR,"unexpected malloc return!\n");
  }
  int *mem3 = malloc(2*sizeof(int));
  custom_print_string(ETISS_LOGGER_ADDR,"malloc returned!\n");
  custom_print_hex_int32(ETISS_LOGGER_ADDR, (unsigned int)mem3);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");
  if (mem2 == mem3)
  {
    custom_print_string(ETISS_LOGGER_ADDR,"invalid malloc return!\n");
  }
  int *oldmem2 = mem2;
  mem2 = realloc(mem2, 8*sizeof(int));
  custom_print_string(ETISS_LOGGER_ADDR,"realloc returned!\n");
  custom_print_hex_int32(ETISS_LOGGER_ADDR, (unsigned int)mem2);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");
  if (mem2 == oldmem2)
  {
    custom_print_string(ETISS_LOGGER_ADDR,"unexpected realloc return!\n");
  }
  free(mem2);
  free(mem3);


  puts("hello world\n");


  custom_print_string(ETISS_LOGGER_ADDR,"main end!\n");


  // generate an ebreak instruction
  asm(".byte 0x73\n.byte 0x00\n.byte 0x10\n.byte 0x00");

	return 0;
}
