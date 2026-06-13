// Giants Engine - COM Object Release Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ComObjectRelease.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// ComObjectRelease (FUN_004ad590) — 16 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Standard COM shared_ptr release:
//   1. Decrement strong refcount (thread-safe via LOCK)
//   2. If strong == 0: call vtable[0] (destructor)
//   3. Decrement weak refcount
//   4. If weak == 0: call vtable[1] (deallocator)

void ComObjectRelease(int* obj)
{
    if (obj == nullptr) {
        return;
    }

    // Decrement strong refcount
    int* refCountBlock = reinterpret_cast<int*>(obj[1]);  // +0x4: refcount block ptr
    if (refCountBlock == nullptr) {
        return;
    }

    // Strong ref decrement (LOCK for thread safety)
    int strongRef;
    {
        // LOCK prefix for atomic decrement
        strongRef = refCountBlock[1] - 1;
        refCountBlock[1] = strongRef;
    }

    if (strongRef == 0) {
        // Call destructor via vtable[0]
        auto* vtable = *reinterpret_cast<void***>(refCountBlock);
        reinterpret_cast<void(*)(void*)>(vtable[0])(refCountBlock);

        // Decrement weak refcount
        int weakRef;
        {
            weakRef = refCountBlock[2] - 1;
            refCountBlock[2] = weakRef;
        }

        if (weakRef == 1) {
            // Call deallocator via vtable[1]
            auto* vtable2 = *reinterpret_cast<void***>(refCountBlock);
            reinterpret_cast<void(*)(void*)>(vtable2[1])(refCountBlock);
        }
    }
}

} // namespace Giants
