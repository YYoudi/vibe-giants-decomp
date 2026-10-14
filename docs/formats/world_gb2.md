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

## Open items

- Per-component body layouts (vertex format, counts, color encoding) — needs the
  component loader/render path (upcall-side, `GDV` renderer interface). Tracked for
  P1.3 RENDERER.md; for a Rust reimplementation the sky/sea/waterfall can also be
  rebuilt procedurally once the vertex soup is dumped per component (P1.1 runtime dump
  of the loaded component structs will settle it).
