// Giants Engine - Dynamic Array Grow Capacity Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "GrowCapacity.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

struct MemoryStats {
    int allocationCount; // offset 0x370
};

extern MemoryStats* g_MemoryStats; // DAT_00701a3c

// Simple int vector layout: { size(0x00), capacity(0x04), data(0x08) }

void GrowCapacity(int* vec, int newCapacity)
{
    int capacity = vec[1]; // offset 0x04
    if (capacity < newCapacity)
    {
        // Track new allocation
        if (g_MemoryStats != nullptr)
            g_MemoryStats->allocationCount += 1;

        int* newData = static_cast<int*>(malloc(newCapacity * 4));
        int* oldData = reinterpret_cast<int*>(vec[2]); // offset 0x08

        // Copy existing elements if we have data
        if (oldData != nullptr)
        {
            int size = vec[0]; // offset 0x00
            memcpy(newData, oldData, size * 4);

            // Track deallocation before freeing
            if (g_MemoryStats != nullptr)
                g_MemoryStats->allocationCount -= 1;

            free(oldData);
        }

        vec[2] = reinterpret_cast<int>(newData); // store new data ptr
        vec[1] = newCapacity;                     // store new capacity
    }
}

} // namespace Giants
