// Giants Vanilla-Native Recomp — Scene Load: level selector + mission start.
//
// Faithful C++ ports of two vanilla Giants.exe functions (base 0x400000),
// confirmed by the decompiled bodies in vanilla_decompiled/004913c0.json and
// vanilla_decompiled/004f3230.json. Every behavior is traced to specific
// addresses (cited inline as [0x......] = code address, DAT_......... = .data
// global, s_......... = rdata string). The two functions form the
// intros→menu handoff chain:
//
//   FUN_004913c0  intro_island SELECTOR.
//                Called from WinMain FUN_005222c0 step 14 (after intros
//                FUN_00523b60). Scans the level table for "intro_island",
//                stores its index in DAT_00631380 + DAT_0059ca4c, then kicks
//                the async load (loading screen + scene bootstrap) via
//                FUN_0045a520 / FUN_0045a530. Sets DAT_005a766c = 1.
//
//   FUN_004f3230  MISSION / object-class START (the "SetupGame" path).
//                Called from FUN_0052a050 when the active level name (at
//                world_state+4) == s_intro_island_0055df20 (FUN_00547250
//                returns nonzero). Tears down the previous level's resources
//                (texture pools at world_state+0x503c/+0x4ffc/+0x5044/+0x4ea4,
//                the DAT_00631504 objl spawn list), rebuilds the object-class
//                table by spawning 16 object types via FUN_0049d280(typeId) +
//                FUN_004af220(entity), runs the per-placed-object spawn-callback
//                walk, then clears the world state and dispatches the final
//                reset cluster (FUN_004bac50 / FUN_0040aff0 / FUN_0050dc20 /
//                FUN_00491540 + 5 subsystem resets).
//
// Source-of-truth bodies:
//   vanilla_decompiled/004913c0.json  (109 bytes decompiled)
//   vanilla_decompiled/004f3230.json  (832 bytes decompiled)
//
// Anti-derivation: every statement maps to a decompiled line. Callees not yet
// ported are declared `extern` and called verbatim (link resolves later) and/or
// marked `// FIXME(unverified)`. No invented behavior.
#pragma once
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// FUN_004913c0 — intro_island selector + async-load kick.
// ============================================================================
// Decompiled body (vanilla_decompiled/004913c0.json):
//
//   void FUN_004913c0(void) {
//     int iVar1 = FUN_0052f960();          // gate check: DAT_005dd5d8 == 4
//     if (iVar1 != 0) { FUN_0052a050(); return; }
//     int iVar2 = FUN_004b77c0();          // (result discarded; side-effect fn)
//     int iVar4 = 0;
//     iVar1 = DAT_00631380;
//     if (-1 < iVar2) {
//       do {
//         iVar1 = FUN_004b7640(iVar4);      // lookup level record by index
//         if ((iVar1 != 0) &&
//             (iVar3 = FUN_0053c970(s_intro_island_0055df20, *(char**)(iVar1 + 4)),
//              iVar1 = iVar4, iVar3 != 0)) break;
//         iVar4 = iVar4 + 1;
//         iVar1 = DAT_00631380;
//       } while (iVar4 <= iVar2);
//     }
//     DAT_00631380 = iVar1;                 // store the selected index
//     FUN_0045a520(DAT_00631380);           // DAT_0059ca4c = DAT_00631380
//     FUN_0045a530();                       // kick async load (loading screen)
//     DAT_005a766c = 1;
//   }
//
// Globals touched:
//   DAT_00631380  (read+write) — selected level index ("intro_island")
//   DAT_0059ca4c  (via FUN_0045a520) — mirror of the selected level index
//   DAT_005a766c  (write) — flag set to 1 after kick (intro-mode active)
//   DAT_005dd5d8  (via FUN_0052f960) — game-state phase (4 ⇒ active level)
void FUN_004913c0(void);

// ============================================================================
// FUN_004f3230 — mission / object-class start (the SetupGame body for the
// active level, run when active level == "intro_island").
// ============================================================================
// Decompiled body (vanilla_decompiled/004f3230.json), 832 bytes. See the .cpp
// for the full instruction-by-instruction port. Summary:
//   - clears DAT_0063166c
//   - runs the reset cluster: FUN_004aa190, FUN_0040f2e0, FUN_00519ca0
//     (arg DAT_00630f34, then DAT_00630f34 = 0)
//   - if world_state (DAT_006316ec) != 0: releases four texture/anim pools at
//     world_state + 0x503c / +0x4ffc / +0x5044 / +0x4ea4 via the
//     FUN_0050e4b0 + FUN_0050e360 release pair
//   - reset cluster 2: FUN_00439b80, FUN_004470d0, FUN_0044a120, FUN_004d20f0,
//     FUN_0044ab40
//   - spawns 16 object classes by typeId (see spawn list below) via
//     FUN_0049d280(typeId) → FUN_004af220(entity)
//   - walks the spawn-callback list at DAT_00631504 (count) /
//     DAT_00631508 (head) / DAT_0063150c (tail), invoking each entry's
//     vtable[0] callback, removing entries that return 0 (compact-in-place)
//   - reset cluster 3: FUN_0051eb10, FUN_0049cc60, FUN_004b71d0, FUN_0044ac80,
//     *DAT_005dc25c, *DAT_005dc2e8, *DAT_005dc32c, FUN_0049a910, FUN_0049b6d0,
//     FUN_005102d0
//   - if world_state != 0: FUN_0049a570; walks world_state+0x178 sub-array
//     (count world_state+0x174, stride 0x304), invoking FUN_0049f1f0 on each;
//     frees the array via FUN_0053c5c0(arr, src_file, 0x94) and zeroes the
//     count + ptr; then FUN_004759c0
//   - reset cluster 4: FUN_004bac50, FUN_0040aff0, FUN_0050dc20, FUN_00491540
//   - clears DAT_006316ec and DAT_006310e8
//   - final reset cluster 5: FUN_00431800, FUN_00473190, FUN_00403430,
//     FUN_004a5600, FUN_00445340
void FUN_004f3230(void);

// ============================================================================
// Self-test: verify the level selector can locate "intro_island" in the level
// table (g_LevelTable @ DAT_00631388, populated by FUN_004b77f0). Pure trace —
// no engine mutation. Returns the selected index, or -1 on failure.
// ============================================================================
int VanillaSceneLoad_SelfTest(void);

#ifdef __cplusplus
} // extern "C"
#endif
