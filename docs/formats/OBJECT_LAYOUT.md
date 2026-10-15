# OBJECT layout (PC GOG 1.449) — offset-par-offset, provenance par champ

**C'est le document-référence pour porter le gameplay.** Tout agent qui porte une
fonction du domaine object/ai/status doit partir d'ici au lieu de re-découvrir
chaque offset dans le décomp Ghidra (`*(int*)(param_1+0xNN)`).

Table machine complète : `docs/formats/object_layout_merged.csv` (135 champs ≤ 0x470).
Minages sources : `ps2_symbols/OBJECT_LAYOUT.csv` (PS2, 779 fonctions) et
`docs/formats/object_layout_pc.csv` (corpus 1.449, 18 fonctions noyau) — régénérables
par `scripts/mine_object_layout_pc.py`.

## Méthode et limites (lire avant d'utiliser)

- **Trois sources, trois provenances** :
  - `observed` — validé sur le RUNTIME x32dbg (breakpoints, dumps) ;
  - `derived` — accès présent DES DEUX côtés (PS2 + corpus PC 1.449) ;
  - `inferred` — accès PS2 seul : l'existence du champ est sûre (779 fonctions
    PS2 minées), la sémantique vient des NOMS des accessors PS2, l'offset PC
    n'est pas confirmé.
- **PS2 = GCC/MIPS, PC = MSVC/x86** : l'alignement des structs peut différer
  (padding, doubles). Les offsets 0x00-0x30 risquent le plus de diverger.
- Le mineur PC ne suit que les accès `param_1` directs ; Ghidra réassigne
  `param_1` à des locals dans certains corps (faux négatifs possibles, faux
  positifs rares). Les offsets PS2 > 0x900 (ex. `0x2b2c`) sont quasi certainement
  des accès via un autre pointeur — non repris ici.
- La taille exacte de OBJECT n'est pas bornée par ce doc ; le record acteur FLK
  (0x874 octets) embarque un OBJECT à +0x0C (cf. ci-dessous), ce qui donne une
  borne haute ≈ 0x860 pour OBJECT utilisé par les acteurs.

## Embedding FLK : acteur 0x874 contient OBJECT à +0x0C

`FLK_ActorAdd @ 0x443A90` : record acteur = 0x874 octets ;
`objobj_type_lookup(type, actor+3 dwords)` → **OBJECT commence à acteur+0x0C**.
Dans ce contexte : `acteur+0x00` director ANM_Anim\*, `+0x04` nom (char\*),
`+0x08` enabled. Les offsets ci-dessous sont TOUJOURS relatifs au début de
OBJECT (donc `acteur+0x0C+off`).

## Champs `observed` (runtime, x32dbg)

| offset | champ | preuve runtime |
|---|---|---|
| `+0x04` | type/class id | FLK_FlickRender : `*(obj+4)==0x65 / 0x66` branche les actors flick ; ordre des cases du dispatch objspec |
| `+0x10` | ANM_Anim\* courant | `ObjectSetAnim(obj, *(obj+0x10), 0x34, 1, 0)` sur state 0x3D (cinéma) |
| `+0xD8` | **flags** | bit `0x20` = animé par la flick (posé par FLK avant animate) ; bit `0x40` = gate apply-location (testé puis posé par FLK_FlickRender) ; bit `0x8000` = libéré (main_flick destroy) |
| `+0x1E0` | **state id** | `== 0x3D` → mode acteur-cinématique (force ObjectSetAnim+animate chaque frame) |

## Champs clés `derived` (PS2 ∩ PC, sémantique par accessors)

| offset | sémantique (accessors PS2) | usage gameplay |
|---|---|---|
| `+0x10` | anim courant | animation de toute entité |
| `+0xD8` | flags | cycle de vie / gates |
| `+0xE0` | rayon collision (`collide_localline`, `vu0_ObjectCollision`, `TreeBend`) | COLLISION |
| `+0x100` | état animate (`object_animate_process`) | animation |
| `+0x108..0x114` | **vélocité courante** (x,y,z + w) — `obj_velocity_commit` | intégration mouvement |
| `+0x118..0x124` | **vélocité précédente** — le corps fait le shift `prev ← cur` (0x118←0x108, 0x11c←0x10c, 0x120←0x110, 0x124←0x114) avant update | amort/accélération |
| `+0xD8` bits 14-15 (`& 0xC000`) | gate de `obj_velocity_commit` (early-return) | cycle de vie |
| `+0x130/0x138-0x140` | cluster apply-location / target-center (`object_apply_location`, `TargetCenter`) | positionnement |
| `+0x148/0x150` | waypoint/position (`lift_logic`, `buoy_ambient`, `collgrid_fill_table_moveable`, `rockgen`, 18f sur 0x150) | déplacement/AI |
| `+0x16C` | sélecteur d'anim (`*_select_run_anim` ×5, `TargetSize2`, 18f) | locomotion |
| `+0x180` | **bloc acteur-spec / classe** (47 fonctions : `rpman_setup_firing_parameters`, `evilreaper_init_bow_firing`, `rpboat_fire`, `mecc_init`) | LE champ du gameplay armé |
| `+0x188/0x18C` | états IA A/B (9f/15f : `sf_disarm_followers`, `ripper_switch_to_normal_ai`, `charger_select_run_anim`) | machine à états IA |
| `+0x1A8` | **tête de liste d'ordres** (102 fonctions : `army_insert_alive_order`, `army_release_alive_order`, `formation_find_spline`, `ripper_control`) | le système d'ordres armée |
| `+0x1E8` | thrust (`mecc_get_thrust`, `rpman_get_thrust`) | mouvement |
| `+0x28C` | état mort rpman (23f `rpman_handle_death`) | mort/dégâts |
| `+0x2D8/0xDC/0xE0(data)` | ptrs de données allouées (`object_free_all_allocated_data`) | libération |
| `+0x2F0` | **énergie/vie** (11f `EnergyIncrease`) | santé |
| `+0x464` | shadow render (3f `RenderShadow`) | rendu |

## Champs `inferred` notables (PS2-only — offsets PC à confirmer)

Sélection (table complète dans le CSV) : `+0x08` mass/class-ptr (25f),
`+0x0C` team link (12f), `+0x60/0x64` weapon-ids, `+0x68` items-id,
`+0x184` mission-trigger, `+0x190` formation-spline, `+0x274` camera-data (7f),
`+0x294` LOS evilreaper, `+0x2EC` shrinker (13f), `+0x35C` mecc backpack (9f).

## Structs dérivées → `ps2_symbols/giants_types.h`

Le header `ps2_symbols/giants_types.h` (même commit) formalise OBJECT + les
structs satellites déjà spécifiées (ANM_Anim runtime, ANM_Node inline 0xB0,
ANM_Keys, FLK_Flick, FLK_Actor 0x874, bloc attach HUD 0x310). Champs inconnus =
`_pad` nommés par offset — à remplacer au fil des validations.

## Ré-export annoté du corpus

`scripts/annotate_corpus.py` réécrit `*(int *)(param_1 + 0xNN)` en accès typé
(`obj->field`) pour les fonctions listées, en sortie
`decompiled/gog144_annotated/` (best-effort, opt-in par liste de fonctions —
ne touche jamais au corpus source). Procédure : ajouter la fonction à
`ANNOTATED_FUNCS`, relancer, relire le diff.

## Trous assumés (ne pas deviner)

- Taille exacte de OBJECT et bornes des sous-blocs (0x180 = ptr ou inline ?).
- Sémantique fine de 0x100-0x140 (velocity vs location accumulators) — à trancher
  par oracle tick-par-tick (RUNTIME_TRACES).
- Alignement PS2↔PC pour les champs < 0x30.
