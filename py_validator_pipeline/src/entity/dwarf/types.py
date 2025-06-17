from dataclasses import dataclass, field
from typing import Optional, List, Union
from abc import ABC, abstractmethod



# Abstract base
@dataclass
class AbstractType(ABC):

    @abstractmethod
    def __str__(self):
        pass

# Concrete types
@dataclass
class BaseType(AbstractType):
    base_type: Optional[str] = None
    byte_size: Optional[int] = None
    bit_size: Optional[int] = None
    bit_offset: Optional[int] = None

    def __str__(self):
        return self.base_type or '<missing basetype>'

@dataclass
class ArrayType(AbstractType):
    base_type: Optional[AbstractType] = None
    length: Optional[int] = None

    def __str__(self):
        base_str = str(self.base_type) if self.base_type else "<unknown>"
        len_str = str(self.length) if self.length is not None else "<?>"
        return f"{base_str}[{len_str}]"

@dataclass
class PointerType(AbstractType):
    to_type: Optional[AbstractType] = None

    def __str__(self) -> str:
        return f"*{self.to_type}" if self.to_type else "*<unknown>"

@dataclass
class StructMember:
    name: Optional[str] = None
    type: Optional[AbstractType] = None

    def __str__(self) -> str:
        member_name = self.name or "<name unknown>"
        member_type = str(self.type) if self.type else "<type unknown>"
        return f"{member_type} {member_name}"


@dataclass
class StructType(AbstractType):
    name: Optional[str] = None
    members: List[StructMember] = field(default_factory=list)

    def __str__(self) -> str:
        name_str = self.name if self.name else "<name unknown>"
        members_str = "; ".join(str(member) for member in self.members)
        return f"struct {name_str} {{ {members_str}; }}"


# TODO: typedef, union
