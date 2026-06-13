// Giants Engine - Extended Math Utilities Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MathUtilsExtended.h"
#include "CRTStubs.h"
#include <cmath>
#include <cstring>

namespace Giants {

// --- runtime state globals (were *reinterpret_cast derefs; engine-populated) ---
static uint32_t g_state_00702c20 = 0;  // was @0x0X00702C20
static uint32_t g_state_00702c1c = 0;  // was @0x0X00702C1C
static uint32_t g_state_00702c24 = 0;  // was @0x0X00702C24
static uint32_t g_state_00702c28 = 0;  // was @0x0X00702C28

// ═══════════════════════════════════════════════════════════════════
// AngleDiff (FUN_00638870) — 33 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Computes shortest angular difference between two angles (degrees).
// Normalizes both to [0, 360), then wraps difference to [-180, 180].

float AngleDiff(float angle1, float angle2)
{
    // Normalize angle1 to [0, 360)
    if (angle1 >= 0.0f)
    {
        if (angle1 >= 360.0f)
            angle1 = fmodf(angle1, 360.0f);
    }
    else
    {
        angle1 = fmodf(angle1, 360.0f) + 360.0f;
    }

    // Normalize angle2 to [0, 360)
    if (angle2 >= 0.0f)
    {
        if (angle2 >= 360.0f)
            angle2 = fmodf(angle2, 360.0f);
    }
    else
    {
        angle2 = fmodf(angle2, 360.0f) + 360.0f;
    }

    // Compute difference and wrap to [-180, 180]
    float diff = angle1 - angle2;

    if (diff > 180.0f)
        return diff - 360.0f;

    if (diff < -180.0f)
        return diff + 360.0f;

    return diff;
}

// ═══════════════════════════════════════════════════════════════════
// Vector3Distance (FUN_00638c80) — 33 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Computes 3D Euclidean distance. Uses double precision for the
// squared sum to maintain precision, then sqrt.

float Vector3Distance(const float* p1, const float* p2)
{
    float dx = p2[0] - p1[0];
    float dy = p2[1] - p1[1];
    float dz = p2[2] - p1[2];

    double distSq = static_cast<double>(dx * dx + dy * dy + dz * dz);

    if (distSq >= 0.0)
    {
        return static_cast<float>(sqrt(distSq));
    }

    // Fallback for negative (shouldn't happen with real data)
    return static_cast<float>(sqrt(fabs(distSq)));
}

// ═══════════════════════════════════════════════════════════════════
// ClearAndFree (FUN_0042b2c0) — 33 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// STL vector clear-and-free: destroys elements, frees buffer,
// resets to null. Handles MSVC aligned allocation scheme.

extern void DestroyElementRange(int* begin);  // FUN_0042b650

void ClearAndFree(int** container)
{
    int* begin = container[0];
    if (begin == nullptr)
        return;

    // Destroy all elements
    DestroyElementRange(begin);

    // Calculate size in bytes, rounded to 8-byte alignment
    unsigned int size = (reinterpret_cast<unsigned int>(container[2]) -
                        reinterpret_cast<unsigned int>(begin)) & 0xFFFFFFF8;

    int* block = begin;

    // MSVC big allocation threshold
    if (size > 0xFFF)
    {
        // For big blocks, actual base is at ptr[-4]
        block = reinterpret_cast<int*>(begin[-4]);
        size = size + 0x23;

        // Validate header distance (heap corruption check)
        unsigned int headerDist = static_cast<unsigned int>(begin - block) - 4U;
        if (headerDist > 0x1F)
        {
            // Heap corruption — original calls _invoke_watson
            std::abort();
        }
    }

    CRTFree(block);

    container[0] = nullptr;
    container[1] = nullptr;
    container[2] = nullptr;
}

// ═══════════════════════════════════════════════════════════════════
// VectorAssign (FUN_0061d7b0) — 34 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// STL vector<uint32_t>::assign(data, data+count).
// Copies count elements, growing buffer with 1.5x strategy.

extern void VectorReserve(uint32_t* vec, uint32_t newCap);  // FUN_0061d720

void VectorAssign(uint32_t* thisPtr, const uint32_t* data, uint32_t count)
{
    uint32_t* begin = reinterpret_cast<uint32_t*>(thisPtr[0]);
    uint32_t oldCapacity = (thisPtr[2] - thisPtr[0]) >> 2;

    if (count <= oldCapacity)
    {
        uint32_t oldSize = (thisPtr[1] - thisPtr[0]) >> 2;

        if (count <= oldSize)
        {
            memmove(begin, data, count * 4);
            thisPtr[1] = reinterpret_cast<uint32_t>(begin) + count * 4;
            return;
        }

        memmove(begin, data, oldSize * 4);
        uint32_t* endPtr = reinterpret_cast<uint32_t*>(thisPtr[1]);
        uint32_t tailBytes = (count - oldSize) * 4;
        memmove(endPtr, reinterpret_cast<const uint8_t*>(data) + oldSize * 4, tailBytes);
        thisPtr[1] = tailBytes + reinterpret_cast<uint32_t>(endPtr);
        return;
    }

    // Overflow check
    if (count > 0x3FFFFFFF)
    {
        ThrowVectorTooLong();
    }

    // Grow: 1.5x or count, whichever is larger
    uint32_t newCap;
    if (0x3FFFFFFF - (oldCapacity >> 1) < oldCapacity)
    {
        newCap = 0x3FFFFFFF;
    }
    else
    {
        newCap = (oldCapacity >> 1) + oldCapacity;
        if (newCap < count)
            newCap = count;
    }

    // Free old buffer
    if (begin != nullptr)
    {
        uint32_t allocSize = oldCapacity * 4;
        void* block = begin;

        if (allocSize > 0xFFF)
        {
            block = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(begin) - 4);
            allocSize += 0x23;

            if (static_cast<unsigned int>(reinterpret_cast<uint8_t*>(begin) - static_cast<uint8_t*>(block)) - 4U > 0x1F)
            {
                std::abort();  // _invoke_watson
            }
        }

        CRTFree(block);
        thisPtr[0] = 0;
        thisPtr[1] = 0;
        thisPtr[2] = 0;
    }

    VectorReserve(thisPtr, newCap);

    uint32_t* newBegin = reinterpret_cast<uint32_t*>(thisPtr[0]);
    memmove(newBegin, data, count * 4);
    thisPtr[1] = count * 4 + reinterpret_cast<uint32_t>(newBegin);
}

// ═══════════════════════════════════════════════════════════════════
// ResetEntityBuffers (FUN_00541080) — 34 callers — FAIL (usable ~85%)
// ═══════════════════════════════════════════════════════════════════
// Resets render entity buffers and state. Steps:
//   1. Free descriptor array entries (8 entries of stride 12)
//   2. Walk linked list, free buffers
//   3. Set flag 0x8000 on type-0x4E entities with flag 0x400
//   4. Remove list entries with flag 0x4000
//   5. Conditional flush
//   6. Reset state buffer preserving sentinel values

extern void FlushEntityCommand();       // FUN_004ea1b0
extern void* RemoveListEntry();          // FUN_004ea130
extern void FlushPendingRender();       // FUN_004e9870

// Globals for entity buffer system
static uint32_t DAT_0074892c = 0;
static int* DAT_00748b54 = nullptr;     // Buffer descriptor array start
static int* DAT_00748b48 = nullptr;     // Linked list head
static uint32_t DAT_00748b44 = 0;       // Flush flag
static uint32_t* DAT_00747d40 = nullptr; // Entity list 1
uint32_t* DAT_007027a8 = nullptr; // Entity list 2

void ResetEntityBuffers()
{
    DAT_0074892c = 0;

    // Free descriptor array entries (stride 12: ptr, count, ?)
    int* piVar5 = DAT_00748b54;
    do
    {
        if (piVar5[0] != 0)
        {
            int iVar6 = 0;
            if (0 < piVar5[1])
            {
                do
                {
                    FlushEntityCommand();
                    iVar6++;
                } while (iVar6 < piVar5[1]);
            }
            free(reinterpret_cast<void*>(piVar5[0]));
            piVar5[0] = 0;
        }
        piVar5 = piVar5 + 3;
    } while (reinterpret_cast<uintptr_t>(piVar5) < 0x749004);

    // Walk linked list via +0x50 next, free buffers at +0x48/+0x4c
    for (int* link = reinterpret_cast<int*>(DAT_00748b48); link != nullptr;
         link = reinterpret_cast<int*>(link[0x14]))
    {
        if (link[0x12] != 0)
        {
            int iVar7 = 0;
            if (0 < link[0x13])
            {
                do
                {
                    FlushEntityCommand();
                    iVar7++;
                } while (iVar7 < link[0x13]);
            }
            free(*reinterpret_cast<void**>(&link[0x12]));
            link[0x12] = 0;
        }
    }

    // Walk entity list, set flag 0x8000 on type 0x4E entities with flag 0x400
    // Note: re-agent flagged potential iterator swap with next loop
    for (uint32_t* puVar4 = DAT_00747d40; puVar4 != nullptr;
         puVar4 = reinterpret_cast<uint32_t*>(puVar4[0]))
    {
        uint32_t* entity = reinterpret_cast<uint32_t*>(puVar4[3]);
        if ((entity[0x8B] == 0x4E) && ((entity[0x4C] & 0x400) != 0))
        {
            entity[0x49] = entity[0x49] | 0x8000;
        }
    }

    // Walk another linked list, remove entries with flag 0x4000
    uint32_t* puVar1 = DAT_007027a8;
    while (puVar1 != nullptr)
    {
        if ((puVar1[6] & 0x4000) == 0)
        {
            puVar1 = reinterpret_cast<uint32_t*>(puVar1[0]);
        }
        else
        {
            puVar1 = reinterpret_cast<uint32_t*>(RemoveListEntry());
        }
    }

    // Conditional flush
    if (DAT_00748b44 != 0)
    {
        FlushPendingRender();
    }

    // Reset state buffer (0x74 bytes at DAT_00702c00), preserving sentinels
    uint32_t uVar3 = g_state_00702c20;
    uint32_t uVar2 = g_state_00702c1c;
    memset(reinterpret_cast<void*>(0x00702c00), 0, 0x74);
    g_state_00702c1c = uVar2;
    g_state_00702c24 = uVar2;
    g_state_00702c20 = uVar3;
    g_state_00702c28 = uVar3;
}

} // namespace Giants
