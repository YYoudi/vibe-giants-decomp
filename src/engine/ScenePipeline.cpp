// Giants Engine - Scene Pipeline Functions Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Batch-reversed sub-functions of ProcessGameLogic (FUN_00524f30).

#include "ScenePipeline.h"
#include "GameLogic.h"
#include "Camera.h"
#include "GiantsTypes.h"
#include <windows.h>

namespace Giants {

// --- runtime state globals (were *reinterpret_cast derefs; engine-populated) ---
static char g_state_006ff367 = 0;  // was @0x0X006FF367
static char g_state_0068578c = 0;  // was @0x0X0068578C
static float g_state_00727e38 = 0.0f;  // was @0x0X00727E38

// ─── External data references used by EndSceneDirectional ─────
static char DAT_00702b5e = 0;
static char DAT_00702b61 = 0;

// ─── External data references used by FrameEnd ────────────────
static int      DAT_00682204 = -1;     // Module index (-1 = none)
static int      DAT_00702a5c = 0;      // Frame skip flag
static void**   DAT_00747b74 = nullptr; // Module COM object array
static void**   DAT_00747b64 = nullptr; // Module function pointer array
static uint32_t g_frameCounter = 0;    // DAT_0074bbb8 — RenderDoc frame counter

// ─── PreFrameReset (FUN_00565480) — PASS ──────────────────────

static bool g_sceneInitFlag = false;        // DAT_00749734
static uint32_t g_sceneStatusHandle = 0;    // DAT_006850a8

void PreFrameReset()
{
    g_sceneInitFlag = false;
    g_sceneStatusHandle = 0xFFFFFFFF;
}

// ─── BeginScene (FUN_004f7e60) — PASS ─────────────────────────
// Reference-counted: first call initializes all render stages.

static int g_sceneRefCount = 0;             // DAT_00748700

// Render subsystem objects (COM-like, vtable-based)
static void* g_subsystem00 = nullptr;       // DAT_00702700
static void* g_subsystem18 = nullptr;       // DAT_00702718
static void* g_subsystem1c = nullptr;       // DAT_0070271c
static void* g_subsystem20 = nullptr;       // DAT_00702720
static void* g_subsystem24 = nullptr;       // DAT_00702724
static void* g_subsystem28 = nullptr;       // DAT_00702728
static void* g_subsystem2c = nullptr;       // DAT_0070272c
static void* g_subsystem30 = nullptr;       // DAT_00702730
static void* g_subsystem34 = nullptr;       // DAT_00702734
static void* g_subsystem38 = nullptr;       // DAT_00702738

bool BeginScene()
{
    int nextCount = g_sceneRefCount + 1;
    bool wasZero = (g_sceneRefCount == 0);
    g_sceneRefCount = nextCount;

    if (wasZero)
    {
        // Initialize all render stages via vtable dispatch
        // vtable[0xa4/4] on subsystem00 — main renderer init
        (*reinterpret_cast<void(**)()>(
            *reinterpret_cast<uintptr_t*>(g_subsystem00) + 0xa4))();

        // vtable[4] on each subsystem — stage setup (stage_id, param)
        using StageSetup = void(*)(void*, int, int);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem18) + 4))(g_subsystem18, 1, 0);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem24) + 4))(g_subsystem24, 2, 0);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem1c) + 4))(g_subsystem1c, 1, 4);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem2c) + 4))(g_subsystem2c, 2, 4);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem28) + 4))(g_subsystem28, 2, 2);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem20) + 4))(g_subsystem20, 1, 5);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem30) + 4))(g_subsystem30, 0, 5);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem34) + 4))(g_subsystem34, 0, 5);
        (*reinterpret_cast<StageSetup*>(
            *reinterpret_cast<uintptr_t*>(g_subsystem38) + 4))(g_subsystem38, 0, 5);
    }

    return true;
}

// ─── ShutdownSubsystems (FUN_004f7f10) — PASS ─────────────────
// Reference-counted: when counter reaches 0, shuts down all stages.

uint32_t ShutdownSubsystems(uint32_t param)
{
    g_sceneRefCount--;

    if (g_sceneRefCount == 0)
    {
        // vtable[1] on each subsystem — shutdown/release
        using VMethod1 = void(*)(void*, uint32_t);
        using VMethod0 = void(*)(void*);

        (*reinterpret_cast<VMethod1*>(
            *reinterpret_cast<void***>(g_subsystem30)[1]))(g_subsystem30, param);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem28)[1]))(g_subsystem28);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem2c)[1]))(g_subsystem2c);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem18)[1]))(g_subsystem18);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem24)[1]))(g_subsystem24);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem1c)[1]))(g_subsystem1c);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem20)[1]))(g_subsystem20);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem34)[1]))(g_subsystem34);
        (*reinterpret_cast<VMethod0*>(
            *reinterpret_cast<void***>(g_subsystem38)[1]))(g_subsystem38);

        // vtable[0xa8/4] = index 42 on subsystem00 — final renderer shutdown
        (*reinterpret_cast<void(**)()>(
            reinterpret_cast<void**>(*reinterpret_cast<void***>(g_subsystem00))[0xa8 / 4]))();
    }

    return 1;
}

// ─── EndSceneDirectional (FUN_00524c10) — PASS ────────────────
// Multi-pass directional rendering: 6 light directions.
// For each pass: compute light vector, render objects, draw to screen.

void EndSceneDirectional()
{
    // Guard: skip if no scene loaded (prevents crash on zeroed state)
    if (g_sceneReady == 0) return;

    // Light direction table: 6 directions with different vector components
    // LightDir defined in GiantsTypes.h (7 floats, 28 bytes)

    int iVar2 = reinterpret_cast<int>(g_sceneReady);

    // Check render conditions
    if ((((DAT_00702b5e == '\0') || (DAT_00702b61 != '\0')) && (g_sceneReady != 0)) &&
        ((~*reinterpret_cast<uint32_t*>(
            reinterpret_cast<int>(g_sceneReady) + 0x4efc) & 0x4000) != 0))
    {
        LightDir light;
        light.w = 800.0f;    // max distance / range
        float* fLight = reinterpret_cast<float*>(&light);

        int iVar3 = 1;       // first-iteration flag
        int iVar1 = reinterpret_cast<int>(g_sceneReady) + 0x4edc;
        g_state_006ff367 = 1;  // rendering flag

        for (int iVar4 = 0; iVar4 < 6; iVar4++)
        {
            // Reset light vector
            fLight[3] = 0.0f;
            fLight[2] = 0.0f;
            fLight[6] = 0.0f;
            fLight[5] = 0.0f;
            fLight[4] = 0.0f;

            // Direction-specific setup
            switch (iVar4) {
            default: fLight[4] = -1.0f; break;
            case 1:  fLight[4] =  1.0f; break;
            case 2:  fLight[5] =  1.0f; fLight[3] = -1.0f; break;
            case 3:  fLight[5] = -1.0f; fLight[3] =  1.0f; break;
            case 4:  fLight[6] =  1.0f; break;
            case 5:  fLight[6] = -1.0f; break;
            }
            fLight[2] = 1.0f;

            // Only render if object exists and has flag 0x80
            if ((iVar1 != 0) &&
                (*reinterpret_cast<uint8_t*>(iVar2 + 0x4efc) & 0x80) != 0)
            {
                // vtable[0xa0/4] = GetNextRenderObject
                if (iVar3 != 0)
                {
                    iVar3 = reinterpret_cast<int(*)(int, int)>(
                        **reinterpret_cast<void(***)(void*)>(
                            *reinterpret_cast<void**>(g_rendererObj) + 0xa0))(iVar1, iVar4);
                }

                // vtable[0xd0/4] = RenderObjectWithLight
                reinterpret_cast<void(*)(int, void*, void*)>(
                    **reinterpret_cast<void(***)(void*)>(
                        *reinterpret_cast<void**>(g_rendererObj) + 0xd0))(
                    iVar1, &light, &light);

                // Update camera from render result
                // TODO: extract from struct offsets

                // vtable[0x44/4] = SetCameraPosition
                reinterpret_cast<void(*)(void*)>(
                    **reinterpret_cast<void(***)(void*)>(
                        *reinterpret_cast<void**>(g_rendererObj) + 0x44))(&g_camX);

                g_state_0068578c = 1;

                RenderPassHelper();           // FUN_005f9c10 — SetupViewportMatrix stub
                PostRenderPass();             // FUN_005fa310 — CopyAndObfuscateMatrix stub
                SetupProjection();            // FUN_005f9d00 — real impl in Camera.cpp

                // vtable[0x2c/4] = SetRenderPass
                reinterpret_cast<void(*)()>(
                    **reinterpret_cast<void(***)(void*)>(
                        *reinterpret_cast<void**>(g_rendererObj) + 0x2c))();

                // vtable[0xb4/4] = DrawFullscreen
                reinterpret_cast<void(*)(int, int, float, float, int)>(
                    **reinterpret_cast<void(***)(void*)>(
                        *reinterpret_cast<void**>(g_rendererObj) + 0xb4))(0, 0, 0.0f, 0.0f, 0);

                // vtable[0x24/4] = Present
                reinterpret_cast<void(*)()>(
                    **reinterpret_cast<void(***)(void*)>(
                        *reinterpret_cast<void**>(g_rendererObj) + 0x24))();

                // Stage cleanup
                BeginScene();                 // FUN_004f7e60
                SetupProjection();            // FUN_005f9d00
                ShutdownSubsystems(0);        // FUN_004f7f10
            }
        }

        // Final present
        if (iVar3 == 0)
        {
            reinterpret_cast<void(*)(int, int, float, float, int)>(
                **reinterpret_cast<void(***)(void*)>(
                    *reinterpret_cast<void**>(g_rendererObj) + 0xb0))(0, 0, 0.0f, 0.0f, 0);
        }
        else
        {
            reinterpret_cast<void(*)(int, int, float, float)>(
                **reinterpret_cast<void(***)(void*)>(
                    *reinterpret_cast<void**>(g_rendererObj) + 0xb8))(0, 0, 0.0f, 0.0f);
        }

        // Reset iterator
        reinterpret_cast<int(*)(int, int)>(
            **reinterpret_cast<void(***)(void*)>(
                *reinterpret_cast<void**>(g_rendererObj) + 0xa0))(0, 0);

        g_state_006ff367 = 0;

        // Mark scene as rendered (set bit 0x4000)
        *reinterpret_cast<uint32_t*>(
            reinterpret_cast<int>(g_sceneReady) + 0x4efc) |= 0x4000;
    }
}

// ─── ProcessSceneTransition (FUN_005539d0) — FAIL (usable ~75%) ────
// Scene transition state machine with fade, loading, and callbacks.
// Called from ProcessGameLogic each frame. Returns 1 if active, 0 if idle.
// State machine (switch on level state):
//   1 = loading screen, 2 = level load, 3 = network reset + player setup,
//   4 = default player load, default = set large timer

// Transition state globals
static int      DAT_0074892c = 0;     // Transition active flag
static int      DAT_007488dc = 0;     // Pending transition
static int      DAT_00748900 = 0;     // Scene busy flag
static int      DAT_007488f8 = 0;     // Loading flag
static int      DAT_007495ac = 0;     // Transition initialized
static float    DAT_007495b4 = 0.0f;  // Fade timer (counts down)
static int      DAT_00748929 = 0;     // Fade active flag
static float    DAT_00748908 = 0.0f;  // Fade duration threshold
static float    DAT_007488b0 = 0.0f;  // Fade counter
static int      DAT_007495b0 = 0;     // Fade direction (0=out, 1=in)
static int      DAT_007495a8 = 0;     // Pre-load flag
static int      DAT_007494a0 = 0;     // Render target ID
static int      DAT_0074893c = 0;     // Scene load result
static uint32_t DAT_006ff960 = 0;     // Game state (6 = in-game)

int ProcessSceneTransition()
{
    // Guard: skip during cutscene or multiplayer
    if (g_cutsceneMode || DAT_006ff960 == 6)
        return 0;

    // Check transition conditions: no pending transitions, scene exists, not busy
    if (DAT_0074892c == 0 && DAT_007488dc == 0 &&
        reinterpret_cast<int>(g_sceneReady) != 0 &&
        DAT_00748900 == 0 && DAT_007488f8 == 0)
    {
        if (DAT_007495ac == 0)
            DAT_007495ac = 1;

        int sceneObj = reinterpret_cast<int>(g_sceneReady);
        int levelProgress = *reinterpret_cast<int*>(sceneObj + 0x4aa0);
        int levelTarget = *reinterpret_cast<int*>(sceneObj + 0x4a9c);

        if (levelProgress > levelTarget)
        {
            int levelIndex = *reinterpret_cast<int*>(sceneObj + 0x4a98);
            if (levelIndex > 0)
            {
                int levelState = *reinterpret_cast<int*>(
                    sceneObj + 0x4558 + levelIndex * 0x30);
                if (levelState == 2)
                {
                    // Fade-out transition
                    DAT_007495b4 -= g_state_00727e38;
                    DAT_00748929 = 1;
                    if (DAT_007495b4 > 0.0f)
                    {
                        // Still fading
                        DAT_007495b0 = 1;
                        return 0;
                    }
                    DAT_007495b0 = 0;
                }
            }

            DAT_007495a8 = 0;
            DAT_007495ac = 0;

            // State machine dispatch
            int levelIdx = *reinterpret_cast<int*>(sceneObj + 0x4a98);
            if (levelIdx < 0x1B)
            {
                int state = *reinterpret_cast<int*>(levelIdx * 0x30 + 0x4588 + sceneObj);
                switch (state)
                {
                case 1:  // Loading screen
                    *reinterpret_cast<int*>(sceneObj + 0x4a98) = levelIdx + 1;
                    return 1;
                case 2:  // Level load
                    return 1;
                case 3:  // Network reset + player setup
                    *reinterpret_cast<uint32_t*>(sceneObj + 0x4a98) = 0x1B;
                    return 1;
                case 4:  // Default player
                    *reinterpret_cast<int*>(sceneObj + 0x4a98) = levelIdx + 1;
                    break;
                default:
                    *reinterpret_cast<uint32_t*>(sceneObj + 0x4aa0) = 9999999;
                    *reinterpret_cast<uint32_t*>(sceneObj + 0x4a9c) = 1;
                    break;
                }
            }
        }
    }
    return 0;
}

// ─── FrameEnd (FUN_005253b0) — FAIL (usable ~85%) ──────────────────
// Final frame operations: begin/end scene, FPS limiter, RenderDoc capture, present.
// Called from ProcessGameLogic at the end of every frame.

// FPS limiter globals
static int64_t  g_qpcFrequency   = 0;   // DAT_00725e90/94 — QueryPerformanceFrequency result
static int64_t  g_lastFrameTime   = -1;  // DAT_0074eef0/efc — last frame timestamp
static int      g_fpsLimit        = 0;   // DAT_00702b78 — target FPS (0 = unlimited)
extern uint32_t g_frameCounter;           // DAT_0074bbb8 — RenderDoc frame counter

void FrameEnd()
{
    // Guard: skip if no renderer object (prevents crash on zeroed state)
    if (g_rendererObj == nullptr) return;

    // ── Phase 1: Pre-present renderer call ──
    // Get scene object state value (0 if no scene)
    uint32_t sceneState = 0;
    if (g_sceneReady != 0 && g_renderMode != 0 && DAT_00682204 == -1 && DAT_00702a5c == 0)
    {
        sceneState = *reinterpret_cast<uint32_t*>(reinterpret_cast<int>(g_sceneReady) + 0x1b4);
    }

    // vtable[0xac] — PrePresent or BeginFrame
    ((void(__thiscall*)(void*, uint32_t))(
        *reinterpret_cast<void***>(g_rendererObj))[0xac / 4])(g_rendererObj, sceneState);

    // ── Phase 2: Scene begin/end for frame stats ──
    BeginScene();

    // ── Phase 3: Debug overlay / per-module rendering ──
    if (DAT_00682204 == -1)
    {
        // Default module rendering
        // FUN_00526be0 — render debug overlay or stats
    }
    else
    {
        // Module-specific rendering via function pointer table
        // DAT_00747b64 = function pointer array, DAT_00747b74 = COM object array
        void* moduleObj = reinterpret_cast<void**>(DAT_00747b74)[DAT_00682204 * 6];
        if (moduleObj == nullptr)
        {
            // Direct function call
            reinterpret_cast<void(*)()>(reinterpret_cast<void**>(DAT_00747b64)[DAT_00682204 * 6])();
        }
        else
        {
            // COM vtable call: vtable[2]
            reinterpret_cast<void(*)()>(
                (*reinterpret_cast<void***>(moduleObj))[2])();
        }
    }

    // FUN_005655e0 — update frame statistics
    // FUN_00526be0 and FUN_005655e0 are frame-stat/debug overlays

    ShutdownSubsystems(0);

    // ── Phase 4: FPS limiter (QueryPerformanceCounter + Sleep) ──
    if (g_qpcFrequency == 0)
    {
        QueryPerformanceFrequency(reinterpret_cast<LARGE_INTEGER*>(&g_qpcFrequency));
    }

    int64_t currentTime;
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentTime));

    // Convert to milliseconds: currentTime * 1000 / frequency
    int64_t freqMs = g_qpcFrequency / 1000;
    int64_t currentMs = currentTime / freqMs;

    // Thread-local frame timing check
    if (g_lastFrameTime == -1)
    {
        g_lastFrameTime = currentMs;
    }

    // FPS cap: if target frame time not elapsed, Sleep the difference
    if (g_cutsceneMode == false && g_fpsLimit > 0)
    {
        int targetMs = 1000 / g_fpsLimit;
        int64_t elapsed = currentMs - g_lastFrameTime;
        if (elapsed < targetMs)
        {
            Sleep(static_cast<uint32_t>(targetMs - elapsed));
        }
    }

    // Update timestamp after potential Sleep
    QueryPerformanceCounter(reinterpret_cast<LARGE_INTEGER*>(&currentTime));
    g_lastFrameTime = currentTime / (g_qpcFrequency / 1000);

    // ── Phase 5: RenderDoc F12 capture trigger ──
    if (g_frameCounter != 0)
    {
        uint16_t keyState = GetAsyncKeyState(0x7b);  // VK_F12
        if ((keyState & 1) != 0 && g_frameCounter != 0)
        {
            // vtable[0x3c] on RenderDoc capture object
            reinterpret_cast<void(*)()>(
                *reinterpret_cast<void(**)(void)>(g_frameCounter + 0x3c))();
            // FUN_00461f00 — fmt::format debug log
        }
    }

    // ── Phase 6: Present (vtable[0xbc]) ──
    reinterpret_cast<void(*)()>(
        (*reinterpret_cast<void***>(g_rendererObj))[0xbc / 4])();
}

// ─── Stubs for remaining callees ──────────────────────────────

// ─── Stubs — signature mismatch with real implementations ────────
void RenderPassHelper()           { /* FUN_005f9c10 — SetupViewportMatrix takes params */ }
void PostRenderPass()             { /* FUN_005fa310 — CopyAndObfuscateMatrix takes params */ }
void ExtractRenderStats(void*)    { /* FUN_0063e7f0 — CopyMatrix4x4 stub */ }
int NetworkStateCheck()           { return 0; /* FUN_004e8dd0 — stub */ }
void SceneBegin()                 { /* FUN_00522310 — stub */ }
void CountdownExpired()           { /* FUN_00490c50 — stub */ }
void FrameEndNetworkTick()        { /* FUN_004d0dd0 — stub */ }

// ─── BuildViewMatrix (FUN_005f9eb0) — PASS ─────────────────────
// Constructs 4x4 view matrix from eye, direction, and up vectors.
// Cross products compute right/up/forward, then normalized.
// Z column elements are XOR-obfuscated with key DAT_0066c580.

static uint32_t g_depthXorKey = 0;                      // DAT_0066c580
static float g_viewMatrix[16] = {0};                    // DAT_00685790
static const float ONE_POINT_ZERO = 1.0f;               // DAT_0066bf2c

void BuildViewMatrix(const Vector3& eye, const Vector3& dir, const Vector3& up)
{
    // Normalize direction vector
    float dirLenSq = dir.x * dir.x + dir.y * dir.y + dir.z * dir.z;
    // FUN_0042bee0 — likely sqrt or assert on dirLenSq
    float invDirLen = ONE_POINT_ZERO / dirLenSq;
    float ndx = dir.x * invDirLen;
    float ndy = dir.y * invDirLen;
    float ndz = dir.z * invDirLen;

    // Right = up × dir (cross product)
    float rx = up.y * ndz - up.z * ndy;
    float ry = up.z * ndx - up.x * ndz;
    float rz = up.x * ndy - up.y * ndx;

    // True up = dir × right (cross product)
    float ux = rz * ndy - ry * ndz;
    float uy = rx * ndz - rz * ndx;
    float uz = ry * ndx - rx * ndy;

    // Normalize right
    float rLenSq = ry * ry + rx * rx + rz * rz;
    float invRLen = ONE_POINT_ZERO / rLenSq;

    // Normalize up
    float uLenSq = ux * ux + uy * uy + uz * uz;
    float invULen = ONE_POINT_ZERO / uLenSq;

    // Build 4x4 view matrix — interleaved packed format (NOT standard row/col-major)
    // Re-derived from Ghidra global offsets: DAT_00685790 + N*4
    // Layout: [right.x, up.x, right.y, up.y, right.z, dir.x, dir.y, up.z, dir.z, 0, 0, 0, tx, ty, tz, 1.0]
    // XOR obfuscation applied to depth-related elements

    g_viewMatrix[0]  = (uint32_t)(invRLen * rx) ^ g_depthXorKey;   // 0x90: right.x (obfuscated)
    g_viewMatrix[1]  = invULen * ux;                                // 0x94: up.x
    g_viewMatrix[2]  = (uint32_t)(invRLen * ry) ^ g_depthXorKey;   // 0x98: right.y (obfuscated)
    g_viewMatrix[3]  = invULen * uy;                                // 0x9c: up.y
    g_viewMatrix[4]  = (uint32_t)(invRLen * rz) ^ g_depthXorKey;   // 0xa0: right.z (obfuscated)
    g_viewMatrix[5]  = ndx;                                         // 0xa4: dir.x (invDirLen*dir.x)
    g_viewMatrix[6]  = ndy;                                         // 0xa8: dir.y
    g_viewMatrix[7]  = invULen * uz;                                // 0xac: up.z
    g_viewMatrix[8]  = ndz;                                         // 0xb0: dir.z
    g_viewMatrix[9]  = 0;                                           // 0xb4: pad
    g_viewMatrix[10] = 0;                                           // 0xb8: pad
    g_viewMatrix[11] = 0;                                           // 0xbc: pad
    g_viewMatrix[12] = invRLen * rx * eye.x + invRLen * ry * eye.y + invRLen * rz * eye.z;  // 0xc0: tx (right·eye)
    g_viewMatrix[13] = (uint32_t)(invULen * ux * eye.x + invULen * uy * eye.y + invULen * uz * eye.z) ^ g_depthXorKey;  // 0xc4: ty (up·eye, obfuscated)
    g_viewMatrix[14] = (uint32_t)(ndx * eye.x + ndy * eye.y + ndz * eye.z) ^ g_depthXorKey;  // 0xc8: tz (dir·eye, obfuscated)
    g_viewMatrix[15] = 0x3f800000;                                  // 0xcc: 1.0f
}

// ─── SetWorldTransform (FUN_005fa1a0) — PASS ───────────────────
// Applies world/view transform to renderer. Deobfuscates scale from param[0xd].
// Writes 3x4 matrix + 3 translation components to g_worldTransform buffer.

// WorldTransform defined in GiantsTypes.h (12 floats, 48 bytes)

WorldTransform g_worldTransform = {};            // DAT_0074bb60 (extern in GiantsTypes.h)
void* g_renderDevice = nullptr;                  // DAT_00702700 (extern in GiantsTypes.h)
void* g_d3d9Device  = nullptr;                   // IDirect3DDevice9* (found by scanner in EngineInit)

void SetWorldTransform(const float* m)
{
    // Deobfuscate scale from m[0xd]
    float scale = (float)((uint32_t)m[0xd] ^ g_depthXorKey);

    // Compute translation: (scale * axis1 - m[0xc] * axis2 - m[0xe] * axis3) + pos
    g_worldTransform.tx = (scale * m[1] - m[0] * m[0xc] - m[0xe] * m[2]) + m[3];
    g_worldTransform.ty = (scale * m[5] - m[0xc] * m[4] - m[0xe] * m[6]) + m[7];
    g_worldTransform.tz = (scale * m[9] - m[0xc] * m[8] - m[0xe] * m[10]) + m[11];

    // Renderer vtable calls (SetViewTransform + SetProjection)
    // vtable[0x28] — likely SetTransform or SetViewMatrix
    auto vtable = *(void***)g_renderDevice;
    ((void(__thiscall*)(void*))vtable[0x28 / 4])(g_renderDevice);

    // Copy rotation/scale columns directly from input matrix
    g_worldTransform.m00 = m[0];
    g_worldTransform.m01 = m[4];
    g_worldTransform.m02 = m[8];
    g_worldTransform.m10 = m[1];
    g_worldTransform.m11 = m[5];
    g_worldTransform.m12 = m[9];
    g_worldTransform.m20 = m[2];
    g_worldTransform.m21 = m[6];
    g_worldTransform.m22 = m[10];

    // vtable[0x30] — likely SetProjection or ApplyTransform
    ((void(__thiscall*)(void*))vtable[0x30 / 4])(g_renderDevice);
}

} // namespace Giants
