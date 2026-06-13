// Giants Engine - Dialog Stack Pop
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── PopDialogStack (FUN_004d0fd0) ── PASS ──
// Pops a dialog from the dialog level stack. Validates underflow and
// pop mismatch. Clears stack entry at DAT_00747b74. 10 callers, 2 callees.
void PopDialogStack(int dialogPtr);  // FUN_004d0fd0
} // namespace Giants
