#!/usr/bin/env python3
"""Propagate the v1.0 <-> 1.449 byte-match anchors through both call graphs.

Same reliability contract as ps2_symbols/match_propagate.py:
  - seeds = byte/norm-identical pairs (unique on both sides), never changed
  - growth: (F10,F149) matched when >=2 already-matched caller- or callee-pairs
    both connect them, mutually unique, conf decays 0.85/hop, floor 0.4

Outputs:
  decompiled/v10_v149_propagated.csv  v10_addr,v149_addr,stage,conf
"""
import csv, json, os, re, collections

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CALL = re.compile(r"\bFUN_([0-9a-fA-F]{8})\s*\(")

def norm(a):
    return a.lower().lstrip("0").rjust(8, "0")

def graph(exports_dir):
    callees = collections.defaultdict(set)
    for fn in os.listdir(exports_dir):
        if not fn.endswith(".json"):
            continue
        a = fn[:-5]
        body = json.load(open(os.path.join(exports_dir, fn), encoding="utf-8"))["decompiled"]
        for m in CALL.finditer(body):
            c = norm(m.group(1))
            if c != a:
                callees[a].add(c)
    callers = collections.defaultdict(set)
    for a, cs in callees.items():
        for c in cs:
            callers[c].add(a)
    return callees, callers

def main():
    callees10, callers10 = graph(os.path.join(REPO, "ghidra_exports_v10"))
    callees149, callers149 = graph(os.path.join(REPO, "ghidra_exports"))
    print(f"graph v1.0: {len(callees10)} w/ callees; 1.449: {len(callees149)}")

    seeds = []
    seen10, seen149 = set(), set()
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v10_v149_bytemap.csv"), encoding="utf-8")):
        a10, a149 = norm(r["v10_addr"]), norm(r["v149_addr"])
        seeds.append((a10, a149)); seen10.add(a10); seen149.add(a149)
    nbyte = len(seeds)
    # string-anchor seeds (conf>=0.5), only where both sides are still free
    for r in csv.DictReader(open(os.path.join(REPO, "decompiled", "v10_v149_stringmatch.csv"), encoding="utf-8")):
        if float(r["conf"]) < 0.5:
            continue
        a10, a149 = norm(r["v10_addr"]), norm(r["v149_addr"])
        if a10 in seen10 or a149 in seen149:
            continue
        seeds.append((a10, a149)); seen10.add(a10); seen149.add(a149)
    print(f"seeds: {len(seeds)} ({nbyte} byte + {len(seeds)-nbyte} string)")

    M10, M149 = {}, {}
    for a10, a149 in seeds:
        M10[a10] = (a149, 1.0)
        M149[a149] = (a10, 1.0)

    def neighbors(callees, callers, a):
        return callees.get(a, set()) | callers.get(a, set())

    conf = {p: 1.0 for p in seeds}
    for it in range(30):
        # 2-parent rule via paired edges: (b10,b149) gets a vote for every
        # already-matched (a10,a149) pair where b10/b149 are both callees or
        # both callers of a10/a149.
        edge_pairs = collections.Counter()
        support = collections.defaultdict(set)
        for a10, (a149, _) in M10.items():
            for b10 in callees10.get(a10, set()):
                if b10 in M10:
                    continue
                for b149 in callees149.get(a149, set()):
                    if b149 in M149:
                        continue
                    edge_pairs[(b10, b149)] += 1
                    support[(b10, b149)].add(("c", a10, a149))
            for b10 in callers10.get(a10, set()):
                if b10 in M10:
                    continue
                for b149 in callers149.get(a149, set()):
                    if b149 in M149:
                        continue
                    edge_pairs[(b10, b149)] += 1
                    support[(b10, b149)].add(("p", a10, a149))

        best10, best149 = collections.defaultdict(list), collections.defaultdict(list)
        for (b10, b149), cnt in edge_pairs.items():
            if cnt >= 2 and len(support[(b10, b149)]) >= 2:
                best10[b10].append((cnt, b149))
                best149[b149].append((cnt, b10))
        added = 0
        used = set()
        for b10, lst in sorted(best10.items(), key=lambda kv: -max(c for c, _ in kv[1])):
            if b10 in M10 or len(lst) != 1:
                continue
            cnt, b149 = lst[0]
            if best149[b149].count((cnt, b10)) != 1 or len(best149[b149]) != 1:
                continue
            if b149 in M149:
                continue
            # conf = min parent conf * 0.85
            pc = min((M10[s[1]][1]) for s in support[(b10, b149)])
            nc = round(pc * 0.85, 3)
            if nc < 0.4:
                continue
            M10[b10] = (b149, nc)
            M149[b149] = (b10, nc)
            added += 1
        print(f"[iter {it}] +{added} (total {len(M10)})")
        if added == 0:
            break

    with open(os.path.join(REPO, "decompiled", "v10_v149_propagated.csv"), "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["v10_addr", "v149_addr", "stage", "conf"])
        for a10, (a149, c) in sorted(M10.items()):
            w.writerow([a10, a149, "seed" if c == 1.0 else "prop", c])
    print(f"wrote {len(M10)} v1.0<->1.449 correspondences")

if __name__ == "__main__":
    main()
