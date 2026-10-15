# GiantsRE — Reverse Engineering of Giants: Citizen Kabuto

AI-assisted, clean-room reverse engineering of **Giants: Citizen Kabuto** (PC, x86 32-bit).
No game code or assets are recreated here from scratch: everything is derived by analysis
(Ghidra decompilation + runtime observation) and documented in this repo.

**Current status (re-verified 2026-10-16): the GOG 1.4.0 build (1.449) corpus is fully exported**
— 2 807 non-thunk functions, done=2807 failed=0 (see decompiled/gog144_full/stats.txt).
**Naming is coverage, not truth**: ~15 % of names are anchored on real PS2 symbols, the rest are
LLM inferences (some flatly wrong, e.g. ANM_BinderDestroy_3 is atoi). Read docs/TRUST.md before
trusting any name, and verify the decompiled body.

## What's in the repo

| Path | Content |
|---|---|
| `decompiled/gog144_full/` | Full decompiled corpus of GOG 1.449 (`all_decompiled.c.gz` + `index.json` + `stats.txt`) |
| `decompiled/gog144_modules/` | Same corpus split into 76 per-module `.c` files (`_INDEX.md` to navigate) |
| `decompiled/v10_v149_bytemap.csv` (+ `_propagated.csv`, `_stringmatch.csv`) | Cross-version address mapping (vanilla 1.0 ↔ 1.449) |
| `ps2_symbols/` | 4 769 named functions from the unstripped PS2 build (SLUS_201.78) used as naming ground truth, plus per-wave naming ledgers (`llm_waveNN.csv`: address, name, evidence note) |
| `scripts/` | The tooling: `apply_names_pyghidra.py`, `export_decomp_pyghidra.py`, `build_modules.py`, `dump_callgraph_pyghidra.py`, `cross_version_map.py`, x64dbg MCP bridge (`xdbg_call.py`), … |
| `RuntimeLab/` | Runtime lab: boot recipes, filtered logs (no game binaries) |
| `docs/` | Format inventory, decomp pipeline, **handoff docs for the Rust+Bevy reimplementation**: `docs/systems/*.md` (sim loop, collision, renderer, audio, AI, netcode, mission/flick VM verdict), `docs/formats/*.md`, `docs/specs/formats.json` (machine-readable), `docs/constants/`, `docs/RUNTIME_TRACES.md` (oracle protocol) |
| `tools_spec/` | Python validation parsers per format (`bin_formats.py`) |
| `AGENTS.md` | Operating manual for the RE agent (tools, method, rules) |

## Reference targets

- **Primary reference: GOG 1.4.0 (build 1.449)** — `G:\Games\Giants\Giants.exe`,
  fully decompiled and named; Ghidra project in `ghidra_projects_gog144/` (not committed,
  regenerable from the exe + `ps2_symbols/`).
- **Secondary reference: vanilla v1.0 retail** — bit-exact snapshot kept locally
  (`GameFiles-VanillaV1/`, not committed) for inter-version comparisons and any future
  bit-exact recomp validation.

## Reproduce the corpus

```bash
# after importing G:\Games\Giants\Giants.exe into ghidra_projects_gog144 (Ghidra 12.1.2)
python scripts/apply_names_pyghidra.py ps2_symbols/llm_wave226.csv   # …repeat per wave CSV
python scripts/export_decomp_pyghidra.py
python scripts/build_modules.py
```

## Legal

This repository contains **no copyrighted game assets**: no binaries, no art, no audio,
no game screenshots (captures are git-ignored and stored locally only). Decompiled output
and analysis notes are for interoperability / preservation research.
