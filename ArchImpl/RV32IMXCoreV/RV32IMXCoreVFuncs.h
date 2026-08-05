/**
 * Generated on Wed, 05 Aug 2026 14:25:16 +0200.
 *
 * This file contains the function prototypes for the RV32IMXCoreV core architecture.
 */

#ifndef __RV32IMXCOREV_FUNCS_H
#define __RV32IMXCOREV_FUNCS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "RV32IMXCoreV.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/Coverage.h"
    // clang-format off

void leave(etiss_int32 priv_lvl);

void wait(etiss_int32 flag);

etiss_int32 RV32IMXCoreV_cv_mac(etiss_int32 x, etiss_int32 y, etiss_int32 acc);

etiss_int32 RV32IMXCoreV_cv_msu(etiss_int32 x, etiss_int32 y, etiss_int32 acc);

etiss_uint8 RV32IMXCoreV_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension);

etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 etiss_get_time();

etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint32 RV32IMXCoreV_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint32 RV32IMXCoreV_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint32 RV32IMXCoreV_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr);

void RV32IMXCoreV_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val);

etiss_uint64 RV32IMXCoreV_get_field(etiss_uint64 reg, etiss_uint64 mask);

etiss_uint64 RV32IMXCoreV_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val);

etiss_uint8 RV32IMXCoreV_ctz(etiss_uint64 val);

void RV32IMXCoreV_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause);

void RV32IMXCoreV_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause);

etiss_uint32 RV32IMXCoreV_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

void RV32IMXCoreV_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint8 etiss_semihost_enabled();

etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);

    // clang-format on

#ifdef __cplusplus
}
#endif

#endif