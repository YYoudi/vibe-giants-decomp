// Giants Engine - Entity Slot State Check Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntitySlotState.h"
#include <cstdint>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static float DAT_0066c09c = 50.0f;  // faithful @0x0066C09C  // Reference scale value

// ─── External callees ──────────────────────────────────────────
extern void FUN_00497350();  // Scale comparison helper A
extern void FUN_00580930();  // Scale comparison helper B

// ═══════════════════════════════════════════════════════════════════
// CheckEntitySlotState (FUN_004a6650) — 19 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Checks if entity at given slot is in terminal/done state.
// Navigates: container+0x14c → entity table → slot * 0x1c → entity.
// Entity type at +0x22c determines comparison:
//   0x20: compare scale at entity+0x14c+0x594 vs 0x4a/0x52 path
//   0x4a: use FUN_00497350 for scale comparison
//   0x52: use FUN_00580930 for scale comparison
//   0x53: use FUN_00580930 with DAT_0066c09c as reference
// Returns true if current scale == reference scale.

bool CheckEntitySlotState(int container, int slotIndex)
{
    // Get entity table base
    int entityTable = 0;
    if (container != 0) {
        entityTable = *reinterpret_cast<int*>(container + 0x14c);
    }

    // Get entity at slot
    int entity = *reinterpret_cast<int*>(entityTable + 0x20 + slotIndex * 0x1c);
    if (entity == 0) {
        return false;
    }

    int entityType = *reinterpret_cast<int*>(entity + 0x22c);
    float scale, refScale, curScale;

    if (entityType == 0x20) {
        scale = *reinterpret_cast<float*>(*reinterpret_cast<int*>(entity + 0x14c) + 0x594);
        // Type 0x20: direct comparison path (scale vs scale)
        refScale = scale;
        FUN_00497350();
        curScale = scale;
        scale = refScale;
    } else if (entityType == 0x4a) {
        scale = **reinterpret_cast<float**>(entity + 0x14c);
        refScale = scale;
        FUN_00497350();
        curScale = scale;
        scale = refScale;
    } else if (entityType == 0x52) {
        scale = **reinterpret_cast<float**>(entity + 0x14c);
        refScale = scale;
        FUN_00580930();
        curScale = scale;
        scale = refScale;
    } else if (entityType == 0x53) {
        scale = **reinterpret_cast<float**>(entity + 0x14c);
        curScale = scale;
        FUN_00580930();
        refScale = scale;
        scale = curScale;
        if (entity == 0) {
            refScale = DAT_0066c09c;
            curScale = scale;
        }
    } else {
        scale = **reinterpret_cast<float**>(entity + 0x14c);
        refScale = DAT_0066c09c;
        curScale = scale;
    }

    return scale == refScale;
}

} // namespace Giants
