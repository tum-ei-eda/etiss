class FrameBaseInfo:

    def __init__(self, pc, reg, offset) -> None:
        self._pc = pc
        self._reg = reg
        self._offset = offset


    def get_pc(self):
        return self._pc

    def get_reg(self):
        return self._reg

    def get_offset(self):
        return self._offset

    def __str__(self) -> str:
        result = f"    ├── pc: {self._pc}, reg value: {self._reg}, offset: {self._offset}\n"
        return result

