// Giants Engine - Open Dialog (dialog stack management)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── OpenDialog (FUN_00549b60) ── PASS ──
// Opens a dialog screen: pushes update/render callbacks onto a 10-level
// stack, creates dialog entity, sets screen dimensions, dispatches
// render path based on dialog flags.
// 15 callers, ~8 callees.
void OpenDialog();  // FUN_00549b60

} // namespace Giants
