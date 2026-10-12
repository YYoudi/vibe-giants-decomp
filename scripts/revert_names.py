#!/usr/bin/env python3
"""Revert provisional names: restore FUN_<ADDR> for addresses in a CSV
(pc_addr column). Usage: python scripts/revert_names.py <csv>"""
import csv, os, sys

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.symbol import SourceType

def main():
    csv_path = sys.argv[1]
    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        fm = program.getFunctionManager()
        af = program.getAddressFactory().getDefaultAddressSpace()
        tx = program.startTransaction("revert names")
        n = 0
        try:
            for r in csv.DictReader(open(csv_path, encoding="utf-8")):
                a = r["pc_addr"].lower().lstrip("0").rjust(8, "0")
                fn = fm.getFunctionAt(af.getAddress("0x" + a))
                if fn is None:
                    continue
                orig = f"FUN_{a.upper()}"
                if fn.getName() != orig:
                    fn.setName(orig, SourceType.DEFAULT)
                    n += 1
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print(f"reverted {n} names to FUN_<ADDR>")
    finally:
        project.close()

if __name__ == "__main__":
    main()
