// Giants Engine - Effect Resource Reset Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EffectResources.h"

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static void** g_LookupTableBegin = nullptr;  // DAT_00749908
static void** g_LookupTableEnd = nullptr;    // DAT_0074990c

// ─── Forward declarations ──────────────────────────────────────
extern void    FUN_004ea1b0();                            // Resource cleanup
extern uint32_t FUN_004e9cd0(void* factoryArgs);          // Resource factory

// ═══════════════════════════════════════════════════════════════════
// ResetEffectResources (FUN_0058a270) — 24 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// 1. Look up effectId in g_LookupTableBegin/End (key at entry[0])
// 2. Clean up existing resources at state+0xfc0 and state+0xfc4
// 3. Reset state+0xd94 to 0
// 4. If entry+0x58 != 0, create two new resources via FUN_004e9cd0
// 5. Set state+0xd94 from entry+0x64

void ResetEffectResources(int* context, int effectId)
{
    // Resolve state pointer from context
    int* state = nullptr;
    if (context != nullptr)
    {
        state = reinterpret_cast<int*>(context[0x53]);  // offset 0x14c
    }

    if (effectId < -2)
        return;

    // Search lookup table for matching effectId
    void** tableIter = g_LookupTableBegin;
    void** tableEnd = g_LookupTableEnd;

    if (tableIter == tableEnd)
        return;

    int* foundEntry;
    while (true)
    {
        foundEntry = reinterpret_cast<int*>(*tableIter);
        if (*foundEntry == effectId)
            break;

        tableIter += 2;
        if (tableIter == tableEnd)
            return;
    }

    // Re-resolve state (context may have changed)
    int* resolvedState = nullptr;
    if (context != nullptr)
    {
        resolvedState = reinterpret_cast<int*>(context[0x53]);
    }

    // Clean up resource at offset 0xfc0
    if (resolvedState[0x3f0] != 0)
    {
        FUN_004ea1b0();
        resolvedState[0x3f0] = 0;
    }

    // Clean up resource at offset 0xfc4
    if (resolvedState[0x3f1] != 0)
    {
        FUN_004ea1b0();
        resolvedState[0x3f1] = 0;
    }

    // Reset effect parameter
    resolvedState[0x365] = 0;  // offset 0xd94

    // Check if entry has secondary resource flag
    if (foundEntry[0x16] != 0)
    {
        // Build factory args
        struct FactoryArgs {
            uint8_t  data[16];
            uint32_t size;      // offset 0x10
            uint32_t active;    // offset 0x14
            int*     contextPtr;
        } args;

        args.active = 0;
        args.size = 8;
        args.contextPtr = context;

        // Create primary resource
        uint32_t resource1 = FUN_004e9cd0(&args);
        args.active = 1;

        reinterpret_cast<uint32_t*>(state)[0x3f0] = resource1;

        // Create secondary resource
        uint32_t resource2 = FUN_004e9cd0(&args);
        reinterpret_cast<uint32_t*>(state)[0x3f1] = resource2;

        // Set effect parameter from entry
        state[0x365] = foundEntry[0x19];
        return;
    }

    // No secondary resource — just set the effect parameter
    state[0x365] = foundEntry[0x19];
}

} // namespace Giants
