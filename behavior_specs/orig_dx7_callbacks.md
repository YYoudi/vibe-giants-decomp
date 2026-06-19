# Original 21 engine→renderer callbacks — RUNTIME-OBSERVED vanilla addresses (bit-exact oracle)

**Source**: proxy_dx7 (gg_dx7r.dll replacement, forward-only) captured
`UpCallsLoad(version=0x2775, count=21, table=005dc8e0)` on the ORIGINAL. Log: `giants_dx7_proxy.log`.
**Captured**: 2026-06-19. RUNTIME OBSERVATION (rule 5). These are the GROUND-TRUTH vanilla addresses
the recomp's `VanillaRenderer.cpp` callback table must match for bit-exact parity.

## The 21 vanilla callback addresses (all in vanilla .text 0x401000–0x551c50 ✓)
```
callback[ 0] = 0051d890   callback[ 7] = 004a1320   callback[14] = 0051e7a0
callback[ 1] = 00523ad0   callback[ 8] = 004a1340   callback[15] = 0053a2b0
callback[ 2] = 00429100   callback[ 9] = 0050dd10   callback[16] = 0053a090
callback[ 3] = 00542410   callback[10] = 0050e360   callback[17] = 00539f00   ← VFSOpenFile
callback[ 4] = 0051d860   callback[11] = 0050d7f0   callback[18] = 00521a20
callback[ 5] = 0051eca0   callback[12] = 0040d430   callback[19] = 00521a40
callback[ 6] = 00523b50   callback[13] = 00510fb0   callback[20] = 00523aa0
```
- `UpCallsLoad` vanilla export = `0x1000c790` (in gg_dx7r.dll), `GDVSysCreate` = `0x10002dc0`.
- `callback[17]=00539f00` (VFSOpenFile) — the engine's VFS open. `FUN_00539e30` (the open-by-name I
  Frida-hooked, see `orig_vfsopen.md`) is 0xD0 below it — a sibling VFS function; both vanilla.
- **Recomp must register these same 21 functions** at these addresses (or equivalent ports) for the
  proxy dual-mode 0-mismatch oracle.

## KNOWN BUG — proxy GDVSysCreate HANGS when deployed (2026-06-19)
The proxy's lazy device-discovery + polling thread were added (commit 569f5ba), but when deployed
the original's `GDVSysCreate` (forwarded to g_realGDVSysCreate) now reliably HANGS — it's entered
and never returns (`detach total frames captured: 0`), every attempt. The hang is PROXY-SPECIFIC
(the real renderer launches fine without the proxy). Likely a loader-lock / DX7-state issue from
the proxy's DllMain LoadLibraryA or repeated force-killed runs leaving a leaked device. The
render-recipe capture is therefore blocked until a clean system state (reboot) or the loader-lock
issue is fixed.

## Rule-11 — the recomp callback TABLE LABELS are 1.5-mislabeled (not the vanilla semantics)
The recomp's `callbacks[21]` in VanillaRenderer.cpp uses the 1.5-era giants-proxy labels. Vanilla
callbacks have DIFFERENT semantics. Verified from vanilla_decompiled:
- **callback[12] = 0040d430 = CAMERA-STATE accessor, NOT TextureLoader**. It copies 6 globals:
  DAT_005561a4/a8/ac = camera POSITION, DAT_005561b0/b4/b8 = camera ANGLES (see FUN_0040d560 /
  FUN_0040d9f0 which compute view matrices from these). The recomp's `callback[12]=Stub_Void`
  returns no camera state.
- **callback[13] = 00510fb0 = SinCosLookup ✓** (takes param+2 float out ptrs, uses __ftol) — matches
  the 1.5 label.
- callback[0] = 0051d890 = wvsprintfA varargs string formatter (debug print).
- callback[1] = 00523ad0 = init-once guard (DAT_005dca58) + FUN_00523700.
The recomp table should be relabeled/reimplemented per VANILLA semantics (camera accessor for [12],
etc.), not the 1.5 table.

## GAP — 6 of the 21 vanilla callbacks are MISSING from vanilla_decompiled
These addresses were captured at runtime (valid, called) but have NO JSON in vanilla_decompiled
(the Ghidra export missed them — likely thunks or undefined functions):
0050dd10 [9], 00539f00 [17 VFSOpenFile], 0053a090 [16], 0053a2b0 [15], 004a1320 [7], 004a1340 [8].
To port them faithfully: re-export from Ghidra at those addresses, or disassemble directly from
Giants_nocd.exe. (callback[17]=00539f00 is the VFS open-by-name wrapper; FUN_00539e30 — Frida-hooked
in orig_vfsopen.md — is its sibling 0xD0 below.)

## KNOWN BUG — proxy D3D7 per-frame trace captured 0 frames
The proxy's `InstallD3D7Hooks` assumed the wrapper device is at `obj+0x294` (a 1.5-era offset). In
vanilla the "WRAPPER VTABLE DUMP" came back EMPTY and `total frames captured: 0` — the offset is
wrong for vanilla, so the hooks landed on garbage and never fired. **Rule 11**: the proxy's
device-offset is a stale 1.5 assumption → re-verify the vanilla wrapper/device offset before the
D3D7 trace (SetTexture/SetTransform/DrawPrimitive per-frame recipe) can be captured.

## To capture the menu render recipe (next)
Either (a) fix the proxy's vanilla wrapper offset (find where vanilla stores the IDirect3DDevice7*
— re-read the vanilla GDVSysCreate/CreateDevice path in vanilla_decompiled), or (b) Frida-hook the
D3D7 device vtable directly: grab the device pointer from the CreateDevice return, read its vtable,
hook DrawPrimitive@0x64 / SetTexture@0x8c / SetTransform@0x2c. The render recipe = the bridge from
"observed assets" to "observed rendering" (needed for faithful logo framing/camera).
