# ODEF VM — Object-Definition Bytecode Interpreter

**Target**: `Giants.exe` vanilla 1.0 retail (`G:\GiantsRE\GameFiles-VanillaV1\Giants.exe`, base `0x400000`).
**Scope**: the bytecode interpreter that creates placed-object entities from the `.BIN` level file's `odef_blob` section.

This documents the ODEF VM dispatcher (jump table @ `0x4baa28`) and the SPAWN path that populates `g_PlacedObjectList` (`DAT_006313c8`). The faithful port lives in `src_vanilla/VanillaOdef.cpp`.

---

## 1. Where the VM lives

The ODEF interpreter is **not a standalone function** — it is inlined at the tail of the `.BIN` loader `FUN_004b7c50` (ported in `VanillaBinLoader.cpp`). After the loader parses the 7-section header and reads the odef blob into an in-memory template, execution falls directly into the dispatch loop.

### 1.1 Entry sequence (addresses inside `FUN_004b7c50`)

| Address | Action |
|---------|--------|
| `0x4b7e8e` | `push 0x1c9; push "odef"; push eax; push 0x18; call 0x53c810` — allocate the 0x1c9-byte template (tag `"odef"` @ `0x562d10`). |
| `0x4b7eae` | `mov [esp+0x50], ebp` — `ebp` = template buffer (becomes the stream cursor). |
| `0x4b7eb2` | `call 0x51d750` — `READ(blobSize)` bytes from the file into the template. |
| `0x4b7eb7`–`0x4b7edb` | Skip **two NUL-terminated header strings** (template-name + class-name). For `w_intro_island.bin`: `"box01\0"` + `"intro_island.gti\0"`. |
| `0x4b7ee4`–`0x4b7f95` | Seed default floats on the engine object @ `[0x6316ec]` (camera/scene defaults — `[+0x7c]=0x447a0000`, `[+0x80]=0x3d000000`, `[+0x84]=0x3f000000`, `[+0x505c]=0x80`, `[+0x5048..0x5058]=0`, `[+0x5064]=0x457a0000`, etc.). |
| `0x4b7f95`–`0x4b805d` | More engine default init (cosine tables `[+0x4e9c]`/`[+0x4ea0]`, fog colors `[+0x4e90]`/`[+0x4e94]`/`[+0x4e98]`, etc.). |
| `0x4b805d` | `call 0x4b7b30` — pre-dispatch hook (setup). |
| `0x4b8062`–`0x4b8096` | Stack-frame init; `xor ebx, ebx` @ `0x4b808c` (ebx = current entity, initially NULL). |
| **`0x4b809d`** | **DISPATCH LOOP ENTRY** (see §2). |

### 1.2 Register / state conventions inside the loop

| Register | Role |
|----------|------|
| `ebp` | **Stream cursor** — points into the in-memory odef template. Each handler advances it by its fixed size. |
| `ebx` | **Current entity pointer** — NULL between spawns; set by the spawn handler's tail (`0x4b8908..0x4b8938`). Many property-setter opcodes write through `[ebx+offset]`. |
| `[0x6316ec]` | Global engine pointer (`g_Engine`). Most engine-state opcodes read/write `[engine+offset]`. |
| `[0x6313c8]` | `g_PlacedObjectList` head — entities are head-inserted here. |
| `[0x6313b4]` | `g_EntityInstanceList` head — searched by `FUN_0049d2d0(nameId)` for existing entities. |
| `[0x631404]` | Entity pool free-list head — `FUN_0049c190` pops from here. |
| `[esp+0x1c]` | The current opcode byte (saved by the dispatcher). |
| `[esp+0x18]` | Inner-list slot index for the spawn tail. |
| `[esp+0x20]` | Inner-list entity count. |

---

## 2. The dispatch loop (`0x4b809d`)

```asm
0x4b809d: xor eax, eax
0x4b809f: mov al, byte ptr [ebp]          ; read opcode byte
0x4b80a2: inc ebp                         ; advance cursor
0x4b80a3: cmp eax, 0xff                   ; terminator?
0x4b80a8: mov [esp+0x1c], eax             ; save opcode
0x4b80ac: je   0x4ba5d4                   ; → END
0x4b80b2: lea ecx, [eax - 0x13]           ; table index = opcode - 0x13
0x4b80b5: cmp ecx, 0x71                   ; range check (0x13..0x84)
0x4b80b8: ja   0x4ba592                   ; → BAD opcode (error/abort)
0x4b80be: jmp dword ptr [ecx*4 + 0x4baa28] ; dispatch via jump table
```

- Valid opcodes: **`0x13`..`0x84`** (0x72 entries in the jump table).
- `0xff` = stream terminator → jumps to the function epilogue at `0x4ba5d4`.
- Anything else → error formatter at `0x4ba592` (logs `"0x655"` and aborts).
- Every handler ends with `xor edi, edi; jmp 0x4b809d` (loop back).

---

## 3. Opcode map (the jump table `0x4baa28`)

The jump table is `0x72` dwords. **Table index = opcode_byte − 0x13.** Sizes are the byte count consumed AFTER the opcode byte (derived from each handler's `add ebp, N` / `inc ebp` sequence via capstone). `-1` = variable-length (NUL-string + tail).

### 3.1 SPAWN opcodes (entity creation — the port's focus)

| Op | Handler | Size | Name | Action |
|----|---------|------|------|--------|
| **`0x2a`** | `0x4b883f` | **20** | **SPAWN_POS_ANGLE** | `nameId(4)` + `x,y,z(12)` + `angle(4)`. Calls `FUN_0049d2d0(nameId)`; on miss `FUN_0049c190(0x406)` allocates. Tail `0x4b8908` writes `[ebx+0xa0..0xa8]` (pos), `[ebx+0xc8]` (angle). |
| **`0x46`** | `0x4b883f` | **28** | **SPAWN_POS_3ANGLES** | Same as `0x2a` plus 2 more angles. Tail reads `[ebx+0xcc]`, `[ebx+0xd0]` when `[esp+0x1c]==0x46` (checked @ `0x4b8983`). |

### 3.2 NAME opcode (feeds the spawn name slot)

| Op | Handler | Size | Name | Action |
|----|---------|------|------|--------|
| `0x84` | `0x4ba50a` | var (NUL-str) | NAME_set | Reads a NUL-terminated string, copies it into `[engine+0x509c]` (the pending-name slot the spawn path consumes). The BinLoader's "placement name" heuristic recovers these. |

### 3.3 Property setters on current entity (`ebx`)

| Op | Handler | Size | Field written |
|----|---------|------|---------------|
| `0x13` | `0x4b8a17` | 1 | `[ebx+0x10]` (1 byte) + sets `[ebx+0x30]=1` |
| `0x2b` | `0x4b8a36` | 4 | `[ebx+0x14]` (dword) |
| `0x2f` | `0x4b8a05` | 28 | skip 0x1c (the on-disk `ObjectRef6` row) |
| `0x3b` | `0x4b8a4e` | 1 | **`[ebx+0xe8]` (1 byte) = KIND/typeId** |
| `0x52` | `0x4b8a69` | 4 | **`[ebx+0x174]` (dword) = VARIANT** |
| `0x5a` | `0x4b8a84` | 12 | `[ebx+0xf4], [ebx+0xf8], [ebx+0xfc]` (3 floats — alt pos) |
| `0x62` | `0x4b8ae7` | 8 | `[[ebx+0x100]+0x10], [+0x14]` (2 floats — fx_light) |
| `0x3f` | `0x4b8f2b` | 8 | `[[ebx+0x170]+0xc], [+0x10]` (path segment — gated on `[ebx+0x1e0]==0x24`) |

### 3.4 Engine-state setters (write to `[0x6316ec]` = `g_Engine`)

| Op | Handler | Size | Engine offset(s) |
|----|---------|------|------------------|
| `0x1d`–`0x26`, `0x2c` | various | 16–32 | material/texture blocks (`[+0x50]`, `[+0x5c]`, `[+0x64]`, `[+0x6c]`, `[+0x74]`, `[+0x7c]`) |
| `0x27` | `0x4b837f` | 17 | indexed attach slot `[+0x88..0x94]` (byte-indexed) |
| `0x28` | `0x4b8451` | 3 | `[+0x4f38], [+0x4f3c], [+0x4f40]` (3 bytes → floats, scaled by `[0x5524b4]`) |
| `0x29` | `0x4b8533` | 11 | `[+0x128], [+0x12c], [+0x130..0x138]` (scaled) |
| `0x2e` | `0x4b8333` | 12 | `[+0x7c]`, `[+0x80]` (div by `[0x5522c0]`), `[+0x84]` |
| `0x30` | `0x4b83e7` | 18 | indexed `[+0x17c..0x188]` |
| `0x34`/`0x35`/`0x36` | `0x4b9112`/`0x4b9195`/`0x4b9218` | 44 | light props `[+0x1e4]`/`[+0x1ec]`/`[+0x1f4]` (0x20 name + dword + div) |
| `0x37`/`0x38` | `0x4b8fef`/`0x4b900e` | 36 | error-log paths (fog overflows?) |
| `0x39` | `0x4b902d` | 28 | ambient light `[+0x1ac..0x1b8]` |
| `0x3a` | `0x4b8c2e` | 36 | block |
| `0x60` | `0x4b84f2` | 4 | **fx selector `[+0x4e8c]`** (0=fx, 1=dust, 2=snow) — sets `[+0x4a64]=0x1b` when nonzero |
| `0x72`/`0x73`/`0x74` | `0x4b929b`/`0x4b931e`/`0x4b93a1` | 44 | fog props `[+0x4ee0]`/`[+0x4ee8]`/`[+0x4ef0]` |
| `0x75` | `0x4b9424` | 4 | `[+0x4ef4]` |
| `0x77`/`0x78`/`0x79` | `0x4ba0b0`/`0x4ba193`/`0x4ba276` | 48 | 12-dword blocks |
| `0x81` | `0x4b87c9` | 4 | `[+0x4a7c]` |
| `0x6b` | `0x4b9dd7` | 4 | `[+0x4a80]` slot-array push |

### 3.5 Variable-length opcodes (NUL-string + tail)

| Op | Handler | String dest | Tail |
|----|---------|-------------|------|
| `0x76` | `0x4ba02a` | `[+0x4efc]` (0x4f38 followed by) | 16 bytes (4 dwords → `[+0x4f38..0x4f54]`) |
| `0x5d` | `0x4b8ba2` | `[+0x2214]` slot find | `0x20`-byte block |
| `0x5e` | `0x4b87e9` | `[+0x4a80]` slot find | `0x20`-byte block |
| `0x82` | `0x4b878d` | `[+0x507c]` (0x20-byte head-copy) | 0 |
| `0x6f` | `0x4b87b7` | (shared path) | `0x40`-byte skip |

### 3.6 No-op / default opcodes (size 0, fall to error if reached mid-stream)

`0x3d`, `0x43`, `0x44`, `0x45`, `0x4a`, `0x4d`, `0x55`–`0x57`, `0x63`/`0x64`, `0x69`, `0x7a`–`0x80`, `0x83` — all map to the no-op `0x4ba57f` or the default error `0x4ba58e`. Reaching the error path mid-stream aborts the load.

---

## 4. The SPAWN path in detail

### 4.1 `FUN_0049c190(size_arg)` — entity pool allocator

**Disasm @ `0x49c190`:**

```asm
0x49c190: mov eax, [0x59e3dc]      ; alloc counter
0x49c195: mov ecx, [0x59e3e0]      ; high-water mark
0x49c19b: inc eax; mov [0x59e3dc], eax
0x49c1a1: cmp ecx, eax; jge skip
0x49c1ab: mov [0x59e3e0], eax      ; update HW mark
0x49c1b0: mov esi, [0x631404]      ; esi = entity pool free-list head
0x49c1b7: test esi, esi; jne pop
0x49c1bc: push 0x55f7f0; call 0x523aa0  ; fatal: "no free entities"
0x49c1cb: mov eax, [esi]; mov [0x631404], eax  ; pop free-list
0x49c1d9: mov edi, esi; xor eax, eax
0x49c1db: push esi
0x49c1dc: mov ecx, 0xc1; rep stosd  ; ZERO 0x304 bytes (entity slot)
0x49c1de: push 0x6313c8            ; &g_PlacedObjectList
0x49c1e3: call 0x472ef0            ; head-insert scene-list node
0x49c1e8: mov eax, [esi+0xdc]
0x49c1f1: or  eax, 0x80000000
0x49c1f6: mov [esi+0xc4], 0x3f800000  ; scale = 1.0f
0x49c200: mov [esi+0xdc], eax      ; active flag
0x49c206: lea eax, [esi+0x10]; mov ecx, 4
0x49c20e: mov dword ptr [eax], 0xfe; add eax, 0x24; dec ecx; jne  ; sentinel slots
0x49c21a: call 0x49c150            ; post-alloc hook (event dispatch)
```

**What it does**:
1. Bumps allocation counters @ `[0x59e3dc]` / `[0x59e3e0]`.
2. Pops a slot from the entity free-list @ `[0x631404]` (fatal if empty).
3. Zeroes the **0x304-byte** entity slot (`0xc1` dwords).
4. Calls `FUN_00472ef0(entity, &g_PlacedObjectList)` — builds a 0xc84-byte scene-list node and head-inserts it into `g_PlacedObjectList` (the entity is embedded inside at the inner-stride offset).
5. Sets `[entity+0xc4] = 1.0f` (scale), `[entity+0xdc] |= 0x80000000` (active flag).
6. Writes the sentinel `0xfe` at offsets `+0x10`, `+0x34`, `+0x58`, `+0x7c` (4 linked-list slot markers).

The `size_arg` parameter (pushed as `0x406` by the spawn handler @ `0x4b88e0`) is informational — the zero-size is always `0xc1` dwords.

### 4.2 Spawn handler tail (`0x4b8908`)

After `FUN_0049c190` returns the entity in `esi`, the tail at `0x4b8908`:

```asm
0x4b8908: mov edi, [esp+0x18]      ; slot index
0x4b890c: cmp edi, 0x400; jl ...
0x4b8921: dec edi                  ; bounds (max 1024 per inner block)
0x4b8926: mov eax, [esp+0x20]      ; inner-block base
0x4b892a: lea edx, [edi+edi*2]     ; edx = slotIdx*3
0x4b892d: shl edx, 6              ; edx = slotIdx*192
0x4b8930: add edx, edi            ; edx = slotIdx*193
0x4b8932: mov ecx, 0xc1
0x4b8938: lea ebx, [eax+edx*4]    ; ebx = base + slotIdx*772  → stride 0x304
0x4b8940: rep stosd               ; zero the entity
0x4b8946: call 0x49ccf0           ; entity vtable/ctor (template install)
0x4b894d: call 0x49cfd0           ; entity name-bind (FUN_0049d2d0-style)
0x4b8952: mov ecx, [ebp]; add ebp, 4
0x4b8958: mov [ebx+0xa0], ecx     ; POSITION.x
0x4b8961: mov edx, [ebp]; add ebp, 4
0x4b8967: mov [ebx+0xa4], edx     ; POSITION.y
0x4b896d: mov eax, [ebp]; add ebp, 4
0x4b8973: mov [ebx+0xa8], eax     ; POSITION.z
0x4b897d: mov ecx, [ebp]; add ebp, 4
0x4b8983: cmp eax, 0x46           ; opcode 0x46?
0x4b8986: mov [ebx+0xc8], ecx     ; ANGLE0
0x4b898c: jne 0x4b89a6            ; skip extra angles for 0x2a
0x4b898e: mov edx, [ebp]; add ebp, 4
0x4b8994: mov [ebx+0xcc], edx     ; ANGLE1 (0x46 only)
0x4b899a: mov eax, [ebp]; add ebp, 4
0x4b89a0: mov [ebx+0xd0], eax     ; ANGLE2 (0x46 only)
0x4b89a6: ...                     ; copies template state +c0/+d8/+dc/+e4 + links
```

**Fields written by SPAWN:**

| Offset | Type | Opcode 0x2a | Opcode 0x46 |
|--------|------|-------------|-------------|
| `+0xa0` | float | x | x |
| `+0xa4` | float | y | y |
| `+0xa8` | float | z | z |
| `+0xc8` | float | angle0 | angle0 |
| `+0xcc` | float | — | angle1 |
| `+0xd0` | float | — | angle2 |

(The `+0xe4`/`+0xe8`/`+0x174` fields are set by the separate `0x3b`/`0x52` opcodes, not by spawn itself.)

---

## 5. `w_intro_island.bin` worked example

**File**: `G:\GiantsRE\GameFiles-VanillaV1\Bin\w_intro_island.bin` (1514 bytes).

**Header** (7 section offsets @ file+4): `[0x20, 0x46d, 0x5c2, 0x5d6, 0x4d5, 0x4d9, 0x4fe]`.
**odef blob**: @ `header[0]` = file off `0x20`; size u32 @ `0x20` = **1097 bytes**.

**Blob structure**:
- Bytes `0..22`: two header strings `"box01\0"` (6B) + `"intro_island.gti\0"` (17B).
- Bytes `23..1096`: bytecode.
- Byte `1096`: `0xff` terminator.

**Bytecode walk** (selected):
- `@23` `0x84` NAME `"stream\\intro_island"`
- `@45` `0x39` ambient_light (28B)
- `@74` `0x34` light_prop `[+0x1e4]` (44B) — `"intro_grnd"` baked in the 0x20 name field
- `@119` `0x35` light_prop `[+0x1ec]` (44B) — `"intro_rock"`
- `@164` `0x36` light_prop `[+0x1f4]` (44B) — `"intro_rock"`
- `@209`–`@726`: property setters (0x2e, 0x1e, 0x25, 0x26, 0x27×10, 0x30×3, 0x28, 0x4f×2, 0x76, 0x6c, ...)
- `@1015` **`0x2a` SPAWN**: `nameId=0x03ec` `pos=(125.06, 789.05, 193.87)` `angle=48.33` — **entity #1** ("mission1")
- `@1051` **`0x46` SPAWN**: `nameId=0x03ec` `pos=(134.22, 780.11, 195.48)` `angles=(-123.0, -4.66, 0.0)` — **entity #2** ("mission1")
- `@1080`–`@1095`: trailing property opcodes (`0x3b` KIND=15, `0x5f`, etc.)
- `@1096` `0xff` END

**Spawn count for `w_intro_island.bin`: 2 entities.**

(The `intro_grnd`/`intro_rock`/`intro_sky`/`intro_sea`/`intro_underside` names appear as light/material property targets via opcodes `0x34`/`0x35`/`0x36`, NOT as entity spawns. Only `mission1` is placed via the spawn opcodes — twice, with different positions/angles.)

---

## 6. Port status (`VanillaOdef.cpp`)

| Feature | Status |
|---------|--------|
| Dispatch loop (opcode read, range check, jump) | ✅ Faithful |
| Two-string header skip | ✅ Faithful |
| Opcode `0x84` NAME | ✅ Reads NUL-string, logs (engine slot write stubbed) |
| **Opcodes `0x2a` / `0x46` SPAWN** | ✅ **Faithful**: allocates via `FUN_0049c190`, writes `+0xa0..0xa8` (pos), `+0xc8` (ang0), `+0xcc`/`+0xd0` (ang1/2 for 0x46) |
| `FUN_0049c190` allocator | ✅ Faithful zero (0x304B) + `[+0xc4]=1.0` + `[+0xdc]|=0x80000000` + sentinel `0xfe` writes + head-insert into `g_PlacedObjectList` |
| Opcodes `0x3b` KIND / `0x52` VARIANT / `0x5a` POS | ✅ Applied to current entity |
| Other property/engine-state opcodes | ⚠️ Advanced by correct size, engine-state writes **skipped** (logged). Materials/lights/fog subsystems not yet ported. |
| Variable-length opcodes (`0x76`/`0x5d`/`0x5e`/`0x82`/`0x6f`) | ✅ NUL-string scan + documented tail |
| `0xff` terminator | ✅ |
| Bad-opcode abort | ✅ |

**Compile**: `g++ -m32 -fsyntax-only -Isrc_vanilla src_vanilla/VanillaOdef.cpp` → **clean**.

**SelfTest**: `VanillaOdef::SelfTest()` opens `w_intro_island.bin`, parses the header, runs `VanillaOdef_Run` on the 1097-byte blob. Expected output: 2 SPAWN log lines + `[ODEF] run complete: 2 entities spawned`.
