#!/usr/bin/env python3
"""Apply OBJECT* type to the first parameter of functions whose body
dereferences it at >=3 distinct offsets mined from the PS2 OBJECT layout
(ps2_symbols/OBJECT_LAYOUT.csv). Only functions whose current parameters are
all undefined (no PS2 float/pointer signatures to damage).

This makes the decompiler render obj->field instead of *(int *)(param_1 + N)
and enriches BSim IR vectors.

Usage: python scripts/apply_struct_params.py
"""
import csv, json, os, re, glob

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.app.cmd.function import ApplyFunctionSignatureCmd
from ghidra.program.model.data import (FunctionDefinitionDataType, ParameterDefinitionImpl,
                                       PointerDataType, Undefined4DataType)
from ghidra.program.model.symbol import SourceType
from ghidra.util.task import ConsoleTaskMonitor
MON = ConsoleTaskMonitor()

MIN_HITS = 2

def main():
    mined = set()
    for r in csv.DictReader(open(os.path.join(REPO, "ps2_symbols", "OBJECT_LAYOUT.csv"), encoding="utf-8")):
        off = r["offset"]
        if not off.startswith("0x-"):
            mined.add(int(off, 16))
    big = {o for o in mined if o >= 0x100}

    cands = []
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        body = d["decompiled"]
        m = re.match(r".*?\(([^)]*)\)", body, re.S)
        if not m:
            continue
        params = [p.strip() for p in m.group(1).split(",") if p.strip()]
        if not params or "param_1" not in params[0]:
            continue
        offs = set(int(x, 16) for x in re.findall(r"param_1\s*\+\s*(0x[0-9a-fA-F]+)", body))
        if len(offs & mined) >= MIN_HITS and len(offs & big) >= 1:
            cands.append((d["address"], len(offs & mined)))
    print(f"OBJECT* candidates: {len(cands)}")

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        fm = program.getFunctionManager()
        af = program.getAddressFactory().getDefaultAddressSpace()
        dtm = program.getDataTypeManager()
        obj_ptr = PointerDataType(dtm.getDataType("/GiantsRE/OBJECT"))
        undef = Undefined4DataType.dataType

        tx = program.startTransaction("apply OBJECT* params")
        applied = skipped = failed = 0
        try:
            reasons = {"nofunc": 0, "noparams": 0, "already": 0, "bad": 0}
            for addr, _nh in cands:
                fn = fm.getFunctionAt(af.getAddress("0x" + addr))
                if fn is None:
                    skipped += 1; reasons["nofunc"] += 1
                    continue
                params = fn.getParameters()
                if not params:
                    # Ghidra dissolved params, but the export body used param_1
                    # at OBJECT offsets — force a 1-param OBJECT* signature.
                    sig = FunctionDefinitionDataType(fn.getName())
                    sig.setReturnType(fn.getReturnType())
                    sig.setArguments([ParameterDefinitionImpl("obj", obj_ptr, "")])
                    if ApplyFunctionSignatureCmd(fn.getEntryPoint(), sig, SourceType.USER_DEFINED).applyTo(program, MON):
                        applied += 1
                    else:
                        failed += 1
                    continue
                if "OBJECT" in params[0].getDataType().getName():
                    skipped += 1; reasons["already"] += 1
                    continue
                bad = False
                for p in params[1:]:
                    n = p.getDataType().getName()
                    if "float" in n or "double" in n:
                        bad = True      # would damage FPU-arg signatures
                    elif "*" in n and "undefined" not in n and "char" not in n and "OBJECT" not in n and "FxData" not in n:
                        bad = True      # would damage named-pointer params
                if bad:
                    skipped += 1; reasons["bad"] += 1
                    continue
                sig = FunctionDefinitionDataType(fn.getName())
                sig.setReturnType(fn.getReturnType())
                args = [ParameterDefinitionImpl("obj", obj_ptr, "")]
                for i in range(1, max(len(params), 1)):
                    args.append(ParameterDefinitionImpl(f"p{i}", undef, ""))
                sig.setArguments(args)
                if ApplyFunctionSignatureCmd(fn.getEntryPoint(), sig, SourceType.USER_DEFINED).applyTo(program, MON):
                    applied += 1
                else:
                    failed += 1
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print(f"OBJECT* applied={applied} skipped={skipped} failed={failed} reasons={reasons}")
    finally:
        project.close()

if __name__ == "__main__":
    main()
