#!/usr/bin/env python3
"""Dump function name table + call edges (no decompile) for fast re-analysis."""
import json, os, sys
os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
import pyghidra
pyghidra.start()
from ghidra.base.project import GhidraProject

project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
try:
    program = project.openProgram("/", "Giants.exe", True)
    fm = program.getFunctionManager()
    names, callees, callers = {}, {}, {}
    it = fm.getFunctions(True)
    while it.hasNext():
        fn = it.next()
        if fn.isThunk() or fn.isExternal(): continue
        ep = '0x%08X' % fn.getEntryPoint().getOffset()
        names[ep] = fn.getName()
        for c in fn.getCalledFunctions(None):
            if not c.isExternal() and not c.isThunk():
                ce = '0x%08X' % c.getEntryPoint().getOffset()
                callees.setdefault(ep, set()).add(ce)
                callers.setdefault(ce, set()).add(ep)
    json.dump(names, open(os.path.join(REPO, 'graph_names.json'), 'w'), indent=0)
    json.dump({k: sorted(v) for k, v in callees.items()}, open(os.path.join(REPO, 'graph_callees.json'), 'w'))
    json.dump({k: sorted(v) for k, v in callers.items()}, open(os.path.join(REPO, 'graph_callers.json'), 'w'))
    print('funcs:', len(names), 'edges:', sum(len(v) for v in callees.values()))
finally:
    project.close()
