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

## ROOT CAUSE (2026-06-19, corrected) — VFS is INNOCENT; bug = managed-texture upload
**CORRECTION**: an earlier note blamed VanillaVFS (claimed zero pixels). That was WRONG. PROOF:
dumped the recomp's `VanillaVFS::GzpReadFile` output for Giants_logo_512 to a file and ran
`cmp vfsdump_logo512.tga extracted/.../Giants_logo_512.tga` → **IDENTICAL** (393260 bytes,
byte-exact). The earlier "center=zeros" samples hit legitimately-BLACK regions of the texture
(the logo's black background). VanillaVFS + the LZ port + VanillaTGA all produce correct pixels.

So the texture surface gets the CORRECT pixels (verified: Lock hr=0x0, valid surface, pixels copied;
the data matches the canonical extraction). `SetTexture@0x8c hr=0x0` (binds). **Yet the sampler
returns white** → the managed texture (DDSCAPS2_TEXTUREMANAGE) is NOT being uploaded to the device's
texture memory. The Lock-write to the managed surface's system-memory shadow isn't committed to VRAM
by this DX7 wrapper. (Tried DDSCAPS_SYSTEMMEMORY instead → 96% white, worse.)

## Next (focused)
1. **Fix the texture upload** via the robust DX7 pattern: create a SYSTEMMEMORY offscreen surface,
   fill it (guaranteed), create the managed TEXTURE surface, then **Blt** sysmem→texture (forces the
   driver upload) — instead of Lock-writing the managed surface directly.
   **Blt slot search (2026-06-19)**: dumped the wrapper-surface vtable (all slots in DDRAW.dll).
   Lock@0x64=slot25, Unlock@0x80=slot32, GetDDInterface@0x90=slot36 (non-standard, +1/+2 shift vs
   IDirectDrawSurface7). Tried Blt@0x18(slot6) → **CRASH** (slot6=BltBatch, wrong). Blt@0x14(slot5)
   with full RECTs → hr=0x80070057 (invalid-arg, no crash) — slot5 not Blt either, or signature/caps
   mismatch. **Blt's slot still unknown** — needs ddraw.dll symbols or RenderDoc. Alternative: try
   SetTexture on a DDSCAPS_TEXTURE|DDSCAPS_SYSTEMMEMORY surface directly (driver may sample sysmem),
   or IDirect3DDevice7::Load.
2. Capture the original's per-frame render recipe (proxy/Frida) for the faithful camera, tune to
   capdiff-PASS vs `orig_menu_3d.png`.

## 2026-06-19 — renderer's OWN scene-walk also renders white (scene not loaded)
Tested -scene3d (VanillaRunFrame → renderer's real scene walk, slot 0x7370) with a clean
forced-foreground capture: 88% white, 0% colored, 6 distinct. So it's NOT just my manual
SetTexture — the renderer's scene-walk ALSO renders nothing, because the recomp never loads the
SCENE (no FUN_004b7c50 world load, no camera setup via callback[12], no object placements). The
manual-D3D7-texture approach is a confirmed dead end. The FAITHFUL path = port the boot chain
(FUN_004913c0 → FUN_0045a530 → FUN_004b7c50 → FUN_004f3230) so the scene is populated, then the
renderer's scene-walk renders it (with textures) itself. (Also: the d3d7-3d-pipeline "textured
terrain" memory is likely STALE — clean captures show white for both terrain-menu and logo3d.)
