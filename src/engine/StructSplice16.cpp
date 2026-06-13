// Giants Engine - 16-byte Struct Splice Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "StructSplice16.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// SpliceStruct16 (FUN_004436c0) — 18 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Moves 16-byte entries from source [begin, end) to destination.
// Each entry is: [+0] 4 bytes, [+4..+7] skip, [+8..+F] 8 bytes.
// After moving, source entries are zeroed.
// Returns pointer past last written destination entry.

uint8_t* SpliceStruct16(uint8_t* begin, uint8_t* end, uint8_t* dest)
{
    uint8_t* writePtr = dest;
    for (uint8_t* src = begin; src != end; src += 0x10) {
        // Copy first 4 bytes
        *writePtr = *src;
        writePtr += 0x10;

        // Copy bytes 8-15 (high qword) using offset-based addressing
        *reinterpret_cast<uint32_t*>(src + reinterpret_cast<ptrdiff_t>(dest + 8 - reinterpret_cast<ptrdiff_t>(begin))) =
            *reinterpret_cast<uint32_t*>(src + 8);
        *reinterpret_cast<uint32_t*>(src + reinterpret_cast<ptrdiff_t>(dest + 0xc - reinterpret_cast<ptrdiff_t>(begin))) =
            *reinterpret_cast<uint32_t*>(src + 0xc);

        // Zero source entry
        *reinterpret_cast<uint32_t*>(src) = 0;
        *reinterpret_cast<uint32_t*>(src + 8) = 0;
        *reinterpret_cast<uint32_t*>(src + 0xc) = 0;
    }
    return writePtr;
}

} // namespace Giants
