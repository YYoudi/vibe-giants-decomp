// Giants Engine - Dynamic Buffer Resize Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "DynamicBufferResize.h"
#include <cstdint>
#include <cstdlib>
#include <cstring>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern int DAT_00701a3c;  // Stats/allocator context pointer

// ═══════════════════════════════════════════════════════════════════
// DynamicBufferResize (FUN_004830d0) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Buffer descriptor layout (size_t* param_1):
//   [+0] = current data size (bytes)
//   [+1] = current capacity
//   [+2] = data pointer

void DynamicBufferResize(size_t* bufDesc, size_t newCapacity)
{
    // Only grow, never shrink
    if (static_cast<int>(bufDesc[1]) >= static_cast<int>(newCapacity)) {
        return;
    }

    // Increment allocation counter
    if (DAT_00701a3c != 0) {
        *reinterpret_cast<int*>(DAT_00701a3c + 0x370) += 1;
    }

    // Allocate new buffer
    void* newBuf = malloc(newCapacity);

    // Copy existing data
    if (reinterpret_cast<void*>(bufDesc[2]) != nullptr) {
        memcpy(newBuf, reinterpret_cast<void*>(bufDesc[2]), bufDesc[0]);

        // Free old buffer
        void* oldBuf = reinterpret_cast<void*>(bufDesc[2]);
        if (oldBuf != nullptr && DAT_00701a3c != 0) {
            *reinterpret_cast<int*>(DAT_00701a3c + 0x370) -= 1;
        }
        free(oldBuf);
    }

    bufDesc[2] = reinterpret_cast<size_t>(newBuf);
    bufDesc[1] = newCapacity;
}

} // namespace Giants
