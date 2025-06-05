#-------------------------------------------------------------------------------
# Based on the pyelftools examples:
# - examples/dwarf_die_tree.py
# - examples/dwarf_location_info.py
# - examples/dwarf_decode_address.py
# For the original sources please see:
#    https://github.com/eliben/pyelftools
#
# The purpose of this script is to print out the following information:
# - A given subprogram and
#   - Global variables (static & external) in the scope of the 
#     subprogram with their locations and types
#   - parameters, their locations and their types
#   - local variables, their locations and their types
#-------------------------------------------------------------------------------
import os
from pathlib import Path
import logging

from elftools.elf.elffile import ELFFile
from elftools.dwarf.descriptions import (
    describe_DWARF_expr, set_global_machine_arch)
from elftools.dwarf.locationlists import (
    LocationEntry, LocationExpr, LocationParser)
from elftools.dwarf.descriptions import describe_form_class

from src.entity.dwarf_info import  DwarfInfo

from src.entity.global_variable import GlobalVariable
from src.entity.formal_parameter import FormalParameter
from src.entity.local_variable import LocalVariable

from src.entity.type_construct import TypeConstruct

class DwarfInfoExtractor:

    def __init__(self, binary: str,source_file: str, function: str, debug: bool=False ):
        self.logger = logging.getLogger(__name__)
        self.extracted_dwarf_info = DwarfInfo()
        self.extracted_dwarf_info.set_source_file(source_file)
        self.extracted_dwarf_info.set_binary_name(binary)
        self.extracted_dwarf_info.set_function_of_interest(function)

        self.debug_output = ""

        self.binary = binary
        self.source_file = source_file
        self.function = function
        self.debug = debug


    def get_dwarf_info(self) -> DwarfInfo:
        return self.extracted_dwarf_info

    def extract_dwarf_info(self) -> None:
        self.logger.info(f'Processing file: {self.binary}')

        with open(self.binary, 'rb') as f:
            elffile = ELFFile(f)

            if not elffile.has_dwarf_info():
                self.logger.error('  file has no DWARF info')
                raise Exception('File has no DWARF info')

            # get_dwarf_info returns a DWARFInfo context object, which is the
            # starting point for all DWARF-based processing in pyelftools.
            dwarf_info_context_object = elffile.get_dwarf_info()

            # The location lists are extracted by DWARFInfo from the .debug_loc
            # section, and returned here as a LocationLists object.
            location_lists = dwarf_info_context_object.location_lists()

            # This is required for the descriptions module to correctly decode
            # register names contained in DWARF expressions.
            set_global_machine_arch(elffile.get_machine_arch())

            # Create a LocationParser object that parses the DIE attributes and
            # creates objects representing the actual location information.
            loc_parser = LocationParser(location_lists)

            for CU in dwarf_info_context_object.iter_CUs():
                # DWARFInfo allows to iterate over the compile units contained in
                # the .debug_info section. CU is a CompileUnit object, with some
                # computed attributes (such as its offset in the section) and
                # a header which conforms to the DWARF standard. The access to
                # header elements is, as usual, via item-lookup.
                # print('  Found a compile unit at offset %s, length %s' % (CU.cu_offset, CU['unit_length']))

                # Start with the top DIE, the root for this CU's DIE tree
                top_DIE = CU.get_top_DIE()
                self.extract_architecture_information(top_DIE)

                indent_level = '    '
                # print(f"{indent_level}Top DIE with tag={top_DIE.tag}")

                # We're interested in the filename...
                # print(f"| {indent_level}name={Path(top_DIE.get_full_path()).as_posix()}")

                file = os.path.basename(Path(top_DIE.get_full_path()).as_posix())

                # We are only interested in the CU for a specific source file
                if not file == self.source_file:
                    continue

                self.logger.info(f"{file}, offset: {CU.cu_offset}, length: {CU['unit_length']}\n")

                # We iterate through all direct descendants of the CU
                for child in top_DIE.iter_children():
                    self.die_extract_recurser(child, location_lists, loc_parser, CU, dwarf_info_context_object, self.function, indent_level)


    def die_extract_recurser(self, die, loc_list: list, loc_parser, CU, dwarfinfo, function, indent_level='    ', global_level=True):
        """
            This recurses extracts any global variables, the subprogram of interest
            and the formal parameters and local variables of the subprogram of
            interest
        """
        match die.tag:
            case 'DW_TAG_subprogram':
                # Case of subprogram. We are only interested in the subroutine specified by the user.
                if 'DW_AT_name' in die.attributes and  die.attributes['DW_AT_name'].value.decode('utf-8') == function:
                    # A subprogram may not have type, so we create type_info before iterating attributes
                    type_info = TypeConstruct()

                    for attr, value in die.attributes.items():
                        match attr:
                            case 'DW_AT_name':
                                fun_name = value.value.decode('utf-8')
                                self.extracted_dwarf_info.set_subprogram_name(fun_name)
                            case 'DW_AT_type':
                                die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                                self.extract_type_information(die_from_attr, type_info)
                            case _:
                                pass

                    self.extracted_dwarf_info.set_subprogram_type_information(type_info)
                    lowpc, highpc = self.get_low_and_high_pc(die)
                    self.extracted_dwarf_info.set_subprogram_low_and_high_pc(lowpc, highpc)


                    """
                        We also want to extract formal parameters and local variables
                        as we recurse, the level is no longer global. This affects how
                        variables are extracted.
                    """
                    child_indent = indent_level + '  '
                    for child in die.iter_children():
                        self.die_extract_recurser(child, loc_list, loc_parser, CU, dwarfinfo, child_indent, global_level=False)
            case 'DW_TAG_variable':
                # Case of global variable
                if global_level:
                    var = GlobalVariable()
                else:
                    var = LocalVariable()

                for attr, value in die.attributes.items():

                    if attr in ['DW_AT_name']:
                        var_name = value.value.decode('utf-8')
                        var.set_name(var_name)
                    if attr in ['DW_AT_type']:

                        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                        type_info = TypeConstruct()
                        self.extract_type_information(die_from_attr, type_info)
                        var.create_type_information(type_info)

                    if loc_parser.attribute_has_location(value, CU['version']):
                        loc = loc_parser.parse_from_attribute(value, CU['version'], die)
                        loc_output = self.get_location_output(loc, dwarfinfo, CU)
                        if loc_output != "":
                            var.set_location(loc_output)
                if global_level:
                    self.extracted_dwarf_info.add_global_variable(var)
                else:
                    self.extracted_dwarf_info.add_local_variable(var)
            case 'DW_TAG_formal_parameter':
                # Formal parameter for the subprogram of interest
                formal_param = FormalParameter()
                if self.debug:
                    self.debug_output += f"{indent_level} DIE tag={die.tag}\n"
                for attr, value in die.attributes.items():
                    if attr in ['DW_AT_name']:
                        param_name = die.attributes['DW_AT_name'].value.decode('utf-8')
                        formal_param.set_name(param_name)
                    if attr in ['DW_AT_type']:
                        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                        type_info = TypeConstruct()
                        self.extract_type_information(die_from_attr, type_info)
                        formal_param.create_type_information(type_info)
                    if loc_parser.attribute_has_location(value, CU['version']):
                        line_prefix = f"{indent_level}  | "
                        loc = loc_parser.parse_from_attribute(value, CU['version'], die)
                        loc_output = self.get_location_output(loc, dwarfinfo, CU)
                        if loc_output != "":
                            formal_param.set_location(loc_output)
                self.extracted_dwarf_info.add_formal_parameter(formal_param)
            case _:
                pass

    def get_location_output(self, loc, dwarfinfo, CU):
        # We either get a list (in case the attribute is a
        # reference to the .debug_loc section) or a LocationExpr
        # object (in case the attribute itself contains location
        # information).
        loc_output = ""

        if isinstance(loc, LocationExpr):
            loc_output += describe_DWARF_expr(loc.loc_expr, dwarfinfo.structs, CU.cu_offset)
        elif isinstance(loc, list):
            loc_output += self.show_loclist(loc, dwarfinfo, '', CU.cu_offset)

        return loc_output

    def show_loclist(self, loclist, dwarfinfo, indent, cu_offset) -> str:
        """
            Display a location list nicely, decoding the DWARF expressions
            contained within.
        """
        d = []
        for loc_entity in loclist:
            if isinstance(loc_entity, LocationEntry):
                d.append('%s <<%s>>' % (
                    loc_entity,
                    describe_DWARF_expr(loc_entity.loc_expr, dwarfinfo.structs, cu_offset)))
            else:
                d.append(str(loc_entity))
        return '\n'.join(indent + s for s in d)

    def get_low_and_high_pc(self, DIE):
        lowpc = DIE.attributes['DW_AT_low_pc'].value

        # DWARF v4 in section 2.17 describes how to interpret the
        # DW_AT_high_pc attribute based on the class of its form.
        # For class 'address' it's taken as an absolute address
        # (similarly to DW_AT_low_pc); for class 'constant', it's
        # an offset from DW_AT_low_pc.
        highpc_attr = DIE.attributes['DW_AT_high_pc']
        highpc_attr_class = describe_form_class(highpc_attr.form)
        if highpc_attr_class == 'address':
            highpc = highpc_attr.value
        elif highpc_attr_class == 'constant':
            highpc = lowpc + highpc_attr.value
        else:
            self.logger.error('Error: invalid DW_AT_high_pc class:',highpc_attr_class)
            lowpc, highpce = None, None

        return lowpc, highpc


    def extract_architecture_information(self, top_die):
        """
            Extracts architecture information from the top DIE compile unit
        """
        if not top_die.attributes['DW_AT_producer']:
            self.logger.warning("Core information (DW_AT_producer) not found from DWARF top DIE")
        else:
            producer_string = top_die.attributes['DW_AT_producer'].value.decode('utf-8')
            self.extracted_dwarf_info.extract_core_information(producer_string)


    def extract_type_information(self, t, type_construct: TypeConstruct) -> None:
        """
            A recursive method that extracts the type information from the DIE tree.
        """
        match t.tag:
            case 'DW_TAG_base_type':
                base_type = t.attributes['DW_AT_name'].value.decode('utf-8')
                base_type_byte_size = int(t.attributes['DW_AT_byte_size'].value)

                type_construct.create_type_information(base_type, base_type_byte_size)
            case 'DW_TAG_array_type':
                try:
                    at = t.get_DIE_from_attribute('DW_AT_type')
                    type_construct.add_element_to_description_list("array of")
                    arr_range = self.compute_array_size_from_subranges(t)
                    type_construct.add_element_to_range_list(arr_range)
                    self.extract_type_information(at, type_construct)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    type_construct.add_element_to_description_list("array of <NO_TYPE>")
            case 'DW_TAG_pointer_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    type_construct.add_element_to_description_list("pointer to")
                    self.extract_type_information(pt, type_construct)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    type_construct.add_element_to_description_list("pointer to <NO_TYPE>")
            case 'DW_TAG_const_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    type_construct.add_element_to_description_list("const")
                    self.extract_type_information(pt, type_construct)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    type_construct.add_element_to_description_list("const of <NO_TYPE>")
            case 'DW_TAG_typedef':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    type_construct.add_element_to_description_list("typedef")
                    type_construct.add_element_to_description_list(f"{t.attributes['DW_AT_name'].value.decode('utf-8')}")
                    type_construct.add_element_to_description_list("of type")
                    self.extract_type_information(pt, type_construct)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    type_construct.add_element_to_description_list("typedef of <NO_TYPE>")
            case 'DW_TAG_structure_type':
                try:
                    type_construct.add_element_to_description_list("struct")
                    type_construct.add_element_to_description_list(f"{t.attributes['DW_AT_name'].value.decode('utf-8')}")
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    type_construct.add_element_to_description_list("struct <NO_NAME>")
            case 'DW_TAG_class_type':
                try:
                    type_construct.add_element_to_description_list("class")
                    type_construct.add_element_to_description_list(f"{t.attributes['DW_AT_name'].value.decode('utf-8')}")
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    type_construct.add_element_to_description_list("class <NO DEFINITION>")
            case _:
                pass


    @staticmethod
    def compute_array_size_from_subranges(arr_die) -> int:
        """
            A helper that iterates through array DIEs children
            to determine the total number of array elements.
            Arrays can be multidimensional.

            Currently only supports subranges. Enumeration support
            is not implemented.
        """
        arr_size = 1
        for die in arr_die.iter_children():

            if die.tag == 'DW_TAG_subrange_type':
                upper_bound = int(die.attributes['DW_AT_upper_bound'].value)
                lower_bound = 0
                range = 0
                if die.attributes.get('DW_AT_lower_bound'):
                    lower_bound = int(die.attributes['DW_AT_lower_bound'].value)
                arr_size *= (upper_bound - lower_bound + 1)
        return arr_size

