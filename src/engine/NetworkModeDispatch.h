// Giants Engine - Network Mode Dispatch (complex game state machine)
// Reverse engineered from GiantsMain.exe v1.520.59
#pragma once
#include <cstdint>
namespace Giants {
// ─── NetworkModeDispatch (FUN_00504a20) ── FAIL (usable ~70%) ──
// PS2-PROVEN name: "inv_award_item" (conf 0.9, string InvChPickupItem).
// Awards an item to the player inventory — NOT a network dispatch. The recomp
// mis-named it from call-graph location; PS2 debug symbol corrects. 819 lines
// of decompiled item-award logic. 10 callers, many callees.
void NetworkModeDispatch();  // FUN_00504a20 — PS2 "inv_award_item"
} // namespace Giants
