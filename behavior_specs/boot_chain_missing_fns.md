# Boot-chain missing functions — disassembled from Giants_nocd.exe (gap fill)

The Ghidra export (`vanilla_decompiled/`) missed these functions (referenced as continuation
labels / not auto-defined). Disassembled with `scripts/disasm_exe.py` (capstone, ImageBase 0x400000)
to fill the gap for the faithful boot-chain port. Regenerate with `python scripts/disasm_exe.py <VA>`.

## FUN_0045a640 — world-load CONTINUATION (post-loading-screen)
Gated on `DAT_0059ca70 >= 3` (else `jmp 0x45a7bc` = keep waiting). This is the async continuation
FUN_0045a530 set up (via FUN_0042be00(&LAB_0045a640, &LAB_0045a7c0)). Once the loading progress
counter hits 3:
1. `call FUN_004f3230` — **the scene spawn** (next chain function — spawns the loaded world's objects).
2. `call [0x5dc2a4]` (indirect engine callback) → fstp [0x59ca50] (a float, likely time/delta).
3. `push 0; call [0x5dc298]` (indirect).
4. `DAT_00631380 = DAT_0059ca4c` (current world index).
5. `call FUN_004f3570`, `call FUN_004f35f0`.
6. `ecx = DAT_006316ec + 0x4514; push 0x55c214 (string); push ecx; call FUN_00544b47` (sprintf world name).
7. `call FUN_004b7a10`, `call FUN_004b7ae0`.
8. `call FUN_0050f120(<4 floats>)` — loading-screen fade/transition finalize.
9. `DAT_006316e8 = 1; DAT_0059ca54 = 1` (mark loaded).
→ So FUN_0045a640 = "loading finished → spawn scene (FUN_004f3230) + finalize state".

## FUN_0045a7c0 — LOADING-SCREEN RENDER (the other continuation, runs each frame while loading)
1. `call FUN_00433900` — **the 2D tiled blitter** (draws the loading image: giants_loading.tga etc.).
2. `call FUN_0042c1a0`.
3. `inc DAT_0059ca70` — **increments the loading-progress counter** that FUN_0045a640 waits for.
4. `call FUN_0050d7f0` (GetLocalizedString), `call FUN_004b7730`, `call FUN_00544b47` (format text).
5. `call FUN_00521060`, then 2× `call FUN_00432fb0` (2D text/quad draws, colors 0x0a0d0d0, 0x0102060).
→ So FUN_0045a7c0 = "draw the loading screen + bump progress; FUN_0045a640 fires when progress>=3".

## Chain confirmation
`FUN_004913c0` (select "intro_island") → `FUN_0045a530` (show loading screen + async task
{0045a7c0=render-loop, 0045a640=post-load}) → `FUN_0045a640` → `FUN_004f3230` (scene spawn).
The .BIN world itself is loaded by `FUN_004b7c50` (called somewhere in the async path / by
FUN_004f3230 setup). `FUN_0053a3e0` = the asset loader bridge (GZP read → renderer texture).
