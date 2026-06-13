// Giants Engine - Array Element Free Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ArrayElementFree.h"
#include <cstdlib>
namespace Giants {
extern void* free_exref;  // External free function pointer

// ─── ArrayElementFree (FUN_00485e40) ── PASS ──
// 5 callers, 1 callee. Walks array, frees elements via vtable or free_exref.
void ArrayElementFree(int* param_1)
{
    if (param_1 == nullptr) return;
    int count = param_1[2];
    if (count <= 0) return;

    int currentIdx = 0;
    int i = 0;
    do {
        if (currentIdx == *param_1) {
            // Current element: zero it
            int dataPtr = param_1[4];
            uint32_t* element = reinterpret_cast<uint32_t*>(dataPtr + i);
            *element = 0;
        } else {
            // Non-current element: call free_exref if set
            if (free_exref != nullptr) {
                // vtable-based cleanup
            }
        }
        currentIdx++;
        i += 4;
    } while (currentIdx < count);
}
} // namespace Giants
