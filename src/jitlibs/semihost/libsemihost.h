#ifndef JITLIB_SEMIHOST_H
#define JITLIB_SEMIHOST_H

#include <stdint.h>
#include "etiss/jit/CPU.h"
#include "etiss/jit/System.h"

/// Checks whether semihosting is enabled in the config
uint8_t etiss_semihost_enabled();

/// Executes the semihosting call based on the operation number.
/// For description of all semihosting calls see:
/// https://github.com/ARM-software/abi-aa/blob/main/semihosting/semihosting.rst
int64_t etiss_semihost(ETISS_CPU *const cpu, ETISS_System *const etissSystem, void *const *const _, uint32_t XLEN,
                       uint64_t operation, uint64_t parameter);

#endif
