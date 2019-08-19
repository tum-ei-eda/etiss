#define __riscv__
#include "utils.h"
#include "machine/syscall.h"

#include "../test_cases/cust_print/cust_print.h"
#define ETISS_LOGGER_ADDR (void*)0x80000000



// BRK
extern char _heap_start;
extern char _heap_end;
static char *brk = &_heap_start;
typedef unsigned int ptrdiff_t;

// This is not the correct implementation according to linux, because:
// - It returns the current brk value instead of 0 on success.
// - It returns the current brk value if the given addr is 0.
// It is expected like this from: https://github.com/riscv/riscv-newlib/blob/riscv-newlib-3.0.0/libgloss/riscv/sys_sbrk.c
static int _brk(void *addr)
{
  /* If __heap_size == 0, we can't allocate memory on the heap */
  if(&_heap_start == &_heap_end) {
    return -1;
  }
  if(addr == 0) {
    return brk;
  }
  if(addr < &_heap_start) {
    return -1;
  }
  /* Don't move the break past the end of the heap */
  if(addr < &_heap_end) {
    brk = addr;
  } else {
    brk = &_heap_end;
  }
  return brk;
}



// Overrides weak definition from pulpino sys_lib.
void default_exception_handler_c(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7)
{
  custom_print_string(ETISS_LOGGER_ADDR,"got exception!\n");
  unsigned int mcause = 0;
  csrr(mcause, mcause);
  custom_print_hex_int32(ETISS_LOGGER_ADDR, mcause);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");
  unsigned int mepc = 0;
  csrr(mepc, mepc);
  custom_print_hex_int32(ETISS_LOGGER_ADDR, mepc);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");
  custom_print_hex_int32(ETISS_LOGGER_ADDR, a7);
  custom_print_string(ETISS_LOGGER_ADDR,"\n");

  long ecall_result;

  switch (mcause)
  {
  case 0xb: // Machine ECALL
    switch (a7)
    {
    case SYS_brk:
      custom_print_string(ETISS_LOGGER_ADDR,"SYS_brk!\n");
      ecall_result = (unsigned int)_brk(a0);
      break;
    default:
      custom_print_string(ETISS_LOGGER_ADDR,"unhandled syscall!\n");
      break;
    }
    // Advance to instruction after ECALL.
    csrw(mepc, mepc + 4);
    // Store result in a0. Need this explicitly or GCC will optimize it out.
    asm volatile("mv a0,%0" : : "r"(ecall_result));
    break;
  default:
    custom_print_string(ETISS_LOGGER_ADDR,"unhandled cause\n");
    while (1);
  }

  return ecall_result;
}
