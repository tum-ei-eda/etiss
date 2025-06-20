from dataclasses import dataclass, field
from abc import ABC, abstractmethod

@dataclass
class StructRegDataTypes(ABC):
    """
    Abstract and concrete data types representing how fields within a struct are laid out in argument registers
    during return value classification.

    These types are used at an abstract level to model how different elements (bitfields, integers, and floats)
    occupy register space, helping simulate or verify calling convention behavior without depending on the actual
    register hardware.

    Classes:
        StructRegDataTypes (ABC): Abstract base class for struct field representations.
        Bitfield: Represents a bitfield with specific size and alignment constraints.
        Integer: Represents an integer with a given byte size.
        Float: Represents a floating-point value with a given byte size.

    Note:
        Nested structs are also supported, but they are flattened into one or more of these data types
        during struct analysis.
    """
    pass

@dataclass
class Bitfield(StructRegDataTypes):
    """
    Represents a bitfield with specific size and alignment constraints.
    """
    bit_size: int
    alignment: int

@dataclass
class Integer(StructRegDataTypes):
    """
    Represents an integer with a given byte size.
    """
    byte_size: int

@dataclass
class Float(StructRegDataTypes):
    """
    Represents a floating-point value with a given byte size.
    """
    byte_size: int
