# RUNTIME_TRACES — capture protocol (the parity oracle)

Status: ✅ harness operational (2026-10-14). First gameplay trace: see
`RuntimeLab/logs/traces/` + `runtime_hits_log.json` (gitignored except this doc and the
scripts).

## Environment (the hard-won part)

- The GOG `Giants.exe` **self-elevates** (requireAdministrator). A non-elevated x32dbg
  cannot spawn it (ERROR_ELEVATION_REQUIRED) nor attach to a running instance
  (access denied) — symptoms: `LoadBinary` answers "command sent" but state stays
  `NO_TARGET`, no Giants.exe process ever appears.
- **x32dbg MUST run elevated** (UAC click): `Start-Process x32dbg.exe -Verb RunAs`, then
  `LoadBinary filePath=G:/Games/Giants/Giants.exe` → PAUSED at ntdll system break.
- **Single-instance mutex**: launching a second instance shows "Giants already running
  or install in progress" — close/kill all Giants.exe first (`taskkill /F /IM Giants.exe`
  from an elevated console).
- Boot under the debugger trips ~15 first-chance pauses (DLL loads, threads) before the
  menu: send `run` in a loop until `GetDebugState` reports `RUNNING` stably (~2 min).
- Never patch the exe on disk. The CD-check memory stub (`boot_session.py`, vanilla
  copy) is not needed for the GOG build.
- Shell note: the agent's shell is sandboxed (cannot OpenProcess the game, cannot
  taskkill elevated processes). Everything process-level goes through the elevated
  x32dbg via the MCP HTTP bridge (`scripts/xdbg_call.py` → `127.0.0.1:9095`, token in
  `G:/Tools/x64dbg/release/x32/mcp_config.json`, NEVER committed).

## What is traced (P1.1 harness)

`ps2_symbols/p11_bps.txt` — 19 named, EVENT-frequency functions (per-frame functions
excluded on purpose: a BP hit costs ~0.5 s of pause+resume, per-frame BPs freeze the
game):

| function | address | why |
|---|---|---|
| `new_fire__FP6OBJECTiPfT0P3P3Df` | 0x00478AD0 / 0x0052E250 | weapon shots |
| `obj_impact_effects` | 0x00404D70 | impacts |
| `hurt_pusher_2` | 0x004FA520 | damage |
| `rpman_notify_hit` | 0x004E7AE0 | hit notification |
| `sound_play_obj` | 0x004954E0 | every sound event (id, obj) |
| `object_destroy` | 0x00497510 | every object death |
| `verm_ai_cb` | 0x00425850 | vermin AI spawn/food |
| `mecc_bubble_show` | 0x00475350 | speech bubbles |
| `bubble_timeout_clear` | 0x00536C60 | bubble lifecycle |
| `facing_player_bark` | 0x0049DBD0 | creature→player reactions |
| `smartie_target_filter` / `injured_target_scan` | 0x004D1840 / 0x004D1A00 | AI scans (excluded from hot set if laggy) |
| `mission_init` | 0x00492910 | mission start (wm_* interpreter) |
| `read_worlds_bin_fn_PS2` | 0x00490860 | wm file load |
| `scenario_list_load` | 0x00490C50 | scenario registration |
| `gti_terrain_load` | 0x00474440 | terrain load |
| `FLK_FlickProcess` | 0x00445A20 | cutscene VM tick (hot during cutscenes only) |
| `world_next_enter` | 0x004EE800 | world transitions |

## Capture loop

`scripts/runtime_capture.py <minutes> <bpfile>` (background):
polls `GetDebugState`; on PAUSE at a listed giants-module address it records
`{addr, t, args[esp+4..0x18], ret, stack[8]}` into `runtime_hits_log.json` (full JSONL-
style log, gitignored — metadata only) and resumes with `g`. 1 s dedup per address.

Companion milestone screenshots: window-DC BitBlt at known moments, stored in
`RuntimeLab/logs/traces/*.png` with their MD5 (below) — LOCAL ONLY (gitignored, game
imagery must not be published).

## Reproduce a session

```
1. elevated x32dbg + LoadBinary G:/Games/Giants/Giants.exe + run-loop to menu
2. (human tester) navigate: player ID → New Game → race → mission
3. python scripts/runtime_capture.py 30 ps2_symbols/p11_bps.txt   # background
4. play 2-3 min of target gameplay
5. stop sensor; mv runtime_hits_log.json RuntimeLab/logs/traces/hits_<name>.json
6. screenshots: RuntimeLab/logs/traces/*.png + md5sum
```

## Session log

| date | target | result |
|---|---|---|
| 2026-10-14 | GOG 1.449, pid 25488, menu reached under elevated x32dbg | harness armed (19 BPs), awaiting gameplay trace |
