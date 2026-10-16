# NIGHT_REPORT — worker RE (GiantsRE), session du 2026-10-16

Worker GLM spécialiste RE. Toutes les affirmations ci-dessous portent leur
provenance dans le commit cité (observed/derived/inferred par affirmation).

## Tâches faites (DONE, commit)

| Tâche | Commit | Preuve / gate |
|---|---|---|
| **Q13 répondue** (lieur xx section 3 débloqué) | b679020 | preuve exécutable `tools_spec/xx_section3_tag_proof.py` (asserts verts sur mecclev1) : offsets relatifs au buffer APRÈS le tag u32 de section (0x4D0D) ; le walk +8 du moteur ≡ +4 du décomp ; « head2 » = type_id dword0 ; « nm_block_off » = bruit de cadrage (fin de string / terminator) |
| **TASK-017** structs OBJECT dans Ghidra (10 témoins) | 0d3a95b | struct sémantique (33 champs) + 10 fonctions typées OBJECT\* dans GOG144.gpr + exports `decompiled/gog144_annotated/ghidra/` — DoD auto-PASS (zéro offset brut pour champs couverts). Découvertes : 0x00-0x30 = bloc constantes physiques réinitialisables ; homonymes stop_movement légitimes |
| **P3 COLLISION** (mur gameplay) | 2489167 | `collgrid_collide_walk` LU EN ENTIER : c'est le rasteriseur d'empreintes (== PS2 `collgrid_fill_table_moveable`, même signature) — **échelle cellule = 5.0 u (facteur 0.2)**, blobs compressés types 1-5 décodés (RLE, double plan, bitmap b0=occupé/b1=exclusion, bits packés) ; l'ancien claim « walk resolver » retiré ; collide_resolve = test point/empreinte |
| **P4 SIM_LOOP** (RNG + tick) | d042863 | `srand` ABSENT des imports PE → RNG = LCG MSVC per-thread jamais reseedé (déterminisme total) ; `time_frame_update` décodé : dt EMA temps réel (nominal 0.025 s, clamp 0.25 s), modes cmdline 1/40 fixe et ×10/×0.1, **DAT_00633248 = force 1/60 (gamegauge)** |
| **P5/TASK-016** harnais stabilité | 77a6555 + 7905af4 | `scripts/harness_stability.py` ; 3 runs gamegauge : exits propres à 239.1-239.2 s (reproductible 0.1 s), fps.txt réécrit (3596 B) mais NON byte-identique — quantifie la dépendance charge. G:\Games\Giants non modifié |
| **P6/TASK-013** (partiel : audit) | 77a6555 | `decompiled/dup_audit.json` : 17 vrais noms dupliqués (tous corps DISTINCTS — ex. mecc_fire_logic 22 Ko vs 43 Ko), 6 artefacts de parsing ; TRUST.md à jour |
| **Repli SAVEGAME** (non décodé → amorcé) | 3567661 | `docs/formats/SAVEGAME.md` : mission.sav = **dump brut 0x23084 o de la zone 0x633380** (un seul file_write_locked, `savegame_verify @0x491F10`), version gate 0x11, chemins savegame/\<player\|SaveGame%d\>/ ; carte empirique (compteurs +0x00/08/0C/10, bloc timestamps epoch-2001 +0x1104) |

## Non fait / restant

- **TASK-013 fin** : renommage Ghidra des 17 dupliqués + ré-export (suffixe à
  convenir avec l'architecte — audit prêt).
- **Q12** (dump ospec runtime) : laissée conformément à la consigne (UAC humain
  requis). Le protocole est prêt : BP `read_objects_bin_PS2 @ 0x4AE4C0`, à la
  sortie lire la liste `[0x632D50]` ({next; count; ospecs[n] inline 0x464}).
- COLLISION suite : consommateurs de la table d'occupation (sweep glissement
  — candidats `collgrid_query_obj`, `collide_localline_objtris_mips` PS2),
  carte complète des flags cellule, validation runtime de l'échelle 5 u.
- SAVEGAME : minage des accès `DAT_00633380+k` (pattern OBJECT) + diff des
  échantillons pour la carte complète.

## État des repos en fin de session

- GiantsRE poussé jusqu'à `7905af4` (origine main à jour).
- giants-rs : seuls TASKS.md (statuts TASK-016/017) et QUESTIONS_FOR_DECOMP.md
  (réponse Q13) modifiés par ce worker — aucun cargo lancé, aucune gate touchée.
- x32dbg : fermé proprement (session Q12 interrompue sans dump, cible libérée).
