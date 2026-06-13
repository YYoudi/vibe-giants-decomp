// Giants Engine - Vtable Callback Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VtableCallbackDispatch.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// VtableCallbackDispatch (FUN_00631f00) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Two dispatch paths:
//   1. If *(obj+0x10) != NULL: call that function with 5 args
//   2. If p4 == 0: call *(obj+0x28) with 4 args (omits p4)
//   3. Otherwise: return 0xFFFFFFFF (error)

uint32_t VtableCallbackDispatch(int obj, uint32_t p2, uint32_t p3, int p4, uint32_t p5)
{
    // Primary callback at vtable+0x10
    auto* primaryFn = *reinterpret_cast<uint32_t**>(obj + 0x10);
    if (primaryFn != nullptr) {
        return reinterpret_cast<uint32_t(*)(uint32_t, uint32_t, uint32_t, int, uint32_t)>(
            *reinterpret_cast<void**>(primaryFn))(
                *reinterpret_cast<uint32_t*>(obj + 0x1c), p2, p3, p4, p5);
    }

    // Alternate callback at vtable+0x28 (no p4 parameter)
    if (p4 == 0) {
        auto* altObj = *reinterpret_cast<uint32_t**>(obj);
        return reinterpret_cast<uint32_t(*)(uint32_t, uint32_t, uint32_t, uint32_t)>(
            *reinterpret_cast<void**>(altObj + 0x28))(
                *reinterpret_cast<uint32_t*>(obj + 0x1c), p2, p3, p5);
    }

    return 0xFFFFFFFF;
}

} // namespace Giants
