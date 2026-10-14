# INPUT — DirectInput pipeline, key/mouse state, memory-driven input

Status: ✅ full pipeline decoded + **observed**: memory-written keypress drove a menu
selection (screenshots `RuntimeLab/logs/traces/before_drive.png` / `after_drive.png`:
selection moved "Return to Game Options" → "Change Resolutions" with zero OS input).

**Evidence:** GOG 1.449 corpus (`dinput_init @ 0x00519110`,
`dinput_key_poll @ 0x00519930`, `input_keystate_update @ 0x00519A50`,
`dinput_device_check @ 0x00519750`, input-translate function writing `DAT_00632AA0..AD7`).
Marking: **observed** (validated live) vs **derived** (decomp only).

## Devices (from `dinput_init`)

- DirectInput8 via `DirectInput8Create`; two devices: **keyboard** (`c_dfDIKeyboard`,
  buffered) and **mouse** (`c_dfDIMouse2`-style, immediate 0x34-byte state).
  Globals: DI object `DAT_005DDB7C`, keyboard device `DAT_005DD0BC`,
  mouse device `DAT_005DD184`.
- No `GetAsyncKeyState` anywhere — the game consumes DirectInput only.

## Keyboard (scancode bitfields)

`dinput_key_poll` reads buffered events (`GetDeviceData`, 20-byte entries) and maintains
**8-dword bitfields indexed by DIK scancode** (`bit = 1 << (dik & 31)`, dword
`dik >> 5`):

| address | meaning |
|---|---|
| `0x5DD0C0[8]` | held (down state; set on press event, cleared on release event) |
| `0x5DD0E0[8]` | pressed this poll (set on press; consumed by rotation) |
| `0x5DD0F0[8]`, `0x5DD100..0x5DD11C` | history rotation (prev-held / released / shadow), rotated per frame by `input_keystate_update` |

`input_keystate_test(dik, ...)` = the game's key test helper (e.g. F11 check `0x7a`).

**Memory-driven input (proven)**: write the held bit + the pressed bit, let one frame
run, then clear the held bit. The per-frame rotation delivers exactly one keypress.
Helper: `scripts/memkey.py` (`press('DOWN')`, `press(0x1C)`), driven entirely through
the debugger's memory writes — works while the game runs under x32dbg.

## Mouse

`dinput_device_check` (per frame):

```
0x5DD1B4[13]  fresh DIMOUSESTATE2 from GetDeviceState (0x34 bytes)
0x5DD1E8[13]  previous state copy (pre-poll snapshot)
DIMOUSESTATE2: +0x00 i32 lX, +0x04 i32 lY, +0x08 i32 lZ, +0x0C u8 buttons[8]
after read: first 4 dwords get -0x7DFF bias adjustment (unset-marker encoding)
then: 0x5DD21C..0x5DD230 = game-side mouse ints (cursor x/y, wheel, buttons) via ftol
```

- Mouse **deltas are per-frame** — synthesizing movement needs per-frame writes
  (impractical over the MCP bridge). Persistent game-side cursor = **floats
  `0x632B10` (x) / `0x632B14` (y)** (copied from the 0x5DD21C/220 ints each frame).
- **Buttons are per-frame derived** — no persistent synthetic hold via memory; use
  OS-level `SendInput` (`scripts/game_driver.py`, elevated) for button holds.
- The input-translate pass rebuilds the **action-flag block `0x632AA0..0x632AD7`**
  (32 dwords of byte flags: fire/jump/camera/...) every frame from the key bitfields
  (`0x5DD0C0/E0/F0/F8`, `0x5DD138`, `0x5DD144`) + mouse ints. Downstream systems read
  these flags, the cursor floats, and `0x632B18` (button-derived float).

## Provenance summary

- Keyboard bitfields + memkey channel: **observed** (menu-selection proof).
- Mouse layout + game-side structs: **derived** (decomp), consistent with the
  menu-cursor behavior seen live.
- Action-flag bit → action name mapping: open item (decode the translate function's
  32 flags against in-game key bindings during a traced gameplay session).
