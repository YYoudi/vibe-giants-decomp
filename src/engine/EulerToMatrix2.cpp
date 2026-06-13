// Giants Engine - Euler To Matrix (variant 2) Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EulerToMatrix2.h"
#include <cstring>
#include <cmath>

namespace Giants {

static inline uint32_t f2u(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static inline float u2f(uint32_t u) { float f; memcpy(&f, &u, 4); return f; }

void EulerToMatrix2(uint32_t* matrix, float pitch, float yaw, float roll)
{
    constexpr float kDegToRad = 3.14159265358979323846f / 180.0f;
    constexpr uint32_t kSignBit = 0x80000000u;

    pitch *= kDegToRad;
    float cp = cosf(pitch);
    float sp = sinf(pitch);

    yaw *= kDegToRad;
    float cy = cosf(yaw);
    float sy = sinf(yaw);

    roll *= kDegToRad;
    float cr = cosf(roll);
    float sr = sinf(roll);

    float cx_xor = u2f(f2u(cp) ^ kSignBit);

    // Build rotation matrix (Rz * Ry * Rx convention)
    matrix[1]  = f2u(sr * sy);                              // m00
    matrix[2]  = f2u(cx_xor * cy * sr - cr * sp);           // m01
    matrix[5]  = f2u(cr * sy);                              // m10
    matrix[3]  = f2u(cr * cp - cy * sp * sr);               // m02
    matrix[6]  = f2u(sr * sp - cy * cp * cr);               // m11

    // Set rotation flag
    matrix[0] = (matrix[0] & 0xFFFFFFFD) | 1;

    matrix[9]  = f2u(cy);                                   // m20
    matrix[7]  = f2u(u2f(f2u(sp) ^ kSignBit) * cy * cr - sr * cp);  // m12
    matrix[10] = f2u(sy * cp);                              // m21
    matrix[11] = f2u(sy * sp);                              // m22
}

} // namespace Giants
