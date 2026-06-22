import unittest
from src.entity.verification.rv32_return_register_layout import  RV32ReturnRegisterLayout
from src.entity.verification.struct_reg_data_types import Bitfield, Integer, Float
from src.exception.pipeline_exceptions import VerificationProcessException


class TestRV32ReturnRegisterLayout(unittest.TestCase):

    def setUp(self):
        self.xlen = 32

    def test_has_room_for_bitfield_with_simple_case(self) -> None:
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        bits_to_reserve = 12
        alignment_bytes = 16

        self.assertTrue(reg_layout.has_room_for_bitfield(bits_to_reserve=bits_to_reserve, alignment_bytes=alignment_bytes))

    def test_has_room_for_bitfield_supports_padding(self) -> None:
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        # we want to reserve 10 bits
        bit_size = 10
        # alignent is one byte (e.g. char)
        alignment = 1

        self.assertTrue(reg_layout.has_room_for_bitfield(bits_to_reserve=bit_size, alignment_bytes=alignment))


    def test_has_room_for_bitfield_alignment_edge_case(self) -> None:
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        bit_size = 16
        alignment = 2
        bitfield = Bitfield(bit_size=bit_size, alignment=alignment)

        reg_layout.add_bitfield(bitfield)
        self.assertTrue(reg_layout.has_room_for_bitfield(bits_to_reserve=bit_size, alignment_bytes=alignment))

    def test_neg_has_room_for_bitfield_alignment_edge_case(self) -> None:
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        bit_size = 16
        alignment = 2
        reg_layout.add_bitfield(Bitfield(bit_size=bit_size, alignment=alignment))
        # There is only 16 bits left in the 32-bit register
        self.assertFalse(reg_layout.has_room_for_bitfield(bits_to_reserve=bit_size + 1, alignment_bytes=alignment))


    def test_bits_cross_boundary_but_alignment_fits_to_register(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        bit_size = 8
        alignment = 2
        reg_layout.add_bitfield(Bitfield(bit_size=bit_size, alignment=alignment))
        self.assertTrue(reg_layout.has_room_for_bitfield(bits_to_reserve=bit_size + 1, alignment_bytes=alignment))

    def test_raises_error_if_trying_to_add_bitfield_when_not_enough_room(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        bit_size = 16
        alignment = 2
        reg_layout.add_bitfield(Bitfield(bit_size=bit_size, alignment=alignment))
        reg_layout.add_bitfield(Bitfield(bit_size=bit_size, alignment=alignment))
        with self.assertRaises(VerificationProcessException):
            reg_layout.add_bitfield(Bitfield(bit_size=bit_size, alignment=alignment))

    def test_bits_cross_boundary_but_alignment_fits_to_register_edge_case(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        alignment = 1
        # Data [(0,7)]
        reg_layout.add_bitfield(Bitfield(bit_size=8, alignment=alignment))
        # Data [(0,7),(8,16)] (note padding)
        reg_layout.add_bitfield(Bitfield(bit_size=9, alignment=alignment))
        # Data placement should be [(0,7),(8,16), (24,31)]
        self.assertTrue(reg_layout.has_room_for_bitfield(bits_to_reserve=8, alignment_bytes=alignment))


    def test_edge_case_reg_layout_full_of_one_bit_bitfiels(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        alignment = 1
        for i in range (self.xlen):
            reg_layout.add_bitfield(Bitfield(bit_size=1, alignment=alignment))

        expected_data = []
        for i in range(self.xlen):
            # Creates tuples (0, 0), (1, 1,),...,(31,31)
            expected_data.append((i, i))

        self.assertEqual(expected_data, reg_layout.data)

        with self.assertRaises(VerificationProcessException):
            reg_layout.add_bitfield(Bitfield(bit_size=1, alignment=alignment))


    def test_add_bitfield_complex_case(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        alignment = 1
        # Data [(0,7)]
        reg_layout.add_bitfield(Bitfield(bit_size=8, alignment=alignment))
        # Data [(0,7), (8,16)]
        reg_layout.add_bitfield(Bitfield(bit_size=9, alignment=alignment))
        # Data  [(0,7), (8,16), (24,31)]
        reg_layout.add_bitfield(Bitfield(bit_size=8, alignment=alignment))
        self.assertEqual([(0,7), (8, 16), (24,31)], reg_layout.data)

    def test_raises_exception_if_trying_to_add_int_that_does_not_fit(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        # Data [(0,7),(8,15),(16,23),(24,31)]
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        self.assertEqual([(0, 7), (8, 15), (16, 23), (24, 31)], reg_layout.data)

        with self.assertRaises(VerificationProcessException):
            reg_layout.add_int(Integer(byte_size=1))

    def test_add_int_register_layout_one_more_int_fits(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)

        # Data [(0,7),(8,15),(16,23),(24,31)]
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        self.assertEqual([(0,7), (8, 15), (16,23)], reg_layout.data)
        # Should NOT have room for another int
        self.assertTrue(reg_layout.has_room_for_int(byte_size=1))

    def test_add_int_register_layout_full_of_chars(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)

        # Data [(0,7),(8,15),(16,23),(24,31)]
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        reg_layout.add_int(Integer(byte_size=1))
        self.assertEqual([(0,7), (8, 15), (16,23), (24,31)], reg_layout.data)
        # Should NOT have room for another int
        self.assertFalse(reg_layout.has_room_for_int(byte_size=1))

    def test_add_float_is_stored_with_correct_start_and_end_value(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        reg_layout.add_float(Float(byte_size=4))
        self.assertEqual([(0,31)], reg_layout.data)

    def test_add_float_with_double_is_stored_with_correct_start_and_end_value(self):
        reg_layout = RV32ReturnRegisterLayout(self.xlen)
        reg_layout.add_float(Float(byte_size=8))
        self.assertEqual([(0,63)], reg_layout.data)