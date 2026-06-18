# DX7 Wrapper = standard IDirect3DDevice7 (D3DIM700.DLL) — AUTHORITATIVE

**BREAKTHROUGH 2026-06-18.** The "wrapper" at `renderer_obj + 0x294` is a stock
`IDirect3DDevice7` COM object whose vtable lives entirely in **D3DIM700.DLL**
(the DirectX 7 D3D Implementor module). Every slot resolves there via
`GetModuleHandleEx` (see `proxy_dx7/dx7_proxy_main.cpp` module-resolved dump).

This kills the long-running "0x63xxxxx mystery": that base WAS D3DIM700.DLL
(rebases per-run, e.g. 0x643b0000). The wrapper is NOT a custom vtable — its
indices are the canonical `IDirect3DDevice7` order from `d3d.h`.

## Authoritative slot map (byte offset → method → D3DIM700 offset observed)

Verified against `/c/msys64/mingw32/include/d3d.h` DECLARE_INTERFACE_(IDirect3DDevice7)
order + live proxy dump. Index = byte_offset/4.

| Offset | Idx | Method                 | D3DIM700+  | Notes |
|--------|-----|------------------------|-----------|-------|
| 0x00   | 0   | QueryInterface         | 0x13ea0   | |
| 0x04   | 1   | AddRef                 | 0x13f30   | |
| 0x08   | 2   | Release                | 0x13f60   | |
| 0x0c   | 3   | GetCaps                | 0x57c0    | |
| 0x10   | 4   | EnumTextureFormats     | 0x5810    | |
| **0x14** | 5 | **BeginScene**         | 0x5940    | ✓ old Frida correct |
| **0x18** | 6 | **EndScene**           | 0x5c10    | ✓ |
| 0x1c   | 7   | GetDirect3D            | 0x5f10    | |
| 0x20   | 8   | SetRenderTarget        | 0xa1b0    | |
| 0x24   | 9   | GetRenderTarget        | 0xa580    | |
| **0x28** |10 | **Clear**              | 0x12f90   | ✗ OLD CODE MISCALLED THIS "DrawPrimitive" |
| **0x2c** |11 | **SetTransform**       | 0x9e50    | ✓ old correct |
| 0x30   | 12  | GetTransform           | 0x9ee0    | |
| 0x34   | 13  | SetViewport            | 0x12ed0   | |
| 0x38   | 14  | MultiplyTransform      | 0xad60    | |
| 0x3c   | 15  | GetViewport            | 0x12f50   | |
| 0x40   | 16  | SetMaterial            | 0x13670   | |
| 0x44   | 17  | GetMaterial            | 0x136e0   | |
| 0x48   | 18  | SetLight               | 0x13880   | |
| 0x4c   | 19  | GetLight               | 0x138f0   | |
| **0x50** |20 | **SetRenderState**     | 0x9630    | ✓ old correct |
| 0x54   | 21  | GetRenderState         | 0x9780    | |
| 0x58   | 22  | BeginStateBlock        | 0xae80    | |
| 0x5c   | 23  | EndStateBlock          | 0xaf50    | |
| 0x60   | 24  | PreLoad                | 0x6140    | |
| **0x64** |25 | **DrawPrimitive**      | 0x11f50   | ✗✓ WAS UNMAPPED → now known (terrain uses it, hr=0) |
| 0x68   | 26  | DrawIndexedPrimitive   | 0x12040   | |
| 0x6c   | 27  | SetClipStatus          | 0xa5f0    | |
| 0x70   | 28  | GetClipStatus          | 0xa670    | |
| 0x74   | 29  | DrawPrimitiveStrided   | 0x11c50   | |
| 0x78   | 30  | DrawIndexedPrimStrided | 0x11dc0   | |
| 0x7c   | 31  | DrawPrimitiveVB        | 0x10c90   | |
| 0x80   | 32  | DrawIndexedPrimitiveVB | 0x108d0   | (hot 54K calls — VB path) |
| 0x84   | 33  | ComputeSphereVisibility| 0x12730   | |
| 0x88   | 34  | GetTexture             | 0x9850    | |
| **0x8c** |35 | **SetTexture**         | 0x9970    | ★ THE MISSING SLOT — unblocks textured render |
| 0x90   | 36  | GetTextureStageState   | 0x9b60    | |
| **0x94** |37 | **SetTextureStageState**| 0x9aa0   | ✓ old correct |
| 0x98   | 38  | ValidateDevice         | 0xe7c0    | |
| 0x9c   | 39  | ApplyStateBlock        | 0xb180    | |
| 0xa0   | 40  | CaptureStateBlock      | 0xb1d0    | |
| 0xa4   | 41  | DeleteStateBlock       | 0xb070    | |
| 0xa8   | 42  | CreateStateBlock       | 0xb250    | |
| 0xac   | 43  | Load                   | 0x6260    | |
| 0xb0   | 44  | LightEnable            | 0x13ab0   | |
| 0xb4   | 45  | GetLightEnable         | 0x13b30   | |
| 0xb8   | 46  | SetClipPlane           | 0xb910    | |
| 0xbc   | 47  | GetClipPlane           | 0xb9a0    | |
| 0xc0   | 48  | GetInfo                | 0x14b50   | |

## Calling convention
All D3D7 device methods are **`__stdcall`** (thiscall on the COM ptr is the 1st arg):
`HRESULT method(IDirect3DDevice7* this, ...)`. NOT `__cdecl` (unlike the renderer's
own front-table methods + the 21 UpCalls callbacks, which ARE cdecl).

## Key signatures
```
DrawPrimitive(this, D3DPRIMITIVETYPE prim, DWORD fvf, void* verts, DWORD vertCount, DWORD flags)
  prim: 1=POINTLIST 2=LINELIST 3=TRIANGLELIST 4=TRIANGLESTRIP ...
SetTexture(this, DWORD stage, IDirectDrawSurface7* texture)
SetTextureStageState(this, DWORD stage, D3DTEXTURESTAGESTATETYPE type, DWORD value)
  type: 1=COLOROP 2=COLORARG1 3=COLORARG2 ...
  COLOROP value: 1=DISABLE 2=SELECTARG1 3=SELECTARG2 4=MODULATE ...
  COLORARG value: 0=DIFFUSE 1=CURRENT 2=TEXTURE 3=TPF ...
Clear(this, DWORD count, D3DRECT* rects, DWORD flags, D3DCOLOR color, float z, DWORD stencil)
SetTransform(this, D3DTRANSFORMSTATETYPE state, D3DMATRIX* matrix)
```

## Bugs this corrects
1. **Logo DrawPrimitive E_INVALIDARG (0x80070057)**: was calling slot **0x28 (Clear)**
   with DrawPrimitive-style args → garbage rect count/flags → rejected. Fixed: use **0x64**.
   Verified: hr=0x0, gold logo triangles now render.
2. **"Terrain DrawPrimitive at vt[0x28]"** in old notes was a mislabel — terrain already
   migrated to 0x64 (VanillaTerrain.cpp:234) and succeeds. The 0x28 = Clear confusion is
   why earlier texturing experiments on "DrawPrimitive(0x28)" produced nothing.

## NEXT (unblocked)
- **Textured terrain**: call `SetTexture(wrapper, 0, <IDirectDrawSurface7* of intro_grnd>)`
  at slot **0x8c** before DrawPrimitive. Need the texture's D3D7 surface handle — the
  renderer's +0xb4 (BindTexture, front-table) registers textures in an internal table;
  the actual surface ptr to feed D3D7 SetTexture must be captured from the ORIGINAL via
  the proxy (hook 0x8c on the original → log the surface ptr per draw). That oracle trace
  is the exact sequence to reproduce.
