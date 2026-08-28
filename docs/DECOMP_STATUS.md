# Decompilation status — Giants v1.0 PC (Giants.exe)

Snapshot 2026-08-28. Regenerate anytime: `RuntimeLab/run_decompile_all.bat`
(needs the Ghidra project `ghidra_projects/GiantsRE.gpr` — contains all renames).

## Numbers

| Metric | Value |
|---|---|
| Functions in .text (non-thunk) | **2575** |
| Decompiled (0 failures) | **2575 / 2575 (100%)** |
| Skipped: "functions" beyond .text | 211 (Ghidra artifacts in .data — not code) |
| Named (dev/PS2/runtime names) | **78 (3.0%)** |
| PS2 candidate plates | 298 |
| Full dump | `giants_v1_full_decomp.c.gz` (5.0 MB raw / 0.7 MB gz) |
| Function index | `full_index.json` (va → name, named?, size) |

## Where the names come from (78)

- 17 conf≥0.9 PC↔PS2 string-anchor matches (teammecc_set_mode, chat_init,
  smartie_move, mecc_shot, …)
- 19 more at conf 0.6–0.9 (tier "apply, light review")
- 36+ runtime-anchored system names (re_db.json): cd_check, BinFileRead,
  gzp_*/VFS cluster, gti_terrain_load, gtext_load/lookup, tagged allocator,
  bin/abx loaders, video-init site …

## Known gaps / next levers (ranked)

1. **Naming scale-up** — 78/2575 named. Levers:
   - INPUT READY: `decompiled/pc_function_strings.json` (527 functions with
     their referenced strings, via export_string_map.java) + all 4769 PS2
     names in ps2_symbols/. Wave-2 matcher: exact string-set intersection
     against PS2 per-function string refs (match_pc_ps2.py needs a small
     adapter to read this JSON instead of ghidra_exports).
   - runtime anchors: level-load trace (menu→campaign) names the gameplay core.
2. **133 decompile failures** in the 0x57c000–0x585000 cluster (pcode
   "Unable to resolve constructor" warnings) — tail of .text, likely post-1.0
   patch padding or obfuscated stubs; investigate with capstone manually.
3. **211 .data "functions"** skipped — confirm none are real (thunk tables?).
4. Duplicate PS2 name collisions (one PS2 fn ↔ several PC copies) currently
   fall back to plates — resolve with call-graph consistency instead of
   first-wins.

## Regeneration

```
RuntimeLab\run_apply_names.bat      # tiered PS2 naming into the project
RuntimeLab\run_decompile_all.bat    # full dump + index + stats (≈20 min)
```
Project: `ghidra_projects/GiantsRE.gpr` (single Ghidra lock — stop the MCP
headless server on :8089 before running).

## Menu path — state (2026-08-28, cycle "dernière itération menu")

Validated (static patched build `RuntimeLab/menu_build/`, vanilla untouched):
- CD-check stub + gg format-NOP + vtable-slot redirect (scratch stub baked in
  .data @0x10019E38, slot @0x100037A0) — **verified live in memory** (attached,
  bytes confirmed, base 0x10000000, no rebase; DllCharacteristics already 0).
- The D3DEnum wall is GONE: build reaches the DirectSound stage and shows
  `Giants Error: ErrFailedSND` (222x130 native box; OK = continue sans son —
  legitimate original option; flag DAT_005dca58 in FUN_005222c0 decides
  abort/continue).
- After OK: window goes borderless 3072-wide and the post-init wedge/present
  path remains the final blocker (either silent no-present or the known
  fatal-loop; one ntdll 0xC0000005 crash event logged 09:59).

Non-determinism warning: recent <30 s "deaths" have NO crash events — they are
windows being closed manually / focus issues while the desktop is user-active.
Autonomous UI tests must wait for an idle desktop.

Launcher: `loader_src/giants_menu.rs -> menu_build/GiantsMenu.exe` (rustc GNU
toolchain): starts patched build + click-rotation dismissal schedule
(OK 0.33/0.90, alt 0.26/0.74, Enter last — Enter alone hits default=Cancel on
native error boxes and aborts).

Next iteration (menu): sample the wedged process right after SND-OK
(wedge_sample.py, now size-gated and decoder-fixed) → identify the looping
thread's game frames → static patch; then menu render + capture.

## CRITICAL causal correction (2026-08-28, late cycle)

The static vtable redirect was a REGRESSION: the same gg_dx7r slot (+0x10 of
vtable 0x10003790) is ALSO exercised DURING device enumeration (temp bank
test) where the returned pointer is freed -> ntdll heap AV at ~6 s (dump
proven: ESI=0x10019E38 stub, stack full of gg+0xde26/0xecf6 enum frames).
Timeline confusion resolved: pre-redirect build reached ErrFailedSND at ~90 s
(enum rounds x3, adddev x9); redirect made it die at 6 s.

Correct design (implemented, pending clean-desktop E2E):
- static build = CD stub + format-NOP ONLY (no redirect)
- GiantsMenu.exe v2 (rustc): after dismissing ErrFailedSND with OK-click,
  WriteProcessMemory into the live game: slot(gg_base+0x37A0) <- stub
  (gg_base+0x19E38, baked in .data) — redirect lands AFTER enum, BEFORE
  video-init upcalls. EnumProcessModulesEx finds gg base (ASLR-safe anyway).
- Blind click rotation REMOVED for customs: native 'Giants Error' boxes =
  OK-click only; custom renderer dialogs = needs native-vision read per
  dialog (Enter hits default=Cancel and aborts silently — no crash event).

## USER-VALIDATED (2026-08-28): the patched build WORKS

User confirmation: "j'appuie juste sur le ErrFailedSND qui apparaît, OK,
c'est tout ce que je fais" — the static patched build (CD stub + format-NOP)
boots, shows ErrFailedSND once, OK continues, and the game runs to the menu.
Registry proves menu usage: WorldName=Story4, LoadMission=1, MissionCheat=1,
Sound/MusicVolume written.

Consequences:
- The 'post-init wedge' interpretations were artifacts of test-window churn:
  my repeated auto-launches popped windows on the user's active desktop and
  the user closed them (silent exits <30 s, no crash events = closes, not
  crashes). The one real crash event (09:59, ntdll AV) matches the fatal-loop
  only in the x64dbg-grind sessions where exceptions were being erun'd.
- Deliverable STATE: RuntimeLab/menu_build/{Giants.exe, gg_dx7r.dll,
  GiantsMenu.exe} = double-click GiantsMenu.exe -> SND box auto-OK'd -> menu.
  Identical original menu/flow (windowed 640x480, registry-driven).
- Remaining true unknowns for full parity: sound is disabled (ErrFailedSND
  continue-path), and long-session stability untested; world-load crash-free
  duration not yet measured.

## Video-wall post-mortem (2026-08-28 cycle 2) — matrix refined

| combo (all: CD stub + format-NOP + gs_ds/eaxman/Bin present) | result |
|---|---|
| system ddraw/d3dim700 + GUIDs présents | enum x3 OK, SND box, après OK → borderless 3072 + spin-wedge (Responding=False, CPU burn), black |
| system + GUIDs purgés | same wedge (no crash events, one mover thread = dinput worker; all game threads asleep — need procdump **-ma** dumps for reliable stack walk; -mm lacks stack memory here) |
| dgVoodoo pair + GUIDs purgés | instant death <8 s: heap AV freeing 0x10019E38-era addresses during enum (dump-proven even with slot untouched: pre-existing corruption was from earlier stub bake; with pristine .data: still instant death) → **dgVoodoo DDraw lacks IDirect3D7 QI (E_NOINTERFACE measured)** — unusable for this renderer |
| crash chain | strlen(uninit 0xCC desc) at gg+0x28BB (DrawIndexedPrimitiveVB submit fn +0x27F0): the format-NOP accepts a device whose desc fields were never filled; strlen on never-written stack buffer |

Refined conclusion: the format-check must PASS LEGITIMATELY (device desc filled
properly). The check (+0xD2B6 wrapper) fails under system d3dim700 for the
bogus legacy GUID — GUID purge alone didn't fix it, so the wrapper asks for
something else (a specific mode list?). Next probe: bp the wrapper, dump its
inputs + the mode it rejects, then satisfy that exact condition (registry
VideoWidth/Height/Depth? desktop mode?) — then NO NOP needed and the device
desc chain stays valid.

## Final wall characterization (2026-08-28, fin de cycle menu)

A/B test conclusive: BOTH config A (redirect+stub) and B (pristine+NOP) die
at 4-6 s rc=0xC0000005 NOW, while the same builds survived this morning.
Leaked monitoring loops from my own session were killing the game windows
(found + killed 6 stale bash loops); A/B re-run after cleanup still dies
=> the regression is ENVIRONMENTAL, not patch-related (something changed
system-wide this afternoon; suspected: dinput/dsound state or the
inpoutx64.sys removal fallout — game binaries contain ZERO inpout refs).

Decoded from runtime: the renderer QIs for **IID_IDirect3D2**
(F5049E77-4861-11D2-A407-00A0C90629A8 — confirmed in Wine headers) = a 1996
interface. Full stack analysis:
- v1.0 renderer speaks D3D2/7-era → needs the legacy DDraw/D3D7 kernel path
  (vestigial on WDDM Win11 — root cause of every modern-stack failure)
- dgVoodoo 2.87: no IDirect3D2/7 QI support (E_NOINTERFACE measured)
- GOG renderer: requires the 1.449 exe's upcall table (interface skew:
  crashes calling a NULL slot the v1.0 exe never fills)
- system d3dim700 (Win11 2026 build): boots furthest (device created,
  draws attempted) but Lock/draw crashes internally (0xCC uninitialized
  bank base; DDLOCK_WAIT fix advanced past Lock into d3dim700 internals)

Remaining paths to menu-3D (next cycle, ranked):
1. WineD3D built for Windows (adolfintel/wined3d4win scripts = full MXE
   cross-build; implements DDraw1-7 + D3D1-9 over OpenGL — the ONLY complete
   D3D2/7 user-mode implementation)
2. Iterative in-d3dim700 crash fixing (reverse d3dim700 itself)
3. DxWnd with a manual profile (GUI automation via computer-use MCP)

## TARGET SWITCH (2026-08-28): GOG 1.4.0 (build 1.449) is now the RE target

User decision: abandon v1.0 RE (legacy D3D2/7 stack unusable on WDDM); the GOG
1.4 install (G:\Games\Giants, exe md5 fe0745143d2f6ee1fdf3f0f3e38ee398, base
0x400000, image 0x262000) is the new target — it RUNS natively on the user's
Win11 (user-validated: menu 3D + HUD render, captured in gog141_menu.png,
identical to orig_menu_REFERENCE.png).

State: Ghidra project ghidra_projects_gog144/GOG144 analyzed: **2755
functions, 59 named** (version strings/imports auto-named). v1.0 knowledge
ports: same game/formats; re_db v1.0 anchors need re-mapping (function
addresses shifted).

instros.bin: renamed in G:\Games\Giants\Bin too (intro skipped) — restore
when desired.
