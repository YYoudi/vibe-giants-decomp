# GBS — mesh statique

> Statut : dérivé, validé sur les 1561 GBS de l'install (source giants-modtools
> `gbs.rs`, port fidèle de l'importateur Blender communautaire, 2026-10-17).
> **Rendu** : vérité moteur établie par l'agent éclairage (décompile gg_dx7r +
> RENDERER_GGDX7.md, 2026-10-17).

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

## Matériaux par sous-objet (après les runs)

```
texname[32]       (si UVs flaguées — nom de texture, NUL-terminé)
bumptexture[32]   (si UVs flaguées — bump map, souvent vide)
falloff: f32
blend: f32        (si RGBs flaguées)
flags: u32
emissive: u32     (mot COLORREF 0x00BBGGRR)
ambient: u32      (mot COLORREF)
diffuse: u32      (mot COLORREF)
specular: u32     (mot COLORREF)
power: f32        (exposant spéculaire 3ds Max)
```

### Ordre des octets COLORREF

Chaque mot couleur est **`0x00BBGGRR`** (Windows COLORREF) : byte0=R, byte1=G,
byte2=B (les outils communautaires utilisent `GetRValue/GetGValue/GetBValue`).

### Flags sous-objet (outils : `GbsImporter.cpp` l.184, 229-246)

| Flag | Sémantique |
|------|-----------|
| `0x10` | **Additif** (TRANSP_ADDITIVE) — la texture se superpose en addition |
| `0x20` | **Soustractif** (TRANSP_SUBTRACTIVE) |
| `blend > 0.5` + `0x10/0x20` | MixMat (facteur de blend) |
| `0x80000000` | GBSFlagMaxLit (« max lit » — heuristique 3ds Max) |
| bit 0 (hypothèse forte) | Chemin SetMaterial (« lit ») — voir Rendu ci-dessous |

## Rendu (vérité moteur — décompile gg_dx7r / RENDERER_GGDX7.md)

### Le moteur n'éclaire PAS les modèles GBS

La formule du jeu est simplement :

```
final.rgb = texture.rgb × vertexRGB.rgb
```

**AUCUNE lumière** n'est appliquée aux modèles GBS :
- `D3DRS_LIGHTING = 0` (chemin « pré-éclairé »)
- `D3DRS_COLORVERTEX = 1`, `D3DRS_DIFFUSEMATERIALSOURCE = 1` (COLOR1)
- **Aucun `SetLight`** dans le renderer (367 fonctions analysées)
- **`D3DRS_AMBIENT` jamais posé** → globalAmbient = 0

Toute la « chaleur » visuelle du jeu vient des **vertex colors pré-cuites**
(flag 0x4 du GBS) — c'est L'ÉCLAIRAGE. Sans le flag, blanc `0xFFFFFF`.

Le **soleil** (couleur `(1.0, 1.0, 0.5)`) n'éclaire que le ciel, le fog et
l'eau — jamais les modèles.

### Chemin SetMaterial (rare, flag bit0)

Si le flag bit0 du sous-objet est actif, un `D3DMATERIAL8` est construit depuis
les mots GBS (÷255) et posé — mais **sans lumière**, le résultat reste
`texture × emissive`. Les mots diffuse/ambient/specular ne produisent rien
(sauf spéculaire si `SPECULARENABLE` + une lumière existait — ce qui n'arrive pas).

### UV wrapping (tiling)

Le moteur DX7 utilise **`D3DTADDRESS_WRAP`** : les UV des bâtiments vont
au-delà de [0,1] pour tiler les textures sur les grandes surfaces.
Exemples mesurés :
- `guard_tower1.gbs` : U [0..2], V [-3..1] — **34% des sommets hors [0,1]**
- `guard_shop.gbs` : U [-1.37..2.37], V [-1.25..2.37] — 12% hors [0,1]

Un viewer moderne doit utiliser un sampler **Repeat** (`address_mode = Repeat`)
sur les axes U et V, sinon les pixels du bord s'étirent en lignes.

### Alpha (textures d'effets EFX)

- 32bpp avec canal alpha : la forme du halo vit dans l'alpha (le RGB est
  noir — en rendu additif, le noir n'ajoute rien)
- 24bpp sans alpha : color-key noir en jeu (le noir pur = transparent)
- Flags sous-objet : `0x10` = additif, `0x20` = soustractif (cf. tableau)

### Résumé pour un viewer moderne

| Élément GBS | Mapping |
|-------------|---------|
| texture (`texname`) | `base_color_texture` + sampler **Repeat** |
| vertex RGB (flag 0x4) | `ATTRIBUTE_COLOR` — C'EST l'éclairage |
| — (pas de lumière) | **`unlit: true`** — clé de la parité |
| flags 0x10 | `AlphaMode::Add` (si la texture a un alpha) |
| flags 0x20 | blend soustractif |
| UV v-inversée (stockage) | dé-inverser pour wgpu (origine haut-gauche) |

Sources : `GiantsRE/RuntimeLab/ggdx7_decomp/ggdx7_decompiled.c` (FUN_10001e60,
l.340-472), `RENDERER_GGDX7.md`, `GiantsTools/Plugins/imp_gbs/GbsData.cpp` l.111-121,
mesures giants-modtools (2026-10-17).
