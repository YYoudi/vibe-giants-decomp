// Giants Engine - Entity Lookup Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "EntityLookup.h"
#include <cstdint>

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
// Container: array of 8-byte entries (pointer + metadata)
// Each pointer targets: { int id; char flag; ... }
extern int** g_entityContainerBegin;  // DAT_00749914
extern int** g_entityContainerEnd;    // DAT_00749918
extern int   g_gameState;             // DAT_006ff960 (6 = in-game)

// ═══════════════════════════════════════════════════════════════════
// FindEntityById (FUN_0056e960) — 35 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Linear scan through entity container for matching ID.
// The game state (DAT_006ff960) determines which entries are
// valid matches:
//   - gameState != 6: returns entry if flag==0 (not active)
//   - gameState == 6: returns entry if flag!=0 (active), or
//     stores last entry with flag==0 as fallback result.

int* FindEntityById(int targetId)
{
    // Bounds check
    int count = reinterpret_cast<int>(g_entityContainerEnd)
              - reinterpret_cast<int>(g_entityContainerBegin);
    if (targetId < 0 || count / 8 <= targetId) {
        return nullptr;
    }

    int* result = nullptr;
    int** current = g_entityContainerBegin;

    while (true) {
        if (current == g_entityContainerEnd) {
            return result;
        }

        int* entry = reinterpret_cast<int*>(*current);

        if (*entry == targetId) {
            char flag = static_cast<char>(entry[1]);

            if (g_gameState != 6) {
                if (flag != '\0') goto continue_loop;
                if (g_gameState != 6) {
                    if (flag == '\0') {
                        return entry;
                    }
                    if (g_gameState != 6) goto continue_loop;
                }
            }
            // g_gameState == 6 path
            if (flag != '\0') {
                return entry;
            }
            if (g_gameState == 6 && flag == '\0') {
                result = entry;
            }
        }

    continue_loop:
        current = current + 2;  // 8 bytes per entry
    }
}

} // namespace Giants
