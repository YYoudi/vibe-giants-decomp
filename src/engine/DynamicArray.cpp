// Giants Engine - Dynamic Array Resize Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "DynamicArray.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern int g_globalValue;  // DAT_00701a3c — AnimationCalc.cpp
static uint32_t DAT_00701a3c = 1954305085u;  // faithful @0x00701A3C  // Allocation tracker

// ═══════════════════════════════════════════════════════════════════
// ArrayResizeDword (FUN_004810b0) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Array header: [+0] size, [+4] capacity, [+8] data pointer.
// If newCapacity > current capacity:
//   1. Increment allocation counter (if tracker set)
//   2. malloc(newCapacity * 4)
//   3. Copy existing data (size * 4 bytes)
//   4. Free old buffer (decrement counter)
//   5. Update header

void ArrayResizeDword(int* arrayHeader, int newCapacity)
{
    if (arrayHeader[1] < newCapacity) {
        if (DAT_00701a3c != 0) {
            *reinterpret_cast<int*>(DAT_00701a3c + 0x370) += 1;
        }

        void* newBuf = malloc(newCapacity * 4);
        if (reinterpret_cast<void*>(arrayHeader[2]) != nullptr) {
            memcpy(newBuf, reinterpret_cast<void*>(arrayHeader[2]), *arrayHeader * 4);
            void* oldBuf = reinterpret_cast<void*>(arrayHeader[2]);
            if (oldBuf != nullptr && DAT_00701a3c != 0) {
                *reinterpret_cast<int*>(DAT_00701a3c + 0x370) -= 1;
            }
            free(oldBuf);
        }
        arrayHeader[2] = reinterpret_cast<int>(newBuf);
        arrayHeader[1] = newCapacity;
    }
}

// ═══════════════════════════════════════════════════════════════════
// ArrayResizeQword (FUN_00481950) — 20 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Same as ArrayResizeDword but with 8-byte element stride.

void ArrayResizeQword(int* arrayHeader, int newCapacity)
{
    if (arrayHeader[1] < newCapacity) {
        if (DAT_00701a3c != 0) {
            *reinterpret_cast<int*>(DAT_00701a3c + 0x370) += 1;
        }

        void* newBuf = malloc(newCapacity * 8);
        if (reinterpret_cast<void*>(arrayHeader[2]) != nullptr) {
            memcpy(newBuf, reinterpret_cast<void*>(arrayHeader[2]), *arrayHeader * 8);
            void* oldBuf = reinterpret_cast<void*>(arrayHeader[2]);
            if (oldBuf != nullptr && DAT_00701a3c != 0) {
                *reinterpret_cast<int*>(DAT_00701a3c + 0x370) -= 1;
            }
            free(oldBuf);
        }
        arrayHeader[2] = reinterpret_cast<int>(newBuf);
        arrayHeader[1] = newCapacity;
    }
}

} // namespace Giants
