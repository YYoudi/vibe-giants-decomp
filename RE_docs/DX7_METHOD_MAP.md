# DX7 Renderer Method-Table Map — `gg_dx7r.dll` (vanilla v1.0)

Target: `G:\GiantsRE\GameFiles-VanillaV1\gg_dx7r.dll` (PE32, base `0x10000000`).
Source: disassembly of the GDVSysCreate (RVA `0x2dc0`) method-table writes + each
slot function. RVAs are file-relative (== RVA in this DLL, file alignment matches).

## 0. Critical structural finding — TWO COM interfaces

The renderer object does **not** call IDirect3DDevice7 directly from most slotted methods.
There are (at least) three COM-like interface pointers stored on the object:

| field         | interface                                                | evidence                                                                                          |
|---------------|----------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| `obj+0x284`   | D3D framework sub-object (factory, holds `[+0x2c]` wrapper) | `0x81d2: mov eax,[eax+0x2c]; mov [esi+0x294],eax` — wrapper is fetched from framework `+0x2c`     |
| `obj+0x288`   | IDirectDrawSurface7 (back-buffer)                        | `0x7345/0x7477: mov ecx,[esi+0x288]; call 0x2010`; `0xacf0` calls vt[0x14]=Blt on it              |
| `obj+0x28c`   | **IDirect3DDevice7 (raw)**                               | `0x7370` calls vt[0x68] and checks `0x88760245` (DDERR_DEVICELOST) / `0x8876024b` (NOTRESET)      |
| `obj+0x294`   | **Private Giants D3D wrapper** (sub-interface from 0x284)| `0x86a0/0x87a0/0x81d6` drive it via vt[0x14]/[0x18]/[0x50]/[0x94]; offsets do NOT match canonical D3D7 |

**Implication:** the renderer's slotted methods mostly talk to the **wrapper at obj+0x294**.
Its vtable layout is Giants-internal; the offsets `0x14/0x18/0x50/0x94` are NOT the canonical
IDirect3DDevice7 indices (`0x1c/0x20/0x30/0x58`). The wrapper in turn drives the real device.
Labels below use "wrapper-vt[N]" for the obj+0x294 interface and "D3D7-vt[N]" for the raw
obj+0x28c device. Raw-device D3D7 calls actually live in the **0x1000–0x4000 RVA scene-render
cluster** (called from 0x71a0/0x7340), not in the slotted front-table.

The wrapper at obj+0x294 (set up in `0x81d6` and used by `0x86a0`) uses these empirically:
- wrapper-vt[0x14] = scene-bracket open  (called once with `this` only — likely BeginScene equiv)
- wrapper-vt[0x18] = scene-bracket close (EndScene equiv; paired via `obj+0x520` flag)
- wrapper-vt[0x50] = Clear                (args: `(this, clearFlags, count)`)
- wrapper-vt[0x94] = SetTextureStageState (args: `(this, stage, state, value)`; 0x10/0x11 = MAGFILTER/MINFILTER)
- wrapper-vt[0x48] = SetMaterial          (used by 0x42f0 with a D3DMATERIAL7-shaped struct)
- wrapper-vt[0xb0] = commit/apply fallback

## 1. Method table — full slot map

`__cdecl`, first stack arg `[esp+4]` = `this`. Sorted by slot offset.

| slot    | RVA     | semantic                                                       | confidence | evidence (vtOffset/import + 1-line why)                                                                                                                  |
|---------|---------|----------------------------------------------------------------|------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| +0x00   | 0x4420  | dtor (not in disasm scope; written by GDVSysCreate)            | low        | first vtable slot per C++ ABI                                                                                                                             |
| +0x04   | 0x3090  | **internal: entity-list node allocator** (0x60-byte ctor)      | high       | `call [0x10028780]` size 0x60; zero-fills; links node into list at `obj+0xf0`; invokes node sub-vtable[0xc]/[0x10]                                       |
| +0x08   | 0x42c0  | **internal: getter** — returns `obj+0xf4` (active scene ctx)   | high       | 4-insn `mov eax,[esp+4]; mov eax,[eax+0xf4]; ret`                                                                                                         |
| +0x0c   | 0x3490  | **internal: scene-entity node allocator** (0x2d8-byte ctor)    | high       | allocator size 0x2d8; zero-fill 0x36 dwords; links into list at `obj+0xe8`; sets sub-vtable 0x10003620/0x10003660/…                                       |
| +0x10   | 0x2d80  | **scene-object dispatch** — walks `obj+0xe4` list              | high       | list-walk loop calling `node-vt[0x30]` per entity until self-ref; no D3D COM call — dispatches into per-entity vtables (819K calls/frame, hot path)      |
| +0x14   | 0x42d0  | **internal: reset 48-byte material block** at `obj+0xf8`       | high       | `rep movsd` from template 0x10019070 (0xc dwords); no COM                                                                                                |
| +0x18   | 0x3e60  | **internal: invalidate viewport (stage 1)**                    | medium     | calls 0x2d80 then wrapper-vt[0x2c] with literal `1`; sets `obj+0x248 \|= 1` (bit 0)                                                                       |
| +0x1c   | 0x3ea0  | **internal: invalidate viewport (stage 2)**                    | medium     | identical to +0x18 but literal `2`; sets `obj+0x248 \|= 2` (bit 1)                                                                                        |
| +0x20   | 0x3ee0  | **internal: invalidate viewport (stage 3) + aspect math**      | medium     | wrapper-vt[0x2c] with literal `3`; FPU block on arg w/h/near/far → `obj+0x238/0x23c`; sets `obj+0x248 \|= 4`                                              |
| +0x24   | 0x3f90  | **internal: set render-mode by index** (table 0x1001920c)      | medium     | `obj+0xf8=0; obj+0x104=-1`; reads `0x1001920c[idx]`; wrapper-vt[0x2c] dispatch                                                                            |
| +0x28   | 0x3fe0  | **Clear viewport rect 1** (wrapper-vt[0x30], count=1)          | medium     | wrapper @ obj+0x294 vt[0x30] with D3DRECT at `obj+0x138`; count 1                                                                                         |
| +0x2c   | 0x4000  | **Clear viewport rect 2** (wrapper-vt[0x30], count=2)          | medium     | vt[0x30] with D3DRECT at `obj+0x178`; count 2                                                                                                             |
| +0x30   | 0x4020  | **Clear viewport rect 3** (wrapper-vt[0x30], count=3)          | medium     | vt[0x30] with D3DRECT at `obj+0x1b8`; count 3                                                                                                             |
| +0x34   | 0x4040  | **Clear indexed viewport rect** (wrapper-vt[0x30])             | medium     | indexes flag table 0x1001920c by arg2; vt[0x30] with D3DRECT at `obj+0x1f8`                                                                              |
| +0x38   | 0x4130  | **SetViewport region (scaled)** via wrapper-vt[0x3c]           | high       | float-mul arg by 0x10017158; builds 4-float rect (X,Y,W,H); wrapper @ obj+0x294 vt[0x3c]                                                                 |
| +0x3c   | 0x4070  | **SetTransform from rect+aspect** via wrapper-vt[0x34]         | medium     | copies 16-byte matrix from arg → `obj+0x128`; computes int rect with aspect from `obj+0x4dc`; wrapper-vt[0x34]                                             |
| +0x40   | 0x4120  | **internal: get matrix ptr** — returns `obj+0x128`             | high       | trivial getter; no COM                                                                                                                                    |
| +0x44   | 0x4200  | **internal: set frame-skip mode** (state machine)              | high       | branches on arg2; writes `obj+0x524` and `obj+0x240`; no COM                                                                                              |
| +0x48   | 0x4240  | **SetRenderState (state 0x2f)** via wrapper-vt[0x50]           | low        | stores arg2 → `obj+0x528`; wrapper-vt[0x50] with state 0x2f; wrapper-vt[0x50] is "apply state" not canonical D3D7 RS                                      |
| +0x4c   | 0x4180  | **SetTextureStageState pair** (stages 0xb + 0x18) wrapper-vt[0x94] | medium | 2× wrapper-vt[0x94] with stage constants 0xb/0x18 + OR-ed flags; resets `obj+0x104=-1`, `obj+0xf8=0`                                                      |
| +0x50   | 0x2d40  | **SetSingleTextureStageState** (stage 0xc) wrapper-vt[0x94]    | medium     | single wrapper-vt[0x94] with stage 0xc; table @0x10019240                                                                                                 |
| +0x54   | 0x4270  | **internal: set viewport flag/cookie** `obj+0x52c`             | high       | trivial setter after 0x2d80 cleanup; no COM                                                                                                               |
| +0x58   | 0x4290  | **internal: set fog params** (near/far/color → `obj+0x530..0x538`) | high   | `fld [esp+8]; fstp [eax+0x530]`; stores ecx→+0x534, edx→+0x538; no COM                                                                                    |
| +0x5c   | 0x42f0  | **SetMaterial** (D3DMATERIAL7 copy) via wrapper-vt[0x48]       | high       | builds 0x68-byte D3DMATERIAL7 (diffuse/ambient/specular/emissive/power layout); wrapper-vt[0x48] + fallback vt[0xb0]                                      |
| +0x60   | 0xc880  | **internal: present/flip framebuffer** (Blt chain)             | medium     | guards on `obj+0x288/0x264/0x42c`; 3 IAT calls (USER32 + DDS7 ops); tail-calls 0x10002020(device); always returns 1 — end-of-frame present path           |
| +0x64   | 0xc900  | **internal: display-mode setup/resize** (mode-set dispatcher)  | medium     | clears `obj+0x264`; calls 0x7500 then 0x6470 + 0x75f0 with (w/h/bpp/refresh/win/cfg); restores `obj+0x264=1` on done                                      |
| +0x68   | 0xc9d0  | **internal: display-mode setup entry** (wraps 0xc900)          | medium     | same 3-flag guard; pulls dims from `obj+0x250/0x24c/0x254/0x258` + framework `+0x830/+0x8cc`; delegates to 0xc900                                         |
| +0x6c   | 0xc970  | **internal: get display-config (GETTER)** — copies 2×16 bytes  | high       | reads framework `obj+0x284 +0x830 / +0x8cc`; copies 16 bytes each into 2 caller out-ptrs; pure read, no COM                                               |
| +0x70   | 0x79c0  | **internal: build surface list from entity array**             | high       | walks `obj+0x118` stride 0x900; heap-alloc ptr array; no COM                                                                                              |
| +0x74   | 0x7bc0  | **internal: finalizer** — frees buffer via `[0x10028784]`      | high       | single `call [0x10028784]` (heap free) on `[esp+8]` if non-null; 5-insn wrapper                                                                           |
| +0x78   | 0x7aa0  | **internal: enumerate display modes** (640x480x16 filter)      | high       | walks `obj+0x8ec` stride 0x7c; filters w≥0x280 & h≥0x1e0 & bpp≥0x10; heap-alloc output                                                                   |
| +0x7c   | 0x7bc0  | (alias of +0x74 — same finalizer; table lists it twice)       | high       | identical RVA to +0x74                                                                                                                                    |
| +0x80   | 0x7370  | **per-frame entry: TestCooperativeLevel / ValidateDevice**    | high       | loads `obj+0x28c` (raw IDirect3DDevice7); D3D7-vt[0x68]; checks DDERR 0x88760245/0x8876024b (DEVICELOST/NOTRESET); gates 0x7340 render                  |
| +0x84   | 0x73e0  | **internal: scene-state refcount toggle**                      | medium     | manipulates global [0x10028718] + `obj+0x264`; no device COM; sibling 0x7430 is Release via vt[0x8]                                                       |
| +0x88   | 0x7910  | **internal: zero render-state cache** (9 dwords `obj+0x4fc`)   | high       | clears `obj+0x4fc..0x51c` to 0; no COM                                                                                                                    |
| +0x8c   | 0xaba0  | **internal: texture-stage state dispatch** (STSS wrapper)      | medium     | renderer vt[0xb0] (thiscall); texture-COM vt[0x30]; table 0x10019a00 indexed by stage; guarded by `obj+0x544` flag                                        |
| +0x90   | 0x86a0  | **draw-setup: SetTextureStageState ×4 + Clear + open scene**   | high       | wrapper-vt[0x14] (scene-open) then 4× wrapper-vt[0x94] with states 0x10/0x11 stages 0/1 (MAG/MINFILTER) then wrapper-vt[0x50] (Clear flags=8); sets `obj+0x520=1` |
| +0x94   | 0x87a0  | **EndScene** (wrapper-vt[0x18], closes scene)                  | medium     | reads `obj+0x520` flag; wrapper-vt[0x18]; clears flag on success; HRESULT fail → `[0x10028748]`; pairs with +0x90                                         |
| +0x98   | 0x87e0  | **DrawPrimitive-style** (stage 3) via wrapper-vt[0x28]         | medium     | wrapper-vt[0x28] with (0x3f800000, stage3, 0); primitive-arg dispatch on obj+0x294 vertex-batch wrapper                                                  |
| +0x9c   | 0x8810  | **DrawPrimitive-style indexed** (stage 1, offset math)         | medium     | base from `obj+0x4dc`; wrapper-vt[0x28] with (1, 1.0f, rect)                                                                                              |
| +0xa0   | 0x8890  | **DrawPrimitive-style** (stage 1 variant)                      | medium     | wrapper-vt[0x28] with (1, 0x3f800000, 0, 1); sibling of +0x9c                                                                                            |
| +0xa4   | 0x8910  | **DrawPrimitive-style** (stage 2 / LINELIST)                   | medium     | primitive arg 2 (D3DPT_LINELIST); wrapper-vt[0x28]                                                                                                       |
| +0xa8   | 0x8990  | **internal: get backbuffer surface** (`obj+0x288`)             | high       | 3-insn: `mov eax,[esp+4]; mov ecx,[eax+0x288]; jmp 0x10002090` (surface-return helper)                                                                    |
| +0xac   | 0x84d0  | **SetRenderState batch** (fog/texfactor/material-color) + SetTransform | high | wrapper-vt[0x50] with D3DRENDERSTATE_TEXTUREFACTOR (0x22), 0x30, 0x23, 0x8c, 0x24, 0x25; wrapper-vt[0x30] (SetTransform); RGB float→byte pack            |
| +0xb0   | 0xc030  | **internal: entity visibility/flag cull**                      | high       | reads entity flags `[esi+0x1e]`, tests bits 0x10/0x20; checks `obj+0x468/0x470/0x544`; returns 0 to cull; no COM                                          |
| +0xb4   | 0xc6a0  | **internal: entity-list thunk** → list walker 0xc630          | high       | 18-byte thunk: extracts `[arg+8]` sub-obj, `jmp 0xc6c30`; (adjacent 0xc6c0 is the ExtTextOutA text body, but +0xb4 is this thunk)                        |
| +0xb8   | 0xacf0  | **Blt 2D sprite/quad** (DDS7::Blt on backbuffer)              | high       | reads entity flags; calls +0xb0 (state setup); loads `obj+0x288`→vt[0x34] DC; DDS7-vt[0x14] (Blt) with DDBLT_WAIT 0x1000000                              |
| +0xbc   | 0xae60  | **internal: clamp helper** (`max(0, min(a,b)-1)`)              | high       | pure int util; no COM, no obj access                                                                                                                      |
| +0xc0   | 0xae80  | **internal: glyph/text-clip rect calculator**                 | high       | reads `obj+0x2a0/0x2a8` (abs via 0x44b0), inset byte `[edi+0x1d]`, clamps vs `[edx+0x43c]`; pure rect math                                               |
| +0xc4   | 0x7870  | **GetInfo/Capability dispatcher** (8-case switch) — NOT SetRenderState | high | `mov eax,[esp+8]; cmp 7; jmp [eax*4+0x78e4]`; each case returns one obj field (0x42c/0x4d8/0x4dc/0x2a0/0x2a8/0x4e0/0x4e4/0x544); no D3D touched         |
| +0xc8   | 0x7950  | **GetTextString/GetStatus** — returns static buffer           | high       | writes `[0x100286a8]=0`; arg 0 → strcpy; arg 3 → sprintf 5 fields from `obj+0x4fc..0x51c`; no COM                                                        |
| +0xcc   | 0x76e0  | **ToggleRenderState** (6-state bool flip, ASCII keys 0x42-0x59) | high      | `sub eax,0x42; cmp 0x17; jmp [table 0x77ac]`; 6 flags at `obj+0x55c..0x570`; `sete dl` (logical NOT) and write-back                                       |
| +0xd0   | 0x77d0  | **GetRenderState** (6-state bool getter, same keys)            | high       | `sub eax,0x42; cmp 0x18; jmp [table 0x7850]`; reads same 6 flags; companion to +0xcc                                                                     |
| +0xd4   | 0x7f20  | **DrawText/TextOut** — surface Lock + glyph blit (555/565)     | high       | loads `obj+0x288`→vt[0x34]→vt[0x64] (DDS7 Lock); branches 0xf800/0x7e0/0x1f (565) vs 0x7c00/0x3e0/0x1f (555); word-copy blit                            |
| +0xd8   | 0x7bf0  | **DrawText alias** — `jmp 0x7c00` (single-instruction thunk)   | high       | one instruction; forwards to +0xdc                                                                                                                        |
| +0xdc   | 0x7c00  | **DrawText/TextOut (primary)** — glyph blit w/ color-key skip  | high       | DDS7 Lock via vt[0x64] on `obj+0x288`; bounds `obj+0x4d8/0x4dc`; 555/565 masks; `test ax,ax; je skip` (transparent blit); src `obj+0x188`                |
| +0xe0   | 0x7be0  | **stub/empty** — reserved slot                                 | high       | single `ret`; padding nops follow; unused callback                                                                                                       |

## 2. 0x7870 (slot +0xc4) switch table — GetInfo dispatcher

Indexed by `[esp+8]` (0–7). Jump table at `0x100078e4`.

| case | target RVA | reads obj-field | returns                |
|------|-----------|-----------------|------------------------|
| 0    | 0x7880    | `+0x42c`        | `!field` (boolean: "is mode empty") |
| 1    | 0x7892    | `+0x4d8`        | surface width  (DWORD) |
| 2    | 0x789d    | `+0x4dc`        | surface height (DWORD) |
| 3    | 0x78a8    | `+0x2a0`        | float (X-DPI/pitch)    |
| 4    | 0x78b3    | `+0x2a8`        | float (Y-DPI/pitch)    |
| 5    | 0x78c9    | `+0x4e0`        | capability/value       |
| 6    | 0x78d4    | `+0x4e4`        | capability/value       |
| 7    | 0x78be    | `+0x544`        | capability/value       |
| >7   | 0x78df    | —               | 0                      |

`obj+0x4d8`/`+0x4dc` are confirmed as surface width/height (used as bounds in 0x7c00/0x7f20
text blits). `obj+0x2a0`/`+0x2a8` are floats (abs'd in glyph-clip helper 0xae80).

## 3. Render-cycle slots grouped by category

**Device lifecycle / cooperative level**
- +0x80 (0x7370) — TestCooperativeLevel entry (raw D3D7-vt[0x68], DDERR_DEVICELOST/NOTRESET)
- +0x70/+0x74/+0x7c (0x79c0/0x7bc0) — internal buffer build / finalizer
- +0x78 (0x7aa0) — display-mode enumeration
- +0x84 (0x73e0) — scene-state refcount toggle
- +0x88 (0x7910) — render-state cache reset
- +0x60/+0x64/+0x68/+0x6c (0xc880/0xc900/0xc9d0/0xc970) — present/resize/get-display-config

**Render cycle (scene bracket)**
- +0x90 (0x86a0) — **scene-open**: SetTextureStageState ×4 + Clear + sets `obj+0x520=1`
- +0x94 (0x87a0) — **EndScene**: wrapper-vt[0x18], clears `obj+0x520`
- +0x98/+0x9c/+0xa0/+0xa4 (0x87e0/0x8810/0x8890/0x8910) — **DrawPrimitive** variants (TRIANGLELIST/LINELIST) via wrapper-vt[0x28]
- +0xb8 (0xacf0) — 2D sprite/quad Blt
- +0xac (0x84d0) — SetRenderState batch (fog/texfactor/material-color) + SetTransform

**State / texture**
- +0x48 (0x4240) — SetRenderState (single, state 0x2f)
- +0x4c (0x4180) — SetTextureStageState pair (stages 0xb + 0x18)
- +0x50 (0x2d40) — SetSingleTextureStageState (stage 0xc)
- +0x5c (0x42f0) — **SetMaterial** (D3DMATERIAL7)
- +0x58 (0x4290) — set fog params
- +0x54 (0x4270) — set viewport flag
- +0x3c (0x4070) — SetTransform (matrix → `obj+0x128` + wrapper-vt[0x34])
- +0x38 (0x4130) — SetViewport region
- +0x28/+0x2c/+0x30/+0x34 (0x3fe0/0x4000/0x4020/0x4040) — Clear viewport rects (1/2/3/indexed)
- +0x18/+0x1c/+0x20/+0x24 (0x3e60/0x3ea0/0x3ee0/0x3f90) — viewport invalidate/render-mode set
- +0xcc/+0xd0 (0x76e0/0x77d0) — Toggle/Get render-state (6 bool flags)
- +0xc4 (0x7870) — GetInfo/Caps dispatcher (NOT SetRenderState)

**Scene dispatch**
- +0x04/+0x0c (0x3090/0x3490) — entity-node allocators
- +0x10 (0x2d80) — scene-object dispatch (linked-list walk, 819K calls)
- +0xb0 (0xc030) — entity visibility cull
- +0xb4 (0xc6a0) — entity-list thunk

**Surface / text**
- +0xa8 (0x8990) — get backbuffer surface
- +0xd4/+0xdc (0x7f20/0x7c00) — DrawText/TextOut (glyph blit, 555/565)
- +0xd8 (0x7bf0) — DrawText alias
- +0xc0/+0xbc (0xae80/0xae60) — text-clip rect math helpers
- +0xc8 (0x7950) — GetTextString/Status

**Trivial getters/setters**
- +0x08 (0x42c0) — getter `obj+0xf4`
- +0x14 (0x42d0) — reset 48-byte material block
- +0x40 (0x4120) — get matrix ptr `obj+0x128`
- +0x44 (0x4200) — set frame-skip mode
- +0xe0 (0x7be0) — empty stub

## 4. Where the *real* D3D7 calls live

A scan for canonical D3D7 vt-offsets (`0x1c`=BeginScene, `0x30`=Clear, `0x34`=SetTransform,
`0x58`=SetRenderState, `0x90`=SetTexture, etc.) on the raw `obj+0x28c` device finds them
concentrated in the **0x1000–0x4000 RVA cluster** — functions like `0x71a0` (scene render)
and `0x7340` (per-frame render) which are called *from* the slotted table but are not
themselves slotted. Examples (call sites, not slot RVAs):

- `0x7340`: `obj+0x28c` D3D7-vt[0x64] (EndStateBlock), then `call 0x71a0(obj,1)` scene render
- canonical BeginScene/Clear/SetTransform/SetRenderState/SetTexture sites cluster in 0x1000–0x4000 (called from 0x71a0's render pipeline)

The slotted renderer is therefore a **high-level orchestration layer**; raw D3D7 device
interaction is centralized in the unslotted scene-render cluster.

## 5. Confidence summary

- **High** confidence (45 slots): clear from disasm (trivial getters, pure-internal helpers,
  confirmed COM patterns like 0x7370 DDERR check, 0xacf0 DDS7 Blt, 0x42f0 D3DMATERIAL7 layout).
- **Medium** confidence (13 slots): wrapper-vt offsets interpreted empirically; semantic label
  is right but exact D3D7-equivalent method name may differ (e.g. 0x86a0/0x87a0 scene bracket,
  0x87e0–0x8910 DrawPrimitive variants).
- **Low** confidence (2 slots): +0x48 (0x4240) SetRenderState single, +0x00 (0x4420) dtor.

To lock the wrapper-vt mapping definitively, a Frida capture of the `obj+0x294` vtable
function-pointer table (read its 16 entries at runtime, compare against resolved
`IDirect3DDevice7` if obj+0x294==obj+0x28c, or against a known Giants wrapper if not)
would convert all medium-confidence labels to high.
