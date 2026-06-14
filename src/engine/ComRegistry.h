// GiantsRE — COM subsystem registry (functional reconstruction).
//
// The original engine uses a COM-like service registry: subsystems are created
// during PreInitCheck, each carrying a GUID (e.g. DAT_0065cdf8), and registered
// via the engine-context's vtable[1] (DAT_0073c924 -> Register(GUID, obj)).
// Factories (FUN_00461a60 etc.) then query the registry by GUID to obtain
// subsystem instances.
//
// The exact internal layout of the original registry is not byte-recoverable
// without full RE, but the BEHAVIOR (register by GUID, query by GUID) is what
// matters. This file provides that functional registry so the ported COM
// functions work. Confirmed by the live proxy dump (commit 25b036a): the engine
// context (DAT_0073c924) holds registered subsystem objects in arrays.
#pragma once
#include <cstdint>

namespace Giants {

// A "GUID" in the Giants COM sense — a pointer to a .rdata type descriptor
// (e.g. &DAT_0065cdf8). We key on the pointer value (stable per type).
using ComGuid = const void*;

// Register a subsystem object under its GUID (refcount-bumped). Mirrors the
// original's engine-context vtable[1] register call. Returns the object.
void* ComRegister(ComGuid guid, void* obj);

// Query the registry for a subsystem by GUID. Returns nullptr if not registered.
// Mirrors the factory lookup pattern in FUN_00461a60.
void* ComQuery(ComGuid guid);

// Number of subsystems currently registered (for diagnostics).
int ComRegistryCount();

} // namespace Giants
