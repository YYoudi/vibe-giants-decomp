// Giants Engine - Build Rotation Matrix Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BuildRotationMatrix.h"
#include <cstdint>
#include <cmath>
namespace Giants {
extern float _DAT_0066bd40;              // Degrees to radians constant
extern uint32_t PTR_FUN_0067d230;        // sin function pointer
extern uint32_t PTR_FUN_0067d234;        // cos function pointer

void BuildRotationMatrix(uint32_t* matrix, float yaw, float pitch, float roll, float unused)
{
    float radYaw   = yaw   * _DAT_0066bd40;
    float radPitch = pitch * _DAT_0066bd40;

    // Compute sin/cos via function pointers (MSVC x87 float10->float)
    auto sinFn = reinterpret_cast<float(*)(float)>(PTR_FUN_0067d230);
    auto cosFn = reinterpret_cast<float(*)(float)>(PTR_FUN_0067d234);

    float sy = sinFn(radYaw);
    float cy = cosFn(radYaw);
    float sp = sinFn(radPitch);
    float cp = cosFn(radPitch);

    // Fill rotation matrix (3x3 part, row-major at offsets 0, 0x10, 0x20)
    // Column 0
    *reinterpret_cast<float*>(&matrix[0])  = cy * cp;
    *reinterpret_cast<float*>(&matrix[1])  = sy * cp;
    *reinterpret_cast<float*>(&matrix[2])  = -sp;
    *reinterpret_cast<float*>(&matrix[3])  = 0.0f;
    // Column 1
    *reinterpret_cast<float*>(&matrix[4])  = -sy;
    *reinterpret_cast<float*>(&matrix[5])  = cy;
    *reinterpret_cast<float*>(&matrix[6])  = 0.0f;
    *reinterpret_cast<float*>(&matrix[7])  = 0.0f;
    // Column 2
    *reinterpret_cast<float*>(&matrix[8])  = sp * cy;
    *reinterpret_cast<float*>(&matrix[9])  = sp * sy;
    *reinterpret_cast<float*>(&matrix[10]) = cp;
    *reinterpret_cast<float*>(&matrix[11]) = 0.0f;
    // Column 3 (translation = 0)
    *reinterpret_cast<float*>(&matrix[12]) = 0.0f;
    *reinterpret_cast<float*>(&matrix[13]) = 0.0f;
    *reinterpret_cast<float*>(&matrix[14]) = 0.0f;
    *reinterpret_cast<float*>(&matrix[15]) = 1.0f;
}
} // namespace Giants
