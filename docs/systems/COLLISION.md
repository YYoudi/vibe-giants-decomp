# COLLISION — collision grid + queries

Status: 🔶 `collgrid_collide_walk` FULLY DECODED (2026-10-16, worker pass — it is
the footprint RASTERIZER, not the walk sweep; supersedes the earlier reading);
remaining open: the movement sweep consumers (sliding/stepping) and the full
per-cell world-flag map.

**Evidence:** module `Main/collgrid.c` (assert strings
`s_C__Giants_source_main_collgrid_c_00555464`). All **derived** unless noted.

## The two grids (disambiguation — fixed 2026-10-16)

1. **World collision grid** (byte per cell) — queried by `collgrid_query_small`:
   `cell & 0x02` = **blocked** (query_small returns that bit; consistent with
   the bitmap `& 2` exclusion in `collgrid_collide_resolve` type-3, below).
2. **Moveable occupancy table** (byte per cell, values 0/1) — FILLED by
   `collgrid_collide_walk` with each moving object's footprint. PC twin of
   PS2 `collgrid_fill_table_moveable(OBJECT*, int, int, int, unsigned char*)`
   (ps2_symbols — **same 5-arg signature**, 508 B on PS2).

## `collgrid_collide_walk @ 0x00412730` — footprint rasterizer (FULL READ)

Signature (decomp): `(obj, x0, y0, w, table)` — `x0,y0` = sub-rect origin
(cells), `w` = row stride, `table` = byte base. Writes `1` (word-filled
`0x01010101`) into every covered cell of the occupancy table.

### Rectangle branch (no footprint blob — `obj+0x21C == 0`)

Gate: `obj+0x1C8 & 0x400000` (moveable active), NOT `& 0x181808`, and
`obj flags +0xD8 & 0x80000`. Coverage from position `(+0xA0 x, +0xA4 y)` and
radius `(+0x154)`:

```
cell_min = round((pos - radius) * 0.2)      # corpus l.11000-11007
cell_max = round((pos + radius) * 0.2)
```

**→ world scale of a cell = 5.0 units (factor 0.2)** — *derived*, the
constant the port needed. Clamp to the requested sub-rect, then fill.

### Blob branch (`obj+0x21C` → compressed footprint)

Header: `{i8 type; i16 x0; i16 y0; i16 x1; i16 y1}` (bbox), payload at +9:

| type | payload | notes |
|---|---|---|
| 1 | RLE rows: pairs `(i8 dx, u8 run)` until `0x80` terminator | run covers `[x+dx, x+dx+run)` per row, row++ per pair |
| 2 | TWO consecutive RLE planes (2nd header re-read after 1st terminator) | e.g. hull + detail |
| 3 | byte-per-cell bitmap, **b0 = occupied, b1 = EXCLUSION** | b1 proven by `collide_resolve` requiring `&1 && !&2` |
| 4 | packed-bit bitmap (`>>3` byte index, `1<<(i&7)` bit) | sign-corrected mask math (l.11212-11217) |
| 5 | RLE rows — variant of type 1 | same walk |

## `collgrid_collide_resolve @ 0x00412180` — point-vs-footprint test (FULL READ)

`(obj, cellx, celly) → 1` if the object's footprint covers the cell.
- Rectangle branch: same gates (`0x400000` set; NOT `0x800/0x80000/0x100000/0x1008`)
  + same `round((pos±r)*0.2)` bounds (l.10749-10756).
- Blob types 1/2/5: RLE row walk (row==celly then x within run).
- Type 3: `byte & 1 && !(byte & 2)` → hit.
- Type 4: packed-bit lookup, returns the bit directly.

## Query / resolve surfaces

| function | addr | role (derived) |
|---|---|---|
| `collgrid_query_small` | 0x00412570 | world-grid point test: `cell & 0x02` = blocked |
| `collgrid_pos_query_dlog` | 0x004125F0 | position query (dialog/debug variant) |
| `collgrid_query_obj` | 0x00418CF0 | object-vs-grid query (OPEN: full read pending) |
| `collgrid_00430e10` | 0x00430E10 | generic cell/triangle query used everywhere (raycast helper — callers: `obj_collpts_world_test`, `hud_radar_collide_sweep`, `trajectory_throw_calc`) |
| `collgrid_collision_test` | 0x00404230 | per-slot FACE-NORMAL precompute (cross products of cell triangles, l.2470-2475) — NOT a movement test |
| `collgrid_collide_b` | 0x004047C0 | per-cell triangle gradient precompute (`S_TriCalcGradients`) — NOT a movement test |
| `collgrid_collide_walk` | 0x00412730 | **footprint rasterizer** (see above; == PS2 `collgrid_fill_table_moveable`) |
| `collgrid_collide_resolve` | 0x00412180 | point-vs-footprint test (see above) |
| `collgrid_collide_c/d` | 0x00410720 / 0x00414990 | OPEN (precompute variants suspected — verify before use) |
| `collgrid_clear_grid` | 0x004101D0 | free grid on world unload |

Fine collision inside a cell is **mesh-based** (per-cell triangle lists +
precomputed normals/gradients), not flag-based — the byte grids are the coarse
broad-phase.

## OBJECT flags proven here (cross-ref docs/formats/OBJECT_LAYOUT.md)

- `+0x1C8 & 0x400000` — object participates in the moveable occupancy table
  (both walk & resolve gates; **derived**).
- `+0x1C8` exclusions: `0x181808` (walk) / `0x800, 0x80000, 0x100000, 0x1008`
  (resolve) — per-bit semantics OPEN.
- `+0xD8 & 0x80000` — dead/removed gate (blocks both paths).
- `+0x21C` — pointer to the compressed footprint blob (0 = rectangle from
  pos/radius).

## Movement integration (correction 2026-10-16)

The earlier claim that `collgrid_collide_walk` was "the character-mode
resolver (walkable/collision bits)" is **withdrawn** — it fills the occupancy
table. The frame order (SIM_LOOP.md: `obj_velocity_commit` → per-class AI →
`object_apply_location`) still consumes collision in that window, but the
sweep itself lives in the consumers of the table (open items below).

## Movement sweep — sliding/stepping DECODED (`collgrid_collide_d @ 0x414990`)

`(mover_obj, pos_from*, pos_to*)` — the full walk-mode movement resolver, in
TWO phases (all **derived**, corpus l.12252-12380):

### Phase 1 — STEPPING (slope/step negotiation, ≤4 iterations)

```
while (collide_wall_block(obj+0xA0, pos_to, radius=obj+0x154)
       && obj+0x1BC < 0 && obj+0x224 == 0) {
    floor_z = get_floor_z_point_plat(pos_to)           # ground height under target
    if (physics_vec_math(pos_to,..) >= 0.64278          # slope <= ~50° (cos 50°)
        && -(obj->step_h(+0x1E8) * obj->q(+0xC4)) <= floor_z)
        break                                           # step is climbable: accept
    dir = dirfcalcp3d(...)                              # push direction out of the wall
    sincos(dir)
    pos_to += (cos, -sin) * global(DAT_006330e4+0x1C0) * 0.25   # small push step
    if (--iterations < 1) break
}
```
- A blocked target is RETRIED up to 4× by pushing 0.25·scale per attempt
  (**stepping**); a target on a slope ≤ ~50° (threshold 0.64278 = cos 50°)
  whose ground height is within the step budget
  (`-step_h(+0x1E8)·q(+0xC4) <= floor_z`) is accepted outright.
- `collide_wall_block @ 0x49C550` (l.92137) = the world-grid broad phase:
  extends the segment by radius(+1.1 in param units), maps to grid coords
  (`grid_coords_from_floats`), walks the covered cells (DDA-style), against
  the world grid. PS2 twin exists (`collide_wall_block`, 476 B).

### Phase 2 — SLIDING (footprint clamp, per blocking object)

For each object in the blocking list `DAT_00632d7c` passing the gates
(`+0xD8 & 0x4000C000 == 0`, `+0x1C8 & 0x800 == 0`, not Kabuto/type0f unless
`+0x1CC b0`, `+0x8 != 0`, `+0x210 != mover`):

```
while (collgrid_collide_resolve(blocker, cell(pos_to))) {   # target cell covered
    c_from = cell(pos_from); c_to = cell(pos_to)
    if (c_from == c_to) return                              # already inside: give up
    t_x = (adjacent_cell*5.0 - from.x) / (to.x - from.x)    # border crossing on X
    t_y = (adjacent_cell*5.0 - from.y) / (to.y - from.y)    # ... on Y
    t = max(t_x, t_y)
    pos_to = from + (to - from) * t                          # CLAMP at last free border
}
```
- The movement segment is SHORTENED to the last cell border before the
  blocker's footprint — component-wise (`max` of the two axis parameters),
  which produces the classic wall **slide** (the freer axis keeps its motion).
- Cell scale re-proven here: borders computed as `cell * 5.0` (l.12340/12347).
- Same-scale rounding everywhere: `round(pos * 0.2)` (l.12329-12332).

### Related queries

- `collgrid_query_obj @ 0x418CF0` : scans the object list `DAT_00632d9c` for
  occupants (type 0x4A8, same-team filter via `+0x18C`, `+0xD8>>8 >= 0`),
  returns blocker + radius `+0xE0` — an occupancy QUERY, not a sweep.
- PS2 parity refs: `collide_localline_objtris` (460 B) /
  `collide_localline_objtris_mips` (1184 B, `P3D*,P3D*,OBJECT*,P3D*,char**`) —
  the PS2 line-vs-object-triangles walk (for the mesh-level line semantics).

## Open items (next pass)

1. ~~Movement sweep (sliding/stepping)~~ **RESOLVED 2026-10-16** — decoded in
   `collgrid_collide_d` (phases above). Remaining: per-bit semantics of the
   exclusion masks `0x4000C000` / `0x800` / `0x1CC.b0`, and the mesh-level
   line walk (PS2 localline) if the port needs triangle-precision.
2. Per-cell world-flag map beyond b1 (blocked) — read the writers of the world
   grid (build path `main_collgrid_00410200`) or dump a runtime grid.
3. Confirm the 5.0 u/cell scale at runtime (one BP at 0x412730, read
   pos/radius vs cell bounds).

## Validation

- P1.1 trace: `collgrid_00430e10` is hot; not BP'd by default. Validation via
  `obj_impact_effects`/`hurt_pusher_2` hits (fire from collision outcomes) and
  a runtime dump of the grid header vs terrain bounds (pending).
