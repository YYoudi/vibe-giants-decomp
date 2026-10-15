# CINEMATIC_PIPELINE — lancement gamegauge + rendu in-engine, décomp précise

Objectif : donner à l'agent Rust **toute la chaîne** — parse de l'argument, boot
différentiel, timing, chargement du monde/flicks, boucle de rendu de la cinématique —
avec fonctions, adresses GOG 1.449, valeurs exactes et provenance.

Légende : **observed** = vérifié runtime · **derived** = décomp · **inferred** = hypothèse.

---

## 1. Parse de l'argument `-gamegauge`

**Fonction : `gfx_d3d_0051d0d0 @ 0x0051D0D0`** (init D3D/launcher, parse argv).

```c
// argv walk (crt_file_lock_ok(arg, expected) = comparaison str)
else if ((len == 10) && crt_file_lock_ok(arg, "-gamegauge")) {
    DAT_00633248 = 1;                    // ← LE FLAG gamegauge
}
```

Flags voisins du même parseur (même table de chaînes @ 0x57D9A0-0x57DA60) :
`-noplay`→`633200`, `-noload`→`633208`, `-voodoo`→mode 0x15, `-dedicated`→mode 0x12,
`-noaudio`→`6331FC`, `-nostream`→`633204`, `-nophff`→`633250`, `-autodesignate`→`63325C`,
`-novimps`→`63323C`, `-bbwait`→`632358`, `-pmarkers`→mode 0xF, `-logchat`→`633240`,
**`-gamegauge`→`633248`**.

**Consommateurs du flag `DAT_00633248`** (liste exhaustive des fonctions qui le testent) :

| fonction | adresse | effet du flag |
|---|---|---|
| `time_get_ms` | 0x00518890 | dt forcé 1/60 (voir §2) |
| `time_frame_update` | 0x00518950 | dt forcé 1/60 **à chaque frame** (voir §2) |
| `game_loop_run` | 0x00471A60 | `if (FLK_FlickPlaying()==0) fps_log_write();` — log par seconde (§5) |
| `FLK_FlickRender` | 0x004444C0 | variante de rendu cinematic (§4) |
| `flick_file_load_state` | 0x00446650 | `render_stats_reset()` à chaque chargement de flick-state |
| `mission_load_world2` | 0x00488A80 | bypass menus : `dlog_push_level(&LAB_00488E60, dlog_page_process)` |
| `defaults_reset_menu` / `menu_keymap_screen` / `dlog_page_process` / `menu_handlers_lookup` / `menu_handlers_exec` | 0x004574D0 / 0x00457550 / 0x004829D0 / 0x00482E90 / 0x004835F0 | menus court-circuités |
| `menu_load_world3` / `mission_menu_load` / `mission_menu_load2` | 0x00488D00 / 0x00489120 / 0x004897D0 | idem menus |

---

## 2. TIMING — le mécanisme du déterminisme (précis)

**Fonctions : `time_get_ms @ 0x00518890`, `time_frame_update @ 0x00518950`**
(source `win95/frate.c`). Registres :

| global | rôle |
|---|---|
| `DAT_6328E0` | **dt simulation** (ce que retourne `FRateGetSecsframe`, utilisé par tous les systèmes) |
| `DAT_6328E4` | dt lissé (EMA) |
| `DAT_6328E8` | secondes mur (horloge HUD/menus — n'affecte PAS la sim) |
| `DAT_6328EC` | facteur EMA (ramp 0→0.75 par pas de 0.15) |
| `DAT_6328F0` | timescale utilisateur (×dt) |
| `DAT_5DCF9C` | baseline ms (clampée : `if (now < base) base = now`) |
| `DAT_5DCFA4` | dernier ms (slow-mo freeze : `uVar3 = last + 0x32`) |

```c
// time_frame_update (steady state, chaque frame) :
wall_ms = timeGetTime() - start;               // (ou last+50 en slow-mo figé)
DAT_6328E8 = wall_ms * 0.001;                  // horloge mur
raw = (wall_ms - baseline) * 0.001;            // dt brut
// EMA : 6 premières frames brutes, puis
//   E4 = E4*alpha + (1-alpha)*raw ; alpha += 0.15, clamp 0.75
dt = timescale * E4;
if (dt > 0.25) dt = 0.25;                      // clamp 250 ms
if (GAMEGAUGE) dt = 0.016666668f;              // ← 1/60 EXACT, FORCE CHAQUE FRAME
```

**Conséquences (observed + derived)** :
- Mode normal : dt = timescale × EMA du delta mur (au menu j'ai mesuré 0.002 s — EMA
  suit le mur ; la constante 0.025 n'est que le fallback premier-frame).
- **Mode gamegauge : dt = 1/60 s FIXE, réécrit après tous les autres calculs.**
  La cinématique est donc **fixed-step 60 Hz** → d'où le fps.txt byte-identique entre
  runs (228 secondes de sim = 13 680 pas de sim exacts, indépendants du rendu).
- `FRateGetSecsframe(obj,x) = DAT_6328E0 × mult_zone_lente` — les slow-zones
  (`FRateSlowTime @ 0x00518BE0` alloue les entrées 0x24 octets de `DAT_5DCFA8` ;
  `win95_frate_00518c60` les décrémente et libère) multiplient le dt par zone.
  **En gamegauge aussi** (le forçage 1/60 arrive AVANT la multiplication de zone :
  `FRateGetSecsframe` multiplie à la lecture — portez les deux).

## 3. Enchaînement du lancement gamegauge (observed + derived)

1. `gfx_d3d_0051d0d0` parse `-gamegauge` → `DAT_633248=1`.
2. Menus neutralisés : `mission_load_world2` pousse directement la page
   `&LAB_00488E60` (page gamegauge) au lieu de `dlog_page_26_open` ; les handlers de
   menus testent le flag et court-circuitent.
3. Le monde "Mecc Story 4" se charge par le chemin standard
   (`mission_load_full` → world bin `w_<nom>.bin` → GTI → flicks) — écran
   "Loading Mecc Story 4: The Search for Timmy" **observed**.
4. `flick_file_load_state` : à chaque flick-state chargé → `render_stats_reset()`
   (les compteurs graphics du gamegauge repartent de zéro).
5. `game_loop_run` : quand aucun flick ne joue (`FLK_FlickPlaying()==0`) →
   `fps_log_write()` → accumule ce qui deviendra `fps.txt` (1 ligne par seconde de sim).
6. Fin de la dernière cinématique → le jeu **se ferme seul** (exit propre, observed).

## 4. RENDU de la cinématique — `FLK_FlickRender @ 0x004444C0`

Appelée par frame quand un flick joue (depuis la chaîne de rendu principale, après
`FLK_FlickProcess` qui a avancé le bytecode). Séquence exacte :

```c
if (flick->b4 == 0) return 1;                  // pas de caméra node → rien
fov    = render_get_fov();                     // FOV courant
aspect = render_get_aspect();
XFGetViewport_2();                             // viewport
view_matrix_get(local);                        // matrice vue de base
render_get_clip_nearfar(&near, &far);
FNT_StringRender(1.0f, far_info);              // couche texte (sous-titres)
hud  = AddHud(flick_camera->c, flick->b0);     // HUD du flick
mat  = flick_node_mat_get(flick->b4, hud, actors_table[1]);
GEO_MatTranspose(tmp, mat);
view_matrix_reset(tmp);                        // ← LA CAMÉRA EST POSÉE ICI (node flick)
cam  = XFGetCameraOrigin();                    // origine caméra (3 floats)
saved_dt = DAT_6328E0;
DAT_6328E0 = *(float*)(flick + 0xAC);          // ← dt PROPRE DU FLICK pour ses acteurs
// passe 1 : les N=flick->94 acteurs du flick (table flick->A0, stride 0x21d dwords
// = 0x874 bytes = FLK_Actor) :
//   flag +0x3C |= 0x20 ; object_animate_process(obj, flick_dt)
// passe 2 : monde (liste DAT_632D68) :
//   obj->D8 &= ~0x40 ; obj_velocity_commit()
//   si obj->D8 & 0x40 : object_apply_location() + objspec_dispatch_gate(obj)
//   classes animées spéciales : 0x3D (ObjectSetAnim(...,0x34,1)), 0x65/0x66
// passe 3 : FLK_ObjectInFlick(flick, obj) → traitement des objets du flick
DAT_6328E0 = saved_dt;                         // restauration du dt global
```

Points clés pour un portage :
- La **caméra de la cinématique vient du flick lui-même** (node matrix) — elle écrase
  la vue par `view_matrix_reset` après transposée.
- Les acteurs du flick ont **leur propre dt** (`flick+0xAC`), indépendant du dt monde.
- Le stride FLK_Actor = **0x874 octets** ; la table = `flick+0xA0`, N = `flick+0x94`.
- Le monde tourne AUTOUR (vitesse→position→dispatch) : la cinématique est jouée par
  le même moteur que le jeu, pas par un player séparé.

## 5. fps.txt (l'oracle chiffré)

- Écrit par `fps_log_write` — déclenché depuis `game_loop_run` en mode gamegauge
  chaque frame sans flick actif (agrégation par seconde de sim).
- Format : `"<avg> Giants v1.400"` / `"<n> Min"` / `"<n> Max"` / `"<n> Second <i>"` × N.
- **CORRECTION run4 (2026-10-15)** : le fichier n'est byte-identique qu'INTRA-session
  (run1==run3, md5 `aa93dfcbcb5ee9e67de0f5cf40d6ef78`) ; entre sessions/machines il
  varie (run4 : 209 lignes, avg 309.12) — les comptes par seconde = frames rendues
  par seconde de mur, dépendants de la charge. Le fixed-step 1/60 reste vrai pour la
  SIM (dt forcé) mais pas pour le compte de frames de mur.
- Oracle de parité corrigé : (a) la playlist cyclique (§7), (b) la STRUCTURE du
  fichier (frontières de scènes aux mêmes positions — dips à s8 et s15-17), PAS
  l'égalité byte-exact.

## 6. Checklist de portage Rust (résumé opérationnel)

1. Parse `-gamegauge` → flag → dt forcé 1/60, menus bypassés.
2. Charger le monde par le chemin standard (formats déjà spec'd : world bin, GTI, GBS,
   textures GZP) + les flicks `flk_story4_*` (décodeur `tools_spec/flk_decode.py`).
3. VM flick : 41 opcodes (table dans MISSION_VM.md), records `{op,adv,payload}`,
   fixed-step 60 Hz en gamegauge.
4. Rendu : caméra depuis node flick → view matrix ; acteurs CPU-skinnés
   (`anm_skin_verts_apply`) ; terrain GTI ; texte FNT ; HUD icons.
5. Oracle : playlist cyclique (§7) + structure des frontières fps.txt + captures.

## 7. PLAYLIST gamegauge — table id→fichier complète (capture runtime 2026-10-15)

Capturé au breakpoint `flick_file_load @ 0x00443480` (x32dbg, capteur
`scripts/flick_name_capture.py`) pendant **2 passes complètes** de la cinématique —
données : `RuntimeLab/logs/traces/flick_playlist.json` (+ brut `flick_id_map.json`).

**Règle (observed + cross-check disque)** : la playlist = les fichiers
`Bin/flk_story4_T_square_<N>.bin` triés par N (ordre naturel, variantes comme
`25a` après `25`), les N absents du disque sautés ; **id = 0x0D + index**.
Signatures des appels : `flick_file_load(ctx, id, NULL, 0, ...)` — le nom est résolu
depuis `ctx + *(ctx+0x14)` (string dans la struct), pas via param_3.

| id | fichier | id | fichier | id | fichier |
|----|---------|----|---------|----|---------|
| 0x0D | T_square_2 | 0x20 | T_square_23 | 0x33 | T_square_41 |
| 0x0E | T_square_3 | 0x21 | T_square_24 | 0x34 | T_square_42 |
| 0x0F | T_square_4 | 0x22 | T_square_25 | 0x35 | T_square_43 |
| 0x10 | T_square_5 | 0x23 | T_square_25a | 0x36 | T_square_44 |
| 0x11 | T_square_6 | 0x24 | T_square_26 | 0x37 | T_square_48 |
| 0x12 | T_square_7 | 0x25 | T_square_27 | 0x38 | T_square_49 |
| 0x13 | T_square_8 | 0x26 | T_square_28 | 0x39 | T_square_50 |
| 0x14 | T_square_9 | 0x27 | T_square_29 | 0x3A | T_square_51 |
| 0x15 | T_square_10 | 0x28 | T_square_30 | 0x3B | T_square_52 |
| 0x16 | T_square_11 | 0x29 | T_square_31 | 0x3C | T_square_53 |
| 0x17 | T_square_12 | 0x2A | T_square_32 | 0x3D | T_square_54 |
| 0x18 | T_square_13 | 0x2B | T_square_33 | 0x3E | T_square_55 |
| 0x19 | T_square_14 | 0x2C | T_square_34 | 0x3F | T_square_56 |
| 0x1A | T_square_15 | 0x2D | T_square_35 | 0x40 | T_square_57 |
| 0x1B | T_square_16 | 0x2E | T_square_36 | 0x41 | T_square_58 |
| 0x1C | T_square_17 | 0x2F | T_square_37 | | |
| 0x1D | T_square_18 | 0x30 | T_square_38 | | |
| 0x1E | T_square_19 | 0x31 | T_square_39 | | |
| 0x1F | T_square_20 | 0x32 | T_square_40 | | |

- **Trous observés et confirmés disque** : T_square_21, 22, 45, 46, 47 n'existent
  pas dans `Bin/` → absents de la playlist. `T_square_58` = dernier fichier.
- **La playlist est CYCLIQUE** (observed, 2 passes) : après 0x41, un hit **0x42**
  (jamais de nom résolu sur lui, probablement l'entrée de wrap) puis retour à 0x0D.
  La fin du PROCESSUS jeu n'est donc pas un id de la playlist — la durée en secondes
  du fps.txt (209 vs 228 entre sessions) reste dépendante de l'horloge mur.
- Tous les noms minuscules `story4_t_square_*` dans les captures = tels qu'en
  mémoire ; les fichiers disque sont `flk_story4_T_square_*.bin` (T majuscule —
  Windows insensible à la casse, les deux chemins s'ouvrent).

## 8. SOUS-TITRES — le flux texte des flicks (ops 14-22)

Les ops 14-22 du flux de records FLK sont le **moteur de sous-titres**
(`FLK_FlickTextProcess @ 0x004440F0` — observed, decomp `Main_flick` module).
Même flux que les ops scène (histogramme `flk_decode.py --stats` : ops
14,15,16,18,21 présents dans les 545 fichiers). Le curseur partagé vit à
`flick+0xfc` ; les handlers écrivent dans la struct flick :

| op | nom | sémantique (payload = `puVar6[2..]`, adv = `puVar6[1]` dwords) |
|----|-----|----------------------------------------------------------------|
| 14 | text-time-copy | `flick+0x124 = flick+0x120` (reset du chrono de fade) |
| 15 | font-tick | `FNT_RenderInfoProcess(&flick+0x104, flick_dt)` (flick+0xAC = dt flick, le MÊME que les acteurs) |
| 16 | **text-set** | id = payload[0] (+base si non nul) → `TextGetPtr(id)` → `flick_text_layout(flick+0xf8, str, &flick+0x104)` |
| 17 | param A | `flick+0x114 = payload[0]` |
| 18 | param B | `flick+0x118 = payload[0]` |
| 19 | param C | `flick+0x10c = payload[0]` |
| 20 | param D | `flick+0x110 = payload[0]` |
| 21 | **font-set** | `FNT_RenderInfo` = payload paire `[0],[1]` (écrit flick+0x104/0x108 — font id + param) |
| 22 | **fade-set** | durée = payload[0] secondes ; 0 → rate=1000.0 sinon `rate = 1.0/durée` → flick+0x11c ; ignoré si chrono < 0 |
| 23 | param E | `flick+0x128 = payload[0]` (observed 707×) |

- **Résolution du texte** : `TextGetPtr @ 0x00507B00` = lookup **par nom** dans la
  table des traductions chargée (`fx_table_lookup(handle@0x57bc94, name)`) — la
  table = `Bin/GText*.bin` (langue courante ; format 100 % décodé :
  `scripts/gtext_parse.py`, loader jeu +0x10D660). Fallback si absent : retourne
  le nom brut (le string pool du flick sert donc aussi de source de secours).
- **Layout** : `flick_text_layout @ 0x00446CE0` copie 13 floats (FNT_RenderInfo),
  mesure la largeur via `textrender_draw_large(font, str)`, aligne le curseur
  (`info[4]-=w*info[0]`, `info[5]-=h*info[1]`), gère `\n` (saut = info[3] hauteur
  de ligne), re-mesure par ligne.
- **Rendu** : par les passes FNT déjà documentées (RENDERER_GGDX7 — texte FNT,
  HUD) ; la struct affichée vit flick+0xf8 (rect/couleur posés par les params
  17-20/23, fade par 22).
- **Pour le portage Rust** : il faut (a) parser GText*.bin (fait : `gtext_parse.py`
  comme référence), (b) une fonte FNT (format non encore inversé — OPEN ITEM,
  mais les IDs de fonte posés par op 21 sont dans les flk), (c) implémenter les
  ops 14-23 avec la table de champs ci-dessus.

## 9. AUDIO cinématique — op 13

- `FLK_FlickProcess @ 0x00445A20`, case 0x0D (observed) :
  `sound_play_obj(sound_id=payload[1], source=actor_base + payload[0]*0x874 + 0xc)`
  — son 3D **attaché à un acteur** du flick (stride acteur 0x874, +0xc = champ
  position/attribut son). payload[0] = index acteur (-1 → pas de son).
- ops 11/12 = enable/disable acteur (`actor+8` flag set/clear).
- Sons ambiant opportunistes hors VM : `ambient_critter_ai_c36` joue rnd les ids
  0x4a6/0x4a7 (ticks d'ambiance — pas une partie de la VM).
- **Banques** : les sons référencés par id dans `Bin/*.gzp` (VO_*.gzp = voix,
  Stream/ = musique) — chargeurs déjà cartographiés dans FORMAT_INVENTORY +
  docs de formats. Le moteur audio (mixage 3D) reste du côté Rust (crate
  `giants_audio`).

## 10. Chaîne story + ARRÊT du jeu en gamegauge

- La table des "flick slots" vit dans la mémoire de mission (base `DAT_006330e4`) :
  **128 slots de stride 0x20**, noms à `base+0x1210+slot*0x20`, handles à
  `base+0x210+slot*0x20`. Des slots spéciaux nommés **"start"** et **"end"**
  existent (`match_start_entry @ 0x004EB850` matche "start" ; `fx_logic @
  0x004EBA40` type 3 matche "end").
- **Fin de chaîne (derived, decomp)** : quand le slot courant matche **"end"**
  (= notre id observé 0x42, jamais de nom de fichier résolu), `fx_logic` pose
  `world_done=1 (DAT_00632b98)` → `game_loop_run` voit `world_done && !FLK_FlickPlaying()`
  → pose `world_next=1` → frame suivante : `world_next_enter()`.
- L'id 0x42 = 0x0D + 53 = l'entrée juste après le dernier fichier T_square_58 →
  la playlist des fichiers EST la chaîne story4, et 0x42 est son terminateur.
- La boucle observée en run5 (retour à 0x0D après 0x42) = reprise de la chaîne
  par le slot "start" (`match_start_entry`) — **et le run6 a tranché le modèle
  complet (2026-10-15, observed)** :
  1. La playlist joue 0x0D→0x41 (~227-229 s de sim).
  2. **1er passage par "end"** : `fx_logic(3)` (flag `DAT_00632b94==0`) charge le
     flick "end", pose 94=1, puis la chaîne **repart au début** (boucle d'attirance).
  3. **2e passage par "end"** : 94==1 → branche sautée → suite du fx →
     `world_next_enter` : `FLK_FlickStop()`, index monde+1 vs dict (InitFxDict),
     plus de monde → `gameover_menu` → **le processus se ferme** (confirmé run6 :
     exit propre à 04:06:45, fps.txt écrit une seule fois à la fermeture —
     229 lignes "Second", avg 498.99, machine-load-dépendant comme établi).
  Le flag 94 n'est remis à 0 QUE par le rechargement de monde (`_unmapped_004e`
  :11308) — d'où exactement UNE boucle d'attirance puis l'arrêt.
- **Pour le portage Rust** : comportement fidèle = jouer la chaîne 0x0D→0x41,
  jouer le flick "end", reprendre la chaîne une fois, fermer au 2e "end" — ou
  simplifier en : chaîne + end + fermeture (l'utilisateur perçoit la boucle
  comme une seconde lecture de la cinématique).
- `world_next_enter @ 0x004EE800` (observed) : `if (dialog_level_is_base()) return;
  FLK_FlickStop(); if (InitFxDict() < world_index+1) gameover_menu(); else
  AudioSetSpeakerConfig(next); mission_texture_audio();`


## Open items

- ~~Fonte FNT~~ **RÉSOLU 2026-10-15** : pas de fichier de fonte — rasterisation
  GDI runtime, spec complète dans `docs/formats/FONT_GDI.md` (LOGFONT, atlas
  256×128 u16, métriques 5 octets/char).
- ~~Payloads ops 30-53~~ **RÉSOLU 2026-10-15** : table exacte dans
  `docs/systems/MISSION_VM.md` §MISE À JOUR 3 (op 41/0x29 = skipped observé).
- Dernier maillon de fermeture : entre `gameover_menu` (dialog Restart/Quit) et
  l'exit processus observé — le chemin exact en gamegauge (auto-quit du dialog ?)
  reste à lire si le portage veut reproduire le décompte exact des frames.

## 11. MANIFESTE D'ASSETS de la cinématique (outils : `tools_spec/flk_manifest.py`)

Extraction automatique des 53 flicks de la playlist (données :
`RuntimeLab/logs/traces/story4_manifest.json`, régénérable) :

- **14 acteurs nommés** (op 2) : `baz, bennet, borjoyzee, gordon, kabuto, lander,
  offspring, reaper, reaper1, reg, rpman, rpman1, tel, timmy` — le casting du
  chapitre 4 Mecc. Slots/types par fichier dans le JSON.
- **Caméra** : une seule track, `camera01` (op 4), via le director.
- **65 noms de sous-titres GText** (op 16), convention `Flk_story4_T_square_<N>_<k>`
  — présence à vérifier dans `GText*.bin` (le parseur gtext existe des deux côtés).
- **Op 13 (son VM) : AUCUNE occurrence dans les 53 fichiers** — l'audio de la
  cinématique ne vient PAS de la VM flick ! Sources réelles : la musique/stream
  de la couche mission + les sons attachés aux objets du monde. **Conséquence
  M7** : pour la parité de la cinématique, le canal audio = stream du monde,
  pas l'op 13 (qui sert aux flicks de gameplay).
- **Chaîne de succession** : le nom du flick SUIVANT (`story4_t_square_3`...)
  vit dans le string pool de chaque fichier, référencé par le loader de fin de
  chaîne (`main_flick_00443740`), PAS par une op. Le dernier fichier
  (T_square_58) n'a pas de successeur → fin de chaîne → slot "end" (§10).
  Le portage peut donc dériver la playlist du contenu des fichiers eux-mêmes.
- **Op 44 (0x2C)** cible des objets du monde nommés (`reg011`, `baz049`,
  `tel022` = instances .bin), pas des acteurs flick — confirmé par payload.
- Résolution des noms : les payloads des op 1/2/4/16/47 = **offsets dans le
  fichier .flk** (l'image entière est mallocée par le loader) — NUL-terminés.
  Seule exception : le nom du director (op 1) pointe une structure binaire de
  40 octets après le nom du successeur (champ nom exact TBD — non bloquant :
  le template du director vient de toute façon du monde .bin).

## 12. ORDRE DE CHARGEMENT réel du boot gamegauge (trace runtime 2026-10-15)

Capteur `scripts/fileopen_capture.py` sur `stream_player_start @ 0x005380E0`
(l'unique ouvreur de fichiers du moteur — les noms passent par le registre
virtuel fx_table + override `Bin/`). Données : `RuntimeLab/logs/traces/
fileopen_trace.json` (28 opens uniques, 2 runs) :

```
GameObj.bin → GData.gbn → worldlist.bin → worldlist2..5.bin →
W_Intro.bin → xx_intro.bin → xx_menus.bin → W_Intro.abx → weapondefs.bin →
GTextEnglish.bin → intros.bin → W_intro_island.bin → fx_world_dust.bin →
tx_lev1.bin → xx_effects.bin → xx_efx.bin → xx_permanentaliens.bin →
xx_patch_screens.bin → xx_markers.bin → xx_tools.bin → W_intro_island.abx →
W_Story4.bin → xx_giants_logo_3d.bin → wm_mission1.bin → xx_story4.bin
```

- **Le monde de la cinématique = `W_Story4`** (chapitre 4 Mecc — confirmé
  runtime ; les variantes Kstory4/Rstory4 = chapitres Kabuto/Reaper). La
  cinématique se joue DANS le monde intro : l'île d'intro charge d'abord
  (W_Intro/W_intro_island), puis W_Story4 + sa mission (`wm_mission1.bin`) et
  la séquence story4 (`xx_story4.bin`) — les flk de la playlist s'ouvrent à
  chaque segment (ordre = playlist §7, déjà établi).
- Les `worldlist2..5.bin` = registres de mondes additionnels (complément
  WorldList.bin — à documenter si le portage itère les mondes).
- Les `xx_*.bin` = packs système (intro, menus, effets, marqueurs, écrans).
- **Note instrumentation** : un BP sur `stream_player_start` + traçage lent
  provoque un crash reproductible (AV second-chance `mem_debug_alloc
  @ 0x0053A321`, `mov [ecx-4],eax`) juste après `xx_story4.bin` — le jeu joue
  parfaitement avec un BP sur `flick_file_load` seul (runs 5-6). Suspect :
  race sensible au timing IO sous instrumentation lourde. Ne PAS utiliser ce
  BP pendant les runs de parité ; pour retracer, logger léger (déjà dédupliqué).
