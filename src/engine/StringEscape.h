// Giants Engine - String Escape with SSO
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── BuildStringFromIterator (FUN_00434860) ── FAIL (usable ~80%) ──
// Builds an SSO std::string from a byte iterator range [param_1+0x20, param_1+0x24).
// Control chars (<0x20) are formatted as "<U+XXXX>". Printable chars appended directly.
// Full SSO-aware reallocation with grow strategy.
// 23 callers, 8 callees.
void BuildStringFromIterator(int param_1, uint32_t* outString);  // FUN_00434860

} // namespace Giants
