// Giants Vanilla-Native Recomp — texture-list feed to renderer.
//
// Recipe (per RE_docs/OBJECT_VTABLE_SYSTEM.md §7):
//   1. Open w_intro_island.bin via the engine file API.
//   2. Parse magic + 7-u32 header.
//   3. SEEK to header[1] (name_list section) and call FUN_0050d8f0(name, handle)
//      to populate g_TextureEntityList (DAT_005a78b4).
//   4. Call SceneWalk_Textures() (FUN_0050e4d0 port) to dispatch each texture
//      sub-entry to renderer slot +0xb4 (RVA 0xc6a0 in gg_dx7r.dll).
//
// Section provenance (capstone-verified from FUN_004b7c50):
//   header[1] = name_list  → SEEK'd then passed to FUN_0050d8f0 @ 0x4b7d26
//   header[2] = texmem     → SEEK'd then passed to FUN_0049a580 @ 0x4b7d12
// FUN_0050d8f0 reads ONLY the name_list section (header[1]).
#pragma once
#include <cstdint>

extern "C" {

// Feed the level's texture list into g_TextureEntityList and dispatch each
// entry to the renderer via slot +0xb4. Returns the number of texture entries
// dispatched (0 on failure).
uint32_t VanillaFeedTextures(void);

} // extern "C"
