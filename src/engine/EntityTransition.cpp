// Giants Engine - Entity State Transition Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityTransition.h"
#include "EntitySystem.h"

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
// Type handler vtable: 108 entries (stride 0x50 = 80 bytes each)
// Defined in EntitySystem.cpp
extern uint32_t g_entityVtable_Destructor[108];  // DAT_00682ec8

extern void CRTFree(void* ptr);                  // FUN_00643505
extern void* EntityFactoryCreate(uint32_t type); // FUN_005d6d00
extern void EntityCreateAndRegister(int entityDef); // FUN_0055cda0

// ═══════════════════════════════════════════════════════════════════
// EntityStateTransitionFn (FUN_0055ccc0) — 43 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Transitions an entity from its current state to a new state.
//
// Entity offsets:
//   +0x14c  resource handle (animation/mesh instance)
//   +0x22c  current state type index (< 0x6c = 108)
//
// Steps:
//   1. If current type index is valid, look up exit handler from
//      DAT_00682ec8 vtable (stride 0x50) and call it
//   2. Free old resource handle via CRTFree
//   3. Set new state type index
//   4. Allocate new resource via EntityFactoryCreate
//   5. Call EntityCreateAndRegister for post-init

void EntityStateTransitionFn(int param_1, unsigned int param_2)
{
    // Step 1: Call type-specific exit handler if present
    if ((*(int*)(param_1 + 0x22c) < 0x6c) &&
        (*reinterpret_cast<void***>(&g_entityVtable_Destructor[0] +
            *(int*)(param_1 + 0x22c) * (0x50 / sizeof(uint32_t))) != nullptr) &&
        (*(int*)(param_1 + 0x14c) != 0))
    {
        auto handler = *reinterpret_cast<void(**)(int)>(
            &g_entityVtable_Destructor[0] + *(int*)(param_1 + 0x22c) * (0x50 / sizeof(uint32_t)));
        handler(param_1);
    }

    // Step 2: Free old resource handle
    if (*(int*)(param_1 + 0x14c) != 0) {
        CRTFree(reinterpret_cast<void*>(*(int*)(param_1 + 0x14c)));
        *(unsigned int*)(param_1 + 0x14c) = 0;
    }

    // Step 3: Update state type index
    *(unsigned int*)(param_1 + 0x22c) = param_2;

    // Step 4: Allocate new resource for new state
    unsigned int newHandle = reinterpret_cast<unsigned int>(EntityFactoryCreate(param_2));
    *(unsigned int*)(param_1 + 0x14c) = newHandle;

    // Step 5: Post-transition registration
    EntityCreateAndRegister(param_2);
}

} // namespace Giants
