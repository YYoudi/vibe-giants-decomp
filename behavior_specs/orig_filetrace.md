# Boot file-open sequence — RUNTIME OBSERVATION (original Giants_nocd.exe)

**Source**: `scripts/frida_filetrace.js` + `frida_filetrace_run.py` — hooks `CreateFileA`/`CreateFileW`
(kernel32) on the ORIGINAL vanilla game (`Giants_nocd.exe -window`). Raw log: `orig_filetrace.txt`.
**Captured**: 2026-06-19. This is RUNTIME OBSERVATION (rule 5), not static code reading.

## What this proves (ground truth, no guessing)

### Phase 1 — VFS index build (t = 0.026s → 0.099s)
At boot, the game opens **EVERY `.gzp` archive** to build the VFS index, in alphabetical order.
All under `Bin\` (relative to exe):
- `aablood, aanoeng, extra, sfxlev1, tx_lev1` (engine core: textures/sfx/font)
- `w_intro_island, w_Kstory1..5, w_menus, w_M_*, w_Rstory*, w_Story1..5, w_the_end` (worlds)
- `xx_*` (object/character banks: ~70 files — birds, effects, giants_logo_3d, menus, smarties...)
- **Patch gzps from registry AppPath** (`G:\Games\Giants\Bin\`): `arpfix.gzp, VO_SfxEnglish.gzp,
  xx_patch_screens.gzp` ← loaded from a SECOND path configured in registry, not the exe dir.

Then immediately: **`Bin\GameObj.bin`** (0.099s), **`Bin\WorldList.bin`** (0.100s) — object + world
manifests read loose (not in a gzp).

### Phase 2 — DirectInput init (t = 0.7s → 0.79s)
Enumerates HID devices (`\\?\hid#vid_*&pid_*...#{4d1e55b2-...}` GUID) — keyboard/mouse/controller
probing. Opens `Giants_nocd.exe` itself repeatedly (module/resource reads).

### Phase 3 — intros begin (t = 0.789s)
**`Bin\intros.bin`** opened (0.789s). From here intros play.

### KEY FINDING — after index, NO per-asset CreateFile
Once all `.gzp` handles are open (0.099s) and `intros.bin` is read (0.789s), **no further file
opens appear via CreateFile**. All subsequent asset reads (textures, models, sounds) happen via
the engine's **VFS open-by-name** → `fseek`/`fread` on the already-open `.gzp` handles.

**Implication**: CreateFileA/W observation CANNOT prove "is Giants_logo_512.tga loaded at the menu".
To prove per-asset loads, the **VFS open-by-name function** must be hooked (engine-side, not the
OS file API). That is the next observation layer (todo).

## What this means for the recomp (rule 11 — no prior code is sacred)
The recomp's boot does NOT replicate this sequence. To be faithful, the recomp must, at boot:
1. Open & index every `.gzp` under `Bin\` (+ registry-AppPath patch gzps) — build the same VFS index.
2. Read `GameObj.bin` then `WorldList.bin` (loose manifests).
3. Init DirectInput (HID enum).
4. Read `intros.bin` and play intros from indexed assets.

Any recomp boot that does not open the same `.gzp` set in the same order is NOT faithful — replace it.

## Todo (next observation layer)
- Hook the engine **VFS open-by-name** function (vanilla addr TBD from decompile) to log every
  per-asset name the original requests, with timestamps — proves the asset-display question.
- Hook proxy_dx7 callback[17] (renderer's VFSOpenFile) for renderer-requested textures.
