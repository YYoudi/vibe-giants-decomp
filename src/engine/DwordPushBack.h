// Giants Engine - DWord Vector Push Back
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── PushDwordBack (FUN_004cfbe0) ── PASS ──
// Pushes a dword value to the back of a std::vector<uint32_t>-like container.
// Container layout: [+0] start ptr, [+4] end ptr, [+8] capacity ptr.
// If end == capacity, calls realloc helper FUN_0042c4e0.
// 22 callers, 1 callee.
void PushDwordBack(int container, uint32_t* value);  // FUN_004cfbe0

} // namespace Giants
