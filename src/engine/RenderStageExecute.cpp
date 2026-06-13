// Giants Engine - Render Stage Execute Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderStageExecute.h"
#include <cstdint>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern uint32_t DAT_0067d280;  // Security cookie — defined in CRTStubs.cpp

// ─── Forward declarations for callees ──────────────────────────
extern void FUN_004f7570(uint32_t device, uint32_t param_2, uint32_t param_3, uint32_t cookie);
extern void FUN_0044dc30(void* dst, void* src);  // String/collection copy

// ═══════════════════════════════════════════════════════════════════
// ExecuteRenderStage (FUN_004f7050) — 28 callers — FAIL (usable ~85%)
// ═══════════════════════════════════════════════════════════════════
// Render stage execution wrapper.
// param_1: render context (this ptr, has device at [0], state at [2])
// param_2: stage parameter 1
// param_3: stage parameter 2
// Preserves param_1[2] across the render call, then invokes string op.

void ExecuteRenderStage(uint32_t* param_1, uint32_t param_2, uint32_t param_3)
{
    // Save state from param_1[2]
    uint32_t savedState = param_1[2];

    // Execute render operation
    FUN_004f7570(param_1[0], param_2, param_3, DAT_0067d280 ^ reinterpret_cast<uint32_t>(&savedState));

    // String/collection operation (constructs local string from stack)
    uint8_t localBuffer[504];  // 0x1f8 bytes local
    FUN_0044dc30(localBuffer, localBuffer);

    // Restore state
    param_1[2] = savedState;
}

} // namespace Giants
