# HANDOFF: canonical target pivots to vanilla 1.0

**Decision (human, 2026-06-16):** The canonical reverse target is now **vanilla 1.0
retail** (`GameFiles-VanillaV1/Giants.exe`). The 1.520.59 work is NOT discarded — it
transfers as gameplay-core knowledge. Post-1.4 community patches are **reimplemented by
us**, not inherited. Renderer strategy: reverse the **DX7 vanilla renderer**, then write a
fresh **DX12** renderer (skip the community DX8/9/11 chain).

## What's in version_bridge/

| File | Purpose |
|------|---------|
| `ghidra_proj/VanillaProj` | **Ghidra project with vanilla Giants.exe analyzed.** Open this to work on vanilla. |
| `vanilla_functions.jsonl` | 2574 vanilla functions: addr, size, callees, strings, mnemonic fingerprint. |
| `VERSION_MAP_full.csv` | **The bridge**: 461 1.5→vanilla function pairs, with confidence + origin (seed=string-confirmed, propagated=call-graph). |
| `VERSION_MAP.csv` | 123 string-confirmed pairs with identity tier (IDENTICAL/NEAR/MODIFIED). |
| `ExportFunctions.java` | Ghidra export script (rerun if you re-analyze). |
| `build_version_map.py`, `propagate_map.py` | Regenerate the map. |

## The numbers — how identical is 1.5 to vanilla?

- vanilla functions discovered: **2574** | 1.520.59: **6254** (1.5 grew +76 % .text).
- 1.5 functions mapped to a vanilla counterpart: **461** (17 % of vanilla covered)
  - 123 string-confirmed (conf 1.0), of which 8 IDENTICAL / 13 NEAR / 102 MODIFIED
  - 338 call-graph-propagated (conf 0.4–0.8)
- The 461 is a **bootstrap**, not exhaustive. Reconcile the rest interactively with both
  Ghidra projects open (1.5 `ghidra_projects/GiantsRE` + vanilla `version_bridge/ghidra_proj/VanillaProj`).

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
