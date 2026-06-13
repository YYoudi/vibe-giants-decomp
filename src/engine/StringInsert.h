// Giants Engine - String Insert (SSO-aware std::string::insert)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── StringInsert (FUN_0043fcf0) ── PASS ──
// std::string::insert at offset with char* source. SSO-aware with
// 1.5x grow strategy, heap/inline buffer management.
// 10 callers, ~3 callees.
uint32_t* StringInsert(uint32_t* strObj, uint32_t offset, const char* src, uint32_t count);  // FUN_0043fcf0
} // namespace Giants
