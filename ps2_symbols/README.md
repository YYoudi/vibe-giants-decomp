# PS2 Symbols — names/types dictionary for the PC decompilation

The PS2 prototype of Giants: Citizen Kabuto (`SLUS_201.78`, a MIPS R5900 ELF) was
shipped **unstripped**. Its `.symtab` exposes **4 769 named functions** and **1 691
named globals**, plus a 1 MB `.mdebug` block. Because the PS2 and PC builds share the
same C++ source (per modder "Amazed", ~50 % of functions are identical), these names
and signatures are ground truth for naming the stripped PC `GiantsMain.exe`.

## Files

| File | Purpose |
|------|---------|
| `SLUS_201.78` | The ELF itself (re-extracted from the ISO on demand; gitignored) |
| `extract_ps2_symbols.py` | Reproducible extractor: ISO → ELF → demangled CSV/text |
| `SLUS_201.78.symbols.csv` | Full table: addr,size,kind,bind,section,demangled,mangled |
| `SLUS_201.78.functions.txt` | `addr<TAB>size<TAB>demangled` — one function per line |
| `SLUS_201.78.rodata_strings.txt` | PS2 `.rodata` strings (for string-based PC↔PS2 matching) |
| `MODULE_INDEX.md` | Functions grouped by semantic prefix (scannable) |
| `lookup.py` | Search the database by keyword/regex/prefix/global |

## Regenerating

```bash
python extract_ps2_symbols.py   # needs: pyelftools, 7z at C:\Program Files\7-Zip
```

## How to use during PC reverse-engineering

1. When working a PC `sub_XXXXX`, run `lookup.py <concept>` to list PS2 candidates
   (e.g. `lookup.py collide`, `lookup.py --top reaper`).
2. Confirm the candidate by structure: same callee tree / same string refs / same size
   ballpark between the PC Ghidra decompile and the PS2 function.
3. Rename the PC function (Ghidra label + the `src/` stub) and apply the PS2 signature
   types (e.g. `collide_movement_grid_ground(OBJECT*, GridGround*)` → tells us the PC
   function takes `OBJECT*` and `GridGround*`).

## Validated mappings (PC ↔ PS2)

| PC `GiantsMain.exe` | PS2 `SLUS_201.78` |
|---|---|
| `MainGameLoop` 0x0062d100 | `game_loop_run` 0x0015b178 / `Psx2GameLoop__7PS2Game` 0x0018a3c8 |
| `FrameEnd` 0x005253b0 | `gs_buildFrameEnd` 0x0020ab00 |
| `EndSceneDirectional` 0x00524c10 | `XFEndScene` 0x001f6d90 |
| `UpdateActiveCamera` 0x0049a040 | `camera_get_curcamdef` 0x00113e28 + `camera_get_*` |
| `ComputeBoundingBox` 0x005de6b0 | `ANM_ClusterGenerateBoundingBox` / `WorldGridBoundingBox` |
| `collide_objects` (PC unmapped) | `collide_objects` 0x0011ba58 |

## Where PS2 ≠ PC (do NOT port these — mine the core only)

- **Renderer**: PS2 = direct GS via `gs_*`/`dma_*`; PC = DX plugin `gg_dx9r/dx11r/dx12r.dll`
- **Input**: PS2 = PADMAN IOP module; PC = DirectInput
- **Audio**: PS2 = LIBSD + IOP RPC; PC = SDV `gs_*.dll`
- **OS**: PS2 = `sce*` syscalls / IOP; PC = Win32 / CRT

Gameplay core (ai, army, collide, camera, mission, object, anim, fx, path) is the
shared overlap to mine for naming.
