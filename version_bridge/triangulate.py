#!/usr/bin/env python3
"""
Triangulate 1.5 <-> vanilla via PS2 symbols, then merge into VERSION_MAP_v2.csv.

PS2 (SLUS_201.78) has FULL debug symbols -> authoritative function names. If a 1.5
function and a vanilla function BOTH independently string-anchor to the SAME PS2
function, they are the same function. This is a signal INDEPENDENT of the direct
1.5<->vanilla comparison (it routes through the PS2 symbol dictionary), so it both
CONFIRMS existing v2 pairs and DISCOVERS new ones the direct matcher missed.

Inputs:
  ps2_symbols/pc_ps2_matches_full.csv   1.5 -> PS2 (string + call-graph propagated)
  version_bridge/vanilla_ps2_matches.csv vanilla -> PS2 (string)
  version_bridge/VERSION_MAP_v2.csv     current 1.5 <-> vanilla map
Output:
  version_bridge/VERSION_MAP_v2.csv     rewritten with: `triangulated` flag,
                                        LOW pairs promoted to MEDIUM on triangulation,
                                        + NEW triangulated pairs appended (origin=triangulated)

Rules:
  - Require conf >= TRI_CONF on BOTH the 1.5->PS2 and vanilla->PS2 leg.
  - A PS2 func matched by exactly 1 vanilla and N 1.5 funcs: the vanilla<->each 1.5
    is a candidate. If N>1 it may be a 1.5 duplicate/merge -> still emit but tag.
  - Cross with v2:
      v2 EXACT/HIGH/MEDIUM + triangulated  -> add tri flag (independent confirmation)
      v2 LOW + triangulated                 -> PROMOTE to MEDIUM
      not in v2                             -> NEW pair, tier MEDIUM, origin=triangulated
      in v2 but mapped to a DIFFERENT van   -> CONFLICT (flag, don't override)
"""
import csv, os, collections

HERE = os.path.dirname(os.path.abspath(__file__))
PS2_DIR = os.path.join(os.path.dirname(HERE), "ps2_symbols")
PC_PS2 = os.path.join(PS2_DIR, "pc_ps2_matches_full.csv")
VAN_PS2 = os.path.join(HERE, "vanilla_ps2_matches_full.csv")
V2 = os.path.join(HERE, "VERSION_MAP_v2.csv")

TRI_CONF = 0.4  # both legs must reach this

def norm(a):
    a = a.lower(); a = a[2:] if a.startswith("0x") else a; return a.rjust(8, "0")

def main():
    # ps2_addr -> [(side_addr, conf, name)]
    ps2_15 = collections.defaultdict(list)   # ps2_addr -> 1.5 addrs
    for r in csv.DictReader(open(PC_PS2, encoding="utf-8")):
        if float(r.get("conf", 0)) >= TRI_CONF:
            ps2_15[r["ps2_addr"]].append((norm(r["pc_addr"]), float(r["conf"]), r.get("ps2_name", "")))
    ps2_van = collections.defaultdict(list)
    for r in csv.DictReader(open(VAN_PS2, encoding="utf-8")):
        if float(r.get("conf", 0)) >= TRI_CONF:
            ps2_van[r["ps2_addr"]].append((norm(r["vanilla_addr"]), float(r["conf"]), r.get("ps2_name", "")))
    shared_ps2 = set(ps2_15) & set(ps2_van)
    print(f"[*] PS2 funcs matched on 1.5 side: {len(ps2_15)}; vanilla side: {len(ps2_van)}; BOTH: {len(shared_ps2)}")

    # load v2
    v2 = list(csv.DictReader(open(V2, encoding="utf-8")))
    fields = list(v2[0].keys()) if v2 else []
    if "triangulated" not in fields: fields.append("triangulated")
    by15 = {norm(r["1.5_addr"]): r for r in v2}
    for r in v2: r.setdefault("triangulated", "")

    # build triangulated pairs
    tri_pairs = {}  # 1.5_addr -> (vanilla_addr, ps2_name)
    conflicts = []
    n_new = n_promote = n_confirm = n_conflict = 0
    for pa in shared_ps2:
        ps2name = ps2_15[pa][0][2] or ps2_van[pa][0][2]
        for (ra, rc, _) in ps2_15[pa]:
            for (va, vc, _) in ps2_van[pa]:
                # strongest: pick highest combined conf; but record all candidates
                key = (ra, va, pa)
                tri_pairs.setdefault(ra, []).append((va, ps2name, pa, rc + vc))
    # for each 1.5 func, pick its best triangulated vanilla (highest combined conf)
    best_tri = {}
    for ra, lst in tri_pairs.items():
        lst.sort(key=lambda t: -t[3])
        best_tri[ra] = lst[0]  # (va, ps2name, pa, score)

    for ra, (va, ps2name, pa, score) in best_tri.items():
        rec = by15.get(ra)
        if rec is None:
            n_new += 1
            continue
        if norm(rec["vanilla_addr"]) == va:
            rec["triangulated"] = "yes"
            if rec["tier"] == "LOW":
                rec["tier"] = "MEDIUM"; rec["origin"] = rec["origin"] + "+tri"
                n_promote += 1
            else:
                n_confirm += 1
        else:
            n_conflict += 1
            conflicts.append((ra, rec["vanilla_addr"], va, ps2name))

    # append NEW triangulated pairs (1.5 funcs not in v2). Reject if the vanilla addr
    # is ALREADY claimed in v2 (claimed addrs belong to a better-evidenced pair, often a
    # merge target) or if size ratio is poor (triangulation via different strings can
    # join unrelated funcs that both happen to match the same big PS2 function).
    v2_15 = set(by15)
    v2_vanillas = set(norm(r["vanilla_addr"]) for r in v2)
    new_rows = []
    import json as _json
    rec_j = {_json.loads(l)["addr"].lower().replace("0x", "").rjust(8, "0"):
             _json.loads(l) for l in open(os.path.join(HERE, "recomp_functions.jsonl"), encoding="utf-8") if l.strip()}
    van_j = {_json.loads(l)["addr"].lower().replace("0x", "").rjust(8, "0"):
             _json.loads(l) for l in open(os.path.join(HERE, "vanilla_functions.jsonl"), encoding="utf-8") if l.strip()}
    for ra, (va, ps2name, pa, score) in best_tri.items():
        if ra in v2_15: continue
        if va in v2_vanillas: continue   # already claimed -> not a free new pair
        rsz = rec_j.get(ra, {}).get("size", 0); vsz = van_j.get(va, {}).get("size", 0)
        sr = max(rsz, vsz) / min(rsz, vsz) if min(rsz, vsz) else 99
        if sr > 1.6: continue            # size sanity: triangulation must still match size
        new_rows.append({
            "1.5_addr": ra, "1.5_name": rec_j.get(ra, {}).get("name", ""),
            "vanilla_addr": va, "vanilla_name": van_j.get(va, {}).get("name", ""),
            "tier": "MEDIUM", "score": round(min(0.8, 0.45 + score * 0.05), 3),
            "origin": "triangulated", "shared_rare": 0, "size_ratio": round(sr, 3),
            "prefix": 0, "jaccard": 0.0, "ps2_name": ps2name, "triangulated": "yes",
        })
    n_new = len(new_rows)

    # write merged
    allrows = v2 + new_rows
    torder = {"EXACT": 0, "HIGH": 1, "MEDIUM": 2, "LOW": 3}
    allrows.sort(key=lambda r: (torder.get(r["tier"], 9), -float(r["score"] or 0)))
    with open(V2, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=fields); w.writeheader(); w.writerows(allrows)

    # names for new rows: backfill from jsonl (light)
    print(f"\n[+] triangulation merged into VERSION_MAP_v2.csv")
    print(f"    confirmed (already EXACT/HIGH/MEDIUM, +tri flag): {n_confirm}")
    print(f"    PROMOTED LOW -> MEDIUM (+tri): {n_promote}")
    print(f"    NEW triangulated pairs appended: {n_new}")
    print(f"    conflicts (v2 disagrees with PS2): {n_conflict}")
    for ra, v2va, triva, nm in conflicts[:12]:
        print(f"      1.5 {ra}: v2->{v2va}  TRI->{triva}  (ps2={nm})")

if __name__ == "__main__":
    main()
