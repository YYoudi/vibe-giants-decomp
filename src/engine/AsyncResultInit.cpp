// Giants Engine - Async Result Init Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "AsyncResultInit.h"
#include <cstdint>
#include <cstring>
namespace Giants {
extern uint32_t PTR_FUN_00669d30;  // Vtable for async result

uint32_t* AsyncResultInit(uint32_t* param_1, int param_2, uint32_t param_3,
                          int* param_4, uint32_t param_5)
{
    // Set vtable
    param_1[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00669d30);

    // Zero out all fields
    memset(&param_1[1], 0, 0x34 * sizeof(uint32_t));

    // Set initial state
    param_1[5] = 2;
    param_1[0xF] = 0xFFFFFFFF;
    param_1[0x12] = param_2;
    param_1[0x32] = reinterpret_cast<uint32_t>(param_1);

    // COM refcount management on param_4
    auto addRef = [](int* p) { if (p) { p[1]++; } };
    auto release = [](int* p) {
        if (p) {
            int ref = --p[1];
            if (ref == 0) {
                reinterpret_cast<void(*)()>(reinterpret_cast<uint32_t*>(p[0])[0])();
                int wref = --p[2];
                if (wref == 0) {
                    reinterpret_cast<void(*)()>(reinterpret_cast<uint32_t*>(p[0])[1])();
                }
            }
        }
    };

    addRef(param_4);
    param_1[0x2A] = param_3;
    param_1[0x2B] = reinterpret_cast<uint32_t>(param_4);
    param_1[0x2C] = param_5;
    release(param_4);

    if (param_2 != 2) {
        reinterpret_cast<int*>(param_2)[1]++;
    }
    release(param_4);

    return param_1;
}
} // namespace Giants
