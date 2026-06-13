// Giants Engine - String Comparison Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringCompare.h"
#include <cstdint>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern uint32_t DAT_0067d280;  // Security cookie — defined in CRTStubs.cpp

// ─── Forward declarations for callees ──────────────────────────
extern void FUN_004431a0(uint32_t strPtr);    // String acquire/init
extern int  FUN_0043b1e0(void* str1, uint32_t len1, void* str2, uint32_t len2, uint32_t cookie);
extern void FUN_004439b0();                    // String release/cleanup

// ═══════════════════════════════════════════════════════════════════
// CompareStringEntries (FUN_0044fa40) — 27 callers — FAIL (usable ~85%)
// ═══════════════════════════════════════════════════════════════════
// Compares two string entries from a sorted container.
// Extracts string data from param+0x1c offset, performs comparison.
// Returns 0 if strings are equal, 1 if different.

uint8_t CompareStringEntries(int* param_1, int* param_2)
{
    // Acquire string references from both entries
    FUN_004431a0(*reinterpret_cast<uint32_t*>(*param_2 + 0x1c));
    FUN_004431a0(*reinterpret_cast<uint32_t*>(*param_1 + 0x1c));

    // SSO string buffers — max 16 bytes inline, else heap pointer
    // local_44[0..3] = string 1 buffer (or pointer if > 15 chars)
    // local_2c[0..3] = string 2 buffer (or pointer if > 15 chars)
    uint32_t strBuf1[4];  // SSO string 1
    uint32_t strBuf2[4];  // SSO string 2
    uint32_t len1 = 0;
    uint32_t len2 = 0;

    // Get actual data pointer (SSO vs heap)
    uint8_t* data1 = reinterpret_cast<uint8_t*>(strBuf1);
    uint8_t* data2 = reinterpret_cast<uint8_t*>(strBuf2);

    // String comparison via specialized comparator
    int cmpResult = FUN_0043b1e0(data2, len2, data1, len1,
        DAT_0067d280 ^ reinterpret_cast<uint32_t>(&cmpResult));

    // Release string references
    FUN_004439b0();
    FUN_004439b0();

    // Return 0 if equal (cmpResult == 0), 1 if different
    if (cmpResult == 0) return 0;
    if (cmpResult > 0) return 0;
    return 1;
}

} // namespace Giants
