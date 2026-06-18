// Giants Vanilla-Native Recomp — SFX section loader (FUN_0049a580 port).
// Faithful port of vanilla FUN_0049a580 (size 904): lazily allocs the sounds table
// (DAT_0063141c, 2000 entries × 0xb dwords), then reads the SFX-def blob + per-sound
// records into it. See vanilla_decompiled/0049a580.json. Callees extern/stubbed.
#pragma once
#include <cstdint>

extern "C" {
void FUN_0049a580(uint32_t handle);   // load SFX section (vanilla 0049a580)
}
