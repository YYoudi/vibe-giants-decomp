# Menu 3D logo model — `Giants_logo_3D.gbs` (asset structure, decoded)

**Source**: extracted `Giants_logo_3D.gbs` + `.anm` from `Bin/xx_giants_logo_3d.gzp`; decoded with
`tools/gbs_decode.py` (faithful port of Amazed's `blender-giants-plugin/gbs_plugin/shared.py`).
**Decoded**: 2026-06-19. This is the centerpiece 3D object the menu renders (observed visually in
`orig_menu_3d.png`: the metallic curved "GIANTS / CITIZEN KABUTO" logo).

## Model structure
- **GBS magic** `0xaa0100be`, flags=7 (Normals | UVs | RGBs all present).
- **1337 unique vertices** (XYZ floats), **3858 indexed vertices**, 6531 normals.
- **3 max-objects**, **6 sub-objects**, **2020 triangles total** (strip-encoded tridata).
- Sub-object material: `texname = "Giants_logo_512"` → the model is textured with
  **Giants_logo_512.tga** (512x256, 24bpp). Material: ambient=0x1e0e10, diffuse=0x1e1ecc,
  specular=0xc8c80c, power=27.0, blend=0.3.

## ⚑ CORRECTION (rule 11) — Giants_logo_512.tga IS used
My earlier claim (`orig_vfsopen.md` / `orig-asset-load-sequence` memory) that "Giants_logo_512.tga is
NEVER loaded" was INCOMPLETE and partly WRONG. The truth:
- The engine's VFS open-by-name (`FUN_00539e30`) does NOT open it during the menu (confirmed by the
  runtime hook — no VFS-open by that name).
- BUT the **3D logo MODEL references it as its texture** (`texname="Giants_logo_512"`), and it IS
  displayed at the menu (the metallic logo). It loads via the **renderer's texture-management path**
  (engine→renderer callback[12] = TextureLoader @ 0040d430), NOT via the engine VFS-open-by-name.
- So: a hook on `FUN_00539e30` alone CANNOT prove/disprove texture use. To observe texture loads,
  hook the renderer's TextureLoader callback[12] OR the D3D7 SetTexture@0x8c (per-frame).

## The menu logo = 3-asset recipe
1. **`Giants_logo_3D.gbs`** — the curved 3D logo geometry (this model).
2. **`Giants_logo_512.tga`** — the metallic logo texture (applied via the model's texname).
3. **`Giants_logo_3D.anm`** — the logo animation (1644 bytes; the float/spin).
All three live in `Bin/xx_giants_logo_3d.gzp` (9 entries; also contains the loading-screen TGAs:
giants_loading, mecc/reaper/kabuto_loading, MP_screen).

## Faithful render path (for the recomp)
Render the model through the proven D3D7 3D pipeline ([[d3d7-3d-pipeline-works]]):
- Load `.gbs` → unique verts + indexed verts + UVs + strip-decoded triangles + texname.
- `SetTexture@0x8c(Giants_logo_512)` + `STSS@0x94 COLOROP=MODULATE` + material (ambient/diffuse/specular/power).
- `SetTransform@0x2c(WORLD=256/VIEW=2/PROJ=3)` + directional light + `DrawPrimitive@0x64(XYZ|DIFFUSE|TEX1, FVF=0x142)`.
- The camera/framing + animation come from `flk_intro_island_*.bin` (FLICK cinematic) + `.anm` —
  STILL NEEDS the runtime render-recipe capture (per-frame SetTransform values) for faithful framing.
