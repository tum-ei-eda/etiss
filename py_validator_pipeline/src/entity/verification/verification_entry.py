class VerificationEntry:

    def __init__(self, function_name: str, invoke_chain: str):
        self.function_name = function_name
        self.invoke_chain = invoke_chain
        self.prologue = ''
        self.formal_params = ''
        self.local_vars = ''
        self.global_vars = ''
        self.epilogue = ''
        self.return_value = ''
        self.contains_failures = False

    def add_prologue_verification_result(self, result: str, failed: bool) -> None:
        """ Adder for prologue verification result """
        self.prologue = result

    def add_formal_param_verification_result(self, result: str, failed: bool) -> None:
        """ Adder for formal parameters verification result """
        self.formal_params = result


    def add_local_vars_verification_result(self, result: str, failed: bool) -> None:
        """ Adder for local variables verification result """
        if failed:
            self.contains_failures = failed
        self.local_vars = result

    def add_global_vars_verification_result(self, result: str, failed: bool) -> None:
        """ Adder for global variables verification result """
        if failed:
            self.contains_failures = failed
        self.global_vars = result


    def add_epilogue_verification_result(self, result: str, failed: bool) -> None:
        """ Adder for epilogue verification result """
        if failed:
            self.contains_failures = failed
        self.epilogue = result

    def add_return_value_verification_result(self, result: str, failed: bool) -> None:
        """ Adder for return value verification result """
        if failed:
            self.contains_failures = failed
        self.return_value = result

    def failed(self) -> bool:
        return self.contains_failures

    def __str__(self):
        return ''.join([
            f'> {self.function_name} ({self.invoke_chain})\n',
            self.prologue,
            self.formal_params,
            self.local_vars,
            self.global_vars,
            self.epilogue,
            self.return_value
        ])
