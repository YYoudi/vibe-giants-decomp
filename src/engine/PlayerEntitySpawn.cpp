// Giants Engine - Player Entity Spawn Check Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "PlayerEntitySpawn.h"
#include <cstdint>
namespace Giants {
extern int DAT_006ff960;     // Game mode (6 = dedicated)
extern int DAT_00702964;     // Is dedicated server
extern uint8_t DAT_006ff8fc[]; // Player level array
extern float DAT_006ff898[];  // Player score/skill array
extern uint32_t DAT_006ff910[]; // Player config array

// External: FUN_00463850 — EntityFindByFlag
extern int EntityFindByFlag();
// External: FUN_00469310 — Spawn effect
extern void SpawnEffect(int a, int b, uint32_t c, int d, uint32_t e, int f);
// External: FUN_00463890 — Entity update
extern void EntityUpdate();
// External: FUN_0045fe10 — Dispatch game command
extern void DispatchGameCommand(void* cmd);

void PlayerEntitySpawn(unsigned int playerIndex, uint8_t param_2)
{
    // Skip on dedicated server
    if (DAT_006ff960 != 6) return;
    if (DAT_00702964 == 0) return;

    bool canSpawn = false;

    if (playerIndex < 0x14) {
        // Check if player level ≥ 0xE (14)
        canSpawn = DAT_006ff8fc[playerIndex] >= 0x0E;

        if (canSpawn) {
            int entity = EntityFindByFlag();
            if (entity == 0) goto done_check;
            // Check health vs threshold at +0x20c vs +0x2c8
            float health = *reinterpret_cast<float*>(entity + 0x20C);
            float threshold = *reinterpret_cast<float*>(entity + 0x2C8);
            if (health < threshold || health == threshold) {
                canSpawn = false;
            }
        }

        if (canSpawn) {
            if ((int)playerIndex < 0) goto done_check;
            if (DAT_006ff898[playerIndex] <= 0.0f) {
                canSpawn = false;
                goto done_check;
            }
            // Spawn visual effect
            SpawnEffect(0, 0, 0x3F800000, 0, 0x3F800000, 0);
        }
    } else {
        canSpawn = false;
    }

done_check:
    // Build command struct
    uint8_t cmd[8];
    cmd[0] = 0x0E;        // Command type
    cmd[4] = 0;            // Unused
    cmd[1] = param_2;      // Parameter 2
    cmd[5] = canSpawn ? 1 : 0;  // Can spawn flag

    // Set player config value
    if ((int)playerIndex >= 0) {
        *reinterpret_cast<uint32_t*>(&cmd[2]) = DAT_006ff910[playerIndex];
    } else {
        *reinterpret_cast<uint32_t*>(&cmd[2]) = 0;
    }

    EntityUpdate();
    DispatchGameCommand(cmd);
}
} // namespace Giants
