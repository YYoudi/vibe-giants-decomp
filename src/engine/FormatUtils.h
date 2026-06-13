// Giants Engine - Format/String Utilities
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── FormatUIntToBuffer (FUN_004ce120) ── PASS ──
// Formats an unsigned integer into a string buffer using format "{:02}".
// param_1 = value to format, param_2 = output buffer/stream object.
// For values < 100: writes two ASCII digits directly.
// For values >= 100: delegates to FUN_004cdfc0 with "{:02}" format.
// 44 callers, 2 callees.
void FormatUIntToBuffer(uint32_t param_1, uint32_t* param_2);  // FUN_004ce120

} // namespace Giants
