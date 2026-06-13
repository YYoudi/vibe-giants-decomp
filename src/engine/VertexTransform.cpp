// Giants Engine - Vertex Transform Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VertexTransform.h"
#include <cstring>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static float g_ScaleFactor = 0.5f;  // faithful @0x0066BE20
static float g_InvThreshold = 1.0f;  // faithful @0x0066BF2C
extern uint32_t  g_depthXorKey;                          // DAT_0066c580
static float g_Divisor1 = 480.0f;  // faithful @0x0066C15C
static float g_Divisor2 = 640.0f;  // faithful @0x0066C174
static float g_Multiplier1 = 0.0f;  // state (BSS @0x007028A0, engine-populated)
static float g_Multiplier2 = 0.0f;  // state (BSS @0x007028A4, engine-populated)

extern void GetTransformCos();   // FUN_00483160
extern void GetTransformSin();   // FUN_00483140

// ═══════════════════════════════════════════════════════════════════
// TransformVertices (FUN_005d79a0) — 30 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Transforms mesh vertices based on scaling and mode flags.
// param_1: source object (mesh data + config)
// param_2: destination item (vertex positions + flags)
// param_3: unused
// param_4: vertical scale factor
// param_5: horizontal offset
// param_6: vertical offset

void TransformVertices(int param_1, int param_2, uint32_t /*param_3*/,
                       float param_4, float param_5, float param_6)
{
    float local_20 = 0.0f;
    float local_1c = param_6;

    // Phase 1: Scaling and depth offset computation
    if (*reinterpret_cast<int*>(param_1 + 0x34) != 0) {
        float fVar7 = *reinterpret_cast<float*>(param_1 + 0x2c);
        if (fVar7 < g_InvThreshold) {
            if ((*reinterpret_cast<uint8_t*>(param_2 + 0x18) & 0x20) == 0) {
                local_1c = param_6 * fVar7;
                if (*reinterpret_cast<int*>(param_1 + 0x38) != 0) {
                    if (*reinterpret_cast<int*>(param_2 + 0x1c) == 1) {
                        // Mode 1: XOR depth key
                        local_20 = static_cast<float>(
                            *reinterpret_cast<uint32_t*>(param_1 + 0x30) ^ g_depthXorKey);
                    } else if (*reinterpret_cast<int*>(param_2 + 0x1c) == 2) {
                        // Mode 2: direct float
                        local_20 = *reinterpret_cast<float*>(param_1 + 0x30);
                    }
                    local_20 = local_20 * g_ScaleFactor;
                }
            } else {
                param_4 = param_4 / fVar7;
            }
        }
    }

    // Phase 2: Vertex position computation
    if ((*reinterpret_cast<uint32_t*>(param_2 + 0x18) & 1) == 0) {
        // ── Simple transform mode ──
        if ((*reinterpret_cast<uint32_t*>(param_2 + 0x18) & 4) != 0) {
            float fVar7 = g_Multiplier1 / g_Divisor2;
            *reinterpret_cast<float*>(param_2 + 0x38) =
                local_1c * *reinterpret_cast<float*>(param_2 + 0x20) * fVar7 + param_5 + local_20;
            *reinterpret_cast<float*>(param_2 + 0x3c) =
                (param_4 * *reinterpret_cast<float*>(param_2 + 0x24) * g_Multiplier2) / g_Divisor1 + param_6;
            *reinterpret_cast<float*>(param_2 + 0x44) =
                local_1c * *reinterpret_cast<float*>(param_2 + 0x2c) * fVar7 + param_5 + local_20;
            *reinterpret_cast<float*>(param_2 + 0x48) =
                (param_4 * *reinterpret_cast<float*>(param_2 + 0x30) * g_Multiplier2) / g_Divisor1 + param_6;
        }
    } else {
        // ── Indexed vertex transform mode ──
        int iVar5 = *reinterpret_cast<int*>(param_2 + 0x50) * 4;
        int iVar4 = *reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 8) + iVar5);
        int iVar1 = *reinterpret_cast<int*>(iVar4 + 0x94 +
                     *reinterpret_cast<int*>(param_2 + 0x14) * 0x90);
        iVar4 = *reinterpret_cast<int*>(iVar4 + 0x98 +
                *reinterpret_cast<int*>(param_2 + 0x14) * 0x90);
        iVar5 = reinterpret_cast<int*>(*reinterpret_cast<int*>(param_1 + 0xc))[iVar5 / 4];
        float fVar7 = *reinterpret_cast<float*>(param_2 + 0x58);
        bool hasRotation = fVar7 != 0.0f;

        // Write corner positions
        *reinterpret_cast<float*>(param_2 + 0x38) =
            local_1c * *reinterpret_cast<float*>(param_2 + 0x20) + param_5 + local_20;
        *reinterpret_cast<float*>(param_2 + 0x3c) =
            param_4 * *reinterpret_cast<float*>(param_2 + 0x24) + param_6;
        *reinterpret_cast<float*>(param_2 + 0x44) =
            local_1c * *reinterpret_cast<float*>(param_2 + 0x2c) + param_5 + local_20;
        *reinterpret_cast<float*>(param_2 + 0x48) =
            param_4 * *reinterpret_cast<float*>(param_2 + 0x30) + param_6;

        float local_18 = 0.0f;
        float fVar6 = 0.0f;

        if (hasRotation) {
            GetTransformCos();
            local_18 = *reinterpret_cast<float*>(param_2 + 0x58);
            GetTransformSin();
            fVar6 = fVar7;
        }

        if (iVar4 != 0) {
            if (!hasRotation) {
                // No rotation: simple offset
                float* pfVar3 = reinterpret_cast<float*>(iVar1 * 0x38 + 4 + iVar5);
                do {
                    pfVar3[5] = local_1c * pfVar3[-1] + local_20 + param_5;
                    pfVar3[6] = param_4 * *pfVar3 + param_6;
                    pfVar3 = pfVar3 + 0xe;
                    iVar4 = iVar4 + -1;
                } while (iVar4 != 0);
                return;
            }
            // Rotation: 2D rotation matrix applied
            float* pfVar3 = reinterpret_cast<float*>(iVar5 + (iVar1 * 7 + 3) * 8);
            do {
                *pfVar3 = (pfVar3[-6] * local_18 - pfVar3[-5] * fVar6) *
                           local_1c + local_20 + param_5;
                pfVar3[1] = (pfVar3[-6] * fVar6 + pfVar3[-5] * local_18) *
                             param_4 + param_6;
                pfVar3 = pfVar3 + 0xe;
                iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
            return;
        }
    }
}

} // namespace Giants
