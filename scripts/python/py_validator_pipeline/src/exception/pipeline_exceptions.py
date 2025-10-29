class DWARFExtractionException(Exception):
    """Exception raised for errors encountered during DWARF debug information extraction."""
    pass

class ETISSSimulationException(Exception):
    """Exception raised for issues that occur during the ETISS simulation process."""
    pass

class ActivityLogParserException(Exception):
    """Exception raised when parsing of activity logs fails or encounters invalid data."""
    pass

class SnapshotLoggerException(Exception):
    """Exception raised during errors in the snapshot logging mechanism."""
    pass

class VerificationProcessException(Exception):
    """Exception raised when for failures or severe inconsistencies in verification stage."""
    pass

class OutOfRegistersException(Exception):
    """
    Exception raised when the return value cannot be passed
    via the architecture's argument registers.

    This signals to stop attempting to place the return value
    in registers and instead retrieve it from memory.
    """
    pass
