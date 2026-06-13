// Giants Engine - Snap Float to Precision Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "SnapFloatPrecision.h"
#include <cstdint>
namespace Giants {
extern float _DAT_006866a8;  // Precision snap constant (large power of 2)
void SnapFloatPrecision(float* a, float* b)
{
    *a = *a + _DAT_006866a8;
    *b = *b + _DAT_006866a8;
    *a = *a - _DAT_006866a8;
    *b = *b - _DAT_006866a8;
}
} // namespace Giants
