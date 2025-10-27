// SPDX-License-Identifier: BSD-3-Clause
//
// This file is part of ETISS. It is licensed under the BSD 3-Clause License; you may not use this file except in
// compliance with the License. You should have received a copy of the license along with this project. If not, see the
// LICENSE file.

/*
 * Taken from https://bitbucket.org/rafzi/hacklib
 */

#ifndef ETISS_MEMORY_H
#define ETISS_MEMORY_H

#include <vector>
#include <string>
#include <memory>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace etiss
{

#ifdef _WIN32

/// Represents a module handle. Can interpreted as pointer to the module base address.
typedef HINSTANCE ModuleHandle;

/// Represents a null value for hl::ModuleHandle.
static const ModuleHandle NullModuleHandle = NULL;

#else

/// Represents a module handle. Analogous to Windows this represents the module base address, not a dlopen handle!
typedef void *ModuleHandle;

/// Represents a null value for hl::ModuleHandle.
static const ModuleHandle NullModuleHandle = nullptr;

#endif

// An empty string requests the main module.
etiss::ModuleHandle GetModuleByName(const std::string &name = "");

// Returns hl::NullModuleHandle when the address does not reside in a module.
etiss::ModuleHandle GetModuleByAddress(uintptr_t adr);

std::string GetModulePath(etiss::ModuleHandle hModule);

/// Returns the module handle to the own dynamic library.
etiss::ModuleHandle GetCurrentModule();

/// Returns the abolute path with filename to the own dynamic library.
std::string GetCurrentModulePath();

} // namespace etiss

#endif