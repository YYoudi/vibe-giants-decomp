#!/usr/bin/env python3
"""One shard of the parallel decomp export (internal worker, not a CLI).
Env/argv: <out_dir> <lo_hex> <hi_hex> <shard_json>
Opens the GOG144 project read-only, decompiles functions in [lo,hi),
writes [{"addr":int,"name":str,"c":str}, ...] to shard_json.
"""
import json, os, sys

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

OUT = sys.argv[1]
LO = int(sys.argv[2], 16)
HI = int(sys.argv[3], 16)
SHARD = sys.argv[4]

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.app.decompiler import DecompInterface, DecompileOptions

project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
try:
    program = project.openProgram("/", "Giants.exe", True)
    fm = program.getFunctionManager()
    di = DecompInterface()
    di.setOptions(DecompileOptions())
    di.openProgram(program)
    out = []
    it = fm.getFunctions(True)
    while it.hasNext():
        fn = it.next()
        if fn.isThunk() or fn.isExternal():
            continue
        ep = fn.getEntryPoint().getOffset()
        if not (LO <= ep < HI):
            continue
        res = di.decompileFunction(fn, 60, None)
        if not res.decompileCompleted():
            res = di.decompileFunction(fn, 240, None)
        c = res.getDecompiledFunction().getC() if res.decompileCompleted() else "// DECOMPILE FAILED\n"
        out.append({"addr": ep, "name": fn.getName(), "c": c})
    json.dump(out, open(SHARD, "w", encoding="utf-8"))
    print(f"shard [{LO:X},{HI:X}): {len(out)} functions")
finally:
    project.close()
