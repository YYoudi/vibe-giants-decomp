# DX7 Renderer — Engine→Renderer Method-Call Recipe (vanilla, captured 2026-06-16)

Captured via Frida (`scripts/frida_render_recipe.js`) on the original `Giants_nocd.exe`
(intros skipped for faster 3D). Hooks all ~55 method-table slots of the GDVSysCreate
renderer object (this=0x42ce820), logs call order + first 3 args + total counts over ~9s.

This is the EXACT sequence the engine drives on the DX7 renderer object — the recipe the
vanilla recomp must reproduce to render. All calls are `__thiscall` (ECX=renderer obj).

## Method-table slot → RVA (from GDVSysCreate disasm)
```
+0x04=0x3090  +0x08=0x42c0  +0x0c=0x3490  +0x10=0x2d80  +0x14=0x42d0  +0x18=0x3e60
+0x1c=0x3ea0  +0x20=0x3ee0  +0x24=0x3f90  +0x28=0x3fe0  +0x2c=0x4000  +0x30=0x4020
+0x34=0x4040  +0x38=0x4130  +0x3c=0x4070  +0x40=0x4120  +0x44=0x4200  +0x48=0x4240
+0x4c=0x4180  +0x50=0x2d40  +0x54=0x4270  +0x58=0x4290  +0x5c=0x42f0
+0x60..= c880/c9d0/c900/c970/79c0/7bc0/7aa0/7370/73e0/7910/aba0/86a0/87a0/...
```

## Init phase (one-shot, first ~50 calls) — device/display/state setup
```
0x3090  a1=0x1e0(480) ...                ; init/size
0x42d0  ...
0x3e60  a1=0x100190a0 (const ptr)        ; state block begin?
0x2d80  (repeated)                       ; clear/flush
0x3ea0  a1=0x100190a0
0x3ee0  a1=0x100190a0
0x3f90  a1=0x100190a0
0x4180  a1=0 a2=0 a3=0                   ; reset
0xc970  a1=&5dcb34 a2=&5dcb44 a3=0x2c    ; set display params (globals, count=44)
0x7870  a1=STATE a2=&val a3=VALUE        ; SetRenderState — repeated for states 7,1,2,5,0,1..7
0x3490  a1=2 a2=2/0x20/0xfa0/0x100/0x200 ; SetDisplayMode / viewport (res, bpp)
0xc6a0  a1=incr_ptr a2=0x1e(30) a3=base  ; BULK DATA UPLOAD — 30 per call (vertices/buffers)
```

## Per-frame hot path (total counts over ~9s of menu render)
```
0x2d80 : 819,201   ← THE draw/clear hot loop (called ~90K/frame)
0x3ee0 : 214,406
0x84d0 : 182,829   (slot ~0xac)
0x3e60 : 123,007
0x4240 :  49,126
0xaba0 :  24,570
0xae80 :  18,193
0x86a0 :  21,083   (paired with 0x87a0)
0x87a0 :  21,083
0x4070 :  31,588
0x42d0 :  14,089
0x7370 :   3,557
0x8970 :   3,532   (paired with 0x7910)
0x7910 :   3,532
0xc030 :     334
0xc6a0 :   1,007   (init-time bulk upload)
0xc970 :       2
0x7870 :      60
```

## Implication for the recomp
The device CREATES (callback[18] malloc fix). To render, the engine must drive the above
sequence. Faithful reproduction = port the vanilla engine's render pipeline (ScenePipeline,
GameLogic) that issues these thiscall method invocations. The `0x2d80` hot loop is the
per-polygon/per-vertex draw dispatch; `0xc6a0` is buffer upload; `0x7870` is SetRenderState;
`0x3490` is display-mode/viewport setup.

The recomp's path to a visible frame: port the vanilla init chain (registry → renderer →
this method-driving sequence) so the recomp issues these calls itself with real game data.
See `vanilla_decompiled/` (2578 funcs) + `version_bridge/VERSION_MAP_v2.csv` for the source.

Full raw capture: `reports/frida_render_recipe.txt` (SEQ = first 120 ordered calls,
COUNTS = per-method totals).
