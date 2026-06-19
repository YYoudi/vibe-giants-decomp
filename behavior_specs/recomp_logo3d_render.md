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

## ROOT CAUSE FOUND (2026-06-19) — it's a VFS bug, NOT D3D texturing
The texture samples white because `VanillaVFS::GzpReadFile("xx_giants_logo_3d.gzp",
"Giants_logo_512.tga")` returns a buffer of the CORRECT size (393260 = 18 + 512*256*3) with the
CORRECT TGA header (512x256 type2 24bpp) but **ALL-ZERO pixel data**. Confirmed by trace:
`VFSraw Giants_logo_512.tga len=393260 hdr: 00 00 02 ... 00 02 00 01 18 00` (512x256 ✓) yet pixels
zero; `copy center(256,128): src=000000...`, `READBACK: 000000...`.
Python `tools/gzp_extract.py` decompresses the SAME entry correctly (metallic logo PNG). So the LZ
data is valid — the recomp `VanillaVFS` LZ decompressor (port of Amazed's fileutils.py) produces
zeros for THIS entry (compr=1, compSize=226336 uncmpSize=393260). Other entries (intro_sea 256x256)
decompress fine (`raw@pos: 68 47 3e ...`). Entry-specific LZ bug.
The D3D path is INNOCENT: SetTexture hr=0x0, Lock hr=0x0, surface created + pixels copied (just
zero pixels). Fix = `VanillaVFS::GzpReadFile` (src_vanilla/VanillaVFS.cpp) — diff its LZ against
the Python canonical (tools/gzp_extract.py lz_decompress) for this entry.

## Next (focused)
1. **Fix VanillaVFS LZ for Giants_logo_512** (diff vs Python canonical) → logo texture non-zero →
   3D logo renders with its metallic texture.
2. Capture the original's per-frame render recipe (proxy/Frida) for the faithful camera, tune to
   capdiff-PASS vs `orig_menu_3d.png`.
