// Giants Engine - String Pool Lookup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── StringPoolLookup (FUN_005e99d0) ── PASS ──
// Looks up or creates a string pool entry by content. Uses hash table
// with chaining. If not found, allocates new entry, copies string,
// links into chain. Returns pointer to string data within entry.
// 32 callers, 3 callees.
void* StringPoolLookup(const char* str);  // FUN_005e99d0

} // namespace Giants
