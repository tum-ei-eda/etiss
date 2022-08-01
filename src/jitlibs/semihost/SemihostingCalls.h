#ifndef ETISS_INCLUDE_SEMIHOSTING_CALLS_H_
#define ETISS_INCLUDE_SEMIHOSTING_CALLS_H_

// taken from
// https://github.com/ARM-software/abi-aa/releases/download/2022Q1/semihosting.pdf

#define SYS_OPEN 0x01
#define SYS_CLOSE 0x02
#define SYS_WRITEC 0x03
#define SYS_WRITE0 0x04
#define SYS_WRITE 0x05
#define SYS_READ 0x06
#define SYS_READC 0x07
#define SYS_ISERROR 0x08
#define SYS_ISTTY 0x09
#define SYS_SEEK 0x0A
#define SYS_FLEN 0x0C
#define SYS_TMPNAM 0x0D
#define SYS_REMOVE 0x0E
#define SYS_RENAME 0x0F
#define SYS_CLOCK 0x10
#define SYS_TIME 0x11
#define SYS_SYSTEM 0x12
#define SYS_ERRNO 0x13
#define SYS_GET_CMDLINE 0x15
#define SYS_HEAPINFO 0x16
#define SYS_EXIT 0x18
#define SYS_EXIT_EXTENDED 0x20
#define SYS_ELAPSED 0x30
#define SYS_TICKFREQ 0x31

#endif
