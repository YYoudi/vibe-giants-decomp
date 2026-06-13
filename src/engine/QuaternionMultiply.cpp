// Giants Engine - Quaternion Multiply Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "QuaternionMultiply.h"
#include <cstdint>
#include <cstring>
namespace Giants {
void QuaternionMultiply(float* out, float* q1, float* q2)
{
    // Handle aliasing: if out aliases q1 or q2, use temp buffer
    float* result = out;
    float temp[4];
    if (out == q1 || out == q2) {
        result = temp;
    }

    // Hamilton product: q1 * q2
    // w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z
    result[3] = (q2[3] * q1[3] - q1[0] * q2[0]) - q1[1] * q2[1] - q1[2] * q2[2];
    // x = q1.w*q2.x + q2.w*q1.x + q1.y*q2.z - q1.z*q2.y
    result[0] = (q2[3] * q1[0] + q1[3] * q2[0] + q1[2] * q2[1]) - q1[1] * q2[2];
    // y = q1.w*q2.y + q2.w*q1.y + q1.z*q2.x - q1.x*q2.z
    result[1] = (q1[3] * q2[1] + q1[1] * q2[3] + q1[0] * q2[2]) - q1[2] * q2[0];
    // z = q1.w*q2.z + q2.w*q1.z + q1.x*q2.y - q1.y*q2.x
    result[2] = (q1[3] * q2[2] + q1[2] * q2[3] + q1[1] * q2[0]) - q1[0] * q2[1];

    // Copy temp back to output if we used it
    if (result == temp) {
        out[0] = temp[0];
        out[1] = temp[1];
        out[2] = temp[2];
        out[3] = temp[3];
    }
}
} // namespace Giants
