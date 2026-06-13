// Giants Engine - UI Node Find By Tag
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── UINodeFindByTag (FUN_00491060) ── PASS ──
// Searches UI node array for matching wide-string tag. Compares byte-by-byte.
// Returns node data pointer and writes index to param_3. 6 callers, 0 callees.
int UINodeFindByTag(int param_1, uint8_t* tagName, int* outIndex);  // FUN_00491060
} // namespace Giants
