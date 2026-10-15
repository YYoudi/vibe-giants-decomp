# PROMPT À DONNER À L'AGENT RUST (giants-rs) — reprise de session

> À coller tel quel au début de sa prochaine session (ou adapte le ton). Il suppose
> son `MISSION.md`/`PROGRESS.md` déjà en place. Objectif : verrouiller le cap sur la
> cinématique gamegauge.

---

Reprends ton travail d'agent moteur (lis PROGRESS.md en premier comme d'habitude).
Beaucoup de nouvelles ressources sont arrivées chez l'agent decomp depuis ta dernière
lecture — ta priorité est désormais guidée par LA CIBLE FINALE : reproduire la
**cinématique gamegauge** (`Giants.exe -gamegauge`, intro Mecc Story 4) à l'identique.

## 1. NOUVEAUTÉS à lire dans ../GiantsRE (dans cet ordre)

1. `docs/systems/CINEMATIC_PIPELINE.md` — la chaîne COMPLÈTE lancement→rendu de la
   cinématique : parse de `-gamegauge`, tous les consommateurs du flag, le modèle de
   timing EXACT (dt forcé 1/60 par frame rendue en mode gamegauge = fixed-step),
   l'enchaînement, `FLK_FlickRender` (caméra posée depuis le flick, dt propre des
   acteurs), le mécanisme fps.txt.
2. `docs/systems/RENDERER_GGDX7.md` — le renderer `gg_dx7r.dll` est DÉCOMPILÉ (367
   fns) et c'est en fait GFX_DX8. Contient : la table des 6 passes de rendu de la
   cinématique (FVF + texture + géométrie pour chacune), les formules EXACTES :
   - terrain = palette par hauteur (`u = height*(0.5/hScale)+lodBias+0.5`, v=0),
   - mer (`uv = pos/WS+0x7C`, grille 33×13 caméra-centrée miroir horizon ×12500),
   - gb2 (layout complet validé octets dans `docs/formats/world_gb2.md`),
   - GBS acteurs : `animate_core_caller` (LOD 9 slots par distance + token-stream
     u16 : 0=fin, bit15=strip, bit14=fan, sinon tri-list).
3. `docs/systems/MISSION_VM.md` — le décodeur FLK est VALIDÉ 545/545 fichiers
   (`tools_spec/flk_decode.py` = référence), table des 41 opcodes avec sémantiques.
   Les missions wm_*.bin = data (28 commandes one-shot), les cinématiques flk = VM
   à porter.
4. `QUESTIONS_FOR_DECOMP.md` — mes réponses Q1→Q6 + 3 compléments, dont une
   **CORRECTION IMPORTANTE** : le fps.txt est charge-machine-dépendant entre
   sessions (run4 ≠ run1/3). Ne PAS utiliser son égalité byte-exact comme gate —
   l'oracle = playlist flick + structure des frontières de scène (dips s8/s15-17).
5. `docs/golden/story4_flick_decode_summary.json` — les 112 fichiers flk de la
   famille story4 (celle de LA cinématique) décodés : counts, histograms d'opcodes.
6. `HANDOFF.md` reste l'index général.

## 2. TON CHEMIN CRITIQUE vers la cinématique (révisé)

1. **SKN/ANM** (ton M1 restant) — C'EST LE GOULOT. Les acteurs de la cinématique
   sont des GBS skinnés : sans SKN/ANM pas d'animation, pas de cinématique.
   Référence clean-room : `../GiantsRE/RESSOURCES_FOR_AI/git_repos_from_amazed/
   gck-map-extract-objects/lib/skn_anm.py` (1337 lignes). Fais `giants_skn_anm`,
   golden-validé sur les 782 skins / 1318 anims comme pour GBS.
2. **M5 objets** : placements `.abx` (spec exacte dans docs/formats/abx.md — y compris
   la sémantique "unset = transform égal au défaut") + object-sets.
3. **M6 = LA VM flick** (`giants_flick` est déjà dans ton workspace) : implémente
   l'interpréteur d'après MISSION_VM.md — records `{op, adv_dwords, payload}` depuis
   le dword 6, fin sur le string pool. Test direct : décode `flk_story4_T_square_1.bin`
   avec `tools_spec/flk_decode.py` et compare ta sortie op-par-op.
4. **Camera-from-flick** : `FLK_FlickRender` (CINEMATIC_PIPELINE.md §4) — le node du
   flick écrase la view matrix après transposée ; acteurs au dt `flick+0xAC`.
5. **M7 audio** : events `sound_play_obj(id, obj)` (op FLK 13) + banques WAV des
   `VO_*.gzp`.
6. **Parité finale** : protocole de capture dans RUNTIME_TRACES.md (captures locales
   PrintWindow OK chez toi), comparer aux screenshots de référence.

## 3. RÈGLES TOUJOURS EN VIGUEUR

- Rien de GiantsRE n'est copié : transpose constantes (bit-exactes) et sémantiques.
- La veille `QUESTIONS_FOR_DECOMP.md` : pose-y tes questions, l'agent decomp répond
  (Q1-Q6 résolues en <1 jour). Marque `[EN ATTENTE ORACLE]` si besoin runtime.
- Provenance observed/derived/inferred dans ton code.
- `xtask publish-check` vert à chaque commit.

## 4. ÉTAT DE L'ORACLE CÔTÉ DECOMP (pour ta planification)

- Playlist gamegauge : 28 ids flick déterministes (`0x0D→0x41`) — le mapping
  id→nom est en cours de capture côté decomp (watch QUESTIONS_FOR_DECOMP).
- Le jeu tourne sous debugger elevated + capteurs : toute demande de trace runtime
  (dump de valeurs, args de fonction) est faisable — demande dans le fichier.
