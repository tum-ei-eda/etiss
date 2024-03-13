/**
 * Generated on Wed, 13 Mar 2024 21:23:08 +0100.
 *
 * This file contains the function prototypes for the RV64IMACFD core architecture.
 */

#ifndef __RV64IMACFD_FUNCS_H
#define __RV64IMACFD_FUNCS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "RV64IMACFD.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/Coverage.h"


void leave(etiss_int32 priv_lvl);

void wait(etiss_int32 flag);

etiss_uint8 RV64IMACFD_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension);

etiss_uint32 fadd_s(etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint32 fsub_s(etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint32 fmul_s(etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint32 fdiv_s(etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint32 fmadd_s(etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint32 fsel_s(etiss_uint32, etiss_uint32, etiss_uint32);

etiss_uint32 fsqrt_s(etiss_uint32, etiss_uint8);

etiss_uint32 fcmp_s(etiss_uint32, etiss_uint32, etiss_uint32);

etiss_uint32 fcvt_s(etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint64 fcvt_32_64(etiss_uint32, etiss_uint32, etiss_uint8);

etiss_uint32 fcvt_64_32(etiss_uint64, etiss_uint32, etiss_uint8);

etiss_uint32 unbox_s(etiss_uint64);

etiss_uint32 fclass_s(etiss_uint32);

etiss_uint32 fget_flags();

etiss_uint8 RV64IMACFD_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm);

etiss_uint64 fadd_d(etiss_uint64, etiss_uint64, etiss_uint8);

etiss_uint64 fsub_d(etiss_uint64, etiss_uint64, etiss_uint8);

etiss_uint64 fmul_d(etiss_uint64, etiss_uint64, etiss_uint8);

etiss_uint64 fdiv_d(etiss_uint64, etiss_uint64, etiss_uint8);

etiss_uint64 fmadd_d(etiss_uint64, etiss_uint64, etiss_uint64, etiss_uint32, etiss_uint8);

etiss_uint64 fsel_d(etiss_uint64, etiss_uint64, etiss_uint32);

etiss_uint64 fsqrt_d(etiss_uint64, etiss_uint8);

etiss_uint64 fcmp_d(etiss_uint64, etiss_uint64, etiss_uint32);

etiss_uint64 fcvt_d(etiss_uint64, etiss_uint32, etiss_uint8);

etiss_uint32 fconv_d2f(etiss_uint64, etiss_uint8);

etiss_uint64 fconv_f2d(etiss_uint32, etiss_uint8);

etiss_uint64 unbox_d(etiss_uint64);

etiss_uint64 fclass_d(etiss_uint64);

etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 etiss_get_time();

etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 RV64IMACFD_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 RV64IMACFD_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 RV64IMACFD_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr);

void RV64IMACFD_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val);

etiss_uint64 RV64IMACFD_get_field(etiss_uint64 reg, etiss_uint64 mask);

etiss_uint64 RV64IMACFD_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val);

etiss_uint8 RV64IMACFD_ctz(etiss_uint64 val);

void RV64IMACFD_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint64 mcause);

void RV64IMACFD_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause);

etiss_uint64 RV64IMACFD_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

void RV64IMACFD_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_int64 RV64IMACFD_mulh(etiss_int64 x, etiss_int64 y);

etiss_int64 RV64IMACFD_mulhsu(etiss_int64 x, etiss_uint64 y);

etiss_uint64 RV64IMACFD_mulhu(etiss_uint64 x, etiss_uint64 y);

etiss_uint8 etiss_semihost_enabled();

etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);

#ifdef __cplusplus
}
#endif

#endif