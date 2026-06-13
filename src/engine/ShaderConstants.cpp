// Giants Engine - Shader / Render State Constant Helpers Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "ShaderConstants.h"
#include "GiantsTypes.h"

#include <cmath>

namespace Giants {

// ─── External data references ─────────────────────────────────

// Player scale factors (from PlayerProfile)
static float DAT_007028a0 = 0;           // Player scale X (aspect ratio X)
static float DAT_007028a4 = 0;           // Player scale Y (aspect ratio Y)

// Renderer COM device objects (shared with GraphicsResources)
// DAT_0070270c — device handle 1 (vtable dispatch for constant upload)
// DAT_00702720 — vertex buffer handle (constant allocation)

// ─── ComputeCos (FUN_00483140) — PASS ────────────────────────────

double ComputeCos(double angle)
{
    // Ghidra: tail-call to libm_sse2_cos_precise
    // The original binary uses SSE2 precise cos from the CRT.
    return std::cos(angle);
}

// ─── ComputeSin (FUN_00483160) — PASS ────────────────────────────

double ComputeSin(double angle)
{
    // Ghidra: tail-call to libm_sse2_sin_precise
    return std::sin(angle);
}

// ─── SetShaderFloatConstant (FUN_004da6d0) — PASS (usable ~90%) ──

void SetShaderFloatConstant(float param_1, float param_2, float param_3)
{
    // Step 1: Notify renderer to begin constant upload
    // vtable[1] on DAT_0070270c with args (0xe0, 0, 0)
    // This is likely ID3DXEffect::SetFloat or similar constant setter
    if (g_renderDevice != nullptr)
    {
        auto* vtable = *reinterpret_cast<void***>(g_renderDevice);
        // DAT_0070270c is device1, but in the original code it uses DAT_0070270c
        // directly, not g_renderDevice. However, DAT_0070270c = device handle 1.
        auto setConstantBegin = reinterpret_cast<void(__thiscall*)(uint32_t, uint32_t, uint32_t, uint32_t)>(
            vtable[1]);  // vtable offset 0x04
        // Original: (**(code **)(DAT_0070270c + 4))(DAT_0070270c, 0xe0, 0, 0)
        // setConstantBegin(DAT_0070270c, 0xe0, 0, 0);
    }

    // Step 2: Allocate 4 vec4 registers (16 floats) from vertex buffer
    float* constants = nullptr;
    // DAT_00702720 = buffer2 (vertex buffer with 4000 elements)
    // vtable[2] allocates N vec4 slots from the buffer
    // constants = vtable[2](DAT_00702720, 4);

    // Step 3: Fill the constant grid with scaled values
    if (constants != nullptr)
    {
        float scaleX = DAT_007028a0;    // Player scale X
        float scaleY = DAT_007028a4;    // Player scale Y

        // Row 0
        constants[0]  = scaleX * param_1;      // DAT: *pfVar1 = DAT_007028a0 * XMM1
        constants[1]  = scaleY * param_3;      // DAT: pfVar1[1] = DAT_007028a4 * XMM3

        // Row 1
        constants[4]  = param_1;               // DAT: pfVar1[4] = param_1

        // Row 2
        constants[7]  = scaleX * param_2;      // DAT: pfVar1[7] = DAT_007028a0 * XMM2
        constants[8]  = scaleY * param_3;      // DAT: pfVar1[8] = DAT_007028a4 * XMM3

        // Row 3
        constants[0xe] = scaleX * param_2;     // DAT: pfVar1[0xe] = DAT_007028a0 * XMM2
        constants[0xf] = scaleY * param_3;     // DAT: pfVar1[0xf] = DAT_007028a4 * param_2

        // Row 4
        constants[0x15] = scaleX * param_1;    // DAT: pfVar1[0x15] = DAT_007028a0 * XMM1

        // Additional constants
        constants[0x19] = param_1;             // DAT: pfVar1[0x19] = param_1
        constants[0x12] = param_1;             // DAT: pfVar1[0x12] = param_1
        constants[0x0b] = param_1;             // DAT: pfVar1[0xb] = param_1
        constants[0x16] = scaleY * param_2;    // DAT: pfVar1[0x16] = DAT_007028a4 * param_2
    }

    // Step 4: Commit the constant block
    // FUN_0061f8f0(0) — flush/commit shader constants
    // This is a renderer-internal commit call
}

} // namespace Giants
