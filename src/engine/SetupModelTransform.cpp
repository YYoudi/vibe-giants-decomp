// Giants Engine - Setup Model Transform Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "SetupModelTransform.h"
#include <cstring>

namespace Giants {

// ─── Globals ────────────────────────────────────────────────────
extern uint32_t g_xorMask;        // DAT_0066c580
extern float    g_zeroFloat;      // _DAT_0066bce4
extern int*     g_renderList;     // DAT_007027b0

// ─── External callees ──────────────────────────────────────────
extern int  GetRendererState();     // FUN_0056fc10
extern int  GetRenderContext();     // FUN_0056e960
extern void SetupRenderState();    // FUN_0055c150
extern void UpdateModelMatrixCache(void* state, int rs); // FUN_004e9cd0
extern void FlushRenderState();    // FUN_0055d110
extern int  IsViewportActive();    // FUN_0055ee40

int SetupModelTransform(uint32_t param1, uint32_t param2, uint32_t* param3, uint32_t param4)
{
    int iVar11 = GetRendererState();

    // Clear model matrix dirty flag (bit 17)
    *reinterpret_cast<uint32_t*>(iVar11 + 0x214) &= 0xfffdffff;

    int iVar12 = GetRenderContext();
    int iVar5 = *reinterpret_cast<int*>(iVar11 + 0x14c);

    *reinterpret_cast<uint32_t*>(iVar5 + 0x21c) = param4;

    SetupRenderState();

    uint32_t uVar10 = g_xorMask;

    // Copy 4x4 matrix (17 values) from param3 to entity at +0x2e4
    *reinterpret_cast<uint32_t*>(iVar11 + 0x2e4) = param3[0];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x2e8) = param3[1];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x2ec) = param3[2];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x2f0) = param3[3];

    *reinterpret_cast<uint32_t*>(iVar11 + 0x2f4) = param3[4];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x2f8) = param3[5];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x2fc) = param3[6];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x300) = param3[7];

    *reinterpret_cast<uint32_t*>(iVar11 + 0x304) = param3[8];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x308) = param3[9];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x30c) = param3[10];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x310) = param3[11];

    *reinterpret_cast<uint32_t*>(iVar11 + 0x314) = param3[12];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x318) = param3[13];
    *reinterpret_cast<uint32_t*>(iVar11 + 0x31c) = param3[14];
    *reinterpret_cast<uint32_t*>(iVar11 + 800) = param3[15];

    *reinterpret_cast<uint32_t*>(iVar11 + 0x324) = param3[16];

    // Set matrix updated flag (bit 16)
    *reinterpret_cast<uint32_t*>(iVar11 + 0x124) |= 0x10000;

    // Compute scale from XOR'd diagonal
    float scaleX, scaleY, scaleZ;
    memcpy(&scaleX, &param3[2], 4); uint32_t sx = *reinterpret_cast<uint32_t*>(&scaleX) ^ uVar10;
    memcpy(&scaleY, &param3[6], 4); uint32_t sy = *reinterpret_cast<uint32_t*>(&scaleY) ^ uVar10;
    memcpy(&scaleZ, &param3[10], 4); uint32_t sz = *reinterpret_cast<uint32_t*>(&scaleZ) ^ uVar10;

    float ctxScale = *reinterpret_cast<float*>(iVar12 + 0x10);
    float fx, fy, fz;
    memcpy(&fx, &sx, 4);
    memcpy(&fy, &sy, 4);
    memcpy(&fz, &sz, 4);
    *reinterpret_cast<float*>(iVar11 + 0x174) = fx * ctxScale;
    *reinterpret_cast<float*>(iVar11 + 0x178) = fy * ctxScale;
    *reinterpret_cast<float*>(iVar11 + 0x17c) = fz * ctxScale;

    // Update model matrix cache
    if (*reinterpret_cast<char*>(iVar12 + 0xe0) != '\0')
    {
        uint8_t local_3c[20];
        UpdateModelMatrixCache(local_3c, iVar11);
    }

    int iVar7 = *reinterpret_cast<int*>(iVar11 + 0x14c);

    FlushRenderState();

    int iVar13 = GetRenderContext();

    // Viewport-projected position for perspective
    if (((*reinterpret_cast<uint32_t*>(iVar13 + 0xc) & 0x20000) != 0) &&
        (*reinterpret_cast<float*>(iVar13 + 0x60) == g_zeroFloat))
    {
        float fVar15 = *reinterpret_cast<float*>(iVar13 + 0x34) / *reinterpret_cast<float*>(iVar13 + 0x18);

        *reinterpret_cast<float*>(iVar7 + 0x204) = fVar15 * *reinterpret_cast<float*>(iVar11 + 0x174) + *reinterpret_cast<float*>(iVar11 + 0xf0);
        *reinterpret_cast<float*>(iVar7 + 0x208) = fVar15 * *reinterpret_cast<float*>(iVar11 + 0x178) + *reinterpret_cast<float*>(iVar11 + 0xf4);
        *reinterpret_cast<float*>(iVar7 + 0x20c) = fVar15 * *reinterpret_cast<float*>(iVar11 + 0x17c) + *reinterpret_cast<float*>(iVar11 + 0xf8);

        int viewportActive = IsViewportActive();
        *reinterpret_cast<bool*>(iVar7 + 0x200) = (viewportActive != 0);
    }

    // Validate render target
    if ((*reinterpret_cast<uint8_t*>(iVar12 + 0xc) & 1) != 0)
    {
        iVar12 = *reinterpret_cast<int*>(iVar5 + 0x21c);

        if ((iVar12 != 0) &&
            (*reinterpret_cast<int*>(iVar12 + 0x22c) == 2) &&
            ((*reinterpret_cast<uint32_t*>(iVar12 + 300) & 0x8020000) != 0))
        {
            int* piVar14 = g_renderList;

            if (piVar14 != nullptr)
            {
                while (true)
                {
                    iVar7 = piVar14[3];

                    if ((*reinterpret_cast<int*>(iVar7 + 0x264) != iVar12) ||
                        (*reinterpret_cast<int*>(iVar7 + 4) != 0x3df))
                    {
                        piVar14 = *reinterpret_cast<int**>(piVar14);
                        if (piVar14 == nullptr)
                            return iVar11;
                    }
                    else
                    {
                        break;
                    }
                }

                *reinterpret_cast<int*>(iVar5 + 0x228) = iVar7;
            }
        }
    }

    return iVar11;
}

} // namespace Giants
