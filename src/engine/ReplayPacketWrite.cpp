// Giants Engine - Replay/Network Packet Writer Implementation
// Reverse engineered from GiantsMain.exe v1.520.59
#include "ReplayPacketWrite.h"
#include <cstdint>
#include <cstring>

namespace Giants {

// ─── Shared globals ────────────────────────────────────────────
extern int      DAT_006ff960;   // Replay mode (6 = recording)
extern int*     DAT_0073d750;   // Replay write buffer pointer
extern int      DAT_0073d748;   // Buffer base/start address

// ─── External callee ──────────────────────────────────────────
extern void FUN_0046ccf0();     // Buffer overflow handler

// ═══════════════════════════════════════════════════════════════════
// ReplayPacketWrite (FUN_00469f80) — 15 callers — PASS
// ═══════════════════════════════════════════════════════════════════
// Packet format in replay buffer:
//   [opcode=8] [totalSize] [entityId(+0x1d4)] [flag(param_5)]
//   [extraFlag(+0x22c)] [data...N bytes]

void ReplayPacketWrite(int entity, int param2, int param3, int dataSize,
                       uint8_t flag, void* data)
{
    // Only write when in replay recording mode
    if (DAT_006ff960 != 6) {
        return;
    }

    int totalSize = dataSize + (param2 + param3) * 4;

    // Bounds check: ensure buffer doesn't overflow 0x3FF bytes from base
    if (reinterpret_cast<int>(DAT_0073d750) + totalSize - DAT_0073d748 > 0x3FF) {
        FUN_0046ccf0();  // Flush/reset buffer
    }

    // Write header
    *reinterpret_cast<uint8_t*>(DAT_0073d750) = 8;  // Opcode
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + 1);

    *DAT_0073d750 = totalSize + 0x0B;  // Total packet size + header
    DAT_0073d750 = DAT_0073d750 + 1;

    *DAT_0073d750 = *reinterpret_cast<int*>(entity + 0x1d4);  // Entity ID
    DAT_0073d750 = DAT_0073d750 + 1;

    *reinterpret_cast<uint8_t*>(DAT_0073d750) = flag;  // Flag byte
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + 1);

    *reinterpret_cast<uint8_t*>(DAT_0073d750) =
        *reinterpret_cast<uint8_t*>(entity + 0x22c);  // Extra flag
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + 1);

    // Write payload data
    if (totalSize != 0) {
        memcpy(DAT_0073d750, data, totalSize);
    }
    DAT_0073d750 = reinterpret_cast<int*>(reinterpret_cast<int>(DAT_0073d750) + totalSize);
}

} // namespace Giants
