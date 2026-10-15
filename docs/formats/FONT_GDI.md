# FONT_GDI — le système de fonte de Giants (pas de fichier, rasterisation GDI runtime)

> Résolution de l'open item "fonte FNT" (CINEMATIC_PIPELINE §8). Décomp
> `win95_text.c` + `_unmapped_0051.c` (GOG 1.449). Toutes les affirmations
> observed (decomp), sauf mention contraire.

## 1. Verdict : il n'y a PAS de format de fonte fichier

Aucun `.fnt` sur disque, aucune ressource `AFont` dans le PE (l'arbre de
ressources ne contient que icônes/dialogues). La string `AFont` est un nom de
**clé de configuration/registre**, pas un fichier. Les glyphes sont **rasterisés
à l'exécution par GDI Windows** dans un atlas généré au boot et au premier
usage de chaque caractère.

## 2. Initialisation de la fonte (`win95_text_0051adb0 @ 0x0051ADB0`)

Appelée avec la **hauteur en pixels** : `0x18` (24 px — HUD, menus, texte de
flick) ou `0xc` (12 px — petit texte) selon les call sites (observed :
`_unmapped_0045`:2198, `_unmapped_0048`:5910/6259, `_unmapped_0052` ×3).

1. `CreateCompatibleDC(NULL)` → DC mémoire (`DAT_005dd8c8`).
2. `CreateDIBSection` 1 bpp, **128×64**, top-down (`biWidth=0x80`,
   `biHeight=-0x40`) — le "scratch" de rasterisation (`DAT_005dd8c0`).
3. `SetBkMode(TRANSPARENT)`, `SetTextColor(0xFFFFFF)`,
   `SetTextAlign(0x18 = TA_BASELINE|TA_CENTER)`.
4. `LOGFONTA` : `lfHeight = <param>`, `lfWidth=0`, `lfWeight=400` (normal),
   `lfItalic/Underline/StrikeOut=0`, `lfCharSet = 0x80` si flag
   `DAT_00633148==0` sinon 0 (édition JA?), `lfQuality=2` (PROOF_QUALITY),
   `lfPitchAndFamily=0x22` (VARIABLE_PITCH|FF_SWISS), `lfFaceName` copié depuis
   le buffer BSS `DAT_005dd8d0`.
5. `CreateFontIndirectA` + `SelectObject`.

### Source du nom de face (`lfFaceName`)

- Buffer 64 octets en BSS, rempli par `render_driver_name_set @ 0x0051AD80`
  (mal nommé : c'est `font_face_set`), appelé par le parseur de configuration
  `gfx_d3d_0051d0d0 @ 0x0051D0D0` **cas 0x10** : option dont le nom fait
  5 caractères et finit par `.font` (ligne 15596) → la valeur = la face GDI.
- `AFont` (VA 0x57D774) : nom de clé posé dans le descripteur de fonte global
  (`_DAT_005dd3a0` dans l'init) — le mécanisme de config persistante du jeu.
- Si jamais renseigné : buffer BSS à zéro → `lfFaceName=""` → GDI choisit une
  fonte par défaut du système.

## 3. Rasterisation d'un caractère (`textrender_texture_alloc @ 0x0051B1C0`)

Cache par (charcode) avec entrées de 5 octets à `DAT_005dd3c0[ch*5]` :

1. Si déjà alloué (`DAT_005dd3c2[ch*5]!=0`), ne rien faire.
2. Efface le DIB scratch (1024 octets = 128×64/8).
3. `GetTextExtentPoint32A(hdc, ch, 1)` (mesure) puis
   `TextOutA(hdc, 0, 0x20, ch, 1)` — dessiné à la **baseline y=32**.
4. `GdiFlush()`, puis scan du DIB 1 bpp (MSB d'abord) → boîte englobante
   {xmin, xmax, ymin, ymax} relative à la baseline. Boîte vide → erreur
   `TextRender Fail on %d` (cas espace : garde fixe 4).
5. Métriques stockées (5 octets/char) :
   `[0] = 0x20 - ymin` (montée au-dessus de la baseline),
   `[1] = ymax - ymin + 1` (hauteur), `[2] = xmax - xmin + 1` (largeur),
   `[3] = atlas_x`, `[4] = atlas_y` (posés après blit).
   Ascent/descent max globaux trackés (`DAT_005dd394/98`).
6. **Blit dans l'atlas** : destination = buffer `DAT_005dd39c`,
   **256×128 pixels, 2 octets/pixel (u16)**, pitch 256 px ; chaque pixel du
   DIB allumé → `0xFFFF` (blanc opaque — teinté à l'affichage par le diffuse).
   Curseur d'empaquetage : x=`DAT_005dd37c` (wrap à 256, +1 de marge),
   y=`DAT_005dd378`, hauteur de rangée=`DAT_005dd380` ; débordement y>128 →
   erreur `Text Texture table is full!` (pas d'éviction).
7. `DAT_005dd390=1` (atlas dirty — re-upload D3D par le renderer).

## 4. Usage au rendu

- `FNT_StringRender @ 0x00515E90` : enregistre (string, FNT_RenderInfo) pour le
  rendu différé de la frame (consommé par la passe texte/HUD,
  `dlog_text_render_screen` etc.).
- `textrender_draw_large/small @ 0x0051BDE0/0x0051B850` : mesure/tracé par la
  taille sélectionnée ; `textrender_glyph_quad @ 0x004FA380` construit le quad
  UV depuis les métriques de la §3.
- Le champ "fonte" des flicks (op 21 = paire {size_id, param}) sélectionne la
  taille initialisée (24 ou 12 px) dans `FNT_RenderInfo` (flick+0x104/0x108).

## 5. Portage Rust (deux options)

1. **Parité exacte (recommandée pour l'oracle)** : répliquer avec `winapi` —
   même LOGFONT, même DIB 1bpp 128×64, baseline 32, même scan → l'atlas sort
   bit-exact identique sur la même machine/fonte installée.
2. **Portable** : rasteriser avec une lib TTF (ab_glyph…) en applicant les
   mêmes métriques (baseline 32, boîte englobante, atlas 256×128 u16, 0xFFFF)
   — parité métrique garantie, parité pixel au pixel près dépend de la fonte
   installée et du rasterizer (à documenter comme `derived`, pas `observed`).

La face par défaut installée sur la machine de référence + la hauteur 24 px
donnent le rendu des sous-titres de la cinématique ; pour l'oracle de parité,
comparer la position/le cadrage des sous-titres (rects op 17-20) plus tôt que
le pixel exact des glyphes.
