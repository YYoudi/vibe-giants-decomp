// Giants Engine - Container Iterator Operations Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ContainerIter.h"

namespace Giants {

// External callees
extern void      HandleSingleStride(uint32_t current, int container);  // FUN_004bc460
extern uint32_t* LookupContainerElement(uint32_t table, uint32_t current);  // FUN_004bbe90

// ═══════════════════════════════════════════════════════════════════
// IterateContainer (FUN_004bc4b0) — 51 callers
// ═══════════════════════════════════════════════════════════════════
// Container iterator: advances through a linked/stride-based container.
// Stride == 1 triggers a special handler (likely array direct access).
// Otherwise, walks the element chain by looking up each element.

uint32_t* IterateContainer(uint32_t* out, int count, uint32_t current, int container)
{
    uint8_t stride = *reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(container) + 8);

    if (stride == 1) {
        HandleSingleStride(current, container);
        return out;
    }

    if (count != 0) {
        do {
            uint32_t* element = LookupContainerElement(
                static_cast<uintptr_t>(container) + static_cast<uint32_t>(stride) * 2,
                current
            );
            current = *element;
            count = count - 1;
        } while (count != 0);
    }

    *out = current;
    return out;
}

} // namespace Giants
