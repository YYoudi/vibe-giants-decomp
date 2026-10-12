#!/usr/bin/env python3
"""One-shot PS2 ELF fixer + string-ref dumper (pyghidra):
  1. disassemble every function body (analysis missed them all)
  2. re-run full analysis (constant-reference analyzer creates data refs)
  3. dump {function_entry -> [strings]} using an ELF byte-scan string map
  4. save the program so future runs skip steps 1-2
Output: ps2_symbols/ps2_string_refs.json
"""
import csv, json, os, struct

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

ELF = os.path.join(REPO, "ps2_symbols", "SLUS_201.78")
OUT = os.path.join(REPO, "ps2_symbols", "ps2_string_refs.json")

# ---- ELF string map (python side, independent of Ghidra string defs) --------
raw = open(ELF, "rb").read()
e = struct.unpack_from("<I", raw, 0x3C)[0] if raw[:4] == b"\x7fELF" else 0
# ELF header: e_shoff at 0x20, e_shentsize 0x2E, e_shnum 0x30, e_shstrndx 0x32
shoff = struct.unpack_from("<I", raw, 0x20)[0]
shentsize, shnum = struct.unpack_from("<HH", raw, 0x2E)
secs = []
for i in range(shnum):
    off = shoff + i * shentsize
    sh_type, _, sh_addr, sh_offset, sh_size = struct.unpack_from("<IIIII", raw, off + 4)
    secs.append((sh_addr, sh_offset, sh_size))

def runs(base, data):
    out = {}
    i = 0
    n = len(data)
    while i < n:
        j = i
        while j < n and 0x20 <= data[j] <= 0x7E:
            j += 1
        if j - i >= 4 and j < n and data[j] == 0:
            out[base + i] = data[i:j].decode("ascii", "replace")
        i = max(j + 1, i + 1)
    return out

strmap = {}
for sh_addr, sh_offset, sh_size in secs:
    if sh_addr and sh_size:
        strmap.update(runs(sh_addr, raw[sh_offset:sh_offset + sh_size]))
print(f"ELF printable strings: {len(strmap)}")

# ---- pyghidra session -------------------------------------------------------
with pyghidra.open_program(ELF,
                           project_location=os.path.join(REPO, "ghidra_projects"),
                           project_name="PS2",
                           analyze=False) as flat:
    program = flat.getCurrentProgram()
    fm = program.getFunctionManager()
    af = program.getAddressFactory().getDefaultAddressSpace()

    funcs = [(int(r["addr"], 16), int(r["size"]))
             for r in csv.DictReader(open(os.path.join(REPO, "ps2_symbols", "SLUS_201.78.symbols.csv"),
                                          encoding="utf-8"))
             if r["kind"] == "FUNC" and int(r["size"]) > 0]
    print(f"symtab functions: {len(funcs)}")

    listing = program.getListing()
    ndis = 0
    for addr, _size in funcs:
        a = af.getAddress(hex(addr))
        if listing.getInstructionAt(a) is None:
            if flat.disassemble(a):
                ndis += 1
    program.flushEvents()
    print(f"disassembled {ndis} new function starts")

    print("running analyzeAll (this takes a few minutes)...")
    flat.analyzeAll(program)
    program.flushEvents()
    print("analysis done; total instructions:", listing.getNumInstructions())

    fmap = {}
    nref = 0
    for addr, _size in funcs:
        fn = fm.getFunctionAt(af.getAddress(hex(addr)))
        if fn is None:
            continue
        ii = listing.getInstructions(fn.getBody(), True)
        ss = set()
        while ii.hasNext():
            ins = ii.next()
            for ref in ins.getReferencesFrom():
                s = strmap.get(ref.getToAddress().getOffset())
                if s:
                    ss.add(s)
        if ss:
            fmap[hex(addr)[2:]] = sorted(ss)
            nref += len(ss)
    print(f"functions with string refs: {len(fmap)} ({nref} refs)")
    json.dump(fmap, open(OUT, "w", encoding="utf-8"))
    print(f"wrote {OUT}")
    try:
        program.save("disassembled+analyzed", None)
        print("program saved")
    except Exception as ex:
        print("save skipped:", ex)
