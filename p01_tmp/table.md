### Opcode table

Sizes below are **byte-validated** on shipped files (108/120 world bins walk to a clean
terminator; see Validation). Sizes = total record bytes including the opcode byte.
`strz` = NUL-terminated string (variable length). Decode levels:
**F** = fields mapped · **S** = size + target known, fields pending · **T** = stream
terminator (clean stop) · **E** = rejected at load ("Unknown/Obsolete") — load aborts.

| op | size | name / target | notes (derived) |
|----|------|----------------|------------------|
| 19 | 2 | obj flag byte | `u8 → obj[4]`, sets `obj[0xC]=1` |
| 20–22 | — | unknown | **E** |
| 23 | 5 | obj float | `f32 → obj[0x31]` |
| 24–28 | — | unknown | **E** |
| 29 | 17 | string (discarded) | 16-char name field |
| 30 | 17 | world texture 1 | str → `main_texture_00508750` → `WS[0x4C]` |
| 31 | 17 | string (discarded) | |
| 32 | 17 | world texture 2 | str → `WS[0x54]` |
| 33 | 17 | world texture 3 | str → `WS[0x5C]` |
| 34 | 17 | world texture 4 | str → `WS[0x64]` |
| 35 | 1 | **terminator** | **T** (switch break = clean end) |
| 36 | 17 | string (discarded) | |
| 37 | 17 | world texture 5 | str → `WS[0x74]` |
| 38 | 17 | world texture 6 | str → `WS[0x6C]` |
| 39 | 18 | skip | |
| 40 | 4 | ambient color RGB | 3×u8 × (1/255) → `WS[0x4F7C..84]` |
| 41 | 13 | fog | f32 min→`WS[0x128]`, f32 max→`WS[0x12C]`, 3×u8 RGB→`WS[0x130..138]` (a size variant exists — see Open items) |
| 42 | 1 | **terminator** | **T** |
| 43 | 5 | obj float | `f32 → obj[5]` |
| 44 | 1 | **terminator** | **T** |
| 45 | 38 | worldanim (shared tail) | same advance as op 58's handler (skips its flag set) |
| 46 | 13 | fog alt | f32 near→`WS[0x7C]`, f32→1/x→`WS[0x80]`, u32→`WS[0x84]` |
| 47 | 29 | skip | |
| 48 | 19 | light slot | `u8 idx` + f32,f32,u32,f32 → `WS[0x178+idx*16 ..]` (4 slots) |
| 49 | 41 | skip | |
| 50 | 6 | obj bytes | type-0x24: sub-alloc bytes; else `u8→spec[8], u8→spec[0x28]` |
| 51 | — | garden | **E** "Obsolete garden opcode" |
| 52 | 45 | terrain name A | str32→`WS[0x1E0]`, f32@+0x21→`WS[0x1E4]` (0→50.0f, then 1/x) |
| 53 | 45 | terrain name B | →`WS[0x1E8]/[0x1EC]` |
| 54 | 45 | terrain name C | →`WS[0x1F0]/[0x1F4]` |
| 55/56 | — | mesh single / group | **E** obsolete |
| 57 | 29 | LOD curve | f32×4 → `WS[0x1A8..1B4]` (squared), slope→`WS[0x1B8]/[0x1BC]` |
| 58 | 37 | worldanim attach | `worldanim_find(str32@+1)`, `object_change_ospec(cur,0x36)` |
| 59 | 2 | obj byte | `u8 → obj[0x3A]` |
| 60 | 17 | skip | |
| 61 | 1 | **terminator** | **T** |
| 62 | 21 | skip | |
| 63 | 9 | obj floats | f32,f32 → obj sub-alloc +0xC/+0x10 (type 0x24) |
| 64 | 26 | **OpAre** (area) | create obj, `ospec 0x16`, f32×2 @+10/+14, team-ripper alloc 0x28 |
| 65 | 9 | obj floats | → sub-alloc +4/+8 |
| 66 | 93 | **OpSmo** (smoke) | create obj, `ospec 0x18`, f32×3 @+9/+13, flags 0x40000000\|4 |
| 67 | 1 | **terminator** | **T** (bare `break`) |
| 68/69 | 1 | no-op | advance 1 (shared-tail entries) |
| 70 | 29 | **OpObj** (object) | `u32 type` (fallback alloc 0x406), f32×3 pos @+5/+9/+0xD, f32 @+0x11, f32×2 @+0x15/+0x19; copies 0x1E dwords of type defaults (type+400); max 0x400 objects (0xC1-dword slots) |
| 71 | 21 | view range | f32×2 + u32×2 → `WS[0x1C0..1CC]` |
| 72 | 13 | point list add | f32×3 → point buffer (max 32) |
| 73 | 5 | world float | f32 → `WS[0x1F8]` |
| 74 | 1 | world flag | `WS[0x1FC]=1` |
| 76 | 7 | **OpLoc** (locator) | create; `u8`,`u8` → obj[0x84]/[0x85]; worldanim lock stack |
| 77 | 1 | lock pop | "Lock level underflow" guard |
| 78 | 34 | Flick ref | name(32); u8 → flag bit obj[0xBA..BC]; "Flick %s not in world flick list" |
| 79 | 65 | Flick pair | name32 + name32 → `WS[0x210+i*0x20]` / `WS[0x1210+i*0x20]` (max 0x7F) |
| 80 | 2+4n | spec floats | `u8 n` + n×f32 → spec |
| 81 | 13 | obj floats | f32×3 → obj[0x32]/[0x33]/[0x34] |
| 82 | 5 | obj float | → obj[0x5D] |
| 83 | 5 | spec float | → spec+4 |
| 84 | 45 | worldanim ×2 | `ospec 0x4F`, extra f32 pair |
| 88 | 13 | water fog | f32 min/max + 3×u8 RGB → `WS[0x140..150]` |
| 89 | strz | palette name | strz → `WS[0x4530]` |
| 90 | 13 | obj floats | f32×3 → obj[0x3D..0x3F] |
| 91 | 13 | spec write | 12 B → spec |
| 92 | 38 | **scenario (mission)** | `u8` + str32@+6 → `scenario_list_load` — the `wm_*.bin` linkage |
| 93 | 33 | scenario name | str32 → `WS[0x2210 + i*0x118]` |
| 94 | 33 | string table 2 | → `WS[0x4A7C]` region |
| 95 | 13 | obj orientation | f32×3 → `obj_orient_set` |
| 96 | 5 | view obj select | f32 → `WS[0x4E88]`; nonzero sets `WS[0x4A60]=0x1B` |
| 97/98 | 9 | spec write | 8 B → spec |
| 99/100 | 1 | spec flags | spec+0x48 / +0x4C = 1 |
| 101 | 13 | sky color | f32 + u32×2 → `WS[0x4E8C..94]` |
| 102 | 9 | sky angle | f32 → cos() → `WS[0x4E98]/[0x4E9C]` |
| 103 | 5+4n | spec float list | `u32 n` (≤0x14) + n×f32 → spec (pre-set −NaN) |
| 104 | 5+4n | spec float list 2 | same into spec+0xA8 |
| 106 | 4 | spec byte | type 0x33: `u8`→spec+0x60; type 0x61: `u8`→spec+0xC |
| 107 | 5 | spec float | → spec+0x50 |
| 108–110 | 1 | **terminator** | **T** |
| 111 | 65 | skip | |
| 112 | 1 | **terminator** | **T** |
| 113 | 34 | flick-family shared | same advance as op 79 tail |
| 114 | 45 | music name A | str32→`WS[0x4F20]`, f32→`WS[0x4F24]` |
| 115 | 45 | music name B | →`WS[0x4F28]/[0x4F2C]` |
| 116 | 45 | music name C | →`WS[0x4F30]/[0x4F34]` |
| 117 | 5 | world float | →`WS[0x4F38]` |
| 118 | strz+20 | env pack | strz→`WS[0x4F40]` + f32×5 → `WS[0x4F7C..4F98]` |
| 119 | 49 | fog pack A | 12 fields → `WS[0x4FB8..4FF4]` |
| 120 | 49 | fog pack B | 12 fields → `WS[0x4FFC..5038]` |
| 121 | 93 | terrain palette | 6×(3 bytes → packed rgb u32) → `WS[0x508C..509C]`, 2×u32 → `WS[0x50A0]/[0x50A4]`, f32×3 → `WS[0x50A8..50B4]` |
| 122–128 | — | unknown | **E** |
| 129 | 5 | world float | →`WS[0x4A78]` |
| 130 | 33 | map name | str32 → `WS[0x50C0]` |
| 131 | — | unknown | **E** (abort + free) |
| 132 | strz | voice path | strz → alloc (`s_vopath_`) → `WS[0x50E0]` |
| 133 | 45 | subtitle set A | str32+f32 → `WS[0x4EF0]/[0x4EF4]` |
| 134 | 45 | subtitle set B | →`WS[0x4EF8]/[0x4EFC]` |
| 135 | 45 | subtitle set C | →`WS[0x4F00]/[0x4F04]` |
| 136 | 45 | subtitle set D | →`WS[0x4F08]/[0x4F0C]` |
| 137 | 46 | subtitle shared tail | same as 133-136 family with extra field |
| 138 | 46 | **terrain (GTI)** | str32→`WS[0x4F18]`, f32→`WS[0x4F1C]`; stream end triggers `gti_terrain_load` + stobj block (`WS[0x170]×0x304`) |

