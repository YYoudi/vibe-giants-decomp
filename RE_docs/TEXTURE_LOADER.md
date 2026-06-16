# TEXTURE_LOADER.md — FUN_0050dd20 (vanilla texture DATA loader) + the +0x08 link-node path

Capstone-disasm-confirmed reference for the vanilla Giants.exe texture-loading
layer and the renderer surface-creation path that writes `TextureEntry+0x08`.

- Target binary: `G:\GiantsRE\GameFiles-VanillaV1\Giants.exe` (base 0x400000)
- Renderer DLL: `G:\GiantsRE\GameFiles-VanillaV1\gg_dx7r.dll` (base 0x10000000)
- Port: `src_vanilla/VanillaTextureLoad.{h,cpp}`

---

## 1. FUN_0050dd20 — signature & semantics

```
__cdecl void FUN_0050dd20(TextureEntry* entry);   // entry = [esp+0x1e0]
```

- `[0x50dd27] mov ebx, [esp+0x1e0]` — `ebx` is the sole argument (a `TextureEntry*`).
- `[0x50dd30] mov eax, [ebx+4]; test eax,eax; jne epilogue` — **idempotent**: if
  `entry+0x04` (surface_data / pixel buffer) is already non-NULL, return immediately.
- `[0x50dd3c..0x50dd6d]` — walk `g_TextureEntityList` (DAT_005a78b4) node-by-node,
  then the secondary list at DAT_005a78b8, to locate which node + entry index owns
  `ebx`. Entries live at `node+0x2c`, stride 0x24, count `node+0x28`.
  If not found → log via FUN_0053a3a0/FUN_0053a3c0, zero `entry+0x04`, return.

### 2. The renderer call: slot +0xc0

```
[0x50ddeb] mov eax, [0x654940]          ; eax = g_vRenderer
[0x50ddf0..0x50ddf5]
    push 0
    push 0
    push ebx            ; entry
    push eax            ; renderer (this)
    call dword ptr [eax + 0xc0]
[0x50ddfc] add esp, 0x10
```

- **Slot +0xc0 = gg_dx7r.dll RVA 0xae80** (confirmed by GDVSysCreate vtable fill at
  `[0x10002fa8] mov [esi+0xc0], 0x1000ae80`).
- Calling convention: `__cdecl`, this-first: `int slot_c0(renderer*, entry*, 0, 0)`.
- **Semantics (disasm of 0xae80):** a mip-bias / dimension adjuster. It reads the
  renderer's display dimensions (`[esi+0x2a0]`, `[esi+0x2a8]`), clamps the entry's
  stored w/h at `entry+0x0c`/`entry+0x10`, adjusts the mip-bias byte at `entry+0x1d`,
  and returns nonzero if the entry's effective dimensions changed.
- **It does NOT create a D3D surface and does NOT write entry+0x08.** This revises
  the prior assumption that slot +0xc0 was the surface creator.

### 3. TGA / DDS parse path (pixel source)

If slot +0xc0 returns nonzero AND `~(entry_flagsHi & 4)` (the entry is NOT already
renderer-bound — flag byte at `entry+0x23`, bit 2):

- `[0x50dfe9..]` build the filename from `entry+0x00` (string-pool name ptr), call
  `FUN_0053a3e0(out_buf, filename)` = VFS open+read (engine file API). The .tga
  bytes come from the level GZP (e.g. `Bin/w_intro_island.gzp` contains
  `intro_sea.tga`, `intro_grnd.tga`, `intro_rock.tga`, ...).
- `[0x50de9b] cmp eax, 0x20534444` — DDS magic check ("DDS "). If DDS, parse the
  DDS header at `[0x50dea6..0x50dfaf]` (copies the 0x7C-byte DX7 DDS header +
  surface bytes into an engine buffer at `node_ext+0x30`).
- TGA header parse `[0x50e083..0x50e2ec]`: image type 1/2/3, color-map present,
  bpp 8/24/32. Computes format code + mip count from power-of-two dimensions.
- `[0x50e27b..0x50e2c1]` allocate pixel buffer via `FUN_0053c810` (engine allocator,
  tag 0x1d), `memcpy` the decoded pixels, then **`[0x50e2c1] mov [ebx+4], eax`** —
  store the pixel buffer pointer at **entry+0x04**.
- Writes the format/mip fields: `entry+0x14` (format), `entry+0x18` (mip levels),
  `entry+0x1e` flags (bit 0 = pixel data present, bit 2 = has-alpha/32bpp).
- `[0x50e0eb]` / `[0x50e13d]` tail-jmp `FUN_00523b40` → `[0x523b40] mov [0x5dcb14], 1`
  sets the global "textures changed" flag DAT_005dcb14. The game loop checks this
  flag (engine VA 0x522580/0x522900) and re-queries display config + rebuilds the
  pipeline when set.

### 4. What writes TextureEntry+0x08 (the link-node) — THE decisive finding

`TextureEntry+0x08` is initialized to 0 by the engine (`FUN_0050d8f0` at
`src_vanilla/VanillaSceneLists.cpp` line 210: `*(entry+0x08) = 0`). It is written
**only by the renderer**, via **slot +0xb0** — NOT by FUN_0050dd20 and NOT by slot +0xc0.

**Renderer slot +0xb0 = gg_dx7r.dll RVA 0xc030** (confirmed by GDVSysCreate vtable
fill `[0x10002f80] mov [esi+0xb0], 0x1000c030`). Disasm of 0xc030:

```
[0x1000c069] call [ebx+0xb4]            ; first the walk-if-linked (slot b4)
[0x1000c110] mov ecx, [ebx+0x4e8]       ; renderer texture-list head (obj+0x4e8)
[0x1000c116] lea eax, [ebx+0x4e8]       ; list sentinel
... allocate 0xC-byte node {next(+0), prev(+4), self/sentinel(+8)} ...
[0x1000c153] mov [ebp+8], esi           ; write node+0x08 = entry/surface ref
... insert node into the obj+0x4e8 doubly-linked list ...
[0x1000c175] call [ebx+0xc0]            ; then adjust mip-bias (slot c0)
```

The 0xC-byte node allocated here is the "link-node" stored at `entry+0x08` (the
renderer assigns it back to the entry after insertion). Slot +0xb4 (RVA 0xc6a0)
then consumes it:

```
[0x1000c6a0] mov eax, [esp+8]           ; eax = entry
[0x1000c6a8] mov eax, [eax+8]           ; eax = entry->link_node (+0x08)
[0x1000c6ab] test eax, eax
[0x1000c6ad] je ret                      ; *** +0x08 NULL → EARLY RETURN (the bug) ***
[0x1000c6af] mov [esp+8], eax
[0x1000c6b3] jmp 0xc630                 ; walker: unlink+relink, call [edi+0x14]
```

### 5. The engine driver of slot +0xb0

Slot +0xb0 is called from exactly one engine site:

```
VA 0x4f3c20  (inside a per-frame texture-bind walk)
[0x4f3c38] mov ecx, [0x5a7668]; inc ecx; mov [0x5a7668], ecx   ; frame counter
[0x4f3c49] mov ebx, [edx]               ; edx = entity; ebx = entity
[0x4f3c4b] mov eax, [ebx+0x68]          ; entity->texture_count
[0x4f3c5b] lea esi, [ebx+0x90]          ; entity->textures[0] (stride 0x50)
loop:
[0x4f3c61] mov eax, [esi]               ; entry = textures[i]
[0x4f3c6b] mov cx, [eax+0x1e]           ; entry flags
[0x4f3c6f] not ecx; test ch, ch; jns skip ; flag bit 15 clear → skip
[0x4f3c79] push eax
[0x4f3c7a] mov eax, [0x654940]          ; renderer
[0x4f3c80] call [eax+0xb0]              ; *** slot +0xb0(renderer, entry) ***
[0x4f3c86] add esp, 8
```

This iterates an **entity's** texture array (`entity+0x90`, count `entity+0x68`,
stride 0x50 — NOT the global `g_TextureEntityList`). So +0x08 gets populated when
the per-entity render-bind walk runs — which requires entities with populated
texture arrays to exist in the scene.

### 6. Implication for unblocking slot +0xb4

Calling `FUN_0050dd20` on every `g_TextureEntityList` entry (what
`VanillaLoadAllTextures` does) populates `entry+0x04` (pixel data) + format fields
— necessary precondition — but **does not by itself set entry+0x08**. To unblock
slot +0xb4's early-return, the recomp must additionally drive the per-entity
texture-bind walk at VA 0x4f3c20 (call slot +0xb0 for each entity texture), which
requires:

1. Entities with `texture_count (+0x68) > 0` and a populated `textures[] (+0x90)`
   array whose entries point into `g_TextureEntityList`.
2. Those entries' flags byte `+0x1e` bit 15 set (the bind-eligibility bit the walk
   tests at `[0x4f3c6f]`).

The next layer to port is therefore the per-entity texture-bind walk (FUN around
VA 0x4f3c20) + the entity texture-array population path — not FUN_0050dd20 alone.

---

## 7. Port status

`src_vanilla/VanillaTextureLoad.cpp` ports FUN_0050dd20 faithfully:
- Idempotency check on entry+0x04.
- List-walk to find the owning node.
- Renderer slot +0xc0 call (mip-bias adjust).
- TGA parse via `VanillaTGA::Parse` (vanilla inlines an equivalent) + DDS magic
  handling.
- Writes entry+0x04 (pixel buffer), +0x14 (format), +0x18 (mips), +0x1e (flags).
- Sets `g_TexturesChangedFlag_5dcb14` (= DAT_005dcb14) on success.
- `VanillaLoadAllTextures()` iterates `g_TextureEntityList` and loads every entry.
- Wired into `WinMain_vanilla.cpp` immediately after `VanillaFeedTextures()`.
- Compiles clean (`g++ -m32 -fsyntax-only -Isrc_vanilla`, exit 0).

### Key offsets (TextureEntry, stride 0x24)

| offset | field | source |
|--------|-------|--------|
| +0x00  | name (string-pool ptr) | FUN_0050d8f0 |
| +0x04  | surface_data / pixel buffer | FUN_0050dd20 (TGA/DDS parse) |
| +0x08  | renderer link-node | **renderer slot +0xb0** (NOT FUN_0050dd20) |
| +0x0c  | stored width | renderer slot +0xc0 adjusts |
| +0x10  | stored height | renderer slot +0xc0 adjusts |
| +0x14  | format code | FUN_0050dd20 |
| +0x18  | mip levels | FUN_0050dd20 |
| +0x1d  | mip-bias byte | renderer slot +0xc0 |
| +0x1e  | flags lo (bit0=data, bit2=alpha/32bpp) | FUN_0050dd20 |
| +0x23  | flags hi (bit2 = renderer-bound) | FUN_0050d8f0 / renderer |
