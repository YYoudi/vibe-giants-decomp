// Giants Engine - Math Utility Functions Implementation
// Reverse engineered from GiantsMain.exe v1.520.59

#include "MathUtils.h"
#include <cmath>

namespace Giants {

// ─── FloatToInt64 (FUN_00643f70) — PASS ────────────────────────
// CRT float-to-int64 conversion with overflow clamping.
// Uses SSE cvttps2dq for the fast path when FPU precision flag is clear.

static uint8_t DAT_0067d2e0 = 0;  // FPU precision/control flags

int64_t FloatToInt64(float value)
{
    // Fast path: SSE conversion when precision flag bit 0x20 is clear
    if ((DAT_0067d2e0 & 0x20) == 0) {
        return (int64_t)(int)value;  // SSE cvttps2dq + sign extend
    }

    // Slow path: manual conversion with overflow handling
    uint32_t sign = (int)value >> 31;
    uint32_t abs2x = (int)value * 2;

    if (abs2x <= 0x9dffffff) {
        // Small value: fits in int32
        return (int64_t)(int)value;
    }
    if (abs2x > 0xbdffffff) {
        // Overflow: clamp to INT64_MIN
        return (int64_t)0x8000000000000000ULL;
    }

    // Medium value: manual fixed-point extraction
    uint8_t exponent = (uint8_t)(abs2x >> 24) + 0x42;
    uint32_t mantissa = ((abs2x | 0x01000000) << 7 ^ sign) - sign;
    uint8_t shift = exponent & 0x1f;

    uint32_t hi = sign << shift | mantissa >> (32 - shift);
    uint32_t lo = mantissa << shift;
    return (int64_t)hi << 32 | lo;
}

// ─── VectorDistanceSq (FUN_00638d40) — PASS ─────────────────────
// Trivial: squared distance between two Vector3 pointers.
// 192 callers, 0 callees — hot path function.

float VectorDistanceSq(const float* a, const float* b)
{
    float dx = b[0] - a[0];
    float dy = b[1] - a[1];
    float dz = b[2] - a[2];
    return dx * dx + dy * dy + dz * dz;
}

// ─── SinCosLookup (FUN_006387e0) — PASS ─────────────────────────
// Fast sin/cos via 16K-entry lookup tables.
// Index = (angle * 10430.378 + 0.5) & 0x3FFF
// 150 callers, 0 callees — extremely hot path.
//
// The magic constant 10430.378 ≈ 65536 / (2*pi) converts radians to
// a 16-bit index. DAT_006543c8 = 10430.378, DAT_0066be20 = 0.5 (rounding bias).
//
// DAT_00698800: sin table (float[16384])
// DAT_006ac800: cos table (float[16384]) — accessed as uint32_t offset

static float s_sinTable[0x4000];      // DAT_00698800
static float s_cosTable[0x4000];      // DAT_006ac800
static float DAT_006543c8 = 10430.378f;  // Radians-to-index scale
static float DAT_0066be20 = 0.5f;        // Rounding bias

void SinCosLookup(float angle, float* outSin, float* outCos)
{
    uint32_t index = (int32_t)(angle * DAT_006543c8 + DAT_0066be20) & 0x3FFF;
    *outSin = s_sinTable[index];
    *outCos = s_cosTable[index];
}

// ─── CheckProcessorSupport (FUN_006391d0) — PASS ────────────────
// Detects CPU feature level by checking feature flags in the binary's
// CRT initialization data (DAT_006bc811..DAT_006bc81e).
// Sets 14 function pointer slots for optimized math routines.
//
// Feature levels:
//   0 = unsupported (returns 0, functions still set to baseline)
//   1 = SSE2
//   2 = some extended set
//   3 = AVX+
//
// The function pointer tables at PTR_FUN_0067d0b8..PTR_FUN_0067d188
// contain arrays of function pointers indexed by feature level.

// CPU feature flag bytes (set by CRT CPUID detection)
static uint8_t DAT_006bc811 = 0;  // Feature flag byte 1
static uint8_t DAT_006bc819 = 0;  // Feature flag byte 2
static uint8_t DAT_006bc81d = 0;  // Feature flag byte 3
static uint8_t DAT_006bc81e = 0;  // Feature flag byte 4

// Function pointer tables for optimized math (14 slots)
static void* g_mathFn1  = nullptr;  // DAT_00701a58
static void* g_mathFn2  = nullptr;  // DAT_00701a54
static void* g_mathFn3  = nullptr;  // DAT_00701a50
static void* g_mathFn4  = nullptr;  // DAT_00701a4c
static void* g_mathFn5  = nullptr;  // DAT_00701cf4
static void* g_mathFn6  = nullptr;  // DAT_00701cf8
static void* g_mathFn7  = nullptr;  // DAT_00701cf0
static void* g_mathFn8  = nullptr;  // PTR_FUN_0067d20c
static void* g_mathFn9  = nullptr;  // PTR_FUN_0067d208
static void* g_mathFn10 = nullptr;  // PTR_FUN_0067d210
static void* g_mathFn11 = nullptr;  // PTR_FUN_0067d214
static void* g_mathFn12 = nullptr;  // PTR_FUN_0067d218
static void* g_mathFn13 = nullptr;  // PTR_FUN_0067d22c
static void* g_mathFn14 = nullptr;  // PTR_FUN_0067d000

int CheckProcessorSupport()
{
    // FUN_00638f90 — CPUID detection (sets DAT_006bc811..006bc81e)
    // Stub: we just set feature level 0 (baseline)

    int featureLevel;
    if (DAT_006bc81e != 0) {
        featureLevel = 3;
    } else if (DAT_006bc81d != 0) {
        featureLevel = 2;
    } else if (DAT_006bc819 != 0) {
        featureLevel = 1;
    } else {
        featureLevel = (DAT_006bc811 != 0) ? 0 : -1;
    }

    int index = (featureLevel != -1) ? featureLevel : 0;

    // Select function pointers from feature-indexed tables
    // Original: DAT_00701a58 = (&PTR_FUN_0067d0b8)[index];
    // etc. for all 14 function pointer slots
    // These would point to SSE2/AVX optimized versions of math ops

    // Stub: function pointers remain null (would be set from tables in real binary)
    (void)index;

    return (featureLevel != -1) ? 1 : 0;
}

// ═══════════════════════════════════════════════════════════════════
// DetectCpuFeatures — FUN_00638f90
// ═══════════════════════════════════════════════════════════════════
// CPU feature detection via CPUID. Queries basic info, extended features (leaf 7),
// and extended processor info (0x80000001). Sets 25+ boolean feature flags in
// DAT_006bc808..DAT_006bc826 covering: HTT, SSE2, SSE4.1, SSE4.2, AVX, AVX2,
// FMA, BMI1/2, LZCNT, POPCNT, RDRAND, etc. Some blocks are unreachable
// (compiler dead code from #ifdef paths).
// 1 caller (CRT init), 0 callees (pure CPUID).

void DetectCpuFeatures()
{
    // Original:
    // piVar1 = cpuid_basic_info(0);   // max basic leaf
    // puVar2 = cpuid(0x80000000);     // max extended leaf
    //
    // if (max_basic > 0):
    //   leaf1 = cpuid_Version_info(1)
    //   DAT_006bc808 = (leaf1.ebx >> 23) & 1;  // HTT
    //   DAT_006bc810 = (leaf1.ebx >> 25) & 1;  // SSE2 (or similar)
    //   ... 14 more flags from leaf1.ebx/edx/ecx
    //
    // if (max_basic > 6):
    //   leaf7 = cpuid_Extended_Feature_Enumeration_info(7)
    //   ... 13 flags from leaf7.ebx/ecx/edx (AVX2, BMI1/2, etc.)
    //
    // if (max_ext > 0x80000000):
    //   ext1 = cpuid(0x80000001)
    //   ... 5 flags from ext1 (RDTSCP, LZCNT, 3DNow, etc.)
}

// ═══════════════════════════════════════════════════════════════════
// ApplyTransform — PTR_FUN_0067d208 (data pointer)
// ═══════════════════════════════════════════════════════════════════
// Function pointer at address 0x0067d208, set by CheckProcessorSupport().
// Points to optimized transform application function (SSE2/AVX variant).
// Called from UpdateEntityTransform (FUN_00634ea0) to apply world transform.
// 3 references (Camera.cpp, MathUtils.cpp, entity transform pipeline).
// Not directly decompilable — address is in .data, resolved at runtime.

// PTR_FUN_0067d208 — resolved to one of:
//   g_mathFn8 (baseline), SSE2 variant, or AVX variant
// Signature: void ApplyTransform(void* transformData)

// ═══════════════════════════════════════════════════════════════════
// PostTransformUpdate — PTR_FUN_0067d20c (data pointer)
// ═══════════════════════════════════════════════════════════════════
// Function pointer at address 0x0067d20c, set by CheckProcessorSupport().
// Points to optimized post-transform matrix update function.
// Called from UpdateEntityTransform (FUN_00634ea0) after transform application.
// 2 references (Camera.cpp, MathUtils.cpp).
// Not directly decompilable — address is in .data, resolved at runtime.

// PTR_FUN_0067d20c — resolved to one of optimized variants
// Signature: void PostTransformUpdate(int param_1)

// ═══════════════════════════════════════════════════════════════════
// VectorDistanceSq2D — FUN_00638d00 — 111 callers
// ═══════════════════════════════════════════════════════════════════
// Squared distance between two 2D points: (x2-x1)² + (y2-y1)²

float VectorDistanceSq2D(const float* a, const float* b)
{
    float dx = b[0] - a[0];
    float dy = b[1] - a[1];
    return dx * dx + dy * dy;
}

// ═══════════════════════════════════════════════════════════════════
// QuaternionMultiply — FUN_00639640 — 136 callers, 146 lines
// ═══════════════════════════════════════════════════════════════════
// Full quaternion/matrix multiplication with type-tag dispatch.
// Matrices are 17 floats: [type_tag, 4x4 matrix].
// Type tag bits: 0x20 = has rotation, 0x0F = sub-type.
// Three cases:
//   - Both inputs have no rotation (bit 0x20 clear): fast path
//   - One input is identity (sub-type 0): copy from other
//   - General: 3x3 matrix multiply with 6-element stride per row

void QuaternionMultiply(float* param_1, float* param_2, float* param_3)
{
    float local_54[17];  // Temp buffer for alias protection
    float* out = param_1;
    float* inA = param_2;
    float* inB = param_3;

    // Use temp buffer if output aliases either input
    if ((param_1 == param_2) || (param_1 == param_3)) {
        out = local_54;
    }

    // Both inputs have no rotation — fast path
    if ((((uint32_t)*param_2 & 0x20) == 0) && (((uint32_t)*param_3 & 0x20) == 0)) {
        uint32_t subA = (uint32_t)*param_2 & 0xf;
        if ((subA == 0) || (((uint32_t)*param_3 & 0xf) == 0)) {
            // One or both are identity — copy from the non-zero one
            float* src = param_3;
            if (subA != 0) src = param_2;

            // Copy 2 rows of 6 floats (3x3 rotation part)
            float* dst = out + 1;
            float* srcRow = src + 3;
            for (int i = 2; i > 0; i--) {
                *dst = *(float*)((int)dst + ((int)src - (int)out));
                dst[1] = srcRow[-1];
                dst[2] = srcRow[0];
                dst[3] = srcRow[1];
                dst[4] = srcRow[2];
                dst[5] = srcRow[3];
                dst += 6;
                srcRow += 6;
            }
            // Copy type tag and translation
            *out = *src;
            out[13] = src[13];
            out[14] = src[14];
            out[15] = src[15];
            out[16] = src[16];
        } else {
            // General 3x3 multiply: both have rotation
            float* dst = out + 1;
            float* rowA = param_2 + 1;
            for (int row = 3; row > 0; row--) {
                float a0 = rowA[0];
                float* colB = param_3 + 1;
                for (int col = 3; col > 0; col--) {
                    *dst++ = a0 * colB[0] + rowA[1] * colB[6] + rowA[2] * colB[12];
                    colB++;
                }
                rowA += 6;
            }
            *out = 0x11;  // Type tag: full matrix
            // Translation: T = A.T * B.3x3 + B.T
            out[13] = param_2[13] * param_3[1] + param_2[14] * param_3[7] + param_2[15] * param_3[13] + param_3[13];
            out[14] = param_2[13] * param_3[2] + param_2[14] * param_3[8] + param_2[15] * param_3[14] + param_3[14];
            out[15] = param_2[13] * param_3[3] + param_2[14] * param_3[9] + param_2[15] * param_3[15] + param_3[15];
            out[16] = 1.0f;
        }
    } else {
        // At least one input has rotation — full multiply
        float* dst = out + 1;
        float* rowA = param_2 + 1;
        for (int row = 3; row > 0; row--) {
            float a0 = rowA[0];
            float* colB = param_3 + 1;
            for (int col = 3; col > 0; col--) {
                *dst++ = a0 * colB[0] + rowA[1] * colB[6] + rowA[2] * colB[12];
                colB++;
            }
            rowA += 6;
        }
        *out = 0x11;
        out[13] = param_2[13] * param_3[1] + param_2[14] * param_3[7] + param_2[15] * param_3[13] + param_3[13];
        out[14] = param_2[13] * param_3[2] + param_2[14] * param_3[8] + param_2[15] * param_3[14] + param_3[14];
        out[15] = param_2[13] * param_3[3] + param_2[14] * param_3[9] + param_2[15] * param_3[15] + param_3[15];
        out[16] = 1.0f;
    }

    // Copy from temp if aliased
    if (out == local_54) {
        for (int i = 0; i < 17; i++) param_1[i] = local_54[i];
    }
}

// ═══════════════════════════════════════════════════════════════════
// ComputeAngle2D — FUN_006389d0 — 86 callers
// ═══════════════════════════════════════════════════════════════════
// Computes 2D angle from point A to point B, normalized to [0, 2π].
// Uses atan2 for the base angle, then scales by DAT_0066c0a8 and
// offsets by DAT_0066c0cc. Wraps to [0, DAT_0066c14c] range.
// Returns DAT_0066c0cc (default) if points are coincident.

static float DAT_0066c0a8 = 1.0f;    // Angle scale factor
static float DAT_0066c0cc = 0.0f;    // Default angle / offset
static float DAT_0066c14c = 6.2832f; // 2π — angle wrap boundary
static float DAT_0066c148 = 0.0f;    // Minimum valid angle

float ComputeAngle2D(const float* a, const float* b)
{
    float dx = b[0] - a[0];
    float dy = b[1] - a[1];

    if (dx == 0.0f && dy == 0.0f) {
        return DAT_0066c0cc;  // Default angle for coincident points
    }

    float angle = atan2f(dy, dx);
    float result = angle * DAT_0066c0a8 + DAT_0066c0cc;

    // Wrap to [0, 2π]
    if (result > DAT_0066c14c) {
        result -= DAT_0066c14c;
    }
    if (result < 0.0f) {
        result += DAT_0066c14c;
    }

    // Clamp to max
    if (result > DAT_0066c148) {
        result = 0.0f;
    }

    return result;
}

// ═══════════════════════════════════════════════════════════════════
// Vector3Normalize — FUN_00638d90 — 69 callers
// ═══════════════════════════════════════════════════════════════════
// Normalizes a 3D vector in-place. If length² < epsilon, zeroes all.

static float DAT_0066bd04 = 1e-10f;  // Normalization epsilon

void Vector3Normalize(float* x, float* y, float* z)
{
    float lenSq = (*x) * (*x) + (*y) * (*y) + (*z) * (*z);

    if (DAT_0066bd04 <= lenSq) {
        float invLen = 1.0f / sqrtf(lenSq);
        *x *= invLen;
        *y *= invLen;
        *z *= invLen;
    } else {
        *x = 0.0f;
        *y = 0.0f;
        *z = 0.0f;
    }
}

// ═══════════════════════════════════════════════════════════════════
// WrapAngle — FUN_00638f10 — 73 callers
// ═══════════════════════════════════════════════════════════════════
// Normalizes angle to [0, 2π) using fmod.

void WrapAngle(float* angle)
{
    if (*angle < 0.0f) {
        *angle = fmodf(*angle, DAT_0066c14c) + DAT_0066c14c;
    } else if (DAT_0066c14c <= *angle) {
        *angle = fmodf(*angle, DAT_0066c14c);
    }
}

} // namespace Giants
