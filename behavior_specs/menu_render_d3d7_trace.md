# Menu render — D3D7 per-frame call trace (MEASURED on original)

**Source of truth** for reproducing the vanilla menu render. Captured 2026-06-18 by
the C5 DX7 proxy's per-object D3D7 vtable trace hooks (`proxy_dx7/dx7_proxy_main.cpp`,
slots resolved via [[RE_docs/DX7_D3D7_VTABLE_AUTHORITATIVE.md]]). Run: original
`Giants_nocd.exe -window` with proxy AS `gg_dx7r.dll`, 11s, frames 1-8 consistent.

## Per-frame call counts (steady state, frame 2+)
| Call (slot) | Count | Notes |
|-------------|-------|-------|
| BeginScene (0x14) | 1 | frame delimiter |
| Clear (0x28) | 1 | **flags=0x3 (TARGET\|ZBUFFER), color=0x00000000 = BLACK** |
| DrawPrimitiveVB (0x7c) | **130** | the geometry draw path |
| DrawPrimitive (0x64) | 0 | NOT used |
| DrawIndexedPrimitive/VB/Strided | 0 | NOT used |
| SetTexture (0x8c) | 259-260 | ~2 per draw (bind + NULL-unbind) |
| SetTextureStageState (0x94) | 1566 | ~12 per draw |
| SetRenderState (0x50) | 1301-1303 | ~10 per draw |
| SetTransform (0x2c) | **0** | vertices pre-transformed |
| MultiplyTransform (0x38) | **0** | vertices pre-transformed |

## DrawPrimitiveVB detail (every one of the 130 calls)
```
DrawPrimitiveVB(prim=6, vb=<shared IDirect3DVertexBuffer7*>, start=0, verts=4)
```
- **prim=6 = D3DPT_TRIANGLEFAN** (1=PTLIST 2=LINELIST 3=LINESTRIP 4=TRILIST 5=TRISTRIP 6=TRIFAN)
- 4 verts → a **quad** (fan: 2 triangles). The menu is **130 textured quads** (sprites / UI / 3D-logo pieces / sky).
- **One shared VB** reused for all 130 draws (same ptr within a frame).

## SetTexture detail (the texturing mechanism — was the blocker)
```
SetTexture(stage=0, surf=<IDirectDrawSurface7*>)   ; bind
... DrawPrimitiveVB ...
SetTexture(stage=0, surf=NULL)                     ; unbind after each draw
```
- Textures bound to **stage 0 only**, via **standard D3D7 device SetTexture@0x8c**.
- A DIFFERENT surface ptr per draw (03d1bdd8, 03d1c078, 03d1bdb8, ...) → each quad a distinct texture.
- Pattern: bind → draw → NULL → bind next. Hence 260 SetTextures / 130 draws.

## TextureStageState detail
- stage 0 COLOROP alternates **DISABLE(1) ↔ 14** (14 = a blend op; per-draw setup).
- stage 1 COLOROP always **DISABLE(1)** → only stage 0 active.
- ~12 SetTSS per draw (COLOROP/ARG1/ARG2/MAGFILTER/MINFILTER/MIPFILTER/addressing...).

## Clear detail
```
Clear(count, rects, flags=0x3, color=0x00000000, z, stencil)   ; BLACK
```
- **Sky is NOT the clear color** — the original clears BLACK, then draws the dark cloudy
  sky as one of the 130 textured quads. (Recomp currently clears dark-blue 0xFF2a2a3e —
  a fidelity gap: should clear black + draw sky quad.)

## Implications for the recomp
1. **Why the recomp's terrain/logo never textured**: the recomp binds textures via the
   renderer's internal +0xb4 (BindTexture), which only takes effect inside the renderer's
   OWN scene walk. The actual device-level binding is **SetTexture@0x8c**, which the recomp
   never called in its manual bracket. → to texturize in a bracket, call
   `SetTexture(wrapper, 0, <real IDirectDrawSurface7*>)` at 0x8c + COLOROP via 0x94.
2. **Canonical path** = port the engine scene walk so the renderer itself issues the 130
   DrawPrimitiveVB + 260 SetTexture calls (the render lists in DAT_005a78b4/DAT_006313c8).
3. **Geometry form**: menu entities are pre-transformed textured quads (TRIFAN, 4 verts)
   in a shared vertex buffer — not arbitrary 3D meshes. This matches the menu being mostly
   2D-over-3D chrome.
4. **Clear must be BLACK** (0x00000000), sky drawn as a quad — fix the recomp's blue clear.

## Reproduce the capture
```bash
cd GameFiles-VanillaV1   # proxy deployed: gg_dx7r.dll=proxy, gg_dx7r_orig.dll=real
rm -f giants_dx7_proxy.log
powershell -c "Start-Process .\Giants_nocd.exe -ArgumentList '-window'; sleep 11; Stop-Process -Name Giants_nocd -Force"
grep 'frame [0-9]\+:' giants_dx7_proxy.log   # per-frame summary
```
