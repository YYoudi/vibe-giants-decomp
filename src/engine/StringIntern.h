// Giants Engine - String Intern Table
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── InternString (FUN_005e99d0) ── FAIL (usable ~85%) ──
// String interning: returns a unique pointer for each unique string.
// Uses hash-based lookup in a page-based table (InternPage linked lists).
// If string not found, allocates new page and copies string.
// 32 callers, 3 callees.
char* InternString(char* str);  // FUN_005e99d0

} // namespace Giants
