import struct
import json

# Header size
HEADER_BYTE_SIZE = 4

# Entry identifiers (first 4 bytes of each entry)
TYPE_STATE_SNAPSHOT = 1
TYPE_DATA_WRITE = 2

# Byte sizes
STATE_SNAPSHOT_BYTE_SIZE = 412
DATA_WRITE_BYTE_SIZE = 84

def parse_state_snapshot(data):
    fmt = '<III32I32Q16s'
    expected_size = struct.calcsize(fmt)
    if len(data) != expected_size:
        raise ValueError(f"Expected {expected_size} bytes for state_snapshot, got {len(data)} bytes")

    unpacked = struct.unpack(fmt, data)
    result = {
        "type": "state_snapshot",
        "pc": unpacked[1],
        "sp": unpacked[2],
        "x": list(unpacked[3:35]),
        "f": list(unpacked[35:67]),
        "instruction": unpacked[67].split(b'\x00', 1)[0].decode('ascii', errors='ignore')
    }
    return result

def parse_dwrite(data):
    fmt = '<IIQI64s'
    expected_size = struct.calcsize(fmt)
    if len(data) != expected_size:
        raise ValueError(f"Expected {expected_size} bytes for dwrite, got {len(data)} bytes")

    unpacked = struct.unpack(fmt, data)
    result = {
        "type": "dwrite",
        "pc": unpacked[1],
        "location": f"{unpacked[2]:08x}",
        "byte_size": unpacked[3],
        "data": unpacked[4][:unpacked[3]].hex().upper()
    }
    return result

def parse_trace_file(path):
    entries = []
    with open(path, 'rb') as f:
        while True:
            header = f.read(HEADER_BYTE_SIZE)
            if not header or len(header) < HEADER_BYTE_SIZE:
                break  # EOF
            entry_type = struct.unpack('<I', header)[0]
            f.seek(-4, 1)  # Rewind back

            if entry_type == TYPE_STATE_SNAPSHOT:
                data = f.read(STATE_SNAPSHOT_BYTE_SIZE)
                entries.append(parse_state_snapshot(data))
            elif entry_type == TYPE_DATA_WRITE:
                data = f.read(DATA_WRITE_BYTE_SIZE)
                entries.append(parse_dwrite(data))
            else:
                print(f"Unknown entry type {entry_type}, stopping.")
                break
    return entries


if __name__ == "__main__":
    # In case the parser needs to be manually tested
    parse_trace_file('/path/to/trace.bin')
