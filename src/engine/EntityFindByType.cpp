// Giants Engine - Entity Find By Type Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityFindByType.h"
#include <cstdint>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static uint32_t DAT_007027a8 = 1410338561u;  // faithful @0x007027A8  // Entity linked list head

// ═══════════════════════════════════════════════════════════════════
// FindEntityByType (FUN_00463250) — 19 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Walks entity linked list at DAT_007027a8.
// Each node: [+0] next, [+12] entity ptr.
// Skips entities with flag 0x8000 set at entity+0x124.
// Matches on entity+0x1d4 == param_1 (type ID).

int FindEntityByType(int typeId)
{
    uint32_t* node = reinterpret_cast<uint32_t*>(DAT_007027a8);

    while (true) {
        if (node == nullptr) {
            return 0;
        }
        int entity = static_cast<int>(node[3]);  // entity ptr
        // Check: not flagged as removed, and type matches
        if ((*reinterpret_cast<uint32_t*>(entity + 0x124) & 0x8000) == 0 &&
            *reinterpret_cast<int*>(entity + 0x1d4) == typeId) {
            break;
        }
        node = reinterpret_cast<uint32_t*>(*node);  // next
    }

    return static_cast<int>(node[3]);
}

// ═══════════════════════════════════════════════════════════════════
// EntityFindByTypeMatch (FUN_0047c9c0) — 5 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Searches entity list at DAT_00701a3c+0x1BAC for entity matching
// param_1's +0x31C field. Walks at stride 0x24 in list at +0x1BB4.
// Checks flag 0x1000000 at entity+8.

int EntityFindByTypeMatch(int param_1)
{
    extern uint32_t DAT_00701a3c;

    int count = *reinterpret_cast<int*>(DAT_00701a3c + 0x1BAC);
    if (count == 0 || param_1 == 0) return 0;

    int matchId = *reinterpret_cast<int*>(param_1 + 0x31C);
    int* listBase = reinterpret_cast<int*>(*reinterpret_cast<int*>(DAT_00701a3c + 0x1BB4) + 4);

    for (int i = 0; i < count; i++) {
        int node = listBase[i * 9];  // stride 0x24 (9 * 4)
        if (node == 0) continue;
        if (*reinterpret_cast<uint32_t*>(node + 8) & 0x1000000) continue;  // skip flagged
        if (*reinterpret_cast<int*>(node + 0x31C) == matchId) {
            return node;
        }
    }
    return 0;
}

} // namespace Giants
