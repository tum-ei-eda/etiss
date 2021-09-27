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
/// \brief C++ Source for ETISS JIT libary or independent C application. Implements a C interface when compiled to
/// library beforehand \date 11/23/2020
//////////////////////////////////////////////////////////////////////////////////////

//#include "softvector.h"
#include "base/base.hpp"
#include "lsu/lsu.hpp"

#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

#include "libsoftvector.h"
extern "C"
{

    uint8_t etiss_vload_encoded_unitstride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV,
                                           uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVd, uint16_t pVSTART,
                                           uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8))
            return 1;

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                   size_t len) {
            (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
        };

        VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8, pVd, pMSTART, pVSTART,
                       pVm, 0);
        return (0);
    }

    uint8_t etiss_vload_encoded_stride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV, uint16_t pVTYPE,
                                       uint8_t pVm, uint16_t pEEW, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN,
                                       uint16_t pVL, uint64_t pMSTART, int16_t pSTRIDE)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8))
        {
            return 1;
        }

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                   size_t len) {
            (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
        };

        VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8, pVd, pMSTART, pVSTART,
                       pVm, pSTRIDE);

        return (0);
    }

    uint8_t etiss_vload_segment_unitstride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV,
                                           uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd,
                                           uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * pNF * 8) || (_z_emul * pNF > _n_emul * 8))
            return 1;
        if ((pVd + pNF * _z_emul / _n_emul) > 32)
            return 1;
        if (pVSTART >= pVL)
            return (0);

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                   size_t len) {
            (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
        };

        uint16_t _vstart = pVSTART;
        uint64_t _moffset = pMSTART;
        for (int i = 0; i < pNF; ++i)
        {
            VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8,
                           pVd + (i * _z_emul / _n_emul), _moffset, _vstart, pVm, 0);
            _moffset += (pVL - _vstart) * pEEW / 8;
            _vstart = 0;
        }
        return (0);
    }

    uint8_t etiss_vload_segment_stride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV, uint16_t pVTYPE,
                                       uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART,
                                       uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pSTRIDE)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * pNF * 8) || (_z_emul * pNF > _n_emul * 8))
            return 1;
        if ((pVd + pNF * _z_emul / _n_emul) > 32)
            return 1;
        if (pVSTART >= pVL)
            return (0);

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_readMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                   size_t len) {
            (*(pSystem->dread))(pSystem->handle, pCpu, addr, buff, len);
        };

        uint16_t _vstart = pVSTART;
        uint64_t _moffset = pMSTART;
        for (int i = 0; i < pNF; ++i)
        {
            _moffset = pMSTART + i * pEEW / 8;
            VLSU::load_eew(f_readMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8,
                           pVd + (i * _z_emul / _n_emul), _moffset, _vstart, pVm, pSTRIDE);
            _vstart = 0;
        }
        return (0);
    }

    uint8_t etiss_vstore_encoded_unitstride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV,
                                            uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVd, uint16_t pVSTART,
                                            uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8))
            return 1;

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                    size_t len) {
            (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
        };

        VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8, pVd, pMSTART, pVSTART,
                        pVm, 0);

        return (0);
    }

    uint8_t etiss_vstore_encoded_stride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV,
                                        uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVd, uint16_t pVSTART,
                                        uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pStride)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * 8) || (_z_emul > _n_emul * 8))
            return 1;

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                    size_t len) {
            (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
        };

        VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8, pVd, pMSTART, pVSTART,
                        pVm, pStride);

        return (0);
    }

    uint8_t etiss_vstore_segment_unitstride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV,
                                            uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd,
                                            uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * pNF * 8) || (_z_emul * pNF > _n_emul * 8))
            return 1;
        if ((pVd + pNF * _z_emul / _n_emul) > 32)
            return 1;
        if (pVSTART >= pVL)
            return (0);

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                    size_t len) {
            (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
        };

        uint16_t _vstart = pVSTART;
        uint64_t _moffset = pMSTART;
        for (int i = 0; i < pNF; ++i)
        {
            VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8,
                            pVd + (i * _z_emul / _n_emul), _moffset, _vstart, pVm, 0);
            _moffset += (pVL - _vstart) * pEEW / 8;
            _vstart = 0;
        }
        return (0);
    }

    uint8_t etiss_vstore_segment_stride(ETISS_CPU *const pCpu, ETISS_System *const pSystem, uint8_t *pV,
                                        uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd,
                                        uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART,
                                        int16_t pStride)
    {
        VTYPE::VTYPE _vt(pVTYPE);
        uint64_t _z_emul = pEEW * _vt._z_lmul;
        uint64_t _n_emul = _vt._sew * _vt._n_lmul;

        if ((_n_emul > _z_emul * pNF * 8) || (_z_emul * pNF > _n_emul * 8))
            return 1;
        if ((pVd + pNF * _z_emul / _n_emul) > 32)
            return 1;
        if (pVSTART >= pVL)
            return (0);

        uint8_t *VectorRegField = pV;
        std::function<void(size_t, uint8_t *, size_t)> f_writeMem = [pSystem, pCpu](size_t addr, uint8_t *buff,
                                                                                    size_t len) {
            (*(pSystem->dwrite))(pSystem->handle, pCpu, addr, buff, len);
        };

        uint16_t _vstart = pVSTART;
        uint64_t _moffset = pMSTART;
        for (int i = 0; i < pNF; ++i)
        {
            _moffset = pMSTART + i * pEEW / 8;
            VLSU::store_eew(f_writeMem, VectorRegField, _z_emul, _n_emul, pEEW / 8, pVL, pVLEN / 8,
                            pVd + (i * _z_emul / _n_emul), _moffset, _vstart, pVm, 0);
            _moffset += (pVL - _vstart) * pEEW / 8;
            _vstart = 0;
        }
        return (0);
    }

} // extern "C"
