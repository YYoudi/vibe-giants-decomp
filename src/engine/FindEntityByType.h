// Giants Engine - Find Entity By Type
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── FindEntityByType (FUN_0053ea80) ── PASS ──
// Searches entity linked list (DAT_007027b0) for entity with type 0x3DF,
// matching param_1 at offset +0x264, and flag 0x8000 clear at +0x124.
// Returns entity or 0. 10 callers, 0 callees (self-contained).
int FindEntityByType(int matchValue);  // FUN_0053ea80
} // namespace Giants
