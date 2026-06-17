# Loading screen spec (measured from vanilla Giants.exe FUN_0045a530)

**The recomp's "LOAD ISLAND" screen DOES NOT EXIST in the original.** The string
`int_loadisland` appears NOWHERE in Giants.exe. This spec corrects that invention.

## Real loading screen = giants_loading.tga
`FUN_0045a530` (`vanilla_decompiled/0045a530.json`) picks the loading texture by the
**first letter of the level name**:
- `'K'` → `kabuto_loading`
- `'R'` → `reaper_loading`
- `'I'` → **`giants_loading`**  ← intro_island starts with 'I'
- default → `mecc_loading`

The 4 names live at `.rdata` VA `0x0055c1d4`–`0x0055c208`.

`giants_loading.tga` = the screen the user described: 3 character portraits (Mecca,
Kabuto, Delphi) + "Loading Giants..." text + progress bar. Matches
`memory/menu-visual-reference.md`.

## When it shows
Shown by `FUN_0045a530` DURING the async level load that `FUN_004913c0` kicks off
(boot step 14). It is NOT a standalone boot phase — it flashes only while the level
.BIN loads, then the menu 3D scene + GUI appear.

## What int_loadisland.tga actually is
A menu GUI texture packed in `Bin/w_menus.gzp` (offset 0x35e4f0). It is menu chrome
(the "Load Single Player Game" / level-select list-row artwork), part of the
`xx_menus.bin` screen set. **Never displayed standalone at boot.**

## Recomp TODO (fidelity)
- DELETE the fake `int_loadisland`-based "LOAD ISLAND" display.
- Show `giants_loading.tga` during the async load path (`FUN_0045a530`), driven by
  `FUN_004913c0`, only while the level .BIN is parsing.
- CONFIRM dynamically: Frida-capture when `giants_loading.tga` is bound/drawn.
