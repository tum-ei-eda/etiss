from typing import List

from src.entity.simulation.simulation_data_entry import SimulationDataEntry

class SimulationDataCollection:
    """
    A container class for managing collections of simulation data entries.

    Each entry in the collection is a list of SimulationDataEntry objects
    representing simulation data grouped by function invocation. Specifically,
    each list corresponds to one call of a function of interest and includes
    the data for that function call as well as the data for any other functions
    invoked during its execution.

    This recursive grouping captures the full call hierarchy within the
    context of the original function invocation.
    """

    def __init__(self):
        """
        Initializes an empty collection for simulation data entries.
        """
        self.entries: List[List[SimulationDataEntry]] = []


    def add_entry(self, entry: List[SimulationDataEntry]) -> None:
        """
        Adds a new list of simulation data entries to the collection.

        Args:
            entry (List[SimulationDataEntry]): A list of simulation data entries to add.
        """
        self.entries.append(entry)


    def get_entries(self) -> List[List[SimulationDataEntry]]:
        """
        Returns all stored simulation data entry lists.

        Returns:
            List[List[SimulationDataEntry]]: The list of simulation data entry lists.
        """
        return self.entries