/**
 * Generated on Tue, 15 Feb 2022 21:11:54 +0100.
 *
 * This file contains the function macros for the RV32IMCFD core architecture.
 */

#ifndef __RV32IMCFD_FUNCS_H
#define __RV32IMCFD_FUNCS_H

#ifndef ETISS_ARCH_STATIC_FN_ONLY
#include "Arch/RV32IMCFD/RV32IMCFD.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#endif



#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline etiss_uint32 csr_read (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1) {
return *((RV32IMCFD*)cpu)->CSR[3] & 31;
}
if (csr == 2) {
return (*((RV32IMCFD*)cpu)->CSR[3] >> 5) & 3;
}
return *((RV32IMCFD*)cpu)->CSR[csr];
}

#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline void csr_write (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
if (csr == 1) {
*((RV32IMCFD*)cpu)->CSR[3] = val & 31;
} else {
if (csr == 2) {
*((RV32IMCFD*)cpu)->CSR[3] = (val & 3) << 5;
} else {
*((RV32IMCFD*)cpu)->CSR[csr] = val;
}
}
}

#endif
#endif