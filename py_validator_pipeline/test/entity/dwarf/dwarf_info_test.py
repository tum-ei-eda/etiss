from unittest import TestCase

from src.entity.dwarf.dwarf_info import DwarfInfo
from src.entity.dwarf.subprogram import Subprogram

class DwarfInfoTest(TestCase):
    """
    Methods for extracting specific subprograms contain logic
    that is tested here
    """

    def setUp(self):
        self.di = DwarfInfo()
        sp1 = Subprogram()
        sp1.name = 'sp1'
        sp1.low_pc = 100
        sp1.high_pc = 120
        sp2 = Subprogram()
        sp2.name = 'sp2'
        sp2.low_pc = 130
        sp2.high_pc = 150
        sp3 = Subprogram()
        sp3.name = 'sp3'
        sp3.low_pc = 170
        sp3.high_pc = 190
        self.di.subprograms = {'sp1': sp1, 'sp2': sp2, 'sp3': sp3}

    def test_has_subprogram_with_low_and_high_pc_positive_lower_boundary_case(self) -> None:

        # lower boundary for sp2
        sp = self.di.get_enclosing_subprogram(130)
        self.assertIsInstance(sp, Subprogram)
        self.assertEqual('sp2', sp.name)

    def test_has_subprogram_with_low_and_high_pc_positive_upper_boundary_case(self) -> None:
        # upper boundary for sp2
        sp = self.di.get_enclosing_subprogram(150)
        self.assertIsInstance(sp, Subprogram)
        self.assertEqual('sp2', sp.name)

    def test_returns_none_if_no_enclosing_subprogram_exists(self) -> None:
        sp = self.di.get_enclosing_subprogram(155)
        self.assertIsNone(sp)

    def test_get_subprogram_with_low_pc_returns_correct_subprogram(self) -> None:
        # Should return sp1
        sp = self.di.get_subprogram_with_pc_as_low_pc(100)
        self.assertEqual('sp1', sp.name)

    def test_returns_none_if_no_subprogram_with_given_low_pc_exists(self) -> None:
        # within range of sp1
        sp = self.di.get_subprogram_with_pc_as_low_pc(101)
        self.assertIsNone(sp)

