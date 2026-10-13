#!/usr/bin/env python3
"""Give OBJECT struct fields semantic names derived from their PS2 accessor
function names (OBJECT_LAYOUT.csv). Strategy per offset:
  - normalize accessor list (strip PS2 race/class prefixes and get/set/is
    verbs, unify)
  - if the accessors converge on one semantic stem -> field_<stem>
  - else keep field_0xNN (no invention)
"""
import csv, os, re, collections

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.data import StructureDataType, DWordDataType, CategoryPath

CLASS_PREFIX = re.compile(
    r"^(mecc|smartie|reaper|kabuto|vimp|rpman|rpboat|ripper|teammecc|evilreaper|"
    r"evilreaper|base|herd|buoy|sf|gun|weapon|item|inv|object|obj|common|world|main)_")

def stems(accessors):
    out = set()
    for acc in accessors:
        a = acc.strip()
        a = CLASS_PREFIX.sub("", a)
        a = re.sub(r"^(get|set|is|has|clear|do)_", "", a)
        a = re.sub(r"__F.*$", "", a)
        if len(a) >= 4:
            out.add(a.lower())
    return out

def main():
    per_off = {}
    for r in csv.DictReader(open(os.path.join(REPO, "ps2_symbols", "OBJECT_LAYOUT.csv"), encoding="utf-8")):
        off = r["offset"]
        if off.startswith("0x-"):
            continue
        accs = [a.strip() for a in r["accessors"].split(",") if a.strip()]
        per_off[int(off, 16)] = accs

    fieldnames = {}
    for o, accs in sorted(per_off.items()):
        st = stems(accs)
        if len(st) == 1:
            fieldnames[o] = f"f_{st.pop()}"
        elif len(st) > 1:
            # converge on the longest common prefix if >= 6 chars
            pre = os.path.commonprefix(sorted(st))
            if len(pre) >= 6:
                fieldnames[o] = f"f_{pre}"

    print(f"semantic names derivable: {len(fieldnames)} / {len(per_off)} offsets")
    for o in sorted(fieldnames)[:20]:
        print(f"  {hex(o)} -> {fieldnames[o]}  (acc: {per_off[o][:2]})")

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        dtm = program.getDataTypeManager()
        cat = CategoryPath("/GiantsRE")
        tx = program.startTransaction("OBJECT semantic field names")
        try:
            st = StructureDataType(cat, "OBJECT", 0)
            prev = 0
            for o in sorted(per_off):
                if o < prev:
                    continue
                if o > prev:
                    st.add(DWordDataType.dataType, o - prev, f"gap_{prev:X}", None)
                nm = fieldnames.get(o, f"field_{o:X}")
                st.add(DWordDataType.dataType, 4, nm, None)
                prev = o + 4
            existing = dtm.getDataType(cat, "OBJECT")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(st, None)
            print(f"OBJECT rebuilt: {st.getLength()} bytes, {st.getNumComponents()} fields "
                  f"({len(fieldnames)} semantic)")
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print("saved")
    finally:
        project.close()

if __name__ == "__main__":
    main()
