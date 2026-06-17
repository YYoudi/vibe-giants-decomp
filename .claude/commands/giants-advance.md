# giants-advance

Avance autonome sur le recodage **100%-identique** de Giants: Citizen Kabuto jusqu'à blocage dur. Cycle : `mesure → spec → implémente → build → auto-vérif (capdiff) → commit`. Pas de résumé en route. Un cycle = un commit. **Tu ne t'arrêtes QUE sur demande humaine ou blocage dur.**

## ⚑ PRINCIPE SUPRÊME : MESURE AVANT CODE (OVERRIDE TOUT)
Pour TOUT comportement observable (ce qui s'affiche, l'ordre, la durée, la valeur de fondu, quel asset à quel instant) : **mesure l'original d'abord** → écris une spec dans `behavior_specs/` → implémente → vérifie par `tools/run.sh <phase>` (capdiff PASS). Coder un observable sans l'avoir mesuré = **dérive** (CLAUDE.md §0 règle 5). Le succès = « matche l'original » (capdiff PASS), JAMAIS « ça tourne + quelque chose s'affiche ». Ne JAMAIS clamer qu'un rendu est correct sans un `compare` qui PASS.

## Cible canonique : VANILLA 1.0
**vanilla 1.0 retail** (`GameFiles-VanillaV1/Giants_nocd.exe`, 2574 fn, DX7 `gg_dx7r.dll`). Le 1.520.59 se transfère comme connaissance via `version_bridge/VERSION_MAP_v2.csv`. Renderers DX9/11/12 post-1.4 = **réimplémentés par nous**, pas hérités. Piste 1.5/DX9 = legacy/oracle, plus canon.

## Contexte (LIS EN PREMIER)
- **`CLAUDE.md` §0** — doctrine + **règles de fidélité observable 5-10** (mesure-avant-code, asset-display, succès=matche-original, auto-vérif, spec=source, diagnostic-only élargi). OVERRIDE tout.
- **`behavior_specs/`** — specs mesurées sur l'original. **Source de vérité de tout observable.** En particulier : `boot_sequence.md` (chaîne FUN_005222c0, 15 étapes), `intro_timings.md` (fondu 0.2s / tenu 12s / 3 images depuis intros.bin), `loading_screen.md` (giants_loading.tga via FUN_0045a530, **PAS int_loadisland**), `menu_render.md` (3D+2D ensemble, chargés au boot step 4).
- **`vanilla_decompiled/*.json`** — corps vanilla (source de provenance). Index `version_bridge/vanilla_functions.jsonl`.
- **`RE_docs/DX7_RENDERER_CONTRACT.md`** + **`DX7_RENDER_RECIPE.md`** — contrat DX7 (21 callbacks, engineCtx=NULL, 2 exports, table 0x57c).
- **Skill `/giants-proxy`** — oracle proxy + classification.
- **Mémoires** (`.../memory/`) — `dx7-minimal-contract.md`, `boot-sequence-and-3d-terrain.md`, `scene-load-roadmap.md`, `giants-format-specs.md`.
- **`git log --oneline -20`** — état courant.

## Outils d'auto-vérif (OBLIGATOIRES — ne code pas un observable sans les utiliser)
- **`tools/run.sh <phase> [compare|recomp|original] [norebuild]`** — build→deploy→capture→diff en une commande. rc 0=PASS / 1=diff-FAIL / 2=capture-fail.
- **`tools/capdiff.py`** — capture recomp (flags de phase) + capture original (Giants_nocd) + diff PIL (mean_abs_delta). Subcommands `recomp|original|diff|compare`. **L'original se lance via PowerShell Start-Process** (segfault sous subprocess plain) ; 4s de relâchement DX7 entre recomp et original (même `gg_dx7r.dll`).
- **Flags de phase recomp (C1)** : `-skip-intros`, `-at menu`, `-at level:<name>`, `-frames N`, `-no-audio`. **Teste une phase sans rejouer le boot** (`-skip-intros -frames 200` atteint le menu en ~5s vs ~15s).
- **Frida** (`scripts/frida_*.js`) — capture timing/séquence de l'original + RPC de contrôle.
- **`appsnap`** (`uvx appsnap -o <png> "Giants"`) — capture ponctuelle.

## Workflow (BOUCLE jusqu'à blocage dur)
1. **Cible** le prochain observable à matcher (ou blocker lu dans trace). Si pas de spec → **MESURE d'abord** (Frida/capture/decompile) → écris `behavior_specs/<x>.md`.
2. **Diagnostique** : statique (`vanilla_decompiled/*.json`, ghidra-bridge/re-agent sur vanilla ; sémantique 1.5 via `VERSION_MAP_v2.csv`) + dynamique (Frida sur l'original vanilla).
3. **Implémente** : porte le corps vanilla OU capture+valide via oracle. Documente les DAT_ en commentaires. **Vérifie la règle asset-display** avant d'afficher quoi que ce soit.
4. **Build** : `cd /g/GiantsRE && export PATH="/c/msys64/mingw32/bin:$PATH" && mingw32-make GiantsMain_vanilla`. **Build = série** (1 make, lock `tools/.build.lock` si >1 agent). Vérifie vert.
5. **Auto-vérif** : `tools/run.sh <phase>` → doit PASS. Si FAIL : le recomp dévie de l'original → **fixe le recomp, n'affaiblis pas la spec**. Pour une nouvelle phase sans original capturable, documente pourquoi (Frida à venir).
6. **Commit + push** si progression : `git add -u && git commit -q -m "RE(...): ..."` (EN, pas de trailer Claude, guard secret/lourds).
7. **Reboucle**. Pas de résumé — enchaîne.

## Blocage DUR (seuls arrêts — sinon continue)
- **Sur demande humaine explicite** (l'humain valide sur demande uniquement — tu tournes en continu sinon).
- Décision de direction que seul l'humain peut prendre.
- Outil absent non-installable (tu as pip/curl — installe Frida/x32dbg toi-même d'abord).
- Gateway 529 persistant ou build cassé >3 fix.

→ À un vrai blocage : 3 lignes (où, ce qui bloque, prochaine action) puis rends la main.

## Chantiers (l'axe visuel = l'original ; les autres = autonomes)
**Axe visuel principal** : menu/île 3D fidèle (texturé, eau, ciel, logo 3D, GUI 2D, caméra `ref_camera1`) — nourrir la scène via la chaîne `FUN_004913c0→FUN_0045a530→FUN_004b7c50→FUN_004f3230`. **Toujours vérifier par `compare menu` qui doit PASS.**
**Chantiers autonomes** (vérifiables par trace/oracle/asm-diff, pas d'œil requis) : VFS (callbacks 15-17 + GZP), audio (`FUN_0051f900`), 21 callbacks UpCalls, mapping sémantique des ~55 méthodes renderer (RVA→D3D7), init-chain engine (`FUN_004f41c0`…), portage moteur-core via `VERSION_MAP_v2` (embarrassingly parallel).

## Règles
- **Anti-dérive** : pas de rendu/logique inventée. Diagnostic stub isolé et étiqueté. Mur COM + DX9 registry = quarantaine `reference/patch15/`, jamais câblé.
- **Mesure avant code** (observable) + **asset-display** + **succès = capdiff PASS** (CLAUDE.md §0 règles 5-7).
- **Preuve avant assemblage** : Ghidra vanilla vérifié OU 0 mismatch vs original.
- **Build = série** (1 make). Subagents : `g++ -fsyntax-only` ; toi seul intègres + build.
- **CRT heap** : jamais ton `free()` MinGW sur un buffer MSVC.
- **Conventions** : callbacks UpCalls `__cdecl`. **Méthodes renderer DX7 = `__cdecl(this,args)`** (this en 1er arg, `mov eax,[esp+4]; ret`) — PAS thiscall. engineCtx=NULL, 21 callbacks, 2 exports.
- **Structures** : layouts/globals vanilla ≠ 1.5 — réaligne `GiantsTypes` structure par structure.
- **DLL setups** : `gg_dx7r.dll` = renderer vanilla (cible). `gg_dx7r_stub.dll` = diagnostic. `gg_dx9r*.dll` + proxy = legacy 1.5/oracle. Original oracle = `Giants_nocd.exe`.

## Subagents (parallélisation MAX, back-off 529)
- Objectif : **parallélisation maximale** que tolère le gateway. Fork des subagents sur chantiers **indépendants** (fichiers disjoints via claim board / worktree). Le portage moteur-core est embarrassingly parallel.
- **Modèle** : `sonnet` (glm-5.1) pour les subagents ; opus (glm-5.2) pour la main (intégration, build, décisions).
- **Anti-race** : un seul rédacteur par fichier ; ils RETOURNENT du code, toi seul tu intègres + build. **Worktree par agent** (EnterWorktree) pour zéro conflit.
- **API 529** : back-off (séquentiel), ne réessaie pas le fork immédiatement.
- **re-agent** : JAMAIS en parallèle (session unique).

## Args
$ARGUMENTS — directive additionnelle (sinon : « continue le blocker courant »).
