# DX7 Renderer Reverse — gg_dx7r.dll::GDVSysCreate (vanilla, 127KB)

PE: .text rva 0x1000 (0x16000), .rdata 0x17000, .data 0x19000. base 0x10000000.
Imports: ddraw.dll (DirectDrawCreateEx, DirectDrawEnumerateExA), gdi32 (ExtTextOutA = GDI text),
kernel32, user32. NO d3d8/9, NO COM/registry/IID strings.

## GDVSysCreate @ RVA 0x2dc0 (export ordinal 1)

Signature (cdecl, captured via Frida): `GDVSysCreate(cmdLine, hWnd, dispCfg, winCfg, modeCfg, engineCtx=NULL)`.
**engineCtx is NULL in vanilla** (no COM registry — confirmed).

Body:
1. `HeapAlloc(0x57c)` → renderer object `esi` (zeroed, 0x15f dwords).
2. Sets linked-list nodes: `[esi+0xec]` self-ref, `[esi+0xf0]`→`[esi+0xec]`; `[esi+0xe8]`→`[esi+0xe4]`.
3. Sets the renderer interface — a TYPE TAG `[esi]=0x10004420` (code addr as marker, NOT a
   vtable; reading it yields x86 code) + ~40 method pointers at fixed offsets:
   ```
   [esi+0x04]=0x10003090  [esi+0x08]=0x100042c0  [esi+0x0c]=0x10003490  [esi+0x10]=0x10002d80
   [esi+0x14]=0x100042d0  [esi+0x18]=0x10003e60  [esi+0x1c]=0x10003ea0  [esi+0x20]=0x10003ee0
   [esi+0x24]=0x10003f90  [esi+0x28]=0x10003fe0  [esi+0x2c]=0x10004000  [esi+0x30]=0x10004020
   [esi+0x34]=0x10004040  [esi+0x38]=0x10004130  [esi+0x3c]=0x10004070  [esi+0x40]=0x10004120
   [esi+0x44]=0x10004200  [esi+0x48]=0x10004240  [esi+0x4c]=0x10004180  [esi+0x50]=0x10002d40
   [esi+0x54]=0x10004270  [esi+0x58]=0x10004290  [esi+0x5c]=0x100042f0
   [esi+0x60..0x98]= more methods (0x1000c880, 0x1000c9d0, 0x100079c0, 0x10007bc0, 0x100086a0...)
   ```
4. Returns `esi` (the renderer object). **Does NOT call DirectDrawCreateEx itself** — device
   creation happens in one of the object's methods the engine invokes later.

## Contract (minimal engine→renderer, vanilla DX7)

- **UpCallsLoad(0x2775, 21, table)** — 21 cdecl callbacks (see dx7-minimal-contract memory).
- **GDVSysCreate(cmdLine, hWnd, dispCfg, winCfg, modeCfg, NULL)** → renderer object (0x57c bytes,
  ~40 method pointers). engineCtx=NULL (no COM registry).
- The engine drives the object's methods (one creates the DirectDraw device via
  DirectDrawCreateEx; others BeginScene/Clear/Present/etc.). Render-method offsets match the
  stable DX7→DX9 interface (vt41/42/43/47 in 1.5; same semantic slots in DX7).

## Implication for the fresh DX12 renderer
Reproduce this minimal contract: GDVSysCreate allocates a renderer object exposing the ~40
method slots the engine calls; the methods build a D3D12 device (instead of DirectDraw) and
render. The 21 UpCalls callbacks provide engine services (strings, VFS, dealloc, trig, etc.).
**No COM registry, no engine-context object** — just 21 callbacks + a method-table object.

## Next
- Capture the vanilla per-frame render sequence (which object method offsets the engine calls)
  via Frida — confirms the method-slot → semantic (BeginScene/Clear/Present) mapping for DX7.
- Then the DX12 renderer reproduces the object + 21 callbacks + those method slots in D3D12.
