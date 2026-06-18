// Giants Vanilla-Native Recomp — stobj position/transform apply (FUN_00472560 port).
// Faithful port of vanilla FUN_00472560 (size 414). Called by the placement reader to
// apply a placed object's position quaternion to its local matrix + resolve attachment
// slots. See vanilla_decompiled/00472560.json. Callees not yet ported are extern/stubbed.
#pragma once
#include <cstdint>

extern "C" {
// Apply position quaternion (4 dwords) to stobj's local matrix (+0x100) and resolve
// attachment-slot index (stobj+0xe8) from the placed-object list. (vanilla FUN_00472560)
void FUN_00472560(int stobj, uint32_t* pos);
}
