// Giants Vanilla-Native Recomp — TEXMEM section handler (FUN_0049a580).
//
// Faithful C++ port of vanilla Giants.exe FUN_0049a580 @ 0x49a580 (base
// 0x400000). This function is called by the .BIN loader FUN_004b7c50 at
// [0x4b7d12..0x4b7d18] AFTER SEEK'ing the stream to header[2] (the "texmem"
// section offset) and BEFORE SEEK'ing to header[1] (name_list) + FUN_0050d8f0.
//
// CALL ORDER in FUN_004b7c50 (verified by esp-tracking on the cdecl calls):
//   [0x4b7d09] mov eax, header[2]
//   [0x4b7d12] call FUN_0051d7b0(stream, header[2])   ; SEEK texmem
//   [0x4b7d18] call FUN_0049a580(stream)              ; ← THIS (reads texmem)
//   [0x4b7d24] call FUN_0051d7b0(stream, header[1])   ; SEEK name_list
//   [0x4b7d32] call FUN_0050d8f0(name, stream)        ; populate texture list
//
// WHAT FUN_0049a580 ACTUALLY DOES (capstone-verified against Giants.exe):
//   It is the loader for a versioned per-texture "memory layout" table stored
//   in a global pool at DAT_0063141c (stride 0x2c, capacity 0x7d0=2000 slots).
//   The on-disk texmem section is a SMALL HEADER + an array of per-texture
//   records. For w_intro_island.bin the section is 20 bytes:
//       ff ff ff ff | 02 11 22 33 | 00 00 00 00 | 28 00 00 00 | 14 00 00 00
//   meaning: sentinel(-1), magic 0x33221100, 0, record_size 0x28, total 0x14.
//   The 20-byte section == header-only (no per-texture records), so the
//   per-entry loop [0x49a6bf..0x49a8ed] executes ZERO iterations for this file.
//
// IMPORTANT — this function does NOT establish TextureEntry +0x08 link-nodes.
//   The renderer (gg_dx7r.dll) slot +0xb4 reads entry+0x08 as a renderer-side
//   list-node pointer; that node is allocated + assigned by the RENDERER DLL
//   itself when it creates a D3D texture surface (via a different slot), not
//   by any Giants.exe function in the texture-list path. See
//   RE_docs/TEXMEM_HANDLER.md for the full evidence.
//
// Allocator debug tags in vanilla push 'C:\Giants\Source\main\noise.c' +
// 'sounds' for the DAT_0063141c pool — these are SHARED debug strings, not a
// semantic identifier (the same allocator macro is used across subsystems).
#pragma once
#include <cstdint>

extern "C" {

// FUN_0049a580 — TEXMEM section reader.
//   arg1 (stream) = engine file handle, already SEEK'd to header[2].
// Reads the versioned header, (optionally) per-texture records into the
// DAT_0063141c pool. For w_intro_island.bin this is a header-only no-op loop.
void FUN_0049a580(uint32_t stream);

} // extern "C"
