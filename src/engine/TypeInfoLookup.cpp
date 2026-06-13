// Giants Engine - Type Info Lookup with Exception Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TypeInfoLookup.h"
#include <cstdint>
#include <cstdlib>

namespace Giants {

// ─── External callees ──────────────────────────────────────────
extern uint32_t DAT_0067d280;    // Security cookie — CRTStubs.cpp
extern int*     FUN_004318a0();  // Type info vtable lookup
extern uint32_t FUN_0043fc70(uint32_t cookie);  // Type descriptor init
extern uint32_t FUN_00442f40(uint32_t desc);    // Type info construct
extern uint32_t FUN_0043fe80(uint32_t str);     // SSO string init
extern void     FUN_0043fef0(uint32_t obj);     // Name setup

// ═══════════════════════════════════════════════════════════════════
// LookupTypeInfoOrThrow (FUN_00603e80) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Two paths:
//   1. If param_1[0] == 1: Direct RTTI lookup via vtable, return ptr+0x28
//   2. Otherwise: Build type_info object, throw _CxxThrowException

int LookupTypeInfoOrThrow(char* param_1)
{
    if (*param_1 == '\x01') {
        // Fast path: direct lookup
        int* result = FUN_004318a0();
        return *result + 0x28;
    }

    // Slow path: construct type_info and throw
    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&param_1);

    uint32_t typeDesc = FUN_0043fc70(cookie);
    uint32_t typeInfo = FUN_00442f40(typeDesc);
    uint32_t nameStr = FUN_0043fe80(typeInfo);

    FUN_0043fef0(nameStr);

    // Throw — does not return
    // _CxxThrowException(local_64, &DAT_00678038)
    // Stub: we abort since this path represents a type error
    std::abort();
    return 0;  // Unreachable
}

} // namespace Giants
