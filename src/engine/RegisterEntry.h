// Giants Engine - Register Entry (linked list with hash + string)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── RegisterEntry (FUN_0048f130) ── FAIL (usable ~80%) ──
// Registers an entry in a doubly-linked list with hash dedup.
// Allocates 0x38 byte nodes with string SBO, position floats, params.
// Inserts at head of intrusive list via sentinel.
// 17 callers, ~6 callees.
int RegisterEntry(const char* name, uint32_t param2, uint32_t param3,
                  float xmm1, float xmm2, float xmm3);  // FUN_0048f130

} // namespace Giants
