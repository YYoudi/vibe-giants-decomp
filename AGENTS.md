# AGENTS.md — manuel des workers GiantsRE

Repo de reverse engineering de **Giants: Citizen Kabuto** (GOG 1.4.0 build
1.449, PC x86 32-bit). Tu es un worker d'exécution coordonné par
l'architecte (même responsable que `G:\VibeRE\giants-rs`). La file de
tâches unique des deux repos est `G:\VibeRE\giants-rs\TASKS.md` : les
tâches marquées « repo : GiantsRE » sont les tiennes.

**LIRE D'ABORD [docs/TRUST.md](docs/TRUST.md).** Le corpus est exporté à
100 % (2 807 fonctions), mais ~85 % des noms sont des inférences LLM —
« 100 % nommé » est une couverture, pas une sémantique. Ne crois jamais
un nom (surtout `_cNN`) sans lire le corps décompilé.

## Session type (dans l'ordre)

1. `git pull --rebase` dans ce repo (et dans `giants-rs` si la tâche y
   touche). Ne jamais écrire pendant la session d'un autre agent sans
   pull préalable ; commit + push à la fin de chaque session.
2. Lire `G:\VibeRE\giants-rs\TASKS.md`, prendre la première tâche
   GiantsRE `TODO` dont les dépendances sont `DONE`.
3. Lire exactement les fichiers nommés dans CONTEXTE. Fichier manquant =
   `BLOCKED`, pas une devinette.
4. Travailler selon la MÉTHODE ci-dessous. Toute conclusion distingue
   **observed / derived / inferred** et cite sa source (Evidence ID REA,
   run RuntimeLab horodaté, ou fichier:ligne du corpus).
5. DoD de la tâche atteint → statut `DONE (commit <hash>, <date>)` dans
   TASKS.md, commit (message en anglais, concis, sans trailer IA), push.
   Sinon `BLOCKED: <question précise>` + question dans
   `G:\VibeRE\giants-rs\QUESTIONS_FOR_DECOMP.md`, tâche suivante.
6. Réponses aux questions du moteur : dans
   `G:\VibeRE\giants-rs\QUESTIONS_FOR_DECOMP.md`, au format des réponses
   existantes (citations vérifiables, jamais de prose non sourcée).

## Cible (ground truth)

- **Référence : GOG 1.4.0 (build 1.449)** — `G:\Games\Giants\Giants.exe`
  (1 630 208 octets, déc 2008). **INTOUCHABLE** : on y lit, on y exécute
  le harnais, on n'y écrit jamais (le jeu écrit seul `fps.txt`/saves).
- Corpus : `decompiled/gog144_full/` (export complet + stats) et
  `decompiled/gog144_modules/` (76 fichiers ; les `region_00XX.c` sont
  des **bandes d'adresses**, pas des sources retrouvées — en-têtes
  neutres depuis le 2026-10-16).
- Projet Ghidra de référence : `ghidra_projects_gog144/` (programme
  `Giants.exe`) — source de vérité des renames validés. Structs :
  `giants_types.h`, application fonction par fonction
  (`docs/formats/OBJECT_LAYOUT.md` donne la provenance par champ).
- Symboles PS2 : `ps2_symbols/` (4 769 noms du build PS2 SLUS_201.78) —
  l'ancre de nommage. `python ps2_symbols/lookup.py <motif>`.
- Référence secondaire : `GameFiles-VanillaV1/` (snapshot bit-exact v1.0,
  **lecture seule**). Fichiers CONTAMINÉS (jamais ground truth) :
  `Giants_nocd.exe`, `gg_dx7r.dll`, `libgcc_s_dw2-1.dll`,
  `libstdc++-6.dll`, `libwinpthread-1.dll`, `vfsdump_logo512.tga`
  (dates 2025 = modifiés ; dates 2000 = propres).

## Outils

- **x32dbg + MCP** (vérité runtime) : `G:\Tools\x64dbg\release\x32\x32dbg.exe`
  (jeu 32-bit, UAC requis), HTTP :9095. Token dans
  `G:\Tools\x64dbg\release\x32\mcp_config.json` — **jamais commité**
  (repo public). Premier appel : `GetDebugState` ; chargement :
  `LoadBinary` (paramètre `filePath`) ; cible PAUSED pour lire la
  mémoire. Fallback CLI : `python scripts/xdbg_call.py <Tool> '<json>'`
  (chemins JSON avec `/`). Harnais sans interaction :
  `RuntimeLab/run_gauge.bat` (= `Giants.exe -gamegauge`, monde 3 imposé,
  écrit `fps.txt`).
- **REA** (`mcp__rea__*`, lecture statique + évidence) : `open_binary` →
  `trace_feature` / `search_procedures` / `analyze_function` (Evidence
  `ev_*` à citer) → `close_binary`. Pas de renames via REA sous Windows :
  les renames passent par le bridge Ghidra ci-dessous.
- **Ghidra** 12.1.2 : `G:\Tools\ghidra_12.1.2_PUBLIC`. MCP interactif :
  `RuntimeLab/start_ghidra_mcp.bat` (127.0.0.1:8089, ouvre GOG144.gpr).
  Boucle corpus : `scripts/apply_names_pyghidra.py` (CSV
  `ps2_symbols/llm_waveNN.csv`, seuil 0.9) →
  `scripts/export_decomp_pyghidra.py` → `scripts/build_modules.py`.
- **Parseurs de référence** : `tools_spec/bin_formats.py` +
  `tools_spec/flk_decode.py` (validés par les goldens giants-rs).

## Méthode

1. **Observer** le vrai jeu (breakpoints, harnais `-gamegauge`, ProcMon)
   avant de conclure ; ne jamais deviner quel asset/flow/valeur est pris.
2. **Nommer** depuis les ancres PS2 (string-anchor + call-graph), jamais
   depuis la plausibilité du corps seul.
3. **Réutiliser** `RESSOURCES_FOR_AI/` (repos communautaires, lecture
   seule — pas de réécriture historique).
4. Le code décompilé est de la **documentation** : on transpose des
   constantes et des sémantiques vers giants-rs, on ne copie jamais le C.
5. Oracle runtime = événementiel seulement (les breakpoints par-frame
   s'effondrent sous le dédup) : toute mesure par-frame passe par le
   harnais scripté et des dossiers `RuntimeLab/runs/<horodatage>/`.

## Interdictions absolues

- Écrire dans `G:\Games\Giants`, `GameFiles-VanillaV1/`,
  `RESSOURCES_FOR_AI/`.
- Committer le token x32dbg, un binaire du jeu, ou une capture non
  horodatée présentée comme preuve.
- Affirmer un nom, un offset ou un chiffre sans provenance
  (observed/derived/inferred) — voir `docs/TRUST.md`.
- Réécrire l'historique git ; modifier la structure de
  `giants-rs/TASKS.md` ou les gates de giants-rs.
- Demander à l'humain un choix technique : il est testeur visuel
  uniquement. Blocage = `BLOCKED` écrit, pas une question orale.

## Git

- Repo public : `origin` → github.com/YYoudi/vibe-giants-decomp.
- `pull --rebase` avant push ; messages en anglais, concis (ce qui a été
  reversé + statut) ; aucun trailer `Co-Authored-By`.
- Un commit par session de travail terminée ; jamais de demi-tâche
  commitée comme finie.
