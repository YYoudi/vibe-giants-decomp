// Giants Engine - Wide String Assign (std::wstring::assign)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
#include <string>
namespace Giants {
// ─── WStringAssign (FUN_00441d10) ── PASS ──
// std::wstring::assign(const std::wstring& _Right). SSO-aware with
// 1.5x grow strategy, heap/inline buffer management, CRT validation.
// Uses MSVC _Bx._Ptr/_Buf and _Myres/_Mysize internals.
// 10 callers, ~3 callees.
std::wstring* WStringAssign(std::wstring* dest, const std::wstring* src);  // FUN_00441d10
} // namespace Giants
