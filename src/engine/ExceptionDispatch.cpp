// Giants Engine - Exception Dispatch Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "ExceptionDispatch.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

extern uint32_t DAT_0067d280; // Security cookie
extern void* ExceptionList;

// External CRT/ConCRT functions
extern void FUN_0061d390(int*);                // ConCRT init
extern void FUN_0042b1f0();                     // Stack cookie check
extern void __ExceptionPtrCopy(void* dest, const void* src);

// Placeholder for vtable pointer
extern void* PTR_FUN_00669e64;

static inline int* operator_new(size_t size) { return static_cast<int*>(malloc(size)); }

uint8_t DispatchExceptionContinuation(int* param1, void* param2)
{
    void* savedExceptionList = ExceptionList;
    ExceptionList = &savedExceptionList;

    uint32_t cookie = DAT_0067d280 ^ reinterpret_cast<uint32_t>(&savedExceptionList);

    // Read virtual method at vtable offset +0x04
    auto dispatchFn = *reinterpret_cast<uint8_t(**)(int, int, int, int**, uint32_t)>(
        *reinterpret_cast<uintptr_t*>(*param1) + 4);

    FUN_0061d390(param1 + 0x2e);

    // Allocate ExceptionHolder (0x28 = 40 bytes)
    int* holder = operator_new(0x28);
    memset(holder, 0, 0x28);
    holder[0] = reinterpret_cast<int>(&PTR_FUN_00669e64); // vtable
    holder[1] = 1;  // refCount = 1
    holder[2] = 1;  // weakCount = 1
    holder[3] = 0;  // field0C

    int* piVar1 = holder + 3;

    // Copy exception_ptr from param_2
    __ExceptionPtrCopy(holder + 4, param2);

    // Build local dispatch argument struct
    int local_38[4];
    FUN_0061d390(local_38);

    // Stack-allocated pair for virtual dispatch
    int* local_28 = piVar1;
    int* local_24 = holder;

    // Invoke virtual dispatch
    uint8_t result = dispatchFn(1, 1, 0, &local_28, cookie);

    // Release strong reference
    if (local_24 != nullptr)
    {
        int32_t refCount;
        refCount = local_24[1] - 1;
        local_24[1] = refCount;

        if (refCount == 0)
        {
            // Call vtable[0] destructor
            reinterpret_cast<void(*)()>(**reinterpret_cast<uintptr_t**>(local_24))();

            int32_t weakBefore = local_24[2];
            local_24[2] = local_24[2] - 1;

            if (weakBefore == 1)
            {
                reinterpret_cast<void(*)()>(
                    *reinterpret_cast<uintptr_t*>(
                        *reinterpret_cast<uintptr_t*>(*local_24) + 4))();
            }
        }
    }

    FUN_0042b1f0();
    ExceptionList = savedExceptionList;

    return result;
}

} // namespace Giants
