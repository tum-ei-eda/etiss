/**
 * Generated on Thu, 06 Aug 2026 13:26:11 +0200.
 *
 * This file contains the function prototypes for the RV32IMACFDV_zvl128b core architecture.
 */

#ifndef __RV32IMACFDV_ZVL128B_FUNCS_H
#define __RV32IMACFDV_ZVL128B_FUNCS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "RV32IMACFDV_zvl128b.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/Coverage.h"
    // clang-format off

void leave(etiss_int32 priv_lvl);

void wait(etiss_int32 flag);

etiss_uint8 RV32IMACFDV_zvl128b_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension);

etiss_uint8 vtype_extractSEW(etiss_uint16);

etiss_uint8 vtype_extractLMUL(etiss_uint16);

etiss_uint8 vtype_extractTA(etiss_uint16);

etiss_uint8 vtype_extractMA(etiss_uint16);

etiss_uint16 vcfg_concatEEW(etiss_uint8 mew, etiss_uint8 width);

etiss_uint8 etiss_vload_encoded_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vstore_encoded_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vload_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vstore_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint8 pVm, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vload_encoded_stride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_int16 pStride);

etiss_uint8 etiss_vstore_encoded_stride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_int16 pStride);

etiss_uint8 etiss_vload_encoded_index(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_uint8 pVs2);

etiss_uint8 etiss_vstore_encoded_index(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_uint8 pVs2);

etiss_uint8 etiss_vload_segment_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vstore_segment_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vload_segment_stride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_int16 pStride);

etiss_uint8 etiss_vstore_segment_stride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_int16 pStride);

etiss_uint8 etiss_vload_segment_index(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_uint8 pVs2);

etiss_uint8 etiss_vstore_segment_index(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint64 pMSTART, etiss_uint8 pVs2);

etiss_uint8 etiss_vstore_registers(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pNF, etiss_uint8 pVs3, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint64 pMSTART);

etiss_uint8 etiss_vload_registers(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pNF, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint64 pMSTART);

etiss_uint8 vadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vadd_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vrsub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vrsub_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwaddu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwaddu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsubu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwsubu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwsub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwaddu_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwaddu_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsubu_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwsubu_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwadd_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwadd_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsub_w_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwsub_w_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vext_vf(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 extension_encoding, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vadc_vvm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vadc_vim(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vadc_vxm(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmadc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmadc_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmadc_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsbc_vvm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsbc_vxm(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsbc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsbc_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vand_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vand_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vand_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vor_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vor_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vor_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vxor_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vxor_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vxor_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsll_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsll_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsll_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsrl_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsrl_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsrl_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsra_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsra_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsra_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vnsrl_wv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vnsrl_wi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vnsrl_wx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vnsra_wv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vnsra_wi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vnsra_wx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmseq_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmseq_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmseq_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsne_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsne_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsne_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsltu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsltu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmslt_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmslt_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsleu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsleu_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsleu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsle_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsle_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsle_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsgtu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsgtu_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsgt_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsgt_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmin_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmin_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vminu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vminu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmax_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmax_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmaxu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmaxu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmul_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmul_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmulh_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmulh_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmulhu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmulhu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmulhsu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmulhsu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vdiv_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vdiv_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vdivu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vdivu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vrem_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vrem_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vremu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vremu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmul_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwmul_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmulu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwmulu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmulsu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwmulsu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmacc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmacc_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vnmsac_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vnmsac_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vnmsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vnmsub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmaccu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwmaccu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmacc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwmacc_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmaccsu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwmaccsu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwmaccus_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmerge_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmerge_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmerge_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmv_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmv_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmv_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsaddu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsaddu_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsaddu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsadd_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vsadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vssubu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vssubu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vssub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vssub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vaaddu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vaaddu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vaadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vaadd_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vasubu_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vasubu_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vasub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vasub_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vsmul_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vsmul_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vssrl_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vssrl_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vssrl_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vssra_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vssra_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vssra_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vnclipu_wv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vnclipu_wi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vnclipu_wx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vnclip_wv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vnclip_wi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vnclip_wx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vredsum_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredmaxu_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredmax_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredminu_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredmin_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredand_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredor_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vredxor_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwredsumu_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vwredsum_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmand_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmnand_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmandn_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmxor_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmor_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmnor_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmorn_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmxnor_mm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vcpop_m(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pRd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vfirst_m(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pRd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsbf_m(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsif_m(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmsof_m(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 viota_m(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vid_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmv_xs(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pRd, etiss_uint8 pVs2, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmv_sx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslideup_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vslideup_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslidedown_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vslidedown_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslide1up_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslide1down_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vrgather_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vrgatherei16_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vrgather_vi(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vrgather_vx(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vcompress_vm(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

etiss_uint8 vmvr_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL);

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

etiss_uint8 RV32IMACFDV_zvl128b_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm);

etiss_uint8 vfadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfadd_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfsub_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfrsub_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwadd_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwsub_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwadd_wv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwadd_wf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwsub_wv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwsub_wf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfmul_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmul_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfdiv_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfdiv_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfrdiv_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwmul_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwmul_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfmacc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmacc_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfnmacc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfnmacc_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfmsac_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmsac_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfnmsac_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfnmsac_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfmadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmadd_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfnmadd_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfnmadd_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfmsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmsub_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfnmsub_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfnmsub_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwmacc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwmacc_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwnmacc_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwnmacc_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwmsac_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwmsac_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfwnmsac_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwnmsac_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfsqrt_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfrsqrt7_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfrec7_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmin_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmin_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfmax_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmax_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfsgnj_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfsgnj_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfsgnjn_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfsgnjn_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfsgnjx_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfsgnjx_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vmfeq_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vmfeq_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vmfne_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vmfne_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vmflt_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vmflt_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vmfle_vv(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vmfle_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vmfgt_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vmfge_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN, etiss_uint8 pRm);

etiss_uint8 vfclass_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmerge_vfm(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vfmv_v_f(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pXLEN);

etiss_uint8 vfcvt_xu_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfcvt_x_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfcvt_rtz_xu_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfcvt_rtz_x_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfcvt_f_xu_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfcvt_f_x_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_xu_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_x_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_rtz_xu_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_rtz_x_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_f_xu_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_f_x_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwcvt_f_f_v(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_xu_f_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_x_f_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_rtz_xu_f_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_rtz_x_f_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_f_xu_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_f_x_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_f_f_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfncvt_rod_f_f_w(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfredosum_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfredusum_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfredmax_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfredmin_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwredosum_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfwredusum_vs(void* pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pRm);

etiss_uint8 vfmv_f_s(void* pV, void* pF, etiss_uint16 pVTYPE, etiss_uint8 pRd, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pFLEN);

etiss_uint8 vfmv_s_f(void* pV, void* pF, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pFLEN);

etiss_uint8 vfslide1up_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pFLEN);

etiss_uint8 vfslide1down_vf(void* pV, void* pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint32 pVLEN, etiss_uint32 pVL, etiss_uint8 pFLEN);

etiss_uint64 etiss_get_cycles(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 etiss_get_time();

etiss_uint64 etiss_get_instret(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint32 RV32IMACFDV_zvl128b_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint32 RV32IMACFDV_zvl128b_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint32 RV32IMACFDV_zvl128b_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr);

void RV32IMACFDV_zvl128b_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint32 val);

etiss_uint64 RV32IMACFDV_zvl128b_get_field(etiss_uint64 reg, etiss_uint64 mask);

etiss_uint64 RV32IMACFDV_zvl128b_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val);

etiss_uint8 RV32IMACFDV_zvl128b_ctz(etiss_uint64 val);

void RV32IMACFDV_zvl128b_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint32 mcause);

void RV32IMACFDV_zvl128b_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause);

etiss_uint32 RV32IMACFDV_zvl128b_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

void RV32IMACFDV_zvl128b_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint8 etiss_semihost_enabled();

etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);

    // clang-format on

#ifdef __cplusplus
}
#endif

#endif