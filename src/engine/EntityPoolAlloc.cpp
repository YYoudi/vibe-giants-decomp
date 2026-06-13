// Giants Engine - Entity Pool Allocator Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityPoolAlloc.h"
#include <cstring>
namespace Giants {
extern uint32_t* DAT_007027f8;  // Free list head
extern uint32_t* DAT_007027f4;  // Active list head
extern uint32_t DAT_007028f4;   // Entity system base
extern void FUN_00498080();     // Entity init (no pool)
extern void FUN_005fade0(void* ctx);     // Get entity context

void EntityPoolAlloc(uint32_t param_1, int param_2)
{
    if (param_2 == 0) {
        FUN_00498080();
        return;
    }

    uint64_t localCtx;
    uint32_t localExtra;
    FUN_005fade0(&localCtx);

    // Allocate from free list or walk active list to tail
    uint32_t* newNode;

    if (DAT_007027f8 == nullptr) {
        // No free nodes: walk active list to tail
        newNode = reinterpret_cast<uint32_t*>(*DAT_007027f4);
        uint32_t* prev = DAT_007027f4;
        uint32_t* current = newNode;

        if (current != nullptr) {
            do {
                prev = current;
                current = reinterpret_cast<uint32_t*>(*current);
            } while (current != nullptr);
            newNode = reinterpret_cast<uint32_t*>(*prev);
        }
        *prev = 0;  // Detach from list
    } else {
        // Reuse from free list
        newNode = DAT_007027f8;
        DAT_007027f8 = reinterpret_cast<uint32_t*>(*DAT_007027f8);
    }

    // Initialize 0x48 bytes
    memset(newNode, 0, 0x48);

    // Link into active list
    *newNode = reinterpret_cast<uint32_t>(DAT_007027f4);
    DAT_007027f4 = newNode;

    // Set up entity fields
    newNode[0xD] = reinterpret_cast<uint32_t>(newNode + 1);  // Self-pointer +4
    *reinterpret_cast<uint64_t*>(&newNode[5]) = localCtx;     // +0x14: context
    newNode[0xE] = param_1;                                    // +0x38: param
    newNode[7] = localExtra;                                   // +0x1C: extra
    newNode[0x11] = *reinterpret_cast<uint32_t*>(DAT_007028f4 + 0x560);  // +0x44: entity config
}
} // namespace Giants
