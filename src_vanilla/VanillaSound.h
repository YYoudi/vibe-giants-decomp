// Giants Vanilla-Native Recomp — sound loader (FUN_00491830 port).
// Faithful port of vanilla FUN_00491830 (size 240): registers a sound entry in the
// world_state sound table (+0x4554, 27 slots stride 0x30); for kind==2 also resolves
// the name index in the +0x2214 table (stride 0x118). See vanilla_decompiled/00491830.json.
#pragma once
#include <cstdint>

extern "C" {
void FUN_00491830(int kind, uint32_t arg2, const char* name);   // load sound (vanilla 00491830)
}
