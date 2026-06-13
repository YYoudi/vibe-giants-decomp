// Giants Engine - Entity Event Processing
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once

#include <cstdint>

namespace Giants {

// ─── ProcessEntityEvent (FUN_00500d30) ────────────────────────
// Main entity event dispatcher. Routes game events to entity handlers,
// applies scale factors, manages event recording buffer for replays,
// and checks audio triggers.
// 59 callers — core entity interaction system.
//
// Event flow:
//   1. Check processing flags (stop flags, entity visibility)
//   2. Resolve owner chain (param_2 → owner entity)
//   3. Apply scale factors (global + per-player)
//   4. Dispatch to handler table (if registered for entity type)
//   5. Record to replay buffer (if game mode == 6)
//   6. Call ProcessEventSecondary for non-replay mode
//   7. Check audio events
//
// Known issues from re-agent FAIL:
//   - Control flow at check_game_mode label needs verification
//   - Event handler array indexing (g_EventHandlers + index * 0x50)
//   - param_4 pointer arithmetic (8 vs 4 byte offset)
//   - Null check dereference needs void** cast
//
// @param param_1  Event type (0x00-0x46 range, special values 4,6,8,0xf,0x12,0x19,0x32)
// @param param_2  Entity pointer (with owner chain at +0x264)
// @param param_3  Secondary entity/context (type ID at +0x22c)
// @param param_4  Event data (uint64_t pair, nullable)
// @param param_5  Additional event parameter
// @param scaleIn  Scale value (passed via XMM1)
// @param extraIn  Extra parameter (passed via XMM2)
void ProcessEntityEvent(int param_1, int param_2, int param_3,
                        uint64_t* param_4, uint32_t param_5,
                        float scaleIn, uint32_t extraIn);  // FUN_00500d30

} // namespace Giants
