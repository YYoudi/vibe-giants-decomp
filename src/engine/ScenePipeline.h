// Giants Engine - Scene Pipeline Functions
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Sub-functions of ProcessGameLogic (FUN_00524f30), reversed in batch.

#pragma once

#include <cstdint>
#include "../../stubs/stubs.h"

namespace Giants {

// ─── Pre-Frame Reset (FUN_00565480) — PASS ────────────────────
// Resets initialization flag and status handle.
// Two-line function: g_Initialized = false; g_StatusHandle = 0xFFFFFFFF;
void PreFrameReset();              // FUN_00565480

// ─── BeginScene (FUN_004f7e60) — PASS ─────────────────────────
// Reference-counted scene begin. On first call (counter 0→1), initializes
// all 9 render subsystem stages via vtable dispatch on g_subsystem objects.
// @return true (always)
bool BeginScene();                 // FUN_004f7e60

// ─── ShutdownSubsystems (FUN_004f7f10) — PASS ─────────────────
// Reference-counted scene end. When counter reaches 0, shuts down all
// 9 render subsystems via vtable[1] calls.
// @return 1 (always)
uint32_t ShutdownSubsystems(uint32_t param);  // FUN_004f7f10

// ─── EndScene / Directional Render (FUN_00524c10) — PASS ──────
// Multi-pass directional rendering (6 light/shadow passes).
// For each direction: sets light vector, renders objects, calls vtable pipeline.
// Only runs if scene flag bit 0x4000 is NOT set and bit 0x80 IS set.
void EndSceneDirectional();        // FUN_00524c10

// ─── Scene Transition System (FUN_005539d0) — FAIL (usable) ───
// Handles scene transitions: fade in/out, loading callbacks, state machine.
// Uses a sub-state machine (states 0-4) for different transition types.
// @return 0 if no transition, 1 if transition started/active
int ProcessSceneTransition();      // FUN_005539d0

// ─── Frame End (FUN_005253b0) — FAIL (usable) ─────────────────
// Final frame operations: render dispatch, FPS limiter (QueryPerformanceCounter),
// RenderDoc F12 capture trigger, present call.
// Uses __alldiv for 64-bit timing math.
void FrameEnd();                   // FUN_005253b0

// ─── Scene Begin (FUN_00522310) ────────────────────────────────
// Stub — to be reversed.
void SceneBegin();                 // FUN_00522310

// TimerTick — real implementation in TimerTick.cpp (FUN_004ad640)

// ─── Countdown Expired (FUN_00490c50) ──────────────────────────
// Stub — to be reversed.
void CountdownExpired();           // FUN_00490c50

// ─── Frame End / Network Tick (FUN_004d0dd0) ──────────────────
// Stub — to be reversed.
void FrameEndNetworkTick();        // FUN_004d0dd0

// ─── Remaining Stubs (signature mismatch with real impls) ──────
void RenderPassHelper();           // FUN_005f9c10 — SetupViewportMatrix (needs params)
void PostRenderPass();             // FUN_005fa310 — CopyAndObfuscateMatrix (needs params)
void ExtractRenderStats(void*);    // FUN_0063e7f0 — CopyMatrix4x4
int NetworkStateCheck();           // FUN_004e8dd0

// ─── BuildViewMatrix (FUN_005f9eb0) — PASS ─────────────────────
// Constructs a 4x4 view matrix from eye position, direction, and up vector.
// Uses cross products + normalization. XOR-obfuscates depth/Z column with
// key DAT_0066c580. Output stored in g_viewMatrix (DAT_00685790).
void BuildViewMatrix(const Vector3& eye, const Vector3& dir, const Vector3& up);  // FUN_005f9eb0

// ─── SetWorldTransform (FUN_005fa1a0) — PASS ───────────────────
// Applies a 4x3 world/view transform to the renderer via vtable calls.
// Deobfuscates the scale parameter from param[0xd] via XOR with DAT_0066c580.
// Writes to g_worldTransform (DAT_0074bb60) then calls vtable[0x28] and [0x30].
void SetWorldTransform(const float* matrix);  // FUN_005fa1a0

} // namespace Giants
