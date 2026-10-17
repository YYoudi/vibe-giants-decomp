# GBS — mesh statique

> Statut : dérivé, validé sur les 1561 GBS de l'install (source giants-modtools
> `gbs.rs`, port fidèle de l'importateur Blender communautaire, 2026-10-17).

## Layout (little-endian)

1. `u32` magie/version : `0xAA0100BE`
2. `u32` options :
   - bit 0 (0x0001) : table de normales présente
   - bit 1 (0x0002) : UVs présentes
   - bit 2 (0x0004) : RGB par sommet rendu présents
   - bit 3 (0x0008) : normales à calculer au chargement
   - bit 31 : matériau max-lit
3. `u32` nb sommets + triplets `f32 ×3` (positions)
4. Si bit 0 : table optionnelle de mots-normales `u16` (précédée de 2×`u32`)
5. `u32` nverts + indices `u16` par sommet rendu (+ indices normales `u16` si bit 0)
6. Si bit 1 : UVs `f32×2` par sommet rendu (**v inversée** à la lecture, cf. loader)
7. Si bit 2 : RGB `u8×3` par sommet rendu
8. Table MaxObj (5×`u32`) — assert de la référence : **la somme des `vcount` MaxObj
   doit égaler le nombre de sommets** (sinon le fichier est rejeté)
9. `u32` nb sous-objets + enregistrements : `nom[32]`, triangle-runs, matériau

## Runs de triangles (`decode_triangles`)

Par sous-objet, le flux est une suite de runs : `u8 run` puis `run × 3` indices `u16`
(un triangle par triplet), jusqu'à épuisement. Référence d'implémentation :
giants-modtools `gbs.rs:200-215` (et `giants-rs/crates/giants_gbs/decode_triangles`).
