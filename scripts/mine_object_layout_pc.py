#!/usr/bin/env python3
"""Mine PC (GOG 1.449) OBJECT-field accesses from the decompiled corpus.

Method: for a curated list of functions whose first parameter is a proven
OBJECT* (kernel object_* / animate / status functions), count direct
`param_1 + 0xNN` / `param_1[NN]` accesses. Ghidra re-assigns param_1 to
locals in some bodies (noise possible); results are cross-checked against
ps2_symbols/OBJECT_LAYOUT.csv before being trusted.
Output: docs/formats/object_layout_pc.csv (offset,width,hits,functions)
"""
import re, csv, sys
from collections import defaultdict

CORPUS = "decompiled/gog144_full/all_decompiled.c"

# functions taking OBJECT* as param 1 (proven by call sites: FLK_FlickRender
# passes puVar10-0xc == actor+0xC; status/animate kernel from MODULE_INDEX)
TARGETS = [
    "object_animate_process", "obj_velocity_commit", "object_apply_location",
    "objspec_dispatch_gate", "object_free_all_allocated_data", "ObjectSetAnim",
    "status_update_3obj", "object_list_update", "object_stop_movement",
    "object_lock_apply", "hud_icon_for_object", "object_clone_objectset",
    "objobj_type_lookup", "sound_play_obj", "object_set_flags",
    "object_animate_init", "object_find_by_name", "object_new",
]

def main():
    src = open(CORPUS, encoding="utf-8", errors="replace").read()
    # split into functions
    funcs = re.split(r"/\* ===== ([A-Za-z_0-9]+) @ 0x([0-9A-Fa-f]+) ===== \*/", src)
    # funcs: [pre, name1, addr1, body1, name2, addr2, body2, ...]
    pat_off = re.compile(r"param_1 \+ (0x[0-9a-f]+)\)")
    pat_idx = re.compile(r"param_1\[(0x[0-9a-f]+)\]")
    rows = defaultdict(lambda: defaultdict(int))
    for i in range(1, len(funcs) - 2, 3):
        name, addr, body = funcs[i], funcs[i+1], funcs[i+2]
        if not any(t == name or name.startswith(t) for t in TARGETS):
            continue
        for m in pat_off.finditer(body):
            rows[int(m.group(1), 16)][name] += 1
        for m in pat_idx.finditer(body):
            # dword index -> byte offset
            rows[int(m.group(1), 16) * 4][name] += 1
    out = "docs/formats/object_layout_pc.csv"
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["offset", "width", "hits", "functions"])
        for off in sorted(rows):
            fl = rows[off]
            w.writerow([hex(off), 4, sum(fl.values()),
                        "; ".join(sorted(fl)[:6])])
    print(f"wrote {out}: {len(rows)} offsets")

if __name__ == "__main__":
    main()
