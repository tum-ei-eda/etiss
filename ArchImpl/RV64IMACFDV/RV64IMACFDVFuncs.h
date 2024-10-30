/**
 * Generated on Wed, 30 Oct 2024 10:54:30 +0100.
 *
 * This file contains the function prototypes for the RV64IMACFDV core architecture.
 */

#ifndef __RV64IMACFDV_FUNCS_H
#define __RV64IMACFDV_FUNCS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "RV64IMACFDV.h"
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"
#include "etiss/jit/ReturnCode.h"
#include "etiss/jit/Coverage.h"


void leave(etiss_int32 priv_lvl);

void wait(etiss_int32 flag);

etiss_uint8 RV64IMACFDV_extension_enabled(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 extension);

etiss_uint8 vtype_extractSEW(etiss_uint16);

etiss_uint8 vtype_extractLMUL(etiss_uint16);

etiss_uint8 vtype_extractTA(etiss_uint16);

etiss_uint8 vtype_extractMA(etiss_uint16);

etiss_uint16 vcfg_concatEEW(etiss_uint8 mew, etiss_uint8 width);

etiss_uint8 etiss_vload_encoded_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint64 pMSTART);

etiss_uint8 etiss_vstore_encoded_unitstride(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint16 pEEW, etiss_uint8 pVd, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint64 pMSTART);

etiss_uint8 vadd_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vadd_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vadd_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsub_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsub_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwaddu_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwaddu_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwadd_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwadd_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsubu_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwsubu_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsub_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwsub_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwaddu_w_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwaddu_w_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwadd_w_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwadd_w_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsubu_w_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwsubu_w_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vwsub_w_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vwsub_w_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vand_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vand_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vand_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vor_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vor_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vor_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vxor_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vxor_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vxor_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsll_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsll_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsll_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsrl_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsrl_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsrl_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vsra_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsra_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vsra_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmseq_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmseq_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmseq_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsne_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsne_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsne_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsltu_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsltu_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmslt_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmslt_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsleu_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsleu_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsleu_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsle_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsle_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsle_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsgtu_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsgtu_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmsgt_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint8 pVs2, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmsgt_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmv_vv(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmv_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vmv_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmv_xs(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pRd, etiss_uint8 pVs2, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vmv_sx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVd, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslideup_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vslideup_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslidedown_vi(etiss_int8 pV, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pVimm, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL);

etiss_uint8 vslidedown_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslide1up_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

etiss_uint8 vslide1down_vx(etiss_int8 pV, etiss_int8 pR, etiss_uint16 pVTYPE, etiss_uint8 pVm, etiss_uint8 pVd, etiss_uint8 pVs2, etiss_uint8 pRs1, etiss_uint16 pVSTART, etiss_uint16 pVLEN, etiss_uint16 pVL, etiss_uint8 pXLEN);

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

etiss_uint8 RV64IMACFDV_get_rm(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint8 rm);

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

etiss_uint64 RV64IMACFDV_sstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 RV64IMACFDV_mstatus_mask(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_uint64 RV64IMACFDV_csr_read(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr);

void RV64IMACFDV_csr_write(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 csr, etiss_uint64 val);

etiss_uint64 RV64IMACFDV_get_field(etiss_uint64 reg, etiss_uint64 mask);

etiss_uint64 RV64IMACFDV_set_field(etiss_uint64 reg, etiss_uint64 mask, etiss_uint64 val);

etiss_uint8 RV64IMACFDV_ctz(etiss_uint64 val);

void RV64IMACFDV_raise(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 irq, etiss_uint64 mcause);

void RV64IMACFDV_translate_exc_code(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_int32 cause);

etiss_uint64 RV64IMACFDV_calc_irq_mcause(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

void RV64IMACFDV_check_irq(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers);

etiss_int64 RV64IMACFDV_mulh(etiss_int64 x, etiss_int64 y);

etiss_int64 RV64IMACFDV_mulhsu(etiss_int64 x, etiss_uint64 y);

etiss_uint64 RV64IMACFDV_mulhu(etiss_uint64 x, etiss_uint64 y);

etiss_uint8 etiss_semihost_enabled();

etiss_int64 etiss_semihost(ETISS_CPU * const cpu, ETISS_System * const system, void * const * const plugin_pointers, etiss_uint32 XLEN, etiss_uint64 operation, etiss_uint64 parameter);

#ifdef __cplusplus
}
#endif

#endif