from dataclasses import dataclass, field
from typing import List, Tuple, Optional
from math import ceil

from src.entity.verification.struct_reg_data_types import Bitfield, Integer, Float


@dataclass
class RV32Register:
    xlen: int
    float: bool = False
    data: List[Tuple[int, int]] = field(default_factory=list)

    def has_room_for_bitfield(self, bits_to_reserve: int, alignment_bytes: int) -> bool:
        """
        Determine if a bitfield with a given size and alignment can be packed
        into the current register word without crossing an alignment boundary.

        Args:
            bits_to_reserve: Number of bits the field needs
            alignment_bytes: Alignment requirement of the base type (e.g., 2 for short)

        Returns:
            True if the bitfield can be packed in the current word; False otherwise.
        """
        alignment_bits = alignment_bytes * 8
        current_bit_offset = 0

        if self.data:
            last_end_bit = self.data[-1][1]
            current_bit_offset = last_end_bit + 1

        # Check if the bit value crosses the alignment boundary
        aligned_base = (current_bit_offset // alignment_bits) * alignment_bits
        # Padding can cross alignment boundary
        bits_to_consider = bits_to_reserve
        if bits_to_reserve > alignment_bits:
            bits_to_consider = alignment_bits

        end_of_field = current_bit_offset + bits_to_consider - 1

        crosses_boundary = (end_of_field // alignment_bits) != (current_bit_offset // alignment_bits)

        # Make sure bits fit in to the register
        fits_in_register = end_of_field < self.xlen

        return not crosses_boundary and fits_in_register


    def crosses_alignment_boundary(self, bits_to_reserve: int, alignment_bytes: int) -> bool:
        """
            Verifies whether a bitfield or an int value can fit in the current
            integer register
        """
        alignment_bits = alignment_bytes * 8
        current_bit_offset = 0

        if self.data:
            last_end_bit = self.data[-1][1]
            current_bit_offset = last_end_bit + 1

        # Padding can cross alignment boundary
        bits_to_consider = bits_to_reserve
        if bits_to_reserve > alignment_bits:
            bits_to_consider = alignment_bits

        end_of_field = current_bit_offset + bits_to_consider - 1

        crosses_boundary = (end_of_field // alignment_bits) != (current_bit_offset // alignment_bits)

        return crosses_boundary

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
        if self.crosses_alignment_boundary(bits_to_reserve=e.bit_size, alignment_bytes=e.alignment):
            res_bits = e.bit_size if e.bit_size <= e.alignment * 8 else e.alignment * 8
            start_bit = self.get_aligned_start_bit(alignment_bytes=e.alignment, bits_to_reserve=res_bits)
        else:
            if self.data:
                start_bit = self.data[-1][1] + 1
        print(f"Adding bitfield value for bit {start_bit} to bit {start_bit + e.bit_size - 1}")
        self.data.append((start_bit, start_bit + e.bit_size - 1))

    def add_int(self, e: Integer) -> None:
        start_bit = 0
        if self.crosses_alignment_boundary(bits_to_reserve=e.byte_size, alignment_bytes=e.byte_size):
            start_bit = self.get_aligned_start_bit(e.byte_size, e.byte_size)
        else:
            if self.data:
                start_bit = self.data[-1][1] + 1
        int_bits = e.byte_size * 8
        self.data.append((start_bit, start_bit + int_bits - 1))


    def add_float(self, e: Float):
        end = e.byte_size * 8 - 1
        self.data.append((0, end))

    def get_float_size(self) -> int:
        size = 0
        if not self.data:
            size = 0
        return (self.data[-1][1] + 1) // 8


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

    def is_empty(self) -> bool:
        return bool(len(self.data) == 0)