# Menu render spec (measured from vanilla Giants.exe + RE_docs/SCENE_SYSTEM.md)

After intros, the menu shows **3D scene + 2D GUI together** (not one then the other).

## 3D background
Loaded at boot **step 4** (`FUN_004f41c0` → `FUN_004b7af0("Intro")` →
`FUN_004b7c50("W\Intro.bin")`) — BEFORE the intros play. Persists through profile-select
→ main-menu. Contents:
- `intro_island` terrain (heightfield `intro_island.gti`, 115×142)
- water (`intro_sea.tga`), sky (`intro_sky.tga`)
- the giant 3D "GIANTS CITIZEN KABUTO" logo model (`xx_giants_logo_3d.gzp` →
  `xx_giants_logo_3d.gbs`)

## 2D GUI overlay
Loaded from `xx_menus.gzp` + `w_menus.gzp`, screen list in `xx_menus.bin`:
`mu_idselect` (Select Player ID), `mu_mpsel`, `mu_gnselect`, `mu_wdselect`, `efx_menu`,
custom cursor `cursor.tga`. Each menu screen has a `ref_camera1` entry → **camera is
driven by the menu screens**; the logo + camera translate together on a curve (the
"logo fixed while landscape scrolls" effect the user described).

## Transition intros → menu
No separate loading screen between them in the boot code. `FUN_00523b60` (intros)
returns → `FUN_004913c0` runs → kicks async load of intro_island. `giants_loading.tga`
shows only during that async load, then menu 3D scene + GUI appear.

## Recomp TODO (fidelity)
- The menu is not a "phase after loading" — the 3D scene is loaded at boot step 4 and
  persists. The recomp's linear BOOT state machine must reflect this.
- Currently the recomp shows only the projected heightfield (green→yellow diagnostic).
  Fidelity target: textured island + water + sky + 3D logo + 2D menu GUI overlay, with
  the camera driven by the menu screen's `ref_camera1`.

## Measured baseline (capdiff compare menu, 2026-06-17)
The original's first menu screen (post-intros) = **profile-select**: 3D "GIANTS CITIZEN
KABUTO" logo + red "Player" beam + French GUI ("Qui êtes-vous ?", "Entrer un nouveau nom
de joueur", "Sélectionnez ce nom...") over a dark cloudy sky. The island 3D scene is the
background beneath the GUI.
- **recomp (diagnostic terrain) vs original (profile-select) = mean_abs_delta 0.2992 → FAIL.**
- Target: < 0.04 (PASS). Gap = the whole scene chain (FUN_004913c0→FUN_0045a530→FUN_004b7c50→FUN_004f3230) + textured logo/sky + 2D GUI.
- Reliable original-menu capture = NATURAL intro playback (~42s, no SendInput/Frida — both destabilize the no-CD exe).
