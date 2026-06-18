// Giants Vanilla-Native Recomp — Object-placement reader (FUN_004b50b0).
//
// Faithful structural C++ port of vanilla Giants.exe FUN_004b50b0
// (base 0x400000, size 7693 bytes, 25 callees). The body is cited from
// `vanilla_decompiled/004b50b0.json`. Every control-flow decision and every
// on-disk field read below mirrors the decompiled structure; callees not yet
// ported are declared `extern "C"` and invoked verbatim with a
// `// FIXME(unverified): callee <addr>` tag, per anti-dérive doctrine.
//
// WHAT THE FUNCTION DOES (per decompiled body):
//   1. Prologue  FUN_00545ab0()                                         [0x4b50ba]
//   2. Read u32 odef_count; allocate odef node (count*4 + 8 hdr bytes);
//      head-insert into DAT_006313ac; read each odef name string + resolve
//      via FUN_00474d10 (object-definition lookup).                     [0x4b50bd..0x4b51d0]
//   3. Read u32 objl_count (iVar18); allocate objl node (count*0x464 + 8);
//      head-insert into DAT_006313b0.                                   [0x4b51f3..0x4b5256]
//   4. Per-object placement loop (count iterations):                    [0x4b5269..0x4b5d21]
//        - read opcode byte (0x51 'Q' .. 0xff)
//        - dispatch: placement sub-record readers for opcodes Q/Y/Z/[,
//          R (ref-name), V/W/X (mesh+pos+scale), 0x5c, 0x7f/0x80 (string
//          lists via FUN_0044acf0), 0x53/0x54 (slot tables), 0xff (end).
//   5. Read u32 atl_count (iVar18 @ 0x4b5d25); allocate atl node
//      (count*0x304 + 8); head-insert into DAT_006313b4.               [0x4b5d3a..0x4b5dc5]
//   6. Per-atl-entry attribute loop: FUN_0049c920 init, FUN_0049d2d0 type
//      resolve, then opcode switch (cases 0x01..0xff) writes entity
//      fields (flags, scale, light refs, shadow textures, etc.).        [0x4b5dfe..0x4b6689]
//   7. Epilogue FUN_0053c5c0().                                         [0x4b5dd4]
//
// Anti-dérive: NO logic invented. Constants (0x464, 0x304, flag masks,
// opcode set) come straight from the decompiled body. Callees are extern.
#pragma once
#include <cstdint>

#include "VanillaSceneTypes.h"

extern "C" {

// ---------------------------------------------------------------------------
// DAT_ globals written by FUN_004b50b0 (defined in VanillaSceneLists.cpp).
// Re-declared here only for documentation; the cpp does not re-define them.
// ---------------------------------------------------------------------------
//   DAT_006313ac  → g_PlacementListOdef  (odef list head)
//   DAT_006313b0  → g_PlacementListObjl  (objl list head, stride 0x464)
//   DAT_006313b4  → g_PlacementListOsl   (osl/atl list head, stride 0x304)
//   DAT_006313b8  → first-placed-object pointer (set when type resolves to 0)
//   DAT_006313c8  → g_PlacedObjectList (outer list head)

// The ported function. cdecl, exactly as the .BIN loader FUN_004b7c50 calls it.
//   arg1 (stream)     = file handle from FUN_00539e30 / inherited .BIN context
//   arg2 (scene_name) = level/scene name (used in error/allocator tags only)
void __cdecl FUN_004b50b0(uint32_t stream, const char* scene_name);

// Tiny trace-only verifier: opens scene_name (.bin), seeks to the placements
// section, reads odef/objl/atl counts + first few placement rows, logs them.
// NO mutation of engine globals (uses local copies of the heads).
int VanillaPlacements_SelfTest(const char* bin_path);

} // extern "C"
