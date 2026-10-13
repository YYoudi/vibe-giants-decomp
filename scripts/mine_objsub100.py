#!/usr/bin/env python3
"""Mine the OBJECT+0x100 substruct offsets: in functions that load
*(param_1 + 0x100) into a local, track that local's constant-offset
dereferences. Then create the ObjSub100 struct in the project and wire it as
OBJECT.field_0x100.
"""
import csv, json, glob, os, re, collections

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.data import StructureDataType, DWordDataType, PointerDataType, CategoryPath

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

def main():
    # 1) mine: functions using *(param_1 + 0x100) and the local's offset usage
    LOAD = re.compile(r"(\w+)\s*=\s*\*\(int \*\)\(param_1 \+ 0x100\)")
    USE = re.compile(r"\b(\w+)\s*\+\s*(0x[0-9a-fA-F]+)")
    hist = collections.Counter()
    users = collections.defaultdict(list)
    nfuncs = 0
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        body = d["decompiled"]
        m = LOAD.search(body)
        if not m:
            continue
        var = m.group(1)
        nfuncs += 1
        for u in USE.finditer(body):
            if u.group(1) == var:
                o = int(u.group(2), 16)
                if o < 0x800:
                    hist[o] += 1
                    if len(users[o]) < 3:
                        users[o].append(d["name"])
    keep = sorted(o for o, c in hist.items() if c >= 4)
    print(f"functions loading OBJECT+0x100: {nfuncs}; sub offsets (>=4 funcs): {len(keep)}")
    print("  ", [hex(o) for o in keep[:25]])

    if len(keep) < 5:
        print("insufficient evidence — struct not created")
        return

    # 2) create struct + wire as OBJECT.field_0x100
    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        dtm = program.getDataTypeManager()
        cat = CategoryPath("/GiantsRE")
        tx = program.startTransaction("create ObjSub100 + wire OBJECT.field_0x100")
        try:
            st = StructureDataType(cat, "ObjSub100", 0)
            prev = 0
            for o in keep:
                if o < prev:
                    continue
                if o > prev:
                    st.add(DWordDataType.dataType, o - prev, f"gap_{prev:X}", None)
                st.add(DWordDataType.dataType, 4, f"field_{o:X}", None)
                prev = o + 4
            existing = dtm.getDataType(cat, "ObjSub100")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(st, None)

            obj = dtm.getDataType(cat, "OBJECT")
            if obj is not None:
                objst = obj
                # find component at 0x100 and replace its datatype with ObjSub100*
                comps = objst.getComponents()
                for i in range(comps.length):
                    c = comps[i]
                    if c.getOffset() == 0x100:
                        c.setDataType(PointerDataType(st))
                        print("OBJECT.field_0x100 -> ObjSub100*")
                        break
            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print(f"ObjSub100: {st.getLength()} bytes, {st.getNumComponents()} fields — saved")
    finally:
        project.close()

if __name__ == "__main__":
    main()
