// Giants Engine - Vector Push Back Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "VectorPushBack.h"

namespace Giants {

extern void VectorGrowAndPush(uint32_t* last, uint32_t* element);  // FUN_0042c4e0

void VectorPushBack(int* vecObj, uint32_t* element)
{
    uint32_t* last = *reinterpret_cast<uint32_t**>(vecObj + 1);  // _Mylast
    uint32_t* end  = *reinterpret_cast<uint32_t**>(vecObj + 2);  // _Myend

    if (last != end)
    {
        // Capacity available — move element directly
        uint32_t val = *element;
        *element = 0;
        *last = val;
        *reinterpret_cast<int*>(vecObj + 1) += 4;  // ++_Mylast
    }
    else
    {
        VectorGrowAndPush(last, element);
    }
}

} // namespace Giants
