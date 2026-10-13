#!/usr/bin/env python3
"""Apply FxData* to param_1 of fx-engine functions (fx_*/fxb_*/fxn_* names)
whose first parameter is undefined. Pattern from PS2 signatures:
fx_setupEmitter(FxData*, FXSTACKTAG*, ...) etc.
"""
import os

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.app.cmd.function import ApplyFunctionSignatureCmd
from ghidra.program.model.data import (FunctionDefinitionDataType, ParameterDefinitionImpl,
                                       PointerDataType, Undefined4DataType)
from ghidra.program.model.symbol import SourceType
from ghidra.util.task import ConsoleTaskMonitor

MON = ConsoleTaskMonitor()

def main():
    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        fm = program.getFunctionManager()
        dtm = program.getDataTypeManager()
        fx_ptr = PointerDataType(dtm.getDataType("/GiantsRE/FxData"))
        undef = Undefined4DataType.dataType

        tx = program.startTransaction("apply FxData* params")
        applied = skipped = 0
        try:
            it = fm.getFunctions(True)
            while it.hasNext():
                fn = it.next()
                nm = fn.getName()
                if not (nm.startswith("fxb_") or nm.startswith("fxn_") or nm.startswith("fx_")):
                    continue
                params = fn.getParameters()
                if not params or "FxData" in params[0].getDataType().getName():
                    continue
                if params[0].getDataType().getName() not in ("undefined", "undefined4", "int", "undefined4 *", "undefined *"):
                    continue
                sig = FunctionDefinitionDataType(nm)
                sig.setReturnType(fn.getReturnType())
                args = [ParameterDefinitionImpl("fx", fx_ptr, "")]
                for i in range(1, max(len(params), 1)):
                    args.append(ParameterDefinitionImpl(f"p{i}", undef, ""))
                sig.setArguments(args)
                if ApplyFunctionSignatureCmd(fn.getEntryPoint(), sig, SourceType.USER_DEFINED).applyTo(program, MON):
                    applied += 1
                else:
                    skipped += 1
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print(f"FxData* applied={applied} skipped={skipped}")
    finally:
        project.close()

if __name__ == "__main__":
    main()
