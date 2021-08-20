/*
 * Copyright [2020] [Technical University of Munich]
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//////////////////////////////////////////////////////////////////////////////////////
/// \file libsoftvector.h
/// \brief C/C++ Header for ETISS JIT libary or independent C application
/// \date 11/23/2020
//////////////////////////////////////////////////////////////////////////////////////

#ifndef __ETISS_SOFTVECTOR_H__
#define __ETISS_SOFTVECTOR_H__

#include "stdint.h"

struct ETISS_System;
struct ETISS_CPU;

#ifdef __cplusplus
extern "C" {
#endif

/* Vector Loads/Stores Helpers*/
//////////////////////////////////////////////////////////////////////////////////////
/// \brief Load encoded (unitstride) from memory to target vector (-group)
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vload_encoded_unitstride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t  pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Load encoded (strided) from memory to target vector (-group)
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vload_encoded_stride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t  pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pSTRIDE);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Load seqgmented (unitstride) from memory to target vector (-group)
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vload_segment_unitstride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Load encoded (strided) from memory to target vector (-group)
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vload_segment_stride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pSTRIDE);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Store encoded (unitstride) source vector (-group) to memory
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vstore_encoded_unitstride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Store encoded (strided) source vector (-group) to memory
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vstore_encoded_stride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t pVm, uint16_t pEEW, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pStride);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Store segmented (unitstride) source vector (-group) to memory
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vstore_segment_unitstride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART);

//////////////////////////////////////////////////////////////////////////////////////
/// \brief Store segmented (strided) source vector (-group) to memory
/// \return 0 if no exception triggered, else 1
uint8_t etiss_vstore_segment_stride(
	ETISS_CPU* const pCpu,				//!<[inout] Pointer to ETISS_CPU structure. Supports Vector register field
	ETISS_System* const pSystem,		//!<[inout] Pointer to ETISS_System structure. Supports databus/memory acesses
	uint8_t* pV,						//!<[inout] Vector register field as local memory
	uint16_t pVTYPE, uint8_t  pVm, uint16_t pEEW, uint8_t pNF, uint8_t pVd, uint16_t pVSTART, uint16_t pVLEN, uint16_t pVL, uint64_t pMSTART, int16_t pStride);

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* __ETISS_SOFTVECTOR_H__ */
