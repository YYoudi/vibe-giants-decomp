# RECOMP TEXTURE BINDING BROKEN — silent render regression (2026-06-19, Rule 11 catch)

## Symptom
EVERY render phase is now ~90% white with a consistent near-white-blue RGB(241,243,249):
- intro1 capdiff = **0.5139 FAIL** (was 0.0006 PASS — REGRESSION). recomp intro1 = white.
- loading (-at loading, frozen) = white center. giants_loading.tga loaded (trace: 5x4 tiles) but
  NOT visible. Original loading screen = mostly BLACK + green character portraits.
- menu = white (known).

## Root cause (the FUNDAMENTAL blocker, unifies 2D + 3D white-render)
Textures LOAD (VanillaBlit::Load succeeds, TGA decoded into 128px D3D7 tiles) but they do NOT
appear on the presented DX7 surface. The recomp draws textured quads (DrawScaled / DrawPrimitive)
but the result is the device's default near-white-blue surface, NOT the texture.
=> **IDirect3DDevice7::SetTexture (vtable 0x8c) is not binding the tile surfaces** (or the draw
targets the wrong surface / wrong texture stage). Same failure mode as the 3D white-render.
The (241,243,249) color = the untextured-quad default (vertex/material color modulated with no
texture = light fill).

## How the regression happened
VanillaBlit (the faithful port of the canonical 2D tiled blitter FUN_00433900, driving the D3D7
device) REPLACED the earlier GDI BitBlt 2D path. The GDI path produced visually-correct intros
(capdiff PASS) but was not the faithful renderer path. VanillaBlit IS the faithful path but its
texture binding doesn't reach the visible surface → white. Net: visual correctness was traded for
a faithful-but-broken path, with NO continuous verification catching the regression.

## Rule 11 lesson
"Build green ≠ faithful." The recomp built and ran fine while silently regressing intro rendering
from PASS to 0.51 FAIL. Continuous per-cycle capdiff (at least intro1) is required to catch this.

## Fix direction (next)
Make SetTexture@0x8c actually bind the D3D7 tile surface (IDirectDrawSurface7*) so textured quads
sample the texture. Verify the texture-stage COLOROP (SetTextureStageState@0x94 state 6 = MODULATE)
and that the draw targets the SAME surface the renderer Presents (+0xa8). Once textures bind,
2D intros/loading AND 3D should gain visible content together.
