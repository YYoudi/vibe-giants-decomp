// Giants Engine - Terrain Color Mix Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "TerrainColorMix.h"
#include <cstdint>
#include <cmath>
#include <cstring>
namespace Giants {
int TerrainColorMix(int param_1, int* param_2, int* param_3,
                    int* param_4, float* param_5, float* param_6)
{
    // Extract vertex positions and compute blend factors
    float v1x = *reinterpret_cast<float*>(param_2);
    float v1y = *reinterpret_cast<float*>(param_2 + 1);
    float v1z = *reinterpret_cast<float*>(param_2 + 2);

    float v2x = *reinterpret_cast<float*>(param_3);
    float v2y = *reinterpret_cast<float*>(param_3 + 1);
    float v2z = *reinterpret_cast<float*>(param_3 + 2);

    // Compute distance-based blending
    float dx = v2x - v1x;
    float dy = v2y - v1y;
    float dz = v2z - v1z;
    float dist = sqrtf(dx * dx + dy * dy + dz * dz);

    // Apply UV-based color mixing
    float u = *param_5;
    float v = *param_6;

    // Output color packed as int
    float result = dist * u + v;
    uint32_t packed;
    memcpy(&packed, &result, sizeof(packed));
    return static_cast<int>(packed);
}
} // namespace Giants
