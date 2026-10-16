#!/usr/bin/env python3
"""TASK-013: rename duplicate function names in the GOG144 Ghidra project.

Convention (neutral, reversible — no semantic claim):
  for each duplicated name, the occurrence at the LOWEST address keeps the
  name; every other occurrence becomes `<name>_dup<addr8>` (hex address,
  no 0x). Bodies verified DISTINCT by decompiled/dup_audit.json (all pairs
  differ in body size; that audit is the "one name != one body" evidence).

Usage: python scripts/dedup_rename_pyghidra.py [--dry]
"""
import json, os, sys

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.symbol import SourceType

AUDIT = os.path.join(REPO, "decompiled", "dup_audit.json")

def main():
    dry = "--dry" in sys.argv
    audit = json.load(open(AUDIT, encoding="utf-8"))
    dup_names = {e["name"]: [o["addr"] for o in e["occurrences"]]
                 for e in audit["real_duplicates"]}
    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"),
                                        "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        fm = program.getFunctionManager()
        af = program.getAddressFactory().getDefaultAddressSpace()
        tx = program.startTransaction("dedup renames")
        ok = False
        renamed = []
        try:
            for name, addrs in sorted(dup_names.items()):
                addrs = sorted(int(a, 16) for a in addrs)
                for a in addrs[1:]:  # first occurrence keeps the name
                    f = fm.getFunctionAt(af.getAddress(hex(a)))
                    if f is None:
                        print(f"  !! no function at {hex(a)} for {name}")
                        continue
                    new = f"{name}_dup{a:08x}"
                    old = f.getName()
                    if not dry:
                        f.setName(new, SourceType.USER_DEFINED)
                    renamed.append((old, hex(a), new))
            ok = True
        finally:
            program.endTransaction(tx, ok)
        program.flushEvents()
        project.save(program)
        for old, a, new in renamed:
            print(f"  {old} @ {a} -> {new}")
        print(f"{'would rename' if dry else 'renamed'}: {len(renamed)} functions")
    finally:
        project.close()

if __name__ == "__main__":
    main()
