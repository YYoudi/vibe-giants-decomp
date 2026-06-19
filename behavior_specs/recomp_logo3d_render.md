# Recomp menu 3D logo render — STATUS (diagnostic, WIP)

**2026-06-19.** Wired the observed menu 3D logo (`Giants_logo_3D.gbs` + `Giants_logo_512.tga`,
see `orig_logo3d_model.md`) into the recomp via the proven D3D7 3D pipeline. Driven by the
`-logo3d` flag (replaces the wrong flat-2D-blit logo path in the MENU bracket).

## What WORKS (verified by trace + capture)
- `VanillaLogo_Draw` (src_vanilla/VanillaLogo.cpp): loads `Giants_logo_3D.gbs` from
  `xx_giants_logo_3d.gzp`, parses via VanillaGBS (1337 verts, 2020 tris, bbox known), builds
  textured verts (XYZ+DIFFUSE+UV, FVF 0x142), sets a bbox-framed camera (eye along -Y, the thin
  axis), binds `Giants_logo_512.tga` via the generic `VanillaD3D7_BindTga`, and submits
  `DrawPrimitive@0x64` every frame.
- Trace confirms: `DrawPrimitive 6060 verts (2020 tris) hr=0x0` per frame; texture surface
  created + `Lock hr=0x0 lpSurface=valid pitch=2048` (pixels copied).
- Capture: the 3D geometry RENDERS (visible mesh against the dark sky) — the GBS→D3D7 path is
  proven end-to-end for the logo. The wrong 2D-blit logo is replaced.

## What does NOT work yet (WIP — texture samples white)
- The textured logo renders WHITE (pixel sample: 79% white, 20% dark-sky). The texture surface is
  created + locked + filled correctly (Lock succeeds, valid pointer, correct pitch) yet the sampler
  returns white everywhere. Same symptom affects the terrain path post the BindTga refactor (which
  is logically identical to the original BindIntroGrnd — so the bug is NOT the refactor; likely the
  managed-texture upload / SetTexture state / renderer-bracket state reset).
- Camera framing is a bbox guess (eye along -Y, the thin axis) — NOT the original's framing. The
  faithful camera/transforms come from the per-frame render-recipe capture (proxy D3D7 trace),
  still blocked by the flaky game launch under the proxy.

## Next (focused)
1. Fix the texture-sampling-white bug. Diagnosed so far: texture surface created, `Lock hr=0x0`
   (valid surface, correct pitch, pixels copied), AND `SetTexture@0x8c hr=0x0` (binds OK) — yet the
   sampler returns white everywhere (lit faces render white, unlit faces render dark-mesh). Tried
   DDSCAPS2_TEXTUREMANAGE (79% white) vs DDSCAPS_SYSTEMMEMORY (96% white, worse) — managed is
   better. UVs span U[-1.67..2.67]/V[-0.06..1.45] (outside [0,1], but WRAP should tile, not white).
   Root cause NOT found by reasoning — needs RenderDoc surface inspection or comparing against the
   terrain path that reported tex_variety=3405 in an earlier `-scene3d` test (re-establish that to
   isolate what's different).
2. Capture the original's per-frame SetTransform/SetTexture/DrawPrimitive recipe (proxy or Frida
   device-vtable hook) for the faithful camera + material, then tune to capdiff-PASS vs
   `orig_menu_3d.png`.
