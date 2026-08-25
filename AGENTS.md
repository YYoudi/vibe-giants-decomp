# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

# GIANTS: CITIZEN KABUTO — Reverse Engineering (v1.0 PC, x86 32-bit)

## CIBLE (Ground Truth)

- **Binaire de référence : `GameFiles-VanillaV1/Giants.exe`** — PE32, 1 634 304 octets, daté 30 nov 2000 (v1.0 retail).
  MD5 `330c6a9a8ab0fa4b0173d925e1d5ec27`. Image base `0x400000`, entry `0x547358`.
- ⚠️ **Fichiers contaminés** dans `GameFiles-VanillaV1/` (modifiés lors de sessions précédentes — NE PAS utiliser
  comme ground truth) : `Giants_nocd.exe`, `gg_dx7r.dll`, `libgcc_s_dw2-1.dll`, `libstdc++-6.dll`,
  `libwinpthread-1.dll`, `vfsdump_logo512.tga` (dates 2025 = modifiés ; dates 2000 = propres).
- Renderers DX7 propres disponibles : `RESSOURCES_FOR_AI/Giants Mecc Demo/gg_dx7r.dll` (jan 2001) et
  `Giants Reaper Demo/gg_dx7r.dll` (fév 2001). Interface renderer : `GDVSysCreate` / `GFXGetCapabilities` / `UpCallsLoad`.

## OUTIL PRINCIPAL : x64dbg via MCP (observation runtime)

**La mesure = OBSERVER LE VRAI JEU DANS LE DEBUGGER. On ne devine JAMAIS un comportement non observé.**

1. **Lancer le debugger d'abord** : `G:\Tools\x64dbg\release\x32\x32dbg.exe` (x32dbg — le jeu est 32-bit).
   Le plugin MCP démarre automatiquement : HTTP sur `http://localhost:9095/`, token Bearer dans
   `G:\Tools\x64dbg\release\x32\mcp_config.json` (serveur MCP déjà enregistré dans Claude Code en scope *local* —
   le token ne doit JAMAIS être commité, le repo est public).
2. **Outils MCP** (`mcp__x64dbg__*` après rechargement de session) :
   - `GetDebugState` — TOUJOURS l'appeler en premier (état, PID, adresse courante).
   - `LoadBinary` — paramètre **`filePath`** (pas `path`). Charge l'exe et pause au breakpoint système.
   - `ExecuteDebuggerCommand` — **escape hatch universel** : toute commande x64dbg
     (`bp`, `bpx`, `bc`, `g`, `r`, `dump`, `disasm`, `SetBPX`, etc.).
   - `SearchForStrings` — paramètre **`searchText`**. `EvalExpression`, `GetEventLog`, `AttachProcess`, `ListCommandsByCategory`.
   - La cible doit être **PAUSED** pour lire mémoire/disassembler.
3. **Fallback CLI** (marche même sans outils MCP dans la session) :
   `python scripts/xdbg_call.py <ToolName> '<json-args>'` — lit token/port tout seul depuis `mcp_config.json`.
   Utiliser des `/` dans les chemins JSON (bash mange les `\`).
4. Debugger statique : Ghidra à `G:\Tools\ghidra_12.1.2_PUBLIC` (analyse batch/headless si besoin).

## MÉTHODE (dans l'ordre)

1. **OBSERVER le vrai jeu en runtime** (breakpoints x64dbg sur APIs Win32 / entry du module / strings)
   → jamais deviner quel asset est chargé, quel flow est pris, quelle valeur est passée.
2. **NOMMER** les fonctions PC vanilla via `ps2_symbols/` (4769 fonctions nommées du binaire PS2 SLUS_201.78,
   même code source C++). Pipeline de matching string-anchor + call-graph : voir `ps2_symbols/README.md`.
   `python ps2_symbols/lookup.py <motif>` pour chercher.
3. **Réutiliser les 14 repos d'Amazed** (`RESSOURCES_FOR_AI/git_repos_from_amazed/`) — RE clean-room des formats
   GZP/GTI/GBS/SKN/ANM/.BIN, décompression LZ (`gck-map-extract-objects/lib/fileutils.py` = décompresseur canonique).
4. **Compléments** : `RESSOURCES_FOR_AI/sent_by_Amazed/` (debug.exe + doc, prototype PS2 ISO 2001, docs
   mécaniques du jeu, maps, outils), `RESSOURCES_FOR_AI/Patches_extracts/` (patches 1.4→1.520 avec renderers
   DX9/DX11/DX12 — utiles pour comprendre l'interface renderer), `RESSOURCES_FOR_AI/GiantsTools` + `GiantsEdit`
   (C#), `RESSOURCES_FOR_AI/GiantZiP` (Delphi, format GZP).

## RÈGLES D'AUTONOMIE

- **Agent pleinement autonome** : l'humain est uniquement testeur visuel (0 connaissance RE). Ne jamais lui
  demander d'installer un outil, deviner une data, ou choisir une techno. Il manque un outil → l'installer
  (`pip`, `curl`, terminal, internet) ou l'écrire.
- Pas de code custom/inventé dans une éventuelle recomp : tout est validé bit-à-bit vs l'original.
- Ne jamais modifier les fichiers ground truth de `GameFiles-VanillaV1/` — travailler sur des copies.

## GIT

- Repo **public** : `origin/main` → https://github.com/YYoudi/vibe-giants-decomp. Commit+push = sauvegarde
  (un crash perd le cycle sinon).
- Messages de commit en **anglais**, concis (ce qui a été reversé + statut).
- `pull --rebase` avant push ; si rejet, rebase + retry.
- **JAMAIS** de trailer `Co-Authored-By` ni mention de Claude/AI dans les commits.
