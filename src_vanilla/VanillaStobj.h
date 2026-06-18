// Giants Vanilla-Native Recomp — stobj lifecycle callees (faithful ports).
// FUN_0049cfd0 (copy defaults into stobj) + FUN_0049f3b0 (set object kind).
// See vanilla_decompiled/0049cfd0.json + 0049f3b0.json. Callees extern/stubbed.
#pragma once
#include <cstdint>

extern "C" {
void FUN_0049ccf0(int stobj, int objData);    // init placed-object slot (vanilla 0049ccf0)
void FUN_0049cfd0(int stobj, int src);   // copy defaults (vanilla 0049cfd0)
void FUN_0049f3b0(int stobj, int kind);  // set object kind/subtype (vanilla 0049f3b0)
}
