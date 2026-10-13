#!/usr/bin/env python3
"""Apply a name table to the GOG144 Ghidra project via pyghidra (no OSGi).
Replaces scripts/ghidra_apply_matches.java + go_apply_gog144.bat.

CSV format (as produced by build_unified_names.py):
  pc_addr,pc_name,ps2_addr,ps2_name,conf,tier,shared
conf >= --min-rename  -> rename function (SourceType.USER_DEFINED)
else                  -> plate comment "PS2 candidate: name (conf c)"

Usage: python scripts/apply_names_pyghidra.py <csv> [min_rename=0.9]
"""
import csv, os, sys

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.app.cmd.function import CreateFunctionCmd
from ghidra.program.model.symbol import SourceType
from ghidra.program.model.listing import CodeUnit

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

def main():
    csv_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "ps2_symbols", "unified_names_1449.csv")
    min_rename = float(sys.argv[2]) if len(sys.argv) > 2 else 0.9

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)  # read-write
        fm = program.getFunctionManager()
        listing = program.getListing()
        af = program.getAddressFactory().getDefaultAddressSpace()

        tx = program.startTransaction("apply names")
        renamed = commented = missed = 0
        try:
            for r in csv.DictReader(open(csv_path, encoding="utf-8")):
                va = norm(r["pc_addr"])
                name = r["ps2_name"].strip()
                if not name:
                    # wave CSVs may put the new name in pc_name (ps2_name empty);
                    # pc_name is otherwise the current FUN_ auto-name, never a target.
                    cand = r.get("pc_name", "").strip()
                    if cand and not cand.upper().startswith(("FUN_", "SUB_", "THUNK_")):
                        name = cand
                conf = float(r["conf"])
                addr = af.getAddress("0x" + va)
                fn = fm.getFunctionContaining(addr)
                if fn is None:
                    ok = CreateFunctionCmd(addr).applyTo(program, None)
                    fn = fm.getFunctionContaining(addr) if ok else None
                if fn is None:
                    missed += 1
                    continue
                if conf >= min_rename:
                    try:
                        fn.setName(name, SourceType.USER_DEFINED)
                        renamed += 1
                        continue
                    except Exception:
                        pass
                cu = listing.getCodeUnitAt(addr)
                if cu is not None:
                    cu.setComment(CodeUnit.PLATE_COMMENT,
                                  f"PS2 candidate: {name} (conf {conf})")
                    commented += 1
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print(f"renamed={renamed} candidate-commented={commented} no-func={missed}")
    finally:
        project.close()

if __name__ == "__main__":
    main()
