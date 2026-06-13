// Giants Engine - Vector Insert with Grow Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: PASS
#include "VectorInsert.h"
#include <cstdlib>
#include <cstring>
namespace Giants {

extern void FUN_0042b750();    // _Xlength_error (noreturn)
extern void FUN_00643505(void* ptr, uint32_t size); // operator delete
extern void _invoke_watson(void* a, void* b, void* c, int d, int e); // CRT assert

uint32_t* VectorInsertGrow(int* vecHeader, void* pos, uint32_t* elem)
{
    int iVar3 = vecHeader[0]; // _Myfirst
    int iVar4 = (vecHeader[1] - iVar3) >> 2; // size()

    if (iVar4 == 0x3fffffff)
        FUN_0042b750(); // _Xlength_error

    uint32_t uVar6 = static_cast<uint32_t>((vecHeader[2] - iVar3) >> 2); // capacity()
    uint32_t uVar1 = iVar4 + 1; // new_size

    uint32_t newCap;
    if (0x3fffffff - (uVar6 >> 1) < uVar6)
        newCap = 0x3fffffff;
    else
    {
        newCap = (uVar6 >> 1) + uVar6;
        if (newCap < uVar1)
            newCap = uVar1;
    }

    // Allocate new buffer
    uint32_t allocSize = newCap * 4 + 4;
    int* _Dst = static_cast<int*>(malloc(allocSize));
    if (_Dst == nullptr)
    {
        allocSize = newCap * 4;
        _Dst = static_cast<int*>(malloc(allocSize));
        if (_Dst == nullptr) newCap = 0;
    }

    // Copy element at insert position
    int insertOff = (reinterpret_cast<int>(pos) - iVar3) >> 2;
    uint32_t* puVar2 = reinterpret_cast<uint32_t*>(reinterpret_cast<int>(_Dst) + (insertOff << 2));
    *puVar2 = *elem;

    // Move elements before insert point
    if (insertOff > 0)
        memcpy(_Dst, reinterpret_cast<void*>(iVar3), insertOff << 2);

    // Move elements after insert point
    int afterOff = iVar4 - insertOff;
    if (afterOff > 0)
        memcpy(reinterpret_cast<void*>(reinterpret_cast<int>(_Dst) + ((insertOff + 1) << 2)),
               reinterpret_cast<void*>(reinterpret_cast<int>(iVar3) + (insertOff << 2)),
               afterOff << 2);

    // Free old buffer
    if (iVar3 != 0)
    {
        uint32_t uVar6_2 = static_cast<uint32_t>(vecHeader[1] - iVar3) & 0xfffffffc;
        int iVar4_2 = iVar3;
        if (0xfff < uVar6_2)
        {
            iVar4_2 = *reinterpret_cast<int*>(iVar3 - 4);
            uVar6_2 += 0x23;
            if (static_cast<uint32_t>(iVar3 - iVar4_2 - 4) > 0x1f)
                std::abort();
        }
        FUN_00643505(reinterpret_cast<void*>(iVar4_2), uVar6_2);
    }

    vecHeader[0] = reinterpret_cast<int>(_Dst);
    vecHeader[1] = reinterpret_cast<int>(_Dst) + static_cast<int>(uVar1 * 4);
    vecHeader[2] = static_cast<int>(newCap * 4 + reinterpret_cast<int>(_Dst));

    return puVar2;
}

} // namespace Giants
