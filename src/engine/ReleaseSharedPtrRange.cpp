// Giants Engine - Shared Pointer Range Release Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ReleaseSharedPtrRange.h"
#include <cstdint>
namespace Giants {
void ReleaseSharedPtrRange(int begin, int end)
{
    for (; begin != end; begin += 8) {
        int* refBlock = *reinterpret_cast<int**>(begin + 4);
        if (refBlock == nullptr) continue;

        // Decrement strong refcount (LOCK for thread safety)
        int strongRef;
        strongRef = refBlock[1] - 1;
        refBlock[1] = strongRef;

        if (strongRef == 0) {
            // Call destructor via vtable[0]
            auto* vtable = *reinterpret_cast<void***>(refBlock);
            reinterpret_cast<void(*)(void*)>(vtable[0])(refBlock);

            // Decrement weak refcount
            int weakRef;
            weakRef = refBlock[2] - 1;
            refBlock[2] = weakRef;

            if (weakRef == 0) {
                // Call deallocator via vtable[1]
                auto* vtable2 = *reinterpret_cast<void***>(refBlock);
                reinterpret_cast<void(*)(void*)>(vtable2[1])(refBlock);
            }
        }
    }
}
} // namespace Giants
