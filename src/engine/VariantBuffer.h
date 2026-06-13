// Giants Engine - Variant Buffer Operations
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── CleanupVariantBuffer (FUN_004d3a50) ── PASS ──
// Cleans up a variant/typed buffer based on its type field.
// type 3: linked-list walk and free each node
// type 0: single allocation free (if ownership bit set)
// type 2: alternate buffer free (if ownership bit set)
// 44 callers, 1 callee.
void CleanupVariantBuffer(uint32_t param_1, int* param_2);  // FUN_004d3a50

} // namespace Giants
