# Decompilation pipeline (system layer)

Prereqs: Ghidra 12.1.2 at `G:/Tools/ghidra_12.1.2_PUBLIC`, JDK in PATH.
Inputs: vanilla exe (read-only), `scripts/re_db.json` (runtime-anchored names),
`ps2_symbols/pc_ps2_matches_full.csv` (378 PC↔PS2 matches).

## One-shot (project already imported)

```
analyzeHeadless.bat G:\VibeRE\GiantsRE\ghidra_projects GiantsRE \
  -process Giants.exe -noanalysis \
  -scriptPath G:\VibeRE\GiantsRE\scripts \
  -postScript ghidra_apply_matches.java G:\VibeRE\GiantsRE\ps2_symbols\pc_ps2_matches_full.csv \
  -postScript ghidra_dump_system.java G:\VibeRE\GiantsRE\scripts\system_names.json \
              G:\VibeRE\GiantsRE\decompiled\system_layer
```

First-time import: replace `-process Giants.exe -noanalysis` with
`-import GameFiles-VanillaV1/Giants.exe -processor x86:LE:32:default -cspec windows`.

## What each script does

- `ghidra_apply_matches.java` — pc_ps2_matches_full.csv: conf≥0.9 → real function
  names (17 applied); conf<0.9 → PLATE comment "PS2 candidate: name (conf)" (317);
  creates functions where Ghidra missed them.
- `ghidra_dump_system.java` — applies `scripts/system_names.json` (generated from
  `scripts/re_db.json`: 43 runtime-anchored function/global labels) then decompiles
  the 16 system-layer anchors to `decompiled/system_layer/*.c` (14/16 ok; the two
  misses were addresses Ghidra didn't turn into functions — fix by adding real
  function starts to re_db and re-running).

## Updating

1. New runtime anchor → add to `scripts/re_db.json` (+ label via apply_labels.py).
2. `python - <<py` regenerate `scripts/system_names.json` from re_db (see git log).
3. Re-run the headless command above; new .c files land in decompiled/system_layer.

## Provenance tags used in file headers

- `runtime` = observed live under x64dbg (breakpoints, args, crash sites)
- `static`  = capstone/Ghidra disassembly
- `res`     = RESSOURCES_FOR_AI (Amazed repos, game_structure.txt, …)
- `ps2`     = SLUS_201.78 symbol table (dev-authored names, same C++ source)
