// Giants Engine - Matrix Operations
// Reverse engineered from GiantsMain.exe v1.520.59
//
// Viewport/projection matrix construction and obfuscated matrix copy.
// The XOR obfuscation on Z-column elements uses key at DAT_0066c580.

#pragma once

#include <cstdint>

namespace Giants {

// ─── SetupViewportMatrix (FUN_005f9c10) — PASS ──────────────────
// Constructs a viewport/projection matrix from min/max extents.
// Writes 16 floats to the global projection buffer (DAT_006857d0..+0x40),
// then dispatches to the renderer via vtable[0x34] on DAT_00702700.
// The Z-column values are XOR-obfuscated with key at DAT_0066c580.
// 4 callers, 1 callee.
//
// Parameters:
//   param_1 — pointer to {minX, minY} viewport extents (2 floats)
//   param_2 — pointer to {maxX, maxY} viewport extents (2 floats)
void SetupViewportMatrix(const float* param_1, const float* param_2);  // FUN_005f9c10

// ─── CopyAndObfuscateMatrix (FUN_005fa310) — PASS ───────────────
// Copies a 4x4 matrix (16 uint32) from param_1 to the global render
// state buffer at DAT_00685790..+0x40, XOR-ing elements [2], [6],
// [10], [14] (the entire Z column) with key DAT_0066c580.
// Calls FUN_005fa1a0 after copy (likely a renderer notification).
// 11 callers, 1 callee.
//
// Parameters:
//   param_1 — source 4x4 matrix (16 uint32 values, row-major)
void CopyAndObfuscateMatrix(const uint32_t* matrix);  // FUN_005fa310

// ─── MatrixIdentityOrMultiply (FUN_0063e2c0) — FAIL ───────────
// Loads 4x4 identity matrix, optionally applies scale and axis rotation.
// Uses XOR obfuscation on param2 elements with key DAT_0066c580.
// 11 callers, 1 callee (FUN_0063eaa0).
void MatrixIdentityOrMultiply(uint32_t* param1, uint32_t* param2);  // FUN_0063e2c0

} // namespace Giants
