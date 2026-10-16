# SAVEGAME — mission.sav (static decode, first pass 2026-10-16)

**Bottom line : `mission.sav` is a RAW MEMORY DUMP of the global mission-state
zone at `0x00633380`, exactly `0x23084` bytes (143 492), read/written by one
call each. No container, no checksum.**

All **derived** from corpus (addresses are GOG 1.449).

## Proof (corpus lines)

- Writer `savegame_verify @ 0x00491F10` :
  `file_write_locked(&DAT_00633380, 0x23084, 1, f)` (l.84686).
- Reader (mission load path, l.84620-84650) :
  `file_read_locked(&DAT_00633380, 0x23084, 1, f)` (l.84646).
- File path : `savegame/%s/mission.sav` where `%s` = player name
  (`&DAT_0063304c`, default profile "Player") or `savegame/SaveGame%d/
  mission.sav` (numbered slots — the Reaper demo ships `SaveGame0`).
  Directory created with `CreateDirectoryA` before writing.
- Version gate : setting `SaveGameVersion` (via `mission_0051a0c0`) must equal
  **0x11** or the file is simply not loaded (l.84632-84636).
- Zone init before load (l.84616-84628): the loader fills `&DAT_00637404`
  (= zone + 0x4084) with `0xFFFFFFFF` dwords — an ID/index cache table
  (0x4800 then 0x6c00 iterations in the decomp; second loop likely a Ghidra
  duplicate — verify) before the read.

## Zone map (starts; per-field map = open)

```
0x00633380 +0x0000  dword flags (b0 set on entry somewhere: l.83794
                    `DAT_00633380 |= 1 << (x & 0x1f)` — bitfield of visited
                    mission flags?)
0x00633380 +0x4084  ID cache table, dwords init 0xFFFFFFFF
0x00633380 +0x23084 end of dumped zone
```

## Samples on hand (all same size — fixed-layout dump)

| file | bytes | head dwords |
|---|---|---|
| `savegame/Player/mission.sav` | 143 492 | `01 00 00 00, 01 00 00 00, 00…` |
| `RESSOURCES_FOR_AI/Giants Reaper Demo/savegame/SaveGame0/mission.sav` | 143 492 | identical head to Player sample |
| `RuntimeLab/gog141/savegame/Player/mission.sav` | 143 492 | `0F 00 00 00, 01, 17 00 00 00, 1D 00 00 00, 07…` |

No ASCII anywhere → pure binary structs; the gog141 head (`0x0F, 0x1, 0x17,
0x1D, 0x7` = 15, 1, 23, 29, 7) reads like mission counters/indices — prime
candidates for the first fields (mission number / stage / objectives state).

## Empirical field map (diff Player-vs-gog141 samples, 18 diff runs)

| offset | evidence | reading |
|---|---|---|
| +0x00 | 1 vs 0x0F | counter A (mission index / furthest stage) |
| +0x08,+0x0C,+0x10 | 0 vs 0x17/0x1D/0x07 | counters B/C/D (objectives/stage numbers) |
| +0x114 | 0 vs 0x0A | counter E |
| +0x1104..+0x1210 | 12+4+4+12+6+4 diff bytes, values `0x0BECxxxx`-`0x0BD7xxxx` | **TIMESTAMP block** (LE u32 epoch seconds ≈ 2001-11 — matches the era; Player sample has zeros) |
| +0x2184 | 0 vs 2 | flag/level |

## How to finish the field map (next session)

Mine `DAT_00633380 + k` accessors in the corpus the same way OBJECT was mined
(scripts/mine_object_layout_pc.py pattern) — most code will hold
`&DAT_00633380` in a register-derived base, so also mine functions between
`savegame_verify`'s callees. Then diff the two clean samples (Player vs gog141)
to locate the counters block empirically. keymapping.sav is a separate
registry-backed file (`keymap_0051a100`), NOT part of this dump.
