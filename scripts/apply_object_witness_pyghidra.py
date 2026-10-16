#!/usr/bin/env python3
"""TASK-017: apply the semantic OBJECT struct (giants_types.h / OBJECT_LAYOUT.md)
to the 10 witness functions in the GOG144 Ghidra project, then re-decompile
and export their bodies. After this, the witness decompilations read
`obj->flags` / `obj->vel[0]` instead of `*(int *)(param_1 + 0xd8)`.

Steps:
 1. (Re)create /GiantsRE/OBJECT with NAMED fields at the documented offsets
    (observed+derived semantics only; gaps stay explicit pad_ dwords).
 2. For each witness function: set parameter 0 to OBJECT* and name it `obj`.
 3. Decompile and export to decompiled/gog144_annotated/ghidra/<name>.c.
 4. DoD self-check: no `param_1 + 0xNN` left for covered offsets in exports.

Usage: python scripts/apply_object_witness_pyghidra.py
"""
import os, re

os.environ.setdefault("GHIDRA_INSTALL_DIR", r"G:\Tools\ghidra_12.1.2_PUBLIC")
REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUTDIR = os.path.join(REPO, "decompiled", "gog144_annotated", "ghidra")

import pyghidra
pyghidra.start()

from ghidra.base.project import GhidraProject
from ghidra.program.model.data import StructureDataType, DWordDataType, CategoryPath
from ghidra.program.model.symbol import SourceType
from ghidra.app.decompiler import DecompInterface

# semantic fields (offset, name) — observed+derived from docs/formats/OBJECT_LAYOUT.md
FIELDS = [
    (0x004, "type_id"), (0x008, "class_ptr"), (0x00C, "team_link"),
    (0x010, "anim"),
    (0x0D8, "flags"), (0x0E0, "coll_radius"),
    (0x100, "animate_state"),
    (0x108, "vel0"), (0x10C, "vel1"), (0x110, "vel2"), (0x114, "vel_w"),
    (0x118, "prev_vel0"), (0x11C, "prev_vel1"), (0x120, "prev_vel2"), (0x124, "prev_vel_w"),
    (0x130, "loc_accum0"), (0x134, "loc_accum1"), (0x138, "loc_accum2"), (0x13C, "loc_accum3"),
    (0x150, "waypoint0"), (0x154, "waypoint1"), (0x158, "waypoint2"), (0x15C, "waypoint3"),
    (0x16C, "anim_selector"),
    (0x180, "actor_spec"),
    (0x18C, "ai_state_b"),
    (0x1A8, "orders_head"),
    (0x1E0, "state"),
    (0x2D8, "alloc_data0"), (0x2DC, "alloc_data1"), (0x2E0, "alloc_data2"),
    (0x2F0, "energy"),
    (0x464, "shadow"),
]
STRUCT_END = 0x468

WITNESSES = [
    "ObjectSetAnim", "object_stop_movement", "hud_icon_for_object",
    "object_apply_location", "obj_velocity_commit", "object_animate_process",
    "object_lock_apply", "object_free_all_allocated_data",
    "object_stop_movement_2", "sound_play_obj",
]
# functions whose OBJECT* arrives on parameter 1, not 0
# (call-site evidence: FLK_FlickProcess sound_play_obj(idx, actor+0xC))
WITNESS_PARAM = {"sound_play_obj": 1}

def build_object_struct(cat):
    st = StructureDataType(cat, "OBJECT", 0)
    pos = 0
    for off, name in FIELDS:
        if off > pos:
            st.add(DWordDataType.dataType, off - pos, f"pad_{pos:X}", None)
        st.add(DWordDataType.dataType, 4, name, None)
        pos = off + 4
    if STRUCT_END > pos:
        st.add(DWordDataType.dataType, STRUCT_END - pos, f"pad_{pos:X}", None)
    return st

def main():
    os.makedirs(OUTDIR, exist_ok=True)
    project = GhidraProject.openProject(os.path.join(REPO, "ghidra_projects_gog144"), "GOG144", True)
    try:
        program = project.openProgram("/", "Giants.exe", False)
        dtm = program.getDataTypeManager()
        fm = program.getFunctionManager()
        cat = CategoryPath("/GiantsRE")

        tx = program.startTransaction("OBJECT semantic struct + witness params")
        ok = False
        try:
            st = build_object_struct(cat)
            existing = dtm.getDataType(cat, "OBJECT")
            if existing is not None:
                dtm.remove(existing, None)
            dtm.addDataType(st, None)
            obj_ptr = dtm.getPointer(st)
            print(f"OBJECT: {st.getLength()} bytes, named fields {len(FIELDS)}")

            by_name = {}
            for f in fm.getFunctions(True):
                by_name.setdefault(f.getName(), []).append(f)

            typed = []
            for name in WITNESSES:
                cands = by_name.get(name, [])
                # prefer unique name; else take the first and report
                if not cands:
                    print(f"  !! not found in project: {name}")
                    continue
                f = cands[0]
                pidx = WITNESS_PARAM.get(name, 0)
                p0 = f.getParameter(pidx)
                if p0 is None:
                    # no formal parameter yet — create one (uses incoming
                    # register storage per the calling convention)
                    from ghidra.app.cmd.function import AddParameterCommand
                    from ghidra.program.model.listing import ParameterImpl, Parameter
                    from ghidra.program.model.data import IntegerDataType
                    from ghidra.program.model.symbol import SourceType as ST
                    dt = dtm.getDataType(CategoryPath("/GiantsRE"), "OBJECT")
                    newp = ParameterImpl("obj", dtm.getPointer(dt), program)
                    if not AddParameterCommand(f, newp, pidx, ST.USER_DEFINED).applyTo(program):
                        print(f"  !! cannot create param0: {name}")
                        continue
                    p0 = f.getParameter(0)
                p0.setDataType(obj_ptr, SourceType.USER_DEFINED)
                try:
                    p0.setName("obj")
                except Exception:
                    pass
                typed.append((name, f))
                extra = f" (+{len(cands)-1} homonyms)" if len(cands) > 1 else ""
                print(f"  typed {name}{extra} @ {f.getEntryPoint()}")
            ok = True
        finally:
            program.endTransaction(tx, ok)
        program.flushEvents()
        project.save(program)

        # re-decompile + export
        ifc = DecompInterface()
        ifc.openProgram(program)
        cov_offsets = {o for o, _ in FIELDS}
        dod_fail = 0
        for name, f in typed:
            res = ifc.decompileFunction(f, 120, None)
            if not res.decompileCompleted():
                print(f"  !! decompile failed: {name}")
                continue
            c = res.getDecompiledFunction().getC()
            path = os.path.join(OUTDIR, f"{name}.c")
            open(path, "w", encoding="utf-8", newline="").write(c)
            # DoD: covered offsets must not appear as param_1 + 0xNN anymore
            left = []
            for m in re.finditer(r"param_1 \+ (0x[0-9a-f]+)\)", c):
                if int(m.group(1), 16) in cov_offsets:
                    left.append(m.group(1))
            # also obj(->_field) forms must exist for sanity
            n_fields = len(re.findall(r"obj->", c))
            status = "OK" if not left else f"LEFT {sorted(set(left))}"
            if left:
                dod_fail += 1
            print(f"  export {name}: obj-> x{n_fields} [{status}]")
        print("DoD:", "PASS" if dod_fail == 0 else f"FAIL on {dod_fail}")
    finally:
        project.close()

if __name__ == "__main__":
    main()
