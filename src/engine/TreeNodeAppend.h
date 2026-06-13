// Giants Engine - Tree Node String Append
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AppendStringToNode (FUN_004d5150) ── PASS ──
// Finds a node in a linked tree by ID (param_2), walks to tail of
// child list at node[10], allocates new child with string data.
// Sets node[3] |= 0x200 on success.
// 22 callers, 1 callee (malloc).
void AppendStringToNode(int* rootNode, int nodeId, char* str, uint32_t param4);  // FUN_004d5150

} // namespace Giants
