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

## Items 1-3 de Q6 (UV terrain, mer, gb2) — où c'est, statut

- **UV terrain** : générées ENGINE-side dans la famille `main_drawwrld_00434xxx`
  (le DLL ne fait que DrawPrimitive des FVF engine). Le GTI (1024×1024) n'a pas
  d'UV : le mapping naît dans le builder de vertex du terrain. **Open** : lire
  `main_drawwrld_00434c80` (scene draw) + le builder (suivre `DAT_006573B0-BC`,
  la liste de draw contexts vidée par `main_drawwrld_00432E10`). Hypothèse de
  départ (`inferred`) : `tu = grid_x/(N-1)`, `tv = grid_z/(N-1)` à confirmer.
- **Mer** : chercher `main_drawwatr*` / passes water dans la même famille (les
  flags waterfog WS+0x140..0x150 = op 88 s'y consomment).
- **gb2** : les composants (sky/sea/underside) sont instanciés via le registre
  GameObj (`main_makeobj_00472dd0(DAT_00632D2C/30)`) → objets rendus par la même
  passe scene. Vertex layout des corps gb2 : encore open (prologue décodé dans
  docs/formats/world_gb2.md).

## Livrables

- Corpus décompilé : `RuntimeLab/ggdx7_decomp/ggdx7_decompiled.c` (367 fns) +
  index + projet Ghidra `ghidra_projects_ggdx7/` (local).
- Script d'export : `scripts/export_ggdx7_pyghidra.py`.
