# Menu system (from decompiled code)

Derived 2026-06-18 by reading vanilla_decompiled. Code analysis (not screenshots).
The menus are **TEXT-based** (drawn line-by-line via text-render functions), NOT FLICK.

## Menu rendering = text lines
Menus draw each choice as a text line via three text-render primitives:
- **FUN_0042c750(textCtx, align, x, y, alphaColor, str)** — draw a text string (header/title).
  - `DAT_0059e3a0` = the font/text context (the game's bitmap font).
  - args: alignment, position (floats like 0x3f000000=0.5, 0x3f800000=1.0), color+alpha
    (0x88000000 = alpha 0x88), the string.
- **FUN_0042cd40(textCtx, align, x, y, color)** — set text position/color for following lines.
- **FUN_0042d0a0(textCtx, align, str)** — draw a menu line at the current position (advances Y).

Each menu choice has TWO string variants: **`...On`** (selected/highlighted) and **`...Off`**
(unselected). The menu picks On/Off per the current selection index, e.g.
FUN_00497230 (multiplayer options):
```
FUN_0042c750(ctx, 0, 0.5, 1.0, 0x88000000, "Options For Mission: ...")   // title
FUN_0042cd40(ctx, 2, 0.5, 0.05, 0x8000022)                              // set pos for lines
sel = world[0x2238 + idx*0x118]
FUN_0042d0a0(ctx, 2, sel==0 ? "1. No Character Change ... On" : "... Off")
FUN_0042d0a0(ctx, 2, sel==2 ? "2. Play Mecc ... On" : "... Off")
FUN_0042d0a0(ctx, 2, sel==3 ? "3. Play Reaper ... On" : "... Off")
FUN_0042d0a0(ctx, 2, sel==1 ? "4. Play Kabuto ... On" : "... Off")
... (Zero/One/Two/Three Teammates ...)
```

## Selection state
- `DAT_006316ec` = world-state base (the `.data` world struct).
- `DAT_0063125c` = current menu/mission index.
- Per-menu selection values at `world + 0x2214 + idx*0x118` (title), `+0x2238` (character),
  `+0x2290` (teammates), etc.

## Profile-select ("Qui êtes-vous ?")
The first menu (no profile yet) — uses the SAME text-render primitives. The strings come
from localization (callback[11] GetLocalizedString → VanillaText::Lookup). Rendered over
the menu background (sky + logo).

## Implementation path (canonical, code-driven)
1. Port the text-render primitives (FUN_0042c750/cd40/d0a0) — they draw the game's bitmap
   font as quads via the renderer (DAT_00654948/00654958, same as the 2D blitter). Need the
   font asset (bitmap font texture + glyph metrics).
2. Port a menu driver (e.g. the profile-select) using the primitives + On/Off selection.
3. Wire selection state (mouse hover/click → DAT_0063125c) + cursor (DONE — FUN_0042e450).

## Note
FUN_00497230 is the MULTIPLAYER-OPTIONS menu (a sub-menu). The MAIN menu (Single Player /
Multiplayer / Options / Quit) and the profile-select are sibling functions using the same
text primitives. The text-render primitives (FUN_0042c750/cd40/d0a0) are the shared core —
port those first to unlock all menus.
