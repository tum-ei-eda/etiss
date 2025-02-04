/*
 * Copyright [2020] [Technical University of Munich]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//////////////////////////////////////////////////////////////////////////////////////
/// \file etiss_softvector.cpp
/// \brief C++ Source for ETISS JIT libary or independent C application. Implements a C interface when compiled to library beforehand
/// \date 11/23/2020
//////////////////////////////////////////////////////////////////////////////////////

//#include "softvector.h"
#include <algorithm>

#include "base/base.hpp"
#include "lsu/lsu.hpp"

#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

#include "libsoftvector.h"
extern "C"
{

uint8_t etiss_vload_encoded_unitstride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t  pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW*_vt._z_lmul;
  uint64_t _n_emul = _vt._sew*_vt._n_lmul;

  if ((_n_emul > _z_emul*8) || (_z_emul > _n_emul*8)) return 1;

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
  };

  auto const eew_bytes = pEEW >> 3U;
  VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVd, pMSTART, pVSTART, pVm, eew_bytes);
  return (0);
}

uint8_t etiss_vload_encoded_stride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t  pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pSTRIDE)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;

  if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8)){
    return 1;
  }

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
  };

  auto const eew_bytes = pEEW >> 3U;
  VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVd, pMSTART, pVSTART, pVm, pSTRIDE);

  return (0);
}

uint8_t etiss_vload_encoded_index(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t  pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, uint8_t pVs2)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;

  if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8)){
    return 1;
  }

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
  };

  VInstrInfo const v_instr_info{ .lmul_num = _vt._z_lmul,
                                 .lmul_denom = _vt._n_lmul,
                                 .sew = _vt._sew,
                                 .vector_length = pVL,
                                 .vector_register_length = pVLEN,
                                 .start_element = pVSTART,
                                 .masked = !pVm };

  VLSU::load_indices(f_readMem, VectorRegField, v_instr_info, pVd, pVs2, pMSTART, pEEW);

  return (0);
}

uint8_t etiss_vload_segment_unitstride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW*_vt._z_lmul;
  uint64_t _n_emul = _vt._sew*_vt._n_lmul;

  if ((_n_emul > _z_emul*pNF*8) || (_z_emul*pNF > _n_emul*8)) return 1;
  if ((pVd + pNF*_z_emul/_n_emul) > 32) return 1;
  if (pVSTART >= pVL) return (0);

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
  };

  uint16_t _vstart = pVSTART;
  uint64_t _moffset = pMSTART;
  auto const eew_bytes = pEEW >> 3U;

  for(size_t i = 0; i < pNF; ++i){
    VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVd + std::max(i, i * (_vt._z_lmul / _vt._n_lmul)), _moffset, _vstart, pVm, pNF * eew_bytes);
    _moffset += eew_bytes;
    // _vstart = 0;
  }
  return (0);
}

uint8_t etiss_vload_segment_stride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pSTRIDE)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW*_vt._z_lmul;
  uint64_t _n_emul = _vt._sew*_vt._n_lmul;

  if ((_n_emul > _z_emul*pNF*8) || (_z_emul*pNF > _n_emul*8)) return 1;
  if ((pVd + pNF*_z_emul/_n_emul) > 32) return 1;
  if (pVSTART >= pVL) return (0);

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
  };

  uint16_t _vstart = pVSTART;
  uint64_t _moffset = pMSTART;
  auto const eew_bytes = pEEW >> 3U;

  for(size_t i = 0; i < pNF; ++i){
    _moffset = pMSTART + i * (eew_bytes);
    VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVd + std::max(i, i * (_vt._z_lmul / _vt._n_lmul)), _moffset, _vstart, pVm, pSTRIDE);
    // _vstart = 0;
  }
  return (0);
}

uint8_t etiss_vload_segment_index(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, uint8_t pVs2)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;

  if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8)){
    return 1;
  }

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
  };

  VInstrInfo const v_instr_info{ .lmul_num = _vt._z_lmul,
                                 .lmul_denom = _vt._n_lmul,
                                 .sew = _vt._sew,
                                 .vector_length = pVL,
                                 .vector_register_length = pVLEN,
                                 .start_element = pVSTART,
                                 .masked = !pVm };

  uint64_t _moffset = pMSTART;
  for(size_t i = 0; i < pNF; ++i){
    VLSU::load_indices(f_readMem, VectorRegField, v_instr_info, pVd + std::max(i, i * (_vt._z_lmul / _vt._n_lmul)), pVs2, _moffset, pEEW);
    _moffset += _vt._sew >> 3;
  }
  return (0);
}

uint8_t etiss_vstore_encoded_unitstride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVs3, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW*_vt._z_lmul;
  uint64_t _n_emul = _vt._sew*_vt._n_lmul;
  auto const eew_bytes = pEEW >> 3U;

  if ((_n_emul > _z_emul*8) || (_z_emul > _n_emul*8)) return 1;

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
  };

  VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVs3, pMSTART, pVSTART, pVm, eew_bytes);

  return (0);
}

uint8_t etiss_vstore_encoded_stride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVs3, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pStride)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW*_vt._z_lmul;
  uint64_t _n_emul = _vt._sew*_vt._n_lmul;
  auto const eew_bytes = pEEW >> 3U;

  if ((_n_emul > _z_emul*8) || (_z_emul > _n_emul*8)) return 1;

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
  };

  VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVs3, pMSTART, pVSTART, pVm, pStride);

  return (0);
}

uint8_t etiss_vstore_encoded_index(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t  pVs3, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, uint8_t pVs2)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;

  if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8)){
    return 1;
  }

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
  };

  VInstrInfo const v_instr_info{ .lmul_num = _vt._z_lmul,
                                 .lmul_denom = _vt._n_lmul,
                                 .sew = _vt._sew,
                                 .vector_length = pVL,
                                 .vector_register_length = pVLEN,
                                 .start_element = pVSTART,
                                 .masked = !pVm };

  VLSU::store_indices(f_writeMem, VectorRegField, v_instr_info, pVs3, pVs2, pMSTART, pEEW);

  return (0);
}

uint8_t etiss_vstore_segment_unitstride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVs3, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;
  auto const eew_bytes = pEEW >> 3U;

  if ((_n_emul > _z_emul * pNF * 8) || (_z_emul * pNF > _n_emul * 8)) return 1;
  if ((pVs3 + pNF*_z_emul/_n_emul) > 32) return 1;
  if (pVSTART >= pVL) return (0);

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
  };

  uint16_t _vstart = pVSTART;
  uint64_t _moffset = pMSTART;
  for(size_t i = 0; i < pNF; ++i){
    VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN/8, pVs3 + std::max(i, (i * _z_emul / _n_emul)), _moffset, _vstart, pVm, pNF * eew_bytes);
    _moffset += eew_bytes;
    // TODO: Why reset _vstart?
    // _vstart = 0;
  }
  return (0);
}

uint8_t etiss_vstore_segment_stride(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVs3, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pStride)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;

  if ((_n_emul > _z_emul * pNF * 8) || (_z_emul * pNF > _n_emul * 8)) return 1;
  if ((pVs3 + pNF * _z_emul / _n_emul) > 32) return 1;
  if (pVSTART >= pVL) return (0);

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
  };

  uint16_t _vstart = pVSTART;
  uint64_t _moffset = pMSTART;
  auto const eew_bytes = pEEW >> 3U;

  // Memory order problem: 
  // Which stores come first? According to the spec: 
  // "Accesses to the fields within each segment can occur in any order, 
  // including the case where the byte stride is such that segments overlap in memory."
  // For now, we change order depending on positive/negative stride.
  if (pStride < 0){
    for(size_t i = 0; i < pNF; ++i) {
      VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN / 8, pVs3 + std::max(i, (i * _z_emul / _n_emul)), _moffset, _vstart, pVm, pStride);
      _moffset += eew_bytes;
    }
  }
  else{
    for(size_t i = pNF; i > 0; --i) {
      _moffset = pMSTART + ((i - 1) * eew_bytes);
      VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, eew_bytes, pVL, pVLEN / 8, pVs3 + std::max((i - 1), ((i - 1) * _z_emul / _n_emul)), _moffset, _vstart, pVm, pStride);
    }
  }
  return (0);
}

uint8_t etiss_vstore_segment_index(
  ETISS_CPU* const pCpu,
  ETISS_System* const pSystem,
  void * const * const plugin_pointers,
  uint8_t* pV,
  uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t pNF, uint8_t  pVs3, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, uint8_t pVs2)
{
  VTYPE::VTYPE _vt(pVTYPE);
  uint64_t _z_emul = pEEW * _vt._z_lmul;
  uint64_t _n_emul = _vt._sew * _vt._n_lmul;

  if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8)){
    return 1;
  }

  uint8_t* VectorRegField = pV;
  std::function<void(size_t, uint8_t*, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t* buff, size_t len) {
    (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
  };

  VInstrInfo const v_instr_info{ .lmul_num = _vt._z_lmul,
                                 .lmul_denom = _vt._n_lmul,
                                 .sew = _vt._sew,
                                 .vector_length = pVL,
                                 .vector_register_length = pVLEN,
                                 .start_element = pVSTART,
                                 .masked = !pVm };

  uint64_t _moffset = pMSTART;

  for (size_t i = 0; i < pNF; i++)
  {
    VLSU::store_indices(f_writeMem, VectorRegField, v_instr_info, pVs3 + std::max(i, (i * _z_emul / _n_emul)), pVs2, _moffset, pEEW);
    _moffset += _vt._sew >> 3;
  }
  

  return (0);
}

} // extern "C"
