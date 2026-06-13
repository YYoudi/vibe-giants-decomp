// Giants Engine - Struct Initialization Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StructInit5.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// InitStruct5 (FUN_004359d0) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Sets type field to 5 and stores a 32-bit value at +8/+0xC.
// Likely an event/message descriptor initialization.

void InitStruct5(uint8_t* param_1, int32_t param_2)
{
    param_1[0] = 5;                    // +0x00: type = 5
    *reinterpret_cast<int32_t*>(param_1 + 8) = param_2;   // +0x08: value low
    *reinterpret_cast<int32_t*>(param_1 + 0xC) = param_2 >> 31;  // +0x0C: sign extend
}

} // namespace Giants
