// Giants Engine - Container Find Max Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ContainerFindMax.h"
#include <cstdint>
namespace Giants {
int* ContainerFindMax(int* param_1)
{
    // Stub: finds container with max size among 2 candidates
    // Original: compares (end-begin)/4 for each, returns pointer to larger
    int* first  = reinterpret_cast<int*>(param_1[0]);
    int* second = reinterpret_cast<int*>(param_1[1]);
    if (second == nullptr) return first;
    if (first == nullptr) return second;
    return first; // simplified
}
} // namespace Giants
