/**
 * Generated on Thu, 12 May 2022 16:30:21 +0200.
 *
 * This file contains the function macros for the RV32IMACFDPV core architecture.
 */

#ifndef __RV32IMACFDPV_FUNCS_H
#define __RV32IMACFDPV_FUNCS_H

#ifndef ETISS_ARCH_STATIC_FN_ONLY
#include "Arch/RV32IMACFDPV/RV32IMACFDPV.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#endif



#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void raise(etiss_int32 irq, etiss_int32 mcause);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void leave(etiss_int32 priv_lvl);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void wait(etiss_int32 flag);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fadd_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fsub_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fmul_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fdiv_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fmadd_s(etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fsel_s(etiss_uint32, etiss_uint32, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fsqrt_s(etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fcmp_s(etiss_uint32, etiss_uint32, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fcvt_s(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fcvt_32_64(etiss_uint32, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fcvt_64_32(etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 unbox_s(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fclass_s(etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fget_flags();
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fadd_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fsub_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fmul_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fdiv_d(etiss_uint64, etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fmadd_d(etiss_uint64, etiss_uint64, etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fsel_d(etiss_uint64, etiss_uint64, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fsqrt_d(etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fcmp_d(etiss_uint64, etiss_uint64, etiss_uint32);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fcvt_d(etiss_uint64, etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 fconv_d2f(etiss_uint64, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fconv_f2d(etiss_uint32, etiss_uint8);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 unbox_d(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint64 fclass_d(etiss_uint64);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vtype_extractSEW(etiss_uint16);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vtype_extractLMUL(etiss_uint16);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vtype_extractTA(etiss_uint16);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vtype_extractMA(etiss_uint16);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint16 vcfg_concatEEW(etiss_uint8 mew, etiss_uint8 width);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 etiss_vload_encoded_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint64 pMSTART);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 etiss_vstore_encoded_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint64 pMSTART);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vadd_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwaddu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwaddu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsubu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsubu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwaddu_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwaddu_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwadd_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwadd_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsubu_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsubu_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsub_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vwsub_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vand_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vand_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vand_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vor_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vor_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vor_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vxor_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vxor_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vxor_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsll_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsll_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsll_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsrl_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsrl_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsrl_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsra_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsra_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vsra_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmseq_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmseq_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmseq_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsne_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsne_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsne_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsltu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsltu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmslt_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmslt_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsleu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsleu_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsleu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsle_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsle_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsle_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsgtu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsgtu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsgt_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmsgt_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmv_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmv_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmv_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmv_xs(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pRd, etiss_uint8 pVs2, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vmv_sx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vslideup_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vslideup_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vslidedown_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vslidedown_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vslide1up_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint8 vslide1down_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline etiss_uint32 csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr)
{
if (csr == 1U) {
return *((RV32IMACFDPV*)cpu)->CSR[3U] & 31U;
}
if (csr == 2U) {
return (*((RV32IMACFDPV*)cpu)->CSR[3U] >> 5U) & 7U;
}
return *((RV32IMACFDPV*)cpu)->CSR[csr];
}
#endif

#ifndef ETISS_ARCH_STATIC_FN_ONLY
static inline void csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val)
{
if (csr == 1U) {
*((RV32IMACFDPV*)cpu)->CSR[3] = (*((RV32IMACFDPV*)cpu)->CSR[3U] & 224U) | (val & 31U);
} else if (csr == 2U) {
*((RV32IMACFDPV*)cpu)->CSR[3] = ((val & 7U) << 5U) | (*((RV32IMACFDPV*)cpu)->CSR[3U] & 31U);
} else if (csr == 3U) {
*((RV32IMACFDPV*)cpu)->CSR[3] = val & 255U;
} else {
*((RV32IMACFDPV*)cpu)->CSR[csr] = val;
}
}
#endif
#endif
