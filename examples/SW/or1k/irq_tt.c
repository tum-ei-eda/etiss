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

#include "cust_print/cust_print.h"
#include <or1k-support.h>
#include <stdlib.h>



//or1k macros (copied from "spr_defs.h" and adapted)
#define SPR_SR            (17)
#define SPR_TTMR          (10 << 11)
#define SPR_TTCR          ((10 << 11) + 1)
#define SPR_TTMR_IP       0x10000000  /* Interrupt Pending */
#define SPR_TTMR_IE       0x20000000  /* Interrupt Enable */
#define SPR_TTMR_RT       0x40000000  /* Restart tick */
#define SPR_TTMR_OS       0x80000000  /* one-shot */
#define SPR_TTMR_CT       0xc0000000  /* continuous */
#define SPR_TTMR_PERIOD   0x0fffffff  /* Time Period */
#define SPR_SR_TEE        0x00000002  /* Tick timer Exception Enable */

#define RESET_TIMER_IP or1k_mtspr(SPR_TTMR, or1k_mfspr(SPR_TTMR) & ~SPR_TTMR_IP)


volatile char* global_logger_addr;

void irq2(void* data __attribute__ ((unused))){
  custom_print_string(global_logger_addr,"\n\nCALLED irq2\n\n");
}

void irq3(void* data __attribute__ ((unused)))
{
  custom_print_string(global_logger_addr,"\n\nCALLED irq3\n\n");
}

void irq4(void* data __attribute__ ((unused)))
{
  custom_print_string(global_logger_addr,"\n\nCALLED irq4\n\n");
}

void timer_isr(void) {
  custom_print_string(global_logger_addr,"<timer interrupt>");
  RESET_TIMER_IP;
  return;
}




void init_irq_tt(volatile char* logger_addr)
{
  global_logger_addr = logger_addr;
}

void interruptcontroler()
{
  or1k_interrupt_handler_add(2, irq2, NULL);
  or1k_interrupt_handler_add(3, irq3, NULL);
  or1k_interrupt_handler_add(4, irq4, NULL);
  or1k_interrupt_enable(2);
  or1k_interrupt_enable(3);
  or1k_interrupt_enable(4);     
  or1k_interrupts_enable();

  custom_print_string(global_logger_addr,"PICSR = ");
  custom_print_hex_int32(global_logger_addr, or1k_mfspr((9<<11) |2));
  PRINT_CHAR(global_logger_addr,'\n');
}

void ticktimer()
{
  // setup period in cycles (maximum: 2^28-1)
  uint32_t timer_period = 40000;
  
  // Register Timer Handler Function 
  or1k_timer_set_handler(&timer_isr); 
  
  // unmask timer irq
  or1k_mtspr(SPR_SR, or1k_mfspr(SPR_SR) | SPR_SR_TEE); 
  
  // Setup the counter register. Just for fun we initialize it with the half
  // of the period, which leads to the first timer interrupt coming after 
  // half of the period. 
  or1k_mtspr(SPR_TTCR, timer_period / 2); 
  
  // Set Timer Mode Register to start timer
  or1k_mtspr(SPR_TTMR, SPR_TTMR_IE      // interrupt enable
                      | SPR_TTMR_RT     // restart after timer match
                      | timer_period);  // the period in cycles
}
