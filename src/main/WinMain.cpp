// GiantsRE — Standalone GiantsMain.exe
// Entry point: WinMain → EngineInitializeImpl → MainGameLoop
//
// This is our recompiled version of GiantsMain.exe v1.520.59.
// It links against the full giants_engine static lib (all 6254 RE'd functions).
// Most functions are stubs — crashes are expected and logged via TRACE_FUNC.

#include "engine/Engine.h"
#include "engine/GameLoop.h"
#include "engine/EngineInit.h"
#include "engine/Player.h"
#include "vfs/VirtualFileSystem.h"
#include "engine/TraceLog.h"
#include "engine/CRTStubs.h"
#include "renderer/RendererLoader.h"

#include <windows.h>
#include <dbghelp.h>
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
    // Filter out BENIGN exceptions so the trace reflects only real crashes:
    //  - IsBadReadPtr and friends deliberately raise an access violation to
    //    probe a pointer, then catch it themselves (SEH-internal probing).
    //  - GPU driver DLLs (AMDXN32, nvoglv, igdumd, d3d9 internals) raise and
    //    swallow exceptions as part of normal operation.
    // We are FIRST in the VEH chain (priority 1), so we see all of these.
    // Only LOG when the fault is in OUR code: the recomp engine image range,
    // the gg_dx9r renderer DLL, or a null call whose caller is our engine.
    {
        DWORD code = pEx->ExceptionRecord->ExceptionCode;
        uintptr_t addr = (uintptr_t)pEx->ExceptionRecord->ExceptionAddress;
        const uintptr_t ENG_LO = 0x00401000, ENG_HI = 0x00444000;
        const uintptr_t RND_LO = 0x10000000, RND_HI = 0x10200000;

        bool inOurCode = (addr >= ENG_LO && addr < ENG_HI) || (addr >= RND_LO && addr < RND_HI);

        // Null call (EIP==0): only ours if the stack contains a return address
        // inside the engine image. Driver-originated null calls stay silent.
        if (addr == 0) {
            CONTEXT* c = pEx->ContextRecord;
            DWORD* sp = (DWORD*)(uintptr_t)c->Esp;
            for (int i = 0; i < 24 && !inOurCode; i++) {
                DWORD v = sp[i];
                if (v >= ENG_LO && v < ENG_HI) inOurCode = true;
            }
        }

        if (!inOurCode) return EXCEPTION_CONTINUE_SEARCH; // benign, silent
        (void)code;
    }

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

        // Dump stack for context — resolve each value's module so we can tell
        // whether the null call came from the engine (fixable), the renderer,
        // d3d9.dll, or a GPU driver DLL (benign driver-internal SEH).
        DWORD* sp = (DWORD*)(uintptr_t)ctx->Esp;
        HANDLE hProcForStack = GetCurrentProcess();
        fprintf(g_traceLog, "[CRASH] Stack dump (ESP+0..+64, with module resolution):\n");
        for (int i = 0; i < 16; i++)
        {
            DWORD val = sp[i];
            HMODULE hMod = nullptr;
            char modTag[96] = "";
            // Only attempt resolution for plausible code addresses.
            if (val >= 0x00400000 && val < 0x80000000) {
                if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                                       GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                                       (LPCSTR)(uintptr_t)val, &hMod) && hMod) {
                    char path[MAX_PATH] = {0};
                    if (GetModuleFileNameA(hMod, path, sizeof(path))) {
                        const char* base = strrchr(path, '\\');
                        base = base ? base + 1 : path;
                        uintptr_t modBase = (uintptr_t)hMod;
                        snprintf(modTag, sizeof(modTag), "  <%s +0x%X>",
                                 base, (unsigned)(val - modBase));
                    }
                }
            }
            fprintf(g_traceLog, "[CRASH]   ESP+%02X: %08lX%s\n",
                    i*4, (unsigned long)val, modTag);
        }

        // Walk the EBP chain to log return addresses (call stack) — identifies
        // which engine/renderer function led to the crash.
        fprintf(g_traceLog, "[CRASH] Call stack (StackWalk64):\n");        {
            HANDLE hProc = GetCurrentProcess(); HANDLE hThr = GetCurrentThread();
            SymSetOptions(SYMOPT_DEFERRED_LOADS);
            SymInitialize(hProc, nullptr, TRUE);
            CONTEXT ctxCopy = *ctx;
            STACKFRAME64 sf = {};
            sf.AddrPC.Offset = ctx->Eip;     sf.AddrPC.Mode = AddrModeFlat;
            sf.AddrStack.Offset = ctx->Esp;  sf.AddrStack.Mode = AddrModeFlat;
            sf.AddrFrame.Offset = ctx->Ebp;  sf.AddrFrame.Mode = AddrModeFlat;
            for (int frame = 0; frame < 32; frame++) {
                if (!StackWalk64(IMAGE_FILE_MACHINE_I386, hProc, hThr, &sf, &ctxCopy,
                                 nullptr, SymFunctionTableAccess64, SymGetModuleBase64, nullptr))
                    break;
                DWORD64 pc = sf.AddrPC.Offset;
                const char* where = "unknown";
                if (pc >= 0x401000 && pc < 0x444000) where = "recomp-engine";
                else if (pc >= 0x10000000 && pc < 0x10200000) where = "renderer";
                else if (pc >= 0x62300000 && pc < 0x62400000) where = "renderer";
                else if (pc >= 0x70000000) where = "system-DLL";
                char symBuf[sizeof(SYMBOL_INFO)+256] = {0};
                SYMBOL_INFO* sym = (SYMBOL_INFO*)symBuf; sym->SizeOfStruct = sizeof(SYMBOL_INFO); sym->MaxNameLen = 256;
                const char* name = "";
                if (SymFromAddr(hProc, pc, nullptr, sym)) name = sym->Name;
                fprintf(g_traceLog, "[CRASH]   #%d  pc=0x%08llX  %s %s\n",
                        frame, (unsigned long long)pc, where, name);
                if (pc == 0) break;
            }
            SymCleanup(hProc);
        }

        // Dump engine state — search for the bad pointer the renderer computed.
        extern void* GetEngineContextPtr();
        extern DWORD* GetRendererStatePtr();
        void* ec = GetEngineContextPtr();
        DWORD* rs = GetRendererStatePtr();
        fprintf(g_traceLog, "[DUMP] g_engineContext=%p:", ec);
        if (ec) for (int i=0;i<7;i++) fprintf(g_traceLog, " [%d]=0x%08X", i, ((DWORD*)ec)[i]);
        fprintf(g_traceLog, "\n[DUMP] g_rendererState[0..47]:");
        for (int i=0;i<48;i++) fprintf(g_traceLog, " %08X", rs[i]);
        fprintf(g_traceLog, "\n");

        fflush(g_traceLog);
    }
    return EXCEPTION_CONTINUE_SEARCH; // Let it crash after logging
}

} // namespace Giants

// Forward-declare the char* CLI-parser overload (defined in EngineLifecycle.cpp;
// the no-arg InitGlobals() is declared via GameLoop.h).
namespace Giants { void InitGlobals(char* commandLine); }

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

    // ─── Phase 3a: Initialize VFS (file system) ────────────────
    if (Giants::g_traceLog) {
        fprintf(Giants::g_traceLog, "[TRACE] Calling VFS_Initialize...\n");
        fflush(Giants::g_traceLog);
    }
    Giants::VFS_Initialize();
    if (Giants::g_traceLog) {
        int fc = Giants::VFS_GetFileCount();
        fprintf(Giants::g_traceLog, "[VFS] Initialize done: %d files indexed\n", fc);
        for (int i = 0; i < fc && i < 25; i++)
            fprintf(Giants::g_traceLog, "[VFS]   [%d] %s\n", i, Giants::VFS_GetFileName(i));
        // Try level-name lookups (various extension conventions).
        const char* names[] = {"intro_island", "intro_island.gti", "intro_island.gck",
                               "intro_island.bin", "w_intro_island.bin", "intros.bin"};
        for (auto n : names) {
            char buf[128]; snprintf(buf, sizeof(buf), "%s", n);
            fprintf(Giants::g_traceLog, "[VFS] lookup \"%s\" -> 0x%08X\n", n, Giants::VFSFileLookup(buf));
        }
        fflush(Giants::g_traceLog);
    }

    // ─── Phase 3a5: Parse command line (InitGlobals — original CLI parser) ──
    // The original parses the command line early (player/server/level/FPS tokens
    // + -window/-nointro/-dedicated/+connect/+host switches). InitGlobals(char*)
    // is the real parser; the no-arg InitGlobals() called inside MainGameLoop only
    // does the globals memset. Wire the char* overload so the tokenizer runs
    // (token-matching is still stubbed in EngineLifecycle.cpp — port it to
    // activate flag/level handling).
    Giants::InitGlobals(lpCmdLine ? lpCmdLine : (char*)"");

    // ─── Phase 3b: Load default player / intro scene ───────────
    {
        int ldpResult = Giants::LoadDefaultPlayer();
        if (Giants::g_traceLog) {
            fprintf(Giants::g_traceLog, "[TRACE] LoadDefaultPlayer returned %d\n", ldpResult);
            fflush(Giants::g_traceLog);
        }
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
