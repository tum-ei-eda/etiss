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
from typing import Any
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

from src.entity.dwarf.global_variable import GlobalVariable
from src.entity.dwarf.formal_parameter import FormalParameter
from src.entity.dwarf.local_variable import LocalVariable

from src.entity.dwarf.type_construct import TypeConstruct

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
        binary (str): The path or name of the binary file to analyze.
        source_file (str): The source file associated with the debugging information.
        function (str): The name of the function whose debugging info is to be extracted.
        debug (bool, optional): Enables debug output if True. Defaults to False.

    TODO:
        - Consider redesigning `DwarfInfoExtractor` as a singleton to avoid
          repeated instantiation.
        - Avoid populating instance state with class attributes in the initializer.
        - Instead of storing extracted info internally, refactor to create and
          return a new `DwarfInfo` instance after extraction completes.
    """


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
        """
        Returns the extracted DWARF debugging information.

        Returns:
            DwarfInfo: The populated DWARF information object.
        """
        return self.extracted_dwarf_info

    def extract_dwarf_info(self) -> None:
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
        self.logger.debug(f'Processing file: {self.binary}')

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
                self.extract_architecture_information(top_DIE, elffile.little_endian)

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
                    self.die_extract_recurser(child, location_lists, loc_parser, CU, dwarf_info_context_object, self.function, indent_level)

            # Extract CFA register values and offsets for subprogram of interest
            self.extract_cfa_register_values_and_offsets(dwarf_info_context_object)



    def extract_cfa_register_values_and_offsets(self, di_context_object):
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
        low_pc = self.extracted_dwarf_info.get_low_pc()
        for entry in cf_section:
            if isinstance(entry, FDE) and entry['initial_location'] == low_pc:
                self.logger.debug(
                    f"Extracting frame base information for entry: PC {entry['initial_location']:x}..{entry['initial_location'] + entry['address_range']:x}")
                instructions = entry.get_decoded().table
                for row in instructions:
                    self.extracted_dwarf_info.add_frame_base_info(
                        FrameBaseInfo(row['pc'], row['cfa'].reg, row['cfa'].offset))

    def die_extract_recurser(self, die, loc_list: list, loc_parser, CU, dwarfinfo, function, indent_level='    ', global_level=True):
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
            function (str): The name of the target subprogram to extract.
            indent_level (str): Used to format debug output based on recursion depth.
            global_level (bool): Indicates whether the current DIE is at global scope,
                                 influencing how variables are classified.

        Side Effects:
            - Populates extracted_dwarf_info with data about the target subprogram,
              global variables, local variables, and formal parameters.
            - May append formatted debug output if debugging is enabled.

        TODO:
            - This method has significant redundancy. Consider refactoring it
              to reduce complexity. For instance consider creating attribute
              specific helper methods and

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

    def show_loclist(self, loclist, dwarfinfo, indent, cu_offset) -> str:
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

        TODO:
            This method is intended only for DIEs representing subprograms.
            Rename the method to reflect this constraint, and raise an explicit error
            if the DIE tag is not 'DW_TAG_subprogram'.
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
            lowpc, highpce = None, None

        return lowpc, highpc


    def extract_architecture_information(self, top_die, little_endian):
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
            self.extracted_dwarf_info.extract_core_information(producer_string, little_endian)


    def extract_type_information(self, t, type_construct: TypeConstruct) -> None:
        """
        Recursively extracts type information from a DWARF Debugging Information Entry (DIE)
        and populates a `TypeConstruct` object with a structured, human-readable representation
        of the type.

        This method handles a variety of DWARF type tags, including base types, arrays, pointers,
        constants, typedefs, structures, and classes. It traverses the type tree recursively,
        adding descriptive elements and dimensional information (in the case of arrays) to the
        `TypeConstruct`.

        Supported DIE tags:
            - DW_TAG_base_type: Extracts base type name and size.
            - DW_TAG_array_type: Recursively extracts element type and computes total element count.
            - DW_TAG_pointer_type: Follows and resolves pointer target type.
            - DW_TAG_const_type: Resolves the underlying const-qualified type.
            - DW_TAG_typedef: Tracks typedef name and underlying type.
            - DW_TAG_structure_type: Adds struct name to the description.
            - DW_TAG_class_type: Adds class name to the description.

        Parameters:
            t: A DWARF DIE representing the type to analyze.
            type_construct (TypeConstruct): An object used to incrementally build a
                                    structured description of the type composition.

        Notes:
            - Errors encountered when expected attributes (like DW_AT_type or DW_AT_name)
              are missing are logged and represented with placeholder strings in the output.
            - The method does not yet handle all DWARF type tags (e.g., union, enumeration).

        TODO:
            - Improve support for more complex types, such as structures
            - Extend support to additional DWARF types like unions and enumerations.
            - Consider extracting a base `resolve_child_type()` helper to reduce repetition.
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
        Computes the total number of elements in an array described by a DWARF array DIE.

        This static helper method iterates over the children of the given array DIE,
        which represent the array's dimension subranges, and calculates the product
        of their sizes to determine the total number of elements. It supports
        multidimensional arrays by multiplying the size of each dimension.

        Limitations:
            - Only subrange type children (`DW_TAG_subrange_type`) are supported.
            - Does not handle arrays defined via enumeration types or other mechanisms.

        Parameters:
            arr_die: A DWARF DIE representing an array type, expected to have children
                     defining its dimensions.

        Returns:
            int: The total number of elements in the array, computed as the product
                 of the sizes of all subranges.
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

