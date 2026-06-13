// Giants Engine - Count Scene Nodes
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── CountSceneNodes (FUN_004d6ee0) ── PASS ──
// Counts nodes in scene graph starting at param_1+8+0x400.
// Iterates children, accumulates count. 10 callers, 0 callees.
int CountSceneNodes(int param_1);  // FUN_004d6ee0
} // namespace Giants
