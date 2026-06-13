// Giants Engine - Game Subsystem Init Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "GameSubsystemInit.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Globals (shared — many defined in other TUs) ──────────────
extern uint32_t DAT_0074892c;    // Active flag — ScenePipeline.cpp, MathUtilsExtended.cpp
static uint32_t& DAT_00748a40 = *reinterpret_cast<uint32_t*>(0x00748a40);  // Entity count A
static uint32_t& DAT_00748a30 = *reinterpret_cast<uint32_t*>(0x00748a30);  // Entity count B
static uint32_t& DAT_00748b48 = *reinterpret_cast<uint32_t*>(0x00748b48);  // Init phase flag
extern uint32_t DAT_00702d58;    // Callback arg — EntitySystem.cpp
extern uint32_t DAT_00702d50;    // Resolve callback ptr — GameCommand.cpp
static uint32_t& DAT_00702d54 = *reinterpret_cast<uint32_t*>(0x00702d54);  // Secondary callback
static uint32_t& DAT_00748b44 = *reinterpret_cast<uint32_t*>(0x00748b44);  // First-init flag
extern uint32_t DAT_00747d3c;    // Already initialized? — CRTStubs.cpp, EffectSystem.cpp
static uint32_t& DAT_0068298c = *reinterpret_cast<uint32_t*>(0x0068298c);  // Game context B
static uint32_t& DAT_00682e98 = *reinterpret_cast<uint32_t*>(0x00682e98);  // Game context A
extern int       g_activeArray[]; // DAT_00748b50 — ActiveIndex.cpp (entity state block)

// ─── Forward declarations ──────────────────────────────────────
extern void FUN_004e96b0();  // Audio/system initialization

// ═══════════════════════════════════════════════════════════════════
// InitGameSubsystem (FUN_00540fe0) — 21 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Resets the game subsystem to a clean state.
// 1. Sets active flag, clears entity counts
// 2. Installs default resolve callback (LAB_005411e0)
// 3. Zeroes state block (0x4b0 bytes = 1200 bytes at g_activeArray/DAT_00748b50)
// 4. On first init (DAT_00747d3c == 0): runs audio init, marks first-init
// 5. Always stores game context params

void InitGameSubsystem(uint32_t param_1, uint32_t param_2)
{
    DAT_0074892c = 1;
    DAT_00748a40 = 0;
    DAT_00748a30 = 0;
    DAT_00748b48 = 0;
    DAT_00702d58 = 0;
    DAT_00702d50 = 0;  // Will be set to resolve callback after zeroing
    DAT_00702d54 = 0;

    // Zero entity state block (0x4b0 = 1200 bytes)
    memset(g_activeArray, 0, 0x4b0);

    // Set resolve callback after zeroing
    DAT_00702d50 = 0;  // LAB_005411e0 placeholder — set after memset

    if (DAT_00747d3c == 0) {
        // First-time initialization
        FUN_004e96b0();
        DAT_0068298c = param_2;
        DAT_00748b44 = 1;
        DAT_00682e98 = param_1;
        return;
    }

    // Subsequent reset
    DAT_00682e98 = param_1;
    DAT_0068298c = param_2;
    DAT_00748b44 = 0;
}

} // namespace Giants
