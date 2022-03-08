/**
 * Generated on Thu, 03 Mar 2022 12:13:52 +0100.
 *
 * This file contains the function macros for the RV32IMACFD core architecture.
 */

#ifndef __RV32IMACFD_FUNCS_H
#define __RV32IMACFD_FUNCS_H

#ifndef ETISS_ARCH_STATIC_FN_ONLY
#include "Arch/RV32IMACFD/RV32IMACFD.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#endif



#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline etiss_uint32 csr_read (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1U) {
return *((RV32IMACFD*)cpu)->CSR[3U] & 31U;
}
if (csr == 2U) {
return (*((RV32IMACFD*)cpu)->CSR[3U] >> 5U) & 7U;
}
return *((RV32IMACFD*)cpu)->CSR[csr];
}

#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY

static inline void csr_write (ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
if (csr == 1U) {
*((RV32IMACFD*)cpu)->CSR[3] = (*((RV32IMACFD*)cpu)->CSR[3U] & 224U) | (val & 31U);
} else {
if (csr == 2U) {
*((RV32IMACFD*)cpu)->CSR[3] = ((val & 7U) << 5U) | (*((RV32IMACFD*)cpu)->CSR[3U] & 31U);
} else {
if (csr == 3U) {
*((RV32IMACFD*)cpu)->CSR[3] = val & 255U;
} else {
*((RV32IMACFD*)cpu)->CSR[csr] = val;
}
}
}
}

#endif
#endif