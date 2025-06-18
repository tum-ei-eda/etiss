import struct

def from_rv32_words_le_bytes(low_hex: str, high_hex: str) -> float:
    # Convert each 32-bit word from little-endian hex string to bytes
    low_bytes = bytes.fromhex(low_hex)[::-1]
    high_bytes = bytes.fromhex(high_hex)[::-1]
    # Concatenate to get 8-byte double (little endian overall)
    double_bytes = high_bytes + low_bytes  # high comes first in IEEE 754
    return struct.unpack('>d', double_bytes)[0]  # Big-endian for correct IEEE interpretation

# Now try:
print(from_rv32_words_le_bytes('00000000', '00404940'))  # → 50.5
print(from_rv32_words_le_bytes('00000000', '00404E40'))  # → 60.5