// Giants Engine - UI Text Rendering Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderUIText.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Globals (shared) ───────────────────────────────────────────
extern void*    g_renderDevice;       // DAT_00702700 — EngineInit.h
extern uint32_t DAT_0067d280;         // Security cookie — CRTStubs.cpp
extern float    DAT_0066bf2c;         // 1.0f constant — FlickInterpreter.cpp
extern float    DAT_0066bd54;         // Time scale — GameCommand.cpp
extern float    DAT_0066be20;         // Aspect/scale — Camera.cpp
extern float    DAT_0066bdf4;         // Color/scale A
extern float    DAT_0066bec4;         // Scale factor B — AnimationCalc.cpp
extern uint32_t DAT_0074bed4;         // Screen X offset — ErrorHandler.cpp
extern float    _DAT_0074beb4;        // Font pixel size — DisplayMode.cpp
extern float    _DAT_0066bf0c;        // Text offset constant
extern void*    DAT_007280cc;         // Text renderer callback — GameCommand.cpp
extern uint32_t* DAT_00702d50;        // String resolve callback — GameCommand.cpp

// ─── External callees ───────────────────────────────────────────
extern const char* LookupStringById(uint32_t id);     // FUN_005e80c0
extern void        AcquireString(const char** str);    // FUN_005df640
extern void        ReleaseString();                    // FUN_004439b0
extern void        DrawTextPrepare();                  // FUN_0062c690
extern void        DrawTextExecute(float x, int len);  // FUN_0062c420
extern int         GetActiveEntityData();              // FUN_0054e0c0
extern uint64_t    GetEntityPosition();                // FUN_0054d540
extern void        TextCommandDispatchPre();           // FUN_005d79a0 — TransformVertices alias
extern void        TextCommandDispatchPost();          // FUN_005d7de0

// ═══════════════════════════════════════════════════════════════════
// RenderUIText (FUN_005da470) — 27 callers — FAIL (usable ~85%)
// ═══════════════════════════════════════════════════════════════════
// Renders UI text based on mode from param_4+4.
// param_1: entity/context (cast to float for position math)
// param_2: layout descriptor (positions at +0x38..+0x48)
// param_3: must be 0, else early return
// param_4: command descriptor (mode at +4)

uint32_t RenderUIText(int param_1, int param_2, int param_3, int param_4)
{
    if (param_3 != 0) {
        return 0xFFFFFF;
    }

    float local_34 = static_cast<float>(param_1);
    uint32_t local_30 = 0;
    float local_3c = 0.0f;
    const char* local_38 = nullptr;
    float local_38_f = 0.0f;  // float alias for position calc

    int mode = *reinterpret_cast<int*>(param_4 + 4);

    // ── Mode 0: MH_Renderer text with time ──
    if (mode == 0) {
        // Get time value via render device vtable[0x36]
        float timeValue = reinterpret_cast<float(*)(int, uint32_t)>(
            *reinterpret_cast<void**>(
                *reinterpret_cast<void**>(0x00702700))  // g_renderDevice vtable
            + 0xD8)(0, DAT_0067d280 ^ reinterpret_cast<uint32_t>(&param_1));

        local_38 = LookupStringById(/* "MH_Renderer" hash */ 0);
        local_3c = timeValue;
        AcquireString(&local_38);

        // Measure string length (SSO-aware)
        char local_2c[5 * sizeof(void*)];
        uint32_t local_18 = 0;
        char* ppuVar8 = local_2c;
        char* ppuVar5 = local_2c;
        if (local_18 > 0xF) {
            ppuVar8 = *reinterpret_cast<char**>(local_2c);
            ppuVar5 = *reinterpret_cast<char**>(local_2c);
        }
        // Scan to end of string
        char c;
        do { c = *ppuVar8; ppuVar8++; } while (c != '\0');
        DrawTextPrepare();

        const char* scanStart = ppuVar5;
        do { c = *ppuVar5; ppuVar5++; } while (c != '\0');

        DrawTextExecute(
            static_cast<float>(DAT_0074bed4) * (DAT_0066bd54 / _DAT_0074beb4) + _DAT_0066bf0c,
            static_cast<int>(ppuVar5 - scanStart));

        ReleaseString();
    }

    int iVar7 = *reinterpret_cast<int*>(param_4 + 4);

    // ── Mode 0x17: early exit ──
    if (iVar7 == 0x17) {
        return 0xFFFFFF;
    }

    // ── Mode 0x1A: entity camera operation ──
    if (iVar7 == 0x1A) {
        int entityPtr = *reinterpret_cast<int*>(
            *reinterpret_cast<int*>(
                *reinterpret_cast<int*>(static_cast<int>(local_34) + 0x18) + 0x480)
            + 8);

        uint32_t savedValue = *reinterpret_cast<uint32_t*>(entityPtr + 0x1C);
        *reinterpret_cast<uint32_t*>(entityPtr + 0x1C) = 0;

        TextCommandDispatchPre();
        TextCommandDispatchPost();

        *reinterpret_cast<uint32_t*>(entityPtr + 0x1C) = savedValue;
        return 0xFFFFFF;
    }

    // ── Mode 0x19: early exit ──
    if (iVar7 == 0x19) {
        return 0xFFFFFF;
    }

    // ── Get text string ──
    const char* pcVar3 = reinterpret_cast<const char*>(GetActiveEntityData());
    if (pcVar3 == nullptr) {
        return 0xFFFFFF;
    }

    // ── Mode < 0xE: string lookup + position calculation ──
    if (*reinterpret_cast<int*>(param_4 + 4) < 0xE) {
        // Resolve string for this mode
        typedef int* (*ResolveFn)(uint32_t);
        ResolveFn resolve = reinterpret_cast<ResolveFn>(reinterpret_cast<uintptr_t>(DAT_00702d50));
        int* piVar4 = resolve(*reinterpret_cast<uint32_t*>(param_4 + 4));

        // Measure source string
        const char* pcVar6 = pcVar3 + 1;
        const char* scan = pcVar3;
        char c;
        do { c = *scan; scan++; } while (c != '\0');
        piVar4[2] = static_cast<int>(scan - pcVar6);

        if (*piVar4 == 0) {
            iVar7 = *reinterpret_cast<int*>(param_4 + 4);
            if (iVar7 == 0 || iVar7 == 0xB || iVar7 == 0xC || iVar7 == 0xD) {
                local_30 = 0;
                goto LAB_005da6ec;
            }
            uint64_t uVar11 = GetEntityPosition();
            iVar7 = static_cast<int>(uVar11 >> 32);
            if (static_cast<int>(uVar11 & 0xFFFFFFFF) == 0) {
                local_30 = *reinterpret_cast<uint32_t*>(&DAT_0066bdf4);
            } else {
                local_30 = *reinterpret_cast<uint32_t*>(&DAT_0066bec4);
            }
        } else {
            if (piVar4[1] != 0 && *reinterpret_cast<int*>(piVar4[1]) == 0) {
                DAT_007280cc = reinterpret_cast<void*>(0x005423e0);
            }
            local_30 = 0;
LAB_005da6ec:
            iVar7 = *reinterpret_cast<int*>(param_4 + 4);
        }

        if (iVar7 == 0 || iVar7 == 0xB || iVar7 == 0xC || iVar7 == 0xD) {
            float fVar10;
            float posField = *reinterpret_cast<float*>(param_2 + 0x48);
            int lineCount = *reinterpret_cast<int*>(static_cast<int>(local_34) + 0x28);
            local_38_f =
                (*reinterpret_cast<float*>(param_2 + 0x44) +
                 *reinterpret_cast<float*>(param_2 + 0x38)) *
                DAT_0066be20 /
                static_cast<float>(*reinterpret_cast<int*>(static_cast<intptr_t>(local_34) + 0x24));

            const char* scan2 = pcVar3;
            char c2;
            do { c2 = *scan2; scan2++; } while (c2 != '\0');

            local_34 = (posField - *reinterpret_cast<float*>(param_2 + 0x3C)) /
                       static_cast<float>(lineCount);

            DrawTextPrepare();

            const char* scan3 = pcVar3;
            const char* scan3b = pcVar3 + 1;
            do { c2 = *scan3; scan3++; } while (c2 != '\0');

            iVar7 = static_cast<int>(scan3 - scan3b);
            fVar10 = DAT_0066bf2c - posField / static_cast<float>(lineCount);

            // goto LAB_005da883;  // fallthrough
        }
    } else {
        local_30 = *reinterpret_cast<uint32_t*>(&DAT_0066bdf4);
    }

    // ── Default path: simple text rendering ──
    {
        int* piVar4b = reinterpret_cast<int*>(static_cast<int>(local_34) + 0x28);
        float fVar10;
        const char* pcVar6b = pcVar3 + 1;

        local_34 = (*reinterpret_cast<float*>(param_2 + 0x48) -
                    *reinterpret_cast<float*>(param_2 + 0x3C)) /
                   static_cast<float>(*piVar4b);

        const char* scan4 = pcVar3;
        char c3;
        do { c3 = *scan4; scan4++; } while (c3 != '\0');

        iVar7 = static_cast<int>(scan4 - pcVar6b);
        fVar10 = DAT_0066bf2c -
                 *reinterpret_cast<float*>(param_2 + 0x48) / static_cast<float>(*piVar4b);

        DrawTextPrepare();

        // LAB_005da883: fallthrough
        DrawTextExecute(
            fVar10 + (local_34 / _DAT_0074beb4) * static_cast<float>(DAT_0074bed4),
            iVar7);
    }

    DAT_007280cc = nullptr;
    return 0xFFFFFF;
}

} // namespace Giants
