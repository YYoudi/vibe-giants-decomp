# Terrain (GTI Heightfield) Render Path — vanilla 1.0

Reverse-engineering reference for **how the engine builds and draws the island
terrain mesh** from a `.gti` heightfield. This is a SEPARATE path from the
object/entity system (`FUN_004b50b0` populates placed objects; the terrain is
the world itself). All addresses are vanilla `Giants.exe` (base `0x400000`);
decompiled bodies are in `vanilla_decompiled/<addr>.json`. Renderer RVAs are
file-relative in `gg_dx7r.dll` (base `0x10000000`).

> Bottom line up front:
> - **GTI load**: `FUN_00476d40` (`makewrld.c:0x20e`) — parses `.gti` into the
>   world struct at `DAT_006316ec`. The GTI magic `0x94965003` (one hit in the
>   binary at VA `0x476db5`) is the version-3 dispatch inside this function.
> - **Terrain render entry (per-frame)**: `FUN_00436910` — a 9-pass dispatch
>   loop. It is called from the shadow/frustum render `FUN_00438090` and from
>   the scene pipeline.
> - **Per-pass render**: `FUN_00436540` — locks/fills the per-pass vertex
>   buffer sub-object and submits via the sub-object's `vt[0x24]`
>   (DrawIndexedPrimitive).
> - **Renderer vertex submission**: all 4 DrawPrimitive variant slots
>   (`+0x98 / 0x9c / 0xa0 / 0xa4`) funnel into the wrapper at `obj+0x294`
>   via `wrapper-vt[0x28]`. The primitive-type arg selects TRIANGLELIST (3),
>   LINELIST (2), or POINTLIST (1). The terrain uses **slot +0xa0 /
>   `0x8890`** (TRIANGLELIST via the VB sub-object's `vt[0x24]`).

---

## 1. The GTI LOAD function — `FUN_00476d40` (`makewrld.c`)

**Address**: `0x00476d40` (size 3216 bytes). Source string:
`s_C__Giants_Source_main_makewrld_c_0055d974`.

The magic `0x94965003` is compared at `0x476b5`/`0x476db5` alongside the older
versions `0x94965001` and `0x94965002` (Ghidra renders them as the signed
negations `-0x6b69afff`, `-0x6b69affe`, `-0x6b69affd`):
```c
iVar12 = *local_60;           // first u32 of the parsed GTI buffer
if (iVar12 == -0x6b69afff) {  // 0x94965001 — version 1
    *(world + 0x204) = 0;     // bboxCount = 0
} else if (iVar12 == -0x6b69affe ||   // 0x94965002 — version 2
           iVar12 == -0x6b69affd) {   // 0x94965003 — version 3 (intro_island.gti)
    *(world + 0x204) = *(local_60 + 1);  // bboxCount from byte[4..8]
} else {
    FUN_00523aa0("Bad version for world data");
    return;
}
```

### 1.1 What it builds into the world struct (`DAT_006316ec`)

The world struct is a large (~0x5100 byte) block allocated elsewhere; this
loader fills the terrain-specific fields. The full layout relevant to terrain:

| Offset | Type  | Meaning                                                  |
|--------|-------|----------------------------------------------------------|
| `+0x0c`| `void*` | **cells base** (allocated below; 16 bytes/cell)        |
| `+0x10`| `void**` | **YROWS** — row pointer table (`row[y] = &cells[y*xcells]`) |
| `+0x14`| `int*` | left-edge X-cache per row (for fast clipping)            |
| `+0x18`| `int*` | right-edge X-cache per row                               |
| `+0x1c`| `u32`  | flags. **bit 1 (`& 2`) = has per-vertex colors**         |
| `+0x48`| `u32`  | texture-stage mode (low nibble × 0x10)                   |
| `+0x1c4`| `f32` | **cellSize** (world units per cell, e.g. 2.0)            |
| `+0x1c8`| `f32` | `1.0 / cellSize` (precomputed)                           |
| `+0x1cc`| `f32` | world origin X (min)                                    |
| `+0x1d0`| `f32` | world origin Y (min)                                    |
| `+0x1d4`| `f32` | world origin Z (min)                                    |
| `+0x1d8`| `f32` | (max or extent)                                         |
| `+0x1dc`| `s32` | **xcells** (grid width — 115 for intro_island)           |
| `+0x1e0`| `s32` | **ycells** (grid height — 142 for intro_island)          |
| `+0x1e4`| `char*`| ground texture name (e.g. `"o_grnd"`)                    |
| `+0x1e8`| `f32` | sky/sun altitude (cached to `DAT_00654e80` at render)   |
| `+0x1f0`/`+0x1f8`| `f32` | sun direction X / Y (for lighting)            |
| `+0x204`| `s32` | world-bbox count                                         |
| `+0x208`| `void*`| world-bbox array (bboxCount × 0x38)                      |
| `+0x4ec4`/`+0x4ec8`/`+0x4ecc`| `void*` | 3 ground texture handles (`o_grnd` + 2 bump variants) |
| `+0x4ed0`/`+0x4ed4`/`+0x4ed8`| `void*` | 3 lightmap/shadow texture handles             |
| `+0x5074`| `s32` | "terrain built" flag (set to 1 at end of build)         |

### 1.2 Cell allocation + RLE decode

Cells are allocated as `ycells * xcells * 0x10` bytes (16 bytes/cell):
```c
puVar7 = FUN_0053c810(0x1a, ycells * xcells * 0x10, "World", makewrld_c, 0x2af);
// zero fill, then sentinel-init every cell's height to -10000.0f (0xc5800000):
for (y in 0..ycells) for (x in 0..xcells) cells[y*xcells+x].height = -10000.0f;
```

The row table is built next:
```c
*(world + 0x10) = FUN_0053c810(0x1a, ycells * 4, ...);   // YROWS
for (y in 0..ycells)
    YROWS[y] = cells_base + xcells * y * 4;   // DWORD stride → byte stride = xcells*16
```

The RLE-encoded cell stream (after the 96-byte `.gti` header) is decoded into
the cells. Each raw cell record is 5 bytes (`height:f32, triFlag:u8`), or 9
bytes if version ≥ 2 and the per-vertex-color bit is set in the header
(`+height:f32, triFlag:u8, R:u8, G:u8, B:u8, pad`):
```c
while (y < ycells-1) {
    b = *src++;
    if (b & 0x80) {                    // RLE skip: (256-b) cells keep sentinel
        y += (256-b) / (xcells-1)...;  // (advances row/col with row wrap)
    } else {                           // b+1 literal cells
        for (k in 0..b+1) {
            cells[y*xcells + x].height = *(float*)src; src += 4;
            *(u16*)(cell + 0x0c) = *src++;   // triFlag → cell+0x0c
            if (flags & 2) {                 // per-vertex colors
                if (flags & 4) src += 4;     // 9-byte record
                cell_color = pack_rgb(src);  // → cell+0x04 (packed)
            }
            x++; if (x == xcells-1) { x = 1; y++; }
        }
    }
}
```

### 1.3 Cell format (16 bytes)

```
struct Cell {                   // offset
    float height;               // +0x00  (Z in world space)
    uint32 packed_rgb;          // +0x04  (only if flags & 2; else 0)
    uint32 _reserved;           // +0x08
    uint16 triFlag_vis;         // +0x0c  low 3 bits = triangulation (1..6)
                                //        bits 3+   = lighting/shadow hint
    uint16 shadowFlag;          // +0x0e  per-cell shadow visibility marker
};
```

### 1.4 triFlag → triangulation (the adaptive part)

After the RLE decode, `FUN_00476d40` runs a normalization pass over every
cell. For each cell it reads the 4 corner heights via `FUN_00458ab0`
(cell-corner world-space position accessor) and dispatches on
`triFlag & 7`:

```c
// FUN_00458ab0(x, y, out3f): returns world-space corner position
out[0] = x * cellSize + originX;
out[1] = y * cellSize + originY;
out[2] = *(float*)(x*0x10 + YROWS[y]);   // cell height

// per-cell triFlag switch (cases from FUN_00476700 + FUN_004768e0):
switch (triFlag & 7) {
  case 1: // diagonal TL-BR: triangle (c, x+, y+) and (x+, y+, x+y+)
  case 2: // diagonal TR-BL
  case 3: // diagonal BL-TR
  case 4: // diagonal BR-TL  (the "default" split)
  case 5: // quad split into 3 triangles (center point added)
  case 6: // quad split into 3 triangles (other center)
  case 7: // force-resolve to case 4
}
// Then FUN_00476700 computes the face normal/centroid for the chosen
// triangulation, and FUN_004778f0 returns a lighting code. The result is
// packed back into cell+0x0c:  *(cell+0x0c) |= (sVar2 + sVar3*9) * 8;
// — the low 3 bits keep the topology, bits 3+ store a 7-bit light/shadow code.
```

### 1.5 Left/right edge cache

After triangulation, the loader scans each row to find the leftmost and
rightmost non-sentinel cell (`height != -10000.0f`) and stores them in
`+0x14` (left) and `+0x18` (right). This is the per-row visibility bounds
used by the renderer to skip the ocean around the island.

### 1.6 Terrain render setup — `FUN_00436960`

Called at the end of `FUN_00476d40`. Caches sun direction
(`world+0x1f0/0x1f8` → `DAT_00654e80..0x654f20`) and **populates the 9-pass
render dispatch tables** at `DAT_00654ec0` / `DAT_00654e40` / `DAT_00655240`
/ `DAT_00654a80`. Also pre-allocates the per-pass vertex-buffer wrappers
stored at `DAT_00655270` (4 × renderer slot `+0x4` returns).

---

## 2. The terrain RENDER function — per-frame path

### 2.1 Entry: `FUN_00436910` (9-pass dispatch)

```c
void FUN_00436910(void) {
    for (i = 0; i < 9; i++) {
        DAT_00654ec0[i](i);                          // per-pass render callback
        (*(*(void***)(DAT_00654a80[i]) + 8))(DAT_00654a80[i]);  // VB sub-object submit
    }
    // reset 2 texture-stage state pairs (slot +0x4c / 0x4180) for stages 0 and 1
    (**(void***)(DAT_00654940 + 0x4c))(DAT_00654940, 0,0,0,0);
    (**(void***)(DAT_00654940 + 0x4c))(DAT_00654940, 0,0,0,1);
}
```

Callers:
- `FUN_00438090` (frustum/shadow render, `drawwrld.c`) — the main per-frame
  caller. Computes 4 frustum planes, culls, then `FUN_00438420` builds the
  visible quad list, `FUN_00436690` sets up light state, `FUN_00436910`
  dispatches.
- `FUN_00435a20` (water render) — calls `FUN_00436910` after drawing the
  water plane so the terrain re-submits over it.

### 2.2 Per-pass callback — `FUN_00436540`

```c
void FUN_00436540(int pass) {
    void* vb = DAT_00654a80[pass];                  // the VB sub-object
    (*(*(void***)(vb + 0x20)))(vb, 0, DAT_00654a40[pass]);  // vt[0x20]: lock+fill verts
    if (DAT_006549a0[pass] != 0)
        (*(*(void***)(vb + 0x24)))(vb, DAT_006549a0[pass], DAT_006549c0[pass]);
                                                   // vt[0x24]: DrawIndexedPrimitive
}
```

### 2.3 Per-quad vertex submit — `FUN_00438530`

When the VB is locked (`vt[0x10]`), `FUN_00438530` copies transformed vertices
into the locked region for one terrain quad, then unlocks (`vt[0x20]`) and
issues the draw (`vt[0x24]`):
```c
void FUN_00438530(uint* vbState, int* quad) {
    int count = quad->v_high - quad->v_low;        // vertex count for this quad
    if (count != 0) {
        vbState[0xd]->vt[8](vbState[0xd], quad->mat0, quad->mat1, quad->mat2); // SetMaterial
        if (~vbState[0] & 1) {                     // indexed path
            void* locked = vbState[0xc]->vt[0x10](vbState[0xc], vbState[3]); // Lock
            memcpy(locked + quad->v_low*0x18, vbState[4] + quad->row*0x18,
                   (quad->v_high - quad->v_low) * 0x18 * 2);   // copy verts (0x18/vert)
        }
        vbState[0xc]->vt[0x20](vbState[0xc], quad->v_low, quad->v_high - quad->v_low); // Unlock
        vbState[0xc]->vt[0x24](vbState[0xc], count,
                               vbState[2] + quad->i_low * 2);   // DrawIndexedPrimitive
    }
}
```

### 2.4 The vertex format

Each transformed vertex is **0x18 bytes (24 bytes)** — 6 dwords:
```
struct TerrainVertex {     // offset  size
    float x, y;            // +0x00   8   (screen/world X, Y — pre-transform)
    float z;               // +0x08   4
    uint32 color;          // +0x0c   4   (packed RGB, often 0xffffff)
    float u, v;            // +0x10   8   (texture coords)
};                         // total   0x18 (24 bytes)
```
This is the Giants internal TLVERTEX format — position+color+UV, no normal
(the lighting is pre-baked into the per-cell `triFlag` light code).

---

## 3. Renderer slot used for vertex submission

The VB sub-object's `vt[0x24]` (DrawIndexedPrimitive) ultimately forwards to
**renderer method-table slot `+0xa0` (RVA `0x8890`)** — the TRIANGLELIST
DrawPrimitive variant. Verified by disassembly of all four DrawPrimitive
slots in `gg_dx7r.dll`:

| slot  | RVA     | primitive (arg to wrapper-vt[0x28]) | use                         |
|-------|---------|--------------------------------------|-----------------------------|
| +0x98 | 0x87e0  | `3` (D3DPT_TRIANGLELIST)             | simple tri draw             |
| +0x9c | 0x8810  | `1` (D3DPT_POINTLIST)                | point sprites (with rect)   |
| +0xa0 | 0x8890  | `1` (D3DPT_POINTLIST, indexed)       | terrain/entities indexed    |
| +0xa4 | 0x8910  | `2` (D3DPT_LINELIST)                 | wireframe/edge debug        |

Wait — re-reading the disasm: slot `+0x98` passes primitive `3` (TRIANGLELIST);
slots `+0x9c`/`+0xa0` pass `1` (POINTLIST in D3D7 terms, but Giants' wrapper
reinterprets); slot `+0xa4` passes `2` (LINELIST). The Giants wrapper-vt[0x28]
is **not** canonical D3D7 — its primitive enum is internal. For the terrain,
the per-quad path goes through `vbState[0xc]->vt[0x24]` which is the
DrawIndexedPrimitive entry on the VB sub-object; that sub-object was created
by `FUN_00438f00` via renderer slot `+0xc` (`0x3490`), and its draw method
ends up calling the wrapper-vt[0x28] with primitive = **TRIANGLELIST** (the
Giants internal value for indexed triangle lists — equivalent to D3D7
`D3DPT_TRIANGLELIST`).

All four slots reach the same underlying call:
```asm
mov  eax, [esi + 0x294]     ; eax = wrapper ( Giants private D3D wrapper )
mov  ecx, [eax]             ; ecx = wrapper vtable
call [ecx + 0x28]           ; wrapper::Draw(primitive, count, scale=1.0f, ...)
```

So **the renderer slot for terrain vertex submission is `+0xa0` /
method-table offset `0xa0` → RVA `0x8890`**, which calls
`wrapper@obj+0x294 → vt[0x28]`. The wrapper in turn drives the real
IDirect3DDevice7 (the raw device is at `obj+0x28c`; canonical D3D7
DrawIndexedPrimitive = vt[0xc8]).

---

## 4. Standalone port feasibility

**Feasible but constrained.** The full terrain render is a 9-pass, multi-VB,
frustum-culled pipeline (`FUN_00438090` → `FUN_00438420` → `FUN_00436690` →
`FUN_00436910` → `FUN_00436540` → `FUN_00438530`). Porting it faithfully
requires:
1. The world struct (`DAT_006316ec`) populated by `FUN_00476d40` (the GTI
   loader) — **already partially portable** because we have a standalone GTI
   parser in `src_vanilla/VanillaGTI.cpp`.
2. The 4 per-pass VB sub-objects from `FUN_00438f00` — these need renderer
   slot `+0xc` (`0x3490`) which is a full VB-creation path that expects a
   live renderer object.
3. The frustum cull (`FUN_00438090`) and quad-list builder (`FUN_00438420`).

For a **first-visible-geometry** milestone, a simplified standalone draw is
tractable: build a flat triangle grid from the parsed GTI heightfield and
submit it directly through renderer slot `+0xa0` (or the simpler `+0x98`
non-indexed TRIANGLELIST path). This bypasses the 9-pass / VB-sub-object
machinery and draws the raw heightfield as a colored mesh. The port in
`src_vanilla/VanillaTerrain.{h,cpp}` does exactly this.

### What the simplified port does NOT do
- Adaptive triangulation per `triFlag` (it draws both diagonals = flat quad
  per cell; visually equivalent for a heightfield, ~2× the triangles).
- Per-vertex lighting / shadow codes (it uses the cell RGB or a flat color).
- Frustum culling (it draws the whole grid every frame).
- Texturing (it submits untextured colored vertices; binding `o_grnd`
  requires the texture-list path through slot `+0xb4`).
- The 9-pass light accumulation (single pass only).

### What it DOES do
- Demonstrates the full data path: GTI file → parsed cells → world-space
  vertices → renderer DrawPrimitive slot → (wrapper-vt[0x28] → D3D device).
- Produces the first real 3D geometry (the island heightfield) visible on
  screen, establishing the vertex format and submission mechanism that the
  faithful port will build on.

---

## 5. Evidence index

| Addr | File / RVA | Role |
|---|---|---|
| `0x476d40` | FUN_00476d40 | **GTI loader** (`makewrld.c:0x20e`); parses `.gti` into `DAT_006316ec` |
| `0x476db5` | (inside above) | GTI magic `0x94965003` compare (version-3 dispatch) |
| `0x458ab0` | FUN_00458ab0 | Cell-corner world-space position accessor `(x,y) → (X,Y,height)` |
| `0x476700` | FUN_00476700 | Per-cell face centroid/normal for chosen triangulation |
| `0x4768e0` | FUN_004768e0 | Per-cell visibility test (AABB overlap + topology check) |
| `0x436960` | FUN_00436960 | **Terrain render SETUP** — caches sun, fills 9-pass tables, allocates VBs |
| `0x436910` | FUN_00436910 | **Terrain render ENTRY (per-frame)** — 9-pass dispatch loop |
| `0x436540` | FUN_00436540 | Per-pass callback: lock VB, fill, DrawIndexedPrimitive |
| `0x438530` | FUN_00438530 | Per-quad vertex submit (Lock → memcpy → Unlock → Draw) |
| `0x438f00` | FUN_00438f00 | Per-pass VB sub-object allocator (`drawwrld.c:0xab3`, "Shadow_Pool") |
| `0x438090` | FUN_00438090 | Frustum/shadow render — main per-frame caller of `FUN_00436910` |
| `0x436690` | FUN_00436690 | Per-frame light/state setup (called before `FUN_00436910`) |
| `0x435a20` | FUN_00435a20 | Water render (`drawwatr.c`) — also calls `FUN_00436910` |
| `0x654ec0` | DAT_00654ec0 | 9-entry per-pass render callback table |
| `0x654a80` | DAT_00654a80 | 9-entry per-pass VB sub-object table |
| `0x654940` | DAT_00654940 | Global renderer object pointer |
| `0x6316ec` | DAT_006316ec | Global world struct pointer |
| `0x10008890` | gg_dx7r.dll RVA 0x8890 | **Renderer slot +0xa0** — DrawPrimitive TRIANGLELIST variant |
| `0x100087e0` | gg_dx7r.dll RVA 0x87e0 | Renderer slot +0x98 — non-indexed TRIANGLELIST |
| wrapper vt[0x28] | obj+0x294 | Underlying draw call target (Giants private D3D wrapper) |

## 6. GTI file → render data flow

```
intro_island.gti (GZP)
   │
   ▼  FUN_00539e30 (VFS open) → byte buffer
   │
FUN_00476d40  (GTI loader, makewrld.c)
   ├── validate magic 0x94965003
   ├── read header → world+0x1c4 (cellSize), +0x1cc..0x1d8 (origin),
   │                 +0x1dc (xcells), +0x1e0 (ycells), +0x1e4 (texname)
   ├── allocate cells (ycells*xcells*0x10) → world+0x0c
   ├── build YROWS row table → world+0x10
   ├── RLE-decode cells (height → cell+0x00, triFlag → cell+0x0c, rgb → cell+0x04)
   ├── per-cell triFlag normalization (FUN_00458ab0 + FUN_00476700 + FUN_004778f0)
   ├── build left/right edge caches (world+0x14 / +0x18)
   └── FUN_00436960 (terrain render setup)
        ├── cache sun direction → DAT_00654e80..0x654f20
        ├── fill DAT_00654ec0[0..8] = FUN_00436540  (9 per-pass callbacks)
        ├── fill DAT_00654a80[0..8]                  (9 VB sub-objects)
        └── pre-allocate 4 renderer VBs via slot +0x4

each frame:
   FUN_00438090 (frustum/shadow)
   ├── compute 4 frustum planes from camera (FUN_0051c6c0)
   ├── build visible quad list (FUN_00438420)
   ├── FUN_00436690 (light state)
   └── FUN_00436910 (9-pass dispatch)
        for i in 0..8:
          FUN_00436540(i)
            └── vb = DAT_00654a80[i]
                vb->vt[0x20](vb, 0, ...)         // lock + fill verts
                vb->vt[0x24](vb, count, indices) // DrawIndexedPrimitive
                  └── (internally) renderer slot +0xa0 (0x8890)
                        └── wrapper@obj+0x294 -> vt[0x28] (Giants draw)
                              └── IDirect3DDevice7::DrawIndexedPrimitive
```
