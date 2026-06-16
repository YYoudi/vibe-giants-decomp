#!/usr/bin/env python3
# Disassemble gg_dx7r.dll::GDVSysCreate (RVA 0x2dc0) fully to find the NULL-return path.
import struct, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

DLL = r"G:\GiantsRE\GameFiles-VanillaV1\gg_dx7r.dll"
RVA = 0x2dc0
BASE = 0x10000000
SIZE = 0x400  # generous; GDVSysCreate object-setup is ~0x300 bytes

# Minimal PE parser to map RVA -> file offset
data = open(DLL, "rb").read()
e_lfanew = struct.unpack_from("<I", data, 0x3C)[0]
pe = e_lfanew
num_sections = struct.unpack_from("<H", data, pe+6)[0]
size_opt = struct.unpack_from("<H", data, pe+20)[0]
sections_off = pe + 24 + size_opt
secs = []
for i in range(num_sections):
    off = sections_off + i*40
    name = data[off:off+8].rstrip(b"\x00").decode("latin1")
    vsize = struct.unpack_from("<I", data, off+8)[0]
    vaddr = struct.unpack_from("<I", data, off+12)[0]
    rsize = struct.unpack_from("<I", data, off+16)[0]
    roff  = struct.unpack_from("<I", data, off+20)[0]
    secs.append((name, vaddr, vsize, roff, rsize))

def rva_to_off(rva):
    for n, va, vs, ro, rs in secs:
        if va <= rva < va + max(vs, rs):
            return ro + (rva - va)
    return None

fileoff = rva_to_off(RVA)
code = data[fileoff:fileoff+SIZE]
print(f"# GDVSysCreate RVA=0x{RVA:x} fileoff=0x{fileoff:x} disasm {SIZE} bytes")
md = Cs(CS_ARCH_X86, CS_MODE_32)
md.detail = True
for ins in md.disasm(code, BASE+RVA):
    print(f"0x{ins.address:08x}: {ins.mnemonic:8s} {ins.op_str}")
    # stop at first ret after some body (heuristic: stop if ret and address > start+0x30)
    if ins.mnemonic == "ret" and ins.address > BASE+RVA+0x20:
        # peek: continue a bit more to catch trailing, but GDVSysCreate likely single ret
        pass
