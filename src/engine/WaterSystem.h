// Giants Engine - Water/Wave System
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Ocean/water wave simulation with shader constant dispatch.
// Manages wave position, shader parameter uploads, and
// time-based wave animation with wrapping.

#pragma once

#include <cstdint>

namespace Giants {

// ─── UpdateWaves (FUN_004ddf10) — FAIL (usable ~80%) ───────────
// Updates the water/wave simulation for a given wave layer index.
// Computes wave position from time, uploads a 6x4 shader constant
// matrix to the GPU via renderer vtable calls, and animates the
// wave offset with wrapping modulo DAT_0066bf2c.
//
// The function performs:
//   1. Compute 4x4 wave transform from wave tables (DAT_006628f8, DAT_006628d0)
//   2. Upload shader constants to GPU (SetVertexShaderConstant via vtable)
//   3. Animate wave offset based on elapsed time
//   4. Wrap wave positions into [0, DAT_0066bf2c) range
//
// 1 caller (likely the scene pipeline), 2 callees.
//
// Parameters:
//   param_1 — wave layer index (0 or 1; selects wave parameter tables)
void UpdateWaves(int waveIndex);  // FUN_004ddf10

// ─── InitializeWaveSystem (FUN_004dfe20) — PASS (usable ~80%) ───
// Initializes the wave/ocean rendering system. Computes wave tiling
// parameters from scene data, allocates wave context structures,
// and configures the render dispatch function pointers.
//
// Performs:
//   1. Compute wave tile sizes: DAT_00702684 = wavePeriod / waterScale
//   2. Select wave frequency based on water type (offset 0x4fb0 or 0x5010)
//   3. Allocate wave context via FUN_004e2180
//   4. Configure render dispatch: DAT_00701d34, DAT_00701de8, DAT_00701d7c
//      depending on water complexity (simple vs. 3-layer)
//   5. Create shader objects via renderer vtable[2] and vtable[0x18]
//
// @param param_1  Optional wave data to free (previous context)
void InitializeWaveSystem(void* param_1);   // FUN_004dfe20

// ─── ShutdownWaveSystem (FUN_004dff90) — PASS (usable ~85%) ──────
// Shuts down and cleans up the wave/ocean rendering system.
// Releases all shader objects, vertex buffers, and texture resources.
//
// Iterates over 9 device slots (DAT_007026d8, DAT_00701dc4),
// then over 3 water layers (0..2) with 3 resource categories each:
//   - Water surface textures (offsets 0x4fb0..0x4fb8)
//   - Foam/detail textures (offsets 0x5010..0x5018)
//   - Reflection textures (offsets 0x4f50..0x4f58)
// For each: releases via renderer vtable[0x32] and frees pixel data.
void ShutdownWaveSystem();   // FUN_004dff90

// ─── ComputeWaveVertex (FUN_004e07f0) — PASS ─────────────────────
// Computes a single wave vertex position from a 2D coordinate.
// Applies wave transform matrix to compute world-space XZ position,
// reads height from input, and returns out-of-bounds flag.
//
// Output layout (5 floats written to param_1):
//   [0] = x (input param_2)
//   [1] = z (input param_3)
//   [2] = y (height from param_4)
//   [3] = 0.0 (padding/homogeneous)
//   [4] = transformed X (x*m00 + z*m10 + tx)
//   [5] = transformed Z (x*m01 + z*m11 + tz)
//
// @param param_1  Output vertex buffer (at least 6 floats)
// @param param_2  X coordinate (world space)
// @param param_3  Z coordinate (world space)
// @param param_4  Height input pointer
// @param param_5  Transform matrix pointer (offsets 0x3c..0x58)
// @return true if vertex is out of wave tile bounds (clipped)
bool ComputeWaveVertex(float* param_1, float param_2, float param_3,
                       float* param_4, int param_5);   // FUN_004e07f0

} // namespace Giants
