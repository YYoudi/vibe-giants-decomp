#!/usr/bin/env python3
"""Apply PS2-derived signatures to already-named functions in GOG144.

For every USER_DEFINED-named function whose base name matches a PS2 function
in ps2_symbols/SLUS_201.78.symbols.csv (demangled "name(types)"), build a
FunctionDefinition with the PS2 parameter types and apply it via
ApplyFunctionSignatureCmd. The current (Ghidra-inferred) return type is kept
so float/pointer returns are not lost; parameter names p0..pN.

Usage: python scripts/apply_signatures_pyghidra.py
"""
import csv, os, re

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.util.task import ConsoleTaskMonitor
MONITOR = ConsoleTaskMonitor()

from ghidra.base.project import GhidraProject
from ghidra.app.cmd.function import ApplyFunctionSignatureCmd
from ghidra.program.model.data import (FunctionDefinitionDataType, ParameterDefinitionImpl,
                                       PointerDataType, IntegerDataType, FloatDataType,
                                       DoubleDataType, CharDataType, Undefined4DataType,
                                       UnsignedIntegerDataType)
from ghidra.program.model.symbol import SourceType
from ghidra.program.model.data import CategoryPath

CAT = "/GiantsRE"

def parse_sig(dem):
    m = re.match(r"^(.+?)\((.*)\)$", dem)
    if not m:
        return None, None
    name, params = m.group(1), m.group(2)
    if params.strip() in ("", "void"):
        plist = []
    else:
        plist = [p.strip() for p in params.split(",")]
    return name, plist

def resolve(t, dtm):
    t = t.strip()
    isptr = t.endswith("*")
    if isptr:
        t = t[:-1].strip()
    builtin = {
        "int": IntegerDataType.dataType, "unsigned int": UnsignedIntegerDataType.dataType,
        "long": IntegerDataType.dataType, "unsigned long": UnsignedIntegerDataType.dataType,
        "short": IntegerDataType.dataType, "char": CharDataType.dataType,
        "float": FloatDataType.dataType, "double": DoubleDataType.dataType,
    }
    if t in builtin:
        base = builtin[t]
    else:
        base = dtm.getDataType(CategoryPath(CAT), t)   # OBJECT, FxData, ...
        if base is None:
            base = Undefined4DataType.dataType
    return PointerDataType(base) if isptr else base

def main():
    sigs = {}
    for r in csv.DictReader(open(os.path.join(REPO, "ps2_symbols", "SLUS_201.78.symbols.csv"),
                                 encoding="utf-8")):
        if r["kind"] != "FUNC":
            continue
        name, params = parse_sig(r["demangled"])
        if name:
            sigs[name] = params

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        fm = program.getFunctionManager()
        dtm = program.getDataTypeManager()
        tx = program.startTransaction("apply ps2 signatures")
        applied = nomatch = failed = 0
        try:
            it = fm.getFunctions(True)
            todo = []
            while it.hasNext():
                fn = it.next()
                if fn.isThunk() or fn.isExternal():
                    continue
                nm = fn.getName()
                if nm.startswith("FUN_"):
                    continue
                base = nm.split("__F")[0] if "__F" in nm else nm
                params = sigs.get(base)
                if params is None:
                    nomatch += 1
                    continue
                todo.append((fn, base, params))
            for fn, base, params in todo:
                try:
                    sig = FunctionDefinitionDataType(base)
                    sig.setReturnType(fn.getReturnType())
                    args = []
                    for i, t in enumerate(params):
                        if t == "...":
                            sig.setVarArgs(True)
                            continue
                        dt = resolve(t, dtm)
                        args.append(ParameterDefinitionImpl(f"p{i}", dt, ""))
                    sig.setArguments(args)
                    cmd = ApplyFunctionSignatureCmd(fn.getEntryPoint(), sig, SourceType.USER_DEFINED)
                    if cmd.applyTo(program, MONITOR):
                        applied += 1
                    else:
                        failed += 1
                except Exception as ex:
                    failed += 1
                    if failed <= 3:
                        print(f"  fail {base}: {ex}")
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print(f"signatures applied={applied} no-ps2-match={nomatch} failed={failed}")
    finally:
        project.close()

if __name__ == "__main__":
    main()
