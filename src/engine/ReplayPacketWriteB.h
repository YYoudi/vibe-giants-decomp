// Giants Engine - Replay Packet Write B
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── ReplayPacketWriteB (FUN_00469ec0) ── PASS ──
// Writes a replay packet with type byte 8, size, entity ID, flags, and payload.
// Only writes when DAT_006ff960 == 6 (replay recording mode). 14 callers, 2 callees.
void ReplayPacketWriteB(int entity, size_t payloadSize, uint8_t flag, void* payload);  // FUN_00469ec0
} // namespace Giants
