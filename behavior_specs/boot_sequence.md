# Boot sequence spec (measured from vanilla Giants.exe FUN_005222c0)

Source: `vanilla_decompiled/005222c0.json` (WinMain, 2339 bytes). Confirmed by
static RE (agent 2026-06-17). TODO: confirm dynamically with Frida timestamp capture
(`scripts/frida_capture_boot.js`, C3).

## Exact boot order (FUN_005222c0, WinMain)
1. `CreateMutexA("Giants_CK")` + launch `reg32.exe FALSE` (CD/registry check)
2. `RegisterClassA("Example", wndproc=0x523470)` + `CreateWindowExA("Giants", style=0x6cf0000)`
3. `FUN_00505d20(hWnd)` — DInput/window setup
4. **`FUN_004f41c0()`** — scene bootstrap: reset entity/texture lists, `FUN_004b77f0` (reads `worldlist.bin` → 31-level table `DAT_00631388`), `FUN_004b7af0("Intro")` → `FUN_004b7c50("W\Intro.bin",1.0,0)` (**loads the menu 3D scene BEFORE intros**)
5. `FUN_0051eb70` — load `gg_dx7r.dll`, resolve `GDVSysCreate`/`UpCallsLoad`, install 21 callbacks
6. `GDVSysCreate` (7-param) → `DAT_00654940` (global renderer)
7. `FUN_0051f900` — InitAudioSystem (`gs_ds.dll`)
8. `FUN_0051f8a0("DefPlayer")` — registry default player
9. `FUN_00483740` — load default player state
10. `FUN_004290f0(DAT_005dcb60)` — enable scene-pipeline gate `DAT_0058c15c`
11. `FUN_0051ede0(cmdLine)` — DirectInput + cmd-line/replay parse
12. `FUN_0051f8a0` again (music/sound volume)
13. **`FUN_00523b60("intros.bin")`** — play the 3 intros (see `intro_timings.md`)
14. **`FUN_004913c0()`** — select intro_island + kick async load (shows `giants_loading.tga` via `FUN_0045a530`, see `loading_screen.md`) → enters menu/message loop
15. Win32 message loop. Per active frame: `FUN_0051e7c0` (UpdateTime) → input poll → `FUN_004742f0` (network) → renderer method `(DAT_00654940+0x20)(renderer, frameState)`.

## Key consequence for the recomp
- The **menu 3D scene is loaded at step 4, before intros** (not a phase after). The recomp's
  "BOOT_INTRO → BOOT_LOADING → BOOT_MENU" linear state machine is WRONG structurally: there is
  no separate loading phase between intros and menu in the boot code. `giants_loading.tga` shows
  only during the async load `FUN_004913c0`→`FUN_0045a530` kicks off.
- **There is NO "LOAD ISLAND" screen.** (See `loading_screen.md`.)
