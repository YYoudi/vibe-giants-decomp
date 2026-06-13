// Giants Engine - Visual Effect System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
//
// FUN_004e9cd0 — fx_create: creates visual effects (particles, flashes, etc.)
// Re-agent PASS (3 rounds), 169 callers.
#include <cstdlib>
#include <cstring>
#include "EffectSystem.h"
#include <cstring>
#include <windows.h>

namespace Giants {

// ─── Effect System Globals ──────────────────────────────────────
uint32_t  g_nextEffectId    = 0;           // DAT_00747d3c
uint32_t* g_effectListHead  = nullptr;     // DAT_00747d40
uint32_t* g_effectListTail  = nullptr;     // DAT_00747d44

// ─── External game state references ────────────────────────────
extern char     DAT_00702bdd;              // Disabled flag
extern int      DAT_006ff960;              // Game state (6 = multiplayer)
extern int      DAT_00702964;              // Network flag

// ─── Forward declarations for callees ──────────────────────────
char*         ResolveEffectOffsetImpl(uint32_t cookie);  // FUN_004e9ab0
uint32_t*     AllocateEffectNodeImpl();                   // FUN_004e9c70
void          ShowErrorDialog(const char* msg);           // FUN_0062edc0
const char*   GetDefaultEffectNameImpl();                 // FUN_004e98e0
void          InitEffectRenderStateImpl(uint32_t* e, int a, int b, int c);  // FUN_0063e480
void          PostEffectCreateImpl(int arg);              // FUN_004eadd0
void          DebugLogFmt(int level, int code, const char* msg);  // FUN_0043f440
void          FlushDebugLog();                            // FUN_004439b0

// ─── CreateEffect (FUN_004e9cd0) — PASS ─────────────────────────

uint32_t* CreateEffect(char* param_1, uint32_t param_2, int* param_3)
{
    // Guard: skip if disabled or in certain game modes
    if ((DAT_00702bdd != '\0') && (DAT_006ff960 == 6) && (DAT_00702964 != 0) &&
        ((param_2 & 0x82) == 0))
    {
        // Resolve the effect offset/position
        char* local_18;
        if ((param_2 & 0x10) == 0)
        {
            local_18 = ResolveEffectOffsetImpl(0);  // FUN_004e9ab0
        }
        else
        {
            local_18 = reinterpret_cast<char*>(*param_3);
        }

        if (reinterpret_cast<int>(local_18) > 0)
        {
            // Allocate effect node from pool
            uint32_t* effect = AllocateEffectNodeImpl();  // FUN_004e9c70
            if (effect == nullptr)
            {
                ShowErrorDialog("fx_create failed (too many effects running at once!!!)");
            }
            else
            {
                // Initialize node and link into doubly-linked list
                effect[0] = 0;  // prev
                if (g_effectListHead == nullptr)
                {
                    effect[1] = 0;
                    g_effectListHead = effect;
                }
                else
                {
                    effect[1] = reinterpret_cast<uint32_t>(g_effectListTail);
                    *g_effectListTail = reinterpret_cast<uint32_t>(effect);
                }
                g_effectListTail = effect;

                // Clear effect data (0xD8 bytes = 54 DWORDs after the 2 link pointers)
                memset(effect + 2, 0, 0xD8);

                // Copy name (max 32 chars)
                const char* name = param_1;
                if (name == nullptr)
                {
                    name = GetDefaultEffectNameImpl();  // FUN_004e98e0
                }
                if (name != nullptr)
                {
                    strncpy(reinterpret_cast<char*>(effect + 10), name, 0x20);

                    effect[2] = g_nextEffectId + reinterpret_cast<int>(local_18);
                    effect[5] = 0;

                    // Flag 0x08: extended position data (3 uint32)
                    if ((param_2 & 8) != 0)
                    {
                        *reinterpret_cast<uint64_t*>(effect + 7) =
                            *reinterpret_cast<uint64_t*>(param_3 + 1);
                        effect[9] = param_3[3];
                    }

                    // Flag 0x01: has origin entity + render state init
                    if ((param_2 & 1) != 0)
                    {
                        effect[6] |= 0x1000;
                        InitEffectRenderStateImpl(effect + 0x23,
                            param_3[8], param_3[9], param_3[7]);
                    }

                    // Flag 0x02: has target data
                    if ((param_2 & 2) != 0)
                    {
                        effect[0x34] = param_3[10];
                        effect[0x35] = param_3[0x0B];
                    }

                    // Flag 0x04: has entity reference
                    if ((param_2 & 4) != 0)
                    {
                        if (param_3[6] == 0)
                        {
                            return nullptr;
                        }
                        effect[6] |= 4;
                        effect[0x15] = param_3[6];
                        effect[0x16] = param_3[5];

                        // Check entity flag 0x400 — inherit render flags
                        if ((*reinterpret_cast<uint32_t*>(param_3[6] + 0x124) & 0x400) != 0)
                        {
                            if ((param_2 & 0x20) == 0)
                            {
                                param_2 |= 0x20;
                                param_3[4] = 0;
                            }
                            param_3[4] |= 1;
                        }
                    }

                    // Flag 0x40: has duration
                    if ((param_2 & 0x40) != 0)
                    {
                        effect[4] = param_3[0x0C];
                    }

                    // Flag 0x20: render flags from param_3[4]
                    if ((param_2 & 0x20) != 0)
                    {
                        uint32_t renderFlags = *reinterpret_cast<uint8_t*>(param_3 + 4);
                        if (renderFlags & 2)  effect[6] |= 0x4000;
                        if (renderFlags & 4)  effect[6] |= 0x8000;
                        if (renderFlags & 1)  effect[6] |= 0x10000;
                        if (renderFlags & 0x10) effect[6] |= 0x200000;
                        if (renderFlags & 8)  effect[6] |= 0x20000;
                    }

                    // Initialize AABB sentinel values (6 pairs, each sentinel = 0xFFFFFFFF)
                    effect[0x17] = 0;  effect[0x1D] = 0xFFFFFFFF;
                    effect[0x18] = 0;  effect[0x1E] = 0xFFFFFFFF;
                    effect[0x19] = 0;  effect[0x1F] = 0xFFFFFFFF;
                    effect[0x1A] = 0;  effect[0x20] = 0xFFFFFFFF;
                    effect[0x1B] = 0;  effect[0x21] = 0xFFFFFFFF;
                    effect[0x1C] = 0;  effect[0x22] = 0xFFFFFFFF;

                    // Post-creation callback
                    PostEffectCreateImpl(0);  // FUN_004eadd0

                    return effect;
                }

                // Error: missing effect name
                DebugLogFmt(6, 4, "fx_create failed: missing name for offset");
                FlushDebugLog();
            }
        }
    }

    return nullptr;
}

// ─── Stub implementations for callees ──────────────────────────
char*         ResolveEffectOffsetImpl(uint32_t) { return nullptr; }
uint32_t*     AllocateEffectNodeImpl()          { return nullptr; }
const char*   GetDefaultEffectNameImpl()        { return nullptr; }
void          InitEffectRenderStateImpl(uint32_t*, int, int, int) {}
void          PostEffectCreateImpl(int)         {}
void          DebugLogFmt(int, int, const char*) {}
void          FlushDebugLog()                   {}

} // namespace Giants
