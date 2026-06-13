// Giants Engine - Water/Wave System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include <cstdlib>
#include <cstring>
#include "WaterSystem.h"
#include <cstring>

namespace Giants {

// ─── External data references ─────────────────────────────────

// Renderer device vtable pointers
static uint32_t DAT_00702700 = 0;              // D3D device
static uint32_t DAT_00702714 = 0;              // Shader constant interface
static uint32_t DAT_00702730 = 0;              // Vertex shader constant buffer
static uint32_t DAT_00702770 = 0;              // Render context / scene object

// Wave parameter tables (indexed by waveIndex)
static float    DAT_006628f8[2] = {0};         // Wave amplitude table
static float    DAT_006628d0[2] = {0};         // Wave frequency table
static float    DAT_006628d4[2] = {0};         // Wave speed table

// Wave position state (persistent across frames, per layer)
// Layout: [waveIndex*8 + base] gives the X or Y offset
static float    DAT_0074c508 = 0;              // Base wave offset
static float    DAT_0074c50c[2] = {0};         // Wave X position per layer
static float    DAT_0074c510[2] = {0};         // Wave Y position per layer

// Timing
extern float    g_timeMultiplier;              // DAT_00727e38 — frame time scale

// Wave scale constants
static float    DAT_0066bf2c = 0;              // Wave wrap period (e.g., 2*PI or tile size)
static float    DAT_0066c00c = 0;              // Frequency multiplier
static float    DAT_0066bfc8 = 0;              // Speed multiplier
static float    DAT_0066bff8 = 0;              // Wrap threshold

// Shader constant indices
// 0x20060 = shader reg index for wave 0; 0x20560 for wave 1
static const uint32_t SHADER_CONST_WAVE0 = 0x20060;
static const uint32_t SHADER_CONST_WAVE1 = 0x20560;

// ─── Wave transform buffer ────────────────────────────────────
// 6 rows x 4 floats = 24 floats = 96 bytes
// Written to GPU as vertex shader constants
// Ghidra addresses: DAT_00685958 through DAT_006859b4
static float    g_waveTransform[24] = {0};

// Sub-region of the above buffer for individual access
// (Ghidra decomposes these into individual DAT_ labels)
// DAT_00685958..DAT_006859b4 covers 6 rows of 4 floats each

// ─── Unknown helper functions ─────────────────────────────────
extern void BeginShaderBlock();                // FUN_00483160
extern void EndShaderBlock();                  // FUN_00483140

// Wave system context and state
static uint32_t DAT_007026cc = 0;              // Wave shader object handle
static float    DAT_00702684 = 0;              // Wave tile size X
static float    DAT_0070263c = 0;              // Wave tile frequency
static float    DAT_00702660 = 0;              // Wave tile frequency copy
static float    DAT_007026a8 = 0;              // Wave tile size copy
static uint32_t DAT_00701d58 = 0;              // Wave system initialized flag
static uint32_t DAT_00702b64 = 0;              // Water complexity level
static uint32_t DAT_00701de8 = 0;              // Render strip count
static uint32_t DAT_00701d7c = 0;              // Render LOD level
static uint32_t DAT_00701d34 = 0;              // Render function pointer
static uint32_t DAT_00701dc4[9] = {0};         // Device buffer slots
static uint32_t DAT_007026d8[9] = {0};         // Shader object slots
static void*    DAT_00747c74 = nullptr;        // Wave context to free

// Out-of-bounds helper
static uint32_t DAT_007488b8 = 0;              // Render context flag

// ─── UpdateWaves (FUN_004ddf10) — FAIL (usable ~80%) ───────────

void UpdateWaves(int waveIndex)
{
    // ── Step 1: Initialize sentinel values for wave transform ──
    // Mark rows 1, 3, 5 as unused (-1.0f in integer representation)
    g_waveTransform[4 + 3]  = -1.0f;  // DAT_00685964
    g_waveTransform[8 + 3]  = -1.0f;  // DAT_0068597c
    g_waveTransform[12 + 3] = -1.0f;  // DAT_00685994
    g_waveTransform[16 + 3] = -1.0f;  // DAT_006859ac

    // ── Step 2: Compute wave amplitude from table ──
    float amplitude = DAT_006628f8[waveIndex];                     // DAT_00685998

    // Row 1: wave X/Y direction scaled by amplitude
    g_waveTransform[4 + 0]  = DAT_0074c50c[waveIndex] * amplitude; // DAT_00685968
    g_waveTransform[4 + 1]  = DAT_0074c510[waveIndex] * amplitude; // DAT_0068596c

    // Row 3: wave X/Y direction + offset, scaled by amplitude
    g_waveTransform[12 + 1] = (DAT_0074c510[waveIndex] + DAT_0066bf2c) * amplitude; // DAT_00685984
    g_waveTransform[12 + 0] = (DAT_0074c50c[waveIndex] + DAT_0066bf2c) * amplitude; // DAT_00685998

    // Select shader constant register index based on wave layer
    uint32_t shaderReg = (waveIndex == 0) ? SHADER_CONST_WAVE0 : SHADER_CONST_WAVE1;

    // Copy row 1 → row 4 and row 3 → row 5 (mirroring for shader)
    g_waveTransform[16 + 0] = g_waveTransform[4 + 0];   // DAT_00685980 = DAT_00685968
    g_waveTransform[16 + 1] = g_waveTransform[12 + 1];  // DAT_0068599c = DAT_00685984
    g_waveTransform[20 + 0] = g_waveTransform[12 + 0];  // DAT_006859b0 = DAT_00685998
    g_waveTransform[20 + 1] = g_waveTransform[4 + 1];   // DAT_006859b4 = DAT_0068596c

    // ── Step 3: Upload wave transform to GPU ──
    // SetVertexShaderConstant(shaderReg, null, null) — via vtable on DAT_00702714
    if (DAT_00702714 != 0) {
        uint32_t** iface = (uint32_t**)DAT_00702714;
        typedef void(__thiscall* SetConstFn)(uint32_t, uint32_t, uint32_t, uint32_t);
        SetConstFn fn = (SetConstFn)(*iface)[1];  // vtable[4] / offset 0x4
        fn(DAT_00702714, shaderReg, 0, 0);
    }

    // Allocate 4 shader constant registers (24 floats = 6 vec4)
    // via vtable[2] on DAT_00702730
    float* constants = nullptr;
    if (DAT_00702730 != 0) {
        uint32_t** buf = (uint32_t**)DAT_00702730;
        typedef float*(__thiscall* AllocFn)(uint32_t, uint32_t);
        AllocFn fn = (AllocFn)(*buf)[2];
        constants = fn(DAT_00702730, 4);
    }

    if (constants != nullptr) {
        // Copy all 24 floats (6 rows x 4 columns) to the shader constant buffer
        memcpy(constants, g_waveTransform, sizeof(g_waveTransform));
    }

    // Begin shader effect "Waves"
    if (DAT_00702700 != 0) {
        uint32_t** device = (uint32_t**)DAT_00702700;
        // vtable[0xe8/4 = 58] — likely ID3DXEffect::Begin or SetTechnique
        typedef int(__thiscall* BeginEffectFn)(uint32_t, const char*);
        BeginEffectFn fn = (BeginEffectFn)(*device)[0xe8 / 4];
        fn((uint32_t)device, "Waves");
    }

    // ── Step 4: Set shader frame constants with color/direction data ──
    // Extract RGBA components from packed color at DAT_00702770 + 0x5164 + waveIndex*4
    uint32_t packedColor = 0;
    if (DAT_00702770 != 0) {
        packedColor = *(uint32_t*)(DAT_00702770 + 0x5164 + waveIndex * 4);
    }

    // Decompose into normalized [0,1] floats
    float r = (float)((packedColor & 0xFF) + 0.0f) / 256.0f;         // DAT_0066c12c ≈ 256
    float g = (float)(((packedColor >> 8) & 0xFF) + 0.0f) / 256.0f;
    float b = (float)(((packedColor >> 16) & 0xFF) + 0.0f) / 256.0f;
    float a = (float)((packedColor >> 24) + 0.0f) / 256.0f;

    // Note: The original code has a conditional block comparing deltas
    // against DAT_0066bcf4 with XOR masking — this appears to be a
    // dirty-flag check for the frame constants. When any channel
    // changes significantly, it marks the constant as dirty and
    // uploads to the shader.

    // ── Step 5: End shader effect ──
    // vtable[0xc] on DAT_00702730 — CommitShaderConstants("Waves")
    if (DAT_00702730 != 0) {
        uint32_t** buf = (uint32_t**)DAT_00702730;
        typedef void(__thiscall* CommitFn)(uint32_t, const char*);
        CommitFn fn = (CommitFn)(*buf)[3];  // vtable offset 0xc
        fn(DAT_00702730, "Waves");
    }

    // vtable[0x10] — DrawPrimitive or similar
    // Uses render context offset 0x515c

    // ── Step 6: Animate wave positions ──
    BeginShaderBlock();                          // FUN_00483160

    // Compute wave phase from frequency and time
    float phase = DAT_006628d0[waveIndex] * DAT_0066c00c * DAT_0066bfc8
                  + DAT_0074c508;

    // Wrap phase into [0, DAT_0066bff8)
    while (DAT_0066bff8 < phase) {
        phase = phase - DAT_0066bff8;
    }

    // Advance wave X position
    float newPosX = phase * DAT_006628d4[waveIndex] * g_timeMultiplier
                    * *(float*)(DAT_00702770 + 0x518c)
                    + DAT_0074c50c[waveIndex];
    DAT_0074c50c[waveIndex] = newPosX;

    EndShaderBlock();                            // FUN_00483140

    // Advance wave Y position
    float newPosY = phase * DAT_006628d4[waveIndex] * g_timeMultiplier
                    * *(float*)(DAT_00702770 + 0x518c)
                    + DAT_0074c510[waveIndex];
    DAT_0074c510[waveIndex] = newPosY;

    // Wrap X position into [0, DAT_0066bf2c)
    if (DAT_0066bf2c < newPosX) {
        do {
            newPosX = newPosX - DAT_0066bf2c;
        } while (DAT_0066bf2c < newPosX);
        DAT_0074c50c[waveIndex] = newPosX;
    }

    // Wrap Y position into [0, DAT_0066bf2c)
    if (DAT_0066bf2c < newPosY) {
        do {
            newPosY = newPosY - DAT_0066bf2c;
        } while (DAT_0066bf2c < newPosY);
        DAT_0074c510[waveIndex] = newPosY;
    }
}

// ─── InitializeWaveSystem (FUN_004dfe20) — PASS (usable ~80%) ───

void InitializeWaveSystem(void* param_1)
{
    // Step 1: Compute wave tiling parameters from scene data
    // DAT_00702770 + 0x4f5c = water scale factor
    float waterScale = *(float*)(DAT_00702770 + 0x4f5c);
    DAT_00702684 = DAT_0066bf2c / waterScale;

    // Step 2: Select wave frequency based on water type
    float frequency;
    if (*(int*)(DAT_00702770 + 0x4fb0) == 0) {
        if (*(int*)(DAT_00702770 + 0x5010) == 0) {
            goto skip_frequency;
        }
        frequency = *(float*)(DAT_00702770 + 0x501c);  // Secondary water frequency
    } else {
        frequency = *(float*)(DAT_00702770 + 0x4fbc);  // Primary water frequency
    }
    DAT_0070263c = DAT_0066bf2c / frequency;
    DAT_00702660 = DAT_0070263c;

skip_frequency:
    DAT_007026a8 = DAT_00702684;

    // Step 3: Allocate new wave context via FUN_004e2180
    // uint32_t* newContext = FUN_004e2180();
    // uint32_t contextValue = *newContext;
    // *newContext = 0;

    // Free previous wave context (DAT_00747c74)
    void* prevContext = DAT_00747c74;
    bool hadPrev = (prevContext != nullptr);
    // DAT_00747c74 = contextValue;
    if (hadPrev) {
        // operator delete(prevContext, 0x270, 0x10)
    }

    // Free caller-provided context
    if (param_1 != nullptr) {
        // operator delete(param_1, 0x270, 0x10)
    }

    // Step 4: Mark wave system initialized
    DAT_00701d58 = 1;

    // Step 5: Configure render dispatch based on water complexity
    if (DAT_00702b64 < 1 ||
        (*(int*)(DAT_00702770 + 0x4fb0) == 0 && *(int*)(DAT_00702770 + 0x5010) == 0))
    {
        // Simple water: 28 strips, LOD 10
        DAT_00701de8 = 0x1c;
        DAT_00701d7c = 10;
        DAT_00701d34 = 0x004de5e0;  // LAB_004de5e0 — simple render path
    } else {
        // Complex water: 32 strips, LOD 11
        DAT_00701de8 = 0x20;
        DAT_00701d7c = 0x0b;
        DAT_00701d34 = 0x004de630;  // LAB_004de630 — complex render path
    }

    // Step 6: Create shader objects via renderer vtable
    // DAT_00701d10 = FUN_004de7d0;  // Render function pointer

    // vtable[2] on DAT_00702700 — create shader/resource
    // DAT_007026cc = vtable[2]();

    // vtable[0x18] — set shader parameters from scene data
    // vtable[0x18](offsets 0x4ec0, 0x4ec4, 0x4ec8 from render context)
}

// ─── ShutdownWaveSystem (FUN_004dff90) — PASS (usable ~85%) ──────

void ShutdownWaveSystem()
{
    // Step 1: Release wave shader object
    if (DAT_007026cc != 0) {
        // Call via vtable with security cookie
        // (*DAT_007026cc)(DAT_007026cc, securityCookie);
        DAT_007026cc = 0;
    }

    // Step 2: Release 9 device/shader slots
    int i = 0;
    do {
        // Release shader via vtable[0x14] on DAT_00702700
        if (DAT_007026d8[i] != 0) {
            // vtable[0x14](DAT_007026d8[i])  — Release shader
            DAT_007026d8[i] = 0;
        }

        // Free device buffer with scalar deleting destructor
        if (DAT_00701dc4[i] != 0) {
            // FUN_006438f8(DAT_00701dc4[i], 0xc, *(int*)(DAT_00701dc4[i] - 4), FUN_0042b1f0);
            // FUN_00643c84(DAT_00701dc4[i] - 4, size);
            DAT_00701dc4[i] = 0;
        }
        i++;
    } while (i < 9);  // 0x24 / 4 = 9 iterations

    // Step 3: Release water textures (3 layers x 3 categories)
    if (DAT_00702770 != 0) {
        int layer = 0;
        int ctx = DAT_00702770;

        do {
            // Category 1: Water surface textures (0x4fb0 + layer*4)
            int surfTex = *(int*)(ctx + 0x4fb0 + layer * 4);
            if (surfTex != 0) {
                // vtable[0xc8](surfTex) — release texture
                // Free pixel data if owned (check offset +0x20 bit 0)
                int surfObj = *(int*)(DAT_00702770 + 0x4fb0 + layer * 4);
                if (*(void**)(surfObj + 4) != nullptr &&
                    (~*(uint32_t*)(surfObj + 0x20) & 1) == 0) {
                    free(*(void**)(surfObj + 4));
                    *(uint32_t*)(surfObj + 4) = 0;
                    *(uint32_t*)(surfObj + 0x20) &= 0xfffffffe;
                }
            }

            // Category 2: Foam/detail textures (0x5010 + layer*4)
            int foamTex = *(int*)(ctx + 0x5010 + layer * 4);
            if (foamTex != 0) {
                // vtable[0xc8](foamTex) — release texture
                int foamObj = *(int*)(DAT_00702770 + 0x5010 + layer * 4);
                if (*(void**)(foamObj + 4) != nullptr &&
                    (~*(uint32_t*)(foamObj + 0x20) & 1) == 0) {
                    free(*(void**)(foamObj + 4));
                    *(uint32_t*)(foamObj + 4) = 0;
                    *(uint32_t*)(foamObj + 0x20) &= 0xfffffffe;
                }
            }

            // Category 3: Reflection textures (0x4f50 + layer*4)
            int reflTex = *(int*)(ctx + 0x4f50 + layer * 4);
            if (reflTex != 0) {
                // vtable[0xc8](reflTex) — release texture
                int reflObj = *(int*)(DAT_00702770 + 0x4f50 + layer * 4);
                if (*(void**)(reflObj + 4) != nullptr &&
                    (~*(uint32_t*)(reflObj + 0x20) & 1) == 0) {
                    free(*(void**)(reflObj + 4));
                    *(uint32_t*)(reflObj + 4) = 0;
                    *(uint32_t*)(reflObj + 0x20) &= 0xfffffffe;
                }
            }

            layer++;
        } while (layer < 3);
    }

    // Step 4: Free wave context
    void* waveCtx = DAT_00747c74;
    DAT_00747c74 = nullptr;
    if (waveCtx != nullptr) {
        // operator delete(waveCtx, 0x270, 0x10)
    }
}

// ─── ComputeWaveVertex (FUN_004e07f0) — PASS ─────────────────────

bool ComputeWaveVertex(float* param_1, float param_2, float param_3,
                       float* param_4, int param_5)
{
    // Write input position
    param_1[0] = param_2;      // X
    param_1[1] = param_3;      // Z

    // Read height
    float height = *param_4;

    // Optional render context callback
    if (DAT_007488b8 != 0) {
        // FUN_005f9b00() — render state update before vertex output
    }

    param_1[2] = height;       // Y

    // Apply transform matrix from param_5 to compute world-space XZ
    // Matrix layout at param_5:
    //   +0x3c..0x48 = row 0 (m00, m01, m02) + translation tx
    //   +0x4c..0x58 = row 1 (m10, m11, m12) + translation tz
    float worldX = param_2 * *(float*)(param_5 + 0x4c) +
                   param_3 * *(float*)(param_5 + 0x50) +
                   *(float*)(param_5 + 0x58);
    float worldZ = param_2 * *(float*)(param_5 + 0x3c) +
                   param_3 * *(float*)(param_5 + 0x40) +
                   *(float*)(param_5 + 0x48);

    param_1[3] = 0.0f;        // Homogeneous coordinate
    param_1[4] = worldX;      // Transformed X
    param_1[5] = worldZ;      // Transformed Z

    // Return true if vertex is outside wave tile bounds (needs clipping)
    return (worldX < 0.0f) || (worldZ < 0.0f) ||
           (DAT_0066bf2c < worldZ) || (DAT_0066bf2c < worldX);
}

} // namespace Giants
