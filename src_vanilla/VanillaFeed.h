// Giants Vanilla-Native Recomp — texture-list feed to renderer.
//
// Recipe (per RE_docs/OBJECT_VTABLE_SYSTEM.md §7 + capstone verification of
// FUN_004b7c50):
//   1. Open w_intro_island.bin via the engine file API.
//   2. Parse magic + 7-u32 header.
//   3. SEEK to header[2] (texmem section) and call FUN_0049a580(stream)
//      — the versioned texmem-header reader (VanillaTexmem.cpp).
//   4. SEEK to header[1] (name_list section) and call FUN_0050d8f0(name, handle)
//      to populate g_TextureEntityList (DAT_005a78b4).
//   5. Call SceneWalk_Textures() (FUN_0050e4d0 port) to dispatch each texture
//      sub-entry to renderer slot +0xb4 (RVA 0xc6a0 in gg_dx7r.dll).
//
// Section provenance (esp-tracked on the cdecl calls in FUN_004b7c50):
//   header[2] = texmem     → SEEK'd @ [0x4b7d12] then FUN_0049a580 @ [0x4b7d18]
//   header[1] = name_list  → SEEK'd @ [0x4b7d26] then FUN_0050d8f0 @ [0x4b7d32]
// (The disasm's [esp+0xa0] at 0x4b7d09 resolves to header[2] because the 3
//  cdecl pushes for the header read at 0x4b7d04 are not cleaned before 0x4b7d09.)
//
// NOTE: FUN_0049a580 does NOT establish TextureEntry +0x08 link-nodes — see
// RE_docs/TEXMEM_HANDLER.md. The renderer's slot+0xb4 early-return on a NULL
// entry+0x08 is expected until the renderer-side texture-surface creation path
// is wired (a separate layer).
#pragma once
#include <cstdint>

extern "C" {

// Feed the level's texture list into g_TextureEntityList and dispatch each
// entry to the renderer via slot +0xb4. Returns the number of texture entries
// dispatched (0 on failure).
uint32_t VanillaFeedTextures(void);

} // extern "C"
