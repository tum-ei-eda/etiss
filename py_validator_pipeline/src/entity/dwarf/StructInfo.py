from typing import List
from src.entity.dwarf.AbstractTypeInfo import AbstractTypeInfo


class StructInfo(AbstractTypeInfo):

    def __init__(self):
        super().__init__()
        self.name = "struct"
        self.byte_size = 0
        self.members: List[AbstractTypeInfo] = []
        self.description = self.get_description()

    def get_members(self) -> List[AbstractTypeInfo]:
        return self.members

    def add_member(self, member: AbstractTypeInfo):
        self.members.append(member)

    def get_description(self) -> str:
        # Example of output: { float x; int y; }
        return "{" + ''.join(
            [f'{m.description} {m.name}; ' for m in self.members]) + "}"

