// Giants Engine - Main Render Frame Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "RenderFrame.h"
#include <cstdint>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern uint32_t DAT_0067d280;    // Security cookie — CRTStubs.cpp
extern int      g_renderState;   // DAT_00702d5c — GameLogic.cpp
extern int      g_isActive;      // DAT_00748a34 — GameLogic.cpp
extern int      g_someFlag;      // DAT_00702be8 — EngineInit.cpp
extern int      g_presentMode;   // DAT_00749000 — GameSettings.cpp
extern int      g_renderMode;    // DAT_00749004 — GameSettings.cpp
extern int      g_frameData;     // DAT_0074b5f8 — GameLoop.cpp
extern int&     g_frameCount;    // DAT_00682e9c / DAT_0074b5fc — GameLoop.cpp
extern int      g_frameParam;    // DAT_00681dd0
extern int      g_frameParam2;   // DAT_00681db4
extern int      g_frameParam3;   // DAT_00681dec
extern int      g_frameActive;   // DAT_00681db0
extern int      g_frameParam4;   // DAT_00681e34
extern int      g_configValue;   // DAT_00702d60 — GameSettings.cpp

// ─── External callees ──────────────────────────────────────────
extern void FUN_006435f8();      // TLS alloc
extern void FUN_004ad590();      // TLS callback init
extern void FUN_0064389d();      // TLS atexit
extern void FUN_006435a7();      // TLS set index
extern void FUN_0049a040();      // UpdateActiveCamera
extern void FUN_004e9bb0();      // RenderScene (DX8 path)
extern void FUN_004d5b50();      // RenderScene (DX9+ path)
extern void FUN_005d7de0();      // Post-processing dispatch
extern void FUN_005dec20();      // Frame finalize
extern void FUN_005401b0();      // Frame end
extern void FUN_005fa390();      // Viewport setup
extern void FUN_00565580();      // Pre-frame reset

// ═══════════════════════════════════════════════════════════════════
// RenderFrame (FUN_00541860) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Main per-frame render dispatch. Two paths:
//
// Path A (g_renderState != 0, active rendering):
//   - If g_isActive == 0: full render cycle
//     - UpdateActiveCamera
//     - Select renderer by presentMode/renderMode
//     - Run post-processing loops
//     - Finalize frame
//   - If g_isActive != 0: set inactive, return
//
// Path B (g_renderState == 0, first frame init):
//   - Initialize frame parameters
//   - UpdateActiveCamera + viewport setup
//   - TLS renderer vtable dispatch
//   - Select renderer, run post-processing
//   - Finalize + pre-frame reset

void RenderFrame()
{
    if (g_someFlag != 0) {
        return;
    }

    // TLS initialization (MSVC __tls_init pattern)
    // Note: Simplified for ground truth — actual TLS check omitted
    static void* g_tlsRenderer = nullptr;  // DAT_0074ef18

    if (g_renderState != 0) {
        // ── Active rendering path ──
        if (g_isActive == 0) {
            FUN_0049a040();  // UpdateActiveCamera

            if (g_presentMode == 0) {
                if (g_renderMode == 0) {
                    FUN_004e9bb0();  // DX8 render
                } else {
                    FUN_004d5b50();  // DX9+ render
                }
            } else {
                FUN_004d5b50();  // DX9+ render
            }

            // Post-processing loops
            for (int i = *reinterpret_cast<int*>(g_frameData + 4 + g_frameCount * 0x24);
                 i != 0; i--) {
                FUN_005d7de0();
            }

            FUN_005dec20();  // Frame finalize
            FUN_005401b0();  // Frame end
            return;
        }
        g_isActive = 0;
        return;
    }

    // ── First frame / initialization path ──
    g_frameParam = g_configValue;
    g_frameParam2 = 0;
    g_frameParam3 = 0;
    g_frameActive = 1;

    FUN_0049a040();  // UpdateActiveCamera
    FUN_005fa390();  // Viewport setup

    // TLS renderer vtable call [1]
    if (g_tlsRenderer != nullptr) {
        reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(
            *reinterpret_cast<void**>(g_tlsRenderer) + 8))();
    }

    if (g_presentMode == 0) {
        if (g_renderMode == 0) {
            FUN_004e9bb0();
        } else {
            FUN_004d5b50();
        }
    } else {
        FUN_004d5b50();
    }

    // Post-processing loops
    for (int i = *reinterpret_cast<int*>(g_frameData + 4 + g_frameCount * 0x24);
         i != 0; i--) {
        FUN_005d7de0();
    }

    FUN_005dec20();

    // TLS renderer vtable call [3]
    if (g_tlsRenderer != nullptr) {
        reinterpret_cast<void(*)()>(*reinterpret_cast<void**>(
            *reinterpret_cast<void**>(g_tlsRenderer) + 0x18))();
    }

    g_frameActive = 0;
    g_frameParam2 = -1;
    g_frameParam3 = 0;
    g_frameParam4 = 0;

    FUN_00565580();  // Pre-frame reset
    FUN_005401b0();  // Frame end
}

} // namespace Giants
