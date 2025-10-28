// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_INCLUDE_CLASSDEFS_H_
#define ETISS_INCLUDE_CLASSDEFS_H_

///> forwards: include/jit/*
#ifdef __cplusplus
extern "C"
{
#endif

    struct ETISS_CPU;
    struct ETISS_System;

#ifdef __cplusplus
}
#endif
///< forwards: include/jit/*

namespace etiss
{
class BlockLink;

class CodeBlock;
class CodePart;
class CodeSet;
class CoroutinePlugin;
class CPUArch;
class CPUCore;
class CPUArchRegListenerInterface;

class InterruptEnable;
class InterruptListenerPlugin;
class InterruptVector;

class JIT;

class LibraryInterface;

class MemSegment;
class SimpleMemSystem;

class Plugin;

class RegisterDevicePlugin;

class System;
class SimpleSystem;

class SystemWrapperPlugin;

class Translation;
class TranslationPlugin;

class VirtualStruct;

namespace instr
{
class Buffer;
class BitArray;
class BitArrayRange;
class Instruction;
class InstructionClass;
class InstructionContext;
class InstructionDefinition;
class InstructionGroup;
class InstructionSet;
class OPCode;
class ModedInstructionSet;
class VariableInstructionSet;

} // namespace instr

namespace interfaces
{
class Delegate;
}

namespace mm
{
class DMMUWrapper;
class MMU;
} // namespace mm

namespace fault
{
class Trigger;
class Fault;
class Action;
} // namespace fault

namespace plugin
{

namespace gdb
{
class Connection;
class PacketProtocol;
} // namespace gdb

} // namespace plugin

} // namespace etiss

#endif
