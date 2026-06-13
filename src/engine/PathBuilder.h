// Giants Engine - Path Builder
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BuildFilePath (FUN_00453a40) ── PASS ──
// Builds a file path by concatenating param_1 with optional wrapping.
// If param_4 == 0: simple strncat. Otherwise wraps in parentheses.
// Uses DAT_0065de44 separator. 15 callers, 4 callees.
void BuildFilePath(const char* name, char* output, uint32_t param3, int wrapMode);  // FUN_00453a40

} // namespace Giants
