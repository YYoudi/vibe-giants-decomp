# FEATURE_MAP — carte de maturité du RE de Giants: Citizen Kabuto

> **À quoi ça sert** : la carte unique de tout ce que le jeu fait (même les détails
> triviaux), et pour chaque feature **combien on sait comment le jeu le fait dans les bytes**.
> Source de vérité pour cadrer le projet — relis-la avant toute décision de priorité.
>
> **Colonnes** :
> - `🔬 Compris` = niveau de compréhension des bytes du jeu original (0-100).
>   0 = rien · 20 = repéré dans le binaire · 50 = format décodé, sémantique floue ·
>   80 = comportement compris et traçable · 100 = validé par l'oracle (bytes + runtime d'accord).
> - `🦀 Moteur` = ce que giants-rs (Rust/Bevy) reproduit aujourd'hui.
> - `Preuve` = doc / fonction décompilée / gate / commit — jamais une impression.
>
> **Tenue à jour** (règle pour tous les agents) : toute tâche fermée met à jour la ou les
> lignes concernées de cette carte (+ régénérer la vue : `python scripts/render_feature_map.py`).
> Un % sans preuve n'a pas le droit d'exister ici.
>
> Générée le 2026-10-16 (audit cross-repos, 4 collecteurs de preuves).

## Lecture rapide (état du 2026-10-16)

- **Ce qui est compris en profondeur** : la cinématique gamegauge (VM flick, playlist,
  sous-titres, caméra dirigée), les formats d'assets (819 fichiers golden), le RNG
  (LCG MSVC bit-exact), le WorldList, la ligne de commande.
- **Le double trou central** : le **joueur Mecc** (marche/saut/course jamais décodés —
  `mecc_logic` décompilé mais jamais analysé) et l'**IA** (107 classes répertoriées,
  zéro arbre de comportement décodé). Tout le gameplay est bloqué derrière ces deux-là.
- **Spécs closes mais non portées** (rapide à gagner côté moteur) : mer 33×13 caméra-centrée,
  palette-hauteur terrain, fog/lumières depuis le world bin, 21 ops flick restantes.
- **Trou documentaire unique** : `MusicSet.bin` (77 Ko présent dans chaque install) =
  0 %, jamais mentionné dans un doc.
- Seul gate du RE restant identifié : **Q12** (dump runtime d'un ospec assemblé).

---

## 1. RENDU / MONDE / ASSETS / UI

| Feature | 🔬 Compris | 🦀 Moteur | Preuve |
|---|---|---|---|
| Afficher le terrain (grilles GTI) | 85 | 55 | Formule palette-par-hauteur + LOD quadtree décompilées (`terrain_elevation_gen @ 0x514D60`, RENDERER_GGDX7.md §1) ; Rust : UV palette-hauteur portées (u = h·(0.5/heightScale)+0.5+lodBias, formule observée asm) + ramp 64 éch. ; heightScale = maxHeight GTI inferred (Q14) |
| Afficher le ciel (dôme, étoiles, soleil) | 80 | 55 | Ce n'est PAS un dôme : composants `sky`/`outsky`/`space` du world.gb2 (corps 100 % décodé, indices u32 vérifiés octets) ; TASK-021 DONE (f09531f) ; ouvert : `space`, passe fog ciel, soleil (aucune fonction de rendu soleil identifiée) |
| Afficher la mer / l'eau (vagues, reflets) | 85 | 25 | Spec « close » : grille **33×13 caméra-centrée**, réflexion par miroir caméra ×12500, fade par rangée (`main_drawwatr_00430F30`, RENDERER_GGDX7.md §2) ; Rust : plan fixe y=0 inferred ; TASK-022 TODO |
| Éclairer la scène (soleil, ombres, fog) | 70 | 25 | Modèle = vertex **pré-éclairés** (pas de SetLight en cinématique, FRAME_ANATOMY §5.3) ; fog par passe depuis le world bin (ops 41/46/88/119/120) ; Rust : DirectionalLight+DistanceFog **codés en dur** (main.rs:526) |
| Afficher les maillages (GBS), skins, animations | 80 | 60 | Passe mesh `animate_core_caller @ 0x42E460` : 9 LOD, token stream u16 strips/fans ; skinning CPU `anm_skin_verts_apply` ; clés de rotation ANM **non décodées** (ANM_IMAGE.md) ; Rust : digests golden 782+1318, TASK-014 DONE (ebf3e7d) |
| Afficher les textures (TGA, palettes) | 85 | 70 | `main_texture.c` : TGA 24bpp+8 alpha, slots ops 30/32/33/34/37/38, palette terrain op 121 ; Rust : chaîne portée — slots 30-38 + section textures (`bin_world.rs`), palette op 121 + défauts loader (layout asm GOG 1.449, tests), ramp 64 éch. procédurale + UV palette-hauteur (`terrain.rs`, formule `_ftol` observée exe), résolution `<name>.tga` VFS multi-archives (`texture_cache.rs`, preuve `RuntimeLab/runs/20261016-231742-18956/`) ; ouvert : heightScale (Q14), slot WS+0x74, passe détail |
| Placer des objets dans le monde | 80 | 30 | op 70 OpObj (type+pos+0x1E défauts, max 0x400), abx placements, lieur xx_*.bin (ospec 0x464/instance 0x304, Q13 fermée, 952/952 walkées) ; TASK-002/003 DONE ; **BUG CONFIRMÉ par l'oracle visuel (propriétaire, 17/10)** : tous les props (pub/bar, éléments) sont agglutinés au centre de la scène au lieu d'être placés sur le monde — les gates prouvaient le spawn (984 sous-maillages), pas la position. Pistes : pivots sets jamais appliqués (TASK-015), membres abx world-space vs set-space (M18), poses par-node ospec (Q12) ; dispatch par classe non fait ; set_id abx = checksum inferred |
| Charger un monde (w_*.bin, streaming) | 85 | 55 | `bin_load_1a0002e5` : 7 sections, flux d'opcodes 19-138 (108/120 validés octets), section 6 = sous-chunks récursifs avec découpe z-range ; gate validate-formats 819 golden/0 FAIL (213eec2) ; le streaming récursif n'est pas câblé |
| Bouger la caméra (libre, cinématique, suivi) | 75 | 50 | Cinématique : `ANM_NodeGetMat` → transposée → vue écrasée (CINEMATIC_PIPELINE §4/13), tracks pos/rot par node, wrap repeat/ping-pong ; Rust : caméra director + orbite libre (TASK-007) ; suivi joueur absent (M4) |
| Météo, particules, FX | 35 | 5 | Section 4 = env fx (fx_world_dust/snow via `main_fx_004470b0`) ; `fx_process` **« pas documentée en détail »** (FRAME_ANATOMY §7) ; modules main_smoke/Flame/Tracer non spécifiés ; Rust : rien |
| Menus, HUD & radar | 70 | 35 | `status_hud_render @ 0x42C3E0`, `hud_radar_collide_sweep @ 0x4043A0`, ~32 fns hud_* ; handlers menus (`dlog_page_process`) mais pas de spec menu ; Rust : aucun menu ni HUD |
| Sous-titres & textes (gtext → police GDI) | 85 | 30 | Pipeline complet : ops 14-23 (`FLK_FlickTextProcess`), GText 100 % décodé (`gtext_parse.py`), layout `flick_text_layout`, fonte = raster GDI 256×128 (FONT_GDI.md) ; Rust : overlay sous-titres, layout FNT non porté |
| Effets d'écran (fades, letterbox) | 55 | 5 | Fades ops FLK 0x1F/0x25 appliqués en modulation plein-écran (FRAME_ANATOMY §9, « à confirmer visuellement ») ; letterbox = viewport 16:9 (trivial, derived) ; **flash : aucune trace** ; Rust : état fade gardé mais jamais appliqué au framebuffer |
| Modèle de lumière (par objet, fog par passe) | 70 | 20 | Pré-éclairage vertex (RGB/normales GBS), TSS presets décodés (MODULATE, MODULATE2X) ; SetLight vtable présent mais inutilisé en ciné ; fog = uniforms chargés par `main_drawwrld_0x4329b0` ; Rust : StandardMaterial approximé |

## 2. GAMEPLAY / MÉCANIQUES

| Feature | 🔬 Compris | 🦀 Moteur | Preuve |
|---|---|---|---|
| Faire tourner la boucle de jeu (ordre, tick, dt) | 85 | 30 | Ordre des ~40 appels de `game_loop_run @ 0x471A60` (SIM_LOOP.md) ; dt = `time_frame_update` (EMA, clamp 0,25 s, 1/60 en gamegauge), Q1 résolue runtime ; Rust : `World::step` 5 phases (53f9245) |
| Tirer des nombres aléatoires (RNG) | 90 | 75 | `_rand @ 0x543DD4` = LCG MSVC `s*0x343FD+0x269EC3`, **jamais seedé** → déterministe (SIM_LOOP §RNG) ; Rust : `CrtRand` bit-exact + test de séquence ; manquants : rndfloat/rndintrange |
| Empêcher de traverser les murs (collision) | 65 | 0 | `collgrid_collide_walk @ 0x412730` = rasterizer d'empreinte (cellule 5,0 u), resolve + sweep avec stepping ≤4 itér./pente ≤50° + sliding (COLLISION.md, commit 20c0e93) ; ouvert : bits des masques d'exclusion, carte de flags |
| Faire marcher le joueur (Mecc : marche, saut, course) | 25 | 0 | Gravité décodée : `obj_gravity_apply` g=**32.17405** + réponse au sol ; **`mecc_logic @ 0x4982C0` décompilé mais jamais analysé** — saut/course/fuel non décodés. C'est LE blocage du gameplay |
| Lancer des grenades (trajectoires) | 35 | 10 | `trajectory_throw_calc @ 0x4698F0` (vitesse = distance × 0.1), `trajectory_calculate` = ballistique exacte v=Δp/t−½at (corps lu) ; Rust : Projectile générique sans trajectoire |
| Faire jouer Kabuto (le géant) | 20 | 0 | `kabuto_ai_main_c15` (corps décompilé, non analysé), `kabuto_bite_damage`, respawner ; modes/échelle : aucun doc |
| Faire jouer le Reaper | 30 | 0 | `reaper_ai_main @ 0x45ECE0`, constantes portée 35.0/20.0 (gameplay_constants), `reaper_is_water_jump` ; classes 1/21/99 |
| Animer les Vimps / créatures | 25 | 0 | `objtype_setup_vimp`, `vimp_animselect`/`vimp_get_wanted_loc`, herd_promote_check (rank +0x9C) ; familles seamonster/piranha identifiées |
| Faire travailler les Smarties (ouvriers, build) | 35 | 0 | `smartie_move`, `smartie_house_scan` (type 0x353, 6 slots), `smartie_worker_ai_main_c74`, village AI ; aucun comportement décodé |
| Faire combattre les ennemis (IA de combat) | 20 | 0 | `cspec_attack_tick_dispatch` (field 3), `rpman_ai_main` (153 Ko !), `ai_standoff_goal_calc` ; arbres de comportement non décodés |
| Gérer vie/mort/respawn, dégâts | 25 | 5 | `process_wound @ 0x40BDC0`, `hurt_pusher`, handlers mort = field 16 des class-specs (~15 nommés), champs hp +0x278/+0x2F0/+0x1C0 ; Rust : rien |
| Construire la base (bâtiments) | 25 | 0 | `meccbasepit_bldg_from_object @ 0x40ACF0` (9 call sites), `bldg_spawn_state_tick` (états 1/2/3), food slots +0x52C |
| Jouer les types de parties (deathmatch, capture…) | 20 | 0 | `mission_type_dispatch @ 0x494BC0`, menus capture points/time, maps M_Mecc/M_Reaper/M_3WAY ; aucune section doc |
| Jouer les missions Story (objectifs) | 45 | 0 | Verdict DATA : wm_*.bin = 28 opcodes 0x0B-0x26 à tailles dérivées (`mission_init`), runtime natif (`mission_00447fd0`) ; carte champ-par-champ open ; aucun parseur Rust |
| Jouer les cinématiques (playlist, déroulé) | 88 | 60 | Playlist runtime capturée (53 flicks, ids 0x0D→0x41, terminateur 0x42 = « end »), intros.bin = 3 slides, **pas d'outros.bin** (fin = gameover_menu) ; oracle flk_sim 7 487 frames ; Rust : les 53 flicks jouées avec exit propre (c679ebd) |
| Faire tourner l'IA complète (107 classes) | 35 | 0 | Table `0x55CB00` 107 classes × 17 slots, 3 dispatchers, 63 handlers nommés, ~25 classes identifiées ; comportements par classe : pending |
| Naviguer / pathfinding | 25 | 0 | `main_path.c` (fn ≈ 850 lignes décompilées), `ai_chase_location`, splines de waypoints, slots objectifs +0x168 ; aucune sémantique documentée |
| Coordonner les PNJ / équipes | 25 | 0 | `teammecc_leader_tick`/`get_wantloc_formation`, `owner_squad_process`, `herd_promote_check`, champ team +0x18C |

## 3. AUDIO / VIDÉO / RÉSEAU / SYSTÈMES

| Feature | 🔬 Compris | 🦀 Moteur | Preuve |
|---|---|---|---|
| Jouer des sons d'effets (SFX, EAX 3D) | 65 | 10 | `read_sfx_bin @ 0x4950A0`, `sound_play_obj @ 0x4954E0` (46 hits runtime), banques VO_Sfx*.gzp + sfxlev*.bin ; Rust : rien (mixage derrière eaxman.dll/gs_ds.dll) |
| Jouer de la musique (streams adaptatifs) | 55 | 15 | `music_stream_play @ 0x51C8D0` (vtable DLL), streams Stream/ observed ; **MusicSet.bin (77 Ko) = 0 %, jamais documenté** (blocs msb_*/mwb_* probables) ; Rust : stream cinématique seulement |
| Jouer les voix / dialogues | 50 | 5 | StreamEnglish = doublage ; op 132 mission voice ; `sound_player_voice_mecc/_smartie` ; `mecc_bubble_show` |
| Placer le son dans l'espace (3D, volumes) | 55 | 5 | `audio_listener_update` (listener = caméra), `sound_checked_big` (gates distance/occlusion), APIs MDV*/SDV*, registre volumes ; Rust : rien |
| Jouer les intros / outro du jeu | 85 | 50 | (voir « Jouer les cinématiques » — intros.bin = 3 slides CRLF, outro = slot « end ») |
| Afficher les sous-titres | 85 | 30 | (voir « Sous-titres & textes » §1) |
| Faire dialoguer les machines (netcode) | 55 | 5 | `comm_msg_dispatch @ 0x531470` (switch 36,9 Ko, handlers 0x17-0x5C), datagrammes WS2_32 ; **transport/négociation = open** ; giants_net = stub 6 lignes |
| Jouer en multijoueur (lobby, matchs) | 50 | 0 | Table 20 joueurs, `comm_all_players_ready/loaded`, gamespy/DirectPlay init, notes de patch (votes, ban, teams) |
| Sauvegarder / charger une partie | 50 | 0 | `mission.sav` = dump mémoire brut 0x23084 o de DAT_0x633380 (`savegame_verify`, gate version 0x11, SAVEGAME.md) ; carte de champs partielle ; Rust : rien |
| Mettre les préférences (registre) | 65 | 0 | `HKCU\Software\PlanetMoon\Giants` — wrappers RegQuery/Set décodés, IDs\Player{Video*, volumes} ; structure totale connue par le dump runtime |
| Enregistrer / rejouer une partie | 20 | 0 | Seul indice : keybind `FlickReplay` (rejouer une ciné) ; aucun démo-recorder trouvé (inferred) |
| Afficher le HUD / la minimap | 45 | 10 | ~32 fns hud_* (radar sweep, icon_timed, world_to_screen) ; keybind MapMode ; Rust : events icônes VM partielles |
| Lire le clavier / la souris | 80 | 10 | `dinput_init @ 0x519110` (DI8, pas de manette), bitfields 0x5DD0C0 (INPUT.md, preuve mémoire before/after observed) ; mapping actions = open ; Rust : clavier Bevy caméra |
| Lancer le jeu avec des options (ligne de commande) | 90 | 40 | Parseur `0x51D0D0`, ~46 flags, consommateurs tracés (dont gamegauge = dt 1/60 + monde 3 imposé) ; flags morts documentés ; Rust : --gamegauge/--map |
| Utiliser les outils de debug (dedicated, GiantsEdit) | 45 | 0 | dedicated.exe (génère .gdf, non inversé), GiantsEdit .NET + GiantsTools inventoriés, patch notes 1.1→1.5 ; debug.exe + doc |
| Modder / étendre le jeu (formats, éditeurs) | 65 | 55 | Tous les formats assets/world validés golden (819) ; Override/, Worlds/*.gck = zip ; outillage communautaire riche ; format .gdf et mécanismes Override non spéciés |

## 4. SCRIPTING / MOTEUR INTERNE / DONNÉES

| Feature | 🔬 Compris | 🦀 Moteur | Preuve |
|---|---|---|---|
| Interpréter la VM flick (41 ops) | 85 | 40 | Marche bytecode validée **545/545** (`flk_decode.py`), payloads exacts ops 1-10 et 30-53 (`FLK_FlickProcess @ 0x445A20`) ; **op 0x29 = saut implicite, à ne PAS porter** ; Rust : walk + ~20 ops sémantisées ; reste ops acteur/ombre/HUD |
| Faire jouer les acteurs de ciné (FLK_Actor 0x874) | 85 | 45 | Table offsets complète (OBJECT embarqué +0x0C, 10 slots SKN/ANM, scale lerp) via `FLK_ActorAdd`/`FLK_ActorOffsetEval` ; Rust : 15 champs + offset_eval fidèle (actor.rs) |
| Dérouler les missions (28 commandes) | 75 | 0 | Conteneur observed, 28 ops 0x03-0x26 à tailles dérivées (`mission_init @ 0x492910`), table scénario stride 0x30, état mission 0x118 ; carte champ-par-champ = open |
| Streamer les mondes (chargement récursif) | 80 | 35 | Section 6 = chunks nommés chargés récursivement, découpe z-range (`bin_load_1a0002e5`) ; `stream_player_start @ 0x5380E0` = unique ouvreur (override Bin/) ; ordre boot observé (28 opens) ; Rust : parse mais eager |
| Déclencher les événements (fx, son, triggers) | 60 | 25 | Aucun langage de script : événements embarqués — keyframes fx ospec 0x56-0x5c/0x80, instance op 0x57, ops FLK son/texte/HUD, triggers natifs (`voice_event_trigger`) ; Rust : VmEvent + SpecOp::Fx (parse seul) |
| Faire vivre les objets (OBJECT, dispatch classes) | 65 | 25 | OBJECT_LAYOUT 135 champs (provenance par champ), dispatch `cspec_update_dispatch` × 107 classes via objspec gate ; 10 témoins typés dans Ghidra (0d3a95b) ; Rust : pas de dispatch de classes |
| Faire de la physique (gravité, trajectoires) | 60 | 20 | g=32.17405 ft/s² sur sous-struct obj+0x104, projection normale, drag ; `trajectory_calculate` ballistique exacte ; vvel_decay_tick ; Rust : intégration vélocité, pas de gravité portée |
| Gérer le temps (horloge, slow motion, pauses) | 85 | 30 | `time_frame_update` (EMA, clamp, dt fixe gamegauge), slow-zone multiplier ×0x24 (`FRateSlowTime` = bullet-time), horloge flick `hud_icon_timed` ; Rust : tick déterministe, pas de slow zones |
| Partager l'état global (WORLD_STATE, tables) | 70 | 20 | WORLD_STATE DAT_0x6333E4 (offsets par opcode), tables scénario 0x4550, slots mission 0x2210, 128 flick-slots, class-spec 0x55CB00, GData ; giants_types.h ; Rust : globals flick seulement |
| Gérer la mémoire (allocators, pooling) | 55 | 10 | `map_chunk_alloc` (MAP_MemGroup, align 0x1F), `MemAllocMsg`/`mem_free_tagged` (tag fichier/ligne), free-list intrusive `main_linkage` ; Rust : N/A natif |
| Afficher les erreurs / logs | 55 | 30 | `error_msg_show @ 0x51EA20` (gated AudioGetMasterVolume → écran erreur), motif sprintf+error dans tous les loaders, `fps_log_write` (oracle) ; Rust : erreurs typées (patron, pas portage) |
| Lire les fichiers de données (GData, GText, MusicSet) | 45 | 40 | GText 100 % (gtext_parse.py + Rust) ; GData.gbn résolu par `reread_globals_bin` (magic 0x7a330000, 1440+339 mots = 7 128 B exact) ; **MusicSet.bin = 0 %** |
| Lire la liste des mondes (WorldList) | 90 | 85 | worldlist.md observed byte (magic 0x1A0003D0, 31 mondes), fix offsets +8 (Q4) ; Rust : validé validate-formats |
| Lire une sauvegarde | 55 | 5 | (voir « Sauvegarder / charger » §3) |
| Contourner la protection CD | 70 | N/A | CD-check entièrement reversé (Giants+0x13AE80 : label GIANTS1 + CDFS + marker GIANTSCD.1) + bypass mémoire documenté (`boot_session.py`) ; checksums maps = set_id abx (inferred) |
| Lire les données de PNJ (ospec, instance, sets) | 80 | 60 | xx_section3_format.md complet (4 tables, ospec 0x464 / instance 0x304, Q13 fermée par preuve octet `xx_section3_tag_proof.py`) ; TASK-002 952/952 ; **Q12 ouverte** (lien ospec→gbs inféré) ; 16 flux spec récalcitrants |

---

## Les 5 plus gros murs (à traiter en priorité par le directeur)

1. **Mecc déplacement** (25 % compris) — sans lui pas de joueur, pas de M4.
   Chemin : analyser `mecc_logic @ 0x4982C0` (décompilé dans `region_0049.c`).
2. **Collision → moteur** (65 % compris / 0 % moteur) — la spec est presque close,
   le port est la prochaine tâche naturelle.
3. **IA par classe** (35 %) — 63 handlers identifiés, 0 comportement décodé :
   commence par une classe unitaire (smartie ou vimp) en témoin.
4. **Missions wm_*.bin** (75 % compris / 0 % moteur) — 28 commandes dont il manque la
   carte champ-par-champ : un désérialiseur, pas une VM (verdict fermme).
5. **FX/particules** (35 %) — zone la plus sombre du rendu ; `fx_process` non documentée.
