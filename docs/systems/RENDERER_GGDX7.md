# RENDERER_GGDX7 — gg_dx7r.dll (GOG 1.449) : décomp du plugin de rendu

Status: ✅ DLL décompilée (367 fns, corpus `RuntimeLab/ggdx7_decomp/`, projet Ghidra
`ghidra_projects_ggdx7/`). Ce doc répond à Q6 de giants-rs avec les items livrés et
les pointeurs précis pour le reste. Provenance : **derived** (decomp DLL + engine).

## Identité (surprise utile)

- Le `gg_dx7r.dll` GOG 1.449 **importe `d3d8.dll`** et s'appelle en interne
  **`GFX_DX8.dll`** (nom d'export PE) : l'interface a été conservée, l'API migrée
  D3D7→**D3D8**. → Pour un portage wgpu, la référence sémantique est donc le pipeline
  D3D8 fixed-function (TSS 8 stages, FVF, state blocks).
- Imports : KERNEL32, USER32, GDI32, **d3d8**, WINMM. Exports : `GDVSysCreate`,
  `UpCallsLoad` (+ entry).
- `GDVSysCreate @ 0x100026F0` : crée un objet renderer de **0x2A5A4 octets**
  (constructeur `FUN_1000D290`, vtable C++ `0x1001A228` = 14 méthodes), puis
  `Direct3DCreate8(0x78)` (D3D_SDK_VERSION), device init `FUN_1000D590`.
- Constantes posées par le constructeur dans la vtable-adjacente : `-1.0f`,
  `0.1f(0x3FB99999)`, `-1e10(0xD2F1A9FC)`, **`0x3F50624D` (≈0.001831)** — mapping
  de profondeur (bornes near/far log-depth du clip).

## Le contrat ABI (engine ↔ renderer)

Deux directions :

1. **engine → renderer** : objets `gfx_sys` / `gfx_state` / `gfx_primbuffer`
   (noms vus dans les allocations du DLL via l'upcall alloc) — stockés engine-side
   dans `DAT_00656420/0065643C/0065644C`. Appels observés dans le corpus engine :
   `+0x10/+0x20/+0x24/+0x28` (primbuffer : soumission de primitives/token streams),
   `+0x30` (end/flush), `+0x78/+0x98/+0xA8` (gfx_sys : setup/frame events).
2. **renderer → engine** : `UpCallsLoad(ctx, n, ptrs[21])` copie **21 pointeurs**
   dans `DAT_1002470C..DAT_1002475C`. Noms (derived des call sites) :

| idx | DAT | nom (usage) |
|---|---|---|
| 2 | 10024714 | `error_show(msg)` — affiche l'erreur générique + MessageBox |
| 3 | 10024718 | `debug_log(str)` — 13 usages ("Error locking vertex buffer…") |
| 4 | 1002471C | `d3d_error(hr)` — échecs EndScene/GetDepthStencil/TestCoop |
| 0xB | 10024738 | `text_get(id)` → char* (TextGetPtr ; ex. "RestoreTextures") |
| 0x12 | 10024754 | `mem_alloc(tag, size, name)` — tags "gfx_sys/state/primbuffer" |
| 0x13 | 10024758 | `mem_free/list_unlink(ptr)` |
| autres | — | non appelés dans ce build (slots réservés) |

## Pipeline texture stages (item 4 de Q6) — TSS presets décodés

`SetTextureStageState(dev, stage, state, value)` = vtable D3D8 **+0xFC** (16 appels).
Sémantique D3D8 TSS : 1=COLOROP 2=COLORARG1 3=COLORARG2 4=ALPHAOP 5=ALPHAARG1
6=ALPHAARG2 0xB=TEXCOORDINDEX 0xE=MAGFILTER 0x10=MIPFILTER 0x11=MIPMAPLODBIAS
0x12=MAXMIPLEVEL 0x13=MAXANISOTROPY 0x15=MINFILTER. Args : 0=DIFFUSE 1=CURRENT
2=TEXTURE ; ops : 1=DISABLE 2=SELECTARG1 3=SELECTARG2 4=MODULATE 5=MODULATE2X.

Preset **opaque simple** (fonction d'init) :
```
stage0: COLOROP=MODULATE, ARG1=TEXTURE, ARG2=DIFFUSE,
        ALPHAOP=MODULATE, AARG1=TEXTURE, AARG2=DIFFUSE,
        TEXCOORDINDEX=0, MIPFILTER=1(point), MAXMIPLEVEL=0, slot24=0
stage1: COLOROP=DISABLE, ALPHAOP=DISABLE
```
Preset **multi-texture 3 stages** (terrain/mer) :
```
stage2: MAGFILTER=3(linear), TEXCOORDINDEX=0,
        COLOROP=5(MODULATE2X), ARG1=TEXTURE, ARG2=CURRENT
(stage0/1 reprennent le preset simple)
```
Per-texture dynamique (texture manager) : `MAXMIPLEVEL=0`,
`MAXANISOTROPY=cfg(+0x9B4)`, `MINFILTER=cfg` ; et pour les 4 stages :
`MIPMAPLODBIAS=v`, `MIPFILTER=v` (defaults texture manager).

## Draw path (device D3D8 = renderer+0x850)

- `SetVertexShader(FVF)` = vtable **+0x130** — **le FVF vient de l'ENGINE**
  (`*(param_1+0xD0)` du côté renderer ; l'engine passe son FVF via gfx_primbuffer).
- `DrawPrimitive(4=TRIANGLELIST, start, count)` = **+0x118** (observé avec
  `(dev,4,0,n)` et via gfx `(+0x58,4,0)`).
- `SetPixelShader?` (+0x160), `SetMaterial`(+0xA8), `SetLight`(+0xB0), `Clear`(+0x90)
  observés. Mapping vtable complet D3D8 dans la réponse Q6 (source wine d3d8.h).

## Fog par passe (item 5) — les registres sources ENGINE

`main_drawwrld_004329b0 @ 0x004329B0` (engine) charge au début du draw world :
```
DAT_00656D00 = WS+0x1E4 ; DAT_00656D04/14 = WS+0x1EC, WS+0x1F4   (ops 52-54 : terrains A/B/C)
_DAT_00657044/48/54/58  = ±mêmes valeurs (variantes signées)
DAT_00656C00 = WS+0x4F24 ; DAT_00656C04 = WS+0x4F2C ; DAT_00656C08 = -WS+0x4F2C  (op 116 : musique/fog C)
```
→ Ce sont les **uniforms de passe** passés au renderer via gfx_sys (offsets 0x98/0xA8).
Les valeurs par défaut de ces WS viennent des ops 41 (fog RGB+near/max),
46 (fog alt), 88 (water fog), 119/120 (fog packs A/B) des world bins —
cf docs/formats/bin_objects.md (table des cibles WS par op).

## MISE À JOUR 2 — items 1 & 2 de Q6 RÉSOLUS (engine side, 2026-10-15)

### (1) TERRAIN — `terrain_elevation_gen @ 0x00514D60` (la formule, enfin)

Le terrain NE MAPPE PAS de texture par position : la 1re passe est une **palette par
hauteur** via une texture ramp **64×64 générée procéduralement** (`elevation_texture`,
gris `v<<16|v<<8|v` ×4 rampes de 0x21/0x20 échantillons, stat `DAT_005DC8B0..CE`).

Boucle vertex exacte (stride **6 floats = 24 octets** : x, z, y, (rhw/0), u, v) :

```c
v[0] = x_monde;                       // avance de cell_size à chaque colonne
v[1] = z_monde;                       // avance de cell_size à chaque rangée
h_a = mesh[node ^ 1];  h_b = mesh[node];     // hauteurs des niveaux LOD voisins
v[2] = h = (1-ratio)*h_a + ratio*h_b;        // ratio = (hmax-hmin)/hmax  (+0x38/+0x3C)
                                            //   → le "skirt" entre patchs LOD
v[5] = 0.0;                            // v = 0 (ramp 1D)
v[4] = h * (0.5 / heightScale) + lodBias + 0.5;   // ← UV = hauteur normalisée!
lodBias = 0.0078125 par défaut | 0.5/2^mip si flag 0x1000 (tex détail) | 0
cell_size = terrain+0x14 ; heightScale = terrain+0x18
```

- Maillage : **quadtree LOD** — chaque nœud 16 octets avec liens ushort
  (`+8/+A/+C/+E/+10` = neighbors/children), grille de départ `param_2*0x10`.
- Soumission : `primbuffer+0x10(cols*rows)` → vertex lock, puis
  `primbuffer+0x20(count=(cols-1)*(rows-1), indices=terrain+0x24)` = **indexed**,
  FVF local `0x124` passé à gfx_state+0x14 avec la texture elevation.
- État : `gfx_sys+0x18(mat identity)`, `state+0x10=1, +0xC=0`, `sys+0x50(2,0)`.
- Bonus : `terrain_vertex_walk @ 0x00514A50` = déformation radiale (cratères) :
  `d = fast_rsqrt(x²+z²)` (table `DAT_005F0A18`), si `d < R` :
  `y += (1-d/R)*cos(phase1*2π*d + phase2*2π)*amp` — via table log, exact.
- La 2e passe (texture détail / multi-tex stage2) : voir suite de la fonction
  (`sys+0x50(0,0)` final) — le couple TSS stage2 MODULATE2X s'applique ici.

### (2) MER — `main_drawwatr_00430F30` + `_00431700` (complet)

- **UV** : `seauv[i].u = seapos[i].x / scale ; seauv[i].v = seapos[i].z / scale`
  avec `scale = WS+0x7C` (op 46 fog-near réutilisée comme taille de tiling !).
- Maillage : **grille 33×13 (429 verts) caméra-centrée**, indices en strip-triangles
  générés une fois (`v, v+1, v+0x21, v+1, v+0x22, v+0x21`) dans `DAT_0059B7D0`.
- Placement : direction horizon = normalize(WS+0x4F60/64) × **12500**, caméra
  **réfléchie** à travers le plan horizon (`p' = p - 2*(p·n)*n` via fVar7*2+fVar5) ;
  vertex = lerp(cam, horizon, fade[row]) avec y=0.
- Fade alpha par rangée : table `((i-1)-5)*0.1*0.25+0.5` + couleur par rangée
  `cos(clamp((i-0x10)*WS+0x50AC*0.09817477, ±π/2))^pow << 24 | WS+0x50A0`
  (WS+0x50A0/A4/A8 = palette terrain op 121 !).
- Fog : `gfx_sys+0xAC(WS+0x140, WS+0x144, WS+0x148..150)` (waterfog op 88 ;
  variante sous-marine couleur 0).
- Textures : mer = `WS+0x6C` (la texture sea de world.gb2 !), variante via
  `WS+0x4EA0` si flag 0x40, FVF `0x23004`/`0x14` selon état.
- Anim : `DAT_006331B0` gate + reset `WS+0x50B8` (init une fois).

### (3) gb2 — reste open (prologue seul)

Composants instanciés via GameObj registry (`main_makeobj_00472dd0`), la texture
mer ci-dessus (`WS+0x6C`) est précisément le composant `sea` de world.gb2 →
la consommation passe par les slots WS. Vertex layout des corps : encore open.

## Livrables

- Corpus décompilé : `RuntimeLab/ggdx7_decomp/ggdx7_decompiled.c` (367 fns) +
  index + projet Ghidra `ghidra_projects_ggdx7/` (local).
- Script d'export : `scripts/export_ggdx7_pyghidra.py`.

## MISE À JOUR 3 — 2026-10-15 : passe GBS (acteurs/props) + rôle réel du GTI + clarification terrain

### `animate_core_caller @ 0x0042E460` — LA passe mesh GBS (les acteurs de la cinématique)

```c
// 1. LOD par distance : d = distance3d(obj, cam) ; fVar1 = (camRight/objScale)*(d+objRadius)
//    sélection du 1er slot LOD (table pondérateur DAT_005565C0[DAT_631150]) — 9 niveaux
// 2. main_animate (skin CPU) → GEO_MatTranspose → gfx_sys+0x18(matrice modèle)
// 3. gfx_state+8(FVF=0x20060, texture=0, couleur=0xFFFFFF)
// 4. par LOD-section (stride 0x14 dwords, count=+0x68 du LOD entry) :
//    vbuf = primbuffer+0x10(count, ctx, section)      // lock 3-args (contexte section)
//    PTR_mesh_build_fvf_verts_2_005565B0(vbuf)         // builder FVF (ptr table)
//    primbuffer+0x18(-count)                          // unlock
//    → TOKEN STREAM u16 (le format de soumission GBS) :
//        0            = fin de section
//        bit15 set    : strip  → primbuffer+0x24(n & 0x7FFF)
//        bit14 set    : fan    → primbuffer+0x28(n & 0xBFFF)
//        sinon        : tri-list → primbuffer+0x20(n*3, indices[n*3] suivent)
```

C'est le rendu de TOUS les modèles (Meccs, Reapers, smarties de la cinématique).

### Rôle réel du GTI (`gti_terrain_load @ 0x00474440`)

Le GTI n'est PAS le mesh visuel : il produit **les 958 bounding-boxes monde de
collision** (records 0x38 octets : bbox 8 dwords + 6 dwords auxiliaires,
`WS+0x204`) + les **bornes du monde** (`WS+0x1C8..0x1DC`, cellSize `WS+0x1C0` +
inverse `WS+0x1C4`). Le mesh visuel du terrain est le quadtree de
`terrain_elevation_gen` (formule palette-hauteur §MISE À JOUR 2).

### Récap des passes de rendu (carte complète pour la cinématique)

| passe | fonction | FVF GDV | texture | géométrie |
|---|---|---|---|---|
| gb2 (sky/sea/underside) | `dlog_scene_submit` | 0x24 | WS+0x4C (op30) | pos+uv gb2, diffuse blanc, tri-list (+2e passe fog 0x60720 si WS+0x16C>0) |
| terrain | `terrain_elevation_gen` (+ appel wave) | 0x124 (local) | ramp64 élévation | quadtree LOD, palette hauteur |
| mer | `main_drawwatr_00431700` | 0x23004/0x14 | WS+0x6C (sea du gb2) | grille 33×13 caméra, uv=pos/WS+0x7C |
| GBS acteurs/props | `animate_core_caller` | 0x20060 | par-section | token-stream strip/fan/tri |
| HUD/texte | `status_hud_render`/`showchat_mission_objective` | var / 0x20000 | var | quads |
| effets | `animate_core_caller` alias 0x20060, `fx_*` | var | var | billboards |
