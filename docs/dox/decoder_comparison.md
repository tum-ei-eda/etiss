Instruction Decoder Algorithms: Comparison {#decodercomparison}
==========================================

## Overview

ETISS supports two instruction decoding algorithms for matching fetched instruction bit patterns to their corresponding instruction definitions:

1. **Old Decoder (Chunk-based Tree Algorithm)**: The original algorithm that splits instructions into fixed-size chunks and uses set intersection
2. **New Decoder (Hierarchical Map Algorithm)**: A more direct lookup-based approach using nested maps

This document provides a detailed comparison of both algorithms, their implementation, performance characteristics, and use cases.

---

## Old Decoder: Chunk-based Tree Algorithm

### Algorithm Description

The old decoder uses a **chunk-based tree structure** to organize instructions. It divides instruction bit patterns into fixed-size chunks (default: 4 bits) and creates a hierarchical tree where each level corresponds to a chunk position.

#### Data Structure

```cpp
Node **root_;  // Array of groups, one per chunk position
// Each group is: Node[2^chunk_size]
// Each Node is: std::set<Instruction*>
```

**Structure:**
- **Groups**: One group per chunk position (e.g., for 32-bit instructions with 4-bit chunks: 8 groups)
- **Nodes**: Each group contains `2^chunk_size` nodes (e.g., 16 nodes for 4-bit chunks)
- **Buckets**: Each node is a set of instruction pointers that match that chunk value

#### Compilation Phase

**Algorithm:**
1. For each instruction in the instruction set:
   - Extract the opcode and mask
   - Split into chunks of size `chunk_size` (default: 4 bits)
   - For each chunk:
     - Identify don't-care bits (bits where mask = 0)
     - **Permutate** all possible values for don't-care bits
     - For each permutation, add the instruction to the corresponding node

**Example:**
For a 16-bit instruction with pattern `01XX 1101` (where `X` = don't care):
- Chunk 0: `01XX` → Permutates to: `0100`, `0101`, `0110`, `0111`
- Chunk 1: `1101` → No don't-cares, single value: `1101`
- Instruction is added to nodes: `root_[0][4]`, `root_[0][5]`, `root_[0][6]`, `root_[0][7]`, and `root_[1][13]`

**Time Complexity:** O(N × C × 2^D)
- N = number of instructions
- C = number of chunks (width / chunk_size)
- D = average number of don't-care bits per chunk

**Space Complexity:** O(N × C × 2^D)
- Each instruction may be stored in multiple nodes due to permutation

#### Decoding Phase

**Algorithm:**
1. Split the incoming instruction bit pattern into chunks
2. For each chunk:
   - Extract the chunk value
   - Look up the corresponding node: `root_[group_index][chunk_value]`
   - Get the set of instructions in that node
3. **Intersect** all sets from all chunks
4. Return the instruction (or the one with the most specific mask if multiple matches)

**Example:**
For fetched instruction `0111 1001 0110 0011`:
- Chunk 0: value = 3 → `root_[0][3]` → set S₀
- Chunk 1: value = 6 → `root_[1][6]` → set S₁
- Chunk 2: value = 9 → `root_[2][9]` → set S₂
- Chunk 3: value = 7 → `root_[3][7]` → set S₃
- Result: S₀ ∩ S₁ ∩ S₂ ∩ S₃

**Time Complexity:** O(C × M)
- C = number of chunks
- M = average number of instructions per node (can be large due to permutations)

**Space Complexity:** O(1) for decoding (uses existing tree structure)

---

## New Decoder: Hierarchical Map Algorithm

### Algorithm Description

The new decoder uses a **hierarchical nested map structure** for direct lookup. Instead of chunking and set intersection, it uses a three-level map indexed by instruction width, mask, and pattern.

#### Data Structure

```cpp
std::map<unsigned,                           // Level 1: Instruction width (16, 32, 64, ...)
         std::map<BitArray,                  // Level 2: Instruction mask
                  std::map<BitArray,         // Level 3: Instruction pattern (code & mask)
                           Instruction*>>>   // Value: Instruction pointer
    lut;
```

**Structure:**
- **Level 1 (Width)**: Groups instructions by bit width (16, 32, 64, etc.)
- **Level 2 (Mask)**: Groups by opcode mask (identifies which bits are significant)
- **Level 3 (Pattern)**: Maps the actual opcode pattern to the instruction

#### Compilation Phase

**Algorithm:**
1. For each instruction in the instruction set:
   - Extract: width, mask, and code
   - Compute: `pattern = code & mask` (extract only significant bits)
   - Store: `lut[width][mask][pattern] = instruction`

**Example:**
For a 32-bit instruction with:
- Code: `0xE0000000`
- Mask: `0xFC00030F`
- Pattern: `0xE0000000 & 0xFC00030F = 0xE0000000`
- Stored at: `lut[32][0xFC00030F][0xE0000000]`

**Time Complexity:** O(N)
- N = number of instructions
- Simple map insertion for each instruction

**Space Complexity:** O(N)
- Each instruction stored exactly once

#### Decoding Phase

**Algorithm:**
1. Get the mask map for the instruction width: `mask_map = lut[instr.size()]`
2. For each mask in the mask map:
   - Compute: `key = incoming_instruction & mask`
   - Check if `pattern_map.count(key)` exists
   - If found, add to candidate matches
3. If exactly one match: return it
4. If multiple matches: return the instruction with the **highest popcount** (most specific mask, i.e., most 1-bits)
5. If no matches: return `nullptr`

**Example:**
For fetched instruction `0xE0000000`:
- Iterate through all masks in `lut[32]`
- For mask `0xFC00030F`: `key = 0xE0000000 & 0xFC00030F = 0xE0000000`
- Check `lut[32][0xFC00030F][0xE0000000]`
- Return the instruction

**Time Complexity:** O(M)
- M = number of unique masks (typically much smaller than N)
- Each mask lookup is linear (iteration), and pattern lookup is O(log P) for std::map (where P is patterns per mask)
- Profiling showed no significant difference when using `std::unordered_map` instead of `std::map`, suggesting that `std::map` is sufficient. and no need for custom std::hash<etiss::instr::BitArray> implementation.

**Space Complexity:** O(1) for decoding (uses existing map structure)
