// Giants Engine - Random String Selector
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── SelectRandomString (FUN_005e81d0) ── PASS ──
// If param_1 is null, returns "Null". Otherwise, appends param_1
// to a string pool, queries for existing entry. If not found,
// retries up to 10 times, then picks random result.
// 24 callers, 6 callees.
char* SelectRandomString(char* param_1);  // FUN_005e81d0

} // namespace Giants
