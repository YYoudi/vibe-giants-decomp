# OBJECT VTABLE SYSTEM — Entity Render Dispatch & Vtable Mechanism

**Subject:** WHERE the entity "vtable" (`[entity+0x00]`) is installed — the critical
blocker for 3D rendering.
**Binary:** `G:\GiantsRE\GameFiles-VanillaV1\Giants.exe` (base `0x400000`) +
`G:\GiantsRE\GameFiles-VanillaV1\gg_dx7r.dll` (base `0x10000000`)
**Method:** capstone disasm (3 subagents + main), byte-pattern scan, cross-DLL trace.

---

## TL;DR — THE PREMISE WAS WRONG. HERE IS THE REAL MECHANISM.

The task brief, `OBJECT_CREATE_CHILD.md`, and `SCENE_RENDER_DISPATCH.md` all assumed:
> Entities have a vtable at `[entity+0x00]`; the renderer calls
> `vtable[0x30]` (`[vtable]+0x30`); entities have NULL vftable, blocking render.

**Disassembly proves this is FALSE at every level:**

1. **The renderer does NOT read `[entity+0x00]`.** The render dispatch at
   renderer slot `+0x10` (RVA `0x2d80`) does:
   ```
   node = renderer_obj->list_e4_first
   entity_proxy = node - 0x34
   call [entity_proxy + 0x30]        ; DIRECT fn-ptr, NO vtable indirection
   ```
   It reads the DWORD at `entity_proxy+0x30` and calls it. There is no
   `mov reg,[entity]; call [reg+0x30]` double-indirection. The `+0x30` field
   IS the function pointer — flat, direct.

2. **`entity_proxy` is NOT the engine EntityObject.** It is the renderer's
   PRIVATE **scene-entity** (`0x2d8` bytes, allocated inside `gg_dx7r.dll` by
   slot `+0x0c` at RVA `0x3490`). The scene-entity embeds a back-pointer to
   the engine entity at `scene_entity+0x3c`. The engine entity's `+0x34`
   (`link_node`) is the intrusive-list node the renderer walks.

3. **The engine entity's `[+0x00]` is NEVER a render vtable.** A full `.text`
   sweep of `Giants.exe` finds **ZERO** `call [reg+0x30]` instructions and
   **ZERO** `call [reg+0]` vtable-slot-0 dispatches. The engine does not
   dispatch render through the entity at all. `[entity+0x00]` is either
   unused by render, or serves gameplay-event dispatch (TBD — see §6).

4. **The Render function pointer is installed INSIDE `gg_dx7r.dll`, not in
   `Giants.exe`.** The scene-entity constructor + the type-setter vtable slot
   populate `[scene_entity+0x30]` from a per-type function table at
   `0x100191dc` in the DLL. The engine has no role.

**Implication for the recomp:** The "NULL vftable" check in
`SceneWalk_PlacedObjects` (`VanillaSceneDispatch.cpp`) is the BUG. The
original engine never checks `[entity+0]` before rendering — it doesn't render
entities at all. **The render path runs entirely in the renderer DLL over
renderer-private scene-entities.** To get visible geometry, the recomp must
feed the engine entity lists to the renderer via slot `+0xb4`, and let the
renderer build its own scene-entities with their own vtables. (See §7 recipe.)

---

## 1. THE RENDER DISPATCH CHAIN (verified, end-to-end)

### 1.1 Engine side — list population (Giants.exe)

```
FUN_0049c190 (entity pool allocator)
  ├── pop zeroed slot from free-list @ [0x631404]
  ├── rep stosd (0xC1 dwords = 0x304 bytes zeroed)
  ├── [esi+0xc4] = 1.0f
  ├── [esi+0xdc] |= 0x80000000
  ├── call 0x49c150  →  [esi+0x188] = unique_id
  └── call 0x472ef0(entity, &g_PlacedObjectList_head=0x6313c8)
        └── inserts into doubly-linked list at [0x6313c8]
            (node stride 0xC84, allocated from pool @ [0x59cadc])

FUN_0050e4d0 / FUN_0050e540 (scene walkers)
  ├── walk g_TextureEntityList ([0x5a78b4]) and g_PlacedObjectList ([0x6313c8])
  └── for each entry: call renderer_slot_b4(g_vRenderer, entry)
        └── [g_vRenderer+0xb4] = renderer slot +0xb4 (RVA 0xc6a0 in gg_dx7r.dll)
```

**The engine NEVER calls a render function on the entity.** It only hands
entity/texture references to the renderer via slot `+0xb4`.

### 1.2 Renderer side — scene-entity creation (gg_dx7r.dll)

```
slot +0xb4 (RVA 0xc6a0):
  └── tail-jump to FUN_0x1000c630 — moves engine data into renderer-internal list @ obj+0x4e8

Scene-entity creation path (called during model load, RVA 0x2f00-0x3070):
  ├── allocate 0x2d8 bytes (slot +0x0c, RVA 0x3490)
  ├── zero 0x36 dwords
  ├── [scene_entity+0x3c] = engine_entity_ptr          ; BACK-POINTER
  ├── [scene_entity+0x38] = &scene_entity+0x34          ; link-node self-ref
  ├── link scene_entity+0x34 into engine_entity->e4/e8 list
  ├── fill FULL vtable (0x88-0xe0 = ~30 method slots):  ; see §3
  │     [esi+0x88]=0x10007910, [esi+0x8c]=0x1000aba0, ... [esi+0xe0]=0x10007be0
  ├── [esi+0x58]=0x10003590, [esi+0x5c]=0x10003c70
  ├── [esi+0x00]=0x10003620  (vtable slot 0: dtor/list-remove)
  ├── [esi+0x04]=0x10003660  (vtable slot 1: SET-TYPE ← THIS INSTALLS RENDER)
  ├── [esi+0x0c]=0x100031d0  (vtable slot 3: link-node update)
  ├── [esi+0x30]=0x100022a0  (INITIAL Render = nop-ret placeholder)
  ├── call 0x10006520(...)   (load model/GBS geometry)
  └── call [esi+0x04]        (vtbl slot 1 = SET-TYPE → installs real Render)
```

### 1.3 The Render install (the answer to "where is [+0x30] set")

**Function:** `0x10003660` (scene-entity vtable slot 1, "set-type")
**Called at:** `0x10003026: call [esi+4]` during scene-entity init
**Signature:** `void set_type(SceneEntity* this, uint32_t type_id)`

```asm
0x10003660: mov  eax, [esp+4]          ; eax = scene_entity (this)
0x10003664: mov  ecx, [esp+0xc]        ; ecx = type_id (arg2)
0x1000366a: mov  esi, [eax+0x54]       ; current type
0x10003670: cmp  esi, ecx; je done     ; skip if same
            ; --- load 11 fn-ptrs from type-indexed tables ---
0x10003674: mov  esi, [ecx*4+0x10019104]; mov [eax+0x08], esi
0x1000367e: mov  esi, [ecx*4+0x1001911c]; mov [eax+0x10], esi
0x10003688: mov  esi, [ecx*4+0x10019134]; mov [eax+0x14], esi
0x10003692: mov  esi, [ecx*4+0x1001914c]; mov [eax+0x18], esi
0x1000369c: mov  esi, [ecx*4+0x10019164]; mov [eax+0x1c], esi
0x100036a6: mov  esi, [ecx*4+0x1001917c]; mov [eax+0x20], esi
0x100036b0: mov  esi, [ecx*4+0x10019194]; mov [eax+0x24], esi
0x100036ba: mov  esi, [ecx*4+0x100191ac]; mov [eax+0x28], esi
0x100036c4: mov  esi, [ecx*4+0x100191c4]; mov [eax+0x2c], esi
0x100036ce: mov  esi, [ecx*4+0x100191dc]; mov [eax+0x30], esi  ; ← RENDER INSTALL
0x100036d8: mov  esi, [ecx*4+0x100191f4]; mov [eax+0x88], esi  ; render-pass id
0x100036e5: mov  [eax+0x54], ecx       ; store new type
```

**THE EXACT INSTRUCTION THAT INSTALLS THE RENDER FUNCTION:**
```
0x100036ce: mov esi, [ecx*4 + 0x100191dc]   ; load Render fn for this type
0x100036d5: mov [eax + 0x30], esi            ; store into scene_entity+0x30
```
**Function:** `0x10003660` (vtable slot 1 "set_type"), inside `gg_dx7r.dll`.
**Source table:** `0x100191dc` (in gg_dx7r.dll `.data`), indexed by `type_id`.

### 1.4 The per-frame render dispatch

**Function:** renderer slot `+0x10`, RVA `0x2d80` in `gg_dx7r.dll`.
```asm
0x10002d80: mov  eax, [esp+4]          ; eax = renderer_obj
0x10002d86: mov  ecx, [eax+0xe4]       ; first node in render list
0x10002d8c: lea  edi, [eax+0xe4]       ; sentinel
            ; loop:
0x10002da0: add  eax, -0x34            ; eax = scene_entity (= node - 0x34)
0x10002da3: push eax                   ; this = scene_entity
0x10002da4: call [eax+0x30]            ; CALL scene_entity->Render
0x10002da7: mov  eax, esi              ; advance
0x10002dba: jne  loop                  ; until sentinel
```
**Reads `[scene_entity+0x30]` directly.** No vtable indirection through `[+0]`.

---

## 2. THE RENDER FUNCTION TABLE (per-type, at 0x100191dc)

The table at `0x100191dc` in `gg_dx7r.dll` `.data` holds the Render function
for each of the 6 renderer entity types (types 6+ are constants/flags, not
code ptrs — the table is only 6 entries deep before other data begins):

| type_id | Render fn (VA) | Role |
|---|---|---|
| 0 | `0x100022b0` | OPAQUE geometry render (DrawIndexedPrimitive) |
| 1 | `0x100023c0` | ALPHA/transparent render (multi-pass) |
| 2 | `0x100022b0` | OPAQUE (same as type 0) |
| 3 | `0x100023c0` | ALPHA (same as type 1) |
| 4 | `0x100023c0` | ALPHA (same as type 1) |
| 5 | `0x100022a0` | NOP (`ret`) — type 5 does not render (lights, markers) |

**Render fn `0x100022b0` (opaque) — confirmed draw routine:**
```asm
0x100022b0: push esi
0x100022b1: mov  esi, [esp+8]          ; this = scene_entity
0x100022b6: mov  eax, [esi+0x68]       ; vertex/index count
0x100022b9: mov  edi, [esi+0x3c]       ; engine entity back-ptr
0x100022be: test eax,eax; je ret       ; nothing to draw
0x100022c5: mov  [esi+0x78], 0
0x100022cc: mov  [esi+0x7c], eax
0x100022cf: call [esi+0x60]            ; per-pass setup fn
0x100022f3: mov  eax, [edi+0x508]      ; engine entity stat field
0x10002301: add  [edi+0x508], eax      ; update draw stats
0x10002322: mov  edi, [edi+0x294]      ; D3D device (from engine entity!)
0x10002328: push edx; push eax; ...    ; → DrawPrimitive via device vtable
```
**Both Render functions read `scene_entity+0x3c` (engine entity) to access
the D3D device at `engine_entity+0x294` and stats at `+0x508/+0x514`.**

### Full type-table map (11 tables → 11 scene_entity fields)

| Table VA (.data) | scene_entity offset | First 6 entries |
|---|---|---|
| `0x10019104` | `+0x08` | `0x10002270` ×5, `0x100022a0` |
| `0x1001911c` | `+0x10` | `0x10002520/570/520/570/570/6d0` |
| `0x10019134` | `+0x14` | `0x100025d0/5e0/5d0/5e0/5e0/0` |
| `0x1001914c` | `+0x18` | `0` ×5, `0x10002610` |
| `0x10019164` | `+0x1c` | `0` ×5, `0x100026a0` |
| `0x1001917c` | `+0x20` | `0` ×5, `0x10002750` |
| `0x10019194` | `+0x24` | `0` ×5, `0x10002770` |
| `0x100191ac` | `+0x28` | `0` ×5, `0x10002be0` |
| `0x100191c4` | `+0x2c` | `0` ×5, `0x10002c50` |
| **`0x100191dc`** | **`+0x30` (RENDER)** | **`0x100022b0/23c0/22b0/23c0/23c0/22a0`** |
| `0x100191f4` | `+0x88` (pass-id) | `2,3,4,5,6,0x7fffffff` |

**Type 5 is special** — it's the only type with non-zero entries in the
`+0x18`–`+0x2c` tables (it has extended behavior: lights/fx setup), but its
Render (`+0x30`) is a nop `ret` (it doesn't draw geometry directly).

---

## 3. THE SCENE-ENTITY FULL VTABLE (renderer-private, 0x2d8 bytes)

The scene-entity is a **C++ object with a complete vtable**, built entirely
inside `gg_dx7r.dll`. The vtable is installed at construction (RVA
`0x2f1c`–`0x3070`):

### 3.1 Static vtable (set at ctor, RVA 0x3490 + 0x2f00)

| scene_entity offset | VA installed | Role (inferred) |
|---|---|---|
| `+0x00` | `0x10003620` | vtable slot 0: destructor + list-removal |
| `+0x04` | `0x10003660` | vtable slot 1: **set_type** (installs per-type fns) |
| `+0x0c` | `0x100031d0` | vtable slot 3: link-node / sibling update |
| `+0x30` | `0x100022a0` | Render (INITIAL = nop; overwritten by set_type) |
| `+0x58` | `0x10003590` | material/texture bind |
| `+0x5c` | `0x10003c70` | transform/state apply |
| `+0x60` | `0x10003900` / `0x10003820` | per-pass setup (set per type at `0x1000370d/16`) |
| `+0x88`–`+0xe0` | (30 slots) | `0x10007910, 0x1000aba0, 0x100086a0, ...` full method table |

### 3.2 Per-type dynamic vtable (set by slot 1 / set_type)

After model load, `call [scene_entity+4]` invokes `set_type(this, type_id)`
which overwrites `+0x08` through `+0x30` and `+0x88` from the 11 type tables.

---

## 4. THE typeId → CLASS RESOLUTION CHAIN (engine side)

The engine's per-type dispatch (for gameplay, NOT render) uses `[entity+0x1e0]`
as the type_id and two tables in `Giants.exe` `.data`:

| Global VA | Stride | Role | Sample entries |
|---|---|---|---|
| `0x55f8cc` | `0x44` | "get extra size" per type | type1→`0x469a20`(0x348), type2→`0x4819c0`(0x200), type3→`0x4ca440`(0xfe0), type4→`0x4a3710`(0x64), type5/6→`0x4f0080`(0x24) |
| `0x55f8e4` | `0x44` | per-type update/cleanup | type1→`0x460340`, type2→`0x4819d0`, type3→`0x4cbcf0`, type4→`0x46c810` |

**Dispatch function:** `FUN_0049f480` reads `[entity+0x1e0]` and indexes these
tables. This is GAMEPLAY logic (AI, physics), not rendering.

### 4.1 The osl-list (master entity tree)

| Global VA | Role |
|---|---|
| `0x6313b4` | osl-list head (master entity-tree root) |
| `0x6313ac` | osl-list (built by `FUN_004b50b0` from `.BIN` placement rows) |
| `0x6313c8` | `g_PlacedObjectList` head (entities ready for render) |
| `0x6316ec` | current-template pointer (during readobjs.c loading) |
| `0x631404` | entity pool free-list head |
| `0x631408/0x40c` | entity alloc/free counters |

**osl-list node stride:** `0x304` per slot (10 slots per node, `+0x400..+0x428`).

### 4.2 The entity pool

- **Allocator:** `FUN_0049c190` — pops from free-list `[0x631404]`, zeroes
  `0x304` bytes, sets defaults, inserts into `g_PlacedObjectList` via
  `FUN_00472ef0`. **242 callers.** Returns zeroed entity with `[+0]=NULL`.
- **The `[entity+0x00]` field stays NULL** — no code path writes it with a
  vtable. The pool allocator zeroes it; no caller re-sets it.

---

## 5. WHAT THE PRIOR DOCS GOT WRONG (corrections)

### `OBJECT_CREATE_CHILD.md` §3 — "template/clone model"
> Claimed: "vtables are never written as immediate-constant stores... the
> entity vtable is established by cloning a template."

**Correction:** The entity vtable is never established at all — because there
is no entity vtable. The prior doc's sweep found "0 immediate-constant
writes" and correctly concluded there's no global vtable table, but
mis-inferred a clone model. The truth: **the engine entity has no render
vtable; the renderer has its own private scene-entity with its own vtable.**

### `SCENE_RENDER_DISPATCH.md` §3.2 — "EntityObject: +0x00 void* vftable"
> Claimed: `[entity+0x00]` is the vftable; `vtable[0x30/4 = slot 0xC] = Render`.

**Correction:** The `EntityObject` layout in `VanillaSceneTypes.h` has
`+0x00 = void* vftable` — this field exists but is **not used for rendering**.
The render dispatch reads `[scene_entity+0x30]` directly (scene_entity is a
different struct in the renderer DLL). The "+0x30 = slot 0xC of vtable at +0"
interpretation was a mis-read of the renderer's `call [eax+0x30]`.

### `SCENE_RENDER_DISPATCH.md` §3.3 — "Entities created by our list-inserts
currently have null vtables → skipped + logged."
This is the recomp's own bug. The original never checks `[entity+0]` for
render. The recomp's `SceneWalk_PlacedObjects` incorrectly gates on it.

---

## 6. WHAT IS `[entity+0x00]` THEN? (open question, lower priority)

The engine entity's `[+0x00]` is zeroed by the pool allocator and **never
written** by any code path I could find via static analysis. Possibilities:
1. **Truly unused** — a reserved/deprecated field. The PS2 EntityObject layout
   may have had a vtable there, but the PC build doesn't use it.
2. **Gameplay-event vtable** — set lazily by a per-type constructor that I
   couldn't isolate statically (subagent 2 suggested the `0x4010xx` cluster
   with runtime-filled BSS globals, but this is unconfirmed).
3. **COM-interface base** — if entities are treated as COM objects in some
   paths, `[+0]` would be the IUnknown vtable. But the engine has only 2
   `call [reg+8]` and 0 `call [reg+0]` — negligible COM usage.

**Recommendation:** Hook `FUN_0049c190` return in Frida, set a hardware
breakpoint (write watchpoint) on `[entity+0]`, and run the original game. If
the watchpoint never fires, `[+0]` is unused. If it fires, the firing
instruction is the true vtable-install site.

For RENDERING purposes, this field is irrelevant. Do not block on it.

---

## 7. RECIPE — "To install a real Render on an entity, do X"

The engine entity does not get a Render. The RENDERER gets scene-entities.
To get visible geometry in the recomp:

### Step 1: Feed engine lists to the renderer (ALREADY SCAFFOLDED)
The recomp's `SceneWalk_Textures` already calls `renderer_slot_b4`. Ensure
the engine entity/texture lists (`g_PlacedObjectList`, `g_TextureEntityList`)
are populated with real entities (not just stub SpawnTestEntity).

### Step 2: Ensure the renderer builds scene-entities
When `slot +0xb4` fires on the renderer with real engine data, the renderer
(running the ORIGINAL `gg_dx7r.dll`) will:
- Call `slot +0x0c` (RVA `0x3490`) to allocate a `0x2d8`-byte scene-entity.
- Link it into the engine entity's `+0xe4` list.
- Fill its full vtable (slot 0 = `0x10003620`, etc.).
- Load the model geometry (`0x10006520`).
- Call `set_type` (`[scene_entity+4]`) to install the Render fn from
  `0x100191dc[type_id]`.

**You do not need to port the vtable install — it happens automatically in
the original renderer DLL.** You only need to feed it valid engine entities.

### Step 3: Ensure entities have geometry data
The renderer's `0x10006520` (model loader) reads from the engine entity's
fields. The engine entity must have:
- `[+0x294]` = D3D device pointer (the Render fn reads this for DrawPrimitive).
- `[+0x508]`, `[+0x514]` = stat counters (written by Render).
- Geometry/mesh data accessible via the model-handle at `[scene_entity+0xf4]`.

### Step 4: Remove the null-vtable check
In `VanillaSceneDispatch.cpp` `SceneWalk_PlacedObjects`: delete the
`if (entity->vftable != nullptr)` gate. The original engine has no such check.
The render dispatch is the renderer's job, not the engine's.

### Step 5: Verify the dispatch fires
Set a Frida hook on renderer slot `+0x10` (RVA `0x2d80` in `gg_dx7r.dll`).
Log `[scene_entity+0x30]` per call. You should see `0x100022b0` (opaque) or
`0x100023c0` (alpha) for visible entities, `0x100022a0` (nop) for lights.

---

## 8. KEY ADDRESSES (quick reference)

### Giants.exe (base 0x400000)
| VA | Role |
|---|---|
| `0x49c190` | Entity pool allocator (free-list pop, zeroes entity, inserts into list) |
| `0x472ef0` | List-insert (pushes entity into g_PlacedObjectList at 0x6313c8) |
| `0x49c150` | UID generator (→ `[entity+0x188]`) |
| `0x49cfd0` / `0x49ccf0` | Template→instance field copy (positions, flags; skips +0) |
| `0x49f480` | Per-type gameplay dispatch (uses `[entity+0x1e0]`, tables at 0x55f8cc/e4) |
| `0x4b50b0` | osl/objl list builder (from .BIN placement rows) |
| `0x50e4d0` | Texture/entity list walker → renderer slot +0xb4 |
| `0x50e540` | Placed-object list walker (builds name-match uselist) |
| `0x6313c8` | `g_PlacedObjectList` head |
| `0x6313b4` | osl-list head (master entity-tree root) |
| `0x631404` | Entity pool free-list head |
| `0x55f8cc` | Per-type "extra size" table (stride 0x44, gameplay) |
| `0x55f8e4` | Per-type "update/cleanup" table (stride 0x44, gameplay) |

### gg_dx7r.dll (base 0x10000000)
| RVA / VA | Role |
|---|---|
| `0x2d80` / `0x10002d80` | **Render dispatch** (slot +0x10): walks obj+0xe4, calls `[scene_entity+0x30]` |
| `0x3490` / `0x10003490` | **Scene-entity ctor** (slot +0x0c): allocates 0x2d8 bytes, fills vtable |
| `0x3660` / `0x10003660` | **set_type** (vtable slot 1): installs Render from 0x100191dc |
| `0x36ce` / `0x100036ce` | **THE Render-install instruction**: `mov esi,[ecx*4+0x100191dc]; mov [eax+0x30],esi` |
| `0x22b0` / `0x100022b0` | Render fn: OPAQUE draw (types 0, 2) |
| `0x23c0` / `0x100023c0` | Render fn: ALPHA/transparent draw (types 1, 3, 4) |
| `0x22a0` / `0x100022a0` | Render fn: NOP `ret` (type 5 — no draw) |
| `0xc6a0` / `0x1000c6a0` | Engine-list bridge (slot +0xb4): moves engine data to renderer list |
| `0xc630` / `0x1000c630` | Scene-entity registration from engine data |
| `0x6520` / `0x10006520` | Model/GBS geometry loader |
| `0x191dc` / `0x100191dc` | **Render fn table** (6 entries, indexed by type_id) |
| `0x19104` / `0x10019104` | Type table #1 → scene_entity+0x08 (11 tables, stride 0x18) |

---

## 9. SUBAGENT FINDINGS (consolidated)

### Subagent 1 (clone-factory trace) — CORRECTED THE PREMISE
Proved that `0x5dc278`, `0x5dc280`, `0x63141c`, and the 8 "allocators"
(`0x49a9b0`–`0x49ae90`) are the **SDV audio subsystem** (`noise.c`), not
entity allocation. `0x5dc278 = SDVStart3DObj`, `0x5dc280 = SDVStart2DSample`,
installed by `FUN_0051f900` (SDV plugin loader). `0x63141c` = SFX sample table
(2000 entries, stride 0x2C, built by `FUN_0049a580`). The "entity-sized
allocations" were sound-instance spawns (coincidentally ~0x460 bytes).

### Subagent 2 (odef VM trace) — REFINED THE LOADER PATH
- The "jump table at 0x4baa28" is NOT a jump table — it's post-`ret` bytes
  misread as table entries. The odef/osl parsing uses sequential `cmp` dispatch.
- The `.BIN` loader only calls `0x49c190` (pool allocator) once, for a child
  array — not for top-level entities.
- Confirmed vtable-style dispatches exist at `0x529e03` (scene-graph root
  render) and `0x479a6d` (composite-object teardown), but these are on
  **scene-graph nodes / resource managers**, NOT EntityObject pool entities.
- Template construction at `0x4b79c1` sets `[template+0] = class_name_string`,
  NOT a vtable.

### Subagent 3 (PS2 re-match) — CONFIRMED AUDIO CLUSTER
Independently confirmed subagent 1's finding: the `0x5dc268`–`0x5dc2e8` slots
are UpCalls (runtime DLL exports), not static vtables. Size-matched the PS2
cluster: `object_setup_specialtype`→`0x49a588` (896B, exact 1.5x),
`object_init_type`→`0x49a440` (114B, exact 1.5x), `object_init_usage`→`0x49b496`
(403B, behavioral match — writes list-head pointers, not vtables).

---

## 10. BOTTOM LINE

**There is no entity vtable to install.** The render mechanism is:
1. Engine populates entity lists (done via `FUN_0049c190` pool alloc).
2. Engine feeds lists to renderer via slot `+0xb4`.
3. Renderer creates its OWN scene-entities (0x2d8 bytes) with their OWN vtable.
4. Renderer's `set_type` (`0x10003660`) installs the Render fn from
   `0x100191dc[type_id]` into `[scene_entity+0x30]`.
5. Renderer's slot `+0x10` (`0x2d80`) dispatches `call [scene_entity+0x30]`.

**The recomp's blocker is NOT a missing vtable — it's that the recomp's
`SceneWalk_PlacedObjects` tries to render entities directly (checking a
non-existent vtable) instead of delegating to the renderer via slot `+0xb4`.**
Fix the scene-walk to feed the renderer, and the original `gg_dx7r.dll` will
handle vtable installation and drawing automatically.
