// Giants Engine - Byte Vector Push Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VectorPushByte.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// PushByteToVector (FUN_0044a950) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Pushes `count` bytes from `src` into `vec` (growing byte vector).
// Vector struct: [+0] vtable/next, [+4] data ptr, [+8] size, [+12] capacity
// On overflow, calls vtable[0] to reallocate.
// Returns `vec` via `out`.

uint32_t* PushByteToVector(uint32_t* out, int count, uint32_t* vec, const uint8_t* src)
{
    if (count < 1) {
        *out = reinterpret_cast<uint32_t>(vec);
        return out;
    }

    do {
        // Check if capacity needs to grow
        uint32_t size = vec[2];
        uint32_t capacity = vec[3];
        if (capacity < size + 1) {
            // Call vtable[0] to grow — realloc
            typedef void (*GrowFn)(uint32_t);
            GrowFn grow = reinterpret_cast<GrowFn>(
                *reinterpret_cast<uint32_t*>(vec[0]));
            grow(size + 1);
        }
        // Push byte
        *reinterpret_cast<uint8_t*>(vec[1] + size) = *src;
        vec[2] = size + 1;
        count--;
    } while (count != 0);

    *out = reinterpret_cast<uint32_t>(vec);
    return out;
}

} // namespace Giants
