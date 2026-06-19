#!/usr/bin/env python3
# Disassemble a function in Giants_nocd.exe (vanilla 1.0) by VA. Fills the vanilla_decompiled gap
# (Ghidra export missed ~8 functions: continuations/thunks/callbacks). Usage: disasm_exe.py <hexVA> [size] [endVA]
# Stops at first 'ret' unless endVA given. ImageBase=0x400000.
import struct, sys
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = r"G:\GiantsRE\GameFiles-VanillaV1\Giants_nocd.exe"
BASE = 0x400000

def main():
    if len(sys.argv) < 2:
        print("usage: disasm_exe.py <hexVA> [size=0x200] [endVA]"); return
    va = int(sys.argv[1], 16)
    size = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
    endva = int(sys.argv[3], 16) if len(sys.argv) > 3 else None
    data = open(EXE, "rb").read()
    e = struct.unpack_from("<I", data, 0x3C)[0]
    ns = struct.unpack_from("<H", data, e+6)[0]; so = struct.unpack_from("<H", data, e+20)[0]
    off = e+24+so; secs = []
    for i in range(ns):
        o = off+i*40
        rva = struct.unpack_from("<I", data, o+12)[0]; vs = struct.unpack_from("<I", data, o+8)[0]
        ra = struct.unpack_from("<I", data, o+20)[0]; secs.append((rva, vs, ra))
    r = va - BASE; fo = None
    for rva, vs, ra in secs:
        if rva <= r < rva+vs: fo = ra + (r-rva); break
    if fo is None:
        print("VA 0x%x not in any section" % va); return
    md = Cs(CS_ARCH_X86, CS_MODE_32)
    out = []
    for ins in md.disasm(data[fo:fo+size], va):
        out.append("0x%06x: %s %s" % (ins.address, ins.mnemonic, ins.op_str))
        if endva and ins.address >= endva: break
        if endva is None and ins.mnemonic == "ret": break
    print("\n".join(out))

if __name__ == "__main__":
    main()
