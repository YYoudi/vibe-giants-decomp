#!/usr/bin/env python3
"""Mine COMM struct field offsets from comm_*/gamespy_* named functions
(first param dereferences), then create the COMM struct in the project.
"""
import csv, json, glob, os, re, collections

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
    seeds = set()
    for f in ["unified_names_1449.csv", "llm_strings_wave.csv", "llm_strings_wave2.csv",
              "callpat_wave.csv", "module_names_wave.csv", "bsim_wave.csv"]:
        try:
            for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
                nm = r["ps2_name"]
                if nm.startswith("comm_") or nm.startswith("gamespy_"):
                    seeds.add(norm(r["pc_addr"]))
        except FileNotFoundError:
            pass
    print(f"comm seeds: {len(seeds)}")

    OFF = re.compile(r"param_1\s*\+\s*(0x[0-9a-fA-F]+)")
    hist = collections.Counter()
    users = collections.defaultdict(list)
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        a = norm(d["address"])
        if a not in seeds:
            continue
        for o in set(int(x, 16) for x in OFF.findall(d["decompiled"])):
            hist[o] += 1
            if len(users[o]) < 3:
                users[o].append(d["name"])

    keep = sorted(o for o, c in hist.items() if c >= 3 and o < 0x4000)
    print(f"COMM offsets (>=3 funcs): {len(keep)}")
    with open(os.path.join(REPO, "decompiled", "comm_fields_pc.csv"), "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["offset", "pc_funcs", "examples"])
        for o in keep:
            w.writerow([hex(o), hist[o], ";".join(users[o])])

    if not keep:
        print("no comm layout evidence — struct not created")
        return

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        dtm = program.getDataTypeManager()
        cat = CategoryPath("/GiantsRE")
        tx = program.startTransaction("create COMM struct")
        try:
            st = StructureDataType(cat, "COMM", 0)
            prev = 0
            for o in keep:
                if o < prev:
                    continue
                if o > prev:
                    st.add(DWordDataType.dataType, o - prev, f"gap_{prev:X}", None)
                st.add(DWordDataType.dataType, 4, f"field_{o:X}", None)
                prev = o + 4
            existing = dtm.getDataType(cat, "COMM")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(st, None)
            print(f"COMM: {st.getLength()} bytes, {st.getNumComponents()} fields")
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
