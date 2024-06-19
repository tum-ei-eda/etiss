# Semihosting in ETISS

This JitLib offers semihosting to features to architectures in ETISS.
The specific semihosting calls implemented by this library are used by Arm and RISC-V (https://github.com/ARM-software/abi-aa/blob/main/semihosting/semihosting.rst, https://github.com/riscv/riscv-semihosting-spec/blob/main/riscv-semihosting-spec.adoc).

The JitLib provides the functions `etiss_semihost_enabled` and `etiss_semihost`.
The former returns the value of the config option `arch.enable_semihosting` and is called by the architectures prior to executing a semihosting call.
The latter is the actual semihosting implementation.
It is called with the values of the operation and parameter registers, executes the semihosting call, and returns the value of the return register.
For technical reasons also the bit-width of the architecture, the `ETISS_CPU` and the `ETISS_SYSTEM` are passed to this function.

The JitLib keeps track of some minimal state, such as the open file descriptors.

Semihosting can be used to exit from the simulator.
For this, the semihosting call `SYS_EXIT` is used.
Internally, it sets the exception variable of the CPU to `ETISS_RETURNCODE_CPUFINISHED` and `return_pending` to 1.

# CoreDSL Implementation for RISC-V

For RISC-V the instruction sequence
```
slli x0, x0, 0x1f       # 0x01f01013    Entry NOP
ebreak                  # 0x00100073    Break to debugger
srai x0, x0, 7          # 0x40705013    NOP encoding the semihosting call number 7
```
is used to execute the semihosting call.

In the CoreDSL code we override the `ebreak` instruction.
It first checks whether semihosting is enabled and, if so, checks whether the instruction before and after match the required sequence.
If they match this JitLib will be called with the values of the `a0` and the `a1` registers as the operation and parameter arguments.
After this function return the return value is written to register `a0`.

In case semihosting is disabled, or the instruction sequence does not match, the normal action for `ebreak` is executed: raising a breakpoint exception.
