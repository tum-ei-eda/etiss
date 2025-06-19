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
from math import prod
from typing import Any, List, Optional
import logging

from elftools.elf.elffile import ELFFile
from elftools.dwarf.descriptions import (
    describe_DWARF_expr, set_global_machine_arch)
from elftools.dwarf.locationlists import (
    LocationEntry, LocationExpr, LocationParser)
from elftools.dwarf.descriptions import describe_form_class
from elftools.dwarf.callframe import FDE

from src.entity.dwarf.dwarf_info import  DwarfInfo
from src.entity.dwarf.frame_base_info import FrameBaseInfo

from src.entity.dwarf.subprogram import Subprogram
from src.entity.dwarf.global_variable import GlobalVariable
from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.local_variable import LocalVariable

from src.entity.dwarf.types import (
    AbstractType, ArrayType, BaseType, PointerType,
    StructMember, StructType, ConstType, TypeDef, UnionType, UnionMember, VolatileType
)
from src.entity.dwarf.var_and_param_base import VarAndParamBase

from src.exception.pipeline_exceptions import DWARFExtractionException


class DwarfInfoExtractor:
    """
    Initializes a DwarfInfoExtractor instance to extract debugging information
    for a specified binary, source file, and function.

    This initializer sets up internal state including:
      - Logger instance for debug and error reporting.
      - A fresh `DwarfInfo` object to hold extracted data, with its source file,
        binary name, and target function pre-configured.
      - Storage for accumulating debug output.
      - Basic metadata attributes for the binary, source file, target function,
        and debug mode flag.

    Parameters:
        source_file (str): The source file associated with the debugging information.
        function_of_interest (str): The name of the function whose debugging info is to be extracted.

    TODO:
        - Consider redesigning `DwarfInfoExtractor` as a singleton to shield
          from repeated instantiation.
    """

    def __init__(self, source_file: str, function_of_interest: str):
        self.logger = logging.getLogger(__name__)
        self.source_file = source_file
        self.function_of_interest = function_of_interest


    def extract_dwarf_info(self, binary: str) -> DwarfInfo:
        """
        Extracts DWARF debugging information from the target binary and populates
        an internal DwarfInfo object with data relevant to the specified source file
        and function of interest.

        This is the main entry point for triggering DWARF extraction and should be
        called externally to initiate the parsing process. It performs the following steps:

        - Opens the binary ELF file and verifies that it contains DWARF information.
        - Initializes a DWARF context, location list parser, and architecture decoding setup.
        - Iterates over all compilation units (CUs) and filters them by the given source file.
        - Extracts architecture and producer information from each CU's top DIE.
        - Recursively traverses the CU's DIE tree to locate the target subprogram, global variables,
          local variables, and formal parameters, storing them in the internal data structure.
        - Extracts call frame address (CFA) register values and offsets for the matched subprogram.

        Raises:
            Exception: If the binary does not contain DWARF information.

        TODO:
            - Make internal helper methods (e.g., `_die_extract_recurser`, `_extract_architecture_information`)
              class-private to indicate they are not intended to be called externally.
            - Decouple parsing logic to allow finer-grained access to intermediate DWARF structures.
        """
        self.logger.debug(f'Processing file: {binary}')
        extracted_dwarf_info = DwarfInfo()

        extracted_dwarf_info.set_source_file(self.source_file)
        extracted_dwarf_info.set_binary_name(binary)
        extracted_dwarf_info.set_function_of_interest(self.function_of_interest)

        with open(binary, 'rb') as f:
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
                self.extract_architecture_information(top_DIE, elffile.little_endian, extracted_dwarf_info)

                indent_level = '    '
                # print(f"{indent_level}Top DIE with tag={top_DIE.tag}")

                # We're interested in the filename...
                # print(f"| {indent_level}name={Path(top_DIE.get_full_path()).as_posix()}")

                file = os.path.basename(Path(top_DIE.get_full_path()).as_posix())

                # We are only interested in the CU for a specific source file
                if not file == self.source_file:
                    continue

                self.logger.debug(f"{file}, offset: {CU.cu_offset}, length: {CU['unit_length']}\n")

                # We iterate through all direct descendants of the CU
                for child in top_DIE.iter_children():
                    self.die_extract_recurser(die=child,
                                              loc_list=location_lists,
                                              loc_parser=loc_parser,
                                              CU=CU,
                                              dwarfinfo=dwarf_info_context_object,
                                              extracted_di=extracted_dwarf_info,
                                              indent_level=indent_level)

            # Extract CFA register values and offsets for subprogram of interest
            self.extract_cfa_register_values_and_offsets(dwarf_info_context_object, extracted_dwarf_info)

            return extracted_dwarf_info


    def die_extract_recurser(self, die, loc_list: list, loc_parser, CU, dwarfinfo,
                             extracted_di, indent_level='    ', subprogram: None | Subprogram=None,  global_level: bool=True):
        """
        Recursively traverses a DWARF Debugging Information Entry (DIE) tree to extract
        relevant program data including global variables, the specified subprogram,
        and the subprogram's formal parameters and local variables.

        This method processes DIEs based on their tags:
            - DW_TAG_subprogram: Matches and extracts information for a target function,
              including its name, type, address range, formal parameters, and local variables.
            - DW_TAG_variable: Extracts global or local variable information depending on
              recursion context.
            - DW_TAG_formal_parameter: Extracts formal parameters of the matched subprogram.

        Parameters:
            die: The current DIE node to process.
            loc_list (list): A list used for tracking or storing location-related data.
            loc_parser: An object used to interpret location attributes in DIEs.
            CU: The Compilation Unit to which the DIE belongs, providing version context.
            dwarfinfo: The overarching DWARF information context object from pyelftools.
            extracted_di: DwarfInfo instance to which extracted debug information is stored.
            indent_level (str): Used to format debug output based on recursion depth.
            subprogram (Subprogram | None): The subprogram for which formal params and
                                            local variables are extracted.
            global_level (bool): Indicates whether the current DIE is at global scope,
                                 influencing how variables are classified.

        Side Effects:
            - Populates extracted_dwarf_info with data about the target subprogram,
              global variables, local variables, and formal parameters.
            - May append formatted debug output if debugging is enabled.
        """
        match die.tag:
            case 'DW_TAG_subprogram':
                # Case of subprogram. We are only interested in the subroutine specified by the user.
                fun_name_attr = die.attributes.get('DW_AT_name')
                fun_type_attr = die.attributes.get('DW_AT_type')

                # We only want to extract subprograms declared in the source file,
                is_declared_in_source_file = die.attributes.get('DW_AT_decl_file').value == 1

                if is_declared_in_source_file:
                    # Initialize new subprogram
                    subprogram = Subprogram()
                    subprogram.name = fun_name_attr.value.decode('utf-8')

                    # A subprogram may not have type attribute
                    if fun_type_attr:
                        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
                        # self.extract_type_information(die_from_attr, type_info)
                        type_info = self._extract_type_rec(die.get_DIE_from_attribute('DW_AT_type'))
                        subprogram.type_info = type_info

                    lowpc, highpc = self.get_low_and_high_pc(die)
                    subprogram.low_pc = lowpc
                    subprogram.high_pc = highpc

                    extracted_di.add_subprogram(subprogram)

                    """
                        We also want to extract formal parameters and local variables
                        as we recurse, the level is no longer global. This affects how
                        variables are extracted.
                    """
                    child_indent = indent_level + '  '
                    for child in die.iter_children():
                        self.die_extract_recurser(
                            die=child,
                            loc_list=loc_list,
                            loc_parser=loc_parser,
                            CU=CU,
                            dwarfinfo=dwarfinfo,
                            extracted_di=extracted_di,
                            indent_level=child_indent,
                            subprogram=subprogram,
                            global_level=False)
            case 'DW_TAG_variable' | 'DW_TAG_formal_parameter':
                if die.tag == 'DW_TAG_formal_parameter':
                    var_or_param = FormalParameter()
                elif global_level:
                    var_or_param = GlobalVariable()
                else:
                    var_or_param = LocalVariable()

                if die.attributes['DW_AT_name']:
                    var_name = die.attributes['DW_AT_name'].value.decode('utf-8')
                    var_or_param.set_name(var_name)

                if die.attributes['DW_AT_type']:
                    self._extract_type(var_or_param, die)

                # TODO: see if this can be simplified
                for attr, value in die.attributes.items():
                    if loc_parser.attribute_has_location(value, CU['version']):
                        self._extract_location(var_or_param, loc_parser, value, CU, die, dwarfinfo)

                if isinstance(var_or_param, GlobalVariable):
                    extracted_di.add_global_variable(var_or_param)
                elif isinstance(var_or_param, LocalVariable):
                    subprogram.add_local_variable(var_or_param)
                elif isinstance(var_or_param, FormalParameter):
                    subprogram.add_formal_parameter(var_or_param)
                else:
                    err = f"Unable to resolve parameter or variable DIE: {die}"
                    self.logger.error(err)
                    raise DWARFExtractionException(err)
            case _:
                pass

    def _extract_type(self, var_or_param: VarAndParamBase, die) -> None:
        die_from_attr = die.get_DIE_from_attribute('DW_AT_type')
        # type_info = TypeInfo()
        # self.extract_type_information(die_from_attr, type_info)
        var_or_param.set_type_info(self._extract_type_rec(die_from_attr))

    def _extract_location(self, var_or_param: VarAndParamBase, loc_parser, value, CU, die, dwarfinfo) -> None:
        if loc_parser.attribute_has_location(value, CU['version']):
            loc = loc_parser.parse_from_attribute(value, CU['version'], die)
            loc_output = self._get_location_output(loc, dwarfinfo, CU)
            if loc_output != "":
                var_or_param.set_location(loc_output)

    def _get_location_output(self, loc, dwarfinfo, CU):
        """
        Converts a DWARF location object into a human-readable string representation.

        Depending on the type of `loc`, this method either:
            - Describes a single DWARF location expression if `loc` is a `LocationExpr`.
            - Processes and formats a list of location entries (typically from the
              .debug_loc section) if `loc` is a list.

        Parameters:
            loc: A DWARF location object, either a `LocationExpr` instance or a list
                 of location entries.
            dwarfinfo: The pyelftools DWARF information context object containing
                       type and format metadata.
            CU: The Compilation Unit associated with the location, used for contextual
                offset information.

        Returns:
            str: A string describing the location expression(s), suitable for logging
            or display.

        TODO:
            Instead of returning a string, return a structured object representing
            parsed location data. This object should expose details such as:
                - Location type (e.g. address, register, stack)
                - Raw or computed value (e.g. address value, offset from frame base)
        """
        loc_output = ""

        if isinstance(loc, LocationExpr):
            loc_output += describe_DWARF_expr(loc.loc_expr, dwarfinfo.structs, CU.cu_offset)
        elif isinstance(loc, list):
            loc_output += self.show_loclist(loc, dwarfinfo, '', CU.cu_offset)

        return loc_output

    @staticmethod
    def show_loclist(loclist, dwarfinfo, indent, cu_offset) -> str:
        """
        Formats and returns a string representation of a DWARF location list, decoding
        each location expression for readability.

        This method iterates through a list of location entries and generates a
        human-readable description for each. If an entry is a `LocationEntry`, its
        expression is decoded using DWARF structures; otherwise, a basic string
        representation is used.

        Parameters:
            loclist: A list of DWARF location entries, typically parsed from
                     .debug_loc or .debug_loclists.
            dwarfinfo: The DWARF information object providing decoding context.
            indent (str): A string used to prefix each line of output for formatting.
            cu_offset: The offset of the Compilation Unit, used in expression decoding.

        Returns:
            str: A formatted, multi-line string representing the decoded location list.

        TODO:
            Refactor to return a structured object containing parsed location data
            instead of a formatted string. This object should capture:
                - Entry metadata (e.g. address ranges)
                - Location type (e.g. register, memory, stack)
                - Decoded values (e.g. address or frame base-relative offsets)
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

    def get_low_and_high_pc(self, DIE) -> (Any, Any):
        """
        Extracts and computes the low and high program counter (PC) values from a DWARF DIE.

        DWARF defines two attributes to indicate the range of instruction addresses
        covered by a subprogram or code block:
            - `DW_AT_low_pc`: An absolute starting address.
            - `DW_AT_high_pc`: Either an absolute address or an offset from `low_pc`,
              depending on its form class.

        This method reads both attributes and interprets `DW_AT_high_pc` appropriately
        based on its form class, as described in DWARF v4 §2.17.

        Parameters:
            DIE: A Debugging Information Entry (DIE) representing a code entity with
                 address range metadata.

        Returns:
            tuple: A (low_pc, high_pc) pair of integer addresses, or (None, None) if
            the high_pc attribute has an unrecognized form class.

        Logs:
            Emits an error if `DW_AT_high_pc` has an unsupported form class.
        """
        lowpc = DIE.attributes['DW_AT_low_pc'].value
        highpc_attr = DIE.attributes['DW_AT_high_pc']
        highpc_attr_class = describe_form_class(highpc_attr.form)
        if highpc_attr_class == 'address':
            highpc = highpc_attr.value
        elif highpc_attr_class == 'constant':
            highpc = lowpc + highpc_attr.value
        else:
            self.logger.error('Error: invalid DW_AT_high_pc class:',highpc_attr_class)
            lowpc, highpc = None, None

        return lowpc, highpc


    def extract_architecture_information(self, top_die, little_endian: bool, extracted_di: DwarfInfo) -> None:
        """
        Extracts architecture-related information from the top-level DIE of a Compilation Unit.

        This method expects a DIE tagged `DW_TAG_compile_unit`, which typically contains
        the `DW_AT_producer` attribute — a string describing the toolchain or compiler
        used to generate the binary. This producer string is parsed to extract architecture
        and platform-specific details, taking into account the endianness of the target.

        Parameters:
            top_die: The top-level DIE of a Compilation Unit, usually with tag
                     `DW_TAG_compile_unit`.
            little_endian (bool): Indicates whether the target architecture is little-endian.
            extracted_di (DwarfInfo): An instance of DwarfInfo to which extracted DWARF
                                      debug information is stored

        Side Effects:
            - Calls `self.extracted_dwarf_info.extract_core_information(...)` with the
              decoded producer string and endianness.
            - Emits a warning if `DW_AT_producer` is not present.

        TODO:
            - Consider renaming the parameter to `compile_unit_die` or similar for clarity,
              and add a check to confirm the DIE tag is `DW_TAG_compile_unit`.
            - Verify whether endianness information is accessible through compile_unit.
              If it is, last method parameter is redundant.
        """
        if not top_die.attributes['DW_AT_producer']:
            self.logger.warning("Core information (DW_AT_producer) not found from provided DIE")
        else:
            producer_string = top_die.attributes['DW_AT_producer'].value.decode('utf-8')
            extracted_di.extract_core_information(producer_string, little_endian)

    def _extract_type_rec(self, t) -> Optional[AbstractType]:
        """
        Recursively extracts type information from a DWARF Debugging Information Entry (DIE)
        and creates nested dataclass instances representing the type information.

        This method handles a variety of DWARF type tags, including base types, arrays, pointers,
        constants, typedefs, structures, and classes. It traverses the type tree recursively,
        adding descriptive elements and dimensional information (in the case of arrays) to the
        type dataclasses.

        Supported DIE tags:
            - DW_TAG_base_type: Extracts base type name and size.
            - DW_TAG_array_type: Recursively extracts element type and computes total element count.
            - DW_TAG_pointer_type: Follows and resolves pointer target type.
            - DW_TAG_const_type: Resolves the underlying const-qualified type.
            - DW_TAG_typedef: Tracks typedef name and underlying type.
            - DW_TAG_structure_type: Adds struct name to the description.

        Parameters:
            t: A DWARF DIE representing the type to analyze.

        Returns:
            AbstractType: resolved type information

        Notes:
            - Errors encountered when expected attributes (like DW_AT_type or DW_AT_name)
              are missing are logged and represented with placeholder strings in the output.
            - The method does not yet handle all DWARF type tags (e.g., union, enumeration).

        TODO:
            - Extend support to additional DWARF types like unions and enumerations.
        """
        match t.tag:
            case 'DW_TAG_base_type':
                base_type = t.attributes['DW_AT_name'].value.decode('utf-8')
                byte_size = int(t.attributes['DW_AT_byte_size'].value)

                return BaseType(base_type=base_type, byte_size=byte_size)
            case 'DW_TAG_array_type':
                try:
                    dimensions = self.compute_array_size_from_subranges(t)
                    arr_type = self._extract_type_rec(t.get_DIE_from_attribute('DW_AT_type'))
                    length = prod(dimensions)
                    return ArrayType(arr_type=arr_type, dimensions=dimensions, length=length)
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return ArrayType()
            case 'DW_TAG_pointer_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    points_to = self._extract_type_rec(pt)
                    return PointerType(to_type=points_to)
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return PointerType()
            case 'DW_TAG_const_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    const_type = self._extract_type_rec(pt)
                    return ConstType(const_type=const_type)
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return ConstType(const_type=None)
            case 'DW_TAG_volatile_type':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    vol_type = self._extract_type_rec(pt)
                    return VolatileType(vol_type=vol_type)
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return VolatileType(vol_type=None)
            case 'DW_TAG_typedef':
                try:
                    pt = t.get_DIE_from_attribute('DW_AT_type')
                    name = f"{t.attributes['DW_AT_name'].value.decode('utf-8')}"
                    base_type = self._extract_type_rec(pt)
                    return TypeDef(name=name, base_type=base_type)
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return TypeDef(base_type=None)
            case 'DW_TAG_structure_type':
                try:
                    self.logger.debug(f"case DW_TAG_structure_type. Name: {t.attributes['DW_AT_name'].value.decode('utf-8')}")
                    struct_name = t.attributes['DW_AT_name'].value.decode('utf-8')

                    struct_byte_size = int(t.attributes['DW_AT_byte_size'].value)
                    struct = StructType(name=struct_name, byte_size=struct_byte_size, members=[])
                    for child in t.iter_children():
                        if child.tag == "DW_TAG_member":
                            try:
                                member_name = child.attributes.get("DW_AT_name").value.decode()
                                type_instance = child.get_DIE_from_attribute('DW_AT_type')
                                member_type = self._extract_type_rec(type_instance)
                                member = StructMember(name=member_name, member_type=member_type)
                                if child.attributes.get("DW_AT_bit_size"):
                                    member.bit_size = int(child.attributes.get("DW_AT_bit_size").value)
                                    member.bit_offset = int(child.attributes.get("DW_AT_data_bit_offset").value)
                                struct.members.append(member)
                            except Exception as e:
                                self.logger.error(f"Exception while parsing struct: {e}, caused by {child}")
                    return struct
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return StructType()
            case 'DW_TAG_union_type':
                try:
                    union_byte_size = int(t.attributes['DW_AT_byte_size'].value)
                    union = UnionType(byte_size=union_byte_size, members=[])
                    for child in t.iter_children():
                        if child.tag == "DW_TAG_member":
                            try:
                                member_name = child.attributes.get("DW_AT_name").value.decode()
                                type_instance = child.get_DIE_from_attribute('DW_AT_type')
                                member_type = self._extract_type_rec(type_instance)
                                member = UnionMember(name=member_name, member_type=member_type)
                                union.members.append(member)
                            except Exception as e:
                                self.logger.error(f"Exception while parsing union: {e}, caused by {child}")
                    return union
                except Exception as e:
                    self.logger.error(f"Exception: {e}, caused by {t}")
                    return StructType()
                pass
            case _:
                self.logger.warning(f"Trying to extract type for unsupported DIE: {t}")
                return None


    @staticmethod
    def compute_array_size_from_subranges(arr_die) -> List[int]:
        """
        Computes the total number of elements in an array described by a DWARF array DIE.

        This static helper method iterates over the children of the given array DIE,
        which represent the array's dimension subranges, and calculates the product
        of their sizes to determine the total number of elements. It supports
        multidimensional arrays.

        Limitations:
            - Only subrange type children (`DW_TAG_subrange_type`) are supported.
            - Does not handle arrays defined via enumeration types or other mechanisms.

        Parameters:
            arr_die: A DWARF DIE representing an array type, expected to have children
                     defining its dimensions.

        Returns:
            List[int]: A list of elements in each array dimension
        """
        dimensions: List[int] = []
        for die in arr_die.iter_children():

            if die.tag == 'DW_TAG_subrange_type':
                upper_bound = int(die.attributes['DW_AT_upper_bound'].value)
                lower_bound = 0
                if die.attributes.get('DW_AT_lower_bound'):
                    lower_bound = int(die.attributes['DW_AT_lower_bound'].value)
                dimensions.append(upper_bound - lower_bound + 1)
        return dimensions


    def extract_cfa_register_values_and_offsets(self, di_context_object, extracted_di: DwarfInfo) -> None:
        """
        Extracts Canonical Frame Address (CFA) register and offset information
        from the debug frame section of DWARF data.

        This method looks for a Frame Description Entry (FDE) with an initial
        location matching the low PC of the subprogram of interest, decodes its
        instructions, and collects frame base info for each instruction row.
        The DwarfInfo instance handles the logic of storing relevant frame base
        information

        Parameters:
            di_context_object: pyelftools DWARFInfo object instance providing access to
            CFI entries with .CFI_entries() method.
            extracted_di: DWARFInfo object instance to which DWARF debug information
                          is collected

        Side Effects:
            - Populates frame base information into `self.extracted_dwarf_info`.
            - Logs debug messages for the matching FDE range.

        Warning:
            This method assumes the structure of the decoded data is valid.
            It may raise KeyError if expected keys like 'cfa', 'pc', or
            'initial_location' are missing.

        TODO:
            Add validation or error handling for robustness.
        """
        cf_section = di_context_object.CFI_entries()
        for entry in cf_section:
            if isinstance(entry, FDE) and extracted_di.has_subprogram_with_pc_as_low_pc(entry['initial_location']):
                self.logger.debug(
                    f"Extracting frame base information for entry: PC {entry['initial_location']:x}..{entry['initial_location'] + entry['address_range']:x}")
                instructions = entry.get_decoded().table

                for row in instructions:
                    extracted_di.add_frame_base_info(
                        FrameBaseInfo(row['pc'], row['cfa'].reg, row['cfa'].offset), entry['initial_location'])