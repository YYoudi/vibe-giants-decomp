// Giants Engine - Input Key Query Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "InputKeyQuery.h"
#include <cstdint>

namespace Giants {

// ═══════════════════════════════════════════════════════════════════
// QueryInputKey2 (FUN_00630c40) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Reads 2 key/button states via input vtable dispatch.
// param_1: input context object (has vtable with query method at slot 2)
// param_2: first key index
// param_3: second key index
// Returns: (key2_state << 8) | key1_state

uint32_t QueryInputKey2(int context, int key1Index, int key2Index)
{
    if (context == 0) return 0;

    // vtable[2] is the key state query function
    // Signature: int query(int context, int keyIndex) → 0 or 1
    int* vtable = *reinterpret_cast<int**>(context);
    typedef int (*KeyQueryFn)(int, int);
    KeyQueryFn queryKey = reinterpret_cast<KeyQueryFn>(vtable[2]);

    int state1 = queryKey(context, key1Index);
    int state2 = queryKey(context, key2Index);

    return static_cast<uint32_t>(state1 | (state2 << 8));
}

// ═══════════════════════════════════════════════════════════════════
// QueryInputKey4 (FUN_00630840) — 23 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Reads 4 key/button states via input vtable dispatch.
// param_1: input context object (has vtable with query method at slot 2)
// param_2: first key index
// param_3: second key index
// param_4: third key index
// param_5: fourth key index
// Returns: (key4 << 24) | (key3 << 16) | (key2 << 8) | key1

uint32_t QueryInputKey4(int context, int key1Index, int key2Index, int key3Index, int key4Index)
{
    if (context == 0) return 0;

    int* vtable = *reinterpret_cast<int**>(context);
    typedef int (*KeyQueryFn)(int, int);
    KeyQueryFn queryKey = reinterpret_cast<KeyQueryFn>(vtable[2]);

    int state1 = queryKey(context, key1Index);
    int state2 = queryKey(context, key2Index);
    int state3 = queryKey(context, key3Index);
    int state4 = queryKey(context, key4Index);

    return static_cast<uint32_t>(
        state1 | (state2 << 8) | (state3 << 16) | (state4 << 24));
}

} // namespace Giants
