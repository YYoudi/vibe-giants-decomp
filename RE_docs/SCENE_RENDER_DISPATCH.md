# Giants (vanilla 1.0) — Scene Render Dispatch Reference

Reverse-engineering reference for the **scene render dispatch chain** — how the
populated render lists get walked and drawn each frame. All addresses are
vanilla `Giants.exe` (base 0x400000); disassembly confirmed via capstone
(`G:\GiantsRE\GameFiles-VanillaV1\Giants.exe`).

This document is the companion to `src_vanilla/VanillaSceneDispatch.{h,cpp}`.

> **Bottom line up front:** `FUN_00523aa0` (UpCalls callback[20]) is a 4-instruction
> gate check that tail-jumps to `FUN_00523700`. `FUN_00523700` is the
> **loading/error-overlay frame renderer** (it draws "Giants: Citizen Kabuto",
> "Escape to Exit Game", etc.), NOT the entity-list walker described
> aspirationally in `SCENE_SYSTEM.md §4`. The ACTUAL engine-side list walks are
> `FUN_0050e4d0` (textures → renderer slot `+0xb4`) and `FUN_0050e540` (placed
> objects → name-match/uselist build). The renderer-private entity dispatch
> `(node-0x34)->vtable[0x30]` happens INSIDE the renderer at slot `+0x10`
> (RVA `0x2d80`) over the renderer's OWN `obj+0xe4` list.

---

## 1. FUN_00523aa0 — UpCalls callback[20] "ScenePipelineEntry"

Exact disassembly (4 instructions):

```
0x523aa0: call 0x4290e0           ; eax = FUN_004290e0() = g_ScenePipelineGate
0x523aa5: test eax, eax
0x523aa7: je   0x523aae           ; gate == 0 → return (no work this frame)
0x523aa9: jmp  0x523700           ; gate != 0 → tail-jump to FUN_00523700
0x523aae: ret
```

`FUN_004290e0` (`0x4290e0`) is a trivial getter: `mov eax,[0x58c15c]; ret`. The
gate (`DAT_0058c15c`) is set by `FUN_004290f0(value)` (`mov eax,[esp+4];
mov [0x58c15c],eax; ret`), which WinMain calls with a non-zero value after
scene init completes (`FUN_004290f0(DAT_005dcb60)`).

**Port:** `FUN_00523aa0()` in `VanillaSceneDispatch.cpp` — 1:1.

---

## 2. FUN_00523700 — scene-pipeline processor (overlay/error frame render)

### 2.1 What it actually is

The disassembly proves this is the **loading-screen / error-screen overlay
renderer**, not the entity walk. Smoking-gun evidence — it pushes these rdata
strings and draws them via `FUN_00521060` (the text-draw helper):

| rdata addr | string |
|---|---|
| `0x57fdf4` | `"Giants: Citizen Kabuto"` |
| `0x57fdd4` | `"Wintry Cool Game Error Screen"` |
| `0x57fdc0` | `"Enter  to Continue"` |
| `0x57fdac` | `"Escape to Exit Game"` |

It is the same overlay render loop that `FUN_00523b60` (the intros-bin player,
`SCENE_SYSTEM.md §3`) drives with the same renderer slot pair (`+0x98` / `+0xa8`).

### 2.2 Control flow (condensed trace)

```
[0x523700] prologue: sub esp,0x3c; push ebx; push ebp
[0x523705] mov ebp,[esp+0x48]              ; arg = message string (from renderer's stack)
[0x523709] push ebp; call 0x429100         ; validate/log the message
[0x52370f] mov eax,[0x631568]              ; g_SceneState
[0x523717] cmp eax,2;  jle menu_path       ; state <= 2  → menu/dialog branch
[0x52371f] cmp eax,0xc; jge menu_path      ; state >= 12 → menu/dialog branch
[0x523721] cmp eax,6;  jne 0x523a8f        ; state != 6  → menu/dialog branch
        ─── normal overlay render path (state == 6) ───
[0x52372a] cmp [0x5dcb6c],0; jne menu_path ; overlay-active flag must be 0
[0x523739] cmp [0x5dcb68],0; jne 0x5239b8  ; overlay-in-progress must be 0
[0x523741] mov eax,[0x5dcb58]; jne 0x5239b8; secondary gate
[0x52374d] cmp eax,0; je 0x5239b8
[0x523755] mov [0x5dcb68],1                ; mark overlay frame in progress
[0x52375f] mov eax,[0x654940]              ; g_vRenderer
[0x523764] push 0; push eax; call [eax+0x98]; renderer slot +0x98 (begin draw pass)
[0x52376c] call 0x4551d0                   ; overlay setup
[0x523771] call 0x51c680                   ; overlay setup #2
[0x523776..0x52383e] 8× call 0x432fb0      ; color-table init (hardcoded float constants)
[0x523843] mov eax,[0x654958]; push eax; call [eax+0x30]  ; sub-object dispatch
[0x52384f] mov al,[ebp]; ...               ; message-string draw
[0x523863..0x5238c2] per-line text loop (0x5452a0 strlen + 0x521060 draw)
[0x5238c4..0x52393e] draw 4 fixed overlay lines via 0x521060
[0x523943] call 0x4fe450; call 0x455280    ; camera/frame update
[0x52394d] mov eax,[0x654940]; push eax; call [eax+0xa8]  ; slot +0xa8 (present)
[0x52395c] call 0x51f0e0; 0x51f1f0; 0x41f400  ; input tick
[0x52396b] cmp [0x631108],0; jne done      ; input edge → finish
[0x523973] cmp [0x631107],0; je loop_top   ; no edge → keep looping
[0x52397f] mov eax,1; mov [0x5dca58],eax; mov [0x5dcb6c],eax  ; latch flags
[0x52398e] slot +0x98 (begin); [0x5239a1] slot +0xa8 (present) ; final frame
[0x5239aa] mov [0x5dcb68],0                ; clear overlay-in-progress
        ─── return ───
[0x5239b0..0x5239b7] pop edi/esi/ebp/ebx; add esp,0x3c; ret
        ─── menu/dialog path (0x5239b8..0x523a94) ───
[0x5239b8] inc g_OverlayRefCount; sete g_OverlayZero on overflow
[0x5239d7] renderer slot +0x84(renderer, 1) ; scene-state refcount toggle
[0x5239f0] call 0x51e7c0 (UpdateTime) when refcount == 0
[0x5239f5..0x523a2b] 7-arg cdecl call via [0x55220c] (dialog thunk)
[0x523a2d..0x523a69] dec refcount; re-toggle slot 0x84; UpdateTime
[0x523a6e] cmp edi,2; je latch; cmp edi,3; jne return
[0x523a78] latch g_OverlayFirstDone + g_OverlayFlagA
[0x523a87..0x523a94] clear flagB; epilogue
```

### 2.3 Renderer methods called by FUN_00523700

All `__cdecl(this, ...)`, `this = g_vRenderer` (DAT_00654940). See
`DX7_METHOD_MAP.md §1` for the full slot map.

| call site | slot | RVA | args | semantic |
|---|---|---|---|---|
| `[0x523766]` | `+0x98` | `0x87e0` | `(this, 0)` | DrawPrimitive-style begin (open overlay draw pass) |
| `[0x523953]` | `+0xa8` | `0x8990` | `(this)` | present / EndScene (close frame) |
| `[0x523995]` | `+0x98` | `0x87e0` | `(this, 0)` | second begin (final frame after input edge) |
| `[0x5239a1]` | `+0xa8` | `0x8990` | `(this)` | second present |
| `[0x5239df]` | `+0x84` | `0x73e0` | `(this, 1)` | scene-state refcount toggle (menu path only) |
| `[0x523a58]` | `+0x84` | `0x73e0` | `(this, 0)` | refcount toggle (menu path, decrement) |
| `[0x52384c]` | `+0x30`* | — | `(sub_obj)` | sub-object dispatch (`[0x654958]+0x30`, NOT the renderer) |

`*` The `[0x52384c] call [eax+0x30]` reads `eax = [0x654958]` (a sub-object,
NOT the renderer at `0x654940`), so its `+0x30` is a different vtable.

**Port:** `FUN_00523700(message)` in `VanillaSceneDispatch.cpp` — faithful for
the `state==6` normal path; the menu/dialog branch (state!=6) logs and returns
(the dialog thunk at `[0x55220c]` is not yet ported).

---

## 3. The actual engine-side list walks

### 3.1 Walk algorithm (one paragraph)

The renderer's per-frame method (`slot +0x80`, RVA `0x7370`) calls the engine's
UpCalls callbacks during its internal pipeline. Callback[20] (`FUN_00523aa0`)
is the scene-pipeline entry: it checks `g_ScenePipelineGate` and, when open,
runs the overlay processor. The REAL list-to-renderer data flow happens through
two engine functions the renderer's other slots invoke: `FUN_0050e4d0` walks the
**texture/entity list** (`g_TextureEntityList = DAT_005a78b4`) — a singly-linked
list of `TextureListNode` (head-inserted by `FUN_0050d8f0`), where each node has
a `sub_count` at `+0x28` and a `sub_count`-long array of `TextureEntry`
(stride `0x24`) starting at `+0x2c`; each entry is dispatched to **renderer
slot `+0xb4`** (`(renderer, entry)`). `FUN_0050e540` walks the **placed-object
list** (`g_PlacedObjectList = DAT_006313c8`) — a singly-linked list of outer
nodes where `outer+0x0c` points to an inner-list header whose `+0x08` is a count
and whose `+0x400, +0x404, … +0x424` (10 slots, stride 4) are entity pointers;
each `EntityObject`'s `+0x68` is a sub-count and `+0x90` a sub-array (stride
`0x50`) used for name-matching (uselist build), NOT direct render. The actual
per-entity render dispatch — `(node-0x34)->vtable[0x30]` = `OBJECT::Render` — is
performed INSIDE the renderer at **slot `+0x10` (RVA `0x2d80`)**, which walks the
renderer's OWN private list at `obj+0xe4` (populated by the renderer from the
engine lists via slot `+0xb4` and the `+0x04`/`+0x0c` entity-node allocators).

### 3.2 Node strides and dispatch (confirmed by disasm)

**Texture/entity list** (`g_TextureEntityList`, head `DAT_005a78b4`):
```
TextureListNode:
  +0x00  TextureListNode* next          ; [0x50e504] mov esi,[esi]
  +0x04  char name[0x20]
  +0x24  uint32 data_size
  +0x28  uint32 sub_count               ; [0x50e4dd] mov eax,[esi+0x28]
  +0x2c  TextureEntry entries[sub_count]; [0x50e4e6] lea ebx,[esi+0x2c]
TextureEntry (stride 0x24):             ; [0x50e4fd] add ebx,0x24
  +0x00 .. +0x23  (texture/buffer payload)
```
Dispatch: `RendererSlotB4(renderer, &entry)` — `call [eax+0xb4]`.

**Placed-object list** (`g_PlacedObjectList`, head `DAT_006313c8`):
```
OuterNode:
  +0x00  OuterNode* next                ; [0x50e607] mov ecx,[ecx]
  +0x0c  InnerHeader* inner             ; [0x50e5a5] mov eax,[ecx+0xc]
InnerHeader:
  +0x08  uint32 entity_ptr_count        ; [0x50e5ac] mov edx,[eax+8]
  +0x400, +0x404, … +0x424  entity* (10 slots, stride 4)
        ; [0x50e5b3] mov ebp,0x400; [0x50e5fc] add ebp,4; cmp 0x428
EntityObject:
  +0x00  void* vftable                  ; vtable[0x30/4 = slot 0xC] = Render
  +0x34  void* link_node                ; (node-0x34)->vtable[0x30] dispatch target
  +0x68  uint32 sub_count               ; [0x50e5c8] mov eax,[esi+0x68]
  +0x90  SubItem sub_array[sub_count]   ; [0x50e5d1] lea edi,[esi+0x90], stride 0x50
  +0xe4  uint32 flags
  +0xe8  uint32 kind
```
Engine-side dispatch (in `SceneWalk_PlacedObjects`): when `entity->vftable` is
non-null, call `((RenderFn)vtbl[0x30/4])(entity)`. Entities created by our
list-inserts currently have null vtables → skipped + logged.

### 3.3 Renderer methods in the walk path

| slot | RVA | called from | args | role |
|---|---|---|---|---|
| `+0xb4` | `0xc6a0` | `FUN_0050e4d0 [0x50e4f0]` | `(this, TextureEntry*)` | entity/texture-list thunk → internal walker `0xc630` |
| `+0x10` | `0x2d80` | renderer-internal (scene render cluster) | `(this)` | scene-object dispatch: walks `obj+0xe4`, calls `(node-vt[0x30])` per entity |
| `+0x04` | `0x3090` | renderer-internal | `(this)` | entity-list node allocator (0x60-byte ctor) |
| `+0x0c` | `0x3490` | renderer-internal | `(this)` | scene-entity node allocator (0x2d8-byte ctor) |
| `+0xb0` | `0xc030` | renderer-internal | `(this, entity)` | entity visibility/flag cull (reads `[esi+0x1e]`) |

---

## 4. Unported OBJECT::Render functions (per-entity draw)

The `(entity)->vtable[0x30]` dispatch targets per-type Render methods that are
NOT yet ported. These live in the `004xxxxx` OBJECT cluster (PS2 symbols confirm
the `object_*` API — see `version_bridge/VERSION_MAP_v2.csv`). To get actual
geometry on screen, the following must be ported (each is a separate vtable[0x30]
target; the renderer's slot `+0x10` calls whichever the entity's vtable points
to). The list is derived from the `004xxxxx` cluster functions that write
entity vtables or are referenced as Render targets:

| vanilla addr | PS2 symbol | role | status |
|---|---|---|---|
| `0040bfd0` | `object_*` (light attach) | entity field init (+0xe4/+0x100/+0x174) | partial (field writes done) |
| `0045fde0` | `object_create_child` | entity ctor — installs vtable | **needed** (vtables stay null without it) |
| `00403470` | `ObjectSetAnim` | animation bind | needed for animated entities |
| `004203e0` | `object_set_location` | position write | needed for placement |
| `0049aa20` | `object_destroy` | entity dtor | needed for scene unload |
| `004ae510` | `ObjectCalculateTransform` | transform matrix build | needed for render |
| `004XXXXX` (per-class Render) | `ObjectRender*` | the actual vtable[0x30] draw bodies | **needed** — the slot `+0x10` dispatch targets |

**Critical dependency:** `FUN_0045fde0` (`object_create_child`) is the entity
constructor that installs the per-class vtable. Without it, every entity in
`g_PlacedObjectList` has a null `vftable`, so `SceneWalk_PlacedObjects` skips
them all (the recomp's current state — black screen with populated lists).
Porting `object_create_child` is the single highest-leverage unblock for visible
geometry.

---

## 5. Compilation

```
export PATH="/c/msys64/mingw32/bin:$PATH"
g++ -m32 -fsyntax-only -Isrc_vanilla src_vanilla/VanillaSceneDispatch.cpp
```
Result: **compiles clean** (exit 0) as of this writing.

---

## 6. File index

| file | role |
|---|---|
| `src_vanilla/VanillaSceneDispatch.h` | declarations for `FUN_00523aa0`, `FUN_00523700`, `SceneWalk_Textures`, `SceneWalk_PlacedObjects`, `ScenePipelineEntry_Callback` |
| `src_vanilla/VanillaSceneDispatch.cpp` | faithful ports + engine-side walk skeleton |
| `src_vanilla/VanillaSceneTypes.h` | `TextureListNode`/`TextureEntry`/`EntityObject` struct defs (offsets confirmed) |
| `src_vanilla/VanillaEngine.h` | `g_vRenderer`, `g_ScenePipelineGate`, `g_TextureEntityList`, `g_PlacedObjectList` globals |
| `RE_docs/DX7_METHOD_MAP.md` | full renderer slot map (`+0x98`/`+0xa8`/`+0x84`/`+0xb4`/`+0x10`) |
| `RE_docs/SCENE_SYSTEM.md` | list-population chain (§2), scene-load path (§3) |
