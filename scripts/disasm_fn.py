#!/usr/bin/env python3
# Disassemble a function in gg_dx7r.dll by VA. Usage: disasm_fn.py <hexVA> [size]
import struct, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

DLL = r"G:\GiantsRE\GameFiles-VanillaV1\gg_dx7r.dll"
BASE = 0x10000000

va = int(sys.argv[1], 16) if sys.argv[1].startswith("0x") else int("0x"+sys.argv[1], 16)
SIZE = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x600

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

def va_to_off(v):
    rva = v - BASE
    for va_, vs, ro, rs in secs:
        if va_ <= rva < va_ + max(vs, rs):
            return ro + (rva - va_)
    return None

# resolve import names for [imm] calls into IAT
e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
opt_off = e_lfanew + 24
import_rva = struct.unpack_from("<I", data, opt_off + 104)[0]  # OPT import table rva
idata_dir_off = opt_off + 104
imp_rva = struct.unpack_from("<I", data, idata_dir_off)[0]
imp_size = struct.unpack_from("<I", data, idata_dir_off+4)[0]

def rva_to_off(rva):
    for va_, vs, ro, rs in secs:
        if va_ <= rva < va_ + max(vs, rs):
            return ro + (rva - va_)
    return None

# Build IAT name map: VA-of-IAT-entry -> "dll!func"
iat = {}
o = rva_to_off(imp_rva)
while True:
    ilt_rva = struct.unpack_from("<I", data, o)[0]
    iat_rva = struct.unpack_from("<I", data, o+12)[0]
    name_rva = struct.unpack_from("<I", data, o+12)[0]
    dll_name_rva = struct.unpack_from("<I", data, o+12)[0]
    orig_first = struct.unpack_from("<I", data, o)[0]
    name_rva2 = struct.unpack_from("<I", data, o+12)[0]
    if ilt_rva == 0 and struct.unpack_from("<I", data, o+16)[0] == 0:
        break
    ilt = struct.unpack_from("<I", data, o+0)[0]   # OriginalFirstThunk
    tname_rva = struct.unpack_from("<I", data, o+12)[0]  # Name
    iat_thunk_rva = struct.unpack_from("<I", data, o+16)[0]  # FirstThunk (IAT)
    # dll name
    dnoff = rva_to_off(tname_rva)
    end = data.index(b"\x00", dnoff)
    dll = data[dnoff:end].decode("latin1")
    # walk ILT
    ilt_off = rva_to_off(ilt) if ilt else rva_to_off(iat_thunk_rva)
    idx = 0
    while True:
        ent = struct.unpack_from("<I", data, ilt_off + idx*4)[0]
        if ent == 0: break
        iat_va = BASE + iat_thunk_rva + idx*4
        if ent & 0x80000000:
            iat[iat_va] = f"{dll}#{ent & 0xffff}"
        else:
            noff = rva_to_off(ent & 0x7fffffff)
            hint = struct.unpack_from("<H", data, noff)[0]
            fend = data.index(b"\x00", noff+2)
            iat[iat_va] = f"{dll}!{data[noff+2:fend].decode('latin1')}"
        idx += 1
    o += 20

fileoff = va_to_off(va)
code = data[fileoff:fileoff+SIZE]
print(f"# VA=0x{va:x} fileoff=0x{fileoff:x} size={SIZE}")
md = Cs(CS_ARCH_X86, CS_MODE_32)
ret_count = 0
for ins in md.disasm(code, va):
    annot = ""
    if ins.mnemonic == "call" and ins.op_str.startswith("dword ptr ["):
        try:
            imm = int(ins.op_str.split("[")[1].rstrip("]"), 16)
            if imm in iat:
                annot = f"  ; -> {iat[imm]}"
        except: pass
    print(f"0x{ins.address:08x}: {ins.mnemonic:8s} {ins.op_str}{annot}")
    if ins.mnemonic == "ret":
        ret_count += 1
        if ret_count >= 2:
            break
