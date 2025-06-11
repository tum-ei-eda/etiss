import logging
from abc import ABCMeta, abstractmethod
from typing import Any, Dict, List

class SingletonABCMeta(ABCMeta):
    _instances = {}

    def __call__(cls, *args, **kwargs):
        if cls not in cls._instances:
            instance = super().__call__(*args, **kwargs)
            cls._instances[cls] = instance
        return cls._instances[cls]

class MArchBase(metaclass=SingletonABCMeta):
    """
        A super class for all machine architecture files. Extend this class
        and implement its methods to expand support to a new architecture.
        Additionally add the new architecture to the MArchManager class.

        Note: due to circular import it became difficult to add type
        hints to method parameters. The entry parameters are instances
        of SimulationDataEntry
    """

    def __init__(self):
        self.logger = logging.getLogger(__name__)

    @abstractmethod
    def fetch_int_return_value(self, entry) -> Any:
        """
            Returns the int return value from the given simulation data
            entries, if possible. In case the return value register has
            the same value as it had during function prologue, the
            return value should be considered to be inconclusive.
        """
        pass

    @abstractmethod
    def fetch_unsigned_int_return_value(self, entry) -> Any:
        """
            Returns the unsigned int return value from the given simulation
            data entries, if possible. In case the return value register has
            the same value as it had during function prologue, the
            return value should be considered to be inconclusive.
        """
        pass

    @abstractmethod
    def fetch_char_return_value(self, entry) -> Any:
        """
            Returns the char return value from the given simulation
            data entries, if possible. In case the return value register has
            the same value as it had during function prologue, the
            return value should be considered to be inconclusive.
        """

    @abstractmethod
    def fetch_float_return_value(self, entry) -> Any:
        """
            Returns the float return value from the given simulation data
            entries, if possible. In case the return value register has
            the same value as it had during function prologue, the
            return value should be considered to be inconclusive.
        """
        pass

    @abstractmethod
    def fetch_long_return_value(self, entry) -> Any:
        """
            Returns the long return value from the given simulation data
            entries, if possible. In case the return value register has
            the same value as it had during function prologue, the
            return value should be considered to be inconclusive.
        """
        pass

    @abstractmethod
    def fetch_double_return_value(self, entry) -> Any:
        """
            Returns the double return value from the given simulation data
            entries, if possible. In case the return value register has
            the same value as it had during function prologue, the
            return value should be considered to be inconclusive.
        """
        pass

    @abstractmethod
    def get_march_name(self) -> str:
        """
            This method should return a str representation of the machine architecture.
            The formatting of the string should match the ELF machine architecture
            string representation, e.g. 'rv32imafdc_zicsr_zifencei'
        """
        pass

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