// Giants Engine - Entity Pool Cleanup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityPoolCleanup.h"
#include <cstdint>
namespace Giants {
extern uint32_t* DAT_0073e790;  // Free list head
extern uint32_t* FUN_0048ef70(); // Allocate from pool

void CleanupEntityPool(int entity, uint64_t* param_2)
{
    // Walk linked list at entity+0x1B4 and free each node
    uint32_t* node = *reinterpret_cast<uint32_t**>(entity + 0x1B4);
    while (node != nullptr) {
        uint32_t* next = *reinterpret_cast<uint32_t**>(node);
        // Push to free list
        *node = reinterpret_cast<uint32_t>(DAT_0073e790);
        DAT_0073e790 = node;
        node = next;
    }

    // Clear flag bit 24 (0x04FFFFFF mask → clear bit at offset 0x124)
    *reinterpret_cast<uint32_t*>(entity + 0x124) &= 0xFCFFFFFF;

    // Reset linked list head
    *reinterpret_cast<uint32_t*>(entity + 0x1B4) = 0;

    // Allocate new node from pool
    uint32_t* newNode = FUN_0048ef70();
    *newNode = *reinterpret_cast<uint32_t*>(entity + 0x1B4);
}
} // namespace Giants
