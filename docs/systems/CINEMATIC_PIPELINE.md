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
- Format (observed, byte-exact entre runs) :
  `"<avg> Giants v1.400"` / `"<n> Min"` / `"<n> Max"` / `"<n> Second <i>"` × 228.
- Run1 vs Run3 : **byte-identiques** (3 580 octets, md5 `aa93dfcbcb5ee9e67de0f5cf40d6ef78`)
  malgré des charges de tracing radicalement différentes → preuve du fixed-step 1/60.
- Les chutes de fps par seconde (183 à s8, ~215 s16-20) = frontières de scènes du
  cut-scene (segments flick).

## 6. Checklist de portage Rust (résumé opérationnel)

1. Parse `-gamegauge` → flag → dt forcé 1/60, menus bypassés.
2. Charger le monde par le chemin standard (formats déjà spec'd : world bin, GTI, GBS,
   textures GZP) + les flicks `flk_story4_*` (décodeur `tools_spec/flk_decode.py`).
3. VM flick : 41 opcodes (table dans MISSION_VM.md), records `{op,adv,payload}`,
   fixed-step 60 Hz en gamegauge.
4. Rendu : caméra depuis node flick → view matrix ; acteurs CPU-skinnés
   (`anm_skin_verts_apply`) ; terrain GTI ; texte FNT ; HUD icons.
5. Oracle : `fps.txt` byte-identique + playlist flick (28 ids) + captures.

## Open items

- Mapping id flick → nom de fichier (lire la string `param_1` lors d'une pause —
  1 run gamegauge instrumenté suffira).
- Payloads fins des ops 30-53 (les corps de cases sont dans le corpus, à transcrire
  au fur et à mesure des besoins du portage).
