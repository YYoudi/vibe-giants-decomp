// Giants Engine - Wide Path Parse
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── WidePathParse (FUN_004400d0) ── PASS ──
// Parses wide-char path string, handling UNC prefixes (\\?\, \\.\\, \\).
// Returns pointer past the prefix/scheme portion. 6 callers, 0 callees.
uint32_t* WidePathParse(uint32_t* param_1, uint32_t* param_2);  // FUN_004400d0
} // namespace Giants
