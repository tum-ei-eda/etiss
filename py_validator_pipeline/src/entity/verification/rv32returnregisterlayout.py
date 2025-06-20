from dataclasses import dataclass, field
from typing import List, Tuple
from math import ceil

from src.entity.verification.struct_reg_data_types import Bitfield, Integer, Float


@dataclass
class RV32ReturnRegisterLayout:
    """
    Represents an abstract layout of a return value in a general-purpose or floating-point register for RV32 targets.

    This structure is used to describe how return values (e.g., integers, bitfields, floats) would be placed into
    argument registers based on size and alignment, without assuming actual hardware register availability.

    The final, architecture-specific mapping of these abstract layouts to physical registers is handled separately
    in the verification phase.

    Attributes:
        xlen (int): Register width in bits (e.g., 32 for RV32).
        float (bool): Indicates whether this is a floating-point register placeholder.
        data (List[Tuple[int, int]]): List of bit ranges (start_bit, end_bit) representing reserved fields.
    """
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
        Determine if reserving a given number of bits crosses a specified alignment boundary.

        This method checks whether a bitfield or integer value of size `bits_to_reserve` bits,
        when placed in the current register position, would span across an alignment boundary
        defined by `alignment_bytes`.

        Args:
            bits_to_reserve (int): Number of bits to be reserved in the current register.
            alignment_bytes (int): Alignment boundary size in bytes.

        Returns:
            bool: True if the reserved bits cross the alignment boundary, False otherwise.
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
        """
        Check if there is enough space remaining in the current register to store an integer of given byte size.

        Args:
            byte_size (int): Size of the integer in bytes.

        Returns:
            bool: True if the integer fits within the register boundaries, False otherwise.
        """
        has_room = True
        alignment_bits: int = byte_size * 8
        if self.data:
            aligned_start_bit = ceil(self.data[-1][1] / alignment_bits) * alignment_bits
            if aligned_start_bit >= self.xlen or aligned_start_bit + byte_size >= self.xlen:
                has_room = False
        return has_room

    def add_bitfield(self, e: Bitfield) -> None:
        """
        Add a bitfield to the current register layout, respecting alignment boundaries.

        If the bitfield crosses an alignment boundary, it adjusts the start bit to the next aligned position.
        Otherwise, it appends the bitfield immediately after the last reserved bits.

        Args:
            e (Bitfield): The bitfield object containing size and alignment information.

        Side Effects:
            Updates the internal data structure with the bitfield's start and end bit positions.


        TODO:
            Use `has_room_for_bitfield()` or an appropriate capacity check to verify that the bitfield fits
            before appending it. If it does not fit, raise an exception instead of silently overflowing.
            This method is called externally and must enforce register bounds safety.
        """
        start_bit = 0
        if self.crosses_alignment_boundary(bits_to_reserve=e.bit_size, alignment_bytes=e.alignment):
            res_bits = e.bit_size if e.bit_size <= e.alignment * 8 else e.alignment * 8
            start_bit = self._get_aligned_start_bit(alignment_bytes=e.alignment, bits_to_reserve=res_bits)
        else:
            if self.data:
                start_bit = self.data[-1][1] + 1
        self.data.append((start_bit, start_bit + e.bit_size - 1))

    def add_int(self, e: Integer) -> None:
        """
        Add an integer value to the current register layout, ensuring proper alignment.

        If adding the integer crosses its alignment boundary, the start bit is adjusted to the next aligned position.
        Otherwise, the integer is placed immediately after the last reserved bits.

        Args:
            e (Integer): The integer object containing size (in bytes) and alignment information.

        Side Effects:
            Updates the internal data structure with the integer's start and end bit positions.

        TODO:
            Use `has_room_for_int()` or an appropriate capacity check to verify that the bitfield fits
            before appending it. If it does not fit, raise an exception instead of silently overflowing.
            This method is called externally and must enforce register bounds safety.
        """
        start_bit = 0
        if self.crosses_alignment_boundary(bits_to_reserve=e.byte_size, alignment_bytes=e.byte_size):
            start_bit = self._get_aligned_start_bit(e.byte_size, e.byte_size)
        else:
            if self.data:
                start_bit = self.data[-1][1] + 1
        int_bits = e.byte_size * 8
        self.data.append((start_bit, start_bit + int_bits - 1))


    def add_float(self, e: Float) -> None:
        """
        Add a floating-point value to the register layout, assuming it starts at bit 0.

        This method reserves a bit range for the float based on its byte size,
        and appends it as the first and only value in the layout.

        Args:
            e (Float): The floating-point value with its size in bytes.

        Side Effects:
            Updates the internal data structure with the float's bit range.
        TODO:
            Improve fault handling by verifying that the register is in a clean state
            before modification. Specifically, check that:
                1. The internal data (bit layout) is empty.
                2. The relevant boolean flag 'float' is asserted.
            This can help prevent unexpected overwrites or layout corruption.
        """
        end = e.byte_size * 8 - 1
        self.data.append((0, end))

    def get_float_size(self) -> int:
        size = 0
        if not self.data:
            size = 0
        return (self.data[-1][1] + 1) // 8


    def _get_aligned_start_bit(self, alignment_bytes: int, bits_to_reserve: int) -> int:
        """
        Calculates the next aligned bit position for placing a new value that
        crosses an alignment boundary.

        This function ensures that the starting bit position of the value is
        properly aligned based on the given alignment (in bytes). If the current
        register is full or the aligned position would overflow the register width
        (`xlen`), the alignment is reset to 0, implying the value will be placed
        in the next register.

        Args:
            alignment_bytes (int): Alignment requirement in bytes.
            bits_to_reserve (int): Number of bits that need to be reserved for the value.

        Returns:
            int: Bit offset at which the value should be placed, aligned as required.
        """
        alignment_bits: int = alignment_bytes * 8
        aligned_start_bit: int = 0
        if self.data:
            aligned_start_bit = ceil(self.data[-1][1] / alignment_bits) * alignment_bits
            if aligned_start_bit >= self.xlen or aligned_start_bit + bits_to_reserve >= self.xlen:
                aligned_start_bit = 0
        return aligned_start_bit

    def is_empty(self) -> bool:
        """Check if the register is empty."""
        return bool(len(self.data) == 0)

    def __str__(self) -> str:
        output = 'Reg(type='
        if self.float:
            output += 'float'
        else:
            output += 'int'
        output += f", defined bits: {','.join([str(e) for e in self.data])})"
        return output