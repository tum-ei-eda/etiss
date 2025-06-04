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
import re
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

class DwarfInfoExtractor:

    def __init__(self, binary: str,source_file: str, function: str, debug: bool=False ):
        self.logger = logging.getLogger(__name__)
        self.dwarf_info_instance = DwarfInfo()
        self.debug_output = ""

        self.binary = binary
        self.source_file = source_file
        self.function = function
        self.debug = debug


    def extract_architecture_information(self, top_die):
        # producer_string = 'GNU C17 13.2.0 -mabi=ilp32 -misa-spec=20191213 -march=rv32imac_zicsr -g -g'
        if not top_die.attributes['DW_AT_producer']:
            self.logger.warning("Core information (DW_AT_producer) not found from DWARF top DIE")
        else:
            producer_string = top_die.attributes['DW_AT_producer'].value.decode('utf-8')

            self.dwarf_info_instance.extract_core_information(producer_string)


    def get_dwarf_info(self) -> DwarfInfo:
        return self.dwarf_info_instance

    def extract(self) -> None:

        print(self.logger.getEffectiveLevel())  # Should be 20 (INFO)
        self.logger.info(f'Processing file: {self.binary}')
        with open(self.binary, 'rb') as f:
            elffile = ELFFile(f)

            if not elffile.has_dwarf_info():
                self.logger.error('  file has no DWARF info')
                raise Exception('File has no DWARF info')

            # get_dwarf_info returns a DWARFInfo context object, which is the
            # starting point for all DWARF-based processing in pyelftools.
            dwarf_info = elffile.get_dwarf_info()

            # The location lists are extracted by DWARFInfo from the .debug_loc
            # section, and returned here as a LocationLists object.
            location_lists = dwarf_info.location_lists()

            # This is required for the descriptions module to correctly decode
            # register names contained in DWARF expressions.
            set_global_machine_arch(elffile.get_machine_arch())

            # Create a LocationParser object that parses the DIE attributes and
            # creates objects representing the actual location information.
            loc_parser = LocationParser(location_lists)

            for CU in dwarf_info.iter_CUs():
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

                if self.debug:
                    self.debug_output += f"{file}, offset: {CU.cu_offset}, length: {CU['unit_length']}\n"

                # We iterate through all direct descendants of the CU
                for child in top_DIE.iter_children():
                    self.die_info_direct_child_of_cu(child, location_lists, loc_parser, CU, dwarf_info, self.function, indent_level)

        if self.debug:
            self.logger.debug(f"A more extensive output from DWARF information extraction:\n{self.debug_output}")


    def die_info_direct_child_of_cu(self, die, loc_list: list, loc_parser, CU, dwarfinfo, function, indent_level='    '):
        """
            For now we only want global variables and one specific function that are
            direct descendants of the compilation unit.
        """
        match die.tag:

            case 'DW_TAG_subprogram':

                if 'DW_AT_name' in die.attributes and  die.attributes['DW_AT_name'].value.decode('utf-8') == function:
                    if self.debug:
                        self.debug_output += f"{indent_level}DIE tag={die.tag}\n"
                    for attr, value in die.attributes.items():
                        match attr:

                            case 'DW_AT_name':
                                fun_name = value.value.decode('utf-8')
                                self.dwarf_info_instance.set_subprogram_name(fun_name)
                                if self.debug:
                                    self.debug_output += f"{indent_level}  | {attr}: {fun_name}\n"
                            case 'DW_AT_type':
                                # TODO: add total size (range)
                                die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                                type_description = self.get_type_composition(die_from_attr)
                                base_type_size = self.get_base_type_size(die_from_attr)

                                self.dwarf_info_instance.set_subprogram_base_type(self.get_base_type(die_from_attr))

                                self.dwarf_info_instance.set_subprogram_type_description(type_description)
                                self.dwarf_info_instance.set_subprogram_base_type_byte_size(base_type_size)
                                if self.debug:
                                    self.debug_output += f"{indent_level}  | {attr}={type_description}\n"
                                    self.debug_output += f"{indent_level}  | DW_AT_byte_size={base_type_size}\n"
                            case _:
                                pass
                    lowpc, highpc = self.get_low_and_high_pc(die)
                    self.dwarf_info_instance.set_subprogram_low_and_high_pc(lowpc, highpc)

                    if self.debug:
                            self.debug_output += f"{indent_level}  | {'DW_AT_low_pc'}={self.dwarf_info_instance.get_low_pc()}\n"
                            self.debug_output += f"{indent_level}  | {'DW_AT_high_pc'}={self.dwarf_info_instance.get_high_pc()}\n"
                    child_indent = indent_level + '  '
                    for child in die.iter_children():
                        self.die_info_rec(child, loc_list, loc_parser, CU, dwarfinfo, child_indent)

            case 'DW_TAG_variable':
                glob_var = GlobalVariable()
                if self.debug:
                    self.debug_output +=  f"{indent_level} DIE tag={die.tag}\n"
                for attr, value in die.attributes.items():

                    if attr in ['DW_AT_name']:
                        var_name = value.value.decode('utf-8')
                        glob_var.set_name(var_name)

                        if self.debug:
                            self.debug_output += f"{indent_level}  | {attr}={var_name}\n"
                    if attr in ['DW_AT_type']:
                        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                        type_description = self.get_type_composition(die_from_attr)
                        base_type_byte_size = self.get_base_type_size(die_from_attr)

                        glob_var.set_type_description(type_description)
                        glob_var.set_base_type_byte_size(base_type_byte_size)
                        glob_var.set_base_type(self.get_base_type(die_from_attr))

                        if self.debug:
                            self.debug_output += f"{indent_level}  | {attr}={type_description}\n"
                            self.debug_output += f"{indent_level}  | DW_AT_byte_size={base_type_byte_size}\n"

                    if loc_parser.attribute_has_location(value, CU['version']):
                        line_prefix = f"{indent_level}  | DW_AT_location="
                        loc = loc_parser.parse_from_attribute(value,
                                                              CU['version'], die)

                        loc_output = self.get_location_output(loc, dwarfinfo, CU)

                        if loc_output != "":
                            if self.debug:
                                self.debug_output += f"{line_prefix}{loc_output}\n"

                            glob_var.set_location(loc_output)
                self.dwarf_info_instance.add_global_variable(glob_var)
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



    def die_info_rec(self, die, loc_list: list, loc_parser, CU, dwarfinfo, indent_level='    '):
        """ A recursive function for showing information about a DIE and its
            children.
        """

        match die.tag:
            case 'DW_TAG_formal_parameter':
                formal_param = FormalParameter()
                if self.debug:
                    self.debug_output += f"{indent_level} DIE tag={die.tag}\n"
                for attr, value in die.attributes.items():

                    if attr in ['DW_AT_name']:
                        param_name = die.attributes['DW_AT_name'].value.decode('utf-8')
                        formal_param.set_name(param_name)

                        if self.debug:
                            self.debug_output += f"{indent_level}  | {attr}={param_name}\n"
                    if attr in ['DW_AT_type']:
                        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                        type_description = self.get_type_composition(die_from_attr)
                        base_type_byte_size = self.get_base_type_size(die_from_attr)

                        formal_param.set_type_description(type_description)
                        formal_param.set_base_type_byte_size(base_type_byte_size)
                        formal_param.set_base_type(self.get_base_type(die_from_attr))

                        if self.debug:
                            self.debug_output += f"{indent_level}  | {attr}={type_description}\n"
                            self.debug_output += f"{indent_level}  | DW_AT_byte_size={base_type_byte_size}\n"


                    if loc_parser.attribute_has_location(value, CU['version']):
                            line_prefix = f"{indent_level}  | "
                            loc = loc_parser.parse_from_attribute(value,
                                                                    CU['version'], die)
                            loc_output = self.get_location_output(loc, dwarfinfo, CU)

                            if loc_output != "":
                                if self.debug:
                                    self.debug_output += f"{line_prefix}{loc_output}\n"
                                formal_param.set_location(loc_output)
                self.dwarf_info_instance.add_formal_parameter(formal_param)
            case 'DW_TAG_variable':
                var = LocalVariable()
                if self.debug:
                    self.debug_output += f"{indent_level} DIE tag={die.tag}\n"
                for attr, value in die.attributes.items():

                    if attr in ['DW_AT_name']:
                        var_name = value.value.decode('utf-8')
                        var.set_name(var_name)

                        if self.debug:
                            self.debug_output += f"{indent_level}  | {attr}={var_name}\n"
                    if attr in ['DW_AT_type']:
                        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                        type_description = self.get_type_composition(die_from_attr)
                        base_type_byte_size = self.get_base_type_size(die_from_attr)

                        var.set_type_description(type_description)
                        var.set_base_type_byte_size(base_type_byte_size)
                        var.set_base_type(self.get_base_type(die_from_attr))

                        if self.debug:
                            self.debug_output += f"{indent_level}  | {attr}={type_description}\n"
                            self.debug_output += f"{indent_level}  | DW_AT_byte_size={base_type_byte_size}\n"

                    if loc_parser.attribute_has_location(value, CU['version']):
                        line_prefix = f"{indent_level}  | "
                        loc = loc_parser.parse_from_attribute(value,
                                                              CU['version'], die)
                        loc_output = self.get_location_output(loc, dwarfinfo, CU)

                        if loc_output != "":
                            if self.debug:
                                self.debug_output += f"{line_prefix}{loc_output}\n"
                            var.set_location(loc_output)
                self.dwarf_info_instance.add_local_variable(var)
            case _:
                pass

        child_indent = indent_level + '  '
        for child in die.iter_children():
            self.die_info_rec(child, loc_list, loc_parser, CU, dwarfinfo, child_indent)


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


    def get_base_type_size(self, t) -> str:
        match t.tag:
            case 'DW_TAG_base_type':
                return f"{t.attributes['DW_AT_byte_size'].value}"
            case 'DW_TAG_array_type':
                try:
                    at = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_base_type_size(at)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_pointer_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_base_type_size(pt)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "pointer no <NO_TYPE>"
            case 'DW_TAG_const_type':
                try:
                    ct = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_base_type_size(ct)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_typedef':
                try:
                    td = t.get_DIE_from_attribute('DW_AT_type')
                    return f"{self.get_base_type_size(td)}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_structure_type':
                return f"{t.attributes['DW_AT_byte_size'].value}"
            case 'DW_TAG_class_type':
                size = "NA"
                if 'DW_AT_byte_size' in t.attributes:
                    size = t.attributes['DW_AT_byte_size'].value
                return size
            case _:
                return ""


    def get_type_composition(self, t) -> str:
        match t.tag:
            case 'DW_TAG_base_type':
                return f"{t.attributes['DW_AT_name'].value.decode('utf-8')}"
            case 'DW_TAG_array_type':
                try:
                    at = t.get_DIE_from_attribute('DW_AT_type')
                    return f"array of {self.get_type_composition(at)}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "array of <NO_TYPE>"
            case 'DW_TAG_pointer_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return f"pointer to {self.get_type_composition(pt)}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "pointer to <NO_TYPE>"
            case 'DW_TAG_const_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return f"const {self.get_type_composition(pt)}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "const of <NO_TYPE>"
            case 'DW_TAG_typedef':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return f"typedef {t.attributes['DW_AT_name'].value.decode('utf-8')} of type {self.get_type_composition(pt)}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "typedef of <NO_TYPE>"
            case 'DW_TAG_structure_type':
                try:
                    return f"struct {t.attributes['DW_AT_name'].value.decode('utf-8')}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "struct <NO_NAME>"
            case 'DW_TAG_class_type':
                try:
                    return f"class {t.attributes['DW_AT_name'].value.decode('utf-8')}"
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "class <NO_DEFINITION>"
            case _:
                return ""


    def get_base_type(self, t):

        match t.tag:
            case 'DW_TAG_base_type':
                return f"{t.attributes['DW_AT_name'].value.decode('utf-8')}"
            case 'DW_TAG_array_type':
                try:
                    at = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_type_composition(at)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_pointer_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_type_composition(pt)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_const_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_type_composition(pt)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_typedef':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    return self.get_type_composition(pt)
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_structure_type':
                try:
                    return t.attributes['DW_AT_name'].value.decode('utf-8')
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case 'DW_TAG_class_type':
                try:
                    return t.attributes['DW_AT_name'].value.decode('utf-8')
                except KeyError as e:
                    self.logger.error(f"KeyError: {e}, caused by {t}")
                    return "NA"
            case _:
                return ""