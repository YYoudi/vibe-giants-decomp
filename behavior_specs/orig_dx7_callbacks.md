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
