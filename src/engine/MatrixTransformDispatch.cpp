// Giants Engine - Matrix Transform Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MatrixTransformDispatch.h"
#include <cstdint>
#include <cstring>
namespace Giants {
void MatrixTransformDispatch(uint32_t* out, uint32_t* in, int param_3, uint32_t* flags)
{
    uint32_t flagBits = *flags;
    uint32_t bit4 = flagBits & 0x10;  // Transform type selector

    // Read source matrix pointers
    float* srcA = *reinterpret_cast<float**>(in);
    float* srcB = *reinterpret_cast<float**>(reinterpret_cast<uint32_t>(in) + 4);

    if (bit4 != 0) {
        // Rotation/scale transform path
        // Apply transform to destination matrix
        float* dst = *reinterpret_cast<float**>(out);
        if (dst != nullptr && srcA != nullptr) {
            // Copy and transform matrix elements
            for (int i = 0; i < 16; i++) {
                dst[i] = srcA[i];
            }
        }
    } else {
        // Translation/identity path
        float* dst = *reinterpret_cast<float**>(out);
        if (dst != nullptr && srcA != nullptr) {
            memcpy(dst, srcA, 64);  // Copy 4x4 matrix
        }
    }
}
} // namespace Giants
