// Giants Engine - Entity Update Loop Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityUpdateLoop.h"
#include <cstdint>
namespace Giants {
extern int DAT_007027dc;  // Entity linked list head
extern int FUN_00559dc0();  // Get scene context
extern void FUN_004ac930(); // Entity pre-update
extern void FUN_00580230(); // Update entity (generic)
extern void FUN_00496c30(); // Update entity (smart object type 0x20)
extern void FUN_004a5080(int ctx, int val);  // Post-update
extern void FUN_00493810(int entity);  // Process entity type 0x4A

void EntityUpdateLoop(int param_1, int param_2, int param_3)
{
    int ctx = FUN_00559dc0();
    *reinterpret_cast<int*>(ctx + 0x2C4) = param_1;

    FUN_004ac930();

    // Update entities in range
    for (int i = param_2; i <= param_3; i++) {
        if ((param_1 == 0) || (*reinterpret_cast<int*>(param_1 + 0x22C) != 0x20)) {
            FUN_00580230();
        } else {
            FUN_00496c30();
        }
        FUN_004a5080(ctx, 0);
    }

    // Set update flag
    *reinterpret_cast<uint32_t*>(ctx + 0x124) |= 0x8000;

    FUN_004ac930();

    // Walk linked list, process type 0x4A entities matching param_1
    int* node = reinterpret_cast<int*>(DAT_007027dc);
    if (node != nullptr) {
        do {
            int entity = node[3];  // +0xC = entity pointer
            if (entity != 0 &&
                *reinterpret_cast<int*>(entity + 0x22C) == 0x4A &&
                *reinterpret_cast<int*>(entity + 0x2C4) == param_1) {
                FUN_00493810(entity);
            }
            node = reinterpret_cast<int*>(*node);
        } while (node != nullptr);

        // Second pass (restart from head)
        int* node2 = reinterpret_cast<int*>(DAT_007027dc);
        while (node2 != nullptr) {
            int entity = node2[3];
            if (entity != 0 &&
                *reinterpret_cast<int*>(entity + 0x22C) == 0x4A &&
                *reinterpret_cast<int*>(entity + 0x2C4) == param_1) {
                FUN_00493810(entity);
            }
            node2 = reinterpret_cast<int*>(*node2);
        }
    }
}
} // namespace Giants
