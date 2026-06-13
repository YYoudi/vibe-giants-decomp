// Giants Engine - String Copy Iterator
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StringCopyIterator (FUN_004bb410) ── PASS ──
// Copies string from source to destination with iterator, tracking length.
// Returns pointer past end of written data. 7 callers, 0 callees.
char* StringCopyIterator(char* dest, const char* src);  // FUN_004bb410
} // namespace Giants
