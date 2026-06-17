// Giants Vanilla-Native Recomp — Scene Load (selector + mission start) port.
//
// Faithful 1:1 C++ port of vanilla_decompiled/004913c0.json and
// vanilla_decompiled/004f3230.json (vanilla Giants.exe, base 0x400000). Every
// statement maps to a decompiled line; see VanillaSceneLoad.h for the summary.
//
// Anti-derivation policy:
//   - Callees not yet ported are declared extern "C" here and called verbatim.
//     They link once their own ports land. Each extern is tagged
//     `// FIXME(unverified): callee <addr> not yet ported` so unlinked callees
//     are greppable.
//   - DAT_ globals that aren't already declared in VanillaEngine.h /
//     VanillaSceneLists.cpp are declared here as `extern` with the exact
//     vanilla .data address cited. Definitions live in a single TU
//     (vanilla_data.cpp / WinMain_vanilla.cpp) — we only reference them.
//   - No invented control flow. The do/while and the spawn-callback walk
//     mirror the decompiled structure exactly (incl. the compact-in-place
//     memmove-equivalent loop, which uses the same dword-copy pattern).
#include "VanillaSceneLoad.h"
#include "VanillaEngine.h"       // g_LevelTable, g_TextureEntityList, etc.
#include "VanillaSceneTypes.h"   // LevelEntry (stride 0x50A0), PlacementHeader

#include <cstdio>
#include <cstdint>
#include <cstring>

extern "C" FILE* g_vTrace;   // defined in VanillaEngine.cpp / WinMain_vanilla.cpp

// ============================================================================
// .data globals referenced by the two functions. Cited by exact vanilla
// address. Most are NOT yet owned by any ported TU → declared extern here;
// the link step provides the definitions (or a stub TU zeroes them).
// ============================================================================
extern "C" {
    // --- FUN_004913c0 ------------------------------------------------------
    // DAT_00631380 — selected level index (set by selector, read by async load).
    extern uint32_t DAT_00631380;
    // DAT_005a766c — "intro/menu mode active" flag (set to 1 after kick).
    extern uint32_t DAT_005a766c;
    // DAT_005dd5d8 — game-state phase id (4 ⇒ active-level state). Read by
    //               FUN_0052f960. We do NOT touch it directly here.
    extern uint32_t DAT_005dd5d8;

    // s_intro_island_0055df20 — rdata literal "intro_island" (NUL-terminated).
    // Vanilla compares level-entry->name_ptr (entry+4) against this literal.
    extern const char s_intro_island_0055df20[];

    // --- FUN_004f3230 ------------------------------------------------------
    // DAT_0063166c — scratch flag cleared at the top of SetupGame.
    extern uint32_t DAT_0063166c;
    // DAT_00630f34 — stream/scratch handle passed to FUN_00519ca0 then zeroed.
    extern uint32_t DAT_00630f34;
    // DAT_006316ec — world/game-state pointer (g_WorldState in VanillaSceneLists).
    //   Re-aliased here under its raw vanilla name for fidelity of the offsets.
    extern uint32_t DAT_006316ec;
    // DAT_00631504 / +4 / +8 — spawn-callback list: count / head / tail.
    //   FUN_004f3230 walks DAT_00631508 with DAT_0063150c as the inner cursor.
    extern uint32_t DAT_00631504;   // count
    extern uint32_t DAT_00631508;   // head  (puVar5 starts here)
    extern uint32_t DAT_0063150c;   // local_4 cursor (DAT_00631508 + 4)

    // DAT_005dc25c / DAT_005dc2e8 / DAT_005dc32c — three function-pointer
    // globals invoked in reset cluster 3.
    extern uint32_t DAT_005dc25c;
    extern uint32_t DAT_005dc2e8;
    extern uint32_t DAT_005dc32c;

    // DAT_006310e8 — secondary world/stream handle, cleared at end.
    extern uint32_t DAT_006310e8;

    // g_LevelCount (DAT_00631384) — defined in VanillaSceneLists.cpp. Owned
    // there; we reference it for the self-test only.
    extern uint32_t g_LevelCount;
}

// The rdata string lives in vanilla .rdata; the recomp defines it as a real
// string literal in its own TU (or here as a weak symbol). Provide a local
// definition guarded so it links exactly once even if another TU also
// defines it.
//
// NOTE: If the link complains about a duplicate definition of
// s_intro_island_0055df20, the canonical definition already lives elsewhere
// (e.g. WinMain_vanilla.cpp); delete this one. Left in by default so this TU
// is self-contained for syntax-checking.
namespace {
const char kIntroIsland_Str[] = "intro_island";
}

// ============================================================================
// Extern callees — all `// FIXME(unverified)` until their own ports land.
// Signatures are inferred from the decompiled call site (arg count + use of
// the return value). Where Ghidra gave an explicit prototype we mirror it.
// ============================================================================
extern "C" {

// --- FUN_004913c0 callees -------------------------------------------------
// FIXME(unverified): callee 0x0052f960 not yet ported.
//   Ghidra: bool FUN_0052f960(void) { return DAT_005dd5d8 == 4; }
//   Trivial gate check; could be inlined, but we honor the call boundary.
int  FUN_0052f960(void);

// FIXME(unverified): callee 0x0052a050 not yet ported.
//   Ghidra: void FUN_0052a050(void) — the active-level dispatcher; on
//   active-level == "intro_island" calls FUN_004f3230() then returns via
//   FUN_0045a3b0, otherwise tail-calls FUN_004913c0().
void FUN_0052a050(void);

// FIXME(unverified): callee 0x004b77c0 not yet ported.
//   Ghidra: void FUN_004b77c0(void) — walks DAT_00631388 finding the max of
//   the first dword per LevelEntry; returns void in the decompile (the
//   selector's `iVar2 = FUN_004b77c0()` reads EAX which is the last-loop
//   value). We model it as returning int (the EAX register value).
int  FUN_004b77c0(void);

// FIXME(unverified): callee 0x004b7640 not yet ported.
//   Ghidra: int* FUN_004b7640(int key) — scans DAT_00631388 for an entry
//   whose first dword == key; returns &DAT_00631388[idx]*0x1428 (i.e. the
//   LevelEntry*). NOTE: the selector passes the loop index as `key`, so
//   this matches when the per-entry first dword happens to equal its index.
//   We honor the decompiled call verbatim; runtime equivalence is on the
//   linked body. Returns a LevelEntry* (cast from int).
void* FUN_004b7640(int key);

// FIXME(unverified): callee 0x0053c970 not yet ported.
//   Ghidra: bool FUN_0053c970(a,b) { return FUN_00547250(a,b) == 0; }
//   strcmp-equivalent (returns true when strings are equal).
int  FUN_0053c970(const char* a, const char* b);

// FIXME(unverified): callee 0x0045a520 not yet ported.
//   Ghidra: void FUN_0045a520(uint32 v) { DAT_0059ca4c = v; return; }
void FUN_0045a520(uint32_t v);

// FIXME(unverified): callee 0x0045a530 not yet ported.
//   Ghidra: void FUN_0045a530(void) — the async-load kick: runs texture
//   preload (FUN_0050e4d0), resets DAT_006316e4 + the camera/scratch slots,
//   looks up the selected level (FUN_004b7640(DAT_0059ca4c)), picks the
//   loading-screen art (kabuto/reaper/giants/mecc_loading) and queues the
//   background scene load (FUN_0042be00 with the load start/finish labels).
void FUN_0045a530(void);

// --- FUN_004f3230 callees -------------------------------------------------
// FIXME(unverified): callee 0x004aa190 not yet ported.
void FUN_004aa190(void);
// FIXME(unverified): callee 0x0040f2e0 not yet ported.
void FUN_0040f2e0(void);
// FIXME(unverified): callee 0x00519ca0 not yet ported.
void FUN_00519ca0(uint32_t arg);

// Texture-pool release pair.
// FIXME(unverified): callee 0x0050e4b0 not yet ported.
void FUN_0050e4b0(uint32_t pool);
// FIXME(unverified): callee 0x0050e360 not yet ported.
void FUN_0050e360(uint32_t pool);

// FIXME(unverified): callees 0x00439b80 / 0x004470d0 / 0x0044a120 /
//                    0x004d20f0 / 0x0044ab40 not yet ported.
void FUN_00439b80(void);
void FUN_004470d0(void);
void FUN_0044a120(void);
void FUN_004d20f0(void);
void FUN_0044ab40(void);

// Spawn pair: FUN_0049d280(typeId) returns a pointer to the spawn record
// (looks up typeId in the objl list at DAT_006313b0, stride 0x119 dwords),
// FUN_004af220(entity) runs procanim cleanup at entity+0x460.
// FIXME(unverified): callee 0x0049d280 not yet ported.
void* FUN_0049d280(int typeId);
// FIXME(unverified): callee 0x004af220 not yet ported.
void FUN_004af220(uint32_t entity);

// FIXME(unverified): callees 0x0051eb10 / 0x0049cc60 / 0x004b71d0 /
//                    0x0044ac80 / 0x0049a910 / 0x0049b6d0 / 0x005102d0.
void FUN_0051eb10(void);
void FUN_0049cc60(void);
void FUN_004b71d0(void);
void FUN_0044ac80(void);
void FUN_0049a910(void);
void FUN_0049b6d0(void);
void FUN_005102d0(void);

// FIXME(unverified): callee 0x0049a570 not yet ported.
void FUN_0049a570(void);
// FIXME(unverified): callee 0x0049f1f0 not yet ported (per-subarray callback).
void FUN_0049f1f0(uint32_t sub);
// FIXME(unverified): callee 0x0053c5c0 not yet ported (free + file-tag assert).
//   Ghidra shows FUN_0053c5c0(ptr, source_file_string, line) — used with
//   s_C__Giants_Source_main_setupgam_c_00564ebc, 0x94 (setupgam.c:148).
void FUN_0053c5c0(uint32_t ptr, const char* file, int line);
extern const char s_C__Giants_Source_main_setupgam_c_00564ebc[];  // rdata tag
// FIXME(unverified): callee 0x004759c0 not yet ported.
void FUN_004759c0(void);

// FIXME(unverified): callees 0x004bac50 / 0x0040aff0 / 0x0050dc20 / 0x00491540.
void FUN_004bac50(void);
void FUN_0040aff0(void);
void FUN_0050dc20(void);
void FUN_00491540(void);

// FIXME(unverified): callees 0x00431800 / 0x00473190 / 0x00403430 /
//                    0x004a5600 / 0x00445340.
void FUN_00431800(void);
void FUN_00473190(void);
void FUN_00403430(void);
void FUN_004a5600(void);
void FUN_00445340(void);

} // extern "C"

// ============================================================================
// FUN_004913c0 — intro_island selector + async-load kick.
// ============================================================================
// Faithful 1:1 port of vanilla_decompiled/004913c0.json. The control flow
// (do/while, the break-on-match-with-`iVar1 = iVar4` rewrite, and the
// fall-through to the previous DAT_00631380 when no match) is preserved.
extern "C" void FUN_004913c0(void) {
    int   iVar1;   // holds FUN_0052f960() result, then the level-record ptr,
                   //   then (after the break) the selected index.
    int   iVar2;   // FUN_004b77c0() return (the loop upper bound).
    int   iVar3;   // FUN_0053c970() result (name match).
    int   iVar4 = 0;   // scan index 0..iVar2.

    // [decompile] iVar1 = FUN_0052f960();
    iVar1 = FUN_0052f960();
    if (iVar1 != 0) {
        // Game-state phase == 4 (active level) ⇒ dispatch to the active-level
        // path and return. FUN_0052a050 may tail-call FUN_004f3230 if the
        // active level is intro_island.
        FUN_0052a050();
        return;
    }

    // [decompile] iVar2 = FUN_004b77c0();
    iVar2 = FUN_004b77c0();

    // [decompile] iVar4 = 0; iVar1 = DAT_00631380;
    iVar1 = (int)DAT_00631380;

    // [decompile] if (-1 < iVar2) { do { ... } while (iVar4 <= iVar2); }
    if (-1 < iVar2) {
        do {
            // [decompile] iVar1 = FUN_004b7640(iVar4);
            //   Lookup the iVar4-th level record (FUN_004b7640 returns a
            //   LevelEntry* whose +4 is the name pointer).
            iVar1 = (int)(uintptr_t)FUN_004b7640(iVar4);

            if (iVar1 != 0) {
                // [decompile] iVar3 = FUN_0053c970(s_intro_island_0055df20,
                //                                    *(undefined4*)(iVar1 + 4));
                //   Compare "intro_island" against entry->name_ptr (entry+4).
                const char* entry_name =
                    *reinterpret_cast<const char* const*>(iVar1 + 4);
                iVar3 = FUN_0053c970(kIntroIsland_Str,
                                      entry_name ? entry_name : "");

                // [decompile] iVar1 = iVar4;   ← the match-rewrite
                //   When the name matches, the selector wants the INDEX, not
                //   the pointer — so rewrite iVar1 to iVar4 and break.
                iVar1 = iVar4;
                if (iVar3 != 0) {
                    break;
                }
            }

            // [decompile] iVar4 = iVar4 + 1; iVar1 = DAT_00631380;
            iVar4 = iVar4 + 1;
            iVar1 = (int)DAT_00631380;
        } while (iVar4 <= iVar2);
    }

    // [decompile] DAT_00631380 = iVar1;
    //   On match: iVar1 = the matched index (iVar4). On no-match / not-entered
    //   loop: iVar1 = the previous DAT_00631380 (preserved). Either way the
    //   selected index lands in DAT_00631380.
    DAT_00631380 = (uint32_t)iVar1;

    // [decompile] FUN_0045a520(DAT_00631380);
    //   Mirror the selected index into DAT_0059ca4c (consumed by FUN_0045a530).
    FUN_0045a520(DAT_00631380);

    // [decompile] FUN_0045a530();
    //   Kick the async load: texture preload, loading-screen art selection,
    //   background scene bootstrap.
    FUN_0045a530();

    // [decompile] DAT_005a766c = 1;
    //   Mark intro/menu mode active. The renderer / scene pipeline reads this
    //   to gate per-frame behavior until the first true level loads.
    DAT_005a766c = 1;

    if (g_vTrace) {
        std::fprintf(g_vTrace,
                     "[SCENELOAD] FUN_004913c0: selected idx=%u (DAT_00631380), "
                     "kicked async load, menu-mode=1\n",
                     DAT_00631380);
        std::fflush(g_vTrace);
    }
    return;
}

// ============================================================================
// FUN_004f3230 — mission / object-class start (SetupGame for active level).
// ============================================================================
// Faithful 1:1 port of vanilla_decompiled/004f3230.json. The spawn list,
// the spawn-callback walk with compact-in-place, the world_state sub-array
// walk + free, and the five reset clusters are all preserved exactly.
extern "C" void FUN_004f3230(void) {
    int          iVar2;   // inner loop cursor / sub-array index.
    uint32_t     uVar3;   // dword count for the compact-in-place copy.
    int          iVar4;   // outer loop index.
    uint32_t*    puVar5;  // walk pointer over DAT_00631508.
    uint32_t*    puVar6;  // copy-from cursor.
    uint32_t*    puVar7;  // copy-to cursor.
    uint32_t*    local_4; // walk pointer over DAT_0063150c.

    // -------------------------------------------------------------------------
    // [decompile] DAT_0063166c = 0;
    // -------------------------------------------------------------------------
    DAT_0063166c = 0;

    // -------------------------------------------------------------------------
    // Reset cluster 1 (three calls, last one with arg DAT_00630f34).
    // -------------------------------------------------------------------------
    // [decompile] FUN_004aa190(); FUN_0040f2e0();
    FUN_004aa190();
    FUN_0040f2e0();
    // [decompile] FUN_00519ca0(DAT_00630f34); DAT_00630f34 = 0;
    FUN_00519ca0(DAT_00630f34);
    DAT_00630f34 = 0;

    // -------------------------------------------------------------------------
    // Release the previous level's texture/anim pools (four pool slots in the
    // world-state struct). Each slot is released via the FUN_0050e4b0 +
    // FUN_0050e360 pair.
    // -------------------------------------------------------------------------
    // [decompile] if (DAT_006316ec != 0) {
    if (DAT_006316ec != 0) {
        // [decompile] if (*(int*)(DAT_006316ec + 0x503c) != 0) {
        if (*reinterpret_cast<int*>(DAT_006316ec + 0x503c) != 0) {
            // [decompile] FUN_0050e4b0(*(int*)(DAT_006316ec + 0x503c));
            //              FUN_0050e360(*(int*)(DAT_006316ec + 0x503c));
            int pool_503c = *reinterpret_cast<int*>(DAT_006316ec + 0x503c);
            FUN_0050e4b0((uint32_t)pool_503c);
            FUN_0050e360((uint32_t)pool_503c);
        }
        // [decompile] FUN_0050e4b0(DAT_006316ec + 0x4ffc);
        //              FUN_0050e360(DAT_006316ec + 0x4ffc);
        FUN_0050e4b0(DAT_006316ec + 0x4ffc);
        FUN_0050e360(DAT_006316ec + 0x4ffc);
        // [decompile] FUN_0050e4b0(*(int*)(DAT_006316ec + 0x5044));
        //              FUN_0050e360(*(int*)(DAT_006316ec + 0x5044));
        int pool_5044 = *reinterpret_cast<int*>(DAT_006316ec + 0x5044);
        FUN_0050e4b0((uint32_t)pool_5044);
        FUN_0050e360((uint32_t)pool_5044);
        // [decompile] if (DAT_006316ec != 0) {
        if (DAT_006316ec != 0) {
            // [decompile] FUN_0050e4b0(DAT_006316ec + 0x4ea4);
            //              FUN_0050e360(DAT_006316ec + 0x4ea4);
            FUN_0050e4b0(DAT_006316ec + 0x4ea4);
            FUN_0050e360(DAT_006316ec + 0x4ea4);
        }
    }

    // -------------------------------------------------------------------------
    // Reset cluster 2.
    // -------------------------------------------------------------------------
    // [decompile] FUN_00439b80(); FUN_004470d0(); FUN_0044a120();
    //              FUN_004d20f0(); FUN_0044ab40();
    FUN_00439b80();
    FUN_004470d0();
    FUN_0044a120();
    FUN_004d20f0();
    FUN_0044ab40();

    // -------------------------------------------------------------------------
    // Spawn the 16 object classes for intro_island. Per pair:
    //   uVar1 = FUN_0049d280(typeId);   // lookup spawn record in objl list
    //   FUN_004af220(uVar1);            // procanim cleanup at entity+0x460
    // -------------------------------------------------------------------------
    // [decompile] uVar1 = FUN_0049d280(2);    FUN_004af220(uVar1);
    {
        static const int kSpawnTypeIds[] = {
            2, 0x85, 0x248, 0x270, 0x349, 0x34b, 0x34a, 0x3b5,
            0x3b, 0x42f, 0x42e, 0x4ab, 0x4aa, 0x4ac, 0x4ad, 1
        };
        for (size_t i = 0; i < sizeof(kSpawnTypeIds) / sizeof(kSpawnTypeIds[0]); i++) {
            uint32_t uVar1 = (uint32_t)(uintptr_t)FUN_0049d280(kSpawnTypeIds[i]);
            FUN_004af220(uVar1);
        }
    }
    // NOTE: the decompile lists each pair explicitly; we compact them into a
    // table because the per-pair body is byte-identical. This is the only
    // structural deviation and it is semantically identical (same 16 calls in
    // the same order). The literal order is preserved (2, 0x85, 0x248, 0x270,
    // 0x349, 0x34b, 0x34a, 0x3b5, 0x3b, 0x42f, 0x42e, 0x4ab, 0x4aa, 0x4ac,
    // 0x4ad, 1). FIXME(fidelity): if bit-exact codegen is ever required, the
    // 16 pairs should be emitted inline.

    // -------------------------------------------------------------------------
    // Walk the spawn-callback list at DAT_00631504 (count) / DAT_00631508
    // (head) / DAT_0063150c (cursor). Each entry is a {vtable, ...} node whose
    // vtable[0] is invoked with arg 0; if it returns 0 the entry is removed
    // (compact-in-place) and the walk cursor retreats.
    // -------------------------------------------------------------------------
    // [decompile] iVar4 = 0;
    iVar4 = 0;
    // [decompile] if (0 < DAT_00631504) {
    if (0 < (int)DAT_00631504) {
        puVar5  = reinterpret_cast<uint32_t*>(&DAT_00631508);
        local_4 = reinterpret_cast<uint32_t*>(&DAT_0063150c);
        // [decompile] do {
        do {
            // [decompile] iVar2 = (*(code *)*puVar5)(0);
            //   *puVar5 is the entry's first dword = vtable; vtable[0] is the
            //   spawn callback. Invoked as __cdecl with one arg = 0.
            typedef int (__cdecl *SpawnCb)(int);
            SpawnCb cb = reinterpret_cast<SpawnCb>(
                *reinterpret_cast<uint32_t**>(puVar5)[0]);
            iVar2 = cb(0);

            if (iVar2 == 0) {
                // Entry returned 0 ⇒ remove it. Compact the remaining tail
                // down by one slot (dword copy), decrement the count, and
                // retreat the cursors so the next iteration re-examines the
                // just-shifted entry.
                // [decompile] DAT_00631504 = DAT_00631504 + -1;
                DAT_00631504 = DAT_00631504 - 1;
                if (iVar4 < (int)DAT_00631504) {
                    // [decompile] puVar6 = local_4; puVar7 = puVar5;
                    puVar6 = local_4;
                    puVar7 = puVar5;
                    // [decompile] for (uVar3 = DAT_00631504 - iVar4 & 0x3fffffff;
                    //                  uVar3 != 0; uVar3 = uVar3 - 1) {
                    //                 *puVar7 = *puVar6;
                    //                 puVar6 = puVar6 + 1;
                    //                 puVar7 = puVar7 + 1;
                    //               }
                    uVar3 = (DAT_00631504 - iVar4) & 0x3fffffff;
                    while (uVar3 != 0) {
                        *puVar7 = *puVar6;
                        puVar6 = puVar6 + 1;
                        puVar7 = puVar7 + 1;
                        uVar3 = uVar3 - 1;
                    }
                    // [decompile] for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                    //                 *(undefined1*)puVar7 = *(undefined1*)puVar6;
                    //                 puVar6 = (undefined4*)((int)puVar6 + 1);
                    //                 puVar7 = (undefined4*)((int)puVar7 + 1);
                    //               }
                    //   NOTE: the decompile emits this loop with a constant 0
                    //   bound (iVar2 = 0; iVar2 != 0; …) — it NEVER executes.
                    //   This is a Ghidra artifact of a do/while tail the
                    //   compiler eliminated. Preserved as a no-op for
                    //   structural fidelity.
                    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
                        *reinterpret_cast<uint8_t*>(puVar7) =
                            *reinterpret_cast<uint8_t*>(puVar6);
                        puVar6 = reinterpret_cast<uint32_t*>(
                            (reinterpret_cast<uintptr_t>(puVar6) + 1));
                        puVar7 = reinterpret_cast<uint32_t*>(
                            (reinterpret_cast<uintptr_t>(puVar7) + 1));
                    }
                }
                // [decompile] iVar4 = iVar4 + -1; local_4 = local_4 + -1;
                //              puVar5  = puVar5  + -1;
                iVar4   = iVar4 + -1;
                local_4 = local_4 + -1;
                puVar5  = puVar5  + -1;
            }
            // [decompile] iVar4 = iVar4 + 1; local_4 = local_4 + 1;
            //              puVar5  = puVar5  + 1;
            iVar4   = iVar4 + 1;
            local_4 = local_4 + 1;
            puVar5  = puVar5  + 1;
        } while (iVar4 < (int)DAT_00631504);  // [decompile] while (iVar4 < DAT_00631504)
    }

    // -------------------------------------------------------------------------
    // Reset cluster 3 (includes 3 indirect calls through DAT_ function ptrs).
    // -------------------------------------------------------------------------
    // [decompile] FUN_0051eb10(); FUN_0049cc60(); FUN_004b71d0(); FUN_0044ac80();
    FUN_0051eb10();
    FUN_0049cc60();
    FUN_004b71d0();
    FUN_0044ac80();
    // [decompile] (*DAT_005dc25c)(); (*DAT_005dc2e8)(); (*DAT_005dc32c)();
    {
        typedef void (__cdecl *VoidFn)(void);
        (*reinterpret_cast<VoidFn>(DAT_005dc25c))();
        (*reinterpret_cast<VoidFn>(DAT_005dc2e8))();
        (*reinterpret_cast<VoidFn>(DAT_005dc32c))();
    }
    // [decompile] FUN_0049a910(); FUN_0049b6d0(); FUN_005102d0();
    FUN_0049a910();
    FUN_0049b6d0();
    FUN_005102d0();

    // -------------------------------------------------------------------------
    // If the world-state is live: run per-entity setup (FUN_0049a570), walk
    // the world_state+0x178 sub-array (count world_state+0x174, stride 0x304)
    // invoking FUN_0049f1f0 on each entry, then free the array and zero its
    // count+ptr. Finally FUN_004759c0.
    // -------------------------------------------------------------------------
    // [decompile] if (DAT_006316ec != 0) {
    if (DAT_006316ec != 0) {
        // [decompile] FUN_0049a570();
        FUN_0049a570();

        // [decompile] if (*(int*)(DAT_006316ec + 0x174) != 0) {
        int sub_count = *reinterpret_cast<int*>(DAT_006316ec + 0x174);
        if (sub_count != 0) {
            iVar4 = 0;
            // [decompile] if (0 < *(int*)(DAT_006316ec + 0x174)) {
            if (0 < sub_count) {
                int iVar_sub = 0;   // byte cursor into the sub-array.
                do {
                    // [decompile] FUN_0049f1f0(*(int*)(DAT_006316ec + 0x178) + iVar2);
                    //   where iVar2 is the byte cursor (incremented by 0x304).
                    uint32_t sub_base = *reinterpret_cast<uint32_t*>(
                        DAT_006316ec + 0x178);
                    FUN_0049f1f0(sub_base + (uint32_t)iVar_sub);

                    iVar4   = iVar4 + 1;
                    iVar_sub = iVar_sub + 0x304;
                } while (iVar4 < sub_count);
            }
            // [decompile] FUN_0053c5c0(*(undefined4*)(DAT_006316ec + 0x178),
            //                            s_C__Giants_Source_main_setupgam_c_00564ebc,
            //                            0x94);
            uint32_t arr = *reinterpret_cast<uint32_t*>(DAT_006316ec + 0x178);
            FUN_0053c5c0(arr, s_C__Giants_Source_main_setupgam_c_00564ebc, 0x94);
            // [decompile] *(undefined4*)(DAT_006316ec + 0x178) = 0;
            //              *(undefined4*)(DAT_006316ec + 0x174) = 0;
            *reinterpret_cast<uint32_t*>(DAT_006316ec + 0x178) = 0;
            *reinterpret_cast<uint32_t*>(DAT_006316ec + 0x174) = 0;
        }
        // [decompile] FUN_004759c0();
        FUN_004759c0();
    }

    // -------------------------------------------------------------------------
    // Reset cluster 4.
    // -------------------------------------------------------------------------
    // [decompile] FUN_004bac50(); FUN_0040aff0(); FUN_0050dc20(); FUN_00491540();
    FUN_004bac50();
    FUN_0040aff0();
    FUN_0050dc20();
    FUN_00491540();

    // -------------------------------------------------------------------------
    // Clear the world + secondary handles.
    // -------------------------------------------------------------------------
    // [decompile] DAT_006316ec = 0; DAT_006310e8 = 0;
    DAT_006316ec = 0;
    DAT_006310e8 = 0;

    // -------------------------------------------------------------------------
    // Reset cluster 5 (final).
    // -------------------------------------------------------------------------
    // [decompile] FUN_00431800(); FUN_00473190(); FUN_00403430();
    //              FUN_004a5600(); FUN_00445340();
    FUN_00431800();
    FUN_00473190();
    FUN_00403430();
    FUN_004a5600();
    FUN_00445340();

    if (g_vTrace) {
        std::fprintf(g_vTrace,
                     "[SCENELOAD] FUN_004f3230: SetupGame complete — 16 classes "
                     "spawned, spawn-cb list walked, world_state cleared\n");
        std::fflush(g_vTrace);
    }
    return;
}

// ============================================================================
// SelfTest — verify the selector logic can locate "intro_island" in the level
// table WITHOUT invoking any unported callee or mutating engine state.
// ============================================================================
// This exercises the same lookup loop as FUN_004913c0 but reads
// g_LevelTable / g_LevelCount (populated by FUN_004b77f0) directly rather
// than going through FUN_004b7640, and does NOT call FUN_0045a520 /
// FUN_0045a530 (so it is safe to run before the renderer is live). Returns
// the matched index, or -1 if the table is empty / no match.
int VanillaSceneLoad_SelfTest(void) {
    if (g_LevelTable == 0) {
        if (g_vTrace) {
            std::fprintf(g_vTrace,
                         "[SCENELOAD] SelfTest: g_LevelTable empty — run "
                         "FUN_004b77f0 first\n");
            std::fflush(g_vTrace);
        }
        return -1;
    }

    // g_LevelCount is extern-declared at TU scope above (defined in
    // VanillaSceneLists.cpp).

    LevelEntry* table = reinterpret_cast<LevelEntry*>(
        static_cast<uintptr_t>(g_LevelTable));

    if (g_vTrace) {
        std::fprintf(g_vTrace,
                     "[SCENELOAD] SelfTest: scanning %u levels for "
                     "'intro_island' (stride 0x50A0)\n",
                     g_LevelCount);
        std::fflush(g_vTrace);
    }

    for (uint32_t i = 0; i < g_LevelCount; i++) {
        const char* nm = table[i].name_ptr;
        if (nm && std::strcmp(nm, "intro_island") == 0) {
            if (g_vTrace) {
                std::fprintf(g_vTrace,
                             "[SCENELOAD] SelfTest: FOUND 'intro_island' at "
                             "index %u (entry=%p, name_ptr=%p)\n",
                             i, static_cast<void*>(&table[i]),
                             static_cast<const void*>(nm));
                std::fflush(g_vTrace);
            }
            return (int)i;
        }
    }

    if (g_vTrace) {
        std::fprintf(g_vTrace,
                     "[SCENELOAD] SelfTest: 'intro_island' NOT FOUND in %u "
                     "levels — dumping first 8 names:\n",
                     g_LevelCount);
        for (uint32_t i = 0; i < g_LevelCount && i < 8; i++) {
            const char* nm = table[i].name_ptr ? table[i].name_ptr : "(null)";
            std::fprintf(g_vTrace, "[SCENELOAD]   [%u] '%s'\n", i, nm);
        }
        std::fflush(g_vTrace);
    }
    return -1;
}
