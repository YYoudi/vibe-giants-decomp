// Giants Vanilla-Native Recomp — engine-state globals + scene-system building blocks.
#include "VanillaEngine.h"

extern "C" {

// Engine-state globals (zero-init; populated as scene functions are ported).
uint32_t g_ScenePipelineGate  = 0;   // DAT_0058c15c
uint32_t g_TextureEntityList  = 0;   // DAT_005a78b4 (list head; self-ref when empty)
uint32_t g_PlacedObjectList   = 0;   // DAT_006313c8
uint32_t g_LevelTable         = 0;   // DAT_00631388

// FUN_004290f0(arg) — scene-pipeline gate activator (vanilla 0x4290f0).
//   disasm: mov eax,[esp+4]; mov [0x58c15c],eax; ret
// Sets DAT_0058c15c; the renderer's ScenePipelineEntry (UpCalls callback[20]) checks
// it before walking the render lists. WinMain calls FUN_004290f0(1) after scene load.
void FUN_004290f0(uint32_t arg) {
    g_ScenePipelineGate = arg;
}

} // extern "C"
