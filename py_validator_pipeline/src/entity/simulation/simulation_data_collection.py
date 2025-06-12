"""
    A simple class that collects the simulation data entries
"""
from typing import List

from src.entity.simulation.simulation_data_entry import SimulationDataEntry

class SimulationDataCollection:

    def __init__(self):
        self.entries: List[List[SimulationDataEntry]] = []


    def add_entry(self, entry: List[SimulationDataEntry]) -> None:
        self.entries.append(entry)


    def get_entries(self) -> List[List[SimulationDataEntry]]:
        return self.entries