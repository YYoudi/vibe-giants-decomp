// Giants Engine - Big Number Scalar Multiply Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BigNumScalarMul.h"
#include <cstdint>
namespace Giants {
uint32_t* BigNumScalarMul(uint32_t* param_1, uint32_t param_2)
{
    uint32_t carry = 0;
    uint32_t size = param_1[2];  // Number of limbs
    if (size == 0) return param_1;

    for (uint32_t i = 0; i < size; i++) {
        uint32_t* limb = reinterpret_cast<uint32_t*>(param_1[1] + i * 4);
        uint64_t product = static_cast<uint64_t>(param_2) * static_cast<uint64_t>(*limb) + carry;
        *limb = static_cast<uint32_t>(product);
        carry = static_cast<uint32_t>(product >> 32);
    }

    if (carry != 0) {
        // Need to add a new limb
        if (param_1[3] < param_1[2] + 1) {
            // Need to grow — call vtable[0] (allocator)
            auto grow = reinterpret_cast<void(*)(uint32_t)>(reinterpret_cast<uint32_t*>(param_1[0])[0]);
            grow(param_1[2] + 1);
        }
        *reinterpret_cast<uint32_t*>(param_1[1] + param_1[2] * 4) = carry;
        param_1[2] = param_1[2] + 1;
    }
    return param_1;
}
} // namespace Giants
