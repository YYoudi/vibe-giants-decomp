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

Opcode families (31 ops, **derived** from case bodies):

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
2. **flk_***: port the interpreter. It is small (one switch, ~31 ops, cursor + time),
   the record format is self-describing (size-prefixed), and the FLK_Actor struct
   (0x874 B) plus the two other tables (0xC, 0x310) are the only state. Running the
   original cutscene bytecode buys the entire cutscene library for free and guarantees
   timing parity.
3. **Validation oracle**: run the original game under x32dbg with a breakpoint on
   `FLK_FlickProcess`, dump `{cursor, op, time}` per frame during one cutscene, and
   replay the same flk file in the Rust VM asserting the same op sequence (P1.1 harness).

## Open items

- Per-op payload field maps for the 31 FLK ops (the interpreter is 14.9 KB of
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
