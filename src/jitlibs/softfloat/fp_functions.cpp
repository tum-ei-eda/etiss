////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017, MINRES Technologies GmbH
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Contributors:
//       eyck@minres.com - initial API and implementation
////////////////////////////////////////////////////////////////////////////////
extern "C" {
#include "softfloat_orig.h"
#include "internals.h"
#include "specialize.h"
#include "libsoftfloat.h"
}
#include <limits>

const uint8_t rmm_map[] = {
        softfloat_round_near_even /*RNE*/,
        softfloat_round_minMag/*RTZ*/,
        softfloat_round_min/*RDN*/,
        softfloat_round_max/*RUP?*/,
        softfloat_round_near_maxMag /*RMM*/,
        softfloat_round_max/*RTZ*/,
        softfloat_round_max/*RTZ*/,
        softfloat_round_max/*RTZ*/,
};

const uint32_t quiet_nan32=0x7fC00000;
extern "C" {
uint32_t fget_flags(){
    return softfloat_exceptionFlags&0x1f;
}

uint32_t fadd_s(uint32_t v1, uint32_t v2, uint8_t mode) {
    float32_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float32_t r =f32_add(v1f, v2f);
    return r.v;
}

uint32_t fsub_s(uint32_t v1, uint32_t v2, uint8_t mode) {
    float32_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float32_t r=f32_sub(v1f, v2f);
    return r.v;
}

uint32_t fmul_s(uint32_t v1, uint32_t v2, uint8_t mode) {
    float32_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float32_t r=f32_mul(v1f, v2f);
    return r.v;
}

uint32_t fdiv_s(uint32_t v1, uint32_t v2, uint8_t mode) {
    float32_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float32_t r=f32_div(v1f, v2f);
    return r.v;
}

uint32_t fsqrt_s(uint32_t v1, uint8_t mode) {
    float32_t v1f{v1};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float32_t r=f32_sqrt(v1f);
    return r.v;
}

uint32_t fcmp_s(uint32_t v1, uint32_t v2, uint32_t op) {
    float32_t v1f{v1},v2f{v2};
    softfloat_exceptionFlags=0;
    bool nan = (v1&defaultNaNF32UI)==quiet_nan32 || (v2&defaultNaNF32UI)==quiet_nan32;
    bool snan = softfloat_isSigNaNF32UI(v1) || softfloat_isSigNaNF32UI(v2);
    switch(op){
    case 0:
        if(nan | snan){
            if(snan) softfloat_raiseFlags(softfloat_flag_invalid);
            return 0;
        } else
            return f32_eq(v1f,v2f )?1:0;
    case 1:
        if(nan | snan){
            softfloat_raiseFlags(softfloat_flag_invalid);
            return 0;
        } else
            return f32_le(v1f,v2f )?1:0;
    case 2:
        if(nan | snan){
            softfloat_raiseFlags(softfloat_flag_invalid);
            return 0;
        } else
            return f32_lt(v1f,v2f )?1:0;
    default:
        break;
    }
    return -1;
}

uint32_t fcvt_s(uint32_t v1, uint32_t op, uint8_t mode) {
    float32_t v1f{v1};
    softfloat_exceptionFlags=0;
    float32_t r;
    switch(op){
    case 0:{ //w->s, fp to int32
        uint_fast32_t res = f32_to_i32(v1f,rmm_map[mode&0x7],true);
        return (uint32_t)res;
    }
    case 1:{ //wu->s
        uint_fast32_t res = f32_to_ui32(v1f,rmm_map[mode&0x7],true);
        return (uint32_t)res;
    }
    case 2: //s->w
        r=i32_to_f32(v1);
        return r.v;
    case 3: //s->wu
        r=ui32_to_f32(v1);
        return r.v;
    }
    return 0;
}

uint32_t fmadd_s(uint32_t v1, uint32_t v2, uint32_t v3, uint32_t op, uint8_t mode) {
    // op should be {softfloat_mulAdd_subProd(2), softfloat_mulAdd_subC(1)}
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float32_t res = softfloat_mulAddF32(v1, v2, v3, op&0x1);
    if(op>1) res.v ^= 1ULL<<31;
    return res.v;
}

uint32_t fsel_s(uint32_t v1, uint32_t v2, uint32_t op) {
    softfloat_exceptionFlags = 0;
    bool v1_nan = (v1 & defaultNaNF32UI) == defaultNaNF32UI;
    bool v2_nan = (v2 & defaultNaNF32UI) == defaultNaNF32UI;
    bool v1_snan = softfloat_isSigNaNF32UI(v1);
    bool v2_snan = softfloat_isSigNaNF32UI(v2);
    if (v1_snan || v2_snan) softfloat_raiseFlags(softfloat_flag_invalid);
    if (v1_nan || v1_snan)
        return (v2_nan || v2_snan) ? defaultNaNF32UI : v2;
    else
        if (v2_nan || v2_snan)
            return v1;
        else {
            if ((v1 & 0x7fffffff) == 0 && (v2 & 0x7fffffff) == 0) {
                return op == 0 ? ((v1 & 0x80000000) ? v1 : v2) : ((v1 & 0x80000000) ? v2 : v1);
            } else {
                float32_t v1f{ v1 }, v2f{ v2 };
                return op == 0 ? (f32_lt(v1f, v2f) ? v1 : v2) : (f32_lt(v1f, v2f) ? v2 : v1);
            }
        }
}

uint32_t fclass_s( uint32_t v1 ){

    float32_t a{v1};
    union ui32_f32 uA;
    uint_fast32_t uiA;

    uA.f = a;
    uiA = uA.ui;

    uint_fast16_t infOrNaN = expF32UI( uiA ) == 0xFF;
    uint_fast16_t subnormalOrZero = expF32UI( uiA ) == 0;
    bool sign = signF32UI( uiA );
    bool fracZero = fracF32UI( uiA ) == 0;
    bool isNaN = isNaNF32UI( uiA );
    bool isSNaN = softfloat_isSigNaNF32UI( uiA );

    return
        (  sign && infOrNaN && fracZero )          << 0 |
        (  sign && !infOrNaN && !subnormalOrZero ) << 1 |
        (  sign && subnormalOrZero && !fracZero )  << 2 |
        (  sign && subnormalOrZero && fracZero )   << 3 |
        ( !sign && infOrNaN && fracZero )          << 7 |
        ( !sign && !infOrNaN && !subnormalOrZero ) << 6 |
        ( !sign && subnormalOrZero && !fracZero )  << 5 |
        ( !sign && subnormalOrZero && fracZero )   << 4 |
        ( isNaN &&  isSNaN )                       << 8 |
        ( isNaN && !isSNaN )                       << 9;
}

uint32_t fconv_d2f(uint64_t v1, uint8_t mode){
    softfloat_roundingMode=rmm_map[mode&0x7];
    bool nan = (v1 & defaultNaNF64UI)==defaultNaNF64UI;
    if(nan){
        return defaultNaNF32UI;
    } else {
        float32_t res = f64_to_f32(float64_t{v1});
        return res.v;
    }
}

uint64_t fconv_f2d(uint32_t v1, uint8_t mode){
    bool nan = (v1 & defaultNaNF32UI)==defaultNaNF32UI;
    if(nan){
        return defaultNaNF64UI;
    } else {
        softfloat_roundingMode=rmm_map[mode&0x7];
        float64_t res = f32_to_f64(float32_t{v1});
        return res.v;
    }
}

uint64_t fadd_d(uint64_t v1, uint64_t v2, uint8_t mode) {
    bool nan = (v1&defaultNaNF32UI)==quiet_nan32;
    bool snan = softfloat_isSigNaNF32UI(v1);
    float64_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float64_t r =f64_add(v1f, v2f);
    (void) nan; //TODO: should there really be no check with nan/snan?
    (void) snan;
    return r.v;
}

uint64_t fsub_d(uint64_t v1, uint64_t v2, uint8_t mode) {
    float64_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float64_t r=f64_sub(v1f, v2f);
    return r.v;
}

uint64_t fmul_d(uint64_t v1, uint64_t v2, uint8_t mode) {
    float64_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float64_t r=f64_mul(v1f, v2f);
    return r.v;
}

uint64_t fdiv_d(uint64_t v1, uint64_t v2, uint8_t mode) {
    float64_t v1f{v1},v2f{v2};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float64_t r=f64_div(v1f, v2f);
    return r.v;
}

uint64_t fsqrt_d(uint64_t v1, uint8_t mode) {
    float64_t v1f{v1};
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float64_t r=f64_sqrt(v1f);
    return r.v;
}

uint64_t fcmp_d(uint64_t v1, uint64_t v2, uint32_t op) {
    float64_t v1f{v1},v2f{v2};
    softfloat_exceptionFlags=0;
    bool nan = (v1&defaultNaNF64UI)==quiet_nan32 || (v2&defaultNaNF64UI)==quiet_nan32;
    bool snan = softfloat_isSigNaNF64UI(v1) || softfloat_isSigNaNF64UI(v2);
    switch(op){
    case 0:
        if(nan | snan){
            if(snan) softfloat_raiseFlags(softfloat_flag_invalid);
            return 0;
        } else
            return f64_eq(v1f,v2f )?1:0;
    case 1:
        if(nan | snan){
            softfloat_raiseFlags(softfloat_flag_invalid);
            return 0;
        } else
            return f64_le(v1f,v2f )?1:0;
    case 2:
        if(nan | snan){
            softfloat_raiseFlags(softfloat_flag_invalid);
            return 0;
        } else
            return f64_lt(v1f,v2f )?1:0;
    default:
        break;
    }
    return -1;
}

uint64_t fcvt_d(uint64_t v1, uint32_t op, uint8_t mode) {
    float64_t v1f{v1};
    softfloat_exceptionFlags=0;
    float64_t r;
    switch(op){
    case 0:{ //l->d, fp to int32
        int64_t res = f64_to_i64(v1f,rmm_map[mode&0x7],true);
        return (uint64_t)res;
    }
    case 1:{ //lu->s
        uint64_t res = f64_to_ui64(v1f,rmm_map[mode&0x7],true);
        return res;
    }
    case 2: //s->l
        r=i64_to_f64(v1);
        return r.v;
    case 3: //s->lu
        r=ui64_to_f64(v1);
        return r.v;
    }
    return 0;
}

uint64_t fmadd_d(uint64_t v1, uint64_t v2, uint64_t v3, uint32_t op, uint8_t mode) {
    // op should be {softfloat_mulAdd_subProd(2), softfloat_mulAdd_subC(1)}
    softfloat_roundingMode=rmm_map[mode&0x7];
    softfloat_exceptionFlags=0;
    float64_t res = softfloat_mulAddF64(v1, v2, v3, op&0x1);
    if(op>1) res.v ^= 1ULL<<63;
    return res.v;
}

uint64_t fsel_d(uint64_t v1, uint64_t v2, uint32_t op) {
    softfloat_exceptionFlags = 0;
    bool v1_nan = (v1 & defaultNaNF64UI) == defaultNaNF64UI;
    bool v2_nan = (v2 & defaultNaNF64UI) == defaultNaNF64UI;
    bool v1_snan = softfloat_isSigNaNF64UI(v1);
    bool v2_snan = softfloat_isSigNaNF64UI(v2);
    if (v1_snan || v2_snan) softfloat_raiseFlags(softfloat_flag_invalid);
    if (v1_nan || v1_snan)
        return (v2_nan || v2_snan) ? defaultNaNF64UI : v2;
    else
        if (v2_nan || v2_snan)
            return v1;
        else {
            if ((v1 & std::numeric_limits<int64_t>::max()) == 0 && (v2 & std::numeric_limits<int64_t>::max()) == 0) {
                return op == 0 ?
                        ((v1 & std::numeric_limits<int64_t>::min()) ? v1 : v2) :
                        ((v1 & std::numeric_limits<int64_t>::min()) ? v2 : v1);
            } else {
                float64_t v1f{ v1 }, v2f{ v2 };
                return op == 0 ?
                        (f64_lt(v1f, v2f) ? v1 : v2) :
                        (f64_lt(v1f, v2f) ? v2 : v1);
            }
        }
}

uint64_t fclass_d(uint64_t v1  ){

    float64_t a{v1};
    union ui64_f64 uA;
    uint_fast64_t uiA;

    uA.f = a;
    uiA = uA.ui;

    uint_fast16_t infOrNaN = expF64UI( uiA ) == 0x7FF;
    uint_fast16_t subnormalOrZero = expF64UI( uiA ) == 0;
    bool sign = signF64UI( uiA );
    bool fracZero = fracF64UI( uiA ) == 0;
    bool isNaN = isNaNF64UI( uiA );
    bool isSNaN = softfloat_isSigNaNF64UI( uiA );

    return
        (  sign && infOrNaN && fracZero )          << 0 |
        (  sign && !infOrNaN && !subnormalOrZero ) << 1 |
        (  sign && subnormalOrZero && !fracZero )  << 2 |
        (  sign && subnormalOrZero && fracZero )   << 3 |
        ( !sign && infOrNaN && fracZero )          << 7 |
        ( !sign && !infOrNaN && !subnormalOrZero ) << 6 |
        ( !sign && subnormalOrZero && !fracZero )  << 5 |
        ( !sign && subnormalOrZero && fracZero )   << 4 |
        ( isNaN &&  isSNaN )                       << 8 |
        ( isNaN && !isSNaN )                       << 9;
}

uint64_t fcvt_32_64(uint32_t v1, uint32_t op, uint8_t mode) {
    float32_t v1f{v1};
    softfloat_exceptionFlags=0;
    float64_t r;
    switch(op){
    case 0: //l->s, fp to int32
        return f32_to_i64(v1f,rmm_map[mode&0x7],true);
    case 1: //wu->s
        return f32_to_ui64(v1f,rmm_map[mode&0x7],true);
    case 2: //s->w
        r=i32_to_f64(v1);
        return r.v;
    case 3: //s->wu
        r=ui32_to_f64(v1);
        return r.v;
    }
    return 0;
}

uint32_t fcvt_64_32(uint64_t v1, uint32_t op, uint8_t mode) {
    softfloat_exceptionFlags=0;
    float32_t r;
    switch(op){
    case 0:{ //wu->s
        int32_t r=f64_to_i32(float64_t{v1}, rmm_map[mode&0x7],true);
        return r;
    }
    case 1:{ //wu->s
        uint32_t r=f64_to_ui32(float64_t{v1}, rmm_map[mode&0x7],true);
        return r;
    }
    case 2: //l->s, fp to int32
        r=i64_to_f32(v1);
        return r.v;
    case 3: //wu->s
        r=ui64_to_f32(v1);
        return r.v;
    }
    return 0;
}

uint32_t unbox_s(uint64_t v){
    constexpr uint64_t mask = std::numeric_limits<uint64_t>::max() & ~((uint64_t)std::numeric_limits<uint32_t>::max());
    if((v & mask) != mask)
        return 0x7fc00000;
    else
        return v & std::numeric_limits<uint32_t>::max();
}
}
