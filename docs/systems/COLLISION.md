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

## Open items (next pass)

1. **Movement sweep** (sliding/stepping): consumers of the occupancy table —
   candidates `collgrid_query_obj @ 0x418CF0`, `collgrid_collide_d @ 0x414990`,
   PS2 `collide_localline_objtris_mips` for the line-walk semantics.
2. Per-cell world-flag map beyond b1 (blocked) — read the writers of the world
   grid (build path `main_collgrid_00410200`) or dump a runtime grid.
3. Confirm the 5.0 u/cell scale at runtime (one BP at 0x412730, read
   pos/radius vs cell bounds).

## Validation

- P1.1 trace: `collgrid_00430e10` is hot; not BP'd by default. Validation via
  `obj_impact_effects`/`hurt_pusher_2` hits (fire from collision outcomes) and
  a runtime dump of the grid header vs terrain bounds (pending).
