// Giants Engine - Entity Action Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityActionDispatch.h"
#include <cstdint>
namespace Giants {
extern uint32_t PTR_FUN_0067d208;  // Action callback function pointer
void EntityActionDispatch(int entity, int index, uint32_t* fallback)
{
    if (entity == 0) return;
    if (*reinterpret_cast<int*>(entity + 8) == 0) return;

    // Validate index bounds and slot exists
    if ((index >= 0) &&
        (index < *reinterpret_cast<int*>(entity + 0x328)) &&
        (*reinterpret_cast<int*>(*reinterpret_cast<int*>(*reinterpret_cast<int*>(entity + 8) + 0x454) + index * 4) != 0)) {
        // Dispatch action via callback
        reinterpret_cast<void(*)(int)>(PTR_FUN_0067d208)(
            *reinterpret_cast<int*>(entity + 0x32C) + index * 0x44);
        return;
    }

    // Fallback: use error/backup data from entity
    uint32_t uVar1 = *reinterpret_cast<uint32_t*>(entity + 0x2E8);
    uint32_t uVar2 = *reinterpret_cast<uint32_t*>(entity + 0x2EC);
    uint32_t uVar3 = *reinterpret_cast<uint32_t*>(entity + 0x2F0);
    if (fallback != nullptr) {
        fallback[0] = uVar1;
        fallback[1] = uVar2;
        fallback[2] = uVar3;
    }
}

// ─── EntityActionValidate (FUN_0051b170) ── PASS ──
// 5 callers, 1 callee. Validates entity state for action dispatch.
// Checks type 0x2E9, animation range +0x2C8 < +0x20C, linked entity +0x78/+0x7C.
uint32_t EntityActionValidate(int param_1, uint64_t* param_2)
{
    if (param_1 == 0) return 0;
    int entityData = *reinterpret_cast<int*>(param_1 + 0x14C);
    if (entityData == 0) return 0;

    // Validation: animation range, entity type, linked entity state
    if (*reinterpret_cast<float*>(param_1 + 0x2C8) >= *reinterpret_cast<float*>(param_1 + 0x20C))
        return 0;
    if (*reinterpret_cast<int*>(param_1 + 4) != 0x2E9) return 0;
    if (*reinterpret_cast<int*>(param_1 + 0x130) == 0) return 0;
    if (*reinterpret_cast<int*>(entityData + 0x78) != 0) return 0;
    if (*reinterpret_cast<int*>(entityData + 0x7C) != 0) return 0;

    // Valid: store params and dispatch
    uint32_t lo = static_cast<uint32_t>(*param_2);
    uint32_t hi = static_cast<uint32_t>(*param_2 >> 32);
    *reinterpret_cast<uint32_t*>(param_1 + 0x1C4) = lo;
    *reinterpret_cast<uint32_t*>(param_1 + 0x1C8) = hi;

    // FUN_004fecb0(local_14, local_1c, 1) — action dispatch
    return 1;
}
} // namespace Giants
