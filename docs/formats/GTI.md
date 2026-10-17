# GTI — terrain heightfield (version 3)

Statut : ✅ décodage complet du flux de cellules (corrigé le 2026-10-16 —
voir « Correction » ci-dessous).

Sources : `decompiled/system_layer/gti_terrain_load_0x00476D40.c` (loader
exe), `RESSOURCES_FOR_AI/GiantsEdit/GiantsEdit.Core/Formats/GtiFormat.cs`
(lecteur/écrivain C#, lignée Delphi `bin_w_read.pas`),
`scripts/gti_parse.py` (parseur de validation), viewer
`giants-modtools/crates/giants-format/src/gti.rs` (port Rust).

## Conteneur

```
u32 magic        0x94965001 / 0x94965002 / 0x94965003 (version dans l'octet bas)
[v>=2] u32 chunk_count + chunk_count × 0x34 (0 vu dans le jeu)
11 mots :
  [0] f32 minX     (XOffset)      — le loader fait ensuite minX -= Stretch
  [1] f32 minZ     (YOffset)      — idem minZ -= Stretch (origine bordure)
  [2] f32 minHeight               (GiantsEdit ; non utilisé par le loader)
  [3] f32 maxHeight
  [4] u32 tilesX   (Width)
  [5] u32 tilesZ   (Height)
  [6] f32 Stretch  = taille monde d'une tuile ; le loader calcule
                     +0x1c8 = DAT_005522c0 / Stretch (réciproque, UV ;
                     valeur de la constante non résolue : l'adresse
                     .rdata 0x5522C0 tombe sur de l'ASCII dans la build GOG)
  [7] f32 0.5  [8] f32 0.5  [9] u32 color1  [10] u32 color2
u8 flags (bit1 = lightmap RGB par cellule, bit2 = octet extra),
u8 mat_lo, u8 mat_hi, u8 pad, u32 pad, f32 1.0, char[16] nom,
u32 zero, u32 zero, ... (queue ~0x20B lue par le loader)
```

## Flux de cellules — RLE PLAT parcourant la grille

Le flux **parcourt** la grille `(tilesX+2) × (tilesZ+2)` via l'arithmétique de
wrap (lignes 1..=tilesZ, wrap à tilesX+1), mais seule une **fraction des cellules
est littérale** dans le fichier : les bordures/inactives sont couvertes par des
skip runs (cf. GiantsEdit `Save` : masque linéaire actif/inactif sur `w*h`, runs
littéraux ≤ 128 cellules). [Reformulé 2026-10-17 — sur KStory2.gti (195×196) :
23 012 cellules couvertes (15 667 littérales + 7 345 skippées) sur 39 006 ;
le flux se termine à z=tilesZ+1, consommant 172 929/172 935 octets — source
giants-modtools, vérifié aux bytes.] OPEN : champ nom 16 vs 32 octets —
indécidable sur l'install (tous les noms ≤ 11 chars, octets restants nuls dans
les deux lectures ; les parseurs consomment 32 o dans tous les cas).

Décodage (état `x=1, z=1`) :

```
tant que z < tilesZ+1 :                    # lignes intérieures 1..=tilesZ
    i8 run
    run < 0 :  x += |run| ; tant que x >= tilesX+1 : x += 2 - (tilesX+2) ; z += 1
    run >= 0 : (run+1) fois {
        f32 height ; u8 triangles ;
        [flags&2] u8[3] lightmap ; [flags&4] u8 extra
        grille[z][x] = cellule            # x ∈ 1..=tilesX, z ∈ 1..=tilesZ
        x += 1 ; si x >= tilesX+1 : x = 1 ; z += 1   # wrap INTRA-run
    }
```

Cellule runtime (16 octets, alloc `(tilesX+2)*(tilesZ+2)*0x10`) :
`f32 height @0` (défaut −4096.0), lightmap RGB @+4, **triangles @+0xC**
(bits 0-2 = orientation de la diagonale du quad, switch cases 1-7 du
loader — GiantsEdit l'appelle `Triangles`), +0xE/+0xF drapeaux dérivés
(calcul de visibilité en fin de chargement).

## Correction (2026-10-16)

`gti_parse.py` (et le port Rust d'`giants-modtools`) wrappait les
colonnes à `x >= tilesX-1` et stoppait les lignes à `z < tilesZ-1`, alors
que l'exe wrappe à **`tilesX+1`** et boucle sur **`z < tilesZ+1`** :
cisaillement diagonal de 2 colonnes + 2 lignes perdues — les terrains
rendus étaient déformés. L'erreur venait d'une mauvaise lecture des
seuils `(+0x1dc)-1` / `(+0x1e0)-1` (les deux champs valant déjà
tiles+2 à cet endroit du loader).

Preuves : GiantsEdit (RLE plat, masque sur toute la grille) ; consumed
KStory2.gti passe de 171843 à **172931/172935** (tout le flux de cellules
est consommé) ; rendu viewer d'île cohérent ; Python et Rust corrigés
donnent des sorties identiques.
