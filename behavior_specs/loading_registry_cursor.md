# Loading screen + registry settings + cursor (from decompiled code)

Derived 2026-06-18 by reading vanilla_decompiled (FUN_0045a530, FUN_00483740,
FUN_004a3900, FUN_0042e450). Code analysis (not screenshots) per the menu/game-logic axis.

## 1. Registry settings loading (resolution + options)
The vanilla reads HKCU\Software\PlanetMoon\Giants at boot:
- **FUN_004a3900** = DEFAULT settings init (first run / no profile): zeroes the settings
  struct `DAT_00631700` (0x66 dwords = 0x198 bytes), sets defaults, reads DefPlayer,
  then reads VideoWidth/Height/Depth/GUIDs from registry.
- **FUN_00483740** = READ saved settings: checks GameOptionsVersion==1, reads the
  GameOptions bitmask `_DAT_0059df14` (FUN_0051f7a0 RegDWORD), applies flags via
  FUN_00521* setters, then:
  - `FUN_0051f7a0("VideoWidth",  &DAT_00631818)` → width
  - `FUN_0051f7a0("VideoHeight", &DAT_0063181c)` → height
  - `FUN_0051f7a0("VideoDepth",  &DAT_00631820)` → bpp
  - `FUN_0051f840("VideoDevGuid", DAT_00631838, 16)` → device GUID (RegBinary)
  - `FUN_0051f840("VideoDrvGuid", DAT_00631828, 16)` → driver GUID
  - MusicVolume/SoundVolume (floats).
- FUN_0051f7a0 = RegRead DWORD, FUN_0051f840 = RegRead binary (16B), FUN_0051f8a0 = RegRead string.

**Globals**: DAT_00631818=VideoWidth, DAT_0063181c=VideoHeight, DAT_00631820=VideoDepth,
DAT_00631838=VideoDevGuid, DAT_00631828=VideoDrvGuid, DAT_00631700=settings struct,
_DAT_0059df14=GameOptions flags. The renderer (gg_dx7r GDVSysCreate) uses these for the
device resolution. **Recomp currently HARDCODES 640x480 — should port FUN_00483740 to read
the real registry values.**

## 2. Loading screen (FUN_0045a530)
```
FUN_0050e4d0();                          // SceneWalk_Textures (load textures)
DAT_006316e4 = 1; ...                    // loading-state flags
FUN_0050f120(DAT_0059ca58..ca64);        // clear the 4 loading-tile slots
iVar1 = FUN_004b7640(DAT_0059ca4c);      // level lookup (returns level struct, +4 = name)
ch = first char of level name:
    'K' → PTR_s_kabuto_loading   ("kabuto_loading")
    'R' → PTR_s_reaper_loading   ("reaper_loading")
    'I' → PTR_s_giants_loading   ("giants_loading")
    else → PTR_s_mecc_loading    ("mecc_loading")
FUN_0050eb50(loadingImage, &DAT_0059ca58, &w, &h, &texPtr)   // tile the loading TGA
FUN_0042bfb0();                          // ?
FUN_0042be00(&renderLoopCB, &doneCB);    // register async load + render callbacks
```
So the loading screen = a **`<player>_loading.tga`** (per level/player) shown as a TILED
image (FUN_0050eb50) while the async level load runs. For the menu/intro it's giants_loading.
The render loop draws it via the SAME 2D blitter (FUN_00433900 → the loading-tile slots).

## 3. Custom mouse cursor (FUN_0042e450)
```
if (DAT_0059a770 == 0) DAT_0059a770 = FUN_0050e3c0("cursor");   // resolve cursor texture by name (cached)
(DAT_00654948+8)(DAT_00654948, 0x32c, DAT_0059a770, 0xff000000); // SetTexture(cursorTex, opaque)
verts = (DAT_00654958+0x10)(DAT_00654958, 4);  // lock 4 verts (a quad)
// quad at mouse pos DAT_0063111c(x), DAT_00631120(y), sized DAT_006314e4 * _DAT_005523f0
// 4 verts: XYZRHW + UV + (the 0x32c flags include color)
```
The cursor = the **"cursor" texture** (FUN_0050e3c0 resolves by name) drawn as a quad at
the mouse position via the SAME 2D blitter mechanism (DAT_00654948 SetTexture + DAT_00654958
quad). DAT_0063111c/1120 = mouse X/Y, DAT_006314e4 = cursor size, _DAT_005523f0 = scale.
**FUN_0050e3c0 = single-texture-by-name resolver** (not tiled — for small UI textures
like the cursor; contrast FUN_0050eb50 which tiles large images).

## Implementation priorities (canonical, code-driven)
1. **Registry** (FUN_00483740): read VideoWidth/Height/Depth + GUIDs into the globals →
   the renderer uses the REAL registry resolution (not hardcoded). Pure registry I/O, easy.
2. **Cursor** (FUN_0042e450): load "cursor" texture (FUN_0050e3c0 by name), track mouse X/Y,
   draw cursor quad via VanillaBlit at mouse pos. Visible, on the menu path.
3. **Loading screen** (FUN_0045a530): show giants_loading.tga (tiled) during the load phase
   between intros and menu.

All three use the 2D blitter machinery already ported (VanillaBlit / FUN_00433900).
