# Vanilla 2D render pipeline (from decompiled code, NOT screenshots)

**How the original renders intros, loading screen, menu sky/logo/GUI text, all 2D.**
Derived 2026-06-18 by reading vanilla_decompiled (FUN_00523b60, FUN_004338d0,
FUN_00433900, FUN_0050eb50) — the answer to "analyze how the code works" rather than
pixel-chasing screenshots. This is the canonical 2D path the recomp's GDI bracket deviates from.

## Overview
All 2D imagery (intros, loading, menu background/logo/text) goes through ONE blitter that
**tiles the image into ≤128px texture tiles and draws each as a TRIFAN quad**. This is the
source of the "130 TRIFAN-4 quads" seen in the D3D7 trace of the menu
([[behavior_specs/menu_render_d3d7_trace.md]]) — the menu's sky/logo/text are large 2D
images tiled into 128px quads.

## The four functions

### FUN_00523b60 — intro sequence driver (reads intros.bin)
```
read intros.bin (FUN_00539e30 open, 0051d810 size, 0053c810 alloc, 0051d750 read, 0051d850 close)
parse each line → intro name; "legal" → localized (legalFrench)
for each intro image:
    FUN_0050eb50(name, &texHandle, &w, &h, &tileArray)   // load + tile into 128px textures
    draw once: +0x98(renderer, 0=BLACK Clear)             // 0x98 = Clear/FillBackground
               FUN_004338d0(texHandle, w*h, 1.0, tileArray)   // full-opaque first frame
               +0xa8(renderer)                             // 0xa8 = Present
    fade loop (per frame step _DAT_00552344):
        fade = DAT_005522c0 − elapsed × _DAT_00552358     // rate=5.0 (DAT_00552358)
        +0x98(renderer, 0); FUN_004338d0(tex, wh, fade, tiles); +0xa8(renderer)
        FUN_0051e7c0 (TimeAccessor tick), FUN_0051f0e0/0051f1f0/0041f400 (frame)
        skip if DAT_00631108/0b/0e (keys) or DAT_00631104 (mouse)
```
Constants: 0.2s fade / 12s hold (behavior_specs/intro_timings.md). _DAT_00552358=5.0 rate.
**Clear is BLACK (0)** — matches the menu trace (Clear color=0x00000000).

### FUN_004338d0(texHandle, wh, fade, tileArray) — thin wrapper
```
FUN_00433900(1.0, 1.0, texHandle, wh, fade, tileArray)
```
(1.0, 1.0 = u/v base scale.)

### FUN_00433900(uScale, vScale, imgW, imgH, fade, tileArray) — THE TILED 2D BLITTER
```
tileW = GetCaps(renderer, 3)  // +0xc4 GetCaps index 3 = max texture width
tileH = GetCaps(renderer, 4)  // index 4 = max texture height
tileW = min(tileW, 128); tileH = min(tileH, 128)      // clamp 128
tilesX = ceil(imgW / tileW);  tilesY = ceil(imgH / tileH)
SetRenderState(+0x50, 2, 0)                           // state 2 (alpha/z?) = 0
for ty in tilesY, tx in tilesX:
    tile = tileArray[ty*tilesX + tx]                  // this tile's texture handle + src-rect
    SetTileTexture(DAT_00654948, 0x62024, tile, fade << 24)   // DAT_00654948+8 = stage SetTexture;
                                                            // fade in ALPHA high byte (the fade!)
    verts = LockVB(DAT_00654958, 4)                   // DAT_00654958+0x10 = lock 4 verts (a quad)
    // write 4 verts: XYZRHW (screen px) + UV (tile src-rect) + DIFFUSE(alpha=fade)
    quad @ screen (x0,y0)-(x1,y1) = tile's position, UVs = tile's sub-rect
SetRenderState(+0x50, 0, 0)                           // restore
```
Each tile = **1 DrawPrimitive TRIFAN (prim=6, 4 verts)** — EXACTLY the menu trace shape.

### FUN_0050eb50(name, &texHandle, &w, &h, &tileArray) — texture load + tile
```
tileW/H = GetCaps(3/4) clamped 128
build "<name>.tga"; FUN_0053a3a0 open
parse TGA (width/height/bpp)
for each 128px tile: create a D3D7 texture surface (renderer +0xd8 CreateTexture),
    upload the tile's pixels, store handle + src-rect in tileArray
return tileArray + dims   // (outputs the same tileArray FUN_00433900 walks)
```

## Key objects (DAT_ addresses)
- **DAT_00654940** = the renderer object (g_vRenderer). Methods: +0x98 Clear, +0xa8 Present,
  +0xc4 GetCaps (8-case: 3=maxTexW, 4=maxTexH), +0x50 SetRenderState, +0xd8 CreateTexture.
- **DAT_00654948** = texture-stage sub-object. +8 = SetTexture(this, flags=0x62024, tileTex, alphaRGBA).
- **DAT_00654958** = vertex-buffer sub-object. +0x10 = Lock(this, 4) → returns ptr to 4 verts (28B each: XYZRHW+DIFFUSE+UV).

## Why the recomp deviates (and the fix)
The recomp's intro/menu bracket uses **GDI BitBlt** (double-buffered memory DC) — a totally
different path. The faithful fix: **port FUN_00433900 (the tiled blitter)** to drive the D3D7
device (already mapped: SetTexture@0x8c, SetTextureStageState@0x94, DrawPrimitive@0x64 —
[[dx7-wrapper-is-standard-d3d7]]) + create 128px tile textures (VanillaD3D7Tex already
creates D3D7 surfaces). Then intros/menu render through the renderer like the original →
bit-faithful, and the "130 quads" naturally emerge.

## Port plan (canonical 2D path)
1. Port FUN_0050eb50: load TGA (VanillaTGA), split into 128px tiles, create a D3D7 texture
   surface per tile (extend VanillaD3D7Tex).
2. Port FUN_00433900: per tile → SetTexture@0x8c + STSS COLOROP=MODULATE/SELECTARG1 +
   DrawPrimitive@0x64 TRIFAN-4 (XYZRHW+DIFFUSE[alpha=fade]+UV).
3. Port FUN_00523b60 driver: intros.bin → per image load+blit, fade envelope, +0x98 Clear(0),
   +0xa8 Present. Replace the GDI bracket in VanillaDriveFrame.
4. Verify: capdiff intro1 should PASS (same renderer path as original).
