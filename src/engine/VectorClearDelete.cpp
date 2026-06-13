// Giants Engine - Vector Clear & Delete Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VectorClearDelete.h"
#include "CRTStubs.h"
#include <cstdlib>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// ClearAndDeleteElements (FUN_0042c810) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void ClearAndDeleteElements(int* vecObj)
{
    int* first = reinterpret_cast<int*>(vecObj[0]);  // _Myfirst
    if (first == nullptr)
        return;

    int* last = reinterpret_cast<int*>(vecObj[1]);   // _Mylast
    for (int* it = first; it != last; it++)
    {
        if (*it != 0)
        {
            // Call scalar deleting destructor via vtable
            // In ground truth, we just free the object
            void* obj = reinterpret_cast<void*>(*it);
            free(obj);
        }
    }

    // Free the vector buffer itself
    unsigned int byteSize = (vecObj[2] - reinterpret_cast<int>(first)) & 0xFFFFFFFC;
    int blockStart = reinterpret_cast<int>(first);

    if (byteSize > 0xFFF)
    {
        blockStart = *reinterpret_cast<int*>(reinterpret_cast<int>(first) - 4);
        unsigned int adjustedSize = byteSize + 0x23;
        if (static_cast<unsigned int>(reinterpret_cast<int>(first) - blockStart - 4) > 0x1F)
            return;  // debug check failure
        CRTFree(reinterpret_cast<void*>(blockStart));
    }
    else
    {
        CRTFree(reinterpret_cast<void*>(blockStart));
    }

    vecObj[0] = 0;  // _Myfirst = null
    vecObj[1] = 0;  // _Mylast = null
    vecObj[2] = 0;  // _Myend = null
}

// ═══════════════════════════════════════════════════════════════════
// VectorClear (FUN_00430380) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
void VectorClear(int* vecObj)
{
    int first = vecObj[0];  // _Myfirst
    if (first == 0)
        return;

    // Calculate buffer size
    unsigned int byteSize = (vecObj[2] - first) & 0xFFFFFFFC;
    int blockStart = first;

    if (byteSize > 0xFFF)
    {
        // MSVC debug heap: real allocation base is at (first - 4)
        blockStart = *reinterpret_cast<int*>(first - 4);
        unsigned int adjustedSize = byteSize + 0x23;
        if (static_cast<unsigned int>((first - blockStart) - 4) > 0x1F)
            return;  // iterator debug check failure
    }

    CRTFree(reinterpret_cast<void*>(blockStart));

    vecObj[0] = 0;  // _Myfirst = null
    vecObj[1] = 0;  // _Mylast = null
    vecObj[2] = 0;  // _Myend = null
}

} // namespace Giants
