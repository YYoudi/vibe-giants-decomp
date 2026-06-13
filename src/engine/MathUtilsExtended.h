// Giants Engine - Extended Math Utilities
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── AngleDiff (FUN_00638870) ── PASS ──
// Computes the shortest angular difference between two angles.
// Both inputs are normalized to [0, 360), then difference is
// wrapped to [-180, 180]. 33 callers, 1 callee (fmod).
float AngleDiff(float angle1, float angle2);  // FUN_00638870

// ─── Vector3Distance (FUN_00638c80) ── PASS ──
// Computes 3D Euclidean distance between two float[3] points.
// Uses double-precision for squared sum, then SSE2 sqrt.
// 33 callers, 1 callee (SQRT).
float Vector3Distance(const float* p1, const float* p2);  // FUN_00638c80

// ─── ClearAndFree (FUN_0042b2c0) ── PASS ──
// STL vector clear-and-free: destroys elements, frees buffer,
// resets begin/end/capacity to null. Handles aligned allocs.
// 33 callers, 2 callees (FUN_0042b650, CRTFree).
void ClearAndFree(int** container);  // FUN_0042b2c0

// ─── VectorAssign (FUN_0061d7b0) ── PASS ──
// STL vector<uint32_t> assign from data pointer. Copies count
// elements, grows with 1.5x strategy if needed. 34 callers.
void VectorAssign(uint32_t* thisPtr, const uint32_t* data, uint32_t count);  // FUN_0061d7b0

// ─── ResetEntityBuffers (FUN_00541080) ── FAIL (usable ~85%) ──
// Resets render entity buffers: frees descriptor arrays, walks
// linked lists to free entity buffers, sets flags on entities,
// resets state buffer while preserving sentinels. 34 callers.
void ResetEntityBuffers();  // FUN_00541080

} // namespace Giants
