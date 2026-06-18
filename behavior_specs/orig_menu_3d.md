# Original 3D menu — RUNTIME-OBSERVED visual ground truth (first player-ID / profile-select state)

**Source**: `scripts/frida_menu_observe.py` — spawns the ORIGINAL (`Giants_nocd.exe -window`), hooks
VFS open-by-name (`FUN_00539e30`), waits for the menu scene-load signal (`W_intro_island.bin`),
then `ImageGrab` the window client (640x480). Capture: `orig_menu_3d.png` (+ `orig_menu_3d_view.png`
cropped to client). VFS log: `orig_vfsopen_menu.txt`.
**Captured**: 2026-06-19. RUNTIME OBSERVATION (rule 5), confirmed by image analysis.

## The FIRST menu state the original shows (player-ID / profile select)

This is what appears right after intros end (~18–38s, asset-load burst below). It is a
**dark sky + 3D logo + 2D text** screen — the profile / player-ID select.

### Visual elements (exactly, from the capture)
1. **Background = dark atmospheric sky.** Black + deep blue/purple, misty/cloudy, with a lighter
   grayish-white glow around the center (where the logo sits). NOT terrain, NOT a flat color.
2. **3D logo (center, large)** = the metallic **"GIANTS" / "CITIZEN KABUTO"** logo, curved, rendered
   in **metallic blue/teal**, reflective/polished highlights+shadows. This is the
   `xx_giants_logo_3d.bin` MODEL rendered through the D3D7 3D pipeline — NOT a 2D blitted texture.
3. **2D menu text (white, bitmap font):**
   - Top center: **"Select Player ID"**
   - Bottom center: **"Enter New ID"**
   - Very bottom: **"Select this ID or press the Delete key to remove it"**

### Asset-load burst at the menu moment (VFS open-by-name, t≈18–38s)
```
W_intro_island.bin  fx_world_dust.bin  tx_lev1.bin  xx_effects.bin  xx_efx.bin
xx_permanentaliens.bin  xx_markers.bin  xx_menus.bin  xx_tools.bin
xx_giants_logo_3d.bin   ← THE 3D logo model
W_intro_island.abx  wm_mission1.bin  flk_intro_island_1.bin  flk_intro_island_2.bin
```
The island world (`W_intro_island.bin`) IS loaded but the camera/framing in this first state shows
the **dark sky + 3D logo** (the island is likely behind/below or the logo shot is a FLICK
cinematic frame from `flk_intro_island_*.bin`).

## What this means for the recomp (rule 11 — replace, don't preserve)
- The recomp's current menu renders **green/yellow diagnostic terrain** → WRONG for this state.
  This first menu state = **dark sky + metallic 3D GIANTS logo + white profile-select text**.
- **Giants_logo_512.tga is never used** — confirmed again visually (the logo is the 3D model
  `xx_giants_logo_3d`, not a 2D texture). Delete the VanillaBlit Giants_logo_512 path.
- Faithful menu render order for THIS state:
  1. Clear to dark sky (deep blue/purple, +central glow).
  2. Render the `xx_giants_logo_3d` model through the proven D3D7 3D pipeline
     ([[d3d7-3d-pipeline-works]]) — metallic blue/teal, centered.
  3. Draw white bitmap-font text: "Select Player ID" (top), "Enter New ID" (bottom),
     "Select this ID or press the Delete key to remove it" (very bottom).
- The `flk_intro_island_1/2.bin` FLICK cinematics likely drive the logo framing/animation — port the
  FLICK interpreter path for the menu logo shot.

## Repro harness
`python scripts/frida_menu_observe.py [secs_after]` — spawn + hook + wait-for-menu-signal +
ImageGrab. Note: the 4 SendInput clicks only PARTIALLY skip intros (menu arrived at ~18s in one run,
~38s in others) because DirectInput8 ignores synthesized mouse — a physical click or a Frida
intro-skip flag (force-write the skip DAT) would be faster. The menu-load SIGNAL
(`W_intro_island.bin` in the VFS log) is the reliable "menu is up" marker regardless of skip.
