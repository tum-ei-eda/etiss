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

#include "../cust_print/cust_print.h"

  int a[1000]= {
  5,   4,    3,   2,   1,  6, 8,  7,       9, 10,    11,     15,  14,  13,  12,19,  18,   17,   16, 20,
  20,  19,  18,   17,   16, 15,  3,   2,   1,  5,   4, 7,   6,      10,    9,   8,
  54, 32,  12,   11,14,  13,   8,  26,   64,  107, 211,  314, 100, 101,556, 1988, 433,3539, 1977,2005, 80005,
  3000,3100,3200,3350,3489,3500,3728,3811,3954,3955,3999,4100,4142,4144,4218,4297,4365,4388,4399,4444,4455,4466,4477,4488,
  45,  44,   43,  42,  41,51,    50,   49,  48, 47,  46,   50,  59,  58,   57,   56, 55,  54,  53,  52,
  4510,4512,4520,4525,4537,4540,4551,4583,4599,4600,4701,4717,4722,4737,4739,4742,4748,4755,4759,4766,4799,5000,
  77,  91,  17,   5,   355,889, 432,  298, 798,  336, 5570,5210,5304,5403,5108,5201,5000,5555,5432,5678,5252,5888, 5999,5111,
  3000,3728,3811,3954,3955,3999,4100, 6000,6570,6210,6904,6403,6508,6201,6000,6555,3000,3728,3811,3954,3955,3999,4100,6172,6278,6252,6999, 6999,6111,6453,6559,6726,
  80,  79,  78,   77,   76, 75,  74,  73,  72,   71,    70,   69,  68, 67,  66,  65,  64,   63,  62,  61,
  26,  25,  24,   23,  22,  21,36, 35,  34,  33,  32,   31,    30, 29,  28, 27,   314, 67,  2240,
  84,  83,  82,  81, 90,  89,  88,  87,  86,  85,   95, 94,   93,  92,   91, 100, 99,  98,   97,  96,
  967, 240, 127,49,   176, 111, 1977, 2005,805,  54,1001,55,  132,  198, 43, 1777,355,  67,  1999, 1023,  314,
  91,     90,  89,  88,  87,  86,  85,  84,  83,  82,  81,100, 99,  98,   97,  96,  95, 94,   93,  92,
  50,  59,  58,   57,   56, 55,  54,  53,  52,   51,    50,   49,  48, 47,  46,  45,  44,   43,  42,  41,
  54, 556, 32, 1988, 433, 777, 4355, 567, 999, 123,  556, 32,  1988, 433, 777,4355,567,  999, 123,  34,
  40,  39,  38,   37,   1127,19, 1976,339, 21977,2305, 10005, 954, 56,  932,188,  8848,1433, 977, 455, 567,
  40,  39,  38,   37,   36, 35,  34,  33,  32,   31,    967, 240, 127,49,   176, 111, 1977, 2005,805,  54,
  34,  967, 240,  127, 49, 176, 3539, 1977,2005, 80005,  54, 556, 32, 1988, 433, 777, 4355, 567, 201,
  34,  967, 240,  127, 49, 176, 777, 4355, 567, 999, 123, 267, 90, 1270, 419, 1276,131,  877, 505, 789,2011,
  34,  967, 240,  127, 49, 176, 3539, 1977,2005, 80005,  54, 556,   32, 1988, 433, 777, 4355, 567, 999, 123,
  556, 32,  1988, 433, 777,4355,567,  999, 123,  34,    30,   29,  28, 27,  26,  25,  24,   23,  22,  21,
  1001,55,  132,  198, 43, 1777,355,  67,  1999, 1023,  314, 267, 90, 1270, 419, 1276,131,  877, 505, 789,2011, 
  77,  91,  17,   5,   355,889, 432,  298, 798,  336,   653, 376, 
  77,  91,  17,   5,   355,889, 432,  298, 798,  336,   653, 376, 8,  26,   64,  107, 211,  314, 100, 101,    
  556, 32,  1988, 433, 777,4355,567,  999, 123,  34,    967, 240, 127,49,   176, 111, 1977, 2005,805,  54,  
  1001,55,  132,  198, 43, 1777,355,  67,  1999, 1023,  314, 267, 90, 1270, 419, 1276,131,  877, 505, 789,2011, 
  314, 67,  2240, 1127,19, 1976,339, 21977,2305, 10005, 954, 56,  932,188,  8848,1433, 977, 455, 567,
  34,  967, 240,  127, 49, 176, 3539, 1977,2005, 80005
  }; 
void isort_c(int a[], int n) 
{

  int k;
  int key;
  int i;
  
  for (k = 1; k < n; ++k)
  {
    
    key = a[k];
    i = k - 1;
    
    while ((i >= 0) && (key < a[i])) 
    {
      
      a[i + 1] = a[i];
      --i;
      
    }
    
    a[i + 1] = key;
    
  }
}

void isort(volatile char* logger_addr)
{
  custom_print_string(logger_addr, "isort called!\n");

  isort_c (a,1000);
}

