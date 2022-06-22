#define CSR_CYCLE 0xc00
#define CSR_TIME 0xc01
#define CSR_INSTRET 0xc02

#define CSR_CYCLEH 0xc80
#define CSR_TIMEH 0xc81
#define CSR_INSTRETH 0xc82

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define rdtime() read_csr(time)
#define rdcycle() read_csr(cycle)
#define rdinstret() read_csr(instret)

#if __riscv_xlen == 32

static inline uint64_t rdtime64()
{
  uint32_t time;
  uint32_t timeh1;
  uint32_t timeh2;

  do
  {
    timeh1 = read_csr(timeh);
    time = read_csr(time);
    timeh2 = read_csr(timeh);
  } while(timeh1 != timeh2);

  return (((uint64_t) timeh1) << 32) | time;
}

static inline uint64_t rdcycle64()
{
  uint32_t cycle;
  uint32_t cycleh1;
  uint32_t cycleh2;

  do
  {
    cycleh1 = read_csr(cycleh);
    cycle = read_csr(cycle);
    cycleh2 = read_csr(cycleh);
  } while(cycleh1 != cycleh2);

  return (((uint64_t) cycleh1) << 32) | cycle;
}

static inline uint64_t rdinstret64()
{
  uint32_t instret;
  uint32_t instreth1;
  uint32_t instreth2;

  do
  {
    instreth1 = read_csr(instreth);
    instret = read_csr(instret);
    instreth2 = read_csr(instreth);
  } while(instreth1 != instreth2);

  return (((uint64_t) instreth1) << 32) | instret;
}

#else

#define rdtime64 rdtime
#define rdcycle64 rdcycle
#define rdinstret64 rdinstret

#endif