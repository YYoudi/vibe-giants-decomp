#!/usr/bin/env python3
"""Create engine structs in the GOG144 project from PS2-mined layouts.

OBJECT : dword fields at offsets mined from 779 PS2 functions taking OBJECT*
         (ps2_symbols/OBJECT_LAYOUT.csv). Field names: primary accessor when
         a single function accounts for the accesses, else field_0xNN.
         CAVEAT: PS2 GCC vs PC MSVC alignment may differ for doubles — the
         semantic offsets are a guide; PC layout not asserted.
FxData / FXSTACKTAG : pointer-only evidence — created as opaque dwords sized
         by observed max offset in PC code (defined later as evidence grows).

This makes future decompilation able to cast pointers to OBJECT* and get
stable field offsets, and documents the layout in the project.

Usage: python scripts/apply_structs_pyghidra.py
"""
import csv, os

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.data import StructureDataType, DWordDataType, ByteDataType, CategoryPath

def main():
    layout = []
    seen_off = set()
    for r in csv.DictReader(open(os.path.join(REPO, "ps2_symbols", "OBJECT_LAYOUT.csv"), encoding="utf-8")):
        off = r["offset"]
        if off.startswith("0x-"):       # negative offset (vtable-adjacent header) — skip
            continue
        o = int(off, 16)
        layout.append((o, int(r["width"]), int(r["nfuncs"]), r["accessors"]))
        seen_off.add(o)
    # merge PC-mined offsets (cross-usage evidence) not covered by the PS2 pass
    pcfile = os.path.join(REPO, "decompiled", "object_fields_pc.csv")
    if os.path.exists(pcfile):
        for r in csv.DictReader(open(pcfile, encoding="utf-8")):
            o = int(r["offset"], 16)
            if o not in seen_off:
                layout.append((o, 4, int(r["pc_funcs"]), r["examples"]))
                seen_off.add(o)
        print(f"merged PC-mined offsets: {len(seen_off)} total")
    layout.sort()
    print(f"OBJECT mined fields: {len(layout)} (non-negative offsets)")

    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        dtm = program.getDataTypeManager()
        cat = CategoryPath("/GiantsRE")

        tx = program.startTransaction("create engine structs")
        try:
            # --- OBJECT ----------------------------------------------------
            st = StructureDataType(cat, "OBJECT", 0)
            prev_end = 0
            for off, width, nfuncs, accessors in layout:
                if off < prev_end:      # overlapping mined offsets — widen
                    continue
                if off > prev_end:      # gap → anonymous padding
                    st.add(DWordDataType.dataType, off - prev_end, f"gap_{prev_end:X}", None)
                # name: single dominant accessor → semantic name
                accs = [a.strip() for a in accessors.split(",")]
                fname = f"field_{off:X}"
                if len(accs) == 1 and nfuncs == 1:
                    fname = f"acc_{accs[0][:24]}"
                st.add(DWordDataType.dataType, width, fname, None)
                prev_end = off + width
            existing = dtm.getDataType(cat, "OBJECT")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(st, None)
            print(f"OBJECT: {st.getLength()} bytes, {st.getNumComponents()} fields")

            # --- FxData (opaque start: dwords 0x00..0x3C seen in fx_create*) -
            fx = StructureDataType(cat, "FxData", 0)
            for i in range(16):
                fx.add(DWordDataType.dataType, 4, f"fx_{i*4:X}", None)
            existing = dtm.getDataType(cat, "FxData")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(fx, None)
            print(f"FxData: {fx.getLength()} bytes placeholder")

            program.endTransaction(tx, True)
        except Exception:
            program.endTransaction(tx, False)
            raise
        program.flushEvents()
        project.save(program)
        print("saved project")
    finally:
        project.close()

if __name__ == "__main__":
    main()
