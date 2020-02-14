// License: https://github.com/tum-ei-eda/etiss/blob/master/LICENSE

#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#ifndef __riscv__
#define __riscv__
#endif
#include "utils.h"
#include "machine/syscall.h"

#ifndef ETISS_LOGGER_ADDR
#define ETISS_LOGGER_ADDR (void *)0x80000000
#endif

#ifdef DEBUG_SYSTEM
#include <stdarg.h>
void vprintf_fromisr(const char *format, va_list valist)
{
    va_list valist_copy;
    va_copy(valist_copy, valist);

    char buf[512];
    int size = vsnprintf(0, 0, format, valist);
    vsnprintf(buf, size + 1, format, valist_copy);

    for (size_t i = 0; i < size; ++i)
    {
        *(volatile char *)(ETISS_LOGGER_ADDR) = buf[i];
    }

    va_end(valist_copy);
}
void printf_fromisr(const char *format, ...)
{
    va_list vl;
    va_start(vl, format);
    vprintf_fromisr(format, vl);
    va_end(vl);
}
#endif

// BRK
extern char _heap_start;
extern char _heap_end;
static char *brk = &_heap_start;

// This is not the correct implementation according to linux, because:
// - It returns the current brk value instead of 0 on success.
// - It returns the current brk value if the given addr is 0.
// It is expected like this from:
// https://github.com/riscv/riscv-newlib/blob/riscv-newlib-3.0.0/libgloss/riscv/sys_sbrk.c
static int _brk(void *addr)
{
    /* If __heap_size == 0, we can't allocate memory on the heap */
    if (&_heap_start == &_heap_end)
    {
        return -1;
    }
    if (addr == 0)
    {
        return (int)brk;
    }
    if (addr < (void *)&_heap_start)
    {
        return -1;
    }
    /* Don't move the break past the end of the heap */
    if (addr < (void *)&_heap_end)
    {
        brk = addr;
    }
    else
    {
        brk = &_heap_end;
    }
    return (int)brk;
}

// FSTAT
int _fstat(int file, struct stat *st)
{
    if (file == 1 || file == 2)
    {
        st->st_mode = S_IFCHR;
        st->st_blksize = 0;
        return 0;
    }

    errno = -ENOSYS;
    return -1;
}

// WRITE
ssize_t _write(int file, const void *ptr, size_t len)
{
    if (file != 1 && file != 2)
    {
        errno = ENOSYS;
        return -1;
    }

    const char *bptr = ptr;
    for (size_t i = 0; i < len; ++i)
    {
        *(volatile char *)(ETISS_LOGGER_ADDR) = bptr[i];
    }
    return 0;
}

// EXIT
void _exit_(int exit_status)
{
#ifdef DEBUG_SYSTEM
    printf_fromisr("exit called with code: %i\n", exit_status);
#endif
    asm("ebreak");
    while (1)
        ;
}

// CLOSE
int _close(int file)
{
    if (file == 1 || file == 2)
    {
        return 0;
    }
    errno = ENOSYS;
    return -1;
}

// GETTIMEOFDAY
int _gettimeofday(struct timeval *tp, void *tzp)
{
    // Not implemented by ETISS?
    unsigned int cycle = 0;
    csrr(cycle, cycle);
    unsigned long long timebase = 100000000;
    tp->tv_sec = cycle / timebase;
    tp->tv_usec = cycle % timebase * 1000000 / timebase;
    return 0;
}

// Overrides weak definition from pulpino sys_lib.
int default_exception_handler_c(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4,
                                unsigned int a5, unsigned int a6, unsigned int a7)
{
    unsigned int mcause = 0;
    csrr(mcause, mcause);
    unsigned int mepc = 0;
    csrr(mepc, mepc);

#ifdef DEBUG_SYSTEM
    unsigned int mtval = 0;
    csrr(mtval, mtval);
    char *reason = 0;
    if (mepc == 0)
    {
        unsigned int baseptr = 0;
        asm("mv %0, s0" : "=r"(baseptr));
        // Look for the LR stored on the stack by exception_handler.
        unsigned int lr = *(unsigned int *)(baseptr + 0x5c);
        printf_fromisr("Possible jump to nullptr. Might originate from %08X\n", lr);
        while (1)
            ;
    }
#endif

    long ecall_result;

    switch (mcause)
    {
    case 0xb: // Machine ECALL
        switch (a7)
        {
        case SYS_brk:
            ecall_result = (unsigned int)_brk((void *)a0);
            break;
        case SYS_fstat:
            ecall_result = _fstat(a0, (struct stat *)a1);
            break;
        case SYS_write:
            ecall_result = _write(a0, (void *)a1, a2);
            break;
        case SYS_exit:
            _exit_(a0);
            break;
        case SYS_close:
            ecall_result = _close(a0);
            break;
        case SYS_gettimeofday:
            ecall_result = _gettimeofday((struct timeval *)a0, (void *)a1);
            break;
        default:
#ifdef DEBUG_SYSTEM
            printf_fromisr("Unhandled syscall with ID %i from %08X\n", a7, mepc);
#endif
            while (1)
                ;
        }
        // Advance to instruction after ECALL.
        csrw(mepc, mepc + 4);
        break;
#ifdef DEBUG_SYSTEM
// TODO: mtval is not implemented by ETISS.
#define ERROR_HALT(msg)                                                 \
    printf_fromisr("%s at %08X with address %08X\n", msg, mepc, mtval); \
    while (1)                                                           \
        ;
    case 0x0:
        ERROR_HALT("Instruction address misaligned");
    case 0x1:
        ERROR_HALT("Instruction access fault");
    case 0x2:
        ERROR_HALT("Illegal instruction");
    case 0x4:
        ERROR_HALT("Load address misaligned");
    case 0x5:
        ERROR_HALT("Load access fault");
    case 0x6:
        ERROR_HALT("Store/AMO address misaligned");
    case 0x7:
        ERROR_HALT("Store/AMO access fault");
#endif
    default:
#ifdef DEBUG_SYSTEM
        printf_fromisr("Unhandled cause code %i from %08X\n", mcause, mepc);
#endif
        while (1)
            ;
    }

    return ecall_result;
}

// Required by iostream
// https://lists.debian.org/debian-gcc/2003/07/msg00057.html
void *__dso_handle = (void *)&__dso_handle;

#if __GNUC__ < 9
// Support for <atomic>. Trivial since single threaded without scheduler.
// Add as required.
#include <string.h>
// https://gcc.gnu.org/wiki/Atomic/GCCMM?action=AttachFile&do=view&target=libatomic.c
typedef uint8_t ATOMICINT1;
typedef uint16_t ATOMICINT2;
typedef uint32_t ATOMICINT4;
typedef uint64_t ATOMICINT8;
int __atomic_compare_exchange(size_t size, void *mem, void *expect, void *desired, int success, int failure)
{
    if (memcmp(mem, expect, size) == 0)
    {
        memcpy(mem, desired, size);
        return 1;
    }
    memcpy(expect, mem, size);
    return 0;
}
#define ATOMIC_COMPARE_EXCHANGE(sz)                                                                              \
    int __atomic_compare_exchange_##sz(void *mem, void *expect, ATOMICINT##sz desired, int success, int failure) \
    {                                                                                                            \
        return __atomic_compare_exchange(sz, mem, expect, &desired, success, failure);                           \
    }
ATOMIC_COMPARE_EXCHANGE(1);
ATOMIC_COMPARE_EXCHANGE(2);
ATOMIC_COMPARE_EXCHANGE(4);
ATOMIC_COMPARE_EXCHANGE(8);
#endif

#ifndef fp_barrierf
#define fp_barrierf fp_barrierf
static inline float fp_barrierf(float x)
{
    volatile float y = x;
    return y;
}
#endif
static inline float eval_as_float(float x)
{
    float y = x;
    return y;
}
float __math_xflowf(uint32_t sign, float y)
{
    return eval_as_float(fp_barrierf(sign ? -y : y) * y);
}
float __math_oflowf(uint32_t sign)
{
    return __math_xflowf(sign, 0x1p97f);
}
#undef fp_barrierf
