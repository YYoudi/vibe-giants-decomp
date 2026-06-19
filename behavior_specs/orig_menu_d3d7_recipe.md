# Original menu — D3D7 DEVICE render recipe (RUNTIME-OBSERVED 2026-06-19)

**Source**: `scripts/frida_render_recipe_d3d7.js` hooking the ORIGINAL's IDirect3DDevice7
(stock D3DIM700.DLL device at `renderer_obj+0x294`, `obj` = `DAT_00654940` g_vRenderer).
Method slots (vtable byte-offset): BeginScene@0x14, EndScene@0x18, SetTransform@0x2c,
SetRenderState@0x50, DrawPrimitive@0x64, DrawIndexedPrimitive@0x68, DrawPrimitiveVB@0x6c,
DrawIndexedPrimitiveVB@0x70, DrawPrimitiveStrided@0x78, DrawIndexedPrimitiveStrided@0x7c.
All device methods `__stdcall`. Captured at the post-intro / pre-click menu screen (~37.7–38.6s).

## CRITICAL: which draw API fires
- **DrawIndexedPrimitiveStrided (0x7c)** = the ONLY geometry path that fires at the menu.
  The engine submits mesh geometry as **strided** (separate position/normal/UV arrays),
  indexed, **PT_TRIANGLEFAN**.
- DrawPrimitive (0x64), DrawIndexedPrimitive (0x68), DrawPrimitiveVB (0x6c),
  DrawIndexedPrimitiveVB (0x70) — **0 calls** at the menu. The engine does NOT use plain
  DrawPrimitive / vertex buffers for the menu. (This contradicts the recomp's current
  VanillaLogo/VanillaTerrain which use DrawPrimitive FVF 0x142 — a DIFFERENT, non-faithful path.)

## The 2D GUI / overlay pass (frame #1 at the menu, ~37.76s)
Per element: `SetTexture(0, surf)` then `DrawIndexedPrimitiveStrided(FAN, ...)` with
**vCount=4** (a textured quad = one sprite / text glyph / UI element). Many per frame,
each binding a different texture surface. raw args: `a2=stridedDataPtr, a4=4(vCount),
a6/a7 = index/flags ptrs`. This is the 2D profile-select overlay ("Qui êtes-vous?").

## Camera — the 3D-scene VIEW matrix (THE missing piece, t=38.185s)
DX7 transform states are SMALL (not 256+): **1=WORLD, 2=VIEW, 3=PROJECTION, 16=TEXTURE0,
17=TEXTURE1**. Observed 3D-scene matrices:
```
VIEW  (state 2) =
  [ 0.9563,  0.0000,  0.2925, 0.0000,
   -0.2925,  0.0000,  0.9563, 0.0000,
    0.0000,  1.0000,  0.0000, 0.0000,
  650.9169,-44.0000,-323.1864,1.0000 ]
PROJ  (state 3) =
  [ 1.2990, 0, 0, 0,
    0, 1.7321, 0, 0,
    0, 0, 1.0001, 1.0,
    0, 0,-1.0001, 0 ]            // LH perspective, fovY=60° (cot30=√3), aspect 4/3, znear≈1
```
- VIEW translation (650.9, -44, -323.2) = the observed camera pos (-527.9, 499.4, 44.0) /
  ang (163°, 0, 0) baked into a LH view matrix. This is the menu's 3D island camera.
- The menu camera is **ANIMATED (a path)**: across the frame the VIEW translation moves
  650,-44,-323 → 1328, 592, -6409 and FOV/aspect shift (proj _11: 1.299→1.333→1.2636 =
  640×480 / 800×600 viewports). Multiple sub-viewports are rendered per frame.
- 2D-overlay VIEW (after the 3D pass) = identity with z-flip:
  `[1,0,0,0;0,1,0,0;0,0,-1,0;0,0,0,1]`, PROJ identity.

## WORLD / texture transforms
- WORLD (state 1): identity for the main 3D objects (logo at world origin), plus large
  per-entity matrices (scaled ~5000–30000) for the animated camera-path proxy objects.
- TEXTURE0 (state 16): a `0.0125`-scale animating texture matrix (scrolling/uv-anim).
- TEXTURE1 (state 17): a rotation-style texture matrix.

## Render states observed (SetRenderState@0x50, partial)
st=7 (D3DRS_SHADEMODE)=1 (GOURAUD), st=8 (ZENABLE)=3, st=14 (ZFUNC?), st=22 (LIGHTING)=2,
st=27, st=28, st=29, st=60, st=136/137/141/145/146 (texture-stage / colorop states).

## IMPLICATION for the recomp (faithful reproduction)
1. The recomp must set **VIEW + PROJ** to the observed matrices at the menu 3D pass
   (the recomp currently pushes only PROJ via renderer +0x20 and uses identity/bbox VIEW →
   that is why renders are white/wrong-framed).
2. The draw path is **DrawIndexedPrimitiveStrided**, NOT DrawPrimitive. The recomp's
   VanillaLogo/VanillaTerrain use DrawPrimitive (FVF 0x142) — a different, non-matching path.
   For bit-faithful parity the engine must submit strided+indexed FAN geometry.
3. The 3D island+logo mesh draws are GATED behind the click-to-enter-3D (the auto-advanced
   post-intro screen renders only the 2D profile-select overlay). To OBSERVE the 3D mesh
   draw recipe, the original must be driven past the click (SendInput fails on DI8;
   Frida must synthesize the click via a different route, or the 4-clicks done manually).

## Click-to-enter-3D — input injection BLOCKED (2026-06-19)
The 3D island+logo mesh draws are click-gated. Attempted to drive the original past the click
to OBSERVE the 3D mesh recipe via `scripts/frida_render_recipe_3d_run.py` (AttachThreadInput
foreground + SendInput AND PostMessage WM_LBUTTONDOWN/UP, 8 clicks). RESULT: the game stayed
on the 2D profile-select overlay — **0 big-mesh (vCount>50) DrawIndexedPrimitiveStrided draws**.
DI8 foreground/exclusive mouse ignores both SendInput and PostMessage for scene-entry. So the
3D mesh draw recipe (the actual strided vertex data for island+logo) can only be captured with
MANUAL human clicks. The auto-advanced menu (post-intro, no click) renders only the 2D overlay.

## Faithful port roadmap (next cycles)
The camera path is `FUN_0040d560` (selects active camera obj DAT_005561a0) → `FUN_0040d9f0`
(computes eye/target/up) → `FUN_00403880` (mtxLookAtLH → DAT_005561c0/00556204) →
`FUN_0040d190` (push matrix to renderer). These are stateful deep-engine functions (active-cam
object graph at obj+0x170/+0x210, globals DAT_00556184/0055618c/00631224/006310e8). Porting them
is multi-cycle. Until then, the recomp has no VIEW → renders white/wrong-framed.
