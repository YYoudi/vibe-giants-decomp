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

## Bridge attempts (both FAILED — 2026-06-19)
1. SetRenderTarget(device, obj+0x28c) → 0x80004001 (E_NOTIMPL/DDERR_INVALIDSURFACETYPE).
   obj+0x28c is not RT-eligible; cannot repoint the device RT to the presented surface.
2. Lock(obj+0x28c) via surface vtable slot 0x64 → hr=0x0 but lpSurface=0/pitch=0/w=0/h=0.
   obj+0x28c is not a lockable IDirectDrawSurface7 (slot 0x64 isn't its Lock, or it's not a
   surface). Direct CPU blit to the presented surface is not viable either.
## Texture pipeline is HEALTHY (confirmed)
CreateTexSurf: CreateSurface OK, Lock hr=0x0 (lpSurface valid, lPitch=512=128*4, pixels copied).
DrawScaled: SetTexture@0x8c hr=0x0, DrawPrimitive@0x64 hr=0x0, fade alpha ramps 0x27→0xff.
The texture is created, populated, bound, and drawn — all S_OK. The ONLY break is the device-RT
vs presented-surface mismatch. => Device-direct rendering cannot reach the screen in this renderer.
The faithful scene-population + renderer-draw-submission chain (callback[7]/+0xb4/+0x7370) is the
only path to visible output.

## Frame-recipe clarification (2026-06-19, Frida on original)
- **Intros render via DEVICE draws, NOT renderer front-table methods.** frida_intro_recipe.js hooked
  renderer+0x8c/+0x90/+0x98/+0x9c/+0xa0/+0xa8 during intros (boot, no clicks) — NONE fired during
  the intro phase. So intros (and the menu 2D overlay) drive the D3D7 device directly (SetTexture/
  DrawPrimitive), same as observed. The recomp's VanillaBlit device-direct approach is correct in
  PRINCIPLE.
- **Present = renderer+0xa8 confirmed** (frida_present_path.js: fires at ~12.8s during intro2).
  GetRenderTarget is NOT called per-frame by the original (can't observe device-RT passively).
- The canonical frame order (DX7_METHOD_MAP): (+0x8c PushVP/SetRT) → (+0x98 Clear) → (+0x90
  BeginScene) → (+0x9c 2D Blt) → (+0xa8 Present). +0x8c MUST precede BeginScene.
- **+0x8c (PushViewport/SetRenderTarget) is the missing RT bind.** The recomp never calls it →
  device-RT stays != presented surface. Attempting (+0x8c)(obj, presented, 0) AFTER BeginScene
  CRASHED (ordering violation — +0x8c must be before BeginScene, and the correct surface+flags are
  unknown). SetRenderTarget(device,obj+0x28c) rejected; obj+0x28c not lockable.
- NEXT: call renderer+0x8c BEFORE BeginScene with the correct surface (the device backbuffer, or
  the surface Present flips) to bind the RT so device draws reach the presented surface. Requires
  observing the original's +0x8c call at INIT (before t=2s) to capture surf+flags args.

## +0xa8 Present-with-source discovery (2026-06-19, Frida init recipe)
The canonical intro frame on the ORIGINAL is:
  (+0x98 Clear) → (+0x90 BeginScene) → (+0x94 EndScene) → (+0xa8 Present)
where **+0xa8 Present = (this, srcW, srcH, fade, srcSurface)** — OBSERVED args:
  obj, 0x640(=1600=srcW), 0x4b0(=1200=srcH), fade(1.0→0.95→...), srcSurface(0xf8e7510)
=> the renderer BLITS the source surface (intro TGA dims 1600x1200) with fade + presents
INTERNALLY. The recomp calls m_a8(obj) with NO source -> renders nothing/white. THIS is a real
bug: the recomp invokes Present wrong (missing srcW/srcH/fade/srcSurface).
- +0x8c (PushVP/SetRT) is NEVER called by the original (disproven RT-bind hypothesis).
- +0xd8 (CreateTexture) is NEVER called either -> the srcSurface handle (0xf8e7510) is created by
  a different mechanism, and released by +0xb4 ReleaseTexture (lifecycle: ?create / +0xb4 release).
- TESTED passing a raw D3D7 tile surface (VanillaBlit::FirstSurface) to +0xa8(obj,640,480,1.0,surf)
  -> STILL WHITE. The renderer does not accept a raw IDirectDrawSurface7; the source must be a
  renderer-MANAGED texture handle (created via the unknown method, same type as 0xf8e7510).
- REMAINING: identify how the original creates the renderer-managed source handle (the texture
  passed to +0xa8). Likely a renderer method not yet mapped, or callback[?] (engine TextureLoader).
  Once known: create loading/intro source via that method, pass to +0xa8 -> visible 2D.

## +0xa8 raw-surface test result (2026-06-19)
+0xa8(obj, srcW, srcH, fade, srcSurface) ACCEPTS a raw IDirectDrawSurface7 and blits it at NATIVE
size. Verified: passing a 128px tile surface with dims (128,128) drew that tile top-left (black
count +~6000). But a full 640x480 surface with dims (640,480) did NOT fill the screen (center
stayed white, no green portrait pixels) — single large textures exceed DX7 texture-size limits and
the renderer composites TILED images via its MANAGED source format internally (the 0xf8e7510 handle
is a renderer-managed tiled-image object, not a single texture). +0xa8 takes no position arg, so it
cannot composite a tile grid itself. CONCLUSION: full-screen 2D via +0xa8 requires the renderer's
MANAGED tiled-source format (creation method unknown — not +0xd8, not a raw surface). The recomp's
m_a8(obj) bare-Present call is confirmed wrong (missing srcW/srcH/fade/srcSurface).
