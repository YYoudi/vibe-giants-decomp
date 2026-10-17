# SKN / skinning — sémantique moteur

> Statut : dérivé, validé sur les 782 SKN / 1317 ANM de l'install
> (source giants-modtools `skn.rs`, `skinning.rs`, 2026-10-17).

## Sémantique du skinning (rigide, pas de pondération)

- **Un poids de 1.0 par cluster** : chaque vertex appartient à UN cluster, il n'y a
  PAS de pondération multi-os (skinning rigide).
- Binding : `cluster.handle` → **nom d'os** → **node ANM** (via la table de noms NAM).
- `vbase` d'un objet SKN = cumul des `total_number_vertices` des objets SKN
  précédents (les indices de vertices des clusters sont globaux au fichier).
- Quirk : `cluster.obj == 0` → **resynchroniser la lecture avec +8 octets**
  (décalage observé sur les assets réels ; giants-modtools `skn.rs:28-32`).

## 🐛 Erratum de la référence Python communautaire `skn_anm.py`

1. `find_info` (dichotomie `ANM_KeyFind`, l.545-605) est **buguée** : IndexError sur
   11 clés, paire figée sur 2-3 clés (l'auteur note « not sure about the while loop »).
2. **LIN et QUAT_BEZ ne sont pas implémentées** (`AnmKeyQuatBez` = dataclass vide,
   l.391-394, aucune méthode `interpolate`).
3. `assert PRS` (l.1060) **cassée par les nodes XFORM NONE réels** (présentes dans
   `mc_run`, `ripper`).

→ Conséquence : les digests golden SKN/ANM restent valides (ce sont des conteneurs),
mais l'**évaluation de poses** par skn_anm.py n'est pas fiable. La référence
d'évaluation est désormais giants-modtools `anm_eval.rs` (TCB/BEZ/LIN complets,
quaternions avec négation x/y/z).

## Layouts de référence

- `giants-modtools/crates/giants-format/src/skn.rs` (SKN + NAM + clusters)
- `giants-modtools/crates/giants-format/src/anm.rs` (ANM complet ; types de clés :
  REAL_TCB 36, VEC3_TCB 60, QUAT_TCB 72, BEZ 20/44/56, LIN 8/16/20 — strides)
- Voir `ANM_IMAGE.md` (runtime + erratum quaternion/composition).
