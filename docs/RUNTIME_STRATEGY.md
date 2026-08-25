# Giants v1.0 — Runtime RE strategy & findings (session 2026-08-25)

Ground truth: `GameFiles-VanillaV1/Giants.exe` (MD5 330c6a9a8ab0fa4b0173d925e1d5ec27,
PE32 base 0x400000, image 0x260000 virt / 0x18F000 raw, entry 0x547358).
All runtime work happens on the copy `RuntimeLab/GiantsWork/` — vanilla dir is never touched.

## 1. Toolchain (all verified working)

| Layer | Tool | Notes |
|---|---|---|
| Debugger | x32dbg + x64dbg-MCP-Server.dp32 (duty1g, Zig) | HTTP :9095, Bearer token in `G:/Tools/x64dbg/release/x32/mcp_config.json`; registered in ZCode user scope (`~/.zcode/cli/config.json`) |
| CLI bridge | `scripts/xdbg_call.py <Tool> '<json>'` | reads token/port itself |
| Sessions | `scripts/boot_session.py` | LoadBinary → CD stub → erun-loop → report |
| What/when | Procmon (`G:/Tools/procmon/`) | system-wide file/reg/DLL with timestamps; export CSV → `scripts/analyze_procmon.py` |
| Threads post-mortem | procdump + `minidump` (pip) | dump wedged process → per-thread EIP + stack scan |
| Static | capstone + pefile (pip) | RVA↔file-offset, disasm without debugger |
| Symbols | `ps2_symbols/` (4769 PS2 names, 378 PC↔PS2 matches) | PC addrs in matches.csv are v1.0-valid (image is 0x260000) |

## 2. Method (layered observation, never guess)

1. **Procmon** answers *what/when*: files opened, registry read, DLLs loaded, order, failures.
2. **x64dbg** answers *where in code*: breakpoint on the API that procmon flagged →
   `[esp]` return address = caller RVA → static disasm around it (capstone).
3. **ps2_symbols** answers *who*: match the function's strings/xrefs against PS2 names.
4. Everything memory-patched at runtime only; files stay byte-identical.

## 3. Boot flow (observed, v1.0 vanilla)

```
entry → CRT init (apphelp/AcGenral compat shims injected by OS)
  → scan Bin\*.gzp  (~40 packages, TOC parsed; caller Giants+0x13B9E5 in a CreateFile wrapper)
     · reads fall back to DestDir (registry) for missing packages (VO_SfxEnglish.gzp → G:\Games\Giants\Bin)
  → HKCU\Software\PlanetMoon\Giants read: DefPlayer, IDs\Player\{VideoWidth 640, VideoHeight 480,
     VideoDepth 32, VideoDevGuid, VideoDrvGuid}, Windowed=1, Renderer="gg_dx7r.dll"
  → dinput.dll (DINPUT.dll probe first), winmm
  → CD CHECK (see §4)  ← hard stop without CD
  → LoadLibrary("gg_dx7r.dll") from Giants+0x11EBEF
  → ddraw/d3dim700/dsound init, amdxn32 (AMD driver hook) exception storms
  → content load (~100 MB RSS) → ? (menu not yet reached — see §6)
```

## 4. CD-check — fully reversed

`Giants.exe+0x13AE80` (0x53AE80), observed live at the GetVolumeInformationA hit:

```asm
mov eax,[0x631890]        ; cache flag: set 1 by monitor at +0x1233E1, cleared at +0x123404
test eax,eax ; jne ret 1
mov al,[0x5E11A0]         ; CD path global = HKCU SrcDir ("D:\Games\Giants")
root = first 3 chars      ; "D:\"
GetVolumeInformationA(root, name, 100, 0, 0, 0, fsname, 100)
GetDiskFreeSpaceA(root, ...)
stricmp(name,  "GIANTS1") ; 0x581560  ← expected CD volume label
stricmp(fsname,"CDFS")    ; 0x581558
return ([local0]==0)
```

Related strings at 0x581568: `"%s\..\GIANTSCD.1"` (CD marker file), `"hashtab"`,
`"C:\Giants\Source\Utils\hash..."` (dev paths left in .rdata).

**Runtime bypass (memory only):** `B8 01 00 00 00 C3` (mov eax,1; ret) at 0x53AE80
+ `[0x631890]=1` — applied by `scripts/boot_session.py` at each session start.
Registry keys that matter: `HKCU\Software\PlanetMoon\Giants` SrcDir (CD) / DestDir (install).

## 5. Renderer interface anchors (observed)

- Renderer loader: caller of LoadLibraryA("gg_dx7r.dll") = **Giants+0x11EBEF**.
- Renderer upcall tables: globals `[0x654948]`, `[0x654958]` = structs of function pointers into gg_dx7r.dll
  (C-style interface; the AGENTS.md exports GDVSysCreate/GFXGetCapabilities/UpCallsLoad match this).
- Crash signature with broken renderer at **Giants+0x32FDE**: `call [eax+0x10](obj,4)` returned NULL
  (ESI=0x8007000E E_OUTOFMEMORY) then `fstp [eax]` writing screen coords → AV.

## 6. Renderer matrix on Win11/AMD (all with v1.0 exe + CD stub)

| gg_dx7r.dll | stack | result |
|---|---|---|
| contaminated (demo-patched, prev. sessions) | system d3dim700 | AV Giants+0x32FDE (E_OUTOFMEMORY path) |
| Mecc demo clean (jan 2001) | system d3dim700 | boot to ~109 MB, then AV loop in msvcrt strlen called from d3dim700 ← device-enumeration string |
| Mecc demo + DDrawCompat 0.7.1 | DDrawCompat ddraw + system d3dim700 | same d3dim700 AV loop |
| GOG 2008 build (1.449, D3D8 wrapper — loads d3d8.dll/d3d8thk) | d3d8 | heap-corruption AV in ntdll (mov eax,[ecx+14] heap walk) after ~66 MB |
| **Mecc demo + dgVoodoo2 2.87.3 (DDraw.dll + D3DImm.dll→d3dim700.dll)** | **dgVoodoo → D3D11 → amdxx32** | **✅ MENU REACHED: window "GFX_DX7" responding, frame presented, engine idle-waiting for input** |

Winning work-dir layout: `GiantsWork/{Giants.exe (vanilla bytes), gg_dx7r.dll (Mecc), ddraw.dll + d3dim700.dll (dgVoodoo2 MS/x86), dgVoodoo.conf}`.
Note: dgVoodoo → amdxx32 (AMD D3D11 driver) throws SEH exceptions continuously in normal
operation — x64dbg must not pause on them (`erun` / IgnoreRange), else boot crawls forever.

## 6b. Menu-state architecture (observed via 3× minidump sampling)

- 11 threads; the game MAIN thread (stack ~0x1Axxxx) sits inside:
  `game → gg_dx7r+0x6687 → user32 message pump (5-6 frames) → PeekMessageW` —
  i.e. the renderer's present/wait path pumps messages cooperatively; the menu is
  BLOCKED WAITING FOR INPUT (not wedged): identical dumps ×3, window Responding=True,
  one presented frame, zero CPU.
- Message APIs are **W-variants** (PeekMessageW) — A-variant bps never fire.
- No per-frame QPC/timeGetTime calls observed at menu idle.
- Deeper stable stack values (indirect-call returns, no E8 alignment): giants+0x18B750,
  giants+0x130000 — candidates for the main-loop frames once walked properly.

Wedged-process forensics (procdump + minidump): main thread blocked in kernel wait, top game
frame **Giants+0x3005C** (wrapper calling +0x2FF10 — event/semaphore wait family); all other
threads idle. I/O during wedge: zero (pure usermode deadlock/AV loop).

Remaining candidates: dgVoodoo2 (replaces ddraw AND d3dim700 — removes the crashing system
runtime entirely), unhooking amdxn32, GOG Giants.exe vs v1.0 renderer-interface diff.

## 7. Debugger technique notes (x64dbg MCP)

- `run`/F9 on a first-chance exception **swallows** it — game workers depending on C++ EH deadlock.
  Use **`erun`** (pass exception) or `IgnoreRange 00000000-FFFFFFFF`.
- Statuses: PAUSED/LOCKED both mean "stopped"; the plugin's WaitForPause times out while RUNNING.
- The plugin's `pause` command is unreliable on busy targets — pause via a hot-API breakpoint instead.
- GetCallStack unwinds correctly at real exception pauses; at bp-on-thunk use `[esp]` for the caller.
- Plugin ring event log = 64 events; bp LOG text does NOT reach any retrievable log (LogSave only
  dumps the plugin's own init lines) — trace args by pausing, not by bp-logging.
- `SetConditionalBreakpoint` takes `{"address","condition","log"}` (param name is `log`, address not target).

## 8. Next steps

1. Human: confirm what the GFX_DX7 window shows (menu art? logo? garbage?) and click through it.
2. Main-loop anchors: walk the pump chain deeper (indirect-call alignment at +0x18B750 /
   +0x130000), or hardware-bp the upcall table entries `[0x654948]/[0x654958]` (called per frame).
3. Cross-ref runtime anchors with `ps2_symbols/pc_ps2_matches.csv`; name functions in x64dbg via labels.
4. GZP runtime trace: bp on the LZ decompressor during level load; validate vs
   `gck-map-extract-objects/lib/fileutils.py`.
5. GIANTSCD.1 marker mystery: monitor at +0x1233E1 may poll the CD continuously — verify what it
   reads when the flag is pre-set.
