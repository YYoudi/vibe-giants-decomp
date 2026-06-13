// Giants Engine - Container Iterator Operations
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── IterateContainer (FUN_004bc4b0) ──────────────────────────
// Advances through a container by N elements using stride-based iteration.
// If stride == 1, calls special handler. Otherwise walks element chain.
// 51 callers — container/collection traversal.
//
// @param out       Output: writes final element pointer here
// @param count     Number of elements to advance
// @param current   Current element pointer
// @param container Container descriptor (stride at +8)
// @return          out pointer (passthrough)
uint32_t* IterateContainer(uint32_t* out, int count, uint32_t current, int container);  // FUN_004bc4b0

} // namespace Giants
