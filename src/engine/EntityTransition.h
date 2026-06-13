// Giants Engine - Entity State Transition
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── EntityStateTransition (FUN_0055ccc0) ── PASS ──
// Transitions entity to a new state/type. Calls the exit handler from
// the type vtable at DAT_00682ec8, frees old resource, allocates new.
// 43 callers, 3 callees.
void EntityStateTransitionFn(int param_1, unsigned int param_2);  // FUN_0055ccc0

} // namespace Giants
