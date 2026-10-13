#!/usr/bin/env python3
"""Mine FXSTACKTAG field offsets from param_2 of functions whose PS2 signature
has FXSTACKTAG* as second parameter, then create the struct in the project.
"""
import csv, os, re, collections, json, glob

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.data import StructureDataType, DWordDataType, CategoryPath

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

def main():
    # find PC functions whose PS2 signature has FXSTACKTAG in param 2
    targets = set()
    sigs = {}
    for r in csv.DictReader(open(os.path.join(PS2, "SLUS_201.78.symbols.csv"), encoding="utf-8")):
        if r["kind"] == "FUNC" and "FXSTACKTAG" in r["demangled"].split("(", 1)[-1]:
            sigs[r["demangled"].split("(")[0]] = r["demangled"]
    for f in ["unified_names_1449.csv", "bsim_wave.csv", "llm_strings_wave.csv"]:
        try:
            for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
                base = r["ps2_name"].split("__F")[0].split("(")[0]
                if base in sigs:
                    targets.add(norm(r["pc_addr"]))
        except FileNotFoundError:
            pass
    print(f"FXSTACKTAG-param functions: {len(targets)}")

    OFF = re.compile(r"param_2\s*\+\s*(0x[0-9a-fA-F]+)")
    hist = collections.Counter()
    users = collections.defaultdict(list)
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        a = norm(d["address"])
        if a not in targets:
            continue
        for o in set(int(x, 16) for x in OFF.findall(d["decompiled"])):
            hist[o] += 1
            if len(users[o]) < 3:
                users[o].append(d["name"])
    keep = sorted(o for o, c in hist.items() if c >= 2 and o < 0x100)
    print(f"FXSTACKTAG offsets (>=2 funcs, <0x100): {len(keep)}: {[hex(o) for o in keep]}")
    if len(keep) < 3:
        print("insufficient evidence — struct not created")
        return

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        dtm = program.getDataTypeManager()
        cat = CategoryPath("/GiantsRE")
        tx = program.startTransaction("create FXSTACKTAG struct")
        try:
            st = StructureDataType(cat, "FXSTACKTAG", 0)
            prev = 0
            for o in keep:
                if o < prev:
                    continue
                if o > prev:
                    st.add(DWordDataType.dataType, o - prev, f"gap_{prev:X}", None)
                st.add(DWordDataType.dataType, 4, f"field_{o:X}", None)
                prev = o + 4
            existing = dtm.getDataType(cat, "FXSTACKTAG")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(st, None)
            print(f"FXSTACKTAG: {st.getLength()} bytes, {st.getNumComponents()} fields")
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
