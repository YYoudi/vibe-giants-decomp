# `.abx` files — format spec (magic `0x1A0002DD`)

Status: ✅ fully decoded (both sub-formats share the magic).

**Evidence:** GOG 1.449 corpus — registry reader `main_readdata_004adfa0 @ 0x004ADFA0`
(strings `s_GameObj_bin_0055feac`, `"Bad version for GameObj.bin"`); placement reader
embedded in `bin_load_1a0002e5 @ 0x004B0FC0` tail (extension literal `"abx"` at
`0x00560330`). Claims **derived** unless marked **observed** (byte-verified on real
files).

Two distinct file formats share this magic:

1. `Bin/GameObj.bin` — the **component registry** (read once at boot).
2. `Bin/w_<World>.abx` — **object-set instance placements** (read after each world's
   `.bin`).

---

## 1. `GameObj.bin` — component registry

**Observed** (182 bytes, read byte-exact):

```
u32 magic   = 0x1A0002DD
u32 size                    // payload bytes = filesize - 8 (observed 174 = 182-8)
records:                    // parsed by main_readdata_004adfa0
    u8 kind                 // 1..9 observed (sequence ids)
    char file[]             // NUL-terminated source file name, e.g. "world.gb2"
    char name[]             // NUL-terminated component name, e.g. "sky"
u8 0xFF                     // terminator
```

Shipped content — 9 components, all from `world.gb2`:

| kind | file | name |
|---|---|---|
| 1 | world.gb2 | sky |
| 2 | world.gb2 | outsky |
| 3 | world.gb2 | sea |
| 4 | world.gb2 | waterfall |
| 5 | world.gb2 | waterfall2 |
| 6 | world.gb2 | wfall_edge |
| 7 | world.gb2 | world_glow |
| 8 | world.gb2 | underside |
| 9 | world.gb2 | space |

The parser registers each `(file,name)` pair into two global lists
(`DAT_00632D2C` / `DAT_00632D30`, built via `BinFileSeek_5`). The engine later
instantiates these components by name — that is the runtime path that opens
`world.gb2` (the file name is never a literal at any other call site; only
`game_files_check @ 0x004EE890` references the literal, as an integrity check).

---

## 2. `w_<World>.abx` — object-set placements

Reader (inside `bin_load_1a0002e5`, after the opcode stream):

```
repeat:
    u32 set_id                          // -1 = end of file
    objectset_find(set_id)              // world object-set registry lookup
    float f6_default                    // 6×f32 (0x18 bytes) default transform
        → for each of 10 fixed slots: if slot object exists, f6 → obj+0x44
    repeat:
        u32 member_index                // -1 = end of this set
        float f6_member                 // 6×f32 → objectset members[member_index]+0xC
```

Layout on disk (**observed**, `w_Kstory1.abx`, 28 800 B): after the magic, the first
`u32` is the `set_id` — shipped value `0xC185CF3C` — followed by `f6`, then member
records with ascending indices `1,2,3,…` (`u32` + 24 B each) to EOF.

**Notes**

- `set_id` is a **map checksum**, matching the hardcoded 4-byte map-checksum table used
  by the dedicated-server ecosystem (`giantsd/giants/map.py`, e.g.
  `"Three Way Island - Canyons"` → `9c 53 f4 dd`). *Inferred* from role + ecosystem
  tooling; runtime confirmation = P1.1 trace (breakpoint `objectset_find`).
- The tail of the reader also post-processes: any member whose `f6` equals the default
  (`+0xC..0x14 == +0x18..0x20` dword-wise) gets the default transform copied in — the
  "unset" marker convention.
- `f6` = 6 floats: *inferred* position (3) + orientation (3); the engine stores them raw
  at `+0xC` (members) and `+0x44` (slot objects). Exact semantics (euler order, radians)
  to be pinned by a P1.1 runtime dump before a Rust port trusts them.

### Orientation → matrice (derived, decomp 2026-10-15)

La conversion d'orientation du moteur = `math_euler_to_matrix @ 0x00516F60`
(signature decomp : `(a, b, c, scale, out3x3)`, `sine_cos_lookup(ptr_sin, ptr_cos)`,
**le 2e angle entre nié** : `sin(-b)`), matrice ligne-majeure exacte :

```
s = scale
m[0] =  cos(c)*cos(a)*s                m[3] =  sin(c)*cos(a)*s              m[6] = sin(a)*s
m[1] = (-sin(b)*cos(c)*sin(a) - sin(c)*cos(b))*s
m[4] = ( cos(c)*cos(b) - sin(c)*sin(a)*sin(b))*s
m[7] = cos(a)*sin(b)*s
m[2] = ( sin(c)*sin(b) - cos(c)*sin(a)*cos(b))*s
m[5] = (-sin(c)*sin(a)*cos(b) - cos(c)*sin(b))*s
m[8] = cos(a)*cos(b)*s
```

Colonne 2 = forward = (sin a, cos a sin b, cos a cos b) — `a` = lacet (yaw),
`b` = tangage (pitch, entré en sens inverse), `c` = roulis. Angles en radians
(les tables `sine_cos_lookup` sont indexées en radians). `crt_euler_to_quat @
0x0053E580` existe pour la variante quaternion. Statut : **derived** (decomp) ;
une validation par dump runtime du f6 d'un placement + de la matrice objet
résultante reste le moyen de passer à observed.

## Validation

- GameObj.bin parsed end-to-end (byte-exact, 9 records + 0xFF).
- w_Kstory1.abx walked: set_id + member stream matches the reader's expectations.
- Parser: `tools_spec/abx.py` covers both sub-formats.
