// Giants Vanilla-Native Recomp — Scene Render Dispatch (UpCalls[20] + scene processor).
//
// Faithful C++ ports of FUN_00523aa0 + FUN_00523700 (vanilla Giants.exe, base
// 0x400000), confirmed by capstone disassembly. See the companion .h for the
// high-level contract and RE_docs/SCENE_RENDER_DISPATCH.md for the full
// list-walk algorithm reference.
//
// Every renderer invocation uses the vanilla __cdecl(this, args...) convention
// (NOT thiscall): the renderer object pointer is pushed as the first stack arg,
// matching `call dword ptr [eax+<slot>]` after `push <this>`. See
// RE_docs/DX7_METHOD_MAP.md §1 ("__cdecl, first stack arg [esp+4] = this").
#include "VanillaSceneDispatch.h"
#include "VanillaSceneTypes.h"
#include "VanillaEngine.h"

#include <cstdio>
#include <cstdint>
#include <cstring>

extern "C" FILE* g_vTrace;   // defined in VanillaEngine.cpp / WinMain_vanilla.cpp

// ============================================================================
// Vanilla .data globals referenced by FUN_00523700 (overlay-frame render).
// ============================================================================
// These are the engine state bytes the scene-pipeline processor reads/writes.
// Vanilla addresses in .data (base 0x400000); zero-init in the recomp.
extern "C" {
    // DAT_00631568 — scene state enum. FUN_00523700 requires == 6 for the
    // "normal overlay" path; values <=2 or >=0xc branch to the menu/dialog path.
    uint32_t g_SceneState_631568 = 0;
    // DAT_005dcb6c — overlay-active flag #1 (must be 0 to render).
    uint32_t g_OverlayFlagA_5dcb6c = 0;
    // DAT_005dcb68 — overlay-active flag #2 ("overlay frame in progress").
    uint32_t g_OverlayFlagB_5dcb68 = 0;
    // DAT_005dcb58 — secondary gate (set non-zero by the dialog path).
    uint32_t g_OverlayGate_5dcb58 = 0;
    // DAT_005dcb10 — overlay refcount (inc/dec around the dialog call).
    uint32_t g_OverlayRefCount_5dcb10 = 0;
    // DAT_005dcb24 — "refcount hit zero" sticky flag.
    uint32_t g_OverlayZero_5dcb24 = 0;
    // DAT_005dca50 — text/font context handle (passed to the dialog thunk).
    uint32_t g_TextCtx_5dca50 = 0;
    // DAT_005dca58 — "first overlay frame done" latch.
    uint32_t g_OverlayFirstDone_5dca58 = 0;
    // DAT_00631107 / DAT_00631108 — input-edge bytes checked at frame end.
    uint8_t  g_InputEdge_631107 = 0;
    uint8_t  g_InputEdge_631108 = 0;
}

namespace {

// ============================================================================
// Renderer method-table invokers (__cdecl this-first, per DX7_METHOD_MAP.md §1).
// ============================================================================
// Vanilla pattern: `mov eax,[0x654940]; push <this>=eax; call [eax+<slot>]`.
// Each slot is a cdecl function whose first arg is the renderer object.

// Slot +0x98 (RVA 0x87e0) — DrawPrimitive-style stage-3 entry. In FUN_00523700
// it is called as `(renderer, 0)` to open the overlay draw pass.
//   [0x52375f] mov eax,[0x654940]; push ebx(=0); push eax; call [eax+0x98]
inline void RendererSlot98(void* renderer, uint32_t arg) {
    if (!renderer) return;
    typedef void(__cdecl *Slot98Fn)(void*, uint32_t);
    void** vtbl = *(void***)renderer;
    (*(Slot98Fn)vtbl[0x98 / 4])(renderer, arg);
}

// Slot +0xa8 (RVA 0x8990) — present/EndScene-equivalent. Called as `(renderer)`
// to close the frame. [0x523953] push eax; call [eax+0xa8]
inline void RendererSlotA8(void* renderer) {
    if (!renderer) return;
    typedef void(__cdecl *SlotA8Fn)(void*);
    void** vtbl = *(void***)renderer;
    (*(SlotA8Fn)vtbl[0xa8 / 4])(renderer);
}

// Slot +0x84 (RVA 0x73e0) — scene-state refcount toggle. Called as
// `(renderer, 1)` to mark scene-enter. [0x5239de] push 1; push eax; call [eax+0x84]
inline void RendererSlot84(void* renderer, uint32_t arg) {
    if (!renderer) return;
    typedef void(__cdecl *Slot84Fn)(void*, uint32_t);
    void** vtbl = *(void***)renderer;
    (*(Slot84Fn)vtbl[0x84 / 4])(renderer, arg);
}

// Slot +0xb4 (RVA 0xc6a0) — entity/texture-list thunk → list walker 0xc630.
// Called as `(renderer, entry)` per texture sub-entry. Confirmed by
// FUN_0050e4d0 [0x50e4f0]: `call [eax+0xb4]` with (renderer, &entry).
inline void RendererSlotB4(void* renderer, void* entry) {
    if (!renderer) return;
    typedef void(__cdecl *SlotB4Fn)(void*, void*);
    void** vtbl = *(void***)renderer;
    (*(SlotB4Fn)vtbl[0xb4 / 4])(renderer, entry);
}

} // namespace

// ============================================================================
// FUN_00523aa0 — UpCalls callback[20] "ScenePipelineEntry".
// ============================================================================
// Faithful 1:1 port. Vanilla [0x523aa0]:
//   call 0x4290e0          ; FUN_004290e0 → returns g_ScenePipelineGate
//   test eax, eax
//   je  0x523aae           ; gate zero → return
//   jmp 0x523700           ; gate non-zero → tail-call FUN_00523700
//   0x523aae: ret
// FUN_004290e0 [0x4290e0]: `mov eax,[0x58c15c]; ret` — trivial gate read.
extern "C" void FUN_00523aa0(void) {
    // [0x523aa0] call 0x4290e0  →  eax = g_ScenePipelineGate
    if (g_ScenePipelineGate == 0) {
        // [0x523aa7] je 0x523aae  →  ret
        return;
    }
    // [0x523aa9] jmp 0x523700  — tail-jump into the scene processor.
    // The vanilla jmp passes no explicit arg (the overlay path reads [esp+0x48]
    // which is whatever the renderer pushed before calling callback[20]; for
    // the recomp we forward a default overlay message).
    FUN_00523700(nullptr);
}

// ============================================================================
// FUN_00523700 — scene-pipeline processor (overlay/error frame render).
// ============================================================================
// Faithful port of the vanilla overlay-render path. The disasm shows this is
// the loading-screen / error-screen frame renderer (it draws the strings
// "Giants: Citizen Kabuto", "Escape to Exit Game", "Enter to Continue"). It is
// NOT the entity-list walker — the entity walk is in SceneWalk_PlacedObjects
// below (mirroring FUN_0050e540). See the .h header for the full rationale.
//
// Vanilla trace [0x523700..0x5239b7] (condensed):
//   [0x523700] sub esp,0x3c; push ebx; push ebp
//   [0x523705] mov ebp,[esp+0x48]           ; arg = message string
//   [0x523709] push ebp; call 0x429100      ; log/validate the message
//   [0x52370f] mov eax,[0x631568]           ; g_SceneState_631568
//   [0x523717] cmp eax,2; jle menu_path     ; state<=2 → menu/dialog
//   [0x52371f] cmp eax,0xc; jge menu_path   ; state>=12 → menu/dialog
//   [0x523721] cmp eax,6; jne 0x523a8f      ; state!=6 → menu/dialog
//   ; --- normal overlay render path (state==6) ---
//   [0x52372a] mov eax,[0x5dcb6c]; xor ebx,ebx; cmp eax,ebx; jne 0x523a8f
//   [0x523739] mov eax,[0x5dcb68]; ...; mov eax,[0x5dcb58]; jne 0x5239b8
//   [0x52374d] cmp eax,ebx; je 0x5239b8
//   [0x523755] mov [0x5dcb68],1             ; mark overlay frame in progress
//   [0x52375f] mov eax,[0x654940]; push ebx; push eax; call [eax+0x98]  ; slot 0x98 (begin)
//   [0x523771] call 0x51c680                ; overlay setup
//   [0x523782..0x52383e] push color constants; call 0x432fb0 (×8)       ; color table init
//   [0x523843] mov eax,[0x654958]; push eax; call [eax+0x30]            ; sub-object dispatch
//   [0x52384f..] mov al,[ebp]; ...; je skip                              ; draw message text
//   [0x523863..0x5238c2] per-line text loop: call 0x5452a0 (strlen-ish) then 0x521060 (draw text)
//   [0x5238c4..0x52393e] draw the 4 fixed overlay lines via 0x521060:
//                         "Giants: Citizen Kabuto" (0x57fdf4, color 0xe0e0ff)
//                         "Wintry Cool Game Error Screen" (0x57fdd4, color 0xe0e0ff)
//                         "Enter  to Continue" (0x57fdc0, color 0xc0c0df)
//                         "Escape to Exit Game" (0x57fdac, color 0xc0c0df)
//   [0x523943] call 0x4fe450; call 0x455280                               ; camera/frame update
//   [0x52394d] mov eax,[0x654940]; push eax; call [eax+0xa8]             ; slot 0xa8 (present)
//   [0x52395c] call 0x51f0e0; call 0x51f1f0; call 0x41f400              ; input tick
//   [0x52396b] cmp [0x631108],0; jne done; cmp [0x631107],0; je loop_top ; input-edge check
//   [0x52397f] mov eax,1; mov [0x5dca58],eax; mov [0x5dcb6c],eax         ; latch + set overlay flag
//   [0x52398e] mov eax,[0x654940]; push ebx; push eax; call [eax+0x98]  ; slot 0x98 (re-begin)
//   [0x52399b] mov eax,[0x654940]; push eax; call [eax+0xa8]            ; slot 0xa8 (present)
//   [0x5239aa] mov [0x5dcb68],ebx                                         ; clear overlay-in-progress
//   ; --- return ---
//   [0x5239b0..0x5239b7] pop edi/esi/ebp/ebx; add esp,0x3c; ret
//   ; --- menu/dialog path (0x5239b8..0x523a94) ---
//   [0x5239b8] inc g_OverlayRefCount; set g_OverlayZero on overflow
//   [0x5239d7] renderer slot +0x84(renderer, 1)  ; refcount toggle
//   [0x5239f0] call 0x51e7c0 (UpdateTime) when refcount==0
//   [0x5239f5..0x523a2b] 7-arg cdecl call via [0x55220c] (dialog thunk)
//   [0x523a2d..] dec refcount; re-toggle slot 0x84; UpdateTime again
//   [0x523a6e] cmp edi,2; je latch; cmp edi,3; jne return; latch + set flag
extern "C" void FUN_00523700(const char* message) {
    // [0x52370f] state guard: only the normal render path runs when state==6.
    // The vanilla code branches to the menu/dialog path otherwise; we keep
    // that semantic by early-returning on the non-6 states (the dialog thunk
    // at [0x55220c] is a function pointer we do not yet have a faithful port
    // of — logging instead of inventing one).
    if (g_SceneState_631568 != 6) {
        if (g_vTrace) {
            fprintf(g_vTrace, "[SCENE/0x523700] state=%u (menu/dialog path, not ported)\n",
                    g_SceneState_631568);
            fflush(g_vTrace);
        }
        return;
    }
    // [0x52372a] overlay-flag guard.
    if (g_OverlayFlagA_5dcb6c != 0) {
        return;
    }
    // [0x523739..0x52374d] second guard: if overlay already in progress or
    // the secondary gate is closed, take the menu branch.
    if (g_OverlayFlagB_5dcb68 != 0 || g_OverlayGate_5dcb58 == 0) {
        // Menu/dialog path — see trace above. Not yet ported (dialog thunk).
        if (g_vTrace) {
            fprintf(g_vTrace, "[SCENE/0x523700] menu path (flagB=%u gate=%u)\n",
                    g_OverlayFlagB_5dcb68, g_OverlayGate_5dcb58);
            fflush(g_vTrace);
        }
        return;
    }

    void* renderer = g_vRenderer;
    if (!renderer) {
        if (g_vTrace) { fprintf(g_vTrace, "[SCENE/0x523700] no renderer\n"); fflush(g_vTrace); }
        return;
    }

    // [0x523755] mark overlay frame in progress.
    g_OverlayFlagB_5dcb68 = 1;
    // [0x52375f] renderer slot +0x98 (begin draw pass).
    RendererSlot98(renderer, 0);

    // [0x5238c4..0x52393e] draw the fixed overlay lines. The vanilla calls
    // FUN_00521060(color, 0, x, y, ...) per line; we log since the text-draw
    // helper (FUN_00521060) is not yet ported. Drawing the message string
    // (if any) uses the same path at [0x5238a5].
    if (g_vTrace) {
        fprintf(g_vTrace, "[SCENE/0x523700] overlay frame: '%s'\n",
                message ? message : "(none)");
        fflush(g_vTrace);
    }

    // [0x52394d] renderer slot +0xa8 (present / EndScene).
    RendererSlotA8(renderer);

    // [0x52395c..0x523966] input tick (FUN_0051f0e0/0051f1f0/0041f400) — not
    // ported here; the recomp's main loop drives input separately. We only
    // honor the input-edge latches that the overlay path checks.

    // [0x52396b..0x52397f] if an input edge fired, latch the overlay-done
    // flags and run one more begin/present pair.
    if (g_InputEdge_631108 != 0 || g_InputEdge_631107 == 0) {
        // [0x523979] je loop_top — keep the overlay looping (no edge yet).
        // We do NOT loop here (the renderer's per-frame method re-enters
        // callback[20] each frame); just leave the flags for the next frame.
    } else {
        // [0x52397f] mov eax,1; mov [0x5dca58],eax; mov [0x5dcb6c],eax
        g_OverlayFirstDone_5dca58 = 1;
        g_OverlayFlagA_5dcb6c = 1;
        // [0x52398e..0x5239a7] one final begin/present pair.
        RendererSlot98(renderer, 0);
        RendererSlotA8(renderer);
    }

    // [0x5239aa] clear overlay-in-progress.
    g_OverlayFlagB_5dcb68 = 0;
    // [0x5239b0..0x5239b7] epilogue.
}

// ============================================================================
// SceneWalk_Textures — faithful port of FUN_0050e4d0 (texture-list dispatch).
// ============================================================================
// Walks g_TextureEntityList (DAT_005a78b4) and dispatches each texture
// sub-entry to renderer slot +0xb4. Confirmed 1:1 by disasm of FUN_0050e4d0:
//   [0x50e4d1] mov esi,[0x5a78b4]          ; node = head
//   [0x50e4d7] test esi,esi; je done       ; empty list
//   [0x50e4dd] mov eax,[esi+0x28]          ; node->sub_count
//   [0x50e4e6] lea ebx,[esi+0x2c]          ; node->entries[0]
//   loop_entries:
//   [0x50e4e9] mov eax,[0x654940]          ; renderer
//   [0x50e4f0] call [eax+0xb4]             ; (renderer, entry)
//   [0x50e4fd] add ebx,0x24                ; next entry (stride 0x24)
//   [0x50e502] jb loop_entries
//   [0x50e504] mov esi,[esi]               ; node->next
//   [0x50e508] jne outer_loop              ; (back to 0x50e4dd)
//   ; then DAT_005a78b8 (second list, stride 4, single entry per node at +4)
//   [0x50e50c] mov esi,[0x5a78b8]
//   [0x50e520] call [eax+0xb4]             ; per node
//   [0x50e526] mov esi,[esi]; jne ...
extern "C" uint32_t SceneWalk_Textures(void) {
    void* renderer = g_vRenderer;
    uint32_t dispatched = 0;

    // Primary list: g_TextureEntityList (DAT_005a78b4).
    TextureListNode* node = (TextureListNode*)(uintptr_t)g_TextureEntityList;
    while (node) {
        uint32_t sub_count = node->sub_count;          // [0x50e4dd] [esi+0x28]
        TextureEntry* entry = (TextureEntry*)((uintptr_t)node + 0x2c); // [0x50e4e6]
        for (uint32_t i = 0; i < sub_count; ++i) {
            if (renderer) {
                RendererSlotB4(renderer, entry);        // [0x50e4f0] call [eax+0xb4]
            }
            ++dispatched;
            entry = (TextureEntry*)((uintptr_t)entry + 0x24); // [0x50e4fd] stride
        }
        node = node->next;                              // [0x50e504] mov esi,[esi]
    }

    if (g_vTrace && dispatched) {
        fprintf(g_vTrace, "[SCENE/WalkTextures] dispatched %u entries via slot 0xb4\n",
                dispatched);
        fflush(g_vTrace);
    }
    return dispatched;
}

// ============================================================================
// SceneWalk_PlacedObjects — placed-object list walk (mirrors FUN_0050e540).
// ============================================================================
// Walks g_PlacedObjectList (DAT_006313c8). Node layout confirmed by
// FUN_0050e540 [0x50e597..0x50e60f]:
//   outer node:  +0x00 next, +0x0c → inner-list header pointer
//   inner header: +0x08 = entity-ptr count (10 max: ebp 0x400..0x428, stride 4)
//   entity ptrs: inner_header[ebp]  (ebp = 0x400, 0x404, ..., 0x424)
//   per entity:  +0x68 = sub_count, +0x90 = sub_array (stride 0x50)
//
// The vanilla renderer's per-entity dispatch ((node-0x34)->vtable[0x30]) is
// performed INSIDE the renderer at slot +0x10 (RVA 0x2d80) which walks the
// renderer's OWN obj+0xe4 list. The engine-side walk here iterates the
// engine globals directly so the recomp can drive OBJECT::Render once entity
// vtables are populated. Until then, entities created by our list-inserts
// have null vtables → we skip gracefully and log.
extern "C" uint32_t SceneWalk_PlacedObjects(void) {
    uint32_t iterated = 0;

    // [0x50e597] mov ecx,[0x6313c8]  — outer head.
    uintptr_t outer = (uintptr_t)g_PlacedObjectList;
    while (outer) {
        // [0x50e5a5] mov eax,[ecx+0xc]  — inner list header.
        uintptr_t inner_hdr = *(uintptr_t*)(outer + 0x0c);
        // [0x50e5ac] mov edx,[eax+8]  — entity-ptr count.
        // Vanilla skips the node entirely if inner is null or count is 0
        // ([0x50e5af] test edx,edx; je 0x50e607).
        if (inner_hdr) {
            uint32_t count = *(uint32_t*)(inner_hdr + 0x08);
            if (count != 0) {
                // [0x50e5b3] mov ebp,0x400  — entity-ptr base offset.
                // [0x50e5fc] add ebp,4; cmp ebp,0x428; jb  — 10 slots, stride 4.
                for (uintptr_t off = 0x400; off < 0x428; off += 4) {
                    // [0x50e5c1] mov esi,[eax+ebp]  — entity pointer.
                    uintptr_t entity_raw = *(uintptr_t*)(inner_hdr + off);
                    if (!entity_raw) { continue; }            // [0x50e5c4] test; je

                    EntityObject* entity = (EntityObject*)entity_raw;
                    ++iterated;

                    // Entity dispatch: (entity)->vtable[0x30] = OBJECT::Render.
                    // (The renderer-private path is (node-0x34)->vtable[0x30]
                    // at slot +0x10; here entity IS the OBJECT so we call its
                    // own vtable.)
                    if (entity->vftable) {
                        void** vtbl = (void**)entity->vftable;
                        typedef void(__cdecl *RenderFn)(EntityObject*);
                        RenderFn render = (RenderFn)vtbl[0x30 / 4];
                        if (render) {
                            render(entity);
                        }
                    } else if (g_vTrace) {
                        // Entities created by our list-inserts have null
                        // vtables for now → skip gracefully (per task spec).
                        fprintf(g_vTrace,
                                "[SCENE/WalkObjects] entity %p (kind=%u flags=%u) null vtable, skipped\n",
                                (void*)entity, entity->kind, entity->flags_e4);
                        fflush(g_vTrace);
                    }

                    // [0x50e5c8] mov eax,[esi+0x68]  — sub_count; the vanilla
                    // loop walks the sub-array at entity+0x90 (stride 0x50)
                    // calling FUN_0050ea70 (name-match). That is the uselist
                    // builder, not the render dispatch — skipped here.
                }
            }
        }
        // [0x50e607] mov ecx,[ecx]  — outer node -> next.
        outer = *(uintptr_t*)outer;
    }

    if (g_vTrace && iterated) {
        fprintf(g_vTrace, "[SCENE/WalkObjects] iterated %u placed entities\n", iterated);
        fflush(g_vTrace);
    }
    return iterated;
}

// ============================================================================
// ScenePipelineEntry_Callback — the recomp's UpCalls callback[20] install point.
// ============================================================================
// Faithful to FUN_00523aa0 (gate check → FUN_00523700) and additionally runs
// the engine-side texture + entity walks when the gate is open. This is what
// gets installed as UpCalls callback[20] in the recomp's callback table
// (replacing the Stub_Void placeholder in VanillaRenderer.cpp).
extern "C" void ScenePipelineEntry_Callback(void) {
    // [0x523aa0] gate check.
    if (g_ScenePipelineGate == 0) {
        return;
    }
    // Engine-side scene walks (the data flow SCENE_SYSTEM.md §4 describes):
    //   textures → renderer slot 0xb4
    //   entities → (entity)->vtable[0x30]  (OBJECT::Render)
    SceneWalk_Textures();
    SceneWalk_PlacedObjects();
    // [0x523aa9] jmp 0x523700 — the vanilla overlay/error-frame processor.
    FUN_00523700(nullptr);
}
