# FRAME_ANATOMY — anatomie complète d'une frame de la cinématique gamegauge

> Objectif : pour CHAQUE élément visible de la frame cible (capture run réel :
> 3 Meccs skinnés en gros plan, un Smartie au premier plan, terrain rocheux +
> végétation, mer et ciel à l'horizon, sous-titre jaune, letterbox), donner
> le système engine qui le produit, les calls exacts, et l'état de la spec.
> L'agent Rust doit pouvoir partir de zéro et reconstruire la frame couche par
> couche. Référence image : capture T_square_2 (~frame 30), GOG 1.449.

## 0. Le pipeline d'une frame (vue d'ensemble, ordre observed)

```
game_loop_run (dt global forcé 1/60 en gamegauge)
└─ FLK_FlickProcess        — VM : consomme les ops de la frame (MISSION_VM.md)
└─ FLK_FlickRender         — pose caméra, anime les acteurs, soumet les draws
   ├─ render_get_fov/aspect + view_matrix_get + clip near/far
   ├─ FLICK NODE CAMERA    → GEO_MatTranspose → view_matrix_reset
   ├─ dt swizzle           → DAT_006328E0 ← flick+0xAC (MAJ 7)
   ├─ object_animate_process par acteur actif
   ├─ FLK_ObjectInFlick → object_apply_location + objspec_dispatch_gate
   ├─ HUD nodes (flick+0x98 × 0xC4) : wredit_matrix_recurse + ANM_NodeGetMat
   ├─ object_list_update + fx_process + object_lock_apply + sound_checked_big
   └─ BOUCLE DE SOUMISSION par acteur (MAJ 7) :
      wredit_matrix_recurse ∘ ANM_NodeGetMat → billboard basis →
      LOD select → TILE VIEWPORT → render_scene_begin →
      animate_core_caller → render_scene_end
└─ passes MONDE (terrain/mer/ciel/props, cf. RENDERER_GGDX7 MAJ 2/3)
└─ HUD + texte (FNT) + fade couleur
└─ flip / présentation
```

## 1. FOND NOIR + LETTERBOX

- **Fond** : `Clear` (vtable +0x90, observé) en noir avant les passes.
- **Letterbox** (bandes haut/bas du format cinéma) : *derived, trivial* — le
  viewport de rendu est posé en ratio 16:9 sur un backbuffer noir
  (`XFSetViewportRegion`, déjà documenté pour les tiles MAJ 7) ; le jeu natif
  4:3 étire, les captures widescreen montrent les bars. Aucun système dédié
  trouvé dans les strings (pas de "letterbox"). À reproduire : clear noir +
  viewport réduit.

## 2. CIEL (bande sombre en haut de l'image)

- Composant **sky/outsky de world.gb2** (layout complet :
  docs/formats/world_gb2.md ; rendu : `dlog_scene_submit` FVF 0x24, texture
  WS+0x4C (op 30), diffuse blanc forcé, + passe fog 0x60720) —
  RENDERER_GGDX7 MAJ 2.
- **État : clos.**

## 3. TERRAIN ROCHEUX + VÉGÉTATION

- Mesh **GTI** (`Story4.gti` chargé, 958 records confirmés) : grid heights,
  tuile 40, rendu palette-par-hauteur (`u = height*(0.5/hScale)+lodBias+0.5`,
  v=0) — formule exacte RENDERER_GGDX7 MAJ 2.
- **Vertex colors GTI** (le dégradé roche/herbe de l'image) : portés par les
  RGB du GTI (validés golden par l'agent, 32 terrains md5-identiques).
- **Textures** : `Story4.gti` + 5 textures du `w_Story4.gzp` (vus dans la
  trace fileopen ; chargement TGA : main_texture.c porté chez l'agent M2).
- **Props/végétation** (palmiers…) : GBS statiques via placements .abx
  (`w_Story4.abx`) + object-sets — euler épinglé (math_euler_to_matrix,
  docs/formats/abx.md).
- **État : clos** côté spec (l'agent a déjà le terrain M2 qui rend).

## 4. MER À L'HORIZON

- Composant **sea de world.gb2**, texture WS+0x6C : grille 33×13 caméra-
  centrée miroir horizon ×12500, `uv = pos/WS+0x7C` — RENDERER_GGDX7 MAJ 2.
- **État : clos.**

## 5. ACTEURS SKINNÉS ANIMÉS (les 3 Meccs + Smartie — le cœur de l'image)

Chaîne complète, chaque maillon a sa spec :
1. **Déclaration** : op 1 (director = objet du monde .bin) + op 2 (add actor) →
   record 0x874 (MAJ 4) : bloc template 0x119 dwords avec 10 slots noms
   SKN/ANM par LOD, résolus par `editor_anim_skin` → struct ANIMATE
   (+0x2C skins, +0x54 vertex buffer).
2. **Géométrie par frame** : matrice = `wredit_matrix_recurse` (GEO ∘ offset
   op 0x20 via FLK_ActorOffsetEval) ∘ `ANM_NodeGetMat` (pose director) ;
   scale lerp op 0x2A (+0x860) ; horloge d'anim propre gelée (n°16) — le
   mouvement vient des OPS (positions, offsets), pas d'une ANM auto-jouée.
3. **Éclairage** : *derived, à confirmer par capture* — le shading
   directionnel visible sur les Meccs vient des **RGB vertex pré-éclairés des
   GBS** (les GBS portent vertices/normales/RGB documentés) + matériaux
   D3DCOLOR (M2 agent) ; `SetLight`(+0xB0)/`SetMaterial`(+0xA8) existent dans
   la vtable mais AUCUN call SetLight n'est nécessaire pour les passes
   cinématique observées (pas de lumières dynamiques dans les story4).
   Contrôle : si le rendu Rust éclaire différemment, dumper la light au
   runtime (BP vtable +0xB0).
4. **Soumission** : `animate_core_caller @ 0x0042E460` — LOD 9 slots par
   distance + token-stream u16 (0=fin, bit15=strip, bit14=fan, sinon
   tri-list) ; FVF 0x20060 ; TILE VIEWPORTS par acteur (MAJ 7).
5. **Ombres** (les blobs sombres sous les Meccs) : op 0x22 (1575 usages) →
   record `"Flick_shadow"` attaché à l'acteur (+0x2EC), fade op 0x23 —
   le mesh d'ombre est un objet du monde plaqué au sol (rendu standard
   alpha-blend). Params op 0x22 : p3..p8 → +0x848-0x85C (offset/size).
- **État : clos côté spec** ; l'implémentation SKN/ANM chez l'agent est le
  chemin restant (sa M1/M6 en cours).

## 6. ICÔNES / POINTS D'ATTACHE

- Op 0x27 → blocs 0x310 = ancres HUD/fx sur nodes d'acteurs
  (`hud_icon_for_object @ 0x443D60` — MISSION_VM.md MAJ 8) ; les
  `ref_lhand01/ref_staff/ref_rhand` des pools = noms de nodes.
- En story4 T_square_2 : count_blocks=0 → **absentes de cette frame** ; utilisées
  par les flk de gameplay (marqueurs).
- **État : clos** (spec MAJ 8).

## 7. FX ATMOSPHÉRIQUES (poussière, brume)

- Packs `xx_efx.bin`/`xx_effects.bin` chargés (trace §12) ; système fx
  (fx_process appelé par frame dans FLK_FlickRender) — formats et fades
  couverts par docs/formats bin_objects (fx fades : strings "fx vfade",
  "Failed to setup verticle fade..." = commandes fx du monde).
- **État : partiel** — la mécanique fx_process (types d'effets, particules)
  n'est PAS documentée en détail ; volume visuel faible dans la cinématique
  (dust). À décomposer seulement si parité pixel exigée sur la brume.

## 8. SOUS-TITRES (le texte jaune "Right, what the f*** is a Kabuto???")

Chaîne complète :
1. Op 16 (text-set) : `TextGetPtr("Flk_story4_T_square_2_1")` →
   `'Oy, pub! Top!'`… (65 noms vérifiés dans GTextEnglish.bin).
2. Op 17-20/23 : rect/couleur posés dans la struct flick (+0x10C..0x128).
3. Op 21 : fonte (FNT_RenderInfo flick+0x104/0x108) ; op 22 : fade
   (rate = 1/durée, +0x11C) ; op 14 : reset chrono.
4. Layout : `flick_text_layout @ 0x00446CE0` (mesure largeur, centrage,
   saut de ligne) — le sous-titre est CENTRÉ en bas (le rect des ops).
5. Rendu : texte jaune = couleur posée par les params ; glyphes =
   **rasterisation GDI runtime** (FONT_GDI.md : atlas 256×128 u16,
   métriques 5 octets/char, baseline 32).
- **État : clos** côté spec (y compris la vraie valeur du texte).

## 9. FADES DE COULEUR GLOBALE (l'ambiance crépuscule)

- Ops 0x1F (canal B) et 0x25 (7 dwords) : lerp couleur cible/durée →
  flick+0x36..0x3D / +0x3A..0x3C — appliqués comme fade plein-écran
  (modulation) en fin de passe (wredit_text_fade / les passes HUD).
- **État : clos** (sémantique observée ; l'application exacte au framebuffer
  = modulation finale documentée dans les passes HUD RENDERER_GGDX7).

## 10. PRÉSENTATION

- Fin de frame : flip du device (le dll GFX_DX8 en D3D8 ; présentation
  standard). Letterbox = viewport (§1).

## RÉCAP GAPS RESTANTS pour la parité visuelle de CETTE frame

| Couche | État spec | Gap |
|---|---|---|
| Letterbox | derived trivial | aucun |
| Ciel/mer/terrain/props | clos | aucun |
| Acteurs skinnés | clos (MAJ 4+7) | implémentation SKN/ANM chez l'agent |
| Éclairage acteurs | derived (vertex pre-lit) | dump SetLight runtime SI divergence |
| Ombres | partiel (record + params) | mesh d'ombre exact (texture blob) si parité pixel |
| FX brume | partiel | fx_process détaillé si exigé |
| Sous-titres | clos (MAJ 8 + FONT_GDI) | rasterizer exact = winapi ou TTF équivalent |
| Fades couleur | clos | application finale (modulation) à confirmer visuellement |
