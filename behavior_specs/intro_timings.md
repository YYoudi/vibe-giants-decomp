# Intro timings spec (measured from vanilla Giants.exe FUN_00523b60)

Source: `vanilla_decompiled/00523b60.json` (intro player, 1353 bytes) + `.data` float
globals (VA − 0x400000 = file offset). The recomp currently uses INVENTED timings
(600ms fade / 3000ms hold) — these are the REAL values.

## Intro list (data-driven, NOT hardcoded)
`GameFiles-VanillaV1/Bin/intros.bin` is a 29-byte plaintext file:
```
dmlarge000
planetmoon
legal
```
`FUN_00523b60` reads this file line-by-line. The recomp must read `intros.bin`, not
hardcode the 3 names. Exactly 3 intros.

## Real timings (decoded `.data` floats)

| Global VA    | Hex bytes   | Float | Role |
|--------------|-------------|-------|------|
| DAT_00552344 | 0ad7233c    | 0.01  | per-frame tick gate (advances fade every 10 ms) |
| DAT_00552300 | cdcc4c3e    | **0.20** | fade duration (seconds) |
| DAT_00552358 | 0000a040    | 5.0   | fade rate (1/duration; 0.2 × 5.0 = full sweep) |
| DAT_005522b8 | 00004041    | **12.0** | HOLD at full alpha (seconds) |
| DAT_005522c0 | 0000803f    | 1.0   | start alpha (fully opaque) |

**Each intro: fade-IN 0.2 s → HOLD 12 s → fade-OUT 0.2 s.** Linear alpha
(`fVar2 = 1.0 - (now-start)*5.0`). Skippable on any input (mouse button / keyboard edge
flags `DAT_00631108/0b/0e/04[3]`).

## Render path (NOT FLICK)
Driven via renderer method-table slots: `(DAT_00654940+0x98)(renderer,0)` = BeginScene/Clear,
`FUN_004551d0`/`FUN_004338d0(x,y,alpha,h)`/`FUN_00455280` (camera + draw the intro quad with
alpha), `(DAT_00654940+0xa8)(renderer)` = EndScene/Present. `flk_intro_island_*.bin` are
IN-LEVEL cutscene scripts, unrelated to the 3 splash images.

## Assets
- `dmlarge000.tga` (1600×1200 32bpp) → `Bin/xx_intro.gzp`
- `planetmoon.tga` (1600×1200 24bpp) → `Bin/xx_intro.gzp`
- `legal.tga`/`legalFrench.tga` → `VO_SfxFrench.gzp` (locale-dependent)

## Recomp TODO (fidelity)
- Replace invented 600/3000/600 with 200/12000/200 ms.
- Read `intros.bin` instead of hardcoding.
- Alpha must be linear and applied to the rendered quad (not a GDI pixel-multiply hack).
- CONFIRM dynamically: Frida-capture the original's intro1 fade ramp timestamp.
