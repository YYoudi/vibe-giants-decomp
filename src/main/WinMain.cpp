// GiantsRE — Standalone GiantsMain.exe
// Entry point: WinMain → EngineInitializeImpl → MainGameLoop
//
// This is our recompiled version of GiantsMain.exe v1.520.59.
// It links against the full giants_engine static lib (all 6254 RE'd functions).
// Most functions are stubs — crashes are expected and logged via TRACE_FUNC.

#include "engine/Engine.h"
#include "engine/GameLoop.h"
#include "engine/EngineInit.h"
#include "engine/TraceLog.h"
#include "engine/CRTStubs.h"
#include "renderer/RendererLoader.h"

#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// ═══════════════════════════════════════════════════════════════
// Globals defined ONLY here (not duplicated in other .cpp files).
// Other globals (g_hWnd, g_GDVSysCreate, g_renderDevice, etc.)
// are already defined in their respective subsystem .cpp files.
// ═══════════════════════════════════════════════════════════════

namespace Giants {

// Window globals — only defined here
HINSTANCE g_hInstance         = nullptr;   // DAT_007281dc
HACCEL    g_hAccelTable       = nullptr;   // DAT_007281e0
int       g_shutdownRequested = 0;         // DAT_007281e4
int       g_renderInitialized = 0;         // DAT_007281d4
int       g_gameState         = 0;         // DAT_006866c4

// g_traceLog now defined in giants_engine (src/engine/TraceLog.cpp) so the
// gg_dx9r proxy DLL links too. Declared extern via TraceLog.h.

// ─── Vectored Exception Handler for crash diagnosis ──────────────
static LONG CALLBACK CrashHandler(PEXCEPTION_POINTERS pEx)
{
    if (g_traceLog)
    {
        DWORD code = pEx->ExceptionRecord->ExceptionCode;
        void* addr = pEx->ExceptionRecord->ExceptionAddress;
        CONTEXT* ctx = pEx->ContextRecord;

        fprintf(g_traceLog, "\n[CRASH] Exception 0x%08lX at address %p\n", (unsigned long)code, addr);
        fprintf(g_traceLog, "[CRASH] EAX=%08lX EBX=%08lX ECX=%08lX EDX=%08lX\n",
            (unsigned long)ctx->Eax, (unsigned long)ctx->Ebx,
            (unsigned long)ctx->Ecx, (unsigned long)ctx->Edx);
        fprintf(g_traceLog, "[CRASH] ESI=%08lX EDI=%08lX EBP=%08lX ESP=%08lX\n",
            (unsigned long)ctx->Esi, (unsigned long)ctx->Edi,
            (unsigned long)ctx->Ebp, (unsigned long)ctx->Esp);
        fprintf(g_traceLog, "[CRASH] EIP=%08lX EFL=%08lX\n",
            (unsigned long)ctx->Eip, (unsigned long)ctx->EFlags);

        // Check if crash is inside gg_dx9r.dll (loaded at 0x10000000)
        if ((uintptr_t)addr >= 0x10000000 && (uintptr_t)addr < 0x10200000)
        {
            fprintf(g_traceLog, "[CRASH] >>> Inside gg_dx9r.dll (offset +0x%05X)\n",
                (unsigned int)((uintptr_t)addr - 0x10000000));
        }

        // Dump stack for context
        DWORD* sp = (DWORD*)(uintptr_t)ctx->Esp;
        fprintf(g_traceLog, "[CRASH] Stack dump (ESP+0..+64):\n");
        for (int i = 0; i < 16; i++)
        {
            fprintf(g_traceLog, "[CRASH]   ESP+%02X: %08lX\n", i*4, (unsigned long)sp[i]);
        }

        // Walk the EBP chain to log return addresses (call stack) — identifies
        // which engine/renderer function led to the crash.
        fprintf(g_traceLog, "[CRASH] Call stack (EBP chain return addresses):\n");
        DWORD ebp = ctx->Ebp;
        for (int frame = 0; frame < 24 && ebp != 0 && ebp > ctx->Esp && ebp < 0x3000000; frame++) {
            DWORD retAddr = *((DWORD*)(uintptr_t)(ebp + 4));
            const char* where = "unknown";
            uintptr_t a = (uintptr_t)retAddr;
            if (a >= 0x400000 && a < 0x700000) where = "recomp-engine";
            else if (a >= 0x10000000 && a < 0x10200000) where = "gg_dx9r(renderer)";
            else if (a >= 0x62300000 && a < 0x62400000) where = "gg_dx9r(renderer)";
            else if (a >= 0x70000000) where = "system-DLL";
            fprintf(g_traceLog, "[CRASH]   #%d  ret=0x%08lX  (%s)\n", frame, (unsigned long)retAddr, where);
            ebp = *((DWORD*)(uintptr_t)ebp);
        }

        fflush(g_traceLog);
    }
    return EXCEPTION_CONTINUE_SEARCH; // Let it crash after logging
}

} // namespace Giants

// ═══════════════════════════════════════════════════════════════
// WinMain — Entry Point
// ═══════════════════════════════════════════════════════════════

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    // Initialize trace logging FIRST — before any engine code
    Giants::TraceInit();

    // Install crash handler BEFORE anything else
    AddVectoredExceptionHandler(1, Giants::CrashHandler);

    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] WinMain entered\n");
        fprintf(Giants::g_traceLog, "[TRACE] Command line: %s\n", lpCmdLine ? lpCmdLine : "(null)");
        fflush(Giants::g_traceLog);
    }

    // Store globals
    Giants::g_hInstance = hInstance;

    // ─── Phase 1: Register Window Class ────────────────────────
    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Registering window class...\n");
        fflush(Giants::g_traceLog);
    }

    WNDCLASSA wc = {};
    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc   = Giants::WndProc;
    wc.hInstance      = hInstance;
    wc.hCursor        = LoadCursorA(nullptr, IDC_ARROW);
    wc.hbrBackground  = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wc.lpszClassName  = "GiantsWinClass";

    ATOM classAtom = RegisterClassA(&wc);
    if (!classAtom) {
        if (Giants::g_traceLog) {
            fprintf(Giants::g_traceLog, "[FATAL] RegisterClassA failed, error=%lu\n", (unsigned long)GetLastError());
            fflush(Giants::g_traceLog);
        }
        MessageBoxA(nullptr, "Failed to register window class", "GiantsRE", MB_OK);
        return 1;
    }
    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Window class registered (atom=0x%04X)\n", classAtom);
        fflush(Giants::g_traceLog);
    }

    // ─── Phase 2: Create Window ────────────────────────────────
    DWORD windowStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
    DWORD windowExStyle = 0;

    // Check for -window flag
    bool windowed = (lpCmdLine && strstr(lpCmdLine, "-window") != nullptr);

    int width = 1280;
    int height = 720;

    if (windowed) {
        windowStyle = WS_OVERLAPPEDWINDOW | WS_VISIBLE;
    } else {
        windowStyle = WS_POPUP | WS_VISIBLE;
        windowExStyle = WS_EX_TOPMOST;
    }

    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Creating window (%dx%d, %s)...\n",
                width, height, windowed ? "windowed" : "fullscreen");
        fflush(Giants::g_traceLog);
    }

    Giants::g_hWnd = CreateWindowExA(
        windowExStyle,
        "GiantsWinClass",
        "Giants: Citizen Kabuto [RECOMP]",
        windowStyle,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width, height,
        nullptr, nullptr, hInstance, nullptr
    );

    if (!Giants::g_hWnd) {
        if (Giants::g_traceLog) {
            fprintf(Giants::g_traceLog, "[FATAL] CreateWindowExA failed, error=%lu\n", (unsigned long)GetLastError());
            fflush(Giants::g_traceLog);
        }
        MessageBoxA(nullptr, "Failed to create window", "GiantsRE", MB_OK);
        return 2;
    }
    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Window created: hWnd=0x%p\n", Giants::g_hWnd);
        fflush(Giants::g_traceLog);
    }

    // ─── Phase 3: Initialize Engine ────────────────────────────
    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Calling InitializeEngine...\n");
        fflush(Giants::g_traceLog);
    }

    // CRITICAL: param_2 MUST be the command line string (lpCmdLine).
    // The renderer receives this as the 1st arg to GDVSysCreate and:
    //   1. Parses it with strtok to find renderer mode ("DX9"/"DX11"/"DX12")
    //   2. Reads at [ptr + 0x2B608] — so it MUST point to large valid memory
    // Windows' lpCmdLine buffer is in the PEB (large mapped region), safe for this.
    int initResult = Giants::InitializeEngine(
        reinterpret_cast<unsigned int>(hInstance),
        reinterpret_cast<unsigned int>(lpCmdLine ? lpCmdLine : "")
    );

    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] InitializeEngine returned %d\n", initResult);
        fflush(Giants::g_traceLog);
    }

    if (initResult == 0) {
        if (Giants::g_traceLog) {
            fprintf(Giants::g_traceLog, "[FATAL] InitializeEngine failed\n");
            fflush(Giants::g_traceLog);
        }
        MessageBoxA(nullptr, "Engine initialization failed", "GiantsRE", MB_OK);
        return 3;
    }

    // ─── Phase 4: Enter Game Loop ──────────────────────────────
    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Entering MainGameLoop...\n");
        fflush(Giants::g_traceLog);
    }

    uint32_t loopResult = Giants::MainGameLoop(hInstance, 0, nCmdShow);

    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] MainGameLoop returned %u\n", loopResult);
        fprintf(Giants::g_traceLog, "[TRACE] WinMain exiting normally\n");
        fflush(Giants::g_traceLog);
    }

    Giants::TraceShutdown();
    return loopResult;
}
