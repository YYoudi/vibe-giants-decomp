#!/usr/bin/env python3
"""Cross-version function map v1.0 -> GOG 1.449 by byte identity.

Stage 1 (exact):     md5full unique on BOTH sides -> match, conf=1.0
Stage 2 (head):      md5first32 AND size equal, unique on both sides -> conf=0.95

Then transfers every name known on the v1.0 side (Ghidra project names,
wave-1 PS2 matches, system_names.json, re_db.json) onto the matched 1.449
addresses, emitting an apply-CSV in the pc_ps2_matches_full.csv format that
scripts/ghidra_apply_matches.java consumes.

Outputs:
  decompiled/v10_v149_bytemap.csv     v10_addr,v149_addr,stage
  ps2_symbols/bytehash_names_1449.csv apply-CSV (pc_addr,pc_name,ps2_addr,ps2_name,conf,tier,shared)
"""
import csv, json, os, sys, collections

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(HERE)

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

def load(path):
    # skip degenerate pseudo-functions (size<=4) left by earlier apply passes
    return {norm(r["addr"]): r for r in csv.DictReader(open(path, encoding="utf-8"))
            if int(r["size"]) > 4}

def main():
    v10 = load(os.path.join(REPO, "decompiled", "v10_func_bytes.csv"))
    v149 = load(os.path.join(REPO, "decompiled", "v149_func_bytes.csv"))
    print(f"v1.0: {len(v10)} funcs   1.449: {len(v149)} funcs")

    matches = {}
    used10, used149 = set(), set()

    # stage 1: exact full-body md5, unique both sides
    by_md5_10 = collections.defaultdict(list)
    for a, r in v10.items():
        if r["md5full"]:
            by_md5_10[r["md5full"]].append(a)
    for a149, r in v149.items():
        cands = by_md5_10.get(r["md5full"], []) if r["md5full"] else []
        if len(cands) == 1:
            a10 = cands[0]
            matches[a149] = (a10, "exact")
            used10.add(a10); used149.add(a149)
    print(f"stage1 exact: {len(matches)}")

    # stage 2: head md5 + same size, unique both sides
    by_head_10 = collections.defaultdict(list)
    for a, r in v10.items():
        if r["md5first32"] and a not in used10:
            by_head_10[(r["md5first32"], r["size"])].append(a)
    for a149, r in v149.items():
        if a149 in used149 or not r["md5first32"]:
            continue
        cands = by_head_10.get((r["md5first32"], r["size"]), [])
        if len(cands) == 1:
            a10 = cands[0]
            matches[a149] = (a10, "head")
            used10.add(a10); used149.add(a149)
    print(f"stage2 head+size: {len(matches)} total")


    # stage 3: semantic (relocation-normalized) md5, unique both sides
    def load_norm(path):
        d = {}
        for r in csv.DictReader(open(path, encoding="utf-8")):
            if r["normmd5"]:
                d.setdefault(r["normmd5"], []).append(norm(r["addr"]))
        return d
    nh10 = load_norm(os.path.join(REPO, "decompiled", "v10_normhash.csv"))
    before = len(matches)
    for a149, r in v149.items():
        if a149 in used149:
            continue
        h = None
        for nr in csv.DictReader(open(os.path.join(REPO, "decompiled", "v149_normhash.csv"), encoding="utf-8")):
            pass
    # (load v149 norm into dict first)
    v149nh = {}
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v149_normhash.csv"), encoding="utf-8")):
        if r["normmd5"]:
            v149nh[norm(r["addr"])] = r["normmd5"]
    for a149, h in v149nh.items():
        if a149 in used149:
            continue
        cands = nh10.get(h, [])
        cands = [c for c in cands if c not in used10]
        if len(cands) == 1:
            a10 = cands[0]
            matches[a149] = (a10, "norm")
            used10.add(a10); used149.add(a149)
    print(f"stage3 norm: {len(matches)} total (+{len(matches)-before})")

    with open(os.path.join(REPO, "decompiled", "v10_v149_bytemap.csv"), "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["v10_addr", "v149_addr", "stage"])
        for a149, (a10, stage) in sorted(matches.items(), key=lambda kv: int(kv[0], 16)):
            w.writerow([a10, a149, stage])

    # ---- name transfer ----------------------------------------------------
    # name sources keyed by v1.0 address (no 0x, 8 hex, as in dump csv)
    names = {}  # v10_addr -> (name, source, conf)
    for a, r in load(os.path.join(REPO, "decompiled", "v10_func_bytes.csv")).items():
        if not r["name"].startswith("FUN_") and int(r["size"]) > 4:
            names[a] = (r["name"], "v10_project", 1.0)
    for r in csv.DictReader(open(os.path.join(REPO, "ps2_symbols", "pc_ps2_matches_full.csv"), encoding="utf-8")):
        a = norm(r["pc_addr"])
        nm = r["ps2_name"]
        c = float(r["conf"])
        if a not in names or c > 0.6:
            names[a] = (nm, f"ps2_wave1_conf{c}", min(1.0, c))
    sn = json.load(open(os.path.join(HERE, "system_names.json"), encoding="utf-8"))
    for a, nm in sn.items():
        names.setdefault(norm(a), (nm, "system_names", 1.0))
    db = json.load(open(os.path.join(HERE, "re_db.json"), encoding="utf-8"))
    for a, info in db.get("functions", {}).items():
        if isinstance(info, dict) and info.get("name"):
            names.setdefault(norm(a), (info["name"], "re_db", 1.0))

    rows = []
    for a149, (a10, stage) in matches.items():
        if a10 in names:
            nm, src, conf = names[a10]
            rows.append({
                "pc_addr": a149, "pc_name": f"FUN_{a149.upper()}",
                "ps2_addr": "0x" + a10, "ps2_name": nm,
                "conf": conf if stage == "exact" else round(conf * (0.95 if stage == "head" else 0.85), 3),
                "tier": f"bytehash-{stage}-{src}", "shared": "",
            })
    out = os.path.join(REPO, "ps2_symbols", "bytehash_names_1449.csv")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    print(f"name transfer: {len(rows)} of {len(matches)} matched have a known v1.0 name -> {out}")

if __name__ == "__main__":
    main()
