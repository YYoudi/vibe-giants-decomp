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

## Interactive mode: ghidra-mcp (bethington) — PREFERRED

A 226-endpoint MCP server runs headless (no GUI) against the shared project:

```
# one-time: build + install (done 2026-08-28)
cd G:/Tools/ghidra-mcp
M2_HOME=G:/Tools/maven/apache-maven-3.9.9 python -m tools.setup preflight --ghidra-path G:/Tools/ghidra_12.1.2_PUBLIC
M2_HOME=... python -m tools.setup ensure-prereqs --ghidra-path ... && python -m tools.setup build
# extension installed at G:/Tools/ghidra_12.1.2_PUBLIC/Ghidra/Extensions/GhidraMCP
# launcher bat: RuntimeLab/start_ghidra_mcp.bat

# every session (background):
cmd //c G:/VibeRE/GiantsRE/RuntimeLab/start_ghidra_mcp.bat
#   -> HTTP 127.0.0.1:8089, opens ghidra_projects/GiantsRE.gpr (renames included)
curl http://127.0.0.1:8089/open_project      -d '{"path":"G:/VibeRE/GiantsRE/ghidra_projects/GiantsRE.gpr"}'
curl http://127.0.0.1:8089/load_program_from_project -d '{"path":"/Giants.exe"}'
```

Key REST calls (params are QUERY unless noted; body = JSON):

| Action | Call |
|---|---|
| decompile one | `POST /decompile_function?address=0x53AE80` |
| decompile many | `POST /decompile_function?functions=0x53AE80,0x53B490` → `{addr: C}` |
| list functions | `GET /list_functions?limit=&offset=` |
| search strings | `GET /list_strings` / string-anchored discovery tools |
| xrefs | xref endpoints (`/get_xrefs_...`) |
| rename | `POST /rename_function` (old, new) — feeds the shared project |
| comments/types/structs | dedicated write endpoints (253 tools total) |

Python bridge (MCP stdio for ZCode) is registered in `~/.zcode/cli/config.json`:
`{"command":"python","args":["-m","bridge_mcp_ghidra"]}` — bridge default target is
exactly `http://127.0.0.1:8089`, so no extra config. Tools appear after session reload.

### Workflow loop (updated — replaces "rerun headless for every change")

1. Observe runtime anchor (x64dbg) → add to `scripts/re_db.json`.
2. While the headless server is up: `POST /rename_function` directly + bulk-decompile
   via `/decompile_function?functions=...` and save to `decompiled/system_layer/`.
3. Periodically commit project state by running the headless `-postScript` pair once
   (rarely needed; interactive writes already persist to the project on save/close).
