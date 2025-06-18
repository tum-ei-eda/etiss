from dataclasses import dataclass, field
from typing import List, Tuple
from math import ceil

from src.entity.verification.struct_reg_data_types import Bitfield, Integer


@dataclass
class RV32Register:
    size: int
    float: bool
    data: List[Tuple[int, int]] = field(default_factory=list)
    xlen: int = 32


    def has_room_for_bitfield(self, bits_to_reserve: int, alignment_bytes: int ) -> bool:
        has_room = True
        alignment_bits: int = alignment_bytes * 8
        if self.data:
            aligned_start_bit = ceil(self.data[-1][1] / alignment_bits) * alignment_bits
            if aligned_start_bit >= self.xlen or aligned_start_bit + bits_to_reserve >= self.xlen:
                has_room = False
        return has_room


    def has_room_for_int(self, byte_size: int) -> bool:
        has_room = True
        alignment_bits: int = byte_size * 8
        if self.data:
            aligned_start_bit = ceil(self.data[-1][1] / alignment_bits) * alignment_bits
            if aligned_start_bit >= self.xlen or aligned_start_bit + byte_size >= self.xlen:
                has_room = False
        return has_room

    def add_bitfield(self, e: Bitfield) -> None:
        start_bit = 0
        if self.crosses_alignment_boundary(bits=e.bit_size, alignment_bytes=e.alignment):
            res_bits = e.bit_size if e.bit_size <= e.alignment * 8 else e.alignment * 8
            start_bit = self.get_aligned_start_bit(alignment_bytes=e.alignment, bits_to_reserve=res_bits)
        else:
            if self.data:
                start_bit = self.data[-1][1] + 1
        self.data.append((start_bit, start_bit + e.bit_size - 1))

    def add_int(self, e: Integer) -> None:
        start_bit = 0
        if self.crosses_alignment_boundary(bits=e.byte_size, alignment_bytes=e.byte_size):
            start_bit = self.get_aligned_start_bit(e.byte_size, e.byte_size)
        else:
            if self.data:
                start_bit = self.data[-1][1] + 1
        int_bits = e.byte_size * 8
        self.data.append((start_bit, start_bit + int_bits - 1))

    def crosses_alignment_boundary(self, bits: int, alignment_bytes: int) -> bool:
        """
            Verifies whether a bitfield or an int value can fit in the current
            integer register
        """
        crosses_boundary = False
        alignment_bits = alignment_bytes * 8
        bits_available = alignment_bytes * 8
        if self.data:
            bits_available = alignment_bits - self.data[-1][1] % alignment_bits
        if bits > alignment_bits:
            # With padding the bits can exceed the alignment boundary. The assumption
            # here is that the alignment_bytes still cannot cross the boundary.
            crosses_boundary = bool(bits_available - alignment_bits >= 0)
        else:
            # Without padding the bits cannot cross the alignment boundary
            crosses_boundary = bool(bits_available - bits >= 0)
        return crosses_boundary

    def get_aligned_start_bit(self, alignment_bytes: int, bits_to_reserve: int) -> int:
        """
            The assumption here is that the value crosses alignment boundary.
            Because of this, we want the next possible alignment. It is either
            in the same register, or in the next register, if the register is filled.
        """
        alignment_bits: int = alignment_bytes * 8
        aligned_start_bit: int = 0
        if self.data:
            aligned_start_bit = ceil(self.data[-1][1] / alignment_bits) * alignment_bits
            if aligned_start_bit >= self.xlen or aligned_start_bit + bits_to_reserve >= self.xlen:
                aligned_start_bit = 0
        return aligned_start_bit