// Giants Engine - Hash Table Clear Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "HashTableClear.h"
#include <cstdint>
#include <cstring>
namespace Giants {
void HashTableClear(int hashTablePtr)
{
    if (hashTablePtr == 0) return;

    // Hash table has 13 slots starting at hashTablePtr + 0x10
    for (int i = 0; i < 13; i++) {
        int* entry = reinterpret_cast<int*>(hashTablePtr + 0x10 + i * 4);
        if (*entry != 0) {
            // Call vtable destructor: entry->vtable[1](entry)
            int* obj = reinterpret_cast<int*>(*entry);
            int vtable = obj[0];  // vtable pointer at +0
            auto dtor = reinterpret_cast<void(*)(int)>(reinterpret_cast<int*>(vtable)[1]);
            dtor(*entry);
            *entry = 0;
        }
    }

    // Zero the count field
    *reinterpret_cast<int*>(hashTablePtr + 0x44) = 0;
}
} // namespace Giants
