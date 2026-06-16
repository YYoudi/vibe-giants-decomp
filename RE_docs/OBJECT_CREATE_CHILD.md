# OBJECT_CREATE_CHILD — Entity Constructor & Vtable Resolution

**Subject:** `Giants.exe!FUN_0045fde0` (vanilla 1.0 retail, base `0x400000`)
and the real entity-allocation / vtable-install path.
**Binary:** `G:\GiantsRE\GameFiles-VanillaV1\Giants.exe`
**Port:** `src_vanilla/VanillaObject.{h,cpp}`

---

## TL;DR — the blocker model was wrong; here is what the disasm proves

The task brief named `FUN_0045fde0` as *"the ctor that resolves typeId →
object class → installs the per-class vtable on the EntityObject"* — the
critical blocker for 3D rendering because the scene-render dispatch walks
`g_PlacedObjectList` and calls each entity's `vtable[0x30]` (Render), but
"entities have NULL vftable until object_create_child runs."

**Disassembly proves this is NOT what `FUN_0045fde0` does.** Three independent
facts:

1. **It never writes `[entity+0x00]` (the vtable slot).** A full instruction
   sweep of `0x45fde0..0x46032b` contains no `mov [ebp], <vtable>` or
   `mov [ebp+0], <ptr>`. The only `[ebp]`-relative writes are to `+0xe4`,
   `+0x104`, `+0x18c` — never offset 0.

2. **It takes ONE argument: a pointer to an already-allocated EntityObject.**
   `ebp = [esp+0x10]` at `[0x45fde3]`. All four E8 callers push an existing
   entity pointer:
   - `0x46176e` — pushes `esi` (entity), after `mov edi,[esi+0x100]`.
   - `0x46892c` — pushes `esi` (entity from `[esp+0x24]`).
   - `0x494800` — pushes `[0x6310e8]` (the global "current entity").
   - `0x535f96` — pushes `ebp` where `ebp=[eax+0xc]`, `eax=[0x6313c8]`
     (the placed-object list head) — i.e. an entity already in the list.

3. **PS2 debug symbols disagree with the address.** The propagated PC↔PS2
   match table (`ps2_symbols/pc_ps2_matches_full.csv`) maps PS2
   `object_create_child` (`0x139500`) to **PC `FUN_0050afb0`**, not `0x45fde0`.
   And `FUN_0050afb0` is *also* a child/attachment spawner that operates on
   already-allocated entities (it walks `g_PlacedObjectList` at `[0x50af2c]`
   and copies fields into matching entities). Neither function installs the
   vtable.

**So `FUN_0045fde0` is a ONE-SHOT child/attachment initializer** that runs the
first time an entity is touched (when `kind == 0`), spawning the light-pair,
8 attachment slots, special slot, and gravity/uselist fields. It is faithfully
ported in `VanillaObject.cpp` as `FUN_0045fde0(void* entity)`.

---

## 1. FUN_0045fde0 — confirmed signature & behavior

**Signature:** `uint32_t __cdecl FUN_0045fde0(EntityObject* entity);`
**Returns:** `1` on full init `[0x460324]`, `0` on early-out `[0x45fe07]`.

### Prologue & kind gate `[0x45fde0..0x45fe0b]`
```
0x45fde3: mov  ebp, [esp+0x10]          ; ebp = entity (the ONLY arg)
0x45fdea: mov  eax, [ebp+0xe8]          ; eax = entity->kind
0x45fdf0: mov  esi, [ebp+0x100]         ; esi = entity->fx_light (sub-struct)
0x45fdf6: cmp  eax, ebx(=0)
0x45fdf8: je   0x45fe0c                  ; kind==0 → run full init
0x45fdfa: push 0xf; push ebp; call 0x49f3b0   ; kind!=0 → event(0xf)
0x45fe05: xor  eax, eax; ...; ret       ; return 0 (already init'd)
```
**Semantic:** the function is idempotent. It runs once per entity (when kind
is still 0) and is a no-op thereafter.

### One-time level-stat table init `[0x45fe0c..0x45fe84]`
- Gate: `DAT_0059ca80` (BSS, zero at start). `[0x45fe0c]` reads it; if 0 the
  function runs the init loop then sets it to 1 at `[0x45fe84]`.
- Table: `DAT_0055c604`, **stride `0x1c`**, terminated by a record whose
  `[+0x10] == 0xfe`. `DAT_0055c5f8` holds `0x28` (a count/offset probe).
- Record layout (read from the binary): `{[0]=kind, [4]=group, [8]=0, [c]=0,
  [10]=class_id, [14]=statA, [18]=statB}`. First records have `class_id`
  `0x29, 0x2a, 0x2b, ...` and `statB = 0x2710` (10000, a score/health const).
- Apply callee: `FUN_00403800(entity, group, class_id)` `[0x45fe4b]`.
  **Not ported** (logged-only in the recomp). This table is a **per-level
  class-tuning table**, NOT a vtable table.

### Child spawn block `[0x45fe8e..0x46022a]` (runs when `(~[esi] & 1) != 0`)
`esi` = `entity->fx_light` sub-struct. The block:

| Step | VA | What it does |
|---|---|---|
| fx_light field zero-init | `0x45feaa..0x45fed9` | `[esi+0x78]=[esi+0x7c]=-1.0`, `[esi+0x90/0x98/0x9c]=-1`, `[esi+0x84]=0xfe`, `[esi+0xd8]=3`, `[esi+0xcc]=[esi+0xd4]=1.0`, `[esi+0x128]=[esi+0x134]=1.0` |
| Light-pair child #1 (red) | `0x45ff0d..0x45ffe2` | `FUN_0049c190(1, 0x2ed)` → "fx_buoy_red_light"; stored at `[esi+0x150]`; flags `+0xd8|=0x400000`, `+0xdc|=0x2000000`, `+0x1c8|=0x24000000\|0x20000000`; back-ptr `+0x210=entity`, `+0x218=0xa`, owner `+0x18c=[entity+0x18c]` |
| 8 attachment slots | `0x460063..0x4600d3` | loop 8×: `FUN_0049c6b0(0x362)` → slot; flags `+0xd8|=0x40010000`, `+0x1c8|=0x0e<<8`; written into a trailing array at `[esp+0x2c]` base, `+0x1c` per iter. **In the recomp these are placed at `entity+0x22c+i*0x1c`** (the destructor `FUN_00460440` walks `entity+0x100` then `+0x22c`, 8 slots stride `0x1c`, then `+0x314`). |
| Special slot | `0x4600d5..0x460122` | `FUN_0049c6b0(0x3d4)` → slot; same flags; stored at `[esi+0x314]` (i.e. `entity+0x314`). |
| Frame tick | `0x460128` | `eax=[0x631578]` (frame counter); `call FUN_00526ad0`. |
| Gravity | `0x46020e..0x46021d` | `[esi+0x220] = FUN_00469a30(entity, 0x20, 2, 4.0)` — 4.0 (`0x40800000`) is the gravity magnitude; `FUN_00469a30` is a physics-field setter. |
| Latch | `0x460223..0x46022a` | `[esi] |= 1` ("children spawned"). |

### Uselist / level-config block `[0x46022c..0x460319]`
- `[0x46022c]` `eax = [0x631530]` (current level id). If `[esi+0x120] != eax`,
  store it `[0x46023f]` and apply level config.
- `[0x46024f..0x460262]` first-time uselist alloc: if `[entity+0x104]==0`,
  zero `0xf` dwords at `[esi+0xe4]` and `call FUN_004a73b0(entity)`.
- `[0x46026d..0x4602d3]` copy floats from `DAT_00631538` (level descriptor):
  `+0x6b8→[useList+8]`, `+0x6b4→[useList+4]`, `+0x5f8→[useList+0x28]`,
  `+0x604→[useList+0xc]`, `+0x608→[useList+0x30]`.
- `[0x460307..0x460313]` `[esi+0x14c] = (useList[4]/useList[8]) * -32.174`
  (gravity `ft/s²`, const `DAT_0055251c`).
- `[0x460319]` `call FUN_0045eed0(entity)` — post-init hook.

### Epilogue `[0x460321..0x46032b]`
`pop edi/esi/ebp/ebx; mov eax,1; pop ecx; ret.`

---

## 2. What calls FUN_0045fde0 (the 4 E8 callers)

| Caller VA | Context | Arg |
|---|---|---|
| `0x46176e` | Gameplay update (`mov edi,[esi+0x100]` first); reads `[0x631754]` flag | `esi` (entity) |
| `0x46892c` | Entity creation dispatch (`jmp [eax*4+0x46923c]` switch on `[esp+0x30]`) | `esi` (entity) |
| `0x494800` | Spawn-from-list path: `[0x6310e8]` (current entity global), gated by `FUN_004ad1f0`/`FUN_00506ac0`/`FUN_00506b10` | `[0x6310e8]` |
| `0x535f96` | List-walk spawn: `eax=[0x6313c8]` (list head), `ebp=[eax+0xc]` (inner header), match on `[ebp+0x188]==[esi+1]` | `ebp` (entity) |

**All four pass an already-allocated, already-listed entity.** None allocate.
The `0x535f96` caller is the most informative: it walks `g_PlacedObjectList`
exactly like the render dispatch does and calls `FUN_0045fde0` per matched
entity — confirming the entity existed in the list **before** this call.

---

## 3. WHERE THE VTABLE ACTUALLY COMES FROM (the real blocker)

The per-entity vtable at `[entity+0x00]` is installed by the **entity
allocator** that creates the EntityObject and links it into
`g_PlacedObjectList`. Key findings from the binary:

### 3.1 No global per-class vtable TABLE
- A sweep of `.text` for `mov dword ptr [reg], <imm>` where `<imm>` is a
  `.rdata` (section 2, `0x152000..0x154478`) address returns **0 candidates**.
- The same sweep against `.data` (section 3 file-backed `0x155000..0x186000`)
  returns **0 candidates**.
- **Conclusion:** vtables are never written as immediate-constant stores. The
  engine does **not** keep a global `vtable* classVtables[N]` table indexed by
  typeId. There is no `switch(typeId)` that picks a vtable either.

### 3.2 Template/clone model (inferred)
Because the vtable write is a register-move (e.g. `mov [edi], esi` after
`lea esi, [...]` or after copying a template object), the entity vtable is
established by **cloning a template EntityObject** whose vtable was built once
at engine init (likely populated by the odef-VM / `object_init_type` /
`object_allocate_type` cluster in `readobjs.c`). The PS2 symbols name this
cluster:
- `object_allocate_init` (`0x172ea0`), `object_allocate_finit` (`0x172f30`),
  `object_allocator(int)` (`0x172f80`), `object_allocate_type` (`0x1734c8`),
  `object_allocate_type2` (`0x1734e8`), `object_allocate_type_end`
  (`0x173508`), `object_allocate_type_end2` (`0x173580`),
  `object_init_type` (`0x174070`), `object_init_usage` (`0x174eb0`),
  `object_init_ospec` (`0x175240`).

  These are the real "allocate + install vtable" functions. **They are not
  yet ported** — the propagated PC↔PS2 matches for them are low-confidence
  (0.40) and at least one (`object_allocate_type` → `FUN_00559dc0`) lands on a
  string table, not code. Re-matching this cluster against the PC binary is
  the next RE step (see §5).

### 3.3 What populates g_PlacedObjectList
- `FUN_004b50b0` (`readobjs.c`, strings `odef`/`osl`/`objl`/`odl` at
  `0x562d10/0x563104/0x562fb0/0x563118`) builds the **osl/objl** lists at
  `DAT_006313ac/b0/b4` from the `.BIN` `ObjectRef6` placement rows. These are
  the *placement records* (stride `0x464`), not yet the entity objects.
- The single writer of `g_PlacedObjectList` head (`0x6313c8`) is the
  **teardown** at `0x473142` (`xor eax,eax; mov [0x6313c8..0x631400],eax`) —
  a destructor. The list is built by head-insertion scattered across the
  `object_*` cluster (238 binary references to `0x6313c8`).
- `FUN_0040bfd0` is the **entity lookup** (walks the list, matches on
  `[+0x1e0]`, `[+0xe8]` kind, `[+0x174]` variant) — it never writes `[+0]`.

---

## 4. The vtable[0x30] (Render) dispatch & per-class Render targets

### Dispatch site (renderer-private, slot +0x10 / RVA `0x2d80`)
The renderer walks its own `obj+0xe4` list (populated from the engine lists
via slot `+0xb4`) and calls `(node-0x34)->vtable[0x30]` per entity. This is
**inside `gg_dx7r.dll`**, not `Giants.exe` — the renderer binary holds the
actual `vtable[0x30]` resolution. (See `RE_docs/DX7_METHOD_MAP.md` §1 slot
`+0x10` and `RE_docs/SCENE_RENDER_DISPATCH.md`.)

### Per-class Render function list — NOT AVAILABLE YET
Because (a) the entity vtable is a cloned template, not a global table, and
(b) the dispatch resolves the slot inside the renderer DLL, **there is no
static list of per-class Render function addresses** to enumerate from
`Giants.exe` alone. The Render implementations live as entries in the cloned
template vtables, which are constructed at runtime by the `object_init_*`
cluster from the odef-VM scripts in the `.BIN` `odef` blob (opcodes
`0x13..0x84`, jump table `@0x4baa28`).

**To get the real per-class Render targets, the path is:**
1. Reverse `object_init_type` / `object_init_usage` (`readobjs.c`) to find
   where the template vtable is assembled.
2. Hook the renderer's slot `+0x10` (RVA `0x2d80`) in `gg_dx7r.dll` with
   Frida at runtime and dump `[entity+0x00]` + `[entity+0x00]+0x30` per
   entity class. The ~800 models (`xx_kabuto*`/`xx_mecc*`/`xx_reaper*`/
   `xx_smartie*`/`xx_vimp*`) will cluster into a small number of Render
   functions (one per superclass: character, vehicle, prop, fx, light).

---

## 5. What's needed for real drawing (the actual unblock sequence)

The faithful port of `FUN_0045fde0` (done) gets entities their child
attachments. To get entities a REAL vtable and a REAL Render, in order:

1. **Port the entity allocator (`object_allocate_*` / `object_init_type`).**
   Re-match the PS2 cluster (§3.2) to PC addresses with a tighter fingerprint
   than the propagated 0.40-confidence match. This is where `[entity+0x00]`
   gets set — the true blocker.
2. **Port `FUN_004b50b0` end-to-end** (the osl/objl builder from `.BIN`
   `ObjectRef6` rows → entity objects in `g_PlacedObjectList`). Currently
   `VanillaBinLoader.cpp` only seeks+logs.
3. **Port the odef-VM** (`@0x4baa28`, opcodes `0x13..0x84`) — it runs the
   per-class init scripts that configure the cloned template (model filename
   from typeId via `PlacedObj → ObjSet → ObjData → GBS`, per
   `memory/giants-format-specs.md`).
4. **Renderer slot `+0x10` (`0x2d80`) dispatch** — ensure the engine lists
   feed the renderer's `obj+0xe4` list via slot `+0xb4` (already scaffolded in
   `VanillaSceneDispatch.cpp` `SceneWalk_Textures`).
5. **D3D7 draw calls** — the real Render reads the resolved GBS/SKN/ANM and
   issues `DrawPrimitive` through the renderer vtable (see
   `RE_docs/DX7_RENDER_RECIPE.md`).

### What the recomp has NOW (this change)
- `FUN_0045fde0` ported faithfully (child-init; idempotent; logs the
  not-yet-ported apply callees).
- `SpawnTestEntity(typeId,x,y,z)` — allocates an EntityObject, installs a
  **stub vtable** whose `[0x30]` Render is a logging no-op, head-inserts into
  `g_PlacedObjectList` in the two-level layout the walker expects, and runs
  `FUN_0045fde0`. **This unblocks the dispatch walk end-to-end**: the scene
  walker iterates non-NULL-vtable entities and invokes Render (logged), proving
  the dispatch chain is connected even before real drawing exists.
- The stub Render logs `entity / kind / variant / flags_e4` per call so the
  walk is observable in `vanilla_trace.log`.

---

## 6. Globals referenced (vanilla .data / BSS)

| VA | Name (recomp) | Role | Evidence |
|---|---|---|---|
| `0x59ca80` | `g_StatInitGate_59ca80` | one-shot level-stat init gate (BSS) | `[0x45fe0c]`, `[0x45fe84]` |
| `0x55c5f8` | — | stat-table count probe (=0x28) | `[0x45fe20]` |
| `0x55c604` | — | per-level class-stat table (stride 0x1c, term `[+0x10]==0xfe`) | `[0x45fe2f]` |
| `0x631530` | `g_CurrentLevel_631530` | current level id selector | `[0x46022c]` |
| `0x631538` | `g_LevelConfig_631538` | active level descriptor ptr (floats +0x5f8/+0x604/+0x608/+0x6b4/+0x6b8) | `[0x46026d]` |
| `0x631578` | `g_FrameCounter_631578` | frame counter | `[0x460128]` |
| `0x55251c` | — | gravity const `-32.174` (`ft/s²`) | `[0x46030d]` |
| `0x6310e8` | — | global "current entity" pointer | caller `[0x494765]` |
| `0x6313c8` | `g_PlacedObjectList` | placed-object list head | caller `[0x535f5e]`, dispatch walk |

### Confirmed strings
- `0x57d9e8` = `"AIMeccRange"` (lookup key in the `[0x50b034]` path)
- `0x556124` = `"fx_buoy_red_light"`, `0x556110` = `"fx_buoy_green_light"`
  (the light-pair children `FUN_0045fde0` attaches, read in `FUN_0040bfd0`)
- `0x562d10` = `"odef"`, `0x56311c` = `"C:\Giants\Source\main\readobjs.c"`,
  `0x563118` = `"odl"`, `0x563104` = `"osl"` (allocator tags in `FUN_004b50b0`)
