# AI — factions, classes, perception, movement

Status: 🔶 class architecture + key loops mapped; per-class behavior trees pending.

**Evidence:** class-spec table `0x55CB00` (BSS, 107 classes × 17 slots — dispatchers
`cspec_update_dispatch @ 0x0049A090` field2 / `cspec_attack_tick_dispatch @ 0x0049A0C0`
field3 / `cspec_field17_dispatch @ 0x0049A030`), corpus names. **Derived**.

## Architecture

- Every gameplay entity = `OBJECT` (layout: `ps2_symbols/OBJECT_LAYOUT`) with
  `+0x1E0` = class id (0..106). The BSS table at `0x55CB00` holds 17 function pointers
  per class (field 2 = main AI update, field 3 = attack/anim tick, field 16 = death
  handler, fields 10/11 = free/clear, field 5 = per-class constant getter — see the
  63 cspec_ handlers named in `ps2_symbols/llm_wave226.csv`).
- Frame path: `objspec_dispatch_gate` (per-frame, from `game_loop_run`) →
  `cspec_update_dispatch` → per-class update.

## Class map (from named handlers)

| class | identity | notes |
|---|---|---|
| 1 | reaper_ai_main | story Reaper; spec helpers `reaper_spec_byte_get`, `reaper_spec_float_get`, `reaper_target_range_check_c1` |
| 2 | mecc_ai | player Mecc; `mecc_anim_tick_c2` (animselect), `mecc_chat_send_25`, `mecc_bubble_show` |
| 3 | reaper_spellcast | |
| 15 | kabuto_ai | Kabuto; `kabutoai_death_handler_c1`, `kabuto_laser_texture_init` |
| 18 | smartie_ai | smarties; `smartie_move`, `smartie_target_filter`, `smartie_house_scan` (type 0x353 houses), `injured_target_scan`, `smartie_injured_pet_find` |
| 19 | (death_clear_owners) | clears child owner links on death |
| 21 / 99 | evilreaper herd / fly | `herd_promote_check` (rank `+0x9C`, threshold `+0xFC`) |
| 28 / 47/84/87/89 | seamonster family | `death_state_set_c28`, `seamonster_tick_c29` |
| 33 | rpman_ai | 153 KB `rpman_ai_main` — the Reaper Proxy Man boss logic; `rpman_hit_state_set`, `rpman_target_scan`, `rpman_return_refpt_eval`, `spline_waypoint_push` |
| 44 | turret | `turret_fire` (PS2 name), spec+0x60 ammo |
| 58/59 | pickups | `free_res_c58` |
| 61 / 101 | health_ratio family | `health_anim_tick` pair |
| 76/92 | vimp family | `child_owner_clear_c76` |
| 93 | piranha | `piranha_go` per-frame, `piranha_anchor_move` |
| 103 | barracks spawner | shared handler with 5/6/43/57 |
| 105 | smartieboy (Timmy) | |
| 106 | army opcodes | `army_process_opcodes__FP6OBJECTPPUci` |

## Movement & goals

- Shared movement: `ai_chase_location`, `ai_move_force_goal`,
  `ai_goal_valid_check`/`ai_goal_skip_locked_a/b` (goal slots +0x168/+0x14 flags),
  `ai_standoff_goal_calc` (keep-radius approach), `walkable_floor_check` /
  `slope_walkable_check` (cos 50° ≈ 0.64278 slope gate), `obj_orient_set`.
- Perception: `ai_proximity_scan` (+ `distancesq3d`), `obj_proximity_update`,
  `input_mouse_world_check` (player targeting), `reaperbase_enemy_scan`
  (types: reaper/mecc/0xB/8/0x438/0xE5/0x49/0xE6/0x29A), `reaperbase_dock_check`,
  `herd_promote_check`.
- Fires/food: `reaper_spawn_ospec_1/2` → `verm_ai_cb` (vermin from food),
  `meccbasepit_food_take` (+0x52C slot, `meccbasepit_create_food`).

## Validation

- P1.1 trace hits on `verm_ai_cb`, `facing_player_bark`, `mecc_bubble_show`,
  `smartie_target_filter` give per-decision (id, obj, args) samples to pin the
  constants (rng thresholds like `crt_rand_scaled(100) < 0x32`).
