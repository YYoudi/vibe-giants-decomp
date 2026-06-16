// Giants Vanilla-Native Recomp — engine-state globals + scene-system building blocks.
// These are the vanilla .data globals the scene/render system uses (addresses from
// RE_docs/SCENE_SYSTEM.md). Declared here as the recomp's engine-state layer so ported
// scene functions can reference them. Layouts confirmed by disasm + PS2 symbols.
#pragma once
#include <cstdint>

extern "C" {

// ── Renderer ──
extern void* g_vRenderer;          // DAT_00654940 — the GDVSysCreate renderer object (defined in VanillaRenderer.cpp)

// ── Scene pipeline gate ──
extern uint32_t g_ScenePipelineGate;   // DAT_0058c15c — set by FUN_004290f0(1) to enable scene rendering

// ── Engine render lists (.data linked-list heads) ──
//   DAT_005a78b4 — texture/entity list head (insert = FUN_0050d8f0)
//   DAT_006313c8 — placed-objects/entities list head (insert = FUN_004b50b0)
// These are circular self-referential lists (head->next == head when empty).
extern uint32_t g_TextureEntityList;   // DAT_005a78b4
extern uint32_t g_PlacedObjectList;    // DAT_006313c8

// ── Level table ──
extern uint32_t g_LevelTable;          // DAT_00631388 — populated by FUN_004b77f0 from WorldList.bin

// FUN_004290f0(arg) — scene-pipeline gate activator. Trivial: stores arg into the gate.
//   disasm: mov eax,[esp+4]; mov [0x58c15c],eax; ret
void FUN_004290f0(uint32_t arg);

} // extern "C"
