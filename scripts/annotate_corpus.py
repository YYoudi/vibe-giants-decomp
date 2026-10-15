#!/usr/bin/env python3
"""Annotated re-export of the decompiled corpus.

Rewrites `*(int *)(param_1 + 0xNN)` (and friends) into typed field accesses
using ps2_symbols/giants_types.h semantics, for an opt-in list of functions
whose first parameter is a proven OBJECT*. Output goes to
decompiled/gog144_annotated/<name>.c — the source corpus is NEVER touched.

Usage:  python scripts/annotate_corpus.py [funcname ...]   (default: witness set)
"""
import os, re, sys

CORPUS = "decompiled/gog144_full/all_decompiled.c"
OUTDIR = "decompiled/gog144_annotated"

# witness set — first param proven OBJECT* by call-site evidence
DEFAULT_FUNCS = [
    "object_animate_process",
    "obj_velocity_commit",
    "object_apply_location",
]

# offset -> typed access (from docs/formats/OBJECT_LAYOUT.md; observed/derived only)
FIELD_MAP = {
    0x04: ("type_id", "u32"),   0x10: ("anim", "ptr"),
    0xD8: ("flags", "u32"),     0xE0: ("coll_radius", "f32"),
    0x100: ("animate_state", "u32"),
    0x108: ("vel[0]", "f32"),   0x10C: ("vel[1]", "f32"),
    0x110: ("vel[2]", "f32"),   0x114: ("vel[3]", "f32"),
    0x130: ("loc_accum[0]", "f32"), 0x134: ("loc_accum[1]", "f32"),
    0x138: ("loc_accum[2]", "f32"), 0x13C: ("loc_accum[3]", "f32"),
    0x150: ("waypoint[0]", "f32"), 0x154: ("waypoint[1]", "f32"),
    0x158: ("waypoint[2]", "f32"), 0x15C: ("waypoint[3]", "f32"),
    0x16C: ("anim_selector", "u32"),
    0x180: ("actor_spec", "u32"),
    0x18C: ("ai_state_b", "u32"),
    0x1A8: ("orders_head", "ptr"),
    0x1E0: ("state", "u32"),
    0x2D8: ("alloc_data[0]", "ptr"), 0x2DC: ("alloc_data[1]", "ptr"),
    0x2E0: ("alloc_data[2]", "ptr"),
    0x2F0: ("energy", "f32"),
    0x464: ("shadow", "u32"),
}

def annotate(body: str) -> str:
    # *(int *)(param_1 + 0xNN) / *(undefined4 *)(param_1 + 0xNN) -> obj->field
    def repl_deref_deref(m):
        off = int(m.group(1), 16)
        f = FIELD_MAP.get(off)
        return f"(obj->{f[0]} /* {m.group(0)} */)" if f else m.group(0)

    def annotate_deref(m):
        off = int(m.group(1), 16)
        f = FIELD_MAP.get(off)
        return f"(obj->{f[0]} /* {m.group(0)} */)" if f else m.group(0)

    body = re.sub(r"\*\((?:int|sint|undefined4|uint|float|undefined) ?\*\)\(param_1 \+ (0x[0-9a-f]+)\)",
                  annotate_deref, body)
    # param_1[NN] (dword index)
    def repl_idx(m):
        off = int(m.group(1), 16) * 4
        f = FIELD_MAP.get(off)
        return f"obj->{f[0]} /* param_1[{m.group(1)}] */" if f else m.group(0)
    body = re.sub(r"param_1\[(0x[0-9a-f]+)\]", repl_idx, body)
    header = ("/* ANNOTATED RE-EXPORT — obj->field substitutions from "
              "docs/formats/OBJECT_LAYOUT.md (observed/derived fields only).\n"
              " * Source of truth: decompiled/gog144_full. Regenerate: "
              "scripts/annotate_corpus.py. */\n")
    return header + body

def main():
    funcs = sys.argv[1:] or DEFAULT_FUNCS
    src = open(CORPUS, encoding="utf-8", errors="replace").read()
    parts = re.split(r"/\* ===== ([A-Za-z_0-9]+) @ (0x[0-9A-Fa-f]+) ===== \*/", src)
    os.makedirs(OUTDIR, exist_ok=True)
    for want in funcs:
        for i in range(1, len(parts) - 2, 3):
            if parts[i] == want:
                out = os.path.join(OUTDIR, f"{want}.c")
                open(out, "w", encoding="utf-8", newline="").write(
                    annotate(parts[i + 2]))
                print("wrote", out)
                break
        else:
            print("not found:", want)

if __name__ == "__main__":
    main()
