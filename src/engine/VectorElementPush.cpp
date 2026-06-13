// Giants Engine - Vector Element Push Back Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
// re-agent verdict: FAIL (usable ~80%)
#include "VectorElementPush.h"
#include <cstdlib>
#include <cstring>

namespace Giants {

extern void FUN_004435c0();    // Allocate new buffer
extern void FUN_004436c0(void* dst, void* src); // Move construct
extern void FUN_00443710(void* buf, uint32_t size, uint32_t cap); // Update pointers
extern void FUN_00443620();    // Deallocate old buffer
extern void FUN_0042b750();    // Length error

VectorElement* VectorElementPushBack(VectorElement** container, VectorElement* elem)
{
    VectorElement* end = container[1];

    if (end != container[2])
    {
        // Capacity available: move element in-place
        end->id = elem->id;
        end->pad = 0;
        end->field8 = elem->field8;
        end->fieldC = elem->fieldC;

        elem->id = 0;
        elem->pad = 0;
        elem->field8 = 0;
        elem->fieldC = 0;

        end = container[1];
        container[1] = end + 1;
        return end;
    }

    // Need to grow
    int32_t oldSize = static_cast<int32_t>(reinterpret_cast<uintptr_t>(end) - reinterpret_cast<uintptr_t>(container[0])) >> 4;
    if (oldSize == -1)
        FUN_0042b750();

    uint32_t newSize = oldSize + 1;
    uint32_t oldCap = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(container[2]) - reinterpret_cast<uintptr_t>(container[0])) >> 4;
    uint32_t newCap;

    if ((0xFFFFFFFF - (oldCap >> 1)) < oldCap)
        newCap = 0xFFFFFFFF;
    else
    {
        newCap = (oldCap >> 1) + oldCap;
        if (newCap < newSize)
            newCap = newSize;
    }

    FUN_004435c0(); // Allocate new buffer
    VectorElement* newElem = reinterpret_cast<VectorElement*>(0) + oldSize; // Placeholder

    newElem->id = elem->id;
    newElem->pad = 0;
    newElem->field8 = elem->field8;
    newElem->fieldC = elem->fieldC;

    elem->id = 0;
    elem->pad = 0;
    elem->field8 = 0;
    elem->fieldC = 0;

    // Move old elements
    VectorElement* oldBegin = container[0];
    if (end != container[1])
        FUN_004436c0(nullptr, oldBegin);
    FUN_004436c0(nullptr, oldBegin);

    FUN_00443710(nullptr, newSize, newCap);
    FUN_00443620();

    return newElem;
}

} // namespace Giants
