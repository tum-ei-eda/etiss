#-------------------------------------------------------------------------------
# Based on the pyelftools examples:
# - examples/dwarf_die_tree.py
# - examples/dwarf_location_info.py
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
from argparse import Namespace
from pathlib import Path
import sys
import logging
from typing import Tuple
import argparse

from elftools.elf.elffile import ELFFile
from elftools.dwarf.descriptions import (
    describe_DWARF_expr, set_global_machine_arch)
from elftools.dwarf.locationlists import (
    LocationEntry, LocationExpr, LocationParser)
from elftools.dwarf.descriptions import describe_form_class

# Global logger
logger = logging.getLogger(__name__)

# Argument parser guides user in providing the required arguments
parser = argparse.ArgumentParser()
parser.add_argument("-b", "--bin", help="absolute path of the binary file", required=True)
parser.add_argument("-s", "--src", help="name of source code file, e.g. hello.c", required=True)
parser.add_argument("-f", "--fun", help="name of the function, e.g. foo", required=True)
args = parser.parse_args()


def process_file(binary: str, source_file: str, function: str):
    print('Processing file:', binary)
    with open(binary, 'rb') as f:
        elffile = ELFFile(f)

        if not elffile.has_dwarf_info():
            print('  file has no DWARF info')
            return

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

            indent_level = '    '
            # print(f"{indent_level}Top DIE with tag={top_DIE.tag}")

            # We're interested in the filename...
            # print(f"| {indent_level}name={Path(top_DIE.get_full_path()).as_posix()}")

            file = os.path.basename(Path(top_DIE.get_full_path()).as_posix())

            if not file == source_file:
                continue

            print(f"{file}, offset: {CU.cu_offset}, length: {CU['unit_length']} ")

            # We iterate through all direct descendants of the CU
            for child in top_DIE.iter_children():
                die_info_direct_child_of_cu(child, location_lists, loc_parser, CU, dwarf_info, function, indent_level)


def die_info_direct_child_of_cu(die, loc_list: list, loc_parser, CU, dwarfinfo, function, indent_level='    '):
    """
        For now we only want global variables and one specific function that are
        direct descendants of the compilation unit.
    """

    match die.tag:
        case 'DW_TAG_subprogram':

            if 'DW_AT_name' in die.attributes and  die.attributes['DW_AT_name'].value.decode('utf-8') == function:
                print(indent_level + 'DIE tag=%s' % die.tag, end="\n")
                for attr, value in die.attributes.items():
                    match attr:
                        case 'DW_AT_name':
                            print(f"{indent_level}  | {attr}: {value.value.decode('utf-8')}", end="\n")
                        case 'DW_AT_type':
                            print(f"{indent_level}  | {attr}={get_base_type(die.get_DIE_from_attribute('DW_AT_type'))}")
                            print(
                                f"{indent_level}  | DW_AT_byte_size={get_base_type_size(die.get_DIE_from_attribute('DW_AT_type'))}")
                        case _:
                            pass
                lowpc, highpc = get_low_and_high_pc(die)
                if lowpc and highpc:
                    print(f"{indent_level}  | {'DW_AT_low_pc'}={lowpc}")
                    print(f"{indent_level}  | {'DW_AT_high_pc'}={highpc}")
                child_indent = indent_level + '  '
                for child in die.iter_children():
                    die_info_rec(child, loc_list, loc_parser, CU, dwarfinfo, child_indent)

        case 'DW_TAG_variable':
            print(f"{indent_level} DIE tag={die.tag}")
            for attr, value in die.attributes.items():

                if attr in ['DW_AT_name']:
                    print(f"{indent_level}  | {attr}={value.value.decode('utf-8')}")
                if attr in ['DW_AT_type']:
                    print(f"{indent_level}  | {attr}={get_base_type(die.get_DIE_from_attribute('DW_AT_type'))}")
                    print(f"{indent_level}  | DW_AT_byte_size={get_base_type_size(die.get_DIE_from_attribute('DW_AT_type'))}")

                if loc_parser.attribute_has_location(value, CU['version']):
                    line = f"{indent_level}  | "
                    loc = loc_parser.parse_from_attribute(value,
                                                          CU['version'], die)
                    # We either get a list (in case the attribute is a
                    # reference to the .debug_loc section) or a LocationExpr
                    # object (in case the attribute itself contains location
                    # information).
                    if isinstance(loc, LocationExpr):
                        line += 'DW_AT_location=%s' % (
                            describe_DWARF_expr(loc.loc_expr,
                                                dwarfinfo.structs, CU.cu_offset))
                    elif isinstance(loc, list):
                        line += show_loclist(loc,
                                             dwarfinfo,
                                             'DW_AT_location=', CU.cu_offset)
                    print(line)
        case _:
            pass



def get_low_and_high_pc(DIE):
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
        print('Error: invalid DW_AT_high_pc class:',
              highpc_attr_class)
        lowpc, highpce = None, None

    return lowpc, highpc



def die_info_rec(die, loc_list: list, loc_parser, CU, dwarfinfo, indent_level='    '):
    """ A recursive function for showing information about a DIE and its
        children.
    """
    
    match die.tag:
        case 'DW_TAG_formal_parameter' | 'DW_TAG_variable':
            print(f"{indent_level} DIE tag={die.tag}")
            for attr, value in die.attributes.items():

                if attr in ['DW_AT_name']:
                    print(f"{indent_level}  | {attr}={value.value.decode('utf-8')}")
                if attr in ['DW_AT_type']:
                    print(f"{indent_level}  | {attr}={get_base_type(die.get_DIE_from_attribute('DW_AT_type'))}")
                    print(f"{indent_level}  | DW_AT_byte_size={get_base_type_size(die.get_DIE_from_attribute('DW_AT_type'))}")


                if loc_parser.attribute_has_location(value, CU['version']):
                        line = f"{indent_level}  | "
                        loc = loc_parser.parse_from_attribute(value,
                                                                CU['version'], die)
                        # We either get a list (in case the attribute is a
                        # reference to the .debug_loc section) or a LocationExpr
                        # object (in case the attribute itself contains location
                        # information).
                        if isinstance(loc, LocationExpr):
                            line += ';DW_AT_location=%s' % (
                                describe_DWARF_expr(loc.loc_expr,
                                                    dwarfinfo.structs, CU.cu_offset))
                        elif isinstance(loc, list):
                            line += show_loclist(loc,
                                                dwarfinfo,
                                                ';DW_AT_location=', CU.cu_offset)
                        print(line)
        case _:
            pass

    child_indent = indent_level + '  '
    for child in die.iter_children():
        die_info_rec(child, loc_list, loc_parser, CU, dwarfinfo, child_indent)


def show_loclist(loclist, dwarfinfo, indent, cu_offset) -> str:
    """ Display a location list nicely, decoding the DWARF expressions
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

def get_base_type_size(t) -> str:

    logger.debug("get_base_type::die")
    logger.debug(t)


    match t.tag:
        case 'DW_TAG_base_type':
            return f"{t.attributes['DW_AT_byte_size'].value}"
        case 'DW_TAG_array_type':
            try:
                at = t.get_DIE_from_attribute('DW_AT_type')
                return get_base_type_size(at)
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "NA"
        case 'DW_TAG_pointer_type':
            try:
                pt = t.get_DIE_from_attribute('DW_AT_type')
                return get_base_type_size(pt)
            except KeyError as e:
                #logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "pointer no <NO_TYPE>"
        case 'DW_TAG_const_type':
            try:
                ct = t.get_DIE_from_attribute('DW_AT_type')
                return get_base_type_size(ct)
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "NA"
        case 'DW_TAG_typedef':
            try:
                td = t.get_DIE_from_attribute('DW_AT_type')
                return f"{get_base_type_size(td)}"
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
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


def get_base_type(t) -> str:

    logger.debug("get_base_type::die")
    logger.debug(t)


    match t.tag:
        case 'DW_TAG_base_type':
            return f"{t.attributes['DW_AT_name'].value.decode('utf-8')}"
        case 'DW_TAG_array_type':
            try:
                at = t.get_DIE_from_attribute('DW_AT_type')
                return f"array of {get_base_type(at)}"
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "array of <NO_TYPE>"
        case 'DW_TAG_pointer_type':
            try:
                pt = t.get_DIE_from_attribute('DW_AT_type')
                return f"pointer to {get_base_type(pt)}"
            except KeyError as e:
                #logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "pointer to <NO_TYPE>"
        case 'DW_TAG_const_type':
            try:
                pt = t.get_DIE_from_attribute('DW_AT_type')
                return f"const {get_base_type(pt)}"
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "const of <NO_TYPE>"
        case 'DW_TAG_typedef':
            try:
                pt = t.get_DIE_from_attribute('DW_AT_type')
                return f"typedef {t.attributes['DW_AT_name'].value.decode('utf-8')} of type {get_base_type(pt)}"
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "typedef of <NO_TYPE>"
        case 'DW_TAG_structure_type':
            try:
                return f"struct {t.attributes['DW_AT_name'].value.decode('utf-8')}"
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "struct <NO_NAME>"
        case 'DW_TAG_class_type':
            try:
                return f"class {t.attributes['DW_AT_name'].value.decode('utf-8')}"
            except KeyError as e:
                # logger.error(f"KeyError: {e}, caused by {t}")
                print(f"KeyError: {e}, caused by {t}")
                return "class <NO_DEFINITION>"
        case _:
            return ""


def init_logger() -> None:
    # Clear existing handlers (if running multiple times, like in Jupyter or REPL)
    logger.handlers.clear()

    # Set logging level for the logger
    logger.setLevel(logging.INFO)

    # File handler
    file_handler = logging.FileHandler('pyelftools_test.log')
    file_handler.setLevel(logging.DEBUG)

    # Console handler
    console_handler = logging.StreamHandler()
    console_handler.setLevel(logging.INFO)

    # Formatter
    formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(formatter)
    console_handler.setFormatter(formatter)

    # Add handlers to the logger
    logger.addHandler(file_handler)
    logger.addHandler(console_handler)




if __name__ == '__main__':
    init_logger()

    # logger.info('BEGIN')
    process_file(binary=args.bin, source_file=args.src, function=args.fun)



    # logger.info('END')

    # if sys.argv[1] == '--test':
    #     for filename in sys.argv[2:]:
    #         process_file(filename)