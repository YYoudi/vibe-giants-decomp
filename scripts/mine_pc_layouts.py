#!/usr/bin/env python3
"""Mine PC-side field offsets for OBJECT (first param of OBJECT*-typed/candidate
functions) and COMM (first param of comm_* named functions). Output merged
layout CSVs consumed by apply_structs_pyghidra.py.
"""
import csv, json, glob, os, re, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

# current OBJECT* param1-typed/seed functions: reuse the same heuristic sources
obj_addrs = set()
for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "func_source_map_1449.json")) if False else [], []):
    pass
# source-path seeds are OBJECT-heavy modules (ai_move, object, fx...)
srcmap = json.load(open(os.path.join(REPO, "decompiled", "func_source_map_1449.json"), encoding="utf-8"))
for a, m in srcmap.items():
    if any(k in m.lower() for k in ("object", "ai_move", "fx", "animate", "blood", "smartie",
                                    "reaper", "mecc", "vimp", "kabuto", "rpman", "teammecc")):
        obj_addrs.add(norm(a))
# plus bsim/PS2-named functions whose PS2 name takes OBJECT*
for r in csv.DictReader(open(os.path.join(PS2, "SLUS_201.78.symbols.csv"), encoding="utf-8")):
    pass  # (signature param scan done below via unified names)

comm_addrs = set()
for f in ["unified_names_1449.csv", "llm_strings_wave.csv", "llm_strings_wave2.csv", "callpat_wave.csv"]:
    try:
        for r in csv.DictReader(open(os.path.join(PS2, f), encoding="utf-8")):
            if r["ps2_name"].startswith("comm_") or "comm" in r["ps2_name"].lower()[:6]:
                comm_addrs.add(norm(r["pc_addr"]))
    except FileNotFoundError:
        pass

OFF = re.compile(r"param_1\s*\+\s*(0x[0-9a-fA-F]+)")

def mine(addr_filter, cap=100000):
    hist = collections.Counter()
    users = collections.defaultdict(list)
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        a = norm(d["address"])
        if a not in addr_filter:
            continue
        body = d["decompiled"]
        offs = set(int(x, 16) for x in OFF.findall(body))
        for o in offs:
            hist[o] += 1
            if len(users[o]) < 3:
                users[o].append(d["name"])
    return hist, users

obj_hist, obj_users = mine(obj_addrs)
comm_hist, comm_users = mine(comm_addrs)

with open(os.path.join(REPO, "decompiled", "object_fields_pc.csv"), "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["offset", "pc_funcs", "examples"])
    for o, c in sorted(obj_hist.items()):
        if c >= 3 and o < 0x10000:
            w.writerow([hex(o), c, ";".join(obj_users[o])])
with open(os.path.join(REPO, "decompiled", "comm_fields_pc.csv"), "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["offset", "pc_funcs", "examples"])
    for o, c in sorted(comm_hist.items()):
        if c >= 2 and o < 0x2000:
            w.writerow([hex(o), c, ";".join(comm_users[o])])
print(f"OBJECT PC-mined offsets (>=3 funcs): {sum(1 for o,c in obj_hist.items() if c>=3 and o<0x10000)}")
print(f"COMM PC-mined offsets (>=2 funcs): {sum(1 for o,c in comm_hist.items() if c>=2 and o<0x2000)}")
