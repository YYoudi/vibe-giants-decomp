# COLLISION — collision grid + queries

Status: 🔶 grid layout + main queries derived; full field maps pending (P1.1 trace +
deeper pass over the 10.7 KB `collgrid_collide_walk`).

**Evidence:** module `Main/collgrid.c` (assert strings
`s_C__Giants_source_main_collgrid_c_00555464`). All **derived** unless noted.

## The grid

- World/grid object holds the grid pointer at **`+0x21C`**, allocated by
  `main_collgrid_00410200` (lazy build), freed by `collgrid_clear_grid @ 0x004101D0`.
- Grid header (**derived** from `collgrid_query_small @ 0x00412570`):

```
+0x00 u8  format/version       (observed value 3)
+0x01 i16 x_min
+0x03 i16 z_min
+0x05 i16 x_max
+0x07 i16 z_max
+0x09 u8  cells[(x-x_min) + (x_max-x_min+1)*(z-z_min)]   // byte per cell
```

- Cell test: `cell & 0x02` = **blocked bit** (query_small returns that bit).
  Other bits carry per-cell flags used by movement/walk code (exact map open).
- Grid resolution: one byte per (x,z) cell; world-space scale of a cell = open item
  (GTI terrain grid is 1 024×1 024 samples — collision grid is coarser; confirm scale
  from `collgrid_collide_walk` math or a runtime dump).

## Query / resolve surfaces

| function | addr | role (derived) |
|---|---|---|
| `collgrid_query_small` | 0x00412570 | point-in-grid blocked-bit test |
| `collgrid_pos_query_dlog` | 0x004125F0 | position query (dialog/debug variant) |
| `collgrid_query_obj` | 0x00418CF0 | object-vs-grid query |
| `collgrid_00430e10` | 0x00430E10 | the generic point query used everywhere (world raycast helper — see callers: `obj_collpts_world_test`, `hud_radar_collide_sweep`, `trajectory_throw_calc`) |
| `collgrid_collision_test` | 0x00404230 | per-slot sphere tests: walks the object's 0x24-stride slot table (`+0xC + slot*0x24`; fields `+0x14` mesh-pts idx, `+0x1C` type index into a 0x50-stride table at `+0x84`, `+0x20` count), each point tested via `collgrid_00430e10` |
| `collgrid_collide_walk` | 0x00412730 | THE movement collision (10.7 KB): walk-mode sliding/stepping, honors flags `+0x1C8 & 0x400000/0x181808`, dead-flag `+0xD8 & 0x80000` |
| `collgrid_collide_resolve` | 0x00412180 | penetration resolution |
| `collgrid_collide_b/c/d` | 0x004047C0 / 0x00410720 / 0x00414990 | shape-specific resolvers (b/c/d variants — spheres vs volumes vs walkables) |
| `collgrid_clear_grid` | 0x004101D0 | free grid on world unload |

## Movement integration (how objects collide)

From the frame order (docs/systems/SIM_LOOP.md): `obj_velocity_commit` (integrate) →
per-class update (AI moves via `object_add_location*`) → `object_apply_location` →
`PROJ_ObjectFinalize`. Collision runs inside that window: `collgrid_collide_walk` is the
character-mode resolver (it checks the walkable/collision bits of the cell grid plus
per-object volumes via `object_lock_with_volume` downstream in the frame).

## Validation

- P1.1 trace: `collgrid_00430e10` is hot; not BP'd by default. Validation instead via
  `obj_impact_effects`/`hurt_pusher_2` hits (which fire from collision outcomes) and a
  runtime dump of the grid header vs terrain bounds (pending).
