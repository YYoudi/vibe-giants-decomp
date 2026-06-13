// Giants Engine - Element Lookup by ID Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ElementLookup.h"
#include <vector>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
extern int g_gameState;  // DAT_006ff960

struct Element {
    int id;      // offset 0
    bool flag;   // offset 4
};

// Global element list: begin=DAT_00749914, end=DAT_00749918
static std::vector<Element*> g_elementList;

// ═══════════════════════════════════════════════════════════════════
// FindElementById (FUN_0056e960) — 35 callers — FAIL (usable ~90%)
// ═══════════════════════════════════════════════════════════════════
// Searches element list for matching ID with game-state-dependent logic.
//   - If targetId < 0 or >= list size: returns nullptr
//   - Game state 6: prefer flagged elements, fallback to last unflagged match
//   - Other states: prefer unflagged elements

Element* FindElementById(int targetId)
{
    if (targetId < 0)
        return nullptr;

    size_t count = g_elementList.size();
    if (static_cast<int>(count) <= targetId)
        return nullptr;

    Element* fallback = nullptr;

    for (auto it = g_elementList.begin(); it != g_elementList.end(); ++it)
    {
        Element* elem = *it;

        if (elem->id != targetId)
            continue;

        if (g_gameState == 6)
        {
            if (elem->flag)
            {
                return elem;
            }
            fallback = elem;
        }
        else
        {
            if (!elem->flag)
            {
                return elem;
            }
        }
    }

    return fallback;
}

} // namespace Giants
