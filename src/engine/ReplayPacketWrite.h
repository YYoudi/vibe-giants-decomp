// Giants Engine - Replay/Network Packet Writer
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ReplayPacketWrite (FUN_00469f80) ── PASS ──
// Writes a packet into the replay/network buffer (DAT_0073d750).
// Only active when DAT_006ff960 == 6 (replay recording mode).
// Writes: opcode(1) + size(1) + entityId(1) + flag(1) + extraFlag(1) + data(N).
// 15 callers, 2 callees (memcpy, bounds check).
void ReplayPacketWrite(int entity, int param2, int param3, int dataSize,
                       uint8_t flag, void* data);  // FUN_00469f80

} // namespace Giants
