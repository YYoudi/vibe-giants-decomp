#!/usr/bin/env python3
"""Mine OBJECT field offsets from the definitive OBJECT*-typed function set
(regenerates the threshold-2 candidate list exactly as apply_struct_params).
"""
import csv, json, glob, os, re, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

mined = set()
for r in csv.DictReader(open(os.path.join(PS2, "OBJECT_LAYOUT.csv"), encoding="utf-8")):
    off = r["offset"]
    if not off.startswith("0x-"):
        mined.add(int(off, 16))
big = {o for o in mined if o >= 0x100}

cands = []
for f in glob.glob(os.path.join(EXP, "*.json")):
    d = json.load(open(f, encoding="utf-8"))
    body = d["decompiled"]
    m = re.match(r".*?\(([^)]*)\)", body, re.S)
    if not m:
        continue
    params = [p.strip() for p in m.group(1).split(",") if p.strip()]
    if not params or "param_1" not in params[0]:
        continue
    offs = set(int(x, 16) for x in re.findall(r"param_1\s*\+\s*(0x[0-9a-fA-F]+)", body))
    if len(offs & mined) >= 2 and len(offs & big) >= 1:
        cands.append(norm(d["address"]))
print(f"OBJECT* function set: {len(cands)}")

OFF = re.compile(r"param_1\s*\+\s*(0x[0-9a-fA-F]+)")
hist = collections.Counter()
users = collections.defaultdict(list)
for f in glob.glob(os.path.join(EXP, "*.json")):
    d = json.load(open(f, encoding="utf-8"))
    a = norm(d["address"])
    if a not in cands:
        continue
    for o in set(int(x, 16) for x in OFF.findall(d["decompiled"])):
        hist[o] += 1
        if len(users[o]) < 3:
            users[o].append(d["name"])

with open(os.path.join(REPO, "decompiled", "object_fields_pc.csv"), "w", newline="", encoding="utf-8") as f:
    w = csv.writer(f)
    w.writerow(["offset", "pc_funcs", "examples"])
    for o, c in sorted(hist.items()):
        if c >= 4 and o < 0x10000:
            w.writerow([hex(o), c, ";".join(users[o])])
n = sum(1 for o, c in hist.items() if c >= 4 and o < 0x10000)
print(f"OBJECT PC offsets (>=4 funcs): {n} -> decompiled/object_fields_pc.csv")
