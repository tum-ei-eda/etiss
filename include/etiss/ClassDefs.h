// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

#ifndef ETISS_INCLUDE_CLASSDEFS_H_
#define ETISS_INCLUDE_CLASSDEFS_H_

namespace etiss
{

class Plugin;
class CPUArch;
class CPUCore;

class TranslationPlugin;
class CoroutinePlugin;
class SystemWrapperPlugin;
class RegisterDevicePlugin;
class InterruptListenerPlugin;

class Translation;

namespace instr
{

class BitArray;
class BitArrayRange;
class VariableInstructionSet;
class ModedInstructionSet;

} // namespace instr

} // namespace etiss
#endif
