from dataclasses import dataclass, field
from abc import ABC, abstractmethod

@dataclass
class StructRegDataTypes(ABC):
    pass

@dataclass
class Bitfield(StructRegDataTypes):
    bit_size: int
    alignment: int

@dataclass
class Integer(StructRegDataTypes):
    byte_size: int

@dataclass
class Float(StructRegDataTypes):
    byte_size: int
