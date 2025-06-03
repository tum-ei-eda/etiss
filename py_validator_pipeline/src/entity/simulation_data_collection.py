class SimulationDataCollection:

    def __init__(self):
        self.entries = []


    def add_entry(self, entry):
        self.entries.append(entry)


    def get_entries(self):
        return self.entries