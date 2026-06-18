# giants-advance

**Le SEUL skill pour faire avancer le projet** — recomp 100%-identique de Giants: Citizen Kabuto (vanilla 1.0 DX7). Tu tournes en continu, tu délègues (subagents) ou fais plusieurs choses pour **toujours progresser**. Cycle : `mesure → spec → implémente → build → VÉRIFIE → commit`. Un cycle = un commit.

## ⚑ PRINCIPE SUPRÊME : MESURE AVANT CODE + PREUVE AVANT DE CLAMER
1. **Mesure avant code** : pour TOUT comportement observable, mesure l'original d'abord → `behavior_specs/<x>.md` → implémente → vérifie. Coder un observable sans l'avoir mesuré = **dérive** (CLAUDE.md §0 règle 5).
2. **Succès = preuve, pas « ça tourne + visible »**. Deux modes de preuve, choisis le bon :
   - **Visuel** (ce qui s'affiche) → `tools/run.sh <phase>` (capdiff vs original) doit **PASS** (mean_abs_delta < seuil).
   - **Bit-exact** (fonctions/callbacks) → proxy/oracle dual-mode : notre impl vs original, **0 mismatch**.
   Ne JAMAIS clamer un rendu/fonction correct sans la preuve correspondante.

## Cible canonique : VANILLA 1.0
`GameFiles-VanillaV1/Giants_nocd.exe` (2574 fn, DX7 `gg_dx7r.dll`, 2 exports, 21 callbacks, engineCtx=NULL). Le 1.5/DX9 (`gg_dx9r.dll`, 22 callbacks, engine-context) = **legacy/oracle secondaire**, plus canon. Renderers DX9/11/12 post-1.4 = réimplémentés par nous. Original oracle = `Giants_nocd.exe`.

## Contexte (LIS EN PREMIER)
- **CLAUDE.md §0** — doctrine + règles fidélité observable 5-10. OVERRIDE tout.
- **`behavior_specs/`** — specs mesurées (boot chain, intro timings 0.2s/12s, loading=giants_loading PAS int_loadisland, menu 3D+2D).
- **`vanilla_decompiled/*.json`** — corps vanilla (provenance). Index `version_bridge/vanilla_functions.jsonl`.
- **`RE_docs/DX7_RENDERER_CONTRACT.md` + `DX7_METHOD_MAP_v2.md` + `DX7_RENDER_RECIPE.md`** — contrat (21 callbacks, table 0x57c, 57 slots mappés).
- **Mémoires** (`.../memory/`) — `overnight-2026-06-18-batch.md` (état courant callees), `dx7-minimal-contract.md`, `boot-sequence-and-3d-terrain.md`, `scene-load-roadmap.md`, `giants-format-specs.md`.
- **`git log --oneline -20`** — où on en est.

## Outils (OBLIGATOIRES — choisis selon le mode de preuve)
**Visuel (capdiff)** : `tools/run.sh <phase> [compare|recomp|original] [norebuild]` (build→deploy→capture→diff, rc 0=PASS/1=FAIL/2=capture-fail). `tools/capdiff.py` (capture recomp flags-phase + original Giants_nocd + diff PIL). Original via PowerShell Start-Process (segfault sous subprocess) ; 4s relâchement DX7 entre les deux (même gg_dx7r.dll).
**Bit-exact (proxy oracle, C5)** : `proxy_dx7/` → `gg_dx7r.dll` capture-proxy. Deploy : real gg_dx7r.dll → `gg_dx7r_orig.dll`, proxy AS gg_dx7r.dll, run original → `giants_dx7_proxy.log` capture les 21 callbacks. Pour valider un callback : dual-mode (notre impl + originale, compare, 0 mismatch). Le proxy 1.5 (`proxy/`, gg_dx9r) reste pour l'oracle secondaire.
**Flags phase recomp (C1)** : `-skip-intros`, `-at menu`, `-at level:<name>`, `-frames N`, `-no-audio`. (`-skip-intros -frames 200` atteint le menu en ~5s vs ~15s.)
**Frida** (`scripts/frida_*.js`) — capture timing/séquence de l'original + RPC. **`appsnap`** (`uvx appsnap -o <png> "Giants"`) capture ponctuelle. `-t 100` match strict.

## Workflow (BOUCLER)
1. **Cible** le prochain blocker (trace log, capdiff FAIL, ou callee du chemin boot). Pas de spec → MESURE d'abord → `behavior_specs/`.
2. **Diagnostique** : statique (`vanilla_decompiled/*.json`, re-agent vanilla) + dynamique (Frida/proxy sur l'original). **Vérifie QUE la fonction est sur le chemin réellement exécuté** (ne porte pas du code mort — si le loader n'est pas câblé, ses callees sont dormant : priorise le câblage ou le proxy).
3. **Implémente** : porte le corps vanilla OU capture+valide via oracle. Cite les DAT_. Vérifie la règle asset-display.
4. **Build** : `bash tools/build.sh GiantsMain_vanilla` (lock sérialisé si >1 agent). Vert.
5. **Vérifie** : capdiff PASS (visuel) OU proxy 0-mismatch (bit-exact). FAIL = fixe le recomp, n'affaiblis pas la spec.
6. **Commit + push** : `git add -u && git commit -q -m "RE(...): ..."` (EN, pas de trailer Claude, guard secret/lourds).
7. **Reboucle**. Pas de résumé — enchaîne. **Priorise toujours ce qui débloque le plus** (le chemin boot réel > callee dormant ; le proxy/oracle > portage abstrait).

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
- **Anti-dérive** : pas de code custom/inventé. Diagnostic stub isolé/étiqueté. Mur COM + DX9 registry = quarantaine `reference/patch15/`, jamais câblé.
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
