// Giants Engine - String Comparison
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── CompareStringEntries (FUN_0044fa40) ── FAIL (usable ~85%) ──
// Compares two string entries from a container. Extracts strings at
// param+0x1c, performs string comparison via FUN_0043b1e0, returns
// 0 if equal, 1 if different.
// 27 callers, 4 callees (FUN_004431a0 x2, FUN_0043b1e0, FUN_004439b0 x2).
uint8_t CompareStringEntries(int* param_1, int* param_2);  // FUN_0044fa40

} // namespace Giants
