// Giants Engine - Camera System
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Camera selection, projection setup, and keyframe animation.

#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateActiveCamera (FUN_0049a040) — FAIL (usable ~65%) ────
// Selects the active camera from render target list, computes view angles,
// calls SetupProjection. 8 callers, 12 callees.
void UpdateActiveCamera();    // FUN_0049a040

// ─── SetupProjection (FUN_005f9d00) — FAIL (usable ~70%) ────────
// Sets up the projection matrix with FOV, near/far planes, aspect ratio.
// Uses XOR depth obfuscation (DAT_0066c580). 25 callers, 2 callees.
void SetupProjection(int mode = 0);   // FUN_005f9d00

// ─── AnimateCameraPath (FUN_005f8480) — FAIL (usable ~60%) ─────
// Interpolates camera position/rotation along a keyframe path.
// Supports forward (flag 2) and reverse (flag 4) animation modes.
// Writes interpolated values to renderer at offset 0x1a0-0x1b0.
// 1 caller, 2 callees.
void AnimateCameraPath();     // FUN_005f8480

// ─── UpdateCameraView (FUN_0048f4a0) — PASS (usable ~70%) ────────
// Updates camera view parameters for a specific render target slot.
// Resolves entity from render target list, creates or reuses a camera
// object, computes FOV from entity data, and writes the result to the
// output float pointer.
//
// Performs:
//   1. Resolve entity from render target list (param_3 + 8 -> param_4 index)
//   2. Optional sub-entity lookup (param_5 index, max checked against 0x450)
//   3. Entity creation via FUN_00634e20 if not yet initialized
//   4. Scene state snapshot (memset + copy of 0x44-byte blocks)
//   5. FOV computation: FOV = GetEntityFOV() * DAT_0066be20 / aspectRatio * DAT_0066c0dc
//
// @param param_1  Context/this pointer
// @param param_2  Output float pointer (receives computed FOV value)
// @param param_3  Render target state object
// @param param_4  Target slot index
// @param param_5  Sub-entity index
// @param param_6  Additional parameter for entity query
// @return 1 if camera view was updated, 0 if skipped
uint32_t UpdateCameraView(uint32_t param_1, float* param_2,
                          uint32_t param_3, int param_4,
                          int param_5, uint32_t param_6);  // FUN_0048f4a0

// ─── ComputeCameraTransform (FUN_00499c90) — PASS ────────────────
// Resolves the camera transform data address for a given camera object.
// Uses the camera's type field (offset +4) and flags (offset +0x124, +0x12c)
// to select a specific 0x18-byte transform table. The transform table base
// address is scaled by an index from DAT_00681db8 (or 1 if override mode via
// DAT_00702c45 and specific camera types).
//
// Camera type mapping:
//   0     -> default table at 0x682078
//   1     -> table at 0x681ec8
//   2     -> table at 0x681e38 (or 0x682030 if flag 0x8000000, or 0x3df if flag 0x20000)
//   3     -> table at 0x681f10 (inherits from linked camera at offset +0x264)
//   4     -> table at 0x682030
//   6     -> table at 0x681fe8
//   7     -> table at 0x681fa0
//   0x3df -> table at 0x681e80
//   0x434 -> table at 0x681f58
//
// @param param_1  Camera object pointer (0 = return default)
// @return Address of the selected camera transform row (index * 0x18 + base)
int ComputeCameraTransform(int param_1);   // FUN_00499c90

// ─── CameraTransitionCheck (FUN_00499dd0) — PASS ─────────────────
// Checks whether a camera transition is currently active.
// Returns 1 if the camera system is in a state that allows transitions:
//   - No active camera object (DAT_00681db0 == 0)
//   - Transition flag is zero (DAT_00681dbc == 0)
//   - Camera index is 1 (DAT_00681db8 == 1)
//   OR camera override is active (DAT_00702c45 != 0) with a valid
//   render target of type 1, 2, or 3.
//
// @return 1 if camera transition is active, 0 otherwise
uint32_t CameraTransitionCheck();   // FUN_00499dd0

// ─── TanPrecise (FUN_00490860) — PASS (trivial) ──────────────────
// SSE2 precise tangent. Thin wrapper around libm_sse2_tan_precise.
// Used for FOV validation. 3 callers, 1 callee.
void TanPrecise();  // FUN_00490860

// ─── AtanPrecise (FUN_00490880) — PASS (trivial) ─────────────────
// SSE2 precise arctangent. Thin wrapper around libm_sse2_atan_precise.
// Used for FOV aspect validation. 2 callers, 1 callee.
void AtanPrecise();  // FUN_00490880

// ─── AllocateTransformContext (FUN_00635830) — PASS (trivial) ────
// Increments global transform counter DAT_006887d0 (skips zero).
// 7 callers, 0 callees.
void AllocateTransformContext();  // FUN_00635830

// ─── ComputeEntityScaledValue (FUN_00635850) — PASS ──────────────
// Computes scaled entity value: (field_0x18 * scale * field_0x1c) + field_0x10.
// 18 callers (hot path), 0 callees.
/// @param param_1  Entity data pointer
/// @param param_2  Scale factor
/// @return Scaled integer value
int ComputeEntityScaledValue(int param_1, float param_2);  // FUN_00635850

// ─── BuildViewMatrix (FUN_0063e830) — PASS ──────────────────────
// Constructs 4x4 view matrix from forward vector + position.
// Normalizes, computes cross products, writes row-major matrix.
/// @param param_1  Output matrix (17 uint32_t: type tag + 4x4)
/// @param param_2  Position vector (3 floats)
/// @param param_3  Forward direction vector (3 floats)
/// @param param_4  Up direction vector (3 floats)
void BuildViewMatrix(uint32_t* param_1, uint32_t* param_2, float* param_3, float* param_4);  // FUN_0063e830

// ─── TransposeMatrix (FUN_0063f360) — PASS ──────────────────────
// Transposes 4x4 matrix with column swap bit manipulation.
/// @param param_1  Output (transposed matrix, 17 uint32_t)
/// @param param_2  Input matrix (17 uint32_t)
void TransposeMatrix(uint32_t* param_1, uint32_t* param_2);  // FUN_0063f360

// ─── GetEntityFov (FUN_00634660) — PASS ──────────────────────────
// Computes entity FOV from transform context and parent data.
/// @param param_1  Entity pointer (cast to float for Ghidra typing)
/// @param param_2  FOV parameter (scale/adjustment value)
/// @return Computed FOV value (extended precision float)
float GetEntityFov(float param_1, uint32_t param_2);  // FUN_00634660

// ─── IsEntityValid (FUN_00634e80) — PASS (trivial) ──────────────
// Returns entity pointer if type field (*(short*)(param_1+4)) == 1.
/// @param param_1  Entity pointer
/// @return param_1 if valid, 0 otherwise
int IsEntityValid(int param_1);  // FUN_00634e80

// ─── UpdateEntityTransform (FUN_00634ea0) — FAIL (usable ~55%) ──
// Complex entity transform update: walks tree, processes types 1-3,
/// applies XOR depth obfuscation, calls transform callbacks.
/// @param param_1  Entity node
/// @param param_2  Frame counter (for change detection)
/// @param param_3  Visit stamp (cycle detection)
/// @return Entity transform address (param_1+0x24 or 0)
uint32_t UpdateEntityTransform(int param_1, int param_2, int param_3);  // FUN_00634ea0

// ─── CameraModeSwitch (FUN_00499e30) ──────────────────────────────
// Sets the camera display mode (5 modes: single, split, auto).
// Recomputes camera transform and calls SetupProjection.
// 11 callers, 2 callees.
/// @param param_1  Mode: 1=single, 2=player1, 3=3split-A, 4=2split-A, 5=player2, -1=auto
void CameraModeSwitch(int param_1);  // FUN_00499e30

// ─── CameraFrameTick (FUN_00499f10) ──────────────────────────────
// Cutscene camera sequencer. Increments frame counter, checks keyframe
// timestamps, dispatches sound for entity types 1/2/3 on match.
// 2 callers, 1 callee (SoundDispatch).
void CameraFrameTick();  // FUN_00499f10

// ─── EntityWorldTransform (FUN_005fac30) ──────────────────────────
// Applies entity's rotation matrix + position to a 3D vector.
// Two modes based on flag bit 0x20 at offset 0x124:
//   - Flag clear: uses FUN_005faab0 to decompose rotation, then transforms
//   - Flag set: uses explicit 3x3 rotation matrix at offsets 0x2e8-0x30c
// Result: rotated vector + entity position (0xf0-0xf8).
// 108 callers — core world-space transform.
void EntityWorldTransform(int param_1, float* param_2, float* param_3);  // FUN_005fac30

} // namespace Giants
