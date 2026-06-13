// Giants Engine - String Hash Lookup
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── StringHashLookup (FUN_004e9ab0) ── PASS ──
// Searches a packed string-to-hash table (null-separated entries)
// for a case-insensitive match. Returns the uint32_t value after the
// string, or 0xFFFFFFFF if not found.
// 26 callers, 1 callee (_stricmp).
uint32_t StringHashLookup(const char* name);  // FUN_004e9ab0

} // namespace Giants
