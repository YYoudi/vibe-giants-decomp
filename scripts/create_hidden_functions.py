#!/usr/bin/env python3
"""Create functions at class-spec-table pointers that Ghidra never analyzed.
Reads class_spec_table.json 'hidden' list; creates + names them cspec_<hex>.
"""
import os, sys, json
os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
import pyghidra
pyghidra.start()
from ghidra.base.project import GhidraProject
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.program.model.symbol import SourceType
from ghidra.util.task import ConsoleTaskMonitor
MON = ConsoleTaskMonitor()

d = json.load(open(os.path.join(REPO, "class_spec_table.json"), encoding="utf-8"))
hidden = [int(x, 16) for x in d["hidden"]]

project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
try:
    program = project.openProgram("/", "Giants.exe", False)
    from ghidra.app.decompiler import DecompInterface, DecompileOptions
    fm = program.getFunctionManager()
    af = program.getAddressFactory().getDefaultAddressSpace()
    created = existed = failed = 0
    tx = program.startTransaction("create cspec functions")
    try:
        for v in hidden:
            addr = af.getAddress(hex(v))
            fn = fm.getFunctionContaining(addr)
            if fn is not None and fn.getEntryPoint().getOffset() == v:
                existed += 1
                continue
            ok = CreateFunctionCmd(addr).applyTo(program, MON)
            fn = fm.getFunctionContaining(addr) if ok else None
            if fn is not None:
                try:
                    fn.setName(f"cspec_{v:08x}", SourceType.USER_DEFINED)
                except Exception:
                    pass
                created += 1
            else:
                failed += 1
        program.endTransaction(tx, True)
    except Exception:
        program.endTransaction(tx, False)
        raise
    program.flushEvents()
    project.save(program)
    print(f"created={created} existed={existed} failed={failed}")
finally:
    project.close()
