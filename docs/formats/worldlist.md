# `WorldList.bin` — world registry (magic `0x1A0003D0`)

Status: ✅ decoded (structure + observed content).

**Evidence:** **observed** — byte-verified on `Bin/WorldList.bin` (688 B, both installs
identical). Loader side: exe strings `worldlist.bin` / `worldlist%d.bin` (per-language
variants) near `0x001602E8`; the world id from this table indexes the `w_<name>.bin /
.abx / .gzp` triplets.

## Layout

```
u32 magic        = 0x1A0003D0
u32 names_end    = 0x2A8                  // offset just past the names region (688-8)
u32 count        = 31
u32 offsets[31]  // name offsets RELATIVE TO PAYLOAD START 0x8 (add 8 for absolute)
char names[]     // 31 NUL-terminated strings from 0x88..0x2A8
u32 tail_a       // observed 113
u32 tail_b       // observed 30 (== count-1)
```

Observed names (all 31, parser-verified after the Q4 offset fix):

`Story1..Story5`, `Rstory1..Rstory5` (with `Rstory3_race_1/2/3`), `Kstory1..Kstory5`,
`intro_island`, `M_Mecc_L1..L3`, `M_Reaper_L1..L3`, `M_3WAY_L1..L3`, `The_End`,
`M_Mecc_Lw1`, `M_Reaper_Lw1`, `M_3WAY_Lw1`.

## Notes

- The `w_` prefix + these names generate the per-world file set (`W_%s.bin` /
  `<name>.abx` / `<name>.gzp` literals in the exe at `0x0015C164` ff.).
- Tail `{113, 30}` — *inferred*: last-story id + world count sanity; confirm at P1.1.
- Per-language `worldlist%d.bin` variants suggest localized world name tables for the
  mission menu.
