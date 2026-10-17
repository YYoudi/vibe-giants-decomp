# GZP — conteneur d'assets de Giants

> Statut : dérivé (loader du corpus + outils communautaires), croisé avec les octets
> de l'install le 2026-10-17 (source giants-modtools `gzp.rs`, audit indépendant).

## Conteneur

- En-tête : magie `GZP0` + table des matières (TOC) d'entrées `{ nom, u32 offset }`
  (largeur exacte du nom : cf. GiantZiP / référence communautaire).
- Chaque entrée pointe vers un **en-tête local de 16 octets** :
  `{ u32 csize_tot, u32 usize, u32 dosdate, u32 comp }`
  - `comp` : 0/1 = LZSS, **2 = stocké (copie brute)**.
  - le champ historiquement appelé « crc » est un **timestamp DOS**, pas un CRC.
- Les données (compressées ou stockées) suivent cet en-tête local.

## ⚠ Sémantique critique du `csize` de la TOC [2026-10-17]

Le **`csize` listé dans la TOC INCLUT l'en-tête local de 16 octets**. Donc la taille
des données à lire après l'en-tête est `csize - 16`, PAS `csize`. Lire `csize` octets
après `+16` consomme 16 octets de déchet (le début de l'entrée suivante).
Preuve byte : `VO_SfxEnglish.gzp::BAZ_CT47.wav` → TOC `csize=79676, usize=79660`,
en-tête local `{79676, 79660, 695619628, 2}` ; `csize == usize + 16` sur tous les
fichiers stockés testés. Source : giants-modtools `gzp.rs:60-61,166-185`
(`docs/outils-communautaires.md:8-13`).

## 🐛 Bug OUVERT partagé (golden ne prouve pas la vérité ici)

`read_gzp.py:68,90` (référence Python) ET `giants-rs/crates/giants_gzp` portent le
même défaut (lecture de `csize` sans retrancher les 16 octets sur les entrées
stockées). La gate golden passe **parce que les deux implémentations descendent de
la même erreur** — cas d'école : golden ≠ vérité quand les deux côtés partagent un
bug. Tâche moteur à ouvrir : fix `giants_gzp` + `read_gzp.py` + re-valider les 129
archives contre un décompressé indépendant (giants-modtools).
