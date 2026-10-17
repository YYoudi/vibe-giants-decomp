# MENUS — le système de menus de Giants (dlog + écrans 3D "status screen")

> Spec complète pour portage Rust/Bevy. Corpus GOG 1.449 (`decompiled/gog144_modules/`).
> Rappel `docs/TRUST.md` : ~85 % des noms du corpus sont des inférences LLM — chaque
> affirmation ci-dessous a été vérifiée sur le corps, et **toutes les fonctions
> « handler » clés des menus sont des labels (`LAB_`) que Ghidra n'a PAS faits en
> fonctions** : leur corps a été désassemblé à la main (capstone) depuis
> `RuntimeLab/gog141/Giants.exe` — binaire vérifié identique au corpus (chaînes
> `MH_*`, `intro_island`, `DevNoMissionLoad` aux mêmes VAs que
> `s_*_0055beXX` ; sections .text/.rdata/.data à `file_off = VA − 0x400000`).
> Provenance : **observed** = lu dans le corps décompilé/désassemblé ;
> **byte-verified** = vérifié sur fichiers du jeu ; **derived** = conséquence
> directe d'un observed ; **inferred** = interprétation, à re-vérifier.

## 0. Vue d'ensemble (ordre observed)

```
boot → monde intro_island + cinématique flk (CINEMATIC_PIPELINE.md)
     → mission_intro_load (0x483BA0)          [écran 0x13 : sélection joueur, 7 entrées]
     → dlog_page_1f_open (0x48EE60)           [écran 0x1f : 3 entrées]
     → menu_mission_launch (0x482B60)         [MENU PRINCIPAL, écran 0x12 : 7 entrées]
        ├─ StartSingle  → mission_load_full(0xb)
        ├─ JoinMulti    → mission_load_full(0xc)
        ├─ HostMulti    → mission_load_full(0xd)
        ├─ GameOptions  → mission_load_full(0xe) → dlog_page_1b_open (écran 0x1b : 11 entrées)
        ├─ LoadSingle   → mission_load_full(0xf)
        ├─ ChangeID     → defaults_reset_menu → retour mission_intro_load
        └─ ExitGame     → dlog_page_1e_open (confirmation, écran 0x1e : 3 entrées)
```

Deux couches de rendu cohabitent : le **menu-monde 3D** (l'île `intro_island`
vivante en fond, les entrées = polygones projetés) et l'**overlay 2D dlog**
(texte d'aide, pages de widgets). Le menu EST un niveau de jeu : pas de
fichier de layout dédié lisible, mais une table statique dans l'exe (§2).

## 1. ARCHITECTURE

### 1.1 La pile de niveaux dlog (observed)

- `dlog_push_level @ 0x00426F40` (region_0042.c:9432) : pile globale indexée par
  `DAT_00556498` (garde-fou overflow > 10), entrées de 5 dwords à `0x59AB80 + i*20` :
  `[+0] handler process`, `[+4] handler draw`, `[+8]/[+0xC] résérvés`,
  `[+0x10] flag textentry`.
- `dialog_level_pop @ 0x00426FD0` (region_0042.c:9492) : dépile **seulement si le
  handler passé en argument == handler courant** (sécurité anti-dépilage croisé).
- `dialog_level_set_textentry_mode @ 0x00426FA0` (region_0042.c:9469) : pose le flag
  textentry du sommet + `hud_add_icon(1)`.
- **Dispatcheur** : `dialog_level_process @ 0x00426EE0` (region_0042.c:9368) — si pile
  non vide : `comm_heartbeat_send` + `comm_msg_dispatch` puis appelle le handler
  process du sommet ; **sinon `game_loop_run(1)`** (le jeu tourne). C'est le menu
  qui remplace la boucle de jeu, pas une couche par-dessus.
- **Rendu** : `render_error_poll @ 0x426F20` (region_0042.c:9401) appelle le handler
  draw du sommet. Appelé par la boucle principale Win95 entre
  `render_scene_begin()` / `AddHud…` / `render_scene_end()` (region_0047.c:1740-1764,
  même motif en region_0044.c:5062/6711).

Un « écran » = un couple (handler process, handler draw) + un état global
(§1.3). Les handlers process sont presque toujours des `LAB_` non-fonctions.

### 1.2 Le draw générique dlog_page_process (observed)

`dlog_page_process @ 0x004829D0` (region_0048.c:3267-3388) est le handler draw
partagé par tous les écrans « monde 3D » :

1. Si dédié (`DAT_00633248`) : rien. Si cinématique en cours (`DAT_0059eeb0 ≠ 0`) :
   branche 2D seule (widgets + texte d'aide), pas de monde.
2. Branche monde : `camera_override_refpt(DAT_0059ee98, 0)` → `ref_anode_user` →
   `xfmat_mult_b` → `main_drawobj_0042d490` (rend le monde avec la caméra menu),
   puis `dlog_widgets_draw(page)` si une page 2D est ouverte (`DAT_0059eed4`
   text-entry / `DAT_0059eed8`), sinon `alpha_queue_push_3(0,2)`.
3. `shopmenu_slot_entries_push(&DAT_00632900, écran, -1)` puis
   `status_draw_sub(&DAT_00632900)` → dessine les **panneaux 3D du menu** (§1.4).
4. `render_view_xform` + `camera_override_done` + `Audio3DTestToneStop`.
5. Texte d'aide : `dlog_text_draw_wrap(0xFFFFFF, 0, 0.03125, 0.01, 0.96,
   DAT_0059e8e0)` (région_0048.c:3326) — blanc, fonte 0.03125, **y en unités
   fontes depuis le bas** (cf. §4.1), coin haut-gauche.
6. `ANM_DumpCluster` + `fps_display`.

### 1.3 L'état global d'un écran menu (observed, initialisé par chaque `_open`)

Tous les `dlog_page_XX_open` suivent le même gabarit (ex. `dlog_page_1b_open @
0x00489D40`, region_0048.c:8541-8699) :

| global | rôle |
|---|---|
| `DAT_0055bdb8` = `DAT_0063291c` | **id d'écran** (0x12 menu principal, 0x13 intro, 0x14 liste missions, 0x1b options…) |
| `DAT_0055bdb0` | nombre d'entrées de l'écran |
| `DAT_0055bdb4` | index de scroll (première entrée visible ; wrap au-dessus) |
| `DAT_0059ee9c` | index sélectionné |
| `_DAT_0059eea4` | dernier index visible (scroll) |
| `DAT_0059ee98` | objet caméra du menu (`object_allocate_type`) |
| `DAT_00632924/28` | scale x/y = `DAT_00632e84/88` (largeur/hauteur écran en px) |
| `DAT_0059e8e0` | buffer char[] du texte d'aide courant (sprintf "%s" d'un TextGetPtr) |
| `DAT_0059dcd0[100×3]` | slots fx « selection fx » par entrée (alloués paresseusement par `main_menu_004832f0`, Main_menu.c:64) |
| `_DAT_0059eecc` | callback fx par entrée (défaut `LAB_004829c0` = `&DAT_0059dcd0[entry*3]`, désassemblé) |
| `_DAT_0059eec8` | callback **nom d'fx** par entrée (ex. `LAB_00483990` menu principal) |
| `DAT_0059eed4` | page dlog 2D « text entry » ouverte |
| `DAT_0059eec4` | liste chaînée d'écrans supplémentaires (champs +0x44/+0x48/+0x4c/+0x50) |

Caméras par type d'objet (observed) : `0x401` = écran 0x13 intro
(region_0048.c:4445), `0x402` = écrans 0x14/0x15/0x1d/0x1e/0x1f… , `0x3FB` =
menu principal (menu_mission_launch, region_0048.c:3493) et options 0x1b
(region_0048.c:8616). L'objet reçoit le flag `0x40000000` (+0xd8) puis
`camera_override_refpt(obj, 0)`.

### 1.4 Le fond 3D et les panneaux : le monde + les « status screens » (observed)

- **Monde** : `intro_island` (le nom est comparé à `*(DAT_006330e4+4)` dans
  mission_intro_load, region_0048.c:4387 ; `flick_file_load_state("intro_island_1")`
  ligne 4395 gère la reprise après cinématique ; `teammecc_clear_mode` ligne 4405).
- **Panneaux** : `main_status_00500520 @ 0x00500520` (main_STATUS.c:6-159) construit
  une « status screen » par objectset de la liste statique `DAT_005775e0` :
  `objectset_find_2` → objdata, puis **« P3DN3D List »** (`n × 0x38` octets par
  objet) = les polygones cliquables. `terrain_mesh_query`,
  `mission_screen_icon_bounds_calc`, `mission_screen_slot_bounds_merge` finalisent
  les bboxes. Ces écrans servent AUSSI au HUD in-game (même système).
- **Draw des panneaux** : `status_draw_sub @ 0x00500890` (region_0050.c:516) —
  projette le panneau avec `textrender_glyph_quad` décalé par la position du
  curseur (`DAT_00632abc/ac0` / taille écran) : le panneau 3D « scrolle » avec
  la sélection.
- **Polygones d'entrée** : chaque entrée de menu = un polygone du panneau avec
  bbox écran stockée à `poly+0x34/0x38/0x40/0x44` (lecture dans
  `menu_poly_hittest_process @ 0x004FFF10`, region_004f.c:8882-9010 ; projection
  = simple lerp `mission_004fe2d0 @ 0x004FE2D0`, region_004f.c:8572).
- **Table statique des écrans (byte-verified)** : `DAT_00632918` (le champ +0x18
  de la struct 0x632900, posé par main_status_00500520 ligne 118 :
  `param_1[6] = &PTR_PTR_00576ed8`) pointe sur **0x576ED8 dans l'exe** : 0x2C
  records de 0x24 octets `{ptr vers tableau d'entrées, count}`. Les tableaux
  d'entrées sont des listes de pointeurs NULL-terminées : écran 0x12 →
  0x575FF8 (**7 entrées**), 0x13 → 0x57602C (**7**), 0x1b → 0x57604C (**12**).
  Chaque entrée pointe un struct `{ptr data, vtable 0x5795B0/0x5795C0, callback
  0x004FC5D0}` — le callback standard (désassemblé) appelle
  `DAT_0059eec8(entry)` = obtient le **nom d'fx de sélection**.
- **Textures panneaux** : `w_menus.gzp` (byte-verified) contient `Menus.gti`,
  `game_logo.tga`, `i_start.tga`, `cursor00.tga`, `i_selected.tga`, ~180
  `st_*.tga` (status screens). Lu 368× au boot/menus
  (RuntimeLab/logs/boot1_giants_events.csv:2217+, boot_trace_20260825 seq 18).
  `w_menus.bin` (3 878 o) / `w_menus.abx` (20 128 o) existent (famille
  bin_world/abx, format_validation_report.json:409/1349) mais **ne sont jamais
  ouverts** dans les traces boot → leur rôle runtime est OPEN (piste : variante
  « monde menus » pour l'éditeur ou chargés depuis un pack ; grep `menus` dans
  l'exe = aucun hit, le nom ne vient donc pas d'une chaîne).

### 1.5 Le pipeline 2D : quads texturés (observed/derived)

- `dlog_scene_submit @ 0x0042A4F0` (region_0042.c:13437) : submit générique
  DrawPrimitiveUP — FVF `0x24` (xyz/diffuse/uv, 6 vertex = 2 triangles),
  diffuse forcé 0xFFFFFFFF, texture = world+0x4C ; utilisé pour le ciel du
  monde (RENDERER_GGDX7 MAJ 2) **et** par les passes panneaux (état 0x60720 +
  fog). Les widgets 2D passent par les vtables D3D `DAT_00656428/30/34/38/4C`
  (states + lock/unlock vertex buffers) — cf. `hud_write_quad_vertices @
  0x004292B0` (region_0042.c:11665) et `dlog_rect_vtable_draw @ 0x428B20`
  (region_0042.c:11115, 4 à 6 quads-lignes = cadre de sélection, state 0xa0).
- `cursor_texture_draw @ 0x004295C0` (region_0042.c:11932) : texture
  `"cursor"` (chaîne 0x556568 → `cursor00.tga` de w_menus.gzp, inferred pour
  l'alias), state `0x32c`, couleur 0xFF000000, hotspot décalé de 2 % de la
  largeur écran, positionné sur `DAT_00632abc/ac0`.
- `hud_cursor_status_draw @ 0x427100` (region_0042.c:9669) : si monde actif →
  `status_draw_sub` (curseur intégré au panneau 3D), sinon curseur texture.

## 2. STRUCTURE D'UN MENU (données, entrées, sélection)

- **Aucune page n'est définie dans un fichier** : le layout visuel vit dans
  l'exe (table 0x576ED8 + objectsets du monde, §1.4) ; les textes d'aide et
  labels 2D viennent de GText (§5). Le Rust devra réencoder la table
  0x576ED8 ↔ panneaux Bevy.
- **Cycle process standard** (observed, identique dans menu_handlers_lookup
  region_0048.c:3632-3950, menu_handlers_exec 4036-4354, handler intro
  0x483FD0 désassemblé, options 0x48A140 désassemblé) :
  1. `screenshot_helper @ 0x4A5CD0` puis `main_menu_004832f0` (update : fx de
     sélection + animation caméra menu — `obj_velocity_commit`,
     `objspec_dispatch_gate`, `object_animate_process`,
     `ObjectCalculateTransform` sur DAT_0059ee98, Main_menu.c:64-180).
  2. **Retour/ESC** = flag `0x632AA7` → teardown complet (voir §2.2) puis
     `sound_play(0x657)`.
  3. **Haut/Bas** = `0x632AA1`/`0x632AA2` → `menu_mission_set_clamped @
     0x004834D0` (region_0048.c:3952) : clamp/wrap sur
     `[DAT_0055bdb4, DAT_0055bdb0-1]`, mise à jour du slot fx (table
     `DAT_0059dcd0[i*3]`), `sound_play(0x65A)` si changement, puis
     `mission_004fe2d0` replace le **curseur souris** au centre du polygone de
     la nouvelle entrée (0.5,0.5) × taille écran — la navigation clavier
     déplace physiquement le curseur.
  4. **Souris** : `menu_preview_clamp @ 0x500120` (region_0050.c:17) borne
     `DAT_00632abc/ac0` à la bbox union des polygones de l'écran
     (`DAT_00632bcc`), puis `menu_poly_hittest_process` renvoie l'entrée sous
     le curseur (bbox écran par polygone, flag &4 = cliquable).
  5. **Confirmation** = flag `0x632AA8` (Enter) ou `0x632AAA` (clic) →
     teardown + action de l'entrée + `sound_play(0x659)`.
- **Teardown standard** (répété à l'identique partout, ex. region_0048.c:3658-3745) :
  `dialog_level_pop(handler)` → `camera_override_done` →
  `object_destroy(DAT_0059ee98)` → destruction des fx par entrée
  (`main_menu_00483200`, Main_menu.c:6) → `mission_00447fd0(0,2)` → reset des
  32 dwords de flags `0x632AA0`.
- **Sons** (ids observed, noms symboliques inconnus) : `0x657` retour,
  `0x659` confirmation, `0x65A` déplacement, `0x6E6` ouverture d'écran-menu
  (region_0048.c:4541, 8666). joués par `sound_play @ 0x495920`
  (region_0049.c:6749).
- **Fx de sélection** : `LAB_00483990` (désassemblé) mappe l'entrée du menu
  principal → nom GText de fx : 0=`MainStart`, 1=`MainJoin`, 2=`MainHost`,
  3=`Options`, 4=`MainLoad`, 5=`MainChangeID`, 6=`MainExitGame` (chaînes
  0x55BF78…0x55BF2C, byte-verified) — confirme l'ordre des entrées.

### 2.1 Flags d'entrée (bloc `0x632AA0`, 32 dwords ; cf. INPUT.md)

Observed par usage dans les handlers : `[+0x01]` haut, `[+0x02]` bas,
`[+0x04]/[+0x05]` gauche/droite (sliders), `[+0x07]` retour, `[+0x08]`
confirmer, `[+0x0A]` clic souris, `[+0x13]` sélection joueur (intro),
`[+0x0E..0x12]` edges boutons souris (région_0041.c:12840-12865).
Le curseur `DAT_00632abc/ac0` est intégré par le pass input
(région_0041.c:12873-12965 : += deltas souris `0x632B10/14`, clamp écran).

### 2.2 Scroll

`DAT_0055bdb4` = première entrée visible ; wrap modulo la fenêtre visible
(`_DAT_0059eea4`) ; le panneau 3D défile via le décalé curseur dans
`status_draw_sub`. Pas de scrollbar widget dédié observé pour les écrans
monde ; les listes 2D dlog scrollent via `dlog_list_navigate_sound @
0x4296C0` (region_0042.c:12007) + flag `0x200` « dirty » du widget.

## 3. LES ÉCRANS UN PAR UN

Table récapitulative (tous observed sauf mention) — « id » = DAT_0055bdb8 :

| id | écran | _open @ | handler (désassemblé sauf *) | entrées |
|---|---|---|---|---|
| 0x13 | sélection joueur (boot) | `mission_intro_load 0x483BA0` | `LAB_00483FD0` | 7 (0 = ?/retour, 1-5 = profils registre, 6 = nouveau) |
| 0x1f | post-sélection | `dlog_page_1f_open 0x48EE60` (region_0048.c:12496) | `LAB_0048F160` (non lu) | 3, défaut 2 |
| 0x12 | **menu principal** | `menu_mission_launch 0x482B60` | `menu_handlers_exec 0x4835F0` | 7 |
| 0x2a | menu principal (variante MP/dédié) | idem | `menu_handlers_lookup 0x482E90` | 4 (sans Join/ChangeID/Exit) |
| 0x1b | **options jeu** | `dlog_page_1b_open 0x489D40` | `LAB_0048A140` | 11, défaut 10 |
| 0x1c | options graphiques | `dlog_page_1c_open 0x48C830` (10536) | LAB_0048CDA0* | 14 |
| 0x23 | résolution vidéo | `dlog_page_23_open 0x48A7D0` (8893) | LAB_0048B7B0* | 32 |
| 0x1d | options son | `dlog_page_1d_open 0x48D4B0` (10946) | `LAB_0048D830` + `menu_state_dispatch_2 0x48D690` (11087) | 7 |
| 0x19 | keymap Mecc | `dlog_page_19_open 0x486FC0` (6793) | LAB_004871B0* | 65 |
| 0x18 | keymap Reaper | `dlog_page_18_open 0x4862E0` (6569) | LAB_004864D0* | 83 |
| 0x1a | keymap Kabuto | `dlog_page_1a_open 0x487B70` (6938) | LAB_00487D60* | 57 |
| 0x14 | sélection mission | `menu_mission_list_init 0x485840` (5925) | LAB_00485C90* | dynamique (≤19) |
| 0x15 | liste niveaux/MP | `dlog_page_15_open 0x4850F0` (5563) | LAB_004855A0* | 10 |
| 0x16 | (in-game, 5 entrées) | dans 0x4845E0* | LAB_00486250* | 5 |
| 0x21 | mission select/saves | `menu_mission_select 0x4845E0` (4949) | LAB_00484CE0* | dynamique |
| 0x1e | confirmation sortie | `dlog_page_1e_open 0x48EA50` (12232) | LAB_0048ED70* | 3, défaut 2 |
| 0x27 | chapitres/script | `dlog_page_27_open 0x48F460` (12859) | LAB_0048F840* | 22 (`story_script_scan`) |
| 0x26/0x28/0x29 | in-game (pause etc.) | 0x488740/0x48E430/0x48DE30 | LAB_* | 3 chacune |
| — | **gameover** | `gameover_menu 0x450D10` (region_0045.c:771) | `LAB_00450DB0` proc / `LAB_00450E60` draw (désassemblés) | 2 (liste 2D) |
| — | **MP conn/score** | `comm_show_conn_menu 0x5233F0` (region_0052.c:3210) | LAB_00525460/LAB_00524D90* | dynamique |

`*` = handler non désassemblé dans ce pass — comportement dérivé du `_open`
et des prompts GText uniquement.

### 3.1 Écran 0x13 — sélection joueur (boot), handler 0x483FD0 (désassemblé)

- Boot : `mission_intro_load` (region_0048.c:4361-4545) pousse le niveau,
  alloue la caméra type **0x401**, énumère le registre (5 clés max,
  `registry_enum_key_create` l.4503) pour présélectionner le profil courant
  (`DAT_00632918+0x2AC[sel]` = polygone), `sound_play(0x6E6)`.
- Entrées 1-5 = noms de profils (clés registre du joueur) ; 6 = nouveau
  joueur ; 0 = slot non utilisé/retour (aucune action observée, OPEN).
- Prompts (désassemblé + GText) : sel<6 non-édition → `MH_SelectID`
  (« Select this ID, or press the Delete key to remove it ») ; sel=6 →
  `MH_NewID` ; page texte ouverte → `MH_CreateNewID`.
- Sélection (flag 0x13 ou Enter) → copie du nom vers `0x6329E0`, teardown,
  `jmp dlog_page_1f_open`. Nouveau joueur → page text-entry
  (`main_dlog_00427970(page, 0, 0.5, 3.0, 0x88000002, &DAT_0063304C, 0x20)`,
  désassemblé ; corps Ghidra dans `savegame_cam_section @ 0x00484340`
  region_0048.c:4724-4810 — **nom LLM trompeur**, c'est le handler
  confirmation) puis si nom non vide : `player_defaults_load_all @
  0x483E50` (region_0048.c:4547-4720) crée le profil (« Player » par défaut,
  clé registre `DefPlayer`, `.\\savegame\\%s`, `SaveIdx`), `CamMode=1`.
- Suppression : `menu_deleted_player @ 0x48F040` (region_0048.c:12637) →
  retour à mission_intro_load.

### 3.2 Menu principal 0x12 — `menu_handlers_exec @ 0x4835F0` (region_0048.c:4036-4354, observed)

Ordre exact des entrées (switch l.4186-4234 + fx l.4186 + actions l.4312-4342) :

| # | fx (LAB_00483990) | prompt GText | action |
|---|---|---|---|
| 0 | MainStart | MH_StartSingle | `mission_load_full(0xB)` |
| 1 | MainJoin | MH_JoinMulti | `mission_load_full(0xC)` |
| 2 | MainHost | MH_HostMulti | `mission_load_full(0xD)` |
| 3 | Options | MH_GameOptions | `mission_load_full(0xE)` → dlog_page_1b |
| 4 | MainLoad | MH_LoadSingle | `mission_load_full(0xF)` |
| 5 | MainChangeID | MH_ChangeID | `defaults_reset_menu @ 0x4574D0` → mission_intro_load |
| 6 | MainExitGame | MH_ExitGame | `dlog_page_1e_open` (confirmer quitter) |

`mission_load_full @ 0x4575D0` (region_0045.c:7711-7836) : 0xB copie le nom du
monde 0 + `mission_texture_audio` ; 0xE → `dlog_page_1b_open` ; 0xF →
`mission_load_world2` ; sinon `GiantsInitNewWorld`. Variante 4 entrées =
`menu_handlers_lookup @ 0x482E90` (3632-3950) : StartSingle/HostMulti/
GameOptions/LoadSingle (mêmes codes 0xB/0xD/0xE/0xF).

### 3.3 Options 0x1b — handler 0x48A140 (désassemblé) + confirmations `dlog_page_close_a @ 0x489F50` (region_0048.c:8702-8891)

Entrées (ordre observé — prompts + switch de confirmation) : 1=Graphics
(`MH_GraphicsOptions`, ou `MH_GraphicsResolutionMenu` si DAT_00633104),
2=Sound (`MH_SoundOptions`), 3=Mecc Keys, 4=Reaper Keys, 5=Kabuto Keys,
6=Movies/Flicks (gated), 7=MissionRestart (gated), 8=Exit (gated),
9=Game/ReturnMain, 10=retour. Confirmations : 1→`dlog_page_1c_open`
(graphiques) ou `dlog_page_23_open` (résolution), 2→`dlog_page_1d_open`,
3→`dlog_page_19_open`, 4→`dlog_page_18_open`, 5→`dlog_page_1a_open`,
6/8→`dlog_page_29_open`, 7→`dlog_page_28_open`, 9→`dlog_page_1e_open`,
10→retour jeu/menu. Les entrées 6-9 sont **sautées** à la navigation selon
`0x4469E0`/`dialog_level_is_base_dup0052aa70`/`comm_00426540` (modes
dédié/MP/en-jeu — conditions exactes OPEN).

### 3.4 Options son 0x1d — `LAB_0048D830` (désassemblé) + `menu_state_dispatch_2`

7 entrées : 1/2 = toggles périphériques audio (vtable `DAT_005dd2d4/2e0`,
états 0xB/0xC = dispo/mute ; sautées si indisponibles), 3 = **volume musique**
(`MH_AudioMusicVol`), 4 = **volume SFX** (`MH_AudioSFXVol`) — ajustés par
gauche/droite (`0x632AA4/5`) : `volume = vtable_get() + pas(0x5512D8)`,
clamp [0..1] (0x48DA74-0x48DAA8, désassemblé) ; 5 = reset
(`menu_audio_setup(0)`, region_0048.c:2788) ; 6 = retour (→
`game_options_load @ 0x4824E0` region_0048.c:2883 qui reconstruit le masque
d'options depuis les `dialog_level_is_base_N`) puis `dlog_page_1b_open`.
Écrans graphiques 0x1c/0x23 : toggles `MH_Graphics*` (GText §5) — handlers
non désassemblés (OPEN, même gabarit attendu).

### 3.5 Keymap — `menu_keymap_screen @ 0x457550` (region_0045.c:7662-7710)

Routeur : si état de base → `menu_mission_launch`, sinon recharge
`keymap_load()` puis `mission_load_full` selon le mode. Les écrans réels sont
0x18/0x19/0x1a (entrées = touches `Inp*` du registre, cf. chaînes
`InpJump`, `InpBurn`, `keydefmapping.sav` 0x555E08, `joyd` 0x555E1C ;
compte 83/65/57 = nb d'actions Reaper/Mecc/Kabuto). Prompts :
`MH_NonMappingMode` (« Press Enter to change this key, or Delete to clear
it »), `MH_MappingMode` (« Hit the key you want mapped to this action »),
`$KB/$MC/$RP_kbd_*` (« Remappable … Keys », « Reset … To Default »,
« Return To Options Menu »), `MH_InvertMouse`. Labels d'actions :
`SetKey*` (Fire, Jump, Zoom…). Handler détaillé OPEN (non désassemblé).

### 3.6 Sélection mission 0x14 — `menu_mission_list_init @ 0x485840` (region_0048.c:5925-6115)

Compte les mondes jouables via `world_get_pointer(i)`/`fx_slot_free_check`
(max 0x12=18 +1), présélectionne le monde courant (comparaison
`DAT_00632ee8`), `mission_mpworld_load @ 0x485B00` si MP. Polygones :
`DAT_00632918+0x2D0[sel]`. Prompt : `MH_MissionLoad` (« Select mission to
play ») / `MH_WorldLoad` / `$WDselect`. Les noms viennent de
`WorldList.bin` (worldlist.md, 31 mondes).

### 3.7 Multi — `comm_show_conn_menu @ 0x5233F0` (region_0052.c:3210-3330)

Écran 2D pur (page dlog, widgets texte type 0 aux positions colonnes :
`CommShowConnHPlayers/Ping/Score/Teams/Count/Deaths/Game`, TextGetPtrQ).
C'est la **liste des joueurs/score en jeu et le panneau de connexion MP** —
les écrans de setup MP sont 0x15/0x21 + `comm_multi.c`. Coordonnées y en
unités fontes (3.6 … 12) — cf. §4.1.

### 3.8 Gameover — `gameover_menu @ 0x450D10` (region_0045.c:771-790, handlers désassemblés)

Seul écran 100 % 2D + fond objectset : `objectset_find_2(0x127)` (3D),
page dlog avec titre `GameOverRestart` (y=0.4) + liste (type 3, y=0.6)
d'items `AGameOverQuit+2`→« GameOverQuit » et « GameOverRestart » (flags
0xA000000 = GText+centré-X). Process 0x450DB0 : ESC pop+free ; Enter →
item 1 ; clic → hover (`main_dlog_00427310`) ; item 0 → exit (0x51E670),
item 1 → restart (0x4EE840). Draw 0x450E60 : caméra + `dlog_widgets_draw`.

## 4. WIDGETS (couche 2D dlog)

Page = liste chaînée de widgets 14 dwords (0x38 o), alloc tag `"dlogentry"`
(main_dlog.c:548). Champs (observed, constructeurs) : `[+0] next, [+4] type,
[+8] id, [+0xC] flags, [+0x10/14] x/y ancrage, [+0x18..0x24] bbox
(x0,y0,x1,y1), [+0x28] scale fonte, [+0x2C] couleur/texte, [+0x34] data`.

- **page** : `main_dlog_00427150` (alloc 3 dwords {head, sel=-1, …}) /
  `main_dlog_00427180` (free récursif, libère les strings possédées).
- **texte statique (type 0)** : `main_dlog_004273B0` (main_dlog.c:223),
  variante couleur `main_dlog_00427490` (322), update runtime
  `main_dlog_00427790/7F0` (421/470). Flags : `0x1` string possédée,
  `0x4` multiligne (\n), `0x8` clignote.
- **bouton/entrée (type 1)** : `main_dlog_00427970` (612) — sert aussi de
  **champ de saisie** quand le niveau est en textentry mode (buffer +
  maxchars, ex. nom joueur). Draw : sélectionné = couleur 0xFFFEFF sinon
  0x808080, curseur `>` jaune (0xFFFF00) clignotant à droite du texte
  (chaînes 0x556004/0x556494, region_0042.c:11040-11060).
- **glyphe/icône (type 2)** : `main_dlog_00427BB0` (733) — centré dans sa
  bbox, `textrender_draw_buffered`.
- **liste (type 3)** : `main_dlog_00427E80` (969) + items
  `main_dlog_00428140` (append, 1161) / `main_dlog_00428080` (insert at,
  1038) / `main_dlog_00428340` (append via GText, 1492) / clear
  `main_dlog_004283F0` (1605). Flag `0x200` = liste dirty.
- **rectangle (type 4)** : `main_dlog_00427D00` (854) ; draw = 4-6 quads
  lignes (cadre de sélection), `dlog_rect_vtable_draw`.
- **draw dispatcher** : `dlog_widgets_draw @ 0x428810` (region_0042.c:10898) —
  2 passes (sélectionnés puis non-sélectionnés), termine par
  `hud_cursor_status_draw`.
- **hover 2D** : `main_dlog_00427310 @ 0x427310` (region_0042.c:9748) —
  x = curseur_x/width, **y = 1 − curseur_y/height** contre la bbox.
- **Ancrage** : `dlog_004276A0` (region_0042.c:9931) — flags
  `0x4000000` droite-X, `0x8000000` centre-X, `0x10000000` haut-Y (ancre
  bas), `0x20000000` centre-Y, `0x4000000`-Y baseline ; `0x1000000` petite
  fonte 0.025 (grande 0.03125), `0x2000000` texte = id GText.
- **Sliders** : pas de widget dédié — volumes = entrées d'écran-monde
  ajustées gauche/droite (§3.4) ; les scrolls graphiques (0x23
  `MH_VResDevScroll/ModeScroll`) suivent le même pattern (inferred).
- **Text entry** : `dialog_level_set_textentry_mode` au push du niveau ; le
  buffer du widget type 1 reçoit les frappes (insertion/suppression gérées
  par le pass input du niveau — détail exact OPEN, non désassemblé).

### 4.1 Système de coordonnées texte (observed, une ambiguïté OPEN)

`dlog_text_draw_wrap(color, 0, scale, x, y, str)` → `textrender_text_draw(…
y' = (scale/fontPxH)*ascent + y …)` (region_0051.c:12736-12752). x ∈ [0,1]
largeur ; y mesuré **depuis le bas**, en « unités fontes » (le pass hover
confirme y bas→haut). Deux échelles coexistent dans les call sites :
~0.4-0.96 (gameover, prompt) et 3.6-12 (MP) — la conversion exacte
ligne↔fraction d'écran reste OPEN (piste : `win95_text_0051B160` +
`0x5dd8c4` = hauteur GDI 24/12 px, FONT_GDI.md).

## 5. ASSETS CONSOMMÉS

- **GText\*.bin** (byte-verified, décodage depuis `TextPtrInit @ 0x507970`
  main_textget.c:63-120) : header 3×u32 `{count, keydataSize, textdataSize}`
  puis count×`{u32 keyOff, u32 textOff}` relatifs aux deux blobs (ids puis
  textes). 1 852 entrées EN. Résolution : `TextGetPtr @ 0x507B00`
  (region_0050.c:9102) via hash (utils_hash, 0x76d buckets) ; id inconnu →
  retourne l'id lui-même. Labels menus : tous les `MH_*`, `$ID*`, `$KB/$MC/
  $RP_kbd_*`, `$WDselect`, `SetKey*`, `GameOverRestart`, `Options`,
  `CommShowConn*` (dump complet §annexe du pass — ex. `MH_StartSingle` =
  « Start a new single player game »). **Les gros titres 3D des panneaux ne
  sont PAS dans GText** : ce sont des textures (w_menus.gzp).
- **w_menus.gzp** : Menus.gti + ~180 tga (§1.4). **w_menus.bin/.abx** :
  jamais ouverts au boot — OPEN.
- **Monde** : `w_intro_island.bin/.abx/.gzp` (boot trace seq 12).
- **Curseur/sélection** : `cursor00.tga`, `i_selected.tga` (w_menus.gzp).
- **Polices** : aucune fonte fichier — rasterisation GDI runtime
  (FONT_GDI.md : LOGFONT face configurable via option `.font`, atlas
  généré, 24 px menus/HUD, 12 px petit).
- **Sons** : ids numériques via `sound_play` (§2) ; banque VO_Sfx\*.gzp.
- **Registre/savegames** : profils joueur (clés énumérées, `DefPlayer`,
  `SaveIdx`, `CamMode`, `Deleted`), `savegame\<profil>\`,
  `keydefmapping.sav`.

## 6. TABLE DE PORTAGE BEVY (menu principal fidèle)

Ordre de construction recommandé ; [OPEN] = inconnu restant.

1. **Resource `MenuStack`** (pile de niveaux, max 10) avec
   `{process: fn, draw: fn, textentry: bool}` — remplace dlog_push/pop ;
   le système d'Update de Bevy exécute process à la place de la sim de jeu
   quand la pile est non vide (équivalent dialog_level_process).
2. **Monde 3D de fond** : charger `intro_island` (pipeline monde existant),
   caméra scriptée par objet « type 0x401/0x402/0x3FB » → en Bevy : un
   `MenuCamera` component + position par écran. Animer (l'objet caméra
   natif s'anime : object_animate_process sur DAT_0059ee98).
3. **Panneaux de menu** : décoder la table exe 0x576ED8 (0x2C écrans ×
   0x24) + tableaux d'entrées + `w_menus.abx`/objectsets pour reconstituer
   panneaux/polygones — ou réimplémenter les panneaux comme UI 3D Bevy
   (quads texturés `Menus.gti` + `st_*.tga`). [OPEN] : format exact du
   struct d'entrée pointé (vtables 0x5795B0/C0) et correspondance
   polygone↔position panneau.
4. **UI 2D overlay** : réimplémenter les 5 widgets dlog (texte, bouton/
   saisie, glyphe, liste, cadre) + flags d'ancrage ; coordonnées x∈[0,1],
   y bas→haut en unités fontes (convertir ; [OPEN] convention double).
5. **GText** : loader Rust du format §5 (déjà décodé) + map id→string.
6. **Input menu** : mapper les flags du bloc action (haut/bas/retour/
   confirmer/clic/gauche-droite) sur les évènements Bevy ; déplacer le
   curseur virtuel et le poser au centre de l'entrée sélectionnée
   (comportement natif clé).
7. **Sélection + fx** : sons 0x657/0x659/0x65A/0x6E6 (extraire de
   VO_Sfx ; [OPEN] : correspondance id→fichier wav exact) ; fx visuel
   par entrée (noms `MainStart`… — [OPEN] : définition des fx eux-mêmes).
8. **Écran 0x13 puis 0x12** : profils joueur (répertoire `savegame/`
   au lieu du registre Windows), texte d'aide GText, 7 entrées avec
   l'ordre/labels du §3.2, confirmation sortie 3 entrées.
9. **Screens suivants** : options 0x1b (+ audio 0x1d avec volumes,
   graphiques 0x1c/0x23, keymaps 0x18-0x1a), mission list 0x14, MP,
   gameover (2D pur).
10. **[OPEN] transverses** : (a) déclencheur exact du premier
    `mission_intro_load` au boot (après la cinématique flk intro_island —
    seuls callers trouvés : defaults_reset_menu 0x457532 (jmp),
    menu_deleted_player ×2 ; piste : fin de flick intro via
    scenerio_process) ; (b) condition d'affichage des entrées 6-9 des
    options ; (c) handlers `LAB_*` non désassemblés (table §3) ;
    (d) rôle runtime de w_menus.bin/.abx ; (e) sémantique fine du
    textentry (édition caractère par caractère).
