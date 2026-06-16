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
#include <cstdlib>
#include <d3d9.h>

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

    // INIT-BEHAVIOR RECONSTRUCTION MODE: the renderer-dependent phases below
    // (camera/projection/world-transform/light passes → all vtable dispatch into
    // gg_dx9r.dll) crash deep in the renderer because the engine-context protocol
    // isn't fully driven yet. Per the project focus (init BEHAVIOR, not rendering),
    // these phases are skipped so the loop runs continuously exercising the
    // behavioral state (timer, input, FLICK cinematic, scene-transition FSM,
    // countdown). They're re-enabled when the renderer protocol is reconstructed.
#if 0
    // Phase 3b: Camera update (FUN_0049a040 — camera selection + projection)
    extern void UpdateActiveCamera();
    extern void AnimateCameraPath();
    UpdateActiveCamera();
    AnimateCameraPath();
    extern void SetupProjection(int);
    SetupProjection(0);

    // Phase 3d: World transform — set to identity (no scene loaded yet)
    extern void SetWorldTransform(const float*);
    static const float s_identity[16] = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1};
    SetWorldTransform(s_identity);

    // Phase 3e: Light direction render (6-pass light setup)
    extern void EndSceneDirectional();
    EndSceneDirectional();
#endif

    // Phase 3f: Scene transition state machine (advances scene load → active).
    // SAFE in init-behavior mode: it guards on g_sceneReady != 0 (null here —
    // no scene object built), so it no-ops. Behavioral, not renderer — kept active.
    extern int ProcessSceneTransition();
    ProcessSceneTransition();

    // Phase 3g: FLICK cinematic interpreter — drives camera + logo animation.
    // In the original, this fires every frame during the menu (4503 calls observed).
    extern uint32_t ProcessFlickCommands();
    ProcessFlickCommands();
    if (g_traceLog && g_pglEntryCount <= 2) { fprintf(g_traceLog, "[PGL] Phase3g FLICK OK\n"); fflush(g_traceLog); }

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
    // The full render cycle is OWNED by FrameEnd (FUN_005253b0), matching the
    // original exe structure: FrameEnd does PrePresent(vtable[43]) →
    // BeginScene()→vtable[41] → overlay → ShutdownSubsystems()→vtable[42] →
    // FPS limiter → Present(vtable[47]). All vtable calls use the CallThiscall
    // wrappers (ECX=this). Phase 5's old inline render is removed (it double-
    // rendered with FrameEnd and used bare calls that left ECX garbage).
    // Phase 5 (renderer render cycle) is deferred in init-behavior mode — FrameEnd
    // drives the full PrePresent→BeginScene→Present pipeline via renderer vtable
    // calls that crash without the complete engine-context protocol. Skipped so the
    // loop runs continuously. Re-enabled when the renderer protocol is reconstructed.
#if 0
    if (g_renderDevice != nullptr)
    {
        extern void FrameEnd();
        FrameEnd();

        g_renderFrameCount++;
        if (g_renderFrameCount <= 3 && g_traceLog)
        {
            fprintf(g_traceLog, "[RENDER] Frame %d: FrameEnd render cycle OK\n",
                g_renderFrameCount);
            fflush(g_traceLog);
        }
    }
#endif

    // ── Direct D3D9 present (bypass the renderer protocol) ──────────
    // FINDING (tested 2026-06-15): the raw IDirect3DDevice9 (g_d3d9Device, found
    // by the EngineInit scanner) is OWNED by the renderer (gg_dx9r.dll), which
    // holds the swapchain. Calling IDirect3DDevice9::Present directly HANGS the
    // loop (1 frame in 6s) — Present deadlocks against the renderer's swapchain
    // ownership. Clear alone is fine, but Present cannot be driven externally.
    // CONCLUSION: direct D3D9 manipulation of the renderer's device is not viable.
    // Visible output requires either (B) a stub renderer that OWNS its own device,
    // or (A) driving the real renderer's full protocol. Direct device reuse blocked.
    // extern void* g_d3d9Device;
    // if (g_d3d9Device) { IDirect3DDevice9* dev=(IDirect3DDevice9*)g_d3d9Device;
    //   dev->Clear(0,nullptr,D3DCLEAR_TARGET,D3DCOLOR_XRGB(20,40,100),1.0f,0);
    //   dev->Present(nullptr,nullptr,g_hWnd,nullptr); }  // HANGS — disabled

    // ── Stub-renderer render path (DIAGNOSTIC — stub only) ───────────
    // With the stub renderer (gg_dx9r_stub.dll) deployed as gg_dx9r.dll, the
    // device vtable[43/44/45/46/47] are stub-invented D3D9-backed methods. With
    // the REAL gg_dx9r.dll those slots mean different things → crash. So this
    // path runs ONLY when the stub is active (env STUB_RENDER=1). The real
    // renderer renders via FrameEnd (re-enabled separately).
    static bool s_stubRender = (getenv("STUB_RENDER") != nullptr);
    if (s_stubRender && g_renderDevice != nullptr)
    {
        void** vtable = *reinterpret_cast<void***>(g_renderDevice);
        typedef void (__attribute__((thiscall)) *PFN_This)(void* self);
        typedef void (__attribute__((thiscall)) *PFN_Str)(void* self, const char* str);
        typedef void (__attribute__((thiscall)) *PFN_XY)(void* self, int x, int y);
        if (vtable[43]) reinterpret_cast<PFN_This>(vtable[43])(g_renderDevice);  // Clear
        // Draw the real intro_island terrain (vtable[46]) — terrain_heights.bin.
        if (vtable[46]) reinterpret_cast<PFN_This>(vtable[46])(g_renderDevice);
        // Draw a multi-line localized menu via the stub's text slot (vtable[44]).
        if (vtable[44]) {
            extern const char* GetLocalizedString(const char*);
            const char* yes = GetLocalizedString("ButtonYes");
            const char* no  = GetLocalizedString("ButtonNo");
            const char* q   = GetLocalizedString("MH_Quit");
            char buf[512];
            snprintf(buf, sizeof(buf),
                     "GIANTS: Citizen Kabuto — RECOMP (stub renderer)\n"
                     "frame=%d\n"
                     "ButtonYes = %s\nButtonNo = %s\nMH_Quit = %s\n"
                     "(localized from GTextEnglish.bin, 2081 entries)",
                     g_renderFrameCount, yes ? yes : "?", no ? no : "?", q ? q : "?");
            reinterpret_cast<PFN_Str>(vtable[44])(g_renderDevice, buf);
        }
        // Draw the cursor at the accumulated mouse position (vtable[45]).
        if (vtable[45]) {
            extern int32_t g_cursorX, g_cursorY;
            reinterpret_cast<PFN_XY>(vtable[45])(g_renderDevice, g_cursorX, g_cursorY);
        }
        if (vtable[47]) reinterpret_cast<PFN_This>(vtable[47])(g_renderDevice);  // Present
        g_renderFrameCount++;
        if (g_renderFrameCount <= 2 && g_traceLog) {
            fprintf(g_traceLog, "[STUB-RENDER] frame %d: Clear+DrawText+Present via stub\n",
                    g_renderFrameCount);
            fflush(g_traceLog);
        }
    }

    return 1;
}

} // namespace Giants
