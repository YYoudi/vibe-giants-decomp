# giants-advance

**Le SEUL skill pour faire avancer le projet** — recomp 100%-identique de Giants: Citizen Kabuto (vanilla 1.0 DX7). Tu tournes en continu, tu délègues (subagents) ou fais plusieurs choses pour **toujours progresser**. Cycle : `mesure → spec → implémente → build → VÉRIFIE → commit`. Un cycle = un commit.

## ⚑ STRATÉGIE : TU DÉCIDES SEUL (ne demande JAMAIS de choix à l'humain)
**C'est TOI qui choisis les avancées stratégiques — tu t'y connais mieux que l'humain.** Ne pose JAMAIS de question « option A ou B ? » à l'humain. Tu évalues, tu décides, tu fais. L'humain est **testeur visuel uniquement, sur ta demande expresse** (et seulement pour du subjectif qu'aucun outil ne peut trancher — un rendu « ressemble-t-il à l'original »). Pour TOUT le reste (architecture, techno, ordre des chantiers, quel outil bâtir), tu tranches seul.

**Remets TOUJOURS tes outils en question.** À chaque cycle, demande-toi : « un meilleur outil accélérerait-il ça ? » S'il te manque quelque chose (proxy, capture, diff, debugger, asm-diff, RenderDoc, Frida script, automatisation), **construis-le ou installe-le TOI-MÊME**. Tu as internet (`curl`/`pip`) + terminal + 800k contexte. **Teste-le, ne demande pas.** Le proxy DX7, capdiff, appsnap, les flags de phase — tous bâtis ainsi. Continue ce mouvement.

## ⚑ PRINCIPE : OBSERVATION RUNTIME AVANT CODE + PREUVE AVANT DE CLAMER
1. **OBSERVATION RUNTIME (suprême)** : pour TOUT comportement observable, tu DOIS d'abord **OBSERVER
   le vrai jeu en RUNTIME** — pas lire le code Ghidra. OBSERVER = hook Frida (fichiers ouverts,
   fonctions appelées) + proxy DX7 (SetTexture/SetTransform/DrawPrimitive avec args) + appsnap
   (capture écran). L'analyse STATIQUE (lire le décompilé) est utile pour PORTER mais n'est PAS
   une observation. Workflow obligatoire :
   (a) **OBSERVER** l'original en runtime → quels assets chargent, quel renderer appelé, quel caméra.
   (b) **DOCUMENTER** l'observation → `behavior_specs/`.
   (c) **PORTER** le code vanilla du décompilé.
   (d) **VÉRIFIER** le recomp matche l'observation.
   **NE JAMAIS deviner quel asset le jeu charge** (Giants_logo_512 deviné du GZP index = DÉRIVE).
   **NE JAMAIS écrire de code de rendu sans avoir observé l'original faire ce rendu**.
2. **Succès = preuve, pas « ça tourne + visible »**. Deux modes de preuve :
   - **Visuel** → `tools/run.sh <phase>` (capdiff vs original) doit **PASS**.
   - **Bit-exact** → proxy/oracle dual-mode, **0 mismatch**.

## Cible canonique : VANILLA 1.0
`GameFiles-VanillaV1/Giants_nocd.exe` (vanilla 1.0, DX7 `gg_dx7r.dll`, 2 exports, 21 callbacks, engineCtx=NULL). **100% vanilla-only** — the 1.5/DX9 path was PURGED 2026-06-18 (it caused version/address drift: the Ghidra project was v1.5 GiantsMain.exe, not vanilla). Original oracle = `Giants_nocd.exe`.

## Contexte (LIS EN PREMIER)
- **CLAUDE.md §0** — doctrine + règles fidélité observable 5-10. OVERRIDE tout.
- **`behavior_specs/`** — specs mesurées (boot chain, intro timings 0.2s/12s, loading=giants_loading PAS int_loadisland, menu 3D+2D).
- **`vanilla_decompiled/*.json`** — corps vanilla (provenance). Index: `ls vanilla_decompiled/` (regenerated from vanilla Giants_nocd.exe via ghidra_projects/VanillaProj).
- **`RE_docs/DX7_RENDERER_CONTRACT.md` + `DX7_METHOD_MAP_v2.md` + `DX7_RENDER_RECIPE.md`** — contrat (21 callbacks, table 0x57c, 57 slots mappés).
- **Mémoires** (`.../memory/`) — `overnight-2026-06-18-batch.md` (état courant callees), `dx7-minimal-contract.md`, `boot-sequence-and-3d-terrain.md`, `scene-load-roadmap.md`, `giants-format-specs.md`.
- **`git log --oneline -20`** — où on en est.

## Outils (OBLIGATOIRES — choisis selon le mode de preuve)
**Visuel (capdiff)** : `tools/run.sh <phase> [compare|recomp|original] [norebuild]` (build→deploy→capture→diff, rc 0=PASS/1=FAIL/2=capture-fail). `tools/capdiff.py` (capture recomp flags-phase + original Giants_nocd + diff PIL). Original via PowerShell Start-Process (segfault sous subprocess) ; 4s relâchement DX7 entre les deux (même gg_dx7r.dll).
**Flags phase recomp (C1)** : `-skip-intros`, `-at menu`, `-at level:<name>`, `-frames N`, `-no-audio`. (`-skip-intros -frames 200` atteint le menu en ~5s vs ~15s.)
**Frida** (`scripts/frida_*.js`) — capture timing/séquence de l'original + RPC. **`appsnap`** (`uvx appsnap -o <png> "Giants"`) capture ponctuelle. `-t 100` match strict.

## Workflow (BOUCLER — OBSERVER → DOCUMENTER → PORTER → VÉRIFIER)
1. **OBSERVER l'original en RUNTIME** (suprême, avant tout code) :
   - Hook Frida callback[17] VFSOpenFile → quels fichiers le jeu ouvre, dans quel ordre.
   - Proxy DX7 → quels SetTexture/SetTransform/DrawPrimitive, avec quels args.
   - appsnap → ce qui s'affiche à l'écran.
   - Sans observation = tu devines = DÉRIVE.
2. **DOCUMENTER** l'observation comme spec (`behavior_specs/<x>.md`). Une spec = une observation runtime, pas une lecture de code.
3. **DIAGNOSTIQUER** : lire la fonction vanilla dans `vanilla_decompiled/`. Vérifier qu'elle est sur le chemin exécuté (ne porte pas du code mort). Utiliser les noms PS2 (`ps2_symbols/`) pour identifier.
4. **PORTER** le corps vanilla en C++ dans `src_vanilla/`. Citer les DAT_. Vérifier la règle asset-display (prouvée par runtime, pas par GZP index).
5. **Build** : `bash tools/build.sh GiantsMain_vanilla`. Vert.
6. **VÉRIFIER** : capdiff PASS (visuel) OU proxy 0-mismatch (bit-exact). FAIL = fixe le recomp, n'affaiblis pas la spec.
7. **Commit + push** : `git add -u && git commit -q -m "RE(...): ..."` (EN, pas de trailer Claude, guard secret/lourds).
8. **Reboucle**. **Priorise toujours ce qui débloque le plus** (observer l'original > porter du code > deviner).

## Classification des fonctions (choisis la validation)
| Classe | Validation | Autonomie |
|--------|-----------|-----------|
| **Pure** (feuille, déterministe) | self-test bit-exact (proxy) | 100% |
| **Stateful déterministe** | shadow-predict (prédit → originale → compare → retourne originale) | 100% |
| **Stateful complexe / I-O** (FS, audio, rendu) | swap-and-run + capdiff visuel | capdiff auto, humain si subjectif |
Classifier via `vanilla_functions.jsonl` : callees vides + pas de global muté ⇒ pur.

## Chantiers (toujours progresser — choisis par impact)
**Axe visuel (menu/île 3D fidèle)** : câbler la chaîne boot réelle `FUN_004913c0→FUN_0045a530→FUN_004b7c50(makewrld+placements+SFX...)→FUN_004f3230` pour que la scène se peuple. **CLEF : FUN_0053a3e0 (asset loader) est le pont — le porte (via VanillaVFS::GzpReadFile) puis câble le loader → `compare menu` doit PASS.**
**Bit-exact (proxy)** : capture les 21 callbacks vanilla via le proxy C5, valider chaque impl du recomp (callback table VanillaRenderer.cpp) en dual-mode 0-mismatch.
**Autonomes (trace/oracle, pas d'œil)** : portage callees sur le chemin boot, VFS, audio, mapping 55 méthodes renderer, init-chain.

## Règles
- **AUCUN CODE PRÉCÉDENT N'EST ACQUIS (suprême).** Tout code dans `src_vanilla/` est une
  **hypothèse non prouvée**, pas une vérité. Build vert ≠ fidèle ; « ça tourne » ≠ « ça reproduit ».
  À CHAQUE cycle : ne suppose JAMAIS que le code courant est correct parce qu'il existe déjà.
  Re-vérifie-le contre l'observation runtime ; si une découverte contredit le code actuel →
  **remplace-le** (jette le travail faux, ne le préserve pas). Une hypothèse ne se prouve QUE par
  capdiff PASS ou proxy 0-mismatch. **État 2026-06-19 : 0 reproduction valide observée** → tout le
  recomp est non prouvé, à invalider/remplacer, pas une fondation. L'observation de l'original
  prime sur tout code existant.
- **Anti-dérive** : pas de code custom/inventé. Diagnostic stub isolé/étiqueté. (1.5/DX9 PURGED — vanilla-only.)
- **Mesure avant code** + **asset-display** + **succès = preuve (capdiff PASS / proxy 0-mismatch)**.
- **Preuve avant assemblage** : n'assemble que du prouvé (Ghidra vanilla vérifié OU 0 mismatch).
- **Build = série** (1 make, `tools/build.sh` lock). Subagents : `g++ -fsyntax-only` ; toi seul intègres + build.
- **CRT heap** : jamais ton `free()` MinGW sur un buffer MSVC.
- **Conventions** : callbacks UpCalls `__cdecl`. **Méthodes renderer DX7 = `__cdecl(this,args)`** (this en 1er, `mov eax,[esp+4]; ret`). engineCtx=NULL, 21 callbacks, 2 exports.
- **DLL setups** : `gg_dx7r.dll` = renderer vanilla (cible). `gg_dx7r_orig.dll` = real (pour le proxy). `gg_dx9r*.dll` + proxy 1.5 = legacy/oracle.

## Subagents (parallélisation MAX — vraies limites)
- **GLM-5.1 (sonnet) = 10 concurrent** → fork jusqu'à ~8 subagents sonnet. **GLM-5.2 (opus) = 5 concurrent** → main + qq opus.
- **529/429 = surcharge/limite transitoire** (PAS le plafond de concurrence) → back-off retry, pas de limite à 2. Le plafond = les chiffres ci-dessus.
- Fork sur chantiers **indépendants** (fichiers disjoints, claim board / worktree). Anti-race : 1 rédacteur/fichier ; ils RETOURNENT du code, toi seul intègres+build. Modèle : `sonnet` subagents, `opus` main. **re-agent = JAMAIS en parallèle** (session unique).

## Args
$ARGUMENTS — directive additionnelle (sinon : « continue le blocker courant, priorise le chemin boot réel ou le proxy/oracle »).
