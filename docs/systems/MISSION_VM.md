# MISSION & FLICK formats — verdict: interpreted or data? (`wm_*.bin`, `flk_*.bin`)

Status: ✅ verdict rendered, both formats structurally spec'd.

**Evidence:** GOG 1.449 named corpus. Key functions: `read_worlds_bin_fn_PS2 @ 0x00490860`
(mission file loader), `scenario_list_load @ 0x00490C50`, `mission_init @ 0x00492910`
(mission command interpreter, 24 KB), `flick_file_load @ 0x00443480`,
`FLK_FlickProcess @ 0x00445A20` (flick bytecode VM, 14.9 KB), `flick_file_load_state @
0x00446650`. All claims **derived** unless marked **observed**.

---

## VERDICT

| Format | Verdict | Architecture for the Rust engine |
|---|---|---|
| `wm_*.bin` (~90 files) | **DATA, not a VM.** One-shot setup command stream: 28 fixed-size opcodes (`0x0B–0x26`), zero control-flow ops, executed **once** at mission start by `mission_init`. Runtime mission logic is native code (`mission_00447fd0` tick + trigger checks) reading the state these commands wrote. | Parse → build mission state structs. No VM to port. |
| `flk_*.bin` (~500 files) | **INTERPRETED BYTECODE.** A per-frame timeline VM: variable-length records (`{u32 op, u32 size, payload}`), cursor persists across frames, drives camera/actors/HUD/audio during cutscenes and in-game flicks. | **Port the VM** (interpreter + opcode semantics) and run original flk files — same strategy as iw4L's GSC / the ER×Halo HKS approach. |

The distinction that matters: the wm stream has **no jump/loop/condition opcodes** (cursor
only ever advances by fixed sizes — verified against every `pbVar12`/`pbVar5` assignment in
`mission_init`), while `FLK_FlickProcess` keeps a persistent program cursor across frames
and re-enters `switch(*cursor)` every tick — that is an interpreter.

---

## 1. `wm_*.bin` — mission setup command stream

### File container (**observed** on `wm_mission1.bin` 23 B, `wm_end.bin` 71 B,
`wm_1a_1_timmy.bin` 9 655 B)

```
u32 version = 4
u8  start   = 1
commands:  { u8 op; fixed payload per op }
u8  terminator = 0x02
```

Loader: `read_worlds_bin_fn_PS2` walks the scenario table (`WS+0x4550`, stride 0x30,
max 27 slots: `{i32 type@+0, i32 param@+4, char name[32]@+8, void* mission_data@+0x2C}`);
for every `type==2` slot it opens `wm_<name>.bin`, allocates `mission_data` = file size,
reads the whole file. `mission_init(name)` later finds the slot (name compare), walks the
command stream once, writing into the mission slot's state block
(`WS + slot_index*0x118 + ...`, offsets `0x2298..0x2324` seen).

### Opcode table (28 ops, `mission_init`) — sizes **derived** from cursor advances

| op | advance | action (derived) |
|----|---------|------------------|
| 0x0B | 0x15 | mission/objective text slot init (20 B payload; seen all-zero in simple missions) |
| 0x0C | — | store → slot+0x2298 |
| 0x0D | — | store → slot+0x22E0; may spawn/destroy a smartie passenger (object_allocate/destroy, `smartie_unlock_from_player`, `smartie_board_player`) |
| 0x0E | — | (seen in `wm_end` between objectives) |
| 0x0F | — | store → slot+0x2310 |
| 0x10 | — | store → slot+0x2318 |
| 0x11 | 5 | store → slot+0x231C (seen `00 00 10 00` payload) |
| 0x12 | — | store → slot+0x229C |
| 0x13 | — | store → slot+0x22A0 |
| 0x14 | — | `crt_sprintf` (builds a derived string) |
| 0x15 | 0x0D | name field (seen `"kstory5_end_1"` — links the mission's flick/cutscene) |
| 0x16 | — | object spawn fallback (error "…" + `object_allocate_type`) |
| 0x17 | — | error path |
| 0x03 | 0x15 | object spawn: `u32 id` + f32×3 world position (seen id=1001, pos ≈ (-49552, 3224, -19.7)) |
| 0x05 | 0x0D | object ref: `u32` + f32 (seen id=583) |
| 0x06 | strz-ish | name record (seen `"story1_je…"`) |
| 0x19–0x21 | 1..9 | state writes / small payloads |
| 0x22 | — | destroy + allocate object pair |
| 0x23 | — | state write |
| 0x24 | 1 | flag → slot+0x2324=1; clears a per-race spec field (Mecc +0x4C / Reaper +0xCEC) |
| 0x25 | 1 | flag → slot+0x2314=1, global `DAT_00632BEC=1` |
| 0x26 | 5 | two u32 → slot+0x2308/+0x230C |

(Advances observed in the interpreter: 1, 2, 4, 5, 7, 9, 0xD, 0x11, 0x15, 0x1D, 0x21.
Per-op size pinning to full field level = open item; the stream is short enough to
diff-decode against `mission_init` case-by-case when needed.)

### Example (**observed**, `wm_end.bin`)

```
04 00 00 00                    version 4
01                             start
11 00 00 00 00 10 00 00 00 00  op 0x11 (slot 0x231C = 0x100000)
0b 00*16                       op 0x0B (empty objective text)
0e 00 00 00 00                 op 0x0E
15 "kstory5_end_1" 00*19       op 0x15 (flick name "kstory5_end_1")
02                             terminator
```

---

## 2. `flk_*.bin` — flick bytecode (timeline VM)

### File container (**observed**, `flk_intro_island_1.bin` 4 132 B; loader
`flick_file_load`)

```
u32 version = 3
u32 total_size                 // == filesize (0x1024) — observed
u32 count_directors            // × 0xC-byte records
u32 count_actors               // × 0x874-byte FLK_Actor structs
u32 count_blocks               // × 0x310-byte records
u8  payload[total_size-0x18]   // the bytecode stream, read wholesale
```

Loader allocates the three tables (`map_chunk_alloc`) and initializes an in-memory flick
context (0x140 bytes: name[128], type, table pointers, defaults 1.0f…).

### The VM (`FLK_FlickProcess @ 0x00445A20`)

Per-frame interpreter over the payload:

```
cursor: switch (u32 op @ cursor):
    ... 31 opcodes 0x0B–0x35 ...
advance: cursor += u32 size @ cursor+4        // size-PREFIXED variable records
```

Opcode families (~~31 ops~~ **41 ops utilisées sur les codes 1..53**, derived from case bodies — supérieur au décompte initial de familles) :

- `0x0B–0x0E`: directors — register/bind named director tracks; duplicate-director
  error; records reference the 0xC-stride table (`bistream_tell` markers).
- `0x19–0x1F`: timeline/actor state — per-actor animation curves into the 0x874-byte
  `FLK_Actor` structs (`FLK_ActorOffsetEval`).
- `0x20–0x25`: actor commands — offsets/positions (payload width selects variant,
  e.g. size==5 → two u32 at +0x820/+0x824), transforms.
- `0x26`: camera param → context+0x4E.
- `0x27`: HUD icon bound to an object (`hud_icon_for_object(flick, id, …)` — 5 payload
  words).
- `0x28+`: flow/state — enable flags, context+0x4F, timed waits (context fields 0x33–0x38
  hold 1.0f defaults = interpolation weights; op at 0.4 of body computes
  `(target-current)/duration` — the timeline pacing).

Time base: the interpreter receives the flick's elapsed time each frame; several ops
compare/store against it (`iVar4`), which is what makes this a paced timeline rather
than a load-time setup.

### Runtime role

`flick_file_load_state @ 0x00446650` re-loads/rebinds flicks on world load; scenario
slots (`type==1`, from op 92/`scenario_list_load`) reference flicks by name; the mission
op `0x15` names a mission's flick (`kstory5_end_1` ↔ `flk_*` family).

---

## 3. Recommendation for the Rust engine

1. **wm_***: write a small deserializer for the 28 commands → fill a `MissionState`
   struct per scenario slot (the 0x118-stride layout is documented in
   `ps2_symbols/OBJECT_LAYOUT` terms). Mission triggers/goals are NATIVE — port the
   trigger checks from `mission_00447fd0` and friends as normal Rust systems.
2. **flk_***: port the interpreter. It is small (one switch, ~41 ops, cursor + time),
   the record format is self-describing (size-prefixed), and the FLK_Actor struct
   (0x874 B) plus the two other tables (0xC, 0x310) are the only state. Running the
   original cutscene bytecode buys the entire cutscene library for free and guarantees
   timing parity.
3. **Validation oracle**: run the original game under x32dbg with a breakpoint on
   `FLK_FlickProcess`, dump `{cursor, op, time}` per frame during one cutscene, and
   replay the same flk file in the Rust VM asserting the same op sequence (P1.1 harness).

## Open items

- Per-op payload field maps for the 41 FLK ops (used) on codes 1..53 (the interpreter is 14.9 KB of
  decompiled C; mechanical but unhurried work — do it on demand, driven by the trace
  harness so each op is confirmed against runtime behavior).
- On-disk record → in-memory table transform in `flick_file_load` (records appear
  re-packed; the cursor format in memory is `{op, size, …}` — confirm whether disk
  records are already in this shape; header `count_directors/actors/blocks` mapping).
- wm op-size table to full field level (28 ops; the streams are tiny).

---

## MISE À JOUR 2026-10-14 — cinématique gamegauge (chapitre 4 Mecc) observée in-engine

`Giants.exe -gamegauge` = **oracle déterministe** : lance sans input la cinématique
d'intro "Mecc Story 4: The Search for Timmy" (chargée explicitement à l'écran de
chargement), la joue in-engine (persos, sons, sous-titres, caméras, anims), compte des
stats graphiques à l'écran et **se ferme seul en écrivant `fps.txt`**.

### Preuve byte-exact (observed)

- Run1 (quasi-sans trace) vs Run3 (lourdement tracé/pausé) : `fps.txt` **BYTE-IDENTICAL**
  (3 580 octets, md5 `aa93dfcbcb5ee9e67de0f5cf40d6ef78`, 231 lignes, header
  `357.28 Giants v1.400`, Min 183 / Max 841, 228 secondes de comptes par seconde).
- **La cinématique tourne sur une timeline de simulation figée** — les pauses debugger ne
  changent RIEN à la sortie. C'est l'oracle de parité du moteur : reproduire ce
  fps.txt + la playlist ci-dessous à l'octet près.
- Artefacts locaux : `RuntimeLab/logs/traces/gamegauge_run{1,3}_fps.txt`,
  `hits_gamegauge_run3_full.json` (md5 dans `session_hashes.txt`).

### Playlist flick déterministe (observed, 28 loads)

`flick_file_load` param_2 séquencé :
`0x0D, 0x10, 0x16, 0x17, 0x19, 0x1B, 0x1D, 0x1E, 0x21, 0x22, 0x24, 0x25, 0x26, 0x27,
0x29, 0x2B, 0x2D, 0x2F, 0x31, 0x33, 0x35, 0x36, 0x37, 0x39, 0x3B, 0x3D, 0x3F, 0x41`

### Fichiers flick de cette cinématique (famille story4, observed on disk)

`flk_story4_Freedom_1..12`, `flk_story4_T_square_1..58` (+variantes a),
`flk_story4_rescue_31` — la cinématique "The Search for Timmy" joue des segments de
cette famille. Mapping id→nom : le nom est résolu via la table scénario `WS+0x210`
(op 93 des world bins) puis `sprintf("flk_%s.bin")`.

### Format disque flk confirmé (derived + observed)

```
u32 version = 3
u32 total                  // == filesize
u32 count_directors        // × 0xC-byte records
u32 count_actors           // × 0x874-byte FLK_Actor
u32 count_blocks           // × 0x310-byte records
u32 (0x117 observé — rôle à confirmer)
payload[total-0x18]        // bytecode, copié VERBATIM en mémoire (malloc(total),
                           //  header 6 dwords copié, reste lu après) — le curseur
                           //  de FLK_FlickProcess démarre à payload+0
```

Records bytecode : `{u32 op, u32 size_dwords, payload...}` avec avancement
`cursor += size` (dwords, à caler exactement — la marche complète des 545 fichiers
validera la règle comme pour les world bins).

### Protocole gamegauge (pour reproduire)

1. cmd élevé : `cd /d G:\Games\Giants && Giants.exe -gamegauge`
   (batch `RuntimeLab/run_gauge.bat` — le pattern launcher/élévation casse le passage
   d'args via certains chemins PowerShell).
2. `AttachProcess` x32dbg élevé dès que le pid apparaît (les BPs du module persistent).
3. BPs événementiels seulement (`ps2_symbols/gauge_evt_bps.txt`) — les BPs par-frame
   s'effondrent sous le dedup du capteur (documenté).
4. Auto-exit → `fps.txt` régénéré → comparer md5 au golden.

### Open items

- Règle d'avancement exacte des records FLK (caler sur les 545 fichiers).
- Payloads détaillés des 31+ opcodes FLK (cases décimales 1..10 incluses — la première
  extraction n'a vu que les cases hex 0x0B..0x35 ; ops 1..10 = director/family).
- Mapping id→fichier nominal (lire la string pointée par param_1 pendant une pause).

---

## MISE À JOUR 2 — 2026-10-14 : décodeur FLK validé 545/545 + table d'opcodes complète

### Règle de marche des records (VALIDÉE — 545/545 fichiers flk marchent exactement)

```
cur   = dword 6 du fichier (buffer + 0x18 bytes — arithmétique pointeurs C)
op    = u32[cur]
adv   = u32[cur+1]      // taille du record EN DWORDS, op et size inclus
next  = cur + adv
fin   : le dernier record retombe exactement sur le STRING POOL
        (noms NUL-terminés des acteurs/directors: "reg", "center", "borjoyzee", ...)
```

Décodeur de référence : **`tools_spec/flk_decode.py`** — `--stats <Bin>` valide
l'arbre complet (545 ok / 0 fail) et sort l'usage par opcode.

### Table des opcodes FLK observée (41 ops utilisées sur 1..53)

Usage = nombre total d'occurrences dans les 545 fichiers. Sémantiques tirées des
corps de cases de `FLK_FlickProcess @ 0x00445A20` (derived) :

| op | usage | sémantique (calls observés dans la case) |
|----|-------|------------------------------------------|
| 1 | 545 | register director (bistream_tell) — 1 par fichier |
| 2 | 3602 | **FLK_ActorAdd**(flick, idx, name...) — ajout d'acteur |
| 3 | 758 | flick_slot_lookup_handle |
| 4 | 577 | animGetIndexByName — bind animation par nom |
| 5 | 545 | hud_icon_timed |
| 6 | 554 | (flag/cursor) |
| 7 | 547 | (flag) |
| 9 | 980 | AddHud(cHud, cHudIcon) |
| 10 | — | AddHud variante |
| 11/12 | 11/22 | (setups) |
| 13 | 22 | **sound_play_obj** — événement son de la cinématique |
| 14 | 622 | (const/flag) |
| 15–21 | ~620 ch | (acteurs: champs/slots — bloc T_square) |
| 22 | 1155 | (acteur slot majeur) |
| 23 | 707 | (acteur) |
| 25 | 1686 | flick_slot_lookup ×2 (le plus fréquent) |
| 31 | 188 | (caméra/position) |
| 32/33 | 46/2 | FLK_ActorOffsetEval (positionnement acteur) |
| 34 | 1575 | main_objspec + map_chunk_alloc (spawn resource) |
| 37 | 1 | ftol ×3 (timing) |
| 38/39 | 100/— | hud_icon_for_object (39) |
| 41 | 622 | (bloc) |
| 42 | 5 | rare |
| 44 | 497 | teammecc_clear_mode |
| 47 | 2 | TextGetPtr (texte) |
| 52/53 | 51/1 | AddHud / vcall |
| 26/27 | — | sound_play / sound_stop |
| 36 | — | sound_stop_obj |
| 43 | — | sound_entry_volume_set |
| 45/46/48/49/50 | — | (rare/non observé dans l'usage) |

### Sortie de flux

Le dernier record retombe **exactement** sur le STRING POOL (noms NUL-terminés
`"reg"`, `"center"`, `"borjoyzee"`, `"yan"`, `"reaper"`...) — le stream est
auto-terminé par son propre avancement, pas par marqueur.

## MISE À JOUR 3 — 2026-10-15 : payloads EXACTES des ops 30-53 (hex 0x1E-0x35)

Lecture complète des cases du dispatch `FLK_FlickProcess` (decomp `region_0044.c`
lignes 6100-6700). Convention : `p[i]` = dword payload i (p[0] = premier dword après
{op, adv}), `adv` inclut l'entête. Les offsets d'acteur = acteur_base + idx*0x874.
Nom des acteurs : base + p[i] quand != 0 (p[i] = offset dans le string pool).
Tous observed (decomp), sauf mention contraire.

### Bloc 0x1E-0x24 (décimal 30-36)

| op | usage | payload | sémantique |
|----|-------|---------|------------|
| 0x1E | 0 | — | appel du hook `DAT_005dd31c()` (slot de callback jeu), avance |
| 0x1F | 188 | f32 p0=cible, f32 p1=durée | **FADE couleur** : flick+0x36=courant, +0x37=cible, +0x38=rate (cible-courant)/durée ; durée 0 → instantané |
| 0x20 | 46 | **variadique** : dernier dword = idx acteur ; adv 5: {p0,p1}→act+0x820/0x824 ; adv 6: +p2→0x828 ; adv 7: +p3→0x834 ; adv 9: {p0..p4}→0x820/0x824/0x828/0x834/0x830/0x82c ; puis `FLK_ActorOffsetEval` | **offset acteur** (clé de position/décalage) |
| 0x21 | 2 | idx acteur p0, val p1 | act+0xd0 = p1 |
| 0x22 | **1575** | p0..p2 (dont idx), p3..p8 params | **OMBRE acteur** : alloue record `"Flick_shadow"` 0x20 octets à act+0x2ec (champ nom={s_Flick_shadow,0,0,p3,p4,+0x1d=0,+0x20,word 0x80,[5]=5,[6]=5}), act+0x7d4=1, params p3..p8 → act+0x848/0x84c/0x854/0x858, +0x850/0x85c=0 |
| 0x23 | 2 | idx p0, f32 p1 | act+0x83c = act+0x844 = p1, act+0x840=0 (état de fade d'ombre) |
| 0x24 | 5 | idx acteur p0, sound_id p1 | `sound_stop_obj(p1, act+0xc)` |

### Bloc 0x25-0x28 (décimal 37-40)

| op | usage | payload | sémantique |
|----|-------|---------|------------|
| 0x25 | 1 | 7 dwords f32 | **lerp couleur HUD/flick** : flick+0x3b = 1.0-p1 ; si p0>0 → byte flick+0x3d=ftol(p?) ; si p?>0 → bytes +0xf5/+0xf6 ; p6=durée → +0x3c=rate, sinon +0x3a=cible |
| 0x26 | 100 | f32 p0 | flick+0x4e = p0 (MÊME champ que le défaut 1000.0 du loader — durée d'attente/fade texte) |
| 0x27 | 208 | id p0, name1 p1, p2, p3, name2 p4 | `hud_icon_for_object(flick, id, base+p1, p2, p3, base+p4)` |
| 0x28 | 1 | name p0 | flick+0x4f = base+p0 |

### Bloc 0x2A-0x35 (décimal 42-53)

| op | usage | payload | sémantique |
|----|-------|---------|------------|
| 0x2A | 5 | idx p0, f32 cible p1, durée p2 | **scale lerp** : trio act+0x860 {courant, cible, rate=(cible-courant)/durée} ; durée 0 → courant=cible, rate=0 |
| 0x2B | 0 | p0, p1 | `sound_entry_volume_set(p0, p1)` |
| 0x2C | **497** | name p0 | `teammecc_clear_mode(base+p0, world+0x50e0, 0)` — reset mode IA team |
| 0x2D | 1 | — | flick+0x30 = 1 (flag) |
| 0x2E | 7 | — | flick+0x31 = 1 (flag) |
| 0x2F | 2 | name p0 | `DAT_0059ce38 = TextGetPtr(base+p0)` — **message/caption global** (le message HUD hors sous-titre), reset des globals 0059ce3c/40/44/48 et flick+0x3f |
| 0x30 | 0 | — | toggle `DAT_0059ce40` |
| 0x31 | 1 | — | toggle `DAT_0059ce3c`, clear 0059ce40 |
| 0x32 | 2 | f32 p0 | `DAT_0059ce4c = p0` (défaut loader : 0x3d23d70a = **0.04**) |
| 0x33 | 1 | f32 p0 | `DAT_0059ce50 = p0` (défaut loader : 0x40a00000 = **5.0**) |
| 0x34 | 51 | p0 (+conditions) | icône HUD : si flick+0x2d actif → `AddHud(*(flick+0x2d+0xc), flick+0x2c)` ; sinon (fallback LAB_00446389) `vcall_5dd34c_get(base+p0, world+0x50e0, 0)` + `DAT_0059cdb0=1` + 0059cdb4 = -flick+0x2c |
| 0x35 | 1 | — | toggle `DAT_0059ce44` |

### ⚠ op 41 décimal (0x29) — comportement observé atypique

**Aucune case dans le switch décompilé** → default = avance (skip). Usage ≈ 1/file
(622 au total), position INTERCALÉE au milieu du flux (ex. T_square_2 : record 32,
entre op 23 et op 22, adv=5). Hypothèses : marker de scène consommé implicitement,
ou op traitée dans une couche non couverte par le switch (à trancher par trace
runtime si la parité l'exige — BP conditionnel sur *puVar12==0x29 dans le dispatch).
**Ne pas en faire une op d'action dans le portage : le jeu original la saute.**

### Rappel structure d'exécution (utile au portage)

- Le flux est exécuté **lazily par frame** : les ops temporelles (0x19-0x1c, 5, 52)
  comparent le temps flick et laissent le curseur sur place (état "hold",
  `flick+0x2a` = done-for-frame) ; les ops instantanées s'enchaînent.
- Les ops TEXTE (0x0E-0x18) sont consommées par `FLK_FlickTextProcess` depuis le
  **même curseur** (flick+0xfc), appelé une fois par frame dans la passe rendu.
- Les floats payload sont stockés tels quels (f32 little-endian) ; les noms
  d'acteurs/fichiers = offsets dans le string pool relatif à `flick+0x21*4`
  (iVar4 = base noms — voir flick_file_load).

## MISE À JOUR 4 — 2026-10-15 : record ACTEUR FLK (0x874) et binding SKN/ANM (M6)

Source : `FLK_ActorAdd @ 0x00443A90` (decomp). C'est le pont entre les noms du
string pool et les assets : les acteurs de flick sont des objets skinnés
(GBS+SKN+ANM) créés depuis un **director** (table des directors du header FLK,
records de 0xC octets, `flick[0x27]+idx*0xC`).

### Record acteur (stride 0x874, base `flick[0x28]`)

| offset | contenu (observed) |
|--------|--------------------|
| +0x000 | ptr director/template (le record 0xC du header FLK) |
| +0x004 | ptr nom (string pool — le nom affiché/référencé par les ops) |
| +0x008 | flag enabled (op 0x0B=1 / 0x0C=0) |
| +0x00C | **OBJECT embarqué** (`objobj_type_lookup(type, act+0xC)`) — position, source son 3D (op 0x0D → act+0xC), physique |
| +0x014 | type id (param_5 de l'op ; -1 → type 0 + scale défaut 1.0 à +0x134=0x3f800000... champ [0x34]) |
| +0x0A8 | matrice GEO (identité au spawn) |
| +0x0C4 | **bloc template copié du director : 0x119 dwords (0x464 octets)** — contient notamment : |
| +0x1C4..+0x1EC | **10 slots de ptrs-noms (SKN/ANM par LOD)** : chaque slot non-nul → `*slot+0x6c` = nom → `editor_anim_skin(director, name, nom, 0)` → résultat stocké dans la struct ANIMATE |
| +0x21C | flag "déjà initialisé" (évite la double création) |
| +0x2EC | ptr record ombre `"Flick_shadow"` (op 0x22) |
| +0x7D4 | flag ombre active |
| +0x820-0x834 | clés d'offset (op 0x20) → `FLK_ActorOffsetEval` |
| +0x83C-0x844 | état de fade d'ombre (op 0x23) |
| +0x848-0x85C | paramètres d'ombre (op 0x22 : p3..p8) |
| +0x860 | trio scale lerp {courant, cible, rate} (op 0x2A) |

### Struct ANIMATE (`main_animate_004050d0(director)` → act+0xC6)

- `+0x2C..+0x50` : **10 slots de skins résolus** (résultats `editor_anim_skin`,
  un par entrée non-nulle du bloc template +0x1C4..0x1EC).
- `+0x54` : vertex buffer de skinning (`map_chunk_alloc(animate[0x1D8] << 2)` —
  0x1D8 = nombre de verts × 4 octets).
- Rendu : `animate_core_caller @ 0x0042E460` (RENDERER_GGDX7 MAJ 3 — LOD 9
  slots par distance + token-stream u16).

### Chaîne de création d'un acteur (pour le portage M6)

1. **Op 1 (545×, ~1/file) = DECLARE DIRECTOR** : payload {idx_director,
   nom} — `bistream_tell_user(0,0, base+nom)` résout le nom dans le **monde
   .bin chargé** (le director = une définition d'objet du monde !) et range le
   template dans la table des directors (`flick[0x27]+idx*0xC` : {ptr, ?, used}
   — doublon → erreur `"Error: Duplicate director already..."`).
2. **Op 2 (3602×) = ADD ACTOR** : payload {idx_director p0, nom p1,
   idx_slot_acteur p2, type p3} → `FLK_ActorAdd(flick, p0, base+p1, p2, p3)` :
   lit le template du director, crée le record 0x874, copie le bloc template
   (les 10 noms de skins/ANM par LOD), résout les skins, alloue le VB de
   skinning, `ObjectSetAnim(act+0xC, 0, 0x20, 1, 0, 0)` (anim par défaut),
   matrice identité.
2. Par frame : `FLK_FlickProcess` avance le curseur (ops position/ombre/son/
   scale...), le dt flick à `flick+0xAC` anime les acteurs, la caméra vient du
   node (CINEMATIC_PIPELINE §4), puis `FLK_FlickRender` soumet.
3. Fin de flick : `main_flick_00443740` charge le flick suivant de la chaîne
   (la playlist §7 de CINEMATIC_PIPELINE).

**Pour le portage Rust** : votre `giants_skn_anm` (en cours) se branche ICI —
le nom du slot template + le nom d'acteur = la clé de lookup dans les SKN/ANM
des gzp ; le résultat = mesh GBS skinné par le token-stream documenté.

## MISE À JOUR 5 — 2026-10-15 : le modèle d'exécution par frame + caméra = piste ANM (op 4)

Lecture des cases 1-10 du dispatch (`region_0044.c` 5797-6110). Complète la
MAJ 4 ; tout observed (decomp).

### Le modèle d'exécution (l'algorithme exact du portage)

```
par frame (FLK_FlickProcess(flick), dt dans flick+0xAC, temps écoulé à
l'octet flick+0xB0 — dword index [0x2C], attention à la notation) :
    curseur = flick+0x22 (persiste entre les frames)
    boucle :
        op = *curseur
        si op temporelle (8/9/10) et condition non atteinte :
            flick+0x22 = curseur          // SAUVEGARDE (hold)
            hud_icon_timed(...)           // tick des icônes HUD
            return flick+0x2a             // frame terminée, résume ici la prochaine fois
        exécuter l'op (tables MAJ 3/4)
        curseur += adv
        si op terminale (5 / fin de stream) : flick+0x22 = curseur ; return état
```

- **Op 8 = WAIT** : {f32 t} — tant que `temps_flick < t`, hold. C'est le
  mécanisme de synchronisation de toute la timeline.
- **Ops 9/10** : variantes avec condition sur un acteur (hold si
  `idx_acteur < p` etc. — mêmes labels caseD_5).
- Le dt `flick+0xAC` (commun acteurs+texte, cf. §8) avance le temps
  l'horloge (octet flick+0xB0, dword [0x2C]) comparée par les WAIT —
  avancée par `hud_icon_timed(flick, dt_global)` appelée au caseD_5 de
  chaque frame (voir MAJ 6).

### Ops 1-10 — payloads exactes (complément MAJ 4)

| op | usage | payload | sémantique |
|----|-------|---------|------------|
| 1 | 545 | {idx_director, nom} | **DECLARE DIRECTOR** : `bistream_tell_user(0,0,base+nom)` résout le nom dans le monde .bin → table directors `flick[0x27]+idx*0xC` = {ptr, ?, used} ; doublon = erreur |
| 2 | 3602 | {idx_director, nom, idx_slot, type} | **ADD ACTOR** → FLK_ActorAdd (MAJ 4) |
| 3 | 758 | {p0..p4, 2 noms} | `flick_slot_lookup_handle(flick, p0, base+p1, p2, base+p3...)` — binding de scenario-slot |
| 4 | 577 | {idx_director, nom1, nom2} | **BIND CAMÉRA** : `animGetIndexByName(template_director, base+nom1, base+nom2)` → si 0 : erreur `"Flick error : Can't find camera ..."` ; sinon flick+0x2d = `anm_id_mask(idx)`, flick+0x2e = record director. **LA CAMÉRA EST UNE PISTE ANM** d'un node de l'objet director — c'est cette piste que lit `flick_node_mat_get` (CINEMATIC_PIPELINE §4) |
| 6 | 554 | — | clear flags flick+0x30/+0x2f |
| 7 | 547 | {f32 cible, f32 durée} | fade canal A : flick+0x33=courant, +0x34=cible, +0x35=rate (même motif que 0x1F canal B sur +0x36/37/38) |
| 8 | — | {f32 t} | **WAIT until** temps ≥ t |
| 9/10 | 980 | {idx/conditions} | WAIT avec condition acteur (labels caseD_5 partagés) |

### Conséquence directe pour le portage (correction §4 CINEMATIC_PIPELINE)

Le rendu de caméra ne lit PAS la matrice d'un acteur lambda : il lit la piste
ANM sélectionnée par **op 4** sur l'objet director (`flick+0x2d` = mask de
l'anim, `flick+0x2e` = director). Dans le portage : `camera_anm =
anim_lookup(director_object, cam_node_name, cam_track_name)` puis sample la
track par le temps flick — exactement le même sampler que les acteurs ANM.

## MISE À JOUR 6 — 2026-10-15 : l'HORLOGE flick — `hud_icon_timed @ 0x004457D0` (réponse Q8)

La pièce manquante du timing, lue intégralement (decomp `region_0044.c`
5549-5660) :

**Appel** : une fois par frame, depuis le caseD_5 de `FLK_FlickProcess`
(la sortie de passe d'ops) : `hud_icon_timed(flick, uVar7)` où
**uVar7 = DAT_006328E0** — le dt GLOBAL du jeu (la même source que
`FRateGetSecsframe` ; en gamegauge il vaut 1/60 forcé).

```c
if (flick+0xB4 == 0) return 1;              // pas d'objet horloge-HUD → rien
if (flick+0xA8 != 0) { time = 0; dt = 0; }  // reset au (re)démarrage
// [modulation optionnelle du dt par un timer global si DAT_0059cdb0]
time(+0xB0) += dt;
flick+0xAC = dt;                            // ← le dt stocké lu par texte/acteurs
count = AddHud(hud+0xC, time);              // ← l'horloge HUD alimentée CHAQUE FRAME
flick+0xA8 (done) = (count >= *(hud+0x14)); // FINI = horloge HUD PLEINE
if (message && flag && done && ...) {       // boucle d'attirance (vue run5) :
    time = ANM_SecsFromTicks(hud, count) - 1.0;  // repart ~1 s avant la fin
    dt = 0; done = 0;
}
```

**Conséquences pour le portage** :
1. L'horloge vit à l'**octet +0xB0** (dword index [0x2C] — l'erreur de notation
   "+0x2C" des MAJ 5 est corrigée) et avance du **dt global**, pas d'un dt
   propre au flick ; +0xAC = copie du dt du frame pour texte/acteurs.
2. **La fin d'un flick = l'horloge HUD pleine** (`count >= hud+0x14`) — les ops
   9/10 (hold par icônes) et la fin de flick partagent le MÊME compteur
   d'icônes : toute la timeline est pilotée par ce seul cadran. La capacité
   `hud+0x14` est runtime — c'est le knob de calibration de l'oracle (n°13).
3. Le "wrap" observé au run5 (retour 0x42 → 0x0D) se boucle localement ICI
   (time = fin − 1 s) tant que le message global est actif — et le slot "end"
   (§10) coupe la boucle au niveau monde.

### Complément MAJ 4 (2026-10-15) — FLK_ActorOffsetEval + ObjectSetAnim

**`FLK_ActorOffsetEval @ 0x00443FB0`** (op 0x20) = `math_euler_to_matrix`
inlinée sur les champs acteur : angles euler à **+0x82C (a), +0x830 (b —
niégé, même convention), +0x834 (c)**, translation +0x820/+0x824/+0x828 →
écrit la matrice 3×3 à **+0x7E0..+0x808** (colonnes translation à
+0x7EC/+0x7FC/+0x80C), flags +0x7D8=1 (valide), +0x7DC=0x11 (tag).
C'est le repère d'offset local de l'acteur (3e confirmation de la convention
euler b-négatif du moteur).

**`ObjectSetAnim @ 0x004034A0`** (appelé par FLK_ActorAdd avec
`(act+0xC, 0, 0x20, 1, 0, 0)`) : pose (anim_idx, frame, ..., time_scale) ;
time_scale=0 → **l'horloge d'anim propre de l'objet est GELÉE**. Lecture
architecturale : les acteurs de flick ont leur mesh/squelette fourni par le
binding SKN/ANM (les 10 slots LOD), mais **leur mouvement vient des ops FLK**
(clés d'offset 0x20, positions), pas d'une ANM auto-jouée — l'anim propre
sert de pose de base. Point ouvert mineur : la lecture exacte de la paire
(anim_idx=0, frame=0x20) — tester les deux lectures contre le rendu golden.

## MISE À JOUR 7 — 2026-10-15 : le chemin ACTEUR → TRIANGLES À L'ÉCRAN (FLK_FlickRender intégral)

Le dernier maillon manquant du rendu : comment l'acteur de la struct FLK
devient un mesh skinné soumis à la passe (decomp `FLK_FlickRender @ 0x004444C0`
intégral, observed). Chaîne par frame, après le Process :

**A. Setup de frame** :
- `render_get_fov/aspect`, `XFGetViewport_2`, `view_matrix_get`,
  `render_get_clip_nearfar` (la view/caméra du flick node, cf. §4) ;
- **swizzle dt** : `DAT_006328E0 (dt global) ← flick+0xAC (dt flick)` le temps
  des appels de rendu — les acteurs animés en cinématique avancent au dt du
  FLICK ; restauré en sortie.
- **Caméra** : `flick_node_mat_get(hud_obj, view_node?, flick+0xB8+4)` →
  `GEO_MatTranspose` → `view_matrix_reset`.

**B. Anim + update des acteurs** (boucle sur flick+0xA0/+0x94, stride
0x21d dwords — la table OBJECT des acteurs du flick) :
- flag +0x20 posé sur obj+0xF0 si world_done ;
- `object_animate_process(obj, dt_flick)` par acteur actif
  (`obj[-0xd] != 0` ou world_done) ;
- puis boucle sur la liste OBJECTS globale (DAT_00632D68) :
  `FLK_ObjectInFlick(obj)` → si dans le flick : flag 0x40 clear →
  `object_apply_location` + `objspec_dispatch_gate` ; types spéciaux 0x3D /
  0x65 / 0x66 re-animent.

**C. HUD/nodes du flick** : boucle sur flick+0x98 (count) × 0xC4 dwords —
`wredit_matrix_recurse` + `ANM_NodeGetMat` + multiplication = les matrices
des icônes HUD posées par les ops 0x27/0x34.

**D. Boucle de SOUMISSION des acteurs** (celle qui dessine) — par acteur
actif de la table flick+0xA0 :
1. `wredit_matrix_recurse(actor_obj)` — compose la matrice monde de l'objet
   (GEO + offset op 0x20 + parent) ;
2. `AddHud_4(hud+0xC, time)` puis `ANM_NodeGetMat` × = **le node ANM du
   director compose dans la matrice** (pose du squelette/l'attache) ;
3. **Basis du billboard** : transforme (0,1,0,0) par la matrice caméra →
   right/forward/up normalisés écrits à obj+0x1E0..0x1EB, + translation à
   obj+0x1E3..0x1EF (matrice 4×4 complète reconstruite, tag 0x11 à +0x1DF) ;
4. **Historique de positions** : rotation des slots obj+0x26/0x29/0x2C
   (positions des 3 dernières frames) ;
5. **Sélection du LOD** : `piVar9[0xB6]` = config ; si son byte +0x1E < 0
   (skinné haut-res disponible) ET `DAT_006331C0 != 0` (option) → haut-res ;
6. **RENDU par viewports tiles** (le secret du rendu multi-fenêtre des flicks) :
   - `upcall+0x8C` (1re fois) puis `upcall+0xC0(hud_tex, &dims)` : récupère
     les dims d'une texture → tile = `1 << (bit du dim)` (potences de 2) ;
   - `XFSetViewportRegion(0,0,w,h)` + `upcall+0xA0(...)` : découpe le
     framebuffer en tile ;
   - `render_projection_reset(proj, proj+0xC)` + `render_scene_begin` ;
   - **`animate_core_caller(actor, 0, 0, actor+0x28C, camera_origin)`** — LE
     call qui soumet le mesh skinné (LOD 9 slots + token-stream, cf.
     RENDERER_GGDX7 MAJ 3) dans la tile ;
   - `render_scene_end` ; upcall+0xB8 si tile était la 1re.

**Pour le portage** : un acteur de cinématique = OBJECT (objet du monde)
+ matrice composée {GEO ∘ offset(0x20) ∘ node ANM director} + scale op 0x2A
(+0x860), anim propre GELÉE (n°16), soumis via `animate_core_caller` dans
des tiles de viewport. Le billboard basis (D-3) sert aux sprites/quads attachés.

## MISE À JOUR 8 — 2026-10-15 : FOV/aspect caméra + MYSTÈRE DES BLOCS 0x310 RÉSOLU (points d'attache HUD/fx)

**1. Camera FOV/aspect (`render_get_fov/aspect @ 0x515D90/0x515DA0`)** :
lectures directes des globals +0xB8/+0xBC de la struct render (0x57C0B8/BC).
Écrites par le setup de projection :
- fov en **degrés** (conversion ×0.008726646 = π/360) → sin/cos stockés
  (_DAT_005DCF4C et suivants = la matrice projection) ;
- aspect = param, ou si 0 : `DAT_005DCF0C / DAT_005DCF10` (résolution écran) ;
- le ratio est aussi recalculé au viewport change : `aspect = (2/(right-left)) / (2/(top-bottom))`.
Pour la parité : fov de la cinématique = celui posé par le setup monde/caméra
du node camera01 (à dumper runtime si parité pixel exacte voulue).

**2. LES BLOCS 0x310 = POINTS D'ATTACHE HUD/FX** (`hud_icon_for_object @ 0x00443D60`,
op 0x27) — le mystère ouvert depuis la MAJ 3 est résolu :

Signature op 0x27 : `(flick, id=block_idx, name1, p, slot_idx, name2)` →
`hud_icon_for_object(flick, id, base+name1, p, slot_idx, base+name2)` :
- **block_idx × 0x310 + flick+0xA4** = un objet-attach (struct 0x310) — il y en
  a `count_blocks` par flick ;
- **slot_idx × 0x874 + flick+0xA0** = l'acteur PORTEUR ;
- `animGetIndexByName(director_obj, actor_name, name2)` : name2 = un **nom de
  node/anim de l'acteur** (erreur "Can't find fx actor" sinon). Les strings du
  pool de T_square_2 (`ref_lhand01`, `ref_staff`, `ref_rhand`, `ref_handle`)
  sont ces noms de nodes d'attache (main gauche, arme…) ;
- remplit le bloc : +0x308 = anim idx, +0x304 = acteur porteur, +0x30C = param,
  type 0, scale +0xC4 = 1.0 ;
- **matrice d'attache** : `wredit_matrix_recurse(acteur)` puis composition avec
  `ANM_NodeGetMat(anim, time, node)` = position du bloc SUIT le node du
  squelette animé de l'acteur (ex. l'arme dans la main qui bouge) ;
- `object_set_location(block, +0x2A4, +0x2B4, +0x2C4)`.

Layout struct 0x310 (partiel observed) : +0xC4 scale, +0x294 matrice 3×4,
+0x2A4/B4/C4 position, +0x304 acteur, +0x308 anim idx, +0x30C param.

**Ça ferme l'open item "rôle des blocs 0x310"** (CINEMATIC_PIPELINE §10/Q9) :
ce sont les ancres d'icônes/effets attachés à des nodes d'acteurs. En story4
(count=0 pour T_square_2) les ops 0x27 visent des blocs d'AUTRES flk (les
flk de gameplay utilisent ces attaches pour les marqueurs d'objets).
