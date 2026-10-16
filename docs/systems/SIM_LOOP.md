# SIM_LOOP — main loop, timing, RNG

Status: ✅ frame order + timing derived; RNG seeded NEVER (srand not imported — 2026-10-16); dt = real-time EMA (see Timing).

**Evidence:** `game_loop_run @ 0x00471A60` (source `C:\Giants\source\Main\…`), timing
`win95_frate_00518c60 @ 0x00518C60` (`win95/frate.c`), `FRateGetSecsframe @ 0x00518B70`,
`crt_rand_scaled @ 0x004D5730`. All **derived** from decomp; runtime tick-rate
confirmation pending P1.1 trace.

## Loop topology

`game_loop_run` is called from the two top-level state machines:
`dialog_level_process` (in-game dialog/pump level) and `main_menu_004832f0` (menu).
One call = one simulation tick + update sweep, in this exact order (**derived**, ordered
call sequence extracted from the function body):

```
fps_log_write
world_next_enter              -- world transition gate (see docs/formats/bin_objects.md)
comm_game_session_update      -- network session maintenance
object_init_usage
comm_msg_dispatch             -- network packets (docs: comm_msg_dispatch notes)
object_copy_posdirinfo
main_demo_004267a0
comm_game_session_update
input_mouse_world_check
kabutoai_select_target
obj_float_chase_update
weapon_id_inventory_update
match_start_big
teammecc_leader_tick
teammecc_enemies_helper
cleaner_go_obj
piranha_go
comm_stats_reset
win95_frate_00518c60          -- frame-rate bookkeeping (expired-timer list cleanup)
obj_velocity_commit           -- integrate velocities into positions
objspec_dispatch_gate         -- per-class update dispatch (field-2 table, see below)
object_animate_process
object_apply_location
object_spawn_class3
mecc_logic
owner_squad_process
object_lock_with_volume
PROJ_ObjectFinalize
process_wound
particles_decay_update
game_timerlist_update         -- DAT_59CDA4 timer list (dt-driven sub-timers)
fx_process
sound_checked_big
ANM_DumpCluster               -- anim cluster dumps/debug
comm_heartbeat_send
dlog_objname_menu
object_list_update
objlist_flag_partition        -- DAT_632DA8 -> DAT_632DAC by flag (see objlist_flag_partition)
mission_check_obj_proximity
flk_actor_update              -- cutscene actor interpolation
comm_voice_update             -- voice chat (docs/systems/MISSION_VM.md: comm_voice_update notes)
```

Key invariant for a reimplementation: **velocity integration (`obj_velocity_commit`)
happens BEFORE the per-class AI dispatch (`objspec_dispatch_gate`), and positions are
applied (`object_apply_location`) after animation but before projectiles finalize.**
The per-class dispatch is the class-spec table at `0x55CB00` (BSS, field 2 = main
update) via `cspec_update_dispatch @ 0x0049A090` — 107 classes, see
`cspec_update_dispatch`/`cspec_attack_tick_dispatch`/`cspec_field17_dispatch`.

## Timing

- `FRateGetSecsframe(obj, x)` (`0x00518B70`) = the universal per-frame `dt`:
  `dt = DAT_006328E0 * slow_zone_multiplier(obj)`. The slow-zone list (`DAT_005DCFA8`)
  holds radius + team-checked circles that scale dt (bullet-time zones).
  **Every system must advance by this dt or it desyncs with slow zones.**
- `win95_frate_00518c60` trims expired entries from the same zone list
  (`win95/frate.c`).
- Frame-rate target: **derived — pending trace** (expected 30 fps lock; confirm via
  `fps_log_write` cadence in the P1.1 trace).

## RNG — CLOSED 2026-10-16 (worker pass)

- `_rand @ 0x00543DD4` = MSVC CRT LCG, **per-thread** state at `__getptd()+0x14`:
  `seed = seed*0x343FD + 0x269EC3 ; return (seed>>16) & 0x7FFF` (corpus l.191779+,
  VS2003-2008 signature per Ghidra lib match).
- **The game NEVER seeds it**: `srand` is absent from the PE import table
  (byte-scan of imports: only time fns — GetSystemTimeAsFileTime/GetTickCount/
  timeGetTime) and from the corpus. → the RNG sequence is IDENTICAL every run
  (determinism for free; the initial seed is the CRT default, 0-or-1 per ptd
  init — for parity, port the LCG and match the first outputs empirically).
- Helpers: `crt_rand_scaled(n) = rand()*n >> 15` (@0x4D5730, PS2 `rndint`),
  `rndintrange(a,b)`, `rndfloat(x) = rand()*x*(1/32768)` (@0x4D5760),
  `rndfloatrange` (@0x4D5780).

## Timing — dt pipeline decoded 2026-10-16 (`time_frame_update @ 0x00518950`)

Clock = `timeGetTime()` (WINMM ms; `timeBeginPeriod` imported). Per frame:

1. raw dt = (now − last) × 0.001 s (branch replay/dedicated: `+0x32` ms fixed,
   `DAT_00632d5c/60` gates).
2. Smoothing: first 6 frames prime `_DAT_006328e4`; then EMA
   `_DAT_006328e4 = ema·α + (1−α)·dt` with α stepping +0.15 to 0.75.
3. `DAT_006328e0 (GLOBAL dt) = DAT_006328f0 (time_scale) × ema`.
4. Command-line modes (globals DAT_00633xxx):
   - `DAT_00633130` → dt fixed **0.025 (1/40 s)**;
   - `DAT_0063312c` → dt × 0.1 in frame_update (× 10 in `time_get_ms` init —
     dual use, flag semantics to disambiguate);
   - default clamp: dt > 0.25 → 0.25 (outside modes);
   - **`DAT_00633248` → dt FORCED 0.016666668 (1/60)** — the gamegauge-mode gate
     (matches every cinematic measurement).
5. Defaults at init (`time_get_ms @ 0x00518890`): dt = 0.025 (1/40 s nominal).

**Answer to the tick-rate open item**: there is NO fixed tick outside the
command-line modes — gameplay runs on the smoothed real-time dt (nominal seed
0.025 s = 40 fps expectation, clamp 0.25 s, EMA-smoothed). Fixed-step ports
should drive 1/40 s by default and 1/60 s under the gamegauge flag.

settings under HKLM/HKCU). Full save-structure decode = open item (P2 track).

## Validation

- P1.1 trace hooks `game_loop_run`-adjacent mid-frequency functions; the frame ORDER
  above can be confirmed by relative hit ordering within one tick.
- `fps_log_write` exists — the game has a built-in fps logger; find its file output
  in the install dir after a trace session.
