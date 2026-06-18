# PROFIL ARCHITECTE : GIANTS CITIZEN KABUTO (C++ GROUND TRUTH)

> ## ⚑ PURGE 1.5 (2026-06-18) — 100% VANILLA-ONLY DÉSORMAIS
> Toute la base 1.5/DX9 a été **SUPPRIMÉE** : `src/` (705 fns), `version_bridge/`, `proxy/`
> (gg_dx9r), `reference/patch15/`, `ghidra_projects` (v1.5 GiantsMain.exe), `ghidra_exports`
> (v1.5), `vanilla_decompiled` (v1.5), `GameFiles/`. **Cause racine de la dérive** : le projet
> Ghidra + les decompiles étaient le binaire **v1.5** (GiantsMain.exe 1.520.59), PAS vanilla 1.0
> (Giants_nocd.exe) → les adresses 0x6xxxxx/0x49xxxx ci-dessous sont des adresses **v1.5**,
> souvent DÉCALÉES vs vanilla. **AVANT d'utiliser une adresse : RE-VÉRIFIE-LA contre la
> nouvelle decompile vanilla** (`vanilla_decompiled/`, régénérée depuis Giants_nocd.exe via
> `ghidra_projects/VanillaProj`). Cible unique : `GameFiles-VanillaV1/Giants_nocd.exe` (DX7).
> Build unique : `GiantsMain_vanilla` (src_vanilla/) + `gg_dx7r_proxy`.

## 0. DOCTRINE AUTONOMIE & PARALLÉLISATION (LIT EN PREMIER — OVERRIDE TOUT)

**TU ES UN AGENT PLEINEMENT AUTONOME.** L'humain est uniquement un **testeur visuel** (0 connaissance RE) — il lance le jeu et confirme ce qu'il voit. Tu ne lui demandes JAMAIS d'installer un outil, de deviner une data, ou de choisir une techno. Tu as : accès terminal + internet + 800k context + budget token massif. **Tu décides, tu fais, tu valides.**

### Règles d'autonomie absolues
1. **Il te manque un outil ? INSTALLE-LE ou CONSTRUIS-LE.** Tu as `pip`, `curl`, le terminal, internet. Frida/debugger/asm-diff/PIX → tu les poses toi-même. Un script de comparaison/diff/capture qui n'existe pas → tu l'écris. Ne jamais attendre l'humain.
2. **Pas de code custom/inventé dans le recomp.** Tout vient d'un corps Ghidra (adresse DAT_ documentée) OU est validé bit-à-bit vs l'original (oracle proxy). Un rendu « maison » (GDI DrawText, clear custom) = diagnostic-only, jamais présenté comme RE. (Voir skill `giants-advance` § anti-dérive.)
3. **Le RE ne s'arrête pas à Ghidra (statique).** Complète systématiquement par de l'analyse **dynamique** : hook Frida sur l'original (D3D9/DirectSound/registry/renderer), breakpoints, capture de frame. Le décompilé Ghidra est ~60-90 % correct → confirme TOUJOURS par observation runtime de l'original avant de câbler.
4. **Preuve avant assemblage.** N'assembler dans l'exe recompilé QUE des fonctions prouvées équivalentes (oracle = original via proxy, 0 mismatch) ou portées fidèlement (corps Ghidra vérifié).

### Règles de fidélité OBSERVABLE (ANTI-DÉRIVE RENFORCÉE — rajoutées 2026-06-17)
*Le code source prouvé ne suffit pas : le résultat ASSEMBLÉ et AFFICHÉ doit matcher l'original. C'est l'écart qui a laissé inventer un faux écran « LOAD ISLAND » et des timings de fondu devinés.*

5. **OBSERVATION RUNTIME AVANT CODE (suprême — PAS l'analyse statique).**
   **MESURER ≠ LIRE LE CODE GHIDRA.** La mesure = **OBSERVER LE VRAI JEU EN RUNTIME** via des hooks
   (Frida sur les fonctions/fichiers, proxy DX7 sur les appels renderer). Lire le code décompilé
   est de l'analyse STATIQUE — utile pour PORTER, mais INSUFFISANTE pour PROUVER ce que le jeu
   fait vraiment. Pour TOUT comportement observable :
   (a) **OBSERVER** l'original en runtime : hook Frida callback[17] VFSOpenFile → quels fichiers
   s'ouvrent ; proxy DX7 → quels SetTexture/SetTransform/DrawPrimitive avec quels args ; appsnap
   → ce qui s'affiche.
   (b) **DOCUMENTER** l'observation comme spec (`behavior_specs/`).
   (c) **PORTER** le code vanilla (du décompilé) qui produit ce comportement.
   (d) **VÉRIFIER** le recomp matche l'observation (capdiff PASS ou proxy 0-mismatch).
   **NE JAMAIS deviner quel asset le jeu charge.** TOUJOURS l'observer via un hook runtime.
   (Ex : Giants_logo_512.tga a été deviné du GZP index sans observation runtime → DÉRIVE.)
6. **Règle asset-display (PROUVÉ par runtime, pas par GZP index).** N'affiche JAMAIS un asset
   sauf si une **observation runtime** (hook VFSOpenFile sur l'original) confirme que l'original
   le charge ET l'affiche à ce moment. L'index GZP liste les assets existants, PAS ce que le jeu
   charge. Voir le workflow OBSERVER→DOCUMENTER→PORTER→VÉRIFIER ci-dessus.
7. **Critère de succès = matche l'original, pas « ça tourne + visible ».** Une frame recomp est réussie si `tools/run.sh <phase>` (capture-diff vs original) → **PASS** (mean_abs_delta < seuil). No-crash = prérequis minimal, jamais un succès. Ne JAMAIS clamer « le menu rend correctement » sans un `compare` qui PASS.
8. **Auto-vérif obligatoire, validation humaine sur demande.** L'agent auto-vérifie tout ce qui est objectif via `tools/capdiff.py` (recomp vs original frame-diff) + oracle proxy (bit-exact) + Frida (timing/séquence). L'humain ne valide QUE sur demande explicite ou pour du subjectif — l'agent tourne en continu sinon.
9. **Spec = source de vérité observable.** `behavior_specs/` (boot_sequence, intro_timings, loading_screen, menu_render…) dérive des mesures originales. Le recomp doit matcher la spec ; un écart = bug à corriger, pas une approximation à accepter.
10. **Diagnostic-only élargi.** Tout dessin GDI/custom hors du chemin renderer prouvé qui produit une sortie FINALE (non étiquetée « DIAGNOSTIC ») = dérive. Les rendus diagnostics doivent être étiquetés et exclus du boot canonique.

### PARALLÉLISATION — à CHAQUE itération / CHAQUE pause
**Avant chaque tour de boucle, pose-toi explicitement : « Comment puis-je PARALLÉLISER ce tour ? »** Tu as un budget token énorme et 800k context — le fan-out est ton levier de vélocité principal.

- **Fork N subagents** sur des chantiers **indépendants** (fichiers disjoints, pas de conflit d'édition, pas de build parallèle). Le portage RE (Ghidra → `RE_<fn>`) est « embarrassingly parallel » : chaque fonction est indépendante.
- **Règle anti-race** : plusieurs agents peuvent LIRE/RECHERCHER en parallèle, mais **UN SEUL rédacteur par fichier**. Les agents RETOURNENT du code ; un seul intègre. Jamais d'édition parallèle du même fichier (sinon build cassé).
- **Build = série** (1 CMake/make). Les forks ne build PAS en parallèle ; ils syntax-checkent leur fichier seul (`g++ -fsyntax-only`), et l'agent main intègre + build.
- **Cadence** : 1 main coordonnateur + N forks exécuteurs. Le main découpe en lots disjoints, fork, collecte, intègre, build, commit, recommence.
- **Quand tu hésites à fork ou pas** : FORK. Le défaut est la parallélisation maximale, pas le travail séquentiel.

### Outil RE à ta disposition (installe-en d'autres si besoin)
- **Statique** : Ghidra 12.1.2 + exports `ghidra_exports/` (6254 fn JSON) + `vanilla_decompiled/*.json` (corps vanilla) + `version_bridge/vanilla_functions.jsonl` (index) + re-agent + ghidra-bridge.
- **Dynamique** : **Frida** (`python -m frida`) → hook l'original (renderer/D3D/DS/registry/file/timing). **x32dbg** (debugger scriptable).
- **Auto-vérif visuelle (CŒUR)** : `tools/capdiff.py` — capture recomp (flags de phase) + capture original (Giants_nocd) + diff PIL → verdict PASS/FAIL. `tools/run.sh <phase>` = build→deploy→capture→diff en une commande. `appsnap` (`uvx appsnap -o <png> "Giants"`) pour captures ponctuelles.
- **Flags de phase recomp (C1)** : `-skip-intros`, `-at menu`, `-at level:<name>`, `-frames N`, `-no-audio` → tester une phase sans rejouer le boot.
- **Specs observables** : `behavior_specs/*.md` (mesurées sur l'original) — source de vérité pour tout comportement observable.
- **Oracle** : proxy `gg_dx9r.dll` (dual-mode bit-compare, 1.5/DX9) ; proxy vanilla DX7 C5 (proxy_dx7/ → gg_dx7r.dll, capture 21 callbacks) BUILT.
- **Cross-référence** : ISO PS2 debug symbols (`ps2_symbols/`) pour le nommage PC↔PS2.
- **À construire si besoin** : asm-diff (recomp vs original, fonction par fonction), capture PIX/RenderDoc de frame, moniteur API custom.

### Auto-amélioration continue
- Met à jour **ce fichier** + le skill `giants-advance` + les mémoires après chaque session/jalon.
- Si une méthodo marche (ex: self-test bit-exact, shadow in-game), documente-la dans le skill pour la réutiliser.
- Si tu te surprends à inventer du code (dérive stub), STOP, reviens à la doctrine, corrige le skill.

---

## 1. MISSION & DOCTRINE RETRO-ENGINEERING
- **Objectif Principal :** Compiler et stabiliser un environnement de développement C++ ("Ground Truth") pour *Giants: Citizen Kabuto* (2000, Moteur Amityville) sous Windows en mode natif x86 (32-bits).
- **Architecture Hybride :** Le projet couple le SDK communautaire (Patch 1.5 de `ncblakely`) et la réécriture de la logique interne via extraction du binaire `GiantsMain.exe` v1.520.59.
- **Méthodologie :** Reverse engineering top-down via Ghidra + re-agent, génération de stubs C++ progressifs.

## 2. OUTILS INSTALLÉS ET OPÉRATIONNELS
- **Ghidra 12.1.2** : `RESSOURCES_FOR_AI/ghidra_12.1.2_PUBLIC/`
- **Projet Ghidra** : `ghidra_projects/GiantsRE` — 6 254 fonctions analysées
- **ghidra-bridge** : CLI fonctionnel, config `ghidra-bridge.yaml`
- **re-agent** : CLI fonctionnel, config `re-agent.yaml` (API z.ai, modèle glm-5.1)
- **Exports Ghidra** : `ghidra_exports/` — 103 structs, 3675 strings, 6254 fonctions JSON
- **Python** : 3.11, scripts dans `%APPDATA%\Python\Python311\Scripts\`

## 3. ARCHITECTURE DU BINAIRE (validée par XREFs)
```
entry (0x00643f2e)
  └── __scrt_common_main_seh (0x00643daf) ✅ REVERSED
       └── EngineInitializeImpl (0x0062cd40) ✅ REVERSED
            └── MainGameLoop (0x0062d100) ✅ REVERSED — LA BOUCLE PRINCIPALE
                 ├── ProcessRawKeyboardInput (0x0062aac0) ✅ PASS
                 ├── UpdateTime (0x00629f50) ✅ FAIL (usable)
                 ├── ProcessMouseInput (0x0062abe0) ✅ FAIL (usable)
                 ├── ProcessGameLogic (0x00524f30) ✅ PASS
                 └── InitializeEngine (0x0062e1a0) ✅ FAIL (usable) — registry+renderer+audio+player

ProcessGameLogic callees:
  ├── PreFrameReset (0x00565480) ✅ PASS
  ├── BeginScene (0x004f7e60) ✅ PASS — ref-counted render stage init
  ├── ShutdownSubsystems (0x004f7f10) ✅ PASS — ref-counted render stage shutdown
  ├── EndSceneDirectional (0x00524c10) ✅ PASS — 6-pass light render
  │    ├── BuildViewMatrix (0x005f9eb0) ✅ PASS — view matrix + XOR depth
  │    └── SetWorldTransform (0x005fa1a0) ✅ PASS — apply world transform
  ├── SceneBegin (0x00522310) ✅ PASS — object sort + distance cull + render dispatch
  ├── DispatchGameStateTick (0x004d0dd0) ✅ PASS — time accumulator + callback dispatch
  ├── ProcessSceneTransition (0x005539d0) ✅ FAIL (usable) — fade/scene load state machine
  ├── FrameEnd (0x005253b0) ✅ FAIL (usable) — FPS limiter + RenderDoc + present
  ├── TimerTick (0x004ad640) ✅ FAIL (usable) — input mapping + controller state
  ├── UpdateActiveCamera (0x0049a040) ✅ FAIL — camera selection + projection
  ├── SetupProjection (0x005f9d00) ✅ FAIL — projection matrix + depth XOR
  ├── AnimateCameraPath (0x005f8480) ✅ FAIL — keyframe camera interpolation
  ├── FloatToInt64 (0x00643f70) ✅ PASS — CRT __ftol2, 127 callers
  └── +6 more callees

InitializeEngine sub-functions:
  ├── LockGraphics (0x0062ad90) ✅ trivial — registry open
  ├── UnlockGraphics (0x0062ae40) ✅ trivial — registry close
  ├── InitDisplayMode (0x0062b9c0) ✅ FAIL — GDI font + DIB + LOGFONT
  ├── InitAudioSystem (0x0062af40) ✅ FAIL — SDV plugin loader (gs_*.dll)
  ├── ShowErrorDialog (0x0062edc0) ✅ FAIL — error screen + MessageBoxA fallback
  ├── ProcessReplayFile (0x0062f7e0) ✅ FAIL — replay record/playback
  ├── InitializeDirectInput (0x0062a420) ✅ FAIL — DI8 keyboard+mouse+controller
  ├── InitGraphicsResources (0x004f7fa0) ✅ PASS — 4 devices, 9 buffers, 2 heaps
  ├── LoadModule (0x0062a190) ✅ PASS — DLL loader helper
  ├── WndProc (0x0062ea70) ✅ FAIL — window msg handler
  ├── InitDisplaySettings (0x004f86c0) ✅ FAIL — vtable display query + fullscreen
  └── +10 more sub-functions

Other key functions:
  ├── VectorDistanceSq (0x00638d40) ✅ PASS — 192 callers, trivial
  ├── ComputeBoundingBox (0x005de6b0) ✅ FAIL — AABB from vertices
  ├── LoadDefaultPlayer (0x00552990) ✅ FAIL — load intro_island
  ├── ProcessFlickCommands (0x004e7b10) ✅ FAIL — FLICK cinematic interpreter
  ├── VFS_Initialize (0x00622930) — stub manuel (67 branches)
  ├── GameMainLoop (0x0046a110) — stub only (1648 lines, 104 callees)
  └── GameLoopDispatch (0x005255b0) — undecompilable (50 callees)

Renderer: LoadGDVSystem (0x0062a230) ✅ PASS

## 4. FICHIERS SOURCE GÉNÉRÉS (`src/`)
```
src/engine/Engine.h, Engine.cpp, GameLoop.h
src/engine/Input.h, Input.cpp          — DirectInput keyboard + mouse polling
src/engine/Timer.h, Timer.cpp          — Frame timing, smoothing, pause/slowmo
src/engine/GameLogic.h, GameLogic.cpp  — Render pipeline, network sync, game state
src/engine/ScenePipeline.h, ScenePipeline.cpp — BeginScene, Shutdown, EndScene, View/World matrices
src/engine/Camera.h, Camera.cpp        — Active camera, projection, keyframe animation
src/engine/ErrorHandler.h, ErrorHandler.cpp — Error dialog (in-game + MessageBoxA)
src/engine/EngineInit.h, EngineInit.cpp — InitializeEngine (registry+renderer+audio)
src/engine/DirectInput.h, DirectInput.cpp — DI8 init (needs rewrite, 35%)
src/engine/WndProc.h, WndProc.cpp      — Window message handler
src/engine/MathUtils.h, MathUtils.cpp  — FloatToInt64, VectorDistanceSq
src/engine/AudioSystem.h, AudioSystem.cpp — SDV plugin loader (gs_*.dll)
src/engine/DisplayMode.h, DisplayMode.cpp — GDI font init, bounding box
src/engine/FlickInterpreter.h, FlickInterpreter.cpp — FLICK cinematic opcodes
src/engine/Player.h, Player.cpp        — Default player loading
src/engine/GiantsTypes.h               — 10 game-specific structs
src/renderer/RendererLoader.h, RendererLoader.cpp
src/vfs/VirtualFileSystem.h, VirtualFileSystem.cpp
src/engine/CRTStubs.h, CRTStubs.cpp          — 6000+ CRT/utility stubs (all Ghidra exports)
→ 45,362 lignes total (294 fichiers)
→ ✅ FULL DECOMPILATION COMPLETE: 6262/6254 functions tracked, 100% coverage
```

## 5. COMMANDS/SKILLS DISPONIBLES
- `/re-function <addr>` — Reverse une fonction avec re-agent (gère session, max_tokens adaptatif)
- `/re-trace <addr>` — Remonte XREFs jusqu'à entry, affiche graphe, propose reverse
- `/re-batch <addr1> <addr2>...` — Batch séquentiel avec stubs auto
- `/re-function`, `/re-batch`, `/re-pipeline` — commitent et pushent les avancées en fin de cycle (Phase 5 / étape finale)

## 6. BUGS CONNUS DE RE-AGENT
- **Race condition session file** : Toujours `rm -f re-agent-progress.tmp re-agent-progress.json` avant chaque appel
- **Jamais en parallèle** : re-agent ne supporte PAS l'exécution simultanée
- **Fonctions >50 branches** : Augmenter `max_tokens` à 8192 dans `re-agent.yaml` ou fallback Ghidra brut
- **FAIL ≠ inutile** : Extraire le code même en FAIL, souvent 90% correct
- **CRT functions** : Les CRT init (initterm, SEH) génèrent souvent des FAIL — normal

## 7. PATCHS DISPONIBLES
4 versions dans `RESSOURCES_FOR_AI/Patches_extracts/` :
- GPatch1_5_0_0 → GPatch_1_520_59_0 (LE PLUS RÉCENT avec renderers DX9+DX11+DX12)
- Renderers : `gg_dx9r.dll`, `gg_dx11r.dll`, `gg_dx12r.dll` — interface commune `GDVSysCreate/GFXGetCapabilities/UpCallsLoad`

## 8. RÈGLES DE MODIFICATION DU CODE
1. Ne détruis jamais de logique bas niveau sans valider l'équivalence d'assemblage.
2. Documente chaque offset/adresse Ghidra en commentaire dans les stubs.
3. Priorise la scannabilité et la journalisation des erreurs.
4. Met à jour ce fichier et les mémoires après chaque session de reverse.

## 9. VERSIONNING — COMMIT & PUSH DES AVANCÉES
Le repo est **public** : `origin/main` → https://github.com/YYoudi/vibe-giants-decomp
Commit + push est la **sauvegarde** du travail. Sans ça, un crash perd le cycle.

**Quand commiter/pusher (OBLIGATOIRE) :**
- Fin de chaque `/re-batch` (toutes les adresses traitées).
- Fin de chaque cycle `/re-pipeline` (Phase 5).
- À chaque **milestone** (module complet, +N fonctions, build enfin vert, bug RE majeur résolu).

**Procédure standard :**
```bash
cd G:/GiantsRE && export PATH="/c/msys64/mingw32/bin:$PATH"
git add -A
# GUARD secret/fichiers sensibles (ABORT si match)
git diff --cached --name-only | grep -iE "re-agent\.yaml|ghidra-bridge\.yaml|^GameFiles/|^RESSOURCES_FOR_AI/|^auto-re-agent/|^ghidra-ai-bridge/|^ghidra_projects/|^ghidra_exports/|^reports/|\.dll$|\.exe$|\.a$|\.lib$|api_key"
# si guard OK (vide) :
git pull --rebase origin main 2>&1 | tail -5
git commit -q -m "RE(batch): reverse N functions — <modules> (PASS: X / FAIL: Y)"
git push origin main 2>&1 | tail -5
```

**Règles ABSOLUTES du commit :**
1. Message en **anglais**, concis, résume ce qui a été reversé + statut build.
2. **Pull rebase avant push** — un autre agent peut avoir pushé ; si push rejeté, rebase + retry.
3. **JAMAIS** de trailer `Co-Authored-By` ni aucune mention de Claude/AI dans un message de commit.
4. **JAMAIS** commit `re-agent.yaml` / `ghidra-bridge.yaml` (clé API + chemins machine) — gitignorés, le guard le confirme.
5. Si rien à commitier (`nothing to commit`) → cycle sans nouveauté, OK, passer.
6. Les fichiers scratch (cycles, re-result-*.txt, reports/) sont gitignorés → `git add -A` ne les inclut pas.
