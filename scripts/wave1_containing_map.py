#!/usr/bin/env python3
"""Resolve wave-1 PS2 match addresses to their CONTAINING functions in the
current v1.0 Ghidra project (GiantsRE), opening the EXISTING analyzed program.
Output: ps2_symbols/wave1_containing.csv  wave1_addr,cont_addr,cont_name
"""
import csv, os

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject

project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects"), "GiantsRE", True)
try:
    program = project.openProgram("/", "Giants.exe", True)  # readOnly
    fm = program.getFunctionManager()
    af = program.getAddressFactory().getDefaultAddressSpace()

    w1 = [r["pc_addr"] for r in csv.DictReader(
        open(os.path.join(REPO, "ps2_symbols", "pc_ps2_matches_full.csv"), encoding="utf-8"))]
    rows = []
    seen = {}
    unresolved = 0
    for a in w1:
        addr = af.getAddress("0x" + a.lstrip("0").zfill(8))
        fn = fm.getFunctionContaining(addr)
        if fn is None:
            unresolved += 1
            continue
        c = fn.getEntryPoint().toString()[2:]
        seen.setdefault(c, fn.getName())
        rows.append({"wave1_addr": a, "cont_addr": c, "cont_name": fn.getName()})
    print(f"resolved {len(rows)}/{len(w1)} wave-1 addrs -> {len(seen)} unique containing functions (unresolved {unresolved})")
    out = os.path.join(REPO, "ps2_symbols", "wave1_containing.csv")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["wave1_addr", "cont_addr", "cont_name"])
        w.writeheader(); w.writerows(rows)
    print(f"wrote {out}")
finally:
    project.close()
