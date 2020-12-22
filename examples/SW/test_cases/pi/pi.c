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

#include "pi.h"
#include "../cust_print/cust_print.h"



float power(float x,int count){
	float ret = 1;
	for (int i = 0;i<count;i++){
		ret = ret * x;
	}
	return ret;
}
float F (int i) {
	if (i > 100)
		return 1;
    	return 1 + i / (2.0 * i + 1) * F(i + 1);
}

float atan_(float x) {
	float ret = 0;

	for (int i = 3+30000;i>=3;i-=2){
		ret = ret - power(x,i)/((float)i);
	}

	return ret + x;

}

void pi(volatile char* logger_addr)
{
  custom_print_string(logger_addr, "pi called!\n");

  float pi = 2 * F(1);

	custom_print_string(logger_addr, "pi 1: ");
	custom_print_float(logger_addr, pi);
	custom_print_string(logger_addr, "\n");

  pi = 16*atan_(1.0/5.0)-4*atan_(1.0/239.0);

	custom_print_string(logger_addr, "pi 2: ");
	custom_print_float(logger_addr, pi);
	custom_print_string(logger_addr, "\n");
}
