// Giants Engine - Entity Action Dispatch
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── EntityActionDispatch (FUN_004a6860) ── PASS ──
// Dispatches an action on an entity by index. Validates entity+slot,
// calls vtable function or fallback with error data. 14 callers, 1 callee.
void EntityActionDispatch(int entity, int index, uint32_t* fallback);  // FUN_004a6860

// ─── EntityActionValidate (FUN_0051b170) ── PASS ──
// Validates entity state for action dispatch. Checks entity type 0x2E9,
// animation range, and linked entity state. 1 callee, 5 callers.
uint32_t EntityActionValidate(int param_1, uint64_t* param_2);  // FUN_0051b170
} // namespace Giants
