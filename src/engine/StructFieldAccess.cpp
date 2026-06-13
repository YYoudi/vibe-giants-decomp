// Giants Engine - Struct Field Accessor Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StructFieldAccess.h"

namespace Giants {

extern void OutOfBoundsHandler(uint64_t* out);  // FUN_005fac30

// ═══════════════════════════════════════════════════════════════════
// GetStructField (FUN_0056cd80) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Reads a 12-byte field from struct at param_1:
//   outField[0] = *(uint64_t*)(param_1 + 0xf0)
//   outField[1] = *(uint32_t*)(param_1 + 0xf8)  (lower 32 bits)
// Validates param_2 is in [0, param_1+0x328).

void GetStructField(int param_1, int param_2, uint64_t* outField)
{
    if (param_2 < 0)
    {
        OutOfBoundsHandler(outField);
        return;
    }

    if (param_2 >= *reinterpret_cast<int*>(param_1 + 0x328))
    {
        OutOfBoundsHandler(outField);
        return;
    }

    outField[0] = *reinterpret_cast<uint64_t*>(param_1 + 0xf0);
    *reinterpret_cast<uint32_t*>(outField + 1) = *reinterpret_cast<uint32_t*>(param_1 + 0xf8);
}

} // namespace Giants
