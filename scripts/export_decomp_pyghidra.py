#!/usr/bin/env python3
"""Full decompilation export of the GOG144 project via pyghidra.
Same outputs as scripts/decompile_all.java: all_decompiled.c, index.json,
stats.txt in the target dir.

Usage: python scripts/export_decomp_pyghidra.py [out_dir]
Default out_dir: decompiled/gog144_full
"""
import json, os, sys, time

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.app.decompiler import DecompInterface, DecompileOptions

OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "decompiled", "gog144_full")
os.makedirs(OUT, exist_ok=True)

project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
try:
    program = project.openProgram("/", "Giants.exe", True)  # read-only is fine for decomp
    fm = program.getFunctionManager()

    di = DecompInterface()
    di.setOptions(DecompileOptions())
    di.openProgram(program)

    big = open(os.path.join(OUT, "all_decompiled.c"), "w", encoding="utf-8")
    idx = {}
    done = failed = named = 0
    vmin, vmax = 1 << 62, 0
    t0 = time.time()
    it = fm.getFunctions(True)
    while it.hasNext():
        fn = it.next()
        if fn.isThunk() or fn.isExternal():
            continue
        ep = fn.getEntryPoint().getOffset()
        vmin, vmax = min(vmin, ep), max(vmax, ep)
        name = fn.getName()
        if not name.startswith("FUN_"):
            named += 1
        res = di.decompileFunction(fn, 60, None)
        if not res.decompileCompleted():
            res = di.decompileFunction(fn, 240, None)  # big-function retry
        c = res.getDecompiledFunction().getC() if res.decompileCompleted() else "// DECOMPILE FAILED\n"
        if not res.decompileCompleted():
            failed += 1
        big.write(f"/* ===== {name} @ 0x{ep:08X} ===== */\n{c}\n\n")
        idx[f"0x{ep:08X}"] = {"name": name, "named": named > 0 and not name.startswith("FUN_"), "len": len(c)}
        done += 1
        if done % 200 == 0:
            print(f"  {done} (failed={failed} named={named}) elapsed={time.time()-t0:.0f}s", flush=True)
            big.flush()
    big.close()
    json.dump(idx, open(os.path.join(OUT, "index.json"), "w", encoding="utf-8"), indent=1)
    stats = (f"total_nonthunk={done} done={done} failed={failed} named={named} "
             f"({100.0*named/max(1,done):.1f}%) skipped_gt_maxva=0 "
             f"va_range=0x{vmin:X}..0x{vmax:X}\n")
    open(os.path.join(OUT, "stats.txt"), "w", encoding="utf-8").write(stats)
    print("DONE", stats.strip())
finally:
    project.close()
