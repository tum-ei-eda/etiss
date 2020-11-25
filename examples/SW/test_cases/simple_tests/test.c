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

#include "../cust_print/cust_print.h"
unsigned int isqrt2(int x) {
   unsigned int bit,rest,root=0;
    if (x<0) return 0;

    bit = (unsigned int) 0x40000000;
    rest = (unsigned int) x;
    root = 0;

    while (bit > 0)
    {
	if (rest >= (bit | root))
        {
	    rest = rest - (bit | root);
            root = root >>1;
            root = root | bit;
        }
        else
        {
	    root = root >> 1;
        }
        bit = bit >> 2;
    }
    return root;
}

void test_qrt(volatile char* logger_addr){
	int m1;
	int m2;
	m1 = 1024;
	m2 = 430336;

	if(isqrt2(m1) != 32){
    custom_print_string(logger_addr, "qrt1 failed: ");
		custom_print_hex_int64(logger_addr, isqrt2(m1));
    PRINT_CHAR(logger_addr, '\n');
	}else{
		custom_print_string(logger_addr, "qrt1 success!\n");
	}
	if(isqrt2(m2) != 656){
		custom_print_string(logger_addr, "qrt2 failed: ");
    custom_print_hex_int64(logger_addr, isqrt2(m2));
    PRINT_CHAR(logger_addr, '\n');
	}else{
		custom_print_string(logger_addr, "qrt2 success!\n");
	}

}

void test_mul(volatile char* logger_addr){

	int m1;
	int m2;



	m1 = 3567;
	m2 = 56454;

	if (m1 * m2 != 201371418){
		custom_print_string(logger_addr, "mul1 failed: ");
    custom_print_hex_int64(logger_addr, m1 * m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "mul1 success!\n");
	}

	m1 = 3567;
	m2 = -56454;

	if (m1 * m2 != -201371418){
		custom_print_string(logger_addr, "mul2 failed: ");
    custom_print_hex_int64(logger_addr, m1 * m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "mul2 success!\n");
}

}

void test_div(volatile char* logger_addr){

	int m1;
	int m2;


	m1 = 201371418;
	m2 = -56454;

	if (m1 / m2 != -3567){
		custom_print_string(logger_addr, "div1 failed: ");
    custom_print_hex_int64(logger_addr, m1 / m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "div1 success!\n");
	}

	m1 = 201371418;
	m2 = 56454;

	if (m1 / 56454 != 3567){
		custom_print_string(logger_addr, "div2 failed: ");
    custom_print_hex_int64(logger_addr, m1 / 56454);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "div2 success!\n");
	}
}

void test_fmul(volatile char* logger_addr){

	float m1;
	float m2;

	m1 = 3.4375;
	m2 = 5.3125;

	if (m1 * m2 != 18.26171875f){
		custom_print_string(logger_addr, "fmul1 failed: ");
    custom_print_float(logger_addr, m1 * m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "fmul1 success!\n");
	}

	m1 = -3.4375;
	m2 = 5.3125;

	if (m1 * m2 != -18.26171875f){
		custom_print_string(logger_addr, "fmul2 failed: ");
    custom_print_float(logger_addr, m1 * m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "fmul2 success!\n");
	}

}

void test_fdiv(volatile char* logger_addr){

	float m1;
	float m2;

	m1 = 4.153968;
	m2 = 5.3256;

	if (m1 / m2 != 0.78f){
		custom_print_string(logger_addr, "fdiv1 failed: ");
    custom_print_float(logger_addr, m1 / m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "fdiv1 success!\n");
	}

	m1 = -4.153968;
	m2 = 5.3256;

	if (m1 / m2 != -0.78f){
		custom_print_string(logger_addr, "fdiv2 failed: ");
    custom_print_float(logger_addr, m1 / m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "fdiv2 success!\n");
	}

	m1 = 8.470875;
	m2 = 3.4575;

	if (m1 / m2 != 2.45f){
		custom_print_string(logger_addr, "fdiv3 failed: ");
    custom_print_float(logger_addr, m1 / m2);
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "fdiv3 success!\n");
	}
}

void test_shift(volatile char* logger_addr){

	int m1;
	int m2;

	m1 = 3;
	m2 = 5;

	if (((m1 << m2)>>6) != 1){
		custom_print_string(logger_addr, "shift failed: ");
    custom_print_hex_int64(logger_addr, ((m1 << m2)>>6));
    PRINT_CHAR(logger_addr, '\n');

	}else{
		custom_print_string(logger_addr, "shift success!\n");
	}
}


void test(volatile char* logger_addr)
{
  custom_print_string(logger_addr, "simple tests called!\n");

  test_qrt(logger_addr);
  test_mul(logger_addr);
  test_div(logger_addr);
  test_fmul(logger_addr);
  test_fdiv(logger_addr);
  test_shift(logger_addr);
}
