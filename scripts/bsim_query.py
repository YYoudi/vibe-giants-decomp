#!/usr/bin/env python3
"""Mass BSim query: match every 1.449 PC function against the BSim database
(which holds the named PS2 ELF signatures — cross-architecture via decompiler
IR features). Emits candidates where the best match is a PS2 function whose
name we can transfer.

Output: ps2_symbols/bsim_matches_1449.csv (apply-CSV format, conf = similarity
scaled by evidence — reviewed tier by tier)
"""
import csv, os, sys

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.features.bsim.query.facade import SimilarFunctionQueryService
from ghidra.features.bsim.query.facade import SFQueryInfo
from ghidra.features.bsim.gui.search.results import BSimMatchResult

DB_URL = "file:/G:/VibeRE/GiantsRE/bsim_db"
OUT = os.path.join(REPO, "ps2_symbols", "bsim_matches_1449.csv")

def main():
    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", True)
        fm = program.getFunctionManager()

        from java.util import HashSet
        funcs = HashSet()
        it = fm.getFunctions(True)
        while it.hasNext():
            fn = it.next()
            if not fn.isThunk() and not fn.isExternal():
                funcs.add(fn.getSymbol())

        service = SimilarFunctionQueryService(program)
        service.initializeDatabase(DB_URL)
        err = service.getLastError()
        if err is not None:
            print("db error:", err.message)
            return

        qi = SFQueryInfo(funcs)
        qi.setMaximumResults(3)
        qi.setSimilarityThreshold(0.5)   # cross-arch: keep the net wide
        qi.setSignificanceThreshold(0.0)
        res = service.querySimilarFunctions(qi, None, None)
        rows = BSimMatchResult.generate(res.getSimilarityResults(), program)
        print(f"functions with >=1 match: {rows.size()}")

        out = []
        for row in rows:
            orig = row.getOriginalFunctionDescription()
            match = row.getMatchFunctionDescription()
            mname = match.getFunctionName()
            exe = match.getExecutableRecord().getNameExec()
            if "SLUS" not in exe and "SLUS" not in exe.upper():
                continue                     # only PS2-origin matches
            sim = row.getSimilarity()
            addr = f"{int(orig.getAddress()):08x}"
            out.append({
                "pc_addr": addr.lower().lstrip("0x").rjust(8, "0"),
                "pc_name": orig.getFunctionName(),
                "ps2_addr": "",
                "ps2_name": mname.replace(",", "_"),
                "shared": "",
                "conf": round(sim, 3),
                "tier": f"bsim-sim{sim:.2f}",
            })
        # keep best (highest sim) per address
        best = {}
        for r in out:
            a = r["pc_addr"]
            if a not in best or r["conf"] > best[a]["conf"]:
                best[a] = r
        rows_sorted = sorted(best.values(), key=lambda r: -r["conf"])
        with open(OUT, "w", newline="", encoding="utf-8") as f:
            w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "shared", "conf", "tier"])
            w.writeheader(); w.writerows(rows_sorted)
        hi = sum(1 for r in rows_sorted if r["conf"] >= 0.8)
        print(f"BSim cross-arch candidates: {len(rows_sorted)} (sim>=0.8: {hi}) -> {OUT}")
        service.dispose()
    finally:
        project.close()

if __name__ == "__main__":
    main()
