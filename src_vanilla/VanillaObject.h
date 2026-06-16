// Giants Vanilla-Native Recomp — Entity child-initializer + spawn helpers.
//
// Faithful port of Giants.exe!FUN_0045fde0 (vanilla 1.0 retail, base 0x400000),
// confirmed by capstone disassembly of G:\GiantsRE\GameFiles-VanillaV1\Giants.exe.
// Every behavior is traced to specific instruction addresses cited inline as
// [0x......]. See RE_docs/OBJECT_CREATE_CHILD.md for the full reference doc.
//
// IMPORTANT CORRECTION TO THE PRIOR BLOCKER MODEL
// ----------------------------------------------
// The scene-render dispatch (VanillaSceneDispatch.cpp, renderer method 0x2d80)
// walks g_PlacedObjectList (DAT_006313c8) and dispatches each entity's
// vtable[0x30] (OBJECT::Render) via (node-0x34)->vtable[0x30]. The task brief
// named FUN_0045fde0 as "the ctor that resolves typeId → class → installs the
// per-class vtable". THE DISASSEMBLY SHOWS THIS IS NOT THE CASE:
//
//   * FUN_0045fde0 takes ONE argument — a pointer to an already-allocated
//     EntityObject (ebp = [esp+0x10] at [0x45fde3]). All four E8 callers
//     (0x46176e, 0x46892c, 0x494800, 0x535f96) push an existing entity ptr.
//   * It NEVER writes [entity+0x00] (the vtable slot). Confirmed by a full
//     sweep of the function body 0x45fde0..0x46032b: there is no instruction
//     of the form `mov [ebp], <vtable>` or `mov [ebp+0], <ptr>`.
//   * Its first action [0x45fdea..0x45fdf8] is to read [ebp+0xe8] (kind) and,
//     if kind != 0, call FUN_0049f3b0(entity, 0xf) and return 0. I.e. it is a
//     ONE-SHOT init that runs only when kind == 0 (the freshly-allocated
//     state); it sets kind later indirectly via the per-class stat table.
//   * What it DOES: spawns the entity's child sub-objects — the light-pair
//     (fx_buoy_red/green_light via FUN_0049c190 @ [0x45ff78]), the 8 attachment
//     slots at entity+0x22c (loop [0x460063..0x4600d3], 8 iters), the special
//     slot at entity+0x314 ([0x4600db..0x460122]), gravity [0x460217], and the
//     uselist/population fields at entity+0x104 ([0x46024f..0x460319]).
//
//   The PS2 debug symbols agree: the propagated PC↔PS2 match table maps PS2
//   `object_create_child` (0x139500) to PC FUN_0050afb0 (NOT 0x45fde0). And
//   both 0x45fde0 and 0x50afb0 are child/attachment spawners that operate on
//   already-allocated entities — neither installs the vtable.
//
// WHERE THE VTABLE ACTUALLY COMES FROM (the real blocker)
// -------------------------------------------------------
// The per-entity vtable at [entity+0x00] is set by the entity ALLOCATOR that
// creates the EntityObject and links it into g_PlacedObjectList — the path
// that FUN_004b50b0 (readobjs.c "osl"/"objl" builder) feeds. A full sweep of
// .text for `mov dword ptr [reg], <imm>` where <imm> is a .rdata/.data address
// returns ZERO candidates, which means the vtable is written via a register
// move (e.g. `mov [edi], esi` after `lea esi, [...]` or after copying from a
// template object). There is no global per-class vtable TABLE; the engine
// uses a template/clone model. See RE_docs/OBJECT_CREATE_CHILD.md §3.
//
// RECOMP STRATEGY (what unblocks the dispatch walk TODAY)
// -------------------------------------------------------
// We cannot faithfully reproduce the template-clone allocator without porting
// the full readobjs.c odef-VM (FUN_004b50b0 + ~80 opcodes). What we CAN do —
// and what the task GOAL requires — is:
//   (a) Port FUN_0045fde0 faithfully as the child-init (this file), so when a
//       real entity is handed to it the light-pair + attachments are spawned.
//   (b) Provide SpawnTestEntity(typeId,x,y,z) which allocates an EntityObject,
//       installs a STUB vtable (whose [0x30] Render is a logging no-op), and
//       head-inserts it into g_PlacedObjectList. This gives the dispatch walk
//       non-NULL vtables so the scene walk iterates and Render is invoked —
//       end-to-end proof that the dispatch chain is connected. The stub Render
//       logs the entity so the walk is observable even before real drawing.
#pragma once
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// FUN_0045fde0 — entity one-shot child/attachment initializer.
// ============================================================================
//   entity - pointer to an already-allocated EntityObject (see VanillaSceneTypes.h).
//            Must have its vtable ([+0x00]) already installed by the allocator.
//            entity->kind ([+0xe8]) selects the init branch:
//              kind != 0 → already initialized: call FUN_0049f3b0(entity,0xf)
//                          and return 0 (no-op for the recomp).
//              kind == 0 → fresh entity: run the full child-spawn sequence
//                          (one-time level-stat table apply, light-pair,
//                          8 attachment slots, special slot, gravity, uselist).
// Returns 1 on success (full init path), 0 if the entity was already init'd.
//
// This is a faithful 1:1 port. Side effects on the recomp's engine globals
// (g_LevelStatTable @ DAT_0055c604, g_CurrentLevel @ DAT_00631530,
// g_LevelConfig @ DAT_00631538, g_FrameCounter @ DAT_00631578) are applied
// where the disasm reads them; the child sub-objects are allocated via the
// recomp's allocator stubs and tracked on the entity so the dispatch can see
// a non-NULL, fully-formed EntityObject.
uint32_t FUN_0045fde0(void* entity);

// ============================================================================
// SpawnTestEntity — recomp-only helper to prove the dispatch walk end-to-end.
// ============================================================================
//   typeId - object class id (hashed name). Currently informational (logged);
//            the real typeId→class→vtable resolution lives in the readobjs.c
//            odef-VM allocator which is not yet ported. The stub vtable is the
//            same for every typeId until that path is reversed.
//   x,y,z  - world position written to the entity's placement fields.
// Allocates an EntityObject, installs a STUB vtable whose [0x30] (Render) is a
// logging no-op, sets kind=typeId/flags, head-inserts the entity into
// g_PlacedObjectList (DAT_006313c8) in the inner-header layout the walker
// expects (outer node: {next,?,inner_hdr@+0xc}; inner: {?,count@+0x08,
// entity_ptr@+0x400}), and calls FUN_0045fde0 to spawn the children.
// Returns a pointer to the new EntityObject, or nullptr on allocation failure.
void* SpawnTestEntity(uint32_t typeId, float x, float y, float z);

#ifdef __cplusplus
} // extern "C"
#endif
