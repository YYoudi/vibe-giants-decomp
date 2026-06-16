# HANDOFF: canonical target pivots to vanilla 1.0

**Decision (human, 2026-06-16):** The canonical reverse target is now **vanilla 1.0
retail** (`GameFiles-VanillaV1/Giants.exe`). The 1.520.59 work is NOT discarded — it
transfers as gameplay-core knowledge. Post-1.4 community patches are **reimplemented by
us**, not inherited. Renderer strategy: reverse the **DX7 vanilla renderer**, then write a
fresh **DX12** renderer (skip the community DX8/9/11 chain).

## What's in version_bridge/

| File | Purpose |
|------|---------|
| **`VERSION_MAP_v2.csv`** | **PRIMARY bridge (collision-free)**: 1247 1.5→vanilla pairs, tiered EXACT/HIGH/MEDIUM/LOW with all signals + PS2 name. Use this. See `VERSION_MAP_v2.md`. |
| `VERSION_MAP_v2.md` | How to use v2, the merges, the fingerprint-weakness finding, validation. |
| `recomp_functions.jsonl` | 6254 1.5 functions: addr, size, callees, strings, mnemonic fingerprint (exported via `ExportFunctions.java`). |
| `vanilla_functions.jsonl` | 2574 vanilla functions: addr, size, callees, strings, mnemonic fingerprint. |
| `match_fingerprint.py` | Regenerate v2 (the reliable multi-signal matcher). |
| **`PATCH_LAYER_CLASSIFICATION.md`** | **What in `/src/` is patch-only / DX9+**: 3-bucket stratification (vanilla-core ~694 files / COM+DX9 quarantine 10 files / diagnostic tooling). Answers "how to handle the DX9+ `/src/` content now that vanilla is canonical." |
| `VERSION_MAP_full.csv` | *(legacy)* old call-graph map, 461 pairs — **had 20 collisions, superseded by v2.** |
| `VERSION_MAP.csv` | *(legacy)* 123 string-confirmed pairs (pre-uniqueness). |
| `ghidra_proj/VanillaProj` | Ghidra project with vanilla Giants.exe analyzed. Open this to work on vanilla. |
| `ExportFunctions.java` | Ghidra export script (rerun if you re-analyze either binary). |
| `build_version_map.py`, `propagate_map.py` | *(legacy)* regenerate the old map. |

## The numbers — how identical is 1.5 to vanilla?

- vanilla functions: **2574** | 1.520.59: **6254** (1.5 grew +76 % .text).
- **v2 map: 1247 pairs (48 % of vanilla covered)** — collision-free.
  - 257 reliable (EXACT 14 / HIGH 114 / MEDIUM 129) + 990 LOW hints.
  - **The old 461-pair map had 20 collisions (~11 % corrupted) — superseded.**
- **Critical finding**: the compiler changed between vanilla and 1.5, so mnemonic
  fingerprints are weak cross-version (correct match Jaccard ~0.19). Reliable signals
  are: shared rare strings > size > call-graph topology > fingerprint.
- **6 genuine many-to-1 merges** where 1.5 split a vanilla function (notably vanilla
  `005222c0` = InitializeEngine + MainGameLoop merged). See `VERSION_MAP_v2.md`.
- Reconcile the rest interactively with both Ghidra projects open
  (1.5 `ghidra_projects/GiantsRE` + vanilla `version_bridge/ghidra_proj/VanillaProj`).

## How to carry your 1.5 knowledge onto vanilla

For each row in `VERSION_MAP_full.csv`:
- `1.5_addr` → `vanilla_addr` is the same function. Your 1.5 reverse (semantics, types,
  PS2 name) applies at the **vanilla_addr** as canonical provenance.
- conf 1.0 (seed): transfer verbatim. conf 0.6–0.8: transfer, light re-verify.
  conf 0.4: candidate, verify in Ghidra.
- 1.5 functions NOT in the map are either (a) patch-added (1.5-only → reimplement) or
  (b) unmatched utility funcs → reconcile interactively.

Example: 1.5 `FUN_0062e1a0` (InitializeEngine) → vanilla `0x005222c0`. `FUN_0062af40`
(InitAudioSystem) → vanilla `0x0051f900`. Consistent ~−1 MB shift.

## Renderer pivot (your current wall)

- Stop reversing 1.5's DX9 renderer / engine-context registry as the path forward.
- Vanilla is **DX7-only** (`gg_dx7r.dll`, 127 KB) — no DX8/9, no multi-renderer in-exe.
- Reverse `gg_dx7r.dll::GDVSysCreate` + `UpCallsLoad` for the **minimal engine→renderer
  contract WITHOUT the COM registry**. The registry becomes a documented 1.4/1.5 delta.
- This DX7 contract = the spec for your eventual fresh DX12 renderer.
- Reference: `RESSOURCES_FOR_AI/Giants Reaper Demo/RE_ASSESSMENT.md` + `ps2_symbols/`.

## Rules (preserve the main agent's work)

- `version_bridge/` is PS2/multi-version-agent territory. You consume it **read-only**.
- Don't touch `GameFiles-VanillaV1/` (reference oracle, read-only).
- Your files (`src/`, `proxy/`, `CMakeLists.txt`, `recomp_stub_renderer.cpp`,
  `.gitignore`, `ghidra_exports/`) remain yours — untouched.
- Coordinate `git push` (stash → pull --rebase → push → pop) since both agents push.
