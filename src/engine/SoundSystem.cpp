// Giants Engine - Sound System Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "SoundSystem.h"
#include "CRTStubs.h"

namespace Giants {

// ─── Globals ───────────────────────────────────────────────────
static uint32_t g_soundDisabled = 0;    // DAT_00702bb8 — audio mute flag
static void*    g_soundArray = nullptr; // DAT_00702800 — sound entry array
typedef int (*SoundPlayFunc)(SoundEntry*, uint32_t, uint32_t);
static SoundPlayFunc g_soundPlayFunc = nullptr;  // DAT_00728088

extern void SoundErrorLog(SoundEntry* entry, const char* msg, int len);  // FUN_00558f80

// ═══════════════════════════════════════════════════════════════════
// Sound_Play (FUN_005582f0) — 49 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Plays a sound effect by looking up the index in the global sound
// entry array (stride 0x2C = 44 bytes per entry). Checks that:
//   1. Sound system is not disabled (DAT_00702bb8 == 0)
//   2. Sound array exists (DAT_00702800 != null)
//   3. Entry has active flag (field_0x0 != 0)
//   4. Entry has valid flag (field_0x8 != 0)
// Then calls the registered play function (DAT_00728088).
// Logs error if play function returns 0.

int Sound_Play(int index, uint32_t param_2, uint32_t param_3)
{
    if (g_soundDisabled == 0 && g_soundArray != nullptr)
    {
        SoundEntry* entry = reinterpret_cast<SoundEntry*>(
            static_cast<intptr_t>(index) * 0x2c + reinterpret_cast<intptr_t>(g_soundArray)
        );

        if (entry->field_0x0 != 0 && entry->field_0x8 != 0)
        {
            int result = g_soundPlayFunc(entry, param_2, param_3);
            if (result == 0) {
                SoundErrorLog(entry, "SoundFail {0}", 0xd);
            }
            return result;
        }
    }

    return 0;
}

} // namespace Giants
