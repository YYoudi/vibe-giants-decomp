# TRUST.md — ce qui est prouvé, inféré, ou dangereux dans ce repo

Créé le 2026-10-16 (architecte). Mettre à jour à chaque correction de
doc. Règle : un nom ou un chiffre sans provenance vérifiée par lecture
du corps est un **piège**, pas une source.

## Ancré (utilisable)

- Symboles PS2 : `ps2_symbols/` (4 754 noms, `lookup.py`). Un nom présent
  là ET dont le corps décompilé correspond est ancré.
- Docs validés par exécution : `MISSION_VM.md` (VM FLK 41 ops),
  `CINEMATIC_PIPELINE.md`, `FRAME_ANATOMY.md`, `RENDERER_GGDX7.md`,
  `INPUT.md`, `docs/formats/*.md`, `tools_spec/bin_formats.py`,
  `tools_spec/flk_decode.py`, `docs/OBJECT_LAYOUT.md` (provenance par
  champ : 4 observés / 27 dérivés PS2+PC / 104 inférés PS2).
- Oracle runtime : `RuntimeLab/` (événementiel seulement ; les
  breakpoints par-frame s'effondrent sous le dédup — ne pas s'y fier
  pour des mesures par frame).

## Inféré (à re-vérifier avant usage)

- ~85 % des noms de fonctions du corpus `decompiled/gog144_modules/` :
  vagues LLM à confiance auto-déclarée. Le claim historique « 100 %
  named » est vrai en couverture, faux en sémantique. **Ne jamais croire
  un nom `_cNN` sans lire le corps.**
- Corpus Ghidra brut : zéro struct appliquée à l'export d'origine,
  accès mémoire en `*(int*)(param+0x…)` / `DAT_…`. Les structs vivent
  dans `giants_types.h` / le projet `ghidra_projects_gog144/` et
  s'appliquent fonction par fonction (voir OBJECT_LAYOUT).
- Docs partiels (open items explicites, les croire sur leurs limites) :
  `SIM_LOOP.md` (tick rate + seed RNG ouverts), `COLLISION.md`, `AI.md`,
  `NETCODE.md`, `AUDIO.md`, `RENDERER.md`.

## Dangereux (pièges connus)

- `ANM_BinderDestroy_3` est en réalité `atoi`. Exemple type : suffixe
  `_3` = 3e homonyme LLM, pas une variante.
- 23 noms dupliqués dans le corpus (un nom ≠ un corps). AUDIT 2026-10-16
  (`decompiled/dup_audit.json`) : 17 vrais doublons de fonctions (2-3 corps
  DISTINCTS par nom — tailles différentes partout, ex. mecc_fire_logic 22 070
  vs 43 293 octets de corps), 6 entrées = artefacts de parsing (Main/Utils/
  _GLOBAL_/main/__get_eh_context/_malloc). Renommage Ghidra à faire
  (un nom = un corps, suffixe à convenir avec l'architecte).
- Anciens en-têtes « Original source » des seaux d'adresses : fictifs.
  Les fichiers sont renommés `region_00XX.c` (bande d'adresses neutre) ;
  tout en-tête survivant qui affirme une source est faux jusqu'à preuve.
- « fps.txt byte-identical » : affirmation périmée, corrigée (voir
  l'historique git) — ne pas la recopier.
- `savegame/` : non décodé. `comm_fields_pc.csv` : supprimé (vide).
- Fichiers contaminés de `GameFiles-VanillaV1/` (ne pas utiliser comme
  ground truth) : liste dans `AGENTS.md`.
- Le token x32dbg (`G:\Tools\x64dbg\release\x32\mcp_config.json`) ne se
  committe jamais (repo public).
