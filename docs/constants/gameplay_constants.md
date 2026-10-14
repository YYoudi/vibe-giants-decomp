# gameplay_constants — provenance-tracked constants

| value | function | address | note |
|---|---|---|---|
| `DAT_006328e0` | FRateGetSecsframe | 0x00518B70 | base dt register (frame seconds; runtime value, seed of all timing) |
| `10.0` | facing_player_bark | 0x0049DBD0 | player-facing half-angle threshold (degrees, ±10°) |
| `0x682` | facing_player_bark | 0x0049DBD0 | bark sound id A |
| `0x683` | facing_player_bark | 0x0049DBD0 | bark sound id B |
| `0x32` | facing_player_bark | 0x0049DBD0 | rand threshold 50/100 = 50% |
| `0xd04` | facing_player_bark | 0x0049DBD0 | cfg radius offset (squared dist gate, DAT_632ED8+0xD04) |
| `35.0` | reaper_target_range_check_c1 | 0x0045BE30 | far range multiplier * spec+0xC4 |
| `20.0` | reaper_target_range_check_c1 | 0x0045BE30 | near range multiplier * spec+0xC4 |
| `0x29d` | reaper_target_range_check_c1 | 0x0045BE30 | target-owner self id guard |
| `0x3c00/0x3c0/0x3c` | reaper_target_range_check_c1 | 0x0045BE30 | target weapon-class flag masks at +0x1CC |
| `0x14` | injured_state_start | 0x0046B7F0 | state id: injured-seek (obj+0xE4) |
| `0x3c` | injured_state_start | 0x0046B7F0 | obj flag bits set (0x20|0x10|0x8|0x4) |
| `0x40a00000` | injured_seek_state_set | 0x0046B850 | timer 5.0 s (obj+0xEC) |
| `0x13` | injured_seek_state_set | 0x0046B850 | state id 19 (obj+0xE4) |
| `0x353` | smartie_house_scan | 0x004B6C00 | smartie-house object type id |
| `0x3f` | smartie_house_scan | 0x004B6C00 | occupancy mask (6 slots; full = 0x3F) |
| `9999999.0` | smartie_house_scan | 0x004B6C00 | best-dist sentinel |
| `0x47` | master_flagslot_claim | 0x0040ABF0 | first flagslot id returned (0x47+i, 12 slots) |
| `0xfff` | master_flagslot_claim | 0x0040ABF0 | all-slots-taken mask |
| `0x10` | vvel_decay_tick | 0x004A73A0 | obj+0xD8 flag 0x10 = no-decay |
| `0x80000` | vvel_decay_tick | 0x004A73A0 | obj+0xD8 flag 0x80000 = no-decay variant |
| `0x80` | kabuto_laser_texture_init | 0x00467270 | laser texture 128x128 |
| `0x1ec1/0x1eb0` | kabuto_laser_texture_init | 0x00467270 | allocation site line numbers (kabuto.c) |
| `0x1a8..0x1bc` | worldanim LOD curve | OP57 | WS LOD curve: (near², far², lo, hi) + derived slope |
| `0x457a0000` | bldg defaults | OP121 | 4000.0f default WS+0x50A0 (terrain palette scale) |
| `0x42000000` | bldg defaults | OP121 | 32.0f default WS+0x50A4 |
| `0x3f800000/0x3fc00000` | bldg defaults | OP121 | 1.0f/1.5f defaults WS+0x50AC..B4 |
| `0x447a0000` | fog defaults | OP41 | 1000.0f default WS+0x7C (fog near) |
| `0x3d000000` | fog defaults | OP41 | 0.03125f default (density reciprocal init) |
| `0x3f000000` | fog defaults | OP41 | 0.5f default WS+0x84 |
| `0x42480000` | fog defaults | OP41 | 50.0f fallback for zero fog/music scale (ops 52-54/114-116/133-136) |
| `0x3f800000` | sky defaults | OP101-102 | 1.0f WS+0x4E8C |
| `0xbdcccccd` | sky defaults | OP101-102 | 0.05f WS+0x4E90 |
| `0xbd4ccccd` | sky defaults | OP101-102 | 0.05f WS+0x4E94 |
| `0.8726646304130554` | sky defaults | OP101-102 | default sky angle A (rad, = 50°) → cos = 0.642787 |
| `1.0471975803375244` | sky defaults | OP101-102 | default sky angle B (rad, = 60°) → cos = 0.5 |
| `1.0` | bubble_timeout_clear | 0x00536C60 | bubble timeout seconds (DAT_632E6C - DAT_5E273C > 1.0) |
| `0x40a00000` | player_pet_follow_tick | 0x00501090 | 5.0 s pet-follow timer (creature+0x134) |
| `0x40a00000` | pet_command_set | 0x00501100 | 5.0 s command window |
| `0.1` | heal threshold | fx_name_set_c77 | fx rate floor (param_3 float, obj+0x84) |
| `25.0` | heal threshold | fx_name_set_c77 | health-crossing threshold for fx name trigger (obj+0x278) |
| `999` | comm_scores_send | 0x0052B280 | score clamp max |
| `0x547` | comm echo | comm_echo_send | max echo message length 1351 |
| `1.0` | meccbasepit_food_take | 0x0040B1D0 | food ripeness timer threshold (pit food +0xEC < 1.0 → not ready) |
| `0x52c` | meccbasepit_food_take | 0x0040B1D0 | pit slot array offset in base spec |
| `0.1` | trajectory_throw_calc | 0x004698F0 | throw velocity = dist * 0.1 |
| `0.64278` | walkable_floor_check | 0x004138C0 | slope cos gate (≈50°) — walkable if slope-cos below |
| `0.64278` | slope_walkable_check | 0x00413880 | slope cos gate twin |
| `0xd00` | ai_standoff_goal_calc | 0x0049DE80 | cfg standoff radius (DAT_632ED8+0xD00, squared vs target) |
| `0xdd` | rpman_hit_state_set | 0x004D7C60 | guard state id (obj+0xE4 == 0xDD skips hit reaction) |
| `0x4d` | rpman_hit_state_set | 0x004D7C60 | rpman target class id |
| `0x65/0x66/0x67` | rpman_hit_state_set | 0x004D7C60 | special hit-cause ids (0x65<cause<0x68) |
| `0x60` | seq_index_assign | 0x00476EB0 | special chain class id |
| `0x8000000` | seq_index_assign | 0x00476EB0 | obj+0x1C8 flag = chain member |
| `0x1d8/0x1dc` | gridcell_free_check_store | 0x004E7250 | grid width/height fields in DAT_6330E4 |
| `0x0e` | gridcell_free_check_store | 0x004E7250 | cell occupied flag offset (stride 0x10) |
| `40000.0` | spawn_clearance_check | 0x004E3730 | clearance radius² = 200 units |
| `5` | spawn_clearance_check | 0x004E3730 | max allowed neighbors within radius |
| `0xf4c` | bldg_spawn_state_tick | 0x004E9CE0 | cfg spawn timer offset (DAT_632ED8+0xF4C) |
| `0x30/0x20/0x21` | bldg_spawn_state_tick | 0x004E9CE0 | anim ids: spawn/idle/alt |
| `1/2/3` | bldg_spawn_state_tick | 0x004E9CE0 | building state machine states (obj+0xE4) |
| `0x400000` | worldanim_assign | OP58 | obj+0x72 flag: worldanim-attached |
| `0x36` | worldanim_assign | OP58 | ospec id for animattacher (op 58) |
| `0x4f` | worldanim_assign | OP58 | ospec id for worldanim (op 84) |
| `0x16` | teammecc_target_state_query | 0x00456090 | target type A (carried→1) |
| `0x313` | teammecc_target_state_query | 0x00456090 | target type B (carried→1) |
| `0x311` | teammecc_target_state_query | 0x00456090 | target type C (carried→3) |
| `0x98/0x9c/0xfc` | herd_promote_check | 0x005108F0 | owner slot idx / rank / promote-threshold float (spec+0xFC) |
| `100.0` | herd_promote_check | 0x005108F0 | promotion percent denominator |
| `36.0` | reaperbase_dock_check | 0x004C5B10 | dock distance² threshold (6 units) |
| `0xc` | reaperbase_dock_check | 0x004C5B10 | refpt index used for dock point |
| `0x33` | destroy_by_id_c33_c27 | 0x004782F0 | class A (id at spec+0x134) |
| `0x27` | destroy_by_id_c33_c27 | 0x004782F0 | class B (id at spec+0x14) |
| `0xd7` | type0d7_unique_check | 0x004E21F0 | unique-type id |
| `0x21` | type0d7_unique_check | 0x004E21F0 | state exclusion (obj+0xE4 != 0x21) |
| `0x134` | type0d7_unique_check | 0x004E21F0 | spec id field for uniqueness |
| `0x4000c000` | injured_target_scan | 0x004D1A00 | excluded obj flags (dead-ish) |
| `0x278/0x1c0` | injured_target_scan | 0x004D1A00 | hp / max-hp fields (injured = hp<max) |
| `0x874` | flick timing | FLK | FLK_Actor struct size |
| `0x310` | flick timing | FLK | FLK block record size |
| `0xc` | flick timing | FLK | FLK director record size |
| `0x304` | spec sizes | OP138 | static-object (stobj) record size |
| `0xc1` | spec sizes | OP138 | OpObj world-object slot size (dwords) per object, max 0x400 |
| `0x1c0..0x1cc` | view range | OP71 | WS view-range block (near/far/2×u32) |
| `0x2` | master collision flags | COLLISION | cell blocked bit (collision grid byte) |
| `0x400000/0x181808` | master collision flags | COLLISION | obj+0x1C8 movement mode flags (collide_walk gates) |
| `0x40a00000` | bubble/respawn misc | MISC | 5.0 s (recurring timer constant) |
| `0x447a0000` | bubble/respawn misc | MISC | 1000.0 f (recurring distance/scale default) |
| `0x3dcccccd` | bubble/respawn misc | MISC | 0.1 f (recurring small-rate default) |
