#!/usr/bin/env python3
"""Dump {ps2_function_entry -> [string literals]} from the already-analyzed
PS2 Ghidra project, via pyghidra (no OSGi script bundles).
Output: ps2_symbols/ps2_string_refs.json  (addr hex -> list of strings)
"""
import json, os, sys

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

OUT = os.path.join(REPO, "ps2_symbols", "ps2_string_refs.json")

with pyghidra.open_program(
        os.path.join(REPO, "ps2_symbols", "SLUS_201.78"),
        project_location=os.path.join(REPO, "ghidra_projects"),
        project_name="PS2",
        analyze=False) as flat:
    program = flat.getCurrentProgram()
    listing = program.getListing()
    fm = program.getFunctionManager()
    rm = program.getReferenceManager()

    strmap = {}
    it = listing.getDefinedData(True)
    n = 0
    while it.hasNext():
        d = it.next()
        v = d.getValue()
        if isinstance(v, str) and len(v) >= 4:
            strmap[d.getAddress().toString()] = v
            n += 1
    print(f"defined strings: {n}")

    fmap = {}
    nref = 0
    rit = rm.getReferenceIterator(program.getMinAddress())
    while rit.hasNext():
        r = rit.next()
        s = strmap.get(r.getToAddress().toString())
        if s is None:
            continue
        fn = fm.getFunctionContaining(r.getFromAddress())
        if fn is None or fn.isThunk() or fn.isExternal():
            continue
        key = fn.getEntryPoint().toString()
        fmap.setdefault(key, [])
        if s not in fmap[key]:
            fmap[key].append(s)
        nref += 1
    print(f"string refs into functions: {nref} across {len(fmap)} functions")

json.dump(fmap, open(OUT, "w", encoding="utf-8"))
print(f"wrote {OUT}")
