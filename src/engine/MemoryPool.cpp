// Giants Engine - SIMD Memory Pool Allocator Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "MemoryPool.h"
#include "CRTStubs.h"
#include <cstdlib>
#include <cstring>
#include <emmintrin.h>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static uint32_t* s_FreeListHead = nullptr;  // DAT_0073e790
static uint32_t* s_FreeListNext = nullptr;  // DAT_0073e794
static int g_SimdLevel = 0;                 // DAT_006fd52c — >= 2 enables SIMD

// Helper: extract int from __m128i (portable across MSVC/GCC)
static inline int extract_i32(__m128i v, int idx)
{
    int32_t vals[4];
    _mm_storeu_si128(reinterpret_cast<__m128i*>(vals), v);
    return vals[idx];
}

// ═══════════════════════════════════════════════════════════════════
// AllocateFreeBlock (FUN_0048ef70) — 34 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Allocates a 40-byte (10 uint32_t) block from a free-list pool.
// When the free list is empty, mallocs a new 0x1F44-byte block,
// then chains 198 slots into a linked list. Uses SSE2 SIMD for
// faster initialization when g_SimdLevel >= 2.

uint32_t* AllocateFreeBlock()
{
    uint32_t* slot = s_FreeListHead;

    if (s_FreeListHead != nullptr)
    {
        // Pop from free list
        s_FreeListHead = reinterpret_cast<uint32_t*>(*slot);
        memset(slot, 0, 40);
        return slot;
    }

    // Allocate new pool block (198 slots * 10 ints + header)
    uint32_t* block = reinterpret_cast<uint32_t*>(malloc(0x1F44));
    int idx = 0;
    slot = block;

    // Link block onto pool list
    *block = reinterpret_cast<uint32_t>(s_FreeListNext);
    s_FreeListNext = slot;

    // SIMD constants
    __m128i auVar9 = _mm_load_si128(reinterpret_cast<const __m128i*>(0x0066c3d0));

    int iVar8  = *reinterpret_cast<int*>(0x0066c38c);
    int iVar7  = *reinterpret_cast<int*>(0x0066c388);
    int iVar13 = *reinterpret_cast<int*>(0x0066c384);
    int iVar6  = *reinterpret_cast<int*>(0x0066c380);

    uint32_t* dataStart = block + 1;  // Skip header

    if (g_SimdLevel < 2)
    {
        // Scalar path: chain free-list entries
        int remaining = 0xC6 - idx;
        int offset = idx * 10;
        idx = 0xC6;
        uint32_t* p = dataStart + offset;

        do {
            *p = reinterpret_cast<uint32_t>(p + 10);
            remaining--;
            p += 10;
        } while (remaining != 0);
    }
    else
    {
        // SSE2 path: build 8 free-list entries at a time
        int iVar2 = extract_i32(auVar9, 0);
        int iVar3 = extract_i32(auVar9, 1);
        int iVar4 = extract_i32(auVar9, 2);
        int iVar5 = extract_i32(auVar9, 3);

        int32_t* p = reinterpret_cast<int32_t*>(block + 1 + 0x15);

        do {
            int idx1 = idx + 4;

            int32_t vals[4] = { idx + iVar6, idx + iVar13, idx + iVar7, idx + iVar8 };
            __m128i auVar15 = _mm_loadu_si128(reinterpret_cast<__m128i*>(vals));
            idx += 8;

            // SSE2 multiply — use _mm_mullo_epi16 as approximation since
            // _mm_mullo_epi32 is SSE4.1. For this use case the values are
            // small enough that the 16-bit multiply gives correct results.
            auVar15 = _mm_mullo_epi16(auVar15, auVar9);

            int32_t res[4];
            _mm_storeu_si128(reinterpret_cast<__m128i*>(res), auVar15);

            p[-0x14] = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar2 + res[0];
            p[-10]   = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar3 + res[1];
            *p       = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar4 + res[2];
            p[10]    = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar5 + res[3];

            int32_t vals2[4] = { idx1 + iVar6, idx1 + iVar13, idx1 + iVar7, idx1 + iVar8 };
            __m128i auVar16 = _mm_loadu_si128(reinterpret_cast<__m128i*>(vals2));
            auVar16 = _mm_mullo_epi16(auVar16, auVar9);

            int32_t res2[4];
            _mm_storeu_si128(reinterpret_cast<__m128i*>(res2), auVar16);

            p[0x14] = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar2 + res2[0];
            p[0x1E] = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar3 + res2[1];
            p[0x28] = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar4 + res2[2];
            p[0x32] = static_cast<int32_t>(reinterpret_cast<intptr_t>(dataStart)) + iVar5 + res2[3];

            p += 0x50;  // Advance by 80 ints (8 slots * 10)
        } while (idx < 0xC0);

        if (idx < 0xC6)
        {
            // Scalar tail
            int remaining = 0xC6 - idx;
            int offset = idx * 10;
            idx = 0xC6;
            uint32_t* q = dataStart + offset;

            do {
                *q = reinterpret_cast<uint32_t>(q + 10);
                remaining--;
                q += 10;
            } while (remaining != 0);
        }
    }

    // Null-terminate last slot
    dataStart[idx * 10] = 0;

    // Pop first block
    s_FreeListHead = reinterpret_cast<uint32_t*>(*dataStart);
    memset(dataStart, 0, 40);
    return dataStart;
}

} // namespace Giants
