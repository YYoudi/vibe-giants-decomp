// Giants Engine - Shared Pointer Release Range Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "SharedPtrReleaseRange.h"
#include <cstdint>
namespace Giants {
void SharedPtrReleaseRange(int param_1, int param_2)
{
    for (int it = param_1; it != param_2; it += 8) {
        int* ctrl = *reinterpret_cast<int**>(it + 4);
        if (ctrl == nullptr) continue;

        // Decrement strong refcount (atomic via LOCK)
        int32_t oldRef = ctrl[1];
        ctrl[1] = oldRef - 1;

        if (oldRef == 0) {
            // Strong refcount reached zero — call destructor via vtable[0]
            int* vtable = *reinterpret_cast<int**>(*ctrl);
            auto dtor = reinterpret_cast<void(*)()>(vtable[0]);
            dtor();

            // Decrement weak refcount
            int32_t oldWeak = ctrl[2];
            ctrl[2] = oldWeak - 1;

            if (oldWeak == 0) {
                // Weak refcount reached zero — call deallocator via vtable[1]
                auto dealloc = reinterpret_cast<void(*)()>(reinterpret_cast<int**>(*ctrl)[1]);
                dealloc();
            }
        }
    }
}
} // namespace Giants
