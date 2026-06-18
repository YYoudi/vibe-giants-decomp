# Asset-load-by-name sequence — RUNTIME OBSERVATION (original Giants_nocd.exe)

**Source**: `scripts/frida_vfsopen.js` + `frida_vfsopen_run.py` — hooks `FUN_00539e30` (vanilla VFS
open-by-name @ 0x539e30) on the ORIGINAL game. Raw log: `orig_vfsopen.txt`.
**Captured**: 2026-06-19 (40s run through intros into the menu). RUNTIME OBSERVATION (rule 5).

`FUN_00539e30(char* name)`: looks `name` up in the GZP index (`FUN_0053b280(DAT_005e12b4, name)`),
builds the full path (prefix by index-entry type byte), opens via `FUN_0051d6f0`. Returns 0 on miss.
Hooking it logs **every asset the engine opens by name** — the definitive asset-load observation
(CreateFile can't, because assets are read via fseek/fread on already-open .gzp handles).

## GROUND TRUTH — what the original loads, and when

### Boot (t = 0.07s → 0.75s)
```
GameObj.bin → GData.gbn → worldlist.bin (+ worldlist2..5 MISS) → W_Intro.bin
→ xx_intro.bin → xx_menus.bin → (W_Intro.abx MISS) → weapondefs.bin
→ [0.56s] GTextEnglish.bin → [0.75s] intros.bin
```
The world/manifest + localized text + intros list load ONCE at boot, before anything renders.

### Intros (t = 0.75s → ~38s)
**NO new asset opens.** Intros play entirely from already-loaded data (intros.bin + indexed gzps).
~37s of intro playback (multiple intros, ~12s hold each per intro_timings spec).

### Menu scene load (t = 38.25s → 38.55s) — the moment intros end
```
W_intro_island.bin          ← the 3D island WORLD (terrain scene)
fx_world_dust.bin
tx_lev1.bin                 ← terrain texture bank ref
xx_effects.bin, xx_efx.bin
xx_permanentaliens.bin
xx_markers.bin
xx_menus.bin                ← menu objects
xx_tools.bin
xx_giants_logo_3d.bin       ← THE 3D GIANTS LOGO (spinning model)
W_intro_island.abx          ← island audio
wm_mission1.bin
flk_intro_island_1.bin, flk_intro_island_2.bin   ← FLICK cinematics for the island
```

## DEFINITIVE ANSWERS (kills the drift)

1. **`Giants_logo_512.tga` is NEVER opened by name.** Confirmed by runtime hook — it was a GZP-index
   guess, pure DRIFT. Any recomp code that loads/displays it is WRONG (rule 11 → replace).
2. **The menu's 3D logo is a MODEL**: `xx_giants_logo_3d.bin` → assets in `xx_giants_logo_3d.gzp`.
   It is rendered as 3D geometry, NOT a 2D blitted texture.
3. **The menu's 3D scene = `W_intro_island.bin`** (the island) + the 3D logo + menu objects
   (`xx_menus.bin`). This is the SAME island world as the intro — the menu renders the intro island
   with the 3D logo composited on top.
4. **Menu content loads at ~38s**, AFTER ~37s of intros. The recomp's `-skip-intros` must jump
   straight to this scene-load point, not invent a separate menu phase.

## What this means for the recomp (rule 11 — replace, don't preserve)
- The recomp's `VanillaBlit` Giants_logo_512 path = DRIFT. Delete.
- The recomp must drive the **same scene-load sequence** at menu time:
  `W_intro_island.bin` (world) → `xx_giants_logo_3d.bin` (3D logo model) → `xx_menus.bin` (objects).
- The 3D logo is geometry from `xx_giants_logo_3d.gzp` — load via the GBS/model path, render through
  the proven D3D7 3D pipeline ([[d3d7-3d-pipeline-works]]).
- `VanillaVFSCallbacks.cpp` cites 1.5 addresses (0x621f33 etc.) — CONTAMINATED, do not trust (rule 11).
  The real vanilla open-by-name is `FUN_00539e30` (this function).

## Hook details (reusable)
- Address: module_base + (0x539e30 - 0x400000). ImageBase = 0x400000. Base confirmed 0x400000.
- Signature: `undefined4 FUN_00539e30(char* name)` — cdecl, name in arg[0], returns handle or 0.
