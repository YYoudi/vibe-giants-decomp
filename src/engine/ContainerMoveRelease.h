// Giants Engine - Container Move Release
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ContainerMoveRelease (FUN_0044f790) ── PASS ──
// Moves key-value pairs from [param_1, param_2) to param_3, zeroing source.
// Then calls SharedPtrReleaseRange on the result. 6 callers, 1 callee.
uint32_t* ContainerMoveRelease(uint32_t* param_1, uint32_t* param_2,
                               uint32_t* param_3, uint32_t param_4);  // FUN_0044f790
} // namespace Giants
