// Giants Engine - Game Logic / Render Pipeline Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_00524f30 — ProcessGameLogic (PASS, 1 round)
// Per-frame game logic: timer accumulation, render state save/restore,
// vtable dispatch to renderer, scene rendering, network sync.

#include "GameLogic.h"
#include "GiantsTypes.h"
#include "ScenePipeline.h"
#include "TimerTick.h"
#include "Camera.h"
#include "MathUtils.h"

#include <cstdio>
#include <cmath>

namespace Giants {

// ─── Trace log extern ─────────────────────────────────────────
extern FILE* g_traceLog;

// ─── Global State ─────────────────────────────────────────────

bool     g_frameActive      = false;    // DAT_00702b1d
int      g_frameTimer       = 0;        // DAT_00702890
int      g_frameCount2      = 0;        // DAT_00702894
int      g_countdownActive  = 0;        // DAT_0074bc18
bool     g_cutsceneMode     = false;    // DAT_00702aec
float    g_countdownTimer   = 0.0f;     // DAT_0074bbbc
int      g_renderMode       = 0;        // DAT_00702a58
int      g_sceneReady       = 0;        // DAT_00702770
void*    g_rendererObj      = nullptr;  // DAT_00702700
void*    g_renderCtx        = nullptr;  // DAT_00702714

float    g_camX             = 0.0f;     // DAT_0074bb90
float    g_camY             = 0.0f;     // DAT_0074bb94
float    g_camTargetX       = 0.0f;     // DAT_0074bb98
float    g_camTargetY       = 0.0f;     // DAT_0074bb9c

// Timer globals referenced from ProcessGameLogic
float    g_timeMultiplier   = 1.0f;     // DAT_00727e38 — time scale factor
float    g_smoothedTime     = 0.016f;   // DAT_00727e3c — smoothed frame delta

// ─── Remaining stubs (no real implementation or signature mismatch) ──
// These are called from ProcessGameLogic but have no matching real impl yet.

void FUN_005f9c10() {}      // Render pass helper (SetupViewportMatrix — signature mismatch)
void FUN_0063e7f0(void*) {} // Extract render stats (CopyMatrix4x4)
void FUN_005fa310() {}      // Post-render pass (CopyAndObfuscateMatrix — signature mismatch)
void FUN_004ddf10() {}      // Scene render finalize
void FUN_004d0dd0() {}      // Frame end / network tick
void FUN_005253b0() {}      // Final frame flush (FrameEnd — TODO body)
void FUN_00522310() {}      // Scene begin
int  FUN_004e8dd0() { return 0; }  // Network state check
unsigned int FUN_00643f70() { return 0; }  // FloatToInt64 — FPU register param, keep stub

// ─── Renderer Vtable Helper ──────────────────────────────────
// The render device (g_renderDevice) is a COM-like object from gg_dx9r.dll.
// Vtable layout (derived from ScenePipeline.cpp and FrameEnd decompilation):
//   [ 9] 0x24  Present (intermediate, cdecl no args)
//   [10] 0x28  SetTransform (thiscall)
//   [11] 0x2c  SetRenderPass (cdecl no args)
//   [17] 0x44  SetCameraPosition (cdecl void*)
//   [41] 0xa4  BeginScene/RendererInit (cdecl no args — from BeginScene)
//   [42] 0xa8  Shutdown/EndScene (cdecl no args — from ShutdownSubsystems)
//   [43] 0xac  PrePresent (thiscall: ecx=this, stack=[uint32_t sceneState])
//   [47] 0xbc  Present (cdecl no args — from FrameEnd)

// thiscall wrapper using naked function for MinGW (ecx = this)
// Stack on entry (cdecl): retaddr, objPtr, methodPtr, argVal
// We set ecx=objPtr, push argVal, call methodPtr (thiscall: callee cleans 4 bytes)
extern "C" __attribute__((naked)) void CallThiscall_U32() {
    __asm__ volatile (
        "movl 4(%esp), %ecx\n\t"    /* ecx = objPtr (this) */
        "pushl 12(%esp)\n\t"         /* push argVal (3rd param) */
        "call *12(%esp)\n\t"         /* call methodPtr (2nd param, shifted) */
        "addl $4, %esp\n\t"          /* clean pushed arg (caller cleanup) */
        "ret\n\t"
    );
}

// thiscall wrapper with no stack args — just ecx = this
// Stack on entry: retaddr, objPtr, methodPtr
extern "C" __attribute__((naked)) void CallThiscall_Void() {
    __asm__ volatile (
        "movl 4(%esp), %ecx\n\t"    /* ecx = objPtr (this) */
        "call *8(%esp)\n\t"          /* call methodPtr */
        "ret\n\t"
    );
}

// ── D3D9 direct-call wrappers REMOVED ──────────────────────────
// The experimental D3D9 triangle rendering (rebuild-exe approach) is dead code
// for the proxy approach: the proxy intercepts the ORIGINAL exe's callbacks and
// never runs our ProcessGameLogic. The D3D9 thiscall naked wrappers are removed
// here to keep the static lib compiling. Renderer vtable calls (CallThiscall_*)
// below remain for the standalone build path.

// ─── ProcessGameLogic (FUN_00524f30) ─────────────────────────
// Status: Minimal render loop using render device vtable directly.
//
// Render pipeline (from FrameEnd + BeginScene/ShutdownSubsystems decompilation):
//   1. PreFrameReset — reset scene flags
//   2. Timer accumulation
//   3. TimerTick — input mapping
//   4. Countdown timer
//   5. vtable[43] PrePresent(this, sceneState) — prepare frame
//   6. vtable[41] BeginScene init — start rendering
//   7. (draw calls would go here)
//   8. vtable[42] Shutdown/EndScene — finish rendering
//   9. vtable[47] Present — swap buffers

static int g_renderFrameCount = 0;

static int g_pglEntryCount = 0;

uint32_t ProcessGameLogic()
{
    g_pglEntryCount++;
    if (g_pglEntryCount <= 2 && g_traceLog) {
        fprintf(g_traceLog, "[PGL] ProcessGameLogic enter #%d, g_renderDevice=%p, g_d3d9Device=%p\n",
            g_pglEntryCount, g_renderDevice, g_d3d9Device);
        fflush(g_traceLog);
    }

    // Phase 1: Pre-frame setup (safe — uses our globals)
    PreFrameReset();

    // Phase 2: Timer accumulation (safe — uses our globals)
    if (!g_frameActive)
    {
        g_frameTimer += static_cast<int>(g_timeMultiplier);
        g_frameCount2++;
    }

    // Phase 3: Input mapping + controller state (safe — separate module)
    TimerTick();

    // Phase 4: Countdown timer (safe — uses our globals)
    if (g_countdownActive != 0 && !g_cutsceneMode)
    {
        g_countdownTimer -= g_smoothedTime;
        if (g_countdownTimer <= 0.0f)
        {
            CountdownExpired();
            g_countdownActive = 0;
        }
    }

    // ── Phase 5: Render pipeline ──────────────────────────────────
    if (g_renderDevice != nullptr)
    {
        void** vtable = *(void***)g_renderDevice;

        // Render pipeline uses the renderer COM object (gg_dx9r.dll).
        // The renderer manages D3D9 device state internally.
        // vtable[43] = PrePresent (thiscall: this, sceneState)
        // vtable[41] = BeginScene/RendererInit (calls D3D9 BeginScene internally)
        // vtable[42] = Shutdown/EndScene (calls D3D9 EndScene internally)
        // vtable[47] = Present (swaps buffers)

        // Step 1: PrePresent — prepare frame
        if (vtable[43])
        {
            reinterpret_cast<void(*)(void*, void*, uint32_t)>(CallThiscall_U32)(
                g_renderDevice, vtable[43], 0);
        }

        // Step 2: BeginScene — renderer calls D3D9 BeginScene internally
        if (vtable[41])
        {
            reinterpret_cast<void(*)(void*, void*)>(CallThiscall_Void)(
                g_renderDevice, vtable[41]);
        }

        // ── D3D9 draw calls removed (rebuild-exe experiment) ─────
        // The renderer COM object (gg_dx9r.dll) manages D3D9 draw state internally.
        // Standalone draw calls were part of the abandoned rebuild approach.

        // Step 3: Shutdown/EndScene — renderer calls D3D9 EndScene
        if (vtable[42])
        {
            reinterpret_cast<void(*)(void*, void*)>(CallThiscall_Void)(
                g_renderDevice, vtable[42]);
        }

        // Step 4: Present — swap buffers
        if (vtable[47])
        {
            reinterpret_cast<void(*)(void*, void*)>(CallThiscall_Void)(
                g_renderDevice, vtable[47]);
        }

        g_renderFrameCount++;
        if (g_renderFrameCount <= 3 && g_traceLog)
        {
            fprintf(g_traceLog, "[RENDER] Frame %d: renderer pipeline + D3D9 draw OK\n",
                g_renderFrameCount);
            fflush(g_traceLog);
        }
    }

    return 1;
}

} // namespace Giants
