# RECOMP WHITE-RENDER ROOT CAUSE — draws succeed but target a NON-PRESENTED surface (2026-06-19)

## Verified facts (HRESULT logging in VanillaBlit::DrawScaled)
giants_loading.tga, tile0, during fade-in:
  hrSetTex (SetTexture@0x8c)   = 0x0  (S_OK)  ← texture BOUND successfully
  hrDrawPrim (DrawPrimitive@0x64) = 0x0  (S_OK)  ← quad DRAWN successfully
  surf = 0x0eefbf30 (valid IDirectDrawSurface7*)
  diff alpha ramps 0x27→0xff (fade-in correct)
=> SetTexture is NOT broken. The textured quad draws SUCCEED. Yet the visible frame is white.

## TRUE root cause (unifies 2D + 3D white-render)
The D3D7 device draws (SetTexture/DrawPrimitive via the wrapper@obj+0x294) render to the DEVICE's
current render target. But the renderer's Present method (obj+0xa8) presents a DIFFERENT surface
(obj+0x28c, the renderer's internal managed surface). So the device draws NEVER reach the surface
that gets flipped to screen → the frame shows the presented surface's default (white/near-white-blue
RGB 241,243,249). Confirmed by VanillaTestSurfaceVisible (device-RT vs obj+0x28c mismatch).
This is why intros (0.0006→0.5139), loading, AND 3D all render white: one surface-mismatch root cause.

## Why GDI intros USED to pass
The earlier GDI BitBlt path drew directly to the presented surface via GetDC (the right surface),
so intros rendered correctly (capdiff PASS). VanillaBlit (faithful D3D port) draws to the device RT
(wrong surface) → white. Visual correctness was traded for a faithful-but-mis-targeted path.

## Fix direction (next)
Make the device draws land on the presented surface. Options:
 (a) Set the device render target to obj+0x28c (SetRenderTarget@device-vtable) before the texture
     draws, so SetTexture/DrawPrimitive write to the surface the renderer Presents.
 (b) Discover which surface the renderer's m90/m94 bracket targets and draw there.
 (c) Have the renderer's OWN per-frame (+0x7370) do the draws (it targets the right surface
     internally) — requires the faithful scene-population chain.
 (a) is the smallest verifiable fix: if the device RT = obj+0x28c, the loading texture should
 appear → intro1/loading capdiff should recover toward PASS.

## Lesson (Rule 11)
The recomp built+ran fine while silently rendering white everywhere. Continuous per-cycle capdiff
(≥ intro1) is mandatory to catch render regressions.

## CONFIRMED (2026-06-19, RTDIAG in VanillaRenderer loading-draw)
After the renderer's m90 (BeginScene+Clear), the D3D7 device's current render target is NOT the
surface the renderer Presents:
  device GetRenderTarget = 0x0c47ab90   (where SetTexture/DrawPrimitive draws land)
  obj+0x28c              = 0x0c47ab70   (surface the renderer's m_a8 Present flips) — 0x20 bytes
                                        apart (a back/front-buffer pair or distinct surfaces)
  match = 0 (different)
=> device draws go to 0x0c47ab90; the presented surface 0x0c47ab70 is never drawn to → white frame.
Forcing SetRenderTarget(device, obj+0x28c) is REJECTED (0x80004001 DDERR_INVALIDSURFACETYPE) —
obj+0x28c is not RT-eligible. So the fix is NOT "repoint the device RT".
## Real fix path
The device-direct draw approach (VanillaBlit calling device SetTexture/DrawPrimitive) cannot reach
the renderer's presented surface. The original submits draws through the RENDERER's own path
(callback[7] SceneBegin/DrawTerrain, method +0xb4 entity/texture thunk, +0x7370 scene-walk) which
targets the correct surface internally (DrawIndexedPrimitiveStrided — the observed real path). The
faithful scene-population + renderer-draw-submission chain is required; device-direct draws are a
dead end for visible output.
