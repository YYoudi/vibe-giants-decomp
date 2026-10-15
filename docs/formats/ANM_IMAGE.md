# ANM image sérialisée (director inline FLK et fichiers .ANM)

**Provenance** : `observed` (dump runtime x32dbg BP `nam_entry_ctor @ 0x53D700`, run `-gamegauge`
2026-10-15, dumps `RuntimeLab/nam_entry_boot.bin` + `anm_image_head.bin` + `mapfix_boot.bin`)
croisé `derived` avec le décomp 1.449 et le fichier `Bin/flk_story4_T_square_2.bin`.

## Principe

Le director ANM (et tout ANM du jeu : `MU_Mselect`, flicks, animateurs d'objets) n'est **pas parsé
champ par champ** : c'est une **image mémoire sérialisée**. Les structs sont stockées avec le layout
runtime exact ; les pointeurs sont des u32 = **offsets relatifs à la base de l'image**, relogés au
chargement par `ptr += base` :

- `bistream_tell_user @ 0x53BA50` : charge le bloc (fichier via stream ou image inline du FLK),
  puis `map_group_fix` (relocation globale via la fix-table de l'image), puis `nam_lookup_variant`.
- `nam_lookup_variant @ 0x53D810` : énumère les entrées de la table de noms NAM (handle @ ANM+0x20)
  et appelle `nam_entry_ctor` sur chacune.
- `nam_entry_ctor @ 0x53D700` : remet +0x00 à zéro, fixe les pointeurs (+0x0C/+0x10/+0x14, tracks
  via `ANM_KeysFixPtrs @ 0x53D6B0` selon le track-type), **niégé l'euler +0x78/7C/80** si
  `MAP_Fix+4 != 0` (MAP_Fix = {base, flags} — observé {0x102E8D0, 1}).
- `MAP_PtrFix @ 0x5400E0` : `*ptr = base + *ptr` (mode flag) — la sémantique exacte des offsets.

Chaîne FLK : `FLK_FlickProcess @ 0x445A20` (op acteur) → `bistream_tell_user(0,0,<image inline>)`
→ `FLK_ActorAdd @ 0x443A90(f, animIdx, anm_assemblé, slot, type)`.

## Entry / node (taille variable, ≥ 0xB0)

Validé par double ancrage : dump runtime (avant ctor) et bytes du fichier identiques aux mêmes
offsets. Ancrage fichier T_square_2 : origine 0x3D820, 16 entries consécutives à pitch 0xB0
(pattern queue `[-0.0×3]@+0x78 [1.0×4]@+0x84..0x90 [0x10]@+0x94`, 24 occurrences).

```
+0x00  d0     garbage (mis à 0 par le ctor)
+0x04  d1.lo  u16 class (1 → trio blend tracks à +0xF8/FC/100 existe)
+0x06  d1.hi  u16 track-type : 0=aucune ; 1=+0x9C seul ; 2/3=+0x98,+0x9C,+0xA0
+0x08  d2     u32 name handle {u16,u16} (0 = sans nom) — résolu via la table NAM
+0x0C  d3     ptr (fixé ctor) — souvent un groupe/parent partagé (0x46B88 pour ~200 nodes T_square_2)
+0x10  d4     ptr (fixé ctor) — parent (suivi par ANM_NodeGetAffine)
+0x14  d5     ptr (fixé ctor)
+0x18  d6     callback fn-ptr (out, affine, node, anim)
+0x24..+0x64    matrice cache (runtime)
+0x68          float -0.0 sentinel
+0x6C..+0x74   pos (3f)
+0x78..+0x80   rot euler (3f) — niées au chargement par nam_entry_ctor (flag MAP_Fix+4)
+0x84..+0x8C   scale (3f)
+0x90          float 1.0
+0x94  d37     u32 0x10 constant (ni ptr ni nié — porter tel quel)
+0x98..+0xA0   3 × ANM_Keys* (image-offsets dans le fichier)
+0xA4          ANM_Keys* additionnel (relogé par la fix-table) ; count observé à +0xA8
+0xF8..+0x100  3 × ANM_Keys* blend (seulement si class@+4 == 1)
```

`ANM_Keys = { ptr@+0, ?@+4, u32 count@+8, ptr keys[count]@+0xC }` — chaque élément de keys[] est
lui-même un pointeur relogé.

⚠️ **Ne pas parser par pitch fixe** : la taille d'une entry est variable (le trio blend déborde
0xB0). Énumérer via la table NAM ci-dessous.

## Table de noms NAM inline (à la base de l'image)

Observé au dump boot (ANM « MU_Mselect », base 0x102E8D0) : header de table à la base, puis dès
+0x20 des triplets `{u32 handle, u32 ptr(→entry, image-offset), asciiz name}` :

```
0x00040014 → base+0x3D0 "MU_Mselect"        (l'entry exacte que nam_entry_ctor traitait)
0x00040014 → base+0x2C0 "Ref_camera1"
0x0004001C → base+0x210 "Ref_camera1.Target"
```

Le lookup par nom (`nam_lookup_by_handle @ 0x53CEC0`, messages « Can't find tree %s in ANM %s » /
« Error binding: The SKN %s ref ») passe par `NAM_NameFindByHandle(table@ANM+0x20, handle)` ; le
nom de l'ANM lui-même est à ANM+0x4C. **Op 4 FLK « camera01 »** = chercher l'entrée NAM "camera01"
dans l'image director → ptr → entry → tracks selon track-type.

## Références croisées

- `docs/systems/MISSION_VM.md` (MAJ 5 : op 4 caméra ; MAJ 8 : FLK_ActorOffsetEval euler inlinée).
- `docs/systems/CINEMATIC_PIPELINE.md` §13/§16 (sampler node, crt_stream_seek).
- Struct ANM_Anim runtime (22 dwords, agent giants-rs) : FileVersion@+0=0xB, Start@+4, End@+8,
  TPF@+0xC, FPS@+0x10, NumNodes@+0x14 — le diviseur op 9 est `*(anim+0x18)` (7e dword, non TPF).
