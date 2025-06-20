import unittest
import subprocess
import os
import tempfile

from src.dwarf_info_extractor import DwarfInfoExtractor
from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.global_variable import GlobalVariable
from src.entity.dwarf.local_variable import LocalVariable
from src.entity.dwarf.subprogram import Subprogram
from src.entity.dwarf.types import StructType, AbstractType, UnionType


class TestDwarfExtractor(unittest.TestCase):
    def setUp(self):
        # Create a temporary directory
        self.test_dir = tempfile.TemporaryDirectory()
        # Temporary source and binary files
        self.source_file = os.path.join(self.test_dir.name, 'test.c')
        self.binary_file = os.path.join(self.test_dir.name, 'test.out')

    def tearDown(self):
        # Cleanup temporary files
        self.test_dir.cleanup()

    def test_the_most_simple_c_program_is_correctly_extracted(self):
        # Given the following C program
        c_code = """
        int main() {
            return 0;
        }
        """

        # When the program is compiled with debug information
        self.generate_binary_from_c_code(c_code)

        # When DwarfInfoExtractor is initialized and information is extracted from the binary
        extractor = DwarfInfoExtractor(source_file=self.source_file, function_of_interest='main')
        result: DwarfInfo = extractor.extract_dwarf_info(binary=self.binary_file)

        # Then the returned value is an instance of DwarfInfo
        self.assertIsInstance(result, DwarfInfo)
        #  Then the returned value contains exactly one subprogram
        self.assertEqual(1, len(result.subprograms))
        # Then the name of the only subprogram is main
        sp_main = result.get_subprogram_by_name('main')
        self.assertIsInstance(sp_main, Subprogram)
        # Then the type of the only subprogram is int
        self.assertEqual('int', sp_main.type_info.get_base().type)
        # Then there are no global variables
        self.assertEqual(0, len(result.get_global_variables()))
        # Then the only subprogram main has no formal parameters
        self.assertEqual(0, len(sp_main.get_formal_parameters()))
        # Then the only subprogram main has no local variables
        self.assertEqual(0, len(sp_main.get_local_variables()))

    def test_primitive_type_as_global_variable_is_correctly_extracted(self):
        # Given the following C program
        c_code = """
                float pi = 3.14;
                
                int main() {
                    return 0;
                }
                """

        # When the program is compiled with debug information
        self.generate_binary_from_c_code(c_code)

        # When DwarfInfoExtractor is initialized and information is extracted from the binary
        extractor = DwarfInfoExtractor(source_file=self.source_file, function_of_interest='main')
        result: DwarfInfo = extractor.extract_dwarf_info(binary=self.binary_file)

        # Then there is one global variable
        self.assertEqual(1, len(result.get_global_variables()))
        # Then the name of the only global variable is pi
        glob_var: GlobalVariable = result.get_global_variables()[0]
        self.assertEqual('pi', glob_var.get_name())
        # Then the variable base type should be float
        self.assertEqual('float', glob_var.type_info.get_base().type)

    def test_formal_param_with_primitive_type_is_correctly_extracted(self):
        # Given the following C program
        c_code = """
                    int foo(int x) {
                        return x + 1;                    
                    }
    
                    int main() {
                        foo(4);
                        return 0;
                    }
                    """

        # When the program is compiled with debug information
        self.generate_binary_from_c_code(c_code)

        # When DwarfInfoExtractor is initialized and information is extracted from the binary
        extractor = DwarfInfoExtractor(source_file=self.source_file, function_of_interest='foo')
        result: DwarfInfo = extractor.extract_dwarf_info(binary=self.binary_file)

        sp_of_interest = result.get_subprogram_by_name('foo')

        # Then there is one formal parameter
        self.assertEqual(1, len(sp_of_interest.get_formal_parameters()))
        # Then the name of the only formal parameter is x
        formal_param: FormalParameter = sp_of_interest.get_formal_parameters()[0]
        self.assertEqual('x', formal_param.get_name())
        # Then the variable base type should be int
        self.assertEqual('int', formal_param.type_info.get_base().type)

    def test_local_variable_with_primitive_type_is_correctly_extracted(self):
        # Given the following C program
        c_code = """
                    float foo() {
                        float f = 1.23;
                        return f;                    
                    }

                    int main() {
                        float f = foo();
                        return 0;
                    }
                    """

        # When the program is compiled with debug information
        self.generate_binary_from_c_code(c_code)

        # When DwarfInfoExtractor is initialized and information is extracted from the binary
        extractor = DwarfInfoExtractor(source_file=self.source_file, function_of_interest='foo')
        result: DwarfInfo = extractor.extract_dwarf_info(binary=self.binary_file)

        sp_of_interest = result.get_subprogram_by_name('foo')

        # Then there is one formal parameter
        self.assertEqual(1, len(sp_of_interest.get_local_variables()))
        # Then the name of the only formal parameter is x
        local_var: LocalVariable = sp_of_interest.get_local_variables()[0]
        self.assertEqual('f', local_var.get_name())
        # Then the variable base type should be int
        self.assertEqual('float', local_var.type_info.get_base().type)

    def test_global_struct_with_bitfields_is_correctly_extracted(self):

        # Given the following C program
        c_code = """
                struct X { short x: 5; short y: 7 } x;

                int main() {
                    return 0;
                }
                """

        # When the program is compiled with debug information
        self.generate_binary_from_c_code(c_code)

        # When DwarfInfoExtractor is initialized and information is extracted from the binary
        extractor = DwarfInfoExtractor(source_file=self.source_file, function_of_interest='main')
        result: DwarfInfo = extractor.extract_dwarf_info(binary=self.binary_file)

        # Then there is one global variable
        self.assertEqual(1, len(result.get_global_variables()))
        # Then the name of the only global variable is pi
        glob_var: GlobalVariable = result.get_global_variables()[0]

        # Then the variable name should be x
        self.assertEqual('x', glob_var.get_name())

        # Then the instance of the type should be StructType
        struct_type: AbstractType = glob_var.type_info
        self.assertIsInstance(struct_type, StructType)

        # Then the variable base type should be <NA> as struct has no base type
        self.assertEqual('<NA>', glob_var.type_info.get_base().type)

        # Then the struct should have two members
        self.assertEqual(2, len(struct_type.members))

        # Then the struct members should be named x and y
        self.assertEqual('x', struct_type.members[0].name)
        self.assertEqual('y', struct_type.members[1].name)

        # Then the struct members should have correct base types
        self.assertEqual('short int', struct_type.members[0].get_base().type)
        self.assertEqual('short int', struct_type.members[1].get_base().type)

        # Then the struct members should have correct base type byte sizes
        self.assertEqual(2, struct_type.members[0].get_base().byte_size)
        self.assertEqual(2, struct_type.members[1].get_base().byte_size)

        # Then the struct members should have given bitfield sizes and correct offsets
        self.assertEqual(5, struct_type.members[0].bit_size)
        self.assertEqual(0, struct_type.members[0].bit_offset)
        self.assertEqual(7, struct_type.members[1].bit_size)
        self.assertEqual(5, struct_type.members[1].bit_offset)


    def test_union_type_is_correctly_extracted(self):
        # Given the following C program
        c_code = """
                        union X { short x; double y } x;

                        int main() {
                            return 0;
                        }
                        """

        # When the program is compiled with debug information
        self.generate_binary_from_c_code(c_code)

        # When DwarfInfoExtractor is initialized and information is extracted from the binary
        extractor = DwarfInfoExtractor(source_file=self.source_file, function_of_interest='main')
        result: DwarfInfo = extractor.extract_dwarf_info(binary=self.binary_file)

        # Then there is one global variable
        self.assertEqual(1, len(result.get_global_variables()))
        # Then the name of the only global variable is pi
        glob_var: GlobalVariable = result.get_global_variables()[0]

        # Then the variable name should be x
        self.assertEqual('x', glob_var.get_name())

        # Then the instance of the type should be StructType
        union_type: AbstractType = glob_var.type_info
        self.assertIsInstance(union_type, UnionType)

        # Then the variable base type should be <NA> as struct has no base type
        self.assertEqual('<NA>', union_type.get_base().type)

        # Then the byte size of the union should be the byte size of its largest element
        self.assertEqual(8, union_type.byte_size)


        # Then the struct should have two members
        self.assertEqual(2, len(union_type.members))

        # Then the struct members should be named x and y
        self.assertEqual('x', union_type.members[0].name)
        self.assertEqual('y', union_type.members[1].name)

        self.assertEqual('short int', union_type.members[0].get_base().type)
        self.assertEqual('double', union_type.members[1].get_base().type)


    def generate_binary_from_c_code(self, c_code: str):
        # The simplest C program case

        with open(self.source_file, 'w') as f:
            f.write(c_code)

        # Compile the C code with DWARF info
        compile_result = subprocess.run(
            ['gcc', '-g', self.source_file, '-o', self.binary_file],
            capture_output=True
        )
        self.assertEqual(compile_result.returncode, 0, f"Compilation failed: {compile_result.stderr.decode()}")
        # subprocess.run(['llvm-dwarfdump', self.binary_file])

if __name__ == '__main__':
    unittest.main()
