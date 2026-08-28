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
