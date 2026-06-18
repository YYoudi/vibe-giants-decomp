// Giants Vanilla-Native Recomp — animation load (FUN_00405080 port).
// Faithful port of vanilla FUN_00405080 (size 369): loads an .anm, manages the anim
// cache list (DAT_00585354) with refcounts, builds an anim instance (scale math).
// See vanilla_decompiled/00405080.json. Callees extern/stubbed.
#pragma once
#include <cstdint>

extern "C" {
void FUN_00405080(char* animName);   // load .anm (vanilla 00405080)
}
