# Giants (vanilla 1.0) — Scene / Entity System

Reverse-engineering reference for **how the engine populates the entity/scene lists**
that the DX7 renderer (`gg_dx7r.dll`) walks each frame. All addresses are vanilla
`Giants.exe` (base 0x400000); decompiled bodies are in `vanilla_decompiled/<addr>.json`.

> Bottom line up front: the renderer object's `+0xe4`/`+0x4f0` fields are NOT lists the
> engine fills — they are **self-referential link nodes set up by `GDVSysCreate` itself**
> (see `RE_docs/DX7_RENDERER_CONTRACT.md` step 2: `[esi+0xe4]→[esi+0xe8]`, `[esi+0xec]→[esi+0xf0]`).
> The lists the engine must populate to draw 3D are **two global singly-linked lists in
> `.data`**: `DAT_005a78b4` (entity/texture list, walked by the scene renderer) and
> `DAT_006313c8` (placed-object/entity list, walked by the per-frame scene pipeline).
> Those are what the renderer's methods consume.

---

## 1. Data structures

### 1.1 Entity/texture list node (head: `DAT_005a78b4`)
Built by **`FUN_0050d8f0`** (`C:\Giants\Source\main\texture.c:0xf5`, per allocator tags).
Layout (verified from the allocator zero-fill and field reads in `FUN_0050e4d0`):

```
struct TextureListNode {          // size = 0x2c + count*0x24 (variable)
    TextureListNode* next;        // +0x00  (DAT_005a78b4 = head)
    char             name[0x20];  // +0x04  (32-byte name; copied from param_1)
    undefined4       data_size;   // +0x24  (iVar3 = FUN_0051d7f0(stream))
    uint             sub_count;   // +0x28  (puVar4[10]; number of TextureEntry below)
    TextureEntry     entries[sub_count]; // +0x2c, stride 0x24 (9 dwords)
};
struct TextureEntry {             // stride 0x24
    void* data;        // +0x00  → texture/buffer ptr (set during stream read)
    byte  flags0;      // +0x08  (FUN_0051d750 byte 1)
    byte  flags1;      // +0x09  (FUN_0051d750 byte 2)
    byte  state;       // +0x1a  (~state & 1 ⇒ unloaded; see FUN_0050daf0)
    ...                // +0x0a..0x23 name/string payload (variable)
};
```

Evidence (`vanilla_decompiled/0050d8f0.json`): allocation size is
`iVar2 + 0x2c + local_28 * 0x24`; the node is inserted head-first via
`*puVar4 = DAT_005a78b4; DAT_005a78b4 = puVar4;`; `puVar4[10] = local_28` (sub_count);
sub-entries start at `puVar4 + 0xb` (dword index 11 ⇒ byte +0x2c) with stride
`puVar2 + 9` (dword index ⇒ 0x24 bytes). Each entry is passed to the renderer as
`(**(code **)(DAT_00654940 + 0xb4))(DAT_00654940, entry)` — i.e. renderer method-table
slot **0xb4 / 0x2d0** (counted in DWORDs from `[esi]`).

A second, smaller list tail is `DAT_005a78b8` (walked in the same loops), and
`DAT_005a78bc` caches the tail of `DAT_005a78b4` for O(1) appends (`FUN_0050dc00`).

### 1.2 Placed-object / entity list (head: `DAT_006313c8`)
This is the **scene entity list** — populated by the placement reader
(`FUN_004b50b0`, `C:\Giants\Source\main\readwrls.c`) and walked by scene-render
helpers in `004xxxxx` (e.g. `FUN_0040bfd0` iterates it with `puVar1[3]` as the
entity pointer). Per-entity fields seen in `004xxxxx`:

```
struct EntityObject {        // ~0x500+ bytes (placed-object instance)
    vtable* vftable;         // +0x00  (method 0x30 = 0x2d80 dispatch target)
    EntityListNode link;     // +0x34 is the node used by renderer method 0x2d80:
                             //        renderer 0x2d80 does (node-0x34)->vtable[0x30]
    int      typeId_or_kind; // +0xe8  (matched in FUN_0040bfd0: puVar1[0xe8]==...)
    int      flags_e4;       // +0xe4  (set to 3 in buoy-light attach; FUN_0040bfd0)
    void*    fx_light_a;     // +0x100 (fx_buoy_red/green_light; FUN_0040bfd0)
    int      variant;        // +0x174 (entity variant/skin selector)
    void*    pair_ref;       // +0x274 (paired-entity pointer, e.g. light pair)
    int      type_tag_69;    // +0x1e0 (==0x69 selects buoy/light class)
    ...
};
```

PS2 debug symbols confirm the `004xxxxx` cluster is the **OBJECT API**
(`object_create_child` 0045fde0, `ObjectSetAnim` 00403470, `object_set_location`
004203e0, `object_destroy` 0049aa20, `ObjectCalculateTransform` 004ae510 — see
`version_bridge/VERSION_MAP_v2.csv`). So the renderer's `0x2d80` per-entity dispatch
`(node-0x34)->vtable[0x30]` is exactly `OBJECT->vtable->Render()`.

### 1.3 Level table (`DAT_00631388`, count `DAT_00631384`)
`FUN_004b7640(idx)` returns `DAT_00631388 + idx * 0x1428` — a 0x1428-byte
**level descriptor** whose `+0x04` is a `char**` to the level name string
(`FUN_0045a530` does `**(char**)(iVar1 + 4)` to get the first letter for the
"mecc/reaper/kabuto/giants loading" branch). `DAT_00631380` holds the **active
level index** (set to `0xffffffff` in `FUN_004f41c0`, then to the `intro_island`
match index by `FUN_004913c0`).

### 1.4 Renderer object internals (NOT engine-populated)
Per `RE_docs/DX7_RENDERER_CONTRACT.md`: `GDVSysCreate` allocates a 0x57c-byte
renderer object. At construction:
- `[obj+0xe4]` and `[obj+0xe8]` form a 2-node circular/self list,
- `[obj+0xec]` and `[obj+0xf0]` form another.
These are **renderer-private** (used by methods 0x2d80/0x71a0 for their own
traversal state) and are seeded by `GDVSysCreate`, **not** by the engine. The
engine-side "render lists" are the §1.1/§1.2 globals, passed to the renderer via
method-table invocations (slot 0xb4 for textures; slot 0x10 / method 0x2d80 for
entities through the entity's own vtable).

---

## 2. Who inserts (the engine-side list mutators)

| Address | Role | Evidence |
|---|---|---|
| **`FUN_0050d8f0`** | **Entity/texture-list INSERT** (head insertion at `DAT_005a78b4`). Allocates node from stream, copies name, reads sub-entries. | `0050d8f0.json`; allocator tag `texture.c:0xf5`; `*puVar4 = DAT_005a78b4; DAT_005a78b4 = puVar4;` |
| `FUN_0050dae0` | Entity-list RESET (`DAT_005a78b4 = 0; DAT_005a78b8 = 0`). | `0050dae0.json` |
| `FUN_0050dc00` | Compute list tail into `DAT_005a78bc` (fast-append cache). | `0050dc00.json` |
| `FUN_0050daf0` | Entity-list FLUSH: walks list, releases each entry via renderer slot 0xb4, frees nodes. | `0050daf0.json` |
| `FUN_0050e4d0` | Walk entity list and dispatch each entry to renderer (slot 0xb4). The "render-textures" pass. | `0050e4d0.json` |
| `FUN_0050ea70` | Walk entity list, name-match query. | `0050ea70.json` |
| `FUN_0050e540` | Build the **uselist** (`s_uselist`) aggregate from entity list. | `0050e540.json` |
| **`FUN_004b50b0`** | **Placed-object reader**: parses the `.BIN` objects section, creates `EntityObject` instances, appends to `DAT_006313ac` / `DAT_006313b0` / `DAT_006313c8` lists. Stride 0x464 per placed object. | `004b50b0.json` (`readwrls.c`) |
| `FUN_0040bfd0` (and the `004xxxxx` cluster) | Entity-object mutators (attach lights, set fields +0xe4/+0x100/+0x174). | `0040bfd0.json`; PS2 = `object_*` |
| `FUN_004b77f0` | **Level-table populate**: reads `worldlist.bin` (+`worldlist%d.bin`), validates magic `0x1a0003d0`, allocates `DAT_00631388` (count × 0x1428). | `004b77f0.json` |
| `FUN_004babf0` | Level-table free. | `004babf0.json` |

---

## 3. Scene-load path (WinMain → menu / intro_island)

Trace from `WinMain` (`FUN_005222c0`, `vanilla_decompiled/005222c0.json`):

1. **Window + renderer create**
   - `RegisterClassA("Example")` + `CreateWindowExA("Giants", style=0x6cf0000)`
   - `FUN_0051eb70(&renderer_name, &audio_name)` → loads `gg_dx7r.dll`, resolves
     `GDVSysCreate`/`UpCallsLoad`, installs the 21 UpCalls callbacks
     (`DAT_005dc01c`, `DAT_005dc020`).
   - `DAT_00654940 = GDVSysCreate(cmdLine, hWnd, w, h, bpp, 0, windowed, &guid1, &guid2)`
     → the renderer object. (`DAT_00654940` is the **global renderer pointer**.)

2. **Engine subsystem init** (`iVar4 = FUN_004f41c0()` — `vanilla_decompiled/004f41c0.json`)
   This is the **scene-system bootstrap**. In order:
   ```
   FUN_004db050();            // ?
   FUN_00510e90();            // ?
   DAT_006316ec = 0;          // world/game-state ptr (cleared)
   FUN_004f1fe0(&DAT_00631180); // ?
   FUN_004f4070();            // (returns 0 ⇒ abort)
   FUN_0050dae0();            // RESET entity/texture list (heads = NULL)
   FUN_004b4ba0();            // ?
   thunk_FUN_004b4ef0();      // ?
   FUN_004b77f0();            // *** READ worldlist.bin → level table ***
   FUN_004b7af0("Intro");     // *** LOAD the Intro scene ***
   FUN_0050dc00();            // cache entity-list tail
   FUN_0049c0c0();            // ?
   FUN_0040af10();            // ?
   FUN_0040b7c0();            // ?
   DAT_00631380 = 0xffffffff; // no active level yet
   DAT_006316ec = 0;
   FUN_004fe450();            // ?
   FUN_005324d0();            // ?
   FUN_004b0c10();            // ?
   return 1;
   ```
   - `FUN_004b7af0("Intro")` → `FUN_00544b47(buf, "W\\%s.bin", "Intro")` →
     **`FUN_004b7c50(buf, 1.0, 0)`** — the scene loader (see §3.1).
   - WinMain then calls `FUN_004290f0(DAT_005dcb60)` — this sets
     `DAT_0058c15c`, the **ScenePipelineEntry gate** (`FUN_004290e0` just reads
     it). Once non-zero, the renderer's `ScenePipelineEntry` callback
     (UpCalls[20] = `0x523aa0`) will execute `FUN_00523700`-style pipeline work.

3. **Post-init WinMain flow** (`005222c0.json`, second half)
   - `FUN_00520430(0x18)`, `FUN_00455300()`, `FUN_004fe450()`,
     `FUN_004290f0(DAT_005dcb60)` (enable pipeline gate),
     `FUN_0051ede0(cmdLine)` (DirectInput + cmd-line/replay parse).
   - On success: `FUN_0051f500()` (reg open), `FUN_0051f8a0("DefPlayer", ...)`
     (read registry), `FUN_0051f6c0()`, audio volume set, `FUN_0051f5b0()`,
     `FUN_0042bfe0()`, **`FUN_00523b60("intros_bin")`**, **`FUN_004913c0()`**,
     then the message loop.
   - **`FUN_00523b60("intros_bin")`** (`00523b60.json`): parses `intros.bin`,
     a newline-delimited list of intro-clip names. For each entry it builds
     `"%s.bin"`, calls `FUN_0050eb50` to attach scene textures, and runs a
     timed fade-in/out render loop driving:
     `(DAT_00654940 + 0x98)(renderer, 0)` — slot 0x98 / method offset 0x260
     (likely BeginScene/Clear), then `FUN_004551d0` / `FUN_004338d0` /
     `FUN_00455280` (camera/scene-frame), then
     `(DAT_00654940 + 0xa8)(renderer)` — slot 0xa8 / offset 0x2a0 (Present/End).
   - **`FUN_004913c0()`** (`004913c0.json`): the **intro_island selector**.
     If `FUN_0052f960()` (replay mode?) returns non-zero → `FUN_0052a050()`.
     Otherwise it scans the level table (`FUN_004b7640(i)` for `i` in
     `0..FUN_004b77c0()`) comparing the level name to `"intro_island"`
     (`FUN_0053c970(s_intro_island, *(level+4))`), stores the match index in
     `DAT_00631380`, calls `FUN_0045a520(idx)` (stashes it in `DAT_0059ca4c`),
     `FUN_0045a530()` (kicks the async scene-load task), and sets
     `DAT_005a766c = 1`.
   - `FUN_0045a530()` (`0045a530.json`): picks the loading-screen texture
     (`mecc/reaper/kabuto/giants_loading` based on level first letter),
     calls `FUN_0050e4d0()` (flush existing entity list to renderer),
     `FUN_0050f120(...)` (release textures), `FUN_0050eb50(...)` (load the
     loading-screen texture), then
     `FUN_0042be00(&LAB_0045a640, &LAB_0045a7c0)` — installs an **async
     dialog/load task** (stack at `DAT_0059a680`, slot depth `DAT_005586b8`)
     whose body is `FUN_0045a640`/`FUN_0045a7c0`. This task completes the
     per-level `.bin` load via `FUN_004b7c50` (see `FUN_004b7a10`).

### 3.1 Scene-file loader — `FUN_004b7c50` (`readwrls.c:0x1c9`)
**This is the actual scene/.BIN loader.** `FUN_004b7af0` wraps it as
`FUN_004b7c50("W\\<name>.bin", 1.0, 0)`. Body (`004b7c50.json`, 11736 bytes):

```
FUN_00539e30(path)                       // open via VFS (DAT_005e12b4 cache)
 → stream handle
validate magic: must be 0x1a0002e5       // else "Bad version for %s"
FUN_0051d750(stream, &hdr, 0x1c)         // read 7-dword header
FUN_0051d7b0(stream, local_398)          // seek
FUN_0049a580(stream)                     // load SFX/sound defs (sounds[]) —
                                         //   8-int records, stride 0x1c
FUN_0051d7b0(stream, local_39c)
FUN_0050d8f0(name, stream, version)      // *** ENTITY/TEXTURE LIST INSERT ***
FUN_0051d7b0(stream, local_390)
read fx_world selector (dust/snow/none)  // FUN_0044ab90
if (sub-scene count != 0):                // *** recursive sub-scene load ***
    for each sub-scene:
        read 0x20-byte name, format "%s_bin"
        FUN_004b7c50(sub, t0, t1)        // RECURSIVE
FUN_0051d7b0(stream, local_394)
FUN_004b50b0(stream, name)               // *** PLACED-OBJECT READER ***
                                         //   → fills DAT_006313ac/b0/c8
read entity-class name table (0x18-byte nodes)
set world globals on DAT_006316ec:
    +0x7c=0x447a0000(1000.0), +0x80=0x3d000000(0.03125),
    +0x84=0x3f000000(0.5), +0x505c=0x80, +0x5048..+0x5058=0,
    +0x5064=0x457a0000(1000.0 quasi-dup), +0x5060=0x42000000(32.0)
... (large body: camera, fog, sky, class bindings) ...
```

**Recursive sub-scene loading** is why a single `Intro.bin` fans out into many
`<name>_bin` files (matching the `.BIN` TOC container format in
`memory/giants-format-specs.md`: "0x30-byte TOC header" + object-placement
section as `ObjectRef6 = [typeId:u32][x,y,z:f32][angle,angle2,angle3:f32]`).
`FUN_004b50b0` is the consumer of that object-placement section.

---

## 4. Per-frame render driving (how the populated lists get drawn)

Inside WinMain's message loop (`005222c0.json`), each frame when
`DAT_0057fa60 == 1` (active) and not paused:

```
FUN_0051e7c0();   // UpdateTime — compute DAT_00630f28 (frame dt), smoothed
FUN_0051e7c0();   // (called again inside fade loops in 00523b60)
FUN_0051f0e0();   // DirectInput device Acquire/Poll → keyboard/mouse state
FUN_0051f1f0();   // DirectInput GetDeviceState (20 bytes) → key edges
FUN_004742f0();   // (network/multiplayer tick)
```

The **scene render itself** is driven by the **renderer's methods**, not by
direct engine calls. The engine:

1. Pushes entities/textures into the global lists (§2) — done at scene load.
2. Each frame, calls renderer method `(DAT_00654940 + 0x20)(renderer, frame)`
   — slot 0x20 / method `0x80` — the renderer's per-frame entry (returns the
   new `DAT_0057fa60` state: 1=active, 3=scene-transition).
3. The renderer, during its internal pipeline, invokes the UpCalls callbacks
   the engine registered:
   - **[7] SceneBegin** (`0x4a1320`) — begin a scene frame (no JSON in
     `vanilla_decompiled/` ⇒ it is an engine-side function whose decompile is
     absent; semantically marks scene-start).
   - **[8] SceneEnd** (`0x4a1340`) — mark scene-end (likewise absent).
   - **[20] ScenePipelineEntry** (`0x523aa0` — `00523aa0.json`): reads the
     gate `FUN_004290e0()` (= `DAT_0058c15c`, set by `FUN_004290f0`); if
     non-zero, calls `FUN_00523700` (the engine's scene-pipeline entry, which
     ultimately walks `DAT_006313c8` + textures and dispatches
     `OBJECT->vtable[0x30]` per entity, feeding vertices to renderer method
     `0x2d80`).
   - **[9] PreRenderCheck** (`0x50dd10`) — predicate whether to render this
     frame (visibility / paused).

So the **data flow** is:

```
scene .BIN ──FUN_004b7c50──► DAT_005a78b4 (textures)
                            └─FUN_004b50b0─► DAT_006313c8 (entities)
                                                  │
   each frame: renderer method 0x80 ◄─────────────┤ (engine calls)
                  │
                  ├── UpCalls[7]  SceneBegin
                  ├── UpCalls[20] ScenePipelineEntry ──► FUN_00523700
                  │       walks DAT_006313c8 ──► entity->vtable[0x30]
                  │       walks DAT_005a78b4 ──► renderer slot 0xb4 (textures)
                  │       entity render pushes verts ──► renderer method 0x2d80
                  └── UpCalls[8]  SceneEnd
```

---

## 5. Minimal recipe to draw SOMETHING (after `GDVSysCreate`)

To get a non-black frame (even just the menu background / a single island
entity), the shortest faithful engine-side sequence is:

```c
// (0) renderer already created: DAT_00654940 = GDVSysCreate(...);
//     UpCallsLoad(0x2775, 21, callbacks) already done by FUN_0051eb70.

// (1) Bootstrap the scene subsystem — this populates level table + loads Intro:
FUN_004f41c0();            // ★ does steps 2 of §3 in one call:
                           //   - FUN_0050dae0()            (reset lists)
                           //   - FUN_004b77f0()            (read worldlist.bin)
                           //   - FUN_004b7af0("Intro")     (load W\Intro.bin)
                           //     └─ FUN_004b7c50("W\\Intro.bin", 1.0, 0)
                           //        ├─ FUN_0050d8f0()  → fills DAT_005a78b4
                           //        └─ FUN_004b50b0()  → fills DAT_006313c8
                           //   - FUN_0050dc00()            (cache list tail)

// (2) Enable the scene-pipeline gate so the renderer's ScenePipelineEntry
//     callback actually executes the pipeline each frame:
FUN_004290f0(1);           // sets DAT_0058c15c = 1  (WinMain does this with
                           //   DAT_005dcb60 as the value, which is non-zero
                           //   post-init)

// (3) Drive the renderer's per-frame method once (minimal frame):
while (running) {
    FUN_0051e7c0();        // UpdateTime → DAT_00630f28
    // renderer per-frame entry (returns active state 1/3):
    DAT_0057fa60 = (*(code**)(DAT_00654940 + 0x20))(DAT_00654940, DAT_0057fa60);
    // The renderer internally calls SceneBegin/PipelineEntry/SceneEnd, which
    // walk the two global lists we just populated and dispatch entity
    // vtable[0x30] + texture slot 0xb4, ending at method 0x2d80 (draw) +
    // 0x98 (begin) / 0xa8 (present).
}

// (Optional, to go straight to intro_island instead of Intro.bin)
// FUN_004913c0();   // scans level table for "intro_island", sets
//                    //   DAT_00631380, kicks FUN_0045a530 (async load task)
```

**Hard prerequisites** (without these the lists stay empty regardless of the
above calls):
- The **VFS** must be able to resolve `W\Intro.bin`, `worldlist.bin`, and
  every recursively-referenced `<name>_bin` — these live inside `Giants.gpz`
  (GZP archive; see `memory/giants-format-specs.md` GZP section). `FUN_00539e30`
  is the VFS open (`DAT_005e12b4` is the GZP/file cache); if it returns 0,
  `FUN_004b7c50` aborts with "Failed to open %s".
- The **21 UpCalls callbacks** must be functional (esp. [17] VFSOpenFile
  `0x539f00`, [18] EngineAllocator `0x521a20`=malloc, [19] CRT_free
  `0x521a40`). See `memory/dx7-minimal-contract.md`.
- The **magic check** `0x1a0002e5` (scene) and `0x1a0003d0` (worldlist) must
  match — these are the `.BIN`/worldlist format versions.

If only a single textured quad is acceptable for a smoke test, the shortest
*unfaithful* path is to manually push one `TextureListNode` via the allocation
pattern in `FUN_0050d8f0` (size `0x2c + 1*0x24`, `sub_count=1`, name="test"),
set `DAT_005a78b4` to it, then drive the renderer's per-frame method — but this
bypasses `OBJECT->vtable[0x30]` (entities) and so will texture-bind without
geometry. For real geometry, `DAT_006313c8` must be populated, which requires
the full `FUN_004b50b0` placement reader (i.e. a real `.BIN`).

---

## 6. Evidence index (vanilla addresses)

| Addr | File | Role |
|---|---|---|
| `005222c0` | WinMain | Orchestrator; calls `004f41c0`, `00523b60`, `004913c0`, `004290f0` |
| `004f41c0` | SceneBootstrap | Resets lists, reads worldlist, loads Intro scene |
| `004b77f0` | ReadWorldlist | Parses `worldlist.bin` (magic 0x1a0003d0) → `DAT_00631388` |
| `004b7640` | GetLevel | `DAT_00631388 + idx*0x1428` lookup |
| `004b7af0` | LoadSceneNamed | Wraps `FUN_004b7c50("W\\%s.bin", name)` |
| `004b7c50` | **SceneLoader** | Reads `.BIN`, validates 0x1a0002e5, calls `0050d8f0` + `004b50b0` |
| `0050d8f0` | **EntityListInsert** | Head-insert node into `DAT_005a78b4` |
| `004b50b0` | **ObjectPlacementReader** | Fills `DAT_006313c8` (+ac/b0) from `.BIN` |
| `0050dae0` | ListReset | `DAT_005a78b4/8 = 0` |
| `0050dc00` | CacheTail | `DAT_005a78bc = tail` |
| `0050daf0` | ListFlush | Release + free entity list |
| `0050e4d0` | RenderTextures | Walk list → renderer slot 0xb4 |
| `0050e540` | BuildUselist | Aggregate `s_uselist` |
| `004913c0` | IntroIslandSelect | Scan level table, set `DAT_00631380`, kick `0045a530` |
| `0045a520` | SetActiveLevel | `DAT_0059ca4c = idx` |
| `0045a530` | KickSceneTask | `FUN_0042be00(&LAB_0045a640, &LAB_0045a7c0)` async load |
| `00523b60` | IntrosBinPlayer | Parse `intros.bin`, fade-loop renders via slots 0x98/0xa8 |
| `0051e7c0` | UpdateTime | Frame dt → `DAT_00630f28` |
| `0051f0e0` / `0051f1f0` / `0041f400` | Input | DI Acquire/GetDeviceState/map |
| `004290f0` | SetPipelineGate | `DAT_0058c15c = v` (enables ScenePipelineEntry) |
| `004290e0` | GetPipelineGate | Returns `DAT_0058c15c` |
| `00523aa0` | UpCalls[20] ScenePipelineEntry | If gate set → `FUN_00523700` |
| `004a1320` | UpCalls[7] SceneBegin | (no decompile; renderer-callback) |
| `004a1340` | UpCalls[8] SceneEnd | (no decompile; renderer-callback) |
| `0050dd10` | UpCalls[9] PreRenderCheck | (referenced; predicate) |
| `00654940` | RendererPtr | Global renderer object (set by WinMain after GDVSysCreate) |
| `005a78b4` | TexListHead | Entity/texture list head (engine-side) |
| `006313c8` | ObjListHead | Placed-object/entity list head (engine-side) |
| `00631388` | LevelTable | `count=DAT_00631384`, stride 0x1428 |

PS2 cross-ref (`version_bridge/VERSION_MAP_v2.csv`): the `004xxxxx` cluster maps
to PS2 `object_*` (object_create_child, ObjectSetAnim, object_set_location,
object_destroy, ObjectCalculateTransform) — confirming `DAT_006313c8` is the
OBJECT/entity list.
