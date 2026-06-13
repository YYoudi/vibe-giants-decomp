// Giants Engine - Matrix 3x4 Initializer Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "Matrix3x4Init.h"
#include "CRTStubs.h"
#include <cstring>

namespace Giants {

extern void ComputeMatrixEntry(float m0, float m1, uint32_t p3, uint32_t p4,
                               uint32_t p5, uint32_t p6, uint32_t cookie);  // FUN_00444ef0
extern void AppendString(const char* s, int len);  // FUN_00442eb0

// ═══════════════════════════════════════════════════════════════════
// InitializeMatrix3x4 (FUN_00444db0) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════

void InitializeMatrix3x4(float* result, const float* source,
    uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6)
{
    uint32_t cookie = 0;  // DAT_0067d280 ^ &cookie (simplified)

    ComputeMatrixEntry(source[0], source[1], p3, p4, p5, p6, cookie);

    // Zero the 6-float result
    result[0] = 0.0f;
    result[1] = 0.0f;
    result[2] = 0.0f;
    result[3] = 0.0f;
    result[4] = 0.0f;
    result[5] = 0.0f;

    // Clear temp buffer
    uint8_t buffer[508];
    AppendString(reinterpret_cast<const char*>(buffer), 0);
}

} // namespace Giants
