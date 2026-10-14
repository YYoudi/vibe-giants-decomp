# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

# GIANTS: CITIZEN KABUTO — Reverse Engineering (GOG 1.449 PC, x86 32-bit)

## CIBLE (Ground Truth)

- **Binaire de référence : GOG 1.4.0 (build 1.449)** — `G:\Games\Giants\Giants.exe` (1 630 208 octets, daté
  déc 2008). Image base `0x400000`. **Décompilé à 100 % et nommé à 100 %** (2026-10-14) : 2 807 fonctions
  non-thunk, `done=2807 failed=0 named=2807` — voir `decompiled/gog144_full/stats.txt`, corpus complet dans
  `decompiled/gog144_full/all_decompiled.c(.gz)` + modules `decompiled/gog144_modules/`.
- **Projet Ghidra de référence : `ghidra_projects_gog144/`** (programme `Giants.exe`) — tous les renames validés
  y sont appliqués ; c'est LA source de vérité des noms. Mapping v1.0↔1.449 : `decompiled/v10_1449_ranges.json` +
  `decompiled/v10_to_v149_map.json` (générés par `scripts/cross_version_map.py`).
- **Référence secondaire : vanilla v1.0 retail** — `GameFiles-VanillaV1/Giants.exe` (PE32, 1 634 304 octets,
  30 nov 2000, MD5 `330c6a9a8ab0fa4b0173d925e1d5ec27`, entry `0x547358`). Snapshot bit-exact conservé pour les
  comparaisons inter-versions (REA `compare_functions`/`find_changed_behavior`) et toute éventuelle validation
  bit-à-bit de recomp — ne plus s'y calquer pour l'analyse courante.
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
4. Debugger statique : Ghidra à `G:\Tools\ghidra_12.1.2_PUBLIC` (analyse batch/headless si besoin ; c'est la même
   install que REA auto-détecte, voir section REA).

## OUTIL REA — MCP `mcp__rea__*` (lecture statique + ledger d'évidence ; installé/validé 2026-10-12)

**REA = couche LECTURE/ÉVIDENCE statique sur Ghidra headless 12.1.2 + captures runtime contrôlées.**
Skill : `reverse-engineer-anything` (doc : https://rea.tools/get-started/). Rien à lancer : outils MCP
`mcp__rea__*` déjà connectés dans la session. `binary_session` = check d'état (doit répondre `{open:false, ...}` au repos).

1. **Boucle statique PE** : `open_binary` (chemin absolu de l'exe, cible PAUSED pas requis — lecture fichier) →
   `trace_feature` (ancre string → strings → xrefs → procédures conteneuses : cœur du matching PS2 wave-2),
   `search_procedures` / `search_strings`, `list_procedures`, `analyze_function` (dossier complet avec Evidence),
   `procedure_pseudo_code` / `procedure_assembly`, `xrefs`, `get_call_graph`, `batch_decompile`, `read_bytes`,
   `inspect_native_data_type`. `close_binary` en fin d'investigation.
2. **Évidence** : chaque opération produit un Evidence ID (`ev_*`). Citer les IDs dans les conclusions ; distinguer
   observed / derived / inferred ; ne jamais présenter du statique comme de l'exécution observée.
   `get_evidence_bundle` (résumé) et `export_evidence_bundle` (export complet vers un chemin) pour sauver/passer
   une session — utile comme sauvegarde avant un crash.
3. **Comparaisons inter-versions** (v1.0 vs GOG 1.449) : `compare_functions` (identity/pseudocode/calls/cfg…),
   `compare_artifacts`, `find_changed_behavior` — différences exactes, digest-anchored, sans fuzzy matching.
4. **Limites Windows (attendues, pas des pannes)** : PAS de renames/commentaires via REA
   (`annotate_native_function` bloqué — le Ghidra P0 Windows refuse la mutation de base) → **les renames restent
   dans le bridge ghidra-mcp ci-dessous**. Import headless éphémère : pas de persistance d'analyse entre sessions
   REA. Outils natifs macOS indisponibles (sans objet pour du PE x86).

**Répartition des rôles** : x64dbg = vérité runtime · REA = lecture statique + évidence + comparaisons ·
bridge ghidra-mcp = renames + projet persistant · analyzeHeadless = passes batch complètes.

## MÉTHODE (dans l'ordre)

1. **OBSERVER le vrai jeu en runtime** (breakpoints x64dbg sur APIs Win32 / entry du module / strings)
   → jamais deviner quel asset est chargé, quel flow est pris, quelle valeur est passée.
2. **NOMMER** les fonctions via `ps2_symbols/` (4769 fonctions nommées du binaire PS2 SLUS_201.78,
   même code source C++). Pipeline de matching string-anchor + call-graph : voir `ps2_symbols/README.md`.
   `python ps2_symbols/lookup.py <motif>` pour chercher. Depuis 2026-10 : les lectures d'ancres, xrefs et
   decomp du matching passent par REA (`trace_feature`, `analyze_function`… — section REA) ; les renames
   validés sont appliqués via le bridge ghidra-mcp dans `ghidra_projects_gog144/`.
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
- Ne jamais modifier les fichiers des snapshots de référence (`GameFiles-VanillaV1/` pour v1.0 ;
  l'install GOG `G:\Games\Giants\` pour 1.449) — travailler sur des copies.

## GIT

- Repo **public** : `origin/main` → https://github.com/YYoudi/vibe-giants-decomp. Commit+push = sauvegarde
  (un crash perd le cycle sinon).
- Messages de commit en **anglais**, concis (ce qui a été reversé + statut).
- `pull --rebase` avant push ; si rejet, rebase + retry.
- **JAMAIS** de trailer `Co-Authored-By` ni mention de Claude/AI dans les commits.

## OUTIL GHIDRA MCP INTERACTIF (bethington/ghidra-mcp, installé 2026-08-28)

- Serveur headless : `cmd //c G:/VibeRE/GiantsRE/RuntimeLab/start_ghidra_mcp.bat`
  (HTTP 127.0.0.1:8089, ouvre ghidra_projects_gog144/GOG144.gpr — le projet de référence 1.449).
- MCP dans ZCode : serveur stdio `python -m bridge_mcp_ghidra` (déjà enregistré,
  scope user, avec x64dbg). 253 outils : décomp unitaire/bulk, renames, xrefs,
  strings, types/structs, scripts, émulation P-code.
- Boucle decomp courante (100 % faite, à réutiliser pour toute reprise) :
  `scripts/apply_names_pyghidra.py` (applique les CSV `ps2_symbols/llm_waveNN.csv`, seuil conf 0.9)
  → `scripts/export_decomp_pyghidra.py` (corpus complet + index + stats)
  → `scripts/build_modules.py` → gzip → commit. Ancienne boucle re_db.json/system_layer : docs/DECOMP_PIPELINE.md.
- Runner headless classique (analyzeHeadless + scripts Java) reste pour les
  passes batch complètes.
