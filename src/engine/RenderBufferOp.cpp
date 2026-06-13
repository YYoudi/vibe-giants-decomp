// Giants Engine - Render Buffer Operation Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderBufferOp.h"

namespace Giants {

extern void BufferStageCommit(int param);    // FUN_004f7570
extern void ReleaseTempBuffer(int param);    // FUN_0044dc30

// ═══════════════════════════════════════════════════════════════════
// RenderBufferOperation (FUN_004f7050) — 28 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Saves member[0x20] value, commits buffer stage, then releases
// the temporary buffer using the saved value.

void RenderBufferOperation(int param_1)
{
    int savedValue = *reinterpret_cast<int*>(param_1 + 0x20);
    BufferStageCommit(param_1);
    ReleaseTempBuffer(savedValue);
}

} // namespace Giants
