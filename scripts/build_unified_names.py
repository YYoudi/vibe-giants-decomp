#!/usr/bin/env python3
"""Build the unified 1.449 name table from every source, with priority and
conflict resolution. Emits a ghidra_apply_matches.java-compatible CSV.

Sources (priority order per 1.449 address):
  1. bytehash direct   (v149 func == v1.0 func, exact/head stage)
  2. wave-2 PS2 string anchors conf>=0.9 (direct on 1.449)
  3. wave-1 PS2 names transferred through the v1.0->1.449 map (exact/head/norm/prop)
  4. wave-2 propagated conf>=0.6
  5. everything else    -> plate comments only (conf<0.9)

Output: ps2_symbols/unified_names_1449.csv
        pc_addr,pc_name,ps2_addr,ps2_name,conf,tier,shared
"""
import csv, json, os, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
PS2 = os.path.join(REPO, "ps2_symbols")

def norm(a):
    return a.lower().lstrip("0x").lstrip("0").rjust(8, "0")

STAGE_FACTOR = {"exact": 1.0, "head": 0.95, "norm": 0.85, "seed": 1.0, "prop": 0.85}

def main():
    # v1.0 -> 1.449 map
    vmap = {}
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v10_v149_propagated.csv"), encoding="utf-8")):
        vmap[norm(r["v10_addr"])] = (norm(r["v149_addr"]), r["stage"], float(r["conf"]))

    # v1.0-side names
    v10names = {}  # v10_addr -> (name, source, conf)
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v10_func_bytes.csv"), encoding="utf-8")):
        if not r["name"].startswith("FUN_") and int(r["size"]) > 4:
            v10names[norm(r["addr"])] = (r["name"], "v10_project", 1.0)
    cont = {}
    for r in csv.DictReader(open(os.path.join(PS2, "wave1_containing.csv"), encoding="utf-8")):
        cont[norm(r["wave1_addr"])] = norm(r["cont_addr"])
    for r in csv.DictReader(open(os.path.join(PS2, "pc_ps2_matches_full.csv"), encoding="utf-8")):
        a = cont.get(norm(r["pc_addr"]), norm(r["pc_addr"]))
        c = float(r["conf"])
        if a not in v10names or c > v10names[a][2]:
            v10names[a] = (r["ps2_name"], "ps2_w1", c)
    sn = json.load(open(os.path.join(HERE := os.path.dirname(os.path.abspath(__file__)), "system_names.json"), encoding="utf-8")) if False else json.load(open(os.path.join(REPO, "scripts", "system_names.json"), encoding="utf-8"))
    for a, nm in sn.items():
        v10names.setdefault(norm(a), (nm, "system_names", 1.0))
    db = json.load(open(os.path.join(REPO, "scripts", "re_db.json"), encoding="utf-8"))
    for a, info in db.get("functions", {}).items():
        if isinstance(info, dict) and info.get("name"):
            v10names.setdefault(norm(a), (info["name"], "re_db", 1.0))

    cand = collections.defaultdict(list)  # v149_addr -> [(conf, tier, name)]

    # 1. bytehash direct (from bytehash_names_1449.csv, already merged v1.0 names)
    for r in csv.DictReader(open(os.path.join(PS2, "bytehash_names_1449.csv"), encoding="utf-8")):
        cand[norm(r["pc_addr"])].append((float(r["conf"]), r["tier"], r["ps2_name"]))

    # 3. wave-1 names via the propagated map
    nmap = 0
    for a10, (nm, src, c) in v10names.items():
        m = vmap.get(a10)
        if not m:
            continue
        a149, stage, mapconf = m
        conf = round(c * STAGE_FACTOR.get(stage, 0.85) * (mapconf if stage == "prop" else 1.0), 3)
        cand[a149].append((conf, f"w1via-{stage}-{src}", nm))
        nmap += 1

    # 2/4. wave-2 direct on 1.449
    for r in csv.DictReader(open(os.path.join(PS2, "pc_ps2_matches_full_1449.csv"), encoding="utf-8")):
        cand[norm(r["pc_addr"])].append((float(r["conf"]), f"w2-{r['tier']}", r["ps2_name"]))

    # resolve: keep highest conf per address; log conflicts.
    # verified evidence beats transferred names: bump verified addresses.
    verified = {}
    vfile = os.path.join(PS2, "verified_names.txt")
    if os.path.exists(vfile):
        for line in open(vfile, encoding="utf-8"):
            parts = line.split()
            if len(parts) >= 2:
                verified[norm(parts[0])] = parts[1]
    for a in list(cand):
        if a in verified:
            cand[a] = [(0.95, t + "-verified", verified[a]) for c, t, n in cand[a]]
    # verified entries are authoritative: ensure each has a row even if its
    # candidate disappeared from the source tables (regenerated matchers).
    for a, vnm in verified.items():
        cand.setdefault(a, []).append((0.95, "verified", vnm))
    rows, conflicts = [], []
    for a, lst in cand.items():
        lst.sort(reverse=True)
        best = lst[0]
        others = [x for x in lst[1:] if x[2] != best[2]]
        if others:
            conflicts.append((a, best, others[:2]))
        rows.append({
            "pc_addr": a, "pc_name": f"FUN_{a.upper()}",
            "ps2_addr": "", "ps2_name": best[2].replace(",", "_"),
            "conf": best[0], "tier": best[1], "shared": "",
        })
    rows.sort(key=lambda r: r["pc_addr"])
    out = os.path.join(PS2, "unified_names_1449.csv")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["pc_addr", "pc_name", "ps2_addr", "ps2_name", "conf", "tier", "shared"])
        w.writeheader(); w.writerows(rows)
    ren = sum(1 for r in rows if r["conf"] >= 0.9)
    print(f"unified: {len(rows)} named addresses, {ren} at conf>=0.9 (rename tier)")
    print(f"v1.0-side names mapped through cross-version map: {nmap}")
    print(f"conflicts (different names for same addr): {len(conflicts)}")
    for a, best, oth in conflicts[:8]:
        print(f"  {a}: {best[2]} ({best[1]})  vs  {[x[2] for x in oth]}")
    print(f"wrote {out}")

if __name__ == "__main__":
    main()
