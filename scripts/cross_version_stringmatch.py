#!/usr/bin/env python3
"""Cross-version string-anchor matching: v1.0 exports <-> 1.449 exports.
Same-anchor logic as ps2_symbols/match_pc_ps2.py but PC-vs-PC (both x86, both
have hydrated string literals). Output feeds name transfer: wave-1 PS2 names
at v1.0 addresses ride across to their 1.449 counterparts.

Output: decompiled/v10_v149_stringmatch.csv  v10_addr,v149_addr,shared,conf
"""
import json, os, re, collections, csv

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
STR_RE = re.compile(r'"((?:\\.|[^"\\])*)"')

def load_refs(d):
    refs = collections.defaultdict(set)
    for fn in os.listdir(d):
        if not fn.endswith(".json"):
            continue
        a = fn[:-5]
        body = json.load(open(os.path.join(d, fn), encoding="utf-8"))["decompiled"]
        for m in STR_RE.findall(body):
            m2 = m.replace("\\n", "\n").replace("\\t", "\t").replace('\\"', '"')
            if len(m2) >= 6:
                refs[a].add(m2)
    return refs

def main():
    r10 = load_refs(os.path.join(REPO, "ghidra_exports_v10"))
    r149 = load_refs(os.path.join(REPO, "ghidra_exports"))
    print(f"v1.0 funcs w/ strings: {len(r10)}   1.449: {len(r149)}")

    globfreq = collections.Counter()
    for s in r10.values():
        globfreq.update(s)
    for s in r149.values():
        globfreq.update(s)

    idx10 = collections.defaultdict(set)
    for fa, ss in r10.items():
        for x in ss:
            idx10[x].add(fa)
    idx149 = collections.defaultdict(set)
    for fa, ss in r149.items():
        for x in ss:
            idx149[x].add(fa)

    rows = []
    for a149, ss in r149.items():
        vote = collections.Counter()
        detail = []
        for x in ss:
            c10 = idx10.get(x)
            if not c10:
                continue
            w = 1.0 / max(1, globfreq[x])
            for b in c10:
                vote[b] += w
            detail.append((x, globfreq[x]))
        if not vote:
            continue
        ranked = vote.most_common()
        best10, best_score = ranked[0]
        second = ranked[1][1] if len(ranked) > 1 else 0
        shared = sorted(x for x, _ in detail if best10 in idx10.get(x, set()))
        dom = best_score / (best_score + second) if best_score + second else 1.0
        conf = round(dom * min(1.0, len(shared) / 3.0), 3)
        rows.append({"v149_addr": a149, "v10_addr": best10, "shared": len(shared), "conf": conf})

    rows.sort(key=lambda r: (-r["conf"], -r["shared"]))
    out = os.path.join(REPO, "decompiled", "v10_v149_stringmatch.csv")
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=["v10_addr", "v149_addr", "shared", "conf"])
        w.writeheader(); w.writerows(rows)
    hi = sum(1 for r in rows if r["conf"] >= 0.5)
    print(f"candidates: {len(rows)} (conf>=0.5: {hi}) -> {out}")

if __name__ == "__main__":
    main()
