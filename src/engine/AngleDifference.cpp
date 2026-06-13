// Giants Engine - Angle Difference Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "AngleDifference.h"
#include <cstdint>
namespace Giants {
extern float DAT_0066c14c;  // Full circle (360.0f)
extern float DAT_0066c110;  // Half circle (180.0f)
float AngleDifference(float a, float b)
{
    float diff = a - b;
    if (diff < 0.0f) {
        diff += DAT_0066c14c;
    }
    if (DAT_0066c14c < diff) {
        diff -= DAT_0066c14c;
    }
    if (DAT_0066c110 < diff) {
        diff = DAT_0066c14c - diff;
    }
    return diff;
}
} // namespace Giants
