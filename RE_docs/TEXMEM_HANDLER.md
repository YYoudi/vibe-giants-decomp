# TEXMEM Handler — FUN_0049a580 (vanilla 0x49a580)

**Function:** `void FUN_0049a580(uint32_t stream)` — reader for the `texmem`
section of a scene `.BIN` file (e.g. `w_intro_island.bin`).
**Caller:** `FUN_004b7c50` (the `.BIN` loader) at `[0x4b7d12..0x4b7d18]`,
invoked right after `SEEK(stream, header[2])` and BEFORE the `name_list`
read at `[0x4b7d24..0x4b7d32]`.
**Port:** `src_vanilla/VanillaTexmem.{h,cpp}`.

---

## 1. The `.BIN` section order (capstone + esp-tracking, verified)

`FUN_004b7c50` reads the 7-dword header at `[esp+0x8c]` then, in order:

| addr        | access (post-cdecl-push correction) | action                                |
|-------------|-------------------------------------|---------------------------------------|
| `0x4b7d09`  | `mov eax, [esp+0xa0]` = **header[2]** | `SEEK(stream, header[2])`           |
| `0x4b7d18`  | `call FUN_0049a580(stream)`         | **THIS** — read texmem                |
| `0x4b7d1d`  | `mov ecx, [esp+0xa8]` = **header[1]** | `SEEK(stream, header[1])`           |
| `0x4b7d32`  | `call FUN_0050d8f0(name, stream)`   | populate `g_TextureEntityList`        |
| `0x4b7d40`  | `SEEK(header[4])`                   | fx selector                           |

> The disasm's `[esp+0xa0]` resolves to **header[2]** (not header[0]) because
> the three cdecl pushes for the header `read` at `0x4b7d04` are NOT cleaned
> before `0x4b7d09`. Symbolic esp-tracking from `0x4b7c50` confirms every
> access: `[esp+0xa0]→header[2]`, `[esp+0xa8]→header[1]`, `[esp+0xc8]→header[4]`.
> (The existing `VanillaFeed.h` note was right; a naive first read of the
> disasm is misleading.)

For `w_intro_island.bin` the header is:
```
header[0]=32(0x20)   header[1]=1133(0x46d)  header[2]=1474(0x5c2)
header[3]=1494       header[4]=1237         header[5]=1241   header[6]=1278
```

---

## 2. The texmem section format (header-only for `w_intro_island.bin`)

The `texmem` section at file offset `0x5c2` is **20 bytes**:

```
05c2: ff ff ff ff  02 11 22 33  00 00 00 00  28 00 00 00  14 00 00 00
      │            │            │            │            │
      sentinel     magic        field_b      rec_size     total_size
      (-1)         0x33221102   0            40 (0x28)    20 (0x14)
```

`FUN_0049a580` reads this as a **versioned header**:

1. Read first u32. If `== -1` → NEW format (read 4 more u32s); else OLD format
   (first u32 was the record count, fixed `rec_size=0x1c`).
2. NEW format reads: `magic` (`0x33221102` here — note: NOT `0x33221100`; the
   low byte is a sub-version that dispatches the per-entry body at
   `[0x49a753] cmp eax,0x33221100` vs `[0x49a800] cmp eax,0x33221102`),
   `field_b`, `rec_size`, `total_size`.
3. `total_size = 20`, consumed by the 5-u32 header itself → **0 bytes remain**
   → **entry_count = 0** → the per-entry loop `[0x49a6bf..0x49a8ed]` runs
   **zero iterations**.

Trace confirmation (`vanilla_trace.log`):
```
[TEXMEM] NEW format: magic=0x33221102 field_b=0 rec_size=40 total=20
[TEXMEM] total=20 header=20 remaining=0 rec_size=40 → entry_count=0
[TEXMEM] done: processed 0 records
```

For files with a non-empty texmem section the loop body ([0x49a6bf..0x49a8ed])
reads `index|field1|field2|field3|field4` (5 u32s) per record and writes them
into a 0x2c-stride pool at **DAT_0063141c** (capacity 0x7d0=2000 slots):

| pool offset | source (record) | write site     |
|-------------|-----------------|----------------|
| `+0x00`     | fresh alloc     | `[0x49a8bf]` (sub-object) |
| `+0x0c`     | rec+0x04        | `[0x49a71e]`   |
| `+0x1c`     | rec+0x08        | `[0x49a72e]`   |
| `+0x14`     | rec+0x0c        | `[0x49a73e]`   |
| `+0x18`     | rec+0x10        | `[0x49a74b]`   |
| `+0x24/+0x28` | version-dispatched | `[0x49a765]` / `[0x49a7e9]` |

The allocator debug-tag strings pushed at the top (`'C:\Giants\Source\main\noise.c'`
+ `'sounds'`) are **shared allocator macros** across subsystems, not a semantic
identifier — this IS the texmem/entity pool, not a sound pool.

---

## 3. DOES `FUN_0049a580` set `TextureEntry +0x08`? **NO.**

This was the task hypothesis. It is **disproven** by three independent lines
of evidence:

### 3a. Control flow never reaches a TextureEntry write
`FUN_0049a580`'s only writes are to the `DAT_0063141c` pool (0x2c-stride
slots) and to freshly-allocated sub-objects. It never references
`g_TextureEntityList` (`DAT_005a78b4`) — confirmed by a full xref scan of
`.text`: none of the 24 xrefs to `0x5a78b4` are inside `FUN_0049a580`
(`0x49a580..0x49a907`).

### 3b. A whole-`.text` scan finds NO write to `[reg+8]` near any texture-list ref
Capstone-decoded all of `Giants.exe` `.text`; filtered for
`mov dword ptr [reg+8], …` within 0x120 bytes of any `0x5a78b4` reference.
**Zero matches.** Nothing in the host executable writes the texture entry's
`+0x08` field — at all.

### 3c. The `+0x08` link-node is a RENDERER-side object
The renderer (`gg_dx7r.dll`) slot `+0xb4` @ RVA `0xc6a0` is a **trampoline**:
```asm
0xc6a1: mov eax, [esp+8]        ; eax = TextureEntry*
0xc6a7: je 0xc6b9               ; if NULL, ret
0xc6a9: mov eax, [eax+8]        ; eax = entry->link_node
0xc6ae: je 0xc6b9               ; if link_node==NULL, ret   ← THE EARLY-RETURN
0xc6b0: mov [esp+8], eax        ; replace arg with link_node
0xc6b4: jmp 0xc631              ; tail-call the real doubly-linked-list insert
```
The insert target `0xc631` treats `link_node` as a renderer-internal list node
with `{prev@0, next@4, owner@8}` and splices it into the renderer's per-frame
list at `renderer+0x4e8`. This node is **allocated and written into
`entry+0x08` by the renderer DLL itself** (via a different vtable slot that
creates a D3D texture surface) — NOT by any Giants.exe function in the
texture-list path.

The only Giants.exe function that mutates a TextureEntry in the load path is
`FUN_0050dd20` @ `0x50dd20` (the per-frame texture-DATA loader). It:
- calls renderer slot `+0xc0` (`[0x50ddf6]`) to load the .tga/.dds pixels,
- writes the loaded-surface handle into **entry+0x04** (`[0x50df86] mov [ebp+0x30],eax`,
  where `ebp = entry_base - 0x2c`, so `ebp+0x30 = entry+0x04`),
- sets state bits in `entry+0x1e`/`+0x20`/`+0x21`.

It does **not** touch `entry+0x08`.

---

## 4. Runtime verification (post-port)

After porting `FUN_0049a580` + wiring it into `VanillaFeed.cpp` (SEEK
header[2] → call → SEEK header[1] → FUN_0050d8f0 → SceneWalk), the recomp runs
8 frames cleanly with this trace:

```
[FEED] SEEK texmem @1474; calling FUN_0049a580
[TEXMEM] pool init: 2000 slots x 0x2c = 88000 bytes @ 0f5a6ee0
[TEXMEM] NEW format: magic=0x33221102 ... entry_count=0
[TEXMEM] done: processed 0 records
[FEED] SEEK name_list @1133; calling FUN_0050d8f0
[TEXLIST] insert 'w_intro_island.bin' subs=7 ... (intro_sea, intro_underside, ...)
[SCENE/WalkTextures] dispatched 7 entries via slot 0xb4
  (all 7 "slot 0xb4 returned OK" — but each early-returns because entry+0x08==0)
[VANILLA] frame 0..7: RunFrame(0) -> 2
```

- **No crash.** Pool init + header parse + 0-record loop + texture-list build +
  renderer dispatch all succeed.
- **slot 0xb4 still early-returns** for every entry (entry+0x08==0) — exactly
  as predicted. The renderer trampoline dereferences `entry+0x08`, finds NULL,
  and returns without inserting.
- **No visible change** (window still black) — confirmed: scene-entities are
  not built because the renderer-side link-nodes were never created.

---

## 5. What the next layer actually is

To make `slot +0xb4` insert (and eventually produce visible pixels), the
renderer must populate `entry+0x08` with a renderer-side list-node. This
requires the **renderer texture-surface creation path**:

1. The engine must supply texture DATA (the `.tga`/`.dds` pixels) — via the
   per-frame `FUN_0050dd20` loader which calls renderer slot `+0xc0`, OR via
   the `UpCallsLoad` callbacks the engine registers with the renderer.
2. The renderer, on receiving a texture-create request (some vtable slot that
   takes `(renderer, TextureEntry*, data, ...)`), must:
   - allocate a renderer-internal list-node (`{prev,next,owner}`),
   - create the D3D7 surface from the pixel data,
   - store the node pointer into `entry+0x08`.
3. Only then does the per-frame `SceneWalk_Textures → slot+0xb4` trampoline
   find a non-NULL `entry+0x08` and splice the node into `renderer+0x4e8`.

The vanilla DX7 renderer contract (see `RE_docs/DX7_RENDERER_CONTRACT.md`)
defines 21 `UpCallsLoad` callbacks; the one that maps a texture name to a
surface is the missing piece. **`FUN_0049a580` is not that piece** — it only
pre-populates a metadata pool that is empty for this level.

---

## 6. Files touched

- `src_vanilla/VanillaTexmem.h` (new) — `FUN_0049a580` declaration.
- `src_vanilla/VanillaTexmem.cpp` (new) — faithful port (lazy pool init,
  versioned header read, per-entry loop stubbed for the version-dispatched
  texture-DATA load since it never runs for this file).
- `src_vanilla/VanillaFeed.cpp` — added `SEEK header[2]` + `FUN_0049a580`
  call BEFORE the `name_list` read, matching the loader order at
  `0x4b7d09..0x4b7d32`.
- `src_vanilla/VanillaFeed.h` — corrected header comment (header[2] = texmem,
  not header[0]).
- `RE_docs/TEXMEM_HANDLER.md` (this file).
