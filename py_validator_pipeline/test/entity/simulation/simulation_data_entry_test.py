from unittest import TestCase

from src.entity.simulation.simulation_data_entry import SimulationDataEntry
from src.entity.dwarf.types import BaseType, ArrayType
from src.entity.dwarf.global_variable import GlobalVariable


class TestSimulationDataEntry(TestCase):
    """
    Unit tests for the core logic in the SimulationDataEntry class.

    Note:
        Formal parameters are currently not utilized in the implementation.
        As a result, tests for retrieving the first writes to formal parameters
        have not yet been implemented.
    """

    def test_last_write_to_primitive_type_global_variable_returned_correctly(self) -> None:

        entry = SimulationDataEntry()
        base_type = BaseType('float', byte_size=4)
        glob_var = GlobalVariable()
        glob_var.type_info = base_type
        glob_var.set_name('f')
        # pyelftools v0.32 returns memory address in this form
        glob_var.set_location('DW_OP_addr: 200006f4')
        entry.add_global_variables([glob_var])
        entry.dwrites['200006f0'] = [{'data': '00000000' }, {'data': '00000001' }, {'data': '00000010' }]
        entry.dwrites['200006f4'] = [{'data': '00000123'}, {'data': '00000456'}, {'data': '00000789'}]
        entry.dwrites['200006f8'] = [{'data': '00000100'}, {'data': '00000101'}, {'data': '00000110'}]

        last_glob_writes = entry.get_last_writes_to_global_var_locations()
        self.assertEqual(1, len(last_glob_writes))
        self.assertEqual('00000789', last_glob_writes['f:0']['data'])


    def test_last_writes_to_array_type_global_variable_returned_correctly(self) -> None:

        entry = SimulationDataEntry()
        base_type = BaseType('int', byte_size=4)
        arr_type = ArrayType(arr_type=base_type)
        # an array of four int elements
        arr_type.dimensions = [4]
        arr_type.length = 4

        glob_var = GlobalVariable()
        glob_var.type_info = arr_type
        glob_var.set_name('a')
        glob_var.set_location('DW_OP_addr: 20000004')
        entry.add_global_variables([glob_var])
        entry.dwrites['20000000'] = [{'data': '00000000' }, {'data': '00000000' }, {'data': '00000000' }]
        # array data begin
        entry.dwrites['20000004'] = [{'data': '00000001'}, {'data': '00000010'}, {'data': '00000011'}]
        entry.dwrites['20000008'] = [{'data': '00000100' }, {'data': '00000101' }, {'data': '00000110' }]
        entry.dwrites['2000000c'] = [{'data': '00000111' }, {'data': '00001000' }, {'data': '00001001' }]
        entry.dwrites['20000010'] = [{'data': '00001010' }, {'data': '00001011' }, {'data': '00001100' }]
        # array data end
        entry.dwrites['20000014'] = [{'data': '11111111'}, {'data': '11111111'}, {'data': '11111111'}]

        last_glob_writes = entry.get_last_writes_to_global_var_locations()
        self.assertEqual(4, len(last_glob_writes))
        self.assertEqual('00000011', last_glob_writes['a:0']['data'])
        self.assertEqual('00000110', last_glob_writes['a:1']['data'])
        self.assertEqual('00001001', last_glob_writes['a:2']['data'])
        self.assertEqual('00001100', last_glob_writes['a:3']['data'])

    def test_empty_dict_is_returned_when_no_glob_writes_for_primitive_type_are_found(self):
        entry = SimulationDataEntry()
        base_type = BaseType('float', byte_size=4)
        glob_var = GlobalVariable()
        glob_var.type_info = base_type
        glob_var.set_name('f')
        # pyelftools v0.32 returns memory address in this form
        glob_var.set_location('DW_OP_addr: 200006f4')
        entry.add_global_variables([glob_var])
        last_glob_writes = entry.get_last_writes_to_global_var_locations()
        self.assertIsInstance(last_glob_writes, dict, 'return value is not a list')
        self.assertEqual(0, len(last_glob_writes))

    def test_empty_dict_is_returned_when_no_glob_writes_for_array_type_are_found(self):
        entry = SimulationDataEntry()
        base_type = BaseType('int', byte_size=4)
        arr_type = ArrayType(arr_type=base_type)
        # an array of four int elements
        arr_type.dimensions = [4]
        arr_type.length = 4

        glob_var = GlobalVariable()
        glob_var.type_info = arr_type
        glob_var.set_name('a')
        glob_var.set_location('DW_OP_addr: 20000004')
        entry.add_global_variables([glob_var])
        last_glob_writes = entry.get_last_writes_to_global_var_locations()
        self.assertIsInstance(last_glob_writes, dict, 'return value is not a list')
        self.assertEqual(0, len(last_glob_writes))
