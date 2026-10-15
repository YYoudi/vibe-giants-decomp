# `world.gb2` — world component bundle (magic `0xAA0100AB`)

Status: ✅ container decoded · component bodies: prologue decoded, vertex/body layouts
partial (see Open items).

**Evidence:** GOG 1.449 corpus (`game_files_check @ 0x004EE890` — integrity check;
component instantiation path via the GameObj.bin registry, see
[abx.md](abx.md)); file itself **observed** — shipped inside `Bin/extra.gzp`
(25 488 B uncompressed, extracted read-only with the canonical Amazed LZ decoder).

## Where it lives

`world.gb2` is not a loose file: it ships inside `Bin/extra.gzp` (the GZP container is
✅ spec'd in FORMAT_INVENTORY). `GameObj.bin` registers its 9 named components
(sky, outsky, sea, waterfall, waterfall2, wfall_edge, world_glow, underside, space);
the engine streams them by name at world setup.

## Container layout (**observed**, byte-verified)

```
u32 magic      = 0xAA0100AB
u32 count      = 9
u32 offsets[9] // absolute file offsets of components
               // observed: 0x2C, 0xCF4, 0x2248, 0x379C, 0x39B8, 0x4440, 0x453C, 0x5064, 0x5BC8
components:    // at each offset
    char name[16]   // NUL-terminated, NUL-padded — join key with GameObj.bin
    ...component body...
```

Observed first component (`offsets[0] = 0x2C`, name `"space"`):

```
+0x2C  char[16] "space"
+0x3C  u32 2                       // prologue field (version or type tag) — S
+0x40  u32 0
+0x44  u32 0
+0x48  char[16] "tspace"           // second embedded name (texture tag: t+<name>)
+0x58  f32[] ...                   // vertex/color data to end of component (0x2C→0xCF4)
```

The recurring second name `t<component>` (e.g. `space` → `tspace`) is *inferred* to be
the component's texture/lookup name. Bodies are float-dense — consistent with
render-managed vertex/color buffers for the sky dome, sea surface, waterfalls, and glow
quads (the visible world dressing).

## Component inventory (from GameObj.bin × gb2 names)

| # | name | role (inferred) |
|---|---|---|
| 1 | sky | sky dome |
| 2 | outsky | outer sky / horizon |
| 3 | sea | sea surface |
| 4 | waterfall | waterfall quad |
| 5 | waterfall2 | waterfall variant |
| 6 | wfall_edge | waterfall edge foam |
| 7 | world_glow | global glow/halo |
| 8 | underside | island underside |
| 9 | space | starfield/space skybox (first in gb2 offset order) |

## MISE À JOUR 2026-10-15 — body layout COMPLÈTEMENT DÉCODÉ (parser dérivé + validé fichier)

**Parser : `main_makeobj_00471e10 @ 0x00471E10`** (appelé par `BinFileSeek_5`,
depuis `main_readdata` après lecture de GameObj.bin).

```
u32 magic   ∈ { 0xAA0100AB (v1, avec champ fmt), 0xAA0100AA (v0, fmt=0x101 implicite) }
              (sinon "Bad version of GB2 file")
i32 count
u32 offsets[count]        // relatifs au début du buffer

component @ offset:
    char  name[16]        // ex. "space"
    u32   flags           // &1 = dual-pos (skinning), &2 = UV + texture, &4 = RGB par vertex
    u32   usage           // (retourné, rôle secondaire)
    [u32 fmt]             // SI magic v1 : format FVF-like (observé 0, 0x101 = XYZ|UV1)
    [char texture[16]]    // SI flags&2 : nom de texture (ex. "tspace") → chargée par
                          //   main_texture_00508750 → devient WS+0x4C via op 30
    u32   vertex_count
    u32   tri_count
    f32   pos[vertex_count * 3]          // "objp3d" (12 B/vertex)
    [f32 pos2[vertex_count * 3]]         // SI flags&1 (2e canal position, skinned)
    [f32 uv[vertex_count * 2] ]          // SI flags&2 ("objuv", 8 B/vertex)
    [u8  rgb[vertex_count * 3] ]         // SI flags&4 ("objrgb", 3 B/vertex)
    u16   tri_indices[tri_count * 3]     // "objtri" (triangle list)
```

**Validé par octets** sur `world.gb2` réel : composant `space` = name "space",
flags=2, usage=0, fmt=0, texture "tspace", **vcount=89, tricount=120**, puis les
floats. (Les tailles restantes suggèrent un bloc index redondant par composant —
à trancher en décodant les 9 composants avec le parseur.)

### Rendu (dlog_scene_submit @ 0x0042A4F0)

```
gfx_state+8(FVF_GDV=0x24, texture=WS+0x4C, 0)        // texture 1 (op 30 du world bin)
vertex lock(count=vcount) ; par vertex (stride 6 f32 = 24 B) :
    v[0..2] = pos   v[3] = 0xFFFFFFFF (diffuse blanc forcé)   v[4..5] = uv
primbuffer+0x20(primCount = tricount*3, indices=tri)   // TRIANGLELIST
SI WS+0x16C > 0 : 2e passe même géométrie, FVF 0x60720, texture 0,
                  couleur RGBA packée depuis WS+0x16C..0x178 (passe fog du ciel)
```

Le registre `DAT_632D2C` (GameObj) expose : `+4`=vcount, `+8`=tricount,
`+0xC`=pos, `+0x10`=uv, `+0x18`=indices.
