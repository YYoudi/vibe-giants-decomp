# PATCH LAYER CLASSIFICATION: what in `/src/` is patch-only / DX9+ ?

**Question answered:** the canonical reverse target is now **vanilla 1.0 retail**
(`GameFiles-VanillaV1/Giants.exe`). But `/src/` was RE'd from the **1.5 patch**
binary (`GiantsMain.exe`). How do we handle the `/src/` content that exists *only*
because of the DX9+ patch?

**One-line answer:** `/src/` is ~99% engine-core that transfers to vanilla. The
patch-only renderer machinery is a **10-file / ~38 KB layer**. We don't rewrite
`/src/` — we **quarantine that thin layer to `reference/patch15/`** and re-cite
everything else to vanilla via `VERSION_MAP_v2.csv`.

---

## The three buckets

| Bucket | Files | Size | Origin | Verdict |
|--------|-------|------|--------|---------|
| **A — vanilla-core engine** | ~694 | ~3.6 MB | exists in vanilla, RE'd from 1.5 | KEEP; re-address to vanilla, verify body |
| **A\* — render pipeline (engine-side)** | ~62 | ~123 KB | exists in vanilla shape, RE'd from 1.5 | KEEP; verify each command vs DX7 contract |
| **B — COM wall + DX9 machine** | 10 | ~38 KB | 1.5-only (no vanilla counterpart) | **QUARANTINE → `reference/patch15/`** |
| **C — diagnostic / oracle tooling** | 2 entities | ~129 KB | never shipped | KEEP as-is (instrumentation) |

### Bucket B — PATCH-ONLY (the quarantine list)

These have **no vanilla counterpart**. They exist only because the 1.5 patch
introduced COM + a DX9/DX11/DX12 renderer family. Ground truth (not opinion):

- **`src/engine/EngineContext.cpp` (+ .h)** — the engine-context registry
  (5 vtable methods + 6 placeholder services under captured IIDs). Built
  *specifically* to make `gg_dx9r.dll` create its device. Vanilla DX7 renderer
  takes **NULL engine-context + 21 callbacks, NO registry**
  (see memory `dx7-minimal-contract`, Frida-captured on the original).
- **`src/engine/ComRegistry.cpp`, `ComSubsystem.cpp`, `ComObjectRelease.cpp` (+ .h)** —
  the COM registry "wall" (memory `com-subsystem-breakthrough`: 1043-fn subtree,
  176 COM classes) that the 1.5 renderer traverses. Vanilla DX7 has **no COM**.
- **`src/engine/ShaderConstants.cpp` + `src/renderer/ShaderConstants.cpp` (+ .h)** —
  programmable shaders (DX9+). DX7 is **fixed-function**, no shader constants.

> These are **abandoned as canonical**. They become pure documentation of the
> patch delta — useful later when we *re-implement* the patch as a separate
> deliverable, but NOT compiled into the vanilla-canonical recomp.

### The seam — `src/renderer/RendererLoader.cpp` (LoadGDVSystem)

The function **exists in vanilla** (it loads the renderer DLL — every Giants
build has a renderer loader). The 27 KB body is the **1.5 version with the
registry/COM path**. Vanilla version loads `gg_dx7r.dll` with **no COM registry**.

→ **Action:** re-RE LoadGDVSystem from vanilla Ghidra; cite vanilla address as
canonical (see VERSION_MAP_v2 for the 1.5→vanilla seed); strip the registry path.
This single file is the boundary between Bucket A\* and Bucket B.

### Bucket C — diagnostic / oracle (keep, not canonical)

- **`recomp_stub_renderer.cpp` (21 KB)** + **`src/renderer_stub/StubRenderer.cpp`** —
  diagnostic DX9 stub (per skills `giants-proxy`/`giants-advance`: DIAGNOSTIC-ONLY,
  never presented as RE). Stays as a visibility instrument.
- **`proxy/` (108 KB, 11 files)** — the `gg_dx9r.dll` oracle (dual-mode bit-compare
  vs original). 1.5-specific by construction, but it's an **analysis instrument**,
  not shipped code. Keep as a tool.

### Bucket A / A\* — the bulk (vanilla-core)

- **A (engine-core, ~694 files):** VFS, FLICK, player, camera, input, timer, audio
  loader, WndProc, math, CRT stubs, game logic, network. All map 1:1 to vanilla
  via `VERSION_MAP_v2`. **Handle:** for each EXACT/HIGH/MEDIUM row, cite
  `vanilla_addr` as canonical provenance; carry the 1.5 reverse (semantics,
  types, PS2 name) onto it; verify MEDIUM bodies vs vanilla.
- **A\* (render pipeline, ~62 files):** `RenderFrame`, `RenderStageExecute`,
  `RenderCommandBatch`, `RenderLightDispatch`, `SceneRenderDispatch`, text/menu
  render helpers, etc. These are the **engine→renderer contract side** (the engine
  *issues* render commands; the renderer DLL *executes* them). Vanilla also issues
  render commands (to a DX7 renderer). **Handle:** keep, but verify each render
  command against the **vanilla DX7 contract** (the 21 callbacks from
  `dx7-minimal-contract`); strip any 1.5/DX9-only command extensions.
- **`src/renderer/WaterSystem.cpp`** — water *simulation* is vanilla-core (the game
  has water), but verify and strip any DX9 shader path (DX7 = fixed-function
  multitexture water).

---

## The renderer pivot (the real payoff)

With Bucket B quarantined, the recomp's renderer entry becomes the **vanilla DX7
contract**:

```
vanilla recomp  ──(DX7 contract: NULL engine-context + 21 callbacks)──►  gg_dx7r.dll
                                                                        (to be reversed)
                                                                         │
                                                                         ▼
                                              future fresh DX12 renderer implements THIS contract
                                              (NOT the DX9 contract in EngineContext.cpp)
```

- The DX9 contract (`EngineContext.cpp` + COM wall) is **abandoned as canonical**.
- The renderer reverse (main agent's current task) targets `gg_dx7r.dll` /
  vanilla `LoadGDVSystem` → the 21-callback DX7 contract.
- A future fresh **DX12 renderer** implements the **DX7 contract**, skipping
  DX8/9/11 entirely (per the vanilla-canonical decision).

Net: quarantining Bucket B makes the recomp **cleaner**, not harder — vanilla
ground truth is dramatically simpler than the 1.5 DX9+ stack.

---

## Execution plan (for the main agent, owns `/src/`)

1. **Don't touch Bucket A bulk.** It transfers. Use `VERSION_MAP_v2.csv`
   (EXACT/HIGH/MEDIUM rows) to re-cite each function's `vanilla_addr` as the
   canonical comment; carry 1.5 semantics + `ps2_name`.
2. **Move Bucket B (10 files) to `reference/patch15/`** and drop them from the
   vanilla recomp build (`CMakeLists.txt`). Keep the COM/DX9 work as documentation.
3. **Re-RE `RendererLoader.cpp` from vanilla** — strip the registry path; this is
   the seam where Bucket B detaches.
4. **Verify Bucket A\*** render commands against the DX7 contract (21 callbacks)
   once the DX7 renderer reverse lands; trim DX9-only commands.
5. **Keep Bucket C** (`recomp_stub_renderer.cpp`, `renderer_stub/`, `proxy/`) as
   instrumentation — unchanged.

## Provenance

- File areas + sizes: live inventory of `G:\GiantsRE\src` (this session).
- 1.5↔vanilla mapping: `version_bridge/VERSION_MAP_v2.csv` (1247 pairs).
- DX7 contract (NULL engine-context, 21 callbacks): memory `dx7-minimal-contract`.
- COM wall scope: memory `com-subsystem-breakthrough`.
- Engine-context origin (built for gg_dx9r.dll): memory `engine-context-captured`.
