#!/usr/bin/env python3
"""Address-band module attribution.

Object files link contiguously: functions from one source file occupy a
contiguous address range. Seeds (address -> original source file) come from
  1. assert-string evidence in the 1.449 decomp  (func_source_map_1449.json)
  2. the same evidence in the v1.0 decomp, transferred through the
     cross-version function map (v10_v149_propagated.csv)
  3. PS2-derived function names whose leading token equals a known source
     file stem (fx_* -> Main/fx, ai_move_* -> main/ai_move, ...)

Rule (precision first): an unnamed run of functions bounded by two seeds of
the SAME module, at most --max-gap functions, is attributed to that module.
Named functions are never touched.

Output: ps2_symbols/module_bands.csv (apply-CSV, conf 0.9, tier module-band)
"""
import csv, json, os, re, glob, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXP = os.path.join(REPO, "ghidra_exports")
EXP10 = os.path.join(REPO, "ghidra_exports_v10")
PS2 = os.path.join(REPO, "ps2_symbols")

SRC_PATH = re.compile(r'C:[/\\]+Giants[/\\]+source[/\\]+([A-Za-z0-9_]+)[/\\]+([A-Za-z0-9_]+?)\.(?:c|cpp|h)', re.I)

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

def mod_id(d, f):
    """canonical module id: dir_file lowercased"""
    return f"{d}_{f}".lower()

def main():
    funcs = {}
    for f in glob.glob(os.path.join(EXP, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        funcs[d["address"]] = d
    order = sorted(funcs, key=lambda a: int(a, 16))

    seeds = {}
    # 1) direct 1.449 evidence
    for a, m in json.load(open(os.path.join(REPO, "decompiled", "func_source_map_1449.json"), encoding="utf-8")).items():
        seeds[a] = m
    # 2) v1.0 evidence transferred through the cross-version map
    src10 = {}
    for f in glob.glob(os.path.join(EXP10, "*.json")):
        d = json.load(open(f, encoding="utf-8"))
        ms = SRC_PATH.findall(d["decompiled"])
        if ms:
            c = collections.Counter(f"{m[0]}_{m[1]}".lower() for m in ms)
            src10[d["address"]] = c.most_common(1)[0][0]
    vmap = {}
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v10_v149_propagated.csv"), encoding="utf-8")):
        vmap[norm(r["v10_addr"])] = norm(r["v149_addr"])
    n10 = 0
    for a10, m in src10.items():
        a149 = vmap.get(a10)
        if a149 and a149 not in seeds:
            seeds[a149] = m
            n10 += 1
    # 3) PS2-derived names matching a known source stem
    stems = {m.split("_")[-1]: m for m in set(seeds.values())}
    for r in csv.DictReader(open(os.path.join(PS2, "unified_names_1449.csv"), encoding="utf-8")):
        if float(r["conf"]) < 0.9:
            continue
        a = norm(r["pc_addr"])
        if a in seeds:
            continue
        base = r["ps2_name"].split("__F")[0]
        tok = re.split(r"[^A-Za-z0-9]+", base)[0].lower()
        if tok in stems:
            seeds[a] = stems[tok]
    # chained pass: previous band rows become seeds (same bounded-run rule)
    try:
        for r in csv.DictReader(open(os.path.join(PS2, "module_bands.csv"), encoding="utf-8")):
            m = r["ps2_name"].rsplit("_0", 1)[0]
            if m and r["pc_addr"] not in seeds:
                seeds[norm(r["pc_addr"])] = m
    except FileNotFoundError:
        pass
    print(f"seeds: {len(seeds)} (direct 179 + v10-transferred {n10} + prefix-matched + chained bands)")

    claimed = set()
    for r in csv.DictReader(open(os.path.join(PS2, "unified_names_1449.csv"), encoding="utf-8")):
        claimed.add(norm(r["pc_addr"]))
    for r in csv.DictReader(open(os.path.join(PS2, "module_names_wave.csv"), encoding="utf-8")):
        claimed.add(norm(r["pc_addr"]))

    # fill runs bounded by two seeds of the same module
    rows = []
    i = 0
    while i < len(order):
        a = order[i]
        if a in seeds or a in claimed:
            i += 1
            continue
        # find run of unnamed/claimed-free? runs must be purely unclaimed unnamed
        j = i
        while j < len(order) and order[j] not in seeds and order[j] not in claimed:
            j += 1
        # run = order[i:j]; bounded by order[i-1] and order[j]
        if 0 < i and j < len(order):
            left, right = seeds.get(order[i - 1]), seeds.get(order[j])
            if left and left == right and (j - i) <= 40:
                for k in range(i, j):
                    a2 = order[k]
                    rows.append({"pc_addr": a2, "pc_name": funcs[a2]["name"],
                                 "ps2_addr": "", "ps2_name": f"{left}_{a2}",
                                 "conf": 0.9, "tier": "module-band", "shared": ""})
        i = max(j, i + 1)

    outp = os.path.join(PS2, "module_bands.csv")
    with open(outp, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    dist = collections.Counter(r["ps2_name"].rsplit("_0", 1)[0] for r in rows)
    print(f"band-attributed: {len(rows)} across {len(dist)} modules")
    for m, c in dist.most_common(15):
        print(f"  {c:4d}  {m}")

if __name__ == "__main__":
    main()
