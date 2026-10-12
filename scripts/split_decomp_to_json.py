#!/usr/bin/env python3
"""Split a decompile_all.java output (all_decompiled.c + index.json) into
per-function JSON files in ghidra_exports/ — the format consumed by
ps2_symbols/match_pc_ps2.py and match_propagate.py:

    {"address": "005e3840", "name": "FUN_005e3840", "decompiled": "..."}

Usage: python scripts/split_decomp_to_json.py <dir_with_all_decompiled.c> [out_dir]
Defaults: out_dir = <repo>/ghidra_exports (wiped first — one target at a time).
"""
import json, os, re, shutil, sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)

DELIM = re.compile(r"^/\* ===== (.+?) @ 0x([0-9A-Fa-f]{8}) ===== \*/", re.M)

def main():
    src_dir = sys.argv[1] if len(sys.argv) > 1 else os.path.join(REPO, "decompiled", "gog144_full")
    out_dir = sys.argv[2] if len(sys.argv) > 2 else os.path.join(REPO, "ghidra_exports")
    big_path = os.path.join(src_dir, "all_decompiled.c")
    if not os.path.isfile(big_path):
        sys.exit(f"missing {big_path}")
    if os.path.isdir(out_dir):
        shutil.rmtree(out_dir)
    os.makedirs(out_dir)

    text = open(big_path, encoding="utf-8", errors="replace").read()
    hits = list(DELIM.finditer(text))
    n = 0
    for i, m in enumerate(hits):
        name, hexaddr = m.group(1), m.group(2)
        addr = f"{int(hexaddr, 16):08x}"
        body = text[m.end(): hits[i + 1].start() if i + 1 < len(hits) else len(text)].strip("\n")
        with open(os.path.join(out_dir, f"{addr}.json"), "w", encoding="utf-8") as f:
            json.dump({"address": addr, "name": name, "decompiled": body}, f)
        n += 1
    print(f"split {n} functions -> {out_dir}")

if __name__ == "__main__":
    main()
