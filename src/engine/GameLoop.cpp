// Giants Engine - Game Loop Implementation (MainGameLoop)
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_0062d100 — MainGameLoop
// The heart of the engine: window creation, subsystem init, frame loop
//
// Status: STUB — minimal implementation for standalone exe testing.
//         The real function is ~1648 lines with 104 callees.
//         TRACE_FUNC instrumentation is in place to capture crash points.

#include "GameLoop.h"
#include "EngineInit.h"
#include "TraceLog.h"
#include "Timer.h"
#include "Input.h"
#include "GameLogic.h"

#include <windows.h>
#include <cstdio>

namespace Giants {

// ─── MainGameLoop (FUN_0062d100) — STUB ──────────────────────
// In the original binary, this is called after window creation and
// performs: globals init → SetProcessAffinityMask → RegisterClass →
// CreateWindow → InitializeEngine → message pump loop → cleanup.
//
// For our standalone exe, the window is already created by WinMain.
// We just need to enter the message pump.

uint32_t MainGameLoop(HINSTANCE hInstance, uint32_t param2, int nCmdShow)
{
    TRACE_FUNC;

    // ─── Init globals (Phase 1) ─────────────────────────────────
    // Original: memset 0x110 bytes of globals, then InitGlobals()
    InitGlobals();

    // ─── Process affinity (Phase 2) ─────────────────────────────
    // Original: SetProcessAffinityMask(GetCurrentProcess(), 1)
    // Restrict to single core for timing consistency
    SetProcessAffinityMask(GetCurrentProcess(), 1);

    if (g_traceLog) { fprintf(g_traceLog, "[TRACE] MainGameLoop: entering message pump\n"); fflush(g_traceLog); }

    // ─── Message Pump (Phase 7) ─────────────────────────────────
    MSG msg;
    int frameCount = 0;
    while (g_shutdownRequested == 0)
    {
        // Process all pending messages
        while (PeekMessageA(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                g_shutdownRequested = 1;
                break;
            }
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        if (g_shutdownRequested)
            break;

        // ─── Frame tick ──────────────────────────────────────────
        if (g_traceLog && frameCount == 0) {
            fprintf(g_traceLog, "[TRACE] MainGameLoop: first frame tick\n"); fflush(g_traceLog);
        }
        frameCount++;

        ProcessRawKeyboardInput();
        if (g_traceLog && frameCount == 1) {
            fprintf(g_traceLog, "[TRACE] MainGameLoop: ProcessRawKeyboardInput OK\n"); fflush(g_traceLog);
        }

        UpdateTime();
        if (g_traceLog && frameCount == 1) {
            fprintf(g_traceLog, "[TRACE] MainGameLoop: UpdateTime OK\n"); fflush(g_traceLog);
        }

        ProcessMouseInput();
        if (g_traceLog && frameCount == 1) {
            fprintf(g_traceLog, "[TRACE] MainGameLoop: ProcessMouseInput OK\n"); fflush(g_traceLog);
        }

        ProcessGameLogic();
        if (g_traceLog && frameCount == 1) {
            fprintf(g_traceLog, "[TRACE] MainGameLoop: ProcessGameLogic OK\n"); fflush(g_traceLog);
        }
    }

    // ─── Cleanup (Phase 8) ──────────────────────────────────────
    // Original: COM Release, audio shutdown, renderer free
    // TODO: implement cleanup sequence

    if (g_traceLog) {
        fprintf(g_traceLog, "[LOOP] MainGameLoop exited after %d frames (shutdown=%d)\n",
                frameCount, g_shutdownRequested);
        fflush(g_traceLog);
    }

    return 0;
}

// ─── Stub implementations for game loop helpers ────────────────
// These are called by MainGameLoop but are not yet fully reversed.

void InitGlobals()
{
    TRACE_FUNC;
    // Original: FUN_0062d590 — zeros ~0x110 bytes of globals, sets defaults
    // Minimal stub — globals already zero-initialized
}

void OnQuitRequested()
{
    TRACE_FUNC;
    g_shutdownRequested = 1;
}

void CleanupNetwork() {}
void SaveGameState() {}
void FlushGameData() {}
void ShutdownAudio() {}

} // namespace Giants
