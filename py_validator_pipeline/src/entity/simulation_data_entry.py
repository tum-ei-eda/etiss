class SimulationDataEntry:
    """
        This entity holds the information for one function call.
        The information includes
          - CPU state snapshots from prologue instructions
          - dwrites done during function execution
          - CPU state snapshots from epilogue instructions
    """


    def __init__(self):
        self.prologue = []
        self.epilogue = []
        self.dwrites = {}
        self.formal_param_locations = {}
        self.global_variable_locations = {}
        self.frame_pointer = 0
        self.index = 0



    def append_prologue_instruction(self, inst: str, pc, fp, arg_regs: list, farg_regs: list) -> None:
        if self.frame_pointer == 0:
            self.frame_pointer = fp
        self.prologue.append({
            'idx': self.index,
            'instruction': inst,
            'pc': pc,
            'fp': fp,
            'a0': arg_regs[0],
            'a1': arg_regs[1],
            'a2': arg_regs[2],
            'a3': arg_regs[3],
            'a4': arg_regs[4],
            'a5': arg_regs[5],
            'a6': arg_regs[6],
            'a7': arg_regs[7],
            'fa0': farg_regs[0],
            'fa1': farg_regs[1],
            'fa2': farg_regs[2],
            'fa3': farg_regs[3],
            'fa4': farg_regs[4],
            'fa5': farg_regs[5],
            'fa6': farg_regs[6],
            'fa7': farg_regs[7],
        })

        self.index += 1


    def append_epilogue_instruction(self, inst: str, pc, fp, rv_regs: list, frv_regs) -> None:
        self.epilogue.append({
            'idx': self.index,
            'instruction': inst,
            'pc': pc,
            'fp': fp,
            'a0': rv_regs[0],
            'a1': rv_regs[1],
            'fa0': frv_regs[0],
            'fa1': frv_regs[1],
        })
        self.index += 1

    def append_dwrite_instruction(self, pc, location, data, byte_size) -> None:
        if location not in self.dwrites:
            self.dwrites[location] = []

        self.dwrites[location].append({
            'idx': self.index,
            'pc': pc,
            'data': data,
            'location': location,
            'byte_size': byte_size,
        })
        self.index += 1


    def add_formal_param_locations(self, param_name, param_loc) -> None:
        self.formal_param_locations[param_name] = hex(self.frame_pointer +  param_loc)[2:]

    def add_global_variable_and_location(self, var_name, location):
        self.global_variable_locations[var_name] = location



    def get_last_write_to_global_variables(self):
        last_writes = {}
        for var_name, location in self.global_variable_locations.items():
            if location in self.dwrites:
                last_writes[var_name] = self.dwrites[location][-1]
        return last_writes


    def get_first_writes_to_formal_params(self):
        first_writes = {}
        for param_name, location in self.formal_param_locations.items():
            if location in self.dwrites:
                first_writes[param_name] = self.dwrites[location][0]
        return first_writes


    def __str__(self):
        output = ""
        if self.prologue:
            output += "Prologue instructions CPU state snapshots:\n"
            for inst in self.prologue:
                output += f"  | cswsp <{inst['pc']}>: <a0: {inst['a0']}, a1: {inst['a1']}, fa0: {inst['fa0']}, fa1: {inst['fa1']}>\n"
        formal_param_writes = self.get_first_writes_to_formal_params()
        if formal_param_writes:
            output += "First data writes to formal params stack addresses after prologue:\n"
            for var_name, first_dwrite in formal_param_writes.items():
                output += f"  | {var_name}:\t<pc: {first_dwrite['pc']}\tdata: {first_dwrite['data']}\taddress: {first_dwrite['location']}>\n"
        else:
            output += f"No formal parameters written to stack\n"
        global_var_dwrites = self.get_last_write_to_global_variables()
        if global_var_dwrites:
            output += "Final data writes to global variable(s) before epilogue:\n"
            for var_name, last_dwrite in global_var_dwrites.items():
                output += f"  | {var_name}:\t<pc: {last_dwrite['pc']}\tdata: {last_dwrite['data']}\taddress: {last_dwrite['location']}>\n"
        else:
            output += f"No data writes to global variables\n"
        if self.epilogue:
            output += "Epilogue instructions CPU state snapshots:\n"
            for inst in self.epilogue:
                output += f"  | cjr <{inst['pc']}>: <a0: {inst['a0']}, a1: {inst['a1']}, fa0: {inst['fa0']}, fa1: {inst['fa1']}>\n"

        return output


    def compare_entries(self, other_entry, strict: bool = False) -> str:
        result = ""
        if strict:
            result += self.compare_prologues(other_entry.prologue)

        result += self.compare_formal_param_values(other_entry.get_first_writes_to_formal_params())

        result += self.compare_global_variable_values(other_entry.get_last_write_to_global_variables())

        if strict:
            result += self.compare_epilogues(other_entry.epilogue)

        return result


    def compare_prologues(self, other_entry_prologue) -> str:
        result = ""
        if len(self.prologue) == 0 and len(other_entry_prologue) == 0:
            result += f"Function prologue: no snapshots written to prologue\n"
        elif len(self.prologue) == len(other_entry_prologue):
            mismatch = ""
            for idx, entry in enumerate(self.prologue):
                for key in ['pc', 'a0', 'a1', 'fa0', 'fa1']:
                    if entry[key] != other_entry_prologue[idx][key]:
                        mismatch += f"   | Mismatch at index {idx}: {entry[key]} vs {other_entry_prologue[idx][key]}\n"
            if mismatch:
                result += f'Function prologue ... mismatch\n{mismatch}\n'
        else:
            result += "Function prologue ... Length mismatch\n"

        if not result:
            result += "Function prologue ... OK\n"
        return result

    def compare_formal_param_values(self, other_entry_formal_params) -> str:
        result = ""
        formal_param_values = self.get_first_writes_to_formal_params()
        if len(formal_param_values) == 0 and len(other_entry_formal_params) == 0:
            result += "Formal parameters: No parameters\n"
        elif len(formal_param_values) == len(other_entry_formal_params):
            for var_name, entry in formal_param_values.items():
                if entry['data'] != other_entry_formal_params[var_name]['data']:
                    result += f"Global variables: data mismatch in variable {var_name}: {entry['data']} != {other_entry_formal_params[var_name]['data']}\n"
        else:
            result += "Formal parameters: number of parameters do not match\n"
        if not result:
            result += "Formal parameters: OK\n"
        return result

    def compare_global_variable_values(self, other_entry_global_variable_values) -> str:
        result = ""
        global_var_values = self.get_last_write_to_global_variables()
        if len(global_var_values) == 0 and len(other_entry_global_variable_values) == 0:
            result += "Global variables: No variables\n"
        elif len(global_var_values) == len(other_entry_global_variable_values):
            for var_name, entry in global_var_values.items():
                if entry['data'] != other_entry_global_variable_values[var_name]['data']:
                    result += f"Global variables: data mismatch in variable {var_name}: {entry['data']} != {other_entry_global_variable_values[var_name]['data']}\n"
        else:
            result += "Global variables: number of variables do not match\n"

        if not result:
            result += "Global Variables: OK\n"
        return result

    def compare_epilogues(self, other_entry_epilogue) -> str:
        result = ""
        if len(self.epilogue) == 0 and len(other_entry_epilogue) == 0:
            result += "Function epilogue: no snapshots written to epilogue\n"
        elif len(self.epilogue) == len(other_entry_epilogue):
            mismatch = ""
            for idx, entry in enumerate(self.epilogue):
                for key in ['pc', 'a0', 'a1', 'fa0', 'fa1']:
                    if entry[key] != other_entry_epilogue[idx][key]:
                        mismatch += f"   | Mismatch at index {idx}: {entry[key]} vs. {other_entry_epilogue[idx][key]}\n"
            if mismatch:
                result += f'Function epilogue ... mismatch\n{mismatch}\n'
        else:
            result += "Function epilogue ... Length mismatch\n"

        if not result:
            result += "Function epilogue ... OK\n"
        return result







