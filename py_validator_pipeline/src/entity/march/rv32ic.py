from abc import ABC, abstractmethod
from typing import Any, List, Dict
import logging
import struct

from src.entity.march.march_base import MArchBase


class RV32IC(MArchBase, ABC):
    """
        A base class for
    """

    def __init__(self):
        self.logger = logging.getLogger(__name__)

    def fetch_int_return_value(self, entry) -> Any:
        """
            In RV32 int (32-bit) return value is stored in register a0
        """
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)
        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            rv = cjr['a0']
        return rv

    def fetch_long_long_return_value(self, entry) -> Any:
        """
            In RV32IMAC long long return value is stored in registers
            a0 (lower 32 bits) and a1 (upper 32 bits)
        """
        return self._form_64_bit_value_from_regs_a0_and_a1(entry)

    def fetch_long_double_return_value(self, entry) -> Any:
        """
            From RISC-V specification: Floating-point values
            are returned in floating-point registers only
            if they are primitives or members of a struct
            consisting of only on or two floating-point
            values. Other return values that fit into
            two pointer-words are returned in a0 and a1.
            Larger return values are passed entirely in
            memory.

            Conclusion: long double is always passed
            in memory.
        """
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
            return None

        base_addr = cjr['a0']
        data_words = []

        try:
            for i in range(4):
                addr = format(base_addr + i * 4, 'x')  # Lowercase hex without 0x
                if addr not in entry.dwrites or not entry.dwrites[addr]:
                    raise KeyError(f"Missing or empty dwrites at address {addr}")
                data_hex = entry.dwrites[addr][-1]['data']
                data_words.append(int(data_hex, 16))

            # Combine into a 128-bit value (little-endian: lowest word first)
            combined_val = (data_words[0]
                            | (data_words[1] << 32)
                            | (data_words[2] << 64)
                            | (data_words[3] << 96))

            combined_bytes = combined_val.to_bytes(16, byteorder='little')

            # Note: Python's `struct.unpack('<d', ...)` is for 64-bit floats only.
            # For 128-bit float, you'd need a custom solution, or convert to something readable:
            # rv = combined_bytes  # Return raw bytes for now, or decode externally
            rv = int.from_bytes(combined_bytes, 'little')


        except Exception as e:
            self.logger.error(f"Error reading long double: {e}")

        return rv

    def fetch_struct_return_value(self, entry) -> Any:
        """
            Resolving the return value for a struct is based on the
            v1.0 of RISC-V ABIs Specification. Please see the specification
            Chapter 2 Procedure Calling Conventions.
        """
        rv = None
        struct_type_info = entry.dwarf_info.get_subprogram_by_name(entry.function_name).type_info
        if not struct_type_info:
            self.logger.error("Subprogram missing type info")
        else:
            # Idea: we want to iterate through members and reserve resources
            # Each member has a type which gives its byte or bit length
            # primitive types have set byte sizes. Bitfields have given length
            # We are only interested in whether the value is in memory or not,
            # not so much so in the structure
            # For bitfield
            pass

        return rv

    def _form_64_bit_value_from_regs_a0_and_a1(self, entry) -> Any:
        rv = None
        cjr = self.fetch_cjr_instruction(entry.epilogue)

        if not cjr:
            self.logger.error("Missing cjr instruction. Aborting.")
        else:
            a0 = cjr['a0']
            a1 = cjr['a1']
            combined_val = (a1 << 32) | a0
            combined_bytes = combined_val.to_bytes(8, 'little')
            rv = struct.unpack('<d', combined_bytes)[0]
        return rv

    """
        These static methods fetch specific instructions from CPU state prologue and
        epilogue information
    """
    @staticmethod
    def fetch_cswsp_instruction(prologue: List[Dict[str, Any]]) -> None | Dict[str, Any]:
        cswsp_instr = None
        for i in prologue:
            if i['instruction'] == 'cswsp':
                cswsp_instr = i
                break

        return cswsp_instr

    @staticmethod
    def fetch_cjr_instruction(epilogue: List[Dict[str, Any]]) -> None | Dict[str, Any]:
        cjr_inst = None
        for i in epilogue:
            if i['instruction'] == 'cjr':
                cjr_inst = i
                break

        return cjr_inst