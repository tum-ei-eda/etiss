#!/usr/bin/env python

import os
import csv
import argparse
import configparser
import humanize
import elftools.elf.elffile as elffile
from elftools.elf.constants import SH_FLAGS
from elftools.elf.sections import SymbolTableSection


"""
Script to gather metrics on ROM,RAM,Stack and Heap usage.

To produce the memory trace:
- Compile etissvp_lib with SC_MEM_WRITE_TRACE defined (simple: uncomment at top of mem.cpp)
- Invoke the run.sh script with the "nodmi" option
- A file "pulpino_soc.dmem_memtrace.csv" should have been created

Then run this script:
> ./get_metrics.py ../bin/TARGET_ELF_FILE [-i memsegs.ini]
"""

# Feel free to overwrite these defaults for your needs
DEFAULT_RAM_START = 0x80000
DEFAULT_RAM_SIZE = 0x80000
DEFAULT_STACK_SIZE = 0x4000


class MemRange:
    def __init__(self, name, min, max):
        self.name = name
        self.min = min
        self.max = max
        assert self.min <= self.max, "Invalid MemRange"
        self.count = 0
        self.low = 0xFFFFFFFF
        self.high = 0

    def contains(self, adr):
        return adr >= self.min and adr < self.max

    def trace(self, adr):
        self.low = min(adr, self.low)
        self.high = max(adr, self.high)
        self.count = self.count + 1

    def count(self):
        return self.count

    def usage(self):
        if self.low > self.high:
            return 0
        return self.high - self.low

    def stats(self):
        if self.low > self.high:
            return self.name + "\t[not accessed]"
        return self.name + "\t[" + hex(self.low) + "-" + hex(self.high) + "] \t(" + str(self.count) + " times)"


def parseElf(inFile):
    m = {}
    m["rom_rodata"] = 0
    m["rom_code"] = 0
    m["rom_misc"] = 0
    m["ram_data"] = 0
    m["ram_zdata"] = 0
    heapStart = None

    ignoreSections = ["", ".stack", ".comment", ".riscv.attributes", ".strtab", ".shstrtab"]

    with open(inFile, "rb") as f:
        e = elffile.ELFFile(f)

        for s in e.iter_sections():
            if s.name.startswith(".text"):
                m["rom_code"] += s.data_size
            elif s.name.startswith(".srodata"):
                m["rom_rodata"] += s.data_size
            elif s.name.startswith(".sdata"):
                m["ram_data"] += s.data_size
            elif s.name == ".rodata":
                m["rom_rodata"] += s.data_size
            elif s.name == ".vectors" or s.name == ".init_array":
                m["rom_misc"] += s.data_size
            elif s.name == ".data":
                m["ram_data"] += s.data_size
            elif s.name == ".bss" or s.name == ".sbss" or s.name == ".shbss":
                m["ram_zdata"] += s.data_size
            elif s.name.startswith(".gcc_except"):
                pass
            elif s.name.startswith(".sdata2"):
                pass
            elif s.name.startswith(".debug_"):
                pass
            elif s.name in ignoreSections:
                pass
            elif isinstance(s, SymbolTableSection):
                for sym in s.iter_symbols():
                    if sym.name == "_heap_start":
                        heapStart = sym["st_value"]
            else:
                print("warning: ignored: " + s.name + " / size: " + str(s.data_size))

    return m, heapStart


def printSz(sz, unknown_msg=""):
    if sz is None:
        return f"unknown [{unknown_msg}]" if unknown_msg else "unknown"
    return humanize.naturalsize(sz) + " (" + hex(sz) + ")"


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("elf", metavar="ELF", type=str, nargs=1, help="The target ELF file")
    parser.add_argument(
        "--trace",
        "-t",
        default="dBusAccess.csv",
        type=str,
        help="Path to CSV trace file of memory accesses (default: %(default)s)",
    )
    parser.add_argument(
        "--ini", "-i", default="", type=str, help="Path to INI file containing simple_mem_system layout (optional)"
    )
    parser.add_argument("--out", "-o", metavar="FILE", type=str, default="", help="""Output CSV file (default: -)""")
    args = parser.parse_args()

    elfFile = args.elf[0]
    traceFile = args.trace
    memIni = args.ini
    csvFile = args.out

    ramStart = DEFAULT_RAM_START
    ramSize = DEFAULT_RAM_SIZE
    stackSize = DEFAULT_STACK_SIZE

    if len(memIni) > 0:
        # Overwrite the default memory layout by parsing the specified INI file
        #
        # Example configuration file `memsegs.ini`:
        #
        # [IntConfigurations]
        # simple_mem_system.memseg_origin_00=0x0
        # simple_mem_system.memseg_length_00=0x100000
        # simple_mem_system.memseg_origin_01=0x100000
        # simple_mem_system.memseg_length_01=0x5000000
        #
        config = configparser.ConfigParser()
        config.read(memIni)

        if "IntConfigurations" not in config:
            raise RuntimeError("Section [IntConfigurations] does not exist in config file " + memCfg)

        cfg = config["IntConfigurations"]

        # ROM Start/Size is currently not used
        # romStart = cfg["simple_mem_system.memseg_origin_00"]
        # romSize = cfg["simple_mem_system.memseg_length_00"]
        ramStart = int(cfg["simple_mem_system.memseg_origin_01"], 0)
        ramSize = int(cfg["simple_mem_system.memseg_length_01"], 0)

    staticSizes, heapStart = parseElf(elfFile)
    if not heapStart:
        raise RuntimeError("did not find heap start")

    print("heap starts at: " + hex(heapStart))

    d = MemRange("Data", ramStart, heapStart)
    h = MemRange("Heap", heapStart, ramStart + ramSize - stackSize)
    s = MemRange("Stack", ramStart + ramSize - stackSize, ramStart + ramSize)
    mems = [d, h, s]

    trace_available = False
    if os.path.exists(traceFile):
        trace_available = True
        with open(traceFile) as f:
            reader = csv.reader(f, skipinitialspace=True, delimiter=";")
            for r in reader:
                adr = int(r[2], 16)
                for mem in mems:
                    if mem.contains(adr):
                        mem.trace(adr)

        for mem in mems:
            print(mem.stats())

    romSize = sum([staticSizes[k] for k in staticSizes if k.startswith("rom_")])
    ramSize = sum([staticSizes[k] for k in staticSizes if k.startswith("ram_")])

    results = {
        "rom": romSize,
        "rom_rodata": staticSizes["rom_rodata"],
        "rom_code": staticSizes["rom_code"],
        "rom_misc": staticSizes["rom_misc"],
        "ram": (ramSize + s.usage() + h.usage()) if trace_available else ramSize,
        "ram_data": staticSizes["ram_data"],
        "ram_zdata": staticSizes["ram_zdata"],
        "ram_stack": s.usage() if trace_available else None,
        "ram_heap": h.usage() if trace_available else None,
    }

    print("=== Results ===")
    print("ROM usage:        " + printSz(results["rom"]))
    print("  read-only data: " + printSz(results["rom_rodata"]))
    print("  code:           " + printSz(results["rom_code"]))
    print("  other required: " + printSz(results["rom_misc"]))
    print(
        "RAM usage:        "
        + printSz(results["ram"])
        + ("" if trace_available else " [stack and heap usage not included]")
    )
    print("  data:           " + printSz(results["ram_data"]))
    print("  zero-init data: " + printSz(results["ram_zdata"]))
    print("  stack:          " + printSz(results["ram_stack"], unknown_msg="missing trace file"))
    print("  heap:           " + printSz(results["ram_heap"], unknown_msg="missing trace file"))

    # Write metrics to file
    if csvFile:
        with open(csvFile, "w") as f:
            writer = csv.DictWriter(f, fieldnames=results.keys())
            writer.writeheader()
            writer.writerow(results)
