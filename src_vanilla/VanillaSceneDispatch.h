// Giants Vanilla-Native Recomp — Scene Render Dispatch (UpCalls[20] + scene processor).
//
// Faithful C++ ports of two vanilla Giants.exe functions (base 0x400000), confirmed
// by capstone disassembly of G:\GiantsRE\GameFiles-VanillaV1\Giants.exe. Every
// behavior is traced to specific instruction addresses (cited inline as [0x......]).
// See RE_docs/SCENE_RENDER_DISPATCH.md for the full list-walk algorithm reference.
//
//   FUN_00523aa0 — UpCalls callback[20] "ScenePipelineEntry".
//                  Reads the scene-pipeline gate; if set, tail-jumps to FUN_00523700.
//   FUN_00523700 — scene-pipeline processor (the "scene frame" entry invoked by
//                  the renderer's per-frame method once the gate is open).
//
// IMPORTANT — what FUN_00523700 actually is (per disasm, NOT per SCENE_SYSTEM.md):
//   The disassembly of 0x523700 shows it is the LOADING / ERROR-OVERLAY frame
//   renderer, NOT the entity-list walker. Evidence: it pushes the rdata strings
//   "Escape to Exit Game" / "Enter to Continue" / "Giants: Citizen Kabuto" /
//   "Wintry Cool Game Error Screen" (0x57fdac/0x57fdc0/0x57fdf4/0x57fdd4) and
//   drives renderer slots 0x98 (begin) / 0xa8 (present) / 0x84 (refcount) with
//   font/text setup via FUN_00521060. It guards on DAT_005dcb68 ("overlay active")
//   and DAT_005dcb58 (a second gate). This matches the intros/error-screen render
//   loop described in SCENE_SYSTEM.md §3 (FUN_00523b60 intros-bin player uses the
//   same slot 0x98/0xa8 pair).
//
//   The ACTUAL engine-side entity/texture list walks live in:
//     FUN_0050e4d0 — texture-list walk → renderer slot +0xb4  (ported as a helper here)
//     FUN_0050e540 — uselist builder, walks g_PlacedObjectList (DAT_006313c8)
//   The renderer-private entity dispatch is slot +0x10 (RVA 0x2d80) which walks
//   the renderer's OWN obj+0xe4 list (populated by the renderer from the engine
//   lists via slot +0xb4). See RE_docs/DX7_METHOD_MAP.md §1 slot +0x10.
//
// This file ports what the disassembly shows, and additionally provides the
// engine-side list-walk skeleton (FUN_0050e4d0 pattern) that SCENE_SYSTEM.md §4
// describes conceptually as "the scene walk". Both are faithful to disasm.
#pragma once
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// FUN_00523aa0 — UpCalls callback[20] "ScenePipelineEntry".
// ============================================================================
// Vanilla [0x523aa0]:
//   call 0x4290e0          ; eax = g_ScenePipelineGate (DAT_0058c15c)
//   test eax, eax
//   je  0x523aae           ; gate closed → return (no work this frame)
//   jmp 0x523700           ; gate open → run the scene-pipeline processor
//   0x523aae: ret
//
// FUN_004290e0 is a trivial getter: `mov eax,[0x58c15c]; ret`. The gate is set
// by FUN_004290f0(value) (`mov eax,[esp+4]; mov [0x58c15c],eax; ret`) which
// WinMain calls with a non-zero value once scene init completes.
void FUN_00523aa0(void);

// ============================================================================
// FUN_00523700 — scene-pipeline processor (loading/error-overlay frame render).
// ============================================================================
// Vanilla [0x523700..0x5239b7]. Faithful port of the overlay-render path. See
// the .cpp for the full instruction trace. Summary of the disasm:
//   - reads arg from [esp+0x48] (the overlay message string)
//   - guards on DAT_00631568 (scene state; must be 6 for the "normal" path,
//     otherwise branches to the dialog/menu path at 0x523a8f)
//   - guards on DAT_005dcb6c / DAT_005dcb68 (overlay-active flags)
//   - on the render path: calls renderer slot +0x98 (begin), draws the overlay
//     text via FUN_00521060 with hardcoded color constants, calls slot +0xa8
//     (present), then input tick (FUN_0051f0e0/0051f1f0/0041f400)
//   - on the menu path: drives renderer slot +0x84 (refcount toggle) and the
//     dialog function pointer at DAT_0055520c with a 7-arg cdecl call
//
// Signature: the vanilla function takes one stack arg (the message string at
// [esp+0x48] after the 0x3c+4+4 prologue). We expose it as cdecl with that arg.
void FUN_00523700(const char* message);

// ============================================================================
// Engine-side list walks (the "scene render dispatch" data flow).
// ============================================================================
// These are the functions that actually traverse the engine globals and feed
// the renderer. They are the faithful ports of the walk loops confirmed by
// disasm of FUN_0050e4d0 (textures) and FUN_0050e540 (placed objects).

// FUN_0050e4d0 — walk g_TextureEntityList (DAT_005a78b4) and dispatch each
//   texture sub-entry to renderer slot +0xb4. Confirmed by disasm:
//     [0x50e4d1] mov esi,[0x5a78b4]        ; head
//     [0x50e4dd] mov eax,[esi+0x28]        ; node->sub_count
//     [0x50e4e6] lea ebx,[esi+0x2c]        ; node->entries[0]
//     [0x50e4e9] mov eax,[0x654940]        ; g_vRenderer
//     [0x50e4f0] call [eax+0xb4]           ; renderer slot 0xb4 (this, entry)
//     [0x50e4fd] add ebx,0x24              ; stride 0x24 (TextureEntry)
//     [0x50e504] mov esi,[esi]             ; node->next
//   Then walks the second list DAT_005a78b8 the same way (stride 4, single
//   entry per node at node+4).
// Returns the total number of texture entries dispatched.
uint32_t SceneWalk_Textures(void);

// SceneWalk_PlacedObjects — walk g_PlacedObjectList (DAT_006313c8) and dispatch
//   each placed entity to its vtable[0x30] (OBJECT::Render). This mirrors the
//   walk loop confirmed in FUN_0050e540 [0x50e597..0x50e60f]:
//     [0x50e597] mov ecx,[0x6313c8]        ; outer head
//     [0x50e5a5] mov eax,[ecx+0xc]         ; outer node -> inner list header
//     [0x50e5ac] mov edx,[eax+8]           ; inner header -> count
//     [0x50e5b3] mov ebp,0x400             ; entity-ptr base offset
//     [0x50e5c1] mov esi,[eax+ebp]         ; entity = inner[ebp]
//     [0x50e5c8] mov eax,[esi+0x68]        ; entity->sub_count
//     [0x50e5d1] lea edi,[esi+0x90]        ; entity->sub_array
//     (per sub-item: name-match via FUN_0050ea70)
//     [0x50e5fc] add ebp,4                 ; stride 4 between entity ptrs (10 slots: 0x400..0x428)
//     [0x50e607] mov ecx,[ecx]             ; outer node -> next
//   The renderer-private entity dispatch ((node-0x34)->vtable[0x30]) is done
//   INSIDE the renderer at slot +0x10 (RVA 0x2d80); the engine-side walk here
//   is the texture/uselist builder. For the recomp we expose the walk so the
//   per-entity Render can be called directly when vtables are populated.
// Returns the total number of placed entities iterated.
uint32_t SceneWalk_PlacedObjects(void);

// Combined scene-pipeline entry: the faithful FUN_00523aa0 behavior (gate check
// → FUN_00523700) PLUS, when the gate is open, the engine-side texture + entity
// walks. This is what gets installed as UpCalls callback[20] in the recomp.
void ScenePipelineEntry_Callback(void);

#ifdef __cplusplus
} // extern "C"
#endif
