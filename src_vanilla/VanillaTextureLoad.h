// Giants Vanilla-Native Recomp — per-frame TEXTURE DATA loader.
//
// Faithful port of FUN_0050dd20 @ VA 0x50dd20 (vanilla Giants.exe, base 0x400000),
// confirmed by capstone disassembly (see RE_docs/TEXTURE_LOADER.md for the full
// trace). FUN_0050dd20 is the engine's per-frame texture-DATA loader: for a given
// TextureEntry it (a) asks the renderer to adjust the entry's mip-bias via slot
// +0xc0, and (b) if the entry has no pixel data yet (entry+0x04 == NULL), loads
// the .tga/.dds pixels from the level GZP, parses them, stores the pixel buffer
// pointer at entry+0x04, writes the format/mip fields (+0x14/+0x18/+0x1e) and
// raises the global "textures changed" flag DAT_005dcb14.
//
// *** WHAT THIS DOES NOT DO (decisive finding): ***
// FUN_0050dd20 does NOT create a D3D texture surface and does NOT write the
// renderer link-node at entry+0x08. entry+0x08 is written by the RENDERER's own
// slot +0xb0 (gg_dx7r.dll RVA 0xc030) — the texture-bind/create path — which is
// driven by the per-entity texture-bind walk at engine VA 0x4f3c20 (iterates an
// entity's texture array at +0x90, count +0x68, stride 0x50, and calls
// slot+0xb0(renderer, entry) for each entry needing bind). Slot +0xb0 allocates
// the 0xC-byte {next,prev,self} link-node, assigns it to entry+0x08, and inserts
// it into the renderer-internal list at obj+0x4e8. Slot +0xb4 (RVA 0xc6a0) then
// early-returns on a NULL entry+0x08 — that is the block being investigated, and
// FUN_0050dd20 alone does NOT unblock it. See RE_docs/TEXTURE_LOADER.md §4.
//
// FUN_0050dd20 signature (disasm-confirmed):
//   __cdecl void FUN_0050dd20(TextureEntry* entry);   // arg at [esp+0x1e0]
//   ([0x50dd27] mov ebx,[esp+0x1e0]  — ebx is the sole argument)
//
// Renderer slot invoked:
//   slot +0xc0 (gg_dx7r.dll RVA 0xae80) — `call [eax+0xc0]` at [0x50ddf5]
//   args (cdecl, this-first): (renderer, entry, 0, 0)
//   semantics: mip-bias / dimension adjuster; returns nonzero if the entry's
//   effective dimensions changed. NOT a surface creator.
#pragma once
#include <cstdint>

struct TextureEntry;   // defined in VanillaSceneTypes.h (stride 0x24)

extern "C" {

// Faithful port of vanilla FUN_0050dd20. Loads .tga/.dds pixel data for `entry`
// (looked up by entry name in the level GZP), stores the pixel buffer at
// entry+0x04, writes format/mip fields, raises DAT_005dcb14. Idempotent: if
// entry+0x04 is already set, returns immediately. Safe to call with a NULL entry
// or when the entry's owning node cannot be found.
void FUN_0050dd20(TextureEntry* entry);

// Helper: iterate g_TextureEntityList and call FUN_0050dd20 on every entry (loads
// all textures registered by VanillaFeedTextures). Returns the number of entries
// processed. Intended to be called once after VanillaFeedTextures() so the
// renderer's slot +0xb0 bind path (engine VA 0x4f3c20) has pixel data to upload.
void VanillaLoadAllTextures(void);

} // extern "C"
