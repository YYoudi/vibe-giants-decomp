# Menu capdiff delta breakdown (MEASURED, valid reference)

Measured 2026-06-18 against the verified reference `reference_screens/orig_menu_REFERENCE.png`
(recomp 800x600, reference 1936x1119 resized to match). Overall mean_abs_delta = **0.1208**
(target PASS < 0.04). Per-horizontal-band mean delta (0-255):

| Band | y range | mean_delta | dominant content (reference) |
|------|---------|-----------|------------------------------|
| 0 | 0-60 (TOP) | **73.2** | GUI text "Qui êtes-vous ?" + "Player" (white/red) — **recomp renders NOTHING** |
| 1 | 60-120 | 39.8 | logo upper (chrome) — recomp sparse gold lines |
| 2 | 120-180 | 38.7 | logo upper |
| 3 | 180-240 | 25.3 | logo center |
| 4 | 240-300 | 21.4 | sky / logo mid |
| 5 | 300-360 | 22.9 | sky / logo mid |
| 6 | 360-420 | 19.2 | sky (DARK — already close) |
| 7 | 420-480 | 21.4 | sky / logo lower |
| 8 | 480-540 | 25.4 | bottom help text |
| 9 | 540-600 | 26.3 | bottom help text "Entrer un nouveau nom..." |

## Where the delta is (ranked)
1. **TOP GUI text (band 0, ~73)** — single biggest contributor. "Qui êtes-vous ?" + "Player".
   Recomp renders no text here.
2. **Logo (bands 1-3, ~35-40)** — recomp draws sparse gold wireframe lines; reference is a
   SOLID bright chrome 3D logo (wide+short extruded "GIANTS" shape).
3. **Bottom help text (bands 8-9, ~26)** — "Entrer un nouveau nom de joueur" / "Sélectionnez...".
4. **Sky (bands 4-7, ~20)** — already close (dark blue-gray). Clear color 0xFF31243b.

## Implications (next work, biggest delta first)
- **GUI text** is the #1 lever. Requires the renderer's DrawText path (callback[11]
  GetLocalizedString → renderer text method). The top "Qui êtes-vous ?"/"Player" + bottom
  help lines. Measuring exact font/size/position/color is the measure-before-code step.
- **Solid chrome logo**: the xx_giants_logo_3d.gbs mesh (1337 verts) currently renders as
  sparse gold TRIANGLELIST lines (projection makes the flat-in-Y mesh render thin; needs
  solid fill + the chrome texture + depth handling).
- Sky/terrain: terrain is the INTRO cinematic, correctly removed from the menu. Sky clear
  is close; a textured sky quad (one of the original's 130 quads) is a minor refinement.

## What was tried this cycle
- Reframed menu: cleared dark sky (0xFF31243b), REMOVED the wrong-content island terrain.
  Delta barely moved (0.1205→0.1208) — terrain wasn't the issue; the gap is text+logo.
  The reframe is still CORRECT (terrain = intro, not menu) — it shifts the problem to the
  real remaining content.
