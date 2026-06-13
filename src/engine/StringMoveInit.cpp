// Giants Engine - SSO String Move Init Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StringMoveInit.h"
#include <cstdint>

namespace Giants {

// ─── External callee ──────────────────────────────────────
// FUN_0043fcf0: Allocates/copies string data into SSO buffer
extern uint32_t* FUN_0043fcf0(int mode, const char* src, int len);

// ═══════════════════════════════════════════════════════════════════
// StringMoveFromCStr (FUN_0043fe80) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Initializes an MSVC std::string (24-byte SSO layout) from a C-string.
// Layout: [0] data/inline[0], [4] inline[1]/size, [8] inline[2],
//         [12] inline[3]/capacity_or[0], [16] capacity, [20] size
//
// Steps:
//   1. Measure strlen(param_2)
//   2. Call FUN_0043fcf0 to allocate and copy into a temp buffer
//   3. Zero dest (6 × uint32_t)
//   4. Move 24 bytes from temp to dest
//   5. Reset temp to empty SSO (capacity=0xF, data[0]=0)
//   6. Return dest

uint32_t* StringMoveFromCStr(uint32_t* dest, const char* src)
{
    // Measure string length
    const char* scan = src;
    char c;
    do { c = *scan; scan++; } while (c != '\0');
    int len = static_cast<int>(scan - src) - 1;

    // Allocate/copy via helper
    uint32_t* temp = FUN_0043fcf0(0, src, len);

    // Zero dest
    dest[0] = 0;
    dest[1] = 0;
    dest[2] = 0;
    dest[3] = 0;
    dest[4] = 0;
    dest[5] = 0;

    // Move SSO fields (4 × uint32_t data + 2 × uint32_t meta)
    uint32_t t1 = temp[1];
    uint32_t t2 = temp[2];
    uint32_t t3 = temp[3];
    dest[0] = temp[0];
    dest[1] = t1;
    dest[2] = t2;
    dest[3] = t3;
    *reinterpret_cast<uint64_t*>(dest + 4) = *reinterpret_cast<uint64_t*>(temp + 4);

    // Reset temp to empty SSO state
    temp[4] = 0;
    temp[5] = 0xF;  // SSO capacity marker
    *reinterpret_cast<uint8_t*>(temp) = 0;

    return dest;
}

} // namespace Giants
