// Giants Engine - BigNum Compare Ex Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "BigNumCompareEx.h"
#include <cstdint>
namespace Giants {
int BigNumCompareEx(int param_1, int param_2, int param_3)
{
    // Each param is a bignum struct: +0x94=base, +8=size, +4=data_ptr
    int a_base = *reinterpret_cast<int*>(param_1 + 0x94);
    int a_end = *reinterpret_cast<int*>(param_1 + 8) + a_base;

    int b_base = *reinterpret_cast<int*>(param_2 + 0x94);
    int b_end = *reinterpret_cast<int*>(param_2 + 8) + b_base;

    int c_base = *reinterpret_cast<int*>(param_3 + 0x94);
    int c_end = *reinterpret_cast<int*>(param_3 + 8) + c_base;

    // Find max endpoint
    int maxEnd = (b_end < a_end) ? a_end : b_end;
    if (maxEnd + 1 < c_end) return -1;  // c too large
    if (c_end < maxEnd) return 1;        // c too small

    int top = c_end - 1;
    int minBase = (a_base < b_base) ? a_base : b_base;
    minBase = (minBase < c_base) ? minBase : c_base;

    if (minBase <= top) {
        uint32_t borrow = 0;
        for (int i = top; i >= minBase; i--) {
            uint32_t va = (i >= a_base && i < a_end)
                ? *reinterpret_cast<uint32_t*>(((i - a_base) * 4) + *reinterpret_cast<int*>(param_1 + 4))
                : 0;
            uint32_t vb = (i >= b_base && i < b_end)
                ? *reinterpret_cast<uint32_t*>(((i - b_base) * 4) + *reinterpret_cast<int*>(param_2 + 4))
                : 0;

            uint32_t sum = vb + va;
            uint32_t carry = (sum < vb) ? 1u : 0u;

            uint32_t vc = (i >= c_base && i < c_end)
                ? *reinterpret_cast<uint32_t*>(((i - c_base) * 4) + *reinterpret_cast<int*>(param_3 + 4))
                : 0;

            if (borrow < carry) return 1;
            if (borrow <= carry && vc < sum) return 1;

            uint32_t diff = vc - sum;
            uint32_t newBorrow = borrow + ((vc < sum) ? 1u : 0u) - carry;
            if (newBorrow != 0) return -1;
            if (diff > 1) return -1;
            borrow = diff;
        }
        if (borrow != 0) return -1;
    }
    return 0;
}
} // namespace Giants
