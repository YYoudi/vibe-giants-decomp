// Giants Engine - Linked List Cleanup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "LinkedListCleanup.h"
#include "CRTStubs.h"
#include <cstdint>
namespace Giants {
void LinkedListCleanup(int* head)
{
    uint32_t* sentinel = reinterpret_cast<uint32_t*>(*head);

    // Clear the sentinel's back link
    *reinterpret_cast<uint32_t*>(sentinel[1]) = 0;

    // Walk the list from sentinel->next
    uint32_t* node = reinterpret_cast<uint32_t*>(*sentinel);
    while (node != nullptr) {
        int* subObj = reinterpret_cast<int*>(node[0xD]);  // +0x34 sub-object
        uint32_t* next = reinterpret_cast<uint32_t*>(*node);

        if (subObj != nullptr) {
            // Call vtable[4] destructor with (subObj != node+4) flag
            auto dtor = reinterpret_cast<void(*)(int)>(reinterpret_cast<int*>(*subObj + 0x10));
            dtor(subObj != reinterpret_cast<int*>(node + 4));
            node[0xD] = 0;  // Clear sub-object pointer
        }

        // Free the 0x38-byte node
        CRTFree(node);
        node = next;
    }

    // Free the sentinel itself
    CRTFree(reinterpret_cast<void*>(*head));
}
} // namespace Giants
