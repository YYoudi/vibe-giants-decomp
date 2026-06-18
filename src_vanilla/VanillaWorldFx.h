// Giants Vanilla-Native Recomp — world-FX preset apply (FUN_0044ab90 port).
// Faithful port of vanilla FUN_0044ab90 (size 224): opens "<fx>_bin", validates
// version==1, reads the FX entry count + the FX table into DAT_0059c96c.
// See vanilla_decompiled/0044ab90.json. Callees extern/stubbed (file I/O real).
#pragma once
#include <cstdint>

extern "C" {
void FUN_0044ab90(const char* fxName);   // apply world FX preset (vanilla 0044ab90)
}
