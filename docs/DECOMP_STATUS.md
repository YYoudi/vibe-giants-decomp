# Decompilation status — Giants v1.0 PC (Giants.exe)

Snapshot 2026-08-28. Regenerate anytime: `RuntimeLab/run_decompile_all.bat`
(needs the Ghidra project `ghidra_projects/GiantsRE.gpr` — contains all renames).

## Numbers

| Metric | Value |
|---|---|
| Functions in .text (non-thunk) | **2575** |
| Decompiled (0 failures) | **2575 / 2575 (100%)** |
| Skipped: "functions" beyond .text | 211 (Ghidra artifacts in .data — not code) |
| Named (dev/PS2/runtime names) | **78 (3.0%)** |
| PS2 candidate plates | 298 |
| Full dump | `giants_v1_full_decomp.c.gz` (5.0 MB raw / 0.7 MB gz) |
| Function index | `full_index.json` (va → name, named?, size) |

## Where the names come from (78)

- 17 conf≥0.9 PC↔PS2 string-anchor matches (teammecc_set_mode, chat_init,
  smartie_move, mecc_shot, …)
- 19 more at conf 0.6–0.9 (tier "apply, light review")
- 36+ runtime-anchored system names (re_db.json): cd_check, BinFileRead,
  gzp_*/VFS cluster, gti_terrain_load, gtext_load/lookup, tagged allocator,
  bin/abx loaders, video-init site …

## Known gaps / next levers (ranked)

1. **Naming scale-up** — 78/2575 named. Levers:
   - grow PC↔PS2 matching: the string-anchor+propagate pipeline stopped at 378;
     feed it ALL PS2 4769 names against the now-complete dump (decomp strings
     instead of raw disasm) — expect a large second wave.
   - runtime anchors: level-load trace (menu→campaign) names the gameplay core.
2. **133 decompile failures** in the 0x57c000–0x585000 cluster (pcode
   "Unable to resolve constructor" warnings) — tail of .text, likely post-1.0
   patch padding or obfuscated stubs; investigate with capstone manually.
3. **211 .data "functions"** skipped — confirm none are real (thunk tables?).
4. Duplicate PS2 name collisions (one PS2 fn ↔ several PC copies) currently
   fall back to plates — resolve with call-graph consistency instead of
   first-wins.

## Regeneration

```
RuntimeLab\run_apply_names.bat      # tiered PS2 naming into the project
RuntimeLab\run_decompile_all.bat    # full dump + index + stats (≈20 min)
```
Project: `ghidra_projects/GiantsRE.gpr` (single Ghidra lock — stop the MCP
headless server on :8089 before running).
