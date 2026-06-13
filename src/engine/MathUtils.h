// Giants Engine - Math Utility Functions
// Reverse engineered from GiantsMain.exe v1.520.59

#pragma once

#include <cstdint>

namespace Giants {

// ─── FloatToInt64 (FUN_00643f70) — PASS ────────────────────────
// CRT intrinsic: converts float (XMM0) to int64.
// Handles overflow by clamping to INT64_MIN/MAX.
// 127 callers — this is __ftol2, NOT a random/hash function.
int64_t FloatToInt64(float value);   // FUN_00643f70

// ─── VectorDistanceSq (FUN_00638d40) — PASS ─────────────────────
// Computes squared distance between two 3D points.
// Returns (x2-x1)² + (y2-y1)² + (z2-z1)²
// 192 callers — one of the most called functions.
float VectorDistanceSq(const float* a, const float* b);  // FUN_00638d40

// ─── SinCosLookup (FUN_006387e0) — PASS ────────────────────────
// Fast sine/cosine via 16K-entry lookup tables (DAT_00698800, DAT_006ac800).
// Converts angle to table index via (angle * 10430.378 + 0.5) & 0x3FFF.
// 150 callers — extremely hot path.
void SinCosLookup(float angle, float* outSin, float* outCos);  // FUN_006387e0

// ─── CheckProcessorSupport (FUN_006391d0) — PASS ───────────────
// Detects CPU feature level (SSE2, AVX) and selects optimized
// math function tables. Returns feature level (0=none, 1=SSE2, 2=AVX, 3=AVX2)
// or -1 if unsupported. Sets function pointer tables at DAT_00701a4c..DAT_00701cf8.
// Called once during engine startup.
int CheckProcessorSupport();  // FUN_006391d0

// ─── DetectCpuFeatures (FUN_00638f90) — PASS ────────────────────
// CPUID-based feature detection. Sets 25+ boolean flags at DAT_006bc808..bc826
// for SSE2, SSE4.1/4.2, AVX, AVX2, FMA, BMI1/2, LZCNT, POPCNT, RDRAND, etc.
// Some unreachable blocks from #ifdef paths.
// 1 caller (CRT init), 0 callees.
void DetectCpuFeatures();  // FUN_00638f90

// ─── ApplyTransform — PTR_FUN_0067d208 (data pointer) ───────────
// Runtime function pointer set by CheckProcessorSupport(). Points to
// optimized transform application (SSE2/AVX). Not decompilable — .data address.
// 3 references (Camera.cpp, MathUtils.cpp, entity pipeline).
extern void (*ApplyTransform)(void* transformData);  // PTR_FUN_0067d208

// ─── PostTransformUpdate — PTR_FUN_0067d20c (data pointer) ──────
// Runtime function pointer set by CheckProcessorSupport(). Points to
// optimized post-transform update. Not decompilable — .data address.
// 2 references (Camera.cpp, MathUtils.cpp).
extern void (*PostTransformUpdate)(int param_1);  // PTR_FUN_0067d20c

// ─── VectorDistanceSq2D (FUN_00638d00) — PASS ────────────────────
// Computes squared distance between two 2D points.
// Returns (x2-x1)² + (y2-y1)²
// 111 callers — hot path for 2D distance checks.
float VectorDistanceSq2D(const float* a, const float* b);  // FUN_00638d00

// ─── QuaternionMultiply (FUN_00639640) ────────────────────────────
// Full quaternion/matrix multiplication with type-tag dispatch.
// Handles 3 cases based on type tags (bit 0x20, bits 0-3):
//   - Both identity-type: optimized fast path
//   - One identity: copy from the other
//   - General: full 3x3 matrix multiply (6-element stride)
// Uses temp buffer if output aliases an input.
// 136 callers — core transform math.
/// @param param_1  Output quaternion/matrix (17 floats: tag + 4x4)
/// @param param_2  Input A (17 floats)
/// @param param_3  Input B (17 floats)
void QuaternionMultiply(float* param_1, float* param_2, float* param_3);  // FUN_00639640

// ─── ComputeAngle2D (FUN_006389d0) ────────────────────────────────
// Computes normalized 2D angle between two points via atan2.
// Returns angle scaled and wrapped to [0, 2π], clamped to max.
// Returns DAT_0066c0cc (default angle) if points are coincident.
// 86 callers — used for entity facing/rotation.
float ComputeAngle2D(const float* a, const float* b);  // FUN_006389d0

// ─── Vector3Normalize (FUN_00638d90) ─────────────────────────────
// Normalizes a 3D vector in-place. If length² < DAT_0066bd04 (epsilon),
// sets all components to 0. Uses SSE2 sqrt for the division.
// 69 callers — core math utility.
void Vector3Normalize(float* x, float* y, float* z);  // FUN_00638d90

// ─── WrapAngle (FUN_00638f10) ────────────────────────────────────
// Normalizes an angle to [0, 2π) range using fmod.
// If angle < 0, adds DAT_0066c14c (2π). If >= 2π, applies fmod.
// 73 callers — used for rotation wrapping.
void WrapAngle(float* angle);  // FUN_00638f10

} // namespace Giants
