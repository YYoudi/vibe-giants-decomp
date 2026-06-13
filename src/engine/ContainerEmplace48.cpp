// Giants Engine - Container Emplace 0x48 Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ContainerEmplace48.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── External callees ──────────────────────────────────────────
extern void FUN_0042b0f0(uint32_t param);  // Container init callback
extern void FUN_00568ec0(uint32_t* dest, void* src);  // Vector grow + emplace

// ═══════════════════════════════════════════════════════════════════
// EmplaceContainer48 (FUN_00568df0) — 17 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Emplaces a zero-initialized 0x48-byte entry into a growing container.
//
// Container layout:
//   +0x20: current end pointer
//   +0x24: capacity pointer
//
// If end < capacity: zero-fill 18 uint32_t fields (0x48 bytes), advance end
// If end == capacity: call FUN_00568ec0 to grow the vector first

void EmplaceContainer48(int container, uint32_t param_2)
{
    uint32_t* endPtr = *reinterpret_cast<uint32_t**>(container + 0x20);
    uint32_t* capPtr = *reinterpret_cast<uint32_t**>(container + 0x24);

    if (endPtr != capPtr) {
        // Space available: zero-fill and advance
        endPtr[0] = 0;
        endPtr[1] = 0;
        endPtr[2] = 0;
        endPtr[3] = 0;
        endPtr[4] = 0;
        endPtr[5] = 0;
        endPtr[6] = 0;
        endPtr[7] = 0;
        endPtr[8] = 0;
        endPtr[9] = 0;
        endPtr[10] = 0;
        endPtr[0xb] = 0;
        endPtr[0xc] = 0;
        endPtr[0xd] = 0;
        endPtr[0xe] = 0;
        endPtr[0xf] = 0;
        *reinterpret_cast<uint64_t*>(endPtr + 0x10) = 0;
        *reinterpret_cast<int*>(container + 0x20) += 0x48;

        FUN_0042b0f0(param_2);
    } else {
        // Need to grow: build local 0x48-byte init block
        uint32_t local[18] = {0};

        FUN_00568ec0(endPtr, local);
        FUN_0042b0f0(param_2);
    }
}

} // namespace Giants
