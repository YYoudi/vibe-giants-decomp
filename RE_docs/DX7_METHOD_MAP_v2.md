# DX7 Renderer Method-Table Map v2 — `gg_dx7r.dll` (vanilla v1.0)

**Target:** `GameFiles-VanillaV1/gg_dx7r.dll` (PE32, base 0x10000000, .text RVA 0x1000–0x16000).
**Engine renderer-object global:** `DAT_00654940`. Written in WinMain @ 0x5222c0 as `DAT_00654940 = GDVSysCreate(...)`. Referenced by 64 vanilla functions.
**Supersedes:** `DX7_METHOD_MAP.md` (v1). v2 adds engine-side call-pattern evidence and resolves wrapper-vt[0x30] Clear-vs-SetTransform via Frida runtime disasm.

## Evidence tiers
- **CONFIRMED-runtime**: Frida disasm of live `obj+0x294` wrapper vtable, or unambiguous engine call pattern.
- **CONFIRMED-disasm**: static disasm of gg_dx7r.dll slot fn + matching engine call signature.
- **INFERRED**: single line of evidence; best-fit label, states what would confirm.

## 1. Front table — engine-driven slots on `DAT_00654940` (`__cdecl(this,args)`)

### Device lifecycle
| slot | RVA | semantic | conf |
|------|-----|----------|------|
| +0x60 | 0xc880 | Present/Flip (Blt chain to window) | INFERRED (reached via +0xa8) |
| +0x64 | 0xc900 | internal mode-set dispatcher | INFERRED (engine calls +0x68) |
| +0x68 | 0xc9d0 | **SetDisplayMode / device reset** `(obj,w,h,bpp,refresh,win,&out1,&out2)` | CONFIRMED-disasm (caller 0x455640) |
| +0x6c | 0xc970 | **GetDisplayConfig** `(obj,&out1,&out2)` 2×16B | CONFIRMED-disasm |
| +0x70 | 0x79c0 | internal: surface-list builder | CONFIRMED-disasm |
| +0x78 | 0x7aa0 | EnumerateDisplayModes (640×480×16 filter) | CONFIRMED-disasm |
| +0x80 | 0x7370 | TestCooperativeLevel / per-frame gate | CONFIRMED-disasm |
| +0x84 | 0x73e0 | **PushScene/PopScene** `(obj,1)`…`(obj,0)` bracket | CONFIRMED-disasm (callers 0x524c10/0x523700) |
| +0x88 | 0x7910 | **FrameReset** (zero render-state cache, once/frame top) | CONFIRMED-disasm (caller 0x4742f0) |
| +0x8c | 0xaba0 | PushViewport/SetRenderTarget `(obj,surf,flags)`→bool | CONFIRMED-disasm |
| +0x90 | 0x86a0 | **BeginScene (+Clear +SetTextureStageState×4)** | CONFIRMED-runtime (ref-counted via 0x4551d0) |
| +0x94 | 0x87a0 | **EndScene** | CONFIRMED-runtime (ref-counted via 0x455280) |
| +0x98 | 0x87e0 | **Clear/FillBackground** `(obj, ARGB color)` BEFORE BeginScene | CONFIRMED-disasm |
| +0xa8 | 0x8990 | **Present** (end-of-frame, last call after EndScene) | CONFIRMED-disasm |

### Drawing
| slot | RVA | semantic | conf |
|------|-----|----------|------|
| +0x9c | 0x8810 | **DrawPrimitive 2D / scaled Blt quad** `(obj,0,x,y,w,h,color)` HUD | CONFIRMED-disasm |
| +0xa0 | 0x8890 | DrawPrimitive 2D variant | INFERRED |
| +0xa4 | 0x8910 | DrawPrimitive LINELIST | CONFIRMED-disasm |
| +0xac | 0x84d0 | **SetRenderState batch + SetTransform** `(obj,matrix@+0x128,color@+0x12c,ptr@+0x130)` per-entity | CONFIRMED-disasm |
| +0xb8 | 0xacf0 | PopViewport/RestoreRenderTarget + 2D sprite Blt | CONFIRMED-disasm |
| +0xc0 | 0xae80 | GetSurfaceDesc/GetCaps `(obj,surf,&w,&h)` | CONFIRMED-disasm |

### State / texture / material
| slot | RVA | semantic | conf |
|------|-----|----------|------|
| +0x14 | 0x42d0 | SetWorldMatrix/SetTransform (model) inside BeginScene | CONFIRMED-disasm |
| +0x20 | 0x3ee0 | **SetCameraProjection** `(obj, &4×4 matrix)` — callers 0x51bbd0 (2D/HUD), 0x51bea0 (perspective) | CONFIRMED-disasm |
| +0x2c/+0x30/+0x34 | — | Clear viewport rect (dispatch via wrapper vt[0x30]) | CONFIRMED-disasm |
| +0x38 | 0x4130 | SetViewport region (scaled) → wrapper vt[0x3c] | CONFIRMED-disasm |
| +0x3c | 0x4070 | **SetTransform** (matrix + aspect rect) → wrapper vt[0x34] | CONFIRMED-disasm |
| +0x5c | 0x42f0 | SetMaterial (D3DMATERIAL7) → wrapper vt[0x48] | CONFIRMED-disasm |
| +0xb0 | 0xc030 | **IsTextureLoaded/ValidateSurface** `(obj,surf)`→bool | CONFIRMED-disasm |
| +0xb4 | 0xc6a0 | **ReleaseTexture** `(obj, tex)` | CONFIRMED-disasm |
| +0xd8 | 0x7bf0 | **CreateTexture/UpdateTexture** `(obj,src,dst,w*8,8,ptr)` raw pixel upload | CONFIRMED-disasm |
| +0xe0 | 0x7be0 | LockBackbuffer/screenshot readback `(obj,ptr)` | INFERRED (re-disasm gap) |

### Caps / dispatch / text
| slot | RVA | semantic | conf |
|------|-----|----------|------|
| +0x04 | 0x3090 | entity-list node allocator (0x60B ctor) | CONFIRMED-disasm |
| +0x0c | 0x3490 | scene-entity node allocator (0x2d8B ctor) | CONFIRMED-disasm |
| +0x10 | 0x2d80 | **scene-object dispatch** (linked-list walk, node-vt[0x30] per entity) | CONFIRMED-disasm (819K calls/frame hot path) |
| +0xc4 | 0x7870 | **GetCaps** `(obj,index)` 8-case switch (HW T&L, w, h, caps bitmask) | CONFIRMED-disasm |
| +0xd4/+0xdc | 0x7f20/0x7c00 | DrawText (glyph blit 555/565) | CONFIRMED-disasm |

## 2. GetCaps (+0xc4) case table (jump table @ 0x100078e4)
| case | returns | meaning |
|0 | `!obj+0x42c` | "is mode empty" bool |
|1 | obj+0x4d8 | surface width |
|2 | obj+0x4dc | surface height |
|3/4 | obj+0x2a0/0x2a8 float | X/Y DPI |
|7 | obj+0x544 | caps bitmask (bits 2,4,0x40,0x4000 tested) |

## 3. Wrapper@obj+0x294 — private D3D7-device wrapper vtable (NOT canonical IDirect3DDevice7)
| wrapper-vt | semantic | conf |
|-----------|----------|------|
| vt[0x14] | **BeginScene** | CONFIRMED-runtime |
| vt[0x18] | **EndScene** | CONFIRMED-runtime |
| vt[0x28] | **DrawPrimitive/DrawIndexedPrimitive** | CONFIRMED-runtime |
| vt[0x2c] | invalidate/dispatch (viewport-invalidate stage selector) | CONFIRMED-runtime |
| vt[0x30] | **Clear** (resolves prior Clear-vs-SetTransform ambiguity) | CONFIRMED-runtime |
| vt[0x34] | **SetTransform** | CONFIRMED-disasm |
| vt[0x3c] | SetViewport | CONFIRMED-disasm |
| vt[0x48] | SetMaterial | CONFIRMED-disasm |
| vt[0x50] | **SetRenderState** (batched/deferred — bitfield test at obj+0x31b0) | CONFIRMED-runtime |
| vt[0x94] | SetTextureStageState | CONFIRMED-disasm |
| vt[0xb0] | commit/apply fallback (post-SetMaterial) | CONFIRMED-disasm |
Gaps: vt[0x38,0x40,0x44,0x4c,0x54..0x90,0x98..0xb0] — re-run `scripts/frida_wrapper_vtable.js` to confirm.

## 4. The canonical engine frame — slot call order (FUN_004742f0)
```
(+0x88)(obj)                  ; FrameReset
(+0x20)(obj, &projMatrix)     ; SetCameraProjection (perspective or 2D/HUD)
... optional light/shadow passes (each = +0x8c push ... +0xb8 pop) ...
(+0x98)(obj, bgColor)         ; Clear/FillBackground (pre-scene wipe)
EnterScene (refcount 0→1):
    (+0x90)(obj)              ; BeginScene
    (+0x14)(obj)              ; SetWorldMatrix (model transform)
    ... entity draws via +0x10 dispatch ...
    ... 2D HUD via +0x9c (×N) ...
LeaveScene (refcount 1→0):
    (+0x94)(obj)              ; EndScene
(+0xa8)(obj)                  ; Present/Flip
```
Modal bracket: `(+0x84)(obj,1)` … work … `(+0x84)(obj,0)`.

## 5. CRITICAL for menu 3D fidelity
- `+0x20(obj, &matrix)` takes the **projection matrix** — the renderer DOES handle projection (my earlier "wrapper ignores transforms" was wrong: I used the wrong slot). Use +0x20 for projection, +0x14 for world/model.
- `+0x98(obj, color)` is the Clear (background), NOT +0x90. +0x90 is BeginScene.
- `+0xa8(obj)` is the real Present — should replace the GDI BitBlt workaround.
- `+0xac` per-entity sets world matrix + material + texture-factor (batched). This is how entities are positioned.
- `+0xd8` CreateTexture / `+0xb4` ReleaseTexture = texture lifecycle for textured geometry.

## 6. Differences from v1
| slot | v1 | v2 |
|+0x20 | "per-frame entry 0x7370" | **SetCameraProjection** (matrix arg) |
|+0x84 | "scene-state refcount toggle" | **PushScene/PopScene** |
|+0x98 | "DrawPrimitive stage 3" | **Clear/FillBackground** |
|+0xa8 | "get backbuffer surface" | **Present** (end-of-frame) |
|+0x9c | "DrawPrimitive indexed" | **DrawPrimitive 2D quad** (HUD) |
|+0xb0 | "entity visibility cull" | **IsTextureLoaded** |
|+0xb4 | "entity-list thunk" | **ReleaseTexture** |
|+0xd8 | (unmapped) | **CreateTexture** |
|wrapper vt[0x30] | "Clear OR SetTransform" | **Clear** (SetTransform is vt[0x34]) |

## 7. Open gaps
1. Re-run `scripts/frida_wrapper_vtable.js` to dump all 48 wrapper-vt ptrs (confirm 13 INFERRED).
2. Disambiguate +0xe0 (screenshot path; slot RVA 0x7be0 may be stub).
3. Capture Frida slot-invocation order on the ORIGINAL exe to lock per-frame ordering for renderer-internal slots.

**Sources:** gg_dx7r.dll; reports/frida_wrapper_disasm.txt; reports/dx7_gdvsyscreate.md; reports/frida_render_recipe.txt; vanilla_decompiled/{004551d0,00455280,004742f0,00448210,0051bea0,0051bbd0,00523700,00524c10,004833d0,004f3630,004f3b80,00521980,004f1220,0050e4b0,00455640}.json.
