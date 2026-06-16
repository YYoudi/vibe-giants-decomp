#!/usr/bin/env python3
"""Disassemble a function in gg_dx7r.dll, annotating IAT import calls.
Annotates COM vtable calls like `call dword ptr [eax+0x24]` with the candidate
D3D7/DDraw7 vtable index (heuristic, for human review).

Usage: python dx7_disasm.py <RVA-hex-or-0xVA> [size_hex]
"""
import struct, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

DLL = r"G:\GiantsRE\GameFiles-VanillaV1\gg_dx7r.dll"
BASE = 0x10000000

data = open(DLL, "rb").read()
e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
pe = e_lfanew
num_sections = struct.unpack_from("<H", data, pe+6)[0]
size_opt = struct.unpack_from("<H", data, pe+20)[0]
sections_off = pe + 24 + size_opt
secs = []
for i in range(num_sections):
    off = sections_off + i*40
    vaddr = struct.unpack_from("<I", data, off+12)[0]
    vsize = struct.unpack_from("<I", data, off+8)[0]
    roff  = struct.unpack_from("<I", data, off+20)[0]
    rsize = struct.unpack_from("<I", data, off+16)[0]
    secs.append((vaddr, vsize, roff, rsize))

def rva_to_off(rva):
    for va_, vs, ro, rs in secs:
        if va_ <= rva < va_ + max(vs, rs):
            return ro + (rva - va_)
    return None

def va_to_off(v):
    return rva_to_off(v - BASE)

# Walk import directory properly.
opt_off = e_lfanew + 24
idata_dir_off = opt_off + 104  # data dir[1] = import
imp_rva = struct.unpack_from("<I", data, idata_dir_off)[0]

iat = {}  # VA -> "dll!func"
o = rva_to_off(imp_rva)
while True:
    if o is None: break
    fields = struct.unpack_from("<5I", data, o)
    if all(f == 0 for f in fields): break
    orig_first, tdate, tname_rva, iat_thunk_rva = fields[0], fields[1], fields[2], fields[3]
    if tname_rva == 0: break
    dnoff = rva_to_off(tname_rva)
    end = data.index(b"\x00", dnoff)
    dll = data[dnoff:end].decode("latin1")
    ilt = orig_first if orig_first else iat_thunk_rva
    ilt_off = rva_to_off(ilt)
    idx = 0
    while ilt_off is not None:
        ent = struct.unpack_from("<I", data, ilt_off + idx*4)[0]
        if ent == 0: break
        iat_va = BASE + iat_thunk_rva + idx*4
        if ent & 0x80000000:
            iat[iat_va] = f"{dll}#{ent & 0xffff}"
        else:
            noff = rva_to_off(ent & 0x7fffffff)
            if noff is None:
                idx += 1; continue
            fend = data.index(b"\x00", noff+2)
            iat[iat_va] = f"{dll}!{data[noff+2:fend].decode('latin1')}"
        idx += 1
    o += 20

# D3D7 vtable indices (IDirect3DDevice7) — index*4 = byte offset
D3D7 = {
    0:"QueryInterface",1:"AddRef",2:"Release",
    3:"GetCaps",4:"GetStats",5:"AddViewport",6:"DeleteViewport",7:"BeginScene",
    8:"EndScene",9:"GetDirect3D",10:"SetRenderTarget",11:"GetRenderTarget",
    12:"Clear",13:"SetTransform",14:"GetTransform",15:"SetViewport",16:"MultiplyTransform",
    17:"GetViewport",18:"SetMaterial",19:"GetMaterial",20:"SetLight",21:"GetLight",
    22:"SetRenderState",23:"GetRenderState",24:"BeginStateBlock",25:"EndStateBlock",
    26:"CaptureStateBlock",27:"ApplyStateBlock",28:"DeleteStateBlock",29:"CreateStateBlock",
    30:"Load",31:"LightEnable",32:"GetCreateFlags",33:"EnumTextureFormats",
    34:"GetDirect3D2",35:"ValidateDevice",36:"SetTexture",37:"GetTexture",
    38:"GetTextureStageState"  # actually part of stage state set/get in 7
}
# IDirectDrawSurface7
DDS7 = {
    0:"QueryInterface",1:"AddRef",2:"Release",3:"AddAttachedSurface",
    4:"AddOverlayDirtyRect",5:"Blt",6:"BltBatch",7:"BltFast",8:"DeleteAttachedSurface",
    9:"EnumAttachedSurfaces",10:"EnumOverlayZOrders",11:"Flip",12:"GetAttachedSurface",
    13:"GetBltStatus",14:"GetCaps",15:"GetClipper",16:"GetColorKey",17:"GetDC",
    18:"GetDC2",19:"GetFlipStatus",20:"GetOverlayPosition",21:"GetPalette",
    22:"GetPixelFormat",23:"GetSurfaceDesc",24:"Initialize",25:"IsLost",
    26:"Lock",27:"ReleaseDC",28:"Restore",29:"SetClipper",30:"SetColorKey",
    31:"SetOverlayPosition",32:"SetPalette",33:"Unlock",34:"UpdateOverlay",
    35:"UpdateOverlayZOrder",36:"GetDDInterface",37:"PageLock",38:"PageUnlock",
    39:"SetSurfaceDesc",40:"SetPrivateData",41:"GetPrivateData",42:"FreePrivateData",
    43:"GetUniquenessValue",44:"ChangeUniquenessValue",45:"SetPriority",
    46:"GetPriority",47:"SetLOD",48:"GetLOD"
}
# IDirectDraw7 (after IUnknown)
DD7 = {
    0:"QueryInterface",1:"AddRef",2:"Release",3:"Compact",
    4:"CreateClipper",5:"CreatePalette",6:"CreateSurface",7:"DuplicateSurface",
    8:"EnumDisplayModes",9:"EnumSurfaces",10:"FlipToGDISurface",11:"GetCaps",
    12:"GetDisplayMode",13:"GetFourCCCodes",14:"GetGDISurface",15:"GetMonitorFrequency",
    16:"GetScanLine",17:"GetVerticalBlankStatus",18:"Initialize",19:"RestoreAllSurfaces",
    20:"SetCooperativeLevel",21:"SetDisplayMode",22:"WaitForVerticalBlank",
    23:"GetAvailableVidMem",24:"GetSurfaceFromDC",25:"RestoreDrawingSurface",
    26:"CreateEx",27:"GetDeviceIdentifier",28:"StartModeTest",29:"EvaluateMode"
}

def com_annot(reg, off):
    idx = off // 4
    cands = []
    if off in (0,4,8) or idx in (0,1,2):
        cands.append("IUnknown:"+"QueryInterface,AddRef,Release"[idx*0:][:0] or "QI/AR/Rel")
    if reg in ("eax","ecx","edx","ebx","esi","edi"):
        pass
    # provide all 3 since we don't know the interface type
    return f"D3D7[{idx}]={D3D7.get(idx,'?')} | DDS7[{idx}]={DDS7.get(idx,'?')} | DD7[{idx}]={DD7.get(idx,'?')}"

def main():
    arg = sys.argv[1]
    va = int(arg, 16) if arg.startswith("0x") else int("0x"+arg, 16)
    if va < BASE:  # treat as RVA
        va = BASE + va
    SIZE = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
    fileoff = va_to_off(va)
    if fileoff is None:
        print(f"# ERROR: VA 0x{va:x} not mapped"); return
    code = data[fileoff:fileoff+SIZE]
    print(f"# VA=0x{va:x} RVA=0x{va-BASE:x} fileoff=0x{fileoff:x} size={SIZE}")
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    ret_count = 0
    for ins in md.disasm(code, va):
        annot = ""
        if ins.mnemonic == "call" and ins.op_str.startswith("dword ptr ["):
            s = ins.op_str.split("[")[1].rstrip("]")
            try:
                imm = int(s, 16)
                if imm in iat:
                    annot = f"  ; IAT -> {iat[imm]}"
                else:
                    # COM vtable call: [reg+0xNN]
                    if "+" in s:
                        parts = s.split("+")
                        reg = parts[0].strip()
                        off = int(parts[1].rstrip("]"), 16) if parts[1].rstrip("]").startswith("0x") else int(parts[1].rstrip("]"), 16)
                        annot = f"  ; COM {com_annot(reg, off)}"
                    elif s in ("eax","ecx","edx","ebx","esi","edi"):
                        annot = "  ; COM call [reg] (vtable[0])"
            except Exception as e:
                pass
        print(f"0x{ins.address-BASE:08x}: {ins.mnemonic:8s} {ins.op_str}{annot}")
        if ins.mnemonic == "ret":
            ret_count += 1
            if ret_count >= 2:
                break

if __name__ == "__main__":
    main()
