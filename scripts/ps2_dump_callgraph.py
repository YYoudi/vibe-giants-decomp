#!/usr/bin/env python3
"""Dump the PS2 call graph from the fixed Ghidra analysis:
{caller_entry: [callee_entry, ...]} — much better jal resolution than the
capstone word-by-word decoder.
Output: ps2_symbols/ps2_callgraph.json
"""
import json, os

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject

project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects"), "PS2", True)
try:
    program = project.openProgram("/", "SLUS_201.78", True)
    fm = program.getFunctionManager()
    af = program.getAddressFactory().getDefaultAddressSpace()

    graph = {}
    n = 0
    it = fm.getFunctions(True)
    while it.hasNext():
        fn = it.next()
        if fn.isThunk() or fn.isExternal():
            continue
        callees = set()
        for c in fn.getCalledFunctions(None):
            if c.isThunk():
                t = c.getCalledFunction(None)
                if t is not None:
                    callees.add(t.getEntryPoint().toString())
                    continue
            callees.add(c.getEntryPoint().toString())
        if callees:
            graph[fn.getEntryPoint().toString()] = sorted(callees)
            n += len(callees)
    print(f"callers: {len(graph)}, total edges: {n}")
    json.dump(graph, open(os.path.join(REPO, "ps2_symbols", "ps2_callgraph.json"), "w"))
    print("wrote ps2_symbols/ps2_callgraph.json")
finally:
    project.close()
