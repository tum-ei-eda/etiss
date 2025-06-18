from collections import namedtuple
from dataclasses import dataclass, field
from typing import Optional, List, Union
from abc import ABC, abstractmethod


# Abstract base
@dataclass
class AbstractType(ABC):

    @abstractmethod
    def __str__(self):
        pass

    @abstractmethod
    def get_base(self) -> namedtuple:
        pass

    @abstractmethod
    def get_range(self) -> int:
        pass

# Concrete types
@dataclass
class BaseType(AbstractType):
    base_type: Optional[str] = None
    byte_size: Optional[int] = None

    def __str__(self):
        return self.base_type or '<missing basetype>'

    def get_base(self) -> namedtuple:
        Base = namedtuple('Base', ['type', 'byte_size'])
        return Base(type=self.base_type, byte_size=self.byte_size)

    def get_range(self) -> int:
        return self.byte_size


@dataclass
class ConstType(AbstractType):
    const_type: AbstractType

    def get_base(self) -> namedtuple:
        return self.const_type.get_base()

    def get_range(self) -> int:
        return self.const_type.get_range()

    def __str__(self):
        base_str = str(self.const_type) if self.const_type is not None else '<type unknown>'
        return f"const {base_str}"


@dataclass
class TypeDef(AbstractType):
    base_type: AbstractType
    name: Optional[str] = None

    def get_base(self) -> namedtuple:
        return self.base_type.get_base()

    def get_range(self) -> int:
        return self.base_type.get_range()

    def __str__(self):
        name_str = self.name if self.name is not None else '<name unknown>'
        base_str = str(self.base_type) if self.base_type is not None else '<type unknown>'
        return f"typedef {base_str} {name_str}"


@dataclass
class ArrayType(AbstractType):
    arr_type: AbstractType
    dimensions: List[int] = field(default_factory=list)
    length: Optional[int] = None

    def get_base(self) -> namedtuple:
        return self.arr_type.get_base()

    def get_range(self) -> int:
        return self.length * self.arr_type.get_range()

    def __str__(self):
        base_str = str(self.arr_type) if self.arr_type else "<type unknown>"
        return f"{base_str}{''.join([ f'[{d}]' for d in self.dimensions ])}"

@dataclass
class PointerType(AbstractType):
    to_type: AbstractType

    def get_base(self) -> namedtuple:
        return self.to_type.get_base()

    def get_range(self) -> int:
        return self.to_type.get_range()

    def __str__(self) -> str:
        return f"*{self.to_type}" if self.to_type else "*<type unknown>"

@dataclass
class StructMember:
    member_type: AbstractType
    name: Optional[str] = None
    bit_size: Optional[int] = None
    bit_offset: Optional[int] = None

    def get_base(self) -> namedtuple:
        return self.member_type.get_base()

    def get_range(self) -> int:
        return self.member_type.get_range()

    def __str__(self) -> str:
        member_name = self.name or "<name unknown>"
        member_type = str(self.member_type) if self.member_type else "<type unknown>"
        bitfield = ""
        if self.bit_size is not None:
            bitfield = bitfield + f": {self.bit_size}"
        return f"{member_type} {member_name}{bitfield}"


@dataclass
class StructType(AbstractType):
    name: Optional[str] = None
    byte_size: Optional[int] = None
    members: List[StructMember] = field(default_factory=list)

    def get_base(self) -> namedtuple:
        Base = namedtuple('Base', ['type', 'byte_size'])
        return Base(type='<NA>', byte_size=self.byte_size)

    def get_range(self) -> int:
        return self.byte_size

    def __str__(self) -> str:
        name_str = self.name if self.name else "<name unknown>"
        members_str = "; ".join(str(member) for member in self.members)
        return f"struct {name_str} {{ {members_str}; }}"


# TODO: union
