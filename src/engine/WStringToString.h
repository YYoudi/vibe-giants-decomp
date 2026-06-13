// Giants Engine - Wide String to Narrow String Converter
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>
#include <string>

namespace Giants {

// ─── WStringToString (FUN_00441e50) ── PASS ──
// Converts std::wstring to std::string using ___std_fs_convert_wide_to_narrow_20.
// SSO-aware for both source and result. Handles code page, buffer grow, and
// error cases.
// 19 callers, ~4 callees.
std::string* WStringToString(std::wstring* wideStr, std::string* result);  // FUN_00441e50

} // namespace Giants
